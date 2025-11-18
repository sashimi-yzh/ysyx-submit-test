#include "VMux.h"
#include "nvboard.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

static TOP_NAME top;

void nvboard_bind_all_pins(TOP_NAME *top);

void step_and_dump_wave() {
  static int i = 0;
  i++;
  if (i % 50000000 == 0) {
    top.Y += 1;
    top.Y = top.Y % 4;
  }
  nvboard_update();
  top.eval();
}

void sim_init() {
  nvboard_bind_all_pins(&top);
  nvboard_init();
}

void sim_exit() { step_and_dump_wave(); }

int main() {
  sim_init();

  top.X0 = 0b00;
  top.X1 = 0b01;
  top.X2 = 0b10;
  top.X3 = 0b11;

  while (1) {
    step_and_dump_wave();
  }

  sim_exit();
}