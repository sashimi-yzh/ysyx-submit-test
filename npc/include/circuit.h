#ifndef __CIRCUIT_H__
#define __CIRCUIT_H__

#ifdef NPCCONFIG_TOP_IS_YSYXSOC
#include <VysyxSoCFull___024root.h>
#include <VysyxSoCFull__Dpi.h>
#include <VysyxSoCFull.h>
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
#include <VNPC___024root.h>
#include <VNPC__Dpi.h>
#include <VNPC.h>
#endif

#include <verilated.h>
#include <verilated_vcd_c.h>
#include <verilated_fst_c.h>
#include <svdpi.h>
#include <common.h>

#ifdef NPCCONFIG_TOP_IS_YSYXSOC
extern VysyxSoCFull *top;
static inline VysyxSoCFull* init_top() {
    return new VysyxSoCFull("top");
}
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
extern VNPC *top;
static inline VNPC* init_top() {
    return new VNPC("top");
}
#endif


//circuit
void single_cycle();
void cpu_exec(uint64_t n);
void reset(int i);



#define BITMASK(bits) ((1ull << (bits)) - 1)
#define BITS(x, hi, lo) (((x) >> (lo)) & BITMASK((hi) - (lo) + 1)) // similar to x[hi:lo] in verilog
#define SEXT(x, len) ({ struct { int64_t n : len; } __x = { .n = x }; (uint64_t)__x.n; })
#define JAL  0b1101111
#define JALR 0b1100111

//processunit
#define PROCESSUNIT_ALU 0
#define PROCESSUNIT_CSR 1
#define PROCESSUNIT_LSU 2

//instr
#define INST_JAL  0b1101111
#define INST_JALR 0b1100111
#define INST_STORE 0b0100011
#define INST_BRANCH 0b1100011
#define INST_LOAD 0b0000011
#define INST_CSR 0b1110011

#ifdef NPCCONFIG_TOP_IS_YSYXSOC
#define ISEBREAK top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__idu__DOT__ebreak__DOT__isEbreak
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
#define ISEBREAK top->rootp->NPC__DOT__cpu__DOT__core__DOT__idu__DOT__ebreak__DOT__isEbreak
#endif


















#ifndef NPCCONFIG_CI




#ifdef NPCCONFIG_TOP_IS_YSYXSOC

//vals
#define PC top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu_io_pipe_in_bits_r_diff_pc
#define INSTR  top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu_io_pipe_in_bits_r_diff_inst
#define VGPR ((uint32_t[32]){ \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[0], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[1], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[2], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[3], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[4], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[5], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[6], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[7], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[8], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[9], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[10], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[11], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[12], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[13], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[14], \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[15], \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0 \
})
#define VCSR ((uint32_t[32]){ \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mstatus, \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mtvec, \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mepc, \
    top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mcause \
})

#define DIFFVALID top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu__DOT__diffvalid

//PerfAnalysis
#define CYC_START (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_pipe_out_valid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_pipe_out_ready)
/*认为ifu发起取指令为一个新的周期*/
#define CYC_END (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_out_valid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_out_ready)
/*认为wbu处理结束的out握手为周期结束*/

#define INST_VALID (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_in_valid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_in_ready)

#define EV_IFU_GETINST_FIRE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_arvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_arready)
#define EV_LSU_READDATA_FIRE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_arvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_arready)
#define EV_LSU_WRITEDATA_FIRE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_awvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_awready)
#define EV_EXU_FSHCAL_FIRE ((top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_valid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_ready) \
                           && top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_bits_is2exe_processunit == PROCESSUNIT_ALU)
#define IFU_GETINST_DONE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_rvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_rready)
#define LSU_READDATA_DONE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_rvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_rready)
#define LSU_WRITEDATA_DONE (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_bvalid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_bready)
#define EXU_FSHCAL_DONE ((top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_out_valid & top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_out_ready) \
                           && top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_bits_is2exe_processunit == PROCESSUNIT_ALU)


