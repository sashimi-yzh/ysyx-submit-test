package reg

import chisel3._
import chisel3.util._
import dto._

class RegFileRV32E extends Module {
  val io   = IO(new Bundle {
    // idu read 1
    val regReadAddr1 = Input(UInt(4.W))
    val regReadData1 = Output(UInt(32.W))
    // idu read 2
    val regReadAddr2 = Input(UInt(4.W))
    val regReadData2 = Output(UInt(32.W))
    // wbu
    val wbReq        = Input(new Wb2Reg)
  })
  val regs = RegInit(VecInit(Seq.fill(16)(0.U(32.W))))
  regs(0)         := 0.U
  when(io.wbReq.writeEn && io.wbReq.rd =/= 0.U) {
    regs(io.wbReq.rd) := io.wbReq.writeData
  }
  io.regReadData1 := Mux(io.regReadAddr1 === 0.U, 0.U, regs(io.regReadAddr1))
  io.regReadData2 := Mux(io.regReadAddr2 === 0.U, 0.U, regs(io.regReadAddr2))
}
