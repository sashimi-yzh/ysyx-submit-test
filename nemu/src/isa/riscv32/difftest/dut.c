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

// bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
//   return false;
// }
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  // pc实现difftest
  if (cpu.pc != ref_r->pc) {
    printf("%sPC mismatch at pc = " FMT_WORD ", ref = " FMT_WORD ", dut = " FMT_WORD "%s\n",
        ANSI_FG_RED,pc, ref_r->pc, cpu.pc,ANSI_NONE );
    return false;
  }
  // 寄存器实现difftest
  for (int i = 0; i < 32; i++) {
    if (cpu.gpr[i] != ref_r->gpr[i]) {
      printf("%sGPR mismatch at pc = " FMT_WORD ", reg = %s, ref = " FMT_WORD ", dut = " FMT_WORD "%s\n",
          ANSI_FG_RED,pc, reg_name(i), ref_r->gpr[i], cpu.gpr[i],ANSI_NONE );
      return false;
    }
  }

  return true;
}

void isa_difftest_attach() {
}
