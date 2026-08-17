#pragma once
#include "Capstone.h"
#include "my_utils.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <fmt/format.h>
#include <stdexcept>
#include <vector>
class InstRingBuffer {
public:
  InstRingBuffer(size_t sz) : instr_buffer(), pos_begin(), pos_end(), cnt() {
    init(sz);
  }
  struct Item {
    uint32_t pc;
    uint32_t instr;
  };

  void init(size_t sz) {
    instr_buffer.resize(sz);
    pos_begin = 0;
    pos_end = sz - 1;
    cnt = 0;
  }
  void insert(uint32_t pc, uint32_t instr) {
    pos_end++;
    if (pos_end == instr_buffer.size())
      pos_end = 0;
    instr_buffer[pos_end] = {.pc = pc, .instr = instr};

    if (cnt < instr_buffer.size())
      cnt++;
    else {
      pos_begin++;
      if (pos_begin == instr_buffer.size())
        pos_begin = 0;
    }
  }

  Item last(uint32_t instr) {
    if (cnt == 0)
      log_and_throw<std::logic_error>(
          "Can not fetch last element of an empty RingBuffer");
    return instr_buffer[pos_end];
  }

  Item first(uint32_t instr) {
    if (cnt == 0)
      log_and_throw<std::logic_error>(
          "Can not fetch first element of an empty RingBuffer");
    return instr_buffer[pos_begin];
  }

  void display() {
    if (cnt == 0)
      fmt::println("No instruction recorded");
    else {
      fmt::println("Recent {} instructions", cnt);
      int pos = pos_begin;
      for (int i = 0; i < cnt; i++) {
        auto show = Capstone::capstone.disassemble(
            instr_buffer[pos].pc,
            reinterpret_cast<uint8_t *>(&instr_buffer[pos].instr), 4, false);
        if (i != cnt - 1)
          println("{:5}    {}", i, show);
        else
          println("{:5}--->{}", i, show);
        pos++;
        if (pos == instr_buffer.size())
          pos = 0;
      }
    }
  }

private:
  std::vector<Item> instr_buffer;
  int pos_begin, pos_end, cnt;
};

inline std::unique_ptr<InstRingBuffer> instRingBuffer;