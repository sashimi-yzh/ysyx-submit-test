#include <bits/stdc++.h>
#include <config.hpp>
#include <fast_trace.hpp>
#include <format.hpp>
#include <ftrace.hpp>
#include <memory.hpp>
#include <npc.hpp>
#include <sdb.hpp>

int main(int argc, char *argv[]) {
  Verilated::commandArgs(argc, argv);
  Config &config = Config::getInstance();
  assert(config.load(argc, argv));
  Ftrace &ftrace = Ftrace::getInstance();
  ftrace.loadELF(config.elfFilename);
  Memory &mem = Memory::getInstance();
  mem.load(config.filename);
  Npc &npc = Npc::getInstance();
  AXI::getInstance().bind(npc.axi());
  npc.reset();
#ifdef USE_YSYXSOC
  npc.nvboardInit();
#endif

#ifdef FAST_ITRACE
  fast_itrace();
  return 0;
#elif defined(FAST_BTRACE)
  fast_btrace();
  return 0;
#else
  auto &sdb = Sdb::getInstance();
  while (sdb.wait()) {
  }
  // sdb.performance();
  if (!npc.done()) {
    print("HIT BAD TRAP", "!npc.done()");
    return 1;
  }
  if (!sdb.difftestOk()) {
    print("HIT BAD TRAP", "!sdb.difftestOk()");
    return 2;
  }
  if (npc.illegalInstruction()) {
    print("HIT BAD TRAP", "npc.illegalInstruction()");
    return 3;
  }
  if (npc.getCpu().gpr[10]) {
    print("HIT BAD TRAP", "npc.getCpu().gpr[10]");
    return npc.getCpu().gpr[10];
  }
  print("HIT GOOD TRAP");
  return 0;
#endif
}
