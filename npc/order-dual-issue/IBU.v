/* ******************
    * IBU指令缓存模块
    * 替代IF, ID之间的流水线寄存器
****************** */

module IBU (
    input             clk,
    input             rst,
    input             is_full,
     
    input             is_flush,
    input      [31:0] pc_in1,
    input      [31:0] npc_in1,
    input      [63:0] inst_in1,
    input             receive_flag1,
     
    input      [31:0] pc_in2,
    input      [31:0] npc_in2,
    input      [63:0] inst_in2,
    input             receive_flag2,

    output reg [31:0] pc_out1,
    output reg [31:0] npc_out1,
    output reg [63:0] inst_out1,
    output reg        send_flag1,
    input             launch_flag1,

    output reg [31:0] pc_out2,
    output reg [31:0] npc_out2,
    output reg [63:0] inst_out2,
    output reg        send_flag2,
    input             launch_flag2,

    output reg        ibu_full
);
    wire valid1, valid2;
    reg [96:0] ib [0:3];
    reg [96:0] in_buf1 = receive_flag1 ? {pc_in1, npc_in1, inst_in1, valid1}; //pc(32) + npc(32) + inst(64) + valid(1)
    reg [96:0] in_buf2 = receive_flag2 ? {pc_in2, npc_in2, inst_in2, valid2};

    always @(posedge clk) begin
        if(rst | is_flush) begin
            ib[0] <= 97'h0;
            ib[1] <= 97'h0;
            ib[2] <= 97'h0;
            ib[3] <= 97'h0;
        end
        else begin
            case(ib[0][0], ib[1][0], ib[2][0], ib[3][0])//有效位
                4'b0000: begin
                end
            endcase
        end
    end
endmodule