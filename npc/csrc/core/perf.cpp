/***************************************************************************************
* NPC Performance Counter
* 性能计数器实现: 汇总 RTL 通过 DPI-C 上报的性能事件, 并在仿真结束时打印报告.
***************************************************************************************/

#include "core/perf.h"
#include "core/npc.h"
#include "../utils/log.h"

#include <cinttypes>
#include <cstdarg>
#include <cerrno>
#include <cstdio>
#include <cstring>

static uint64_t perf_count[PERF_EVENT_COUNT] = {};
static FILE *perf_fp = NULL;

void perf_log_open(const char *path) {
    if (perf_fp != NULL || path == NULL || path[0] == '\0') return;

    perf_fp = fopen(path, "w");
    if (perf_fp == NULL) {
        fprintf(stderr, "Cannot open perf log '%s': %s\n", path, strerror(errno));
        return;
    }
    setvbuf(perf_fp, NULL, _IOLBF, 0);
    fprintf(perf_fp, "# NPC performance log\n");
#ifndef ENABLE_PERF
    fprintf(perf_fp, "PERF is disabled at compile time (PERF=0)\n");
#endif
    fflush(perf_fp);
}

void perf_log_close() {
    if (perf_fp != NULL) {
        fflush(perf_fp);
        fclose(perf_fp);
        perf_fp = NULL;
    }
}

static void perf_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    if (perf_fp != NULL) {
        va_start(args, format);
        vfprintf(perf_fp, format, args);
        va_end(args);
        fflush(perf_fp);
    }
}

// Colored only on the terminal; perf.log always receives plain text.
static void perf_color(const char *color, const char *format, ...) {
    va_list args;
    va_start(args, format);
    if (log_color_enabled()) {
        fputs(color, stdout);
        vprintf(format, args);
        fputs(ANSI_NONE, stdout);
    } else {
        vprintf(format, args);
    }
    va_end(args);

    if (perf_fp != NULL) {
        va_start(args, format);
        vfprintf(perf_fp, format, args);
        va_end(args);
        fflush(perf_fp);
    }
}

static void perf_section(const char *name) {
    perf_printf("\n");
    perf_color(ANSI_FG_CYAN, "[%s]\n", name);
}

static void perf_status(bool ok) {
    perf_color(ok ? ANSI_FG_GREEN : ANSI_FG_RED, "%s", ok ? "OK" : "MISMATCH");
}

extern "C" void perf_event(int event_id) {
    if (event_id >= 0 && event_id < PERF_EVENT_COUNT) {
        perf_count[event_id]++;
    }
}

extern "C" int perf_delay_acc_step() {
    static const int M = 8;                 // 放大系数 s = 2^M
    static const int S = 1 << M;
    static const int F_DEV_MHZ = 100;       // 外设频率

#ifdef F_CPU
    const int f_cpu_mhz = F_CPU * 10;
#else
    const int f_cpu_mhz = F_DEV_MHZ;        // 未指定 F: r = 1
#endif

    if (f_cpu_mhz <= F_DEV_MHZ) return 0;
    const double r = static_cast<double>(f_cpu_mhz) / F_DEV_MHZ;
    return static_cast<int>((r - 1.0) * S + 0.5);   // 四舍五入
}

static double ratio(uint64_t num, uint64_t den) {
    return den ? static_cast<double>(num) / static_cast<double>(den) : 0.0;
}

static double percent(uint64_t num, uint64_t den) {
    return ratio(num, den) * 100.0;
}

static void print_mix(const char *name, uint64_t count, uint64_t total) {
    perf_printf("  %-14s %10" PRIu64 "  %7.2f%%\n", name, count, percent(count, total));
}

