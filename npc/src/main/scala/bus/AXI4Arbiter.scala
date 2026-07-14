package top

import chisel3._
import chisel3.util._

class AXI4Arbiter extends Module {
  val io    = IO(new Bundle {
    val sIFU = Flipped(new AXI4IO)
    val sLSU = Flipped(new AXI4IO)
    val m    = new AXI4IO
  })
  DriveZeroSinks(io) 

  object State extends ChiselEnum {
    val sIFU, sLSU = Value
  }
  val state = RegInit(State.sIFU)

  val sIFU_Finish = RegInit(false.B)
  val sLSU_Finish = RegInit(false.B)

  // 读通道仲裁
  switch(state) {
    is(State.sIFU) {
      io.sIFU.ar <> io.m.ar
      io.sIFU.r  <> io.m.r

      when(io.sIFU.ar.valid){
        sIFU_Finish := false.B
      }
      when(io.sIFU.r.ready && io.m.r.valid && io.m.r.last){
        sIFU_Finish := true.B
      }
      when(sIFU_Finish && !io.sIFU.ar.valid){
        when(io.sLSU.ar.valid){
          io.m.ar.valid := false.B
          io.sIFU.ar.ready := false.B

          state := State.sLSU
          sIFU_Finish := false.B
        }
      }
    }
    is(State.sLSU) {
      io.sLSU.ar <> io.m.ar
      io.sLSU.r  <> io.m.r

      when(io.sLSU.ar.valid){
        sLSU_Finish := false.B
      }
      when(io.sLSU.r.ready && io.m.r.valid && io.m.r.last){
        sLSU_Finish := true.B
      }
      when(sLSU_Finish){
        when(io.sIFU.ar.valid){
          io.m.ar.valid := false.B
          io.sLSU.ar.ready := false.B
          state := State.sIFU
          sLSU_Finish := false.B
        }
      }
    }
  }

  // 写通道只有LSU访问
  io.m.aw <> io.sLSU.aw
  io.m.w  <> io.sLSU.w
  io.m.b  <> io.sLSU.b
}