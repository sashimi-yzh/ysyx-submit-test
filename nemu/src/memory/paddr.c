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

#ifndef CONFIG_TARGET_SHARE
#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

uint32_t memory_trace;
bool if_memory_trace = false;
char load_or_store;

static word_t pmem_read(paddr_t addr, int len) {
  memory_trace = addr;
  if_memory_trace = true;
  load_or_store = 'l';
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  memory_trace = addr;
  if_memory_trace = true;
  load_or_store = 's';
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

word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

#else


static uint8_t mrom[4*1024] PG_ALIGN = {};
static uint8_t sram[8*1024] PG_ALIGN = {};
static uint8_t psram[4*1024*1024] PG_ALIGN = {};
static uint8_t flash[16*1024*1024] PG_ALIGN = {};
static uint8_t sdram[64*1024*1024] PG_ALIGN = {};

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

uint8_t* guest_to_host(paddr_t paddr) {
  if(paddr >= 0x0f000000 && paddr <= 0x0fffffff) {
    return sram + paddr - 0x0f000000;
  } else if(paddr >= 0x20000000 && paddr <= 0x20000fff) {
    return mrom + paddr - 0x20000000;
  } else if(paddr >= 0x30000000 && paddr <= 0x3fffffff) {
    return flash + paddr - 0x30000000;
  } else if(paddr >= 0x80000000 && paddr <= 0x9fffffff) {
    return psram + paddr - 0x80000000;
  } else if(paddr >= 0xa0000000 && paddr <= 0xbfffffff) {
    return sdram + paddr - 0xa0000000;
  } else {
    out_of_bound(paddr);
    assert(0);
  }
}

paddr_t host_to_guest(uint8_t *haddr) { return 0; }

static word_t pmem_read(paddr_t addr, int len) {
  // printf("read  addr:0x%08x len:%d\n", addr, len);
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  // printf("wite  addr:0x%08x len:%d data:0x%08x\n", addr, len, data);
  host_write(guest_to_host(addr), len, data);
}

word_t paddr_read(paddr_t addr, int len) {
  return pmem_read(addr, len);
}

void paddr_write(paddr_t addr, int len, word_t data) {
  pmem_write(addr, len, data);
}

void init_mem() {
  IFDEF(CONFIG_MEM_RANDOM, memset(sram, 0, 8*1024));
  IFDEF(CONFIG_MEM_RANDOM, memset(mrom, rand(), 4*1024));
  IFDEF(CONFIG_MEM_RANDOM, memset(flash, rand(), 16*1024*1024));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

#endif
