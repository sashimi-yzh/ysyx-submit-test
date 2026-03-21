#include "isa.h"
#include "utils.h"
#include <locale.h>

#define CLK clock
#define RST reset

int cpu_inst_valid = 0;

IFDEF(CONFIG_DIFFTEST, void difftest_step(paddr_t pc, paddr_t npc));
void reg_display();

IFDEF(CONFIG_PERF_CAL, void perf_cal());

uint64_t get_time();
uint64_t g_timer = 0;
uint64_t g_cycle = 0;

extern TOP_NAME *top ;
extern VerilatedContext *contextp;

void difftest_skip_ref();

#ifdef CONFIG_USE_NVBOARD
#include <nvboard.h>
void nvboard_bind_all_pins(TOP_NAME *top);

void nvboard()
{
    nvboard_bind_all_pins(top);
    nvboard_init();
}
#endif

static bool g_print_step = false;
uint64_t g_nr_guest_inst = 0;

#define MAX_INST_TO_PRINT 1000
#define IRINGBUF_SIZE 256
#define IRINGBUF_LINE 20

LoopHistory_t loop_history[LOOP_HISTORY_SIZE];

#ifdef CONFIG_ITRACE
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

void check_watchpoint();

static void trace_and_difftest(Decode _this, paddr_t dnpc)
{
    if(g_print_step) {
        IFDEF(CONFIG_ITRACE, printf("%s\n", _this.logbuf));
    }
    IFDEF(CONFIG_TRACE, log_write("%s\n", _this.logbuf));
    IFDEF(CONFIG_ITRACE, iringbuf_trace(_this.logbuf));
    IFDEF(CONFIG_DIFFTEST, difftest_step(_this.pc, dnpc));
    IFDEF(CONFIG_WATCHPOINT, check_watchpoint());
}

#ifdef CONFIG_LOOP_DETECT
void detect_loop_pattern() { 
    static bool initialized = false;
    if(!initialized) {
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
            npc_state.state = NPC_STOP;
            break;
        }
    }
}
#endif

extern "C" void trap(int reg_data, int halt_pc)
{
    IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
    npc_state.halt_pc = halt_pc;
    npc_state.halt_ret = reg_data + 1;
    npc_state.state = NPC_END;
    // printf("Total cycles: %lu\n", extra_cpu.mcyclel + ((uint64_t)extra_cpu.mcycleh << 32));
}

#if WAVE_ENABLE == 1
    #if WAVE_FORMAT == 1
        extern VerilatedVcdC *tfp;
    #else
        extern VerilatedFstC *tfp;
    #endif
#endif

static void single_cycle()
{
    top->CLK = 0;
    top->eval();
#if WAVE_ENABLE == 1
    // printf("Dumping waveforms at time %lu...\n", contextp->time());
    contextp->timeInc(1);
    tfp->dump(contextp->time());
#endif
    top->CLK = 1;
    top->eval();
#if WAVE_ENABLE == 1
    // printf("Dumping waveforms at time %lu...\n", contextp->time());
    contextp->timeInc(1);
    tfp->dump(contextp->time());
#endif
}

void cpu_reset(int n)
{
    top->RST = 1;
    while (n-- > 0)
        single_cycle();
    top->RST = 0;
}


void statistic() {
    setlocale(LC_NUMERIC, "");
    PRINTF_BLUE("host time spent = %'lu us\n", g_timer);
    PRINTF_BLUE("total guest instructions = %'lu\n", g_nr_guest_inst);
    if (g_timer > 0) {
        PRINTF_BLUE("simulation frequency = %'lu inst/s\n", g_nr_guest_inst * 1000000 / g_timer);
    } else {
        PRINTF_BLUE("Finish running in less than 1 us and can not calculate the simulation frequency.\n");
    }
}

// void assert_fail_msg() {
//     IFDEF(CONFIG_ITRACE, iring_trace_printf());
//     reg_display();
//     statistic();
// }

static void exec_once()
{
    single_cycle();
    
    g_cycle++;
    
    if (!cpu_inst_valid) return;

    IFDEF(CONFIG_LOOP_DETECT, detect_loop_pattern());
    
#ifdef CONFIG_ITRACE
    char *p = s.logbuf;
    p += snprintf(p, sizeof(s.logbuf), "0x%08x: ", s.pc);
    int i;
    uint8_t *inst = (uint8_t *)&s.inst;

    int ilen = 4;
    for (i = ilen-1; i >= 0; i --)
        p += snprintf(p, sizeof(s.logbuf) - (p - s.logbuf), " %02x", inst[i]);

    int ilen_max = 4;
    int space_len = ilen_max - 4;
    space_len = space_len * 3 + 5;
    memset(p, ' ', space_len);
    p += space_len;

    // printf("%p, %d, %d, %p, %d\n", p, s.logbuf + sizeof(s.logbuf) - p, s.pc, (uint8_t *)&s.inst, ilen);

    void disassemble(char *str, int size, uint64_t pc, uint8_t *code, int nbyte);
    disassemble(p, s.logbuf + sizeof(s.logbuf) - p, s.pc, (uint8_t *)&s.inst, ilen);
#endif
}

static void execute(uint64_t n)
{
    while (n-- > 0) {
        exec_once();

        IFDEF(CONFIG_USE_NVBOARD, nvboard_update());

        if(!cpu_inst_valid) {
            n++;
            continue;
        }

        trace_and_difftest(s, cpu.pc);
        cpu_inst_valid = 0;
        g_nr_guest_inst++;
        if (npc_state.state != NPC_RUNNING) break;

    }

}

void cpu_exec(uint64_t n)
{
    g_print_step = (n <= MAX_INST_TO_PRINT);

    switch (npc_state.state)
    {
        case NPC_END: 
        case NPC_QUIT: 
        case NPC_ABORT:
            printf("Program execution has ended. To restart the program, exit NPC and run again\n");
            return ;
        default: 
            npc_state.state = NPC_RUNNING;
            break;
    }

    uint64_t timer_start = get_time();

    execute(n);

    uint64_t timer_end = get_time();
    g_timer += timer_end - timer_start;

    switch (npc_state.state)
    {
        case NPC_END:
            if (npc_state.halt_ret == 1) {
                PRINTF_GREEN("[=>>> HIT GOOD TRAP at pc = 0x%08x\n", npc_state.halt_pc);
                IFDEF(CONFIG_PERF_CAL, perf_cal());
            } else if (npc_state.halt_ret == 2) {
                PRINTF_RED("[=>>> HIT BAD TRAP at pc = 0x%08x\n", npc_state.halt_pc);
            }
            statistic();
            break;
        case NPC_ABORT:
            PRINTF_RED("[=>>> ABORT at pc = 0x%08x\n", npc_state.halt_pc);
            break;
        case NPC_QUIT:
            statistic();
            break;

        default:
            break;
    }
}
