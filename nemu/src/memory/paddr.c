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
#include <utils.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_YSYXSOC_MODE
bool ysyxsoc_mode = true;
static uint8_t mrom[CONFIG_MROM_SIZE] = {};
static uint8_t sram[CONFIG_SRAM_SIZE] = {};
static uint8_t flash[CONFIG_FLASH_SIZE] = {};
static uint8_t sdram[CONFIG_SDRAM_SIZE] = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) {
  if(in_pmem(paddr))
    return pmem + paddr - CONFIG_MBASE; 
#ifdef CONFIG_YSYXSOC_MODE
  else if(in_mrom(paddr)){
    return mrom + paddr - CONFIG_MROM_BASE;
  }
  else if(in_sram(paddr)){
    return sram + paddr - CONFIG_SRAM_BASE;
  }
  else if(in_flash(paddr)){
    return flash + paddr - CONFIG_FLASH_BASE;
  }
  else if(in_sdram(paddr)){
    return sdram + paddr - CONFIG_SDRAM_BASE;
  }
#endif
  return 0;
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

void print_itrace();
static void out_of_bound(paddr_t addr) {
  print_itrace();
  panic("address = " FMT_PADDR " is out of bound of pmem at pc = " FMT_WORD,
      addr, cpu.pc);
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
  if (likely(in_pmem(addr)
#ifdef CONFIG_YSYXSOC_MODE
    || in_mrom(addr) || in_sram(addr) || in_flash(addr) || in_sdram(addr)
#endif
    )){
    record_mtrace(WRITE_TRACE,addr,len, pmem_read(addr, len));
    return pmem_read(addr, len);
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr)
#ifdef CONFIG_YSYXSOC_MODE
    || in_sram(addr) || in_flash(addr) || in_sdram(addr)
#endif
    )) {
    record_mtrace(READ_TRACE,addr,len, data);
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);

  out_of_bound(addr);
}
