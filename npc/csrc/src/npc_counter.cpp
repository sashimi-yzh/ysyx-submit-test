#include <npc_counter.h>
#include "svdpi.h"
#include "Vnpc_top__Dpi.h"

// static _Float32 ATMT;
// static float amat;

static float p_hit;

static uint64_t icache_total = 0;
static uint64_t icache_hit = 0;


enum {IFU, LSU, XBAR, RAW, BRANCH, NO_TYPE};

static struct counter {
    const char *regex;
    uint64_t time_count; 
    uint64_t cycle_count; 
} counters[] = {
    {"ifu_delay_block", 0, 0},
    {"ifu_delay_miss", 0, 0},
    {"lsu_delay", 0, 0},
    {"xbar_delay", 0, 0},
    {"raw_delay_alu", 0, 0},
    {"raw_delay_load", 0,0},
    {"branch_delay", 0, 0},
};

#ifdef CONFIG_COUNTER
extern "C" void time_add(int no){
    counters[no].time_count ++;
    return;
}

extern "C" void cycle_add(int no){
    counters[no].cycle_count ++;
}

void display_counter(){

    printf("           type |   num    | cycles/num\n");

    for(int i = 0; i < 7; i++){
        if(counters[i].time_count != 0){
            printf("%15s | %8ld | %ld\n", counters[i].regex, counters[i].time_count, counters[i].cycle_count/counters[i].time_count);
        }
    }
}
#else
extern "C" void time_add(int no){ }
void display_counter(){ }
extern "C" void cycle_add(int type, uint32_t num){ }
#endif

#ifdef CONFIG_AMAT
extern "C" void icache_add(int no){
    if(no == 0){
        icache_total ++;
    }
    else if(no == 1) {
        icache_hit ++;
    }
}
void display_amat(){
    if(icache_total !=0 ){ p_hit = (float)icache_hit / (float)icache_total; }
    printf("AMAT: total = %ld, hit = %ld, p_hit = %.2f\n", icache_total, icache_hit, p_hit);
}
#else 
extern "C" void icache_add(int no){ }
void display_amat(){ }
#endif
