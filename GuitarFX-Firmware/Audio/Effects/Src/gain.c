#include "gain.h"
#include "audio_common.h"

#include <stdint.h>

static float gain = 0.5f;

void gain_process(audio_sample_t samples[restrict static 1], uint32_t frame_count) {
    
    for (uint32_t i = 0u; i < frame_count; i++) {
        samples[i] = audio_clamp(samples[i] * gain);
    }
    
}

void gain_reset(void) {
    
}

void gain_set(float g) {

    gain = g;

}