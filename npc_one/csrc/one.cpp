#include <common.h>
#include <paddr.h>

// Include common routines
#include <verilated.h>
#include <verilated_dpi.h>
#include "verilated_vcd_c.h"
// Inculde model header, generated from Verilating "top.v"
#include <Vtop.h>
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include <cpu.h>


//#define MTRACE
#define RTC_ADDR1   0xa0000048
#define RTC_ADDR2   0xa000004c
#define SERIAL_ADDR 0xa00003f8

uint64_t get_time();


VerilatedContext* contextp;
Vtop* top;
 
VerilatedVcdC* tfp;
vluint64_t main_time = 0;
void difftest_skip_ref();
void npc_trap(int state, vaddr_t pc, int halt_ret);

   
void init_verilator(int argc, char** argv, char** env) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new Vtop{contextp};
  //VCD波形设置  start
  Verilated::traceEverOn(true);
  tfp = new VerilatedVcdC;
  top->trace(tfp, 0);
  tfp->open("wave.vcd");
   
}
static void single_cycle() {
  top->clk  = !top->clk;
  
  top->eval(); 
  tfp->dump(main_time);
  top->clk  = !top->clk;
  main_time ++;
  top->eval(); 
  //tfp->dump(main_time);

}

void reset(int n) {
  top->rstn = 0;
  //top->ifu_ARREADY = 0;
  while( n-- > 0) single_cycle();
  top->rstn = 1;
  
} 

void init_module() {

  reset(10);
  return ;

}
uint32_t *cpu_gpr = NULL;
  extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
    cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
  }
uint32_t *cpu_csr = NULL;
extern "C" void set_csr_ptr(const svOpenArrayHandle r) {
  cpu_csr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
}
extern "C" void vpmem_write(int waddr, char wlen,int wdata,char wen) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  if(wen && waddr>=0x80000000 && waddr <= 0x88000000){
     #ifdef MTRACE
      printf("write at pc = %08x, data = %08x\n",waddr,wdata);
  #endif
    
      paddr_write((paddr_t)(waddr), wlen, wdata);
  
  }
  else if( wen && waddr == SERIAL_ADDR){
      #ifdef MTRACE
      printf("write at pc = %08x, data = %08x\n",waddr,wdata);
  #endif
      putchar(wdata);
      pass_diff = true;
      difftest_skip_ref();
    }
}

extern "C" void vpmem_read(int raddr,char ren, int *rdata) {
  if(ren && raddr>=0x80000000 && raddr <= 0x88000000){
    
      *rdata = paddr_read((paddr_t)(raddr),4);
    
    #ifdef MTRACE
      printf("addr = %08x , rdata = %08x\n",raddr,*rdata);
    #endif
   
  }
  else if(ren && raddr == RTC_ADDR1){
      uint64_t us = get_time();
      *rdata = (uint32_t)us;
      difftest_skip_ref();
    #ifdef MTRACE
      printf("addr = %08x , rdata = %08x\n",raddr,*rdata);
    #endif
      
  }
  else if(ren && raddr == RTC_ADDR2) {
      uint64_t us = get_time()>>32;
      *rdata = (uint32_t)us;
      pass_diff = true;
      difftest_skip_ref();
    #ifdef MTRACE
      printf("addr = %08x , rdata = %08x\n",raddr,*rdata);
    #endif
  }

}
/*
extern "C" void call(word_t pc , word_t dnpc);

extern "C" ret(word_t pc );
*/
void run_step(Decode *s, CPU_state *cpu,bool *pass_diff_out) {

       

      
      pass_diff = false;
      
       
      top->clk  = !top->clk;
      top->instr =inst_fetch(&s->snpc, 4);
      top->eval();
      
      tfp->dump(main_time);
      main_time ++;
      top->clk  = !top->clk;

      top->eval(); 

      tfp->dump(main_time);
      main_time ++;

        
       
        s->dnpc = top->dnpc;
        s->pc = top->pc;
        //printf("pc = %08x, dnpc = %08x\n",s->pc,s->dnpc);
        s->isa.inst.val = top->instr;
        for (int i=0; i<32; i++) {
          cpu->gpr[i] = cpu_gpr[i];
        }
        for (int i=0; i<4; i++) {
          cpu->csr[i] = cpu_csr[i];
        }
      *pass_diff_out = pass_diff;
      if(top->ebreak)  { 
        npc_trap(NPC_END , top->pc, cpu_gpr[10]);
        return ;
      }
      
}


void delete_module() {

  //end_sim(); 
  tfp->close();

delete tfp;
  top->final();

  // Destory model
  delete top;

 

}
