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

#ifndef __MEMORY_PADDR_H__
#define __MEMORY_PADDR_H__

#include <common.h>

#ifdef CONFIG_SOC

#define PMEM_LEFT_MROM  ((paddr_t)CONFIG_MROM_BASE)
#define PMEM_RIGHT_MROM ((paddr_t)CONFIG_MROM_BASE + CONFIG_MROM_SIZE - 1)

#define PMEM_LEFT_SRAM  ((paddr_t)CONFIG_SRAM_BASE)
#define PMEM_RIGHT_SRAM ((paddr_t)CONFIG_SRAM_BASE + CONFIG_SRAM_SIZE - 1)

#define PMEM_LEFT_FLASH  ((paddr_t)CONFIG_FLASH_BASE)
#define PMEM_RIGHT_FLASH ((paddr_t)CONFIG_FLASH_BASE + CONFIG_FLASH_SIZE - 1)

#define PMEM_LEFT_PSRAM  ((paddr_t)CONFIG_PSRAM_BASE)
#define PMEM_RIGHT_PSRAM ((paddr_t)CONFIG_PSRAM_BASE + CONFIG_PSRAM_SIZE - 1)

#define PMEM_LEFT_SDRAM  ((paddr_t)CONFIG_SDRAM_BASE)
#define PMEM_RIGHT_SDRAM ((paddr_t)CONFIG_SDRAM_BASE + CONFIG_SDRAM_SIZE - 1)

#ifdef CONFIG_NOBOOTLOADER
  #define RESET_VECTOR (PMEM_LEFT_SDRAM + CONFIG_PC_RESET_OFFSET)
#else 
  #define RESET_VECTOR (PMEM_LEFT_FLASH + CONFIG_PC_RESET_OFFSET)
#endif


static inline bool in_mrom(paddr_t addr) {
  return addr >= PMEM_LEFT_MROM && addr <= PMEM_RIGHT_MROM;
}

static inline bool in_sram(paddr_t addr) {
  return addr >= PMEM_LEFT_SRAM && addr <= PMEM_RIGHT_SRAM;
}

static inline bool in_flash(paddr_t addr) {
  return addr >= PMEM_LEFT_FLASH && addr <= PMEM_RIGHT_FLASH;
}

static inline bool in_psram(paddr_t addr) {
  return addr >= PMEM_LEFT_PSRAM && addr <= PMEM_RIGHT_PSRAM;
}

static inline bool in_sdram(paddr_t addr) {
  return addr >= PMEM_LEFT_SDRAM && addr <= PMEM_RIGHT_SDRAM;
}

static inline bool in_pmem(paddr_t addr) {
  return in_mrom(addr) || in_sram(addr) || in_flash(addr) || in_psram(addr) || in_sdram(addr);
}

#else

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)

#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

#endif


/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);



word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
