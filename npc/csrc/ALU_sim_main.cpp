#include "VALU.h"
#include "verilated.h"
#include "verilated_fst_c.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
  // 顶层模块定义
  VerilatedContext* contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  VALU* ALU = new VALU{contextp};

  // 导出波形图
  Verilated::traceEverOn(true);
  VerilatedFstC* tfp = new VerilatedFstC;
  ALU->trace(tfp, 99);
  tfp->open("waveform/ALU_waveform.fst");
  int Asrc[9] = {7, 6, 2, 1, 0, -1, -2, -7, -8};
  int Bsrc[9] = {7, 6, 2, 1, 0, -1, -2, -7, -8};
  int selsrc[9] = {0, 1, 6, 7};
  for(int i=0;i<4;i++){
    for(int s=0;s<9;s++){
      for(int t=0;t<9;t++){
        ALU->A = Asrc[s];
        ALU->B = Bsrc[t];
        ALU->sel = selsrc[i];
        ALU->eval();
        contextp->timeInc(1);
        tfp->dump(contextp->time());
      }
    }
  }
  tfp->close();
  delete ALU;
  delete contextp;
  return 0;
}
