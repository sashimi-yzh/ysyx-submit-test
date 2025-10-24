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

#define REGNUM 32
#define CSRNUM 4

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool flag = true;
  if(ref_r->pc != cpu.pc)
    flag = false;
  for(int i = 0; i < REGNUM; i++){
    if(ref_r->gpr[i] != cpu.gpr[i])
      flag = false;
  }
  // if(ref_r->csr[MSTATUS] != cpu.csr[MSTATUS])
  //   flag = false;
  if(ref_r->csr[MEPC] != cpu.csr[MEPC] || ref_r->csr[MCAUSE] != cpu.csr[MCAUSE] || ref_r->csr[MTVEC] != cpu.csr[MTVEC])
    flag = false;
  return flag;
}

void isa_difftest_attach() {
}
