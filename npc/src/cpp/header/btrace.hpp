#pragma once
#include <format.hpp>
#include <fstream>

class Btrace {
  std::ofstream ofsTxt;
  std::ofstream ofsBin;

  Btrace()
      : ofsTxt("./build/btrace.txt"),
        ofsBin("./build/btrace.bin", std::ios::binary) {}

public:
  enum FLAGS { DUMMY = 0x0, TEXT = 0x1 };
  static Btrace &getInstance() {
    static Btrace instance;
    return instance;
  }

  void trace(uint32_t addr, uint32_t inst, FLAGS flag = FLAGS::DUMMY) {
    if (flag & FLAGS::TEXT)
      ofsTxt << hex(addr) << ' ' << hex(inst) << std::endl;
    char buf[8] = {
        static_cast<char>(addr & 0xff),
        static_cast<char>((addr >> 8) & 0xff),
        static_cast<char>((addr >> 16) & 0xff),
        static_cast<char>((addr >> 24) & 0xff),
        static_cast<char>(inst & 0xff),
        static_cast<char>((inst >> 8) & 0xff),
        static_cast<char>((inst >> 16) & 0xff),
        static_cast<char>((inst >> 24) & 0xff),
    };
    ofsBin.write(buf, sizeof(buf));
  }
};
