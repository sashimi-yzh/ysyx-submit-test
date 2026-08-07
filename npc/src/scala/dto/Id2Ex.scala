package dto

import chisel3._
import enums._
import org.chipsalliance.cde.config.Parameters
import config.Configs
class Id2Ex(
  implicit p: Parameters)
    extends Bundle {
  val aluOperator  = AluOperator()
  val mret         = Bool()
  val regWriteEn   = Bool()
  val rd           = UInt(4.W)
  val rs1Data      = UInt(32.W)
  val rs2Data      = UInt(32.W)
  val needMA       = Bool()
  val memSize      = UInt(3.W)
  val memSignEx    = Bool()
  val imm          = UInt(32.W)
  // csr
  val csrWriteEn   = Bool()
  val csrrw        = Bool()
  // val csrOp       = AluOperator()
  // branch and jump
  val isBranch     = Bool()
  val isJal        = Bool()
  val isJalr       = Bool()
  val branchFunct3 = UInt(3.W)
  // fence.i
  val fence_i      = Bool()
  val pc           = UInt(32.W)
  val exception    = Bool()
  val exceptionNum = SynchronousException()
  // debug
  val npc          = UInt(32.W)
  val instruction  = if (p(Configs.DebugMode)) UInt(32.W) else null

}
