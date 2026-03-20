package cpu

import chisel3._
import chisel3.util._
import axi4._

// make exu and ifu access memory
class EXUIFU_MemVisitArbiter extends Module {
  val io = IO(new Bundle {
    val exu = AXI4IO.Slave
    val ifu = AXI4IO.Slave

    val out = AXI4IO.Master
  })

  // Simple arbiter
  //
  // exu has higher priority than ifu

  val ifuIO = io.ifu
  val exuIO = io.exu
  val outIO = io.out


  object State extends ChiselEnum {
    val idle, exuAccess, ifuAccess = Value
  }

  val txnDone = outIO.rvalid && outIO.rready && outIO.rlast

  val state = RegInit(State.idle)
  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle      -> Mux(exuIO.arvalid, State.exuAccess, Mux(ifuIO.arvalid, State.ifuAccess, State.idle)),
      State.exuAccess -> Mux(txnDone, Mux(ifuIO.arvalid, State.ifuAccess, State.idle), State.exuAccess),
      State.ifuAccess -> Mux(txnDone, Mux(exuIO.arvalid, State.exuAccess, State.idle), State.ifuAccess)
    )
  )

  val isExu = (state === State.exuAccess) || ((state === State.idle) && exuIO.arvalid)
  val isIfu = (state === State.ifuAccess) || ((state === State.idle) && !exuIO.arvalid && ifuIO.arvalid)

  // AR channel
  outIO.arvalid := (isExu && exuIO.arvalid) || (isIfu && ifuIO.arvalid)
  outIO.araddr  := Mux(isExu, exuIO.araddr, ifuIO.araddr)

  outIO.arid    := Mux(isExu, exuIO.arid, ifuIO.arid)
  outIO.arlen   := Mux(isExu, exuIO.arlen, ifuIO.arlen)
  outIO.arsize  := Mux(isExu, exuIO.arsize, ifuIO.arsize)
  outIO.arburst := Mux(isExu, exuIO.arburst, ifuIO.arburst)

  exuIO.arready := isExu && outIO.arready
  ifuIO.arready := isIfu && outIO.arready

  // R channel
  AXI4IO.noShakeConnectR(exuIO, outIO)
  AXI4IO.noShakeConnectR(ifuIO, outIO)

  exuIO.rvalid := isExu && outIO.rvalid
  ifuIO.rvalid := isIfu && outIO.rvalid

  outIO.rready := Mux(isExu, exuIO.rready, ifuIO.rready)

  // AW, W, B channel
  //   since only exu need write
  AXI4IO.connectAW(exuIO, outIO)
  AXI4IO.connectW(exuIO, outIO)
  AXI4IO.connectB(exuIO, outIO)

  io.ifu.dontCareAW()
  io.ifu.dontCareW()
  io.ifu.dontCareB()
}
