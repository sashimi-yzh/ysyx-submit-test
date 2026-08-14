`include "ysyx_26010007_defines.v"
module ysyx_26010007_LSU (
  input clock,
  input reset,
  // 握手信号
  input exu_valid,
  output lsu_ready,
  output lsu_valid,
  input wbu_ready,
  // 来自exu的信号
  input [`WORD_WIDTH-1:0]      exu_alu_res,
  input                        exu_wreg,
  input [`REG_ADDR_WIDTH-1:0]  exu_wa,
  input [7:0]                  exu_ls_inst,
  input [`WORD_WIDTH-1:0]      exu_store_data,
  // 传输到wbu的信号
  output [`WORD_WIDTH-1:0]      lsu_mwd,
  output                        lsu_mwreg,
  output [`WORD_WIDTH-1:0]      lsu_alu_res,
  output                        lsu_wreg,
  output [`REG_ADDR_WIDTH-1:0]  lsu_wa,
  // DRAM
  // IROM AXI BUS
  output                    lsu_arvalid,
  input                     lsu_arready,
  output [`PADDR_WIDTH-1:0] lsu_araddr,
  output [7:0]              lsu_arlen,
  output [2:0]              lsu_arsize,
  output [3:0]              lsu_arid,
  output [1:0]              lsu_arburst,

  input                     lsu_rvalid,
  output                    lsu_rready,
  input  [`WORD_WIDTH-1:0]  lsu_rdata,
  input  [1:0]              lsu_rresp,
  input                     lsu_rlast,
  input  [3:0]              lsu_rid,

  output                    lsu_awvalid,
  input                     lsu_awready,
  output [`PADDR_WIDTH-1:0] lsu_awaddr,
  output [7:0]              lsu_awlen,
  output [2:0]              lsu_awsize,
  output [3:0]              lsu_awid,
  output [1:0]              lsu_awburst,

  output                    lsu_wvalid,
  input                     lsu_wready,
  output [`WORD_WIDTH-1:0]  lsu_wdata,
  output [3:0]              lsu_wstrb,
  output                    lsu_wlast,

  input                     lsu_bvalid,
  output                    lsu_bready,
  input  [1:0]              lsu_bresp,
  input  [3:0]              lsu_bid
);
wire lw_inst  = exu_ls_inst[7];
wire lbu_inst = exu_ls_inst[6];
wire lb_inst  = exu_ls_inst[5];
wire lhu_inst = exu_ls_inst[4];
wire lh_inst  = exu_ls_inst[3];
wire sw_inst  = exu_ls_inst[2];
wire sb_inst  = exu_ls_inst[1];
wire sh_inst  = exu_ls_inst[0];

wire load_inst = |exu_ls_inst[7:3];
wire store_inst = |exu_ls_inst[2:0]; 
localparam C0 = 2'b00, C1 = 2'b01, C2 = 2'b10, C3 = 2'b11;
reg [1:0] state;
always @(posedge clock) begin
  if(reset) begin
    state <= C0;
  end
  case (state)
    C0: state <= (load_inst && lsu_arready) ? C1 : (store_inst && lsu_awready && lsu_wready) ? C2 : C0;
    C1: state <= lsu_rvalid && lsu_rlast && (lsu_rid == 4'b0000) && (lsu_rresp == 2'b00) ? C0 : C1;

    C2: state <= lsu_bvalid && (lsu_bid == 4'b0000) && (lsu_bresp == 2'b00) ? C0 : C2;
    default: state <= C0;
  endcase
end
assign lsu_arvalid = (state == C0) && load_inst;
assign lsu_araddr = exu_alu_res;
assign lsu_arlen = 8'd0;
assign lsu_arsize[0] = lh_inst | lhu_inst;
assign lsu_arsize[1] = lw_inst | lw_inst; 
assign lsu_arid = 4'b0000;
assign lsu_arburst = 2'b01;

assign lsu_rready = (state == C1);

assign lsu_awvalid = (state == C0) && store_inst;
assign lsu_awaddr = exu_alu_res;
assign lsu_awlen = 8'd0;
assign lsu_awsize[0] = sh_inst;
assign lsu_awsize[1] = sw_inst;
assign lsu_awid = 4'b0000;
assign lsu_awburst = 2'b01;

// 先发送写地址，然后再传输写数据
assign lsu_wvalid = (state == C0 && store_inst);
assign lsu_wlast = (state == C0 && store_inst);
assign lsu_wdata = sw_inst ? exu_store_data : sb_inst ? {4{exu_store_data[7:0]}} : sh_inst ? {2{exu_store_data[15:0]}} : 0;
assign lsu_wstrb[3] = sw_inst | (sb_inst && exu_alu_res[1:0] == 2'b11) | (sh_inst && exu_alu_res[1:0] == 2'b10);
assign lsu_wstrb[2] = sw_inst | (sb_inst && exu_alu_res[1:0] == 2'b10) | (sh_inst && exu_alu_res[1:0] == 2'b10);
assign lsu_wstrb[1] = sw_inst | (sb_inst && exu_alu_res[1:0] == 2'b01) | (sh_inst && exu_alu_res[1:0] == 2'b00);
assign lsu_wstrb[0] = sw_inst | (sb_inst && exu_alu_res[1:0] == 2'b00) | (sh_inst && exu_alu_res[1:0] == 2'b00);

assign lsu_bready = (state == C2);

assign lsu_mwd =  lw_inst ? lsu_rdata :
              (lbu_inst && exu_alu_res[1:0] == 2'b11) ? {24'd0, lsu_rdata[31:24]} :
              (lbu_inst && exu_alu_res[1:0] == 2'b10) ? {24'd0, lsu_rdata[23:16]} :
              (lbu_inst && exu_alu_res[1:0] == 2'b01) ? {24'd0, lsu_rdata[15: 8]} :
              (lbu_inst && exu_alu_res[1:0] == 2'b00) ? {24'd0, lsu_rdata[ 7: 0]} :
              (lb_inst  && exu_alu_res[1:0] == 2'b11) ? {{24{lsu_rdata[31]}}, lsu_rdata[31:24]} :
              (lb_inst  && exu_alu_res[1:0] == 2'b10) ? {{24{lsu_rdata[23]}}, lsu_rdata[23:16]} :
              (lb_inst  && exu_alu_res[1:0] == 2'b01) ? {{24{lsu_rdata[15]}}, lsu_rdata[15: 8]} :
              (lb_inst  && exu_alu_res[1:0] == 2'b00) ? {{24{lsu_rdata[ 7]}}, lsu_rdata[ 7: 0]} :
              (lhu_inst && exu_alu_res[1:0] == 2'b10) ? {16'd0, lsu_rdata[31:16]} :
              (lhu_inst && exu_alu_res[1:0] == 2'b00) ? {16'd0, lsu_rdata[15: 0]} :
              (lh_inst  && exu_alu_res[1:0] == 2'b10) ? {{16{lsu_rdata[31]}}, lsu_rdata[31:16]} :
              (lh_inst  && exu_alu_res[1:0] == 2'b00) ? {{16{lsu_rdata[15]}}, lsu_rdata[15: 0]} : 0;

wire valid = (state == C0 && ~|exu_ls_inst) | (state == C1 && lsu_rvalid && lsu_rlast && (lsu_rid == 4'b0000) && (lsu_rresp == 2'b00)) | (state == C2 & lsu_bvalid && (lsu_bid == 4'b0000) && (lsu_bresp == 2'b00));

assign lsu_alu_res = exu_alu_res;
assign lsu_wa = exu_wa;
assign lsu_wreg = exu_wreg;
assign lsu_mwreg = state == C1 && lsu_rvalid && lsu_rlast && (lsu_rid == 4'b0000) && (lsu_rresp == 2'b00);

// 握手信号
assign lsu_valid = exu_valid & valid;
assign lsu_ready = wbu_ready & valid;

`ifdef debug
  always @(posedge clock) begin
    if(load_inst) event_count(13);
    else if(store_inst) event_count(14);
  end

  always @(posedge clock) begin
    // 0x1000_0000~0x1000_0fff UART
    if(state == C0 && ((load_inst && (lsu_araddr >= 32'h10000000 && lsu_araddr < 32'h10001000)) || (store_inst && (lsu_awaddr >= 32'h10000000 && lsu_awaddr < 32'h10001000))))
      dpi_diff_skip();
  end
`endif
endmodule