#define IS_STORE (BITS(INSTR, 6, 0) == INST_STORE)
#define IS_LOAD (BITS(INSTR, 6, 0) == INST_LOAD)
#define IS_BRANCH (BITS(INSTR, 6, 0) == INST_BRANCH)
#define IS_JUMP (BITS(INSTR, 6, 0) == INST_JAL || BITS(INSTR, 6, 0) == INST_JALR)
#define IS_CSR (BITS(INSTR, 6, 0) == INST_CSR && BITS(INSTR, 14, 12) != 0)
#define IS_OTHER (BITS(INSTR, 6, 0) != 0 && \
                 BITS(INSTR, 6, 0) != INST_STORE && \
                 BITS(INSTR, 6, 0) != INST_LOAD && \
                 BITS(INSTR, 6, 0) != INST_BRANCH && \
                 BITS(INSTR, 6, 0) != INST_JAL && \
                 BITS(INSTR, 6, 0) != INST_JALR && \
                 BITS(INSTR, 6, 0) != INST_CSR)

#define IS_HIT (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__icache__DOT__c_state == 1 && top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__icache__DOT__hit == 1)
#define INST_ADDR_IS_SDRAM (top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_araddr >= 0xa0000000 && top->rootp->ysyxSoCFull__DOT__asic__DOT__cpu__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_araddr <= 0xbfffffff)

#define EV_ICACHE_FIRE (CYC_START & INST_ADDR_IS_SDRAM)

#define EV_ICACHE_HIT_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 1)
#define EV_ICACHE_MISS_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 0)



#endif
#ifdef NPCCONFIG_TOP_IS_NPC


//vals
#define PC top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu_io_pipe_in_bits_r_diff_pc
#define INSTR  top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu_io_pipe_in_bits_r_diff_inst
#define VGPR ((uint32_t[32]){ \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[0], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[1], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[2], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[3], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[4], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[5], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[6], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[7], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[8], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[9], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[10], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[11], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[12], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[13], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[14], \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__isu__DOT__gpr_ext__DOT__Memory[15], \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0 \
})
#define VCSR ((uint32_t[32]){ \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mstatus, \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mtvec, \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mepc, \
    top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__csr__DOT__mcause \
})

#define DIFFVALID top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu__DOT__diffvalid

//PerfAnalysis
#define CYC_START (top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_pipe_out_valid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_pipe_out_ready)
/*认为ifu发起取指令为一个新的周期*/
#define CYC_END (top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_out_valid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_out_ready)
/*认为wbu处理结束的out握手为周期结束*/

#define INST_VALID (top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_in_valid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__wbu__DOT__io_pipe_in_ready)

#define EV_IFU_GETINST_FIRE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_arvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_arready)
#define EV_LSU_READDATA_FIRE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_arvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_arready)
#define EV_LSU_WRITEDATA_FIRE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_awvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_awready)
#define EV_EXU_FSHCAL_FIRE ((top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_valid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_ready) \
                           && top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_bits_is2exe_processunit == PROCESSUNIT_ALU)
#define IFU_GETINST_DONE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_rvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_rready)
#define LSU_READDATA_DONE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_rvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_rready)
#define LSU_WRITEDATA_DONE (top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_bvalid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__lsu__DOT__io_dmem_dmem_bready)
#define EXU_FSHCAL_DONE ((top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_out_valid & top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_out_ready) \
                           && top->rootp->NPC__DOT__cpu__DOT__core__DOT__exu__DOT__io_pipe_in_bits_is2exe_processunit == PROCESSUNIT_ALU)


