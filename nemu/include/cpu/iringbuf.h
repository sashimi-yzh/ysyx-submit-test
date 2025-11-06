#ifndef __CPU_IRINGBUF_H__
#define __CPU_IRINGBUF_H__

#include <common.h>

#define MAX_INST_BUFFER 10

typedef struct RING_BUFFER{
    char inst[MAX_INST_BUFFER][1024];
    int start;
    int end;
    bool store; // 是否开始存储指令
} INST_BUFFER;

void init_inst_buffer();
void write_inst_buffer(char* inst);
void print_inst_buffer();

#endif