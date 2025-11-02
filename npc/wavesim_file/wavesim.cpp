#include <assert.h>
#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "VysyxSoCFull.h"
#include <engine/engine.h>
#include <sdb/sdb.h>
#include <mrom/mrom.h>
#include <flash/flash.h>
#include <register/register.h>
#include <nvboard.h>

using namespace std;


#define MAX_SIM_TIME 50
uint64_t sim_time = 0;
bool is_simulating = false;
bool wp_triggered = false;
bool difftest_to_skip = false;
bool difftest_skipping = false;


const char* ref_so_file = "../../nemu/build/riscv32-nemu-interpreter-so";

VysyxSoCFull* top = new VysyxSoCFull;
VerilatedVcdC* m_trace = new VerilatedVcdC;


void nvboard_bind_all_pins(VysyxSoCFull* top);


int main(int argc, char *argv[]){
	Verilated::commandArgs(argc, argv);	
#ifdef CONFIG_MROM
	long size = init_mrom(argv[1]);
#endif
#ifdef CONFIG_FLASH
	long size = init_flash(argv[1]);
#endif
	//printf("Checking Devices:\n");
	//init_devices();

	printf("Checking Options:\n");

#ifdef CONFIG_STAT
    printf("\033[36mStatistics is \033[32mON\033[0m\n");
#else
    printf("\033[36mStatistics is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_WAVEREC
	printf("\033[36mWave Record is \033[32mON\033[0m\n");
    // to enable wave tracing
    Verilated::traceEverOn(true);
    //VerilatedVcdC* m_trace = new VerilatedVcdC;
    top -> trace(m_trace, 5);
    m_trace -> open("./wavesim_file/wave.vcd");
#else
	printf("\033[36mWave Record is \033[31mOFF\033[0m\n");
#endif


#ifdef CONFIG_NVBOARD
    printf("\033[36mNvboard is \033[32mON\033[0m\n");
#else
    printf("\033[36mNvboard is \033[31mOFF\033[0m\n");
#endif


#ifdef CONFIG_SDB
#ifdef CONFIG_PRINT_INST
	printf("\033[36mSDB is \033[32mON\033[36m (Print instructions \033[32mEnabled\033[36m)\033[0m\n");
#else
	printf("\033[36mSDB is \033[32mON\033[36m (Print instructions \033[31mDisabled\033[36m)\033[0m\n");
#endif
#else
	printf("\033[36mSDB is \033[31mOFF\033[0m\n");
#endif


#ifdef CONFIG_WP
	printf("\033[36mWatchpoint is \033[32mON\033[0m\n");
#else
	printf("\033[36mWatchpoint is \033[31mOFF\033[0m\n");
#endif

//检查四大trace
#ifdef CONFIG_ITRACE
	printf("\033[36mItrace is \033[32mON\033[0m\n");
#else
	printf("\033[36mItrace is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_MTRACE
	printf("\033[36mMtrace is \033[32mON\033[0m\n");
#else
	printf("\033[36mMtrace is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_DTRACE
    printf("\033[36mDtrace is \033[32mON\033[0m\n");
#else
    printf("\033[36mDtrace is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_FTRACE
	printf("\033[36mFtrace is \033[32mON\033[36m, elf file found in %s\033[0m\n", argv[2]);
#else
	printf("\033[36mFtrace is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_ETRACE
	printf("\033[36mEtrace is \033[32mON\033[0m\n");
#else
	printf("\033[36mEtrace is \033[31mOFF\033[0m\n");
#endif


#ifdef CONFIG_DIFFTEST
	printf("\033[36mDifftest is \033[32mON\033[0m\n");
	printf("\033[36mPath of reference file:\n%s\033[0m\n",ref_so_file);
#else
	printf("\033[36mDifftest is \033[31mOFF\033[0m\n");
#endif

#ifdef CONFIG_NVBOARD
	nvboard_bind_all_pins(top);
	nvboard_init();
#endif

#ifdef CONFIG_FTRACE
	init_ftrace(argv[2]);
#endif

	init_engine(top, m_trace, &sim_time);//完成reset信号的置位/复位

//始终不支持difftest
#ifdef CONFIG_DIFFTEST
	init_difftest(ref_so_file, size, 0);//如果开启difftest这条指令必须在init_engine后执行
#endif
	
	is_simulating = true;
	
#ifdef CONFIG_SDB
	init_sdb();
	//循环主体
	sdb_mainloop(&sim_time);
#else
	if(is_simulating)
		exec_engine(top, m_trace, &sim_time, -1);
	else
		printf("Simulation has ended; Press 'q' to exit and check the wave.\n");
#endif

	m_trace -> close();
    
	if(top)
		delete top;
	if(m_trace)
		delete m_trace;	


    return 0;
}

