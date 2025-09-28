`timescale 1ps/1ps

module iverilog_tb;

// initial begin // 波形
//   $dumpfile("build/iverilog_wave.vcd");
//   $dumpvars(0, CPU);
//   $dumpvars(0, RAM);
// end

// 时钟信号
reg clock = 0;
always #10 clock = ~clock;

// 复位信号
reg reset = 1;
initial begin
  #200 reset = 0;
end

wire        io_master_awready;
wire        io_master_awvalid;
wire [31:0] io_master_awaddr;
wire [3:0]  io_master_awid;
wire [7:0]  io_master_awlen;
wire [2:0]  io_master_awsize;
wire [1:0]  io_master_awburst;
wire        io_master_wready;
wire        io_master_wvalid;
wire [31:0] io_master_wdata;
wire [3:0]  io_master_wstrb;
wire        io_master_wlast;
wire        io_master_bready;
wire        io_master_bvalid;
wire [1:0]  io_master_bresp;
wire [3:0]  io_master_bid;
wire        io_master_arready;
wire        io_master_arvalid;
wire [31:0] io_master_araddr;
wire [3:0]  io_master_arid;
wire [7:0]  io_master_arlen;
wire [2:0]  io_master_arsize;
wire [1:0]  io_master_arburst;
wire        io_master_rready;
wire        io_master_rvalid;
wire [1:0]  io_master_rresp;
wire [31:0] io_master_rdata;
wire        io_master_rlast;
wire [3:0]  io_master_rid;

ysyx_23060203 CPU (
  .reset(reset), .clock(clock),
  .io_interrupt(1'b0),
  .io_master_awready(io_master_awready),
  .io_master_awvalid(io_master_awvalid),
  .io_master_awaddr(io_master_awaddr),
  .io_master_awid(io_master_awid),
  .io_master_awlen(io_master_awlen),
  .io_master_awsize(io_master_awsize),
  .io_master_awburst(io_master_awburst),
  .io_master_wready(io_master_wready),
  .io_master_wvalid(io_master_wvalid),
  .io_master_wdata(io_master_wdata),
  .io_master_wstrb(io_master_wstrb),
  .io_master_wlast(io_master_wlast),
  .io_master_bready(io_master_bready),
  .io_master_bvalid(io_master_bvalid),
  .io_master_bresp(io_master_bresp),
  .io_master_bid(io_master_bid),
  .io_master_arready(io_master_arready),
  .io_master_arvalid(io_master_arvalid),
  .io_master_araddr(io_master_araddr),
  .io_master_arid(io_master_arid),
  .io_master_arlen(io_master_arlen),
  .io_master_arsize(io_master_arsize),
  .io_master_arburst(io_master_arburst),
  .io_master_rready(io_master_rready),
  .io_master_rvalid(io_master_rvalid),
  .io_master_rresp(io_master_rresp),
  .io_master_rdata(io_master_rdata),
  .io_master_rlast(io_master_rlast),
  .io_master_rid(io_master_rid)
);

sim_RAM RAM (
  .reset(reset), .clock(clock),
  
  .in_awready(io_master_awready),
  .in_awvalid(io_master_awvalid),
  .in_awaddr(io_master_awaddr),
  .in_awid(io_master_awid),
  .in_awlen(io_master_awlen),
  .in_awsize(io_master_awsize),
  .in_awburst(io_master_awburst),
  .in_wready(io_master_wready),
  .in_wvalid(io_master_wvalid),
  .in_wdata(io_master_wdata),
  .in_wstrb(io_master_wstrb),
  .in_wlast(io_master_wlast),
  .in_bready(io_master_bready),
  .in_bvalid(io_master_bvalid),
  .in_bresp(io_master_bresp),
  .in_bid(io_master_bid),
  .in_arready(io_master_arready),
  .in_arvalid(io_master_arvalid),
  .in_araddr(io_master_araddr),
  .in_arid(io_master_arid),
  .in_arlen(io_master_arlen),
  .in_arsize(io_master_arsize),
  .in_arburst(io_master_arburst),
  .in_rready(io_master_rready),
  .in_rvalid(io_master_rvalid),
  .in_rresp(io_master_rresp),
  .in_rdata(io_master_rdata),
  .in_rlast(io_master_rlast),
  .in_rid(io_master_rid)
);

endmodule

module sim_RAM (
  input clock, reset,

  output logic        in_arready,
  input  logic        in_arvalid,
  input  logic [31:0] in_araddr,
  input  logic [3:0]  in_arid,
  input  logic [7:0]  in_arlen,
  input  logic [2:0]  in_arsize,
  input  logic [1:0]  in_arburst,
  input  logic        in_rready,
  output logic        in_rvalid,
  output logic [1:0]  in_rresp,
  output logic [31:0] in_rdata,
  output logic        in_rlast,
  output logic [3:0]  in_rid,

  // write
  output logic        in_awready,
  input  logic        in_awvalid,
  input  logic [31:0] in_awaddr,
  input  logic [3:0]  in_awid,
  input  logic [7:0]  in_awlen,
  input  logic [2:0]  in_awsize,
  input  logic [1:0]  in_awburst,
  output logic        in_wready,
  input  logic        in_wvalid,
  input  logic [31:0] in_wdata,
  input  logic [3:0]  in_wstrb,
  input  logic        in_wlast,
  input  logic        in_bready,
  output logic        in_bvalid,
  output logic [1:0]  in_bresp,
  output logic [3:0]  in_bid
);

  reg [7:0] mem [32'h1000_0000];
  initial $readmemh("build/img.hex", mem);

  function automatic logic [31:0] pmem_read(input [31:0] addr);
    logic [31:0] r = {4'b0, addr[27:2], 2'b0};
    if (addr[31:4] == 28'ha000004) return 32'h0; // NPC CLINT
    return {mem[r + 32'h3], mem[r + 32'h2], mem[r + 32'h1], mem[r]};
  endfunction
  
  function automatic void pmem_write(input [31:0] addr, input [31:0] data, input [7:0] mask);
    logic [31:0] r = {4'b0, addr[27:2], 2'b0};
    if (addr == 32'ha00003f8) begin // NPC UART
      $write("%c", data[7:0]);
      return;
    end
    if (mask[0]) mem[r] = data[7:0];
    if (mask[1]) mem[r + 32'h1] = data[15:8];
    if (mask[2]) mem[r + 32'h2] = data[23:16];
    if (mask[3]) mem[r + 32'h3] = data[31:24];
  endfunction

  reg waddr_valid_reg;
  reg wdata_valid_reg;

  always @(posedge clock) if (reset) begin // 复位
    in_arready <= 1;
    in_rvalid <= 0;
    in_rlast <= 0;

    in_awready <= 1;
    in_wready <= 1;
    in_bvalid <= 0;

    waddr_valid_reg <= 0;
    wdata_valid_reg <= 0;
  end

  assign in_rresp = 2'b00;

  reg [31:0] araddr;
  reg [7:0] arlen;
  reg [2:0] arsize;
  reg [1:0] arburst;
  reg [7:0] burst_cnt;

  reg [2:0] len_w;
  always_comb begin
    case (arlen)
      8'h01: len_w = 3'h1;
      8'h03: len_w = 3'h2;
      8'h07: len_w = 3'h3;
      8'h0f: len_w = 3'h4;
      default: len_w = 3'h0;
    endcase
  end
  wire [31:0] wrap_mask = (32'h1 << (arsize + len_w)) - 32'h1;
  wire [31:0] araddr_incr_next = araddr + (32'h1 << arsize);
  reg [31:0] araddr_next;
  always_comb begin
    case (arburst)
      2'b01: araddr_next = araddr_incr_next; // incr
      2'b10: araddr_next = (araddr & ~wrap_mask) | (araddr_incr_next & wrap_mask);
      default: araddr_next = araddr; // fixed
    endcase
  end

  always @(posedge clock) if (~reset) begin
    if (in_arvalid & in_arready) begin
      in_arready <= 0; // idle -> access

      araddr <= in_araddr;
      arlen <= in_arlen;
      arsize <= in_arsize;
      arburst <= in_arburst;
      burst_cnt <= in_arlen;

      in_rvalid <= 1;
      in_rdata <= pmem_read(in_araddr);
      in_rlast <= (in_arlen == 8'b0);
    end

    if (~in_arready & in_rvalid & in_rready) begin
      if (in_rlast) begin // burst的最后一拍
        in_arready <= 1;
        in_rvalid <= 0;
        in_rlast <= 0;
      end else begin
        burst_cnt <= burst_cnt - 1;
        araddr <= araddr_next;
        in_rdata <= pmem_read(araddr_next);
        in_rlast <= (burst_cnt == 8'h1);
      end
    end
  end

  wire waddr_handshake = in_awready & in_awvalid;
  reg [31:0] waddr_reg;
  wire [31:0] waddr = waddr_handshake ? in_awaddr : waddr_reg;
  wire waddr_valid = waddr_handshake | waddr_valid_reg;

  wire wdata_handshake = in_wready & in_wvalid;
  reg [31:0] wdata_reg;
  reg [3:0] wmask_reg;
  wire [31:0] wdata = wdata_handshake ? in_wdata : wdata_reg;
  wire [3:0] wmask = wdata_handshake ? in_wstrb : wmask_reg;
  wire wdata_valid = wdata_handshake | wdata_valid_reg;

  wire write_en = waddr_valid & wdata_valid;

  always @(posedge clock) if (~reset) begin
    if (waddr_handshake) begin
      waddr_reg <= in_awaddr;
      if (~write_en) begin
        waddr_valid_reg <= 1;
        in_awready <= 0;
      end
    end
    if (wdata_handshake) begin
      wmask_reg <= in_wstrb;
      wdata_reg <= in_wdata;
      if (~write_en) begin
        wdata_valid_reg <= 1;
        in_wready <= 0;
      end
    end

    if (write_en) begin
      pmem_write({waddr[31:2], 2'b00}, wdata[31:0], {4'b0, wmask[3:0]});

      in_bresp <= 2'b00;
      in_bvalid <= 1;
      in_awready <= 1;
      in_wready <= 1;

      waddr_valid_reg <= 0;
      wdata_valid_reg <= 0;
    end

    if (in_bvalid & in_bready) in_bvalid <= 0;
  end
endmodule

