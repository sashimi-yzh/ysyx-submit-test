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

#include <isa.h>
#include <cpu/cpu.h>
#include <difftest-def.h>
#include <memory/paddr.h>

#define USE_YSYXSOC

__EXPORT void difftest_memcpy(paddr_t addr, void *buf, size_t n, bool direction)
{
  printf("difftest_memcpy: addr = 0x%08x, buf = %p, n = %zu, direction = %s\n",
         addr, buf, n, direction == DIFFTEST_TO_REF ? "to_ref" : "to_dut");
  if (direction == DIFFTEST_TO_REF)
  {
    for (size_t i = 0; i < n; i++)
    {
      paddr_write(addr + i, 1, ((uint8_t *)buf)[i]);
    }
  }
  else
  {
    for (size_t i = 0; i < n; i++)
    {
      ((uint8_t *)buf)[i] = paddr_read(addr + i, 1);
    }
  }
  cpu.memRValid = false;
  cpu.memWValid = false;
}

CPU_state *dut_cpu_ptr = NULL;

__EXPORT void difftest_regcpy(void *dut, bool direction)
{

  if (direction == DIFFTEST_TO_DUT)
  {
    memcpy(dut, &cpu, sizeof(CPU_state));
    cpu.memRValid = false;
    cpu.memWValid = false;
  }
  else
  {
    memcpy(&cpu, dut, sizeof(CPU_state));
    // printf("difftest_regcpy: cpu.pc = 0x%08x\n", cpu.pc);
  }
}

bool ref_nemu_difftest_skip_once = false;

__EXPORT void difftest_exec(uint64_t n)
{
  // printf("difftest_exec: n = %lu\n", n);
  cpu_exec(n);
  if (ref_nemu_difftest_skip_once)
  {
    ref_nemu_difftest_skip_once = false;
    difftest_regcpy(dut_cpu_ptr, DIFFTEST_TO_REF);
  }
}

__EXPORT void difftest_raise_intr(word_t NO)
{
  assert(0);
}

__EXPORT void difftest_init(void *dut)
{
  dut_cpu_ptr = (CPU_state *)dut;

  // #ifdef USE_YSYXSOC
  //   cpu.pc = 0x30000000;
  //   return;
  // #endif
  cpu.pc = dut_cpu_ptr->pc;
  return;

  void init_mem();
  init_mem();

  /* Perform ISA dependent initialization. */
  init_isa();
}

// ysyxsoc 新增功能

/* ── Address map ─────────────────────────────────────────────────── */
#define MROM_BASE 0x20000000u
#define MROM_SIZE 0x00001000u /* 4 KB */

#define SRAM_BASE 0x0f000000u
#define SRAM_SIZE 0x00002000u /* 8 KB */

#define MEM_BASE 0x80000000u
#define MEM_SIZE 1024 * 1024 * 64

#define FLASH_BASE 0x30000000u
#define FLASH_SIZE 16 * 1024 * 1024

#define PSRAM_BASE 0x80000000u
#define PSRAM_SIZE 4 * 1024 * 1024

#define SDRAM_BASE 0xa0000000u
#define SDRAM_SIZE 128 * 1024 * 1024

/* ── Backing storage ─────────────────────────────────────────────── */
// #ifdef USE_YSYXSOC
// static uint8_t mrom_mem[MROM_SIZE];
static uint8_t sram_mem[SRAM_SIZE];
static uint8_t sdram_mem[SDRAM_SIZE];
static uint8_t flash[FLASH_SIZE];
static uint8_t psram[PSRAM_SIZE];
// #else
static uint8_t mem_mem[MEM_SIZE];
// #endif
/* ── Device descriptor ───────────────────────────────────────────── */
typedef struct
{
  paddr_t base;
  size_t size;
  uint8_t *mem;
  const char *name;
} SoCDevice;

static SoCDevice soc_devices[] = {
    // #ifdef USE_YSYXSOC
    // {MROM_BASE, MROM_SIZE, mrom_mem, "MROM"},
    {SRAM_BASE, SRAM_SIZE, sram_mem, "SRAM"},
    {FLASH_BASE, FLASH_SIZE, flash, "FLASH"},
    {PSRAM_BASE, PSRAM_SIZE, psram, "PSRAM"},
    {SDRAM_BASE, SDRAM_SIZE, sdram_mem, "SDRAM"},
    // #else
    {MEM_BASE, MEM_SIZE, mem_mem, "MEM"},
    // #endif
};

#define NR_SOC_DEVICES (sizeof(soc_devices) / sizeof(soc_devices[0]))

/* ── Lookup ──────────────────────────────────────────────────────── */
static SoCDevice *soc_find_device(paddr_t addr)
{
  for (size_t i = 0; i < NR_SOC_DEVICES; i++)
  {
    if (addr >= soc_devices[i].base &&
        addr < soc_devices[i].base + soc_devices[i].size)
      return &soc_devices[i];
  }
  return NULL;
}

/* ── Public API ──────────────────────────────────────────────────── */
word_t diff_addr_read(paddr_t addr, int len)
{
  SoCDevice *dev = soc_find_device(addr);
  if (dev == NULL)
  {
    ref_nemu_difftest_skip_once = true;
    return 0;
  }

  uint32_t offset = addr - dev->base;
  word_t data = 0;
  for (int i = 0; i < len; i++)
    data |= (word_t)(dev->mem[offset + i]) << (i * 8);

  if (addr != cpu.pc)
  {
    cpu.memAddr = addr;
    cpu.memRdata = data;
    cpu.memRValid = true;
  }

  return data;
}

void diff_addr_write(paddr_t addr, int len, word_t data)
{
  SoCDevice *dev = soc_find_device(addr);
  if (dev == NULL)
  {
    ref_nemu_difftest_skip_once = true;
    return;
  }

  uint32_t offset = addr - dev->base;
  for (int i = 0; i < len; i++)
    dev->mem[offset + i] = (data >> (i * 8)) & 0xff;

  cpu.memAddr = addr;
  cpu.memWdata = data;
  cpu.memWValid = true;
  // printf("diff_addr_write: addr = 0x%08x, len = %d, data = 0x%08x\n", addr, len, data);
}
