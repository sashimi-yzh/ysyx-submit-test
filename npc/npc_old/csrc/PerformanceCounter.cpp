#include <DUT.h>
#include <PerformanceCounter.h>
#include <spdlog/spdlog.h>

extern std::unique_ptr<Dut> dut;

extern "C" void notify_ifu_r_event() {}
extern "C" void notify_icache_hit_event() {}
extern "C" void notify_lsu_r_event() {}
extern "C" void notify_ifu_ar_event() {}
extern "C" void notify_lsu_ar_event() {}
extern "C" void notify_exu_event() {}
extern "C" void notify_idu_event() {}
extern "C" void notify_wbu_event() {}
extern "C" void notify_inst_type_is_arithmetic_imm() {}
extern "C" void notify_inst_type_is_arithmetic_reg() {}
extern "C" void notify_inst_type_is_store() {}
extern "C" void notify_inst_type_is_load() {}
extern "C" void notify_inst_type_is_branch() {}
extern "C" void notify_inst_type_is_jal() {}
extern "C" void notify_inst_type_is_jalr() {}
extern "C" void notify_inst_type_is_lui() {}
extern "C" void notify_inst_type_is_auipc() {}
extern "C" void notify_inst_type_is_ebreak() {}
extern "C" void notify_inst_type_is_ecall() {}
extern "C" void notify_inst_type_is_mret() {}
extern "C" void notify_inst_type_is_csrop() {}
extern "C" void notify_inst_type_is_fence() {}
extern "C" void notify_bus_read(unsigned int addr, unsigned int data, unsigned int len,
                     unsigned int id) {}
extern "C" void notify_bus_write(unsigned int addr, unsigned int data, unsigned int len,
                      unsigned int id) {}
extern "C" void notify_stalled() {}
extern "C" void notify_flushed() {}

extern "C" void notify_new_cycle_not_on_flash() {}
extern "C" void notify_new_inst_not_on_flash() {}