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

#define YSYXSOC_MROM_SIZE  ((paddr_t)0x00001000)
#define YSYXSOC_MROM_LEFT  ((paddr_t)0x20000000)
#define YSYXSOC_MROM_RIGHT ((paddr_t)YSYXSOC_MROM_LEFT + YSYXSOC_MROM_SIZE - 1)

#define YSYXSOC_SRAM_SIZE  ((paddr_t)0x00002000)
#define YSYXSOC_SRAM_LEFT  ((paddr_t)0x0F000000)
#define YSYXSOC_SRAM_RIGHT ((paddr_t)YSYXSOC_SRAM_LEFT + YSYXSOC_SRAM_SIZE - 1)

#define YSYXSOC_FLASH_SIZE  ((paddr_t)0x01000000)
#define YSYXSOC_FLASH_LEFT  ((paddr_t)0x30000000)
#define YSYXSOC_FLASH_RIGHT ((paddr_t)YSYXSOC_FLASH_LEFT + YSYXSOC_FLASH_SIZE - 1)

#define YSYXSOC_PSRAM_SIZE  ((paddr_t)0x00400000)
#define YSYXSOC_PSRAM_LEFT  ((paddr_t)0x80000000)
#define YSYXSOC_PSRAM_RIGHT ((paddr_t)YSYXSOC_PSRAM_LEFT + YSYXSOC_PSRAM_SIZE - 1)

#define YSYXSOC_SDRAM_SIZE  ((paddr_t)0x08000000)
#define YSYXSOC_SDRAM_LEFT  ((paddr_t)0xA0000000)
#define YSYXSOC_SDRAM_RIGHT ((paddr_t)YSYXSOC_SDRAM_LEFT + YSYXSOC_SDRAM_SIZE - 1)

#if !defined(CONFIG_TARGET_YSYXSOC)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
#else
#define RESET_VECTOR (YSYXSOC_FLASH_LEFT)
#endif


/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);


static inline bool in_pmem(paddr_t addr) {
  #if !defined(CONFIG_TARGET_YSYXSOC)
    return addr - CONFIG_MBASE < CONFIG_MSIZE;
  #else
    return (   (addr >= YSYXSOC_MROM_LEFT && addr <= YSYXSOC_MROM_RIGHT) \
           || (addr >= YSYXSOC_SRAM_LEFT && addr <= YSYXSOC_SRAM_RIGHT) \
           || (addr >= YSYXSOC_PSRAM_LEFT && addr <= YSYXSOC_PSRAM_RIGHT) \
           || (addr >= YSYXSOC_SDRAM_LEFT && addr <= YSYXSOC_SDRAM_RIGHT) \
           || (addr >= YSYXSOC_FLASH_LEFT && addr <= YSYXSOC_FLASH_RIGHT));
  #endif
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
