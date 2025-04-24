package npc
import chisel3._
import chisel3.util._
import utils._

class SimIMEM extends BlackBox with HasBlackBoxInline with NPCParameters {
  val io = IO(new Bundle {
    val pc = Input(UInt(PALEN.W))
    val inst = Output(UInt(32.W))
  })
  setInline("SimIMEM.v",
    """module SimIMEM(
      |  input  [31:0] pc,
      |  output reg [31:0] inst
      |);
      |import "DPI-C" function int pmem_read(input int raddr);
      |always @(*) begin
      |  inst = pmem_read(pc);
      |end
      |endmodule
    """.stripMargin)
}

class SimDMEM extends BlackBox with HasBlackBoxInline with NPCParameters {
  val io = IO(Flipped(new MemRWPortBundle))
  setInline("SimDMEM.v",
   s"""module SimDMEM(
      |  input         ren,
      |  input  [31:0] raddr,
      |  output reg [${XLEN-1}:0] rdata,
      |  input         wen,
      |  input  [31:0] waddr,
      |  input  [${XLEN-1}:0] wdata,
      |  input  [ ${XLEN/8-1}:0] wmask
      |);
      |import "DPI-C" function ${if (XLEN == 64) "longint" else "int"} pmem_read(input int raddr);
      |import "DPI-C" function void pmem_write(input int waddr, input ${if (XLEN == 64) "longint" else "int"} wdata, input byte wmask);
      |always @(*) begin
      |  if (ren) rdata = pmem_read(raddr); else rdata = 0;
      |  if (wen) pmem_write(waddr, wdata, {${if (XLEN == 64) "" else "4'b0, "} wmask});
      |end
      |endmodule
    """.stripMargin)
}

class AXI4IMEM extends Module {
  val io = IO(Flipped(new AXI4Lite))
  val imem = Module(new SimIMEM)
  imem.io.pc := io.ar.bits.addr
  io. r.bits.data := RegNext(imem.io.inst)
  io. r.bits.resp := AXI4Parameters.RESP_OKAY
  io. r.valid := RegNext(io.ar.fire)
  io.ar.ready := true.B
  io.aw.ready := false.B
  io. w.ready := false.B
  io. b.valid := false.B
  io. b.bits.resp := 0.U
}

class AXI4MemCtrl extends Module {
  val io = IO(new Bundle {
    val axi = Flipped(new AXI4)
    val dmem = new MemRWPortBundle
  })

  object StateRead extends ChiselEnum {
    val idle, waitRready = Value
  }

  val araddrReg = RegEnable(io.axi.ar.bits.addr, io.axi.ar.valid)
  val arsizeReg = RegEnable(io.axi.ar.bits.size, io.axi.ar.valid)
  val arburstCnt = RegEnable(io.axi.ar.bits.len, io.axi.ar.valid)
  when (io.axi.r.fire) { araddrReg := araddrReg + (1.U << arsizeReg) }
  when (io.axi.r.fire) { arburstCnt := arburstCnt - 1.U }

  val state_r = RegInit(StateRead.idle)
  state_r := Lookup1H(state_r, Array(
    StateRead.idle       -> Mux(io.axi.ar.valid, StateRead.waitRready, StateRead.idle),
    StateRead.waitRready -> Mux(io.axi.r.fire && io.axi.r.bits.last, StateRead.idle, StateRead.waitRready),
  ))

  io.axi. r.bits.data := io.dmem.rdata
  io.axi. r.bits.last := (arburstCnt === 0.U)
  io.axi. r.bits.resp := AXI4Parameters.RESP_OKAY
  io.axi. r.bits.id := RegEnable(io.axi.ar.bits.id, io.axi.ar.valid)
  io.axi. r.valid := (state_r === StateRead.waitRready)
  io.axi.ar.ready := (state_r === StateRead.idle)


  object StateWrite extends ChiselEnum {
    val idle, waitWvalid, waitBready = Value
  }

  val awaddrReg = RegEnable(io.axi.aw.bits.addr, io.axi.aw.valid)
  val awsizeReg = RegEnable(io.axi.aw.bits.size, io.axi.aw.valid)
  val awburstCnt = RegEnable(io.axi.aw.bits.len, io.axi.aw.valid)
  when (io.axi.w.fire) { awaddrReg := Mux(io.axi.aw.fire, io.axi.aw.bits.addr, awaddrReg) + (1.U << Mux(io.axi.aw.fire, io.axi.aw.bits.size, awsizeReg)) }
  when (io.axi.w.fire) { awburstCnt := Mux(io.axi.aw.fire, io.axi.aw.bits.len, awburstCnt) - 1.U }

  val state_w = RegInit(StateWrite.idle)
  state_w := Lookup1H(state_w, Array(
    StateWrite.idle       -> Mux(io.axi.aw.valid,
                               Mux(io.axi.w.valid && io.axi.w.bits.last, StateWrite.waitBready, StateWrite.waitWvalid), StateWrite.idle),
    StateWrite.waitWvalid -> Mux(io.axi.w.valid && io.axi.w.bits.last, StateWrite.waitBready, StateWrite.waitWvalid),
    StateWrite.waitBready -> Mux(io.axi.b.ready, StateWrite.idle, StateWrite.waitBready),
  ))

  io.dmem.ren := io.axi.ar.valid || (state_r =/= StateRead.idle)
  io.dmem.raddr := Mux(io.axi.ar.valid, io.axi.ar.bits.addr, araddrReg)

  io.dmem.wen := io.axi.w.valid
  io.dmem.waddr := Mux(io.axi.aw.valid, io.axi.aw.bits.addr, awaddrReg)
  io.dmem.wdata := io.axi.w.bits.data
  io.dmem.wmask := io.axi.w.bits.strb
  io.axi.aw.ready := (state_w === StateWrite.idle)
  io.axi. w.ready := state_w.isOneOf(StateWrite.idle, StateWrite.waitWvalid)
  io.axi. b.bits.resp := AXI4Parameters.RESP_OKAY
  io.axi. b.valid := (state_w === StateWrite.waitBready)
  io.axi. b.bits.id := RegEnable(io.axi.aw.bits.id, io.axi.aw.valid)
}

class AXI4DMEM extends Module {
  val io = IO(Flipped(new AXI4))
  val axi4memctrl = Module(new AXI4MemCtrl)
  val dmem = Module(new SimDMEM)
  axi4memctrl.io.axi <> io
  dmem.io <> axi4memctrl.io.dmem
}
