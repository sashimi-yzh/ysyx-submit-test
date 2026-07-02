#include <verilated.h>
#include <verilated_vcd_c.h>

#include <platform/platform.h>
#include <sim_top.h>

SimTop *g_top = NULL;
VerilatedContext *g_contextp = NULL;
VerilatedVcdC *g_tfp = NULL;

extern "C" uint64_t npc_get_sim_time() {
  return g_contextp == NULL ? 0 : g_contextp->time();
}

extern "C" void npc_bus_trace(int is_write, int addr, int data, int len) {
  uint32_t value = (uint32_t)data;
  if (len == 1) value = (value >> (((uint32_t)addr & 3) * 8)) & 0xff;
  if (len == 2) value = (value >> (((uint32_t)addr & 2) * 8)) & 0xffff;

  if (is_write) platform_trace_write((paddr_t)addr, len, value);
  else platform_trace_read((paddr_t)addr, len, value);
}
