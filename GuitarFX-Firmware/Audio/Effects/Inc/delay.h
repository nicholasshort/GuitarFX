#ifndef DELAY_H
#define DELAY_H

#include "audio_effect.h"
#include "audio_common.h"

typedef audio_effect_t delay_effect_t;

void delay_process(audio_sample_t samples[restrict static 1], uint32_t frame_count);
void delay_reset(void);
void delay_init(void);
void delay_set_delay_ms(uint32_t delay_ms);

#endif // DELAY_H