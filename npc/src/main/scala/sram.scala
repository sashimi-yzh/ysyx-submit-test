package ysyx_23060246

import chisel3._
import chisel3.util._

import AXI4._
import freechips.rocketchip.amba.axi4._


/*
module Mem(
        input clock,
        input reset,

        input wire we,
        input wire [`InstAddrBus] waddr,
        input wire [`InstAddrBus] raddr,
        input wire [`WordBus] wdata,
        input wire [7:0] wmask,

        output reg [`WordBus] rdata
);
 */
class MemIO extends Bundle {
  val clock = Input(Clock())
  val reset = Input(Bool())
  val we    = Input(Bool())
  val waddr = Input(UInt(32.W))
  val raddr = Input(UInt(32.W))
  val wdata = Input(UInt(32.W))
  val wmask = Input(UInt(8.W))
  val rdata = Output(UInt(32.W))
}

class Mem extends BlackBox with HasBlackBoxPath {
  val io = IO(new MemIO)
}

class LFSR4 extends Module {
  val io = IO(new Bundle {
    val out = Output(UInt(4.W))
  })

  val lfsr = RegInit(1.U(4.W))

  lfsr := Cat(lfsr(0) ^ lfsr(1) ^ lfsr(2), lfsr(3, 1))

  io.out := lfsr
}

class SRAM(params: AXI4BundleParameters) extends Module {
  val io = IO(new Bundle {
    val axi = Flipped(new AXI4Bundle(params))
  })

  val axi    = io.axi
  val mem    = Module(new Mem)
  val lfsr_r  = Module(new LFSR4)
  val random_r = lfsr_r.io.out
  //val random_r = 10.U
  val lfsr_w = Module(new LFSR4)
  val random_w = lfsr_w.io.out
  //val random_w = 10.U

  // 读状态机
  val s_read_idle :: s_read :: s_read_delay :: s_wait_read_ready :: Nil = Enum(4)
  val state_r = RegInit(s_read_idle)
  state_r := MuxLookup(state_r, s_read_idle)(Seq(
    s_read_idle -> Mux(axi.ar.valid, s_read, s_read_idle),
    //s_read -> s_read_delay,
    s_read -> s_wait_read_ready, //不使用随机延迟
    // s_read_delay -> Mux(random_r >= 10.U , s_wait_read_ready, s_read_delay),
    s_wait_read_ready -> Mux(axi.r.ready, s_read_idle, s_wait_read_ready)
  ))

  axi.ar.ready := state_r === s_read_idle
  val rdata = RegInit(0.U(32.W))
  when(state_r === s_read){
    rdata := mem.io.rdata
  }
  axi.r.valid := state_r === s_wait_read_ready
  axi.r.bits.data := rdata 
  axi.r.bits.resp := 0.U



  // 写状态机
  val s_write_idle :: s_wait_data :: s_wait_addr :: s_write :: s_write_delay :: s_wait_write_ready :: Nil = Enum(6)
  val state_w = RegInit(s_write_idle)
  state_w := MuxLookup(state_w, s_write_idle)(Seq(
    s_write_idle -> Mux(axi.aw.valid && axi.w.valid, s_write, 
                        Mux(axi.aw.valid, s_wait_data, 
                            Mux(axi.w.valid, s_wait_addr, s_write_idle))),
    s_wait_data -> Mux(axi.w.valid, s_write, s_wait_data),
    s_wait_addr -> Mux(axi.aw.valid, s_write, s_wait_addr),
    //s_write -> s_write_delay,
    s_write -> s_wait_write_ready, //不使用随机延迟
    // s_write_delay -> Mux(random_w >= 10.U, s_wait_write_ready, s_write_delay),
    s_wait_write_ready -> Mux(axi.b.ready, s_write_idle, s_wait_write_ready)
  ))


  val wdata = RegInit(0.U(32.W))
  val waddr = RegInit(0.U(32.W))
  val wstrb = RegInit(0.U(4.W))
  when(axi.aw.valid){
    waddr := axi.aw.bits.addr
  }
  when(axi.w.valid){
    wdata := axi.w.bits.data
    wstrb := axi.w.bits.strb
  }
  
  axi.aw.ready := state_w === s_write_idle || state_w === s_wait_addr
  axi.w.ready := state_w === s_write_idle || state_w === s_wait_data
  axi.b.valid := state_w === s_wait_write_ready


  mem.io.clock := clock
  mem.io.reset := reset
  mem.io.raddr := Cat(axi.ar.bits.addr(params.addrBits-1,2), 0.U(2.W))
  mem.io.we := state_w === s_write
  mem.io.waddr := Cat(waddr(params.addrBits-1,2), 0.U(2.W))
  mem.io.wdata := wdata
  mem.io.wmask := wstrb

  io.axi.b.bits.id := 0.U
  io.axi.b.bits.resp := 0.U

  io.axi.r.bits.last := true.B
  io.axi.r.bits.id := 0.U
}
