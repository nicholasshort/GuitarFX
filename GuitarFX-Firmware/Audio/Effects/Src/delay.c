#include "delay.h"
#include "audio_common.h"

#include <string.h>

#define MAX_DELAY_LINE_LENGTH 24000 // 500ms second delay max

// Delay line ring buffer
typedef struct {
    audio_sample_t line[MAX_DELAY_LINE_LENGTH];
    uint32_t length;
    uint32_t head; // Points to where to add next sample (i.e. the tail data in this example since buffer is always "full")
} delay_line_t;

static delay_line_t delay_line;
static float mix = 0.5f; // (0 <= m <= 1)
static float feedback_gain = 0.5f; // (|g| < 1 to ensure stability)

void delay_process(audio_sample_t samples[restrict static 1], uint32_t frame_count) {

    for (uint32_t i = 0u; i < frame_count; i++) {
        audio_sample_t input = samples[i];
        audio_sample_t delayed = delay_line.line[delay_line.head]; // Delayed is at the tail
        
        delay_line.line[delay_line.head] = input + feedback_gain * delayed;
        delay_line.head++;
        if (delay_line.head >= delay_line.length) delay_line.head = 0u;

        samples[i] = (1-mix) * samples[i] + mix * delayed;
    }
    
}

void delay_reset(void) {

    delay_init();
    
}

void delay_init(void) {

    memset(&delay_line, 0, sizeof(delay_line_t));
    delay_line.length = MAX_DELAY_LINE_LENGTH;
    mix = 0.5f;
    feedback_gain = 0.5f;

}

void delay_set_delay_ms(uint32_t delay_ms) {

    delay_line.length = (delay_ms * AUDIO_SAMPLE_RATE_HZ) / 1000u;
    
    if (delay_line.length > MAX_DELAY_LINE_LENGTH)
        delay_line.length = MAX_DELAY_LINE_LENGTH;

}

