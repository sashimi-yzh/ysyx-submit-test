#pragma once
#include <format.hpp>
#include <fstream>
#include <status_pipe.hpp>

class Mtrace {
  std::ofstream ofsBin;
  StatusPipe pipe{"/tmp/npc_mtrace"};

  Mtrace() : ofsBin("./build/mtrace.bin", std::ios::binary) {}

public:
  enum FLAGS {
    DUMMY = 0x0,
    PIPE = 0x1,
    BIN = 0x2,
    TRACE_WR = 0x4,
    TRACE_DATA = 0x8
  };

  static Mtrace &getInstance() {
    static Mtrace instance;
    return instance;
  }

  void trace(uint32_t addr, bool write, uint32_t data,
             uint32_t flag = FLAGS::DUMMY) {
    if (flag == FLAGS::DUMMY)
      return;
    if (flag & BIN) {
      static char buf[4];
      buf[0] = static_cast<char>(addr & 0xff);
      buf[1] = static_cast<char>((addr >> 8) & 0xff);
      buf[2] = static_cast<char>((addr >> 16) & 0xff);
      buf[3] = static_cast<char>((addr >> 24) & 0xff);
      ofsBin.write(buf, sizeof(buf));
      if (flag & TRACE_DATA) {
        buf[0] = static_cast<char>(data & 0xff);
        buf[1] = static_cast<char>((data >> 8) & 0xff);
        buf[2] = static_cast<char>((data >> 16) & 0xff);
        buf[3] = static_cast<char>((data >> 24) & 0xff);
        ofsBin.write(buf, sizeof(buf));
      }
      if (flag & TRACE_WR) {
        buf[0] = write;
        ofsBin.write(buf, 1);
      }
    }

    if (flag & PIPE) {
      pipe.write([=]() -> std::string {
        std::string line = hex(addr);
        if (flag & TRACE_WR)
          line += ' ' + (std::string)(write ? "W" : "R");
        if (flag & TRACE_DATA)
          line += ' ' + hex(data);
        return line + '\n';
      });
    }
  }
};
