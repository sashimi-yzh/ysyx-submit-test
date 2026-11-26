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

#ifdef YSYXSOC_REF

static uint8_t flash[FLASH_SIZE] PG_ALIGN = {};
static uint8_t sram[SRAM_SIZE] PG_ALIGN = {};
static uint8_t sdram[SDRAM_SIZE] PG_ALIGN = {};

uint8_t* guest_to_host(paddr_t paddr) { assert(in_flash(paddr)); return flash + (paddr - FLASH_LEFT); }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - flash + FLASH_LEFT; }

bool in_flash(paddr_t addr) { return addr - FLASH_LEFT < FLASH_SIZE; }
bool in_sram(paddr_t addr) { return addr - SRAM_LEFT < SRAM_SIZE; }
bool in_sdram(paddr_t addr) { return addr - SDRAM_LEFT < SDRAM_SIZE; }
uint8_t* flash_to_host(paddr_t paddr) { return flash + (paddr - FLASH_LEFT); }
uint8_t* sram_to_host(paddr_t paddr) { return sram + (paddr - SRAM_LEFT); }
uint8_t* sdram_to_host(paddr_t paddr) { return sdram + (paddr - SDRAM_LEFT); }
#else
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }
#endif

#ifdef CONFIG_MTRACE
static void mtrace_read(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE_COND
  if (MTRACE_COND) {
    log_write("[MTRACE] READ  at " FMT_PADDR " len=%d data=" FMT_WORD " pc=" FMT_WORD "\n", 
              addr, len, data, cpu.pc);
  }
#endif
}

static void mtrace_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE_COND
  if (MTRACE_COND) {
    log_write("[MTRACE] WRITE at " FMT_PADDR " len=%d data=" FMT_WORD " pc=" FMT_WORD "\n", 
              addr, len, data, cpu.pc);
  }
#endif
}
#endif

#ifndef YSYXSOC_REF
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}
#endif

static void out_of_bound(paddr_t addr) {
#ifdef YSYXSOC_REF
  panic("address = " FMT_PADDR " is out of bound of SoC memory (FLASH/SRAM/SDRAM) at pc = " FMT_WORD,
      addr, cpu.pc);
#else
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
#endif
}

void init_mem() {
#ifdef YSYXSOC_REF
  IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), FLASH_SIZE));
  Log("SoC memory: FLASH [" FMT_PADDR ", " FMT_PADDR "], SRAM [" FMT_PADDR ", " FMT_PADDR "], SDRAM [" FMT_PADDR ", " FMT_PADDR "]",
      FLASH_LEFT, FLASH_RIGHT, SRAM_LEFT, SRAM_RIGHT, SDRAM_LEFT, SDRAM_RIGHT);
#else
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#endif
}

word_t paddr_read(paddr_t addr, int len) {
#ifdef YSYXSOC_REF
  if (in_flash(addr)) {
    word_t ret = host_read(flash_to_host(addr), len);
    IFDEF(CONFIG_MTRACE, mtrace_read(addr, len, ret));
    return ret;
  }
  if (in_sram(addr)) {
    word_t ret = host_read(sram_to_host(addr), len);
    IFDEF(CONFIG_MTRACE, mtrace_read(addr, len, ret));
    return ret;
  }
  if (in_sdram(addr)) {
    word_t ret = host_read(sdram_to_host(addr), len);
    IFDEF(CONFIG_MTRACE, mtrace_read(addr, len, ret));
    return ret;
  }
#else
  if (in_pmem(addr)) {
    word_t ret = pmem_read(addr, len);
    IFDEF(CONFIG_MTRACE, mtrace_read(addr, len, ret));
    return ret;
  }
#endif
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE, mtrace_write(addr, len, data));
#ifdef YSYXSOC_REF
  if (in_flash(addr)) { return; }  // FLASH 只读 (XIP)
  if (in_sram(addr)) { host_write(sram_to_host(addr), len, data); return; }
  if (in_sdram(addr)) { host_write(sdram_to_host(addr), len, data); return; }
#else
  if (in_pmem(addr)) { pmem_write(addr, len, data); return; }
#endif
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
