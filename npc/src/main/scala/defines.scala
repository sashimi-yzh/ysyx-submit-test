package cpu

import chisel3._

// object defines {
//   val USE_SOC = false
//   val XLEN = 32
//   val PC_INIT = if(USE_SOC) "h30000000".U(XLEN.W) else "h80000000".U(XLEN.W)
//   val MSTATUS_INIT = 0x1800
//   val MTVEC_INIT = 0x100
//   val AXI_IDBITS = 4
//   val CLINT_BASE = if(USE_SOC) 0x02000000L else 0xa0000040L
//   val CLINT_END = if(USE_SOC) 0x0200ffffL else 0xa0000050L
//   val PERF_CNT = true
// }



object pc_sel {
  val PC_4  = 0.U(2.W)
  val PC_0  = 1.U(2.W)
  val PC_ALU = 2.U(2.W)
  val PC_CSR = 3.U(2.W)
}

object A_sel {
  val A_PC  = 0.U(1.W)
  val A_RS1 = 1.U(1.W)
}

object B_sel {
  val B_IMM  = 0.U(2.W)
  val B_RS2  = 1.U(2.W)
}

object imm_sel {
  val IMM_I = 0.U(3.W)
  val IMM_U = 1.U(3.W)
  val IMM_S = 2.U(3.W)
  val IMM_J = 3.U(3.W)
  val IMM_B = 4.U(3.W)
}

// wb from alu, mem, pc or xx
object wb_sel {
  val WB_XX  = 0.U(3.W)
  val WB_ALU = 1.U(3.W)
  val WB_MEM = 2.U(3.W)
  val WB_PC4  = 3.U(3.W)
  val WB_CSR = 4.U(3.W)
  
}

object st_sel {
  val ST_XX  = 0.U(2.W)
  val ST_SW  = 1.U(2.W)
  val ST_SH  = 2.U(2.W)
  val ST_SB  = 3.U(2.W)
  
}

object ld_sel {
  val LD_XX  = 0.U(3.W)
  val LD_LW  = 1.U(3.W)
  val LD_LH  = 2.U(3.W)
  val LD_LB  = 3.U(3.W)
  val LD_LBU = 4.U(3.W)
  val LD_LHU = 5.U(3.W)
  
}


object mask_sel {
  val MASK_XX = 0x00.U(8.W)
  val MASK_B  = 0x01.U(8.W)
  val MASK_H  = 0x03.U(8.W)
  val MASK_W  = 0x0f.U(8.W)
}

object br_sel {
  val BR_EQ  = 0.U(3.W)
  val BR_NE  = 1.U(3.W)
  val BR_LTU = 2.U(3.W)
  val BR_GE  = 3.U(3.W)
  val BR_GEU = 4.U(3.W)
  val BR_LT  = 5.U(3.W)
  val BR_XX  = 6.U(3.W)
}

object csr_cmd {
  val CSR_W = 0.U(3.W)
  val CSR_S = 1.U(3.W)
  val CSR_C = 2.U(3.W)
  val CSR_P = 3.U(3.W)
  val CSR_XX = 4.U(3.W)
}

object csr_addr {
  val CSR_MSTATUS = 0x300.U(12.W)
  val CSR_MTVEC   = 0x305.U(12.W)
  val CSR_MEPC    = 0x341.U(12.W)
  val CSR_MCAUSE  = 0x342.U(12.W)
  val CSR_VENDORID= 0xF11.U(12.W)
  val CSR_MARCHID = 0xF12.U(12.W)
}

object valid {
  val INST_VALID   = 0.U(1.W)
  val INST_INVALID = 1.U(1.W)
}

object inst_type {
  val N_TYPE = 0.U(4.W)
  val R_TYPE = 1.U(4.W)
  val I_TYPE = 2.U(4.W)
  val S_TYPE = 3.U(4.W)
  val B_TYPE = 4.U(4.W)
  val U_TYPE = 5.U(4.W)
  val J_TYPE = 6.U(4.W)
  val ICSR_TYPE = 7.U(4.W)
  val FENCE_TYPE = 8.U(4.W)
}

object forward_sel {
  val FWD_XX = 0.U(2.W)
  val FWD_EXU = 1.U(2.W)
  val FWD_LSU = 2.U(2.W)
  val FWD_WBU = 3.U(2.W)
}