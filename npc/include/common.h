
#ifndef __COMMON_H__
#define __COMMON_H__

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#include <assert.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef int32_t sword_t;
typedef uint32_t word_t;
typedef uint32_t vaddr_t;
typedef uint32_t paddr_t;

#define FMT_WORD "0x%08x"
#define FMT_PADDR "0x%08x"


/*YSYXSOC的外设地址*/
#define FLASH_SIZE 0xfffffff
#define FLASH_BASE 0x30000000

#define SDRAM_SIZE 0x1fffffff
#define SDRAM_BASE 0xa0000000

/*NPC的外设地址*/
#define CONFIG_MSIZE 0x0fffffff
#define CONFIG_MBASE 0x80000000


/*只是为了通过YSYXSOC实现的一些其他内存外设编译, 因为ysyxSoC文件夹中调用了相关函数*/
#define MROM_SIZE 0xfff
#define MROM_BASE 0x20000000

#define PSRAM_SIZE 0x1fffffff
#define PSRAM_BASE 0x80000000

#endif
