// // ============================================
// // 文件名: tb_npc_top.v
// // 仿真器: Icarus Verilog (iverilog)
// // 顶层模块: npc_top
// // 超时保护: 50ms 自动结束
// // ============================================

// `timescale 1ns / 1ps

// module tb_npc_top();

//     // 时钟和复位信号
//     reg clk;
//     reg reset;
    
//     // 时钟周期: 100MHz = 10ns
//     localparam CLK_PERIOD = 10;
    
//     // 复位持续时间: 10个时钟周期
//     localparam RESET_CYCLES = 10;
    
//     // 超时时间: 50ms = 50_000_000ns
//     localparam TIMEOUT_NS = 5_000_000;
    
//     // 超时标志
//     reg timeout_occurred;
    
//     // ============================================
//     // 实例化待测模块
//     // ============================================
//     npc_top u_npc_top (
//         .clk   (clk),
//         .reset (reset)
//     );
    
//     // ============================================
//     // 时钟生成 (100MHz)
//     // ============================================
//     initial begin
//         clk = 1'b0;
//         forever begin
//             #(CLK_PERIOD / 2) clk = ~clk;
//         end
//     end
    
//     // ============================================
//     // 复位信号生成
//     // ============================================
//     initial begin
//         // 初始复位有效
//         reset = 1'b1;
        
//         // 等待10个时钟周期的复位时间
//         repeat (RESET_CYCLES) begin
//             @(posedge clk);
//         end
        
//         // 释放复位，之后一直保持无效
//         reset = 1'b0;
        
//         $display("[%0t] INFO: Reset released, simulation running...", $time);
//     end
    
//     // ============================================
//     // 超时保护机制 (5ms)
//     // ============================================
//     initial begin
//         timeout_occurred = 1'b0;
        
//         // 等待超时时间
//         #TIMEOUT_NS;
        
//         // 检查仿真是否已经正常结束
//         timeout_occurred = 1'b1;
        
//         $display("==========================================");
//         $display("[%0t] ERROR: Simulation timeout!", $time);
//         $display("       Expected $finish within %0d ns", TIMEOUT_NS);
//         $display("       Possible causes:");
//         $display("       1. Design stuck in infinite loop");
//         $display("       2. Missing $finish in npc_top");
//         $display("       3. Clock/reset not connected properly");
//         $display("==========================================");
        
//         // 强制结束仿真
//         $finish(1);
//     end
    
//     // ============================================
//     // 正常仿真结束检测
//     // ============================================
//     `ifdef IVERILOG
//     // Iverilog 特定的 $finish 检测机制
//     always @(negedge timeout_occurred) begin
//         // 这个块不会被触发，仅作占位
//     end
//     `endif
    
//     // ============================================
//     // 可选: 仿真进度监控
//     // ============================================
//     initial begin
//         // 每 5ms 打印一次进度（仅当仿真持续较长时间时有用）
//         repeat (10) begin
//             #500_000;  // 5ms
//             if (!$time) begin
//                 // 仿真已结束
//                 $finish(1);
//             end
//             $display("[%0t] INFO: Simulation still running... (%0.1f ms elapsed)", 
//                      $time, $time / 1_000_000.0);
//         end
//     end
    
//     // ============================================
//     // 波形文件生成 (VCD格式)
//     // ============================================
//     initial begin
//         $dumpfile("tb_npc_top.vcd");
//         $dumpvars(0, tb_npc_top);
//         $display("[%0t] INFO: FST dump started: tb_npc_top.vcd", $time);
//     end
    

// endmodule

// ============================================
// 文件名: tb_npc_top.v
// 仿真器: Icarus Verilog (iverilog)
// 顶层模块: npc_top
// ============================================

`timescale 1ns / 1ps

module tb_npc_top();

    // 时钟和复位信号
    reg clk;
    reg reset;
    
    // 时钟周期: 100MHz = 10ns
    localparam CLK_PERIOD = 10;
    
    // 复位持续时间: 10个时钟周期
    localparam RESET_CYCLES = 10;
    
    // ============================================
    // 实例化待测模块
    // ============================================
    npc_top u_npc_top (
        .clk   (clk),
        .reset (reset)
    );
    
    // ============================================
    // 时钟生成 (100MHz)
    // ============================================
    initial begin
        clk = 1'b0;
        forever begin
            #(CLK_PERIOD / 2) clk = ~clk;
        end
    end
    
    // ============================================
    // 复位信号生成
    // ============================================
    initial begin
        // 初始复位有效
        reset = 1'b1;
        
        // 等待10个时钟周期的复位时间
        repeat (RESET_CYCLES) begin
            @(posedge clk);
        end
        
        // 释放复位，之后一直保持无效
        reset = 1'b0;
        
        $display("[%0t] Reset released, simulation running...", $time);
    end
    
    // ============================================
    // 可选: 波形文件生成 (VCD格式，GTKWave可查看)
    // ============================================
    // initial begin
    //     $dumpfile("tb_npc_top_.fst");
    //     $dumpvars(99, tb_npc_top);
    //     $display("[%0t] VCD dump started: tb_npc_top.fst", $time);
    // end
    
    // ============================================
    // 仿真结束检测 (可选，因为npc_top内部已有$finish)
    // ============================================
    initial begin
        // 等待内部 $finish 被调用
        wait (0);  // 永远不会自己执行，等待$finish结束仿真
    end

endmodule
