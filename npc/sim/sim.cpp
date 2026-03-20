#include "sim.hpp"
#include "sdbWrap.hpp"

#include <algorithm>
#include <cmath>
#include <spdlog/common.h>
#include <spdlog/logger.h>
#include <spdlog/pattern_formatter.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/dup_filter_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include <cassert>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <string_view>
#include <sys/types.h>
#include <variant>

#include "verilated_fst_c.h"
#include "vsrc.hpp"

#include "common.hpp"

#if ENABLE_NVBOARD
#include <nvboard.h>
#endif

#include <getopt.h>
#include <unistd.h>
#include <vector>

#include "PerfCounter.hpp"

#include "memory/mem.hpp"

#include "KonataLog/KonataLog.hpp"

TOP_NAME dut;
sim_config sim_cfg;
sim_setting &sim_settings = sim_cfg.setting;

sim_cpu_state cpu;

TOP_NAME *get_dut() { return &dut; }

void nvboard_bind_all_pins(TOP_NAME *top);

typedef uint32_t word_t;
typedef uint32_t addr_t;

std::shared_ptr<VerilatedFstC> tfp;

static uint64_t sim_time = 0;
static uint64_t cycle_count = 0;
static uint64_t inst_count = 0;

sim_time_t sim_get_time() { return sim_time; }
sim_cycle_t sim_get_cycle() { return cycle_count; }

sim_config *sim_get_config() { return &sim_cfg; }
sim_cpu_state *sim_get_cpu_state() { return &cpu; }

uint64_t sim_get_inst_count() { return inst_count; }

class sim_time_formatter : public spdlog::custom_flag_formatter {
public:
  void format(const spdlog::details::log_msg &, const std::tm &,
              spdlog::memory_buf_t &dest) override {
    std::string s = std::to_string(sim_time) + "ps";
    dest.append(s.data(), s.data() + s.size());
  }

  std::unique_ptr<custom_flag_formatter> clone() const override {
    return spdlog::details::make_unique<sim_time_formatter>();
  }
};

std::shared_ptr<KonataLogger> konata_logger;

static void _sim_eval() {
  dut.eval();
  if (tfp) {
    tfp->dump(sim_time);
  }
  sim_time++;
}

void sim_step_cycle() {
  if (sim_settings.trace_clock_cycle) {
    printf("[Clock Cycle Begin]\n");
  }

  dut.clock = 1;
  _sim_eval();

  dut.clock = 0;
  _sim_eval();

  cycle_count++;
  // fmt::println("cycle {}", cycle_count);

#if ENABLE_NVBOARD
  if (sim_settings.nvboard) {
    nvboard_update();
  }
#endif

  if (sim_settings.trace_clock_cycle) {
    printf("[Clock Cycle End]\n");
  }
  if (sim_settings.cycle_finish_cb) {
    sim_settings.cycle_finish_cb();
  }

  if (dut.reset == 0) {
    updatePerfCounters();
    if (konata_logger) {
      konata_logger->update();
    }
  }
}
static void reset(int n) {
  dut.reset = 1;
  while (n-- > 0) {
    sim_step_cycle();
  }
  dut.reset = 0;
}

static bool is_running = true;
static bool is_good_trap = false;

void raise_ebreak() {
  is_running = false;

  int a0 = cpu.gpr[10];

  // sbd_set_halt(a0);
  assert(sim_cfg.raise_halt_cb);
  sim_cfg.raise_halt_cb(a0);

  constexpr std::string_view fg_red = "\33[1;31m", fg_green = "\33[1;32m",
                             fg_yellow = "\33[1;33m", ansi_none = "\33[0m";

  is_good_trap = (a0 == 0);

  spdlog::info("{}HIT {} TRAP{} a0 = {} @pc = 0x{:08x} cyc {}",
               is_good_trap ? fg_green : fg_red, is_good_trap ? "GOOD" : "BAD",
               ansi_none, a0, cpu.pc, cycle_count);
}
bool sim_halted() { return !is_running; }

// word_t img[60 * 1024 * 1024 / 4] = {};
std::vector<uint8_t> img;
const word_t defalut_img[] = {
    0x00000297, // auipc t0,0
    0x00028823, // sb  zero,16(t0)
    0x0102c503, // lbu a0,16(t0)
    0x00100073, // ebreak
    0xdeadbeef, // some data
    0x12345678,
};

#define _EXPAND(x) x

extern "C" void uart_putch(char ch) {
  putchar(ch);
  fflush(stdout);
  skip_difftest_ref();
}

extern "C" void gpr_upd(char regno, int data) {
  if (regno == 0)
    return;
  cpu.gpr[regno] = data;
}

bool pc_changed = false;
extern "C" void pc_upd(int pc, int npc) {
  pc_changed = true;
  cpu.pc = npc;
  // printf("[DPI] pc_upd called, pc=0x%08x npc=0x%08x\n", pc, npc);
}

extern "C" void skip_difftest_ref() {
  if (sim_settings.trace_difftest_skip) {
    printf("(%ld)[DPI] skip_difftest_ref called\n", sim_time);
  }
  sdb_skip_difftest_ref();
}

