#ifndef PSRAM_H
#define PSRAM_H

#include <stdint.h>
#include <iostream>

#define PSRAM_BASE	0x80000000
#define PSRAM_END	0x803fffff
//#define PSRAM_END	0x9fffffff //注意用到的psram只有4MB
#define PSRAM_SIZE	0x400000

extern "C" uint32_t psram_read(uint32_t addr);
extern "C" void psram_write(uint32_t addr, uint32_t data, uint8_t bytes_to_write);

#endif
