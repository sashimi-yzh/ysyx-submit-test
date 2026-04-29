package cpu
import chisel3._
import chisel3.util._
import common_def._
import busfsm._

import axi4._

import chisel3._
import chisel3.util._

class IFU extends Module {
  val io = IO(new Bundle {
    val pc              = Flipped(Decoupled(Types.UWord))
    val predictedNextPC = Input(Types.PredictedTarget)
    val mem             = AXI4IO.Master
    val out             = Decoupled(new Inst)
  })

  object State extends ChiselEnum {
    val idle, waitAR, waitR, waitOut = Value
  }

  dontTouch(io)
  val memIO = io.mem
  io.mem.dontCareAW()
  io.mem.dontCareW()
  io.mem.dontCareB()
  io.mem.dontCareNonLiteAR()

  val pcReg     = RegEnable(io.pc.bits(31,2), io.pc.fire)
  val pc        = Mux(io.pc.fire, io.pc.bits(31,2), pcReg)
  val predNxtPC = RegEnableReadNew(io.predictedNextPC, io.pc.fire)
  // dontTouch(pc)
  val state     = RegInit(State.idle)

  val instID = RegInit(0.U(Types.BitWidth.inst_id.W))
  when(io.pc.fire) {
    instID := instID + 1.U
  }
  // dontTouch(instID)

  io.out.bits.iid := Mux(io.pc.fire, instID + 1.U, instID)

  io.pc.ready   := (state === State.idle)
  memIO.arvalid := (state === State.waitAR) || (state === State.idle && io.pc.fire)
  memIO.araddr  := pc ## 0.U(2.W)

  val inst = RegEnableReadNew(memIO.rdata(31,2), memIO.rvalid)
  memIO.rready                := true.B
  io.out.bits.code.raw        := inst
  io.out.bits.pc.pc30b        := pc
  io.out.bits.predictedNextPC := predNxtPC
  io.out.valid                := ((state === State.waitR || state === State.waitAR) && memIO.rvalid) || (state === State.idle && io.pc.fire && memIO.rvalid) || (state === State.waitOut)

  val nxtStateWhenWaitOut = Mux(io.out.ready, State.idle, State.waitOut)
  val nxtStateWhenWaitR   = Mux(memIO.rvalid, nxtStateWhenWaitOut, State.waitR)
  val nxtStateWhenWaitAR  = Mux(memIO.arready, nxtStateWhenWaitR, State.waitAR)
  val nxtStateWhenIdle    = Mux(io.pc.fire, nxtStateWhenWaitAR, State.idle)

  // dontTouch(nxtStateWhenIdle)

  state := MuxLookup(state, State.idle)(
    Seq(
      State.idle    -> nxtStateWhenIdle,
      State.waitAR  -> nxtStateWhenWaitAR,
      State.waitR   -> nxtStateWhenWaitR,
      State.waitOut -> nxtStateWhenWaitOut
    )
  )

  val dbgOutPC = WireDefault(io.out.bits.pc.get)
  val dbgOutInst = WireDefault(io.out.bits.code.get)
  // dontTouch(dbgOutPC)
  // dontTouch(dbgOutInst)
}
