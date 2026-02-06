//#define WAVE_ON  //
#include <common.h>
#include <paddr.h>

// Include common routines
#include <verilated.h>
#include <verilated_dpi.h>
#ifdef WAVE_ON
#include "verilated_fst_c.h"
#endif
// Inculde model header, generated from Verilating "top.v"
#include <nvboard.h>
#include "svdpi.h"
#ifdef YSYXSOC
#include <VysyxSoCFull.h>
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull___024root.h"
#define difftest top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__difftest_valid
#define cpu_dnpc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__TO_top_dnpc
#define cpu_pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__TO_top_pc
#define skip top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ref_skip
#define cpu_rf top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__rf1__DOT__rf
#define cpu_csr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__csr1__DOT__csr
#define cpu_ebreak top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ebreak
#else
#include <Vysyx_24070003_npc.h>
#include "Vysyx_24070003_npc__Dpi.h"
#include "Vysyx_24070003_npc___024root.h"
#define difftest top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__difftest_valid
#define cpu_dnpc top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__TO_top_dnpc
#define cpu_pc top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__TO_top_pc
#define skip top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__ref_skip
#define cpu_rf top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__rf1__DOT__rf
#define cpu_csr top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__csr1__DOT__csr
#define cpu_ebreak top->rootp->ysyx_24070003_npc__DOT__cpu__DOT__ebreak
#endif
//#include <cpu.h>


//#define MTRACE
#define RTC_ADDR1   0xa0000048
#define RTC_ADDR2   0xa000004c
#define SERIAL_ADDR 0xa00003f8

uint64_t get_time();

VerilatedContext* contextp;

#ifdef YSYXSOC
VysyxSoCFull* top;
#else
Vysyx_24070003_npc* top;
#endif
 
#ifdef WAVE_ON
VerilatedFstC* tfp;  // 仅在WAVE_ON时声明
#endif
vluint64_t main_time = 0;
void difftest_skip_ref();
void npc_trap(int state, vaddr_t pc, int halt_ret);

void nvboard_bind_all_pins(TOP_NAME* top);
   
void init_verilator(int argc, char** argv, char** env) {
  
  
  Verilated::commandArgs(argc, argv);
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  #ifdef YSYXSOC
  top = new VysyxSoCFull{contextp};
  #else
  top = new Vysyx_24070003_npc{contextp};
  #endif
  #ifdef YSYXSOC
  nvboard_bind_all_pins(top);
  nvboard_init();
  #endif
  //VCD波形设置  start
  #ifdef WAVE_ON
    Verilated::traceEverOn(true);
    tfp = new VerilatedFstC;
    top->trace(tfp, 99);
    tfp->open("wave.fst");
  #endif
   
}
static void single_cycle() {
  top->clock  = !top->clock;
  
  top->eval(); 
  #ifdef WAVE_ON
    tfp->dump(main_time);
  #endif
  top->clock  = !top->clock;
  main_time ++;
  top->eval(); 
  //tfp->dump(main_time);

}

void reset(int n) {
  top->reset = 1;
  //top->ifu_ARREADY = 0;
  while( n-- > 0) single_cycle();
  top->reset = 0;
  
} 

void init_module() {

  reset(10);
  return ;

}
// uint32_t *cpu_gpr = NULL;
//   extern "C" void set_gpr_ptr(const svOpenArrayHandle r) {
//     cpu_gpr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
//   }
// uint32_t *cpu_csr = NULL;
// extern "C" void set_csr_ptr(const svOpenArrayHandle r) {
//   cpu_csr = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
// }

uint32_t *monitor_data = NULL;
extern "C" void set_monitor_ptr(const svOpenArrayHandle r) {
  monitor_data = (uint32_t *)(((VerilatedDpiOpenVar*)r)->datap());
}

