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
static uint8_t flash[0x1000000] PG_ALIGN = {};
static uint8_t sram[0x2000] PG_ALIGN = {};
static uint8_t psram[0x400000] PG_ALIGN = {};
static uint8_t sdram[0x20000000] PG_ALIGN = {};
#endif

uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }
uint8_t* guest_to_flash(paddr_t paddr) { return flash + paddr - 0x30000000; }
uint8_t* guest_to_sram(paddr_t paddr) { return sram + paddr - 0xf000000; }
uint8_t* guest_to_psram(paddr_t paddr) { return psram + paddr - 0x80000000; }
uint8_t* guest_to_sdram(paddr_t paddr) { return sdram + paddr - 0xa0000000; }

bool MTRACE_IF;

static word_t pmem_read(paddr_t addr, int len) {
#ifdef CONFIG_MTRACE
  if(MTRACE_IF) {
    if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
    }
    else {
      printf("read: " FMT_PADDR " len: %d\n", addr, len);
    }
  }
  MTRACE_IF = true;
#endif
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static word_t flash_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_flash(addr), len);
  return ret;
}

static word_t sram_read(paddr_t addr, int len) {
  #ifdef CONFIG_MTRACE
    if(MTRACE_IF) {
      if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
      }
      else {
        printf("read: " FMT_PADDR " len: %d\n", addr, len);
      }
    }
    MTRACE_IF = true;
  #endif
  word_t ret = host_read(guest_to_sram(addr), len);
  return ret;
}

// static word_t psram_read(paddr_t addr, int len) {
//   word_t ret = host_read(guest_to_psram(addr), len);
//   return ret;
// }

static word_t sdram_read(paddr_t addr, int len) {
  #ifdef CONFIG_MTRACE
    if(MTRACE_IF) {
      if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
      }
      else {
        printf("read: " FMT_PADDR " len: %d\n", addr, len);
      }
    }
    MTRACE_IF = true;
  #endif
  word_t ret = host_read(guest_to_sdram(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_MTRACE
  if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
  }
  else printf("write: " FMT_PADDR " len: %d data: " FMT_WORD "\n", addr, len, data);
#endif
  host_write(guest_to_host(addr), len, data);
}

static void sram_write(paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
  }
    else printf("write: " FMT_PADDR " len: %d data: " FMT_WORD "\n", addr, len, data);
  #endif
  host_write(guest_to_sram(addr), len, data);
}

// static void psram_write(paddr_t addr, int len, word_t data) {
//   host_write(guest_to_psram(addr), len, data);
// }

static void sdram_write(paddr_t addr, int len, word_t data) {
  #ifdef CONFIG_MTRACE
    if(CONFIG_MTRACE_FILE) {
      uint32_t align_addr = addr & 0xfffffffc;
      mem_trace_write(align_addr);
  }
    else printf("write: " FMT_PADDR " len: %d data: " FMT_WORD "\n", addr, len, data);
  #endif
  host_write(guest_to_sdram(addr), len, data);
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

#ifdef CONFIG_TARGET_SHARE
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_flash(addr))) return flash_read(addr, len);
  if (likely(in_sram(addr))) return sram_read(addr, len);
  // if (likely(in_psram(addr))) return psram_read(addr, len);
  if (likely(in_sdram(addr))) return sdram_read(addr, len);
  out_of_bound(addr);
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  return 0;
}
void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_sram(addr))) { sram_write(addr, len, data); return; }
  // if (likely(in_psram(addr))) { psram_write(addr, len, data); return; }
  if (likely(in_sdram(addr))) { sdram_write(addr, len, data); return; }
  out_of_bound(addr);
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
}
#else
word_t paddr_read(paddr_t addr, int len) {
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  if (likely(in_flash(addr))) return flash_read(addr, len);
  if (likely(in_sram(addr))) return sram_read(addr, len);
  // if (likely(in_psram(addr))) return psram_read(addr, len);
  if (likely(in_sdram(addr))) return sdram_read(addr, len);
  if (likely(to_uart(addr))) return 0x00000060;
  out_of_bound(addr);
  return 0;
}
void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  if (likely(in_sram(addr))) { sram_write(addr, len, data); return; }
  // if (likely(in_psram(addr))) { psram_write(addr, len, data); return; }
  if (likely(in_sdram(addr))) { sdram_write(addr, len, data); return; }
  if (likely(to_uart(addr))) return ;
  out_of_bound(addr);
}
#endif


