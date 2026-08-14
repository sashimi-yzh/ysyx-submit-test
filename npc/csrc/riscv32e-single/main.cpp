#include <common.h>
VerilatedContext* contextp;
Vriscv32e_top* riscv32e_top;
VerilatedFstC* tfp;

void sdb_mainloop();
extern bool sdb_set_batch_mode;
long int start_time;
struct timeval tv;
int main(int argc, char* argv[]) {
  // 顶层模块定义
  printf("welcome to NPC!\n");
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  riscv32e_top = new Vriscv32e_top{contextp};
  // 导出波形图
  #ifdef CONFIG_WAVEFORM
  Verilated::traceEverOn(true);
  tfp = new VerilatedFstC;
  riscv32e_top->trace(tfp, 99);
  tfp->open("waveform/riscv32e_top_waveform.fst");
  #endif
  init_monitor(argc, argv);
  if(sdb_set_batch_mode) cpu_exec(-1);
  else sdb_mainloop();
  #ifdef CONFIG_WAVEFORM
  tfp->close();
  #endif
  delete riscv32e_top;
  delete contextp;
  return (npc_state == NPC_QUIT || npc_state == NPC_GOODTRAP) ? 0 : 1;
}