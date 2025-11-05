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
#include <cpu/difftest.h>
#include "../local-include/reg.h"
#include <cpu/cpu.h>
#include <fmt-def.h>

extern const char* regs[];

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool succ = true;

  //ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);

  if (cpu.pc != ref_r->pc) {   //check pc
    succ = false;
    printf("\e[1;31mPC DIFFTESET ERROR!\e[0m\n");
    goto print_error_info;
  }
  else{
    //succ = (memcmp(cpu.gpr, ref_r->gpr, DIFFTEST_REG_SIZE) == 0) ; // check gpr
    for(int i = 0; i < MUXDEF(CONFIG_RVE, 16, 32); i++){
      if(cpu.gpr[i] != ref_r->gpr[i]){
        succ = false;
        break;
      }
    }
    
    if(!succ){
      printf("\e[1;31mGPR DIFFTESET ERROR!\e[0m\n");
      goto print_error_info;
    }
  }

  succ = (cpu.csr.mstatus == ref_r->csr.mstatus) && 
         (cpu.csr.mcause == ref_r->csr.mcause) &&
         (cpu.csr.mepc == ref_r->csr.mepc) && 
         (cpu.csr.mtvec == ref_r->csr.mtvec);
  if(succ)
    return true;
  if(!succ){
      printf("\e[1;31mCSR DIFFTESET ERROR!\e[0m\n");
      printf("ref csr info:\n");
      if(cpu.csr.mepc != ref_r->csr.mepc) printf("-->"); 
      printf("mepc: 0x" FMT_WORD_HEX_WIDTH "\n", ref_r->csr.mepc);
      if(cpu.csr.mcause != ref_r->csr.mcause) printf("-->");
      printf("mcause: 0x" FMT_WORD_HEX_WIDTH "\n", ref_r->csr.mcause);
      if(cpu.csr.mstatus != ref_r->csr.mstatus) printf("-->");
      printf("mstatus: 0x" FMT_WORD_HEX_WIDTH "\n", ref_r->csr.mstatus);
      if(cpu.csr.mtvec != ref_r->csr.mtvec) printf("-->");
      printf("mtvec: 0x" FMT_WORD_HEX "\n", ref_r->csr.mtvec);
     goto print_error_info;
  }

  

print_error_info:
  printf("\e[1;31mDifftest ERROR!\e[0m\n");
  
  printf("ref: reg info:\n");
  int reg_num = MUXDEF(CONFIG_RVE, 16, 32);
  for (int i = 0; i < reg_num; i++) {
        if(i%4 == 0)
          printf("ref: ");
        if(ref_r->gpr[i] != cpu.gpr[i])
          printf("$%s = " "\033[1;31m" "0x" FMT_WORD_HEX_WIDTH "\033[0m" "\t", regs[i], ref_r->gpr[i]);
        else
          printf("$%s = 0x"FMT_WORD_HEX_WIDTH"\t", regs[i], ref_r->gpr[i]);
        if((i+1)%4 == 0)
          putchar('\n');
  }
  printf("ref: $pc = 0x" FMT_WORD_HEX_WIDTH "\n", ref_r->pc);

  isa_csr_display();

#ifdef CONFIG_ITRACE
  //print_iringbuf();
#endif 
  return false; // the reg info will be printed when nemu is ABORTed 
}

void isa_difftest_attach() {
}
