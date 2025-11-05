#ifndef _VERILATOR_H_
#define _VERILATOR_H_

#include <autoconf.h>
#include <verilated.h>
#include <common.h>

#ifndef CONFIG_USE_REG0
#define DONT_USE_REG0
#endif // !CONFIG_USE_REG0


#ifdef USE_SOC
#include "VysyxSoCFull.h"
#include "VysyxSoCFull__Dpi.h"
#include "VysyxSoCFull_ysyx_23060246_CSR.h"
#include "VysyxSoCFull_ysyx_23060246_EXU.h"
#include "VysyxSoCFull_ysyx_23060246_Regfile.h"
#ifdef CONFIG_RVE
#ifdef DONT_USE_REG0
#include "VysyxSoCFull_ysyx_23060246_regs_15x32.h"
#else 
#include "VysyxSoCFull_ysyx_23060246_regs_16x32.h"
#endif // !DONT_USE_REG0
#else 
#ifdef DONT_USE_REG0
#include "VysyxSoCFull_ysyx_23060246_regs_31x32.h"
#else 
#include "VysyxSoCFull_ysyx_23060246_regs_32x32.h"
#endif // !DONT_USE_REG0
#endif // !CONFIG_RVE
#include "VysyxSoCFull_ysyx_23060246.h"
#include "VysyxSoCFull_ysyx_23060246_npc.h"
#include "VysyxSoCFull_ysyxSoCFull.h"
#include "VysyxSoCFull_ysyxSoCASIC.h"
#include "VysyxSoCFull_ysyx_23060246_WBU.h"
//#include "VysyxSoCFull_ysyx_23060246_LSU.h"
#include "VysyxSoCFull_ysyx_23060246_LSU_AREA.h"
#include "VysyxSoCFull_ysyx_23060246_IDU.h"
#include "VysyxSoCFull_ysyx_23060246_IFU.h"
#include "VysyxSoCFull_CPU.h"
#ifdef CONFIG_USE_ICACHE
//#error "You need to solve prefix problem first!"
//#include "VysyxSoCFull_ICache.h"
#endif 
#else
#include "VnpcSimTop.h"
#include "VnpcSimTop_npcSimTop.h"
#include "VnpcSimTop__Dpi.h"
#include "VnpcSimTop_ysyx_23060246_CSR.h"
#include "VnpcSimTop_ysyx_23060246_EXU.h"
#include "VnpcSimTop_ysyx_23060246_Regfile.h"
#ifdef CONFIG_RVE
#ifdef DONT_USE_REG0
#include "VnpcSimTop_ysyx_23060246_regs_15x32.h"
#else 
#include "VnpcSimTop_ysyx_23060246_regs_16x32.h"
#endif  // ! DONT_USE_REG0
#else 
#ifdef DONT_USE_REG0
#include "VnpcSimTop_ysyx_23060246_regs_31x32.h"
#else
#include "VnpcSimTop_ysyx_23060246_regs_32x32.h"
#endif // ! DONT_USE_REG0
#endif // ! CONFIG_RVE
#include "VnpcSimTop_ysyx_23060246.h"
#include "VnpcSimTop_ysyx_23060246_npc.h"
#include "VnpcSimTop_ysyx_23060246_WBU.h"
//#include "VnpcSimTop_ysyx_23060246_LSU.h"
#include "VnpcSimTop_ysyx_23060246_LSU_AREA.h"
#include "VnpcSimTop_ysyx_23060246_IDU.h"
#include "VnpcSimTop_ysyx_23060246_IFU.h"
#ifdef CONFIG_USE_ICACHE
//#include "VnpcSimTop_ICache.h"
#endif 
//#include "Vysyx_23060246_CPU.h"
#endif 

#ifdef CONFIG_WAVE_VCD
#include <verilated_vcd_c.h>
#endif 
#ifdef CONFIG_WAVE_FST 
#include <verilated_fst_c.h>
#endif 

#ifdef USE_NVBOARD
#include <nvboard.h>
#endif 

#define VTOP_NAME MUXDEF(USE_SOC, VysyxSoCFull, VnpcSimTop)


extern VTOP_NAME* top ;

#define NPC_CPU MUXDEF(USE_SOC, (top->ysyxSoCFull->asic->cpu->cpu->cpu_npc), \
                        (top->npcSimTop->ysyx_23060246->cpu_npc))

#define REGS (NPC_CPU->regfile->regs_ext->Memory)
#define PC (NPC_CPU->wbu->io_in_bits_pc)
#define NPC (NPC_CPU->wbu->io_in_bits_npc)
#define CSR (NPC_CPU->exu->csr)
#define WBU_VALID (NPC_CPU->wbu->wbu_valid)
// #define INST (NPC_CPU->ifu->io_out_bits_inst)
#define INST (NPC_CPU->wbu->io_in_bits_inst)
#endif // !_VERILATOR_H_


