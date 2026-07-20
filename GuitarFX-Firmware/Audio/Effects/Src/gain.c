#include "gain.h"
#include "audio_types.h"

#include <stdint.h>

static float gain = 0.5f;

void gain_process(int32_t samples[restrict static 1], uint32_t frame_count) {
    
    float result = 0.0f;
    for (uint32_t i = 0u; i < frame_count; i++) {
        result = samples[i] * gain;
        if (result > INT24_MAX)
            result = INT24_MAX;
        else if (result < INT24_MIN)
            result = INT24_MIN;
        samples[i] = (int32_t)result;
    }
    
}

void gain_reset(void) {
    
}

void gain_set(float g) {

    gain = g;

}