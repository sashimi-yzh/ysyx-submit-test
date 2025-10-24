`include "/home/furina/ysyx-workbench/npc/minirv-vsrc/defines.v"
// 取指模块
module IF (
    input             clk,
    input             reset,
    input      [31:0] branch_target,
    input             pc_src,
    output reg [31:0] pc,
    output reg [31:0] instr
);
    
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    
    reg check;

    always @(posedge clk or posedge reset) begin
        if(reset) begin
            pc <= 32'h8000_0000;
            check = 1'b1;
        end
        else if(!check) begin
            if(pc_src) pc <= branch_target;
            else       pc <= pc + 4;
        end
        else check = 1'b0;
    end

    always @(*) begin
        instr = pmem_read(pc,4); // 同步读取指令
    end

endmodule
