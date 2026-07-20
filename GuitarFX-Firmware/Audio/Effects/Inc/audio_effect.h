#ifndef AUDIO_EFFECT_H
#define AUDIO_EFFECT_H

#include "audio_common.h"

#include <stdint.h>

typedef void (*audio_effect_process_fn)(audio_sample_t samples[restrict static 1], uint32_t frame_count);
typedef void (*audio_effect_reset_fn)(void);

typedef struct {
    audio_effect_process_fn process;
    audio_effect_reset_fn reset;
} audio_effect_t;

#endif // AUDIO_EFFECT_H