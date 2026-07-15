#include "VysyxSoCFull.h"
#include "verilated_vcd_c.h"
#include "VysyxSoCFull___024root.h"
#include <stdint.h>
#include "config.hpp"
#include <nvboard.h>

extern VysyxSoCFull* cpu;
extern VerilatedVcdC* tfp;
extern bool exit_flag;
extern uint64_t cycle_cnt;
extern bool bootloader_stage;

enum { BRANCH=0, JAL, JALR, LUI, AUIPC, OP, OP_IMM, LOAD, STORE, SYSTEM };
enum { IFU, IDU, EXU, LSU, WBU };

extern "C" {
void difftest_exec(uint64_t n);
void difftest_regcpy(void *dut, bool direction);
}
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

typedef struct {
  uint32_t gpr[16];
  uint32_t pc;
} CPU_state;

void cpu_exec(uint64_t n)
{
    if(exit_flag) {
        printf("Simulation has already ended.\n");
        return;
    }
    while(n-- > 0) {
        cpu->contextp()->timeInc(1);
        cpu->clock = 0;
        cpu->reset = 0;
        cpu->eval();
#ifdef WAVEON
        tfp->dump(cpu->contextp()->time());
#endif
        cpu->contextp()->timeInc(1);
        cpu->clock = 1;
        cpu->reset = 0;
        cpu->eval();
#ifdef WAVEON
        tfp->dump(cpu->contextp()->time());
#endif

        if(!bootloader_stage) {
            cycle_cnt++;

#ifdef PIPELINE_VIEW
            uint8_t ifu_valid = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_IFU__DOT__u_ICACHE__DOT__m_valid;
            uint8_t idu_valid = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_IDU__DOT__valid_reg;
            uint8_t exu_valid = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_EXU__DOT__valid_reg;
            uint8_t lsu_valid = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_LSU__DOT__valid_reg;
            uint8_t wbu_valid = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_WBU__DOT__valid_reg;
            uint32_t ifu_pc = cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_IFU__DOT__u_ICACHE__DOT__addr_reg;
            printf("\r| %s | %s | %s | %s | %s |     PC: 0x%08x     |",
                ifu_valid ? "IFU" : "   ",
                idu_valid ? "IDU" : "   ",
                exu_valid ? "EXU" : "   ",
                lsu_valid ? "LSU" : "   ",
                wbu_valid ? "WBU" : "   ",
                ifu_pc);
            fflush(stdout);
#endif
        }
    
#ifdef DIFFTEST
        difftest_exec(1);
        CPU_state dut_state;
        difftest_regcpy(&dut_state, DIFFTEST_TO_DUT);
        
        for(uint32_t i = 0; i < 16; i++) {
            if(dut_state.gpr[i] != cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_GPR__DOT__gpr[i]) {
                printf("Difftest failed at time %lu: gpr[%u] = 0x%08x, expected 0x%08x\n",
                    cpu->contextp()->time(), i, cpu->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__ysyx_26040125_GPR__DOT__gpr[i], dut_state.gpr[i]);
                exit_flag = true;
                break;
            }
        }
#endif
        if(exit_flag) {
            break;
        }

        nvboard_update();
    }
    return;
}