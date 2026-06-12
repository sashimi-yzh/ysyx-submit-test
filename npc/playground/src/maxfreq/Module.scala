package maxfreq

import chisel3._

class RegFile extends Module {
  val io = IO(new Bundle {
    val rAddr = Input(Vec(2, UInt(4.W)))
    val rData = Output(Vec(2, UInt(32.W)))
    val wEn   = Input(Bool())
    val wAddr = Input(UInt(4.W))
    val wData = Input(UInt(32.W))
  })

  val rAddr = RegNext(io.rAddr)
  val rData = Wire(chiselTypeOf(io.rData))
  io.rData := RegNext(rData)
  val wEn   = RegNext(io.wEn)
  val wAddr = RegNext(io.wAddr)
  val wData = RegNext(io.wData)

  val regFile = Reg(Vec(16, UInt(32.W)))
  when(wEn) {
    regFile(wAddr) := wData
  }
  regFile(0) := 0.U
  rData(0) := regFile(rAddr(0))
  rData(1) := regFile(rAddr(1))
}

class Adder extends Module {
  val io = IO(new Bundle {
    val a = Input(UInt(32.W))
    val b = Input(UInt(32.W))
    val out = Output(UInt(32.W))
  })
  io.out := RegNext(RegNext(io.a) + RegNext(io.b))
}
