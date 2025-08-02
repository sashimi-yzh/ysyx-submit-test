#ifndef MEMORY_H
#define MEMORY_H

#include <stdint.h>

#define RESET_VECTOR (uint32_t)0x30000000
#define CONFIG_MBASE (uint32_t)0x30000000

#define CONFIG_FLASH_BASE (uint32_t)0x30000000
#define CONFIG_SRAM_BASE (uint32_t)0x0f000000

long load_img(char *img);
uint32_t pmem_read(uint32_t addr, int len);
uint8_t* guest_to_host(uint32_t paddr);

#endif // MEMORY_H

