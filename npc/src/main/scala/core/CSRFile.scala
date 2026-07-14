package top
import chisel3._
import chisel3.util._
class CSRFile extends Module {
  val io = IO(new Bundle {
    val raddr = Input(UInt(12.W))
    val rdata = Output(UInt(32.W))
    val waddr = Input(UInt(12.W))
    val wdata = Input(UInt(32.W))
    val wen   = Input(Bool())

    val excValid    = Input(Bool())
    val excType = Input(ExceptionType())
    val excPc = Input(UInt(32.W))
    val mret     = Input(Bool())
    val wbuRedirectPc = Output(UInt(32.W))
    val dpic = Output(Vec(4,UInt(32.W)))
  })

  val mepc      = Reg(UInt(32.W))
  val mstatus   = Reg(UInt(32.W))
  val mcause    = Reg(UInt(32.W))
  val mtvec     = Reg(UInt(32.W))
  // val mcycle    = Wire(UInt(32.W))
  // val mcycleh   = Wire(UInt(32.W))
  val mvendorid = WireInit(0x79737978.U(32.W))
  val marchid   = WireInit(0x18ce1b4.U(32.W))

  io.rdata := mepc

  io.wbuRedirectPc:=mtvec

  when(io.excValid) {
    mepc        := io.excPc
    mcause      := io.excType.asUInt
    io.wbuRedirectPc := mtvec
  }.elsewhen(io.mret) {
    io.wbuRedirectPc := mepc
  }
  // 写
  when(io.wen) {
    switch(io.waddr) {
      is(0x341.U) { mepc := io.wdata }
      is(0x300.U) { mstatus := io.wdata }
      is(0x342.U) { mcause := io.wdata }
      is(0x305.U) { mtvec := io.wdata }
    }
  }
  // 读
  switch(io.raddr) {
    is(0x341.U) { io.rdata := mepc }
    is(0x300.U) { io.rdata := mstatus }
    is(0x342.U) { io.rdata := mcause }
    is(0x305.U) { io.rdata := mtvec }
    // is(0xb00.U) { io.rdata := mcycle }
    // is(0xb80.U) { io.rdata := mcycleh }
    is(0xf11.U) { io.rdata := mvendorid }
    is(0xf12.U) { io.rdata := marchid }
  }

  // val time = RegInit(0.U(64.W))
    // time := time + 1.U

      // mcycle  := time(31, 0)
        // mcycleh := time(63, 32)

  io.dpic(0) :=mepc
  io.dpic(1) :=mstatus
  io.dpic(2) :=mcause
  io.dpic(3) :=mtvec
}
