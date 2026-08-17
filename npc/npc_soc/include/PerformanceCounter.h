#pragma once
#include "DUT.h"
#include <chrono>
#include <spdlog/spdlog.h>

struct InstTypeItem {
  long long count;
  const std::string name;
};

extern long long ifu_event;
extern long long icache_hit_event;
extern long long lsu_read_event;
extern long long exu_event;
extern long long idu_event;
extern long long wbu_event;
extern long long inst_count;
extern long long clock_count;
extern long long sum_ifu_fetch_delay;
extern long long min_ifu_fetch_delay;
extern long long max_ifu_fetch_delay;
extern long long sum_lsu_fetch_delay;
extern long long min_lsu_fetch_delay;
extern long long max_lsu_fetch_delay;

extern long long cycles_not_on_flash;
extern long long insts_not_on_flash;

extern long long stalled_cycles;
extern long long flushed_insts;

extern std::array<InstTypeItem, 14> inst_type_event;

extern std::unique_ptr<Dut> dut;

struct Statistics {
  long long simulation_time;
  long long simulation_clocks;
  long long simulation_instructions;
};

inline Statistics performance_statistics;

inline void clear_performance_count() {
  ifu_event = 0;
  icache_hit_event = 0;
  lsu_read_event = 0;
  exu_event = 0;
  idu_event = 0;
  wbu_event = 0;
  inst_count = 0;
  clock_count = 0;
  cycles_not_on_flash = 0;
  insts_not_on_flash = 0;
  stalled_cycles = 0;
  flushed_insts = 0;

  sum_ifu_fetch_delay = 0;
  min_ifu_fetch_delay = 1145141919810;
  max_ifu_fetch_delay = 0;
  sum_lsu_fetch_delay = 0;
  min_lsu_fetch_delay = 1145141919810;
  max_lsu_fetch_delay = 0;

  for (InstTypeItem &item : inst_type_event)
    item.count = 0;
}

inline void display_performance(auto start_time, auto end_time) {
  auto elapsed_ms =
      std::chrono::floor<std::chrono::milliseconds>(end_time - start_time);

  spdlog::info("Total simulated instructions : {}", inst_count);
  spdlog::info("Total ifu events : {}", ifu_event);
  spdlog::info("Total icache hit events : {}", icache_hit_event);

  spdlog::info("Total lsu read events : {}", lsu_read_event);
  spdlog::info("Total exu events : {}", exu_event);
  spdlog::info("Total idu events : {}", idu_event);
  spdlog::info("Total wbu events : {}", wbu_event);
  spdlog::info("Total stalled cycles : {}", stalled_cycles);
  spdlog::info("Total flushed instructions : {}", flushed_insts);

  if (ifu_event > 0)
    spdlog::info("Total/Average/Min/Max IFU delay : {}/{:.2f}/{}/{}",
                 sum_ifu_fetch_delay,
                 static_cast<double>(sum_ifu_fetch_delay) / ifu_event,
                 min_ifu_fetch_delay, max_ifu_fetch_delay);
  if (lsu_read_event > 0)
    spdlog::info("Total/Average/Min/Max LSU delay : {}/{:.2f}/{}/{}",
                 sum_lsu_fetch_delay,
                 static_cast<double>(sum_lsu_fetch_delay) / lsu_read_event,
                 min_lsu_fetch_delay, max_lsu_fetch_delay);

  spdlog::info("------------Instruction Type Statistics------------");
  long long sum_recorded_inst = 0;
  for (InstTypeItem &item : inst_type_event) {
    spdlog::info("{:35} |      {}", item.name, item.count);
    sum_recorded_inst += item.count;
  }
  spdlog::info("---------------------------------------------------");
  spdlog::info("{:35} |      {}", "Total", sum_recorded_inst);
  spdlog::info("---------------------------------------------------");
  spdlog::info("Total icache hit rate : {:.3f}",
               static_cast<double>(icache_hit_event) / sum_recorded_inst);

  spdlog::info("Total simulated clock periods : {}", clock_count);
  spdlog::info("Total simulated clock periods outsize flash: {}",
               cycles_not_on_flash);
  spdlog::info("Total simulated instructions periods outsize flash: {}",
               insts_not_on_flash);
  spdlog::info("Clocks per instruction : {:.3f}",
               static_cast<double>(clock_count) / inst_count);
  spdlog::info("Clocks per instruction outside flash : {:.3f}",
               static_cast<double>(cycles_not_on_flash) / insts_not_on_flash);
  spdlog::info("Total simulation time : {} ms", elapsed_ms.count());
  spdlog::info("Simulation speed : {:.2f} clocks/s , {:.2f} insts/s",
               1000 * static_cast<double>(clock_count) / elapsed_ms.count(),
               1000 * static_cast<double>(inst_count) / elapsed_ms.count());
}
