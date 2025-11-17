#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <macro.h>
#include <debug.h>
#include <generated/autoconf.h>

typedef uint32_t word_t;
typedef word_t vaddr_t;
typedef uint32_t paddr_t;
typedef uint16_t ioaddr_t;

#define FMT_WORD  "0x%08" PRIx32
#define FMT_PADDR MUXDEF(PMEM64, "0x%016" PRIx64, "0x%08" PRIx32)


#endif