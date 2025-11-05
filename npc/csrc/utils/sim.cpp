#include <sim.h>
#include <verilator.h>
#include <common.h>
#include <nvboard.h>
#include <string>


#ifdef USE_NVBOARD
void nvboard_bind_all_pins(VTOP_NAME* top);
#endif 


VerilatedWave *tfp = NULL;

VerilatedContext *contextp = NULL;
VTOP_NAME* top = NULL;
int wave_sample_cnt = 0;

#ifdef CONFIG_SAMPLE_WAVE_DUMP
VerilatedWave* get_wave_sample_fp(){
	int wave_num;
	delete tfp;
	tfp = new VerilatedWave;
	top->trace(tfp, 0);
	
	if(wave_sample_cnt < CONFIG_SAMPLE_NUM){
		wave_num = wave_sample_cnt;
	}else{
		wave_num = std::rand() % CONFIG_SAMPLE_NUM;
	}
	std::string wave_name = std::string("wave_") + std::to_string(wave_num) 
							+ MUXDEF(CONFIG_WAVE_VCD,".vcd",".fst");
	wave_name = std::string(getenv("NPC_HOME")) + "/build/" + wave_name;
	tfp->open(wave_name.c_str());
	wave_sample_cnt++;
	return tfp;
}
#endif 

void init_sim(int argc, char** argv){
	//Verilated::commandArgs(argc, argv);
	std::srand(std::time(0));
	top = new VTOP_NAME;
#ifdef USE_NVBOARD
	nvboard_bind_all_pins(top);
	nvboard_init();
#endif 
	top->clock = 0;
#ifdef CONFIG_WAVE_DUMP
	Verilated::traceEverOn(true);
	contextp = new VerilatedContext;
	
    
#ifndef CONFIG_SAMPLE_WAVE_DUMP
	tfp = MUXDEF(CONFIG_WAVE_VCD, new VerilatedVcdC, new VerilatedFstC);
	top->trace(tfp, 0);
	char buf[300];
	sprintf(buf, "%s/%s", getenv("NPC_HOME"), MUXDEF(CONFIG_WAVE_VCD,"wave.vcd","wave.fst"));
	tfp->open(buf);
#else
	//tfp = get_wave_sample_fp();
#endif 
#endif 
	
	
}

void stop_sim(){
    top->final();
#ifdef CONFIG_WAVE_DUMP
	tfp->close();
#endif 
 	
}