module ysyx_23060170_gpr #(
    parameter ADDR_WIDTH = 4,
    parameter DATA_WIDTH = 32
) (
    input                   clock ,
    input  [ADDR_WIDTH-1:0] raddr1 ,
    input  [ADDR_WIDTH-1:0] raddr2 ,
    input                   wen ,
    input  [ADDR_WIDTH-1:0] waddr ,
    input  [DATA_WIDTH-1:0] wdata ,
    output [DATA_WIDTH-1:0] rdata1 ,
    output [DATA_WIDTH-1:0] rdata2 
);

reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-2:0] /*verilator public*/;

always @(posedge clock) begin
  if (wen) begin
    rf[waddr-1] <= wdata;
  end
end

assign rdata1 = rf[raddr1-1];
assign rdata2 = rf[raddr2-1];

endmodule
