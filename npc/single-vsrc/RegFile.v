`include "/home/furina/ysyx-workbench/npc/vsrc/defines.v"
// 寄存器文件
module RegFile (
    input         clk,
    input  [4:0]  rs1,
    input  [4:0]  rs2,
    input  [4:0]  rd,
    input         we,
    input  [31:0] wd,
    output [31:0] rs1_val,
    output [31:0] rs2_val
);
    
    
    reg [31:0] regs [0:31]; // 32个寄存器

    assign rs1_val = (rs1 != 0) ? regs[rs1] : 0;
    assign rs2_val = (rs2 != 0) ? regs[rs2] : 0;

    always @(posedge clk) begin
        if (we && rd != 0) regs[rd] <= wd;
    end

endmodule