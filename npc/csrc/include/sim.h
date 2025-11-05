#ifndef __SIM_H_
#define __SIM_H_

#include <verilator.h>

#define VerilatedWave MUXDEF(CONFIG_WAVE_VCD,VerilatedVcdC,VerilatedFstC)

#ifdef CONFIG_SAMPLE_WAVE_DUMP
VerilatedWave* get_wave_sample_fp();
#endif 
#endif // __SIM_H_