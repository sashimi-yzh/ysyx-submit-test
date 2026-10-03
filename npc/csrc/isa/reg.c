#include "isa/reg.h"
#include "cpu/cpu.h"
const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
void isa_reg_display(CPU_state* dut_r) {
    int i;
    for(i=0;i<16;i++){
        printf("%-4s 0x%08X\n",regs[i],dut_r->gpr[i]);
    }
    printf("pc   0x%08X\n",dut_r->pc);
}
bool isa_difftest_checkregs(CPU_state *ref_r,CPU_state * dut_r){
    int i;
    bool flag=true;
    for(i=0;i<16;i++){
        if(ref_r->gpr[i]!=dut_r->gpr[i]){
            printf("difftest error at %s gpr_ref=%x,gpr_dut=%x\n",regs[i],ref_r->gpr[i],dut_r->gpr[i]);        
            flag=false;
        }
    }
    if(ref_r->pc!=dut_r->pc){
        printf("difftest error at npc_ref=0x%08x,npc_dut=0x%08x\n",ref_r->pc,dut_r->pc);
        flag=false;
    }
    return flag;
} 
