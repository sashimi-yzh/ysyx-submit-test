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
#include "cpu/cpu.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *csrs[] = {
  "mcause", "mepc", "mstatus", "mtvec" 
};

void isa_reg_display() {
  static int i;
  _Log(ANSI_FG_RED "RegName  Hex_Value       Dec_Value\n" ANSI_NONE);

  for(i=0; i<sizeof(regs)/sizeof(regs[0]); i++){
    _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE, regs[i]);
    _Log("0x%08x\t %010u\n", cpu.gpr[i], cpu.gpr[i]);
  }

  _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE "0x%08x\t %010u\n","pc",cpu.pc,cpu.pc);
}

word_t isa_reg_str2val(const char *s) {
  if(strcmp(s,"pc")==0) return cpu.pc;
  for(int i=0;i<sizeof(regs)/sizeof(regs[0]);i++){
    if(strcmp(s,regs[i])==0){
      return cpu.gpr[i];
    }
  }
  return 0;
}

void isa_csr_display() {
  _Log(ANSI_FG_RED "CsrName  Hex_Value       Dec_Value\n" ANSI_NONE);

  _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE, csrs[0]);
  _Log("0x%08x\t %010u\n", cpu.csr.mcause, cpu.csr.mcause);

  _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE, csrs[1]);
  _Log("0x%08x\t %010u\n", cpu.csr.mepc, cpu.csr.mepc);

  _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE, csrs[3]);
  _Log("0x%08x\t %010u\n", cpu.csr.mtvec, cpu.csr.mtvec);
  
  _Log(ANSI_FG_YELLOW "$%s " ANSI_NONE, csrs[2]);
  _Log("0x%08x\t %010u\n", cpu.csr.mstatus, cpu.csr.mstatus);
}
