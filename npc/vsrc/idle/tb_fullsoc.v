`timescale 1ns / 1ps

module tb_fullsoc;
    // 参数
    parameter CLK_PERIOD = 2; // (500MHz)
    parameter PROG_FILE = "defualt.hex"; // Default program file
    // DUT signals
    reg clk;
    reg reset;

    fullsoc #(
        .INIT_FILE(PROG_FILE)
    )
    u_dut (
        .clk    (clk  ),
        .reset  (reset)
    );

    // 始终
    initial begin
        clk = 0;
        forever #(CLK_PERIOD / 2) clk = ~clk;
    end

    // 初始化
    initial begin
        // VCD 波形文件
        // $dumpfile("build/log/waveform.vcd");
        // $dumpvars(0, tb_fullsoc);

        // 复位
        reset = 1'b1;
        repeat (10) @(posedge clk);
        reset = 1'b0;
        $display("复位结束，开始执行程序...");
    end

    reg [63:0] cnt;
    always @(posedge clk) begin
        if (reset) begin
            cnt <= 0;
        end else begin
            cnt <= cnt + 1;
            if(cnt > 5000000) begin
                $display("仿真了500万个时钟周期, 仿真结束");
                $finish;
            end            

        end
    end

    // wire [31:0] pc = u_dut.u_ysyx_25050136.u_ysyx_25050136_NPC.u_ysyx_25050136_NPCCORE.u_ysyx_25050136_IF.pc;
    // // 新增变量用于检测 PC 无变化
    // reg [31:0] pc_prev;
    // integer no_change_count;
    // localparam NO_CHANGE_THRESHOLD = 100; // 100 个时钟周期无变化则输出
    // // 主时序逻辑：检测 PC 无变化
    // always @(posedge clk) begin
    //     if (reset) begin
    //         pc_prev <= pc;
    //         no_change_count <= 0;
    //     end else begin
    //         if (pc != pc_prev) begin
    //             pc_prev <= pc;
    //             no_change_count <= 0;
    //         end else begin
    //             no_change_count <= no_change_count + 1;
    //             if (no_change_count == NO_CHANGE_THRESHOLD) begin
    //                 $display("你的PC已经好久没有变化了, 当前IF的PC: %08h, 当前时间: %dus", pc, $time/1000);
    //                 no_change_count <= 0; // 重置以避免重复输出
    //             end
    //         end
    //     end
    // end

    // // 寻找ebreak作为仿真结束标志
    // wire ebreak = u_dut.u_ysyx_25050136.u_ysyx_25050136_NPC.u_ysyx_25050136_NPCCORE.mem_wb_ebreak;
    // always @(posedge clk) begin
    //     if (reset) begin
    //         // 占位
    //     end else if (ebreak) begin
    //         $display("执行到了ebreak命令，仿真结束！");
    //         $display("实际执行时间: %t us", $time / 1000);
    //         $finish;
    //     end
    // end

endmodule