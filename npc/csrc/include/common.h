#ifndef __COMMOM_H__
#define __COMMOM_H__
#include <macro.h>

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include <assert.h>
#include <stdlib.h>

#if CONFIG_MBASE + CONFIG_MSIZE > 0x100000000ul
    #define PMEM64 1
#endif

typedef uint32_t word_t;
#define FMT_WORD "0x%08x"

typedef word_t vaddr_t;
typedef MUXDEF(PMEM64, uint64_t, uint32_t) paddr_t;
#define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)
typedef uint16_t ioaddr_t;

#include <debug.h>

#endif