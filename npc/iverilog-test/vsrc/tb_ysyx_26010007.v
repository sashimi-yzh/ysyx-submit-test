`timescale 1ns/1ps
module tb_ysyx_26010007;

  reg clock;
  reg reset;
  // initial begin
  //   $dumpfile ("wave.vcd");
  //   $dumpvars (0, tb_ysyx_26010007);
  // end

  /* 复位信号 - 初始为高，一段时间后释放 */
  initial begin
    clock = 0;
    reset = 1;
    # 2000 reset = 0;
    // #15000 $stop;
  end

  /* 时钟生成 */
  always #5 clock = !clock;  // 100MHz时钟

  localparam ADDR_WIDTH = 32;
  localparam DATA_WIDTH = 32;
  localparam STRB_WIDTH = 4;

  // ===== AXI 总线信号（三态/多主需要仲裁，这里直接连接） =====
  wire [ADDR_WIDTH-1:0]       io_master_awaddr;
  wire [7:0]                  io_master_awlen;
  wire [2:0]                  io_master_awsize;
  wire [1:0]                  io_master_awburst;
  wire [3:0]                  io_master_awid;
  wire                        io_master_awvalid;
  wire                        io_master_awready;
  
  wire [DATA_WIDTH-1:0]       io_master_wdata;
  wire [STRB_WIDTH-1:0]       io_master_wstrb;
  wire                        io_master_wlast;
  wire                        io_master_wvalid;
  wire                        io_master_wready;
  
  wire [1:0]                  io_master_bresp;
  wire [3:0]                  io_master_bid;
  wire                        io_master_bvalid;
  wire                        io_master_bready;
  
  wire [ADDR_WIDTH-1:0]       io_master_araddr;
  wire [7:0]                  io_master_arlen;
  wire [2:0]                  io_master_arsize;
  wire [1:0]                  io_master_arburst;
  wire [3:0]                  io_master_arid;
  wire                        io_master_arvalid;
  wire                        io_master_arready;
  
  wire [DATA_WIDTH-1:0]       io_master_rdata;
  wire [1:0]                  io_master_rresp;
  wire [3:0]                  io_master_rid;
  wire                        io_master_rlast;
  wire                        io_master_rvalid;
  wire                        io_master_rready;

  // ===== 地址译码：根据地址选择 UART 或 MEM =====
  wire uart_sel = (io_master_awaddr >= 32'h1000_0000 && io_master_awaddr <= 32'h1000_0FFF) ||
                  (io_master_araddr >= 32'h1000_0000 && io_master_araddr <= 32'h1000_0FFF);
  
  wire mem_sel = (io_master_awaddr >= 32'h8000_0000 && io_master_awaddr <= 32'h8FFF_FFFF) ||
                 (io_master_araddr >= 32'h8000_0000 && io_master_araddr <= 32'h8FFF_FFFF);

  // ===== UART 从设备信号 =====
  wire                        uart_awready, uart_wready;
  wire [1:0]                  uart_bresp;
  wire                        uart_bvalid;
  wire [3:0]                  uart_bid;
  wire                        uart_arready;
  wire [DATA_WIDTH-1:0]       uart_rdata;
  wire [1:0]                  uart_rresp;
  wire                        uart_rlast;
  wire                        uart_rvalid;
  wire [3:0]                  uart_rid;

  // ===== MEM 从设备信号 =====
  wire                        mem_awready, mem_wready;
  wire [1:0]                  mem_bresp;
  wire                        mem_bvalid;
  wire [3:0]                  mem_bid;
  wire                        mem_arready;
  wire [DATA_WIDTH-1:0]       mem_rdata;
  wire [1:0]                  mem_rresp;
  wire                        mem_rlast;
  wire                        mem_rvalid;
  wire [3:0]                  mem_rid;
  wire flag;
  // ===== AXI 互连：根据地址选择从设备 =====
  assign io_master_awready = uart_sel ? uart_awready : (mem_sel ? mem_awready : 1'b0);
  assign io_master_wready  = uart_sel ? uart_wready  : (mem_sel ? mem_wready  : 1'b0);
  assign io_master_bresp   = uart_sel ? uart_bresp   : mem_bresp;
  assign io_master_bvalid  = uart_sel ? uart_bvalid  : mem_bvalid;
  assign io_master_bid     = uart_sel ? uart_bid     : mem_bid;
  assign io_master_arready = uart_sel ? uart_arready : (mem_sel ? mem_arready : 1'b0);
  assign io_master_rdata   = uart_sel ? uart_rdata   : mem_rdata;
  assign io_master_rresp   = uart_sel ? uart_rresp   : mem_rresp;
  assign io_master_rlast   = uart_sel ? uart_rlast   : mem_rlast;
  assign io_master_rvalid  = uart_sel ? uart_rvalid  : mem_rvalid;
  assign io_master_rid     = uart_sel ? uart_rid     : mem_rid;

  // ===== UART 实例化 =====
  axi_uart uart0 (
    .aclk    (clock),
    .aresetn (~reset),         // 注意：你的模块使用 aresetn (低有效)
    
    .awaddr  (io_master_awaddr),
    .awlen   (io_master_awlen),
    .awsize  (io_master_awsize),
    .awburst (io_master_awburst),
    .awvalid (io_master_awvalid && uart_sel),
    .awid    (io_master_awid),
    .awready (uart_awready),
    
    .wdata   (io_master_wdata),
    .wstrb   (io_master_wstrb),
    .wlast   (io_master_wlast),
    .wvalid  (io_master_wvalid && uart_sel),
    .wready  (uart_wready),
    
    .bresp   (uart_bresp),
    .bvalid  (uart_bvalid),
    .bid     (uart_bid),
    .bready  (io_master_bready),
    
    .araddr  (io_master_araddr),
    .arlen   (io_master_arlen),
    .arsize  (io_master_arsize),
    .arburst (io_master_arburst),
    .arvalid (io_master_arvalid && uart_sel),
    .arid    (io_master_arid),
    .arready (uart_arready),
    
    .rdata   (uart_rdata),
    .rresp   (uart_rresp),
    .rlast   (uart_rlast),
    .rvalid  (uart_rvalid),
    .rid     (uart_rid),
    .rready  (io_master_rready)
  );

  // ===== Memory 实例化 =====
  axi_mem memory (
    .aclk    (clock),
    .aresetn (~reset),         // 注意：使用 aresetn (低有效)
    
    .awaddr  (io_master_awaddr),
    .awlen   (io_master_awlen),
    .awsize  (io_master_awsize),
    .awburst (io_master_awburst),
    .awid    (io_master_awid),
    .awvalid (io_master_awvalid && mem_sel),
    .awready (mem_awready),
    
    .wdata   (io_master_wdata),
    .wstrb   (io_master_wstrb),
    .wlast   (io_master_wlast),
    .wvalid  (io_master_wvalid && mem_sel),
    .wready  (mem_wready),
    
    .bresp   (mem_bresp),
    .bvalid  (mem_bvalid),
    .bid     (mem_bid),
    .bready  (io_master_bready),
    
    .araddr  (io_master_araddr),
    .arlen   (io_master_arlen),
    .arsize  (io_master_arsize),
    .arburst (io_master_arburst),
    .arvalid (io_master_arvalid && mem_sel),
    .arid    (io_master_arid),
    .arready (mem_arready),
    
    .rdata   (mem_rdata),
    .rresp   (mem_rresp),
    .rlast   (mem_rlast),
    .rvalid  (mem_rvalid),
    .rid     (mem_rid),
    .rready  (io_master_rready)
  );

  // ===== RISC-V 处理器实例化 =====
  ysyx_26010007 DUT (
    .clock              (clock),
    .reset              (reset),
    .io_interrupt       (1'b0),  // 无中断
    
    // Master AXI 接口
    .io_master_awaddr   (io_master_awaddr),
    .io_master_awlen    (io_master_awlen),
    .io_master_awsize   (io_master_awsize),
    .io_master_awid     (io_master_awid),
    .io_master_awburst  (io_master_awburst),
    .io_master_awvalid  (io_master_awvalid),
    .io_master_awready  (io_master_awready),
    
    .io_master_wdata    (io_master_wdata),
    .io_master_wstrb    (io_master_wstrb),
    .io_master_wlast    (io_master_wlast),
    .io_master_wvalid   (io_master_wvalid),
    .io_master_wready   (io_master_wready),
    
    .io_master_bresp    (io_master_bresp),
    .io_master_bid      (io_master_bid),
    .io_master_bvalid   (io_master_bvalid),
    .io_master_bready   (io_master_bready),
    
    .io_master_araddr   (io_master_araddr),
    .io_master_arlen    (io_master_arlen),
    .io_master_arsize   (io_master_arsize),
    .io_master_arid     (io_master_arid),
    .io_master_arburst  (io_master_arburst),
    .io_master_arvalid  (io_master_arvalid),
    .io_master_arready  (io_master_arready),
    
    .io_master_rdata    (io_master_rdata),
    .io_master_rresp    (io_master_rresp),
    .io_master_rid      (io_master_rid),
    .io_master_rlast    (io_master_rlast),
    .io_master_rvalid   (io_master_rvalid),
    .io_master_rready   (io_master_rready),

    // Slave AXI 接口（未使用，置为无效）
    .io_slave_awvalid   (1'b0),
    .io_slave_awready   (),
    .io_slave_awaddr    (32'h0),
    .io_slave_awlen     (8'h0),
    .io_slave_awsize    (3'h0),
    .io_slave_awid      (4'h0),
    .io_slave_awburst   (2'h0),
    
    .io_slave_wvalid    (1'b0),
    .io_slave_wready    (),
    .io_slave_wdata     (32'h0),
    .io_slave_wstrb     (4'h0),
    .io_slave_wlast     (1'b0),
    
    .io_slave_bvalid    (),
    .io_slave_bready    (1'b0),
    .io_slave_bresp     (),
    .io_slave_bid       (),
    
    .io_slave_arvalid   (1'b0),
    .io_slave_arready   (),
    .io_slave_araddr    (32'h0),
    .io_slave_arlen     (8'h0),
    .io_slave_arsize    (3'h0),
    .io_slave_arid      (4'h0),
    .io_slave_arburst   (2'h0),
    
    .io_slave_rvalid    (),
    .io_slave_rready    (1'b0),
    .io_slave_rdata     (),
    .io_slave_rresp     (),
    .io_slave_rlast     (),
    .io_slave_rid       ()
  );

  // ysyx_26010007 DUT (
  //       .clock              (clock),
  //       .reset              (reset),
  //       .io_interrupt       (1'b0),
        
  //       // ====== 输入端口置0 ======
  //       .io_master_arready  (1'b0),
  //       .io_master_rvalid   (1'b0),
  //       .io_master_rdata    (32'b0),
  //       .io_master_rresp    (2'b0),
  //       .io_master_rlast    (1'b0),
  //       .io_master_rid      (4'b0),
  //       .io_master_awready  (1'b0),
  //       .io_master_wready   (1'b0),
  //       .io_master_bvalid   (1'b0),
  //       .io_master_bresp    (2'b0),
  //       .io_master_bid      (4'b0),
        
  //       .io_slave_arvalid   (1'b0),
  //       .io_slave_araddr    (32'b0),
  //       .io_slave_arlen     (8'b0),
  //       .io_slave_arsize    (3'b0),
  //       .io_slave_arid      (4'b0),
  //       .io_slave_arburst   (2'b0),
  //       .io_slave_rready    (1'b0),
  //       .io_slave_awvalid   (1'b0),
  //       .io_slave_awaddr    (32'b0),
  //       .io_slave_awlen     (8'b0),
  //       .io_slave_awsize    (3'b0),
  //       .io_slave_awid      (4'b0),
  //       .io_slave_awburst   (2'b0),
  //       .io_slave_wvalid    (1'b0),
  //       .io_slave_wdata     (32'b0),
  //       .io_slave_wstrb     (4'b0),
  //       .io_slave_wlast     (1'b0),
  //       .io_slave_bready    (1'b0),
        
  //       // ====== 输出端口悬空（不连） ======
  //       .io_master_arvalid  (),
  //       .io_master_araddr   (),
  //       .io_master_arlen    (),
  //       .io_master_arsize   (),
  //       .io_master_arid     (),
  //       .io_master_arburst  (),
  //       .io_master_rready   (),
  //       .io_master_awvalid  (),
  //       .io_master_awaddr   (),
  //       .io_master_awlen    (),
  //       .io_master_awsize   (),
  //       .io_master_awid     (),
  //       .io_master_awburst  (),
  //       .io_master_wvalid   (),
  //       .io_master_wdata    (),
  //       .io_master_wstrb    (),
  //       .io_master_wlast    (),
  //       .io_master_bready   (),
        
  //       .io_slave_arready   (),
  //       .io_slave_rvalid    (),
  //       .io_slave_rdata     (),
  //       .io_slave_rresp     (),
  //       .io_slave_rlast     (),
  //       .io_slave_rid       (),
  //       .io_slave_awready   (),
  //       .io_slave_wready    (),
  //       .io_slave_bvalid    (),
  //       .io_slave_bresp     (),
  //       .io_slave_bid       ()
  //   );
endmodule