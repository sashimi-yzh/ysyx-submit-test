#pragma once
#include TOP_HEADER
#include TOP_PROOT_HEADER
#include <axi.hpp>
#include <difftest.hpp>
#include <format.hpp>
#include <mtrace.hpp>
#include <nvboard.h>
#include <pattern.hpp>
#include <verilated_vcd_c.h>
class Npc {
  VTop *top;
  VerilatedVcdC *tfp;
  vluint64_t main_time;
  bool nvboardInited;
  bool tracing;
  bool mtrace;
  Npc() {
    Verilated::traceEverOn(true);
    top = new VTop();
    main_time = 0;
    nvboardInited = false;
    mtrace = false;
    setTracing(false);
  }
  ~Npc() {
    if (tfp) {
      tfp->close();
      delete tfp;
    }
  }
  void bindNvBoard() {
#ifdef USE_YSYXSOC
    nvboard_bind_pin(&top->externalPins_gpio_in, 16, SW15, SW14, SW13, SW12,
                     SW11, SW10, SW9, SW8, SW7, SW6, SW5, SW4, SW3, SW2, SW1,
                     SW0);
    nvboard_bind_pin(&top->externalPins_gpio_out, 16, LD15, LD14, LD13, LD12,
                     LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1,
                     LD0);
    nvboard_bind_pin(&top->externalPins_gpio_seg_0, 8, SEG0A, SEG0B, SEG0C,
                     SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_1, 8, SEG1A, SEG1B, SEG1C,
                     SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_2, 8, SEG2A, SEG2B, SEG2C,
                     SEG2D, SEG2E, SEG2F, SEG2G, DEC2P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_3, 8, SEG3A, SEG3B, SEG3C,
                     SEG3D, SEG3E, SEG3F, SEG3G, DEC3P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_4, 8, SEG4A, SEG4B, SEG4C,
                     SEG4D, SEG4E, SEG4F, SEG4G, DEC4P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_5, 8, SEG5A, SEG5B, SEG5C,
                     SEG5D, SEG5E, SEG5F, SEG5G, DEC5P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_6, 8, SEG6A, SEG6B, SEG6C,
                     SEG6D, SEG6E, SEG6F, SEG6G, DEC6P);
    nvboard_bind_pin(&top->externalPins_gpio_seg_7, 8, SEG7A, SEG7B, SEG7C,
                     SEG7D, SEG7E, SEG7F, SEG7G, DEC7P);
    nvboard_bind_pin(&top->externalPins_uart_tx, 1, UART_TX);
    nvboard_bind_pin(&top->externalPins_uart_rx, 1, UART_RX);
    nvboard_bind_pin(&top->externalPins_ps2_clk, 1, PS2_CLK);
    nvboard_bind_pin(&top->externalPins_ps2_data, 1, PS2_DAT);
    nvboard_bind_pin(&top->externalPins_vga_r, 8, VGA_R0, VGA_R1, VGA_R2,
                     VGA_R3, VGA_R4, VGA_R5, VGA_R6, VGA_R7);
    nvboard_bind_pin(&top->externalPins_vga_g, 8, VGA_G0, VGA_G1, VGA_G2,
                     VGA_G3, VGA_G4, VGA_G5, VGA_G6, VGA_G7);
    nvboard_bind_pin(&top->externalPins_vga_b, 8, VGA_B0, VGA_B1, VGA_B2,
                     VGA_B3, VGA_B4, VGA_B5, VGA_B6, VGA_B7);
    nvboard_bind_pin(&top->externalPins_vga_hsync, 1, VGA_HSYNC);
    nvboard_bind_pin(&top->externalPins_vga_vsync, 1, VGA_VSYNC);
    nvboard_bind_pin(&top->externalPins_vga_valid, 1, VGA_BLANK_N);
#endif
  }

  struct PerformanceCounter {
    struct InstCounter {
      uint64_t done = 0;
      uint64_t cost = 0;

