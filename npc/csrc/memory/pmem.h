#ifndef __PMEM_H__
#define __PMEM_H__
#include <sys/time.h>
#include <stdint.h>

#define MROM_START 0x20000000u
#define MROM_SIZE  0x00001000>>2
#define FLASH_START 0x30000000u
#define FLASH_SIZE  0x1000000u>>2
#define PSRAM_START 0x80000000u
#define PSRAM_SIZE  0x2000000u
#define SDRAM_START 0xa0000000u
#define SDRAM_SIZE  0x2000000u
extern uint32_t mrom[MROM_SIZE];
extern uint32_t flash[FLASH_SIZE];
extern uint8_t psram[PSRAM_SIZE];

extern "C" void flash_read(int32_t addr, int32_t *data);
extern "C" void mrom_read(int32_t addr, int32_t *data);
extern "C" void psram_read(int32_t addr, int32_t *data);
extern "C" void psram_write(int32_t addr, int32_t data,int32_t count);
extern "C" void sdram_read(int32_t id,int32_t addr, int32_t *data);
extern "C" void sdram_write(int32_t id,int32_t addr, int32_t data,int32_t dqm);
extern "C" void paddr_read(int32_t addr,int32_t *data);

uint64_t get_time();
#endif
