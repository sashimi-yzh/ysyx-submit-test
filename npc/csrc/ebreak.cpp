#ifndef NPC
#include "svdpi.h"
#include "VysyxSoCFull__Dpi.h"
#include <stdlib.h>
#include <stdio.h>
#include "VysyxSoCFull.h"
#include <utils.h>

uint32_t cur_pc();

uint32_t read_rf_reg(int addr) {
    const char* scope_name = "TOP.ysyxSoCFull.asic.cpu.cpu.RFS_u.Reg_u"; 
    
    svScope scope = svGetScopeFromName(scope_name);
    if (!scope) {
        printf("Error: DPI Scope '%s' not found! Check your Verilog instance name.\n", scope_name);
        return -1;
    }
    svSetScope(scope);

    int data = 0;
    read_reg(addr, &data); 
    return (uint32_t)data;
}

uint32_t read_fetch_pc() {
    const char* scope_name = "TOP.ysyxSoCFull.asic.cpu.cpu.IFU_u.PC_reg.u";
    svScope scope = svGetScopeFromName(scope_name);

    if (!scope) {
        printf("Error: DPI Scope '%s' not found! Check your Verilog instance name.\n", scope_name);
        return -1;
    }
    svSetScope(scope);

    int data = 0;
    read_pc(&data); 
    return (uint32_t)data;
}

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

uint32_t isa_reg_str2val(const char *s, bool *success) {
  if(strcmp("pc",s)==0){
    *success=true;
    return cur_pc();
  }
  for(int i = 0;i < 32;i++){
    if(strcmp(regs[i],s)==0){
      *success=true;
      return read_rf_reg(i);
    }
  }
  *success=false;
  return 0;
}
void isa_reg_display(){
    for(int i = 0;i<32;i++){
        printf("%3s  %x\n",regs[i],read_rf_reg(i));
    }
    printf("pc   %x\n",cur_pc());
}
extern uint64_t cycle;
extern u_int64_t inst_counter;
void printPMU();
void ebreak() {
    uint32_t status = read_rf_reg(10);
    printf("cycle: %llu, InstCounter: %llu, IPC: %f\n",cycle, inst_counter , 1.0 * inst_counter / cycle);
    printPMU();
    if(status == 0){
        printf("\033[32mHIT GOOD TRAP\033[0m\n");
        close_tfp();
        exit(0);
    }else{
        printf("\033[31mHIT BAD TRAP\033[0m\n");
        close_tfp();
        exit(1);
    }
}
void my_assert(bool cond);
void invalid_instruction(int pc,int inst){
    extern uint64_t cycle;
    extern uint64_t inst_counter;
    printf("invalid_instruction: 0x%x at 0x%x (cycle=%llu, committed=%llu)\n",
           (uint32_t)inst,(uint32_t)pc,(unsigned long long)cycle,(unsigned long long)inst_counter);
    close_tfp();
    my_assert(0);
}

#endif
