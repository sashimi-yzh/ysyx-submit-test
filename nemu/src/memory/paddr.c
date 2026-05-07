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

//#define CONFIG_MTRACE

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#define CONFIG_SRAMBASE 0x0f000000
#define CONFIG_SDRAMBASE 0x80000000

static uint8_t sram[0x01000000] PG_ALIGN = {};

static uint8_t sdram[0x20000000] PG_ALIGN = {};

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

uint8_t* guest_to_host_sram(paddr_t paddr) { return sram + paddr - CONFIG_SRAMBASE; }
paddr_t host_to_guest_sram(uint8_t *haddr) { return haddr - sram + CONFIG_SRAMBASE; }

uint8_t* guest_to_host_sdram(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAMBASE; }
paddr_t host_to_guest_sdram(uint8_t *haddr) { return haddr - sdram + CONFIG_SDRAMBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  #ifdef CONFIG_MTRACE
  //log_write("[itrace] read addr:%x, len:%d\n",addr,len);
  #endif
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
  log_write("ERROR\n");
}

static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sram(addr), len);
  #ifdef CONFIG_MTRACE
  log_write("[mtrace] read addr:%x, len:%d, data=%08x\n",addr,len,ret);
  #endif
  return ret;
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sram(addr), len, data);
  #ifdef CONFIG_MTRACE
  log_write("[mtrace] write addr:%x, len:%d, data:%x\n",addr,len,data);
  #endif
}

static word_t sdram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sdram(addr), len);
  #ifdef CONFIG_MTRACE
  log_write("[trace] read addr:%x, len:%d, data=%08x\n",addr,len,ret);
  #endif
  return ret;
}

static void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sdram(addr), len, data);
  #ifdef CONFIG_MTRACE
  log_write("[trace] write addr:%x, len:%d, data:%x\n",addr,len,data);
  #endif
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

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) 
    return pmem_read(addr, len);
  else if(likely(in_sram(addr)))
    return sram_read(addr, len);
  else if(likely(in_sdram(addr)))
    return sdram_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { 
    pmem_write(addr, len, data); 
    return; 
  }
  else if(likely(in_sram(addr))) {
    sram_write(addr, len, data);
    return;
  }
  else if(likely(in_sdram(addr))) {
    sdram_write(addr, len, data);
    return;
  }
  //else return; //so file used to skip
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
