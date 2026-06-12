/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan
 * PSL v2. You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
 * NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <sys/cdefs.h>
__BEGIN_DECLS

#include "../local-include/reg.h"
#include "utils.h"
#include <cpu/difftest.h>
#include <isa.h>

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  bool is_pass = true;
  if (pc != ref_r->pc) {
    printf("Difftest dnpc fail:  nemu: " FMT_WORD "  ref: " FMT_WORD "\n", pc,
           ref_r->pc);
    is_pass = false;
  }
  int i;
  for (i = 0; i < LENGTH(cpu.gpr); i++) {
    if (gpr(i) != ref_r->gpr[i]) {
      printf("Difftest reg %d fail: nemu: " FMT_WORD "  ref: " FMT_WORD "\n", i,
             gpr(i), ref_r->gpr[i]);
      is_pass = false;
    }
  }

  if (!is_pass) {
    printf("FAIL @" FMT_WORD "\n", pc);
  }

  return is_pass;
}

void isa_difftest_attach() {}

__END_DECLS
