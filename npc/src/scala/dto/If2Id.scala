package dto
import chisel3._
import enums._

class If2Id extends Bundle {
  val inst         = UInt(32.W)
  val pc           = UInt(32.W)
  val npc          = UInt(32.W)
  val exception    = Bool();
  val exceptionNum = SynchronousException();
}
