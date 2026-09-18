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
#ifdef CONFIG_REF_SOC
static uint8_t flash[CONFIG_FLASH_SIZE] PG_ALIGN = {};
static uint8_t mrom[CONFIG_MROM_SIZE] PG_ALIGN = {};
static uint8_t sram[CONFIG_SRAM_SIZE] PG_ALIGN = {};
static uint8_t sdram[CONFIG_SDRAM_SIZE] PG_ALIGN = {};
#endif
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t  host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

// ---------- For ysyxSoC ----------
#ifdef CONFIG_REF_SOC
uint8_t* guest_to_host_flash(paddr_t paddr) { return flash + paddr - CONFIG_FLASH_BASE; }
paddr_t  host_to_guest_flash(uint8_t *haddr) { return haddr - flash + CONFIG_FLASH_BASE; }

uint8_t* guest_to_host_mrom(paddr_t paddr) { return mrom + paddr - CONFIG_MROM_BASE; }
paddr_t  host_to_guest_mrom(uint8_t *haddr) { return haddr - mrom + CONFIG_MROM_BASE; }

uint8_t* guest_to_host_sram(paddr_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
paddr_t  host_to_guest_sram(uint8_t *haddr) { return haddr - sram + CONFIG_SRAM_BASE; }

uint8_t* guest_to_host_sdram(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAM_BASE; }
paddr_t  host_to_guest_sdram(uint8_t *haddr) { return haddr - sdram + CONFIG_SDRAM_BASE; }
#endif
// ---------------------------------

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
}

// ---------- For ysyxSoC ----------
#ifdef CONFIG_REF_SOC
static word_t flash_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_flash(addr), len);
  return ret;
}

static word_t mrom_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_mrom(addr), len);
  return ret;
}

static word_t sram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sram(addr), len);
  return ret;
}

static void sram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sram(addr), len, data);
}

static word_t sdram_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host_sdram(addr), len);
  return ret;
}

static void sdram_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host_sdram(addr), len, data);
}
#endif
// ---------------------------------

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
#ifdef CONFIG_REF_SOC
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", FLASH_LEFT, FLASH_RIGHT);
#else
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
#endif
}

word_t paddr_read(paddr_t addr, int len) {
#ifdef CONFIG_REF_SOC
  if (likely(in_flash(addr))) { return flash_read(addr, len); }
  if (likely(in_mrom(addr)))  { return mrom_read(addr, len);  }
  if (likely(in_sram(addr)))  { return sram_read(addr, len);  }
  if (likely(in_sdram(addr))) { return sdram_read(addr, len); }
#endif
  if (likely(in_pmem(addr))) { return pmem_read(addr, len); }

  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  // Without device layer: return 0 for MMIO region
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_REF_SOC
  if (likely(in_sram(addr)))  { sram_write(addr, len, data);  return; }
  if (likely(in_sdram(addr))) { sdram_write(addr, len, data); return; }
#endif
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }

  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  // Without device layer: silently ignore MMIO writes
  out_of_bound(addr);
}
