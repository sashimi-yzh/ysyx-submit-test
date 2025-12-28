`timescale 1ns/1ps

module tb_ysyx_24070003 ();

//----------------------------------------------------------------------
// 时钟 / 复位
//----------------------------------------------------------------------
reg clock = 0;
always #5 clock = !clock;

reg reset = 0;
initial begin
     # 100 reset = 1;
     # 10 reset = 0;
     
end

//----------------------------------------------------------------------
// 中断（不用）
//----------------------------------------------------------------------
assign io_interrupt = 0;

//----------------------------------------------------------------------
// SoC 顶层的 Slave 口 —— 全部 tie 0（本 tb 不访问）
//----------------------------------------------------------------------
localparam Z32 = 32'h0;
localparam Z4  = 4'h0;
localparam Z2  = 2'h0;

assign io_slave_awvalid = 0;
assign io_slave_awaddr  = Z32;
assign io_slave_awlen   = 0;
assign io_slave_awsize  = 0;
assign io_slave_awburst = 0;
assign io_slave_awid    = Z4;
assign io_slave_wvalid  = 0;
assign io_slave_wdata   = Z32;
assign io_slave_wstrb   = 0;
assign io_slave_wlast   = 0;
assign io_slave_arvalid = 0;
assign io_slave_araddr  = Z32;
assign io_slave_arlen   = 0;
assign io_slave_arsize  = 0;
assign io_slave_arburst = 0;
assign io_slave_arid    = Z4;
assign io_slave_rready  = 0;
assign io_slave_bready  = 0;

//----------------------------------------------------------------------
//  Master 口信号（连接到外部 ram）
//----------------------------------------------------------------------
wire        m_awready;
wire        m_awvalid;
wire [31:0] m_awaddr;
wire [3:0]  m_awid;
wire [7:0]  m_awlen;
wire [2:0]  m_awsize;
wire [1:0]  m_awburst;

wire        m_wready;
wire        m_wvalid;
wire [31:0] m_wdata;
wire [3:0]  m_wstrb;
wire        m_wlast;

wire        m_bready;
wire        m_bvalid;
wire [1:0]  m_bresp;
wire [3:0]  m_bid;

wire        m_arready;
wire        m_arvalid;
wire [31:0] m_araddr;
wire [3:0]  m_arid;
wire [7:0]  m_arlen;
wire [2:0]  m_arsize;
wire [1:0]  m_arburst;

wire        m_rready;
wire        m_rvalid;
wire [1:0]  m_rresp;
wire [31:0] m_rdata;
wire        m_rlast;
wire [3:0]  m_rid;

// 绑定到 SoC
assign io_master_awready = m_awready;
assign io_master_wready  = m_wready;
assign io_master_bresp   = m_bresp;
assign io_master_bvalid  = m_bvalid;
assign io_master_bid     = m_bid;
assign io_master_arready = m_arready;
assign io_master_rresp   = m_rresp;
assign io_master_rvalid  = m_rvalid;
assign io_master_rdata   = m_rdata;
assign io_master_rlast   = m_rlast;
assign io_master_rid     = m_rid;
wire [63:0] ifu_count;
//----------------------------------------------------------------------
//  实例化 SoC
//----------------------------------------------------------------------
ysyx_24070003 dut (
    .clock               (clock),
    .reset               (reset),
    .io_interrupt        (io_interrupt),
    // master
    .io_master_awready  (m_awready),
    .io_master_awvalid (m_awvalid),
    .io_master_awaddr  (m_awaddr),
    .io_master_awid    (m_awid),
    .io_master_awlen   (m_awlen),
    .io_master_awsize  (m_awsize),
    .io_master_awburst (m_awburst),
    .io_master_wready   (m_wready),
    .io_master_wvalid  (m_wvalid),
    .io_master_wdata   (m_wdata),
    .io_master_wstrb   (m_wstrb),
    .io_master_wlast   (m_wlast),
    .io_master_bready  (m_bready),
    .io_master_bvalid  (m_bvalid),
    .io_master_bresp   (m_bresp),
    .io_master_bid     (m_bid),
    .io_master_arready (m_arready),
    .io_master_arvalid (m_arvalid),
    .io_master_araddr  (m_araddr),
    .io_master_arid    (m_arid),
    .io_master_arlen   (m_arlen),
    .io_master_arsize  (m_arsize),
    .io_master_arburst (m_arburst),
    .io_master_rready  (m_rready),
    .io_master_rvalid  (m_rvalid),
    .io_master_rresp   (m_rresp),
    .io_master_rdata   (m_rdata),
    .io_master_rlast   (m_rlast),
    .io_master_rid     (m_rid),
    // slave
    .io_slave_awready  (io_slave_awready),
    .io_slave_awvalid (io_slave_awvalid),
    .io_slave_awaddr  (io_slave_awaddr),
    .io_slave_awlen   (io_slave_awlen),
    .io_slave_awsize  (io_slave_awsize),
    .io_slave_awburst (io_slave_awburst),
    .io_slave_awid    (io_slave_awid),
    .io_slave_wready   (io_slave_wready),
    .io_slave_wvalid  (io_slave_wvalid),
    .io_slave_wdata   (io_slave_wdata),
    .io_slave_wstrb   (io_slave_wstrb),
    .io_slave_wlast   (io_slave_wlast),
    .io_slave_bready    (io_slave_bready),
    .io_slave_bvalid   (io_slave_bvalid),
    .io_slave_bresp    (io_slave_bresp),
    .io_slave_bid      (io_slave_bid),
    .io_slave_arready  (io_slave_arready),
    .io_slave_arvalid (io_slave_arvalid),
    .io_slave_araddr  (io_slave_araddr),
    .io_slave_arlen   (io_slave_arlen),
    .io_slave_arsize  (io_slave_arsize),
    .io_slave_arburst (io_slave_arburst),
    .io_slave_arid    (io_slave_arid),
    .io_slave_rready   (io_slave_rready),
    .io_slave_rvalid   (io_slave_rvalid),
    .io_slave_rresp    (io_slave_rresp),
    .io_slave_rdata    (io_slave_rdata),
    .io_slave_rlast    (io_slave_rlast),
    .io_slave_rid      (io_slave_rid)
);
always @(posedge clock) begin
    if (dut.ebreak) begin
        if(dut.rf1.rf[9] == 1'b0) begin
        $display("\n=== EBREAK GOOD ===");
        end else begin
        $display("\n=== EBREAK BAD ===");
        
        end
        $stop;   // 立即停仿真
    end
    // else if(ifu_count >= 'd100000)begin
    //     $display("\n=== TIME OUT ===");
    //     $stop; 
    // end
end 
//----------------------------------------------------------------------
//  外部 ram
//----------------------------------------------------------------------
ram u_ram (
    .clk   (clock),
    .rst   (reset),
    // read
    .araddr  (m_araddr),
    .arlen   (m_arlen),
    .arsize  (m_arsize),
    .arburst (m_arburst),
    .arvalid (m_arvalid),
    .arready (m_arready),
    .rdata   (m_rdata),
    .rresp   (m_rresp),
    .rlast   (m_rlast),
    .rvalid  (m_rvalid),
    .rready  (m_rready),
    // write
    .awaddr  (m_awaddr),
    .awlen   (m_awlen),
    .awsize  (m_awsize),
    .awburst (m_awburst),
    .awvalid (m_awvalid),
    .awready (m_awready),
    .wdata   (m_wdata),
    .wstrb   (m_wstrb),
    .wlast   (m_wlast),
    .wvalid  (m_wvalid),
    .wready  (m_wready),
    .bresp   (m_bresp),
    .bvalid  (m_bvalid),
    .bready  (m_bready)
);


//----------------------------------------------------------------------
// 波形
//----------------------------------------------------------------------
// initial begin
//     $dumpfile("tb.vcd");
//     $dumpvars(0, tb_ysyx_24070003);
// end

endmodule