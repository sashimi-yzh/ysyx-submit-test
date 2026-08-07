#pragma once
#include <format.hpp>
#include <fstream>

class Itrace {
  std::ofstream ofsTxt;
  std::ofstream ofsBin;

  Itrace()
      : ofsTxt("./build/itrace.txt"),
        ofsBin("./build/itrace.bin", std::ios::binary) {}

public:
  enum FLAGS { DUMMY = 0x0, TEXT = 0x1 };
  static Itrace &getInstance() {
    static Itrace instance;
    return instance;
  }

  void trace(uint32_t inst, FLAGS flag = FLAGS::DUMMY) {
    if (flag & FLAGS::TEXT)
      ofsTxt << hex(inst) << std::endl;
    char buf[4] = {
        static_cast<char>(inst & 0xff),
        static_cast<char>((inst >> 8) & 0xff),
        static_cast<char>((inst >> 16) & 0xff),
        static_cast<char>((inst >> 24) & 0xff),
    };
    ofsBin.write(buf, sizeof(buf));
  }
};
