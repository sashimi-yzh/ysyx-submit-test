#ifndef __DTRACE_H
#define __DTRACE_H
#include <device/map.h>
void dtrace_read(paddr_t addr, int len, IOMap *map);
void dtrace_write(paddr_t addr, int len, word_t data, IOMap *map);
#endif
