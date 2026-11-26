`ifdef SOC_MODE
module ysyx_26020070(
  input         clock,
  input         reset,
  input         io_interrupt,

  output        io_master_awvalid,
  input         io_master_awready,
  output [31:0] io_master_awaddr,
  output [ 3:0] io_master_awid,
  output [ 7:0] io_master_awlen,
  output [ 2:0] io_master_awsize,
  output [ 1:0] io_master_awburst,
  output        io_master_wvalid,
  input         io_master_wready,
  output [31:0] io_master_wdata,
  output [ 3:0] io_master_wstrb,
  output        io_master_wlast,
  output        io_master_bready,
  input         io_master_bvalid,
  input  [ 1:0] io_master_bresp,
  input  [ 3:0] io_master_bid,
  output        io_master_arvalid,
  input         io_master_arready,
  output [31:0] io_master_araddr,
  output [ 3:0] io_master_arid,
  output [ 7:0] io_master_arlen,
  output [ 2:0] io_master_arsize,
  output [ 1:0] io_master_arburst,
  output        io_master_rready,
  input         io_master_rvalid,
  input  [ 1:0] io_master_rresp,
  input  [31:0] io_master_rdata,
  input         io_master_rlast,
  input  [ 3:0] io_master_rid,

  output        io_slave_awready,
  input         io_slave_awvalid,
  input  [31:0] io_slave_awaddr,
  input  [ 3:0] io_slave_awid,
  input  [ 7:0] io_slave_awlen,
  input  [ 2:0] io_slave_awsize,
  input  [ 1:0] io_slave_awburst,
  output        io_slave_wready,
  input         io_slave_wvalid,
  input  [31:0] io_slave_wdata,
  input  [ 3:0] io_slave_wstrb,
  input         io_slave_wlast,
  input         io_slave_bready,
  output        io_slave_bvalid,
  output [ 1:0] io_slave_bresp,
  output [ 3:0] io_slave_bid,
  output        io_slave_arready,
  input         io_slave_arvalid,
  input  [31:0] io_slave_araddr,
  input  [ 3:0] io_slave_arid,
  input  [ 7:0] io_slave_arlen,
  input  [ 2:0] io_slave_arsize,
  input  [ 1:0] io_slave_arburst,
  input         io_slave_rready,
  output        io_slave_rvalid,
  output [ 1:0] io_slave_rresp,
  output [31:0] io_slave_rdata,
  output        io_slave_rlast,
  output [ 3:0] io_slave_rid
);

  assign io_slave_awready = 1'b0;
  assign io_slave_wready  = 1'b0;
  assign io_slave_bvalid  = 1'b0;
  assign io_slave_bresp   = 2'b0;
  assign io_slave_bid     = 4'b0;
  assign io_slave_arready = 1'b0;
  assign io_slave_rvalid  = 1'b0;
  assign io_slave_rresp   = 2'b0;
  assign io_slave_rdata   = 32'b0;
  assign io_slave_rlast   = 1'b0;
  assign io_slave_rid     = 4'b0;

  wire [31:0] pc;
  wire [31:0] inst;
  wire [31:0] imem_addr;

  top u_top(
    .clk(clock),
    .rst(reset),
    .imem_rdata(32'b0),
    .pc(pc),
    .inst(inst),
    .imem_addr(imem_addr),

    .mem_awvalid(io_master_awvalid),
    .mem_awready(io_master_awready),
    .mem_awaddr(io_master_awaddr),
    .mem_awid(io_master_awid),
    .mem_awlen(io_master_awlen),
    .mem_awsize(io_master_awsize),
    .mem_awburst(io_master_awburst),
    .mem_wvalid(io_master_wvalid),
    .mem_wready(io_master_wready),
    .mem_wdata(io_master_wdata),
    .mem_wstrb(io_master_wstrb),
    .mem_wlast(io_master_wlast),
    .mem_bready(io_master_bready),
    .mem_bvalid(io_master_bvalid),
    .mem_bresp(io_master_bresp),
    .mem_bid(io_master_bid),
    .mem_arvalid(io_master_arvalid),
    .mem_arready(io_master_arready),
    .mem_araddr(io_master_araddr),
    .mem_arid(io_master_arid),
    .mem_arlen(io_master_arlen),
    .mem_arsize(io_master_arsize),
    .mem_arburst(io_master_arburst),
    .mem_rready(io_master_rready),
    .mem_rvalid(io_master_rvalid),
    .mem_rresp(io_master_rresp),
    .mem_rdata(io_master_rdata),
    .mem_rlast(io_master_rlast),
    .mem_rid(io_master_rid)
  );

endmodule
`endif
