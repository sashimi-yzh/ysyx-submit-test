package empty
import chisel3._
import chisel3.util._
class Adder(WIDTH: Int) extends PrefixedRawModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val Cin = Input(Bool())
    val out = Output(UInt(WIDTH.W))
    val Cout = Output(Bool())
    val overflow = Output(Bool())
  })
  val result33 = Wire(UInt((WIDTH + 1).W))
  result33 := io.A +& io.B + io.Cin
  io.out := result33((WIDTH - 1), 0)
  io.Cout := result33(WIDTH)

  val signA = io.A(WIDTH - 1)
  val signB = io.B(WIDTH - 1)
  val signS = result33(WIDTH - 1)

  io.overflow := (signA === signB) && (signA =/= signS)
}

class ALU(WIDTH: Int) extends PrefixedRawModule {
  val io = IO(new Bundle {
    val A = Input(UInt(WIDTH.W))
    val B = Input(UInt(WIDTH.W))
    val controls = Input(new ALUControl())
    val out = Output(UInt(WIDTH.W))
  })

  val adder = Module(new Adder(WIDTH))
  val log_width = log2Ceil(WIDTH)
  val op = io.controls.op
  val is_sub_like = op === ALUOp.SUB || op === ALUOp.SLT || op === ALUOp.SLTU

  adder.io.A := io.A
  adder.io.B := Mux(is_sub_like, ~io.B, io.B)
  adder.io.Cin := is_sub_like

  io.out := MuxLookup(op, adder.io.out)(
    Seq(
      ALUOp.ADD -> adder.io.out,
      ALUOp.SUB -> adder.io.out,
      ALUOp.SLT -> Cat(0.U((WIDTH - 1).W), adder.io.out(WIDTH - 1) ^ adder.io.overflow),
      ALUOp.SLTU -> Cat(0.U((WIDTH - 1).W), ~adder.io.Cout),
      ALUOp.SLL -> (io.A << io.B(log_width - 1, 0)),
      ALUOp.SRA -> (io.A.asSInt >> io.B(log_width - 1, 0)).asUInt,
      ALUOp.SRL -> (io.A >> io.B(log_width - 1, 0)),
      ALUOp.AND -> (io.A & io.B),
      ALUOp.OR -> (io.A | io.B),
      ALUOp.XOR -> (io.A ^ io.B)
    )
  )
}
