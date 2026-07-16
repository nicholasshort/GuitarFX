#ifndef AUDIO_STREAM_H
#define AUDIO_STREAM_H

#include <stdint.h>
#include <stdbool.h>

#define AUDIO_STREAM_BUFFER_FRAME_COUNT 1024 

typedef enum {
    AUDIO_STREAM_OK,
    AUDIO_STREAM_ERR_BUFFER_NOT_READY,
    AUDIO_STREAM_ERR_NOT_INITIALIZED,
    AUDIO_STREAM_ERR_HAL,
} audio_stream_status_e;

audio_stream_status_e audio_stream_init();

bool audio_stream_input_buffer_ready();
bool audio_stream_output_buffer_ready();

// adc_buffer_data must be length AUDIO_STREAM_BUFFER_FRAME_COUNT
audio_stream_status_e audio_stream_read_adc_buffer(int32_t adc_buffer_data[restrict static AUDIO_STREAM_BUFFER_FRAME_COUNT]);

// dac_buffer_data must be length AUDIO_STREAM_BUFFER_FRAME_COUNT
audio_stream_status_e audio_stream_write_dac_buffer(int32_t const dac_buffer_data[restrict static AUDIO_STREAM_BUFFER_FRAME_COUNT]);

#endif // AUDIO_STREAM_H