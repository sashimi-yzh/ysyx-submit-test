`include "defines.v"
module RegisterFile (
  input clk,
  input rst_n,
  input [`REG_DATA_WIDTH-1:0] wdata,
  input [`REG_ADDR_WIDTH-1:0] waddr,
  input wen,
  input [`REG_ADDR_WIDTH-1:0] r1addr,
  output[`REG_DATA_WIDTH-1:0] r1data,
  input [`REG_ADDR_WIDTH-1:0] r2addr,
  output[`REG_DATA_WIDTH-1:0] r2data,
  output[`REG_DATA_WIDTH-1:0] a0
);
  reg [`REG_DATA_WIDTH-1:0] rf [2**`REG_ADDR_WIDTH-1:0];
  always @(posedge clk) begin
    if(~rst_n) begin
      rf[0]  <= `ZERO_WORD;
      rf[1]  <= `ZERO_WORD;
      rf[2]  <= `ZERO_WORD;
      rf[3]  <= `ZERO_WORD;
      rf[4]  <= `ZERO_WORD;
      rf[5]  <= `ZERO_WORD;
      rf[6]  <= `ZERO_WORD;
      rf[7]  <= `ZERO_WORD;
      rf[8]  <= `ZERO_WORD;
      rf[9]  <= `ZERO_WORD;
      rf[10] <= `ZERO_WORD;
      rf[11] <= `ZERO_WORD;
      rf[12] <= `ZERO_WORD;
      rf[13] <= `ZERO_WORD;
      rf[14] <= `ZERO_WORD;
      rf[15] <= `ZERO_WORD;
    end
    else if (wen && waddr != 0) rf[waddr] <= wdata;
  end
  assign r1data = rf[r1addr];
  assign r2data = rf[r2addr];
  assign a0 = rf[10];
endmodule