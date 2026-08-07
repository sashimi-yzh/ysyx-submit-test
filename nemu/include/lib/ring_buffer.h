#ifndef __RING_BUFFER_H__
#define __RING_BUFFER_H__
#include <stdbool.h>
typedef struct ring_buffer {
  void *buffer;
  int elem_size;
  int capacity;
  int size;
  int head;
  int tail;
} ring_buffer;

bool ring_buffer_init(ring_buffer *rb, int elemSize, int capacity);
void ring_buffer_free(ring_buffer *rb);
void ring_buffer_push(ring_buffer *rb, void *elem);
void ring_buffer_pop(ring_buffer *rb);
void ring_buffer_peek(ring_buffer *rb, void *elem);
bool ring_buffer_isFull(ring_buffer *rb);
bool ring_buffer_isEmpty(ring_buffer *rb);
int ring_buffer_size(ring_buffer *rb);
#endif