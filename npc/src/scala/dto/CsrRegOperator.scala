package dto

import chisel3._

class CsrRegOperator extends Bundle {
  val regAddr      = Output(UInt(12.W))
  val regWriteEn   = Output(Bool())
  val regWriteData = Output(UInt(32.W))
  val regReadData  = Input(UInt(32.W))
}
