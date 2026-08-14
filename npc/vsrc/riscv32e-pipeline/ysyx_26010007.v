`include "ysyx_26010007_defines.v"
`ifdef ysyx_26010007_debug
import "DPI-C" function void event_count(input int _type);
import "DPI-C" function void dpi_diff_skip();
`endif

module ysyx_26010007 (
  input clock,
  input reset,
  input io_interrupt,

  output                    io_master_arvalid,
  input                     io_master_arready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] io_master_araddr,
  output [7:0]              io_master_arlen,
  output [2:0]              io_master_arsize,
  output [3:0]              io_master_arid,
  output [1:0]              io_master_arburst,

  input                     io_master_rvalid,
  output                    io_master_rready,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   io_master_rdata,
  input [1:0]               io_master_rresp,
  input                     io_master_rlast,
  input [3:0]               io_master_rid,

  output                    io_master_awvalid,
  input                     io_master_awready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] io_master_awaddr,
  output [7:0]              io_master_awlen,
  output [2:0]              io_master_awsize,
  output [3:0]              io_master_awid,
  output [1:0]              io_master_awburst,

  output                    io_master_wvalid,
  input                     io_master_wready,
  output [`ysyx_26010007_WORD_WIDTH-1:0]  io_master_wdata,
  output [3:0]              io_master_wstrb,
  output                    io_master_wlast,

  input                     io_master_bvalid,
  output                    io_master_bready,
  input  [1:0]              io_master_bresp,
  input  [3:0]              io_master_bid,

  input                     io_slave_arvalid,
  output                    io_slave_arready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]  io_slave_araddr,
  input [7:0]               io_slave_arlen,
  input [2:0]               io_slave_arsize,
  input [3:0]               io_slave_arid,
  input [1:0]               io_slave_arburst,

  output                    io_slave_rvalid,
  input                     io_slave_rready,
  output [`ysyx_26010007_WORD_WIDTH-1:0]  io_slave_rdata,
  output [1:0]              io_slave_rresp,
  output                    io_slave_rlast,
  output [3:0]              io_slave_rid,

  input                     io_slave_awvalid,
  output                    io_slave_awready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]  io_slave_awaddr,
  input [7:0]               io_slave_awlen,
  input [2:0]               io_slave_awsize,
  input [3:0]               io_slave_awid,
  input [1:0]               io_slave_awburst,

  input                     io_slave_wvalid,
  output                    io_slave_wready,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   io_slave_wdata,
  input [3:0]               io_slave_wstrb,
  input                     io_slave_wlast,

  output                    io_slave_bvalid,
  input                     io_slave_bready,
  output  [1:0]             io_slave_bresp,
  output  [3:0]             io_slave_bid

);

  // io_slave 暂不使用
  assign io_slave_arready = 0;
  assign io_slave_rvalid = 0;
  assign io_slave_rdata = 0;
  assign io_slave_rresp = 0;
  assign io_slave_rlast = 0;
  assign io_slave_rid = 0;
  assign io_slave_awready = 0;
  assign io_slave_wready = 0;
  assign io_slave_bvalid = 0;
  assign io_slave_bresp = 0;
  assign io_slave_bid = 0;

  wire                    icache_arready;
  wire 	                  icache_arvalid;
  wire [31:0]	            icache_araddr;
  wire [ 3:0]	            icache_arid;
  wire [ 7:0]	            icache_arlen;
  wire [ 2:0]	            icache_arsize;
  wire [ 1:0]	            icache_arburst;
  wire 	                  icache_rready;
  wire                    icache_rvalid;
  wire [ 1:0]	            icache_rresp;
  wire [31:0]	            icache_rdata;
  wire                    icache_rlast;
  wire [ 3:0]	            icache_rid;

  wire                    lsu_awready;
  wire 	                  lsu_awvalid;
  wire [31:0]	            lsu_awaddr;
  wire [ 3:0]	            lsu_awid;
  wire [ 7:0]	            lsu_awlen;
  wire [ 2:0]	            lsu_awsize;
  wire [ 1:0]	            lsu_awburst;
  wire                    lsu_wready;
  wire 	                  lsu_wvalid;
  wire [31:0]	            lsu_wdata;
  wire [ 3:0]	            lsu_wstrb;
  wire 	                  lsu_wlast;
  wire 	                  lsu_bready;
  wire                    lsu_bvalid;
  wire [ 1:0]	            lsu_bresp;
  wire [ 3:0]	            lsu_bid;
  wire                    lsu_arready;
  wire 	                  lsu_arvalid;
  wire [31:0]	            lsu_araddr;
  wire [ 3:0]	            lsu_arid;
  wire [ 7:0]	            lsu_arlen;
  wire [ 2:0]	            lsu_arsize;
  wire [ 1:0]	            lsu_arburst;
  wire 	                  lsu_rready;
  wire                    lsu_rvalid;
  wire [ 1:0]	            lsu_rresp;
  wire [31:0]	            lsu_rdata;
  wire                    lsu_rlast;
  wire [ 3:0]	            lsu_rid;

  wire                    clint_arready;
  wire 	                  clint_arvalid;
  wire [31:0]	            clint_araddr;
  wire [ 3:0]	            clint_arid;
  wire [ 7:0]	            clint_arlen;
  wire [ 2:0]	            clint_arsize;
  wire [ 1:0]	            clint_arburst;
  wire 	                  clint_rready;
  wire                    clint_rvalid;
  wire [ 1:0]	            clint_rresp;
  wire [31:0]	            clint_rdata;
  wire                    clint_rlast;
  wire [ 3:0]	            clint_rid;

  ysyx_26010007_riscv32e cpu (
    .clock(clock),
    .reset(reset),
    
    .icache_arvalid(icache_arvalid),
    .icache_arready(icache_arready),
    .icache_araddr(icache_araddr),
    .icache_arlen(icache_arlen),
    .icache_arsize(icache_arsize),
    .icache_arid(icache_arid),
    .icache_arburst(icache_arburst),
    .icache_rvalid(icache_rvalid),
    .icache_rready(icache_rready),
    .icache_rdata(icache_rdata),
    .icache_rresp(icache_rresp),
    .icache_rlast(icache_rlast),
    .icache_rid(icache_rid),

    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arid(lsu_arid),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rready(lsu_rready),
    .lsu_rdata(lsu_rdata),
    .lsu_rresp(lsu_rresp),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awid(lsu_awid),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bready(lsu_bready),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid)
  );
  
  ysyx_26010007_ARBITER arbiter(
    .clock(clock),
    .reset(reset),
    .icache_arvalid(icache_arvalid),
    .icache_arready(icache_arready),
    .icache_araddr(icache_araddr),
    .icache_arlen(icache_arlen),
    .icache_arsize(icache_arsize),
    .icache_arid(icache_arid),
    .icache_arburst(icache_arburst),
    .icache_rvalid(icache_rvalid),
    .icache_rready(icache_rready),
    .icache_rdata(icache_rdata),
    .icache_rresp(icache_rresp),
    .icache_rlast(icache_rlast),
    .icache_rid(icache_rid),

    .lsu_arvalid(lsu_arvalid),
    .lsu_arready(lsu_arready),
    .lsu_araddr(lsu_araddr),
    .lsu_arlen(lsu_arlen),
    .lsu_arsize(lsu_arsize),
    .lsu_arid(lsu_arid),
    .lsu_arburst(lsu_arburst),
    .lsu_rvalid(lsu_rvalid),
    .lsu_rready(lsu_rready),
    .lsu_rdata(lsu_rdata),
    .lsu_rresp(lsu_rresp),
    .lsu_rlast(lsu_rlast),
    .lsu_rid(lsu_rid),
    .lsu_awvalid(lsu_awvalid),
    .lsu_awready(lsu_awready),
    .lsu_awaddr(lsu_awaddr),
    .lsu_awlen(lsu_awlen),
    .lsu_awsize(lsu_awsize),
    .lsu_awid(lsu_awid),
    .lsu_awburst(lsu_awburst),
    .lsu_wvalid(lsu_wvalid),
    .lsu_wready(lsu_wready),
    .lsu_wdata(lsu_wdata),
    .lsu_wstrb(lsu_wstrb),
    .lsu_wlast(lsu_wlast),
    .lsu_bvalid(lsu_bvalid),
    .lsu_bready(lsu_bready),
    .lsu_bresp(lsu_bresp),
    .lsu_bid(lsu_bid),

    .io_master_arvalid(io_master_arvalid),
    .io_master_arready(io_master_arready),
    .io_master_araddr(io_master_araddr),
    .io_master_arlen(io_master_arlen),
    .io_master_arsize(io_master_arsize),
    .io_master_arid(io_master_arid),
    .io_master_arburst(io_master_arburst),
    .io_master_rvalid(io_master_rvalid),
    .io_master_rready(io_master_rready),
    .io_master_rdata(io_master_rdata),
    .io_master_rresp(io_master_rresp),
    .io_master_rlast(io_master_rlast),
    .io_master_rid(io_master_rid),
    .io_master_awvalid(io_master_awvalid),
    .io_master_awready(io_master_awready),
    .io_master_awaddr(io_master_awaddr),
    .io_master_awlen(io_master_awlen),
    .io_master_awsize(io_master_awsize),
    .io_master_awid(io_master_awid),
    .io_master_awburst(io_master_awburst),
    .io_master_wvalid(io_master_wvalid),
    .io_master_wready(io_master_wready),
    .io_master_wdata(io_master_wdata),
    .io_master_wstrb(io_master_wstrb),
    .io_master_wlast(io_master_wlast),
    .io_master_bvalid(io_master_bvalid),
    .io_master_bready(io_master_bready),
    .io_master_bresp(io_master_bresp),
    .io_master_bid(io_master_bid),

    .clint_arvalid(clint_arvalid),
    .clint_arready(clint_arready),
    .clint_araddr(clint_araddr),
    .clint_arlen(clint_arlen),
    .clint_arsize(clint_arsize),
    .clint_arid(clint_arid),
    .clint_arburst(clint_arburst),
    .clint_rvalid(clint_rvalid),
    .clint_rready(clint_rready),
    .clint_rdata(clint_rdata),
    .clint_rresp(clint_rresp),
    .clint_rlast(clint_rlast),
    .clint_rid(clint_rid)
  );
  // AXI Bus

  ysyx_26010007_CLINT clint(
    .clock(clock),
    .reset(reset),

    .arvalid(clint_arvalid),
    .arready(clint_arready),
    .araddr(clint_araddr),
    .arlen(clint_arlen),
    .arsize(clint_arsize),
    .arid(clint_arid),
    .arburst(clint_arburst),
    .rvalid(clint_rvalid),
    .rready(clint_rready),
    .rdata(clint_rdata),
    .rresp(clint_rresp),
    .rlast(clint_rlast),
    .rid(clint_rid)
  );
endmodule