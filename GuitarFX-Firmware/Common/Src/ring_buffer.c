#include "ring_buffer.h"
#include <string.h>

void ring_buffer_queue(ring_buffer_t* ring, void* data) {

    if (!ring || !data)
        return;

    if (ring_buffer_full(ring))
        return;

    memcpy(&ring->buffer[ring->head_index * ring->element_size], data, ring->element_size);

    ring->len++;
    ring->head_index++;

    if (ring->head_index >= ring->buffer_size)
        ring->head_index = 0u;

}

void ring_buffer_dequeue(ring_buffer_t* ring, void* data) {

    if (!ring || !data)
        return;

    if (ring_buffer_empty(ring))
        return;
    
    memcpy(data, &ring->buffer[ring->tail_index * ring->element_size], ring->element_size);

    ring->len--;
    ring->tail_index++;

    if (ring->tail_index >= ring->buffer_size)
        ring->tail_index = 0u;

}

uint32_t ring_buffer_read(ring_buffer_t* ring, void* out_buffer, uint32_t byte_count) {

    if (!ring || !out_buffer)
        return 0u;
    
    if (ring_buffer_empty(ring))
        return 0u;

    byte_count -= byte_count % ring->element_size; // Ensure we are reading full elements
    if (byte_count == 0u)
        return 0u;

    byte_count = byte_count > (ring->len * ring->element_size) ? (ring->len * ring->element_size) : byte_count;

    uint32_t bytes_read = 0;
    while (bytes_read < byte_count) {

        uint32_t bytes_until_wrap = (ring->buffer_size - ring->tail_index) * ring->element_size;
        uint32_t bytes_to_read = bytes_until_wrap < (byte_count - bytes_read) ? bytes_until_wrap : (byte_count - bytes_read);

        memcpy((uint8_t*)out_buffer + bytes_read, &ring->buffer[ring->tail_index * ring->element_size], bytes_to_read);

        uint32_t elements_read = bytes_to_read / ring->element_size;
        bytes_read += bytes_to_read;

        ring->tail_index += elements_read;
        if (ring->tail_index >= ring->buffer_size)
            ring->tail_index -= ring->buffer_size;

        ring->len -= elements_read;
    }
    
    return bytes_read;

}

uint32_t ring_buffer_write(ring_buffer_t* ring, const void* in_buffer, uint32_t byte_count) {

    if (!ring || !in_buffer)
        return 0u;
    
    if (ring_buffer_full(ring))
        return 0u;

    byte_count -= byte_count % ring->element_size; // Ensure we are reading full elements
    if (byte_count == 0u)
        return 0u;

    byte_count = byte_count > ((ring->buffer_size - ring->len) * ring->element_size) ? ((ring->buffer_size - ring->len) * ring->element_size) : byte_count;

    uint32_t bytes_written = 0;
    while (bytes_written < byte_count) {

        uint32_t bytes_until_wrap = (ring->buffer_size - ring->head_index) * ring->element_size;
        uint32_t bytes_to_write = bytes_until_wrap < (byte_count - bytes_written) ? bytes_until_wrap : (byte_count - bytes_written);

        memcpy(&ring->buffer[ring->head_index * ring->element_size], (uint8_t*)in_buffer + bytes_written, bytes_to_write);

        uint32_t elements_written = bytes_to_write / ring->element_size;
        bytes_written += bytes_to_write;

        ring->head_index += elements_written;
        if (ring->head_index >= ring->buffer_size)
            ring->head_index -= ring->buffer_size;

        ring->len += elements_written;
    }
    
    return bytes_written;

}

bool ring_buffer_empty(const ring_buffer_t* ring) {
    return (ring->len == 0);
}

bool ring_buffer_full(const ring_buffer_t* ring) {
    return ((ring->len > 0) && (ring->head_index == ring->tail_index));
}