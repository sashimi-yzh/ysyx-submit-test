package empty

import chisel3._
import chisel3.util._

class RamWriteData extends PrefixedRawModule {
  val io = IO(new Bundle {
    val word = Input(UInt(32.W))
    val lower2bit = Input(UInt(2.W))
    val size = Input(UInt(2.W))

    val out = Output(UInt(32.W))
    val mask = Output(UInt(4.W))
  })

  val shifted = io.word << Cat(io.lower2bit, 0.U(3.W))
  io.out := shifted(31, 0)
  io.mask := MuxLookup(io.size, "b1111".U(4.W))(
    Seq(
      RamSize.BYTE -> MuxLookup(io.lower2bit, "b0001".U(4.W))(
        Seq(
          "b00".U(2.W) -> "b0001".U(4.W),
          "b01".U(2.W) -> "b0010".U(4.W),
          "b10".U(2.W) -> "b0100".U(4.W),
          "b11".U(2.W) -> "b1000".U(4.W)
        )
      ),
      RamSize.HALF -> Mux(io.lower2bit(1), "b1100".U(4.W), "b0011".U(4.W)),
      RamSize.WORD -> "b1111".U(4.W)
    )
  )
}
