package diplomatic

import chisel3._
import chisel3.util.log2Floor

case class AddressSet(base: BigInt, mask: BigInt) {
  require((base & mask) == 0, s"Mis-aligned AddressSets are forbidden, got: $this")
  def size:                 BigInt  = mask + 1
  def contains(addr: UInt): Bool    = {
    val checkBits = (~mask) & ((BigInt(1) << 64) - 1)
    ((addr ^ base.U) & checkBits.U) === 0.U
  }
  def contiguous:           Boolean = (mask & (mask + 1)) == 0
  override def toString:    String  = f"AddressSet(0x$base%x, 0x$mask%x)"
}

object AddressSet {

  // 创建对齐的地址
  def apply(base: BigInt, size: BigInt): AddressSet = {
    require((size & (size - 1)) == 0, s"size must be power of 2, got $size")
    new AddressSet(base, size - 1)
  }

  // 创建非对齐的地址
  def misaligned(base: BigInt, size: BigInt, tail: Seq[AddressSet] = Nil): Seq[AddressSet] = {
    if (size == 0) return tail.reverse
    val maxBaseAlignment = base & (-base)
    val maxSizeAlignment = BigInt(1) << log2Floor(size)
    val step             =
      if (maxBaseAlignment == 0) maxSizeAlignment
      else maxBaseAlignment.min(maxSizeAlignment)
    misaligned(base + step, size - step, AddressSet(base, step) +: tail)
  }
}
