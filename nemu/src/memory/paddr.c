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

#ifdef CONFIG_LSTRACE
void lstrace(uint32_t addr, int op, int len);
#endif

#ifdef CONFIG_YSYXSOC
static uint8_t mrom [MROM_SIZE] PG_ALIGN;
static uint8_t sram [SRAM_SIZE] PG_ALIGN;
static uint8_t flash [FLASH_SIZE] PG_ALIGN;
static uint8_t psram [PSRAM_SIZE] PG_ALIGN;
static uint8_t sdram [SDRAM_SIZE] PG_ALIGN;
const MemMap mem_map[] = {
  { "mrom", MROM_BASE, MROM_SIZE, mrom, true },
  { "sram", SRAM_BASE, SRAM_SIZE, sram, false },
  { "flash", FLASH_BASE, FLASH_SIZE, flash, true },
  { "psram", PSRAM_BASE, PSRAM_SIZE, psram, false },
  { "sdram", SDRAM_BASE, SDRAM_SIZE, sdram, false }
};

static const MemMap *get_mem_map(paddr_t addr) {
  for (int i = 0; i < ARRLEN(mem_map); ++i) {
    if (mem_map[i].start <= addr && addr < mem_map[i].start + mem_map[i].size) {
      return &mem_map[i];
    }
  }
  return NULL;
}
#endif

uint8_t* guest_to_host(paddr_t paddr) {
#ifdef CONFIG_YSYXSOC
  const MemMap *m = get_mem_map(paddr);
  Assert(m, "addr = " FMT_PADDR " out of bound", paddr);
  return paddr - m->start + m->ptr;
#else
  return pmem + paddr - CONFIG_MBASE;
#endif
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len, int inst) {
#ifdef CONFIG_YSYXSOC
  const MemMap *m = get_mem_map(addr);
  if (m) {
    IFDEF(CONFIG_LSTRACE, if (!inst) lstrace(addr, 0, len));
    return host_read(addr - m->start + m->ptr, len);
  }
  if (addr == 0x10000005) return 0xff; // UART_LST
  else return 0; // return 0 for all other soc device registers
#else
  IFDEF(CONFIG_LSTRACE, lstrace(addr, 0, len));
  return host_read(guest_to_host(addr), len);
#endif
}

static void pmem_write(paddr_t addr, int len, word_t data) {
#ifdef CONFIG_YSYXSOC
  const MemMap *m = get_mem_map(addr);
  if (m) {
    host_write(addr - m->start + m->ptr, len, data);
    IFDEF(CONFIG_LSTRACE, lstrace(addr, 1, len));
  }
  if (addr == 0x10000000) { // UART
    putchar(data);
    fflush(stdout);
  }
  // ignore all store to device
#else
  IFDEF(CONFIG_LSTRACE, lstrace(addr, 1, len));
  host_write(guest_to_host(addr), len, data);
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
#ifdef CONFIG_YSYXSOC
  memset(mrom, 0xCB, MROM_SIZE);
  memset(flash, 0xCB, FLASH_SIZE);
#endif
}

#ifdef CONFIG_MTRACE
void locate_object_sym(paddr_t addr) {
  extern ElfSymbol elf_symbol_list[];
  extern word_t elf_symbol_list_size;
  for (word_t i = 0; i < elf_symbol_list_size; ++i) {
    if (elf_symbol_list[i].type == ELF_SYM_OBJECT &&
        elf_symbol_list[i].addr <= addr &&
        addr < elf_symbol_list[i].addr + elf_symbol_list[i].size) {
      log_write("(%s + %u)", elf_symbol_list[i].name, (uint32_t)(addr - elf_symbol_list[i].addr));
      return;
    }
  }
}
#endif

word_t paddr_read(paddr_t addr, int len, int inst) {
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_START <= addr && addr <= CONFIG_MTRACE_END) {
      log_write(ANSI_FG_CYAN "[MTRACE] Read %d bytes at " FMT_PADDR, len, addr);
      locate_object_sym(addr);
      log_write(ANSI_NONE "\n");
    }
#endif
    Assert(addr % len == 0, "Ualigned memory read at " FMT_PADDR, addr);
    return pmem_read(addr, len, inst);
  }
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  if (likely(in_pmem(addr))) {
#ifdef CONFIG_MTRACE
    if (CONFIG_MTRACE_START <= addr && addr <= CONFIG_MTRACE_END) {
      log_write(ANSI_FG_YELLOW "[MTRACE] Write %d bytes at " FMT_PADDR , len, addr);
      locate_object_sym(addr);
      log_write(": " FMT_WORD ANSI_NONE "\n", data);
    }
#endif
    Assert(addr % len == 0, "Ualigned memory write at " FMT_PADDR, addr);
    pmem_write(addr, len, data);
    return; 
  }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}
