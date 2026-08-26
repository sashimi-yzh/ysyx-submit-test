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
#include <cpu/difftest.h>
#include "../local-include/reg.h"

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc, vaddr_t npc) {
  for(int i=0;i<MUXDEF(CONFIG_RVE, 16, 32);i++){
    if(gpr(i)!=ref_r->gpr[i]) {
      Log("%s REG[%02d](%s) DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different GPR!", ANSI_FG_RED),i,reg_name(i),gpr(i),ref_r->gpr[i],pc);
      return false;
    }
  }
  if(ref_r->pc != npc) {
    //printf("===%08x===%08x===\n",ref_r->pc,pc);
    Log("%s DUT:%08x REF:%08x at pc:%08x",ANSI_FMT("Different NEXT PC!", ANSI_FG_RED),npc,ref_r->pc,pc);
    return false;
  }
  return true;
}

void isa_difftest_attach() {
}
