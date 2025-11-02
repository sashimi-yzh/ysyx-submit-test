#ifndef VGA_H
#define VGA_H

#include <stdint.h>
#include <iostream>

#define FB_BASE		0x21000000
#define FB_END		0x211fffff
#define FB_SIZE		0x200000


extern "C" uint32_t vga_read(uint32_t addr);
extern "C" void vga_write(uint32_t addr, uint32_t data);

#endif
