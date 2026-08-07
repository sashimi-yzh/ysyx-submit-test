package dto

import chisel3._
import enums._
import org.chipsalliance.cde.config.Parameters
import config.Configs
class Ex2Ma(
  implicit p: Parameters)
    extends Bundle {
  val rdData       = UInt(32.W)
  val rd           = UInt(4.W)
  val rdWriteEn    = Bool()
  val needMA       = Bool()
  val memAddr      = UInt(32.W)
  val memSize      = UInt(3.W)
  val memSignEx    = Bool()
  // csr
  val mret         = Bool()
  val csrWriteEn   = Bool()
  val csrWriteAddr = UInt(12.W)
  val csrWriteData = UInt(32.W)
  // fence.i
  val fence_i      = Bool()
  // debug
  val pc           = UInt(32.W)
  val npc          = if (p(Configs.DebugMode)) UInt(32.W) else null
  val instruction  = if (p(Configs.DebugMode)) UInt(32.W) else null
  val exception    = Bool()
  val exceptionNum = SynchronousException()
}
