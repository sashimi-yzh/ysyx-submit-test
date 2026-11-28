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

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
/* ysyxSoC address space emulation is only needed by the difftest REF build. */
#ifdef CONFIG_YSYXSOC_MODE
extern bool ysyxsoc_mode;
#define RESET_VECTOR (ysyxsoc_mode ? (paddr_t)CONFIG_FLASH_BASE : (PMEM_LEFT + CONFIG_PC_RESET_OFFSET))
#else
#define ysyxsoc_mode false
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#endif

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

#ifdef CONFIG_YSYXSOC_MODE
static inline bool in_mrom(paddr_t addr){
  return addr - CONFIG_MROM_BASE < CONFIG_MROM_SIZE;
}

static inline bool in_sram(paddr_t addr){
  return addr - CONFIG_SRAM_BASE < CONFIG_SRAM_SIZE;
}

static inline bool in_flash(paddr_t addr){
  return addr - CONFIG_FLASH_BASE < CONFIG_FLASH_SIZE;
}

static inline bool in_sdram(paddr_t addr){
  return addr - CONFIG_SDRAM_BASE < CONFIG_SDRAM_SIZE;
}
#endif

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
