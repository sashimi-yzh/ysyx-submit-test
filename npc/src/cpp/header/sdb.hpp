#pragma once
#include <SDL.h>
#include <atomic>
#include <bits/stdc++.h>
#include <config.hpp>
#include <difftest.hpp>
#include <dlfcn.h>
#include <ftrace.hpp>
#include <itrace.hpp>
#include <npc.hpp>
#include <poll.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <status_pipe.hpp>
#include <termios.h>
class Sdb {
private:
  Npc &npc;
  Ftrace &ftrace;
  bool difftestOn;
  bool batch;
  Difftest *ref;
  std::map<std::string, bool (Sdb::*)(const std::string &)> commandMap;
  static inline std::atomic<uint8_t> interrupted = 0;
  static inline struct termios origTermios;
  static inline bool termSaved = false;
  StatusPipe pcStatus{"/tmp/npc_pc_status"};

  static void sigintHandler(int) { interrupted = true; }

  static void restoreTerm() {
    if (termSaved)
      tcsetattr(STDIN_FILENO, TCSANOW, &origTermios);
  }

  bool runSteps(uint64_t step, bool isC) {
    for (uint64_t i = 1; (isC || i <= step) && !npc.done() &&
                         !npc.coreTimeOut() && !interrupted;) {
      npc.pos();
      if (!npc.nextDone())
        continue;
      i++;
      npc.pos();
      if (npc.illegalInstruction()) {
        print("Invalid instruction pc:", hex(npc.pc()));
        print("Invalid instruction is:", hex(npc.currentInst()));
        return 0;
      }
      pcStatus.write([&]() -> std::string {
        std::ostringstream oss;
        if (!isC)
          oss << "[" << i << "/" << step << "] ";
        oss << "pc:" << hex(npc.pc());
        if (auto hit = ftrace.hit(npc.pc())) {
          oss << " " << hit->name;
          auto printProcessIfHit = [&](std::string name, std::string start,
                                       std::string end) {
            auto &symbols = ftrace.getSymbols();
            if (symbols.count(start) && symbols.count(end)) {
              auto _start = symbols.find(start)->second;
              auto _end = symbols.find(end)->second;
              auto t0 = npc.getCpu().gpr[5];
              if (_start <= t0 && t0 < _end)
                oss << " " << name << "[" << t0 - _start << "/" << _end - _start
                    << "]";
            }
          };
          if (hit->name == "_fsbl") {
            printProcessIfHit("entry.ssbl", "_ssbl_start", "_essbl");
          } else if (hit->name == "_ssbl") {
            printProcessIfHit(".text", "_text_start", "_etext");
            printProcessIfHit(".data", "_data_start", "_edata");
            printProcessIfHit(".rodata", "_rodata_start", "_erodata");
            printProcessIfHit(".data_extra", "_data_extra_start",
                              "_edata_extra");
            printProcessIfHit(".bss_extra", "_bss_extra_start", "_ebss_extra");
          }
        }
        return "\033[2K\r" + oss.str();
      });
      if (difftestOn) {
        auto isPeripheralAddr = [](uint32_t addr) -> bool {
          // UART
          if (addr >= 0x10000000 && addr <= 0x10000FFF)
            return true;
          // SPI
          if (addr >= 0x10001000 && addr <= 0x10001FFF)
            return true;
          // GPIO
          if (addr >= 0x10002000 && addr <= 0x10002FFF)
            return true;
          // Keyboard
          if (addr >= 0x10011000 && addr <= 0x10011FFF)
            return true;
          // VGA
          if (addr >= 0x21000000 && addr <= 0x21FFFFFF)
            return true;
          // Clint
          if (addr >= 0x02000000 && addr <= 0x0200ffff)
            return true;
          return false;
        };
        if (npc.isMemAccess() && isPeripheralAddr(npc.memAddr())) {
          ref->syncReg(npc.getCpu());
        } else {
          ref->exec(1);
          if (!difftestOk()) {
            std::cout << std::endl;
            print(format::red, "Current instruction pc:", hex(npc.pc()),
                  format::clear);
            print(format::red,
                  "Current instruction is:", hex(npc.currentInst()),
                  format::clear);
            npc.getCpu().compare(ref->reg());
            return 0;
          }
        }
      }
    }
    // if (npc.done()) {
    //   print("\nexit code:", npc.getCpu().gpr[10]);
    // }
    return 1;
  }
  static void initTerm() {
    if (tcgetattr(STDIN_FILENO, &origTermios) == 0) {
      termSaved = true;
      struct termios raw = origTermios;
      raw.c_lflag &= ~ECHOCTL;
      tcsetattr(STDIN_FILENO, TCSANOW, &raw);
      std::atexit(restoreTerm);
    }
  }
  Sdb();
  bool cmdSi(const std::string &args) {
    uint64_t step = 0;
    if (!args.empty()) {
      try {
        step = std::stoull(args);
      } catch (...) {
        std::cout << "usage: si <n>" << std::endl;
        return 1;
      }
    }
    if (step == 0) {
      std::cout << "usage: si <n>" << std::endl;
      return 1;
    }
    bool ret = runSteps(step, false);
    std::cout << std::endl;
    return ret;
  }
  bool cmdDifftest(const std::string &args) {
    std::string op;
    std::istringstream ss(args);
    ss >> op;
    if (op == "on") {
      ref->loadMemory();
      difftestOn = true;
      std::cout << "difftest: on" << std::endl;
    } else if (op == "off") {
      difftestOn = false;
      std::cout << "difftest: off" << std::endl;
    } else {
      std::cout << "current: " << (difftestOn ? "on" : "off") << std::endl;
    }
    return 1;
  }
  bool cmdPerformance(const std::string &args) {
    performance();
    return 1;
  }
  bool cmdBatch(const std::string &args) {
    std::stringstream ss(args);
    std::string op;
    ss >> op;
    if (op == "on") {
      batch = true;
    } else if (op == "off") {
      batch = false;
    } else {
      std::cout << "current: " << (batch ? "on" : "off") << std::endl;
      std::cout << "usage: batch [on|off]" << std::endl;
    }
    return 1;
  }

