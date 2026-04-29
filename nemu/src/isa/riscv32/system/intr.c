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

word_t g_csr_MTVEC;

word_t isa_raise_intr(word_t NO, vaddr_t epc) {
  /* TODO: Trigger an interrupt/exception with ``NO''.
   * Then return the address of the interrupt/exception vector.
   */
//	printf("intr %d at epc=%08X mtvec=%08X\n",(int)NO,(uint32_t)epc,(uint32_t)g_csr_MTVEC);
/*
	for(int i=0;i<32;i++){
		printf("gpr[%2d]=%08X ",i,(uint32_t)cpu.gpr[i]);
		if(i%4==3)printf("\n");
	}
*/
  return g_csr_MTVEC;
}

word_t isa_query_intr() {
  return INTR_EMPTY;
}
