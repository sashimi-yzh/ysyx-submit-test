package dle.exp6

import chisel3._
import chisel3.util._

import dle.exp2.DecoderLed

class Lfsr() extends Module {
  val io = IO(new Bundle {
    val seed = Input(UInt(8.W))
    val load = Input(Bool())
    val en = Input(Bool())
    val out = Output(UInt(8.W))
  })

  val shiftReg = RegInit(io.seed)
  val newBit = shiftReg(4) ^ shiftReg(3) ^ shiftReg(2) ^ shiftReg(0)
  shiftReg := Mux(
    io.load,
    io.seed,
    Mux(io.en, newBit ## shiftReg(7, 1), shiftReg)
  )
  io.out := shiftReg
}

class Exp6() extends Module {
  val io = IO(new Bundle {
    val seed = Input(UInt(8.W))
    val load = Input(Bool())
    val next = Input(Bool())
    val led7 = Output(UInt(14.W))
  })

  val lfsr = Module(new Lfsr())
  lfsr.io.seed := io.seed
  lfsr.io.load := io.load
  lfsr.io.en := io.next & ~RegNext(io.next)
  val dcdled1 = Module(new DecoderLed())
  val dcdled2 = Module(new DecoderLed())
  dcdled1.io.in := lfsr.io.out(3, 0)
  dcdled2.io.in := lfsr.io.out(7, 4)
  io.led7 := dcdled2.io.out ## dcdled1.io.out
}
