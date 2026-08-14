#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
  // 顶层模块定义
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  Vtop* top = new Vtop{contextp};

  // 导出波形图
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  top->trace(tfp, 99);
  tfp->open("waveform/top_waveform.fst");
  uint64_t sim_time = 100;
  while (contextp->time() < sim_time && !contextp->gotFinish()) {
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;
    top->eval();
    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == (a ^ b));
    contextp->timeInc(1);
    tfp->dump(contextp->time());
  }
  tfp->close();
  delete top;
  delete contextp;
  return 0;
}
