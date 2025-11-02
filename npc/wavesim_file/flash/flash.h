#ifndef FLASH_H
#define FLASH_H

#include <iostream>
#include <stdint.h>

#define FLASH_BASE	0x30000000
#define FLASH_END	0x3fffffff
#define FLASH_SIZE	0xfffffff


long init_flash(const char* img_file);

extern "C" void flash_read(int32_t addr, int32_t *data);
void flash_read_sdb(int32_t addr, int32_t *data);

#endif
