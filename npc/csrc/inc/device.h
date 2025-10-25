#ifndef NPC_DEVICE
#define NPC_DEVICE

#include "tpdef.h"
#include <cstdint>

#define DEV_SERIAL (0xa00003f8)
#define DEV_TIMER  (0xa0000048)

// 0x80404000 - 0x80405000
#define MROM_START  (0x20000000)
#define MROM_END    (0x20001000)

// 0x81000000 - 0x82000000
#define FLASH_START (0x30000000)
#define FLASH_END   (0x31000000)

// 0x80401000 - 0x80403000
#define SRAM_START  (0xf000000)
#define SRAM_END    (0xf002000)

// 0x80000000 - 0x80400000 
#define PSRAM_START (0x80000000)  
#define PSRAM_END   (0x80400000)

// 0x83000000 - 0x87000000
#define SDRAM_START (0xa0000000)
#define SDRAM_END   (0xa4000000)

void device_init();

bool device_call(uint32_t addr, void* data, bool isw);

bool device_visit(paddr_t addr, uint32_t inst);

#endif