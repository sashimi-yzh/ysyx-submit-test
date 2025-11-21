#include "verilated.h"
#include "verilated_vcd_c.h"
#include "../include/common.h"
#include "../include/memory.h"
#include "../include/monitor.h"
#include "../include/reg.h"
#include "../include/trace.h"
#include "../include/switch.h"
#include "../include/debug.h"
#include "../include/macro.h"

#ifdef CONFIG_YSYXSOC
#include "VysyxSoCFull___024root.h"
#include "VysyxSoCFull.h"
#ifdef CONFIG_NVBOARD
extern void nvboard_bind_all_pins(VysyxSoCFull* top);
#endif

VysyxSoCFull *top = new VysyxSoCFull("top");
#define pc top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__pc
#define gpr top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__wbu_cpu__DOT__regs
#else
#include "Vysyx_25020037_npc___024root.h"
#include "Vysyx_25020037_npc.h"
Vysyx_25020037_npc *top = new Vysyx_25020037_npc("top");
#define pc top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__pc
#define gpr top->rootp->ysyx_25020037_npc__DOT__cpu__DOT__wbu_cpu__DOT__regs
#endif

/*********************************************************************/
//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑        永无BUG
//           南无阿弥陀佛   就算报错也让我看懂
//                    佛祖保佑
/*********************************************************************/

// 定义全局变量
VerilatedContext* contextp = nullptr;
VerilatedVcdC* tfp = nullptr;

int NPC_STATE;

const char *tempregs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};

extern "C" {
    void hit(int inst_not_realize) {
        if(NPC_STATE == NPC_RUNING){
            if(inst_not_realize) {printf("inst not realize\n"); NPC_STATE = NPC_ABORT;}
            else NPC_STATE = NPC_END;
        }
    }
}

int is_exit_status_bad() {
  int good = (NPC_STATE == NPC_END) ||
             (NPC_STATE == NPC_QUIT);
  return !good;
}

void finish(){
#ifdef CONFIG_WAVE
    tfp->dump(contextp->time());
    contextp->timeInc(1);
    tfp->close();
    delete tfp;
    delete contextp;
#endif

    if (NPC_STATE == NPC_ABORT) {
#ifdef CONFIG_ITRACE
        iringbuf_printf();
#endif
        Log("npc: %s at pc = 0x%08x",ANSI_FMT("HIT ABORT TRAP", ANSI_FG_RED), pc-0xc);
    } 
    else if(gpr[10]) Log("npc: %s at pc = 0x%08x",ANSI_FMT("HIT BAD TRAP", ANSI_FG_RED), pc-0xc);
    else Log("npc: %s at pc = 0x%08x",ANSI_FMT("HIT GOOD TRAP", ANSI_FG_GREEN), pc-0xc);
    return;
}

// 一周期最小执行单元
void single_cycle() {
    top->clock=1;
    top->eval();
#ifdef CONFIG_WAVE
    tfp->dump(contextp->time());
    contextp->timeInc(1);
#endif
    top->clock=0;
    top->eval();
#ifdef CONFIG_WAVE
    tfp->dump(contextp->time());
    contextp->timeInc(1);
#endif
}

static void reset(int n) {
    top->reset = 1;
    while (n -- > 0) single_cycle();
    top->reset = 0;
}

int main (int argc, char** argv) {

    // printf("===== 命令行参数信息 =====\n");
    // printf("参数数量 (argc): %d\n", argc);
    // for (int i = 0; i < argc; i++) {
    //     printf("参数 %d: %s\n", i, argv[i]);
    // }
    // printf("==========================\n\n");

#ifdef CONFIG_NVBOARD
    nvboard_bind_all_pins(top);
    nvboard_init();
#endif
    Verilated::traceEverOn(true);

    contextp = new VerilatedContext;
    Verilated::commandArgs(argc, argv);
    contextp->commandArgs(argc, argv);
#ifdef CONFIG_WAVE
    tfp = new VerilatedVcdC;
    top->trace(tfp, 99);
    tfp->open("ysyx_25020037.vcd");
#endif
    reset(10);
    
    init_monitor(argc, argv);

    NPC_STATE = true;

    sdb_mainloop();
    
    return is_exit_status_bad();
}    
