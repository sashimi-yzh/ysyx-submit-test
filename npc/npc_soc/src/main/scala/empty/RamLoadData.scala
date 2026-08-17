package empty

import chisel3._
import chisel3.util._

class RamLoadData extends PrefixedRawModule {
  val io = IO(new Bundle {
    val word = Input(UInt(32.W))
    val lower2bit = Input(UInt(2.W))
    val size = Input(UInt(2.W))
    val is_unsigned = Input(Bool())

    val out = Output(UInt(32.W))
  })

  val short = Mux(io.lower2bit(1), io.word(31, 16), io.word(15, 0))
  val h_out = Mux(io.is_unsigned, Cat(0.U(16.W), short), Cat(Fill(16, short(15)), short))

  val byte = MuxLookup(io.lower2bit, io.word(7, 0))(
    Seq(
      "b00".U(2.W) -> io.word(7, 0),
      "b01".U(2.W) -> io.word(15, 8),
      "b10".U(2.W) -> io.word(23, 16),
      "b11".U(2.W) -> io.word(31, 24)
    )
  )
  val b_out = Mux(io.is_unsigned, Cat(0.U(24.W), byte), Cat(Fill(24, byte(7)), byte))

  io.out := MuxLookup(io.size, io.word)(
    Seq(
      RamSize.BYTE -> b_out,
      RamSize.HALF -> h_out,
      RamSize.WORD -> io.word
    )
  )
}
