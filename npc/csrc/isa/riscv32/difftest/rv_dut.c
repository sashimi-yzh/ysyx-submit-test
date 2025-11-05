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
#include <sim.h>
#include <color.h>

#include <verilator.h>

static CPU_state cpu_state_buf = {}; 
static int state_index = 0;
static bool first = true;
#define INDEX_INC do{state_index = (state_index + 1) % 2;}while(0)

extern const char *regs[];


// 为了匹配，所以让ref_r使用cpu_state_buf推迟了一个周期
// 改了，现在不推迟了
// 现在又要推迟了!! 不过是让npc_cpu推迟一个周期
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  int i =0;
  bool succ = true;
  // static word_t ref_pc_last = 0;
  CPU_state* cpu_state_buf_ptr = &cpu_state_buf;


  if(!first){
    
    //if(ref_r->pc != npc_cpu.pc){
    for(i = 0; i <  MUXDEF(CONFIG_RVE,16,32); i++){
      if(ref_r->gpr[i] != npc_cpu.gpr[i]){
        succ = false;
        break;
      }
    }
     if(!succ){

      
      printf("ref reg info:\n");
      for (int j = 0; j < MUXDEF(CONFIG_RVE,16,32); j++)
      {
              if(ref_r->gpr[j] != npc_cpu.gpr[j])
                printf("$%s = 0x" L_RED  FMT_WORD_HEX_WIDTH COLOR_NONE "\t", regs[j], ref_r->gpr[j]);
              else
                printf("$%s = 0x" FMT_WORD_HEX_WIDTH "\t", regs[j], ref_r->gpr[j]);
              if ((j + 1) % 4 == 0)
                      putchar('\n');
      }
      printf("$pc = 0x" FMT_WORD_HEX_WIDTH "\n", ref_r->pc);
    }


    // if(succ && cpu_state_buf.pc != npc_cpu.gpr[i]){
    //     succ = false;
    //     printf(L_RED "npc: pc = 0x" FMT_WORD_HEX_WIDTH "\tnemu: pc = 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.pc,cpu_state_buf.pc);
    //   }

    if(ref_r->pc != npc_cpu.pc){
        succ = false;
        printf(L_RED "npc: pc = 0x" FMT_WORD_HEX_WIDTH "\tnemu: pc = 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.pc,ref_r->pc);
    }
    if(cpu_state_buf_ptr->csr.mepc != ref_r->csr.mepc && npc_cpu.csr.mepc != ref_r->csr.mepc){
      printf(L_RED "npc: mepc   = 0x" FMT_WORD_HEX_WIDTH "\tnemu: mepc   = 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.csr.mepc,ref_r->csr.mepc);
      succ = false;
    }
    if(cpu_state_buf_ptr->csr.mcause != ref_r->csr.mcause && npc_cpu.csr.mcause != ref_r->csr.mcause){
      printf(L_RED "npc: mcause = 0x" FMT_WORD_HEX_WIDTH "\tnemu: mcause = 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.csr.mcause,ref_r->csr.mcause);
      succ = false;
    }
    if(cpu_state_buf_ptr->csr.mstatus != ref_r->csr.mstatus && npc_cpu.csr.mstatus != ref_r->csr.mstatus){
      printf(L_RED "npc: mstatus= 0x" FMT_WORD_HEX_WIDTH "\tnemu: mstatus= 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.csr.mstatus,ref_r->csr.mstatus);
      succ = false;
    }
    if(cpu_state_buf_ptr->csr.mtvec != ref_r->csr.mtvec && npc_cpu.csr.mtvec != ref_r->csr.mtvec){
      printf(L_RED "npc: mtvec  = 0x" FMT_WORD_HEX_WIDTH "\tnemu: mtvec  = 0x" FMT_WORD_HEX_WIDTH "\n" COLOR_NONE,npc_cpu.csr.mtvec,ref_r->csr.mtvec);
      succ = false;
    }

   
  }
  if(!succ){
      printf("\e[1;31m Difftest ERROR!\e[0m\n ");
      // printf("IF GPR DIFF TEST ERROR: DO NOT SEE CURRENT INSTRATION, SEE PREVIOUS ONE!\n");
  }
  first = false;
  memcpy(&cpu_state_buf, &npc_cpu, DIFFTEST_REG_SIZE);
  // ref_pc_last = ref_r->pc;
 // printf("npc:nemu:ref_r->pc==0x%x\n",ref_r->pc);
  return succ;
}


void isa_difftest_attach() {
}
