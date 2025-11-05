`timescale 1ns/1ns


module top (
);
    
reg clock;
reg reset;


  // ----------------- AXI Master <-> Mem wires -----------------
  // AW
wire        awready;
wire        awvalid;
wire [3:0]  awid;
wire [31:0] awaddr;
wire [7:0]  awlen;
wire [2:0]  awsize;
wire [1:0]  awburst;

// W / B
wire        wready;
wire        wvalid;
wire [31:0] wdata;
wire [3:0]  wstrb;
wire        wlast;

wire        bready;
wire        bvalid;
wire [1:0]  bresp;

// AR
wire        arready;
wire        arvalid;
wire [31:0] araddr;
wire [7:0]  arlen;
wire [2:0]  arsize;
wire [1:0]  arburst;


// R
wire        rready;
wire        rvalid;
wire [31:0] rdata;
wire [1:0]  rresp;
wire        rlast;


`ifdef CONFIG_WAVE_DUMP
initial begin
`ifdef CONFIG_WAVE_FST
        $display("Dumping FST wave file...");
        $dumpfile("wave.fst");
        $dumpvars(0, top);
      // 如果是 VCD
`elsif CONFIG_WAVE_VCD
        $display("Dumping VCD wave file...");
        $dumpfile("wave.vcd");
        $dumpvars(0, top);
