#include "Vtop.h"
#include <stdlib.h>
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <assert.h>
#include "verilated.h"
#include <nvboard.h>
Vtop* top;
void nvboard_bind_all_pins(Vtop* top);

void single_cycle(){
	top->clk=0;top->eval();
	top->clk=1;top->eval();
}


void reset(int n){
	top->rst=1;
	while(n-- >0) single_cycle();
	top->rst=0;
}


int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
    top = new Vtop{contextp};
	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp,99);
	tfp->open("wave.vcd");
	nvboard_bind_all_pins(top);
	nvboard_init();
	//int a,b;
	reset(10);
	while (!contextp->gotFinish()) {
		//top->a=a;
		//top->b=b;
		single_cycle();
		nvboard_update();
		tfp->dump(contextp->time());
		contextp->timeInc(10);
		//printf("a=%d b=%d f=%d\n",a,b,top->f);
		//assert(top->f == (a^b));
	}
	tfp->close();
    delete top;
    delete contextp;
	nvboard_quit();
    return 0;
}
