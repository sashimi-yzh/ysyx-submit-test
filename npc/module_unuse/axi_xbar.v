module axi_xbar #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter NUM_MASTERS = 1,
    parameter NUM_SLAVES = 3,
    // 从设备地址配置
    parameter [(NUM_SLAVES*ADDR_WIDTH)-1:0] SLAVE_BASE = {32'h80000000, 32'ha00003f8, 32'ha0000048},
    parameter [(NUM_SLAVES*ADDR_WIDTH)-1:0] SLAVE_MASK = {32'hF8000000, 32'hFFFFFFF8, 32'hFFFFFFF8}
)(
    //input clk,
    //input rstn,
    
    // 主设备接口 (从IFU和LSU来)
    input  [NUM_MASTERS*ADDR_WIDTH-1:0] m_araddr,
    input  [NUM_MASTERS-1:0]            m_arvalid,
    output [NUM_MASTERS-1:0]            m_arready,
    
    output [NUM_MASTERS*DATA_WIDTH-1:0] m_rdata,
    output [NUM_MASTERS-1:0]            m_rvalid,
    input  [NUM_MASTERS-1:0]            m_rready,
    
    input  [NUM_MASTERS*ADDR_WIDTH-1:0] m_awaddr,
    input  [NUM_MASTERS-1:0]            m_awvalid,
    output [NUM_MASTERS-1:0]            m_awready,
    
    input  [NUM_MASTERS*DATA_WIDTH-1:0] m_wdata,
    input  [NUM_MASTERS*4-1:0]          m_wstrb,
    input  [NUM_MASTERS-1:0]            m_wvalid,
    output [NUM_MASTERS-1:0]            m_wready,
    
    //output [NUM_MASTERS*2-1:0]          m_bresp,
    output [NUM_MASTERS-1:0]            m_bvalid,
    input  [NUM_MASTERS-1:0]            m_bready,
    
    // 从设备接口 (到UART、SRAM等设备去)
    output [NUM_SLAVES*ADDR_WIDTH-1:0]  s_araddr,
    output [NUM_SLAVES-1:0]             s_arvalid,
    input  [NUM_SLAVES-1:0]             s_arready,
    
    input  [NUM_SLAVES*DATA_WIDTH-1:0]  s_rdata,
    input  [NUM_SLAVES-1:0]             s_rvalid,
    output [NUM_SLAVES-1:0]             s_rready,
    
    output [NUM_SLAVES*ADDR_WIDTH-1:0]  s_awaddr,
    output [NUM_SLAVES-1:0]             s_awvalid,
    input  [NUM_SLAVES-1:0]             s_awready,
    
    output [NUM_SLAVES*DATA_WIDTH-1:0]  s_wdata,
    output [NUM_SLAVES*4-1:0]           s_wstrb,
    output [NUM_SLAVES-1:0]             s_wvalid,
    input  [NUM_SLAVES-1:0]             s_wready,
    
    //input  [NUM_SLAVES*2-1:0]           s_bresp,
    input  [NUM_SLAVES-1:0]             s_bvalid,
    output [NUM_SLAVES-1:0]             s_bready
);

// 主设备选择逻辑

//wire [ADDR_WIDTH-1:0] active_addr;



//assign active_addr = m_araddr| m_awaddr;//({32{m_arvalid}} & m_araddr) | ({32{ m_awvalid}} & m_awaddr);
wire[1:0]  active_slave_r, active_slave_w;
assign active_slave_r = (slave_select_r == 3'b100) ? 2'b10 : (slave_select_r == 3'b010) ? 2'b01: (slave_select_r == 3'b001) ? 2'b0:2'b0;
assign active_slave_w = (slave_select_w == 3'b100) ? 2'b10 : (slave_select_w == 3'b010) ? 2'b01: (slave_select_w == 3'b001) ? 2'b0:2'b0;

// 地址译码
wire [NUM_SLAVES-1:0] slave_select_r;
wire [NUM_SLAVES-1:0] slave_select_w;
wire addr_error_r, addr_error_w;

addr_decoder #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .NUM_SLAVES(NUM_SLAVES),
    .BASE_ADDR(SLAVE_BASE),
    .ADDR_MASK(SLAVE_MASK)
) u_decoder1 (
    .addr(m_araddr),
    .slave_select(slave_select_r),
    .error(addr_error_r)
);

addr_decoder #(
    .ADDR_WIDTH(ADDR_WIDTH),
    .NUM_SLAVES(NUM_SLAVES),
    .BASE_ADDR(SLAVE_BASE),
    .ADDR_MASK(SLAVE_MASK)
) u_decoder2 (
    .addr(m_awaddr),
    .slave_select(slave_select_w),
    .error(addr_error_w)
);
// 读通道转发
generate
    genvar j;
    
    for (j = 0; j < NUM_SLAVES; j = j + 1) begin : slave_ports
        assign s_araddr[j*ADDR_WIDTH +: ADDR_WIDTH] = m_araddr;
        assign s_arvalid[j] = (slave_select_r[j]) && m_arvalid;
        assign s_rready[j] = m_rready && (slave_select_r[j]);
        assign s_awaddr[j*ADDR_WIDTH +: ADDR_WIDTH] = m_awaddr;
        assign s_awvalid[j] = (slave_select_w[j]) && m_awvalid;
        assign s_wdata[j*DATA_WIDTH +: DATA_WIDTH] = m_wdata;
        assign s_wstrb[j*4 +: 4] = m_wstrb;
        assign s_wvalid[j] = (slave_select_w[j]) && m_wvalid;
        assign s_bready[j] = m_bready && (slave_select_w[j]) && !(addr_error_r || addr_error_w);
    end
endgenerate

assign m_arready = s_arready[active_slave_r];
assign m_rdata = s_rdata[active_slave_r*DATA_WIDTH +: DATA_WIDTH];;
assign m_rvalid = s_rvalid[active_slave_r] ;
// 写通道转发 (类似读通道)
// ...

assign m_bvalid = s_bvalid[active_slave_w];
assign m_wready = s_wready[active_slave_w];
assign m_awready = s_awready[active_slave_w];



endmodule
