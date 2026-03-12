/***************************************************************************************
 * Copyright (c) 2014-2024 Zihao Yu, Nanjing University
 *
 * NEMU is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 *
 * See the Mulan PSL v2 for more details.
 ***************************************************************************************/

#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/difftest.h>
#include <locale.h>
#include "../monitor/sdb/sdb.h" 

/* The assembly code of instructions executed is only output to the screen
 * when the number of instructions executed is less than this value.
 * This is useful when you use the `si' command.
 * You can modify this value as you want.
 */
#define MAX_INST_TO_PRINT 10
#define IRINGBUF_SIZE 256
#define IRINGBUF_LINE 20

CPU_state cpu = { .csr.mstatus = 0x1800 };
uint64_t g_nr_guest_inst = 0;
static uint64_t g_timer = 0; // unit: us
static bool g_print_step = false;

LoopHistory_t loop_history[LOOP_HISTORY_SIZE];

void device_update();


#ifdef CONFIG_ITRACE_COND
static char iringbuf[IRINGBUF_LINE][IRINGBUF_SIZE];
static int nr_inst = 0;

static void iringbuf_trace(char *logbuf) {
    if(nr_inst < IRINGBUF_LINE) {
        strncpy(iringbuf[nr_inst], logbuf, IRINGBUF_SIZE); 
        nr_inst++;     
    } else {
        for(int i=0; i<IRINGBUF_LINE-1; i++) {
            strncpy(iringbuf[i], iringbuf[i+1], IRINGBUF_SIZE);
        }
        strncpy(iringbuf[IRINGBUF_LINE-1], logbuf, IRINGBUF_SIZE);
    }
}

void iring_trace_printf() {
    if(nr_inst < IRINGBUF_LINE) {
        for(int i=0; i<nr_inst; i++) {
            printf("%s\n", iringbuf[i]);
        }
    } else {
        for(int i=0; i<IRINGBUF_LINE; i++) {
            printf("%s\n", iringbuf[i]);
        }
    }
}
#endif

static void trace_and_difftest(Decode *_this, vaddr_t dnpc) {
#ifdef CONFIG_ITRACE_COND
    if (ITRACE_COND) { log_write("%s\n", _this->logbuf); }
    iringbuf_trace(_this->logbuf);
#endif
    if (g_print_step) { IFDEF(CONFIG_ITRACE, puts(_this->logbuf)); }
    IFDEF(CONFIG_DIFFTEST, difftest_step(_this->pc, dnpc));
#ifdef CONFIG_WATCHPOINT
    check_watchpoint();
#endif
}

#ifdef CONFIG_LOOP_DETECT
void detect_loop_pattern() { 
    static bool initialized = false;
    if(!initialized) {
        printf("Loop detection initialized.\n");
        for(int i=0; i<LOOP_HISTORY_SIZE; i++) {
            loop_history[i].pc = 0;
            loop_history[i].count = 0;
        }
        initialized = true;
    }

    bool found = false;
    for(int i=0; i<LOOP_HISTORY_SIZE; i++) {
        if(loop_history[i].pc == cpu.pc) {
            loop_history[i].count++;
            found = true;
            break;
        }
    }

    if(!found) {
        int min_index = 0;
        uint32_t min_count = loop_history[0].count;
        for(int i=1; i<LOOP_HISTORY_SIZE; i++) {
            if (loop_history[i].count < min_count) {
                min_count = loop_history[i].count;
                min_index = i;
            }
        }
        loop_history[min_index].pc = cpu.pc;
        loop_history[min_index].count = 1;
    }

    for(int i = 0; i < LOOP_HISTORY_SIZE; i++) {
        if(loop_history[i].count > MAX_LOOP_COUNT) {
            printf("Detected loop pattern: PC 0x%08x executed over %u times\n", 
                    loop_history[i].pc, MAX_LOOP_COUNT);
            nemu_state.state = NEMU_STOP;
            break;
        }
    }
}
#endif

