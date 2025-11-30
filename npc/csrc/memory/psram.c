#include <stdio.h>
#include "../include/common.h"

uint8_t psram[0x4000000] PG_ALIGN = {};

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

static uint8_t* guest_to_psram(paddr_t paddr) { return psram + paddr; }
static paddr_t psram_to_guest(uint8_t *haddr) { return haddr - psram; }

int c_psram_read(int addr) {
  return host_read(guest_to_psram(addr), 4);
}

void c_psram_write(int addr, int data, int8_t len) {
	//printf("psram:%08x %08x %08x %08x %08x %08x\n",psram[0],psram[4],psram[8],psram[0xc],psram[0x10],psram[0x14]);
	host_write(guest_to_psram(addr), len, data);
	return;
}

