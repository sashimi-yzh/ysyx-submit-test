#include <common.h>
#include <memory/paddr.h>
#include <cpu/cpu.h>
#ifdef PLATFORM_YSYXSOC
#include <nvboard.h>
#endif

//函数申明
extern void init_isa();
void init_monitor(int, char *[]);
void step_and_dump_wave();
void sdb_mainloop();

VerilatedContext* contextp;
#if CONFIG_WAVE
VerilatedFstC* tfp;
#endif

#ifdef PLATFORM_YSYXSOC
VysyxSoCFull* top;
void nvboard_bind_all_pins(VysyxSoCFull* top);
#else 
Vysyx_25020042* top;
#endif

void sim_init(){
    contextp = new VerilatedContext;
    #if CONFIG_WAVE
    tfp = new VerilatedFstC;
    // tfp = new VerilatedVcdC;
    #endif
    #ifdef PLATFORM_YSYXSOC
    top = new VysyxSoCFull;
    #else 
    top = new Vysyx_25020042;
    #endif
    #if CONFIG_WAVE
    contextp->traceEverOn(true);
    top->trace(tfp,0);
    tfp->open("/home/long/ysyx-workbench/npc/build/wave.fst");
    #endif
    #ifdef PLATFORM_YSYXSOC
    svSetScope(svGetScopeFromName("TOP.ysyxSoCFull.asic.cpu.cpu.IFU_u"));
        nvboard_bind_all_pins(top);
        nvboard_init();
    #else 

    svSetScope(svGetScopeFromName("TOP.ysyx_25020042.IFU_u"));
    #endif
}

void sim_exit(){
    step_and_dump_wave();
    #if CONFIG_WAVE
    tfp->close();
    #endif
}



void npc_engine_start() {
    top->clock = 0;
    top->reset = 1;
    step_and_dump_wave();
    top->clock = 1;
    step_and_dump_wave();
    int n = 18;
    while (n--) {
        top->clock ^= 1;
        step_and_dump_wave();
    }
    top->reset = 0;
    top->clock = 0;
    step_and_dump_wave();
}

static void reset(int n) {
  top->reset = 1;
  while (n -- > 0) {
    top->clock = 0; top->eval();
    top->clock = 1; top->eval();
  }
  top->reset = 0;
}

int main(int argc, char *argv[]){
    Verilated::commandArgs(argc, argv);


  
    sim_init();

    init_monitor(argc, argv);

    npc_engine_start();
    // reset(10);

//   while(1) {
//     nvboard_update();
//     top->clock = 0; top->eval();
//     top->clock = 1; top->eval();
//   }
//--------------------------------------
    

    
    sdb_mainloop();

    sim_exit();
    int is_exit_status_bad(void);
    return is_exit_status_bad();
}