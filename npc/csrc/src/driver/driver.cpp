#include "debug.h"
#include "driver.h"

#include "verilated_vcd_c.h"

#ifdef NVBOARD
#include "nvboard.h"
#endif

Vtop *top_module;

static VerilatedContext *contextp;
static VerilatedVcdC *trace_file;

void init_top(int argc, char **argv) {
  contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  top_module = new Vtop(contextp, "top");
}

void init_wave(const char *filename) {
  if (!filename) return;
  Verilated::traceEverOn(true);
  trace_file = new VerilatedVcdC;
  top_module->trace(trace_file, 99);
  // trace_file->dumpvars(99, "top.ysyxSoCFull.asic.cpu.cpu.NPC_CPU");
  trace_file->open(filename);

  Log("Wave is dumped to %s", filename);
}


void init_nvboard() {
#ifdef NVBOARD
  void nvboard_bind_all_pins(Vtop*);
  nvboard_bind_all_pins(top_module);

  nvboard_init();
  Log("NVBoard initialized");
#endif
}

void finalize_driver() {
  if (trace_file) trace_file->close();
  delete top_module;
  delete contextp;
}

bool wave_rec = true;

static void driver_step() {
  top_module->eval();
  contextp->timeInc(1);
  if (trace_file && wave_rec) trace_file->dump(contextp->time());
}

void driver_cycle() {
  top_module->clock = 0; driver_step();
  top_module->clock = 1; driver_step();
  IFDEF(NVBOARD, nvboard_update());
#ifdef SOC_UART_INPUT
  void soc_uart_input_update();
  soc_uart_input_update();
#endif
}

void reset_top() {
  // reset for 20 clock cycle
  top_module->reset = 1;
  int n = 20;
  while (n--) {
    top_module->clock = 0; driver_step();
    top_module->clock = 1; driver_step();
  }
  top_module->reset = 0;
}
