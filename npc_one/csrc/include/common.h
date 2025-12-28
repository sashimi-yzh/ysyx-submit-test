#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include <macro.h>
#include <config.h>

typedef uint32_t   word_t;
typedef  int32_t  sword_t;
#define FMT_WORD "0x%08x"

typedef   word_t vaddr_t;
typedef uint32_t paddr_t;
#define FMT_PADDR "0x%08x"
typedef uint16_t ioaddr_t;

#endif