#define IS_STORE (BITS(INSTR, 6, 0) == INST_STORE)
#define IS_LOAD (BITS(INSTR, 6, 0) == INST_LOAD)
#define IS_BRANCH (BITS(INSTR, 6, 0) == INST_BRANCH)
#define IS_JUMP (BITS(INSTR, 6, 0) == INST_JAL || BITS(INSTR, 6, 0) == INST_JALR)
#define IS_CSR (BITS(INSTR, 6, 0) == INST_CSR && BITS(INSTR, 14, 12) != 0)
#define IS_OTHER (BITS(INSTR, 6, 0) != 0 && \
                 BITS(INSTR, 6, 0) != INST_STORE && \
                 BITS(INSTR, 6, 0) != INST_LOAD && \
                 BITS(INSTR, 6, 0) != INST_BRANCH && \
                 BITS(INSTR, 6, 0) != INST_JAL && \
                 BITS(INSTR, 6, 0) != INST_JALR && \
                 BITS(INSTR, 6, 0) != INST_CSR)

#define IS_HIT (top->rootp->NPC__DOT__cpu__DOT__core__DOT__icache__DOT__c_state == 1 && top->rootp->NPC__DOT__cpu__DOT__core__DOT__icache__DOT__hit == 1)
#define INST_ADDR_IS_SDRAM (top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_araddr >= 0xa0000000 && top->rootp->NPC__DOT__cpu__DOT__core__DOT__ifu__DOT__io_imem_araddr <= 0xbfffffff)

#define EV_ICACHE_FIRE (CYC_START & INST_ADDR_IS_SDRAM)

#define EV_ICACHE_HIT_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 1)
#define EV_ICACHE_MISS_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 0)


#endif




































#else































#ifdef NPCCONFIG_TOP_IS_YSYXSOC
    #define PC 0
#endif
#ifdef NPCCONFIG_TOP_IS_NPC
    #define PC 0
#endif

#define INSTR  0
#define VGPR ((uint32_t[32]){ \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0, \
    0 \
})
#define VCSR ((uint32_t[32]){ \
    0, \
    0, \
    0, \
    0 \
})

#define DIFFVALID 0

//PerfAnalysis
#define CYC_START 0
/*认为ifu发起取指令为一个新的周期*/
#define CYC_END 0
/*认为wbu处理结束的out握手为周期结束*/

#define INST_VALID 0

#define EV_IFU_GETINST_FIRE 0
#define EV_LSU_READDATA_FIRE 0
#define EV_LSU_WRITEDATA_FIRE 0
#define EV_EXU_FSHCAL_FIRE 0
#define IFU_GETINST_DONE 0
#define LSU_READDATA_DONE 0
#define LSU_WRITEDATA_DONE 0
#define EXU_FSHCAL_DONE 0


#define IS_STORE (BITS(INSTR, 6, 0) == INST_STORE)
#define IS_LOAD (BITS(INSTR, 6, 0) == INST_LOAD)
#define IS_BRANCH (BITS(INSTR, 6, 0) == INST_BRANCH)
#define IS_JUMP (BITS(INSTR, 6, 0) == INST_JAL || BITS(INSTR, 6, 0) == INST_JALR)
#define IS_CSR (BITS(INSTR, 6, 0) == INST_CSR && BITS(INSTR, 14, 12) != 0)
#define IS_OTHER (BITS(INSTR, 6, 0) != 0 && \
                 BITS(INSTR, 6, 0) != INST_STORE && \
                 BITS(INSTR, 6, 0) != INST_LOAD && \
                 BITS(INSTR, 6, 0) != INST_BRANCH && \
                 BITS(INSTR, 6, 0) != INST_JAL && \
                 BITS(INSTR, 6, 0) != INST_JALR && \
                 BITS(INSTR, 6, 0) != INST_CSR)

#define IS_HIT 0
#define INST_ADDR_IS_SDRAM 0

#define EV_ICACHE_FIRE (CYC_START & INST_ADDR_IS_SDRAM)

#define EV_ICACHE_HIT_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 1)
#define EV_ICACHE_MISS_FIRE (INST_VALID & INST_ADDR_IS_SDRAM & IS_HIT == 0)

#endif















//nvboard
#ifdef NV_BOARD
#include <nvboard.h>
void nvboard_bind_all_pins(VysyxSoCFull *top);
#endif






#endif
