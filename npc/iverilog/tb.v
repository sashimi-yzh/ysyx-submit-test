`timescale 1ps / 1ps
module top ();

  reg clock;
  reg reset;

  wire [31:0] araddr;
  wire arvalid;
  wire arready;

  wire rready;
  wire [7:0] arlen;
  wire [31:0] rdata;
  wire [1:0] rresp;
  wire rvalid;
  wire rlast;

  wire [31:0] awaddr;
  wire awvalid;
  wire awready;

  wire [31:0] wdata;
  wire [3:0] wstrb;
  wire wvalid;
  wire wready;

  wire bready;
  wire [1:0] bresp;
  wire bvalid;

  reg [31:0] ebreak_pc;

  initial begin
    clock = 0;
    reset = 1;
    ebreak_pc = 0;
    #20 reset = 0;
  end

  always #1 clock = ~clock;

  always @(posedge cpu.ebreak) begin
    ebreak_pc = cpu.idu_pc;
  end

  always @(posedge clock) begin
    if (cpu.lsu_pc == ebreak_pc) begin
`ifndef NETLIST
      if (cpu.reg_file.regs[10]) $display("\033[31m\tHIT BAD TRAP\033[0m");
      else $display("\033[32m\tHIT GOOD TRAP\033[0m");
`endif
      $finish;
    end
  end

  ysyx_25010008 cpu (
      .clock(clock),
      .reset(reset),
      .io_interrupt(1'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_master_awready(awready),
      .io_master_awvalid(awvalid),
      .io_master_awid(),
      .io_master_awaddr(awaddr),
      .io_master_awlen(),
      .io_master_awsize(),
      .io_master_awburst(),
      .io_master_wready(wready),
      .io_master_wvalid(wvalid),
      .io_master_wdata(wdata),
      .io_master_wstrb(wstrb),
      .io_master_wlast(),
      .io_master_bready(bready),
      .io_master_bvalid(bvalid),
      .io_master_bid(4'b0),
      .io_master_bresp(bresp),
      .io_master_arready(arready),
      .io_master_arvalid(arvalid),
      .io_master_arid(),
      .io_master_araddr(araddr),
      .io_master_arlen(arlen),
      .io_master_arsize(),
      .io_master_arburst(),
      .io_master_rready(rready),
      .io_master_rvalid(rvalid),
      .io_master_rid(4'b0),
      .io_master_rdata(rdata),
      .io_master_rresp(rresp),
      .io_master_rlast(rlast),
      .io_slave_awready(  /* unused */),
      .io_slave_awvalid       (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_awid(4'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_awaddr(32'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_awlen(8'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_awsize(3'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_awburst(2'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_wready(  /* unused */),
      .io_slave_wvalid        (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_wdata(32'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_wstrb(4'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_wlast    (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_bready        (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_bvalid(  /* unused */),
      .io_slave_bid(  /* unused */),
      .io_slave_bresp(  /* unused */),
      .io_slave_arready(  /* unused */),
      .io_slave_arvalid       (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_arid(4'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_araddr(32'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_arlen(8'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_arsize(3'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_arburst(2'h0),  // home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:36:19, :38:21
      .io_slave_rready        (1'h0),	// home/cloud/ysyx-workbench/ysyxSoC/src/CPU.scala:35:23, :36:19, :38:21
      .io_slave_rvalid(  /* unused */),
      .io_slave_rid(  /* unused */),
      .io_slave_rdata(  /* unused */),
      .io_slave_rresp(  /* unused */),
      .io_slave_rlast(  /* unused */)
  );

  ysyx_25010008_SRAM sram (
      .clk(clock),
      .rst(reset),

      .araddr (araddr),
      .arvalid(arvalid),
      .arready(arready),

      .rready(rready),
      .arlen (arlen),
      .rdata (rdata),
      .rresp (rresp),
      .rvalid(rvalid),
      .rlast (rlast),

      .awaddr (awaddr),
      .awvalid(awvalid),
      .awready(awready),

      .wdata (wdata),
      .wstrb (wstrb),
      .wvalid(wvalid),
      .wready(wready),

      .bready(bready),
      .bresp (bresp),
      .bvalid(bvalid)
  );
endmodule

module ysyx_25010008_SRAM (
    input clk,
    input rst,

    input [31:0] araddr,
    input arvalid,
    output reg arready,

    input rready,
    input [7:0] arlen,
    output reg [31:0] rdata,
    output reg [1:0] rresp,
    output reg rvalid,
    output reg rlast,

    input [31:0] awaddr,
    input awvalid,
    output reg awready,

    input [31:0] wdata,
    input [3:0] wstrb,
    input wvalid,
    output reg wready,

    input bready,
    output reg [1:0] bresp,
    output reg bvalid
);

  parameter HANDLE_RADDR = 0;
  parameter READING = 1;
  parameter HANDLE_RDATA = 2;

  parameter HANDLE_WADDR = 0;
  parameter HANDLE_WDATA = 1;
  parameter WRITING = 2;
  parameter HANDLE_BRESP = 3;

  reg [31:0] memory[0:(1<<24)-1];

  reg [1:0] rstate, wstate;

  reg [31:0] _araddr;
  reg [31:0] _awaddr;
  reg [31:0] _wdata;
  reg [31:0] _wstrb;
  reg [ 7:0] _arlen;

  initial begin
    $readmemh(`MEM_PATH, memory);
  end

  reg is_begin;

  always @(posedge clk) begin
    if (rst) begin
      rstate <= HANDLE_RADDR;
      wstate <= HANDLE_WADDR;

      arready <= 1;
      rresp <= 0;
      rvalid <= 0;
      rlast <= 0;

      awready <= 1;
      wready <= 1;

      bresp <= 0;
      bvalid <= 0;
      is_begin <= 1;
    end else begin
      if (rstate == HANDLE_RADDR) begin
        if (arvalid) begin
          _araddr <= araddr - 32'h8000_0000;
          _arlen  <= arlen;
          arready <= 0;
          rstate  <= READING;
        end
      end else if (rstate == READING) begin
        if (is_begin) begin
          if (_arlen == 3) rdata <= 32'h80000537;  // lui a0, 0x80000
          else if (_arlen == 2) rdata <= 32'h00050067;  // jalr zero, 0(a0)
          else rdata <= 32'h00000013;  // nop
        end else rdata <= memory[_araddr>>2];

        rvalid <= 1;
        if (_arlen != 0) begin
          _arlen  <= _arlen - 1;
          _araddr <= _araddr + 4;
          rlast   <= 0;
        end else begin
          rstate <= HANDLE_RDATA;
          rlast <= 1;
          is_begin <= 0;
        end
      end else begin
        if (rready) begin
          rvalid  <= 0;
          arready <= 1;
          rstate  <= HANDLE_RADDR;
        end
      end

      if (wstate == HANDLE_WADDR) begin
        if (awvalid) begin
          _awaddr <= awaddr - 32'h8000_0000;
          awready <= 0;
        end
        if (wvalid) begin
          _wdata <= wdata;
          _wstrb <= {{8{wstrb[3]}}, {8{wstrb[2]}}, {8{wstrb[1]}}, {8{wstrb[0]}}};
          wready <= 0;
        end

        if (!awready && !wready) wstate <= WRITING;

      end else if (wstate == WRITING) begin
        if (_awaddr == 32'h2000_03f8) begin
          $write("%c", _wdata[7:0]);
          $fflush();
        end else memory[_awaddr>>2] <= (memory[_awaddr>>2] & ~_wstrb) | (_wdata & _wstrb);
        bvalid <= 1;
        wstate <= HANDLE_BRESP;
      end else begin
        if (bready) begin
          bvalid  <= 0;
          awready <= 1;
          wready  <= 1;
          wstate  <= HANDLE_WADDR;
        end
      end
    end
  end


endmodule
