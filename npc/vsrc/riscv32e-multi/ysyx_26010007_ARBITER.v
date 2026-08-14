`include "ysyx_26010007_defines.v"
module ysyx_26010007_ARBITER(
  input     clock,
  input     reset,

  input                         icache_arvalid,
  output reg                    icache_arready,
  input [`PADDR_WIDTH-1:0]      icache_araddr,
  input [7:0]                   icache_arlen,
  input [2:0]                   icache_arsize,
  input [3:0]                   icache_arid,
  input [1:0]                   icache_arburst,

  output reg                    icache_rvalid,
  input                         icache_rready,
  output reg [`WORD_WIDTH-1:0]  icache_rdata,
  output reg [1:0]              icache_rresp,
  output reg                    icache_rlast,
  output reg [3:0]              icache_rid,

  input                         icache_awvalid,
  output reg                    icache_awready,
  input [`PADDR_WIDTH-1:0]      icache_awaddr,
  input [7:0]                   icache_awlen,
  input [2:0]                   icache_awsize,
  input [3:0]                   icache_awid,
  input [1:0]                   icache_awburst,

  input                         icache_wvalid,
  output reg                    icache_wready,
  input [`WORD_WIDTH-1:0]       icache_wdata,
  input [3:0]                   icache_wstrb,
  input                         icache_wlast,

  output reg                    icache_bvalid,
  input                         icache_bready,
  output reg [1:0]              icache_bresp,
  output reg [3:0]              icache_bid,

  input                         lsu_arvalid,
  output reg                    lsu_arready,
  input [`PADDR_WIDTH-1:0]      lsu_araddr,
  input [7:0]                   lsu_arlen,
  input [2:0]                   lsu_arsize,
  input [3:0]                   lsu_arid,
  input [1:0]                   lsu_arburst,

  output reg                    lsu_rvalid,
  input                         lsu_rready,
  output reg [`WORD_WIDTH-1:0]  lsu_rdata,
  output reg [1:0]              lsu_rresp,
  output reg                    lsu_rlast,
  output reg [3:0]              lsu_rid,

  input                         lsu_awvalid,
  output reg                    lsu_awready,
  input [`PADDR_WIDTH-1:0]      lsu_awaddr,
  input [7:0]                   lsu_awlen,
  input [2:0]                   lsu_awsize,
  input [3:0]                   lsu_awid,
  input [1:0]                   lsu_awburst,

  input                         lsu_wvalid,
  output reg                    lsu_wready,
  input [`WORD_WIDTH-1:0]       lsu_wdata,
  input [3:0]                   lsu_wstrb,
  input                         lsu_wlast,

  output reg                    lsu_bvalid,
  input                         lsu_bready,
  output  reg [1:0]             lsu_bresp,
  output  reg [3:0]             lsu_bid,

  input	                        io_master_awready,
  output reg 	                  io_master_awvalid,
  output reg [31:0]	            io_master_awaddr,
  output reg [ 3:0]	            io_master_awid,
  output reg [ 7:0]	            io_master_awlen,
  output reg [ 2:0]	            io_master_awsize,
  output reg [ 1:0]	            io_master_awburst,
  input	                        io_master_wready,
  output reg 	                  io_master_wvalid,
  output reg [31:0]	            io_master_wdata,
  output reg [ 3:0]	            io_master_wstrb,
  output reg 	                  io_master_wlast,
  output reg 	                  io_master_bready,
  input	                        io_master_bvalid,
  input	     [ 1:0]	            io_master_bresp,
  input	     [ 3:0]	            io_master_bid,
  input	                        io_master_arready,
  output reg 	                  io_master_arvalid,
  output reg [31:0]	            io_master_araddr,
  output reg [ 3:0]	            io_master_arid,
  output reg [ 7:0]	            io_master_arlen,
  output reg [ 2:0]	            io_master_arsize,
  output reg [ 1:0]	            io_master_arburst,
  output reg 	                  io_master_rready,
  input	                        io_master_rvalid,
  input	     [ 1:0]	            io_master_rresp,
  input	     [31:0]	            io_master_rdata,
  input	                        io_master_rlast,
  input	     [ 3:0]	            io_master_rid,

  input	                        clint_awready,
  output reg 	                  clint_awvalid,
  output reg [31:0]	            clint_awaddr,
  output reg [ 3:0]	            clint_awid,
  output reg [ 7:0]	            clint_awlen,
  output reg [ 2:0]	            clint_awsize,
  output reg [ 1:0]	            clint_awburst,
  input	                        clint_wready,
  output reg 	                  clint_wvalid,
  output reg [31:0]	            clint_wdata,
  output reg [ 3:0]	            clint_wstrb,
  output reg 	                  clint_wlast,
  output reg 	                  clint_bready,
  input	                        clint_bvalid,
  input	     [ 1:0]	            clint_bresp,
  input	     [ 3:0]	            clint_bid,
  input	                        clint_arready,
  output reg 	                  clint_arvalid,
  output reg [31:0]	            clint_araddr,
  output reg [ 3:0]	            clint_arid,
  output reg [ 7:0]	            clint_arlen,
  output reg [ 2:0]	            clint_arsize,
  output reg [ 1:0]	            clint_arburst,
  output reg 	                  clint_rready,
  input	                        clint_rvalid,
  input	     [ 1:0]	            clint_rresp,
  input	     [31:0]	            clint_rdata,
  input	                        clint_rlast,
  input	     [ 3:0]	            clint_rid
);

// 最简单的调度，缓存
localparam C0 = 2'd0; // idle
localparam C1 = 2'd1; // icache_master
localparam C2 = 2'd2; // lsu_master
reg [1:0] master_state;
wire icache_valid = icache_arvalid;
wire lsu_valid = lsu_arvalid | lsu_awvalid | lsu_wvalid;

reg [1:0] slave_state;
localparam s_io = 2'b00, s_clint = 2'b10;
always @(posedge clock) begin
  if(reset) begin
    master_state <= C1;
    slave_state <= s_io;
  end
  else if(master_state == C0 && lsu_valid) begin
    master_state <= C2;
    if(lsu_arvalid && lsu_araddr >= `CLINT_ADDR_START && lsu_araddr <= `CLINT_ADDR_END) slave_state <= s_clint;
    else slave_state <= s_io;
  end
  else if(master_state == C0 && icache_valid) begin
    slave_state <= s_io;
    master_state <= C1;
  end
end

always @(posedge clock) begin
  if(reset) begin
    master_state <= C0;
  end
  else begin
    case(master_state)
      C0: master_state <= lsu_valid ? C2 : icache_valid ? C1 : C0; // lsu > icache
      C1: master_state <= icache_rvalid && icache_rlast ? C0 : C1;
      C2: master_state <= ((lsu_rvalid && lsu_rlast)|| lsu_bvalid) ? C0 : C2;
      default: master_state <= C0;
    endcase
  end
end

reg                     awready;
reg 	                  awvalid;
reg [31:0]	            awaddr;
reg [ 3:0]	            awid;
reg [ 7:0]	            awlen;
reg [ 2:0]	            awsize;
reg [ 1:0]	            awburst;
reg                     wready;
reg 	                  wvalid;
reg [31:0]	            wdata;
reg [ 3:0]	            wstrb;
reg 	                  wlast;
reg 	                  bready;
reg                     bvalid;
reg [ 1:0]	            bresp;
reg [ 3:0]	            bid;
reg                     arready;
reg 	                  arvalid;
reg [31:0]	            araddr;
reg [ 3:0]	            arid;
reg [ 7:0]	            arlen;
reg [ 2:0]	            arsize;
reg [ 1:0]	            arburst;
reg 	                  rready;
reg                     rvalid;
reg [ 1:0]	            rresp;
reg [31:0]	            rdata;
reg                     rlast;
reg [ 3:0]	            rid;
always @(*) begin
  arvalid = 0;
  araddr = 0;
  arlen = 0;
  arsize = 0;
  arid = 0;
  arburst = 0;
  rready = 0;
  awvalid = 0;
  awaddr = 0;
  awlen = 0;
  awsize = 0;
  awid = 0;
  awburst = 0;
  wvalid = 0;
  wdata = 0;
  wstrb = 0;
  wlast = 0;
  bready = 0;

  icache_arready = 0;
  icache_rvalid = 0;
  icache_rdata = 0;
  icache_rresp = 0;
  icache_rlast = 0;
  icache_rid = 0;
  icache_awready = 0;
  icache_wready = 0;
  icache_bvalid = 0;
  icache_bresp = 0;
  icache_bid = 0;

  lsu_arready = 0;
  lsu_rvalid = 0;
  lsu_rdata = 0;
  lsu_rresp = 0;
  lsu_rlast = 0;
  lsu_rid = 0;
  lsu_awready = 0;
  lsu_wready = 0;
  lsu_bvalid = 0;
  lsu_bresp = 0;
  lsu_bid = 0;

  if(master_state == C1) begin
    arvalid = icache_arvalid;
    araddr = icache_araddr;
    arlen = icache_arlen;
    arsize = icache_arsize;
    arid = icache_arid;
    arburst = icache_arburst;
    icache_arready = arready;

    rready = icache_rready;
    icache_rvalid = rvalid;
    icache_rdata = rdata;
    icache_rresp = rresp;
    icache_rlast = rlast;
    icache_rid = rid;

    awvalid = icache_awvalid;
    awaddr = icache_awaddr;
    awlen = icache_awlen;
    awsize = icache_awsize;
    awid = icache_awid;
    awburst = icache_awburst;
    icache_awready = awready;

    wvalid = icache_wvalid;
    wdata = icache_wdata;
    wstrb = icache_wstrb;
    wlast = icache_wlast;
    icache_wready = wready;

    icache_bvalid = bvalid;
    icache_bresp = bresp;
    icache_bid = bid;
    bready = icache_bready;
  end
  else if(master_state == C2) begin
    arvalid = lsu_arvalid;
    araddr = lsu_araddr;
    arlen = lsu_arlen;
    arsize = lsu_arsize;
    arid = lsu_arid;
    arburst = lsu_arburst;
    lsu_arready = arready;

    rready = lsu_rready;
    lsu_rvalid = rvalid;
    lsu_rdata = rdata;
    lsu_rresp = rresp;
    lsu_rlast = rlast;
    lsu_rid = rid;

    awvalid = lsu_awvalid;
    awaddr = lsu_awaddr;
    awlen = lsu_awlen;
    awsize = lsu_awsize;
    awid = lsu_awid;
    awburst = lsu_awburst;
    lsu_awready = awready;

    wvalid = lsu_wvalid;
    wdata = lsu_wdata;
    wstrb = lsu_wstrb;
    wlast = lsu_wlast;
    lsu_wready = wready;

    lsu_bvalid = bvalid;
    lsu_bresp = bresp;
    lsu_bid = bid;
    bready = lsu_bready;
  end
end

always @(*) begin
  arready = 0;
  rvalid = 0;
  rdata = 0;
  rresp = 0;
  rlast = 0;
  rid = 0;
  awready = 0;
  wready = 0;
  bvalid = 0;
  bresp = 0;
  bid = 0;

  io_master_arvalid = 0;
  io_master_araddr = 0;
  io_master_arlen = 0;
  io_master_arsize = 0;
  io_master_arid = 0;
  io_master_arburst = 0;
  io_master_rready = 0;
  io_master_awvalid = 0;
  io_master_awaddr = 0;
  io_master_awlen = 0;
  io_master_awsize = 0;
  io_master_awid = 0;
  io_master_awburst = 0;
  io_master_wvalid = 0;
  io_master_wdata = 0;
  io_master_wstrb = 0;
  io_master_wlast = 0;
  io_master_bready = 0;

  clint_arvalid = 0;
  clint_araddr = 0;
  clint_arlen = 0;
  clint_arsize = 0;
  clint_arid = 0;
  clint_arburst = 0;
  clint_rready = 0;
  clint_awvalid = 0;
  clint_awaddr = 0;
  clint_awlen = 0;
  clint_awsize = 0;
  clint_awid = 0;
  clint_awburst = 0;
  clint_wvalid = 0;
  clint_wdata = 0;
  clint_wstrb = 0;
  clint_wlast = 0;
  clint_bready = 0;

  if(slave_state == s_io) begin
    io_master_arvalid = arvalid;
    io_master_araddr = araddr;
    io_master_arlen = arlen;
    io_master_arsize = arsize;
    io_master_arid = arid;
    io_master_arburst = arburst;
    arready = io_master_arready;

    io_master_rready = rready;
    rvalid = io_master_rvalid;
    rdata = io_master_rdata;
    rresp = io_master_rresp;
    rlast = io_master_rlast;
    rid = io_master_rid;

    io_master_awvalid = awvalid;
    io_master_awaddr = awaddr;
    io_master_awlen = awlen;
    io_master_awsize = awsize;
    io_master_awid = awid;
    io_master_awburst = awburst;
    awready = io_master_awready;

    io_master_wvalid = wvalid;
    io_master_wdata = wdata;
    io_master_wstrb = wstrb;
    io_master_wlast = wlast;
    wready = io_master_wready;

    bvalid = io_master_bvalid;
    bresp = io_master_bresp;
    bid = io_master_bid;
    io_master_bready = bready;
  end
  else if(slave_state == s_clint) begin
    clint_arvalid = arvalid;
    clint_araddr = araddr;
    clint_arlen = arlen;
    clint_arsize = arsize;
    clint_arid = arid;
    clint_arburst = arburst;
    arready = clint_arready;

    clint_rready = rready;
    rvalid = clint_rvalid;
    rdata = clint_rdata;
    rresp = clint_rresp;
    rlast = clint_rlast;
    rid = clint_rid;

    clint_awvalid = awvalid;
    clint_awaddr = awaddr;
    clint_awlen = awlen;
    clint_awsize = awsize;
    clint_awid = awid;
    clint_awburst = awburst;
    awready = clint_awready;

    clint_wvalid = wvalid;
    clint_wdata = wdata;
    clint_wstrb = wstrb;
    clint_wlast = wlast;
    wready = clint_wready;

    bvalid = clint_bvalid;
    bresp = clint_bresp;
    bid = clint_bid;
    clint_bready = bready;
  end
end
endmodule