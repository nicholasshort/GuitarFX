#ifndef AUDIO_EFFECT_H
#define AUDIO_EFFECT_H

#include <stdint.h>

typedef struct audio_effect audio_effect_t;

typedef void (*audio_effect_process_fn)(audio_effect_t* effect, int32_t samples[restrict static 1], uint32_t frame_count);
typedef void (*audio_effect_init_fn)(audio_effect_t* effect);

struct audio_effect {
    audio_effect_process_fn process;
    audio_effect_init_fn init;
    void* context;
};

#endif // AUDIO_EFFECT_H