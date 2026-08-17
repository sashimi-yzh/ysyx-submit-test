#pragma once
#include "my_utils.h"
#include <concepts>
#include <cstdint>
#include <string_view>

struct Pattern {
  uint32_t mask;
  uint32_t pattern;

  template <class T>
    requires std::convertible_to<const T &, std::string_view>
  consteval Pattern(const T &s) : mask(0), pattern(0) {
    const std::string_view str(s);
    for (auto iter = str.begin(); iter != str.end(); iter++) {
      if (*iter == '0') {
        mask = (mask << 1) | 1;
        pattern = (pattern << 1);
      } else if (*iter == '1') {
        mask = (mask << 1) | 1;
        pattern = (pattern << 1) | 1;
      } else if (*iter == '?') {
        mask = (mask << 1);
        pattern = (pattern << 1);
      }
    }
  }

  bool verify(uint32_t inst) { return (mask & inst) == pattern; }
};

struct Decoded {
  uint32_t src1_id;
  uint32_t src2_id;
  uint32_t dst_id;
  uint32_t imm_I;
  uint32_t imm_U;
  uint32_t imm_J;
  uint32_t imm_S;
  uint32_t imm_B;
};
inline Decoded decode(uint32_t inst) {
  uint32_t imm20_j = bits<31>(inst), imm10_1_j = bits<30, 21>(inst);
  uint32_t imm11_j = bits<20>(inst), imm19_12_j = bits<19, 12>(inst);
  uint32_t _21bitimm_j =
      (imm20_j << 20) | (imm19_12_j << 12) | (imm11_j << 11) | (imm10_1_j << 1);

  uint32_t imm12_b = bits<31>(inst), imm10_5_b = bits<30, 25>(inst);
  uint32_t imm11_b = bits<7>(inst), imm4_1_b = bits<11, 8>(inst);
  uint32_t _13bitimm_b =
      (imm12_b << 12) | (imm11_b << 11) | (imm10_5_b << 5) | (imm4_1_b << 1);

  return {.src1_id = bits<19, 15>(inst),
          .src2_id = bits<24, 20>(inst),
          .dst_id = bits<11, 7>(inst),
          .imm_I = sign_ext<12>(bits<31, 20>(inst)),
          .imm_U = inst & ~0xFFF,
          .imm_J = sign_ext<21>(_21bitimm_j),
          .imm_S = (sign_ext<7>(bits<31, 25>(inst)) << 5) | bits<11, 7>(inst),
          .imm_B = sign_ext<13>(_13bitimm_b)};
}