#ifndef _iRingBuffer_h
#define _iRingBuffer_h

#include <common.h>

typedef struct {
    uint32_t pc;
    char logbuf[128];
} IRingBuffer;

void iringbuf_write(uint32_t pc, char* logbuf);
void iringbuf_print();

#endif