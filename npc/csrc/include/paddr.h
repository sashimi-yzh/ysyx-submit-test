#ifndef __PADDR_H__
#define __PADDR_H__

#include <common.h>

#define RESET_VECTOR (0x30000000)

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
uint8_t* guest_to_host_psram(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
    return (addr >= CONFIG_MBASE) && (addr - CONFIG_MSIZE < (paddr_t)CONFIG_MBASE);
}

word_t paddr_read(paddr_t addr, int len);
word_t mrom_read(paddr_t addr, int len);
word_t flash_read(paddr_t addr, int len);
word_t psram_read(paddr_t addr, int len);
void _psram_write(paddr_t addr, word_t data,int len);
void paddr_write(paddr_t addr, int len, word_t data);
uint32_t inst_fetch(vaddr_t *pc, int len);
word_t isa_reg_str2val(const char *s, bool *success);
static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    case 8: return *(uint64_t *)addr;
    default: assert(0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
    switch (len) {
      case 1: *(uint8_t  *)addr = data; return;
      case 2: *(uint16_t *)addr = data; return;
      case 4: *(uint32_t *)addr = data; return;
      case 8: *(uint64_t *)addr = data; return;
     default: assert(0);
    }
}

#endif
