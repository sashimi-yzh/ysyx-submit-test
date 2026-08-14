`include "ysyx_26010007_defines.v"
module ysyx_26010007_CLINT(
  input                         clock,
  input                         reset,

  input                         arvalid,
  output                        arready,
  input [`PADDR_WIDTH-1:0]      araddr,
  input [7:0]                   arlen,
  input [2:0]                   arsize,
  input [3:0]                   arid,
  input [1:0]                   arburst,
  output                        rvalid,
  input                         rready,
  output reg [`WORD_WIDTH-1:0]  rdata,
  output     [1:0]              rresp,
  output                        rlast,
  output     [3:0]              rid,
  input                         awvalid,
  output                        awready,
  input [`PADDR_WIDTH-1:0]      awaddr,
  input [7:0]                   awlen,
  input [2:0]                   awsize,
  input [3:0]                   awid,
  input [1:0]                   awburst,
  input                         wvalid,
  output                        wready,
  input [`WORD_WIDTH-1:0]       wdata,
  input [3:0]                   wstrb,
  input                         wlast,
  output                        bvalid,
  input                         bready,
  output     [1:0]              bresp,
  output     [3:0]              bid
);
  reg state;
  localparam S0 = 1'd0, S1 = 1'd1;
  always @(posedge clock) begin
    if(reset) state <= S0;
    else begin
      case (state)
        S0: state <= arvalid ? S1 : S0;
        S1: state <= rready ? S0 : S1;
        default: state <= S0;
      endcase
    end
  end

  reg [63:0] mtime;
  always @(posedge clock) begin
    if(reset) mtime <= 64'd0;
    else mtime <= mtime + 64'd2;
  end

  always @(posedge clock) begin
    if(state == S0 && arvalid) begin
      if(araddr == `CLINT_ADDR_START) rdata <= mtime[31:0];
      if(araddr == `CLINT_ADDR_START + 32'd4) rdata <= mtime[63:32];
    end
  end

  assign arready = (state == S0);
  assign rvalid = (state == S1);
  assign rresp = 2'b00;
  assign rid = 4'b0000;
  assign rlast = 1'b1;

  assign awready = 0;
  assign wready = 0;
  assign bvalid = 0;
  assign bresp = 0;
  assign bid = 0;
`ifdef debug
  export "DPI-C" function npc_clint;
  function longint npc_clint();
    npc_clint = mtime;
  endfunction
`endif
endmodule