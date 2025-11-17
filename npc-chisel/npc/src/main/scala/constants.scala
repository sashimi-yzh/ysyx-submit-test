//**************************************************************************
// RISCV Processor Constants
//--------------------------------------------------------------------------
//
// Christopher Celio
// 2011 May 28
// Modified from github.com/ucb-bar/riscv-sodor

package npc
package constants
{

import chisel3._
import chisel3.util._

trait RISCVConstants
{
   // abstract out instruction decode magic numbers
   val RD_MSB  = 11
   val RD_LSB  = 7
   val RS1_MSB = 19
   val RS1_LSB = 15
   val RS2_MSB = 24
   val RS2_LSB = 20

   val CSR_ADDR_MSB = 31
   val CSR_ADDR_LSB = 20

   val X0 = 0.U

   // The Bubble Instruction (Machine generated NOP)
   // Insert (XOR x0,x0,x0) which is different from software compiler
   // generated NOPs which are (ADDI x0, x0, 0).
   // Reasoning for this is to let visualizers and stat-trackers differentiate
   // between software NOPs and machine-generated Bubbles in the pipeline.
   val BUBBLE  = 0x4033.U(32.W)
}

trait NPCProcConstants
{
   // for debugging, print out the commit information.
   // can be compared against the riscv-isa-run Spike ISA simulator's commit logger.
   val PRINT_COMMIT_LOG = false
}


trait ExceptionCodesConstants {
  // 异常号定义 (符合 RISC-V 特权规范)
  val EXC_NORMAL                  = 0.U(5.W)
  val EXC_INSTR_ADDR_MISALIGNED   = 0x10.U(5.W)
  val EXC_INSTR_ACCESS_FAULT      = 0x11.U(5.W)
  val EXC_ILLEGAL_INSTR           = 0x12.U(5.W)
  val EXC_BREAKPOINT              = 0x13.U(5.W)
  val EXC_LOAD_ADDR_MISALIGNED    = 0x14.U(5.W)
  val EXC_LOAD_ACCESS_FAULT       = 0x15.U(5.W)
  val EXC_STORE_ADDR_MISALIGNED   = 0x16.U(5.W)
  val EXC_STORE_ACCESS_FAULT      = 0x17.U(5.W)
  val EXC_ECALL_U_MODE            = 0x18.U(5.W)
  val EXC_ECALL_S_MODE            = 0x19.U(5.W)
  val EXC_ECALL_M_MODE            = 0x1b.U(5.W)
  val EXC_INSTR_PAGE_FAULT        = 0x1c.U(5.W)
  val EXC_LOAD_PAGE_FAULT         = 0x1d.U(5.W)
  val EXC_STORE_PAGE_FAULT        = 0x1f.U(5.W)
}


trait ScalarOpConstants
{
   //************************************
   // Control Signals
   val Y        = true.B
   val N        = false.B

   // PC Select Signal
   val PC_4     = 0.asUInt(2.W)  // PC + 4
   val PC_BRJMP = 1.asUInt(2.W)  // brjmp_target
   val PC_JALR  = 2.asUInt(2.W)  // jump_reg_target
   val PC_EXC   = 3.asUInt(2.W)  // exception

   // Branch Type
   val BR_N     = 0.asUInt(4.W)  // Next
   val BR_NE    = 1.asUInt(4.W)  // Branch on NotEqual
   val BR_EQ    = 2.asUInt(4.W)  // Branch on Equal
   val BR_GE    = 3.asUInt(4.W)  // Branch on Greater/Equal
   val BR_GEU   = 4.asUInt(4.W)  // Branch on Greater/Equal Unsigned
   val BR_LT    = 5.asUInt(4.W)  // Branch on Less Than
   val BR_LTU   = 6.asUInt(4.W)  // Branch on Less Than Unsigned
   val BR_J     = 7.asUInt(4.W)  // Jump
   val BR_JR    = 8.asUInt(4.W)  // Jump Register

   // RS1 Operand Select Signal
   val OP1_RS1   = 0.asUInt(2.W) // Register Source #1
   val OP1_PC    = 1.asUInt(2.W) // PC
   val OP1_IMZ   = 2.asUInt(2.W) // Zero-extended Immediate from RS1 field, for use by CSRI instructions
   val OP1_X     = 0.asUInt(2.W)

   // RS2 Operand Select Signal
   val OP2_RS2    = 0.asUInt(3.W) // Register Source #2
   val OP2_ITYPE  = 1.asUInt(3.W) // immediate, I-type
   val OP2_STYPE  = 2.asUInt(3.W) // immediate, S-type
   val OP2_SBTYPE = 3.asUInt(3.W) // immediate, B
   val OP2_UTYPE  = 4.asUInt(3.W) // immediate, U-type
   val OP2_UJTYPE = 5.asUInt(3.W) // immediate, J-type
   val OP2_X      = 0.asUInt(3.W)

   // Register Operand Output Enable Signal
   val OEN_0   = false.B
   val OEN_1   = true.B

   // Register File Write Enable Signal
   val REN_0   = false.B
   val REN_1   = true.B

   // ALU Operation Signal
   val ALU_ADD    = 0.asUInt(4.W)
   val ALU_SUB    = 1.asUInt(4.W)
   val ALU_SLL    = 2.asUInt(4.W)
   val ALU_SRL    = 3.asUInt(4.W)
   val ALU_SRA    = 4.asUInt(4.W)
   val ALU_AND    = 5.asUInt(4.W)
   val ALU_OR     = 6.asUInt(4.W)
   val ALU_XOR    = 7.asUInt(4.W)
   val ALU_SLT    = 8.asUInt(4.W)
   val ALU_SLTU   = 9.asUInt(4.W)
   val ALU_COPY_1 = 10.asUInt(4.W)
   val ALU_COPY_2 = 11.asUInt(4.W)
   val ALU_X      = 0.asUInt(4.W)

   // Writeback Select Signal
   val WB_ALU  = 0.asUInt(2.W)
   val WB_MEM  = 1.asUInt(2.W)
   val WB_PC4  = 2.asUInt(2.W)
   val WB_CSR  = 3.asUInt(2.W)
   val WB_X    = 0.asUInt(2.W)

   // Memory Write Signal
   val MWR_0   = false.B
   val MWR_1   = true.B
   val MWR_X   = false.B

   // Memory Enable Signal
   val MEN_0   = false.B
   val MEN_1   = true.B
   val MEN_X   = false.B

   // Memory Mask Type Signal
   val MSK_B   = 0.asUInt(3.W)
   val MSK_BU  = 1.asUInt(3.W)
   val MSK_H   = 2.asUInt(3.W)
   val MSK_HU  = 3.asUInt(3.W)
   val MSK_W   = 4.asUInt(3.W)
   val MSK_X   = 4.asUInt(3.W)


   // Cache Flushes & Sync Primitives
   val M_N      = 0.asUInt(3.W)
   val M_SI     = 1.asUInt(3.W)   // synch instruction stream
   val M_SD     = 2.asUInt(3.W)   // synch data stream
   val M_FA     = 3.asUInt(3.W)   // flush all caches
   val M_FD     = 4.asUInt(3.W)   // flush data cache

   // Memory Functions (read, write, fence)
   val MT_READ  = 0.asUInt(2.W)
   val MT_WRITE = 1.asUInt(2.W)
   val MT_FENCE = 2.asUInt(2.W)



}

}
