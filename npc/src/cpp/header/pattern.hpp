#pragma once
#include <bits/stdc++.h>
namespace pattern {
inline uint32_t jalMask = 0b0000000000000001111111;
inline uint32_t jalPattern = 0b0000000000000001101111;
inline uint32_t jalrMask = 0b0000000111000001111111;
inline uint32_t jalrPattern = 0b0000000000000001100111;
inline uint32_t branchMask = 0b0000000000000001111111;
inline uint32_t branchPattern = 0b0000000000000001100011;
inline uint32_t csrMask = 0b0000000000000001111111;
inline uint32_t csrPattern = 0b0000000000000001110011;
inline uint32_t loadMask = 0b0000000000000001111111;
inline uint32_t loadPattern = 0b0000000000000000000011;
inline uint32_t storeMask = 0b0000000000000001111111;
inline uint32_t storePattern = 0b0000000000000000100011;
} // namespace pattern
