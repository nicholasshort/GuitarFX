#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t* buffer;
    uint32_t buffer_size;   // Max buffer len
    uint32_t element_size;  // Number of bytes per element
    uint32_t head_index;    // Where the next element should be queued
    uint32_t tail_index;    // Points to next dequeue element
    uint32_t len;           // Number of elements in buffer
} ring_buffer_t;

#define RING_BUFFER(name, size, type, storage)                  \
    storage uint8_t name##_buffer[size * sizeof(type)] = {0};   \
    storage ring_buffer_t name = {                              \
        .buffer = name##_buffer,                                \
        .buffer_size = size,                                    \
        .element_size = sizeof(type),                           \
        .head_index = 0u,                                       \
        .tail_index = 0u,                                       \
        .len = 0u                                               \
    }

#define LOCAL_RING_BUFFER(name, size, type) RING_BUFFER(name, size, type,)
#define STATIC_RING_BUFFER(name, size, type) RING_BUFFER(name, size, type, static) 

void ring_buffer_queue(ring_buffer_t* ring, void* data);
void ring_buffer_dequeue(ring_buffer_t* ring, void* data);
uint32_t ring_buffer_read(ring_buffer_t* ring, void* out_buffer, uint32_t byte_count);
uint32_t ring_buffer_write(ring_buffer_t* ring, const void* in_buffer, uint32_t byte_count);
bool ring_buffer_empty(const ring_buffer_t* ring);
bool ring_buffer_full(const ring_buffer_t* ring);

#endif // RING_BUFFER_H