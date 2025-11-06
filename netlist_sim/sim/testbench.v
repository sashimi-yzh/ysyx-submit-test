`timescale 1ns/1ps

module testbench;
    reg clock = 1'b0;
    reg reset;
    integer cycle_count = 0;
    
    // mainargs 参数和地址（可选）
    reg [511:0] mainargs = "t"; // 默认参数 't'
    reg [31:0] mainargs_addr = 32'h80001810; // 默认地址
    reg use_mainargs = 0; // 是否使用参数功能

    initial begin
        clock = 0;
		reset = 1;
        #25 reset = 0;
    end

    // 在 initial 块中添加超时检测
    initial 
    begin
        // 超时监控进程
        #1000000000; // 根据实际情况调整超时时间（例如10秒）
        $display("ERROR: Simulation timeout at time %t", $time);
        $finish(2);
    end


    // 时钟
    always #5 clock = ~clock;  // 100MHz

    // 波形配置
    reg wave_enable = 0;
    reg [63:0] wave_file = "wave.vcd";

    // 获取命令行参数和地址（可选）
    initial begin
        integer ret1, ret2, ret3, ret4;
        
        // 检查波形开关
        ret3 = $value$plusargs("WAVE=%d", wave_enable);
        ret4 = $value$plusargs("WAVE_FILE=%s", wave_file);
        
        if (wave_enable) begin
            $display("==========================================");
            $display("Waveform generation enabled:");
            $display("  Wave file: %s", wave_file);
            $display("==========================================");
            $dumpfile(wave_file);
            $dumpvars(0, testbench);
        end
        

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
                    u_mem.mem[mem_offset + i] = current_char;
                    $display("[mainargs] Writing '%c' (0x%02x) to 0x%h", 
                             current_char, current_char, mainargs_addr + i);
                end
                // 写入 null 终止符
                u_mem.mem[mem_offset + str_len] = 8'h00;
                $display("[mainargs] Writing null terminator to 0x%h", mainargs_addr + str_len);
                
                // 验证写入 - 等待一个时钟周期让写入稳定
                #10;
                $display("[mainargs] Verification:");
                for (i = 0; i < str_len + 1 && i < 5; i = i + 1) begin
                    $display("  Memory at 0x%h: 0x%02x ('%c')", 
                             mainargs_addr + i, u_mem.mem[mem_offset + i], 
                             u_mem.mem[mem_offset + i]);
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
    localparam XCHK_START = 100;

    `define ASSERT_NO_X(sig) \
        if ((^sig) === 1'bx) begin \
            $display("[%0t] **X detected**: %s", $time, `"sig`"); \
            $stop; \
        end

    always @(posedge clock) begin
        if(reset == 1'b0 && cycle_count > XCHK_START) begin
            // 在此处添加需要检查的信号
            `ASSERT_NO_X(u_npc.u_ID.pc_D)
            `ASSERT_NO_X(u_npc.u_IF.pc_F)
            // 可以根据需要添加更多信号检查
        end
    end

    // 成功检测
    // 网表仿真时访问展平的寄存器信号
    wire [31:0] a0_value;
    
    // 将展平的位信号组合成32位寄存器值
    assign a0_value[0]  = u_npc.u_ID.GPR.\rf[9][0] ;
    assign a0_value[1]  = u_npc.u_ID.GPR.\rf[9][1] ;
    assign a0_value[2]  = u_npc.u_ID.GPR.\rf[9][2] ;
    assign a0_value[3]  = u_npc.u_ID.GPR.\rf[9][3] ;
    assign a0_value[4]  = u_npc.u_ID.GPR.\rf[9][4] ;
    assign a0_value[5]  = u_npc.u_ID.GPR.\rf[9][5] ;
    assign a0_value[6]  = u_npc.u_ID.GPR.\rf[9][6] ;
    assign a0_value[7]  = u_npc.u_ID.GPR.\rf[9][7] ;
    assign a0_value[8]  = u_npc.u_ID.GPR.\rf[9][8] ;
    assign a0_value[9]  = u_npc.u_ID.GPR.\rf[9][9] ;
    assign a0_value[10] = u_npc.u_ID.GPR.\rf[9][10] ;
    assign a0_value[11] = u_npc.u_ID.GPR.\rf[9][11] ;
    assign a0_value[12] = u_npc.u_ID.GPR.\rf[9][12] ;
    assign a0_value[13] = u_npc.u_ID.GPR.\rf[9][13] ;
    assign a0_value[14] = u_npc.u_ID.GPR.\rf[9][14] ;
    assign a0_value[15] = u_npc.u_ID.GPR.\rf[9][15] ;
    assign a0_value[16] = u_npc.u_ID.GPR.\rf[9][16] ;
    assign a0_value[17] = u_npc.u_ID.GPR.\rf[9][17] ;
    assign a0_value[18] = u_npc.u_ID.GPR.\rf[9][18] ;
    assign a0_value[19] = u_npc.u_ID.GPR.\rf[9][19] ;
    assign a0_value[20] = u_npc.u_ID.GPR.\rf[9][20] ;
    assign a0_value[21] = u_npc.u_ID.GPR.\rf[9][21] ;
    assign a0_value[22] = u_npc.u_ID.GPR.\rf[9][22] ;
    assign a0_value[23] = u_npc.u_ID.GPR.\rf[9][23] ;
    assign a0_value[24] = u_npc.u_ID.GPR.\rf[9][24] ;
    assign a0_value[25] = u_npc.u_ID.GPR.\rf[9][25] ;
    assign a0_value[26] = u_npc.u_ID.GPR.\rf[9][26] ;
    assign a0_value[27] = u_npc.u_ID.GPR.\rf[9][27] ;
    assign a0_value[28] = u_npc.u_ID.GPR.\rf[9][28] ;
    assign a0_value[29] = u_npc.u_ID.GPR.\rf[9][29] ;
    assign a0_value[30] = u_npc.u_ID.GPR.\rf[9][30] ;
    assign a0_value[31] = u_npc.u_ID.GPR.\rf[9][31] ;

    always @(posedge clock) begin
        if (!reset && u_npc.is_break_M && u_npc.mem_in_valid) begin
            $display();
            $display("==========================================");
            if (use_mainargs) begin
                $display("Test completed with argument: '%s'", mainargs);
            end else begin
                $display("Test completed");
            end
            $display("Exit code (a0): %x", a0_value);
            if(a0_value == 0)begin
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

    // 信号定义
    // 定义所有实例化连接信号为 wire 类型
    wire [31:0] u_mem_axi_araddr;
    wire [31:0] u_mem_axi_awaddr;
    wire [31:0] u_mem_axi_wdata;
    wire [3:0]  u_mem_axi_wstrb;

    wire        u_mem_axi_arvalid;
    wire        u_mem_axi_arready;
    wire        u_mem_axi_rready;
    wire        u_mem_axi_rvalid;
    wire        u_mem_axi_awvalid;
    wire        u_mem_axi_awready;
    wire        u_mem_axi_wvalid;
    wire        u_mem_axi_wready;
    wire        u_mem_axi_bready;
    wire        u_mem_axi_bvalid;
    wire [1:0]  u_mem_axi_bresp;

    wire [1:0]  u_mem_axi_rresp;
    wire [31:0] u_mem_axi_rdata;

    wire [7:0]  u_mem_axi_arlen;
    wire [2:0]  u_mem_axi_arsize;
    wire        u_mem_axi_rlast;
    wire [7:0]  u_mem_axi_awlen;
    wire [2:0]  u_mem_axi_awsize;
    wire        u_mem_axi_wlast;

    // 实例化 u_mem 模块
    ysyx_24100006_mem u_mem (
        .clk(clock),
        .reset(reset),

        // AXI 接口信号
        .axi_araddr(u_mem_axi_araddr),
        .axi_awaddr(u_mem_axi_awaddr),
        .axi_wdata(u_mem_axi_wdata),
        .axi_wstrb(u_mem_axi_wstrb),

        .axi_arvalid(u_mem_axi_arvalid),
        .axi_arready(u_mem_axi_arready),
        .axi_rready(u_mem_axi_rready),
        .axi_rvalid(u_mem_axi_rvalid),
        .axi_awvalid(u_mem_axi_awvalid),
        .axi_awready(u_mem_axi_awready),
        .axi_wvalid(u_mem_axi_wvalid),
        .axi_wready(u_mem_axi_wready),
        .axi_bready(u_mem_axi_bready),
        .axi_bvalid(u_mem_axi_bvalid),
        .axi_bresp(u_mem_axi_bresp),

        .axi_rresp(u_mem_axi_rresp),
        .axi_rdata(u_mem_axi_rdata),

        .axi_arlen(u_mem_axi_arlen),
        .axi_arsize(u_mem_axi_arsize),
        .axi_rlast(u_mem_axi_rlast),
        .axi_awlen(u_mem_axi_awlen),
        .axi_awsize(u_mem_axi_awsize),
        .axi_wlast(u_mem_axi_wlast)
    );

    // 实例化 UART 模块
	// 读地址通道
	wire       		uart_axi_arvalid;
    wire       		uart_axi_arready;
    wire [31:0]  	uart_axi_araddr;
    // 读数据通道
    wire         	uart_axi_rvalid;
    wire        	uart_axi_rready;
    wire [1:0]		uart_axi_rresp;
    wire [31:0]   	uart_axi_rdata;
    // 写地址通道
    wire         	uart_axi_awvalid;
    wire          	uart_axi_awready;
    wire [31:0]  	uart_axi_awaddr;
    // 写数据通道
    wire          	uart_axi_wvalid;
    wire        	uart_axi_wready;
    wire [31:0] 	uart_axi_wdata;
    wire [3:0]   	uart_axi_wstrb;
    // 写响应通道
    wire         	uart_axi_bvalid;
    wire        	uart_axi_bready;
    wire [1:0]  	uart_axi_bresp;

    ysyx_24100006_uart uart(
		.clk			(clock),
		.reset			(reset),
		
		// axi 写入和读取地址
		.axi_araddr		(uart_axi_araddr),
		.axi_awaddr		(uart_axi_awaddr),
		// axi 写入数据和写入使用的掩码
		.axi_wdata		(uart_axi_wdata),
		.axi_wstrb		(uart_axi_wstrb),
		// axi控制信号
		// read data addr
		.axi_arvalid	(uart_axi_arvalid),
		.axi_arready	(uart_axi_arready),
		// read data
		.axi_rready		(uart_axi_rready),
		.axi_rvalid		(uart_axi_rvalid),
		// write data addr
		.axi_awvalid	(uart_axi_awvalid),
		.axi_awready	(uart_axi_awready),
		// write data
		.axi_wvalid		(uart_axi_wvalid),
		.axi_wready		(uart_axi_wready),
		// response
		.axi_bready		(uart_axi_bready),
		.axi_bvalid		(uart_axi_bvalid),
		.axi_bresp		(uart_axi_bresp),

		// axi读取的回应
		.axi_rresp		(uart_axi_rresp),
		// axi读取的数据
		.axi_rdata		(uart_axi_rdata)
	);

    wire			io_master_awready;
	wire			io_master_awvalid;
	wire  [31:0]    io_master_awaddr;
	wire  [7:0]  	io_master_awlen;
	wire  [2:0]  	io_master_awsize;

	// 写数据通道
	wire			io_master_wready;
	wire            io_master_wvalid;
	wire  [31:0]    io_master_wdata;
	wire  [3:0]  	io_master_wstrb;
	wire  		    io_master_wlast;

	// 写响应通道
	wire			io_master_bready;
	wire			io_master_bvalid;
	wire   [1:0]  	io_master_bresp;
	wire   [3:0]  	io_master_bid;

	// 读地址通道
	wire            io_master_arready;
	wire            io_master_arvalid;
	wire  [31:0]    io_master_araddr;
	wire  [7:0]  	io_master_arlen;
	wire  [2:0]  	io_master_arsize;

	// 读数据通道
	wire  		    io_master_rready;
	wire            io_master_rvalid;
	wire   [1:0]  	io_master_rresp;
	wire   [31:0]   io_master_rdata;
	wire            io_master_rlast;

    // 实例化 DUT
    ysyx_24100006 u_npc(
        .clock(clock),
        .reset(reset),
        .io_interrupt(1'b0),  // 中断信号接地

        // AXI4 主设备接口连接到 u_mem
        .io_master_awready(io_master_awready),
        .io_master_awvalid(io_master_awvalid),
        .io_master_awaddr(io_master_awaddr),
        .io_master_awid(),    // 悬空（u_mem 无对应接口）
        .io_master_awlen(io_master_awlen),
        .io_master_awsize(io_master_awsize),
        .io_master_awburst(), // 悬空（u_mem 无对应接口）

        .io_master_wready(io_master_wready),
        .io_master_wvalid(io_master_wvalid),
        .io_master_wdata(io_master_wdata),
        .io_master_wstrb(io_master_wstrb),
        .io_master_wlast(io_master_wlast),

        .io_master_bready(io_master_bready),
        .io_master_bvalid(io_master_bvalid),
        .io_master_bresp(io_master_bresp),
        .io_master_bid(4'b0),     // 悬空（u_mem 无对应接口）

        .io_master_arready(io_master_arready),
        .io_master_arvalid(io_master_arvalid),
        .io_master_araddr(io_master_araddr),
        .io_master_arid(),    // 悬空（u_mem 无对应接口）
        .io_master_arlen(io_master_arlen),
        .io_master_arsize(io_master_arsize),
        .io_master_arburst(), // 悬空（u_mem 无对应接口）

        .io_master_rready(io_master_rready),
        .io_master_rvalid(io_master_rvalid),
        .io_master_rresp(io_master_rresp),
        .io_master_rdata(io_master_rdata),
        .io_master_rlast(io_master_rlast),
        .io_master_rid(4'b0),     // 悬空（u_mem 无对应接口）

        // Slave 接口输入接地/输出悬空
        .io_slave_awready(),  // 输出悬空
        .io_slave_awvalid(1'b0),
        .io_slave_awaddr(32'b0),
        .io_slave_awid(4'b0),
        .io_slave_awlen(8'b0),
        .io_slave_awsize(3'b0),
        .io_slave_awburst(2'b0),

        .io_slave_wready(),   // 输出悬空
        .io_slave_wvalid(1'b0),
        .io_slave_wdata(32'b0),
        .io_slave_wstrb(4'b0),
        .io_slave_wlast(1'b0),

        .io_slave_bready(1'b0),
        .io_slave_bvalid(),   // 输出悬空
        .io_slave_bresp(),    // 输出悬空
        .io_slave_bid(),      // 输出悬空

        .io_slave_arready(),  // 输出悬空
        .io_slave_arvalid(1'b0),
        .io_slave_araddr(32'b0),
        .io_slave_arid(4'b0),
        .io_slave_arlen(8'b0),
        .io_slave_arsize(3'b0),
        .io_slave_arburst(2'b0),

        .io_slave_rready(1'b0),
        .io_slave_rvalid(),   // 输出悬空
        .io_slave_rresp(),    // 输出悬空
        .io_slave_rdata(),    // 输出悬空
        .io_slave_rlast(),    // 输出悬空
        .io_slave_rid()       // 输出悬空
    );


    // 地址分发逻辑
    parameter UART_ADDR         = 32'ha000_03f8;
    wire sel_uart_read          = ( io_master_araddr >= UART_ADDR && io_master_araddr <= UART_ADDR + 32'h0000_0008);
    wire sel_uart_write         = ( io_master_awaddr >= UART_ADDR && io_master_awaddr <= UART_ADDR + 32'h0000_0008);
    wire sel_mem_read           = ~sel_uart_read;
    wire sel_mem_write          = ~sel_uart_write;

    // 主设备到从设备的信号分发
    // 读地址通道
    assign u_mem_axi_arvalid    = sel_mem_read & io_master_arvalid;
    assign uart_axi_arvalid     = sel_uart_read & io_master_arvalid;
    assign u_mem_axi_araddr     = io_master_araddr;
    assign uart_axi_araddr      = io_master_araddr;
    assign u_mem_axi_arlen      = io_master_arlen;
    assign u_mem_axi_arsize     = io_master_arsize;

    // 写地址通道  
    assign u_mem_axi_awvalid    = sel_mem_write & io_master_awvalid;
    assign uart_axi_awvalid     = sel_uart_write & io_master_awvalid;
    assign u_mem_axi_awaddr     = io_master_awaddr;
    assign uart_axi_awaddr      = io_master_awaddr;
    assign u_mem_axi_awlen      = io_master_awlen;
    assign u_mem_axi_awsize     = io_master_awsize;

    // 写数据通道
    assign u_mem_axi_wvalid     = io_master_wvalid && sel_mem_write;
    assign uart_axi_wvalid      = io_master_wvalid && sel_uart_write;
    assign u_mem_axi_wdata      = io_master_wdata;
    assign uart_axi_wdata       = io_master_wdata;
    assign u_mem_axi_wstrb      = io_master_wstrb;
    assign uart_axi_wstrb       = io_master_wstrb;
    assign u_mem_axi_wlast      = io_master_wlast;

    // 控制信号（从设备到主设备）
    assign io_master_arready    = sel_uart_read ? uart_axi_arready : u_mem_axi_arready;
    assign io_master_awready    = sel_uart_write ? uart_axi_awready : u_mem_axi_awready;
    assign io_master_wready     = sel_uart_write ? uart_axi_wready : u_mem_axi_wready;

    // 读响应通道
    assign io_master_rvalid     = sel_uart_read ? uart_axi_rvalid : u_mem_axi_rvalid;
    assign io_master_rresp      = sel_uart_read ? uart_axi_rresp : u_mem_axi_rresp;
    assign io_master_rdata      = sel_uart_read ? uart_axi_rdata : u_mem_axi_rdata;
    assign io_master_rlast      = sel_uart_read ? 1'b1 : u_mem_axi_rlast; // UART 单次传输，rlast 固定为1

    // 写响应通道
    assign io_master_bvalid     = sel_uart_write ? uart_axi_bvalid : u_mem_axi_bvalid;
    assign io_master_bresp      = sel_uart_write ? uart_axi_bresp : u_mem_axi_bresp;

    // 主设备到从设备的控制信号
    assign u_mem_axi_rready     = io_master_rready && sel_mem_read;
    assign uart_axi_rready      = io_master_rready && sel_uart_read;
    assign u_mem_axi_bready     = io_master_bready && sel_mem_write;
    assign uart_axi_bready      = io_master_bready && sel_uart_write;



    wire [31:0] mtime_lo,mtime_hi;
    // 将展平的位信号组合成64位寄存器值
    assign mtime_lo[0]  = u_npc.u_clint.\mtime_lo[0] ;
    assign mtime_lo[1]  = u_npc.u_clint.\mtime_lo[1] ;
    assign mtime_lo[2]  = u_npc.u_clint.\mtime_lo[2] ;
    assign mtime_lo[3]  = u_npc.u_clint.\mtime_lo[3] ;
    assign mtime_lo[4]  = u_npc.u_clint.\mtime_lo[4] ;
    assign mtime_lo[5]  = u_npc.u_clint.\mtime_lo[5] ;
    assign mtime_lo[6]  = u_npc.u_clint.\mtime_lo[6] ;
    assign mtime_lo[7]  = u_npc.u_clint.\mtime_lo[7] ;
    assign mtime_lo[8]  = u_npc.u_clint.\mtime_lo[8] ;
    assign mtime_lo[9]  = u_npc.u_clint.\mtime_lo[9] ;
    assign mtime_lo[10] = u_npc.u_clint.\mtime_lo[10] ;
    assign mtime_lo[11] = u_npc.u_clint.\mtime_lo[11] ;
    assign mtime_lo[12] = u_npc.u_clint.\mtime_lo[12] ;
    assign mtime_lo[13] = u_npc.u_clint.\mtime_lo[13] ;
    assign mtime_lo[14] = u_npc.u_clint.\mtime_lo[14] ;
    assign mtime_lo[15] = u_npc.u_clint.\mtime_lo[15] ;
    assign mtime_lo[16] = u_npc.u_clint.\mtime_lo[16] ;
    assign mtime_lo[17] = u_npc.u_clint.\mtime_lo[17] ;
    assign mtime_lo[18] = u_npc.u_clint.\mtime_lo[18] ;
    assign mtime_lo[19] = u_npc.u_clint.\mtime_lo[19] ;
    assign mtime_lo[20] = u_npc.u_clint.\mtime_lo[20] ;
    assign mtime_lo[21] = u_npc.u_clint.\mtime_lo[21] ;
    assign mtime_lo[22] = u_npc.u_clint.\mtime_lo[22] ;
    assign mtime_lo[23] = u_npc.u_clint.\mtime_lo[23] ;
    assign mtime_lo[24] = u_npc.u_clint.\mtime_lo[24] ;
    assign mtime_lo[25] = u_npc.u_clint.\mtime_lo[25] ;
    assign mtime_lo[26] = u_npc.u_clint.\mtime_lo[26] ;
    assign mtime_lo[27] = u_npc.u_clint.\mtime_lo[27] ;
    assign mtime_lo[28] = u_npc.u_clint.\mtime_lo[28] ;
    assign mtime_lo[29] = u_npc.u_clint.\mtime_lo[29] ;
    assign mtime_lo[30] = u_npc.u_clint.\mtime_lo[30] ;
    assign mtime_lo[31] = u_npc.u_clint.\mtime_lo[31] ;
    assign mtime_hi[0] = u_npc.u_clint.\mtime_hi[0] ;
    assign mtime_hi[1] = u_npc.u_clint.\mtime_hi[1] ;
    assign mtime_hi[2] = u_npc.u_clint.\mtime_hi[2] ;
    assign mtime_hi[3] = u_npc.u_clint.\mtime_hi[3] ;
    assign mtime_hi[4] = u_npc.u_clint.\mtime_hi[4] ;
    assign mtime_hi[5] = u_npc.u_clint.\mtime_hi[5] ;
    assign mtime_hi[6] = u_npc.u_clint.\mtime_hi[6] ;
    assign mtime_hi[7] = u_npc.u_clint.\mtime_hi[7] ;
    assign mtime_hi[8] = u_npc.u_clint.\mtime_hi[8] ;
    assign mtime_hi[9] = u_npc.u_clint.\mtime_hi[9] ;
    assign mtime_hi[10] = u_npc.u_clint.\mtime_hi[10] ;
    assign mtime_hi[11] = u_npc.u_clint.\mtime_hi[11] ;
    assign mtime_hi[12] = u_npc.u_clint.\mtime_hi[12] ;
    assign mtime_hi[13] = u_npc.u_clint.\mtime_hi[13] ;
    assign mtime_hi[14] = u_npc.u_clint.\mtime_hi[14] ;
    assign mtime_hi[15] = u_npc.u_clint.\mtime_hi[15] ;
    assign mtime_hi[16] = u_npc.u_clint.\mtime_hi[16] ;
    assign mtime_hi[17] = u_npc.u_clint.\mtime_hi[17] ;
    assign mtime_hi[18] = u_npc.u_clint.\mtime_hi[18] ;
    assign mtime_hi[19] = u_npc.u_clint.\mtime_hi[19] ;
    assign mtime_hi[20] = u_npc.u_clint.\mtime_hi[20] ;
    assign mtime_hi[21] = u_npc.u_clint.\mtime_hi[21] ;
    assign mtime_hi[22] = u_npc.u_clint.\mtime_hi[22] ;
    assign mtime_hi[23] = u_npc.u_clint.\mtime_hi[23] ;
    assign mtime_hi[24] = u_npc.u_clint.\mtime_hi[24] ;
    assign mtime_hi[25] = u_npc.u_clint.\mtime_hi[25] ;
    assign mtime_hi[26] = u_npc.u_clint.\mtime_hi[26] ;
    assign mtime_hi[27] = u_npc.u_clint.\mtime_hi[27] ;
    assign mtime_hi[28] = u_npc.u_clint.\mtime_hi[28] ;
    assign mtime_hi[29] = u_npc.u_clint.\mtime_hi[29] ;
    assign mtime_hi[30] = u_npc.u_clint.\mtime_hi[30] ;
    assign mtime_hi[31] = u_npc.u_clint.\mtime_hi[31] ;

    
    wire [31:0] pc_F;
    
    // 将展平的位信号组合成32位寄存器值
    assign pc_F[0]  = u_npc.u_IF.pc_F[0] ;
    assign pc_F[1]  = u_npc.u_IF.pc_F[1] ;
    assign pc_F[2]  = u_npc.u_IF.pc_F[2] ;
    assign pc_F[3]  = u_npc.u_IF.pc_F[3] ;
    assign pc_F[4]  = u_npc.u_IF.pc_F[4] ;
    assign pc_F[5]  = u_npc.u_IF.pc_F[5] ;
    assign pc_F[6]  = u_npc.u_IF.pc_F[6] ;
    assign pc_F[7]  = u_npc.u_IF.pc_F[7] ;
    assign pc_F[8]  = u_npc.u_IF.pc_F[8] ;
    assign pc_F[9]  = u_npc.u_IF.pc_F[9] ;
    assign pc_F[10] = u_npc.u_IF.pc_F[10] ;
    assign pc_F[11] = u_npc.u_IF.pc_F[11] ;
    assign pc_F[12] = u_npc.u_IF.pc_F[12] ;
    assign pc_F[13] = u_npc.u_IF.pc_F[13] ;
    assign pc_F[14] = u_npc.u_IF.pc_F[14] ;
    assign pc_F[15] = u_npc.u_IF.pc_F[15] ;
    assign pc_F[16] = u_npc.u_IF.pc_F[16] ;
    assign pc_F[17] = u_npc.u_IF.pc_F[17] ;
    assign pc_F[18] = u_npc.u_IF.pc_F[18] ;
    assign pc_F[19] = u_npc.u_IF.pc_F[19] ;
    assign pc_F[20] = u_npc.u_IF.pc_F[20] ;
    assign pc_F[21] = u_npc.u_IF.pc_F[21] ;
    assign pc_F[22] = u_npc.u_IF.pc_F[22] ;
    assign pc_F[23] = u_npc.u_IF.pc_F[23] ;
    assign pc_F[24] = u_npc.u_IF.pc_F[24] ;
    assign pc_F[25] = u_npc.u_IF.pc_F[25] ;
    assign pc_F[26] = u_npc.u_IF.pc_F[26] ;
    assign pc_F[27] = u_npc.u_IF.pc_F[27] ;
    assign pc_F[28] = u_npc.u_IF.pc_F[28] ;
    assign pc_F[29] = u_npc.u_IF.pc_F[29] ;
    assign pc_F[30] = u_npc.u_IF.pc_F[30] ;
    assign pc_F[31] = u_npc.u_IF.pc_F[31] ;

    wire [31:0] icache_0;
    wire [31:0] icache_1;
    wire [31:0] icache_2;
    wire [31:0] icache_3;

    // 为 icache_0 的每一位赋值
    assign icache_0[0]  = u_npc.u_icache.\line[0][0] ;
    assign icache_0[1]  = u_npc.u_icache.\line[0][1] ;
    assign icache_0[2]  = u_npc.u_icache.\line[0][2] ;
    assign icache_0[3]  = u_npc.u_icache.\line[0][3] ;
    assign icache_0[4]  = u_npc.u_icache.\line[0][4] ;
    assign icache_0[5]  = u_npc.u_icache.\line[0][5] ;
    assign icache_0[6]  = u_npc.u_icache.\line[0][6] ;
    assign icache_0[7]  = u_npc.u_icache.\line[0][7] ;
    assign icache_0[8]  = u_npc.u_icache.\line[0][8] ;
    assign icache_0[9]  = u_npc.u_icache.\line[0][9] ;
    assign icache_0[10] = u_npc.u_icache.\line[0][10] ;
    assign icache_0[11] = u_npc.u_icache.\line[0][11] ;
    assign icache_0[12] = u_npc.u_icache.\line[0][12] ;
    assign icache_0[13] = u_npc.u_icache.\line[0][13] ;
    assign icache_0[14] = u_npc.u_icache.\line[0][14] ;
    assign icache_0[15] = u_npc.u_icache.\line[0][15] ;
    assign icache_0[16] = u_npc.u_icache.\line[0][16] ;
    assign icache_0[17] = u_npc.u_icache.\line[0][17] ;
    assign icache_0[18] = u_npc.u_icache.\line[0][18] ;
    assign icache_0[19] = u_npc.u_icache.\line[0][19] ;
    assign icache_0[20] = u_npc.u_icache.\line[0][20] ;
    assign icache_0[21] = u_npc.u_icache.\line[0][21] ;
    assign icache_0[22] = u_npc.u_icache.\line[0][22] ;
    assign icache_0[23] = u_npc.u_icache.\line[0][23] ;
    assign icache_0[24] = u_npc.u_icache.\line[0][24] ;
    assign icache_0[25] = u_npc.u_icache.\line[0][25] ;
    assign icache_0[26] = u_npc.u_icache.\line[0][26] ;
    assign icache_0[27] = u_npc.u_icache.\line[0][27] ;
    assign icache_0[28] = u_npc.u_icache.\line[0][28] ;
    assign icache_0[29] = u_npc.u_icache.\line[0][29] ;
    assign icache_0[30] = u_npc.u_icache.\line[0][30] ;
    assign icache_0[31] = u_npc.u_icache.\line[0][31] ;

    // 为 icache_1 的每一位赋值
    assign icache_1[0]  = u_npc.u_icache.\line[1][0] ;
    assign icache_1[1]  = u_npc.u_icache.\line[1][1] ;
    assign icache_1[2]  = u_npc.u_icache.\line[1][2] ;
    assign icache_1[3]  = u_npc.u_icache.\line[1][3] ;
    assign icache_1[4]  = u_npc.u_icache.\line[1][4] ;
    assign icache_1[5]  = u_npc.u_icache.\line[1][5] ;
    assign icache_1[6]  = u_npc.u_icache.\line[1][6] ;
    assign icache_1[7]  = u_npc.u_icache.\line[1][7] ;
    assign icache_1[8]  = u_npc.u_icache.\line[1][8] ;
    assign icache_1[9]  = u_npc.u_icache.\line[1][9] ;
    assign icache_1[10] = u_npc.u_icache.\line[1][10] ;
    assign icache_1[11] = u_npc.u_icache.\line[1][11] ;
    assign icache_1[12] = u_npc.u_icache.\line[1][12] ;
    assign icache_1[13] = u_npc.u_icache.\line[1][13] ;
    assign icache_1[14] = u_npc.u_icache.\line[1][14] ;
    assign icache_1[15] = u_npc.u_icache.\line[1][15] ;
    assign icache_1[16] = u_npc.u_icache.\line[1][16] ;
    assign icache_1[17] = u_npc.u_icache.\line[1][17] ;
    assign icache_1[18] = u_npc.u_icache.\line[1][18] ;
    assign icache_1[19] = u_npc.u_icache.\line[1][19] ;
    assign icache_1[20] = u_npc.u_icache.\line[1][20] ;
    assign icache_1[21] = u_npc.u_icache.\line[1][21] ;
    assign icache_1[22] = u_npc.u_icache.\line[1][22] ;
    assign icache_1[23] = u_npc.u_icache.\line[1][23] ;
    assign icache_1[24] = u_npc.u_icache.\line[1][24] ;
    assign icache_1[25] = u_npc.u_icache.\line[1][25] ;
    assign icache_1[26] = u_npc.u_icache.\line[1][26] ;
    assign icache_1[27] = u_npc.u_icache.\line[1][27] ;
    assign icache_1[28] = u_npc.u_icache.\line[1][28] ;
    assign icache_1[29] = u_npc.u_icache.\line[1][29] ;
    assign icache_1[30] = u_npc.u_icache.\line[1][30] ;
    assign icache_1[31] = u_npc.u_icache.\line[1][31] ;

    // 为 icache_2 的每一位赋值
    assign icache_2[0]  = u_npc.u_icache.\line[2][0] ;
    assign icache_2[1]  = u_npc.u_icache.\line[2][1] ;
    assign icache_2[2]  = u_npc.u_icache.\line[2][2] ;
    assign icache_2[3]  = u_npc.u_icache.\line[2][3] ;
    assign icache_2[4]  = u_npc.u_icache.\line[2][4] ;
    assign icache_2[5]  = u_npc.u_icache.\line[2][5] ;
    assign icache_2[6]  = u_npc.u_icache.\line[2][6] ;
    assign icache_2[7]  = u_npc.u_icache.\line[2][7] ;
    assign icache_2[8]  = u_npc.u_icache.\line[2][8] ;
    assign icache_2[9]  = u_npc.u_icache.\line[2][9] ;
    assign icache_2[10] = u_npc.u_icache.\line[2][10] ;
    assign icache_2[11] = u_npc.u_icache.\line[2][11] ;
    assign icache_2[12] = u_npc.u_icache.\line[2][12] ;
    assign icache_2[13] = u_npc.u_icache.\line[2][13] ;
    assign icache_2[14] = u_npc.u_icache.\line[2][14] ;
    assign icache_2[15] = u_npc.u_icache.\line[2][15] ;
    assign icache_2[16] = u_npc.u_icache.\line[2][16] ;
    assign icache_2[17] = u_npc.u_icache.\line[2][17] ;
    assign icache_2[18] = u_npc.u_icache.\line[2][18] ;
    assign icache_2[19] = u_npc.u_icache.\line[2][19] ;
    assign icache_2[20] = u_npc.u_icache.\line[2][20] ;
    assign icache_2[21] = u_npc.u_icache.\line[2][21] ;
    assign icache_2[22] = u_npc.u_icache.\line[2][22] ;
    assign icache_2[23] = u_npc.u_icache.\line[2][23] ;
    assign icache_2[24] = u_npc.u_icache.\line[2][24] ;
    assign icache_2[25] = u_npc.u_icache.\line[2][25] ;
    assign icache_2[26] = u_npc.u_icache.\line[2][26] ;
    assign icache_2[27] = u_npc.u_icache.\line[2][27] ;
    assign icache_2[28] = u_npc.u_icache.\line[2][28] ;
    assign icache_2[29] = u_npc.u_icache.\line[2][29] ;
    assign icache_2[30] = u_npc.u_icache.\line[2][30] ;
    assign icache_2[31] = u_npc.u_icache.\line[2][31] ;

    // 为 icache_3 的每一位赋值
    assign icache_3[0]  = u_npc.u_icache.\line[3][0] ;
    assign icache_3[1]  = u_npc.u_icache.\line[3][1] ;
    assign icache_3[2]  = u_npc.u_icache.\line[3][2] ;
    assign icache_3[3]  = u_npc.u_icache.\line[3][3] ;
    assign icache_3[4]  = u_npc.u_icache.\line[3][4] ;
    assign icache_3[5]  = u_npc.u_icache.\line[3][5] ;
    assign icache_3[6]  = u_npc.u_icache.\line[3][6] ;
    assign icache_3[7]  = u_npc.u_icache.\line[3][7] ;
    assign icache_3[8]  = u_npc.u_icache.\line[3][8] ;
    assign icache_3[9]  = u_npc.u_icache.\line[3][9] ;
    assign icache_3[10] = u_npc.u_icache.\line[3][10] ;
    assign icache_3[11] = u_npc.u_icache.\line[3][11] ;
    assign icache_3[12] = u_npc.u_icache.\line[3][12] ;
    assign icache_3[13] = u_npc.u_icache.\line[3][13] ;
    assign icache_3[14] = u_npc.u_icache.\line[3][14] ;
    assign icache_3[15] = u_npc.u_icache.\line[3][15] ;
    assign icache_3[16] = u_npc.u_icache.\line[3][16] ;
    assign icache_3[17] = u_npc.u_icache.\line[3][17] ;
    assign icache_3[18] = u_npc.u_icache.\line[3][18] ;
    assign icache_3[19] = u_npc.u_icache.\line[3][19] ;
    assign icache_3[20] = u_npc.u_icache.\line[3][20] ;
    assign icache_3[21] = u_npc.u_icache.\line[3][21] ;
    assign icache_3[22] = u_npc.u_icache.\line[3][22] ;
    assign icache_3[23] = u_npc.u_icache.\line[3][23] ;
    assign icache_3[24] = u_npc.u_icache.\line[3][24] ;
    assign icache_3[25] = u_npc.u_icache.\line[3][25] ;
    assign icache_3[26] = u_npc.u_icache.\line[3][26] ;
    assign icache_3[27] = u_npc.u_icache.\line[3][27] ;
    assign icache_3[28] = u_npc.u_icache.\line[3][28] ;
    assign icache_3[29] = u_npc.u_icache.\line[3][29] ;
    assign icache_3[30] = u_npc.u_icache.\line[3][30] ;
    assign icache_3[31] = u_npc.u_icache.\line[3][31] ;

    // 定义 15 个 32 位 wire 变量
    wire [31:0] rf_1, rf_2, rf_3, rf_4, rf_5, rf_6, rf_7, rf_8, rf_9, rf_10, rf_11, rf_12, rf_13, rf_14, rf_15;

    // rf_1: Register 0
    assign rf_1[0] = u_npc.u_ID.GPR.\rf[0][0] ;  
    assign rf_1[1] = u_npc.u_ID.GPR.\rf[0][1] ;  
    assign rf_1[2] = u_npc.u_ID.GPR.\rf[0][2] ;  
    assign rf_1[3] = u_npc.u_ID.GPR.\rf[0][3] ;  
    assign rf_1[4] = u_npc.u_ID.GPR.\rf[0][4] ;  
    assign rf_1[5] = u_npc.u_ID.GPR.\rf[0][5] ;  
    assign rf_1[6] = u_npc.u_ID.GPR.\rf[0][6] ;  
    assign rf_1[7] = u_npc.u_ID.GPR.\rf[0][7] ;  
    assign rf_1[8] = u_npc.u_ID.GPR.\rf[0][8] ;  
    assign rf_1[9] = u_npc.u_ID.GPR.\rf[0][9] ;  
    assign rf_1[10] = u_npc.u_ID.GPR.\rf[0][10] ;
    assign rf_1[11] = u_npc.u_ID.GPR.\rf[0][11] ;
    assign rf_1[12] = u_npc.u_ID.GPR.\rf[0][12] ;
    assign rf_1[13] = u_npc.u_ID.GPR.\rf[0][13] ;
    assign rf_1[14] = u_npc.u_ID.GPR.\rf[0][14] ;
    assign rf_1[15] = u_npc.u_ID.GPR.\rf[0][15] ;
    assign rf_1[16] = u_npc.u_ID.GPR.\rf[0][16] ;
    assign rf_1[17] = u_npc.u_ID.GPR.\rf[0][17] ;
    assign rf_1[18] = u_npc.u_ID.GPR.\rf[0][18] ;
    assign rf_1[19] = u_npc.u_ID.GPR.\rf[0][19] ;
    assign rf_1[20] = u_npc.u_ID.GPR.\rf[0][20] ;
    assign rf_1[21] = u_npc.u_ID.GPR.\rf[0][21] ;
    assign rf_1[22] = u_npc.u_ID.GPR.\rf[0][22] ;
    assign rf_1[23] = u_npc.u_ID.GPR.\rf[0][23] ;
    assign rf_1[24] = u_npc.u_ID.GPR.\rf[0][24] ;
    assign rf_1[25] = u_npc.u_ID.GPR.\rf[0][25] ;
    assign rf_1[26] = u_npc.u_ID.GPR.\rf[0][26] ;
    assign rf_1[27] = u_npc.u_ID.GPR.\rf[0][27] ;
    assign rf_1[28] = u_npc.u_ID.GPR.\rf[0][28] ;
    assign rf_1[29] = u_npc.u_ID.GPR.\rf[0][29] ;
    assign rf_1[30] = u_npc.u_ID.GPR.\rf[0][30] ;
    assign rf_1[31] = u_npc.u_ID.GPR.\rf[0][31] ;

    // rf_2: Register 1
    assign rf_2[0] = u_npc.u_ID.GPR.\rf[1][0] ;
    assign rf_2[1] = u_npc.u_ID.GPR.\rf[1][1] ;
    assign rf_2[2] = u_npc.u_ID.GPR.\rf[1][2] ;
    assign rf_2[3] = u_npc.u_ID.GPR.\rf[1][3] ;
    assign rf_2[4] = u_npc.u_ID.GPR.\rf[1][4] ;
    assign rf_2[5] = u_npc.u_ID.GPR.\rf[1][5] ;
    assign rf_2[6] = u_npc.u_ID.GPR.\rf[1][6] ;
    assign rf_2[7] = u_npc.u_ID.GPR.\rf[1][7] ;
    assign rf_2[8] = u_npc.u_ID.GPR.\rf[1][8] ;
    assign rf_2[9] = u_npc.u_ID.GPR.\rf[1][9] ;
    assign rf_2[10] = u_npc.u_ID.GPR.\rf[1][10] ;
    assign rf_2[11] = u_npc.u_ID.GPR.\rf[1][11] ;
    assign rf_2[12] = u_npc.u_ID.GPR.\rf[1][12] ;
    assign rf_2[13] = u_npc.u_ID.GPR.\rf[1][13] ;
    assign rf_2[14] = u_npc.u_ID.GPR.\rf[1][14] ;
    assign rf_2[15] = u_npc.u_ID.GPR.\rf[1][15] ;
    assign rf_2[16] = u_npc.u_ID.GPR.\rf[1][16] ;
    assign rf_2[17] = u_npc.u_ID.GPR.\rf[1][17] ;
    assign rf_2[18] = u_npc.u_ID.GPR.\rf[1][18] ;
    assign rf_2[19] = u_npc.u_ID.GPR.\rf[1][19] ;
    assign rf_2[20] = u_npc.u_ID.GPR.\rf[1][20] ;
    assign rf_2[21] = u_npc.u_ID.GPR.\rf[1][21] ;
    assign rf_2[22] = u_npc.u_ID.GPR.\rf[1][22] ;
    assign rf_2[23] = u_npc.u_ID.GPR.\rf[1][23] ;
    assign rf_2[24] = u_npc.u_ID.GPR.\rf[1][24] ;
    assign rf_2[25] = u_npc.u_ID.GPR.\rf[1][25] ;
    assign rf_2[26] = u_npc.u_ID.GPR.\rf[1][26] ;
    assign rf_2[27] = u_npc.u_ID.GPR.\rf[1][27] ;
    assign rf_2[28] = u_npc.u_ID.GPR.\rf[1][28] ;
    assign rf_2[29] = u_npc.u_ID.GPR.\rf[1][29] ;
    assign rf_2[30] = u_npc.u_ID.GPR.\rf[1][30] ;
    assign rf_2[31] = u_npc.u_ID.GPR.\rf[1][31] ;

    // rf_3: Register 2
    assign rf_3[0] = u_npc.u_ID.GPR.\rf[2][0] ;
    assign rf_3[1] = u_npc.u_ID.GPR.\rf[2][1] ;
    assign rf_3[2] = u_npc.u_ID.GPR.\rf[2][2] ;
    assign rf_3[3] = u_npc.u_ID.GPR.\rf[2][3] ;
    assign rf_3[4] = u_npc.u_ID.GPR.\rf[2][4] ;
    assign rf_3[5] = u_npc.u_ID.GPR.\rf[2][5] ;
    assign rf_3[6] = u_npc.u_ID.GPR.\rf[2][6] ;
    assign rf_3[7] = u_npc.u_ID.GPR.\rf[2][7] ;
    assign rf_3[8] = u_npc.u_ID.GPR.\rf[2][8] ;
    assign rf_3[9] = u_npc.u_ID.GPR.\rf[2][9] ;
    assign rf_3[10] = u_npc.u_ID.GPR.\rf[2][10] ;
    assign rf_3[11] = u_npc.u_ID.GPR.\rf[2][11] ;
    assign rf_3[12] = u_npc.u_ID.GPR.\rf[2][12] ;
    assign rf_3[13] = u_npc.u_ID.GPR.\rf[2][13] ;
    assign rf_3[14] = u_npc.u_ID.GPR.\rf[2][14] ;
    assign rf_3[15] = u_npc.u_ID.GPR.\rf[2][15] ;
    assign rf_3[16] = u_npc.u_ID.GPR.\rf[2][16] ;
    assign rf_3[17] = u_npc.u_ID.GPR.\rf[2][17] ;
    assign rf_3[18] = u_npc.u_ID.GPR.\rf[2][18] ;
    assign rf_3[19] = u_npc.u_ID.GPR.\rf[2][19] ;
    assign rf_3[20] = u_npc.u_ID.GPR.\rf[2][20] ;
    assign rf_3[21] = u_npc.u_ID.GPR.\rf[2][21] ;
    assign rf_3[22] = u_npc.u_ID.GPR.\rf[2][22] ;
    assign rf_3[23] = u_npc.u_ID.GPR.\rf[2][23] ;
    assign rf_3[24] = u_npc.u_ID.GPR.\rf[2][24] ;
    assign rf_3[25] = u_npc.u_ID.GPR.\rf[2][25] ;
    assign rf_3[26] = u_npc.u_ID.GPR.\rf[2][26] ;
    assign rf_3[27] = u_npc.u_ID.GPR.\rf[2][27] ;
    assign rf_3[28] = u_npc.u_ID.GPR.\rf[2][28] ;
    assign rf_3[29] = u_npc.u_ID.GPR.\rf[2][29] ;
    assign rf_3[30] = u_npc.u_ID.GPR.\rf[2][30] ;
    assign rf_3[31] = u_npc.u_ID.GPR.\rf[2][31] ;

    // rf_4: Register 3
    assign rf_4[0] = u_npc.u_ID.GPR.\rf[3][0] ;
    assign rf_4[1] = u_npc.u_ID.GPR.\rf[3][1] ;
    assign rf_4[2] = u_npc.u_ID.GPR.\rf[3][2] ;
    assign rf_4[3] = u_npc.u_ID.GPR.\rf[3][3] ;
    assign rf_4[4] = u_npc.u_ID.GPR.\rf[3][4] ;
    assign rf_4[5] = u_npc.u_ID.GPR.\rf[3][5] ;
    assign rf_4[6] = u_npc.u_ID.GPR.\rf[3][6] ;
    assign rf_4[7] = u_npc.u_ID.GPR.\rf[3][7] ;
    assign rf_4[8] = u_npc.u_ID.GPR.\rf[3][8] ;
    assign rf_4[9] = u_npc.u_ID.GPR.\rf[3][9] ;
    assign rf_4[10] = u_npc.u_ID.GPR.\rf[3][10] ;
    assign rf_4[11] = u_npc.u_ID.GPR.\rf[3][11] ;
    assign rf_4[12] = u_npc.u_ID.GPR.\rf[3][12] ;
    assign rf_4[13] = u_npc.u_ID.GPR.\rf[3][13] ;
    assign rf_4[14] = u_npc.u_ID.GPR.\rf[3][14] ;
    assign rf_4[15] = u_npc.u_ID.GPR.\rf[3][15] ;
    assign rf_4[16] = u_npc.u_ID.GPR.\rf[3][16] ;
    assign rf_4[17] = u_npc.u_ID.GPR.\rf[3][17] ;
    assign rf_4[18] = u_npc.u_ID.GPR.\rf[3][18] ;
    assign rf_4[19] = u_npc.u_ID.GPR.\rf[3][19] ;
    assign rf_4[20] = u_npc.u_ID.GPR.\rf[3][20] ;
    assign rf_4[21] = u_npc.u_ID.GPR.\rf[3][21] ;
    assign rf_4[22] = u_npc.u_ID.GPR.\rf[3][22] ;
    assign rf_4[23] = u_npc.u_ID.GPR.\rf[3][23] ;
    assign rf_4[24] = u_npc.u_ID.GPR.\rf[3][24] ;
    assign rf_4[25] = u_npc.u_ID.GPR.\rf[3][25] ;
    assign rf_4[26] = u_npc.u_ID.GPR.\rf[3][26] ;
    assign rf_4[27] = u_npc.u_ID.GPR.\rf[3][27] ;
    assign rf_4[28] = u_npc.u_ID.GPR.\rf[3][28] ;
    assign rf_4[29] = u_npc.u_ID.GPR.\rf[3][29] ;
    assign rf_4[30] = u_npc.u_ID.GPR.\rf[3][30] ;
    assign rf_4[31] = u_npc.u_ID.GPR.\rf[3][31] ;

    // rf_5: Register 4
    assign rf_5[0] = u_npc.u_ID.GPR.\rf[4][0] ;
    assign rf_5[1] = u_npc.u_ID.GPR.\rf[4][1] ;
    assign rf_5[2] = u_npc.u_ID.GPR.\rf[4][2] ;
    assign rf_5[3] = u_npc.u_ID.GPR.\rf[4][3] ;
    assign rf_5[4] = u_npc.u_ID.GPR.\rf[4][4] ;
    assign rf_5[5] = u_npc.u_ID.GPR.\rf[4][5] ;
    assign rf_5[6] = u_npc.u_ID.GPR.\rf[4][6] ;
    assign rf_5[7] = u_npc.u_ID.GPR.\rf[4][7] ;
    assign rf_5[8] = u_npc.u_ID.GPR.\rf[4][8] ;
    assign rf_5[9] = u_npc.u_ID.GPR.\rf[4][9] ;
    assign rf_5[10] = u_npc.u_ID.GPR.\rf[4][10] ;
    assign rf_5[11] = u_npc.u_ID.GPR.\rf[4][11] ;
    assign rf_5[12] = u_npc.u_ID.GPR.\rf[4][12] ;
    assign rf_5[13] = u_npc.u_ID.GPR.\rf[4][13] ;
    assign rf_5[14] = u_npc.u_ID.GPR.\rf[4][14] ;
    assign rf_5[15] = u_npc.u_ID.GPR.\rf[4][15] ;
    assign rf_5[16] = u_npc.u_ID.GPR.\rf[4][16] ;
    assign rf_5[17] = u_npc.u_ID.GPR.\rf[4][17] ;
    assign rf_5[18] = u_npc.u_ID.GPR.\rf[4][18] ;
    assign rf_5[19] = u_npc.u_ID.GPR.\rf[4][19] ;
    assign rf_5[20] = u_npc.u_ID.GPR.\rf[4][20] ;
    assign rf_5[21] = u_npc.u_ID.GPR.\rf[4][21] ;
    assign rf_5[22] = u_npc.u_ID.GPR.\rf[4][22] ;
    assign rf_5[23] = u_npc.u_ID.GPR.\rf[4][23] ;
    assign rf_5[24] = u_npc.u_ID.GPR.\rf[4][24] ;
    assign rf_5[25] = u_npc.u_ID.GPR.\rf[4][25] ;
    assign rf_5[26] = u_npc.u_ID.GPR.\rf[4][26] ;
    assign rf_5[27] = u_npc.u_ID.GPR.\rf[4][27] ;
    assign rf_5[28] = u_npc.u_ID.GPR.\rf[4][28] ;
    assign rf_5[29] = u_npc.u_ID.GPR.\rf[4][29] ;
    assign rf_5[30] = u_npc.u_ID.GPR.\rf[4][30] ;
    assign rf_5[31] = u_npc.u_ID.GPR.\rf[4][31] ;

    // rf_6: Register 5
    assign rf_6[0] = u_npc.u_ID.GPR.\rf[5][0] ;
    assign rf_6[1] = u_npc.u_ID.GPR.\rf[5][1] ;
    assign rf_6[2] = u_npc.u_ID.GPR.\rf[5][2] ;
    assign rf_6[3] = u_npc.u_ID.GPR.\rf[5][3] ;
    assign rf_6[4] = u_npc.u_ID.GPR.\rf[5][4] ;
    assign rf_6[5] = u_npc.u_ID.GPR.\rf[5][5] ;
    assign rf_6[6] = u_npc.u_ID.GPR.\rf[5][6] ;
    assign rf_6[7] = u_npc.u_ID.GPR.\rf[5][7] ;
    assign rf_6[8] = u_npc.u_ID.GPR.\rf[5][8] ;
    assign rf_6[9] = u_npc.u_ID.GPR.\rf[5][9] ;
    assign rf_6[10] = u_npc.u_ID.GPR.\rf[5][10] ;
    assign rf_6[11] = u_npc.u_ID.GPR.\rf[5][11] ;
    assign rf_6[12] = u_npc.u_ID.GPR.\rf[5][12] ;
    assign rf_6[13] = u_npc.u_ID.GPR.\rf[5][13] ;
    assign rf_6[14] = u_npc.u_ID.GPR.\rf[5][14] ;
    assign rf_6[15] = u_npc.u_ID.GPR.\rf[5][15] ;
    assign rf_6[16] = u_npc.u_ID.GPR.\rf[5][16] ;
    assign rf_6[17] = u_npc.u_ID.GPR.\rf[5][17] ;
    assign rf_6[18] = u_npc.u_ID.GPR.\rf[5][18] ;
    assign rf_6[19] = u_npc.u_ID.GPR.\rf[5][19] ;
    assign rf_6[20] = u_npc.u_ID.GPR.\rf[5][20] ;
    assign rf_6[21] = u_npc.u_ID.GPR.\rf[5][21] ;
    assign rf_6[22] = u_npc.u_ID.GPR.\rf[5][22] ;
    assign rf_6[23] = u_npc.u_ID.GPR.\rf[5][23] ;
    assign rf_6[24] = u_npc.u_ID.GPR.\rf[5][24] ;
    assign rf_6[25] = u_npc.u_ID.GPR.\rf[5][25] ;
    assign rf_6[26] = u_npc.u_ID.GPR.\rf[5][26] ;
    assign rf_6[27] = u_npc.u_ID.GPR.\rf[5][27] ;
    assign rf_6[28] = u_npc.u_ID.GPR.\rf[5][28] ;
    assign rf_6[29] = u_npc.u_ID.GPR.\rf[5][29] ;
    assign rf_6[30] = u_npc.u_ID.GPR.\rf[5][30] ;
    assign rf_6[31] = u_npc.u_ID.GPR.\rf[5][31] ;

    // rf_7: Register 6
    assign rf_7[0] = u_npc.u_ID.GPR.\rf[6][0] ;
    assign rf_7[1] = u_npc.u_ID.GPR.\rf[6][1] ;
    assign rf_7[2] = u_npc.u_ID.GPR.\rf[6][2] ;
    assign rf_7[3] = u_npc.u_ID.GPR.\rf[6][3] ;
    assign rf_7[4] = u_npc.u_ID.GPR.\rf[6][4] ;
    assign rf_7[5] = u_npc.u_ID.GPR.\rf[6][5] ;
    assign rf_7[6] = u_npc.u_ID.GPR.\rf[6][6] ;
    assign rf_7[7] = u_npc.u_ID.GPR.\rf[6][7] ;
    assign rf_7[8] = u_npc.u_ID.GPR.\rf[6][8] ;
    assign rf_7[9] = u_npc.u_ID.GPR.\rf[6][9] ;
    assign rf_7[10] = u_npc.u_ID.GPR.\rf[6][10] ;
    assign rf_7[11] = u_npc.u_ID.GPR.\rf[6][11] ;
    assign rf_7[12] = u_npc.u_ID.GPR.\rf[6][12] ;
    assign rf_7[13] = u_npc.u_ID.GPR.\rf[6][13] ;
    assign rf_7[14] = u_npc.u_ID.GPR.\rf[6][14] ;
    assign rf_7[15] = u_npc.u_ID.GPR.\rf[6][15] ;
    assign rf_7[16] = u_npc.u_ID.GPR.\rf[6][16] ;
    assign rf_7[17] = u_npc.u_ID.GPR.\rf[6][17] ;
    assign rf_7[18] = u_npc.u_ID.GPR.\rf[6][18] ;
    assign rf_7[19] = u_npc.u_ID.GPR.\rf[6][19] ;
    assign rf_7[20] = u_npc.u_ID.GPR.\rf[6][20] ;
    assign rf_7[21] = u_npc.u_ID.GPR.\rf[6][21] ;
    assign rf_7[22] = u_npc.u_ID.GPR.\rf[6][22] ;
    assign rf_7[23] = u_npc.u_ID.GPR.\rf[6][23] ;
    assign rf_7[24] = u_npc.u_ID.GPR.\rf[6][24] ;
    assign rf_7[25] = u_npc.u_ID.GPR.\rf[6][25] ;
    assign rf_7[26] = u_npc.u_ID.GPR.\rf[6][26] ;
    assign rf_7[27] = u_npc.u_ID.GPR.\rf[6][27] ;
    assign rf_7[28] = u_npc.u_ID.GPR.\rf[6][28] ;
    assign rf_7[29] = u_npc.u_ID.GPR.\rf[6][29] ;
    assign rf_7[30] = u_npc.u_ID.GPR.\rf[6][30] ;
    assign rf_7[31] = u_npc.u_ID.GPR.\rf[6][31] ;

    // rf_8: Register 7
    assign rf_8[0] = u_npc.u_ID.GPR.\rf[7][0] ;
    assign rf_8[1] = u_npc.u_ID.GPR.\rf[7][1] ;
    assign rf_8[2] = u_npc.u_ID.GPR.\rf[7][2] ;
    assign rf_8[3] = u_npc.u_ID.GPR.\rf[7][3] ;
    assign rf_8[4] = u_npc.u_ID.GPR.\rf[7][4] ;
    assign rf_8[5] = u_npc.u_ID.GPR.\rf[7][5] ;
    assign rf_8[6] = u_npc.u_ID.GPR.\rf[7][6] ;
    assign rf_8[7] = u_npc.u_ID.GPR.\rf[7][7] ;
    assign rf_8[8] = u_npc.u_ID.GPR.\rf[7][8] ;
    assign rf_8[9] = u_npc.u_ID.GPR.\rf[7][9] ;
    assign rf_8[10] = u_npc.u_ID.GPR.\rf[7][10] ;
    assign rf_8[11] = u_npc.u_ID.GPR.\rf[7][11] ;
    assign rf_8[12] = u_npc.u_ID.GPR.\rf[7][12] ;
    assign rf_8[13] = u_npc.u_ID.GPR.\rf[7][13] ;
    assign rf_8[14] = u_npc.u_ID.GPR.\rf[7][14] ;
    assign rf_8[15] = u_npc.u_ID.GPR.\rf[7][15] ;
    assign rf_8[16] = u_npc.u_ID.GPR.\rf[7][16] ;
    assign rf_8[17] = u_npc.u_ID.GPR.\rf[7][17] ;
    assign rf_8[18] = u_npc.u_ID.GPR.\rf[7][18] ;
    assign rf_8[19] = u_npc.u_ID.GPR.\rf[7][19] ;
    assign rf_8[20] = u_npc.u_ID.GPR.\rf[7][20] ;
    assign rf_8[21] = u_npc.u_ID.GPR.\rf[7][21] ;
    assign rf_8[22] = u_npc.u_ID.GPR.\rf[7][22] ;
    assign rf_8[23] = u_npc.u_ID.GPR.\rf[7][23] ;
    assign rf_8[24] = u_npc.u_ID.GPR.\rf[7][24] ;
    assign rf_8[25] = u_npc.u_ID.GPR.\rf[7][25] ;
    assign rf_8[26] = u_npc.u_ID.GPR.\rf[7][26] ;
    assign rf_8[27] = u_npc.u_ID.GPR.\rf[7][27] ;
    assign rf_8[28] = u_npc.u_ID.GPR.\rf[7][28] ;
    assign rf_8[29] = u_npc.u_ID.GPR.\rf[7][29] ;
    assign rf_8[30] = u_npc.u_ID.GPR.\rf[7][30] ;
    assign rf_8[31] = u_npc.u_ID.GPR.\rf[7][31] ;

    // rf_9: Register 8
    assign rf_9[0] = u_npc.u_ID.GPR.\rf[8][0] ;
    assign rf_9[1] = u_npc.u_ID.GPR.\rf[8][1] ;
    assign rf_9[2] = u_npc.u_ID.GPR.\rf[8][2] ;
    assign rf_9[3] = u_npc.u_ID.GPR.\rf[8][3] ;
    assign rf_9[4] = u_npc.u_ID.GPR.\rf[8][4] ;
    assign rf_9[5] = u_npc.u_ID.GPR.\rf[8][5] ;
    assign rf_9[6] = u_npc.u_ID.GPR.\rf[8][6] ;
    assign rf_9[7] = u_npc.u_ID.GPR.\rf[8][7] ;
    assign rf_9[8] = u_npc.u_ID.GPR.\rf[8][8] ;
    assign rf_9[9] = u_npc.u_ID.GPR.\rf[8][9] ;
    assign rf_9[10] = u_npc.u_ID.GPR.\rf[8][10] ;
    assign rf_9[11] = u_npc.u_ID.GPR.\rf[8][11] ;
    assign rf_9[12] = u_npc.u_ID.GPR.\rf[8][12] ;
    assign rf_9[13] = u_npc.u_ID.GPR.\rf[8][13] ;
    assign rf_9[14] = u_npc.u_ID.GPR.\rf[8][14] ;
    assign rf_9[15] = u_npc.u_ID.GPR.\rf[8][15] ;
    assign rf_9[16] = u_npc.u_ID.GPR.\rf[8][16] ;
    assign rf_9[17] = u_npc.u_ID.GPR.\rf[8][17] ;
    assign rf_9[18] = u_npc.u_ID.GPR.\rf[8][18] ;
    assign rf_9[19] = u_npc.u_ID.GPR.\rf[8][19] ;
    assign rf_9[20] = u_npc.u_ID.GPR.\rf[8][20] ;
    assign rf_9[21] = u_npc.u_ID.GPR.\rf[8][21] ;
    assign rf_9[22] = u_npc.u_ID.GPR.\rf[8][22] ;
    assign rf_9[23] = u_npc.u_ID.GPR.\rf[8][23] ;
    assign rf_9[24] = u_npc.u_ID.GPR.\rf[8][24] ;
    assign rf_9[25] = u_npc.u_ID.GPR.\rf[8][25] ;
    assign rf_9[26] = u_npc.u_ID.GPR.\rf[8][26] ;
    assign rf_9[27] = u_npc.u_ID.GPR.\rf[8][27] ;
    assign rf_9[28] = u_npc.u_ID.GPR.\rf[8][28] ;
    assign rf_9[29] = u_npc.u_ID.GPR.\rf[8][29] ;
    assign rf_9[30] = u_npc.u_ID.GPR.\rf[8][30] ;
    assign rf_9[31] = u_npc.u_ID.GPR.\rf[8][31] ;

    // rf_10: Register 9
    assign rf_10[0] = u_npc.u_ID.GPR.\rf[9][0] ;
    assign rf_10[1] = u_npc.u_ID.GPR.\rf[9][1] ;
    assign rf_10[2] = u_npc.u_ID.GPR.\rf[9][2] ;
    assign rf_10[3] = u_npc.u_ID.GPR.\rf[9][3] ;
    assign rf_10[4] = u_npc.u_ID.GPR.\rf[9][4] ;
    assign rf_10[5] = u_npc.u_ID.GPR.\rf[9][5] ;
    assign rf_10[6] = u_npc.u_ID.GPR.\rf[9][6] ;
    assign rf_10[7] = u_npc.u_ID.GPR.\rf[9][7] ;
    assign rf_10[8] = u_npc.u_ID.GPR.\rf[9][8] ;
    assign rf_10[9] = u_npc.u_ID.GPR.\rf[9][9] ;
    assign rf_10[10] = u_npc.u_ID.GPR.\rf[9][10] ;
    assign rf_10[11] = u_npc.u_ID.GPR.\rf[9][11] ;
    assign rf_10[12] = u_npc.u_ID.GPR.\rf[9][12] ;
    assign rf_10[13] = u_npc.u_ID.GPR.\rf[9][13] ;
    assign rf_10[14] = u_npc.u_ID.GPR.\rf[9][14] ;
    assign rf_10[15] = u_npc.u_ID.GPR.\rf[9][15] ;
    assign rf_10[16] = u_npc.u_ID.GPR.\rf[9][16] ;
    assign rf_10[17] = u_npc.u_ID.GPR.\rf[9][17] ;
    assign rf_10[18] = u_npc.u_ID.GPR.\rf[9][18] ;
    assign rf_10[19] = u_npc.u_ID.GPR.\rf[9][19] ;
    assign rf_10[20] = u_npc.u_ID.GPR.\rf[9][20] ;
    assign rf_10[21] = u_npc.u_ID.GPR.\rf[9][21] ;
    assign rf_10[22] = u_npc.u_ID.GPR.\rf[9][22] ;
    assign rf_10[23] = u_npc.u_ID.GPR.\rf[9][23] ;
    assign rf_10[24] = u_npc.u_ID.GPR.\rf[9][24] ;
    assign rf_10[25] = u_npc.u_ID.GPR.\rf[9][25] ;
    assign rf_10[26] = u_npc.u_ID.GPR.\rf[9][26] ;
    assign rf_10[27] = u_npc.u_ID.GPR.\rf[9][27] ;
    assign rf_10[28] = u_npc.u_ID.GPR.\rf[9][28] ;
    assign rf_10[29] = u_npc.u_ID.GPR.\rf[9][29] ;
    assign rf_10[30] = u_npc.u_ID.GPR.\rf[9][30] ;
    assign rf_10[31] = u_npc.u_ID.GPR.\rf[9][31] ;

    // rf_11: Register 10
    assign rf_11[0] = u_npc.u_ID.GPR.\rf[10][0] ;
    assign rf_11[1] = u_npc.u_ID.GPR.\rf[10][1] ;
    assign rf_11[2] = u_npc.u_ID.GPR.\rf[10][2] ;
    assign rf_11[3] = u_npc.u_ID.GPR.\rf[10][3] ;
    assign rf_11[4] = u_npc.u_ID.GPR.\rf[10][4] ;
    assign rf_11[5] = u_npc.u_ID.GPR.\rf[10][5] ;
    assign rf_11[6] = u_npc.u_ID.GPR.\rf[10][6] ;
    assign rf_11[7] = u_npc.u_ID.GPR.\rf[10][7] ;
    assign rf_11[8] = u_npc.u_ID.GPR.\rf[10][8] ;
    assign rf_11[9] = u_npc.u_ID.GPR.\rf[10][9] ;
    assign rf_11[10] = u_npc.u_ID.GPR.\rf[10][10] ;
    assign rf_11[11] = u_npc.u_ID.GPR.\rf[10][11] ;
    assign rf_11[12] = u_npc.u_ID.GPR.\rf[10][12] ;
    assign rf_11[13] = u_npc.u_ID.GPR.\rf[10][13] ;
    assign rf_11[14] = u_npc.u_ID.GPR.\rf[10][14] ;
    assign rf_11[15] = u_npc.u_ID.GPR.\rf[10][15] ;
    assign rf_11[16] = u_npc.u_ID.GPR.\rf[10][16] ;
    assign rf_11[17] = u_npc.u_ID.GPR.\rf[10][17] ;
    assign rf_11[18] = u_npc.u_ID.GPR.\rf[10][18] ;
    assign rf_11[19] = u_npc.u_ID.GPR.\rf[10][19] ;
    assign rf_11[20] = u_npc.u_ID.GPR.\rf[10][20] ;
    assign rf_11[21] = u_npc.u_ID.GPR.\rf[10][21] ;
    assign rf_11[22] = u_npc.u_ID.GPR.\rf[10][22] ;
    assign rf_11[23] = u_npc.u_ID.GPR.\rf[10][23] ;
    assign rf_11[24] = u_npc.u_ID.GPR.\rf[10][24] ;
    assign rf_11[25] = u_npc.u_ID.GPR.\rf[10][25] ;
    assign rf_11[26] = u_npc.u_ID.GPR.\rf[10][26] ;
    assign rf_11[27] = u_npc.u_ID.GPR.\rf[10][27] ;
    assign rf_11[28] = u_npc.u_ID.GPR.\rf[10][28] ;
    assign rf_11[29] = u_npc.u_ID.GPR.\rf[10][29] ;
    assign rf_11[30] = u_npc.u_ID.GPR.\rf[10][30] ;
    assign rf_11[31] = u_npc.u_ID.GPR.\rf[10][31] ;

    // rf_12: Register 11
    assign rf_12[0] = u_npc.u_ID.GPR.\rf[11][0] ;
    assign rf_12[1] = u_npc.u_ID.GPR.\rf[11][1] ;
    assign rf_12[2] = u_npc.u_ID.GPR.\rf[11][2] ;
    assign rf_12[3] = u_npc.u_ID.GPR.\rf[11][3] ;
    assign rf_12[4] = u_npc.u_ID.GPR.\rf[11][4] ;
    assign rf_12[5] = u_npc.u_ID.GPR.\rf[11][5] ;
    assign rf_12[6] = u_npc.u_ID.GPR.\rf[11][6] ;
    assign rf_12[7] = u_npc.u_ID.GPR.\rf[11][7] ;
    assign rf_12[8] = u_npc.u_ID.GPR.\rf[11][8] ;
    assign rf_12[9] = u_npc.u_ID.GPR.\rf[11][9] ;
    assign rf_12[10] = u_npc.u_ID.GPR.\rf[11][10] ;
    assign rf_12[11] = u_npc.u_ID.GPR.\rf[11][11] ;
    assign rf_12[12] = u_npc.u_ID.GPR.\rf[11][12] ;
    assign rf_12[13] = u_npc.u_ID.GPR.\rf[11][13] ;
    assign rf_12[14] = u_npc.u_ID.GPR.\rf[11][14] ;
    assign rf_12[15] = u_npc.u_ID.GPR.\rf[11][15] ;
    assign rf_12[16] = u_npc.u_ID.GPR.\rf[11][16] ;
    assign rf_12[17] = u_npc.u_ID.GPR.\rf[11][17] ;
    assign rf_12[18] = u_npc.u_ID.GPR.\rf[11][18] ;
    assign rf_12[19] = u_npc.u_ID.GPR.\rf[11][19] ;
    assign rf_12[20] = u_npc.u_ID.GPR.\rf[11][20] ;
    assign rf_12[21] = u_npc.u_ID.GPR.\rf[11][21] ;
    assign rf_12[22] = u_npc.u_ID.GPR.\rf[11][22] ;
    assign rf_12[23] = u_npc.u_ID.GPR.\rf[11][23] ;
    assign rf_12[24] = u_npc.u_ID.GPR.\rf[11][24] ;
    assign rf_12[25] = u_npc.u_ID.GPR.\rf[11][25] ;
    assign rf_12[26] = u_npc.u_ID.GPR.\rf[11][26] ;
    assign rf_12[27] = u_npc.u_ID.GPR.\rf[11][27] ;
    assign rf_12[28] = u_npc.u_ID.GPR.\rf[11][28] ;
    assign rf_12[29] = u_npc.u_ID.GPR.\rf[11][29] ;
    assign rf_12[30] = u_npc.u_ID.GPR.\rf[11][30] ;
    assign rf_12[31] = u_npc.u_ID.GPR.\rf[11][31] ;

    // rf_13: Register 12
    assign rf_13[0] = u_npc.u_ID.GPR.\rf[12][0] ;
    assign rf_13[1] = u_npc.u_ID.GPR.\rf[12][1] ;
    assign rf_13[2] = u_npc.u_ID.GPR.\rf[12][2] ;
    assign rf_13[3] = u_npc.u_ID.GPR.\rf[12][3] ;
    assign rf_13[4] = u_npc.u_ID.GPR.\rf[12][4] ;
    assign rf_13[5] = u_npc.u_ID.GPR.\rf[12][5] ;
    assign rf_13[6] = u_npc.u_ID.GPR.\rf[12][6] ;
    assign rf_13[7] = u_npc.u_ID.GPR.\rf[12][7] ;
    assign rf_13[8] = u_npc.u_ID.GPR.\rf[12][8] ;
    assign rf_13[9] = u_npc.u_ID.GPR.\rf[12][9] ;
    assign rf_13[10] = u_npc.u_ID.GPR.\rf[12][10] ;
    assign rf_13[11] = u_npc.u_ID.GPR.\rf[12][11] ;
    assign rf_13[12] = u_npc.u_ID.GPR.\rf[12][12] ;
    assign rf_13[13] = u_npc.u_ID.GPR.\rf[12][13] ;
    assign rf_13[14] = u_npc.u_ID.GPR.\rf[12][14] ;
    assign rf_13[15] = u_npc.u_ID.GPR.\rf[12][15] ;
    assign rf_13[16] = u_npc.u_ID.GPR.\rf[12][16] ;
    assign rf_13[17] = u_npc.u_ID.GPR.\rf[12][17] ;
    assign rf_13[18] = u_npc.u_ID.GPR.\rf[12][18] ;
    assign rf_13[19] = u_npc.u_ID.GPR.\rf[12][19] ;
    assign rf_13[20] = u_npc.u_ID.GPR.\rf[12][20] ;
    assign rf_13[21] = u_npc.u_ID.GPR.\rf[12][21] ;
    assign rf_13[22] = u_npc.u_ID.GPR.\rf[12][22] ;
    assign rf_13[23] = u_npc.u_ID.GPR.\rf[12][23] ;
    assign rf_13[24] = u_npc.u_ID.GPR.\rf[12][24] ;
    assign rf_13[25] = u_npc.u_ID.GPR.\rf[12][25] ;
    assign rf_13[26] = u_npc.u_ID.GPR.\rf[12][26] ;
    assign rf_13[27] = u_npc.u_ID.GPR.\rf[12][27] ;
    assign rf_13[28] = u_npc.u_ID.GPR.\rf[12][28] ;
    assign rf_13[29] = u_npc.u_ID.GPR.\rf[12][29] ;
    assign rf_13[30] = u_npc.u_ID.GPR.\rf[12][30] ;
    assign rf_13[31] = u_npc.u_ID.GPR.\rf[12][31] ;

    // rf_14: Register 13
    assign rf_14[0] = u_npc.u_ID.GPR.\rf[13][0] ;
    assign rf_14[1] = u_npc.u_ID.GPR.\rf[13][1] ;
    assign rf_14[2] = u_npc.u_ID.GPR.\rf[13][2] ;
    assign rf_14[3] = u_npc.u_ID.GPR.\rf[13][3] ;
    assign rf_14[4] = u_npc.u_ID.GPR.\rf[13][4] ;
    assign rf_14[5] = u_npc.u_ID.GPR.\rf[13][5] ;
    assign rf_14[6] = u_npc.u_ID.GPR.\rf[13][6] ;
    assign rf_14[7] = u_npc.u_ID.GPR.\rf[13][7] ;
    assign rf_14[8] = u_npc.u_ID.GPR.\rf[13][8] ;
    assign rf_14[9] = u_npc.u_ID.GPR.\rf[13][9] ;
    assign rf_14[10] = u_npc.u_ID.GPR.\rf[13][10] ;
    assign rf_14[11] = u_npc.u_ID.GPR.\rf[13][11] ;
    assign rf_14[12] = u_npc.u_ID.GPR.\rf[13][12] ;
    assign rf_14[13] = u_npc.u_ID.GPR.\rf[13][13] ;
    assign rf_14[14] = u_npc.u_ID.GPR.\rf[13][14] ;
    assign rf_14[15] = u_npc.u_ID.GPR.\rf[13][15] ;
    assign rf_14[16] = u_npc.u_ID.GPR.\rf[13][16] ;
    assign rf_14[17] = u_npc.u_ID.GPR.\rf[13][17] ;
    assign rf_14[18] = u_npc.u_ID.GPR.\rf[13][18] ;
    assign rf_14[19] = u_npc.u_ID.GPR.\rf[13][19] ;
    assign rf_14[20] = u_npc.u_ID.GPR.\rf[13][20] ;
    assign rf_14[21] = u_npc.u_ID.GPR.\rf[13][21] ;
    assign rf_14[22] = u_npc.u_ID.GPR.\rf[13][22] ;
    assign rf_14[23] = u_npc.u_ID.GPR.\rf[13][23] ;
    assign rf_14[24] = u_npc.u_ID.GPR.\rf[13][24] ;
    assign rf_14[25] = u_npc.u_ID.GPR.\rf[13][25] ;
    assign rf_14[26] = u_npc.u_ID.GPR.\rf[13][26] ;
    assign rf_14[27] = u_npc.u_ID.GPR.\rf[13][27] ;
    assign rf_14[28] = u_npc.u_ID.GPR.\rf[13][28] ;
    assign rf_14[29] = u_npc.u_ID.GPR.\rf[13][29] ;
    assign rf_14[30] = u_npc.u_ID.GPR.\rf[13][30] ;
    assign rf_14[31] = u_npc.u_ID.GPR.\rf[13][31] ;

    // rf_15: Register 14
    assign rf_15[0] = u_npc.u_ID.GPR.\rf[14][0] ;
    assign rf_15[1] = u_npc.u_ID.GPR.\rf[14][1] ;
    assign rf_15[2] = u_npc.u_ID.GPR.\rf[14][2] ;
    assign rf_15[3] = u_npc.u_ID.GPR.\rf[14][3] ;
    assign rf_15[4] = u_npc.u_ID.GPR.\rf[14][4] ;
    assign rf_15[5] = u_npc.u_ID.GPR.\rf[14][5] ;
    assign rf_15[6] = u_npc.u_ID.GPR.\rf[14][6] ;
    assign rf_15[7] = u_npc.u_ID.GPR.\rf[14][7] ;
    assign rf_15[8] = u_npc.u_ID.GPR.\rf[14][8] ;
    assign rf_15[9] = u_npc.u_ID.GPR.\rf[14][9] ;
    assign rf_15[10] = u_npc.u_ID.GPR.\rf[14][10] ;
    assign rf_15[11] = u_npc.u_ID.GPR.\rf[14][11] ;
    assign rf_15[12] = u_npc.u_ID.GPR.\rf[14][12] ;
    assign rf_15[13] = u_npc.u_ID.GPR.\rf[14][13] ;
    assign rf_15[14] = u_npc.u_ID.GPR.\rf[14][14] ;
    assign rf_15[15] = u_npc.u_ID.GPR.\rf[14][15] ;
    assign rf_15[16] = u_npc.u_ID.GPR.\rf[14][16] ;
    assign rf_15[17] = u_npc.u_ID.GPR.\rf[14][17] ;
    assign rf_15[18] = u_npc.u_ID.GPR.\rf[14][18] ;
    assign rf_15[19] = u_npc.u_ID.GPR.\rf[14][19] ;
    assign rf_15[20] = u_npc.u_ID.GPR.\rf[14][20] ;
    assign rf_15[21] = u_npc.u_ID.GPR.\rf[14][21] ;
    assign rf_15[22] = u_npc.u_ID.GPR.\rf[14][22] ;
    assign rf_15[23] = u_npc.u_ID.GPR.\rf[14][23] ;
    assign rf_15[24] = u_npc.u_ID.GPR.\rf[14][24] ;
    assign rf_15[25] = u_npc.u_ID.GPR.\rf[14][25] ;
    assign rf_15[26] = u_npc.u_ID.GPR.\rf[14][26] ;
    assign rf_15[27] = u_npc.u_ID.GPR.\rf[14][27] ;
    assign rf_15[28] = u_npc.u_ID.GPR.\rf[14][28] ;
    assign rf_15[29] = u_npc.u_ID.GPR.\rf[14][29] ;
    assign rf_15[30] = u_npc.u_ID.GPR.\rf[14][30] ;
    assign rf_15[31] = u_npc.u_ID.GPR.\rf[14][31] ;
endmodule