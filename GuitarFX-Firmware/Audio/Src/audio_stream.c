#include "audio_stream.h"
#include "i2s.h"

#include <string.h>

#define ADC_BUFFER_LEN ((AUDIO_STREAM_BUFFER_FRAME_COUNT * 2) * 2) // Stereo audio under the hood + pingpong buffer
#define DAC_BUFFER_LEN ((AUDIO_STREAM_BUFFER_FRAME_COUNT * 2) * 2)

#define ADC_BUFFER_BYTES (ADC_BUFFER_LEN * sizeof(int32_t))
#define DAC_BUFFER_BYTES (DAC_BUFFER_LEN * sizeof(int32_t))

#define DCACHE_LINE_SIZE_BYTES  32u

_Static_assert((ADC_BUFFER_BYTES / 2) %  DCACHE_LINE_SIZE_BYTES == 0u, "ADC half buffer must be multiple of data cache line size");
_Static_assert((DAC_BUFFER_BYTES / 2) %  DCACHE_LINE_SIZE_BYTES == 0u, "DAC half buffer must be multiple of data cache line size");

#define I2S_HANDLE (&hi2s1)

#define INT24_MIN (-8388608)
#define INT24_MAX 8388607

#define INT24_TO_FLOAT(x) ((x) / 8388608.0f)
#define FLOAT_TO_INT24(x) ((int32_t)((x) * 8388607.0f))

static bool initialized = false;

// Esnure ADC and DAC buffers are placed in RAM such that they fill complete cache lines
// We don't want any sharing with other variables in cache lines. Otherwise, flushing and invalidating cache can unintentionally corrupt variable values
__attribute__((section(".dma_buffers"), aligned(DCACHE_LINE_SIZE_BYTES)))
static int32_t adc_buffer[ADC_BUFFER_LEN];
__attribute__((section(".dma_buffers"), aligned(DCACHE_LINE_SIZE_BYTES)))
static int32_t dac_buffer[DAC_BUFFER_LEN];

static volatile bool adc_buffer_ready;
static volatile bool dac_buffer_ready;

static int32_t* volatile adc_half_buffer = &adc_buffer[0]; // Half to read into
static int32_t* volatile dac_half_buffer = &dac_buffer[0]; // Half to write from

audio_stream_status_e audio_stream_init() {

    adc_buffer_ready = false;
    dac_buffer_ready = false;

    memset(adc_buffer, 0, ADC_BUFFER_BYTES);
    memset(dac_buffer, 0, DAC_BUFFER_BYTES);

    // SCB_CleanInvalidateDCache_by_Addr((uint32_t*)adc_buffer, ADC_BUFFER_BYTES); // Sync RAM with cache and mark invalid so adc buffer reads go to RAM first

    // SCB_CleanDCache_by_Addr((uint32_t*)dac_buffer, DAC_BUFFER_BYTES); // Ensure cached dac buffer is flushed to RAM before DMA starts

    HAL_StatusTypeDef err;
    err = HAL_I2SEx_TransmitReceive_DMA(I2S_HANDLE, (uint16_t*)dac_buffer, (uint16_t*)adc_buffer, ADC_BUFFER_LEN);
    if (err != HAL_OK)
        return AUDIO_STREAM_ERR_HAL;

    initialized = true;

    return AUDIO_STREAM_OK;

}

bool audio_stream_adc_buffer_ready() {
    return adc_buffer_ready;
}

bool audio_stream_dac_buffer_ready() {
    return dac_buffer_ready;
}

// adc_buffer_data must be length AUDIO_STREAM_BUFFER_FRAME_COUNT
audio_stream_status_e audio_stream_read_adc_buffer(audio_sample_t adc_buffer_data[restrict static AUDIO_STREAM_BUFFER_FRAME_COUNT]) {

    if (!initialized)
        return AUDIO_STREAM_ERR_NOT_INITIALIZED;

    int32_t* adc_half;

    // Atomically check/update adc buffer states
    __disable_irq();

    if (!adc_buffer_ready) {
        __enable_irq();
        return AUDIO_STREAM_ERR_BUFFER_NOT_READY;
    }

    adc_half = adc_half_buffer;
    adc_buffer_ready = false;
    
    __enable_irq();

    // Invalidate cache data to force CPU to start reading from RAM
    // SCB_InvalidateDCache_by_Addr((uint32_t*)adc_half, (ADC_BUFFER_BYTES / 2));
        
    for (uint32_t i = 0u; i < AUDIO_STREAM_BUFFER_FRAME_COUNT; i++) {
        adc_buffer_data[i] = (audio_sample_t)INT24_TO_FLOAT(adc_half[2*i] >> 8); // Data is placed in buffer by DMA in left aligned format. Ensure right aligned
    }

    return AUDIO_STREAM_OK;

}

// dac_buffer_data must be length AUDIO_STREAM_BUFFER_FRAME_COUNT
audio_stream_status_e audio_stream_write_dac_buffer(audio_sample_t const dac_buffer_data[restrict static AUDIO_STREAM_BUFFER_FRAME_COUNT]) {
    
    if (!initialized)
        return AUDIO_STREAM_ERR_NOT_INITIALIZED;

    int32_t* dac_half;

    // Atomically check/update dac buffer states
    __disable_irq();

    if (!dac_buffer_ready) {
        __enable_irq();
        return AUDIO_STREAM_ERR_BUFFER_NOT_READY;
    }

    dac_half = dac_half_buffer;
    dac_buffer_ready = false;

    __enable_irq();
        
        
    for (uint32_t i = 0u; i < AUDIO_STREAM_BUFFER_FRAME_COUNT; i++) {
        dac_half[2*i]        = (int32_t)(((uint32_t)FLOAT_TO_INT24((float)dac_buffer_data[i])) << 8);
        dac_half[2*i + 1]    = 0;
    }

    // Flush dirty cache lines to RAM so DMA can access it
    // SCB_CleanDCache_by_Addr((uint32_t*)dac_half, (DAC_BUFFER_BYTES / 2));

    return AUDIO_STREAM_OK;

}

void HAL_I2SEx_TxRxHalfCpltCallback(I2S_HandleTypeDef* hi2s) {

    if (hi2s->Instance != I2S_HANDLE->Instance)
        return;

    adc_half_buffer = &adc_buffer[0];
    dac_half_buffer = &dac_buffer[0];
    adc_buffer_ready = true;
    dac_buffer_ready = true;

}

void HAL_I2SEx_TxRxCpltCallback(I2S_HandleTypeDef* hi2s) {

    if (hi2s->Instance != I2S_HANDLE->Instance)
        return;

    adc_half_buffer = &adc_buffer[ADC_BUFFER_LEN / 2];
    dac_half_buffer = &dac_buffer[DAC_BUFFER_LEN / 2];
    adc_buffer_ready = true;
    dac_buffer_ready = true;

}