#include "memory.h"
#include "common.h"
#include "host.h"
#include "map.h"
#include <assert.h>
#include <cstdint>
#include <iostream>

#ifdef __NPC__
const unsigned int psize = 0x20000000;
#else
const unsigned int psize = 0x400000;
#endif
const unsigned int msize = 0x800000;
const unsigned int fsize = 0xfffffff;
const unsigned int dsize = 0x20000000;
static uint8_t pmem[msize] = {};
static uint8_t flash[fsize] = {};
static uint8_t psram[psize] = {};
static uint8_t sdram[dsize] = {};

socspace soc_spaces[] = {
    {"mrom", MBASE, MBASE + msize, pmem},
    {"flash", FBASE, FBASE + fsize, flash},
    {"psram", PSBASE, PSBASE + psize, psram},
#ifndef __NPC__
    {"sdram", SDBASE, SDBASE + dsize, sdram},
#endif
};

#define SPACE_NUM (sizeof(soc_spaces) / sizeof(soc_spaces[0]))

#ifdef MTRACE
extern char *mtrace_out_file;
extern bool mtrace_on;
FILE *mtrace_fd = NULL;
#endif

void init_mem() {
  for (int i = 0; i < SPACE_NUM; i++) {
    printf(COLOR_BLUE "[%s] start: 0x%x -- end: 0x%x\n" COLOR_RESET,
           soc_spaces[i].name, soc_spaces[i].start, soc_spaces[i].end);
  }

#ifdef MTRACE
  if (mtrace_on) {
    mtrace_fd = fopen(mtrace_out_file, "w");
    if (mtrace_fd == NULL) {
      printf(COLOR_RED "[ERROR] Failed to open mtrace output file: %s\n"
                       COLOR_RESET,
             mtrace_out_file);
      mtrace_on = false;
    } else {
      printf(COLOR_GREEN "[INFO] mtrace log file %s\n" COLOR_RESET,
             mtrace_out_file);
    }
  }
#endif
}

bool in_pmem(uint32_t addr) {
  for (int i = 0; i < SPACE_NUM; i++)
    if (addr >= soc_spaces[i].start && addr <= soc_spaces[i].end)
      return true;

  return false;
}

int space_to_host(uint32_t addr, socspace **space) {
  for (int i = 0; i < SPACE_NUM; i++)
    if (addr >= soc_spaces[i].start && addr <= soc_spaces[i].end) {
      *space = &soc_spaces[i];
      return 1;
    }
  return -1;
}

extern Cpu *cpu;
uint8_t *guest_to_host(uint32_t addr) {
  socspace *space;
  if (space_to_host(addr, &space)) {
    return (uint8_t *)space->space + addr - space->start;
  }
  printf("[guest_to_host]the addr 0x%08x is out of bound at pc 0x%08x\n", addr,
         cpu->pc);
  assert(0);
}

uint32_t pmem_read(uint8_t *addr, uint32_t len) {
  switch (len) {
  case 1:
    return *(uint8_t *)addr;
  case 2:
    return *(uint16_t *)addr;
  case 4:
    return *(uint32_t *)addr;
  default:
    std::cerr << "read invaild data len" << std::endl;
  }
  return *(uint32_t *)addr;
}

void pmem_write(uint8_t *addr, uint32_t len, uint32_t data) {
  switch (len) {
  case 1:
    *(uint8_t *)addr = data;
    return;
  case 2:
    *(uint16_t *)addr = data;
    return;
  case 4:
    *(uint32_t *)addr = data;
    return;
  default:
    std::cerr << "write invaild data len" << std::endl;
  }
  return;
}

uint32_t paddr_read(uint32_t addr, uint32_t len) {
  if (in_pmem(addr)) {
    uint32_t ret = pmem_read(guest_to_host(addr), len);
    // printf("\t[paddr_read]space mrom, addr 0x%08x data %u\n", addr, ret);
#ifdef MTRACE
    if (mtrace_on) {
      fprintf(mtrace_fd, "[memory read] %u from 0x%08x\n", ret, addr);
    }
#endif
    return ret;
  }
  return mmio_read(addr, len);
  printf("[paddr_read]the addr 0x%08x is out of bound pc at 0x%08x\n", addr,
         cpu->pc);
  assert(0);
}

void paddr_write(uint32_t addr, uint32_t len, uint32_t data) {
  if (in_pmem(addr)) {
    pmem_write(guest_to_host(addr), len, data);
    // printf("\t[paddr_write]space mrom, addr 0x%08x data %u\n", addr, data);
#ifdef MTRACE
    if (mtrace_on) {
      fprintf(mtrace_fd, "[memory write] %u to 0x%08x\n", data, addr);
    }
#endif
    return;
  }
  mmio_write(addr, len, data);
  return;
  printf("[paddr_write]the addr 0x%08x is out of bound\n", addr);
  assert(0);
}
