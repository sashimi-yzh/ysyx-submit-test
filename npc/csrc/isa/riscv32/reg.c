#include "reg.h"
#include <stdio.h>
#include <assert.h>
#include "fmt-def.h"
#include <verilated.h>


extern bool verbose;
word_t reg0;

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};



void isa_reg_display(){
        printf("reg info:\n");
        int reg_num = MUXDEF(CONFIG_RVE, 16, 32);
        for (int i = 0; i < reg_num; i++)
        {
                printf("$%s = 0x" FMT_WORD_HEX_WIDTH "\t", regs[i], gpr(i));
                if ((i + 1) % 4 == 0)
                        putchar('\n');
        }
        printf("$pc = 0x" FMT_WORD_HEX_WIDTH "\n", NPC);
}

void print_regs_info(){
        if(verbose){
                isa_reg_display();
        }
}



word_t isa_reg_str2val(const char *s, bool *success) {
  if(!strcmp(s, "$pc"))
  {
    *success = true;
    return  PC;
  }

  if(!strcmp(s, "$0"))  //这里匹配$0,后面的for循环代码还可以匹配$$0
  {
    *success = true;
    return gpr(0);    
  }

  int len = MUXDEF(CONFIG_RVE, 16, 32);
  for(int i=0; i<len; i++){
    if(strcmp(s+1, regs[i])==0){   //这里地址+1, 例如： $s0 去匹配 s0，要去掉前面的$
      *success = true;
      return gpr(i);
    }
  }
  *success = false;
  return 0;
}

void isa_csr_display(){
  printf("csr info:\n");
  printf("mepc = 0x" FMT_WORD_HEX_WIDTH "\n", CSR->mepc);
  printf("mcause = 0x" FMT_WORD_HEX_WIDTH "\n", CSR->mcause);
  printf("mstatus = 0x" FMT_WORD_HEX_WIDTH "\n", CSR->mstatus);
  printf("mtvec = 0x" FMT_WORD_HEX_WIDTH "\n", CSR->mtvec);
}