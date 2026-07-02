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
#include <difftest-def.h>
#include <device/mmio.h>
#include <isa.h>
#include <string.h>

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

static bool use_ysyxsoc_paddr = false;

static bool valid_access_len(int len) {
  switch (len) {
    case 1: case 2: case 4:
      return true;
    IFDEF(CONFIG_ISA64, case 8: return true);
    default:
      return false;
  }
}

/*
 * Native NEMU memory map
 */
uint8_t* guest_to_host(paddr_t paddr) {
  IFDEF(CONFIG_RT_CHECK, Assert(in_pmem(paddr),
      "guest_to_host out of pmem: paddr=" FMT_PADDR " pc=" FMT_WORD, paddr, cpu.pc));
  return pmem + paddr - CONFIG_MBASE;
}

paddr_t host_to_guest(uint8_t *haddr) {
  IFDEF(CONFIG_RT_CHECK, {
    uintptr_t host = (uintptr_t)haddr;
    uintptr_t left = (uintptr_t)pmem;
    uintptr_t right = left + CONFIG_MSIZE;
    Assert(host >= left && host < right,
        "host address is out of native pmem: haddr=%p pmem=[%p, %p)",
        haddr, (void *)left, (void *)right);
  });
  return haddr - pmem + CONFIG_MBASE;
}

static word_t pmem_read(paddr_t addr, int len) {
  return host_read(guest_to_host(addr), len);
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

static void out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound of pmem [" FMT_PADDR ", " FMT_PADDR "] at pc = " FMT_WORD,
      addr, PMEM_LEFT, PMEM_RIGHT, cpu.pc);
}

/*
 * ysyxSoC memory map for NEMU-as-ref
 */
#define FLASH_BASE 0x30000000u
#define FLASH_SIZE (16u * 1024u * 1024u)
#define FLASH_RIGHT (FLASH_BASE + FLASH_SIZE - 1)
#define SRAM_BASE 0x0f000000u
#define SRAM_SIZE 0x2000u
#define SRAM_RIGHT (SRAM_BASE + SRAM_SIZE - 1)
#define SDRAM_BASE 0xa0000000u
#define SDRAM_SIZE (32u * 1024u * 1024u)
#define SDRAM_RIGHT (SDRAM_BASE + SDRAM_SIZE - 1)

static uint8_t flash[FLASH_SIZE] = {};
static uint8_t sram[SRAM_SIZE] = {};
static uint8_t sdram[SDRAM_SIZE] = {};

static bool in_region(paddr_t addr, int len, paddr_t base, uint32_t size) {
  if (len <= 0) return false;
  if (addr < base) return false;
  uint64_t off = (uint64_t)(addr - base);
  return off + (uint64_t)len <= (uint64_t)size;
}

static void ysyxsoc_paddr_init(void) {
  memset(flash, 0xff, sizeof(flash));
  memset(sram, 0, sizeof(sram));
  memset(sdram, 0, sizeof(sdram));
}

static bool ysyxsoc_paddr_read(paddr_t addr, int len, word_t *data) {
  if (in_region(addr, len, FLASH_BASE, FLASH_SIZE)) {
    *data = host_read(flash + (addr - FLASH_BASE), len);
    return true;
  }
  if (in_region(addr, len, SRAM_BASE, SRAM_SIZE)) {
    *data = host_read(sram + (addr - SRAM_BASE), len);
    return true;
  }
  if (in_region(addr, len, SDRAM_BASE, SDRAM_SIZE)) {
    *data = host_read(sdram + (addr - SDRAM_BASE), len);
    return true;
  }
  IFDEF(CONFIG_DEVICE, {
    *data = mmio_read(addr, len);
    return true;
  });
  return false;
}

static bool ysyxsoc_paddr_write(paddr_t addr, int len, word_t data) {
  if (in_region(addr, len, FLASH_BASE, FLASH_SIZE)) {
    host_write(flash + (addr - FLASH_BASE), len, data);
    return true;
  }
  if (in_region(addr, len, SRAM_BASE, SRAM_SIZE)) {
    host_write(sram + (addr - SRAM_BASE), len, data);
    return true;
  }
  if (in_region(addr, len, SDRAM_BASE, SDRAM_SIZE)) {
    host_write(sdram + (addr - SDRAM_BASE), len, data);
    return true;
  }
  IFDEF(CONFIG_DEVICE, {
    mmio_write(addr, len, data);
    return true;
  });
  return false;
}

static void ysyxsoc_paddr_log_ranges(void) {
  Log("FLASH area [0x%08x, 0x%08x]", FLASH_BASE, FLASH_RIGHT);
  Log("SRAM area [0x%08x, 0x%08x]", SRAM_BASE, SRAM_RIGHT);
  Log("SDRAM area [0x%08x, 0x%08x]", SDRAM_BASE, SDRAM_RIGHT);
}

static void ysyxsoc_paddr_out_of_bound(paddr_t addr) {
  panic("address = " FMT_PADDR " is out of bound for ysyxsoc memory. valid ranges: flash[0x%08x, 0x%08x], "
      "sram[0x%08x, 0x%08x], sdram[0x%08x, 0x%08x], pc = " FMT_WORD,
      addr, FLASH_BASE, FLASH_RIGHT, SRAM_BASE, SRAM_RIGHT, SDRAM_BASE, SDRAM_RIGHT, cpu.pc);
}

__EXPORT void difftest_enable_ysyxsoc_paddr(void) {
  use_ysyxsoc_paddr = true;
}

void init_mem() {
#if   defined(CONFIG_PMEM_MALLOC)
  pmem = malloc(CONFIG_MSIZE);
  Assert(pmem != NULL, "Can not allocate physical memory: size=%" PRIu64,
      (uint64_t)CONFIG_MSIZE);
#endif
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));

  if (use_ysyxsoc_paddr) {
    ysyxsoc_paddr_init();
    Log("memory backend = ysyxsoc");
    ysyxsoc_paddr_log_ranges();
  } else {
    Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
  }
}

word_t paddr_read(paddr_t addr, int len) {
  IFDEF(CONFIG_RT_CHECK, Assert(valid_access_len(len),
      "invalid memory read length: pc=" FMT_WORD " addr=" FMT_PADDR " len=%d", cpu.pc, addr, len));
  if (use_ysyxsoc_paddr) {
    word_t data = 0;
    if (likely(ysyxsoc_paddr_read(addr, len, &data))) {
      return data;
    }
    ysyxsoc_paddr_out_of_bound(addr);
    return 0;
  }

  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_RT_CHECK, Assert(valid_access_len(len),
      "invalid memory write length: pc=" FMT_WORD " addr=" FMT_PADDR " len=%d data=" FMT_WORD, cpu.pc, addr, len, data));
  if (use_ysyxsoc_paddr) {
    if (likely(ysyxsoc_paddr_write(addr, len, data))) {
      return;
    }
    ysyxsoc_paddr_out_of_bound(addr);
    return;
  }

  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