void sim_step_inst() {
  size_t cnt = 0;
  // SPI flash may need many cycles to respond
  constexpr size_t MAYBE_DEADLOOP_THRESHOLD = 8192 * 2;
  while (!pc_changed) {
    sim_step_cycle();
    if (sim_halted()) {
      cpu.pc += 4;
      inst_count++;
      return;
    }
    cnt++;
    if (cnt >= MAYBE_DEADLOOP_THRESHOLD) {
      if (!sim_settings.gdb_mode) {
        sdb_dump_recent_info();
      }
      spdlog::warn("simulation has stepped {} cycles without pc change, maybe "
                   "lock happened",
                   cnt);
      // printf("wanting to continue? (y/[n]) ");
      // char c = getchar();
      // if (c == 'y' || c == 'Y') {
      //   cnt = 0;
      //   while (getchar() != '\n') {
      //   }
      //   continue;
      // } else {
      spdlog::info("sim exit due to possible deadloop");
      exit(1);
      // }
    }
  }
  pc_changed = false;
  inst_count++;
  if (inst_count % (1024 * 1024 * 8) == 0) {
    spdlog::info("8M instructions executed (now {}M), pc = 0x{:08x}, cycle = "
                 "{}, time = {}ps",
                 inst_count / (1024 * 1024), cpu.pc, cycle_count, sim_time);
  }
}

// IMG

static void load_img() {
#define Assert(expr, ...)                                                      \
  do {                                                                         \
    if (!(expr)) {                                                             \
      fprintf(stderr, __VA_ARGS__);                                            \
    }                                                                          \
  } while (0)

  if (sim_cfg.img_file_path == NULL) {
    spdlog::warn("No image is given. Use the default build-in image.");
    sim_cfg.img_size = 24;
    return;
  }

  FILE *fp = fopen(sim_cfg.img_file_path, "rb");
  Assert(fp, "Can not open '%s'", sim_cfg.img_file_path);

  fseek(fp, 0, SEEK_END);
  sim_cfg.img_size = ftell(fp);

  spdlog::info("load image {}, size = {}", sim_cfg.img_file_path,
               sim_cfg.img_size);

  img.resize(sim_cfg.img_size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(img.data(), sim_cfg.img_size, 1, fp);
  assert(ret == 1);

  fclose(fp);
}

// ARG

static void parse_args(int argc, char **argv) {
  const struct option table[] = {{"batch", no_argument, NULL, 'b'},
                                 {0, 0, NULL, 0}};
  int o;
  while ((o = getopt_long(argc, argv, "-b", table, NULL)) != -1) {
    switch (o) {
    case 'b':
      sim_cfg.hope_batch_mode = true;
      break;
    case 1:
      sim_cfg.img_file_path = optarg;
      break;
    default:
      printf("Bad option %c\n", o);
      exit(1);
    }
  }
}

static auto _gen_logger_formatter_with_simtime() {
  auto formatter = std::make_unique<spdlog::pattern_formatter>();
  formatter->add_flag<sim_time_formatter>('&');
  // (sim_time) [logger_name] [log_level] log_msg
  formatter->set_pattern("(%&) [%n] [%^%l%$] %v");
  return formatter;
}

void set_logger_pattern_with_simtime(std::shared_ptr<spdlog::logger> logger) {
  auto formatter = _gen_logger_formatter_with_simtime();
  logger->set_formatter(std::move(formatter));
}

bool sim_init(int argc, char **argv, sim_setting setting) {
  Verilated::commandArgs(argc, argv);
  sim_settings = setting;
#if ENABLE_NVBOARD
  if (setting.nvboard) {
    spdlog::info("initializing nvboard");
    nvboard_bind_all_pins(&dut);
    if (isCIEnv()) {
      spdlog::info("CI environment detected, disabling UART TX to avoid "
                   "duplicate output");
      nvboard_bind_pin(nullptr, 1, UART_TX);
    }
    nvboard_init();
  }
#endif

  parse_args(argc, argv);

  using std::string;
  using namespace std::ranges;

  load_img();
  // should before dbg_init(which may preload data with func call dpis)
  init_mem(img.data(), sim_cfg);

  if (setting.en_wave) {
    Verilated::traceEverOn(true);
    tfp = std::shared_ptr<VerilatedFstC>(new VerilatedFstC,
                                         [](VerilatedFstC *p) { p->close(); });
    dut.trace(tfp.get(), 99);
    tfp->open(setting.wave_fst_file.c_str());
    spdlog::info("wave enabled, output file: {}", setting.wave_fst_file);
  }

  constexpr int reset_cycles = 30;
  reset(reset_cycles);
  spdlog::info("sim reset done ({} cycles)", reset_cycles);

  cpu.pc = sim_cfg.init_pc;
  spdlog::info("set initial pc to {:08x}", cpu.pc);

  if (isMakePerf()) {
    spdlog::info("Make perf mode, disable konata logger");
    return true;
  }

  konata_logger = std::make_shared<KonataLogger>(genLogFilePath("konata"));
  konata_logger->start(sim_get_cycle());
  spdlog::info("KonataLogger initialized, start at cycle {}, sim time {}ps",
               sim_get_cycle(), sim_get_time());

  return true;
}