  bool cmdWtrace(const std::string &args) {
    std::stringstream ss(args);
    std::string op;
    ss >> op;
    if (op == "on") {
      npc.setTracing(true);
    } else if (op == "off") {
      npc.setTracing(false);

    } else {
      std::cout << "current: " << (npc.isTracing() ? "on" : "off") << std::endl;
      std::cout << "usage: wtrace [on|off]" << std::endl;
    }
    return 1;
  }

  bool cmdFtrace(const std::string &args) {
    ftrace.display();
    return 1;
  }
  bool cmdC(const std::string &args) {
    (void)args;
    interrupted = false;
    bool ret = runSteps(0, true);
    std::cout << std::endl;
    if (batch && !interrupted)
      return 0;
    return ret;
  }

  bool cmdPC(const std::string &args) {
    (void)args;
    std::cout << hex(npc.pc()) << std::endl;
    return 1;
  }

public:
  static bool isInterrupted() { return interrupted; }
  bool difftestOk() { return !difftestOn || npc.getCpu() == ref->reg(); }

  static Sdb &getInstance() {
    static Sdb sdb;
    return sdb;
  }

  bool wait() {
    interrupted = 0;
    if (static bool executed = false;
        Config::getInstance().batch == "true" && !executed) {
      batch = true;
      executed = true;
      return cmdC("");
    }
    rl_signal_event_hook = []() -> int {
      interrupted = 1;
      rl_done = 1;
      return 0;
    };
    rl_event_hook = []() -> int {
      SDL_PumpEvents();
      if (interrupted) {
        rl_done = 1;
        return 1;
      }
      return 0;
    };
    std::string line = readline("\\> ");
    rl_event_hook = nullptr;
    rl_signal_event_hook = nullptr;

    if (interrupted) {
      std::cout << "[quit]" << std::endl;
      return 0;
    }
    add_history(line.c_str());
    std::istringstream iss(line);
    std::string command, args;
    iss >> command;
    std::getline(iss, args);
    auto it = commandMap.find(command);
    if (it != commandMap.end()) {
      bool ret = (this->*(it->second))(args);
      if (interrupted == 2) {
        std::cout << "[quit]" << std::endl;
        return 0;
      }
      if (interrupted == 1) {
        std::cout << "[interrupted]" << std::endl;
        std::cin.clear();
      }
      return ret;
    }
    std::cout << "command error" << std::endl;
    return 1;
  }
  void performance() {
    auto &c = npc.getCounter();
    auto printRow = [](const char *name, uint64_t done, uint64_t cost,
                       std::string ipc) {
      print(format::blue, name, format::red, done, format::blue, cost,
            format::red, ipc, format::clear);
    };
    print(format::greenBG, format::blue, "inst_type", format::red, "inst",
          format::blue, "clock", format::red, "ipc", format::clear);
    printRow("total", c.totalDone, c.clock, c.ipc());
    printRow("control", c.control.done, c.control.cost, c.control.ipc());
    printRow("csr", c.csr.done, c.csr.cost, c.csr.ipc());
    printRow("load", c.load.done, c.load.cost, c.load.ipc());
    printRow("store", c.store.done, c.store.cost, c.store.ipc());
    // module
    print(format::greenBG, format::blue, "module", format::red, "inst",
          format::blue, "clock", format::clear);
    print(format::blue, "ifu fetch", format::red, c.instructionFetch.done,
          format::blue, c.instructionFetch.cost, format::clear);
    print(format::blue, "mau loaded", format::red, c.lsuLoad, format::blue,
          c.lsuLoadCost, format::clear);
    print(format::blue, "mau stored", format::red, c.lsuStore, format::blue,
          c.lsuStoreCost, format::clear);
    print(format::blue, "exu calculated", format::red, c.exuDone, format::blue,
          ' ', format::clear);
    // icache
    print(format::greenBG, format::blue, "icache", format::red, "hit",
          format::blue, "miss", format::red, "accessTime", format::blue,
          "missPenalty", format::red, "AMAT", format::clear);
    print(format::blue, "icache", format::red, c.icache.hit, format::blue,
          c.icache.miss, format::red, c.icache.accessTime, format::blue,
          c.icache.missPenalty, format::red, c.icache.amat(), format::clear);
    // branch predictor
    print(format::greenBG, format::blue, "branch", format::red, "hit",
          format::blue, "miss", format::red, "hit_rate", format::clear);
    print(format::blue, "branch", format::red, c.branch.hit, format::blue,
          c.branch.miss, format::red, c.branch.hitRate(), format::clear);
    print(format::blue, "jal", format::red, c.jal.hit, format::blue, c.jal.miss,
          format::red, c.jal.hitRate(), format::clear);
    print(format::blue, "jalr", format::red, c.jalr.hit, format::blue,
          c.jalr.miss, format::red, c.jalr.hitRate(), format::clear);
    print(
        format::blue, "total", format::red,
        c.branch.hit + c.jal.hit + c.jalr.hit, format::blue,
        c.branch.miss + c.jal.miss + c.jalr.miss, format::red,
        [&](int precision = 3) -> std::string {
          uint64_t hit = c.branch.hit + c.jal.hit + c.jalr.hit;
          uint64_t miss = c.branch.miss + c.jal.miss + c.jalr.miss;
          if (!(hit + miss))
            return "0";
          std::ostringstream oss;
          oss << std::fixed << std::setprecision(precision);
          double p = double(hit) / (hit + miss);
          oss << p;
          return oss.str();
        }(),
        format::clear);
  }
};
