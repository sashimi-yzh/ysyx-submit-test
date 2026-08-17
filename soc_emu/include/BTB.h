#pragma once

#include "spdlog/spdlog.h"
#pragma once

#include <algorithm>
#include <cstdint>
#include <print>
#include <sys/types.h>
#include <vector>
struct BTB {
  void init(int nr_size_b_2pow__) {
    nr_size_b_2pow = nr_size_b_2pow__;
    btb_vector.resize(1 << nr_size_b_2pow);

    reset();
  }

  void reset() {
    btb_wptr = 0;
    btb_wptr = 0;
    miss_count = 0;
    std::ranges::fill(btb_vector, BTBItem{0, 0, 1});
  }

  struct BTBItem {
    uint32_t tag;
    uint32_t target;
    int sat_cnt;
  };
  void predict_branch(uint32_t pc, uint32_t target, bool jump) {
    auto find_pos = std::ranges::find_if(
        btb_vector, [pc](const BTBItem &item) { return item.tag == pc; });
    uint32_t predicted_target = pc + 4;
    if (find_pos != btb_vector.end()) {
      if (find_pos->sat_cnt >= 2)
        predicted_target = find_pos->target;

    } else {
      if (target < pc)
        btb_vector[btb_wptr] = {pc, target, 2};
      else
        btb_vector[btb_wptr] = {pc, target, 1};
      find_pos = btb_vector.begin() + btb_wptr;
      btb_wptr = (btb_wptr + 1) % btb_vector.size();
    }

    uint32_t real_target = pc + 4;
    if (jump) {
      real_target = target;
      find_pos->sat_cnt += 1;
      find_pos->sat_cnt = std::min(find_pos->sat_cnt, 3);
    } else {
      find_pos->sat_cnt -= 1;
      find_pos->sat_cnt = std::max(find_pos->sat_cnt, 0);
    }
    if (real_target != predicted_target) {
      miss_count++;
    } else {
      hit_count++;
    }
  }

  void predict_jal(uint32_t pc, uint32_t target) {
    auto find_pos = std::ranges::find_if(
        btb_vector, [pc](const BTBItem &item) { return item.tag == pc; });
    uint32_t predicted_target = pc + 4;
    if (find_pos != btb_vector.end()) {
      if (find_pos->sat_cnt >= 2)
        predicted_target = find_pos->target;
      find_pos->target = target;
    } else {
      btb_vector[btb_wptr] = {pc, target, 3};
      btb_wptr = (btb_wptr + 1) % btb_vector.size();
    }
    if (predicted_target != target)
      miss_count++;
    else
      hit_count++;
  }
  void predict_jalr(uint32_t pc, uint32_t target) {
    if (pc != target)
      miss_count++;
    else
      hit_count++;
  }
  unsigned long long getMissCount() { return miss_count; }
  unsigned long long getHitCount() { return hit_count; }

  unsigned long long miss_count;
  unsigned long long hit_count;
  int nr_size_b_2pow;
  std::vector<BTBItem> btb_vector;
  int btb_wptr;
};