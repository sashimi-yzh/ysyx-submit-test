#ifndef __RINGBUF_H__
#define __RINGBUF_H__

typedef struct {
    char buf[16][128];
    int head;  // 写指针
    int tail;  // 读指针
    int size;  // 写入的指令数量
} ring_buffer_t;

extern ring_buffer_t ring_buffer;

#endif