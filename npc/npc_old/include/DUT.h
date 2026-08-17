#pragma once

#include "Vnpc_top.h"
#include "Vnpc_top___024root.h"
#include "my_utils.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <ELFParser.h>
#include <Setup.h>
#include <fmt/format.h>

static const std::array<std::string, 32> gpr_names = {
    "$0", "ra", "sp", "gp", "tp",  "t0",  "t1", "t2", "s0", "s1", "a0",
    "a1", "a2", "a3", "a4", "a5",  "a6",  "a7", "s2", "s3", "s4", "s5",
    "s6", "s7", "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

#define gprname(X)                                                             \
  rootp->npc_top__DOT__cpu__DOT__gpr__DOT__register_bank_regs_##X##_r

class Dut {
public:
  Dut(VerilatedContext *contextp) : sim_time{0} {
    top = std::make_unique<Vnpc_top>(contextp);
    if (config.use_waveform) {
      m_trace = std::make_unique<VerilatedVcdC>();
      top->trace(m_trace.get(), 5);
      m_trace->open(config.waveform_file.c_str());
    }
  }

  void reset() {
    top->reset = 1;
    for (int i = 0; i < 32; i++) {
      top->clock = 0;
      top->eval();
      top->clock = 1;
      top->eval();
    }
    top->reset = 0;
  }

  void step_one_cycle() {
    top->clock = 0;
    top->eval();
    if (config.use_waveform)
      m_trace->dump(2 * sim_time);
    top->clock = 1;
    top->eval();
    if (config.use_waveform)
      m_trace->dump(2 * sim_time + 1);
    sim_time++;
    // println("PC : {:08x}, a5 = {:08x}", getPC(), getGPR(15));
  }

  void step_one_inst() {}
  vluint64_t getSimTime() { return sim_time; }

  uint32_t getPC() { return top->rootp->npc_top__DOT__cpu__DOT__pc; }
  uint32_t getGPR(int idx) {
    switch (idx) {
    case 0:
      return 0;
    case 1:
      return top->gprname(0);
    case 2:
      return top->gprname(1);
    case 3:
      return top->gprname(2);
    case 4:
      return top->gprname(3);
    case 5:
      return top->gprname(4);
    case 6:
      return top->gprname(5);
    case 7:
      return top->gprname(6);
    case 8:
      return top->gprname(7);
    case 9:
      return top->gprname(8);
    case 10:
      return top->gprname(9);
    case 11:
      return top->gprname(10);
    case 12:
      return top->gprname(11);
    case 13:
      return top->gprname(12);
    case 14:
      return top->gprname(13);
    case 15:
      return top->gprname(14);
      // case 16:
      //   return top->gprname(15);
      // case 17:
      //   return top->gprname(16);
      // case 18:
      //   return top->gprname(17);
      // case 19:
      //   return top->gprname(18);
      // case 20:
      //   return top->gprname(19);
      // case 21:
      //   return top->gprname(20);
      // case 22:
      //   return top->gprname(21);
      // case 23:
      //   return top->gprname(22);
      // case 24:
      //   return top->gprname(23);
      // case 25:
      //   return top->gprname(24);
      // case 26:
      //   return top->gprname(25);
      // case 27:
      //   return top->gprname(26);
      // case 28:
      //   return top->gprname(27);
      // case 29:
      //   return top->gprname(28);
      // case 30:
      //   return top->gprname(29);
      // case 31:
      //   return top->gprname(30);
    }
    log_and_throw<std::logic_error>("Invalid register index : {} @PC={:08x}",
                                    idx, getPC());
  }

  void print_all_gpr() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        int gpr_id = i * 4 + j;
        fmt::print("{:3}= {:08x} ", gpr_names[gpr_id], getGPR(gpr_id));
      }
      fmt::print("\n");
    }
    println("PC = {:#010x}", getPC());
  }

  ~Dut() {
    if (config.use_waveform)
      m_trace->close();
  }

private:
  vluint64_t sim_time;
  std::unique_ptr<Vnpc_top> top;
  std::unique_ptr<VerilatedVcdC> m_trace;
};
#undef gprname
