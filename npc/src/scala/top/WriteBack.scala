package top

import chisel3._
import dto._
import chisel3.util._
import enums._
import table._
import chisel3.simulator.PeekPokeAPI.TestableData
import table.csrRegTable
import org.chipsalliance.cde.config.Parameters
import config.Configs
class WriteBack(
  implicit p: Parameters)
    extends Module {
  val io = IO(new Bundle {
    val mau          = Flipped(Decoupled(new Ma2Wb))
    val RegFileReq   = Output(new Wb2Reg)
    val CsrFileReq   = new CsrRegOperator
    val pc           = Output(UInt(32.W))
    val mret         = Output(Bool())
    val exception    = Output(Bool())
    val exceptionNum = Output(SynchronousException())
    // forward
    val forward      = Output(new RegForward)
    // debug
    val npc          = if (p(Configs.DebugMode)) UInt(32.W) else null
    val instruction  = if (p(Configs.DebugMode)) UInt(32.W) else null
  })

  val s_wait_mau :: s_send_out :: Nil = Enum(2)
  val state                           = RegInit(s_wait_mau)
  val mauReq                          = Reg(new Ma2Wb)
  state                      := MuxLookup(state, s_wait_mau)(
    Seq(
      s_wait_mau -> Mux(io.mau.fire, s_send_out, s_wait_mau),
      s_send_out -> s_wait_mau
    )
  )
  io.mau.ready               := state === s_wait_mau
  // regfile
  io.RegFileReq.rd           := mauReq.rd
  io.RegFileReq.writeData    := mauReq.writeData
  io.RegFileReq.writeEn      := mauReq.writeEn && state === s_send_out && !mauReq.exception
  // csr
  io.CsrFileReq.regWriteEn   := mauReq.csrWriteEn && state === s_send_out && !mauReq.exception
  io.CsrFileReq.regAddr      := mauReq.csrWriteAddr
  io.CsrFileReq.regWriteData := mauReq.csrWriteData
  // exception
  io.exception               := mauReq.exception && state === s_send_out
  io.exceptionNum            := mauReq.exceptionNum
  // ecal
  io.mret                    := mauReq.mret && state === s_send_out && !mauReq.exception
  // debug
  io.pc                      := mauReq.pc
  if (p(Configs.DebugMode)) {
    io.npc         := mauReq.npc
    io.instruction := mauReq.instruction
  }
  // forward
  io.forward.valid           := state =/= s_wait_mau && mauReq.writeEn && mauReq.rd =/= 0.U
  io.forward.dataValid       := state =/= s_wait_mau && mauReq.writeEn && mauReq.rd =/= 0.U
  io.forward.rd              := mauReq.rd
  io.forward.rdData          := mauReq.writeData
  switch(state) {
    is(s_wait_mau) {
      when(io.mau.fire) {
        mauReq := io.mau.bits
      }
    }
    is(s_send_out) {}
  }
}
