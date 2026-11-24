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

uint32_t mrom_mem[0x1000] = {0};

// instruction:  0x100007b7, 0x04100713, 0x00e78023, 0x00a00713, 0x00e78023,
// 0x0000006f;
uint8_t flash_mem[FLASH_SIZE] = {
    0xb7, 0x07, 0x00, 0x10, 0x13, 0x07, 0x10, 0x04, 0x23, 0x80, 0xe7, 0x00,
    0x13, 0x07, 0xa0, 0x00, 0x23, 0x80, 0xe7, 0x00, 0x6f, 0x00, 0x00, 0x00};

static uint8_t psram_mem[4 * 1024 * 1024] = {0};

static uint16_t sdram_mem[SDRAM_SIZE] = {0};

// it can access both pmem and mrom
uint8_t *guest_to_host(paddr_t paddr) {
  if (paddr >= CONFIG_MBASE && paddr < CONFIG_MBASE + CONFIG_MSIZE) {
    return pmem + (paddr - CONFIG_MBASE);
  } else if (paddr >= MROM_BASE && paddr < MROM_BASE + sizeof(mrom_mem)) {
    return (uint8_t *)mrom_mem + (paddr - MROM_BASE);
  } else if (paddr >= FLASH_BASE && paddr < FLASH_BASE + sizeof(flash_mem)) {
    return (uint8_t *)flash_mem + (paddr - FLASH_BASE);
  } else if (paddr >= PSRAM_BASE && paddr < PSRAM_BASE + sizeof(psram_mem)) {
    return (uint8_t *)psram_mem + (paddr - PSRAM_BASE);
  } else if (paddr >= SDRAM_BASE && paddr < SDRAM_BASE + sizeof(sdram_mem)) {
    return (uint8_t *)sdram_mem + (paddr - SDRAM_BASE);
  } else {
    panic("invalid address " FMT_PADDR " to convert to host address", paddr);
    return NULL;
  }
}
paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  IFDEF(CONFIG_MTRACE, log_mtrace(addr, len, 0));
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE, log_mtrace(addr, len, 1));
  host_write(guest_to_host(addr), len, data);
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

// This is not needed for nemu
// void flash_read(int32_t addr, int32_t *data) {
//   *data = *(int32_t *)&flash_mem[addr];
//   printf("flash read addr 0x%x, data 0x%x\n", addr, *data);
// }