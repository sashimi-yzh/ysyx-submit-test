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
#include "local-include/reg.h"
#include <string.h>


const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


const CSR_INFO csr_info[USED_CSR_NUM]= {
  {.idx=0x180,.name="STAP"},
  {.idx=0x300,.name="MSTATUS"},
  {.idx=0x305,.name="MTVEC"},
  {.idx=0x341,.name="MEPC"},
  {.idx=0x342,.name="MCAUSE"},
};

void isa_reg_display() {
    for (int i=0;i<MUXDEF(CONFIG_RVE, 16, 32) ;i++){
        printf("%4s:%.8x",regs[i],gpr(i));
        (i%3==0)?printf("\n"):printf(" ");
    }
    printf("%4s:%.8x\n","pc",cpu.pc);
}


word_t isa_reg_str2val(const char *s, bool *success) {
  word_t val=0;
  if(strstr(s,"$pc")){
    return cpu.pc;
  }
  for (int i= 0;i<MUXDEF(CONFIG_RVE, 16, 32);i++){
      if (strstr(s,regs[i])){
        val = gpr(i);
        *success = true;
      } 
  }
  return val;
}

void isa_csr_display() {
    for(int i=0;i<USED_CSR_NUM;i++){
        printf("%4s:%.8x\n",csr_info[i].name,csr(csr_info[i].idx));
    }
    printf("%4s:%.8x\n","pc",cpu.pc);
}
