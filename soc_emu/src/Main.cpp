
#include "spdlog/spdlog.h"
#include <Args.h>
#include <Cache.h>
#include <Ref.h>
#include <chrono>
#include <exception>
#include <iostream>
#include <print>

using std::string;

Ref ref;

int simulate(Config config) {
  int return_value = 0;
  ref.init(config);
  ref.reset();

  auto start_time = std::chrono::steady_clock::now();
  while (!ref.isHalt()) {
    ref.step();
  }
  auto end_time = std::chrono::steady_clock::now();

  if (ref.getGPR(10) == 0) {
    spdlog::info("HIT GOOD TRAP");
  } else {
    spdlog::warn("HIT BAD TRAP");
    return_value = -1;
  }

  auto elapsed_ms =
      std::chrono::floor<std::chrono::milliseconds>(end_time - start_time);
  spdlog::info("Total simulation time : {:%Hh %Mm %Ss}", elapsed_ms);
  spdlog::info("Total instruction count : {}", ref.instrCount());
  spdlog::info("Total icache hit count : {}", ref.getICacheHit());
  spdlog::info("ICache hit rate : {:.3f}",
               static_cast<double>(ref.getICacheHit()) / ref.instrCount());
  spdlog::info("Total data fetch count : {}", ref.getDataFetchCount());
  spdlog::info("Total dcache hit count : {}", ref.getDCacheHit());
  spdlog::info("DCache hit rate : {:.3f}",
               static_cast<double>(ref.getDCacheHit()) /
                   ref.getDataFetchCount());
  spdlog::info("Total PC predict miss count : {}", ref.getPCPredictMiss());
  spdlog::info("Total PC predict hit count : {}", ref.getPCPredictHit());
  spdlog::info("PC predict accuracy : {:.3f}",
               static_cast<double>(ref.getPCPredictHit()) /
                   (ref.getPCPredictMiss() + ref.getPCPredictHit()));
  spdlog::info("Simulation speed : {:.2f} insts/s",
               1000 * static_cast<double>(ref.instrCount()) /
                   elapsed_ms.count());

  return return_value;
}

int main(int argc, char *argv[]) {
  Config config = process_args(argc, argv);
  int return_value = -1;
  try {
    return_value = simulate(config);
  } catch (std::exception e) {
    std::println(std::cerr, "Error : {}", e.what());
  }
  spdlog::shutdown();
  return return_value;
}