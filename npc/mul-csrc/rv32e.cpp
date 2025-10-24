#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vysyx_25010030.h"
// #include "verilated_vcd_c.h"
#include "../obj_dir/Vysyx_25010030___024root.h"
#include "Vysyx_25010030__Dpi.h"
#include "svdpi.h"
#include "../include/common.h"
#include "../include/utils.h"
#include "../include/debug.h"
#include "../include/paddr.h"

#define HIT_TRAP 1
#define ABORT 2
#define start_time 10

/* **************** */

extern void ebreak(int station, int inst);
extern void init_monitor(int argc, char *argv[]);
extern void init_monitor(int, char *[]);
extern void sdb_mainloop();
extern int is_exit_status_bad();
extern word_t pmem_r(paddr_t addr, int len);
extern void pmem_w(paddr_t addr, int len, word_t data);

/* **************** */
// VerilatedVcdC *tfp = new VerilatedVcdC(); // 导出vcd波形
Vysyx_25010030 *top = new Vysyx_25010030("top");
vluint64_t main_time = 0; // 仿真时间

extern "C" void ebreak(int station, int inst) {
    if(main_time>=start_time){
        if (Verilated::gotFinish())
            return;

        npc_state.halt_ret = top->rootp->ysyx_25010030__DOT__wb_stage__DOT__regs[10]; // a0
        npc_state.halt_pc = top->rootp->ysyx_25010030__DOT__pc;

        switch (station) {
            case HIT_TRAP:
                npc_state.state = NPC_END;
                // _Log(ANSI_FG_GREEN "HIT GOOD TRAP\n" ANSI_NONE);
                break;

            case ABORT:
            default:
                Log("maintime = %ld, pc = 0x%08x, inst = 0x%08x", main_time, top->rootp->ysyx_25010030__DOT__pc, top->rootp->ysyx_25010030__DOT__instr);
                npc_state.state = NPC_ABORT;
                // _Log(ANSI_FG_RED "HIT BAD TRAP\n" ANSI_NONE);
                break;
        }
    }      
}

extern "C" word_t pmem_read(paddr_t raddr, int len) {
    if(main_time >= 1) return pmem_r(raddr,len);
    return 0; // 复位期间返回 0，避免未定义行为
}

extern "C" void pmem_write(paddr_t waddr, word_t wdata, int len) {
    if (main_time >= start_time) pmem_w(waddr, len, wdata); // 复位结束后才写入
}

NPCState npc_state = { .state = NPC_STOP };

int is_exit_status_bad() {
    int good = (npc_state.state == NPC_END && npc_state.halt_ret == 0) ||
               (npc_state.state == NPC_QUIT);
    return !good;
}

void single_cycle(void) {
    if (!Verilated::gotFinish()) {
        top->clock = !top->clock; // 翻转时钟信号

        if (main_time == start_time) {
            top->reset = 0; // 在指定时间释放复位
        }

        top->eval(); // 执行仿真
        // tfp->dump(main_time); // 记录波形
        main_time++; // 推进仿真时间
    }
}

void reset(void) {
    top->reset = 1; // 复位信号置高
    for (int i = 0; i < start_time; i++) {
        single_cycle(); // 执行复位周期
    }
}

void init_verilator(void) {
    // Verilated::traceEverOn(true); // 启用波形跟踪

    // top->trace(tfp, 0);
    // tfp->open("wave.vcd"); // 打开波形文件

    reset(); // 执行复位
}

void die(){
    top->final();
    // tfp->close();
    delete top;
    Verilated::gotFinish(true);
}

int main(int argc, char *argv[]) {
    /* Initialize the monitor. */
    init_monitor(argc, argv);

    /* Initialize the verilator. */
    init_verilator();

    /* Receive commands from user and run simulation. */
    sdb_mainloop();

    /* End the simulation */
    top->final();
    // tfp->close();
    delete top;

    return is_exit_status_bad();
}