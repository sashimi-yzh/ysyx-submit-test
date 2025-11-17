/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
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
#include <ringbuffer.h>
#include <device/soc.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
static uint8_t *mrom =NULL;
static uint8_t *sram =NULL;
static uint8_t *flash =NULL;
IFDEF(CONFIG_HAS_SDRAM,static uint8_t *sdram =NULL);
IFDEF(CONFIG_HAS_PSRAM,static uint8_t *psram =NULL);

#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#ifdef CONFIG_HAS_MROM
  static uint8_t mrom[CONFIG_MROM_SIZE]  = {};
#endif
#ifdef CONFIG_HAS_SRAM
  uint8_t sram[CONFIG_SRAM_SIZE]  = {};
#endif
#ifdef CONFIG_HAS_SDRAM
  uint8_t sdram[CONFIG_SDRAM_SIZE]  = {};
#endif
#ifdef CONFIG_HAS_PSRAM
  uint8_t psram[CONFIG_PSRAM_SIZE]  = {};
#endif
#ifdef CONFIG_HAS_FLASH
  uint8_t flash[CONFIG_FLASH_SIZE]  = {};
#endif
#endif

#ifdef CONFIG_ITRACE
  extern RingBuffer *log_buff;
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

#ifdef CONFIG_HAS_MROM

uint8_t* guest_to_mrom(paddr_t paddr) { return mrom + paddr - CONFIG_MROM_BASE; }
paddr_t host_to_mrom(uint8_t *haddr) { return haddr - mrom + CONFIG_MROM_BASE; }
#endif

#ifdef CONFIG_HAS_SRAM
uint8_t* guest_to_sram(paddr_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
paddr_t host_to_sram(uint8_t *haddr) { return haddr - sram + CONFIG_SRAM_BASE; }
#endif

#ifdef CONFIG_HAS_PSRAM
uint8_t* guest_to_psram(paddr_t paddr) { return sram + paddr - CONFIG_PSRAM_BASE; }
paddr_t host_to_psram(uint8_t *haddr) { return haddr - sram + CONFIG_PSRAM_BASE; }
#endif

#ifdef CONFIG_HAS_FLASH
uint8_t* guest_to_flash(paddr_t paddr) { return sram + paddr - CONFIG_FLASH_BASE; }
paddr_t host_to_flash(uint8_t *haddr) { return haddr - sram + CONFIG_FLASH_BASE; }
#endif

#ifdef CONFIG_HAS_SDRAM
uint8_t* guest_to_sdram(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAM_BASE; }
paddr_t host_to_sdram(uint8_t *haddr) { return haddr - sdram + CONFIG_SDRAM_BASE; }
#endif
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret;
  if (in_pmem(addr)) ret = host_read(guest_to_host(addr), len);
  #ifdef CONFIG_HAS_SRAM
  else if (in_sram_pmem(addr)) ret = host_read(guest_to_sram(addr), len);
  #endif
  #ifdef CONFIG_HAS_MROM
  else if (in_mrom_pmem(addr)) ret = host_read(guest_to_mrom(addr), len);
  #endif
    #ifdef CONFIG_HAS_FLASH
  else if (in_flash_pmem(addr)) ret = host_read(guest_to_flash(addr), len);
  #endif
  #ifdef CONFIG_HAS_PSRAM
  else if (in_psram_pmem(addr)) ret = host_read(guest_to_psram(addr), len);
  #endif
  #ifdef CONFIG_HAS_SDRAM
  else if (in_sdram_pmem(addr)) ret = host_read(guest_to_sdram(addr), len);
  #endif
  else panic("pmem_read:\taddr = 0x%x\n not support", addr);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
    log_write("W\t0x%x\t%d\n",addr,len);
  #endif
  if (in_pmem(addr))   host_write(guest_to_host(addr), len, data);
  #ifdef CONFIG_HAS_SRAM
  else if (in_sram_pmem(addr)) host_write(guest_to_sram(addr), len, data);
  #endif
  #ifdef CONFIG_HAS_MROM
  else if (in_mrom_pmem(addr)) host_write(guest_to_mrom(addr), len, data);
  #endif
  #ifdef CONFIG_HAS_FLASH
  else if (in_flash_pmem(addr)) host_write(guest_to_flash(addr), len, data);
  #endif
  #ifdef CONFIG_HAS_PSRAM
  else if (in_psram_pmem(addr)) host_write(guest_to_psram(addr), len, data);
  #endif
  #ifdef CONFIG_HAS_SDRAM
  else if (in_sdram_pmem(addr)) host_write(guest_to_sdram(addr), len, data);
  #endif
  else panic("pmem_write:\taddr = 0x%x\n not support", addr);
  // printf("pmem_write:\taddr = 0x%x\n", addr);
}

static void out_of_bound(paddr_t addr) {
  #ifdef CONFIG_ITRACE
    char itrace_log[LOG_BUFSIZE];
    RingBuffer_get(log_buff,itrace_log,RingBuffer_length(log_buff));
    log_write("%s\n", itrace_log);
  #endif
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "], at pc = " FMT_WORD, 
    addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}



void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC) 
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
  #ifdef CONFIG_HAS_MROM
  mrom = malloc(CONFIG_MROM_SIZE);
  assert(mrom);
  #endif
  #ifdef CONFIG_HAS_SRAM
  sram = malloc(CONFIG_SRAM_SIZE);
  assert(sram);
  #endif
  #ifdef CONFIG_HAS_PSRAM
  psram = malloc(CONFIG_PSRAM_SIZE);
  assert(sram);
  #endif
  #ifdef CONFIG_HAS_SDRAM
  sdram = malloc(CONFIG_SDRAM_SIZE);
  assert(sram);
  #endif
  #ifdef CONFIG_HAS_FLASH
  flash = malloc(CONFIG_FLASH_SIZE);
  assert(sram);
  #endif
#endif
#ifdef CONFIG_MEM_RANDOM
  IFNDEF(COMFIG_HAS_MROM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#endif
}

word_t paddr_read(paddr_t addr, int len) {

  #ifdef CONFIG_MTRACE
    log_write("R\t0x%x\t%d\n",addr,len);
  #endif
  if (likely(in_pmem(addr))     || 
    likely(in_mrom_pmem(addr))  ||
    likely(in_sram_pmem(addr))  ||
    likely(in_flash_pmem(addr)) ||
    likely(in_psram_pmem(addr))   ||
    likely(in_sdram_pmem(addr))) return pmem_read(addr, len);
  else if (likely(in_uart_pmem(addr)))  return 0x20;
  else if (likely(in_clint_pmem(addr))) return clint_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr); 
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr)) || 
    likely(in_mrom_pmem(addr)) ||
    likely(in_sram_pmem(addr)) ||
    likely(in_flash_pmem(addr)) ||
    likely(in_psram_pmem(addr))   ||
    likely(in_sdram_pmem(addr))
  )  { pmem_write(addr, len, data); return; }
  if (likely(in_uart_pmem(addr))) return uart_write(addr, len, data); 
  if (likely(in_clint_pmem(addr))) return;

  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);

  out_of_bound(addr);
}
