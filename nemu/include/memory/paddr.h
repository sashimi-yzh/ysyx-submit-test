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
#define RESET_VECTOR (PMEM_LEFT + CONFIG_PC_RESET_OFFSET)
enum  mem_rw{
    MEM_READ,
    MEM_WRITE,
};

typedef struct {
  uint32_t addr;
  uint32_t data;
  uint32_t enable;
  uint32_t fcn; 
} mem_access_t;


/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

#ifdef CONFIG_HAS_MROM
uint8_t* guest_to_mrom(paddr_t paddr);
paddr_t host_to_mrom(uint8_t *haddr);
#endif
#ifdef CONFIG_HAS_SRAM
uint8_t* guest_to_sram(paddr_t paddr);
paddr_t host_to_sram(uint8_t *haddr);
#endif
static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}
static inline bool in_mrom_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_MROM, res=addr - CONFIG_MROM_BASE < CONFIG_MROM_SIZE);
  return  res;  
}

static inline bool in_sram_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_SRAM, res=addr - CONFIG_SRAM_BASE < CONFIG_SRAM_SIZE);
  return  res;  
}

static inline bool in_psram_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_PSRAM, res=addr - CONFIG_PSRAM_BASE < CONFIG_PSRAM_SIZE);
  return  res;  
}

static inline bool in_sdram_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_SDRAM, res=addr - CONFIG_SDRAM_BASE < CONFIG_SDRAM_SIZE);
  return  res;  
}

static inline bool in_flash_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_FLASH, res=addr - CONFIG_FLASH_BASE < CONFIG_FLASH_SIZE);
  return  res;  
}


static inline bool in_uart_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_UART, res=(addr - CONFIG_UART_BASE) < CONFIG_UART_SIZE);
  return  res;  
}

static inline bool in_clint_pmem(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_CLINT, res=(addr - CONFIG_CLINT_BASE) < CONFIG_CLINT_SIZE);
  return  res;  
}

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