      std::string ipc(uint8_t precision = 3) const {
        if (!cost)
          return "0";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision);
        oss << double(done) / cost;
        return oss.str();
      }
    };
    struct CacheCounter {
      uint64_t hit = 0;
      uint64_t miss = 0;
      uint64_t accessTime = 0;
      uint64_t missPenalty = 0;
      std::string amat(int precision = 3) const {
        if (!(hit + miss))
          return "0";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision);
        double p = double(hit) / (hit + miss);
        double amat = accessTime + (1 - p) * missPenalty;
        oss << amat;
        return oss.str();
      }
    };
    struct ControlCounter {
      uint64_t hit = 0;
      uint64_t miss = 0;
      std::string hitRate(int precision = 3) const {
        if (!(hit + miss))
          return "0";
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(precision);
        double p = double(hit) / (hit + miss);
        oss << p;
        return oss.str();
      }
    };
    uint64_t clock = 0;
    uint64_t totalDone = 0;
    uint64_t lsuLoad = 0;
    uint64_t lsuLoadCost = 0;
    uint64_t lsuStore = 0;
    uint64_t lsuStoreCost = 0;
    uint64_t exuDone = 0;
    InstCounter control;
    InstCounter csr;
    InstCounter load;
    InstCounter store;
    InstCounter instructionFetch;
    CacheCounter icache;
    ControlCounter branch;
    ControlCounter jal;
    ControlCounter jalr;
    std::string ipc(int precision = 3) const {
      if (!clock)
        return "0";
      std::ostringstream oss;
      oss << std::fixed << std::setprecision(precision);
      oss << double(totalDone) / clock;
      return oss.str();
    }
  } counter;
  uint32_t pendingMemAddr = 0;
  bool pendingMemAddrValid = false;
  uint32_t retiredMemAddr = 0;
  bool retiredMemAddrValid = false;

public:
  const PerformanceCounter &getCounter() const { return counter; }
  bool done() { return Verilated::gotFinish() || breakpoint(); }
#ifdef USE_YSYXSOC
#define CPU_PRE(x) top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu##x
#else
#define CPU_PRE(x) top->rootp->ysyx_25060161##x
#endif
  bool nextDone() { return CPU_PRE(__DOT__wbu__DOT__state); }
  bool coreTimeOut() {
    const static uint64_t kStallThreshold = 1 << 12;
    static uint8_t lastStatusIFU = 0;
    static uint8_t lastStatusIDU = 0;
    static uint8_t lastStatusEXU = 0;
    static uint8_t lastStatusMAU = 0;
    static uint8_t lastStatusWBU = 0;
    static uint64_t clockPassed = 0;
    if (
#ifdef USE_YSYXSOC
        sdramInited() && main_time > 50000 && !Npc::getInstance().rDelaying() &&
        !Npc::getInstance().wDelaying() &&
#endif
        CPU_PRE(__DOT__ifu__DOT__state) == lastStatusIFU &&
        CPU_PRE(__DOT__idu__DOT__state) == lastStatusIDU &&
        CPU_PRE(__DOT__exu__DOT__state) == lastStatusEXU &&
        CPU_PRE(__DOT__mau__DOT__state) == lastStatusMAU &&
        CPU_PRE(__DOT__wbu__DOT__state) == lastStatusWBU) {
      if (clockPassed++ > kStallThreshold) {
        print(format::red, "core timingout", clockPassed, kStallThreshold);
        print(format::red,
              "====== Register Dump (Timeout) ======", format::clear);
        CPU_state cpu = getCpu();
        for (int i = 0; i < 32; i++)
          print(regs[i], "\t", hex(cpu.gpr[i]));
        print("pc", "\t", hex(pc()));
        print("npc", "\t", hex(cpu.npc));
        print("mtvec", "\t", hex(cpu.csrs.mtvec));
        print("mepc", "\t", hex(cpu.csrs.mepc));
        print("mstatus", "\t", hex(cpu.csrs.mstatus));
        print("mcause", "\t", hex(cpu.csrs.mcause));
        print("mvendorid", "\t", hex(cpu.csrs.mvendorid));
        print("marchid", "\t", hex(cpu.csrs.marchid));
        return 1;
      }
    } else {
      clockPassed = 0;
      lastStatusIFU = CPU_PRE(__DOT__ifu__DOT__state);
      lastStatusIDU = CPU_PRE(__DOT__idu__DOT__state);
      lastStatusEXU = CPU_PRE(__DOT__exu__DOT__state);
      lastStatusMAU = CPU_PRE(__DOT__mau__DOT__state);
      lastStatusWBU = CPU_PRE(__DOT__wbu__DOT__state);
    }
    return 0;
  }
  CPU_state getCpu() {
    CPU_state cpu = {.gpr =
                         {
#define REG(x) CPU_PRE(__DOT__regFile__DOT__regs_##x)
                             REG(0),
                             REG(1),
                             REG(2),
                             REG(3),
                             REG(4),
                             REG(5),
                             REG(6),
                             REG(7),
                             REG(8),
                             REG(9),
                             REG(10),
                             REG(11),
                             REG(12),
                             REG(13),
                             REG(14),
                             REG(15),
#undef REG
                         },
                     .npc = CPU_PRE(__DOT__wbu__DOT__mauReq_npc),
                     .csrs =
                         {
#define CSR(x) CPU_PRE(__DOT__csrRegFile__DOT__##x)
                             .mtvec = CSR(mtvecReg),
                             .mepc = CSR(mepcReg),
                             .mstatus = CSR(mstatusReg),
                             .mcause = CSR(mcauseReg),
                             .mvendorid = CSR(mvendoridWire),
                             .marchid = CSR(marchidWire),
#undef CSR
                         }

    };
    return cpu;
  }
