#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Vrv32e.h"
#include "../obj_dir/Vrv32e___024root.h"
#include "Vrv32e__Dpi.h"
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

extern double lsu_ratio, ifu_ratio, exu_ratio;
/* **************** */
#ifdef CONFIG_WAVE
#include "verilated_vcd_c.h"
VerilatedVcdC *tfp = new VerilatedVcdC(); // 导出vcd波形
#endif
Vrv32e *top = new Vrv32e("top");
vluint64_t main_time = 0; // 仿真时间

extern uint64_t R_inst, I_inst, J_inst, R_inst, L_inst, B_inst, S_inst, CSR_inst;
extern uint64_t ifu_get;
extern uint64_t lsu_get;
extern uint64_t exu_done;
extern "C" void counter(int inst_type, int ifu_inc, int lsu_inc, int exu_inc) {
    ifu_get  += ifu_inc;
    lsu_get  += lsu_inc;
    exu_done += exu_inc;
    switch (inst_type) {
        case 0: R_inst++; break;  // R 类型
        case 1: I_inst++; break;  // I 类型 (包括 LUI/AUIPC)
        case 2: J_inst++; break;  // J 类型 (JAL/JALR)
        case 3: L_inst++; break;  // L 类型 (假设第二个 R_inst 为 L_inst)
        case 4: B_inst++; break;  // B 类型
        case 5: S_inst++; break;  // S 类型
        case 6: CSR_inst++; break; // CSR 类型
        default: break;  // 无效类型，不递增
    }
}

void occupancy(int ifu_active_cycles, int exu_active_cycles, int lsu_active_cycles, int total_cycles) {
    ifu_ratio = (total_cycles == 0) ? 0.0 : (double)ifu_active_cycles / total_cycles * 100.0;
    exu_ratio = (total_cycles == 0) ? 0.0 : (double)exu_active_cycles / total_cycles * 100.0;
    lsu_ratio = (total_cycles == 0) ? 0.0 : (double)lsu_active_cycles / total_cycles * 100.0;
}

extern "C" void ebreak(int station, int inst) {
    if(main_time>=start_time){
        if (Verilated::gotFinish())
            return;

        npc_state.halt_ret = top->rootp->rv32e__DOT__wbu__DOT__regs[10]; // a0
        npc_state.halt_pc = top->rootp->rv32e__DOT__IF_ID_pc;

        switch (station) {
            case HIT_TRAP:
                npc_state.state = NPC_END;
                // _Log(ANSI_FG_GREEN "HIT GOOD TRAP\n" ANSI_NONE);
                break;

            case ABORT:
            default:
                Log("maintime = %ld, pc = 0x%08x, inst = 0x%08x", main_time, top->rootp->rv32e__DOT__IF_ID_pc, top->rootp->rv32e__DOT__IF_ID_inst);
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
        top->clk = !top->clk; // 翻转时钟信号

        if (main_time == start_time) {
            top->reset = 0; // 在指定时间释放复位
        }

        top->eval(); // 执行仿真
    #ifdef CONFIG_WAVE
        tfp->dump(main_time); // 记录波形
    #endif
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
#ifdef CONFIG_WAVE
    Verilated::traceEverOn(true); // 启用波形跟踪

    top->trace(tfp, 0);
    tfp->open("wave.vcd"); // 打开波形文件
#endif
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
#ifdef CONFIG_WAVE
    tfp->close();
#endif
    delete top;

    return is_exit_status_bad();
}
