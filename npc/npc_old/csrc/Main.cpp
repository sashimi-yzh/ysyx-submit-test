
#include "Device/Device.h"
#include "RingBuffer.hpp"
#include "Simulate.h"
#include "spdlog/spdlog.h"
#include <Args.h>
#include <Mem.h>
#include <Monitor.h>
#include <Ref.h>
#include <SDL2/SDL_audio.h>
#include <Vnpc_top.h>
#include <Vnpc_top___024root.h>
#include <exception>
#include <fmt/format.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
using std::string;

int main(int argc, char *argv[]) {
  config = process_args(argc, argv);
  int return_value = -1;
  try {
    return_value = simulate();
  } catch (const std::exception &e) {
    std::cerr << "Error : " << e.what() << std::endl;
    if (device_thread) {
      device_thread->request_stop();
    }
  }
  if (dut)
    dut->print_all_gpr();

  ref = nullptr;
  dut = nullptr;
  contextp = nullptr;
  if (config.itracer > 0)
    instRingBuffer->display();
  spdlog::shutdown();
  return return_value;
}