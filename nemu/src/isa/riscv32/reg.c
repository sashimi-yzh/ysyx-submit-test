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
#include <cpu/difftest.h>
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display(CPU_state cpu) {
  for(int i=0;i<MUXDEF(CONFIG_RVE, 16, 32);i++){
    printf("$%s\t%x\t\t%d\n",regs[i],cpu.gpr[i],cpu.gpr[i]);
  }
  printf("$pc\t%x\t\t%d\n",cpu.pc,cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if(s[0]=='$') s++;
  else{
    *success=false;
    return 0;
  }
  if(strcmp(s,"0")==0)  return cpu.gpr[0];
  for(int i=0;i<MUXDEF(CONFIG_RVE, 16, 32);i++){
    if(strcmp(s,regs[i])==0)  return cpu.gpr[i];
  }
  if(strcmp(s,"pc")==0) return cpu.pc;
  *success=false;
  return 0;
}

void isa_csr_w(word_t csraddr, word_t wdata){
  if(
      (csraddr == CSR_MCYCLE)
    ||(csraddr == CSR_MCYCLEH)
    ||(csraddr == CSR_MVENDORID)
    ||(csraddr == CSR_MARCHID)
    ||(csraddr == CSR_MISA)
  ){

  }else{
    csr(csraddr) = wdata;
  }

}
word_t isa_csr_r(word_t csraddr){
  if(
      (csraddr == CSR_MCYCLE)
    ||(csraddr == CSR_MCYCLEH)
  ){
    difftest_skip_ref();
  }else{

  }
  if(
      (csraddr != CSR_MTVEC)
    &&(csraddr != CSR_MSCRATCH)
    &&(csraddr != CSR_MEPC)
    &&(csraddr != CSR_MCAUSE)
    &&(csraddr != CSR_MSTATUS)
    &&(csraddr != CSR_MCYCLE)
    &&(csraddr != CSR_MCYCLEH)
    &&(csraddr != CSR_MISA)
    &&(csraddr != CSR_MVENDORID)
    &&(csraddr != CSR_MARCHID)
    &&(csraddr != CSR_MTVAL)
  ){
    Assert(0,"Error Read CSR Address!");
    return 0x67678787;
  }
  return csr(csraddr);
}
// #define CSR_MTVEC  0x305
// #define CSR_MSCRATCH 0x340
// #define CSR_MEPC   0x341
// #define CSR_MCAUSE 0x342
// #define CSR_MSTATUS 0x300
// #define CSR_MCYCLE 0xb00
// #define CSR_MCYCLEH 0xb80
// #define CSR_MISA   0x301
// #define CSR_MVENDORID 0xf11
// #define CSR_MARCHID 0xf12
// #endif