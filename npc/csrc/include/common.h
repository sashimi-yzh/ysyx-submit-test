#ifndef __COMMON_H__
#define __COMMON_H__

#include <cstdint>
#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#include <macro.h>

#include <assert.h>
#include <stdlib.h>

#include <sim_verilator.h>

#include <sim_verilator.h>

void sim_init();
void sim_exit();
bool step_and_dump_once();
bool step_and_dump_once();

typedef uint32_t word_t;
typedef word_t vaddr_t;
typedef word_t paddr_t;
#define FMT_WORD "0x%.8x"
#define FMT_PADDR "0x%.8x"

/** == memory range ================================== */
#define CONFIG_MROM_BASE 0x20000000
#define CONFIG_MROM_SIZE 0x1000
#define CONFIG_PSRAM_BASE 0x80000000
#define CONFIG_PSRAM_SIZE 0x20000000

#define CONFIG_PMEM_BASE 0x80000000
#define CONFIG_PMEM_SIZE 0x10000000
#define CONFIG_FLASH_BASE 0x30000000
#define CONFIG_FLASH_SIZE 0x10000000
#define CONFIG_SDRAM_BASE 0xa0000000
#define CONFIG_SDRAM_SIZE 0x4000000

#define CONFIG_TARGET_NATIVE_ELF 1
#define CONFIG_RT_CHECK 1

/** == self define =================================== */
#define CONFIG_TRACE_INST_NUM 0
#define CONFIG_FST 1
// #define CONFIG_PRINT_CPU 1

#ifndef ysyx_23060170_NPC
    #define CONFIG_NVBOARD 1
#endif


/** == useful ======================================== */
// #define CONFIG_DEBUG 1
    #ifdef CONFIG_DEBUG
        #define CONFIG_DIFFTEST 1
        #define CONFIG_WAVE 1
        #define CONFIG_ITRACE 1
        #define CONFIG_ITRACE_COND "true"
    #endif

#define CONFIG_SDB 1 // turn-off all trace

    #define CONFIG_TRACE 1
        #define CONFIG_TRACE_START 0
        #define CONFIG_TRACE_END 1000000000000

        // #define CONFIG_WATCHPOINT 1
        // #define CONFIG_PCTRACE 1
        // #define CONFIG_ICACHE_MISS_PCTRACE 1
        // #define CONFIG_IRINGBUF 1
        // #define CONFIG_MTRACE 1
        // #define CONFIG_MTRACE_START 0x0
        // #define CONFIG_MTRACE_END 0xffffffff
        // #define CONFIG_FTRACE 1
        // #define CONFIG_DTRACE 1
        // #define CONFIG_ETRACE 1

#include <debug.h>

#endif
