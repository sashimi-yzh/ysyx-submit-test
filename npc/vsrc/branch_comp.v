module ysyx_24100012_branch_comp #(ADDR_WIDTH=32,DATA_WIDTH=32) (
    input clk,
    input [2:0] func3,
    input [1:0] PCType,
    input [DATA_WIDTH-1:0] rs1,
    input [DATA_WIDTH-1:0] rs2,    
    output [1:0] PCSel
);
    wire [DATA_WIDTH-1:0] signedRes, unSignRes;
    wire branchPCSel;
    assign unSignRes = rs1-rs2;
    ysyx_24100012_MuxKeyWithDefault #( 6,3 ) branch_comp (
        branchPCSel,
        func3,
        1'b0,{
        3'b000, unSignRes == 0,
        3'b001, unSignRes != 0,
        3'b100, $signed(rs1)<$signed(rs2),          // ??
        3'b101, $signed(rs1)>=$signed(rs2),
        3'b110, rs1<rs2,
        3'b111, rs1>=rs2
    });
    
    assign PCSel = {1'b0,branchPCSel};
endmodule