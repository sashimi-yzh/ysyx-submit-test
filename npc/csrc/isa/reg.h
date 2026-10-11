#ifndef __REG_H__
#define __REG_H__
#include<stdbool.h>
#include "cpu/cpu.h"
void isa_reg_display(CPU_state* dut_r);
bool isa_difftest_checkregs(CPU_state *ref_r,CPU_state*dut_r);
#endif
