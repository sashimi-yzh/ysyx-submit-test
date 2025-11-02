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

#include <isa.h>
#include "local-include/reg.h"


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

//modify by Jason @ 2025.10.16
uint32_t sregs[4096] = {
	[0xf11] = 0x79737978,
	[0xf12] = 0x015fdf05
};


void isa_reg_display() {
    for(int i = 0; i < 32; ++i){
        printf("%3s : 0x%8.8x\n", reg_name(i), cpu.gpr[i]);
    }
    printf("%3s : 0x%8.8x\n", "pc",cpu.pc);
}


word_t isa_reg_str2val(const char *s, bool *success) {
  for (int i = 0; i <= 31; ++i){
    if (strcmp(regs[i], s) == 0){
        *success = true;
        return cpu.gpr[i];
    }
  }

  if (strcmp("pc",s) == 0){
    *success = true;
    return cpu.pc;
  }

  *success = false;
  return 0;
}


void reg_modification(const char *s, uint32_t data){
    for (int i = 0; i <= 31; ++i){
        if(strcmp(regs[i], s) == 0)
                cpu.gpr[i] = data;
    }
}




