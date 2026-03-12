#include "isa.h"
#include "utils.h"

const char *regs[] = {
    "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
    "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
    "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
    "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"};

CPU_state cpu = {};
Extra_CPU_state extra_cpu = {};
Decode s = {};

bool initialized = false;

void difftest_skip_ref();

extern "C" void cpu_value(int diff_skip, int valid, int inst, int inst_addr, int pc, int gpr0, int gpr1, int gpr2, int gpr3,
                          int gpr4, int gpr5, int gpr6, int gpr7,
                          int gpr8, int gpr9, int gpr10, int gpr11,
                          int gpr12, int gpr13, int gpr14, int gpr15,

                          int mepc, int mtvec, int mstatus,
                          int mcause, int mcyclel, int mcycleh,
                          int mvendorid, int marchid)
{
    // printf("dut npc: pc=0x%08x\n", pc);
    cpu_inst_valid = valid;
    s.inst = inst;
    s.pc = inst_addr;

    if (diff_skip) {
        // printf("Difftest: skip ref at pc: 0x%08x\n", s.pc);
        IFDEF(CONFIG_DIFFTEST, difftest_skip_ref());
    }

    cpu.pc = pc;
    cpu.gpr[0] = gpr0;
    cpu.gpr[1] = gpr1;
    cpu.gpr[2] = gpr2;
    cpu.gpr[3] = gpr3;
    cpu.gpr[4] = gpr4;
    cpu.gpr[5] = gpr5;
    cpu.gpr[6] = gpr6;
    cpu.gpr[7] = gpr7;
    cpu.gpr[8] = gpr8;
    cpu.gpr[9] = gpr9;
    cpu.gpr[10] = gpr10;
    cpu.gpr[11] = gpr11;
    cpu.gpr[12] = gpr12;
    cpu.gpr[13] = gpr13;
    cpu.gpr[14] = gpr14;
    cpu.gpr[15] = gpr15;

    cpu.csr.mepc = mepc;
    cpu.csr.mtvec = mtvec;
    cpu.csr.mstatus = mstatus;
    cpu.csr.mcause = mcause;

    extra_cpu.mcyclel = mcyclel;
    extra_cpu.mcycleh = mcycleh;
    extra_cpu.mvendorid = mvendorid;
    extra_cpu.marchid = marchid;

    // if (mcause == 11) {
    //     printf("ecall from inst_addr: 0x%08x\n", s.pc);
    // }

    // if (!initialized) {
    //     initialized = true;
    //     printf("mvendorid: 0x%08x, marchid: 0x%08x\n", extra_cpu.mvendorid, extra_cpu.marchid);
    // }
}

void reg_display()
{
    printf("[NPC:  PC]  : 0x%08x\n", cpu.pc);
    for (int i = 0; i < 16; i++) {
        printf("gpr[%02d]-%-4s: 0x%08x\n", i, regs[i], cpu.gpr[i]);
    }

    printf("csr-mstatus : 0x%08x\n", cpu.csr.mstatus);
    printf("csr-mcause  : 0x%08x\n", cpu.csr.mcause);
    printf("csr-mepc    : 0x%08x\n", cpu.csr.mepc);
    printf("csr-mtvec   : 0x%08x\n", cpu.csr.mtvec);
}

word_t reg_str2val(const char *s, bool *success)
{
    *success = true;

    if (s[0] == '$')
        s++;

    for (int i = 0; i < 16; i++) {
        if (strcmp(s, regs[i]) == 0) {
            return cpu.gpr[i];
        }
    }

    if (strcmp(s, "pc") == 0) {
        return cpu.pc;
    }

    if (strcmp(s, "mstatus") == 0) {
        return cpu.csr.mstatus;
    }

    if (strcmp(s, "mcause") == 0) {
        return cpu.csr.mcause;
    }

    if (strcmp(s, "mepc") == 0) {
        return cpu.csr.mepc;
    }

    if (strcmp(s, "mtvec") == 0) {
        return cpu.csr.mtvec;
    }

    printf("Error: reg error\n");
    *success = false;
    return 0;
}

#define CHECKDIFF(reg,fmt, ...) \
    if (ref_r->reg != cpu.reg){ \
        PRINTF_RED("[DIFF]==>> " fmt " got: 0x%08x, but expected: 0x%08x\n", ##__VA_ARGS__, cpu.reg, ref_r->reg); \
        flag = false;        \
    }

bool difftest_checkregs(CPU_state *ref_r, paddr_t pc)
{
    bool flag = true;

    CHECKDIFF(pc, "pc");

    for (int i = 0; i < 16; i++) {
        CHECKDIFF(gpr[i], "gpr[%02d]-%s", i, regs[i]);
    }

    CHECKDIFF(csr.mstatus, "mstatus");
    CHECKDIFF(csr.mcause, "mcause");
    CHECKDIFF(csr.mepc, "mepc");
    CHECKDIFF(csr.mtvec, "mtvec");

    if (!flag) {
        PRINTF_RED("Difftest: Error at pc: 0x%08x\n", pc);
        return false;
    }

    return true;
}