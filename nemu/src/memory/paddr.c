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

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

#ifdef CONFIG_TARGET_SHARE

static uint8_t mrom[CONFIG_MROM_SIZE] = {};
static uint8_t sram[CONFIG_SRAM_SIZE] = {};
static uint8_t flash[CONFIG_FLASH_SIZE] = {};
static uint8_t psram[CONFIG_PSRAM_SIZE] = {};
static uint8_t sdram[CONFIG_SDRAM_SIZE] = {};
static uint8_t chiplink_mem[CONFIG_CHIPLINK_MEM_SIZE] = {};

uint8_t *mrom2host(paddr_t paddr) { return mrom + paddr - CONFIG_MROM_BASE; }
uint8_t *sram2host(paddr_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
uint8_t *flash2host(paddr_t paddr) { return flash + paddr - CONFIG_FLASH_BASE; }
uint8_t *psram2host(paddr_t paddr) { return psram + paddr - CONFIG_PSRAM_BASE; }
uint8_t *sdram2host(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAM_BASE; }
uint8_t *chiplink_mem2host(paddr_t paddr) { return chiplink_mem + paddr - CONFIG_CHIPLINK_MEM_BASE; }

static word_t mrom_read(paddr_t addr, int len) {
  word_t ret = host_read(mrom2host(addr), len);
  return ret;
}

static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(sram2host(addr), len);
  return ret;
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(sram2host(addr), len, data);
}

static word_t flash_read(paddr_t addr, int len) {
  word_t ret = host_read(flash2host(addr), len);
  return ret;
}

static word_t psram_read(paddr_t addr, int len) {
  word_t ret = host_read(psram2host(addr), len);
  return ret;
}

static void psram_write(paddr_t addr, int len, word_t data) {
  host_write(psram2host(addr), len, data);
}

static word_t sdram_read(paddr_t addr, int len) {
  word_t ret = host_read(sdram2host(addr), len);
  return ret;
}

static void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(sdram2host(addr), len, data);
}

static word_t chiplink_mem_read(paddr_t addr, int len) {
  word_t ret = host_read(chiplink_mem2host(addr), len);
  return ret;
}

static void chiplink_mem_write(paddr_t addr, int len, word_t data) {
  host_write(chiplink_mem2host(addr), len, data);
}

#else
static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}
#endif

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

// only trace inst memory access
bool print_mtrace = false;

word_t paddr_read(paddr_t addr, int len) {
#ifdef CONFIG_TARGET_SHARE
  if (in_mrom(addr)) {
    return mrom_read(addr, len);
  } else if (in_sram(addr)) {
    return sram_read(addr, len);
  } else if (in_flash(addr)) {
    return flash_read(addr, len);
  } else if (in_psram(addr)) {
    return psram_read(addr, len);
  } else if (in_sdram(addr)) {
    return sdram_read(addr, len);
  } else if (in_chiplink_mem(addr)) {
    return chiplink_mem_read(addr, len);
  }
  out_of_bound(addr);
#elif defined(CONFIG_MTRACE)
  word_t result;
  if (likely(in_pmem(addr))) {
    result = pmem_read(addr, len);
    if (print_mtrace)
      log_write("read addr:\t" FMT_PADDR "\tlen:%d\tdata:" FMT_WORD "\n", addr,
                len, result);
    return result;
  }
#ifdef CONFIG_DEVICE
  result = mmio_read(addr, len);
  if (print_mtrace)
    log_write("read addr:\t" FMT_PADDR "\tlen:%d\tdata:" FMT_WORD "\n", addr,
              len, result);
  return result;
#endif
  out_of_bound(addr);
#else
  if (likely(in_pmem(addr))) {
    return pmem_read(addr, len);
  }
#ifdef CONFIG_DEVICE
  return mmio_read(addr, len);
#endif
  out_of_bound(addr);
#endif
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
  if (print_mtrace)
    log_write("write addr:\t" FMT_PADDR "\tlen:%d\tdata:" FMT_WORD "\n",
              (word_t)addr, len, data);
#endif

#ifdef CONFIG_TARGET_SHARE
  if (in_sram(addr)) {
    sram_write(addr, len, data);
    return;
  } else if (in_psram(addr)) {
    psram_write(addr, len, data);
    return;
  } else if (in_sdram(addr)) {
    sdram_write(addr, len, data);
    return;
  } else if (in_chiplink_mem(addr)) {
    chiplink_mem_write(addr, len, data);
    return;
  }
  out_of_bound(addr);
#else
  if (likely(in_pmem(addr))) {
    pmem_write(addr, len, data);
    return;
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return );
  out_of_bound(addr);
#endif
}
