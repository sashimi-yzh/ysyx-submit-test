`timescale 1ns/1ps

// 1. 被测试的硬件模块：一个简单的 4-bit 计数器
module simple_counter(
    input wire clk,
    input wire rst_n, // 低电平复位
    output reg [3:0] count
);
    always @(posedge clk) begin
        if (!rst_n)
            count <= 4'b0000;
        else
            count <= count + 1'b1;
    end
endmodule

// 2. 仿真顶层 (Testbench)
module tb_top;
    reg clk;
    reg rst_n;
    wire [3:0] count;

    // 实例化被测模块
    simple_counter u_counter(
        .clk(clk),
        .rst_n(rst_n),
        .count(count)
    );

    // 生成时钟：周期为 10ns
    initial clk = 0;
    always #5 clk = ~clk;

    // 激励信号与控制
    initial begin
        // 关键步骤：告诉 iverilog 生成用于波形查看的 vcd 文件
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_top);

        // 初始化：故意先不拉低复位，模拟刚上电时触发器未初始化的状态
        rst_n = 1; 
        #15;
        $display("Time %0t: 未复位时, count = %b (四值仿真中的 X 态)", $time, count);
        
        // 施加复位
        rst_n = 0;
        #10;
        rst_n = 1; // 释放复位
        #20;
        $display("Time %0t: 复位释放后, count = %b", $time, count);
        
        #50;
        $display("仿真结束！");
        $finish; // 结束仿真
    end
endmodule
