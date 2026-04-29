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
#include "common.h"
#include "debug.h"

/*
 * see nemu/tools/spike-diff/difftest.cc
 * no diffetent
 */
bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
	for(int i=0;i<sizeof(ref_r->gpr)/sizeof(word_t);i++){
		if(ref_r->gpr[i]!=cpu.gpr[i]){
			Log(ANSI_FMT("reg check failed:",ANSI_FG_RED)
					" at pc = 0x%08X, expect $%s = %08X but get %08X",
					pc,
					reg_name(i),ref_r->gpr[i],cpu.gpr[i]
			);
			return false;
		}
	}
	return true;
}

void isa_difftest_attach() {
}
