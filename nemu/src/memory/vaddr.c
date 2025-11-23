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
#define SOC 0
word_t vaddr_ifetch(vaddr_t addr, int len) {
  return paddr_read(addr, len);
}

word_t vaddr_read(vaddr_t addr, int len) {
  if(SOC){
    if(addr - CONFIG_MBASE < CONFIG_MSIZE){
      return paddr_read(addr, len);
    }
    else if(addr - 0x0f000000 < 0x2000){
      return sramaddr_read(addr, len);
    }
    else{
      panic("address = " FMT_PADDR " is out of bound of sram and mrom at pc = " FMT_WORD,
        addr, cpu.pc);
    }
  }
  else {
    return paddr_read(addr, len);
  }
}

void vaddr_write(vaddr_t addr, int len, word_t data) {
  
  if(SOC){
    sramaddr_write(addr, len, data);
  }
  else {
    paddr_write(addr, len, data);
  }
}
