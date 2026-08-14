`include "ysyx_26010007_defines.v"
module ysyx_26010007_ARBITER(
  input     clock,
  input     reset,

  input                         icache_arvalid,
  output                        icache_arready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]      icache_araddr,
  input [7:0]                   icache_arlen,
  input [2:0]                   icache_arsize,
  input [3:0]                   icache_arid,
  input [1:0]                   icache_arburst,

  output                        icache_rvalid,
  input                         icache_rready,
  output     [`ysyx_26010007_WORD_WIDTH-1:0]  icache_rdata,
  output     [1:0]              icache_rresp,
  output                        icache_rlast,
  output     [3:0]              icache_rid,

  input                         lsu_arvalid,
  output                        lsu_arready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]      lsu_araddr,
  input [7:0]                   lsu_arlen,
  input [2:0]                   lsu_arsize,
  input [3:0]                   lsu_arid,
  input [1:0]                   lsu_arburst,

  output                        lsu_rvalid,
  input                         lsu_rready,
  output     [`ysyx_26010007_WORD_WIDTH-1:0]  lsu_rdata,
  output     [1:0]              lsu_rresp,
  output                        lsu_rlast,
  output     [3:0]              lsu_rid,

  input                         lsu_awvalid,
  output                        lsu_awready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]      lsu_awaddr,
  input [7:0]                   lsu_awlen,
  input [2:0]                   lsu_awsize,
  input [3:0]                   lsu_awid,
  input [1:0]                   lsu_awburst,

  input                         lsu_wvalid,
  output                        lsu_wready,
  input [`ysyx_26010007_WORD_WIDTH-1:0]       lsu_wdata,
  input [3:0]                   lsu_wstrb,
  input                         lsu_wlast,

  output                        lsu_bvalid,
  input                         lsu_bready,
  output      [1:0]             lsu_bresp,
  output      [3:0]             lsu_bid,

  input	                        io_master_awready,
  output     	                  io_master_awvalid,
  output     [31:0]	            io_master_awaddr,
  output     [ 3:0]	            io_master_awid,
  output     [ 7:0]	            io_master_awlen,
  output     [ 2:0]	            io_master_awsize,
  output     [ 1:0]	            io_master_awburst,
  input	                        io_master_wready,
  output     	                  io_master_wvalid,
  output     [31:0]	            io_master_wdata,
  output     [ 3:0]	            io_master_wstrb,
  output     	                  io_master_wlast,
  output     	                  io_master_bready,
  input	                        io_master_bvalid,
  input	     [ 1:0]	            io_master_bresp,
  input	     [ 3:0]	            io_master_bid,
  input	                        io_master_arready,
  output     	                  io_master_arvalid,
  output     [31:0]	            io_master_araddr,
  output     [ 3:0]	            io_master_arid,
  output     [ 7:0]	            io_master_arlen,
  output     [ 2:0]	            io_master_arsize,
  output     [ 1:0]	            io_master_arburst,
  output     	                  io_master_rready,
  input	                        io_master_rvalid,
  input	     [ 1:0]	            io_master_rresp,
  input	     [31:0]	            io_master_rdata,
  input	                        io_master_rlast,
  input	     [ 3:0]	            io_master_rid,

  input	                        clint_arready,
  output     	                  clint_arvalid,
  output     [31:0]	            clint_araddr,
  output     [ 3:0]	            clint_arid,
  output     [ 7:0]	            clint_arlen,
  output     [ 2:0]	            clint_arsize,
  output     [ 1:0]	            clint_arburst,
  output     	                  clint_rready,
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
localparam s_io = 1'b0;
localparam s_clint = 1'b1;
reg [1:0] master_state;
reg slave_state;
wire icache_valid = icache_arvalid;
wire lsu_valid = lsu_arvalid | lsu_awvalid | lsu_wvalid;

always @(*) begin
  if(master_state == C2 && lsu_araddr >= `ysyx_26010007_CLINT_ADDR_START && lsu_araddr <= `ysyx_26010007_CLINT_ADDR_END) begin
    slave_state = s_clint;
  end
  else begin
    slave_state = s_io;
  end
end

always @(posedge clock) begin
  if(reset) begin
    master_state <= C0;
  end
  else begin
    case(master_state)
      C0: master_state <= lsu_valid ? C2 : icache_valid ? C1 : C0; // lsu > icache
      C1: master_state <= icache_rvalid & icache_rready & icache_rlast ? C0 : C1;
      C2: master_state <= ((lsu_rvalid & lsu_rready & lsu_rlast) | (lsu_bvalid & lsu_bready)) ? C0 : C2;
      default: master_state <= C0;
    endcase
  end
