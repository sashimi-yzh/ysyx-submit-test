#include <circuit.h>
static VerilatedVcdC* m_trace = nullptr;
static VerilatedContext* contextp = nullptr;

void init_wave(){
    
	contextp = new VerilatedContext;
	m_trace = new VerilatedVcdC;
	cpu = new CPU;
	contextp->traceEverOn(true);
	cpu->trace(m_trace, 5);
	#ifdef CONFIG_DUMP_WAVE
		m_trace->open("build/waveform.vcd");
	#endif
} 

void dump_wave_inc(){
    m_trace->dump(contextp -> time());
	contextp -> timeInc(1);
} 

void close_wave(){
    m_trace -> close();
}