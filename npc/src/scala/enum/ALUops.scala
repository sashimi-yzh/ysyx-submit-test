package enums
import chisel3._
import chisel3.util._
object AluOperator extends ChiselEnum {
  val nop, add, and, arithmeticRightShift, sub, logicalLeftShift, logicalRightShift, or, signedLess, unsignedLess, xor = Value
}
