#include <circuit.h>

static VerilatedFstC *tfp = nullptr;
static VerilatedContext* contextp = nullptr;

vluint64_t main_time = 0;

void init_wave(const char* wave_path) {
    Verilated::traceEverOn(true);
    contextp = new VerilatedContext;
    tfp = new VerilatedFstC();
    top->trace(tfp, 5);
    tfp->open(wave_path);
}

void dump_wave(){
    tfp->dump(main_time);
	main_time++;
}

void close_wave(int i){
    tfp -> close();
}