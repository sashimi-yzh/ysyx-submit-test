#include "../include/common.h"
#include "../include/debug.h"
#include "Vrv32e.h"
#include "Vrv32e___024root.h" 

/********extern functions or variables********/
extern Vrv32e *top;
/*********************************************/


#define gpr top->rootp->rv32e__DOT__wbu__DOT__regs
#define cpu_pc top->rootp->rv32e__DOT__IF_ID_pc

static const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

void regs_display() 
{
    _Log(ANSI_FG_RED "RegName  Hex_Value       Dec_Value\n" ANSI_NONE);
    for(int i = 0; i < 32; i++)
    {
        _Log(ANSI_FG_YELLOW "$%s\t " ANSI_NONE, regs[i]);
        _Log("0x%08x\t %010u\n", gpr[i], gpr[i]);
    }
    puts("");
    _Log(ANSI_FG_YELLOW "$%s\t" ANSI_NONE " 0x%08x\t %010u\n", "pc", 
        cpu_pc, cpu_pc);
}

word_t single_reg_display(char *reg_name) 
{
    static int i;
    //pc
    printf("[npc]:\n");
    _Log(ANSI_FG_RED "RegName  Hex_Value       U-Dec_Value       Dec_Value\n\33[0m");
    if(strcmp(reg_name, "pc") == 0)
    {
        _Log(ANSI_FG_YELLOW "$%s\t" ANSI_NONE " 0x%08x\t %010u %010d\n", "pc", 
             cpu_pc, cpu_pc, cpu_pc);
        return cpu_pc;
    }

    //others
    for(i = 0; i < 32; i++)
        if(strcmp(reg_name, regs[i]) == 0)
        {
            _Log(ANSI_FG_YELLOW "$%s\t" ANSI_NONE " 0x%08x\t %010u\t   %010d\n", 
                 regs[i], gpr[i], gpr[i], gpr[i]);
            return gpr[i];
        }

    printf("No register %s.", reg_name);
    return -1; // 表示无效寄存器
}

word_t isa_reg_str2val(const char *s) {
  if(strcmp(s,"pc")==0) return cpu_pc;
  for(int i=0;i<sizeof(regs)/sizeof(regs[0]);i++){
    if(strcmp(s,regs[i])==0){
      return gpr[i];
    }
  }
  return 0;
}

word_t reg_str2val(const char *s, bool *success) 
{
    int i;
    //pc
    if(strcmp(s, "pc") == 0)
        return cpu_pc; 
        
    //reg $0
    if(strcmp(s, regs[0]) == 0)
        return gpr[0];
        
    //others
    for(i = 1; i < 32; i++)
        if(strcmp(s, regs[i]) == 0)
        return gpr[i];

    //no reg name matched
    *success = false;
    return 0;
}