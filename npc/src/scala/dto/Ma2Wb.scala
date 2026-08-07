package dto

import chisel3._
import enums._
import org.chipsalliance.cde.config.Parameters
import config.Configs
class Ma2Wb(
  implicit p: Parameters)
    extends Bundle {
  val writeEn      = Bool()
  val writeData    = UInt(32.W)
  val rd           = UInt(4.W)
  // csr
  val csrWriteEn   = Bool()
  val csrWriteAddr = UInt(12.W)
  val csrWriteData = UInt(32.W)
  // debug
  val mret         = Bool()
  val pc           = UInt(32.W)
  val npc          = if (p(Configs.DebugMode)) UInt(32.W) else null
  val instruction  = if (p(Configs.DebugMode)) UInt(32.W) else null
  val exception    = Bool()
  val exceptionNum = SynchronousException()
}
