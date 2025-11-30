#include <stdint.h>
#include <iostream>
#include <cassert>
#include "../include/common.h"

#if   defined(CONFIG_PMEM_MALLOC)
	uint8_t *mem = NULL;
#else // CONFIG_PMEM_GARRAY
	uint8_t mem[CONFIG_MSIZE] PG_ALIGN = {0};
#endif

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

static inline word_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    IFDEF(CONFIG_ISA64, case 8: return *(uint64_t *)addr);
    default: MUXDEF(CONFIG_RT_CHECK, assert(0), return 0);
  }
}

static inline void host_write(void *addr, int len, word_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    IFDEF(CONFIG_ISA64, case 8: *(uint64_t *)addr = data; return);
    IFDEF(CONFIG_RT_CHECK, default: assert(0));
  }
}

uint8_t* guest_to_host(paddr_t paddr) { return mem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - mem + CONFIG_MBASE; }

static word_t mem_read(paddr_t addr, int len) {
	word_t ret = host_read(guest_to_host(addr), len);
	return ret;
}

static void mem_write(paddr_t addr, int len, word_t data) {
	host_write(guest_to_host(addr), len, data);
}

extern CPU_state cpu;
static void out_of_bound(paddr_t addr) {
	panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD, addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  mem = malloc(CONFIG_MSIZE);
  assert(mem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(mem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
	if (likely(in_pmem(addr))) return mem_read(addr, len);
  //IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { mem_write(addr, len, data); return; }
  //IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

