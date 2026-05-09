
module ysyx_25040102_RegisterFile #(ADDR_WIDTH = 4, DATA_WIDTH = 32) (
  input clk,
  input [DATA_WIDTH-1:0] busW, 
  // input bus_valid,/
  input [ADDR_WIDTH-1:0] Ra,
  input [ADDR_WIDTH-1:0] Rb,
  input [ADDR_WIDTH-1:0] Rw, // rd
  input Regwr,

  output [DATA_WIDTH-1:0] busA,
  output [DATA_WIDTH-1:0] busB

);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:1]; // 2^ADDR_WIDTH
  
  always @(posedge clk) begin
    if (Regwr && Rw != 0) rf[Rw]   <= busW; 
  end

  assign busA = (Ra == 0) ? 0 : rf[Ra];
  assign busB = (Rb == 0) ? 0 : rf[Rb];

  
endmodule