void perf_report() {
    const uint64_t cycle  = npc_get_cycle();
    const uint64_t commit = perf_count[PERF_COMMIT];
    const uint64_t state_commit = npc_get_commit_count();

    const uint64_t if_fetch     = perf_count[PERF_IF_FETCH];
    const uint64_t if_bypass    = perf_count[PERF_IF_BYPASS];
    const uint64_t if_stall_bus = perf_count[PERF_IF_STALL_BUS];
    const uint64_t if_stall_mem = perf_count[PERF_IF_STALL_MEM];

    const uint64_t ic_access     = perf_count[PERF_IC_ACCESS];
    const uint64_t ic_hit        = perf_count[PERF_IC_HIT];
    const uint64_t ic_miss       = perf_count[PERF_IC_MISS];
    const uint64_t ic_refill     = perf_count[PERF_IC_REFILL];
    const uint64_t ic_bypass_ar  = perf_count[PERF_IC_BYPASS_AR];
    const uint64_t ic_compulsory = perf_count[PERF_IC_COMPULSORY];
    const uint64_t ic_replace    = perf_count[PERF_IC_REPLACE];
    const uint64_t lsu_ar        = perf_count[PERF_LSU_AR];

    const uint64_t alu     = perf_count[PERF_ALU];
    const uint64_t alu_r   = perf_count[PERF_ALU_R];
    const uint64_t alu_i   = perf_count[PERF_ALU_I];
    const uint64_t load    = perf_count[PERF_LOAD];
    const uint64_t store   = perf_count[PERF_STORE];
    const uint64_t branch  = perf_count[PERF_BRANCH];
    const uint64_t jump    = perf_count[PERF_JUMP];
    const uint64_t upper   = perf_count[PERF_UPPER];
    const uint64_t csr     = perf_count[PERF_CSR];
    const uint64_t ecall   = perf_count[PERF_ECALL];
    const uint64_t mret    = perf_count[PERF_MRET];
    const uint64_t ebreak  = perf_count[PERF_EBREAK];
    const uint64_t fence_i = perf_count[PERF_FENCE_I];

    const uint64_t branch_taken     = perf_count[PERF_BRANCH_TAKEN];
    const uint64_t branch_not_taken = perf_count[PERF_BRANCH_NOT_TAKEN];
    const uint64_t jal              = perf_count[PERF_JAL];
    const uint64_t jalr             = perf_count[PERF_JALR];

    const uint64_t ld_byte    = perf_count[PERF_LD_BYTE];
    const uint64_t ld_half    = perf_count[PERF_LD_HALF];
    const uint64_t ld_word    = perf_count[PERF_LD_WORD];
    const uint64_t st_byte    = perf_count[PERF_ST_BYTE];
    const uint64_t st_half    = perf_count[PERF_ST_HALF];
    const uint64_t st_word    = perf_count[PERF_ST_WORD];
    const uint64_t ld_done    = perf_count[PERF_LD_DONE];
    const uint64_t st_done    = perf_count[PERF_ST_DONE];
    const uint64_t ld_wait    = perf_count[PERF_LD_WAIT];
    const uint64_t st_wait    = perf_count[PERF_ST_WAIT];

    const uint64_t bus_ar       = perf_count[PERF_BUS_AR];
    const uint64_t bus_r        = perf_count[PERF_BUS_R];
    const uint64_t bus_aw       = perf_count[PERF_BUS_AW];
    const uint64_t bus_w        = perf_count[PERF_BUS_W];
    const uint64_t bus_b        = perf_count[PERF_BUS_B];
    const uint64_t bus_ar_stall = perf_count[PERF_BUS_AR_STALL];

    const uint64_t csrrw = perf_count[PERF_CSRRW];
    const uint64_t csrrs = perf_count[PERF_CSRRS];

    // 各指令类别计数之和, 用于与动态指令数做一致性检查
    const uint64_t class_sum =
        alu + load + store + branch + jump + upper + csr + ecall + mret + ebreak + fence_i;

    perf_printf("\n");
    perf_color(ANSI_FG_CYAN, "=================== Performance Report ===================\n");
    perf_printf("Cycles           : %" PRIu64 "\n", cycle);
    perf_printf("Instructions     : %" PRIu64 "\n", commit);
    perf_printf("IPC              : %.4f\n", ratio(commit, cycle));
    perf_printf("CPI              : %.4f\n", ratio(cycle, commit));
#ifdef F_CPU
    perf_printf("Clock estimate   : %d MHz (F=%d)\n", F_CPU * 10, F_CPU);
#endif
    perf_printf("Commit (state)   : %" PRIu64 " (", state_commit);
    perf_status(state_commit == commit);
    perf_printf(")\n");
    perf_printf("Fetch / commit   : %" PRIu64 " / %" PRIu64 " (", if_fetch, commit);
    perf_status(if_fetch == commit);
    perf_printf(")\n");

    perf_section("Instruction mix");
    perf_color(ANSI_DIM, "  %-14s %10s  %7s\n", "category", "count", "share");
    perf_color(ANSI_DIM, "  %-14s %10s  %7s\n", "--------------", "----------", "-------");
    print_mix("alu", alu, commit);
    print_mix("load", load, commit);
    print_mix("store", store, commit);
    print_mix("branch", branch, commit);
    print_mix("jump", jump, commit);
    print_mix("upper", upper, commit);
    print_mix("csr", csr, commit);
    print_mix("ecall", ecall, commit);
    print_mix("mret", mret, commit);
    print_mix("ebreak", ebreak, commit);
    print_mix("fence.i", fence_i, commit);
    perf_printf("  %-14s %10" PRIu64 "  ", "class sum", class_sum);
    perf_status(class_sum == commit);
    perf_printf("\n");

    perf_printf("  ALU breakdown  : R=%" PRIu64 ", I=%" PRIu64 " (",
           alu_r, alu_i);
    perf_status(alu_r + alu_i == alu);
    perf_printf(")\n");
    perf_printf("  Load width     : byte=%" PRIu64 ", half=%" PRIu64 ", word=%" PRIu64 " (",
           ld_byte, ld_half, ld_word);
    perf_status(ld_byte + ld_half + ld_word == load);
    perf_printf(")\n");
    perf_printf("  Store width    : byte=%" PRIu64 ", half=%" PRIu64 ", word=%" PRIu64 " (",
           st_byte, st_half, st_word);
    perf_status(st_byte + st_half + st_word == store);
    perf_printf(")\n");

    perf_section("Control flow");
    perf_printf("  conditional branch : %" PRIu64 "\n", branch);
    perf_printf("  taken / not taken  : %" PRIu64 " / %" PRIu64 " (%.2f%% taken)\n",
           branch_taken, branch_not_taken, percent(branch_taken, branch));
    perf_printf("  jal / jalr         : %" PRIu64 " / %" PRIu64 " (", jal, jalr);
    perf_status(jal + jalr == jump);
    perf_printf(")\n");
    perf_printf("  control transfer   : %.2f%% of committed instructions\n",
           percent(branch + jump, commit));

    perf_section("IFU behavior");
    perf_printf("  fetched            : %" PRIu64 "\n", if_fetch);
    perf_printf("  uncached bypass    : %" PRIu64 " requests\n", if_bypass);
    perf_printf("  stall (busy AR)    : %" PRIu64 " cycles\n", if_stall_bus);
    perf_printf("  stall (wait R)     : %" PRIu64 " cycles\n", if_stall_mem);
    perf_printf("  stall ratio        : %.2f%% of cycles\n",
           percent(if_stall_bus + if_stall_mem, cycle));
    perf_printf("  avg R wait / fetch : %.4f cycles\n", ratio(if_stall_mem, if_fetch));
    perf_printf("  fetch path check   : hit+miss+bypass = %" PRIu64 " (",
           ic_hit + ic_miss + if_bypass);
    perf_status(ic_hit + ic_miss + if_bypass == if_fetch);
    perf_printf(")\n");

    perf_section("ICache behavior");
    perf_printf("  access / hit / miss: %" PRIu64 " / %" PRIu64 " / %" PRIu64 "\n",
           ic_access, ic_hit, ic_miss);
    perf_printf("  hit rate / miss rate: %.2f%% / %.2f%%\n",
           percent(ic_hit, ic_access), percent(ic_miss, ic_access));
    perf_printf("  line fills         : compulsory=%" PRIu64 ", replace=%" PRIu64 "\n",
           ic_compulsory, ic_replace);
    perf_printf("  refill / bypass AR : %" PRIu64 " / %" PRIu64 "\n",
           ic_refill, ic_bypass_ar);
    perf_printf("  refill AR          : %" PRIu64 " (", ic_refill);
    perf_status(ic_refill == ic_compulsory + ic_replace);
    perf_printf(")\n");
    perf_printf("  AR per line fill   : %.2f (1.00 = one AR per line fill)\n",
           ratio(ic_refill, ic_compulsory + ic_replace));
    perf_printf("  misses per 1k inst : %.2f\n", ratio(ic_miss, commit) * 1000.0);

    perf_section("LSU behavior");
    perf_printf("  load / store done  : %" PRIu64 " / %" PRIu64 "\n", ld_done, st_done);
    perf_printf("  load width         : byte=%" PRIu64 ", half=%" PRIu64 ", word=%" PRIu64 "\n",
           ld_byte, ld_half, ld_word);
    perf_printf("  store width        : byte=%" PRIu64 ", half=%" PRIu64 ", word=%" PRIu64 "\n",
           st_byte, st_half, st_word);
    perf_printf("  load wait cycles   : %" PRIu64 "\n", ld_wait);
    perf_printf("  avg load latency   : %.4f cycles\n", ratio(ld_wait, ld_done));
    perf_printf("  store wait cycles  : %" PRIu64 "\n", st_wait);
    perf_printf("  avg store latency  : %.4f cycles\n", ratio(st_wait, st_done));
    perf_printf("  load / store share : %.2f%% / %.2f%%\n",
           percent(load, commit), percent(store, commit));
    perf_printf("  LSU vs commit      : load=");
    perf_status(ld_done == load);
    perf_printf(", store=");
    perf_status(st_done == store);
    perf_printf("\n");

    perf_section("Bus behavior");
    perf_printf("  AR / R             : %" PRIu64 " / %" PRIu64 "\n", bus_ar, bus_r);
    perf_printf("  AW / W / B         : %" PRIu64 " / %" PRIu64 " / %" PRIu64 "\n",
           bus_aw, bus_w, bus_b);
    perf_printf("  AR stall cycles    : %" PRIu64 " (%.2f%% of cycles)\n",
           bus_ar_stall, percent(bus_ar_stall, cycle));
    perf_printf("  beats per read     : %.2f\n", ratio(bus_r, bus_ar));
    perf_printf("  beats per write    : %.2f\n", ratio(bus_w, bus_aw));
    perf_printf("  AR source check    : refill+bypass_ar+lsu_ar = %" PRIu64 " vs AR = %" PRIu64 " (",
           ic_refill + ic_bypass_ar + lsu_ar, bus_ar);
    perf_status(ic_refill + ic_bypass_ar + lsu_ar == bus_ar);
    perf_printf(")\n");
    perf_printf("  write source check : store=%" PRIu64 ", AW=%" PRIu64 ", W=%" PRIu64 ", B=%" PRIu64 " (",
           store, bus_aw, bus_w, bus_b);
    perf_status(store == bus_aw && store == bus_w && store == bus_b);
    perf_printf(")\n");

    perf_section("System / CSR");
    perf_printf("  CSR total          : %" PRIu64 "\n", csr);
    perf_printf("  csrrw / csrrs      : %" PRIu64 " / %" PRIu64 " (", csrrw, csrrs);
    perf_status(csrrw + csrrs == csr);
    perf_printf(")\n");
    perf_printf("  ecall / mret / ebreak: %" PRIu64 " / %" PRIu64 " / %" PRIu64 "\n",
           ecall, mret, ebreak);

    perf_section("Observation");
    bool any = false;
    if (ic_access && ratio(ic_miss, ic_access) > 0.10) {
        perf_color(ANSI_FG_YELLOW,
               "  - ICache miss rate %.2f%%; cache capacity/locality may be limiting fetch.\n",
               percent(ic_miss, ic_access));
        any = true;
    }
    if (ratio(if_stall_bus + if_stall_mem, cycle) > 0.10) {
        perf_color(ANSI_FG_YELLOW,
               "  - IFU stall ratio %.2f%%; fetch wait is a significant fraction of cycles.\n",
               percent(if_stall_bus + if_stall_mem, cycle));
        any = true;
    }
    if (ratio(ld_wait, cycle) > 0.10) {
        perf_color(ANSI_FG_YELLOW,
               "  - load wait %.2f%% of cycles; data-side memory latency is significant.\n",
               percent(ld_wait, cycle));
        any = true;
    }
    if (ratio(bus_ar_stall, cycle) > 0.05) {
        perf_color(ANSI_FG_YELLOW,
               "  - bus AR stall %.2f%% of cycles; arbitration/memory backpressure is visible.\n",
               percent(bus_ar_stall, cycle));
        any = true;
    }
    if (branch && ratio(branch_taken, branch) > 0.50) {
        perf_color(ANSI_FG_YELLOW,
               "  - taken branch ratio %.2f%%; without a branch predictor, fetch redirects are frequent.\n",
               percent(branch_taken, branch));
        any = true;
    }
    if (!any) {
        perf_color(ANSI_FG_GREEN,
               "  - no single dominant stall above current thresholds.\n");
    }
    perf_color(ANSI_FG_CYAN, "==========================================================\n");

    Log("Perf summary: cycles=%llu inst=%llu ipc=%.4f cpi=%.4f icache_access=%llu icache_hit=%llu icache_miss=%llu icache_hit_rate=%.4f if_bypass=%llu",
        (unsigned long long)cycle, (unsigned long long)commit, ratio(commit, cycle),
        ratio(cycle, commit), (unsigned long long)ic_access, (unsigned long long)ic_hit,
        (unsigned long long)ic_miss, ratio(ic_hit, ic_access),
        (unsigned long long)if_bypass);
    Log("Perf memory: load=%llu store=%llu load_latency=%.4f store_latency=%.4f bus_ar=%llu bus_aw=%llu bus_ar_stall=%llu branch_taken_rate=%.4f",
        (unsigned long long)load, (unsigned long long)store,
        ratio(ld_wait, ld_done), ratio(st_wait, st_done),
        (unsigned long long)bus_ar, (unsigned long long)bus_aw,
        (unsigned long long)bus_ar_stall, ratio(branch_taken, branch));
}
