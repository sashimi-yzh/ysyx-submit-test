package dle.exp3

import chisel3._
import chisel3.util._

class Alu4() extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(3.W))
    val a = Input(UInt(4.W))
    val b = Input(UInt(4.W))
    val out = Output(UInt(4.W))
    val overflow = Output(Bool())
    val carry = Output(Bool())
  })

  val sub = io.inst === "b001".U || io.inst === "b110".U || io.inst === "b111".U

  val norB = io.b ^ Fill(4, sub)
  val asResult = io.a +& norB + sub
  val asOut = asResult(3, 0)
  val asOverflow = (io.a(3) === norB(3)) && (asResult(3) =/= norB(3))
  val addCarry = asResult(4)

  val lt = asOverflow ^ asResult(3)
  val subCarry = lt
  val equ = ~asOut.orR

  val out =
    VecInit(asOut, asOut, ~io.a, io.a & io.b, io.a | io.b, io.a ^ io.b, lt, equ)
  io.out := out(io.inst)
  io.overflow := asOverflow
  io.carry := Mux(sub, subCarry, addCarry)
}

class Exp3 extends Module {
  val io = IO(new Bundle {
    val inst = Input(UInt(3.W))
    val a = Input(UInt(4.W))
    val b = Input(UInt(4.W))
    val out = Output(UInt(4.W))
    val overflow = Output(Bool())
    val carry = Output(Bool())
  })
  val alu = Module(new Alu4)
  alu.io <> io
}
