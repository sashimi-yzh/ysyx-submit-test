#include <verilated.h>
#include <verilated_vcd_c.h>

#include <npc/platform.h>
#include <sim_top.h>

SimTop *sim_top = NULL;
VerilatedContext *sim_ctx = NULL;
VerilatedVcdC *sim_trace = NULL;
// for trace the log time
extern "C" uint64_t get_sim_time() { return sim_ctx == NULL ? 0 : sim_ctx->time(); }
// decode the word or byte
static uint32_t extract_bus_data(int address, int data, int length) {
  uint32_t value = (uint32_t)data;
  uint32_t offset = (uint32_t)address;
  if (length == 1) return (value >> ((offset & 3u) * 8)) & 0xffu;
  if (length == 2) return (value >> ((offset & 2u) * 8)) & 0xffffu;
  return value;
}
// choice W or R
extern "C" void trace_bus(int is_write, int address, int data, int length) {
  word_t value = extract_bus_data(address, data, length);
  if (is_write) trace_bus_write((paddr_t)address, length, value);
  else trace_bus_read((paddr_t)address, length, value);
}
