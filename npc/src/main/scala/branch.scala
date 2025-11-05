package cpu

import chisel3._
import chisel3.util._
import br_sel._

class BranchIO(xlen: Int) extends Bundle{
  val src1 = Input(UInt(xlen.W))
  val src2 = Input(UInt(xlen.W))
  val br_sel = Input(UInt(3.W))
  val taken = Output(Bool())
}

class  ysyx_23060246_Branch(xlen:Int) extends Module{
  val io = IO(new BranchIO(xlen))

  val eq = io.src1 === io.src2
  val neq = !eq
  val lt = io.src1.asSInt < io.src2.asSInt
  val ge = !lt
  val ltu = io.src1 < io.src2
  val geu = !ltu
  io.taken := MuxLookup(io.br_sel, false.B)(Seq(
    BR_EQ -> eq,
    BR_NE -> neq,
    BR_LT -> lt,
    BR_GE -> ge,
    BR_LTU -> ltu,
    BR_GEU -> geu
  ))
}