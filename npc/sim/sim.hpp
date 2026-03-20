#pragma once

#include "vsrc.hpp"
#include <cstdint>
#include <stdint.h>
#include <string_view>

#include <spdlog/spdlog.h>
TOP_NAME *get_dut();

namespace DirectSignals {
inline auto GetCPU() {
  // use vlSymsp to get inner module/signal
#ifdef SIM_SOC
  return &get_dut()->ysyxSoCFull->vlSymsp->TOP__ysyxSoCFull__asic__cpu__cpu__core;
#else
  return &get_dut()->TestSoC->vlSymsp->TOP__TestSoC__cpu__core;
#endif
}

inline auto GetIFU() { return GetCPU()->ifu; }
// inline auto GetEXUS1() { return GetCPU()->exu->stageCalc; }
// inline auto GetEXUS2() { return GetCPU()->exu->stageChooseNxt; }

inline auto GetEXU() { return GetCPU()->exu; }

inline auto GetLSU() { return GetCPU()->lsu; }
inline auto GetALU() { return GetEXU()->alu; }
inline auto GetIDU() { return GetCPU()->idu; }
inline auto GetICache() { return GetCPU()->icache; }
} // namespace DirectSignals

typedef void (*cycle_end_callback_t)();

using sim_time_t = uint64_t;
using sim_cycle_t = uint64_t;

struct sim_setting {
  bool en_inst_trace = true;

  bool showdisasm = true;
  bool always_showdisasm = false;

  bool no_batch = false;

  bool gdb_mode = false;

  bool ftrace = false;
  int iringbuf = 32;
  bool etrace = true;
  bool difftest = true;

  bool nvboard = false;

  bool zero_uninit_ram = false;

  bool trace_difftest_skip = false;

  bool trace_pmem_readcall = false;
  bool trace_pmem_writecall = false;
  bool trace_inst_fetchcall = false;
  bool trace_mmio_write = false;

  bool trace_clock_cycle = false;

#define TRACE_DPI_FLAG(name) trace_dpi_##name

#define _GEN_DPI_FLAG(name) bool TRACE_DPI_FLAG(name) = false;
  _GEN_DPI_FLAG(mrom_read);
  _GEN_DPI_FLAG(sdram_read);
  _GEN_DPI_FLAG(sdram_write);
  _GEN_DPI_FLAG(flash_read);

  _GEN_DPI_FLAG(psram_read);
  _GEN_DPI_FLAG(psram_write);

  cycle_end_callback_t cycle_finish_cb = nullptr;

  bool en_wave = false;

  std::string wave_fst_file = "build/wave.fst";
};

typedef void (*raise_halt_cb_t)(int a0);

struct sim_config {
  uint32_t init_pc;
  size_t img_size;
  const char *img_file_path;

  bool hope_batch_mode;

  sim_setting setting;
  raise_halt_cb_t raise_halt_cb;

  inline bool is_batch_mode() const {
    return hope_batch_mode && !setting.no_batch;
  }
};

struct sim_cpu_state {
  uint32_t pc;
  uint32_t gpr[32];
};

// unchange item if not set in env
void load_sim_setting_from_env(sim_setting &setting);

bool sim_init(int argc, char **argv, sim_setting teg = sim_setting{});

void sim_step_cycle();
void sim_step_inst();

sim_time_t sim_get_time();
sim_cycle_t sim_get_cycle();
uint64_t sim_get_inst_count();

void sim_dump_statistics();

sim_config *sim_get_config();
sim_cpu_state *sim_get_cpu_state();

bool sim_halted();

void set_logger_pattern_with_simtime(std::shared_ptr<spdlog::logger> logger);
