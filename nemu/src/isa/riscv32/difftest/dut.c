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

bool isa_difftest_checkregs(CPU_state *ref_r, vaddr_t pc) {
  	//pc is s->pc, namely the initial addr of the last executed inst
	//ref_r -> pc and cpu.pc are the initial addr of the next inst to execute
	bool tag = true;
	if(ref_r -> pc != cpu.pc){
		tag = false;
	}
	for(int i = 0; i < 32; ++i){
		if(ref_r -> gpr[i] != cpu.gpr[i]){
			tag = false;
		}
	}
	
	if(!tag){
		printf("--------------------- Difftest Failure! ------------------------\n");
		printf("inst at addr %#8.8x produces different results!\n",pc);
		printf("----------------------------------------------------------------\n");
		printf("	REF				  DUT\n");
		for(int j = 0; j < 32; ++j)
			printf("%3s : 0x%8.8x			0x%8.8x\n",reg_name(j),ref_r->gpr[j],cpu.gpr[j]);
		printf("%3s : 0x%8.8x           		0x%8.8x\n","pc",ref_r->pc,cpu.pc);
		printf("----------------------------------------------------------------\n");
	}

	return tag;
}


void isa_difftest_attach() {
}
