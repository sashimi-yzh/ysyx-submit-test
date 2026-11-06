#include <isa/reg.h>

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5"
};

void isa_reg_display() {
	#ifdef PLATFORM_YSYXSOC
	svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.gpr_u"));
	#else 
	svSetScope(svGetScopeFromName("TOP.ysyx_25020042.gpr_u"));
	#endif
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
	printf("\033[32mmstatus\033[0m:\033[33m%08x\033[0m ", _mstatus_data_);
	printf("\033[32mmcause\033[0m:\033[33m%08x\033[0m ", _mcause_data_);
	printf("\033[32mmepc\033[0m:\033[33m%08x\033[0m ", _mepc_data_);
	printf("\033[32mmtvec\033[0m:\033[33m%08x\033[0m ", _mtvec_data_);
	printf("\n");
}

word_t isa_reg_str2val(const char *s) {
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
return 0;
}