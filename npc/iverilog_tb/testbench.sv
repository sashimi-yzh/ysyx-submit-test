`timescale 1ns / 100ps
module tb_npc;
  reg clock, reset;
  reg [31:0] mem_init[0:15];

  reg [31:0] mem[0:32'h3FFFFFF];
  always #0.5 clock = ~clock;

  wire [31:0] tb_raddr;
  wire [31:0] tb_waddr;
  wire [31:0] tb_wdata;
  wire [3:0] tb_wmask;
  wire [31:0] tb_wmask32;
  wire tb_wen;
  wire tb_valid;
  reg [31:0] tb_rdata;
  // AXI write address channel
  wire awready, awvalid;
  wire [31:0] awaddr;
  wire [ 3:0] awid;
  wire [ 7:0] awlen;
  wire [ 2:0] awsize;
  wire [ 1:0] awburst;

  // AXI write data channel
  wire wready, wvalid;
  wire [31:0] wdata;
  wire [3:0] wstrb;
  wire wlast;

  // AXI write response
  wire bready, bvalid;
  wire [1:0] bresp;
  wire [3:0] bid;

  // AXI read address channel
  wire arready, arvalid;
  wire [31:0] araddr;
  wire [ 3:0] arid;
  wire [ 7:0] arlen;
  wire [ 2:0] arsize;
  wire [ 1:0] arburst;

  // AXI read data channel
  wire rready, rvalid;
  wire [1:0] rresp;
  wire [31:0] rdata_bus;
  wire rlast;
  wire [3:0] rid;



  integer clock_cnt;
  initial begin : init
    // $dumpfile("wave.vcd");
    // $dumpvars(1, tb_npc);
    clock_cnt   = 0;
    mem_init[0] = 32'h800002b7;
    for (integer i = 1; i < 16; i = i + 1) begin
      mem_init[i] = 32'h00028067;
    end

    $readmemh("./iv_temp/temp.hex", mem);
    for (integer i = 0; i < 32'h3FFFFF; i = i + 1) begin : convert_endian
      reg [31:0] raw;
      raw = mem[i];
      mem[i] = {raw[7-:8], raw[15-:8], raw[23-:8], raw[31-:8]};
    end
    $display("First 8 instructions :");
    $display("%08x %08x %08x %08x", mem[0], mem[1], mem[2], mem[3]);
    $display("%08x %08x %08x %08x", mem[4], mem[5], mem[6], mem[7]);
    $display("----------------- Simulation Begin -----------------");

    clock = 1'b1;
    reset = 1'b1;
    repeat (3) @(negedge clock);
    reset = 1'b0;
  end
  wire [3:0] dbg;
  always @(posedge clock)
    if (reset) clock_cnt = 0;
    else begin
      clock_cnt = clock_cnt + 1;
      if (clock_cnt >= 10000000) begin
        $display("Simulation end");
        $finish;
      end
    end
  ysyx_25080216 dut (
      .clock(clock),
      .reset(reset),

      // AXI master write address
      .io_master_awready(awready),
      .io_master_awvalid(awvalid),
      .io_master_awaddr(awaddr),
      .io_master_awid(awid),
      .io_master_awlen(awlen),
      .io_master_awsize(awsize),
      .io_master_awburst(awburst),

      // AXI master write data
      .io_master_wready(wready),
      .io_master_wvalid(wvalid),
      .io_master_wdata (wdata),
      .io_master_wstrb (wstrb),
      .io_master_wlast (wlast),

      // AXI master write response
      .io_master_bready(bready),
      .io_master_bvalid(bvalid),
      .io_master_bresp(bresp),
      .io_master_bid(bid),

      // AXI master read address
      .io_master_arready(arready),
      .io_master_arvalid(arvalid),
      .io_master_araddr(araddr),
      .io_master_arid(arid),
      .io_master_arlen(arlen),
      .io_master_arsize(arsize),
      .io_master_arburst(arburst),

      // AXI master read data
      .io_master_rready(rready),
      .io_master_rvalid(rvalid),
      .io_master_rresp(rresp),
      .io_master_rdata(rdata_bus),
      .io_master_rlast(rlast),
      .io_master_rid(rid),

      .io_slave_bid(dbg)
  );

  __sim_bus u_simbus (
      .clock(clock),
      .reset(reset),

      // memory interface
      .io_raddr(tb_raddr),
      .io_waddr(tb_waddr),
      .io_wdata(tb_wdata),
      .io_rdata(tb_rdata),
      .io_wmask(tb_wmask),
      .io_valid(tb_valid),
      .io_wen  (tb_wen),

      // AXI write address
      .fetch_port_aw_ready(awready),
      .fetch_port_aw_valid(awvalid),
      .fetch_port_aw_addr(awaddr),
      .fetch_port_aw_id(awid),
      // .fetch_port_aw_len(awlen),
      // .fetch_port_aw_size(awsize),
      // .fetch_port_aw_burst(awburst),

      // AXI write data
      .fetch_port_w_ready(wready),
      .fetch_port_w_valid(wvalid),
      .fetch_port_w_data (wdata),
      .fetch_port_w_strb (wstrb),
      .fetch_port_w_last (wlast),

      // AXI write response
      .fetch_port_b_ready(bready),
      .fetch_port_b_valid(bvalid),
      // .fetch_port_b_resp(bresp),
      .fetch_port_b_id(bid),

      // AXI read address
      .fetch_port_ar_ready(arready),
      .fetch_port_ar_valid(arvalid),
      .fetch_port_ar_addr(araddr),
      .fetch_port_ar_id(arid),
      .fetch_port_ar_len(arlen),
      .fetch_port_ar_size(arsize),
      // .fetch_port_ar_burst(arburst),

      // AXI read data
      .fetch_port_r_ready(rready),
      .fetch_port_r_valid(rvalid),
      // .fetch_port_r_resp(rresp),
      .fetch_port_r_data(rdata_bus),
      .fetch_port_r_last(rlast),
      .fetch_port_r_id(rid)
  );

  assign rresp = 2'b00;
  assign bresp = 2'b00;


  assign tb_wmask32 = {{8{tb_wmask[3]}}, {8{tb_wmask[2]}}, {8{tb_wmask[1]}}, {8{tb_wmask[0]}}};

  always @(posedge clock) begin
    if (tb_valid && !reset) begin
      // $display("%08x", tb_raddr);
      if (tb_raddr >= 32'h80000000 && tb_raddr < 32'ha0000000)
        tb_rdata <= mem[(tb_raddr-32'h80000000)>>2];
      else if (tb_raddr == 32'ha0000048 || tb_raddr == 32'ha000004c) begin : rtc
        integer offset;
        reg [63:0] rtc_us;
        offset = (tb_raddr - 32'ha0000048);
        rtc_us = ($time) / 1000;
        // $display("time : %0d, offset %0d.  %08x %08x", rtc_us, offset, rtc_us[31:0], rtc_us[63:32]);
        if (offset == 0) tb_rdata <= rtc_us[31:0];
        else tb_rdata <= rtc_us[63:32];
      end else begin
        tb_rdata <= mem_init[(tb_raddr-32'h30000000)>>2];
        // $display("rd : %08x", mem_init[(tb_raddr-32'h30000000)>>2]);
      end
    end
  end

  always @(posedge clock) begin
    if (tb_wen && !reset) begin
      if (tb_waddr < 32'ha0000000)
        mem[(tb_waddr-32'h80000000)>>2] = (mem[(tb_waddr-32'h80000000)>>2] & ~tb_wmask32) | (tb_wdata & tb_wmask32);
      else if (tb_waddr == 32'ha00003f8) $write("%c", tb_wdata[7:0]);
    end
  end

`ifndef SOC
  int inst_cnt;
  wire step, ebreak;
  wire [31:0] pc;
  assign step = dut.cpu.io_ok_to_step;
  assign ebreak = dut.cpu.io_ebreak;
  assign pc =dut.cpu.io_pc;

  initial inst_cnt = 1;

  always @(posedge clock) begin
    if (reset) inst_cnt <= 0;
    else if (step) begin
      inst_cnt = inst_cnt + 1;
      //   $display("PC = %08x", pc);
    end
  end

  always @(posedge clock) begin
    if (ebreak && !reset) begin
      $display("HALT@PC=%08h, inst count : %0d", pc, inst_cnt);
      $display("a0 = %08h", dut.cpu.gpr.register_bank_regs_9_r);
      if (dut.cpu.gpr.register_bank_regs_9_r === 32'h0) begin
        $display("HIT GOOD TRAP");
        $finish;
      end else begin
        $display("HIT BAD TRAP");
        $fatal;
      end

    end
  end
`endif





endmodule
