package utils
import chisel3._
import chisel3.util._

sealed trait hasEXT {
  def EXT(x: UInt, len: Int, bit: UInt) = {
    val fillLen = len - x.getWidth
    if (fillLen == 0) x else Cat(Fill(fillLen, bit), x)
  }
}

object SignEXT extends hasEXT {
  def apply(x: UInt, len: Int) = EXT(x, len, x(x.getWidth - 1))
}

object ZeroEXT extends hasEXT {
  def apply(x: UInt, len: Int) = EXT(x, len, 0.U(1.W))
}

object Lookup1H {
  def mkmap[T <: Data, U <: Data](key: T, mapping: Iterable[(T, U)]) = mapping.map(p => (p._1 === key, p._2))
  def apply[T <: Data, U <: Data](key: T, mapping: Iterable[(T, U)]): U = Mux1H(mkmap(key, mapping))
  def apply[T <: UInt, U <: Data](key: T, default: U, mapping: Iterable[(T, U)]): U =
    Mux1H(mkmap(key, mapping) ++ Iterable((mapping.map(p => (p._1 =/= key)).reduce(_ && _), default)))
  def apply[T <: UInt](default: T, mapping: Iterable[(Bool, T)]): T =
     Mux1H(mapping ++ Iterable((mapping.map(!_._1).reduce(_ && _), default)))
  def apply[T <: UInt](mapping: Iterable[(Bool, T)]): T = Mux1H(mapping)
}
