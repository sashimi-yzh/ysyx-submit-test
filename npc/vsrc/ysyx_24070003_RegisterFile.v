module ysyx_24070003_RegisterFile #(
    parameter ADDR_WIDTH = 4,  
    parameter DATA_WIDTH = 32
) (
    input clock,
    input reset,
    input [DATA_WIDTH-1:0] wdata,
    input [ADDR_WIDTH-1:0] waddr,
    input wen,
    
    output [DATA_WIDTH-1:0] rdata1,
    
    input [ADDR_WIDTH-1:0] raddr1,
    
    output [DATA_WIDTH-1:0] rdata2,
    
    input [ADDR_WIDTH-1:0] raddr2
);

    reg [DATA_WIDTH-1:0] rf[14:0];
    // import "DPI-C" function void set_gpr_ptr(input logic [31:0] a []);
    // initial set_gpr_ptr(rf); 

    
    always @(posedge clock) begin
        //if(reset) rf[0] <= 32'h0;
        if (wen & waddr != 0) rf[waddr - 1'b1] <= wdata; 
    end
    
    assign rdata1 = (raddr1 == 4'b0) ? 32'h0 : rf[raddr1 - 1'b1];
    assign rdata2 = (raddr2 == 4'b0) ? 32'h0 : rf[raddr2 - 1'b1];
   
endmodule
