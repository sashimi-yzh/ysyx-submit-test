#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VController.h"

using std::cout;
using std::cin;
using std::endl;

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static VController* top;

void step_and_dump_wave(){
	top -> clk = !top -> clk;//newly added
	top -> eval();
	contextp -> timeInc(1);
	tfp -> dump(contextp -> time());
}

void sim_init(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new VController;
	contextp -> traceEverOn(true);
	top -> trace(tfp, 0);
	tfp -> open("./wavesim_file/wave.vcd");
	top -> clk = 0;//newly added
}


void sim_exit(){
	step_and_dump_wave();
	tfp -> close();
}

int main(){
	
	srand((int)time(0));

	sim_init();
    cout << "simulation started" << endl;
   
	
	for(int i = 0; i < 200; ++i){
		if(i <= 10)
			top -> rst = 0;
		else if(i <= 20)
			top -> rst = 1;
		else
			top -> rst = 0;
		step_and_dump_wave();
	}
	
	sim_exit();
    cout << "simulation completed" << endl;
	return 0;
}
