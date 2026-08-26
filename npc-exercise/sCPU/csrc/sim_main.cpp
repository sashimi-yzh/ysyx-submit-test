#include "VsCPU.h"
#include <unistd.h>
#include <stdlib.h>
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <assert.h>
#include "verilated.h"
#include <nvboard.h>
VsCPU* top;
int timecount=0;
void nvboard_bind_all_pins(VsCPU* top);
VerilatedVcdC* tfp = new VerilatedVcdC;
VerilatedContext* contextp = new VerilatedContext;
void step_and_dump_wave(){
  timecount++;
  if(timecount>10000){
	top->clk=!top->clk;
	timecount=0;
  }
  top->eval();
  nvboard_update();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

int main(int argc, char** argv) {
    contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
    top = new VsCPU{contextp};
	top->trace(tfp,99);
	tfp->open("wave.vcd");
	nvboard_bind_all_pins(top);
	nvboard_init();
	

/*
	
*/	
	//while (1) {
	while (!contextp->gotFinish()) {
		//top->a=a;
		//top->b=b;
		step_and_dump_wave();
		printf("R0=%x R1=%x R2=%x R3=%x RA=%x RB=%x\n",top->tempR0,top->tempR1,top->tempR2,top->tempR3,top->regA,top->regB);
		//assert(top->f == (a^b));
	}
	tfp->close();
	nvboard_quit();
    delete top;
    delete contextp;
    return 0;
}
