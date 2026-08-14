#include <nvboard.h>
#include <Vbarrel_shifter.h>

static TOP_NAME dut;
void nvboard_bind_all_pins(TOP_NAME* dut);

int main(){
  nvboard_bind_all_pins(&dut);
  nvboard_init();
  while(1) {
    dut.eval();
    nvboard_update();
  }
  nvboard_quit();
  return 0;
}