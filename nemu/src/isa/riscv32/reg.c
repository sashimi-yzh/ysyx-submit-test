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
#include <stdio.h>
#include <fmt-def.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};


/*
const char *csrs[] = {
  "mepc",
  "mcause",
  "mstatus",
  "mtvec",
};

word_t get_csr_str2index(const char* _csr_name){
  for(int i=0; i<sizeof(csrs)/sizeof(csrs[0]); i++){
    if(strcmp(_csr_name, csrs[i])==0)
      return i;
  }
  panic("ERROR: Unknow CSR!");
}

word_t* get_csr_reg_addr(word_t imm){
  switch (imm)
  {
  case 0x341: return &cpu.csr[0];
  case 0x342: return &cpu.csr[1];
  case 0x300: return &cpu.csr[2];
  case 0x305: return &cpu.csr[3];
  default: panic("ERROR: Unknow CSR!");
  }
}

void isa_csr_str2val(const char *s, word_t *val, bool *success){
  int index = -1;
  for(int i=0; i<sizeof(csrs)/sizeof(csrs[0]); i++){
    if(strcmp(s, csrs[i])==0)
      index = i;
  }
  if(index == -1) {
    if(success != NULL) *success = false;
    return;
  }
  if(success != NULL) *success = true;
  *val = cpu.csr[index];
}

word_t *get_isa_csr_str2addr(const char *s){
  return &cpu.csr[get_csr_str2index(s)];
}
*/

void isa_csr_display(){
  printf("csr info:\n");
  printf("mepc = 0x"FMT_WORD_HEX_WIDTH"\n", cpu.csr.mepc);
  printf("mcause = 0x"FMT_WORD_HEX_WIDTH"\n", cpu.csr.mcause);
  printf("mstatus = 0x"FMT_WORD_HEX_WIDTH"\n", cpu.csr.mstatus);
  printf("mtvec = 0x"FMT_WORD_HEX_WIDTH"\n", cpu.csr.mtvec);
}

void isa_reg_display() {
	printf("reg info:\n");
  int reg_num = MUXDEF(CONFIG_RVE, 16, 32);
  for (int i = 0; i < reg_num; i++) {
        printf("$%s = 0x"FMT_WORD_HEX_WIDTH"\t", regs[i], gpr(i));
        if((i+1)%4 == 0)
          putchar('\n');
  }
  printf("$pc = 0x" FMT_WORD_HEX_WIDTH "\n", cpu.pc);
}

word_t isa_reg_str2val(const char *s, bool *success) {
  if(!strcmp(s, "$pc") || !strcmp(s, "pc"))
  {
    *success = true;
    return cpu.pc;
  }

  int len = MUXDEF(CONFIG_RVE, 16, 32);
  for(int i=0; i<len; i++){
    if(strcmp(s+1, regs[i])==0 || strcmp(s, regs[i])==0){   // s+1 to skip '$'
      *success = true;
      return gpr(i);
    }
  }
  *success = false;
  return 0;
}


word_t isa_reg_read(int idx){
  return gpr(idx);
}

void isa_reg_write(int idx, word_t val){
  gpr(idx) = val;
}