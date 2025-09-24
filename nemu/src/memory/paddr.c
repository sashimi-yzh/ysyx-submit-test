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

#if   defined(CONFIG_PMEM_MALLOC)
static uint8_t *pmem = NULL;
#else // CONFIG_PMEM_GARRAY
static uint8_t pmem[CONFIG_MSIZE] PG_ALIGN = {};
#endif

#ifdef CONFIG_TARGET_SHARE
static uint8_t pflash[CONFIG_FLASH_SIZE] PG_ALIGN = {};
static uint8_t psram[CONFIG_SRAM_SIZE] PG_ALIGN = {};
static uint8_t psdram[CONFIG_SDRAM_SIZE] PG_ALIGN = {};
uint8_t* guest_to_host(paddr_t paddr) {
  if (paddr >= CONFIG_FLASH_BASE && paddr < CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE)
    return pflash + paddr - CONFIG_FLASH_BASE;
  else if (paddr >= CONFIG_SRAM_BASE && paddr < CONFIG_SRAM_BASE + CONFIG_SRAM_SIZE)
    return psram + paddr - CONFIG_SRAM_BASE;
  else if (paddr >= CONFIG_SDRAM_BASE && paddr < CONFIG_SDRAM_BASE + CONFIG_SDRAM_SIZE)
    return psdram + paddr - CONFIG_SDRAM_BASE;
  else
    return pmem + paddr - CONFIG_MBASE;
}
#else
uint8_t* guest_to_host(paddr_t paddr) { return pmem + paddr - CONFIG_MBASE; }
#endif
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

#ifdef CONFIG_MTRACE
static bool in_mtrace(paddr_t addr) {
  bool in = false;
  if (addr >= CONFIG_MTRACE_START && addr <= CONFIG_MTRACE_END)
    in = true;
  return in;
}
#endif /* ifdef CONFIG_MTRACE */

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  IFDEF(CONFIG_MTRACE, if(in_mtrace(addr)) trace_write("pc: 0x%.8x  memory read:  addr = 0x%.8x, "
                                   "len = %d, data = 0x%.8x\n", cpu.pc, addr, len, ret));
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  host_write(guest_to_host(addr), len, data);
  IFDEF(CONFIG_MTRACE, if(in_mtrace(addr)) trace_write("pc: 0x%.8x  memory write: addr = 0x%.8x, "
                                   "len = %d, data = 0x%.8x\n", cpu.pc, addr, len, data));
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
