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

#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

#define MROM_BASE 0x20000000
#define PMROM_LEFT  ((paddr_t)MROM_BASE)

// Flash related settings
#define FLASH_BASE  0x30000000
#define FLASH_SIZE  (16 * 1024 * 1024)
#define PFLASH_LEFT (FLASH_BASE + CONFIG_PC_RESET_OFFSET)

#define PSRAM_BASE  0x80000000
#define PSRAM_SIZE  (4 * 1024 * 1024)

#define SDRAM_BASE  0xa0000000
#define SDRAM_SIZE  (4 * 8192 * 512)

// define RESET_VECTOR as MROM base
#define RESET_VECTOR (PFLASH_LEFT)


/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  return (addr - CONFIG_MBASE < CONFIG_MSIZE) ||
         (addr >= MROM_BASE && addr < MROM_BASE + 0x1000) ||
         (addr >= FLASH_BASE && addr < FLASH_BASE + FLASH_SIZE) ||
          (addr >= PSRAM_BASE && addr < PSRAM_BASE + PSRAM_SIZE) ||
          (addr >= SDRAM_BASE && addr < SDRAM_BASE + SDRAM_SIZE);
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
