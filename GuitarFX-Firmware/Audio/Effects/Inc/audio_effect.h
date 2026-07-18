#ifndef AUDIO_EFFECT_H
#define AUDIO_EFFECT_H

#include <stdint.h>

#define INT24_MIN (-8388608)
#define INT24_MAX 8388607

typedef void (*audio_effect_process_fn)(int32_t samples[restrict static 1], uint32_t frame_count);
typedef void (*audio_effect_reset_fn)(void);

typedef struct {
    audio_effect_process_fn process;
    audio_effect_reset_fn reset;
} audio_effect_t;

#endif // AUDIO_EFFECT_H