package npc.common

import chisel3._
import chisel3.util._

object Config{
    val ENABLE_DELAY = false
    val IFU_DELAY = 0.U(4.W)
    val LSU_DELAY = 0.U(4.W)

    val WORD_LEN = 32
    val BYTE_LEN = 8

    // val START_ADDR = "h30000000".U(WORD_LEN.W) /*THIS IS NPC MODE*/
    // val START_ADDR = "h20000000".U(WORD_LEN.W) /*THIS IS MROM MODE*/
    val START_ADDR = "h30000000".U(WORD_LEN.W) /*THIS IS FLASH MODE*/

    val GPR_NUM = 16
    val ADDR_LEN = 4 // rs1,rs2,wb
    val CSR_ADDR_LEN = 12

    val DIFFTEST = false

    val RENAME = true
}

object ProcessUnit{
    val ProcessUnit_Width = 3
    def ALU = 0.U(ProcessUnit_Width.W)
    def CSR = 1.U(ProcessUnit_Width.W)
    def LSU = 2.U(ProcessUnit_Width.W)
    def MOU = 3.U(ProcessUnit_Width.W)//for fence.i
    def XXX = 4.U(ProcessUnit_Width.W)
}

object ProcessTpe{
    val ProcessTpe_Width = 4
    object ALU {
        def ALU_ADD    =  "b1000".U(ProcessTpe_Width.W)
        def ALU_SUB    =  "b1001".U(ProcessTpe_Width.W)

        def ALU_AND    =  "b0000".U(ProcessTpe_Width.W)
        def ALU_COMPS  =  "b0001".U(ProcessTpe_Width.W)
        def ALU_XOR    =  "b0010".U(ProcessTpe_Width.W)
        def ALU_COMPU  =  "b0011".U(ProcessTpe_Width.W)
        def ALU_OR     =  "b0100".U(ProcessTpe_Width.W)
        def ALU_SRA    =  "b0101".U(ProcessTpe_Width.W)
        def ALU_SRL    =  "b0110".U(ProcessTpe_Width.W)
        def ALU_SLL    =  "b0111".U(ProcessTpe_Width.W)
    }
    object CSR {
        def CSR_W      =  0.U(ProcessTpe_Width.W)
        def CSR_S      =  1.U(ProcessTpe_Width.W)
        def CSR_MRET   =  2.U(ProcessTpe_Width.W)
        def CSR_ECALL  =  3.U(ProcessTpe_Width.W)
    }
    object LSU {
        def LSU_LB     =  "b0000".U(ProcessTpe_Width.W)
        def LSU_LH     =  "b0001".U(ProcessTpe_Width.W)
        def LSU_LW     =  "b0010".U(ProcessTpe_Width.W)
        def LSU_LBU    =  "b0100".U(ProcessTpe_Width.W)
        def LSU_LHU    =  "b0101".U(ProcessTpe_Width.W)
        def LSU_SB     =  "b1000".U(ProcessTpe_Width.W)
        def LSU_SH     =  "b1001".U(ProcessTpe_Width.W)
        def LSU_SW     =  "b1010".U(ProcessTpe_Width.W)
    }
}

object BJTpe{
    val BJTpe_Width = 4
    def BJ_X      = "b0000".U(BJTpe_Width.W)
    def BJ_BEQ    = "b0001".U(BJTpe_Width.W)
    def BJ_BNE    = "b0010".U(BJTpe_Width.W)
    def BJ_BLTU   = "b0011".U(BJTpe_Width.W)
    def BJ_BLT    = "b0100".U(BJTpe_Width.W)
    def BJ_BGEU   = "b0101".U(BJTpe_Width.W)
    def BJ_BGE    = "b0110".U(BJTpe_Width.W)

    def BJ_J      = "b1000".U(BJTpe_Width.W)
    def BJ_JR     = "b1001".U(BJTpe_Width.W)
}

object CH1Tpe{
    val CH1Tpe_Width = 1
    def CH1Tpe_RS1   = 0.U(CH1Tpe_Width.W)
    def CH1Tpe_PC    = 1.U(CH1Tpe_Width.W)
}

object CH2Tpe{
    val CH2Tpe_Width = 2
    def CH2Tpe_RS2        = 0.U(CH2Tpe_Width.W)
    def CH2Tpe_IMM        = 1.U(CH2Tpe_Width.W)
    def CH2Tpe_CSR_ADDR   = 3.U(CH2Tpe_Width.W)
    def CH2Tpe_4          = 2.U(CH2Tpe_Width.W)
}

object RFwe{
    val RFwe_Width = 1
    def RFwe_y = 0.U(RFwe_Width.W)
    def RFwe_n = 1.U(RFwe_Width.W)
}

object IMMTpe{
    val IMMTpe_Width = 3
    def IMM_TYPE_X = 0.U(IMMTpe_Width.W)
    def IMM_TYPE_B = 1.U(IMMTpe_Width.W)
    def IMM_TYPE_I = 2.U(IMMTpe_Width.W)
    def IMM_TYPE_S = 3.U(IMMTpe_Width.W)
    def IMM_TYPE_J = 4.U(IMMTpe_Width.W)
    def IMM_TYPE_U = 5.U(IMMTpe_Width.W)
}