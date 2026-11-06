#include <common.h>
#include <cpu/cpu.h>
#include <isa/isa_def.h>
#include <isa/reg.h>
#include <cpu/difftest.h>


#define MAX_INST_TO_PRINT 10
#if CONFIG_FTRACE
#include "/home/long/ysyx-workbench/npc/csrc/monitor/elf_reader.h"
  int count = 0;
#endif

uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
#ifdef PLATFORM_NPC
void device_update();
#endif

// 全局结束标志和 DPI-C 函数
bool sim_finish = false;
char p[128];
int print_on = 0;

CPU_state dut = {
  .gpr = {0},            // 所有寄存器初始化为0
  #ifdef PLATFORM_NPC
  .pc = 0x80000000,       // PC初始化为0x30000000
  .next_pc = 0x80000000,
  #else
  .pc = 0x30000000,       // PC初始化为0x30000000
  .next_pc = 0x30000000,
  #endif
};

extern "C" void dpi_ebreak() {
    sim_finish = true;  // 触发仿真结束
}

void step_and_dump_wave(){
    top->eval();
    #if CONFIG_WAVE
    contextp->timeInc(1);   
    tfp->dump(contextp->time());
    #endif
}

static void trace_and_difftest() {

  #if CONFIG_DIFFTEST
    // printf("DIFFTEST:pc:0x%08x next_pc:0x%08x\n", dut.pc, dut.next_pc);
    difftest_step(dut.pc, dut.next_pc);
  #endif

  #if CONFIG_FTRACE
  //if (dut.pc != dut.next_pc){
  int is_call = 0;
  int is_ret = 0;

  uint32_t opcode = _instruction_data_ & 0x7F;
  uint32_t rd = _instruction_data_ >> 7 & 0x1F;
  uint32_t rs1 = (_instruction_data_) >> 15 & 0x1F;
 

  if ((opcode == 0x6F && rd == 1) ||  // JAL rd=x1
      (opcode == 0x67 && rd == 1)) {  // JALR rd=x1
    is_call = 1;
  }
  if (opcode == 0x67 && rs1 == 1 && rd == 0) {
    is_ret = 1;
  }
  
  //int ret = decode_exec(s);
  char blank [100];
  int j = 0;
  if (is_call) {
    count += 2;
    for(j = 0; j < count; j ++){
      blank[j] = ' ';
    }
    blank[count] = '\0';
    for(int i = 0; i < functab_count; i ++){
      if(functab[i].value == dut.next_pc){
        //log_write("0x%08x:%s call [%s@0x%08x]", top->de_pc, blank, functab[i].func_name, functab[i].value);
        printf("0x%08x:%s call [%s@0x%08x]\n", dut.pc, blank, functab[i].func_name, functab[i].value);
        break;
      }
    }
  }
  else if (is_ret) {
    count -= 2;
    for(j = 0; j < count; j ++){
      blank[j] = ' ';
    }
    blank[count] = '\0';
    printf("0x%08x:%s ret [0x%08x]\n", dut.pc, blank, gpr(1));
    //log_write("0x%08x:%s ret [0x%08x]\n", top->de_pc, blank, top->reg_data[1]);
  }
// }
  
  //return ret;
#endif
}

void single_cycle() {
  #ifdef PLATFORM_YSYXSOC
  nvboard_update();
  #endif
  top->clock ^= 1; top->eval();
  step_and_dump_wave();
  top->clock ^= 1; top->eval();
  step_and_dump_wave();
}

static void statistic() {
  IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
  Log("host time spent = " NUMBERIC_FMT " us", g_timer);
  Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
  if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
  else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
  #if CONFIG_WAVE
  void sim_exit();
  sim_exit();
  #endif
}

void assert_fail_msg() {
#ifdef CONFIG_IRINGBUF
  print_iringbuf(cpu.pc);
#else
  void isa_reg_display();
  isa_reg_display();
#endif
  statistic();
}

static void execute(uint64_t n) {
    if(n <= MAX_INST_TO_PRINT) print_on = 1;
    uint32_t counter = 0;
  for (;n > 0; n --) {
    uint32_t prev_pc = dut.next_pc;
    counter = 0;
    while(!sim_finish){
      single_cycle();
      if(_single_inst_done_) {
        counter = 0;
        break;
      }
      // else if (counter > 1000000) {
      //   printf("Error: The simulation seems to be stuck at pc = 0x%08x. Please check your design.\n", prev_pc);
      //   sim_finish = true;
      //   break;
      // }
      // else {
      //   counter++;
      // }
    }

      dut.pc = _pc_data_;
      dut.next_pc = _next_pc_data_;
    g_nr_guest_inst ++;
    #if CONFIG_ITRACE
  if(!sim_finish){
    // if (dut.pc != dut.next_pc){
      uint32_t ilen = 4;
      uint32_t cur_pc = _pc_data_;
      uint32_t cur_inst = _instruction_data_;
      char* s = p;
      s += snprintf(s, sizeof(p), "%08x:", cur_pc);
      int space_len = 2;
      void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
      disassemble(s, s + sizeof(p) - s,
      dut.next_pc, (uint8_t *)&cur_inst, ilen);

      char str[256];
      snprintf(str, sizeof(str), "pc:0x%08x:    %08x   %s", cur_pc, cur_inst, s);
      // printf("%s\n", str);
      log_write("%s\n", str);
      p[0] = '\0';
    // }
  }
  #else
  if(!sim_finish){
    if(print_on){
      print_on = 0;
      printf("0x%08x: %08x\n", 
         _pc_data_, _instruction_data_);
    }
  }
  #endif

  #if CONFIG_DIFFTEST
      for(int i = 0; i < 16; i++){
      dut.gpr[i] = gpr(i);
  }
  #endif
    
    #ifdef PLATFORM_NPC
    device_update();
    trace_and_difftest();
    #if CONFIG_DEVICE
    device_update();
    #endif
    #endif

    if(sim_finish) {
      npc_state.halt_pc = _pc_data_;
      npc_state.halt_ret = _a0_data_; // 寄存器返回值
      npc_state.state = NPC_END;
    }
    if (npc_state.state != NPC_RUNNING) break;
  }
}



void cpu_exec(uint64_t n){
    if(sim_finish) npc_state.state = NPC_END;
    switch (npc_state.state) {
    case NPC_END: case NPC_ABORT: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
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
      Log("npc: %s at pc = 0x%08x",
          (npc_state.state == NPC_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
           (npc_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
            ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
          npc_state.halt_pc);
      // fall through
    case NPC_QUIT: statistic();
  }
}
