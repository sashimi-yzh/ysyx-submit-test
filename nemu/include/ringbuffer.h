#ifndef __RINGBUFFER_H__
#define __RINGBUFFER_H__
#include "common.h"
#include <stdbool.h>
#include <stdint.h>

typedef struct {
  vaddr_t pc;
  uint32_t inst;
} InstrInfo;

typedef struct {
  int sz, count;
  int begin, end;
  InstrInfo *data;
} RingBuffer;

#ifdef CONFIG_INST_RINGBUFFER
extern RingBuffer inst_buffer;
#endif

RingBuffer *createRingbuffer(int size);
void pushRingBuffer(RingBuffer *rb, vaddr_t pc, uint32_t inst);
void freeRingbuffer(RingBuffer *rb);

void showRingBuffer(const RingBuffer *rb);

#endif