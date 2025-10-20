#include "../include/common.h"
#include "../include/switch.h"
#include "../include/memory.h"
#include "../include/difftest-def.h"

#include <time.h>
#include <sys/time.h>

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
extern VysyxSoCFull *top;
#define pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
extern Vysyx_25020037_npc *top;
#define pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__pc
#endif

static const uint32_t img [] = {
0x020006b7,          	//lui	a3,0x2000
0x020006b7,          	//lui	a3,0x2000
0x020006b7,          	//lui	a3,0x2000
0x020006b7,          	//lui	a3,0x2000
0x020006b7,          	//lui	a3,0x2000
0x00000513,           //li  a0 0
0x00000513,           //li  a0 0
0x00000513,           //li  a0 0
0x00000513,           //li  a0 0
0x00000513,           //li  a0 0
0x00000513,           //li  a0 0
0x00100073
};

static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
static uint8_t mrom[MROM_MSIZE] PG_ALIGN = {};
static uint8_t flash[FLASH_MSIZE] PG_ALIGN = {};
static uint8_t psram[PSRAM_MSIZE] PG_ALIGN = {};
static uint8_t clk[CLK_SIZE] PG_ALIGN = {};

extern "C" uint8_t* guest_to_host(uint32_t paddr) {
  if(paddr >= CLK_BASE) return clk + paddr - CLK_BASE;
  else if (paddr >= RESET_VECTOR && paddr <= CONFIG_END) {
    return pmem + paddr - CONFIG_MBASE;
  } else {
    printf("Invalid Address: 0x%0x\n", paddr);
    assert(0);
  }
}
#ifdef CONFIG_YSYXSOC
extern "C" {
  word_t host_read(uint8_t *addr, uint8_t len) {
    switch (len) {
      case 1: return *(uint8_t*)addr; break;
      case 2: return *(uint16_t*)addr; break;
      case 4: return *(uint32_t*)addr; break;
      default: return 0x00100073; break;
    }
  }
}

extern "C" {
  void host_write(uint8_t *addr, word_t data, int len) {
    switch (len) {
      case 0x1: *(uint8_t  *)addr = data; return;
      case 0x2: *(uint16_t *)addr = data; return;
      case 0x4: *(uint32_t *)addr = data; return;
    }
  }
}
#else
extern "C" {
  word_t host_read(void *addr, uint8_t len) {
    switch (len) {
      case 1: return *(uint8_t*)addr; break;
      case 2: return *(uint16_t*)addr; break;
      case 4: return *(uint32_t*)addr; break;
      default: return 0x00100073; break;
    }
  }
}

extern "C" {
  static inline void host_write(void *addr, int len, word_t data) {
    switch (len) {
      case 0x1: *(uint8_t  *)addr = data; return;
      case 0x3: *(uint16_t *)addr = data; return;
      case 0xf: *(uint32_t *)addr = data; return;
    }
  }
}
#endif
extern "C" uint8_t* SoC_to_host(uint32_t paddr) {
  if(paddr >= MROM_RESET_VECTOR && paddr <= MROM_BASE_END) {
    return mrom + paddr - MROM_RESET_VECTOR;
  } else if (paddr >= FLASH_RESET_VECTOR && paddr <= FLASH_BASE_END) {
    return flash + paddr - FLASH_RESET_VECTOR;
  } else if(paddr >= PSRAM_CONFIG_START && paddr <= PSRAM_BASE_END){
    return psram + paddr - PSRAM_CONFIG_START;
  } else {
    printf("Invalid Address: 0x%0x\n", paddr);
    assert(0);
  }
}

extern "C" void flash_read(int32_t addr, int32_t *data) {
  addr = FLASH_RESET_VECTOR + addr;
  uint32_t temp = *(uint32_t*)SoC_to_host(addr);
  *data =  ((temp & 0x000000FF) <<24) + ((temp & 0x0000FF00) <<8) + ((temp & 0x00FF0000) >>8) + ((temp & 0xFF000000) >>24);
  //*data = *(uint32_t*)SoC_to_host(addr);
  //printf("flash_r0x%08x  0x%08x\n", addr, temp);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  *data = *(uint32_t*)SoC_to_host(addr); 
}


extern "C" void psram_read(int32_t addr, int32_t *data) {
  addr = PSRAM_CONFIG_START + addr;
  if(addr >= PSRAM_CONFIG_START && addr < PSRAM_BASE_END) {
    *data = host_read(SoC_to_host(addr), 4);
    //printf("pc:0x%08x: psram_r0x%08x  0x%08x\n", pc, addr, *data);
  }
}

extern "C" void psram_write(int32_t addr, int32_t data, int32_t mask) {
  addr = PSRAM_CONFIG_START + addr;
  if(addr >= PSRAM_CONFIG_START && addr < PSRAM_BASE_END) {
    //printf("pc:0x%08x: psram_w0x%08x  0x%08x  0x%x\n", pc, addr, data, mask/2);
    uint32_t wdata = data >> ((8-mask)*4);
    host_write(SoC_to_host(addr), wdata, mask/2);
  }
}

static uint64_t us;

uint64_t get_time() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (uint64_t)tv.tv_sec * 1000000 + tv.tv_usec;
}

extern "C" word_t pmem_read(paddr_t addr, uint8_t len, int trace_on) {
  uint32_t clk_offset = addr - CLK_BASE;
  if(clk_offset >=0 && clk_offset <= 4) {
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    if(clk_offset == 0) return us;
    if(clk_offset == 4) {us = get_time(); return us >> 32;}
  }

  if(addr < 0x80000000 || addr > 0x8fffffff)
    return 0x0000000;
#ifdef CONFIG_MTRACE
  if(trace_on) printf("0x%08x: r\t%08x   %d\n", pc, addr, len);
#endif
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}


extern "C" void pmem_write(paddr_t addr, uint8_t len, word_t data, int trace_on) {
#ifdef CONFIG_MTRACE
  if(trace_on) printf("0x%08x: w\t%08x   %d   0x%08x\n", pc, addr, len, data);
#endif
  if(addr < 0x80000000) { printf("waddr 0x%08x is error\n", addr);assert(0);}
  if((addr & ~0x3u) == UART_BASE) {
#ifdef CONFIG_DIFFTEST
    difftest_skip_ref();
#endif
    //putchar(data&0xff);
    //fflush(stdout);
  }
  else host_write(guest_to_host(addr), len, data);
}

#ifdef CONFIG_YSYXSOC
extern "C" void init_isa() {memcpy(SoC_to_host(FLASH_RESET_VECTOR), img, sizeof(img));}
#else
extern "C" void init_isa() {memcpy(guest_to_host(RESET_VECTOR), img, sizeof(img));}
#endif

extern "C" void init_device() {
  memcpy(guest_to_host(CLK_BASE), clk, sizeof(clk));
}
