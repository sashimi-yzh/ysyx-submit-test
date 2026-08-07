package top
import chisel3._
import chisel3.util._
import dto._
import enums._
import org.chipsalliance.cde.config.Parameters
import config.Configs
import config.ResetVector

class InstructionFetch(
  implicit p: Parameters)
    extends Module {
  val io = IO(new Bundle {
    val icacheReq  = Decoupled(new ICacheReq)
    val icacheResp = Input(new ICacheResp)
    val predict    = Flipped(new PredictIO)
    val idu        = Decoupled(new If2Id)
    val flush      = Input(new PcRedirect)
  })

  val instReg                                            = Reg(UInt(32.W))
  val resetVec                                           = Module(new ResetVector).vec
  val pcReg                                              = RegInit(resetVec)
  val sIdle :: sWaitReq :: sWaitResp :: sSend2Idu :: Nil = Enum(4)
  val state                                              = RegInit(sIdle)
  io.predict.pc   := pcReg
  io.predict.inst := instReg
  val npc       = Mux(io.flush.valid, io.flush.npc, io.predict.npc)
  val exception = pcReg(1, 0) =/= 0.U
  io.icacheReq.valid       := state === sWaitReq
  io.icacheReq.bits.addr   := pcReg
  io.idu.bits.inst         := instReg
  io.idu.bits.pc           := pcReg
  io.idu.bits.npc          := npc
  io.idu.bits.exception    := exception
  io.idu.bits.exceptionNum := SynchronousException.InstructionAddressMisaligned
  io.idu.valid             := state === sSend2Idu

  when(io.flush.valid) {
    pcReg := io.flush.npc
  }

  state := MuxLookup(state, sIdle)(
    Seq(
      sIdle     -> Mux(io.flush.valid, sIdle, Mux(exception, sSend2Idu, sWaitReq)),
      sWaitReq  -> Mux(io.flush.valid, sIdle, Mux(io.icacheReq.fire, sWaitResp, sWaitReq)),
      sWaitResp -> Mux(io.flush.valid, sIdle, Mux(io.icacheResp.valid, sSend2Idu, sWaitResp)),
      sSend2Idu -> Mux(io.idu.fire | io.flush.valid, sIdle, sSend2Idu)
    )
  )

  switch(state) {
    is(sWaitResp) {
      when(io.icacheResp.valid) {
        instReg := io.icacheResp.data
      }
    }
    is(sSend2Idu) {
      when(io.idu.fire) {
        pcReg := npc
      }
    }
  }
}
