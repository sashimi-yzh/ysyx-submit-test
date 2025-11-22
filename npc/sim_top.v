module sim_top();
    reg clk;
    reg rst_n;


    // 宏定义：默认路径与配置（可通过Makefile传入参数覆盖）
    `ifndef WAVE
        `define WAVE 0  // 0=关闭波形，1=开启波形
    `endif
    `ifndef WAVEFORM_PATH
        `define WAVEFORM_PATH "waveform.fst"
    `endif

    initial begin
        clk = 1'b0;
        forever #10 clk = ~clk;  // 时钟翻转周期10ns，对应50MHz
    end

    initial begin
        rst_n = 1'b0; 
        #100 rst_n = 1'b1;  // 100ns后释放复位
    end

    wire sim_end = u_cpu.cpu.sim_end;
    ysyx_25010030_npc u_cpu (
        .clock(clk),            
        .reset(~rst_n)       
    );

    initial begin
        $display("[SIM] Simulation started. Waiting for endless...");
        $display("[WAVEFORM]PATH = %s, WAVE_EN = %d",`WAVEFORM_PATH, `WAVE);
        // 等待
        wait(sim_end);
        
        $display("\033[32m[SIM] sim_end detected! Simulation completed successfully.\033[0m");
        $finish;  // 终止仿真进程
    end


    initial begin
`ifdef WAVE
        if (`WAVE == 1) begin
            $display("[SIM] Waveform enabled. Saving to: %s", `WAVEFORM_PATH);
            $dumpfile(`WAVEFORM_PATH);  // 指定波形文件路径
            $dumpvars(0, sim_top);     // 抓取整个sim_top模块的所有信号（0表示顶层）
        end else begin
            $display("[SIM] Waveform disabled (set WAVE=1 to enable).");
        end
`else
        $display("[SIM] Waveform disabled by default (add WAVE=1 in Makefile to enable).");
`endif
    end

endmodule