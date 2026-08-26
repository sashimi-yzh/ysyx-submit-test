
#include "verilated.h"
#include "common.h"
#include "devices.h"
#include "cpu.h"
void init(int argc, char** argv);
extern void sdb_mainloop();



int main(int argc, char** argv) {
	init(argc, argv);
	sdb_mainloop();

	// while (!contextp->gotFinish()&&cpu.state==NPC_RUNNING) {
	// 	onecyc(contextp,top);
	// }
	//for(int i=0;i<16;i++) printf("[%2d]:%04x ",i,(uint32_t)top->rootp->top->GPR_0->GPR[i]);
	//int flag=top->rootp->top->GPR_0->GPR[10];
    delete top;
    delete contextp;
    return cpu.halt_ret;
}