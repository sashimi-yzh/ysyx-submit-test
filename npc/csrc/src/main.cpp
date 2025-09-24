#include "VysyxSoCFull.h"
#include "VysyxSoCFull___024root.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include "verilated_vcd_c.h"
#include <common.h>
#include <cstdint>
#include <nvboard.h>
#include <perf_counter.h>

VysyxSoCFull *ysyxSoCFull = NULL;
#ifdef CONFIG_FST
VerilatedFstC *tfp = NULL;
#else
VerilatedVcdC *tfp = NULL;
#endif
static vluint64_t sim_time = 0;
uint64_t cycle = 0;
uint64_t inst_num = 0;
uint64_t last_inst_num = 0;

PerfCounter pf;

void init_monitor(int, char *[]);
void sdb_mainloop();

// == nvboard ==============================================

void nvboard_bind_all_pins(VysyxSoCFull* top);

// == verilator sim =========================================

uint64_t cycle_value() {
  return cycle;
}

void print_cpu() {
  printf("Current Cycle:   %ld\n", cycle);
  printf("WriteBack Insts: %ld\n", inst_num);
  printf("Current IPC:     %lf\n", (double)(inst_num - last_inst_num) / 100000.0);
  printf("Totel IPC:       %lf\n", (double)inst_num / cycle);
  printf("Current PC:      0x%.8x\n", lsu_wbu_pc());
  printf("\n\n\n");
  last_inst_num = inst_num;
}

bool step_and_dump_once() {
  IFDEF(CONFIG_NVBOARD, nvboard_update());
  IFDEF(CONFIG_PERF, pf.updatePerfCounter());

  for (int i = 0; i < 2; i++) {
    ysyxSoCFull->clock ^= 1;
    ysyxSoCFull->eval();
    if (inst_num >= CONFIG_TRACE_INST_NUM) IFDEF(CONFIG_WAVE, tfp->dump(sim_time++));
  }

  cycle++;
  IFDEF(CONFIG_PRINT_CPU, if (cycle % 100000 == 0) print_cpu());

  if (lsu_valid()) {
    inst_num++;
  }

  return true;
}

void sim_init() {
  ysyxSoCFull = new VysyxSoCFull;
#ifdef CONFIG_WAVE
  Verilated::traceEverOn(true);
  #ifdef CONFIG_FST
  tfp = new VerilatedFstC;
  ysyxSoCFull->trace(tfp, 5);
  tfp->open("waveform.fst");
  #else
  tfp = new VerilatedVcdC;
  ysyxSoCFull->trace(tfp, 5);
  tfp->open("waveform.vcd");
  #endif
#endif // CONFIG_WAVE

  IFDEF(CONFIG_NVBOARD, nvboard_bind_all_pins(ysyxSoCFull));
  IFDEF(CONFIG_NVBOARD, nvboard_init());

  // reset
  // 给足一个上升沿才能重置成功
  ysyxSoCFull->reset = 0;
  ysyxSoCFull->eval();
  IFDEF(CONFIG_WAVE, tfp->dump(sim_time++));
  ysyxSoCFull->reset = 1;
  ysyxSoCFull->clock = 1;
  for (int i = 0; i < 26; i++) {
    ysyxSoCFull->clock ^= 1;
    ysyxSoCFull->eval();
    IFDEF(CONFIG_WAVE, tfp->dump(sim_time++));
  }
  // 给一个半周期reset后，正好处于clock为0
  // 如果这时开始执行，那么第一条指令会直接改变cpu状态
  // 如果只给一个周期，这时clock为1
  // 那么过渡时始终处于高电平，第一条指令要等下个周期才会改变cpu

  ysyxSoCFull->reset = 0;
  ysyxSoCFull->clock = 0;
}

void sim_exit() {
  // ysyxSoCFull->clock ^= 1;
  // ysyxSoCFull->eval();
  // IFDEF(CONFIG_WAVE, tfp->dump(sim_time++));
  IFDEF(CONFIG_WAVE, tfp->close());
  IFDEF(CONFIG_NVBOARD, nvboard_quit());
}

int main(int argc, char *argv[]) {

  // fix plusargs error
  Verilated::commandArgs(argc, argv);

  init_monitor(argc, argv);

  sdb_mainloop();

  IFDEF(CONFIG_PERF, pf.logToFile());

  return 0;
}
