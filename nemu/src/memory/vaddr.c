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
#include <memory/paddr.h>

void mem_access_hook(uint8_t role , vaddr_t addr, word_t data){
  mem_access_t  mem_access = (mem_access_t){
    .addr = addr,
    .data = data,
    .enable = 1,
    .fcn = role
  };
  cpu.mem_access = mem_access;
}
word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  word_t data = paddr_read(addr, len);
  mem_access_hook(MEM_READ,addr,data);
  // printf("vaddr_read addr: " FMT_WORD " len: %d data %x\n", addr, len,data);
  return data;
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  // printf("vaddr_write addr: " FMT_WORD " len: %d data %x\n", addr, len,data);
  mem_access_hook(MEM_WRITE,addr, data);
  paddr_write(addr, len, data);
}
