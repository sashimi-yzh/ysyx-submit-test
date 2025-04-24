#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#if XLEN == 64
typedef uint64_t word_t;
typedef int64_t sword_t;
#define FMT_WORD "0x%016lx"
#else
typedef uint32_t word_t;
typedef int32_t sword_t;
#define FMT_WORD "0x%08x"
#endif

#ifdef RVE
#define NR_REGS 16
#else
#define NR_REGS 32
#endif

#define __concat(x, y) x ## y
#define concat(x, y) __concat(x, y)

#endif
