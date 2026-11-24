/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

// sample data
// uint32_t flash_mem[FLASH_SIZE] = {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7,
//                                   0x8, 0x9, 0xa, 0xb, 0xc, 0xd, 0xe, 0xf};

// instruction:  0x100007b7, 0x04100713, 0x00e78023, 0x00a00713, 0x00e78023, 0x0000006f;
uint8_t flash_mem[FLASH_SIZE] = {0xb7, 0x07, 0x00, 0x10, 0x13, 0x07,
                                  0x10, 0x04, 0x23, 0x80, 0xe7, 0x00,
                                  0x13, 0x07, 0xa0, 0x00, 0x23, 0x80,
                                  0xe7, 0x00, 0x6f, 0x00, 0x00, 0x00};

void init_sdram();

// it can access both pmem and mrom
uint8_t *guest_to_host(paddr_t paddr) {
  if (paddr >= CONFIG_MBASE && paddr < CONFIG_MBASE + CONFIG_MSIZE) {
    return pmem + (paddr - CONFIG_MBASE);
  } else if (paddr >= MROM_BASE && paddr < MROM_BASE + sizeof(mrom_mem)) {
    return (uint8_t *)mrom_mem + (paddr - MROM_BASE);
  } else if (paddr >= FLASH_BASE && paddr < FLASH_BASE + sizeof(flash_mem)) {
    return (uint8_t *)flash_mem + (paddr - FLASH_BASE);
  } else {
    panic("invalid address " FMT_PADDR " to convert to host address", paddr);
    return NULL;
  }
}

paddr_t host_to_guest(uint8_t *haddr) { return haddr - pmem + CONFIG_MBASE; }

