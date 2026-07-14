package top

import chisel3._
import chisel3.util._

class RegFile extends Module {
  val io = IO(new Bundle {
    val raddr1 = Input(UInt(5.W))
    val raddr2 = Input(UInt(5.W))
    val rdata1 = Output(UInt(32.W))
    val rdata2 = Output(UInt(32.W))
    val waddr  = Input(UInt(5.W))
    val wdata  = Input(UInt(32.W))
    val wen    = Input(Bool())
    val regs   = Output(Vec(16, UInt(32.W)))
  })

  val raddr1 = io.raddr1(3, 0)
  val raddr2 = io.raddr2(3, 0)
  val waddr  = io.waddr(3, 0)

  val regFile = Reg(Vec(16, UInt(32.W)))


  when(io.wen) {
    regFile(waddr) := io.wdata
  }
  regFile(0) := 0.U
  io.rdata1 := regFile(raddr1)
  io.rdata2 := regFile(raddr2)
  // 调试
  io.regs    := regFile
}
