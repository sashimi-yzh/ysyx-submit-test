import "DPI-C" function int mem_read(input int raddr);
import "DPI-C" function void mem_write(
  input int waddr,
  input int wmask,
  input int wdata
);

module Mem_operator (
    input clock,
    input reset,
    input [31:0] raddr,
    input [31:0] waddr,
    input [31:0] wdata,
    input [3:0] wmask,
    input valid,
    input wen,
    output reg [31:0] rdata
);
  always @(posedge clock) if (valid && !reset) rdata <= mem_read(raddr);

  always @(posedge clock) begin
    if (wen && !reset) mem_write(waddr, {28'h0, wmask}, wdata);
  end

endmodule
