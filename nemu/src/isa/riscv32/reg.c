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
#include "local-include/reg.h"

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void isa_reg_display() {
	int i;
	int count = 0;
	int len = sizeof(regs) / sizeof(regs[0]);
	for(i = 0 ; i < len ; i++){
		char name [5], value [10];
		sprintf(name, "%s",reg_name(i)); 
		sprintf(value, "%08x",gpr(i));
		printf("\033[32m%s\033[0m: \033[33m%s\033[0m\t", name, value); 
		
		count ++;
		if (count == 4) {
			printf("\n");
			count = 0;
		}
	}
	printf("\n");
}

word_t isa_reg_str2val(const char *s, bool *success) {
	if (s == NULL) {	
		printf("invalid register");
  return 0;
	}
	else {
		int index = -1;
		int len = sizeof(regs) / sizeof(regs[0]);
		for (int i = 0; i < len; i++){
			if (strcmp(s,regs[i]) == 0){
				index = check_reg_idx(i);
				break;
			}
			if (strcmp(s, "0") == 0){
				index = check_reg_idx(0);// 检查索引是否合法，合法就返回索引
				break;
			}
		}
		if (index == -1) return 0;
		else {
			return gpr(index);// 返回寄存器中的值
		}
	}
}
