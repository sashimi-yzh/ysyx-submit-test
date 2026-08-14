#include <common.h>

bool itrace_flag = true;
uint8_t mem[CONFIG_MSIZE] = {};
void exec_once() {
#ifdef ITRACE_COND
  if(itrace_flag) {
    inst_display(npc_pc, npc_inst);
  }
#endif
  riscv32e_top->clk = ~riscv32e_top->clk; riscv32e_top->eval(); 
  #ifdef CONFIG_WAVEFORM
  contextp->timeInc(1); tfp->dump(contextp->time());
  #endif
  riscv32e_top->clk = ~riscv32e_top->clk; riscv32e_top->eval(); 
  #ifdef CONFIG_WAVEFORM
  contextp->timeInc(1); tfp->dump(contextp->time());
  #endif
}

void cpu_exec(uint64_t n) {
  switch (npc_state) {
    case NPC_BADTRAP: case NPC_ABORT: case NPC_GOODTRAP: case NPC_QUIT:
      printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
      return;
    default: npc_state = NPC_RUNNING;
  }
  while(n--) {
    word_t cur_pc = npc_pc;
    exec_once();
    difftest_step(npc_pc, cur_pc);
    if(npc_state != NPC_RUNNING) break;
  }

  if(npc_state == NPC_RUNNING) npc_state = NPC_STOP;
}
