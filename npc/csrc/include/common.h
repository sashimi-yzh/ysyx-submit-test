#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdlib>

#include <cassert>
#include <cstdint>

#include "config.h"

typedef MUXDEF(RV64, uint64_t, uint32_t) word_t;
typedef MUXDEF(RV64, int64_t, int32_t)  sword_t;

typedef word_t addr_t;

#define FMT_WORD MUXDEF(RV64, "0x%016x", "0x%08x")
#define FMT_ADDR MUXDEF(RV64, "0x%016x", "0x%08x")

#include "debug.h"

#endif
