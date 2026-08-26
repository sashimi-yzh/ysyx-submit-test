#include "Vtop.h"
#include <stdlib.h>
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <assert.h>
#include "verilated.h"
int main(int argc, char** argv) {
    VerilatedContext* contextp = new VerilatedContext;
    contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
    Vtop* top = new Vtop{contextp};
	VerilatedVcdC* tfp = new VerilatedVcdC;
	top->trace(tfp,99);
	tfp->open("wave.vcd");
	while (!contextp->gotFinish()) {
		int a=rand()&1;
		int b=rand()&1;
		top->a=a;
		top->b=b;
		top->eval();
		tfp->dump(contextp->time());
		contextp->timeInc(1);
		printf("a=%d b=%d f=%d\n",a,b,top->f);
		assert(top->f == (a^b));
	}
	tfp->close();
    delete top;
    delete contextp;
    return 0;
}

