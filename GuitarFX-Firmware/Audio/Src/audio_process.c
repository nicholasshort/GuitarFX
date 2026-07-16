#include "audio_process.h"
#include "audio_stream.h"
#include <stdbool.h>

static int32_t processed_audio_buffer[AUDIO_STREAM_BUFFER_FRAME_COUNT];

void audio_process_poll(audio_effect_t* audio_effect) {
    
    // Read incoming audio
    if (!audio_stream_adc_buffer_ready())
        return;
    
    if (audio_stream_read_adc_buffer(processed_audio_buffer) != AUDIO_STREAM_OK)
        return;

    audio_effect->process(audio_effect, processed_audio_buffer, AUDIO_STREAM_BUFFER_FRAME_COUNT);

    // Output processed audio
    if (!audio_stream_dac_buffer_ready())
        return;
    
    if(audio_stream_write_dac_buffer(processed_audio_buffer) != AUDIO_STREAM_OK)
        return;
        
}

