
#include "DUT.h"
#include "Flash.h"
#include "Setup.h"
#include "spdlog/spdlog.h"
#include <Args.h>
#include <Cache.h>
#include <MROM.h>
#include <PerformanceCounter.h>
#include <Ref.h>
#include <VysyxSoCFull.h>
#include <VysyxSoCFull___024root.h>
#include <chrono>
#include <cstdint>
#include <exception>
#include <iostream>
#include <memory>
#include <nvboard.h>
#include <fmt/format.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

using std::string;

std::unique_ptr<Dut> dut;
static bool retire;

extern "C" void notify_retire(int32_t pc, int32_t inst) { retire = true; }
extern "C" void notify_bus_read(int id, uint32_t addr, int len, int rsize) {
  if (config.mtracer)
    spdlog::info(
        "Read  {:#010x}, arid = {:2}, arlen = {:3}, arsize = {:2}, time = {}",
        addr, id, len, rsize, dut->getSimTime());
}
extern "C" void notify_bus_write(int id, uint32_t addr, int len, int wsize) {
  if (config.mtracer)
    spdlog::info(
        "Write {:#010x}, arid = {:2}, arlen = {:3}, arsize = {:2}, time = {}",
        addr, id, len, wsize, dut->getSimTime());
}

bool check_difftest(Dut &dut, Ref &ref) {
  bool ret = false;
  for (int i = 0; i < 16; i++) {
    if (dut.getGPR(i) != ref.getGPR(i)) {
      spdlog::error("gpr {} differs from ref : should be {:08x}, got {:08x}",
                    gpr_names[i], ref.getGPR(i), dut.getGPR(i));
      ret = true;
    }
  }
  if (dut.getPC() != ref.getPC()) {
    spdlog::error("PC differs from ref : should be {:08x}, got {:08x}",
                  ref.getPC(), dut.getPC());
    ret = true;
  }

  return ret;
}

int simulate() {
  // init_mrom(config.image_path);
  init_flash(config.image_path);
  // Verilated::commandArgs(argc, argv);
  std::unique_ptr<VerilatedContext> contextp =
      std::make_unique<VerilatedContext>();
  // contextp->commandArgs(argc, argv);

  Verilated::traceEverOn(true);

  dut = std::make_unique<Dut>(config, contextp.get());
  Ref ref(config, *dut, 1, 1);
  if (config.nvboard) {
    dut->nvboard_bind();
    nvboard_init();
  }
  ref.reset(*dut);
  dut->reset();
  clear_performance_count();
  bool difftest_state = false;
  auto start_time = std::chrono::steady_clock::now();
  while (!contextp->gotFinish()) {
    retire = false;
    if (dut->getResetCore()) {
      ref.reset(*dut);
      ref.sync_state();
      clear_performance_count();
    }
    if (config.nvboard)
      nvboard_update();
    clock_count++;
    dut->step_one_cycle();

    if (retire) {
      // fmt::println("{:08x}", dut->getPC());
      inst_count++;
      if (config.difftest) {
        ref.step();
        difftest_state = check_difftest(*dut, ref);
        if (difftest_state)
          break;
      }
    }
  }
  auto end_time = std::chrono::steady_clock::now();

  int result;
  if (contextp->gotFinish()) {
    if (dut->getGPR(10) == 0) {
      spdlog::info("HIT GOOD TRAP");
      result = 0;
    } else {
      spdlog::warn("HIT BAD TRAP with a0 = {:010x}", dut->getGPR(10));
      result = -1;
    }
  } else if (difftest_state) {
    spdlog::warn("DIFFTEST FAILED");
    result = -2;
  } else {
    spdlog::warn("FAILED TO HALT");
    result = -3;
  }
  dut->print_all_gpr();
  spdlog::info("Reference cache hit count : {}", ref.getCacheHit());
  spdlog::info("Reference instruction count : {}", ref.instrCount());

  display_performance(start_time, end_time);
  dut = nullptr;
  return result;
}

int main(int argc, char *argv[]) {
  config = process_args(argc, argv);
  int return_value = -1;
  try {
    return_value = simulate();
  } catch (const std::exception& e) {
    std::cerr << "Error : " << e.what() << std::endl;
  }
  spdlog::shutdown();
  return return_value;
}
