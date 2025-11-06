`timescale 1ns/1ps

module testbench;
    reg clock = 1'b0;
    reg reset = 1'b1;
    integer cycle_count = 0;
    
    // mainargs 参数和地址（可选）
    reg [511:0] mainargs = "t"; // 默认参数 't'
    reg [31:0] mainargs_addr = 32'h80001810; // 默认地址
    reg use_mainargs = 0; // 是否使用参数功能

    // 时钟
    always #5 clock = ~clock;  // 100MHz

    // 获取命令行参数和地址（可选）
    initial begin
        integer ret1, ret2;
        // 检查是否有 mainargs 参数
        ret1 = $value$plusargs("mainargs=%s", mainargs);
        if (ret1 != 0) begin
            use_mainargs = 1;
            
            // 检查是否有 mainargs_addr 参数
            ret2 = $value$plusargs("mainargs_addr=%h", mainargs_addr);
            
            $display("==========================================");
            $display("Parameter mode enabled:");
            $display("  mainargs: '%s' (ret=%0d)", mainargs, ret1);
            $display("  mainargs address: 0x%h (ret=%0d)", mainargs_addr, ret2);
            $display("==========================================");
        end else begin
            $display("==========================================");
            $display("Compatibility mode - no parameters");
            $display("==========================================");
        end
    end

    // 复位（对齐若干个上升沿）
    initial begin
        repeat (20) @(posedge clock);
        reset = 1'b0;
    end

    // 在复位释放后设置参数（仅当使用参数功能时）
    reg params_set = 0;
    always @(negedge reset) begin
        if (!params_set && use_mainargs) begin
            params_set = 1;
            set_mainargs_in_memory();
        end
    end

    task set_mainargs_in_memory;
        begin
            integer i;
            integer mem_offset;
            integer str_len;
            reg [7:0] current_char;
            
            $display("[mainargs] Setting parameter '%s' at memory address 0x%h", mainargs, mainargs_addr);
            
            // 计算字符串长度（按字节）
            str_len = 0;
            for (i = 0; i < 64; i = i + 1) begin
                current_char = mainargs[i*8 +: 8];
                $display("[mainargs] Byte %d: 0x%02x ('%c')", i, current_char, current_char);
                
                if (current_char != 0) begin
                    str_len = str_len + 1;
                end else begin
                    // 找到 null 终止符，退出循环
                    i = 64;
                end
            end
            $display("[mainargs] String length: %d bytes", str_len);
            
            // 计算内存偏移（减去基地址）
            mem_offset = mainargs_addr - 32'h80000000;
            
            // 确保地址在内存范围内
            if (mem_offset < 0 || mem_offset >= 65536) begin
                $display("[ERROR] mainargs address 0x%h is out of memory range!", mainargs_addr);
            end else begin
                // 写入参数字符串（以null结尾）- 修正字节顺序
                for (i = 0; i < str_len; i = i + 1) begin
                    // 修正：反转字节顺序
                    current_char = mainargs[(str_len - 1 - i)*8 +: 8];
                    u_npc.u_mem.mem[mem_offset + i] = current_char;
                    $display("[mainargs] Writing '%c' (0x%02x) to 0x%h", 
                             current_char, current_char, mainargs_addr + i);
                end
                // 写入 null 终止符
                u_npc.u_mem.mem[mem_offset + str_len] = 8'h00;
                $display("[mainargs] Writing null terminator to 0x%h", mainargs_addr + str_len);
                
                // 验证写入 - 等待一个时钟周期让写入稳定
                #10;
                $display("[mainargs] Verification:");
                for (i = 0; i < str_len + 1 && i < 5; i = i + 1) begin
                    $display("  Memory at 0x%h: 0x%02x ('%c')", 
                             mainargs_addr + i, u_npc.u_mem.mem[mem_offset + i], 
                             u_npc.u_mem.mem[mem_offset + i]);
                end
                if (str_len + 1 > 5) begin
                    $display("  ... and %d more bytes", str_len + 1 - 5);
                end
            end
            $display("[mainargs] Parameter set completed");
        end
    endtask

    // 计数
    always @(posedge clock) begin
        cycle_count <= cycle_count + 1;
    end

    // 波形
    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, testbench);
    end

    // 监控
    initial begin
        $display("Starting simulation at time %t", $time);
        @(negedge reset);
        $display("Reset released at time %t", $time);
        if (use_mainargs) begin
            $display("Running with parameter: '%s'", mainargs);
        end else begin
            $display("Running in compatibility mode");
        end
    end

    // ========= X 检查器 =========
    localparam XCHK_START = 50;

    `define ASSERT_NO_X(sig) \
        if ((^sig) === 1'bx) begin \
            $display("[%0t] **X detected**: %s", $time, `"sig`"); \
            $stop; \
        end

    // 成功检测
    always @(posedge clock) begin
        if (!reset && u_npc.is_break_M && u_npc.mem_in_valid) begin
            $display();
            $display("==========================================");
            if (use_mainargs) begin
                $display("Test completed with argument: '%s'", mainargs);
            end else begin
                $display("Test completed");
            end
            $display("Exit code (a0): %x", u_npc.u_ID.GPR.rf[10]);
            if(u_npc.u_ID.GPR.rf[10] == 0)begin
                $display("SUCCESS detected at cycle %d", cycle_count);
            end else begin
                $display("FAILURE detected at cycle %d", cycle_count);
            end
            $display("==========================================");
            #100 $finish;
        end
    end
    
    // 检测是否卡死
    localparam MAX_CYCLES = 100;
    reg [31:0] cnt;
    reg [31:0] prev_pc;
    
    always @(posedge clock) begin
        if(reset)begin
            cnt <= 0;
        end else if(prev_pc == u_npc.u_ID.pc_D) begin
            cnt <= cnt + 1;
        end else begin
            cnt <= 0;
        end
    end

    always @(posedge clock) begin
        if(reset)begin
            prev_pc <= 0;
        end else begin
            prev_pc <= u_npc.u_ID.pc_D;
        end
    end

    always @(*) begin
        if(cnt > MAX_CYCLES) begin
            $display("==========================================");
            $display("ERROR: Simulation timed out");
            $display("  PC stuck at: 0x%h", u_npc.u_ID.pc_D);
            $display("  For %d cycles", cnt);
            if (use_mainargs) begin
                $display("  Test argument: '%s'", mainargs);
            end
            $display("==========================================");
            $finish;
        end
    end

    // 实例化 DUT
    ysyx_24100006 u_npc(
        .clock(clock),
        .reset(reset)
    );
endmodule