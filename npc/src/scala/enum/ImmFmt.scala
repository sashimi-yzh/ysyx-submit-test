package enums
import chisel3._
import chisel3.util._

object ImmFmt extends ChiselEnum {
  val immI, immS, immB, immU, immJ = Value
}
