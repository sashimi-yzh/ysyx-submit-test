#include "utils/utils.h"
#include <cpu/cpu.h>
#include <isa.h>
#include <fmt-def.h>
#include <inst.h>
#include <watchpoint.h>
#include <cpu/difftest.h>
#include <reg.h>
#include <verilator.h>
#include <memory/paddr.h>
#include <signal.h>
#include <cstdlib>
#include <color.h>
#include <sim.h>

#define MAX_INST_TO_PRINT 10001
bool first = true;

CPU_state npc_cpu = {};
static uint64_t g_timer = 0; // unit: us
uint64_t g_nr_guest_inst = 0;
uint64_t g_nr_guest_cycle = 0;
static bool g_print_step = false;
volatile sig_atomic_t stop_signal = 0;
volatile sig_atomic_t printinfo_signal = 0;




extern MUXDEF(CONFIG_WAVE_VCD, VerilatedVcdC, VerilatedFstC)* tfp;
extern VerilatedContext* contextp;

void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
void device_update();
void perf_statistic();
void pc_trace(word_t pc);
void pc_trace_close();

void handle_sig(int sig) {
  if(sig == SIGINT)
    stop_signal = 1;
  else if(sig == SIGQUIT)
    printinfo_signal = 1;
}

void init_sig(){
  struct sigaction sa;
  memset(&sa, 0, sizeof(sa));
  sa.sa_handler = handle_sig;
  sigemptyset(&sa.sa_mask);
  if(sigaction(SIGINT, &sa, NULL) == -1){
    perror("sigaction");
  }
  if(sigaction(SIGQUIT, &sa, NULL) == -1){
    perror("sigaction");
  }
}


static void inline trace_and_difftest(){
  //printf("pc=0x%x, dnpc=0x%x\n",PC, PC + (top->cpu->pc1->pc_offset_en?top->cpu->pc1->pc_offset:0));
  //IFDEF(CONFIG_DIFFTEST, difftest_step(PC, PC + top->cpu->pc1->pc_offset));
  //IFDEF(CONFIG_DIFFTEST, difftest_step(0,0));
  IFDEF(CONFIG_DIFFTEST, difftest_step(PC, PC ));
  IFDEF(CONFIG_PC_TRACE, pc_trace(PC));
  //scan_watchpoint();
}

void inline cpu_eval_dump(){
  top->eval();
#ifdef CONFIG_WAVE_DUMP
#ifndef CONFIG_SAMPLE_WAVE_DUMP
  tfp->dump(contextp->time());
  contextp->timeInc(1);
#else
  static int cnt = 0;
  static bool start = false;
  if(!start){
    if(std::rand() % 10000 == 0){
      start = true;
      tfp = get_wave_sample_fp();
    }
  }else{
    if(cnt++ < CONFIG_SAMPLE_CYCLES*2){
      tfp->dump(contextp->time());
      contextp->timeInc(1);
    }else{
      tfp->close();
      cnt = 0;
      start = false;
    }
  }

#endif 
#endif
}

void inline cpu_single_cycle(){
	int i = 2;
	while((i--))
	{
		top->clock = !top->clock;
		cpu_eval_dump();
	}
  g_nr_guest_cycle++;
#ifdef USE_NVBOARD
  nvboard_update();
#endif 
}

void inline cpu_single_inst(){
#ifdef CONFIG_WAVE_DUMP
  size_t cycles = 0;
  do{
    if(cycles++ > 10000){
      printf("************************************\n");
      printf(L_RED "Single Inst Time out!\n" COLOR_NONE);
      printf( "************************************\n");
      npc_state.state = NPC_ABORT;
      return;
    }
    cpu_single_cycle();
  }while(!WBU_VALID);
#else
  do{
    cpu_single_cycle();
  }while(!WBU_VALID);
#endif 
}

void cpu_reset(int n){
	top->reset = RESET_ENABLE;
	while(n--){cpu_single_cycle();}
	top->reset = RESET_DISABLE;
}

void statistic() {
  printf("\n");
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0){ Log("simulation frequency = " NUMBERIC_FMT " inst/s; " NUMBERIC_FMT " cycle/s",
       g_nr_guest_inst * 1000000 / g_timer, g_nr_guest_cycle * 1000000 / g_timer );}
  else{} //Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  Log("IPC: %.4lf" , (double)g_nr_guest_inst/g_nr_guest_cycle);
  perf_statistic();
}


void assert_fail_msg() {
  isa_reg_display();
 // statistic();
}

static void exec_once(){
  
  //cpu_single_cycle();

  cpu_single_inst();

#ifdef CONFIG_DIFFTEST
  for(int i=0; i<MUXDEF(CONFIG_RVE,16,32); i++){
    npc_cpu.gpr[i] = gpr(i);
  }
  npc_cpu.pc = NPC;

  npc_cpu.csr.mepc = CSR->mepc;
  npc_cpu.csr.mcause = CSR->mcause;
  npc_cpu.csr.mstatus = CSR->mstatus;
  npc_cpu.csr.mtvec = CSR->mtvec;
#endif 

  
#ifdef CONFIG_TRACE
  char logbuf[64];
  if(g_print_step){
   //disassemble(logbuf, 64, PC , guest_to_host(PC), 4);
   disassemble(logbuf, 64, PC , ((uint8_t*)&INST), 4);
   printf("0x" FMT_WORD_HEX_WIDTH ":    ", PC);
    
    for(int j = 3; j >= 0; j--){
      //printf("%02x ", ((uint8_t*)guest_to_host(PC))[j]);
      printf("%02x ", ((uint8_t*)&INST)[j]);
    }
  
   printf("%s\n", logbuf);
  }
#endif 
}


static void execute(uint64_t n) {
  for (;n > 0; n --) {
    exec_once();
    
    g_nr_guest_inst ++;
    trace_and_difftest();

    if (stop_signal){
      npc_state.state = NPC_STOP;
      stop_signal = 0;
      break;
    }
    if(printinfo_signal){
      printinfo_signal = 0;
      statistic();
    }
    if (npc_state.state != NPC_RUNNING) break;

    IFDEF(CONFIG_DEVICE, device_update());
  }
}



void cpu_exec(uint64_t n) {


  g_print_step = (n < MAX_INST_TO_PRINT);
  switch (npc_state.state) {
    case NPC_END: case NPC_ABORT:
      printf("Program execution has ended. To restart the program, exit NPC Simulation and run again.\n");
      return;
    default: npc_state.state = NPC_RUNNING;
  }
  uint64_t timer_start = get_time();

  execute(n);

  uint64_t timer_end = get_time();
  g_timer += timer_end - timer_start; 

  switch (npc_state.state) {
    case NPC_RUNNING: npc_state.state = NPC_STOP; break;

    case NPC_END: case NPC_ABORT:
      Log("npc: %s at pc = " FMT_WORD,
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
#ifdef CONFIG_ITRACE
        if(npc_state.state == NPC_END && npc_state.halt_ret != 0) print_iringbuf();
#endif // CONFIG_ITRACE
    
      // fall through
    case NPC_QUIT: pc_trace_close(); statistic() ;
  }
}




