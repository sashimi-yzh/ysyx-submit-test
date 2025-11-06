module ysyx_24100006_net_testbench;
    reg clock;
    reg reset;
    

    // 时钟
    always #5 clock = ~clock;  // 100MHz

    // 复位（对齐若干个上升沿）
    initial begin
        clock = 0;
		reset = 1;
        #25 reset = 0;
    end

    // 在 initial 块中添加超时检测
    // initial 
    // begin
    //     // 超时监控进程
    //     #1000000000; // 根据实际情况调整超时时间（例如10秒）
    //     $display("ERROR: Simulation timeout at time %t", $time);
    //     $finish(2);
    // end

    // 波形
    // initial begin
    //     $dumpfile("wave_net.vcd");
    //     $dumpvars(0, ysyx_24100006_net_testbench);
    // end


    // 监控
    initial begin
        $display("Starting simulation at time %t", $time);
        @(negedge reset);
        $display("Reset released at time %t", $time);
        $display("Running in compatibility mode");
    end

    always @(posedge clock) begin
        if (!reset && u_npc.is_break_M && u_npc.mem_in_valid) begin
            $display();
            $display("==========================================");
            $display("Test completed");
            $display("==========================================");
            #100 $finish;
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
        .axi_araddr({4'b0, u_mem_axi_araddr[27:0]}),
        .axi_awaddr({4'b0, u_mem_axi_awaddr[27:0]}),
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

endmodule