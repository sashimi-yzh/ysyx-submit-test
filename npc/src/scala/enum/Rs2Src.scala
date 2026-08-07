package enums
import chisel3._
import chisel3.util._

object Rs2Src extends ChiselEnum {
  val reg, immI, immU, csr = Value
}
