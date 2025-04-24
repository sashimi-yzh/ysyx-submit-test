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
#ifndef __ICS_EXPORT
#include "../local-include/csr.h"
#endif

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
#ifndef __ICS_EXPORT
  bool ok = true;
  if (memcmp(&cpu.gpr[1], &ref_r->gpr[1], DIFFTEST_REG_SIZE - sizeof(cpu.gpr[0]))) {
    int i;
    // do not check $0
    for (i = 1; i < ARRLEN(cpu.gpr); i ++) {
      difftest_check_reg(reg_name(i), pc, ref_r->gpr[i], cpu.gpr[i]);
    }
    difftest_check_reg("pc", pc, ref_r->pc, cpu.pc);
    ok = false;
  }
#ifndef CONFIG_PA
#define check_csr(name) ok &= difftest_check_reg(str(name), pc, ref_r->name, name->val);
#define csr_list(f) f(mstatus) f(mepc) f(mtval) f(mcause) \
                               f(sepc) f(stval) f(scause)
  MAP(csr_list, check_csr);
#endif
  return ok;
#else
  return false;
#endif
}

void isa_difftest_attach() {
}
