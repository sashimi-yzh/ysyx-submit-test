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


#define CHECKDIFF(reg, fmt, ...) \
  if (ref_r->reg != cpu.reg) { \
    printf("[DIFF]==>> " fmt " got: 0x%08x, but expected: 0x%08x\n", ##__VA_ARGS__, cpu.reg, ref_r->reg); \
    flag = false; \
  }

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
    bool flag = true;

    CHECKDIFF(pc, "pc");

    for(int i=0; i<MUXDEF(CONFIG_RVE, 16, 32); i++) {
        CHECKDIFF(gpr[i], "gpr[%02d]", i);
    }

    CHECKDIFF(csr.mstatus, "mstatus");
    CHECKDIFF(csr.mcause,  "mcause ");
    CHECKDIFF(csr.mepc,    "mepc   ");
    CHECKDIFF(csr.mtvec,   "mtvec  ");

    if(!flag) {
        printf("Difftest: Error at pc: 0x%08x\n", pc);
        return false;
    }

    return true;
}

void isa_difftest_attach() {
}