end
`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(master_state == C1 && lsu_arvalid) event_count(23);
    else if(master_state == C1 && lsu_awvalid) event_count(24);
    else if(master_state == C2 && icache_arvalid) event_count(25);
  end
`endif

// 写地址
// io_master
assign io_master_awvalid = lsu_awvalid & master_state[1];
assign io_master_awaddr = lsu_awaddr & {32{master_state[1]}};
assign io_master_awid = lsu_awid & {4{master_state[1]}};
assign io_master_awlen = lsu_awlen & {8{master_state[1]}};
assign io_master_awsize = lsu_awsize & {3{master_state[1]}};
assign io_master_awburst = lsu_awburst & {2{master_state[1]}};
assign lsu_awready = io_master_awready & master_state[1];
// 写数据
assign io_master_wvalid = lsu_wvalid & master_state[1];
assign io_master_wdata = lsu_wdata & {32{master_state[1]}};
assign io_master_wstrb = lsu_wstrb & {4{master_state[1]}};
assign io_master_wlast = lsu_wlast & master_state[1];
assign lsu_wready = io_master_wready & master_state[1];
// 写返回
assign io_master_bready = lsu_bready & master_state[1];
assign lsu_bvalid = io_master_bvalid & master_state[1];
assign lsu_bresp = io_master_bresp & {2{master_state[1]}};
assign lsu_bid = io_master_bid & {4{master_state[1]}};
// 读地址
assign io_master_arvalid = master_state[0] & icache_arvalid | master_state[1] & lsu_arvalid & ~slave_state;
assign io_master_araddr = {32{master_state[0]}} & icache_araddr | {32{master_state[1]}} & lsu_araddr & {32{~slave_state}};
assign io_master_arid = {4{master_state[0]}} & icache_arid | {4{master_state[1]}} & lsu_arid & {4{~slave_state}};
assign io_master_arlen = {8{master_state[0]}} & icache_arlen | {8{master_state[1]}} & lsu_arlen & {8{~slave_state}};
assign io_master_arsize = {3{master_state[0]}} & icache_arsize | {3{master_state[1]}} & lsu_arsize & {3{~slave_state}};
assign io_master_arburst = {2{master_state[0]}} & icache_arburst | {2{master_state[1]}} & lsu_arburst & {2{~slave_state}};

assign clint_arvalid = master_state[1] & lsu_arvalid & slave_state;
assign clint_araddr = {32{master_state[1]}} & lsu_araddr & {32{slave_state}};
assign clint_arid = {4{master_state[1]}} & lsu_arid & {4{slave_state}};
assign clint_arlen = {8{master_state[1]}} & lsu_arlen & {8{slave_state}};
assign clint_arsize = {3{master_state[1]}} & lsu_arsize & {3{slave_state}};
assign clint_arburst = {2{master_state[1]}} & lsu_arburst & {2{slave_state}};

assign icache_arready = master_state[0] & io_master_arready;
assign lsu_arready = master_state[1] & (io_master_arready & ~slave_state | clint_arready & slave_state);
// 读数据
assign io_master_rready = master_state[0] & icache_rready | master_state[1] & lsu_rready & ~slave_state;
assign clint_rready = master_state[1] & lsu_rready & slave_state;

assign icache_rvalid = master_state[0] & io_master_rvalid;
assign icache_rresp = {2{master_state[0]}} & io_master_rresp;
assign icache_rdata = {32{master_state[0]}} & io_master_rdata;
assign icache_rlast = master_state[0] & io_master_rlast;
assign icache_rid = {4{master_state[0]}} & io_master_rid;

assign lsu_rvalid = master_state[1] & (io_master_rvalid & ~slave_state | clint_rvalid & slave_state);
assign lsu_rresp = {2{master_state[1]}} & (io_master_rresp & {2{~slave_state}} | clint_rresp & {2{slave_state}});
assign lsu_rdata = {32{master_state[1]}} & (io_master_rdata & {32{~slave_state}} | clint_rdata & {32{slave_state}});
assign lsu_rlast = master_state[1] & (io_master_rlast & ~slave_state | clint_rlast & slave_state);
assign lsu_rid = {4{master_state[1]}} & (io_master_rid & {4{~slave_state}} | clint_rid & {4{slave_state}});

endmodule