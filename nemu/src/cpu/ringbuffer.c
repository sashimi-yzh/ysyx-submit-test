#include "ringbuffer.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef CONFIG_INST_RINGBUFFER
static InstrInfo instbuffer_data[CONFIG_RINGBUFFER_SIZE];
RingBuffer inst_buffer = {.sz = CONFIG_RINGBUFFER_SIZE,
                          .begin = 0,
                          .end = 0,
                          .count = 0,
                          .data = instbuffer_data};
#endif

RingBuffer *createRingbuffer(int size) {
  RingBuffer *rb = malloc(sizeof(RingBuffer));
  rb->data = calloc(sizeof(InstrInfo), size);
  rb->sz = size;
  rb->begin = rb->end = rb->count = 0;
  return rb;
}
void pushRingBuffer(RingBuffer *rb, vaddr_t pc, uint32_t inst) {
  rb->data[rb->end].pc = pc;
  rb->data[rb->end].inst = inst;
  rb->end++;
  if (rb->end == rb->sz)
    rb->end = 0;
  if (rb->count != rb->sz)
    rb->count++;
  else
    rb->begin = rb->end;
}
void freeRingbuffer(RingBuffer *rb) {
  free(rb->data);
  free(rb);
}

void showRingBuffer(const RingBuffer *rb) {
  for (int i = 0, pos = rb->begin; i < rb->count;
       i++, pos = (pos + 1) % rb->sz) {
    if (i == rb->count - 1)
      fprintf(stderr, "%s\033[1;31m", "to be executed --> ");
    else
      fprintf(stderr, "%s", "                   ");
    fprintf(stderr, "%08x : %08x  ;", rb->data[pos].pc, rb->data[pos].inst);
    void fdisassemble(FILE * fp, uint64_t pc, uint8_t *code, int nbyte);
    fdisassemble(stderr, rb->data[pos].pc, (uint8_t *)&(rb->data[pos].inst), 4);
    if (i == rb->count - 1)
      fprintf(stderr, "\033[0m");
    fputc('\n', stderr);
  }
}