static void exec_once(Decode *s, vaddr_t pc) {
    // printf("exec_once at pc: 0x%08x\n", pc);
    s->pc = pc;
    s->snpc = pc;
    isa_exec_once(s);
    IFDEF(CONFIG_LOOP_DETECT, detect_loop_pattern());
    cpu.pc = s->dnpc;
#ifdef CONFIG_ITRACE

    // static FILE *itrace_fp = NULL;
        
    // if (itrace_fp == NULL) {
    //     itrace_fp = fopen("/home/hhh/Templates/icachesim.bin", "wb");
    //     if (itrace_fp == NULL) {
    //         perror("Failed to open itrace file");
    //     }
    // }
    
    // if (itrace_fp != NULL) {
    //     // 写入PC值（十六进制）
    //     fwrite(&cpu.pc, sizeof(vaddr_t), 1, itrace_fp);
        
    //     // 定期flush防止数据丢失
    //     static int count = 0;
    //     if (++count % 10000 == 0) {
    //         fflush(itrace_fp);
    //     }
    // }

    char *p = s->logbuf;
    p += snprintf(p, sizeof(s->logbuf), FMT_WORD ":", s->pc);
    int ilen = s->snpc - s->pc;
    int i;
    uint8_t *inst = (uint8_t *)&s->isa.inst;
#ifdef CONFIG_ISA_x86
    for (i = 0; i < ilen; i ++) {
#else
    for (i = ilen - 1; i >= 0; i --) {
#endif
        p += snprintf(p, 4, " %02x", inst[i]);
    }
    int ilen_max = MUXDEF(CONFIG_ISA_x86, 8, 4);
    int space_len = ilen_max - ilen;
    if (space_len < 0) space_len = 0;
    space_len = space_len * 3 + 1;
    memset(p, ' ', space_len);
    p += space_len;

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p, s->logbuf + sizeof(s->logbuf) - p,
                MUXDEF(CONFIG_ISA_x86, s->snpc, s->pc), (uint8_t *)&s->isa.inst, ilen);
#endif
}

// uint64_t total_cycle = 0;

static void execute(uint64_t n) {
    Decode s;
    for (;n > 0; n --) {
        // printf("exec: 0x%08x\n", cpu.pc);
        exec_once(&s, cpu.pc);
        g_nr_guest_inst ++;
        // total_cycle++;
        trace_and_difftest(&s, cpu.pc);
        if (nemu_state.state != NEMU_RUNNING) break;
        IFDEF(CONFIG_DEVICE, device_update());
    }
}

static void statistic() {
    IFNDEF(CONFIG_TARGET_AM, setlocale(LC_NUMERIC, ""));
#define NUMBERIC_FMT MUXDEF(CONFIG_TARGET_AM, "%", "%'") PRIu64
    Log("host time spent = " NUMBERIC_FMT " us", g_timer);
    Log("total guest instructions = " NUMBERIC_FMT, g_nr_guest_inst);
    if (g_timer > 0) Log("simulation frequency = " NUMBERIC_FMT " inst/s", g_nr_guest_inst * 1000000 / g_timer);
    else Log("Finish running in less than 1 us and can not calculate the simulation frequency");
}

void assert_fail_msg() {
    IFDEF(CONFIG_ITRACE, iring_trace_printf());
    isa_reg_display();
    statistic();
}

/* Simulate how the CPU works. */
void cpu_exec(uint64_t n) {
    g_print_step = (n < MAX_INST_TO_PRINT);
    switch (nemu_state.state) {
        case NEMU_END: case NEMU_ABORT: case NEMU_QUIT:
            printf("Program execution has ended. To restart the program, exit NEMU and run again.\n");
            return;
        default: nemu_state.state = NEMU_RUNNING;
    }

    uint64_t timer_start = get_time();

    execute(n);

    // printf("Total cycle: %lu\n", total_cycle);

    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;

    switch (nemu_state.state) {
        case NEMU_RUNNING: nemu_state.state = NEMU_STOP; break;

        case NEMU_END: case NEMU_ABORT:
                           Log("nemu: %s at pc = " FMT_WORD,
                                   (nemu_state.state == NEMU_ABORT ? ANSI_FMT("ABORT", ANSI_FG_RED) :
                                    (nemu_state.halt_ret == 0 ? ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN) :
                                     ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED))),
                                   nemu_state.halt_pc);
                           // fall through
        case NEMU_QUIT: statistic();
    }
}


