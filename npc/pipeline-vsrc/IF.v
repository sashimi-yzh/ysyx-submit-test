`include "/home/furina/ysyx-workbench/npc/pipeline-vsrc/defines/defines.v"
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
    output reg [31:0] IF_ID_pc2, // 用于分支预测
    output reg [31:0] IF_ID_inst,
    //分支预测器接口
    input             predict_taken,    // 分支预测输入
    input      [31:0] predict_target   // 预测目标地址
);
    import "DPI-C" function int unsigned pmem_read(input int unsigned raddr, input int len);
    import "DPI-C" function void counter(input int inst_type, input int ifu_inc, input int lsu_inc, input int exu_inc);

    reg check;
    wire is_branch = (IF_ID_inst[6:0] == 7'b1100011);
    wire is_jal    = (IF_ID_inst[6:0] == 7'b1101111);
    wire is_jalr   = (IF_ID_inst[6:0] == 7'b1100111) && (IF_ID_inst[14:12] == 3'b000);
    //快速解译jal跳转地址
    wire [31:0] immJ = {{12{IF_ID_inst[31]}}, IF_ID_inst[19:12], IF_ID_inst[20], IF_ID_inst[30:21], 1'b0};

    always @(posedge clk or posedge reset) begin
        if (reset) begin
            IF_ID_pc <= 32'h8000_0000;
            IF_ID_pc2 <= 32'h8000_0000;
            check <= 1'b1;
        end
        else if (check) begin
            IF_ID_pc <= IF_ID_pc;
            IF_ID_pc2 <= IF_ID_pc2;
            check <= 1'b0;
        end
        else if (EX_flush && !check) begin
            IF_ID_pc <= EX_flush_pc;
            IF_ID_pc2 <= EX_flush_pc;
        end
        else if (IF_valid && ID_ready) begin
            // IF_ID_pc <= IF_ID_pc + 4;
            IF_ID_pc <= is_jal ? IF_ID_pc + immJ : (predict_taken && (is_branch || is_jalr)) ? predict_target : (IF_ID_pc + 4);
            IF_ID_pc2 <= IF_ID_pc2 + 4; // 用于分支预测

            if(is_jal) counter(2, 0, 0, 0);
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
            // $display("[IF] 访问内存");
            IF_ID_inst = pmem_read(IF_ID_pc, 4);
            counter(7, 1, 0, 0);
        end
        // $display("IF: pc = %h, inst = %h", IF_ID_pc, IF_ID_inst);
    end
endmodule