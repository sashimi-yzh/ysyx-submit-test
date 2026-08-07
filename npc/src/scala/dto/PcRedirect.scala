package dto

import chisel3._
import enums._
class PcRedirect extends Bundle {
  val valid = Bool()
  val npc   = UInt(32.W)
}
