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

#define MROM_BASE 0x20000000
#define SRAM_BASE 0x0f000000

/* convert the guest physical address in the guest program to host virtual address in NEMU */
uint8_t* guest_to_host(paddr_t paddr);
/* convert the host virtual address in NEMU to guest physical address in the guest program */
paddr_t host_to_guest(uint8_t *haddr);

static inline bool in_pmem(paddr_t addr) {
  return addr - CONFIG_MBASE < CONFIG_MSIZE;
}

// typedef struct{
//   paddr_t start;
//   paddr_t end;
//   bool filter_en;
//   word_t filter_data;
// }mtrace_info;
// mtrace_info mtrace_thing;

void init_mtrace();
void close_mtrace();
// void mtrace_set(paddr_t start,paddr_t end,bool filter_en,word_t filter_data);
void mtrace_log(char type,paddr_t addr,word_t data,int len);
void mtrace_filter_output(paddr_t start_addr, paddr_t end_addr, bool filter_en, uint32_t filter_data);

word_t paddr_read(paddr_t addr, int len);
void paddr_write(paddr_t addr, int len, word_t data);

#endif
