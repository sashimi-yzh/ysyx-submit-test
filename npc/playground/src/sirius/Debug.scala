package sirius

import chisel3._
import chisel3.util._
import chisel3.util.experimental.loadMemoryFromFileInline
import chisel3.experimental.dataview.DataViewable

class AxiSimDevice(
  memByte: Int = 0x400000
)(
  implicit private val cfg: CoreConfig)
    extends Module {
  val io = IO(new Bundle {
    val master = Flipped(new Axi4FlatIO)
  })

  val axi4BurstSpliter = Module(new Axi4BurstSpliter)
  axi4BurstSpliter.io.in :<>= io.master.viewAs[Axi4IO]
  val master = axi4BurstSpliter.io.out

  def inRange(addr: UInt, start: UInt, len: UInt) = {
    (addr >= start) && (addr < (start + len))
  }

  val mem = Mem(memByte / 4, Vec(4, UInt(8.W)))
  loadMemoryFromFileInline(mem, "THIS_IS_THE_IVERILOG_HEX_PATH_PLACEHOLDER")

  val sWaitReq :: sWaitAw :: sWaitW :: sWaitResp :: Nil = Enum(4)

  // R
  val rState = RegInit(sWaitReq)
  switch(rState) {
    is(sWaitReq) {
      when(master.ar.fire) {
        rState := sWaitResp
      }
    }
    is(sWaitResp) {
      when(master.r.fire) {
        rState := sWaitReq
      }
    }
  }

  val arBits = RegEnable(master.ar.bits, master.ar.fire)
  when(master.ar.fire) {
    assert(
      inRange(master.ar.bits.addr, "h80000000".U, memByte.U) ||
      inRange(master.ar.bits.addr, "h30000000".U, 256.U),
      "Read unknown device: 0x%x",
      master.ar.bits.addr
    )
  }
  master.ar.ready := rState === sWaitReq
  master.r.valid := rState === sWaitResp
  master.r.bits.id := arBits.id
  master.r.bits.last := true.B
  master.r.bits.resp := Axi4Resp.okay.U
  master.r.bits.data := DontCare
  when (master.r.valid) {
    when(inRange(arBits.addr, "h30000000".U, 256.U)) { // 0x30000000 -> 0x80000000
      when(inRange(arBits.addr, "h30000000".U, 4.U)) {
        master.r.bits.data := "h50000297".U // auipc t0, 0x50000
      }.elsewhen(inRange(arBits.addr, "h30000004".U, 4.U)) {
        master.r.bits.data := "h00028067".U // jr t0
      }.otherwise {
        master.r.bits.data := 0.U
      }
    } .otherwise { // MEM
      master.r.bits.data := mem(arBits.addr >> 2).asUInt
    }
  }

  // W
  val wState = RegInit(sWaitReq)
  switch(wState) {
    is(sWaitReq) {
      when(master.aw.fire && master.w.fire) {
        wState := sWaitResp
      }.elsewhen(master.aw.fire) {
        wState := sWaitW
      }.elsewhen(master.w.fire) {
        wState := sWaitAw
      }
    }
    is(sWaitAw) {
      when(master.aw.fire) {
        wState := sWaitResp
      }
    }
    is(sWaitW) {
      when(master.w.fire) {
        wState := sWaitResp
      }
    }
    is(sWaitResp) {
      when(master.b.fire) {
        wState := sWaitReq
      }
    }
  }
  val awBits = RegEnable(master.aw.bits, master.aw.fire)
  val wBits = RegEnable(master.w.bits, master.w.fire)
  master.aw.ready := wState === sWaitReq || wState === sWaitAw
  master.w.ready := wState === sWaitReq || wState === sWaitW
  master.b.valid := wState === sWaitResp
  master.b.bits.id := awBits.id
  master.b.bits.resp := Axi4Resp.okay.U
  when(master.b.fire) {
    when(awBits.addr === 0x10000000.U) { // UART
      assert(awBits.size === 0.U)
      printf("%c", wBits.data(7, 0))
    }.otherwise { // MEM
      assert(
        inRange(awBits.addr, "h80000000".U, memByte.U),
        "Write unknown device: 0x%x",
        awBits.addr
      )
      mem.write(awBits.addr >> 2, wBits.data.asTypeOf(Vec(4, UInt(8.W))), wBits.strb.asBools)
    }
  }
}

