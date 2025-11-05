package cpu 

import chisel3._
import chisel3.util._

/*
module ysyx_23060246_InstInvalid(
    input isvalid,
    input clock,
    input reset
);
*/

class ysyx_23060246_InstInvalid extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val isvalid = Input(Bool())
    val clock = Input(Clock())
    val reset = Input(Bool())
  })
}


/* 
module Ebreak(
    input isebreak,
    input clock,
    input reset
);
 */
class ysyx_23060246_Ebreak extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val isebreak = Input(Bool())
    val clock = Input(Clock())
    val reset = Input(Bool())
  })
}

/*
module AXIError(
    input [1:0] bresp,
    input [1:0] rresp,
    input wen,
    input ren,
);
*/

class AXIError extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val bresp = Input(UInt(2.W))
    val rresp = Input(UInt(2.W))
    val wen = Input(Bool())
    val ren = Input(Bool())
  })
}