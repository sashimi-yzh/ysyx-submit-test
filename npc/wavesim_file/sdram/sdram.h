#ifndef SDRAM_H
#define SDRAM_H

#include <stdint.h>
#include <iostream>

#define SDRAM_BASE	0xa0000000
#define SDRAM_END	0xa0ffffff
#define SDRAM_SIZE	0x1000000 * 2


extern "C" uint32_t sdram_read(uint32_t addr);
extern "C" void sdram_write(uint32_t addr, uint32_t data, uint8_t mask);
uint32_t sdram_read_sdb(uint32_t addr);


#endif
