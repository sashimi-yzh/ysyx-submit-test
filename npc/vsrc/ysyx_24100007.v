module ysyx_24100007(
    input clock,
    input reset,
    input io_interrupt,

    input               io_master_awready,
    output              io_master_awvalid,
    output [31:0]       io_master_awaddr,
    output [3:0]        io_master_awid,
    output [7:0]        io_master_awlen,
    output [2:0]        io_master_awsize,
    output [1:0]        io_master_awburst,

    input               io_master_wready,
    output              io_master_wvalid,
    output [31:0]       io_master_wdata,
    output [3:0]        io_master_wstrb,
    output              io_master_wlast,

    output              io_master_bready,
    input               io_master_bvalid,
    input  [1:0]        io_master_bresp,
    input  [3:0]        io_master_bid,

    input               io_master_arready,
    output              io_master_arvalid,
    output [31:0]       io_master_araddr,
    output [3:0]        io_master_arid,
    output [7:0]        io_master_arlen,
    output [2:0]        io_master_arsize,
    output [1:0]        io_master_arburst,

    output              io_master_rready,
    input               io_master_rvalid,
    input  [1:0]        io_master_rresp,
    input  [31:0]       io_master_rdata,
    input               io_master_rlast,
    input  [3:0]        io_master_rid,

    // the signal below not used
    output              io_slave_awready,
    input               io_slave_awvalid,
    input  [31:0]       io_slave_awaddr,
    input  [3:0]        io_slave_awid,
    input  [7:0]        io_slave_awlen,
    input  [2:0]        io_slave_awsize,
    input  [1:0]        io_slave_awburst,

    output              io_slave_wready,
    input               io_slave_wvalid,
    input  [31:0]       io_slave_wdata,
    input  [3:0]        io_slave_wstrb,
    input               io_slave_wlast,

    input               io_slave_bready,
    output              io_slave_bvalid,
    output [1:0]        io_slave_bresp,
    output [3:0]        io_slave_bid,

    output              io_slave_arready,
    input               io_slave_arvalid,
    input  [31:0]       io_slave_araddr,
    input  [3:0]        io_slave_arid,
    input  [7:0]        io_slave_arlen,
    input  [2:0]        io_slave_arsize,
    input  [1:0]        io_slave_arburst,

    input               io_slave_rready,
    output              io_slave_rvalid,
    output [1:0]        io_slave_rresp,
    output [31:0]       io_slave_rdata,
    output              io_slave_rlast,
    output [3:0]        io_slave_rid
);

  wire core_awvalid;
  wire core_wvalid;
  wire core_arvalid;
  wire core_rready;
  wire core_bready;
  wire core_bvalid;
  wire core_rvalid;
  wire core_awready;
  wire core_wready;
  wire core_arready;
  wire [31:0] core_araddr;
  wire [31:0] core_awaddr;
  wire [31:0] core_wdata;
  wire [31:0] core_rdata;
  wire [3:0] core_wstrb;
  wire [1:0] core_bresp;
  wire [2:0] core_awsize;
  wire [2:0] core_arsize;
  wire [7:0] core_awlen;
  wire [7:0] core_arlen;
  wire [1:0] core_awburst;
  wire [1:0] core_arburst;
  wire core_wlast;
  wire core_rlast;
  wire [1:0] core_rresp;

  ysyx_24100007_core #(.PORT_NUM(1)) core0(
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    // AXI接口连接到arbiter
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),
    .rresp(core_rresp)
  );

  assign core_rresp = io_master_rresp;

  // Arbiter模块
  wire [63:0] arbiter_araddr_out, arbiter_awaddr_out;
  wire [63:0] arbiter_wdata_out;
  wire [7:0] arbiter_wstrb_out;
  wire [5:0] arbiter_awsize_out, arbiter_arsize_out;
  wire [15:0] arbiter_awlen_out, arbiter_arlen_out;
  wire [3:0] arbiter_awburst_out, arbiter_arburst_out;
  wire [1:0] arbiter_wlast_out;
  wire [1:0] arbiter_awvalid_out, arbiter_wvalid_out, arbiter_arvalid_out;
  wire [1:0] arbiter_rready_out, arbiter_bready_out;
  wire [1:0] arbiter_bvalid_in, arbiter_rvalid_in;
  wire [1:0] arbiter_awready_in, arbiter_wready_in, arbiter_arready_in;
  wire [63:0] arbiter_rdata_in;
  wire [3:0] arbiter_bresp_in;
  wire [1:0] arbiter_rlast_in;

  ysyx_24100007_arbiter #(.SLAVE_NUM(2)) arbiter0(
    .clk(clock),
    .rst(reset),

    // Master接口 - 来自core
    .awvalid(core_awvalid),
    .wvalid(core_wvalid),
    .arvalid(core_arvalid),
    .rready(core_rready),
    .bready(core_bready),
    .bvalid(core_bvalid),
    .rvalid(core_rvalid),
    .awready(core_awready),
    .wready(core_wready),
    .arready(core_arready),
    .araddr(core_araddr),
    .awaddr(core_awaddr),
    .wdata(core_wdata),
    .rdata(core_rdata),
    .wstrb(core_wstrb),
    .bresp(core_bresp),
    .awsize(core_awsize),
    .arsize(core_arsize),
    .awlen(core_awlen),
    .arlen(core_arlen),
    .awburst(core_awburst),
    .arburst(core_arburst),
    .wlast(core_wlast),
    .rlast(core_rlast),

    // Slave接口 - 连接到CLINT和外部AXI
    .awvalid_out(arbiter_awvalid_out),
    .wvalid_out(arbiter_wvalid_out),
    .arvalid_out(arbiter_arvalid_out),
    .rready_out(arbiter_rready_out),
    .bready_out(arbiter_bready_out),
    .bvalid_in(arbiter_bvalid_in),
    .rvalid_in(arbiter_rvalid_in),
    .awready_in(arbiter_awready_in),
    .wready_in(arbiter_wready_in),
    .arready_in(arbiter_arready_in),
    .araddr_out(arbiter_araddr_out),
    .awaddr_out(arbiter_awaddr_out),
    .wdata_out(arbiter_wdata_out),
    .wstrb_out(arbiter_wstrb_out),
    .rdata_in(arbiter_rdata_in),
    .bresp_in(arbiter_bresp_in),
    .awsize_out(arbiter_awsize_out),
    .arsize_out(arbiter_arsize_out),
    .awlen_out(arbiter_awlen_out),
    .arlen_out(arbiter_arlen_out),
    .awburst_out(arbiter_awburst_out),
    .arburst_out(arbiter_arburst_out),
    .wlast_out(arbiter_wlast_out),
    .rlast_in(arbiter_rlast_in)
  );

  // ---------------------------------
  // CLINT (Core Local Interruptor)
  // ---------------------------------
  // CLINT地址范围：0x02000000 - 0x0200ffff
    ysyx_24100007_clint clint0(
    .clk(clock),
    .reset(reset),
    .awvalid(arbiter_awvalid_out[1]),
    .awready(arbiter_awready_in[1]),
    .awaddr(arbiter_awaddr_out[63:32]),
    .awsize(arbiter_awsize_out[5:3]),
    .wvalid(arbiter_wvalid_out[1]),
    .wready(arbiter_wready_in[1]),
    .wdata(arbiter_wdata_out[63:32]),
    .wstrb(arbiter_wstrb_out[7:4]),
    .arvalid(arbiter_arvalid_out[1]),
    .arready(arbiter_arready_in[1]),
    .araddr(arbiter_araddr_out[63:32]),
    .arsize(arbiter_arsize_out[5:3]),
    .rvalid(arbiter_rvalid_in[1]),
    .rready(arbiter_rready_out[1]),
    .rdata(arbiter_rdata_in[63:32]),
    .bvalid(arbiter_bvalid_in[1]),
    .bready(arbiter_bready_out[1]),
    .bresp(arbiter_bresp_in[3:2])
  );

    // 外部AXI接口直接连接到arbiter slave[0]
  assign io_master_awvalid = arbiter_awvalid_out[0];
  assign io_master_wvalid = arbiter_wvalid_out[0];
  assign io_master_arvalid = arbiter_arvalid_out[0];
  assign io_master_rready = arbiter_rready_out[0];
  assign io_master_bready = arbiter_bready_out[0];
  assign io_master_araddr = arbiter_araddr_out[31:0];
  assign io_master_awaddr = arbiter_awaddr_out[31:0];
  assign io_master_wdata = arbiter_wdata_out[31:0];
  assign io_master_wstrb = arbiter_wstrb_out[3:0];
  assign io_master_awsize = arbiter_awsize_out[2:0];
  assign io_master_arsize = arbiter_arsize_out[2:0];
  assign io_master_awlen = arbiter_awlen_out[7:0];
  assign io_master_arlen = arbiter_arlen_out[7:0];
  assign io_master_awburst = arbiter_awburst_out[1:0];
  assign io_master_arburst = arbiter_arburst_out[1:0];
  assign io_master_wlast = arbiter_wlast_out[0];

  // arbiter slave[0]输入来自外部AXI
  assign arbiter_bvalid_in[0] = io_master_bvalid;
  assign arbiter_rvalid_in[0] = io_master_rvalid;
  assign arbiter_awready_in[0] = io_master_awready;
  assign arbiter_wready_in[0] = io_master_wready;
  assign arbiter_arready_in[0] = io_master_arready;
  assign arbiter_rdata_in[31:0] = io_master_rdata;
  assign arbiter_bresp_in[1:0] = io_master_bresp;
  assign arbiter_rlast_in[0] = io_master_rlast;

  assign arbiter_rlast_in[1] = arbiter_rvalid_in[1];

  assign io_master_awid = 4'b0;
  assign io_master_arid = 4'd0;

  assign io_slave_awready = 1'b0;
  assign io_slave_wready  = 1'b0;
  assign io_slave_bvalid  = 1'b0;
  assign io_slave_bresp   = 2'b00;
  assign io_slave_bid     = 4'b0000;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid  = 1'b0;
  assign io_slave_rresp   = 2'b00;
  assign io_slave_rdata   = 32'b0;
  assign io_slave_rlast   = 1'b0;
  assign io_slave_rid     = 4'b0000;

endmodule
