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
#define MROM_SIZE 4 * 1024
#define MROM_BASE 0x20000000
#define SRAM_SIZE 8 * 1024
#define SRAM_BASE 0x0f000000
#define FLASH_SIZE 8 * 1024 * 1024
#define FLASH_BASE 0x30000000
#define PSRAM_SIZE 16 * 1024 * 1024
#define PSRAM_BASE 0x80000000
#define SDRAM_SIZE 64 * 1024 * 1024
#define SDRAM_BASE 0xa0000000
#define UART16550_BASE 0x10000000
#define UART16550_SIZE 0x10000
#define CLINT_BASE 0x02000000
#define CLINT_SIZE 0x10000
uint8_t* flash_guest_to_host(paddr_t paddr);
#define FLASH_LEFT  ((paddr_t)FLASH_BASE)
#define FLASH_RIGHT ((paddr_t)FLASH_BASE + FLASH_SIZE - 1)
#define FLASH_RESET_VECTOR (FLASH_LEFT + CONFIG_PC_RESET_OFFSET)

#define PMEM_LEFT  ((paddr_t)CONFIG_MBASE)
#define PMEM_RIGHT ((paddr_t)CONFIG_MBASE + CONFIG_MSIZE - 1)
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  if(addr >= CONFIG_MBASE && addr < CONFIG_MBASE + CONFIG_MSIZE){
    return addr - CONFIG_MBASE < CONFIG_MSIZE;
  }
  else if (addr >= CLINT_BASE && addr < CLINT_BASE + CLINT_SIZE){
    // difftest_skip_ref();
    return addr - CLINT_BASE < CLINT_SIZE;
  }
  #ifdef CONFIG_YSYXSOC
  else if(addr >= MROM_BASE && addr < MROM_BASE + MROM_SIZE){
    return addr - MROM_BASE < MROM_SIZE;
  }
  else if (addr >= SRAM_BASE && addr < SRAM_BASE + SRAM_SIZE){
    return addr - SRAM_BASE < SRAM_SIZE;
  }
  else if (addr >= FLASH_BASE && addr < FLASH_BASE + FLASH_SIZE){
    return addr - FLASH_BASE < FLASH_SIZE;
  }
  else if (addr >= PSRAM_BASE && addr < PSRAM_BASE + PSRAM_SIZE){
    return addr - PSRAM_BASE < PSRAM_SIZE;
  }
  else if (addr >= SDRAM_BASE && addr < SDRAM_BASE + SDRAM_SIZE){
    return addr - SDRAM_BASE < SDRAM_SIZE;
  }
  else if (addr >= UART16550_BASE && addr < UART16550_BASE + UART16550_SIZE){
    return addr - UART16550_BASE < UART16550_SIZE;
  } 
  #endif
  else{
    return addr - CONFIG_MBASE < CONFIG_MSIZE;
  }
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
