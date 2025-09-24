#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#define PMEM_LEFT ((paddr_t)CONFIG_PMEM_BASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_PMEM_BASE + CONFIG_PMEM_SIZE - 1)
#define FLASH_LEFT ((paddr_t)CONFIG_FLASH_BASE)
#define FLASH_RIGHT ((paddr_t)CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE - 1)
#define SDRAM_LEFT ((paddr_t)CONFIG_SDRAM_BASE)
#define SDRAM_RIGHT ((paddr_t)CONFIG_SDRAM_BASE + CONFIG_SDRAM_SIZE - 1)

#ifdef ysyx_23060170_NPC
#define RESET_VECTOR PMEM_LEFT
#else
#define RESET_VECTOR FLASH_LEFT
#endif

uint8_t *guest_to_host(paddr_t paddr);

/* uint8_t diff_mem_read(int idx); */

static inline bool in_pmrom(paddr_t addr) {
  return addr >= CONFIG_MROM_BASE && addr < CONFIG_MROM_BASE + CONFIG_MROM_SIZE;
}

static inline bool in_pflash(paddr_t addr) {
  return addr >= CONFIG_FLASH_BASE && addr < CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE;
}

static inline bool in_psram(paddr_t addr) {
  return addr >= CONFIG_PSRAM_BASE && addr < CONFIG_PSRAM_BASE + CONFIG_PSRAM_SIZE;
}

static inline bool in_sdram(paddr_t addr) {
  return addr >= CONFIG_SDRAM_BASE && addr < CONFIG_SDRAM_BASE + CONFIG_SDRAM_SIZE;
}

static inline bool in_pmem(paddr_t addr) {
  return addr >= CONFIG_PMEM_BASE && addr < CONFIG_PMEM_BASE + CONFIG_PMEM_SIZE;
}

#endif