class DebugInfoDpiC(
  implicit private val cfg: CoreConfig)
    extends ExtModule {
  val isEbreak = IO(Input(Bool()))
  val pc = IO(Input(UInt(cfg.xlen.W)))
  val pcRaw = IO(Input(UInt(cfg.xlen.W)))
  // val dnpc = IO(Input(UInt(cfg.xlen.W)))
  val inst = IO(Input(UInt(cfg.xlen.W)))
  val wbuValid = IO(Input(Bool()))
  val isJump = IO(Input(Bool()))
  val jumpTarget = IO(Input(UInt(cfg.xlen.W)))
  setInline(
    "DebugInfoDpiC.sv",
    s"""|import "DPI-C" function void set_debug_info(input int is_ebreak, 
        |  input int pc, input int pc_raw, input int inst, input int wbu_valid, 
        |  input int is_jump, input int jump_target
        |  );
        |module DebugInfoDpiC(input isEbreak, input [${cfg.xlen - 1}:0] pc, 
        |  input [${cfg.xlen - 1}:0] pcRaw, input [${cfg.xlen - 1}:0] inst,
        |  input wbuValid, input isJump, input [${cfg.xlen - 1}:0] jumpTarget
        |  );
        |always @(*) begin
        | set_debug_info({31'b0, isEbreak}, pc, pcRaw, inst, {31'b0, wbuValid}, {31'b0, isJump}, jumpTarget);
        |end
        |endmodule
    """.stripMargin
  )
}

class MemDpiC(
  implicit private val cfg: CoreConfig)
    extends ExtModule {
  val clock = IO(Input(Clock()))
  val reset = IO(Input(Reset()))
  val axi = IO(Flipped(new Axi4FlatIO))

  private val memAddrMsb = cfg.memoryAddrWidth - 1
  private val maskMsb = (cfg.xlen >> 3) - 1
  private val maskZero = 32 - (cfg.xlen >> 3)

  private val delayProb = 0
  private val maxDelayCycle = 30

  setInline(
    "MemDpiC.sv",
    s"""
import "DPI-C" function void dpic_pmem_read(input int raddr, output int rdata);
import "DPI-C" function void dpic_pmem_write(
  input int waddr, input int wdata, input int wmask);

module MemDpiC(
  input clock,
  input reset,

  input axi_awvalid,
  output reg axi_awready,
  input [$memAddrMsb:0] axi_awaddr,
  input [3:0] axi_awid,
  input [7:0] axi_awlen,
  input [2:0] axi_awsize,
  input [1:0] axi_awburst,

  input axi_wvalid,
  output reg axi_wready,
  input [31:0] axi_wdata,
  input [$maskMsb:0] axi_wstrb,
  input axi_wlast,

  output reg axi_bvalid,
  input axi_bready,
  output reg [1:0] axi_bresp,
  output reg [3:0] axi_bid,

  input axi_arvalid,
  output reg axi_arready,
  input [$memAddrMsb:0] axi_araddr,
  input [3:0] axi_arid,
  input [7:0] axi_arlen,
  input [2:0] axi_arsize,
  input [1:0] axi_arburst,

  output reg axi_rvalid,
  input axi_rready,
  output reg [31:0] axi_rdata,
  output reg [1:0] axi_rresp,
  output reg axi_rlast,
  output reg [3:0] axi_rid
);

reg [3:0] r_arid_reg;
reg [3:0] r_awid_reg;

assign axi_rresp = 0;
assign axi_bresp = 0;
assign axi_rlast = 1;
assign axi_rid   = r_arid_reg;
assign axi_bid   = r_awid_reg;

reg [31:0] internal_ls_rData;
reg read_state; // 0: IDLE, 1: WAIT_RESP
integer read_delay_cnt;

assign axi_arready = (read_state == 0) && (read_delay_cnt == 0);
assign axi_rvalid = (read_state == 1) && (read_delay_cnt == 0);
assign axi_rdata = axi_rvalid ? internal_ls_rData : ${cfg.xlen}'b0;

reg [31:0] dpi_rdata;

always @(posedge clock) begin
  if (reset) begin
    read_state <= 0;
    read_delay_cnt <= 0;
  end else begin
    if (read_state == 0) begin
      if (read_delay_cnt > 0) begin
        read_delay_cnt <= read_delay_cnt - 1;
      end else if (axi_arvalid && axi_arready) begin
        read_state <= 1;
        r_arid_reg <= axi_arid;
        /* verilator lint_off UNSIGNED */
        read_delay_cnt <= ($$urandom_range(0, 99) < ${100 - delayProb}) ? 0 : $$urandom_range(1, ${maxDelayCycle});
        dpic_pmem_read(axi_araddr, dpi_rdata);
        internal_ls_rData <= dpi_rdata;
        /* $$strobe("VERILOG READ: *0x%x=0x%x", axi_araddr, internal_ls_rData); */
      end
    end else begin
      if (read_delay_cnt > 0) begin
        read_delay_cnt <= read_delay_cnt - 1;
      end else if (axi_rvalid && axi_rready) begin
        read_state <= 0;
        /* verilator lint_off UNSIGNED */
        read_delay_cnt <= ($$urandom_range(0, 99) < ${100 - delayProb}) ? 0 : $$urandom_range(1, ${maxDelayCycle});
      end
    end
  end
end

reg write_state; // 0: IDLE, 1: WAIT_RESP
integer write_delay_cnt;

assign axi_awready = (write_state == 0) && (axi_awvalid && axi_wvalid) && (write_delay_cnt == 0);
assign axi_wready = axi_awready;
assign axi_bvalid = (write_state == 1) && (write_delay_cnt == 0);

always @(posedge clock) begin
  if (reset) begin
    write_state <= 0;
    write_delay_cnt <= 0;
  end else begin
    if (write_state == 0) begin
      if (write_delay_cnt > 0) begin
        write_delay_cnt <= write_delay_cnt - 1;
      end else if (axi_awvalid && axi_wvalid) begin
        write_state <= 1;
        r_awid_reg <= axi_awid;
        /* verilator lint_off UNSIGNED */
        write_delay_cnt <= ($$urandom_range(0, 99) < ${100 - delayProb}) ? 0 : $$urandom_range(1, ${maxDelayCycle});
        dpic_pmem_write(axi_awaddr, axi_wdata, {${maskZero}'b0, axi_wstrb});
      end
    end else begin
      if (write_delay_cnt > 0) begin
        write_delay_cnt <= write_delay_cnt - 1;
      end else if (axi_bvalid && axi_bready) begin
        write_state <= 0;
        /* verilator lint_off UNSIGNED */
        write_delay_cnt <= ($$urandom_range(0, 99) < ${100 - delayProb}) ? 0 : $$urandom_range(1, ${maxDelayCycle});
      end
    end
  end
end

endmodule
"""
  )
}

