#include "register.h"


int32_t registers[32] = {0};
int32_t csregisters[6] = {0, 0, 0, 0, 0x79737978, 0x015fdf05};
extern int32_t top_pc;//defined in engine/engine.cpp

const char *regname[32] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

const char *csregname[6] = {
  "mstatus", "mtvec", "mepc",
  "mcause", "mvendorid", "marchid" 
};

extern "C" void get_current_reg(int32_t id, int32_t regvalue){
	if(id >= 0 && id <= 15){
		registers[id] = regvalue;
	}
	else{
		switch(id){
				//modify by Jason @ 2025.10.12, break added
				case 0x300: csregisters[0] = regvalue; break;
				case 0x305: csregisters[1] = regvalue; break;
				case 0x341: csregisters[2] = regvalue; break;
				case 0x342: csregisters[3] = regvalue; break;
				case 0xf11: csregisters[4] = regvalue; break;
				case 0xf12: csregisters[5] = regvalue; break;
				default: ;
		}
	}
}


//unused
void update_reg(VysyxSoCFull* top){
	printf("Warning: Function update_reg is deprecated; Any use may lead to unexpected behavior.");
	for(int i = 0; i < NO_REG; i++)
		//registers[i] = top -> regs[i];
		registers[i] = 0;
	//regpc = top -> pc;
	//regpc = 0;
}



void display_reg() {
    for(int i = 0; i < NO_REG; ++i){
        printf("%10s : 0x%8.8x\n", regname[i], registers[i]);
    }
	for(int j = 0; j < 6; ++j){
		printf("%10s : 0x%8.8x\n", csregname[j], csregisters[j]);
	}
    printf("%10s : 0x%8.8x\n", "pc", top_pc);//注意为extern top_pc
}



int32_t str2val_reg(const char *s, bool *success) {
  for (int i = 0; i < NO_REG; ++i){
    if (strcmp(regname[i], s) == 0){
        *success = true;
        return registers[i];
    }
  }

  for (int j = 0; j < 6; ++j){
    if (strcmp(csregname[j], s) == 0){
        *success = true;
        return csregisters[j];
    }
  }


  if (strcmp("pc",s) == 0){
    *success = true;
    return top_pc;
  }

  *success = false;
  return 0;
}




