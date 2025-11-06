#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <svdpi.h>
#ifdef CONFIG_SOC
#include <VysyxSoCFull.h>
#include <VysyxSoCFull__Dpi.h>
#include <VysyxSoCFull___024root.h>
#else
#include <Vysyx_24100006.h>
#include <Vysyx_24100006__Dpi.h>
#include <Vysyx_24100006___024root.h>
#endif

#include <common.h>
#ifdef CONFIG_SOC
#define CPU VysyxSoCFull
extern CPU *cpu;
#else
#define CPU Vysyx_24100006
extern CPU *cpu;
#endif

#ifdef CONFIG_SOC
#include <nvboard.h>
// nvboard
void nvboard_bind_all_pins(CPU* top);
#endif

// 一条指令最多运行的周期,超过就报错
#define MAX_NUM_CYC 500000

extern word_t inst,pc,dnpc;
extern word_t pc_w, npc_w;
extern word_t inst, prev_pc, PCW, if_valid, wb_ready;
extern word_t mtvec, mepc, mcause, mstatus;
//circuit
void single_cycle();
void cpu_exec(uint64_t n);
void reset_cpu(int n);
//wave
void init_wave();
void dump_wave_inc();
void close_wave();
// 获取当前的仿真时间，没有算上reset的时间
extern uint64_t cycle;
#endif