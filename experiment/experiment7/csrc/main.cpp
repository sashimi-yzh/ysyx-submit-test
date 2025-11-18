#include "VKeyboard.h"
#include "nvboard.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME *top);

void step_and_dump_wave() {
  nvboard_update();
  top.clk = 0;
  top.eval();
  top.clk = 1;
  top.eval();
}

void sim_init() {
  nvboard_bind_all_pins(&top);
  nvboard_init();
}
static void reset(int n) {
  top.rst = 0;
  while (n-- > 0) {
    top.clk = 0;
    top.eval();
    top.clk = 1;
    top.eval();
  }
  top.rst = 1;
}

void sim_exit() { step_and_dump_wave(); }

int main() {
  sim_init();
  reset(10);
  while (1) {
    step_and_dump_wave();
  }

  sim_exit();
}