static word_t pmem_read(paddr_t addr, int len) {
  word_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static void pmem_write(paddr_t addr, int len, word_t data) {
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
  init_sdram();
  IFDEF(CONFIG_MEM_RANDOM, memset(pmem, rand(), CONFIG_MSIZE));
  Log("physical memory area [" FMT_PADDR ", " FMT_PADDR "]", PMEM_LEFT, PMEM_RIGHT);
}

word_t paddr_read(paddr_t addr, int len) {
  // disable this log to only track npc real mem usage
  //IFDEF(CONFIG_MTRACE, log_mtrace(addr, len, 0, 0));
  if (likely(in_pmem(addr))) return pmem_read(addr, len);
  IFDEF(CONFIG_DEVICE, return mmio_read(addr, len));
  out_of_bound(addr);
  return 0;
}

void paddr_write(paddr_t addr, int len, word_t data) {
  IFDEF(CONFIG_MTRACE, log_mtrace(addr, len, 1, data));
  if (likely(in_pmem(addr))) { pmem_write(addr, len, data); return; }
  IFDEF(CONFIG_DEVICE, mmio_write(addr, len, data); return);
  out_of_bound(addr);
}

// mask not really work for mem read which said in ysyx webpage
int npc_pmem_read(int raddr, char rmask) {
  int read_data = 0;
  if (likely(in_pmem(raddr))) {
    read_data = pmem_read(raddr&~0x3u, 4);
    IFDEF(CONFIG_MTRACE, log_mtrace(raddr&~0x3u, rmask, 0, read_data));
    return read_data;
  }
  // 4bytes align is also needed for mmio_read()
  IFDEF(CONFIG_DEVICE, return mmio_read(raddr&~0x3u, 4));
  out_of_bound(raddr);
  return 0;
}

void npc_pmem_write(int waddr, int wdata, unsigned char wmask) {
  if (likely(in_pmem(waddr))) {
    IFDEF(CONFIG_MTRACE, log_mtrace(waddr&~0x3u, wmask, 1, wdata));
    paddr_t base_addr = waddr & ~0x3u;
    if (wmask & 0x1u) pmem_write(base_addr + 0, 1, (wdata >> 0) & 0xFFu);
    if (wmask & 0x2u) pmem_write(base_addr + 1, 1, (wdata >> 8) & 0xFFu);
    if (wmask & 0x4u) pmem_write(base_addr + 2, 1, (wdata >> 16) & 0xFFu);
    if (wmask & 0x8u) pmem_write(base_addr + 3, 1, (wdata >> 24) & 0xFFu);
    return;
  }
  IFDEF(CONFIG_DEVICE, 
    paddr_t base_addr = waddr & ~0x3u;
    if (wmask & 0x1u) mmio_write(base_addr + 0, 1, (wdata >> 0) & 0xFFu);
    if (wmask & 0x2u) mmio_write(base_addr + 1, 1, (wdata >> 8) & 0xFFu);
    if (wmask & 0x4u) mmio_write(base_addr + 2, 1, (wdata >> 16) & 0xFFu);
    if (wmask & 0x8u) mmio_write(base_addr + 3, 1, (wdata >> 24) & 0xFFu);
    return;
  );
  out_of_bound(waddr);
}

void mrom_read(int32_t addr, int32_t *data) {
  *data = mrom_mem[(addr - MROM_BASE) / 4];
}

void flash_read(int32_t addr, int32_t *data) {
  *data = *(int32_t *)&flash_mem[addr & ~0x3u];
#if defined(CONFIG_STORAGE_LOG)
  static int read_count = 0;
  read_count++;
  if (read_count % 10000 == 0)
    printf("flash read addr 0x%x, data 0x%x\n", addr, *data);
#endif
}

// 4MB x 8bit PSRAM array
static uint8_t psram_mem[4 * 1024 * 1024] = {0};

void psram_write_byte(int32_t addr, char data) {
  psram_mem[addr] = (uint8_t)data;
  // printf("write psram addr 0x%x, data 0x%02x\n", addr, (uint8_t)data);
}

char psram_read_byte(int32_t addr) {
  uint8_t data = psram_mem[addr];
  // printf("read psram addr 0x%x, data 0x%02x\n", addr, data);
  return (char)data;
}

// 32MB SDRAM = 4 Banks * 8192 Rows * 512 Columns * 16 bits
// Total elements = 4 * 8192 * 512 = 16,777,216 (16M words)
#define SDRAM_SIZE (4 * 8192 * 512)
uint16_t *sdram_ptr[4] = {NULL, NULL, NULL, NULL}; // 4 banks of SDRAM

void init_sdram() {
  int id;
  for (id = 0; id < 4; id++) {
    if (sdram_ptr[id] == NULL) {
      sdram_ptr[id] = (uint16_t *)malloc(SDRAM_SIZE * sizeof(uint16_t));
      // Optional: Initialize with 0 or random data
      for (uint32_t i = 0; i < SDRAM_SIZE; i++)
        sdram_ptr[id][i] = 0;
    }
  }
}

// Map Bank, Row, Column to a linear address
// Address = Bank << 22 | Row << 9 | Column
uint32_t get_addr(int bank, int row, int col) {
  return (uint32_t)((bank << 22) | (row << 9) | (col & 0x1FF));
}

void sdram_write(int bank, int row, int col, uint16_t data, int dqm_low,
                 int dqm_high, int chip_id) {
  if (sdram_ptr[chip_id] == NULL)
    init_sdram();
  uint32_t addr = get_addr(bank, row, col);
  if (addr < SDRAM_SIZE) {
    uint16_t old_data = sdram_ptr[chip_id][addr];
    uint16_t new_data = old_data;

    if (dqm_low == 0) {
      new_data = (new_data & 0xFF00) | (data & 0x00FF);
    }
    if (dqm_high == 0) {
      new_data = (new_data & 0x00FF) | (data & 0xFF00);
    }

    sdram_ptr[chip_id][addr] = new_data;
#if defined(CONFIG_STORAGE_LOG)
    static int write_count = 0;
    write_count++;
    if (write_count % 10000 == 0)
      printf(" sdram write addr 0x%x, data 0x%04x new data 0x%04x(old data "
             "0x%04x, dqm_low %d, dqm_high %d)\n ",
             addr, data, new_data, old_data, dqm_low, dqm_high);
#endif
  }
}

uint16_t sdram_read(int bank, int row, int col, int chip_id) {
  if (sdram_ptr[chip_id] == NULL)
    init_sdram();
  uint32_t addr = get_addr(bank, row, col);
#if defined(CONFIG_STORAGE_LOG)
  static int read_count = 0;
  read_count++;
  if (read_count % 10000 == 0)
    printf(" sdram read addr 0x%x, sdram_ptr content 0x%04x\n ", addr,
           sdram_ptr[chip_id][addr]);
#endif
  if (addr < SDRAM_SIZE)
    return sdram_ptr[chip_id][addr];
  return 0xDEAD; // Error indicator
}