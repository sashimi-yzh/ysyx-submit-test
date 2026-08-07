package top

import chisel3._
import chisel3.util._
import chisel3.util.experimental.decode._
import org.chipsalliance.cde.config.Parameters
import config.Configs
import table._

class BTBEntry(tagWidth: Int) extends Bundle {
  val tag    = UInt(tagWidth.W)
  val target = UInt(32.W)
}
class PredictIO               extends Bundle {
  val pc   = Input(UInt(32.W))
  val inst = Input(UInt(32.W))
  val npc  = Output(UInt(32.W))
}
class UpdateIO                extends Bundle {
  val valid  = Input(Bool())
  val pc     = Input(UInt(32.W))
  val target = Input(UInt(32.W))
}
class BranchPredictor(
  implicit p: Parameters)
    extends Module {
  val indexWidth = p(Configs.BranchPredictorIndexWidth)
  val io         = IO(new Bundle {
    val predict = new PredictIO()
    val update  = new UpdateIO()
  })

  val btbSize  = 1 << indexWidth
  val tagWidth = 32 - 2 - indexWidth

  val btb = RegInit(VecInit(Seq.fill(btbSize) {
    val e = Wire(new BTBEntry(tagWidth))
    e.tag    := 0.U
    e.target := 0.U
    e
  }))

  val lookupIndex = if (indexWidth == 0) 0.U else io.predict.pc(indexWidth + 1, 2)
  val lookupTag   = io.predict.pc(31, indexWidth + 2)
  val lookupEntry = btb(lookupIndex)

  val btbHit    = lookupEntry.tag === lookupTag && io.predict.pc(1, 0) === 0.U
  val btbTarget = lookupEntry.target

  val decodeTable = new DecodeTable(
    AllInstructions.all,
    Seq(decodeIsBranch, decodeIsJal, decodeIsJalr)
  )
  val result      = decodeTable.decode(io.predict.inst)
  val isBType     = result(decodeIsBranch)
  val isJal       = result(decodeIsJal)
  val isJalr      = result(decodeIsJalr)

  io.predict.npc := Mux((isBType || isJal || isJalr) && btbHit, btbTarget, io.predict.pc + 4.U)
  val updateIndex = if (indexWidth == 0) 0.U else io.update.pc(indexWidth + 1, 2)
  val updateTag   = io.update.pc(31, indexWidth + 2)

  when(io.update.valid) {
    btb(updateIndex).tag    := updateTag
    btb(updateIndex).target := io.update.target
  }
}
