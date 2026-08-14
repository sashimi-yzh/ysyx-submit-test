`include "ysyx_26010007_defines.v"
module ysyx_26010007_CLINT(
  input                         clock,
  input                         reset,

  input                         arvalid,
  output                        arready,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]      araddr,
  input [7:0]                   arlen,
  input [2:0]                   arsize,
  input [3:0]                   arid,
  input [1:0]                   arburst,
  output                        rvalid,
  input                         rready,
  output     [`ysyx_26010007_WORD_WIDTH-1:0]  rdata,
  output     [1:0]              rresp,
  output                        rlast,
  output     [3:0]              rid
);
  reg state;
  localparam S0 = 1'd0, S1 = 1'd1;
  always @(posedge clock) begin
    if(reset) begin
      state <= S0;
    end
    else begin
      case (state)
        S0: state <= arvalid;
        S1: state <= ~rready;
        default: state <= S0;
      endcase
    end

  end

  reg [63:0] mtime;
  always @(posedge clock) begin
    if(reset) mtime <= 64'd0;
    else mtime <= mtime + 64'd2;
  end

  assign rdata = {32{araddr == `ysyx_26010007_CLINT_ADDR_START_LOW}} & mtime[31:0] | {32{araddr == `ysyx_26010007_CLINT_ADDR_START_HIGH}} & mtime[63:32];
  assign arready = ~state;
  assign rvalid = state;
  assign rresp = 2'b00;
  assign rid = 4'b0000;
  assign rlast = 1'b1;
endmodule