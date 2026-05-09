#ifndef __PARAMETER_H__
#define __PARAMETER_H__


#include <stdint.h>
#include <stdlib.h>

#define BLOCK_SIZE 4
#define CACHE_SIZE 16


#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog

#endif