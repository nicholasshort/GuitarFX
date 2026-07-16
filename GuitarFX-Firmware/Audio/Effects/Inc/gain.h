#ifndef GAIN_H
#define GAIN_H

#include "audio_effect.h"

typedef audio_effect_t gain_effect_t;

void gain_process(audio_effect_t* gain_effect, int32_t samples[restrict static 1], uint32_t frame_count);
void gain_init(audio_effect_t* gain_effect);

#endif // GAIN_H