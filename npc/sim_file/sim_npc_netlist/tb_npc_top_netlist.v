`timescale 1ns / 1ps

module tb_npc_top();

    // 时钟和复位信号
    reg clk;
    reg reset;
    

    // wire mcause_0 = u_npc_top.u_cpu_top.\u_mReg.mcause_r_$_DFFE_PP__Q .Q;
    // wire mcause_1 = u_npc_top.u_cpu_top.\u_mReg.mcause_r_$_DFFE_PP__Q_1 .Q;
    // wire mcause_2 = u_npc_top.u_cpu_top.\u_mReg.mcause_r_$_DFFE_PP__Q_2 .Q;
    // wire mcause_3 = u_npc_top.u_cpu_top.\u_mReg.mcause_r_$_DFFE_PP__Q_3 .Q;

    // wire rf1_0 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_0__reg_p .Q;
    // wire rf1_1 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_1__reg_p .Q;
    // wire rf1_2 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_2__reg_p .Q;
    // wire rf1_3 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_3__reg_p .Q;
    // wire rf1_4 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_4__reg_p .Q;
    // wire rf1_5 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_5__reg_p .Q;
    // wire rf1_6 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_6__reg_p .Q;
    // wire rf1_7 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_7__reg_p .Q;
    // wire rf1_8 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_8__reg_p .Q;
    // wire rf1_9 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_9__reg_p .Q;
    // wire rf1_10 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_10__reg_p .Q;
    // wire rf1_11 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_11__reg_p .Q;
    // wire rf1_12 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_12__reg_p .Q;
    // wire rf1_13 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_13__reg_p .Q;
    // wire rf1_14 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_14__reg_p .Q;
    // wire rf1_15 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_15__reg_p .Q;
    // wire rf1_16 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_16__reg_p .Q;
    // wire rf1_17 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_17__reg_p .Q;
    // wire rf1_18 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_18__reg_p .Q;
    // wire rf1_19 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_19__reg_p .Q;
    // wire rf1_20 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_20__reg_p .Q;
    // wire rf1_21 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_21__reg_p .Q;
    // wire rf1_22 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_22__reg_p .Q;
    // wire rf1_23 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_23__reg_p .Q;
    // wire rf1_24 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_24__reg_p .Q;
    // wire rf1_25 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_25__reg_p .Q;
    // wire rf1_26 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_26__reg_p .Q;
    // wire rf1_27 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_27__reg_p .Q;
    // wire rf1_28 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_28__reg_p .Q;
    // wire rf1_29 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_29__reg_p .Q;
    // wire rf1_30 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_30__reg_p .Q;
    // wire rf1_31 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[14]_31__reg_p .Q;

    // wire rf2_0 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_0__reg_p .Q;
    // wire rf2_1 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_1__reg_p .Q;
    // wire rf2_2 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_2__reg_p .Q;
    // wire rf2_3 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_3__reg_p .Q;
    // wire rf2_4 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_4__reg_p .Q;
    // wire rf2_5 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_5__reg_p .Q;
    // wire rf2_6 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_6__reg_p .Q;
    // wire rf2_7 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_7__reg_p .Q;
    // wire rf2_8 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_8__reg_p .Q;
    // wire rf2_9 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_9__reg_p .Q;
    // wire rf2_10 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_10__reg_p .Q;
    // wire rf2_11 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_11__reg_p .Q;
    // wire rf2_12 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_12__reg_p .Q;
    // wire rf2_13 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_13__reg_p .Q;
    // wire rf2_14 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_14__reg_p .Q;
    // wire rf2_15 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_15__reg_p .Q;
    // wire rf2_16 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_16__reg_p .Q;
    // wire rf2_17 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_17__reg_p .Q;
    // wire rf2_18 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_18__reg_p .Q;
    // wire rf2_19 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_19__reg_p .Q;
    // wire rf2_20 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_20__reg_p .Q;
    // wire rf2_21 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_21__reg_p .Q;
    // wire rf2_22 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_22__reg_p .Q;
    // wire rf2_23 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_23__reg_p .Q;
    // wire rf2_24 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_24__reg_p .Q;
    // wire rf2_25 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_25__reg_p .Q;
    // wire rf2_26 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_26__reg_p .Q;
    // wire rf2_27 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_27__reg_p .Q;
    // wire rf2_28 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_28__reg_p .Q;
    // wire rf2_29 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_29__reg_p .Q;
    // wire rf2_30 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_30__reg_p .Q;
    // wire rf2_31 = u_npc_top.u_cpu_top.u_ysyx_25040102.\u_register.rf[12]_31__reg_p .Q;

    // wire pc_0 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_0__reg_p .Q;
    // wire pc_1 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_1__reg_p .Q;
    // wire pc_2 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_2__reg_p .Q;
    // wire pc_3 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_3__reg_p .Q;
    // wire pc_4 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_4__reg_p .Q;
    // wire pc_5 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_5__reg_p .Q;
    // wire pc_6 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_6__reg_p .Q;
    // wire pc_7 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_7__reg_p .Q;
    // wire pc_8 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_8__reg_p .Q;
    // wire pc_9 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_9__reg_p .Q;
    // wire pc_10 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_10__reg_p .Q;
    // wire pc_11 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_11__reg_p .Q;
    // wire pc_12 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_12__reg_p .Q;
    // wire pc_13 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_13__reg_p .Q;
    // wire pc_14 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_14__reg_p .Q;
    // wire pc_15 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_15__reg_p .Q;
    // wire pc_16 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_16__reg_p .Q;
    // wire pc_17 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_17__reg_p .Q;
    // wire pc_18 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_18__reg_p .Q;
    // wire pc_19 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_19__reg_p .Q;
    // wire pc_20 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_20__reg_p .Q;
    // wire pc_21 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_21__reg_p .Q;
    // wire pc_22 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_22__reg_p .Q;
    // wire pc_23 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_23__reg_p .Q;
    // wire pc_24 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_24__reg_p .Q;
    // wire pc_25 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_25__reg_p .Q;
    // wire pc_26 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_26__reg_p .Q;
    // wire pc_27 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_27__reg_p .Q;
    // wire pc_28 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_28__reg_p .Q;
    // wire pc_29 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_29__reg_p .Q;
    // wire pc_30 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_30__reg_p .Q;
    // wire pc_31 = u_npc_top.u_cpu_top.u_ysyx_25040102.pc_ls_31__reg_p .Q;


    // wire [3:0] mcause = {mcause_0, mcause_1, mcause_2, mcause_3};

    // wire [31:0] result_a4 = {rf1_31, rf1_30, rf1_29, rf1_28, rf1_27, rf1_26, rf1_25, rf1_24,
    //                 rf1_23, rf1_22, rf1_21, rf1_20, rf1_19, rf1_18, rf1_17, rf1_16,
    //                 rf1_15, rf1_14, rf1_13, rf1_12, rf1_11, rf1_10, rf1_9, rf1_8,
    //                 rf1_7, rf1_6, rf1_5, rf1_4, rf1_3, rf1_2, rf1_1, rf1_0};

    // wire [31:0] pc   = {pc_31,  pc_30, pc_29, pc_28, pc_27, pc_26, pc_25, pc_24,
    //                     pc_23,  pc_22, pc_21, pc_20, pc_19, pc_18, pc_17, pc_16,
    //                     pc_15,  pc_14, pc_13, pc_12, pc_11, pc_10, pc_9,  pc_8,
    //                     pc_7,   pc_6,  pc_5,  pc_4,  pc_3,  pc_2,  pc_1,  pc_0};

    // wire [31:0] result_a2 = {rf2_31, rf2_30, rf2_29, rf2_28, rf2_27, rf2_26, rf2_25, rf2_24,
    //                          rf2_23, rf2_22, rf2_21, rf2_20, rf2_19, rf2_18, rf2_17, rf2_16,
    //                          rf2_15, rf2_14, rf2_13, rf2_12, rf2_11, rf2_10, rf2_9,  rf2_8,
    //                          rf2_7,  rf2_6,  rf2_5,  rf2_4,  rf2_3,  rf2_2,  rf2_1,  rf2_0};

    // 时钟周期: 100MHz = 10ns
    localparam CLK_PERIOD = 10;
    
    // 复位持续时间: 10个时钟周期
    localparam RESET_CYCLES = 10;
    
    npc_top u_npc_top (
        .clk   (clk),
        .reset (reset)
    );
    
    initial begin
        clk = 1'b0;
        forever begin
            #(CLK_PERIOD / 2) clk = ~clk;
        end
    end

    // ============================================
    // 超时保护：5ms后强制结束
        // ============================================
    // initial begin
    //     #5_000_000;  // 5ms (timescale = 1ns)
    //     $display("[%0t] TIMEOUT: 5ms reached, forcing finish!", $time);
    //     $finish(1);
    // end
    
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
    //     $dumpfile("tb_npc_top.fst");
    //     $dumpvars(0, tb_npc_top);
    //     $display("[%0t] VCD dump started: tb_npc_top.fst", $time);
    // end


    // always @(posedge clk) begin
    //     if(mcause == 4'h3) begin
    //         $finish(1);
    //     end
    // end


    // ============================================
    // 仿真结束检测 (可选，因为npc_top内部已有$finish)
    // ============================================
    initial begin
        // 等待内部 $finish 被调用
        wait (0);  // 永远不会自己执行，等待$finish结束仿真
    end

endmodule
