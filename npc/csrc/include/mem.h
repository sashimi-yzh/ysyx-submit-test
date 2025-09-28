#ifndef __MEM_H__
#define __MEM_H__

#include "common.h"

#ifdef YSYXSOC

#define MROM_BASE 0x20000000
#define MROM_SIZE 4096
#define SRAM_BASE 0x0f000000
#define SRAM_SIZE 8192
#define FLASH_BASE 0x30000000
#define FLASH_SIZE 0x1000000
#define PSRAM_BASE 0x80000000
#define PSRAM_SIZE 0x400000
#define SDRAM_BASE 0xa0000000
#define SDRAM_SIZE 0x8000000

struct MemMap {
  const char* name;
  addr_t start;
  addr_t size;
  uint8_t *ptr;
  bool readonly;
};

const MemMap *get_mem_map(addr_t addr, bool panic_if_out);

#else

#define MEM_BASE 0x80000000
#define MEM_SIZE 0x8000000

#endif

#define PG_ALIGN __attribute((aligned(4096)))

uint8_t *guest_to_host(addr_t addr);

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    IFDEF(RV64, case 8: return *(uint64_t *)addr);
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    IFDEF(RV64, case 8: *(uint64_t *)addr = data; return);
    default: assert(0);
  }
}

word_t addr_read(addr_t addr, int len);
void addr_write(addr_t addr, int len, word_t data);

#endif
