#include "tpdef.h"
#include <cstdint>
#include <cstdio>

enum {
    IOPT = 0, IJMP, IMEM, ICSR,
    EEND
};

static const char* type_name[EEND] = {
    "OPT", "JMP", "MEM", "CSR"
};

static int counter[EEND] = { 0 };
static int64_t cycnum[EEND] = { 0 };
static int64_t hitnum = 0;


void pmc_init()
{
    for (int i = 0; i < EEND; i++) 
    {
        counter[i] = 0;
        cycnum[i] = 0;
    }
    hitnum = 0;
}

extern "C" void cache_hit()
{
    hitnum++;
}

void cycle_counter(word_t inst, int64_t ncyc)
{
    uint8_t opt = BITS(inst, 6, 0);

    switch (opt) 
    {
    case 0b0010011: cycnum[IOPT] += ncyc; counter[IOPT]++; break;            
    case 0b0010111: cycnum[IOPT] += ncyc; counter[IOPT]++; break;            
    case 0b0110111: cycnum[IOPT] += ncyc; counter[IOPT]++; break;            
    case 0b1100111: cycnum[IJMP] += ncyc; counter[IJMP]++; break;            
    case 0b1101111: cycnum[IJMP] += ncyc; counter[IJMP]++; break;            
    case 0b1110011: cycnum[ICSR] += ncyc; counter[ICSR]++; break;            
    case 0b0100011: cycnum[IMEM] += ncyc; counter[IMEM]++; break;            
    case 0b0000011: cycnum[IMEM] += ncyc; counter[IMEM]++; break;            
    case 0b0110011: cycnum[IOPT] += ncyc; counter[IOPT]++; break;            
    case 0b1100011: cycnum[IJMP] += ncyc; counter[IJMP]++; break;            
    default: ;
    }
}


void pmc_print()
{
    int64_t all_inst = 0, all_cycle = 0;
    double cpi = 0.;

    printf(ANSI_FG_BLUE "%-6s\t%10s\t%10s\t%5s\n" ANSI_NONE,
        "type", "inst", "cycle", "cpi");

    for (int i = 0; i < EEND; i++) 
    {
        all_inst += counter[i];
        all_cycle += cycnum[i];
        cpi = counter[i] ? (double)cycnum[i] / counter[i] : 0.;
        printf(ANSI_FMT("%-6s\t%10d\t%10ld\t%5.3lf", ANSI_FG_GREEN) "\n", 
            type_name[i], counter[i], cycnum[i], cpi);
    }

    cpi = all_inst ? (double)all_cycle / all_inst : 0.;
    printf(ANSI_FMT("%-6s\t%10ld\t%10ld\t%5.3lf", ANSI_FG_GREEN) "\n", 
        "ALL", all_inst, all_cycle, cpi);
    putchar('\n');

    double p = (double)hitnum / all_inst;
    printf("[cache hit] = " ANSI_FMT("%ld", ANSI_FG_GREEN) "\n", hitnum);
    printf(" [hit rate] = " ANSI_FMT("%5.3lf%%", ANSI_FG_GREEN) "\n", p * 100.);
    printf("     [AMAT] = " ANSI_FMT("%5.3lf", ANSI_FG_GREEN) "\n", 3. + (1. - p) * 8);
}