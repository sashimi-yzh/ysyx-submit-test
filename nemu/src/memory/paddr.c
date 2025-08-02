/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <memory/host.h>
#include <memory/paddr.h>
#include <device/mmio.h>
#include <isa.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

/////////////////// for difftest /////////////////////////

// skip some device access for difftest
#define CLINT_START 0x02000000
#define CLINT_END   0x0200ffff

#define UART_START  0x10000000
#define UART_END    0x10000fff

#define SPI_START   0x10001000
#define SPI_END     0x10001fff

#define PS2_START  0x10011000
#define PS2_END    0x10011007

// for ysyxsoc difftest add sram start
#define CONFIG_SRAM_BASE  0x0f000000
#define CONFIG_SRAM_SIZE  0x2000
#define CONFIG_SRAM_END   (CONFIG_SRAM_BASE  + CONFIG_SRAM_SIZE)
static uint8_t sram[CONFIG_SRAM_SIZE] PG_ALIGN = {};
uint8_t* guest_to_host_sram(paddr_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
paddr_t host_to_guest_sram(uint8_t *haddr) { return haddr - sram + CONFIG_SRAM_BASE; }
static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sram(addr), len);
  return ret;
}
static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sram(addr), len, data);
}
// for ysyxsoc difftest add sram end

// for ysyxsoc difftest add sdram start
#define CONFIG_SDRAM_BASE  0xa0000000
#define CONFIG_SDRAM_SIZE  0x2000000
#define CONFIG_SDRAM_END   (CONFIG_SDRAM_BASE  + CONFIG_SDRAM_SIZE)
static uint8_t sdram[CONFIG_SDRAM_SIZE] PG_ALIGN = {};
uint8_t* guest_to_host_sdram(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAM_BASE; }
paddr_t host_to_guest_sdram(uint8_t *haddr) { return haddr - sdram + CONFIG_SDRAM_BASE; }
static word_t sdram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sdram(addr), len);
  return ret;
}
static void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sdram(addr), len, data);
}
// for ysyxsoc difftest add sdram end

/////////////////// end /////////////////////////

word_t paddr_read(paddr_t addr, int len) {
  IFDEF(CONFIG_MTRACE, Log("read in address = " FMT_PADDR ", len = %d\n", addr, len));
  if (likely(in_pmem(addr))) {
    return pmem_read(addr, len);  
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));

  // for ysyxsoc difftest
  if(addr >=  CONFIG_SRAM_BASE  &&  addr <= CONFIG_SRAM_END) return sram_read(addr, len);
  if(addr >=  CONFIG_SDRAM_BASE  &&  addr <= CONFIG_SDRAM_END) return sdram_read(addr, len);

  // device access
  if(addr >=  CLINT_START  &&  addr <= CLINT_END) { return 0; }
  if(addr >=  UART_START  &&  addr <= UART_END) { return 0; }
  if(addr >=  SPI_START  &&  addr <= SPI_END) { return 0; }
  if(addr >=  PS2_START  &&  addr <= PS2_END) { return 0; }

  printf("paddr_read addr = 0x%x\n", addr);

  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE, Log("write in address = " FMT_PADDR ", len = %d, data = " FMT_WORD "\n", addr, len, data));
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);

  // for ysyxsoc difftest
  if(addr >=  CONFIG_SRAM_BASE  &&  addr <= CONFIG_SRAM_END) { sram_write(addr, len, data); return; }
  if(addr >=  CONFIG_SDRAM_BASE  &&  addr <= CONFIG_SDRAM_END) { sdram_write(addr, len, data); return; }
  // printf("addr == 0x%x\n data == 0x%x\n",addr, data); 

  // device access
  if(addr >=  CLINT_START  &&  addr <= CLINT_END) { return; }
  if(addr >=  UART_START  &&  addr <= UART_END) { return; }
  if(addr >=  SPI_START  &&  addr <= SPI_END) { return; }
  if(addr >=  PS2_START  &&  addr <= PS2_END) { return; }

  printf("paddr_write addr = 0x%x\n", addr);

  out_of_bound(addr);
}