#ifdef USE_YSYXSOC
  bool sdramInited();
#endif
  bool isMret() { return CPU_PRE(__DOT___wbu_io_mret); }
  bool getMstatus() { return CPU_PRE(__DOT__csrRegFile__DOT__mstatusReg); }
  bool illegalInstruction() {
    return CPU_PRE(__DOT__wbu__DOT__mauReq_exception) &&
           CPU_PRE(__DOT__wbu__DOT__mauReq_exceptionNum) == 2;
  }
  uint32_t pc() { return CPU_PRE(__DOT__wbu__DOT__mauReq_pc); }
  uint32_t npc() { return CPU_PRE(__DOT__wbu__DOT__mauReq_npc); }
  uint32_t memAddr() const { return retiredMemAddr; }
  bool isMemAccess() const { return retiredMemAddrValid; }
  unsigned int currentInst() {
    return CPU_PRE(__DOT__wbu__DOT__mauReq_instruction);
  }
  static Npc &getInstance() {
    static Npc instance;
    return instance;
  }
  bool isTracing() const { return tracing; }
  void setTracing(bool on) {
    if (on == tracing)
      return;
    if (on) {
      tfp = new VerilatedVcdC();
      top->trace(tfp, 99);
      tfp->open("waveform.vcd");
    } else {
      tfp->close();
      delete tfp;
      tfp = nullptr;
    }
    tracing = on;
  }
  uint32_t gpio() {
#ifdef USE_YSYXSOC
    return top->externalPins_gpio_seg_7 << 28 |
           top->externalPins_gpio_seg_6 << 24 |
           top->externalPins_gpio_seg_5 << 20 |
           top->externalPins_gpio_seg_4 << 16 |
           top->externalPins_gpio_seg_3 << 12 |
           top->externalPins_gpio_seg_2 << 8 |
           top->externalPins_gpio_seg_1 << 4 | top->externalPins_gpio_seg_0;
#else
    return 0;
#endif
  }

  void nvboardInit() {
    bindNvBoard();
    nvboard_init();
    nvboardInited = true;
    nvboardUpdate();
  }
  void nvboardUpdate() {
    if (nvboardInited) {
      nvboard_update();
    }
  }
  AXI::AXIBundle *axi() {
    auto bundle = new AXI::AXIBundle{
#ifdef USE_YSYXSOC
#define BIND(x) .x = CPU_PRE(__DOT__io_master_##x)
#else
#define BIND(x) .x = top->rootp->io_master_##x
#endif
        BIND(awaddr), BIND(awvalid), BIND(awready), BIND(awid),    BIND(awlen),
        BIND(awsize), BIND(awburst), BIND(wdata),   BIND(wstrb),   BIND(wvalid),
        BIND(wready), BIND(wlast),   BIND(bvalid),  BIND(bready),  BIND(bresp),
        BIND(bid),    BIND(araddr),  BIND(arvalid), BIND(arready), BIND(arid),
        BIND(arlen),  BIND(arsize),  BIND(arburst), BIND(rdata),   BIND(rvalid),
        BIND(rready), BIND(rresp),   BIND(rlast),   BIND(rid),
#undef BIND
    };
    return bundle;
  }
  bool breakpoint() {
    return CPU_PRE(__DOT__wbu__DOT__mauReq_exception) &&
           CPU_PRE(__DOT__wbu__DOT__mauReq_exceptionNum) == 3;
  }
  void eval(uint8_t clock) {
    top->clock = clock;
    top->eval();
    main_time++;
    if (tfp) {
      tfp->dump(main_time);
      tfp->flush();
    }
  }
  void pos() {
    eval(0);
    eval(1);
    nvboardUpdate();
#ifndef USE_YSYXSOC
    AXI::getInstance().eval();
#endif
    counter.clock++;
    do { // icache命中统计
      static uint8_t lastStatus = 0;
      uint8_t currentStatus = CPU_PRE(__DOT__icache__DOT__state);
      enum Status {
        sIdle,
        sMissSendAR,
        sMissWaitR,
        sMissSendARObsolete,
        sMissWaitRObsolete,
        sResp,
      };
      if (lastStatus == Status::sIdle && currentStatus == Status::sResp) {
        counter.icache.hit++;
      }
      if (lastStatus != Status::sIdle && currentStatus == Status::sResp) {
        counter.icache.miss++;
      }
      counter.icache.missPenalty +=
          currentStatus == Status::sMissSendAR ||
          currentStatus == Status::sMissWaitR ||
          currentStatus == Status::sMissSendARObsolete ||
          currentStatus == Status::sMissWaitRObsolete;
      counter.icache.accessTime += currentStatus == Status::sResp;
      lastStatus = currentStatus;
    } while (0);
    do { // IFU取到指令
      static uint8_t lastStatus = 0;
      uint8_t currentStatus = CPU_PRE(__DOT__ifu__DOT__state);
      enum Status {
        sIdle,
        sWaitReq,
        sWaitResp,
        sSend2Idu,
      };
      if (lastStatus == Status::sWaitResp &&
          currentStatus != Status::sWaitResp) {
        counter.instructionFetch.done++;
      }
      if (currentStatus == sWaitReq || currentStatus == sWaitResp) {
        counter.instructionFetch.cost++;
      }
      lastStatus = currentStatus;
    } while (0);
    do { // EXU完成计算
      static uint8_t lastStatus = 0;
      uint8_t currentStatus = CPU_PRE(__DOT__exu__DOT__state);
      enum Status {
        s_wait_idu,
        s_calc_address,
        s_calc,
        s_send_ma,
      };
      if (lastStatus != Status::s_calc && currentStatus == Status::s_calc) {
        bool pcRedirect = CPU_PRE(__DOT__exu__DOT__io_pcRedirect_valid);
        bool isBranch = CPU_PRE(__DOT__exu__DOT__decodeInfo_isBranch);
        bool isJal = CPU_PRE(__DOT__exu__DOT__decodeInfo_isJal);
        bool isJalr = CPU_PRE(__DOT__exu__DOT__decodeInfo_isJalr);
        if (isBranch) {
          if (pcRedirect) {
            counter.branch.miss++;
          } else {
            counter.branch.hit++;
          }
        }
        if (isJal) {
          if (pcRedirect) {
            counter.jal.miss++;
          } else {
            counter.jal.hit++;
          }
        }
        if (isJalr) {
          if (pcRedirect) {
            counter.jalr.miss++;
          } else {
            counter.jalr.hit++;
          }
        }
      }
      if (lastStatus == Status::s_calc && currentStatus == Status::s_send_ma) {
        counter.exuDone++;
      }
      lastStatus = currentStatus;
    } while (0);
    do { // 单条流水线结束
      static uint8_t lastStatus = 0;
      static uint64_t lastTime = 0;
      uint8_t currentStatus = CPU_PRE(__DOT__wbu__DOT__state);
      enum Status {
        s_wait_mau,
        s_send_out,
      };
      if (lastStatus == Status::s_send_out &&
          currentStatus == Status::s_wait_mau) {
        counter.totalDone++;
        retiredMemAddr = pendingMemAddr;
        retiredMemAddrValid = pendingMemAddrValid;
        pendingMemAddrValid = false;
        uint32_t inst = CPU_PRE(__DOT__wbu__DOT__mauReq_instruction);
        if ((inst & pattern::jalMask) == pattern::jalPattern ||
            (inst & pattern::jalrMask) == pattern::jalrPattern ||
            (inst & pattern::branchMask) == pattern::branchPattern) {
          counter.control.done += 1;
          counter.control.cost += counter.clock - lastTime;
        }
        if ((inst & pattern::csrMask) == pattern::csrPattern) {
          counter.csr.done += 1;
          counter.csr.cost += counter.clock - lastTime;
        }
        if ((inst & pattern::loadMask) == pattern::loadPattern) {
          counter.load.done += 1;
          counter.load.cost += counter.clock - lastTime;
        }
        if ((inst & pattern::storeMask) == pattern::storePattern) {
          counter.store.done += 1;
          counter.store.cost += counter.clock - lastTime;
        }
        lastTime = counter.clock;
      }
      lastStatus = currentStatus;
    } while (0);
    do { // LSU读写数据
      static uint8_t lastStatus = 0;
      uint8_t currentStatus = CPU_PRE(__DOT__mau__DOT__state);
      enum Status {
        s_wait_exu,
        s_store,
        s_load_ar,
        s_load_r,
        s_send_out,
      };
      if (currentStatus == Status::s_load_ar ||
          currentStatus == Status::s_load_r) {
        counter.lsuLoadCost++;
      } else if (lastStatus == Status::s_load_r &&
                 currentStatus != Status::s_load_r) {
        counter.lsuLoad++;
#define MEM_ADDR CPU_PRE(__DOT__mau__DOT__exuInfo_memAddr)
        pendingMemAddr = MEM_ADDR;
        pendingMemAddrValid = true;
        if (mtrace && MEM_ADDR == 0xA203B010)
          Mtrace::getInstance().trace(
              MEM_ADDR, false, CPU_PRE(__DOT__mau__DOT__exuInfo_rdData),
              Mtrace::PIPE | Mtrace::TRACE_WR | Mtrace::TRACE_DATA);
      } else if (currentStatus == Status::s_store) {
        counter.lsuStoreCost++;
      } else if (lastStatus == Status::s_store &&
                 currentStatus != Status::s_store) {
        counter.lsuStore++;
        pendingMemAddr = MEM_ADDR;
        pendingMemAddrValid = true;
        if (mtrace && MEM_ADDR == 0xA203B010)
          Mtrace::getInstance().trace(
              MEM_ADDR, true, CPU_PRE(__DOT__mau__DOT__exuInfo_rdData),
              Mtrace::PIPE | Mtrace::TRACE_WR | Mtrace::TRACE_DATA);
#undef MEM_ADDR
      }
      lastStatus = currentStatus;
    } while (0);
  }
  void reset() {
    top->reset = 1;
    for (int i = 10; i; i--)
      pos();
    top->reset = 0;
    pos();
    counter = {};
  }
#ifdef USE_YSYXSOC
  bool rDelaying() {
    return 0;
    // return top->rootp
    //            ->ysyxSoCFull__DOT__asic__DOT__axi4delay_delayer__DOT__rState
    //            ==
    //        3;
  }
  bool wDelaying() {
    return 0;
    // return top->rootp
    //            ->ysyxSoCFull__DOT__asic__DOT__axi4delay_delayer__DOT__wState
    //            ==
    //        3;
  }
#endif
};
#undef CPU_PRE
