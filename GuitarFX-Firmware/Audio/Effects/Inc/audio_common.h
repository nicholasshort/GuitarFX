#ifndef AUDIO_TYPES_H
#define AUDIO_TYPES_H

#define AUDIO_SAMPLE_MAX 1.0f
#define AUDIO_SAMPLE_MIN -1.0f

#define AUDIO_SAMPLE_RATE_HZ 48000

typedef float audio_sample_t;

static inline audio_sample_t audio_clamp(audio_sample_t sample) {
    if (sample > AUDIO_SAMPLE_MAX)
        sample = AUDIO_SAMPLE_MAX;
    if (sample < AUDIO_SAMPLE_MIN)
        sample = AUDIO_SAMPLE_MIN;
    return sample;
}

#endif // AUDIO_TYPES_H