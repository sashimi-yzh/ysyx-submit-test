#include <chrono>
#include <fstream>
#include <iostream>
#include <string_view>
#include <verilated.h>
#include <verilated_vpi.h>

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "sdbWrap.hpp"
#include "sim.hpp"

#include "PerfCounter.hpp"
#include "spdlog/common.h"

#include "common.hpp"

int gdb_mainloop();

int main(int argc, char **argv) {
  auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
  console_sink->set_level(spdlog::level::info);
  auto file_sink = newFileLoggerSink("sim");
  file_sink->set_level(spdlog::level::debug);
  auto sinks = spdlog::sinks_init_list{console_sink, file_sink};
  auto logger = std::make_shared<spdlog::logger>("sim", sinks);
  logger->set_level(spdlog::level::debug);

  spdlog::set_default_logger(logger);
  // spdlog::set_level(spdlog::level::debug); // will modify all registered
  // loggers
  spdlog::set_pattern("[%H:%M:%S.%e][%^%-5l%$][%n] %v");

  sim_get_config()->init_pc =
#ifdef SIM_ARCH_JYD
      0x80000000;
#else
      0x30000000;
#endif

  if (is_soc()) {
    spdlog::info("Simulating SoC design");
    if (isCIEnv()) {
      spdlog::info("CI environment detected, enabling nvboard");
      sim_get_config()->setting.nvboard = true;
    }
  } else {
    spdlog::info("Simulating CPU core design");
  }
  std::string_view git_commit_hash = _STR(GIT_COMMIT_HASH);
  spdlog::info("Git commit hash: {}", git_commit_hash);

  std::string perfOutRootDir = isMakePerf() ? "history_perf" : "build/perf";
  std::string perfOutDir = getOutputDir(perfOutRootDir);

  spdlog::info("perf report output dir: {}", perfOutDir);

  spdlog::info("Sim init pc set to 0x{:08x}", sim_get_config()->init_pc);

  auto &setting = sim_get_config()->setting;
  load_sim_setting_from_env(setting);

  if (!sim_init(argc, argv, setting)) {
    get_dut()->final();
    spdlog::error("sim_init failed");
    return 1;
  }

  initPerfCounters();
  spdlog::info("perf counters initialized");

  int mainloop_ret = 0;

  if (setting.gdb_mode) {
    gdb_mainloop();
  } else {
    mainloop_ret = sdb_mainloop();
  }

  if (mainloop_ret == 0) {
    spdlog::info("sim ended good, dumping statistics...");
    dumpPerfCountersStatistics(std::cout);
    dumpPerfReportOnDir(perfOutDir);
  } else {
    spdlog::error("sim ended with bad status");
  }

  get_dut()->final();
  if (!setting.gdb_mode) {
    return mainloop_ret;
  }
  return 0;
}
