/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

 #include <device/mmio.h>
#include <isa.h>
#include <memory/host.h>
#include <memory/paddr.h>
#ifdef CONFIG_TARGET_SHARE
#define mromBase 0x20000000
#define mromSize 0x00001000
#define sramBase 0x0f000000
#define sramSize 0x00002000
#define flashBase 0x30000000
#define flashSize 0x01000000
#define pramBase 0x80000000
#define pramSize 0x00400000
#define sdramBase 0xa0000000
#define sdramSize 0x20000000
static uint8_t mrom[mromSize] PG_ALIGN = {};
static uint8_t sram[sramSize] PG_ALIGN = {};
static uint8_t flash[flashSize] PG_ALIGN = {};
static uint8_t pram[pramSize] PG_ALIGN = {};
static uint8_t sdram[sdramSize] PG_ALIGN = {};
#endif
#if defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t *guest_to_host(paddr_t paddr) {
#ifdef CONFIG_TARGET_SHARE
  if (mromBase <= paddr && paddr < mromBase + mromSize) {
    // printf("guest to mrom: %u\n", paddr - mromBase);
    return mrom + paddr - mromBase;
  }
  if (sramBase <= paddr && paddr < sramBase + sramSize) {
    // printf("guest to sram: %u\n", paddr - sramBase);
    return sram + paddr - sramBase;
  }
  if (flashBase <= paddr && paddr < flashBase + flashSize) {
    return flash + paddr - flashBase;
  }
  if (pramBase <= paddr && paddr < pramBase + pramSize) {
    // printf("guest_to_host paddr: %08x\n", paddr);
    return pram + paddr - pramBase;
  }
  if (sdramBase <= paddr && paddr < sdramBase + sdramSize) {
    // printf("guest_to_host paddr: %08x\n", paddr);
    return sdram + paddr - sdramBase;
  }
#endif
  return pmem + paddr - CONFIG_MBASE;
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
#ifdef CONFIG_TARGET_SHARE
#else
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR
        ", " FMT_PADDR "] at pc = " FMT_WORD,
        addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
#endif
}

void init_mem() {
#if defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  assert(pmem);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT,
      PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
#ifdef CONFIG_TARGET_SHARE
  return pmem_read(addr, len);
#else
  if (likely(in_pmem(addr))) {
    IFDEF(CONFIG_MTRACE, Log("read " FMT_PADDR ": " FMT_WORD " (len = %d)",
                             addr, pmem_read(addr, len), len));
    return pmem_read(addr, len);
  }
#endif
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_TARGET_SHARE
  assert(!(mromBase <= addr && addr < mromBase + mromSize));
  pmem_write(addr, len, data);
  return;
#endif
  if (likely(in_pmem(addr))) {
    IFDEF(CONFIG_MTRACE,
          Log("write " FMT_PADDR ": " FMT_WORD " (len = %d)", addr, data, len));
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
