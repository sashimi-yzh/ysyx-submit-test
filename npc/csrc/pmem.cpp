#include "verilated_dpi.h"
#include <common.h>

#define CONFIG_SRAM_BASE 0xf000000
#define CONFIG_SRAM_SIZE 0x2000

#define CONFIG_FLASH_BASE 0x30000000
#define CONFIG_FLASH_SIZE 0x1000000

#define CONFIG_PSRAM_BASE 0x80000000
#define CONFIG_PSRAM_SIZE 0x400000

#define CONFIG_SDRAM_BASE 0xa0000000
#define CONFIG_SDRAM_SIZE 0x4000000

static uint8_t sram[CONFIG_SRAM_SIZE] = {};
word_t flash[0x10000000] = {};
word_t psram[0x100000] = {};
static uint8_t sdram[CONFIG_SDRAM_SIZE] = {};

uint8_t *sram2host(paddr_t paddr) { return sram + paddr - CONFIG_SRAM_BASE; }
uint8_t *flash2host(paddr_t paddr) {
  return (uint8_t *)flash + paddr - CONFIG_FLASH_BASE;
}
uint8_t *psram2host(paddr_t paddr) {
  return (uint8_t *)psram + paddr - CONFIG_PSRAM_BASE;
}
uint8_t *sdram2host(paddr_t paddr) { return sdram + paddr - CONFIG_SDRAM_BASE; }

static bool in_sram(paddr_t addr) {
  return addr - CONFIG_SRAM_BASE < CONFIG_SRAM_SIZE;
}

static bool in_flash(paddr_t addr) {
  return addr - CONFIG_FLASH_BASE < CONFIG_FLASH_SIZE;
}

static bool in_psram(paddr_t addr) {
  return addr - CONFIG_PSRAM_BASE < CONFIG_PSRAM_SIZE;
}

static bool in_sdram(paddr_t addr) {
  return addr - CONFIG_SDRAM_BASE < CONFIG_SDRAM_SIZE;
}

extern "C" void flash_read(int32_t addr, int32_t *data) {
  int tmp = flash[addr / 4];
  *data = ((tmp >> 24) & 0xff) | (tmp << 24) | ((tmp & 0xff00) << 8) |
          ((tmp >> 8) & 0xff00);
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { assert(0); }

extern "C" void psram_read(paddr_t addr, int *data) { *data = psram[addr / 4]; }

extern "C" void psram_write(word_t addr, word_t data, int mask) {
  uint8_t *psram_addr = (uint8_t *)psram;
  psram_addr += addr;
  word_t origin_data = *(word_t *)psram_addr;
  *(word_t *)psram_addr = (origin_data & ~mask) | (data & mask);
}

word_t pmem_read(paddr_t addr) {
  if (in_sram(addr)) {
    return *(word_t *)sram2host(addr);
  } else if (in_flash(addr)) {
    return *(word_t *)flash2host(addr);
  } else if (in_psram(addr)) {
    return *(word_t *)psram2host(addr);
  } else if (in_sdram(addr)) {
    return *(word_t *)sdram2host(addr);
  } else {
    assert(0);
  }
}

void pmem_write(word_t addr, word_t data, int mask) {
  addr &= 0xfffffffc;
  word_t *tmp = nullptr;
  if (in_sram(addr)) {
    tmp = (word_t *)sram2host(addr);
  } else if (in_flash(addr)) {
    tmp = (word_t *)flash2host(addr);
  } else if (in_psram(addr)) {
    tmp = (word_t *)psram2host(addr);
  } else if (in_sdram(addr)) {
    tmp = (word_t *)sdram2host(addr);
  } else {
    assert(0);
  }

  switch (mask) {
  case 0b1:
    mask = 0xff;
    break;
  case 0b10:
    mask = 0xff00;
    break;
  case 0b100:
    mask = 0xff0000;
    break;
  case 0b1000:
    mask = 0xff000000;
    break;
  case 0b11:
    mask = 0xffff;
    break;
  case 0b110:
    mask = 0xffff00;
    break;
  case 0b1100:
    mask = 0xffff0000;
    break;
  case 0b1111:
    mask = 0xffffffff;
    break;
  default:
    assert(0);
  }
  *tmp = (*tmp & ~mask) | (data & mask);
}
