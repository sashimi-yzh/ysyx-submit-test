`include "ysyx_26010007_defines.v"
module ysyx_26010007_LSU (
  input clock,
  input reset,
  // 握手信号
  input                     lsu_valid_i,
  output                    lsu_ready_i,
  output                    lsu_valid_o,
  input                     lsu_ready_o,
  // 来自exu的信号
  input [`ysyx_26010007_WORD_WIDTH-1:0]   lsu_addr,
  input [4:0]               lsu_MemMask,
  input [`ysyx_26010007_WORD_WIDTH-1:0]   lsu_MemWdata,
  // 传输到wbu的信号
  output [`ysyx_26010007_WORD_WIDTH-1:0]  lsu_wd,
  // DRAM
  // IROM AXI BUS
  output                    lsu_arvalid,
  input                     lsu_arready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] lsu_araddr,
  output [7:0]              lsu_arlen,
  output [2:0]              lsu_arsize,
  output [3:0]              lsu_arid,
  output [1:0]              lsu_arburst,

  input                     lsu_rvalid,
  output                    lsu_rready,
  input  [`ysyx_26010007_WORD_WIDTH-1:0]  lsu_rdata,
  input  [1:0]              lsu_rresp,
  input                     lsu_rlast,
  input  [3:0]              lsu_rid,

  output                    lsu_awvalid,
  input                     lsu_awready,
  output [`ysyx_26010007_PADDR_WIDTH-1:0] lsu_awaddr,
  output [7:0]              lsu_awlen,
  output [2:0]              lsu_awsize,
  output [3:0]              lsu_awid,
  output [1:0]              lsu_awburst,

  output                    lsu_wvalid,
  input                     lsu_wready,
  output [`ysyx_26010007_WORD_WIDTH-1:0]  lsu_wdata,
  output [3:0]              lsu_wstrb,
  output                    lsu_wlast,

  input                     lsu_bvalid,
  output                    lsu_bready,
  input  [1:0]              lsu_bresp,
  input  [3:0]              lsu_bid
);

wire load_inst = lsu_MemMask[4] & lsu_valid_i;
wire store_inst = lsu_MemMask[3] & lsu_valid_i; 
localparam C0 = 3'b000, C1 = 3'b001, C2 = 3'b010, C3 = 3'b011, C4 = 3'b100;
reg [2:0] state;
reg [2:0] next_state;
always @(posedge clock) begin
  if(reset) begin
    state <= C0;
  end
  else begin
    state <= next_state;
  end
end

always @(*) begin
  next_state = state;
  case (state)
    C0 : begin
      if(lsu_arvalid && lsu_arready) next_state = C1;
      else if(lsu_awvalid && lsu_awready && lsu_wvalid && lsu_wready) next_state = C4;
      else if(lsu_awvalid && lsu_awready) next_state = C2;
      else if(lsu_wvalid && lsu_wready) next_state = C3;
      else next_state = C0;
    end 
    C1 : begin
      if(lsu_rready && lsu_rvalid && lsu_rlast && (lsu_rid == 4'b0000) && (lsu_rresp == 2'b00)) next_state = C0;
    end
    C2 : begin
      if(lsu_wvalid && lsu_wready) next_state = C4;
    end
    C3 : begin
      if(lsu_awvalid && lsu_awready) next_state = C4;
    end
    C4 : begin
      if(lsu_bready && lsu_bvalid && (lsu_bid == 4'b0000) && (lsu_bresp == 2'b00)) next_state = C0;
    end
    default: next_state = state;
  endcase
end

assign lsu_arvalid = (state == C0) && load_inst;
assign lsu_araddr = lsu_addr;
assign lsu_arlen = 8'd0;
assign lsu_arsize = {1'b0, lsu_MemMask[1:0]};
assign lsu_arid = 4'b0000;
assign lsu_arburst = 2'b00;

assign lsu_rready = (state == C1);

assign lsu_awvalid = ((state == C0) || (state == C3)) && store_inst;
assign lsu_awaddr = lsu_addr;
assign lsu_awlen = 8'd0;
assign lsu_awsize = {1'b0, lsu_MemMask[1:0]};
assign lsu_awid = 4'b0000;
assign lsu_awburst = 2'b00;

// 先发送写地址，然后再传输写数据
assign lsu_wvalid = ((state == C0) || (state == C2)) && store_inst;
assign lsu_wlast = 1'b1;

ysyx_26010007_MuxKeyWithDefault #(3, 2, `ysyx_26010007_WORD_WIDTH) i1 (lsu_wdata, lsu_MemMask[1:0], 0, {
    2'b00, {4{lsu_MemWdata[7:0]}},
    2'b01, {2{lsu_MemWdata[15:0]}},
    2'b10, lsu_MemWdata
  });

