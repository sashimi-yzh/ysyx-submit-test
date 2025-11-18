#include "VRandomGenerator.h"
#include "nvboard.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME *top);

void step_and_dump_wave() {
  nvboard_update();
  static int i = 0;
  if (i++ % 300000000 == 0) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
  }
}

void sim_init() {
  nvboard_bind_all_pins(&top);
  nvboard_init();
}

void sim_exit() { step_and_dump_wave(); }

int main() {
  sim_init();
  top.din = 1;
  while (1) {
    step_and_dump_wave();
  }

  sim_exit();
}