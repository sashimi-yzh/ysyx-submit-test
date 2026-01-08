`timescale 1ns/1ps

module sim_top;
    // ==================== 时钟和复位 ====================
    reg clk = 0;
    reg rst = 0;
    
    // 100MHz 时钟
    always #5 clk = ~clk;
    
    // 复位控制
    initial begin
        rst = 1;
        #100 rst = 0;          // 100ns 后释放复位
        //#1000000000 $finish;       // 仿真 1s 后结束
    end
    
    // ==================== AXI4 主设备接口信号 ====================
    // 写地址通道
    wire        awready;
    wire        awvalid;
    wire [31:0] awaddr;
    wire [3:0]  awid;
    wire [7:0]  awlen;
    wire [2:0]  awsize;
    wire [1:0]  awburst;
    
    // 写数据通道
    wire        wready;
    wire        wvalid;
    wire [31:0] wdata;
    wire [3:0]  wstrb;
    wire        wlast;
    
    // 写响应通道
    wire        bready;
    wire        bvalid;
    wire [1:0]  bresp;
    wire [3:0]  bid;
    
    // 读地址通道
    wire        arready;
    wire        arvalid;
    wire [31:0] araddr;
    wire [3:0]  arid;
    wire [7:0]  arlen;
    wire [2:0]  arsize;
    wire [1:0]  arburst;
    
    // 读数据通道
    wire        rready;
    wire        rvalid;
    wire [1:0]  rresp;
    wire [31:0] rdata;
    wire        rlast;
    wire [3:0]  rid;

    wire        ebreak;
    wire [2:0]  slave_bid;
    
    // ==================== AXI4 存储器从设备 ====================
    // 简单的 AXI4 从设备（用于仿真）
    npc_pmem #(
        .ADDR_WIDTH(32),
        .DATA_WIDTH(32),
        .PMEM_SIZE(32'h08000000) 
    ) npc_pmem (
        .clk(clk),
        .rst(rst),
        
        // 写地址通道
        .awready(awready),
        .awvalid(awvalid),
        .awaddr(awaddr),
        .awid(awid),
        .awlen(awlen),
        .awsize(awsize),
        .awburst(awburst),
        
        // 写数据通道
        .wready(wready),
        .wvalid(wvalid),
        .wdata(wdata),
        .wstrb(wstrb),
        .wlast(wlast),
        
        // 写响应通道
        .bready(bready),
        .bvalid(bvalid),
        .bresp(bresp),
        .bid(bid),
        
        // 读地址通道
        .arready(arready),
        .arvalid(arvalid),
        .araddr(araddr),
        .arid(arid),
        .arlen(arlen),
        .arsize(arsize),
        .arburst(arburst),
        
        // 读数据通道
        .rready(rready),
        .rvalid(rvalid),
        .rresp(rresp),
        .rdata(rdata),
        .rid(rid),
        .rlast(rlast)
    );
    
    // ==================== 实例化 NPC 顶层模块 ====================
    ysyx_25080222 npc_cpu(
        // 时钟和复位
        .clock(clk),
        .reset(rst),  // 注意复位极性
        
        // AXI4 主设备接口
        // 写地址通道
        .io_master_awready(awready),
        .io_master_awvalid(awvalid),
        .io_master_awaddr(awaddr),
        .io_master_awid(awid),
        .io_master_awlen(awlen),
        .io_master_awsize(awsize),
        .io_master_awburst(awburst),
        
        // 写数据通道
        .io_master_wready(wready),
        .io_master_wvalid(wvalid),
        .io_master_wdata(wdata),
        .io_master_wstrb(wstrb),
        .io_master_wlast(wlast),
        
        // 写响应通道
        .io_master_bready(bready),
        .io_master_bvalid(bvalid),
        .io_master_bresp(bresp),
        .io_master_bid(bid),
        
        // 读地址通道
        .io_master_arready(arready),
        .io_master_arvalid(arvalid),
        .io_master_araddr(araddr),
        .io_master_arid(arid),
        .io_master_arlen(arlen),
        .io_master_arsize(arsize),
        .io_master_arburst(arburst),
        
        // 读数据通道
        .io_master_rready(rready),
        .io_master_rvalid(rvalid),
        .io_master_rresp(rresp),
        .io_master_rdata(rdata),
        .io_master_rid(rid),
        .io_master_rlast(rlast),

        .io_slave_bid({slave_bid, ebreak})  //ebreak指令执行结束
    );
    
    // ==================== 波形输出 ====================
    initial begin
        // $dumpfile("./wave.vcd");
        // $dumpvars(0, sim_top);            // 顶层所有信号
        // //可以分层级 dump 信号
        // $dumpvars(1, npc_cpu);           // NPC 内部信号
        // $dumpvars(1, npc_pmem);            // 存储器内部信号
    end
    

    integer cycle_count = 1;

    // ==================== 初始化日志 ====================
    initial begin
        #100;  // 等待一段时间
        $display("==================================");
        $display("Iverilog Simulation Started");
        $display("Time unit: 1ns");
        $display("Clock period: 10ns (100MHz)");
        $display("==================================");
    end

    always @(posedge clk) begin
        if (~rst) begin


    // ==================== 仿真监控 ====================            
            cycle_count <= cycle_count + 1;

            // $display("\nCycle: %8d, Time: %d ns", cycle_count, $time);
            // $display("[AXI4-WRITE] AW: valid=%d addr=0x%08x W: valid=%d addr=0x%08x", awvalid , awaddr, wvalid , wdata);
            // $display("[AXI4-READ]  AR: valid=%d addr=0x%08x, len=%d", arvalid , araddr, arlen);
            // $display("[AXI4-READ]  R: valid=%d data=0x%08x, last=%d", rvalid , rdata, rlast);

            



    // ==================== 仿真结束条件 ====================
            // 条件1：ebreak
            // if (ebreak) begin  
            //     $display("==================================");
            //     $display("Simulation timeout by ebreak after %d cycles", cycle_count);
            //     $display("==================================");
            //     $finish;
            // end

            // // 条件2：超时保护
            // if (cycle_count >= 20) begin  
            //     $display("==================================");
            //     $display("Simulation timeout after %d cycles", cycle_count);
            //     $display("==================================");
            //     $finish;
            // end
        end
    end
endmodule