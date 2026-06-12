package sirius

import chisel3._
import chisel3.util._

object SignExt {
  def apply(data: UInt, len: Int) = {
    val dataLen = data.getWidth
    val signBit = data(dataLen - 1)
    if (dataLen >= len) data(len - 1, 0) else Fill(len - dataLen, signBit) ## data
  }
}

object ZeroExt {
  def apply(data: UInt, len: Int) = {
    val dataLen = data.getWidth
    if (dataLen >= len) data(len - 1, 0) else 0.U((len - dataLen).W) ## data
  }
}

object PcCat {
  def apply(hasC: Boolean, pcHi: UInt, pcLo: UInt) = {
    pcHi ## pcLo ## (if (hasC) 0.U(1.W) else 0.U(2.W))
  }
}

object ExtractFrom {
  def apply(data: UInt, lsb: Int, width: Int) = {
    data(width + lsb - 1, lsb)
  }
}
