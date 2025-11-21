#include "../include/common.h"
#include "../include/monitor.h"
#include "../include/trace.h"
#include "../include/switch.h"
#include "../include/debug.h"
#include "../include/macro.h"
#include "../include/difftest-def.h"

#include <time.h>
#include <sys/time.h>

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
extern VysyxSoCFull *top;
#define pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc
#define inst top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__inst
#define exu_dnpc_valid top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__exu_dnpc_valid
#define diff top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__diff
#define araddr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_araddr
#define arvalid top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_arvalid
#define awaddr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_awaddr
#define awvalid top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__lsu_awvalid
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
extern Vysyx_25020037_npc *top;
#define pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__pc
#define exu_dnpc_valid top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__cpu__DOT__exu_dnpc_valid
#define diff top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__diff
#define araddr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__lsu_araddr
#define arvalid top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__lsu_arvalid
#define awaddr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__lsu_awaddr
#define awvalid top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__lsu_awvalid
#define inst top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__inst
#endif

static int ifu_access_fault = 0;
static int lsu_access_fault = 0;
extern "C" { void access_fault(int ifu, int lsu) {
    if(ifu) ifu_access_fault = 1;
    if(lsu) lsu_access_fault = 1;
    }
}
typedef struct {
    uint64_t count;      // 指令数量
    uint64_t clk;        // 消耗的时钟数
    uint64_t time;       // 消耗的时间(us)
} TypeStats;

typedef struct {
    uint64_t inst_sum;   // 总指令数
    uint64_t clk_sum;    // 总时钟数
    uint64_t g_timer;    // 总时间(us)
} Stats;
static Stats stats = {0};
static int prev_valid = 0;
static void exec_once();

static uint64_t us;
extern uint64_t get_time();
static uint64_t current_total_clk_reg = 0;
static int last_pc;


static void inst_infomation() {
    Log("IPC = %.4f", (double)stats.inst_sum / stats.clk_sum);
    Log("host time spent = %ld us", stats.g_timer);
    Log("total guest instructions = %ld", stats.inst_sum);
    Log("total guest clocks = %ld", stats.clk_sum);
    Log("simulation frequency = %ld inst/s", stats.inst_sum * 1000000 / stats.g_timer);
}

static void trace_and_difftest() {

#ifdef CONFIG_DIFFTEST
    if(diff) difftest_step(pc);
#endif

#ifdef CONFIG_WATCHPOINT			//监视点
  //printf("enter(1)\n");
  int sign = 0, i = 0;
  i = watchpoint_exec(&sign);
  if(sign == 1) {
    NPC_STATE = (NPC_STATE == NPC_END) ? NPC_END : NPC_STOP;
    printf("watchpoint %d not equavolent\n", i);
  }
  else if (sign == 2) {
    printf("caculate error\n");
    assert(0);
  }
#endif

}

void cpu_exec(int n){
    if(NPC_STATE == NPC_RUNING){
        if(n < 0){
            while(true){
#ifdef CONFIG_ITRACE
                iringbuf(pc, inst);
#endif
#ifdef CONFIG_YSYXSOC
                if(ifu_access_fault) {
                    printf("ifu_access_fault\n");
                    inst_infomation();
                    finish();
                    break;
                }
                if(lsu_access_fault) {
                    printf("lsu_access_fault\n");
                    inst_infomation();
                    finish();
                    break;
                }
#endif
                if(NPC_STATE == NPC_END || NPC_STATE == NPC_ABORT){
                    inst_infomation();
                    finish();
                    break;
                }
                else if (NPC_STATE == NPC_STOP) {
                    NPC_STATE = NPC_RUNING;
                    break;
                }
                exec_once();
            }
        }
        else{
            for(int i = 0; i < n; i++){
#ifdef CONFIG_ITRACE
                iringbuf(pc, inst);
#endif
#ifdef CONFIG_YSYXSOC
                if(ifu_access_fault) {
                    printf("ifu_access_fault\n");
                    inst_infomation();
                    finish();
                    break;
                }
                if(lsu_access_fault) {
                    printf("lsu_access_fault\n");
                    inst_infomation();
                    finish();
                    break;
                }
#endif
                if(NPC_STATE == NPC_RUNING) {
                    exec_once();
                    if(NPC_STATE == NPC_RUNING) printf("0x%08x: %08x\n", pc, inst);
                }
                else if (NPC_STATE == NPC_STOP) {
                    NPC_STATE = NPC_RUNING;
                    break;
                }
                else if(NPC_STATE == NPC_END || NPC_STATE == NPC_ABORT) {
                    inst_infomation();
                    finish();
                    break;
                }
            }
        }
    }
    else if(NPC_STATE == NPC_END) {
        printf("Program execution has ended. To restart the program, exit NPC and run again.\n");
        return;
    }
}

static void exec_once() {
    stats.inst_sum++;
    last_pc = pc;

    uint64_t timer_start, timer_end, time_spent = 0;
    uint64_t clk_sum_reg = 0;
    int prev_valid_reg = 0x10;
    do{
#ifdef CONFIG_DIFFTEST
#ifdef CONFIG_YSYXSOC
        if((((araddr < 0x30000000) | (araddr > 0x3fffffff)) & arvalid) & 
           (((araddr < 0x0f000000) | (araddr > 0x0f002000)) & arvalid) & 
           (((araddr < 0x80000000) | (araddr > 0x9fffffff)) & arvalid) & 
           (((araddr < 0xa0000000) | (araddr > 0xbfffffff)) & arvalid)) {difftest_skip_ref();}
        if((((awaddr < 0x30000000) | (awaddr > 0x3fffffff)) & awvalid) & 
           (((awaddr < 0x0f000000) | (awaddr > 0x0f002000)) & awvalid) & 
           (((awaddr < 0x80000000) | (awaddr > 0x9fffffff)) & awvalid) & 
           (((awaddr < 0xa0000000) | (awaddr > 0xbfffffff)) & awvalid)) {difftest_skip_ref();}
#else
        if(((araddr < 0x80000000) | (araddr > 0x90000000)) & arvalid) {difftest_skip_ref();}
        if(((awaddr < 0x80000000) | (awaddr > 0x90000000)) & awvalid) {difftest_skip_ref();}
#endif
#endif
        timer_start = get_time();
#ifdef CONFIG_NVBOARD
        nvboard_update();
#endif
        single_cycle();

        trace_and_difftest();
        timer_end = get_time();
        time_spent += timer_end - timer_start;
        clk_sum_reg++;
    } while ((pc == last_pc) && (NPC_STATE == NPC_RUNING));
    
    stats.clk_sum += clk_sum_reg;
    stats.g_timer += time_spent;
}