`else
        $display("Unsupported WAVE_FILE_TYPE");
`endif
end
`endif



initial begin
    clock = 1'b0;
    reset = 1'b1;
    #100 reset = 1'b0;
end

always begin
    #1 clock = ~clock;
end


ysyx_23060246 cpu (	// src/CPU.scala:38:21
    .clock                   (clock),
    .reset                   (reset),
    .io_interrupt            (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_master_awready      (awready),
    .io_master_awvalid      (awvalid),
    .io_master_awid    (awid),
    .io_master_awaddr  (awaddr),
    .io_master_awlen   (awlen),
    .io_master_awsize  (awsize),
    .io_master_awburst (awburst),
    // .io_master_awlock  (),
    // .io_master_awcache (),
    // .io_master_awprot  (),
    // .io_master_awqos   (),
    .io_master_wready       (wready),
    .io_master_wvalid       (wvalid),
    .io_master_wdata   (wdata),
    .io_master_wstrb   (wstrb),
    .io_master_wlast   (wlast),
    .io_master_bready       (bready),
    .io_master_bvalid       (bvalid),
    .io_master_bid     (4'b0),
    .io_master_bresp   (bresp),
    .io_master_arready      (arready),
    .io_master_arvalid      (arvalid),
    .io_master_arid    (),
    .io_master_araddr  (araddr),
    .io_master_arlen   (arlen),
    .io_master_arsize  (arsize),
    .io_master_arburst (arburst),
    // .io_master_arlock  (),
    // .io_master_arcache (),
    // .io_master_arprot  (),
    // .io_master_arqos   (),
    .io_master_rready       (rready),
    .io_master_rvalid       (rvalid),
    .io_master_rid     (4'b0),
    .io_master_rdata   (rdata),
    .io_master_rresp   (rresp),
    .io_master_rlast   (rlast),
    .io_slave_awready       (/* unused */),
    .io_slave_awvalid       (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_awid     (4'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_awaddr   (32'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_awlen    (8'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_awsize   (3'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_awburst  (2'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_awlock   (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    // .io_slave_awcache  (4'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_awprot   (3'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_awqos    (4'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_wready        (/* unused */),
    .io_slave_wvalid        (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_wdata    (32'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_wstrb    (4'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_wlast    (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_bready        (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_bvalid        (/* unused */),
    .io_slave_bid      (/* unused */),
    .io_slave_bresp    (/* unused */),
    .io_slave_arready       (/* unused */),
    .io_slave_arvalid       (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_arid     (4'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_araddr   (32'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_arlen    (8'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_arsize   (3'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_arburst  (2'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_arlock   (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    // .io_slave_arcache  (4'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_arprot   (3'h0),	// src/CPU.scala:36:19, :38:21
    // .io_slave_arqos    (4'h0),	// src/CPU.scala:36:19, :38:21
    .io_slave_rready        (1'h0),	// src/CPU.scala:35:23, :36:19, :38:21
    .io_slave_rvalid        (/* unused */),
    .io_slave_rid      (/* unused */),
    .io_slave_rdata    (/* unused */),
    .io_slave_rresp    (/* unused */),
    .io_slave_rlast    (/* unused */)
);	// src/CPU.scala:38:21


AXI_MEM u_mem (
    .clock               (clock),
    .reset               (reset),

    // AW
    .io_axi_aw_ready     (awready),
    .io_axi_aw_valid     (awvalid),
    .io_axi_aw_bits_id   (4'h0),
    .io_axi_aw_bits_addr (awaddr),
    .io_axi_aw_bits_len  (awlen),
    .io_axi_aw_bits_size (awsize),
    .io_axi_aw_bits_burst (2'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_aw_bits_lock  (1'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_aw_bits_cache (4'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_aw_bits_prot  (3'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_aw_bits_qos   (4'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]

    // W / B
    .io_axi_w_ready      (wready),
    .io_axi_w_valid      (wvalid),
    .io_axi_w_bits_data  (wdata),
    .io_axi_w_bits_strb  (wstrb),
    .io_axi_w_bits_last  (1'h1),

    .io_axi_b_ready      (bready),
    .io_axi_b_valid      (bvalid),
    .io_axi_b_bits_id    (),
    .io_axi_b_bits_resp  (),

    // AR
    .io_axi_ar_ready     (arready),
    .io_axi_ar_valid     (arvalid),
    .io_axi_ar_bits_id   (4'h0),
    .io_axi_ar_bits_addr (araddr),
    .io_axi_ar_bits_len  (arlen),
    .io_axi_ar_bits_size (arsize),
    .io_axi_ar_bits_burst(arburst),
    .io_axi_ar_bits_lock  (1'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_ar_bits_cache (4'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_ar_bits_prot  (3'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]
    .io_axi_ar_bits_qos   (4'h0),	// @[src/main/scala/top.scala:24:23, :25:21, :28:20, :38:22, :40:22, :41:24]


    // R
    .io_axi_r_ready      (rready),
    .io_axi_r_valid      (rvalid),
    .io_axi_r_bits_id    (),
    .io_axi_r_bits_data  (rdata),
    .io_axi_r_bits_resp  (),
    .io_axi_r_bits_last  (rlast)
  );


endmodule 



module AXI_MEM(	// @[src/main/scala/sram.scala:51:7]
  input         clock,	// @[src/main/scala/sram.scala:51:7]
                reset,	// @[src/main/scala/sram.scala:51:7]
  output        io_axi_aw_ready,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_aw_valid,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_aw_bits_id,	// @[src/main/scala/sram.scala:52:14]
  input  [31:0] io_axi_aw_bits_addr,	// @[src/main/scala/sram.scala:52:14]
  input  [7:0]  io_axi_aw_bits_len,	// @[src/main/scala/sram.scala:52:14]
  input  [2:0]  io_axi_aw_bits_size,	// @[src/main/scala/sram.scala:52:14]
  input  [1:0]  io_axi_aw_bits_burst,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_aw_bits_lock,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_aw_bits_cache,	// @[src/main/scala/sram.scala:52:14]
  input  [2:0]  io_axi_aw_bits_prot,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_aw_bits_qos,	// @[src/main/scala/sram.scala:52:14]
  output        io_axi_w_ready,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_w_valid,	// @[src/main/scala/sram.scala:52:14]
  input  [31:0] io_axi_w_bits_data,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_w_bits_strb,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_w_bits_last,	// @[src/main/scala/sram.scala:52:14]
                io_axi_b_ready,	// @[src/main/scala/sram.scala:52:14]
  output        io_axi_b_valid,	// @[src/main/scala/sram.scala:52:14]
  output [3:0]  io_axi_b_bits_id,	// @[src/main/scala/sram.scala:52:14]
  output [1:0]  io_axi_b_bits_resp,	// @[src/main/scala/sram.scala:52:14]
  output        io_axi_ar_ready,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_ar_valid,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_ar_bits_id,	// @[src/main/scala/sram.scala:52:14]
  input  [31:0] io_axi_ar_bits_addr,	// @[src/main/scala/sram.scala:52:14]
  input  [7:0]  io_axi_ar_bits_len,	// @[src/main/scala/sram.scala:52:14]
  input  [2:0]  io_axi_ar_bits_size,	// @[src/main/scala/sram.scala:52:14]
  input  [1:0]  io_axi_ar_bits_burst,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_ar_bits_lock,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_ar_bits_cache,	// @[src/main/scala/sram.scala:52:14]
  input  [2:0]  io_axi_ar_bits_prot,	// @[src/main/scala/sram.scala:52:14]
  input  [3:0]  io_axi_ar_bits_qos,	// @[src/main/scala/sram.scala:52:14]
  input         io_axi_r_ready,	// @[src/main/scala/sram.scala:52:14]
  output        io_axi_r_valid,	// @[src/main/scala/sram.scala:52:14]
  output [3:0]  io_axi_r_bits_id,	// @[src/main/scala/sram.scala:52:14]
  output [31:0] io_axi_r_bits_data,	// @[src/main/scala/sram.scala:52:14]
  output [1:0]  io_axi_r_bits_resp,	// @[src/main/scala/sram.scala:52:14]
  output        io_axi_r_bits_last	// @[src/main/scala/sram.scala:52:14]
);

  wire [31:0] _mem_rdata;	// @[src/main/scala/sram.scala:57:22]
  reg  [1:0]  state_r;	// @[src/main/scala/sram.scala:67:24]
  reg  [31:0] rdata;	// @[src/main/scala/sram.scala:77:22]
  reg  [2:0]  state_w;	// @[src/main/scala/sram.scala:89:24]
  reg  [31:0] wdata;	// @[src/main/scala/sram.scala:103:22]
  reg  [31:0] waddr;	// @[src/main/scala/sram.scala:104:22]
  reg  [3:0]  wstrb;	// @[src/main/scala/sram.scala:105:22]
  always @(posedge clock) begin	// @[src/main/scala/sram.scala:51:7]
    if (reset) begin	// @[src/main/scala/sram.scala:51:7]
      state_r <= 2'h0;	// @[src/main/scala/sram.scala:51:7, :67:24]
      rdata <= 32'h0;	// @[src/main/scala/sram.scala:77:22]
      state_w <= 3'h0;	// @[src/main/scala/sram.scala:51:7, :89:24]
      wdata <= 32'h0;	// @[src/main/scala/sram.scala:77:22, :103:22]
      waddr <= 32'h0;	// @[src/main/scala/sram.scala:77:22, :104:22]
      wstrb <= 4'h0;	// @[src/main/scala/sram.scala:105:22]
    end
    else begin	// @[src/main/scala/sram.scala:51:7]
      if (&state_r)	// @[src/main/scala/sram.scala:67:24, :68:45]
        state_r <= io_axi_r_ready ? 2'h0 : 2'h3;	// @[src/main/scala/sram.scala:51:7, :67:24, :73:29]
      else if (state_r == 2'h1)	// @[src/main/scala/sram.scala:51:7, :67:24, :68:45]
        state_r <= 2'h3;	// @[src/main/scala/sram.scala:51:7, :67:24]
      else	// @[src/main/scala/sram.scala:68:45]
        state_r <= {1'h0, ~(|state_r) & io_axi_ar_valid};	// @[src/main/scala/sram.scala:67:24, :68:45, :69:23]
      if (state_r == 2'h1)	// @[src/main/scala/sram.scala:51:7, :67:24, :78:16]
        rdata <= _mem_rdata;	// @[src/main/scala/sram.scala:57:22, :77:22]
      if (state_w == 3'h5)	// @[src/main/scala/sram.scala:89:24, :90:46, :99:30]
        state_w <= io_axi_b_ready ? 3'h0 : 3'h5;	// @[src/main/scala/sram.scala:51:7, :89:24, :99:30]
      else if (state_w == 3'h3)	// @[src/main/scala/sram.scala:89:24, :90:46, :91:24]
        state_w <= 3'h5;	// @[src/main/scala/sram.scala:89:24, :99:30]
      else if (state_w == 3'h2)	// @[src/main/scala/sram.scala:89:24, :90:46, :93:32]
        state_w <= {2'h1, io_axi_aw_valid};	// @[src/main/scala/sram.scala:51:7, :89:24, :95:23]
      else if (state_w == 3'h1)	// @[src/main/scala/sram.scala:51:7, :89:24, :90:46]
        state_w <= {1'h0, io_axi_w_valid, 1'h1};	// @[src/main/scala/sram.scala:68:45, :69:23, :89:24, :94:23, :130:22]
      else if (|state_w)	// @[src/main/scala/sram.scala:89:24, :90:46]
        state_w <= 3'h0;	// @[src/main/scala/sram.scala:51:7, :89:24]
      else	// @[src/main/scala/sram.scala:90:46]
        state_w <=
          io_axi_aw_valid & io_axi_w_valid
            ? 3'h3
            : io_axi_aw_valid ? 3'h1 : {1'h0, io_axi_w_valid, 1'h0};	// @[src/main/scala/sram.scala:51:7, :68:45, :69:23, :89:24, :91:{24,38}, :92:28, :93:32]
      if (io_axi_w_valid) begin	// @[src/main/scala/sram.scala:52:14]
        wdata <= io_axi_w_bits_data;	// @[src/main/scala/sram.scala:103:22]
        wstrb <= io_axi_w_bits_strb;	// @[src/main/scala/sram.scala:105:22]
      end
      if (io_axi_aw_valid)	// @[src/main/scala/sram.scala:52:14]
        waddr <= io_axi_aw_bits_addr;	// @[src/main/scala/sram.scala:104:22]
    end
  end // always @(posedge)
  `ifdef ENABLE_INITIAL_REG_	// @[src/main/scala/sram.scala:51:7]
    `ifdef FIRRTL_BEFORE_INITIAL	// @[src/main/scala/sram.scala:51:7]
      `FIRRTL_BEFORE_INITIAL	// @[src/main/scala/sram.scala:51:7]
    `endif // FIRRTL_BEFORE_INITIAL
    logic [31:0] _RANDOM[0:3];	// @[src/main/scala/sram.scala:51:7]
    initial begin	// @[src/main/scala/sram.scala:51:7]
      `ifdef INIT_RANDOM_PROLOG_	// @[src/main/scala/sram.scala:51:7]
        `INIT_RANDOM_PROLOG_	// @[src/main/scala/sram.scala:51:7]
      `endif // INIT_RANDOM_PROLOG_
      `ifdef RANDOMIZE_REG_INIT	// @[src/main/scala/sram.scala:51:7]
        for (logic [2:0] i = 3'h0; i < 3'h4; i += 3'h1) begin
          _RANDOM[i[1:0]] = `RANDOM;	// @[src/main/scala/sram.scala:51:7]
        end	// @[src/main/scala/sram.scala:51:7]
        state_r = _RANDOM[2'h0][1:0];	// @[src/main/scala/sram.scala:51:7, :67:24]
        rdata = {_RANDOM[2'h0][31:2], _RANDOM[2'h1][1:0]};	// @[src/main/scala/sram.scala:51:7, :67:24, :77:22]
        state_w = _RANDOM[2'h1][4:2];	// @[src/main/scala/sram.scala:51:7, :77:22, :89:24]
        wdata = {_RANDOM[2'h1][31:5], _RANDOM[2'h2][4:0]};	// @[src/main/scala/sram.scala:51:7, :77:22, :103:22]
        waddr = {_RANDOM[2'h2][31:5], _RANDOM[2'h3][4:0]};	// @[src/main/scala/sram.scala:51:7, :103:22, :104:22]
        wstrb = _RANDOM[2'h3][8:5];	// @[src/main/scala/sram.scala:51:7, :104:22, :105:22]
      `endif // RANDOMIZE_REG_INIT
    end // initial
    `ifdef FIRRTL_AFTER_INITIAL	// @[src/main/scala/sram.scala:51:7]
      `FIRRTL_AFTER_INITIAL	// @[src/main/scala/sram.scala:51:7]
    `endif // FIRRTL_AFTER_INITIAL
  `endif // ENABLE_INITIAL_REG_
  SoCMem mem (	// @[src/main/scala/sram.scala:57:22]
    .clock (clock),
    .reset (reset),
    .we    (state_w == 3'h3),	// @[src/main/scala/sram.scala:89:24, :91:24, :122:24]
    .waddr ({waddr[31:2], 2'h0}),	// @[src/main/scala/sram.scala:51:7, :104:22, :123:{22,28}]
    .raddr ({io_axi_ar_bits_addr[31:2], 2'h0}),	// @[src/main/scala/sram.scala:51:7, :121:{22,39}]
    .wdata (wdata),	// @[src/main/scala/sram.scala:103:22]
    .wmask ({4'h0, wstrb}),	// @[src/main/scala/sram.scala:105:22, :125:16]
    .rdata (_mem_rdata)
  );
  assign io_axi_aw_ready = ~(|state_w) | state_w == 3'h2;	// @[src/main/scala/sram.scala:51:7, :89:24, :90:46, :93:32, :114:{27,44,55}]
  assign io_axi_w_ready = ~(|state_w) | state_w == 3'h1;	// @[src/main/scala/sram.scala:51:7, :89:24, :90:46, :114:27, :115:{43,54}]
  assign io_axi_b_valid = state_w == 3'h5;	// @[src/main/scala/sram.scala:51:7, :89:24, :99:30, :116:26]
  assign io_axi_b_bits_id = 4'h0;	// @[src/main/scala/sram.scala:51:7, :105:22]
  assign io_axi_b_bits_resp = 2'h0;	// @[src/main/scala/sram.scala:51:7]
  assign io_axi_ar_ready = ~(|state_r);	// @[src/main/scala/sram.scala:51:7, :67:24, :68:45, :76:27]
  assign io_axi_r_valid = &state_r;	// @[src/main/scala/sram.scala:51:7, :67:24, :81:26]
  assign io_axi_r_bits_id = 4'h0;	// @[src/main/scala/sram.scala:51:7, :105:22]
  assign io_axi_r_bits_data = rdata;	// @[src/main/scala/sram.scala:51:7, :77:22]
  assign io_axi_r_bits_resp = 2'h0;	// @[src/main/scala/sram.scala:51:7]
  assign io_axi_r_bits_last = 1'h1;	// @[src/main/scala/sram.scala:51:7, :130:22]
endmodule


`define MROM_BASE  32'h2000_0000
`define MROM_SIZE  32'h0000_1000   // 4 KiB

`define SRAM_BASE  32'h0f00_0000
`define SRAM_SIZE  32'h0000_2000   // 8 KiB

`define FLASH_BASE 32'h3000_0000
`define FLASH_SIZE 32'h0100_0000   // 16 MiB

`define PSRAM_BASE 32'h8000_0000
`define PSRAM_SIZE 32'h0040_0000   // 4 MiB

`define SDRAM_BASE 32'ha000_0000
`define SDRAM_SIZE 32'h0200_0000   // 32 MiB

module SoCMem(
  input  logic        clock,
  input  logic        reset,           // 1: reset, 0: normal

  input  logic        we,
  input  logic [31:0] waddr,           // byte addr
  input  logic [31:0] raddr,           // byte addr
  input  logic [31:0] wdata,
  input  logic [7:0]  wmask,           // 使用低4位做每字节写使能

  output logic [31:0] rdata
);

// ---- 地址命中判断 ----
function automatic bit in_range(
  input logic [31:0] a,
  input logic [31:0] base,
  input logic [31:0] size
);
  logic [31:0] hi;
  hi = base + size - 1;
  return ($unsigned(a) >= $unsigned(base)) &&
         ($unsigned(a) <= $unsigned(hi));
endfunction


`ifdef USE_SOC
  // ---- 每区容量（字节）→ 仿真容量（字） ----
  localparam int unsigned ROM_BYTES   =
      (`FLASH_SIZE > `MROM_SIZE) ? `FLASH_SIZE : `MROM_SIZE; // 共用一份ROM，取较大值
`ifdef SMALL_MEM
  localparam int unsigned ROM_SIM_BYTES    = 64*1024;        // 缩小大区
  localparam int unsigned PSRAM_SIM_BYTES  = 64*1024;
  localparam int unsigned SDRAM_SIM_BYTES  = 64*1024;
`else
  localparam int unsigned ROM_SIM_BYTES    = ROM_BYTES;
  localparam int unsigned PSRAM_SIM_BYTES  = `PSRAM_SIZE;
  localparam int unsigned SDRAM_SIM_BYTES  = `SDRAM_SIZE;
`endif
  localparam int unsigned SRAM_SIM_BYTES  = `SRAM_SIZE;      // SRAM 保持真实尺寸

  localparam int unsigned ROM_WORDS   = ROM_SIM_BYTES   >> 2;
  localparam int unsigned SRAM_WORDS  = SRAM_SIM_BYTES  >> 2;
  localparam int unsigned PSRAM_WORDS = PSRAM_SIM_BYTES >> 2;
  localparam int unsigned SDRAM_WORDS = SDRAM_SIM_BYTES >> 2;

  localparam int ROM_ABITS   = (ROM_WORDS   > 1) ? $clog2(ROM_WORDS)   : 1;
  localparam int SRAM_ABITS  = (SRAM_WORDS  > 1) ? $clog2(SRAM_WORDS)  : 1;
  localparam int PSRAM_ABITS = (PSRAM_WORDS > 1) ? $clog2(PSRAM_WORDS) : 1;
  localparam int SDRAM_ABITS = (SDRAM_WORDS > 1) ? $clog2(SDRAM_WORDS) : 1;

  // ---- 存储实例 ----
  // MROM + FLASH 共用一块 ROM
  logic [31:0] rom_mem   [0:ROM_WORDS-1];
  logic [31:0] sram_mem  [0:SRAM_WORDS-1];
  logic [31:0] psram_mem [0:PSRAM_WORDS-1];
  logic [31:0] sdram_mem [0:SDRAM_WORDS-1];

  // ---- 镜像路径：载入 ROM（覆盖 MROM/FLASH）----
  //`define IMG_PATH "/home/han/Disk/Document/PROJECT/ysyx/ysyx-workbench/npc/iverilog/add-ysyxsoc.mem"
  integer i;
  initial begin
    // 可选清零
`ifndef NO_CLEAR
    for (i=0;i<ROM_WORDS;i++)   rom_mem[i]   = 32'hf3f3f3f3;
    for (i=0;i<SRAM_WORDS;i++)  sram_mem[i]  = 32'hf3f3f3f3;
    for (i=0;i<PSRAM_WORDS;i++) psram_mem[i] = 32'hf3f3f3f3;
    for (i=0;i<SDRAM_WORDS;i++) sdram_mem[i] = 32'hf3f3f3f3;
`endif
    // 只从文件加载 ROM（供 MROM/FLASH 共用）
    $readmemh(`IMG_PATH, rom_mem);  // 建议用 objcopy --adjust-vma 把起始平移到 0
  end


  logic [31:0] data;
  // ---- 组合读：按片上地址选择 ----
  logic [3:0] in_mem;
  always_comb begin
    
    data = 32'h0;

    // MROM (rom_mem)
    if (in_range(raddr, `MROM_BASE, `MROM_SIZE)) begin
      logic [ROM_ABITS-1:0] idx;
      idx = ((raddr - `MROM_BASE) >> 2)/* verilator lint_off WIDTHTRUNC */;
      if (idx < ROM_WORDS) data = rom_mem[idx]/* verilator lint_off WIDTHEXPAND */;
      else                 data = 32'h0;
        in_mem = 1;
    end
    // FLASH (rom_mem)
    else if (in_range(raddr, `FLASH_BASE, `FLASH_SIZE)) begin
        logic [ROM_ABITS-1:0] idx;
        idx = ((raddr - `FLASH_BASE) >> 2);
        if (idx < ROM_WORDS) data = rom_mem[idx];
        else data = rom_mem[idx]/* verilator lint_off WIDTHEXPAND */;
    in_mem = 2;
    end
    // SRAM
    else if (in_range(raddr, `SRAM_BASE, `SRAM_SIZE)) begin
      logic [SRAM_ABITS-1:0] idx;
      idx = ((raddr - `SRAM_BASE) >> 2)/* verilator lint_off WIDTHTRUNC */;
      if (idx < SRAM_WORDS) data = sram_mem[idx]/* verilator lint_off WIDTHEXPAND */;
      else                  data = 32'h0;
        in_mem = 3;
    end
    // PSRAM
    else if (in_range(raddr, `PSRAM_BASE, `PSRAM_SIZE)) begin
      logic [PSRAM_ABITS-1:0] idx;
      idx = ((raddr - `PSRAM_BASE) >> 2)/* verilator lint_off WIDTHTRUNC */;
      if (idx < PSRAM_WORDS) data = psram_mem[idx]/* verilator lint_off WIDTHEXPAND */;
      else                   data = 32'h0;
        in_mem = 4;
    end
    // SDRAM
    else if (in_range(raddr, `SDRAM_BASE, `SDRAM_SIZE)) begin
      logic [SDRAM_ABITS-1:0] idx;
      idx = ((raddr - `SDRAM_BASE) >> 2);
      if (idx < SDRAM_WORDS) data = sdram_mem[idx];
      else                   data = 32'h0;
        in_mem = 5;
    end
    else begin
        in_mem = 0;
        data = 32'h0; // 未映射区域返回 0（也可返回 0xFFFF_FFFF 或触发断言）
    end

    // 复位时统一返回 0
    rdata = reset ? 32'h0 : data;
  end

  // ---- 同步写：只允许写 RAM（可选放开 FLASH 写入）----
  always_ff @(posedge clock) begin
    if (!reset && we) begin
      // 写 SRAM
      if (in_range(waddr, `SRAM_BASE, `SRAM_SIZE)) begin
        logic [SRAM_ABITS-1:0] idx = ((waddr - `SRAM_BASE) >> 2);
        if (idx < SRAM_WORDS) begin
          if (wmask[0]) sram_mem[idx][7:0]   <= wdata[7:0];
          if (wmask[1]) sram_mem[idx][15:8]  <= wdata[15:8];
          if (wmask[2]) sram_mem[idx][23:16] <= wdata[23:16];
          if (wmask[3]) sram_mem[idx][31:24] <= wdata[31:24];
        end
      end
      // 写 PSRAM
      else if (in_range(waddr, `PSRAM_BASE, `PSRAM_SIZE)) begin
        logic [PSRAM_ABITS-1:0] idx = ((waddr - `PSRAM_BASE) >> 2);
        if (idx < PSRAM_WORDS) begin
          if (wmask[0]) psram_mem[idx][7:0]   <= wdata[7:0];
          if (wmask[1]) psram_mem[idx][15:8]  <= wdata[15:8];
          if (wmask[2]) psram_mem[idx][23:16] <= wdata[23:16];
          if (wmask[3]) psram_mem[idx][31:24] <= wdata[31:24];
        end
      end
      // 写 SDRAM
      else if (in_range(waddr, `SDRAM_BASE, `SDRAM_SIZE)) begin
        logic [SDRAM_ABITS-1:0] idx = ((waddr - `SDRAM_BASE) >> 2);
        if (idx < SDRAM_WORDS) begin
          if (wmask[0]) sdram_mem[idx][7:0]   <= wdata[7:0];
          if (wmask[1]) sdram_mem[idx][15:8]  <= wdata[15:8];
          if (wmask[2]) sdram_mem[idx][23:16] <= wdata[23:16];
          if (wmask[3]) sdram_mem[idx][31:24] <= wdata[31:24];
        end
      end
`ifdef ALLOW_FLASH_WRITE
      // 可选：允许写 FLASH（仍映射到 rom_mem）
      else if (in_range(waddr, `FLASH_BASE, `FLASH_SIZE)) begin
        logic [ROM_ABITS-1:0] idx = ((waddr - `FLASH_BASE) >> 2);
        if (idx < ROM_WORDS) begin
          if (wmask[0]) rom_mem[idx][7:0]   <= wdata[7:0];
          if (wmask[1]) rom_mem[idx][15:8]  <= wdata[15:8];
          if (wmask[2]) rom_mem[idx][23:16] <= wdata[23:16];
          if (wmask[3]) rom_mem[idx][31:24] <= wdata[31:24];
        end
      end
`endif
      // 其它区域：忽略或断言
    end
  end

`else 

`ifdef SMALL_MEM
  localparam int unsigned PMEM_BYTES = 128*1024;
`else
  localparam int unsigned PMEM_BYTES = 1024*1024;
`endif 

  localparam int unsigned PMEM_WORDS = PMEM_BYTES >> 2;


logic [31:0] pmem   [0:PMEM_WORDS-1];

`define PMEM_BASE 32'h8000_0000
`define PMEM_SIZE PMEM_BYTES

`define SERIAL_BASE 32'ha000_03f8
`define SERIAL_SIZE 4

`define VGACTRL_BASE 32'ha000_0100
`define VGACTRL_SIZE 8

// initial begin
//   $readmemh(`IMG_PATH, pmem);
// end
initial begin
  for (int i = 0; i < PMEM_WORDS; i++)
    pmem[i] = 32'h0;
  $readmemh(`IMG_PATH, pmem);
end

function automatic logic [31:0] jump_stub_instr(input logic [31:0] addr);
  unique case (addr)
    32'h3000_0000: jump_stub_instr = 32'h8000_02B7; // LUI x5, 0x80000
    32'h3000_0004: jump_stub_instr = 32'h0002_8067; // JALR x0, 0(x5)
    default:        jump_stub_instr = 32'h0000_0013; // NOP (ADDI x0,x0,0)
  endcase
endfunction

logic [31:0] data;
logic [31:0] idx_r;
always_comb begin
  data = 32'h0;
  idx_r = 32'h0;
  if (in_range(raddr, 32'h3000_0000, 32)) begin
    data = jump_stub_instr(raddr);
  end
  else if (in_range(raddr, `PMEM_BASE, `PMEM_SIZE)) begin
    idx_r = (raddr - `PMEM_BASE) >> 2;
    if (idx_r < PMEM_WORDS) data = pmem[idx_r];
  end
  rdata = reset ? 32'h0 : data;
end

logic [31:0] idx_w;
always_ff @(posedge clock) begin
  if (!reset && we) begin
    if (in_range(waddr, `PMEM_BASE, `PMEM_SIZE)) begin
      idx_w = (waddr - `PMEM_BASE) >> 2;
      if (idx_w < PMEM_WORDS) begin
        if (wmask[0]) pmem[idx_w][7:0]   <= wdata[7:0];
        if (wmask[1]) pmem[idx_w][15:8]  <= wdata[15:8];
        if (wmask[2]) pmem[idx_w][23:16] <= wdata[23:16];
        if (wmask[3]) pmem[idx_w][31:24] <= wdata[31:24];
      end
    end
    else if (in_range(waddr, `SERIAL_BASE, `SERIAL_SIZE)) begin
      $write("%c", wdata[7:0]); $fflush();
    end
    else if (in_range(waddr, `VGACTRL_BASE, `VGACTRL_SIZE)) begin
      // do nothing
    end
    else begin 
      $display("\33[1;31mERROR: write to unmapped address %h, pmem: [%h - %h]\33[0m",
               waddr, `PMEM_BASE, `PMEM_BASE + `PMEM_SIZE - 1);
      $finish;
    end
  end
end

`endif 

endmodule
