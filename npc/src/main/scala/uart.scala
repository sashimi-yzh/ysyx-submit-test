package ysyx_23060246

import chisel3._
import chisel3.util._
import freechips.rocketchip.amba.axi4._

import AXI4._


class UART extends BlackBox {
  val io = IO(new Bundle {
    val clock = Input(Clock())
    val en = Input(Bool())
    val data = Input(UInt(8.W))
  })

}


class UART_AXI(params: AXI4BundleParameters) extends Module {
  val io = IO(new Bundle {
    //val axi = new AXILiteSlaveIF(addrWidthBits = 32, dataWidthBits = 32)
    val axi = Flipped(new AXI4Bundle(params))
  })

  val uart = Module(new UART)
  

  val s_idle :: s_wait_ready :: Nil = Enum(2)

  val state = RegInit(s_idle)
  state := MuxLookup(state, s_idle)(Seq(
    s_idle -> Mux(io.axi.w.valid, s_wait_ready, s_idle),
    s_wait_ready -> Mux(uart.io.en, s_idle, s_wait_ready)
  ))

  uart.io.clock := clock
  uart.io.en := io.axi.w.valid && state === s_wait_ready
  io.axi.w.ready := uart.io.en
  uart.io.data := io.axi.w.bits.data

  io.axi.aw.ready := true.B

  io.axi.b.valid := true.B
  io.axi.ar.ready := true.B
  io.axi.b.bits.id := 0.U 
  io.axi.b.bits.resp := 0.U 
  


  //不支持读
  io.axi.r.valid := false.B
  io.axi.r.bits.data := 0.U
  io.axi.r.bits.resp := 0.U
  io.axi.ar.ready := false.B
  io.axi.r.bits.id := 0.U 
  io.axi.r.bits.last := true.B
}