class Axi4BurstSpliter extends Module {
  val io = IO(new Bundle {
    val in = Flipped(new Axi4IO)
    val out = new Axi4IO
  })
  io.out.aw :<>= io.in.aw
  io.out.w :<>= io.in.w
  io.in.b :<>= io.out.b

  val burstCnt = Reg(UInt(4.W))
  when(io.in.ar.fire) {
    burstCnt := io.in.ar.bits.len
  }.elsewhen(io.in.r.fire && burstCnt =/= 0.U) {
    burstCnt := burstCnt - 1.U
  }

  val bitsReg = Reg(chiselTypeOf(io.in.ar.bits))
  when(io.in.ar.fire) {
    bitsReg := io.in.ar.bits
  }
  when(io.in.r.fire) {
    switch(bitsReg.burst) {
      is(Axi4Burst.incr.U) {
        bitsReg.addr := bitsReg.addr + 4.U
      }
      is(Axi4Burst.warp.U) {
        val size = 1.U << bitsReg.size
        val len = bitsReg.len + 1.U
        val warpMask = (size * len - 1.U).pad(bitsReg.addr.getWidth)
        val addrHi = bitsReg.addr & ~warpMask
        val addrLo = (bitsReg.addr + 4.U) & warpMask
        bitsReg.addr := addrHi | addrLo
      }
    }
  }

  val sInReq :: sOutReq :: sResp :: Nil = Enum(3)
  val state = RegInit(sInReq)
  switch(state) {
    is(sInReq) { when(io.in.ar.fire) { state := sOutReq } }
    is(sOutReq) { when(io.out.ar.fire) { state := sResp } }
    is(sResp) { when(io.in.r.fire) { state := Mux(burstCnt === 0.U, sInReq, sOutReq) } }
  }

  io.in.ar.ready := state === sInReq
  io.out.ar.valid := state === sOutReq
  io.out.ar.bits := bitsReg
  io.out.ar.bits.len := 0.U
  io.in.r.valid := state === sResp && io.out.r.valid
  io.out.r.ready := state === sResp && io.in.r.ready
  io.in.r.bits := io.out.r.bits
  io.in.r.bits.id := bitsReg.id
  io.in.r.bits.last := burstCnt === 0.U
}

class GetGprDpiC(
  implicit private val cfg: CoreConfig)
    extends ExtModule {
  private val regNum = cfg.registerNum
  private val xlen = cfg.xlen
  val gpr = IO(Input(Vec(regNum, UInt(xlen.W))))
  val portDecls =
    (0 until regNum).map(i => s"input [${xlen - 1}:0] gpr_$i").mkString(", ")
  val assignLogic =
    (0 until regNum).map(i => s"    temp_regs[$i] = gpr_$i;").mkString("\n")

  setInline(
    "GetGprDpiC.sv",
    s"""|
        |
        |module GetGprDpiC($portDecls);
        |  reg [${xlen - 1}:0] temp_regs [$regNum] /* verilator public_flat */;
        |
        |  always @(*) begin
        |    $assignLogic
        |  end
        |endmodule
     """.stripMargin
  )
}
