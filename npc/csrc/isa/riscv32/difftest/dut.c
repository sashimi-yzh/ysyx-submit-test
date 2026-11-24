/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NPC is licensed under Mulan PSL v2.
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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
// Debug purpose
#if 0
  int i;
  for (i = 0; i < sizeof(ref_r->gpr)/sizeof(ref_r->gpr[0]); i++) {
    printf("reg %d value 0x%08x\t", i, ref_r->gpr[i]);
    if (i % 4 == 0)
      printf("\n");
  }

  printf("reg %-4s value 0x%08x\n", "pc", ref_r->pc);
#endif
  int i;
  bool same = true;
  for (i = 0; i < sizeof(ref_r->gpr)/sizeof(ref_r->gpr[0]); i++) {
    if (ref_r->gpr[i] != ext_get_gpr_npc(i)) {
      printf("different regs found at index %d, \
        ref regs: %x, dut regs: %x\n", \
        i, ref_r->gpr[i], ext_get_gpr_npc(i));
      same = false;
    }
  }
  return same;
}

void isa_difftest_attach() {
}
