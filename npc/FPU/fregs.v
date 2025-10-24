`timescale 1ns/1ps

module fregs (
    input clk,
    input reset,
    input [4:0] rs1, // 第一个读寄存器地址 (frs1)
    input [4:0] rs2, // 第二个读寄存器地址 (frs2)
    input [4:0] rd,  // 写寄存器地址 (frd)
    input [31:0] write_data, // 写数据
    input write_en, // 写使能
    output reg [31:0] read_data1, // 第一个读数据 (frs1)
    output reg [31:0] read_data2  // 第二个读数据 (frs2)
);

    // 32 个 32 位浮点寄存器
    reg [31:0] fregs [0:31];

    // 初始化寄存器
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1) begin
            fregs[i] = 32'b0;
        end
    end

    // 写操作 (同步)
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            for (i = 0; i < 32; i = i + 1) begin
                fregs[i] <= 32'b0;
            end
        end else if (write_en && rd != 5'b00000) begin // f0 不可写
            fregs[rd] <= write_data;
        end
    end

    // 读操作 (组合逻辑)
    always @(*) begin
        read_data1 = fregs[rs1];
        read_data2 = fregs[rs2];
    end

endmodule