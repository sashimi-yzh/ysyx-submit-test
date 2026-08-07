#include <lib/ring_buffer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool ring_buffer_init(ring_buffer *rb, int elemSize, int capacity) {
  rb->buffer = malloc(elemSize * capacity);
  if (!rb->buffer)
    return false;
  rb->elem_size = elemSize;
  rb->capacity = capacity;
  rb->size = 0;
  rb->head = rb->tail = 0;
  return true;
}

void ring_buffer_free(ring_buffer *rb) {
  if (rb == NULL)
    return;
  if (rb->buffer != NULL) {
    free(rb->buffer);
    rb->buffer = NULL;
  }
  free(rb);
}

void ring_buffer_push(ring_buffer *rb, void *elem) {
  if (rb->size == rb->capacity)
    return;
  memcpy((char *)rb->buffer + rb->tail * rb->elem_size, elem, rb->elem_size);
  rb->tail = (rb->tail + 1) % rb->capacity;
  rb->size++;
}
void ring_buffer_pop(ring_buffer *rb) {
  if (rb->size == 0)
    return;
  rb->head = (rb->head + 1) % rb->capacity;
  rb->size--;
}
void ring_buffer_peek(ring_buffer *rb, void *elem) {
  if (rb->size == 0)
    return;
  memcpy(elem, (char *)rb->buffer + rb->head * rb->elem_size, rb->elem_size);
}

bool ring_buffer_isFull(ring_buffer *rb) {
  return rb->size == rb->capacity;
}
bool ring_buffer_isEmpty(ring_buffer *rb) { return rb->size == 0; }

int ring_buffer_size(ring_buffer *rb) {
  return rb->size;
}