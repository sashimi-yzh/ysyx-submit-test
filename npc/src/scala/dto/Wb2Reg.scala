package dto

import chisel3._
import enums._
class Wb2Reg extends Bundle {
  val writeEn   = Bool()
  val writeData = UInt(32.W)
  val rd        = UInt(4.W)
}
