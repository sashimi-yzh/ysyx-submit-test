package table
import chisel3._
object csrRegTable {
  val mvendorid = "hf11".U(12.W)
  val marchid   = "hf12".U(12.W)
  val mtvec     = "h305".U(12.W)
  val mstatus   = "h300".U(12.W)
  val mepc      = "h341".U(12.W)
  val mcause    = "h342".U(12.W)
}
