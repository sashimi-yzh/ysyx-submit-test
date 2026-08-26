module WBU(
    input clk,
    input rst,
    input [31:0]LSU_data,
    input [31:0]EXU_data,
    input [31:0]snpc,
    input [4:0]address,
    input isLOAD,
    input isWRITE,
    input isJUMP,
    output gpr_WEN,
    output [31:0]gpr_data,
    output [4:0]gpr_address
);  
    assign gpr_data=isLOAD?LSU_data:(isJUMP?snpc:(isWRITE?EXU_data:32'hf0f0f0f0));
    assign gpr_address=address;
    assign gpr_WEN=(isLOAD|isWRITE)?1:0;
endmodule