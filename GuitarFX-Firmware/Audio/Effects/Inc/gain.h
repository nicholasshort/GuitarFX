#ifndef GAIN_H
#define GAIN_H

#include "audio_effect.h"

typedef audio_effect_t gain_effect_t;

void gain_process(float samples[restrict static 1], uint32_t frame_count);
void gain_reset(void);
void gain_init(float gain);

#endif // GAIN_H