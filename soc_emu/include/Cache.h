#pragma once

#include <algorithm>
#include <cstdint>
#include <print>
#include <sys/types.h>
#include <vector>
struct Cache {
  void init(int nr_words_per_line_2pow__, int nr_lines_2pow__) {
    nr_words_per_line_2pow = nr_words_per_line_2pow__;
    nr_lines_2pow = nr_lines_2pow__;
    cache.resize(1 << nr_lines_2pow);
    reset();
  }

  struct CacheLine {
    uint32_t tag;
    bool valid;
  };

  bool fetch(uint32_t addr) {
    if (!should_cache(addr))
      return false;
    const uint32_t index =
        (addr >> (2 + nr_words_per_line_2pow)) & ((1 << nr_lines_2pow) - 1);
    const uint32_t tag = addr >> (nr_lines_2pow + nr_words_per_line_2pow + 2);
    if (cache[index].valid && cache[index].tag == tag) {
      return true;
    }
    cache[index].valid = true;
    cache[index].tag = tag;
    return false;
  }

  void reset() { std::ranges::fill(cache, CacheLine{}); }
  void clear() {
    for (CacheLine &line : cache)
      line.valid = false;
  }
  bool should_cache(uint32_t addr) {
    return (addr >> 28) == 0x3 || (addr >> 28) == 0xa || (addr >> 28) == 0x8 ||
           (addr >> 28) == 0xb || (addr >> 24) == 0x0f;
  }

  std::vector<CacheLine> cache;
  int nr_words_per_line_2pow;
  int nr_lines_2pow;
};