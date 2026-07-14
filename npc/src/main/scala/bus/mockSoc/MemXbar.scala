package top
import chisel3._
import chisel3.util._

class MemXbar extends Module {
  val io = IO(new Bundle {
    val s     = Flipped(new AXI4IO)
    val mUART = new AXI4IO
    val mRAM  = new AXI4IO
  })
  DriveZeroSinks(io)

  val UART = AddressSpace(0x10000000L, 0x4L)
  val RAM  = AddressSpace(0x80000000L, 1024 * 1024 * 64 * 8L)

  object State extends ChiselEnum {
    val sIdle, sUART, sRAM = Value
  }

  val wstate = RegInit(State.sIdle)
  switch(wstate) {
    is(State.sIdle) {
      when(io.s.aw.valid) {
        when(UART.contains(io.s.aw.addr)) {
          wstate := State.sUART
        }.otherwise {
          wstate := State.sRAM
        }
      }
    }
    is(State.sUART) {
      io.s.aw <> io.mUART.aw
      io.s.w  <> io.mUART.w
      io.s.b  <> io.mUART.b
      when(io.s.b.ready && io.mUART.b.valid) {
        wstate := State.sIdle
      }
    }
    is(State.sRAM) {
      io.s.aw <> io.mRAM.aw
      io.s.w  <> io.mRAM.w
      io.s.b  <> io.mRAM.b
      when(io.s.b.ready && io.mRAM.b.valid) {
        wstate := State.sIdle
      }
    }
  }

  val rstate = RegInit(State.sIdle)
  switch(rstate) {
    is(State.sIdle) {
      when(io.s.ar.valid) {
        when(UART.contains(io.s.ar.addr)) {
          rstate := State.sUART
        }.otherwise {
          rstate := State.sRAM
        }
      }
    }
    is(State.sUART) {
      io.s.r<>io.mUART.r
      io.s.ar<>io.mUART.ar
      when(io.s.r.ready && io.mUART.r.valid && io.mUART.r.last) {
        rstate := State.sIdle
      }
    }
    is(State.sRAM) {
      io.s.ar <> io.mRAM.ar
      io.s.r <> io.mRAM.r
      when(io.s.r.ready && io.mRAM.r.valid && io.mRAM.r.last) {
        rstate := State.sIdle
      }
    }
  }
}

case class AddressSpace(base: Long, size: Long) {
  def contains(addr: UInt): Bool =
    addr >= base.U && addr < (base + size).U

  def end: Long = base + size
}