extern "C" void vpmem_write(int waddr, char wmask,int wdata,char wen) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  if(wen && waddr>=0x80000000 && waddr <= 0x88000000){
     #ifdef MTRACE
      printf("write at pc = %08x, data = %08x\n",waddr,wdata);
  #endif
    //paddr_write((paddr_t)(waddr), len, data);
    uint32_t line_addr = waddr & ~0x3u;

    uint32_t old_val = paddr_read(line_addr, 4);
    uint32_t new_val = old_val;

    for (int i = 0; i < 4; ++i) {
        if (wmask & (1 << i)) {                   
            uint8_t byte = (wdata >> (i * 8)) & 0xFF;    
            new_val = (new_val & ~(0xFFu << (i * 8)))     
                    | (byte << (i * 8));                 
        }
    }

    paddr_write(line_addr, 4, new_val);           
  }
  else if( wen && waddr == SERIAL_ADDR){
      #ifdef MTRACE
      printf("write at pc = %08x, data = %08x\n",waddr,wdata);
  #endif
      putchar(wdata);
      difftest_skip_ref();
    }
    else if(wen && waddr == RTC_ADDR2) {
      printf("RTC_ADDR2 write %08x\n",wdata);  }
}

extern "C" void vpmem_read(int raddr,char ren, int *rdata) {
  if(ren && raddr>=0x80000000 && raddr <= 0x88000000){
    #ifdef MTRACE
      printf("addr = %08x\n",raddr);
    #endif
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
      difftest_skip_ref();
    #ifdef MTRACE
      printf("addr = %08x , rdata = %08x\n",raddr,*rdata);
    #endif
  }

}

static uint8_t rom_data[1024];  // 假设 ROM 最大 1KB
static size_t rom_size = 0;
extern "C" void flash_read(int32_t addr, int32_t *data) { 
  *data = flash_read((paddr_t)(addr),4);
  /*
  FILE *fp = fopen("/home/jx/ysyx-workbench/npc/char-test.bin", "rb");
  if (!fp) {
    printf("error\n");
}
    rom_size = fread(rom_data, 1, sizeof(rom_data), fp);
    fclose(fp);
   
    *data = *(int32_t *)(rom_data + addr);  */
    
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 

  *data = mrom_read((paddr_t)(addr),4);
  /*
  FILE *fp = fopen("/home/jx/ysyx-workbench/npc/char-test.bin", "rb");
  if (!fp) {
    printf("error\n");
}
    rom_size = fread(rom_data, 1, sizeof(rom_data), fp);
    fclose(fp);
   
    *data = *(int32_t *)(rom_data + addr - 0x20000000);  
    */
}

extern "C" void psram_read(int32_t addr, int32_t *data) { 
  *data = psram_read((paddr_t)(addr),4);
  //printf("psram_read addr = %x, data = %x\n", addr, *data);
}

extern "C" void psram_write(int addr,int data,int wstrb) {
  int shift_len = (8 - wstrb);
  uint32_t wdata = data >> (shift_len * 4);
  _psram_write(addr, data,wstrb/2);
  //printf("psram_write addr = %x, data = %x\n", addr, data);
}
/*
extern "C" void call(word_t pc , word_t dnpc);

extern "C" ret(word_t pc );
*/
void run_step(Decode *s, CPU_state *cpu,bool *difftest_flag) {

       

      
      
      
       
      top->clock  = !top->clock;
      //top->instr1 =inst_fetch(&s->snpc, 4);
      top->eval();
      #ifdef WAVE_ON
        tfp->dump(main_time);
        main_time ++;
      #endif
      top->clock  = !top->clock;

      #ifdef YSYXSOC
      nvboard_update();
      #endif
      
      top->eval(); 

      #ifdef WAVE_ON
        tfp->dump(main_time);
        main_time ++;
      #endif

       *difftest_flag = difftest;
        s->dnpc = cpu_dnpc;
        s->pc = cpu_pc;
        s->snpc = cpu_pc + 4;
        
        //s->isa.inst.val = top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__instr;
        //printf("pc = %08x, dnpc = %08x, snpc = %08x, isa = %08x\n",s->pc,s->dnpc,s->snpc,s->isa.inst.val);
        if(difftest){
          if(skip){ difftest_skip_ref();}
          for (int i=1; i<16; i++) {
            cpu->gpr[i] =  cpu_rf[i - 1];
          }
          for (int i=0; i<4; i++) {
            cpu->csr[i] = cpu_csr[i];
          }
        }
      
      if(cpu_ebreak)  { 
        npc_trap(NPC_END , cpu_pc, cpu_rf[10 - 1]);
        return ;
      }
      
}


void delete_module() {
  nvboard_quit();
  //end_sim(); 
  #ifdef WAVE_ON
    tfp->close();
    delete tfp;
  #endif
  top->final();

  // Destory model
  delete top;

 

}
