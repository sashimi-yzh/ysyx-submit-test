#include "VLFSR.h"
#include <stdlib.h>
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <assert.h>
#include "verilated.h"
#include <nvboard.h>
VLFSR* top;
void nvboard_bind_all_pins(VLFSR* top);
VerilatedVcdC* tfp = new VerilatedVcdC;
VerilatedContext* contextp = new VerilatedContext;
void step_and_dump_wave(){
  top->eval();
  nvboard_update();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}

int main(int argc, char** argv) {
    contextp->commandArgs(argc, argv);
	Verilated::traceEverOn(true);
    top = new VLFSR{contextp};
	top->trace(tfp,99);
	tfp->open("wave.vcd");
	nvboard_bind_all_pins(top);
	nvboard_init();
	

/*
	top->en=0b0;
	top->x=0b1111;step_and_dump_wave();printf("en=%d, x=%d, y=%d\n", top->en, top->x, top->y);
	for(int j=0;j<4;j++){
	//	top->x = (top->x << 1)&0xF;step_and_dump_wave();printf("en=%d, x=%d, y=%d\n", top->en, top->x, top->y);
	}
	top->x=0b1111;step_and_dump_wave();printf("en=%d, x=%d, y=%d\n", top->en, top->x, top->y);
	for(int j=0;j<4;j++){
	//	top->x = (unsigned)(top->x) >> 1;step_and_dump_wave();
	}
	top->en=0b1;
	top->x=0b1111;step_and_dump_wave();
	for(int j=0;j<4;j++){
	//	top->x = (top->x << 1)&0xF;step_and_dump_wave();
	}
	top->x=0b1111;step_and_dump_wave();
	for(int j=0;j<4;j++){
	//	top->x = (unsigned)(top->x) >> 1;step_and_dump_wave();
	}
	step_and_dump_wave();
	
*/	
	//while (1) {
	while (!contextp->gotFinish()) {
		//top->a=a;
		//top->b=b;
		step_and_dump_wave();
		tfp->dump(contextp->time());
		contextp->timeInc(10);
		//printf("a=%d b=%d f=%d\n",a,b,top->f);
		//assert(top->f == (a^b));
	}
	tfp->close();
	nvboard_quit();
    delete top;
    delete contextp;
    return 0;
}
