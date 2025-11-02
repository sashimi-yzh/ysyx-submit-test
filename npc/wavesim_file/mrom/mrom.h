#ifndef MROM_H
#define MROM_H

#include <iostream>
#include <stdint.h>
#include <cassert>

#define MROM_BASE	0x20000000
#define MROM_EDN	0x20000fff
#define MROM_SIZE	0x1000

long init_mrom(const char* img_file);

extern "C" void mrom_read(int32_t addr, int32_t *data);

#endif
