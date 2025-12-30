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

//static cpu.csr.mstatus = 0x1800;
void etrace_display(){
		printf("\netrace display:\n");
		printf("mcause(Interrupt):%d \nmcause(Code):\t%02d\n", cpu.csr.mcause >> 31, cpu.csr.mcause & 0x7FFFFFFF);
		printf("mstatus:\t%02d\n", cpu.csr.mstatus);
		printf("mepc:\t 0x%x\n", cpu.csr.mepc);
		printf("mtvec:\t 0x%x\n\n", cpu.csr.mtvec);
}


word_t isa_raise_intr(word_t NO, vaddr_t epc) {
	/* TODO: Trigger an interrupt/exception with ``NO''.
	* Then return the address of the interrupt/exception vector.
	*/
	cpu.csr.mepc = epc;
	cpu.csr.mcause = NO;
	IFDEF(CONFIG_ETRACE, etrace_display());
	return cpu.csr.mtvec;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
