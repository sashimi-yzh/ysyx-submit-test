#ifndef __IRINGBUF_H__
#define __IRINGBUF_H__

#define RINGBUF_MAX 20

void init_ringbuf();
void iringbuf(uint32_t thispc);
void iringbuf_printf();
void close_ringbuf();

#endif