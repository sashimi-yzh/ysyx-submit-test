#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "common.h"

#ifdef CONFIG_SOC

#define PMEM_LEFT_MROM  ((paddr_t)CONFIG_MROM_BASE)
#define PMEM_RIGHT_MROM ((paddr_t)CONFIG_MROM_BASE + CONFIG_MROM_SIZE - 1)

#define PMEM_LEFT_SRAM  ((paddr_t)CONFIG_SRAM_BASE)
#define PMEM_RIGHT_SRAM ((paddr_t)CONFIG_SRAM_BASE + CONFIG_SRAM_SIZE - 1)

#define PMEM_LEFT_FLASH  ((paddr_t)CONFIG_FLASH_BASE)
#define PMEM_RIGHT_FLASH ((paddr_t)CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE - 1)

#define PMEM_LEFT_PSRAM  ((paddr_t)CONFIG_PSRAM_BASE)
#define PMEM_RIGHT_PSRAM ((paddr_t)CONFIG_PSRAM_BASE + CONFIG_PSRAM_SIZE - 1)

#define PMEM_LEFT_SDRAM  ((paddr_t)CONFIG_SDRAM_BASE)
#define PMEM_RIGHT_SDRAM ((paddr_t)CONFIG_SDRAM_BASE + CONFIG_SDRAM_SIZE - 1)

// #define RESET_VECTOR (PMEM_LEFT_FLASH + CONFIG_PC_RESET_OFFSET)

static inline bool in_mrom(paddr_t addr) {
    return addr >= PMEM_LEFT_MROM && addr <= PMEM_RIGHT_MROM;
}

static inline bool in_sram(paddr_t addr) {
    return addr >= PMEM_LEFT_SRAM && addr <= PMEM_RIGHT_SRAM;
}

static inline bool in_flash(paddr_t addr) {
    return addr >= PMEM_LEFT_FLASH && addr <= PMEM_RIGHT_FLASH;
}

static inline bool in_psram(paddr_t addr) {
    return addr >= PMEM_LEFT_PSRAM && addr <= PMEM_RIGHT_PSRAM;
}

static inline bool in_sdram(paddr_t addr) {
    return addr >= PMEM_LEFT_SDRAM && addr <= PMEM_RIGHT_SDRAM;
}

static inline bool in_pmem(paddr_t addr) {
    return in_mrom(addr) || in_sram(addr) || in_flash(addr) || in_psram(addr) || in_sdram(addr);
}

#else

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

// #define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

#endif

static inline word_t host_read(uint8_t *addr) {
    return *(word_t *)addr;
}

static inline void host_write(uint8_t *addr, word_t wdata, uint32_t len) {
    switch (len)
    {
        case 1: *(uint8_t  *)addr = wdata; break;
        case 2: *(uint16_t *)addr = wdata; break;
        case 4: *(uint32_t *)addr = wdata; break;
        default: printf("Error write!\n"); assert(0); break;
    }
}

#endif