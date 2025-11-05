package cpu

import chisel3._
import chisel3.util._


class ysyx_23060246_Forward(config: NPCConfig) extends Module {
    val io = IO(new Bundle {
        val idu_rs1 = Input(UInt(5.W))
        val idu_rs2 = Input(UInt(5.W))

        val exu_rd = Input(UInt(5.W))
        val lsu_rd = Input(UInt(5.W))
        val wbu_rd = Input(UInt(5.W))

        // inst type
        val exu_itype = Input(UInt(4.W))
        val lsu_itype = Input(UInt(4.W))
        val wbu_itype = Input(UInt(4.W))

        val forward_A = Output(UInt(2.W))
        val forward_B = Output(UInt(2.W))
    })
    
    
    def writeReg(itype: UInt): Bool = {
        // writeReg R,I,S,B,U,J
        val writeReg = itype === inst_type.R_TYPE || 
                       itype === inst_type.I_TYPE || 
                       itype === inst_type.U_TYPE || 
                       itype === inst_type.J_TYPE ||
                       itype === inst_type.FENCE_TYPE

        writeReg
    }

    def forwardFrom(IDU_rs1: UInt, rd: UInt, itype: UInt): Bool = {
        val ret = IDU_rs1.orR && (IDU_rs1 === rd) && writeReg(itype)
        ret
    }
    val exu_forward_a = forwardFrom(io.idu_rs1, io.exu_rd, io.exu_itype)
    val lsu_forward_a = forwardFrom(io.idu_rs1, io.lsu_rd, io.lsu_itype)
    val wbu_forward_a = forwardFrom(io.idu_rs1, io.wbu_rd, io.wbu_itype)
    dontTouch(exu_forward_a)
    dontTouch(lsu_forward_a)
    dontTouch(wbu_forward_a)
    io.forward_A := Mux(exu_forward_a, forward_sel.FWD_EXU, 
                    Mux(lsu_forward_a, forward_sel.FWD_LSU, 
                    Mux(wbu_forward_a, forward_sel.FWD_WBU, forward_sel.FWD_XX)))

    val exu_forward_b = forwardFrom(io.idu_rs2, io.exu_rd, io.exu_itype)
    val lsu_forward_b = forwardFrom(io.idu_rs2, io.lsu_rd, io.lsu_itype)
    val wbu_forward_b = forwardFrom(io.idu_rs2, io.wbu_rd, io.wbu_itype)
    dontTouch(exu_forward_b)
    dontTouch(lsu_forward_a)
    dontTouch(wbu_forward_b)
    io.forward_B := Mux(exu_forward_b, forward_sel.FWD_EXU, 
                    Mux(lsu_forward_b, forward_sel.FWD_LSU, 
                    Mux(wbu_forward_b, forward_sel.FWD_WBU, forward_sel.FWD_XX)))
}