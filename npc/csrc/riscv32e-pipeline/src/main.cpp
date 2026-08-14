#include <common.h>
VerilatedContext* contextp;
VysyxSoCFull* top;
VerilatedFstC* tfp;

void sdb_mainloop();
extern bool sdb_set_batch_mode;
long int start_time;
struct timeval tv;
int main(int argc, char* argv[]) {
  printf("Welcome to NPC!\n");
  Verilated::commandArgs(argc, argv);
  // 顶层模块定义
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new VysyxSoCFull{contextp};
  
  // 导出波形图
#ifdef CONFIG_WAVEFORM
  Verilated::traceEverOn(true);
  tfp = new VerilatedFstC;
  top->trace(tfp, 0);
  tfp->open("waveform/ysyxSoCFull_waveform.fst");
#endif

  init_monitor(argc, argv);
  if(sdb_set_batch_mode) cpu_exec(-1);
  else sdb_mainloop();
#ifdef CONFIG_WAVEFORM
  tfp->close();
#endif
  delete top;
  delete contextp;
#ifdef CONFIG_BOARD
  nvboard_quit();
#endif
  return (npc_state == NPC_QUIT || npc_state == NPC_GOODTRAP) ? 0 : 1;
}