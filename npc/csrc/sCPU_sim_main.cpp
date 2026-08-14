#include "VsCPU.h"
#include "verilated.h"
#include "verilated_fst_c.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // 顶层模块定义
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  VsCPU* sCPU = new VsCPU{contextp};

  // 导出波形图
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  sCPU->trace(tfp, 99);
  tfp->open("waveform/sCPU_waveform.fst");
  uint64_t sim_time = 100000;
  sCPU->clk = 0;
  sCPU->rst = 1;
  for (int i = 0; i < 10; i++) {
    sCPU->clk = ~sCPU->clk;
    sCPU->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
  }
  sCPU->rst = 0;

  while (contextp->time() < sim_time && !contextp->gotFinish()) {
    sCPU->clk = ~sCPU->clk;
    sCPU->eval();
    contextp->timeInc(1);
    tfp->dump(contextp->time());
  }
  tfp->close();
  delete sCPU;
  delete contextp;
  return 0;
}
