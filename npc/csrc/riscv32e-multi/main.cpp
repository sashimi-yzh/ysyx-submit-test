#include <common.h>
VerilatedContext* contextp;
VysyxSoCFull* top;
VerilatedFstC* tfp;

void sdb_mainloop();
extern bool sdb_set_batch_mode;
long int start_time;
struct timeval tv;
int main(int argc, char* argv[]) {Verilated::commandArgs(argc, argv);
  // 顶层模块定义
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top = new VysyxSoCFull{contextp};
  
  // 导出波形图
  Verilated::traceEverOn(true);
  tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("waveform/ysyxSoCFull_waveform.fst");
  init_monitor(argc, argv);
  if(sdb_set_batch_mode) cpu_exec(-1);
  else sdb_mainloop();
  tfp->close();
  delete top;
  delete contextp;
  return (npc_state == NPC_QUIT || npc_state == NPC_GOODTRAP) ? 0 : 1;
}