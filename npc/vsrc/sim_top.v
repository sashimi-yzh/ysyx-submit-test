module sim_top();
    reg clk;
    reg rst_n;

    `ifndef WAVE
        `define WAVE 0  // 0=关闭波形，1=开启波形
    `endif
    `ifndef WAVEFORM_PATH
        `define WAVEFORM_PATH "waveform.fst"
    `endif


    initial begin
        clk = 1'b0;
        forever #1 clk = ~clk;  // 时钟翻转周期1ns，对应500MHz
    end


    initial begin
        rst_n = 1'b0;
        #100 rst_n = 1'b1;  // 100ns后释放复位
    end


    ysyx_25020037_npc u_cpu (
        .clock      (clk    ),           // 输入：系统时钟
        .reset      (~rst_n )            // 输入：复位信号
    );

    wire sim_end = u_cpu.cpu.sim_end;
    initial begin
        $display("[SIM] Simulation started. Waiting for endless...");
        
        wait(sim_end == 1);
        
        $display("[SIM] sim_end detected! Simulation completed successfully.");
        $finish;
    end


    initial begin
`ifdef WAVE
        if (`WAVE == 1) begin
            $display("[SIM] Waveform enabled. Saving to: %s", `WAVEFORM_PATH);
            $dumpfile(`WAVEFORM_PATH);
            $dumpvars(0, sim_top);
        end else begin
            $display("[SIM] Waveform disabled (set WAVE=1 to enable).");
        end
`else
        $display("[SIM] Waveform disabled by default (add WAVE=1 in Makefile to enable).");
`endif
    end

endmodule
