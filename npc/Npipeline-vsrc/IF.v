`include "/home/furina/ysyx-workbench/npc/Npipeline-vsrc/defines/defines.v"
// 取指模块
module IF (
    input             clk,
    input             reset,
    // input      [31:0] inst,
    input             EX_flush,
    input      [31:0] EX_flush_pc,

    input             ID_ready,
    output reg        IF_valid,

    output reg [31:0] IF_ID_pc,
    output reg [31:0] IF_ID_inst
    // input             predict_taken,    // 分支预测输入
    // input      [31:0] predict_target   // 预测目标地址
);
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    
    reg check;

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            IF_ID_pc <= 32'h8000_0000;
            check <= 1'b1;
        end
        else if (check) begin
            IF_ID_pc <= IF_ID_pc;
            check <= 1'b0;
        end
        else if (EX_flush && !check) begin
            IF_ID_pc <= EX_flush_pc;
        end
        else if (IF_valid && ID_ready) begin
            IF_ID_pc <= IF_ID_pc + 4;
            // IF_ID_pc <= predict_taken ? predict_target : (IF_ID_pc + 4);
        end
    end

    always @(*) begin
        if (reset | check) begin
            IF_valid = 0;
            IF_ID_inst = 0;
        end
        else if(EX_flush) begin//数据冲刷，更新输出有效值
            IF_valid = ID_ready;
            IF_ID_inst = 32'h0;
        end
        else begin
            IF_valid = 1'b1;//默认有效，不停取指令
            IF_ID_inst = pmem_read(IF_ID_pc, 4);
        end
        // $display("IF: pc = %h, inst = %h", IF_ID_pc, IF_ID_inst);
    end
endmodule