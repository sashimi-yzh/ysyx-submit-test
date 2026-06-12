package dle.exp2

import chisel3._
import chisel3.util._

class DecoderLed extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(4.W))
    val out = Output(UInt(7.W))
  })

  io.out := ~MuxLookup(io.in, 0.U)(
    Seq(
      0.U -> "b1111110".U,
      1.U -> "b0110000".U,
      2.U -> "b1101101".U,
      3.U -> "b1111001".U,
      4.U -> "b0110011".U,
      5.U -> "b1011011".U,
      6.U -> "b1011111".U,
      7.U -> "b1110000".U,
      8.U -> "b1111111".U,
      9.U -> "b1111011".U,
      10.U -> "b1110111".U,
      11.U -> "b0011111".U,
      12.U -> "b1001110".U,
      13.U -> "b0111101".U,
      14.U -> "b1001111".U,
      15.U -> "b1000111".U
    )
  )
}

class Encoder83 extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(8.W))
    val en = Input(Bool())
    val out = Output(UInt(3.W))
  })

  val enc = WireDefault(0.U(3.W))
  enc := Mux1H(
    Seq(
      io.in(0) -> 0.U,
      io.in(1) -> 1.U,
      io.in(2) -> 2.U,
      io.in(3) -> 3.U,
      io.in(4) -> 4.U,
      io.in(5) -> 5.U,
      io.in(6) -> 6.U,
      io.in(7) -> 7.U
    )
  )
  io.out := Mux(io.en, enc, 0.U)
}

class PEncoder83 extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(8.W))
    val en = Input(Bool())
    val out = Output(UInt(3.W))
  })

  val hotIn = VecInit.fill(8)(false.B)
  val cond = VecInit.fill(8)(false.B)

  hotIn(7) := io.in(7)
  cond(7) := ~io.in(7)
  for (i <- 6 to 0 by -1) {
    cond(i) := ~io.in(i) & cond(i + 1)
    hotIn(i) := io.in(i) & cond(i + 1)
  }

  val enc83 = Module(new Encoder83)
  enc83.io.in := hotIn.asUInt
  enc83.io.en := io.en
  io.out := enc83.io.out
}

class Exp2 extends Module {
  val io = IO(new Bundle {
    val sw = Input(UInt(8.W))
    val en = Input(Bool())
    val led = Output(UInt(3.W))
    val hasOne = Output(Bool())
    val led7 = Output(UInt(7.W))
  })

  val pe = Module(new PEncoder83)
  val decLed = Module(new DecoderLed)

  io.hasOne := io.sw.orR

  pe.io.in := io.sw
  pe.io.en := io.en
  io.led := pe.io.out

  decLed.io.in := 0.U(1.W) ## io.led
  io.led7 := decLed.io.out
}
