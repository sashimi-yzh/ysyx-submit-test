#include "common.h"
#include "mem.h"

#include <cstring>

#ifdef YSYXSOC

static uint8_t mrom [MROM_SIZE] PG_ALIGN;
// static uint8_t sram [SRAM_SIZE] PG_ALIGN;
static uint8_t flash [FLASH_SIZE] PG_ALIGN;
// static uint8_t psram [PSRAM_SIZE] PG_ALIGN;
// static uint8_t sdram [SDRAM_SIZE] PG_ALIGN;
const MemMap mem_map[] = {
  { "mrom", MROM_BASE, MROM_SIZE, mrom, true },
  { "sram", SRAM_BASE, SRAM_SIZE, nullptr, false },
  { "flash", FLASH_BASE, FLASH_SIZE, flash, true },
  { "psram", PSRAM_BASE, PSRAM_SIZE, nullptr, false },
  { "sdram", SDRAM_BASE, SDRAM_SIZE, nullptr, false }
};

const MemMap *get_mem_map(addr_t addr, bool panic_if_out) {
  for (const MemMap &i : mem_map) {
    if (i.start <= addr && addr < i.start + i.size) {
      return &i;
    }
  }
  if (panic_if_out) {
    panic("addr = " FMT_ADDR " out of bound", addr);
  } else {
    return nullptr;
  }
}

uint8_t *guest_to_host(addr_t addr) {
  const MemMap *m = get_mem_map(addr, true);
  return addr - m->start + m->ptr;
}

void init_mem() {
  memset(mrom, 0xCB, MROM_SIZE);
  memset(flash, 0xCB, FLASH_SIZE);
}

word_t addr_read(addr_t addr, int len) {
  const MemMap *m = get_mem_map(addr, true);
  return host_read(addr - m->start + m->ptr, len);
}

void addr_write(addr_t addr, int len, word_t data) {
  const MemMap *m = get_mem_map(addr, true);
  Assert(!m->readonly, "addr = " FMT_ADDR " readonly", addr);
  return host_write(addr - m->start + m->ptr, len, data);
}

#else

static uint8_t pmem[MEM_SIZE] PG_ALIGN = {};

uint8_t *guest_to_host(addr_t addr) {
  return addr - MEM_BASE + pmem;
}

void init_mem() {
  memset(pmem, 0xCB, MEM_SIZE);
}

word_t addr_read(addr_t addr, int len) {
  Assert(MEM_BASE <= addr && addr + len <= MEM_BASE + MEM_SIZE,
         "addr = " FMT_ADDR " out of bound", addr);
  return host_read(guest_to_host(addr), len);
}

void addr_write(addr_t addr, int len, word_t data) {
  Assert(MEM_BASE <= addr && addr + len <= MEM_BASE + MEM_SIZE,
         "addr = " FMT_ADDR " out of bound", addr);
  return host_write(guest_to_host(addr), len, data);
}

#endif
