
#include "verilated.h"
#include "common.h"
#include "devices.h"
#include "cpu.h"
void init(int argc, char** argv);
extern void sdb_mainloop();



int main(int argc, char** argv) {
	init(argc, argv);
	Log("Init FINISH");
	// Verilated::commandArgs(argc, argv);
	sdb_mainloop();
	
	// while (!contextp->gotFinish()&&cpu.state==NPC_RUNNING) {
	// 	onecyc(contextp,top);
	// }
	//for(int i=0;i<16;i++) printf("[%2d]:%04x ",i,(uint32_t)top->rootp->top->REG_0->GPR[i]);
	//int flag=top->rootp->top->REG_0->GPR[10];
	#ifdef CONFIG_NVBOARD_ENABLE
		nvboard_quit();
	#endif
    delete top;
    delete contextp;
	#ifdef CONFIG_WAVE_ENABLE
		tfp->close();
		delete tfp;
	#endif
	
	int status = !(cpu.state==NPC_QUIT || (cpu.state==NPC_END && cpu.halt_ret==0));
    return status;
}