wire [1:0] offset = lsu_addr[1:0];
wire lsu_addr_00 = offset == 2'b00;
wire lsu_addr_01 = offset == 2'b01;
wire lsu_addr_10 = offset == 2'b10;
wire lsu_addr_11 = offset == 2'b11;

assign lsu_wstrb[3] = lsu_MemMask[1] | (lsu_MemMask[0] & lsu_addr_10) | (lsu_addr_11);
assign lsu_wstrb[2] = lsu_MemMask[1] | (lsu_addr_10);
assign lsu_wstrb[1] = lsu_MemMask[1] | (lsu_MemMask[0] & lsu_addr_00) | (lsu_addr_01);
assign lsu_wstrb[0] = lsu_MemMask[1] | (lsu_addr_00);

assign lsu_bready = (state == C4);
wire lh_00 = lsu_rdata[15] &~lsu_MemMask[2];
wire lh_10 = lsu_rdata[31] &~lsu_MemMask[2];
reg [`ysyx_26010007_WORD_WIDTH-1:0] lsu_MemRdata;
always @(*) begin
  lsu_MemRdata = 0;
  case (lsu_MemMask[1:0])
    2'b00: 
      case (offset)
        2'b00 : lsu_MemRdata = {{24{lsu_rdata[ 7] &~lsu_MemMask[2]}}, lsu_rdata[ 7: 0]}; 
        2'b01 : lsu_MemRdata = {{24{lh_00}}, lsu_rdata[15: 8]}; 
        2'b10 : lsu_MemRdata = {{24{lsu_rdata[23] &~lsu_MemMask[2]}}, lsu_rdata[23:16]}; 
        2'b11 : lsu_MemRdata = {{24{lh_10}}, lsu_rdata[31:24]}; 
      endcase
    2'b01:
      case (offset[1])
        1'b0: lsu_MemRdata = {{16{lh_00}}, lsu_rdata[15: 0]};
        1'b1: lsu_MemRdata = {{16{lh_10}}, lsu_rdata[31:16]};
      endcase
    2'b10: lsu_MemRdata = lsu_rdata;
    default: lsu_MemRdata = 0;
  endcase
end

wire valid = (state == C0 && !load_inst && !store_inst) | 
              (state == C1 && lsu_rvalid && lsu_rlast && (lsu_rid == 4'b0000) && (lsu_rresp == 2'b00)) | 
              (state == C4 && lsu_bvalid && (lsu_bid == 4'b0000) && (lsu_bresp == 2'b00));

assign lsu_wd = load_inst ? lsu_MemRdata : lsu_addr;

// 握手信号
assign lsu_valid_o = lsu_valid_i & valid;
assign lsu_ready_i = valid;

`ifdef ysyx_26010007_debug
  always @(posedge clock) begin
    if(load_inst & !lsu_rvalid) event_count(13);
    else if(store_inst & !lsu_bvalid) event_count(14);
  end

  wire uart_flag = lsu_araddr >= 32'h10000000 && lsu_araddr < 32'h10001000;
  wire clint_flag = lsu_araddr >= 32'h2000000 && lsu_araddr < 32'h2010000;
  wire vga_flag = lsu_araddr >= 32'h21000000 && lsu_araddr < 32'h21200000;
  wire ps2_flag = lsu_araddr >= 32'h10011000 && lsu_araddr < 32'h10011008;
  always @(posedge clock) begin
    if(state == C0 && ((load_inst && (uart_flag || clint_flag || vga_flag || ps2_flag)) || (store_inst && (uart_flag || clint_flag|| vga_flag || ps2_flag))))
      dpi_diff_skip();
  end
`endif
endmodule