package empty

import chisel3._
import chisel3.util._

class Branch(WIDTH: Int) extends PrefixedRawModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val funct3 = Input(UInt(3.W))
    val jump = Output(Bool())
  })

  val diff_ext = Cat(0.U(1.W), io.A) - Cat(0.U(1.W), io.B)
  val diff = diff_ext(WIDTH - 1, 0)
  val is_eq = diff === 0.U
  val sign_diff = io.A(WIDTH - 1) ^ io.B(WIDTH - 1)
  val is_lt = Mux(sign_diff, io.A(WIDTH - 1), diff(WIDTH - 1))
  val is_ltu = diff_ext(WIDTH)

  val compared = Mux(io.funct3(1), is_ltu, is_lt)

  io.jump := io.funct3(0) ^ Mux(io.funct3(2), compared, is_eq)
}
