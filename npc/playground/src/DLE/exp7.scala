package dle.exp7

import chisel3._
import chisel3.util._

class ScanToAscii() extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(8.W))
    val out = Output(UInt(8.W))
  })

  val lut = Seq(
    "h0e".U -> '`'.U,
    "h16".U -> '1'.U,
    "h1e".U -> '2'.U,
    "h26".U -> '3'.U,
    "h25".U -> '4'.U,
    "h2e".U -> '5'.U,
    "h36".U -> '6'.U,
    "h3d".U -> '7'.U,
    "h3e".U -> '8'.U,
    "h46".U -> '9'.U,
    "h45".U -> '0'.U,
    "h4e".U -> '-'.U,
    "h55".U -> '='.U,
    "h15".U -> 'q'.U,
    "h1d".U -> 'w'.U,
    "h24".U -> 'e'.U,
    "h2d".U -> 'r'.U,
    "h2c".U -> 't'.U,
    "h35".U -> 'y'.U,
    "h3c".U -> 'u'.U,
    "h43".U -> 'i'.U,
    "h44".U -> 'o'.U,
    "h4d".U -> 'p'.U,
    "h54".U -> '['.U,
    "h5b".U -> ']'.U,
    "h5d".U -> '\\'.U,
    "h1c".U -> 'a'.U,
    "h1b".U -> 's'.U,
    "h23".U -> 'd'.U,
    "h2b".U -> 'f'.U,
    "h34".U -> 'g'.U,
    "h33".U -> 'h'.U,
    "h3b".U -> 'j'.U,
    "h42".U -> 'k'.U,
    "h4b".U -> 'l'.U,
    "h4c".U -> ';'.U,
    "h52".U -> '\''.U,
    "h1a".U -> 'z'.U,
    "h22".U -> 'x'.U,
    "h21".U -> 'c'.U,
    "h2a".U -> 'v'.U,
    "h32".U -> 'b'.U,
    "h31".U -> 'n'.U,
    "h3a".U -> 'm'.U,
    "h41".U -> ','.U,
    "h49".U -> '.'.U,
    "h4a".U -> '/'.U,
    "h29".U -> ' '.U
  )
  io.out := MuxLookup(io.in, 0.U)(lut)
}

class ParsePs2() extends Module {
  val io = IO(new Bundle {
    val ps2Clk = Input(Bool())
    val ps2Dat = Input(Bool())
    val data = Output(UInt(8.W))
    val valid = Output(Bool())
  })

  val negEdge = ~io.ps2Clk & RegNext(io.ps2Clk)
  val dataCntReg = RegInit(0.U(4.W))
  dataCntReg := Mux(
    negEdge,
    Mux(dataCntReg === 10.U, 0.U, dataCntReg + 1.U),
    dataCntReg
  )
  val dataReg = RegInit(0.U(11.W))
  dataReg := Mux(negEdge, io.ps2Dat ## dataReg(10, 1), dataReg)
  io.data := dataReg(8, 1)
  io.valid := RegNext(negEdge & dataCntReg === 10.U)
}

class DecoderLed extends Module {
  val io = IO(new Bundle {
    val in = Input(UInt(4.W))
    val en = Input(Bool())
    val out = Output(UInt(7.W))
  })

  io.out := ~Mux(
    io.en,
    MuxLookup(io.in, 0.U)(
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
    ),
    0.U
  )
}

class Exp7() extends Module {
  val io = IO(new Bundle {
    val ps2Clk = Input(Bool())
    val ps2Dat = Input(Bool())
    val led7Scan = Output(UInt(14.W))
    val led7Ascii = Output(UInt(14.W))
    val led7Cnt = Output(UInt(14.W))
  })

  val ps = Module(new ParsePs2)
  ps.io.ps2Clk := io.ps2Clk
  ps.io.ps2Dat := io.ps2Dat
  val dataReg = RegEnable(ps.io.data, 0.U(8.W), ps.io.valid)
  val isKeyDown = ps.io.data =/= "hf0".U && dataReg =/= "hf0".U
  val keyDownReg = RegEnable(isKeyDown, false.B, ps.io.valid)

  val scanDcdLed1 = Module(new DecoderLed)
  val scanDcdLed2 = Module(new DecoderLed)
  val asciiDcdLed1 = Module(new DecoderLed)
  val asciiDcdLed2 = Module(new DecoderLed)
  scanDcdLed1.io.en := keyDownReg
  scanDcdLed2.io.en := keyDownReg
  asciiDcdLed1.io.en := keyDownReg
  asciiDcdLed2.io.en := keyDownReg
  scanDcdLed1.io.in := dataReg(3, 0)
  scanDcdLed2.io.in := dataReg(7, 4)
  val sToA = Module(new ScanToAscii)
  sToA.io.in := dataReg
  asciiDcdLed1.io.in := sToA.io.out(3, 0)
  asciiDcdLed2.io.in := sToA.io.out(7, 4)
  io.led7Scan := scanDcdLed2.io.out ## scanDcdLed1.io.out
  io.led7Ascii := asciiDcdLed2.io.out ## asciiDcdLed1.io.out

  val cntReg = RegInit(0.U(8.W))
  cntReg := Mux(ps.io.valid, cntReg + (isKeyDown & ~keyDownReg), cntReg)
  val cntDcdLed1 = Module(new DecoderLed)
  val cntDcdLed2 = Module(new DecoderLed)
  cntDcdLed1.io.en := true.B
  cntDcdLed2.io.en := true.B
  cntDcdLed1.io.in := cntReg(3, 0)
  cntDcdLed2.io.in := cntReg(7, 4)
  io.led7Cnt := cntDcdLed2.io.out ## cntDcdLed1.io.out
}
