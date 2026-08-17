#include <DUT.h>
#include <PerformanceCounter.h>
#include <algorithm>
#include <array>
#include <spdlog/spdlog.h>
long long ifu_event;
long long icache_hit_event;
long long lsu_read_event;
long long exu_event;
long long idu_event;
long long wbu_event;
long long inst_count;
long long clock_count;
long long sum_ifu_fetch_delay;
long long min_ifu_fetch_delay;
long long max_ifu_fetch_delay;
long long sum_lsu_fetch_delay;
long long min_lsu_fetch_delay;
long long max_lsu_fetch_delay;
static long long last_ifu_time;
static long long last_lsu_time;

long long cycles_not_on_flash;
long long insts_not_on_flash;

long long stalled_cycles;
long long flushed_insts;

extern std::unique_ptr<Dut> dut;

std::array<InstTypeItem, 14> inst_type_event = {
    {{0, "Arithmetic immediate"},
     {0, "Arithmetic register"},
     {0, "Store"},
     {0, "Load"},
     {0, "Branch"},
     {0, "Jump and link"},
     {0, "Jump and link register"},
     {0, "Load upper immediate"},
     {0, "Add upper immediate PC"},
     {0, "Environment break"},
     {0, "Environment call"},
     {0, "Machine mode returen"},
     {0, "Control state register operation"},
     {0, "Fence"}}};

enum {
  TYPE_arithmetic_imm,
  TYPE_arithmetic_reg,
  TYPE_store,
  TYPE_load,
  TYPE_branch,
  TYPE_jal,
  TYPE_jalr,
  TYPE_lui,
  TYPE_auipc,
  TYPE_ebreak,
  TYPE_ecall,
  TYPE_mret,
  TYPE_csrop,
  TYPE_fence
};
extern "C" void notify_ifu_r_event() {
  ifu_event++;
  long long delay = dut->getSimTime() - last_ifu_time;
  sum_ifu_fetch_delay += delay;
  max_ifu_fetch_delay = std::max(max_ifu_fetch_delay, delay);
  min_ifu_fetch_delay = std::min(min_ifu_fetch_delay, delay);
}
extern "C" void notify_icache_hit_event() { icache_hit_event++; }
extern "C" void notify_lsu_r_event() {
  lsu_read_event++;
  long long delay = dut->getSimTime() - last_lsu_time;
  sum_lsu_fetch_delay += delay;
  max_lsu_fetch_delay = std::max(max_lsu_fetch_delay, delay);
  min_lsu_fetch_delay = std::min(min_lsu_fetch_delay, delay);
}
extern "C" void notify_ifu_ar_event() { last_ifu_time = dut->getSimTime(); }
extern "C" void notify_lsu_ar_event() { last_lsu_time = dut->getSimTime(); }
extern "C" void notify_exu_event() { exu_event++; }
extern "C" void notify_idu_event() { idu_event++; }
extern "C" void notify_wbu_event() { wbu_event++; }
extern "C" void notify_inst_type_is_arithmetic_imm() {
  inst_type_event[TYPE_arithmetic_imm].count++;
}
extern "C" void notify_inst_type_is_arithmetic_reg() {
  inst_type_event[TYPE_arithmetic_reg].count++;
}
extern "C" void notify_inst_type_is_store() {
  inst_type_event[TYPE_store].count++;
}
extern "C" void notify_inst_type_is_load() {
  inst_type_event[TYPE_load].count++;
}
extern "C" void notify_inst_type_is_branch() {
  inst_type_event[TYPE_branch].count++;
}
extern "C" void notify_inst_type_is_jal() { inst_type_event[TYPE_jal].count++; }
extern "C" void notify_inst_type_is_jalr() {
  inst_type_event[TYPE_jalr].count++;
}
extern "C" void notify_inst_type_is_lui() { inst_type_event[TYPE_lui].count++; }
extern "C" void notify_inst_type_is_auipc() {
  inst_type_event[TYPE_auipc].count++;
}
extern "C" void notify_inst_type_is_ebreak() {
  inst_type_event[TYPE_ebreak].count++;
}
extern "C" void notify_inst_type_is_ecall() {
  inst_type_event[TYPE_ecall].count++;
}
extern "C" void notify_inst_type_is_mret() {
  inst_type_event[TYPE_mret].count++;
}
extern "C" void notify_inst_type_is_csrop() {
  inst_type_event[TYPE_csrop].count++;
}
extern "C" void notify_inst_type_is_fence() {
  inst_type_event[TYPE_fence].count++;
}

extern "C" void notify_new_cycle_not_on_flash() { cycles_not_on_flash++; }
extern "C" void notify_new_inst_not_on_flash() { insts_not_on_flash++; }

extern "C" void notify_stalled() { stalled_cycles++; }
extern "C" void notify_flushed() { flushed_insts++; }