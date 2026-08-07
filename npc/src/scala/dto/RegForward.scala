package dto
import chisel3._

class RegForward extends Bundle {
  val valid     = Bool()
  val dataValid = Bool()
  val rd        = UInt(5.W)
  val rdData    = UInt(32.W)
}
