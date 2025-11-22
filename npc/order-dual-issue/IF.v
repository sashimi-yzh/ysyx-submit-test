/* ****************************************
    *顺序双发射IF模块（草稿）

    * 该模块简单实现了双发射指令的取指功能，以及冲刷功能
    * 暂不支持DPI-C的内存访问接口
    
***************************************** */
module IF(
    input              clk,
    input              rst,

    input              stop,
    input       [63:0] inst_get,  //icahce取回的两条指令
    output wire [31:0] inst_addr, //icache请求的地址

    output wire [31:0] pc_out1,
    output wire [31:0] npc_out1,
    output wire [63:0] inst_out1,
    output reg         send_flag1,

    output wire [31:0] pc_out2,
    output wire [31:0] npc_out2,
    output wire [63:0] inst_out2,
    output reg         send_flag2,

    input              is_flush,
    input       [31:0] flush_pc
);
    reg [31:0] pc;//始终默认为双发两条指令中执行的第一条指令
    reg [31:0] npc;

    always @(posedge clk) begin
        if(rst) begin
            pc <= 32'h8000_0000;
        end
        else begin
            pc <= npc;
        end
    end

    always @(*) begin
        if(is_flush) begin
            npc <= flush_pc;
        end
        if(stop) begin
            npc <= pc;
        end
        else begin
            npc <= {pc[31:3] + 1, 3'b000};//取两条指令
            // npc <= pc + 8;
        end
    end

    always @(*) begin
        send_flag1 = ~pc[2];// pc[2]为0时，发送第一条指令
        send_flag2 = 1'b1;
    end

    assign inst_addr = pc;

    assign pc_out1   = {pc[31:3], 3'b000};
    assign npc_out1  = {pc[31:3], 3'b100};
    assign inst_out1 = inst_get[63:32];

    assign pc_out2   = {pc[31:3], 3'b100};
    assign npc_out2  = {pc[31:3] + 1, 3'b000};
    assign inst_out2 = inst_get[31:0];
    
endmodule
