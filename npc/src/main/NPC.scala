package npc

import chisel3._
import chisel3.util._

class NPCTrap extends BlackBox with HasBlackBoxInline with NPCParameters {
  val io = IO(Flipped(new NPCTrapIO))
  setInline("NPCTrap.v",
   s"""module NPCTrap(
      |  input valid,
      |  input [31:0] pc,
      |  input [31:0] dnpc,
      |  input isEbreak,
      |  input [${XLEN - 1}:0] code,
      |  input isMMIO,
      |  input [31:0] memAddr,
      |  input skip
      |);
      |import "DPI-C" function void set_commit(input bit valid, input int pc, input int dnpc,
      |  input bit isEbreak, input int code, input bit isMMIO, input int memAddr, input bit skip);
      |always @(*) begin
      |  set_commit(valid, pc, dnpc, isEbreak, code, isMMIO, memAddr, skip);
      |end
      |endmodule
    """.stripMargin)
}

object StageConnect {
  def singleCycle[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T]) = {
    right <> left
  }
  def multiCycle[T <: Data, T2 <: Data](left: DecoupledIO[T], right: DecoupledIO[T], right2: DecoupledIO[T2]) = {
    right.bits := RegEnable(left.bits, left.valid)
    right.valid := RegEnable(Mux(right2.valid, false.B, left.valid), false.B, right2.valid || left.valid)
    left.ready := true.B
  }
  def pipeline[T <: Data, T2 <: Data](left: DecoupledIO[T], right: DecoupledIO[T], right2: DecoupledIO[T2], isFlush: Bool) = {
    right.bits := RegEnable(left.bits, left.valid && right.ready)
    right.valid := RegNext(Mux(isFlush, false.B, Mux(left.valid && right.ready, true.B, Mux(right2.fire, false.B, right.valid))), false.B)
    left.ready := right.ready
  }
  def queue[T <: Data, T2 <: Data](left: DecoupledIO[T], right: DecoupledIO[T], right2: DecoupledIO[T2], isFlush: Bool, depth: Int = 1) = {
    val deq = Queue(left, depth, flow = true, flush = Some(isFlush))

    right.bits := RegEnable(deq.bits, deq.valid && right.ready)
    right.valid := RegNext(Mux(isFlush, false.B, Mux(deq.valid && right.ready, true.B, Mux(right2.fire, false.B, right.valid))), false.B)
    deq.ready := right.ready
  }
}

class NPC extends NPCModule {
  val io = IO(new Bundle{
    val master = new AXI4
  })

  val ifu = Module(new IFU)
  val idu = Module(new IDU)
  val exu = Module(new EXU)
  val lsu = Module(new LSU)
  val wbu = Module(new WBU)

  val isFlush = lsu.io.redirect.valid
  StageConnect.queue   (ifu.io.out, idu.io.in, idu.io.out, isFlush)
  StageConnect.pipeline(idu.io.out, exu.io.in, exu.io.out, isFlush)
  StageConnect.pipeline(exu.io.out, lsu.io.in, lsu.io.out, isFlush)
  StageConnect.pipeline(lsu.io.out, wbu.io.in, wbu.io.out, false.B)
  wbu.io.out.ready := true.B

  idu.io.wb  <> wbu.io.wb
  idu.io.exFw <> exu.io.fw
  idu.io.lsFw <> lsu.io.fw
  ifu.io.redirect <> lsu.io.redirect

  val icache = Module(new Cache(readOnly = true))
  val lsuAXI4 = AXI4LiteToAXI4.master(lsu.io.mem)
  icache.io.core <> ifu.io.mem
  val xbar = Module(new AXI4CrossbarNto1(2, new AXI4))
  val xbar2 = Module(new AXI4Crossbar1toN(List((0x02000000, 0xffff), (0, 0)), new AXI4))
  val clint = Module(new AXI4CLINT)
  xbar.io.in(0) <> lsuAXI4  // higher priority
  xbar.io.in(1) <> icache.io.mem
  xbar2.io.in <> xbar.io.out
  AXI4LiteToAXI4.slave(clint.io) <> xbar2.io.out(0)
  io.master <> xbar2.io.out(1)
  // overwride the write channel with LSU
  io.master.aw <> lsuAXI4.aw
  io.master.w  <> lsuAXI4.w
  io.master.b  <> lsuAXI4.b

  icache.io.fence_i := exu.io.fence_i
  icache.io.flush := isFlush

  if (Global.mode != "syn") {
    val npctrap = Module(new NPCTrap)
    npctrap.io := RegNext(wbu.io.in.bits.npctrap) // wait one cycle for writing back to regfile
    npctrap.io.valid := RegNext(wbu.io.in.valid)
  }
}

class Top extends NPCModule {
  val io = IO(new Bundle{
    val master    = if (Global.mode != "sim") Some(new AXI4(idBits = 4)) else None
    val interrupt = if (Global.mode != "sim") Some(Input(Bool())) else None
    val slave     = if (Global.mode != "sim") Some(Flipped(new AXI4(idBits = 4))) else None
  })

  val npc = withModulePrefix("ysyx_88888888") { Module(new NPC) }

  if (Global.mode == "sim") {
    val mem = Module(new AXI4DMEM)
    mem.io <> npc.io.master
  } else {
    io.master.get <> npc.io.master
    io.slave.get := DontCare

    assert(!(npc.io.master.r.fire && npc.io.master.r.bits.resp =/= AXI4Parameters.RESP_OKAY))
    assert(!(npc.io.master.b.fire && npc.io.master.b.bits.resp =/= AXI4Parameters.RESP_OKAY))
  }
}
