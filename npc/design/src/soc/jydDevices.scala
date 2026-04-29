package jyd

import chisel3._
import chisel3.util._

import axi4._
import xbar._
import uart._

import top.{CPUCoreAsBlackBox, PCProviderAsBlackBox}
import testSoC._

object AddrSpace {
  val IROM = ("h80000000".U, "h80004000".U)
  val DRAM = ("h80100000".U, "h80140000".U)
  val MMIO = ("h80200000".U, "h80200100".U)

  val LED = ("h80200040".U, "h80200044".U)
  val SEG = ("h80200020".U, "h80200024".U)

  val CNT = ("h80200050".U, "h80200054".U)

  object SelfExtSpace {
    val UART = ("h10000000".U, "h10001000".U)
  }

  def needSkipDifftestGroup = Seq(
    MMIO,
    SelfExtSpace.UART
  )
}

object RChanelFSM {
  def apply(arvalid: Bool, rready: Bool): Bool = {
    object State extends ChiselEnum {
      val idle, waitReady = Value
    }
    val state = RegInit(State.idle)
    state := MuxLookup(state, State.idle)(
      Seq(
        State.idle      -> Mux(arvalid, State.waitReady, State.idle),
        State.waitReady -> Mux(rready, State.idle, State.waitReady)
      )
    )
    state === State.waitReady
  }
}

class OneWordRWDevice(updFuncName: String) extends Module {
  val io = IO(AXI4IO.Slave)
  io := DontCare

  val sio = io

  sio.awready := true.B
  sio.wready  := true.B

  sio.bvalid := true.B
  sio.bresp  := AXI4IO.BResp.OKAY

  val dataReg = RegEnable(sio.wdata, 0.U, sio.wvalid)

  io.arready := true.B
  io.rvalid  := RChanelFSM(sio.arvalid, io.rready)
  io.rdata   := dataReg
  io.rresp   := AXI4IO.RResp.OKAY
  io.rlast   := true.B

  when(sio.wvalid) {
    dpiwrap.ClockedCallVoidDPIC(updFuncName)(clock, sio.wvalid, sio.wdata)
  }
}

class Timer extends Module {
  val io = IO(AXI4IO.Slave)
  io := DontCare

  object State extends ChiselEnum {
    val idle, ticking, finished = Value
  }

  val MAGIC_START = "h80000000".U
  val MAGIC_STOP  = "hffffffff".U

  val state = RegInit(State.idle)
  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle     -> Mux(io.wvalid && io.wdata === MAGIC_START, State.ticking, State.idle),
      State.ticking  -> Mux(io.wvalid && io.wdata === MAGIC_STOP, State.finished, State.ticking),
      State.finished -> State.finished
    )
  )
  val timer = RegInit(0.U(32.W))
  timer := Mux(state === State.ticking, timer + 1.U, timer)

  // when(io.wvalid && io.wready) {
  //   when(io.wdata === MAGIC_START) {
  //     printf("Timer start!\n")
  //   }.elsewhen(io.wdata === MAGIC_STOP) {
  //     printf("Timer stop! Final value: %d\n", timer)
  //   }
  // }

  io.awready := true.B
  io.wready  := true.B
  io.bvalid  := true.B
  io.bresp   := AXI4IO.BResp.OKAY

  io.arready := true.B
  io.rvalid  := RChanelFSM(io.arvalid, io.rready)
  io.rdata   := timer
  io.rresp   := AXI4IO.RResp.OKAY
  io.rlast   := true.B
}

class JYDDevices extends Module with TestSoCDevice {
  val io = IO(AXI4IO.Slave)
  io := DontCare

  val uart = Module(new UARTUnit)
  val irom = Module(new AXI4MemUnit(1024 * 16))
  val dram = Module(new AXI4MemUnit(1024 * 256))

  val led = Module(new OneWordRWDevice("jyd_update_led"))
  val seg = Module(new OneWordRWDevice("jyd_update_seg"))

  val cnt = Module(new Timer)

  io <> AXI4XBar(
    Seq(
      AddrSpace.IROM              -> irom.io,
      AddrSpace.DRAM              -> dram.io,
      AddrSpace.LED               -> led.io,
      AddrSpace.SEG               -> seg.io,
      AddrSpace.CNT               -> cnt.io,
      AddrSpace.SelfExtSpace.UART -> uart.io
    )
  )
}
