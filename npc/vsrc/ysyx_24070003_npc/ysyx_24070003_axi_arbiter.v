module ysyx_24070003_axi_arbiter #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input clock,
    input rstn,
    
    // IFU 接口 (指令获取)
    input  [ADDR_WIDTH-1:0] ifu_araddr,
    input                   ifu_arvalid,
    output                  ifu_arready,
    
    output [DATA_WIDTH-1:0] ifu_rdata,
    output                  ifu_rvalid,
    input                   ifu_rready,
    
    // LSU 接口 (加载/存储)
    input  [ADDR_WIDTH-1:0] lsu_araddr,
    input                   lsu_arvalid,
    output                  lsu_arready,
    
    output [DATA_WIDTH-1:0] lsu_rdata,
    output                  lsu_rvalid,
    input                   lsu_rready,
    
    input  [ADDR_WIDTH-1:0] lsu_awaddr,
    input                   lsu_awvalid,
    output                  lsu_awready,
    
    input  [DATA_WIDTH-1:0] lsu_wdata,
    input  [3:0]            lsu_wstrb,
    input                   lsu_wvalid,
    output                  lsu_wready,
    
    //output [1:0]            lsu_bresp,
    output                  lsu_bvalid,
    input                   lsu_bready,
    input   [2:0]          lsu_arsize,
    
    // SRAM 从设备接口
    output [ADDR_WIDTH-1:0] master_araddr,
    output                  master_arvalid,
    input                   master_arready,
    
    input  [DATA_WIDTH-1:0] master_rdata,
    input                   master_rvalid,
    output                  master_rready,
    
    output [ADDR_WIDTH-1:0] master_awaddr,
    output                  master_awvalid,
    input                   master_awready,
    
    output [DATA_WIDTH-1:0] master_wdata,
    output [3:0]            master_wstrb,
    output                  master_wvalid,
    input                   master_wready,
    
    //input  [1:0]            sram_bresp,
    input                   master_bvalid,
    output                  master_bready,

    input   [7:0]           ICACHE_AXI4_arlen,
    output  [7:0]           master_arlen,
    input                   master_rlast,
    output  [2:0]           master_arsize
);

// 仲裁状态定义
// typedef enum logic [2:0] {
//     IDLE,
//     IFU_READ_START,
//     IFU_READ_WAIT,
//     LSU_READ_START,
//     LSU_READ_WAIT,
//     LSU_WRITE_START,
//     LSU_WRITE_DATA,
//     LSU_WRITE_RESP
// } arb_state_t;

// arb_state_t state;

parameter  IDLE = 0,
            IFU_READ_START = 1,
            IFU_READ_WAIT = 2,
            LSU_READ_START = 3,
            LSU_READ_WAIT = 4,
            LSU_WRITE_START = 5,
            LSU_WRITE_DATA = 6,
            LSU_WRITE_RESP = 7;
reg [2:0] state;
// 仲裁优先级参数

// 内部信号
reg [ADDR_WIDTH-1:0] saved_araddr;
//reg [ADDR_WIDTH-1:0] saved_awaddr;
//reg [DATA_WIDTH-1:0] saved_wdata;
//reg [3:0]            saved_wstrb;

wire clint = (lsu_araddr >= 32'h02000000 && lsu_araddr <= 32'h0200ffff);
// 状态机
always @(posedge clock ) begin
    if (rstn) begin
        state <= IDLE;
        saved_araddr <= '0;
        //saved_awaddr <= '0;
        //saved_wdata <= '0;
        //saved_wstrb <= '0;
    end else begin
        case (state)
            IDLE: begin
                // 优先级处理：IFU读请求优先
                if (lsu_arvalid && !clint) begin
                    saved_araddr <= lsu_araddr;
                    state <= LSU_READ_START;
                end
                else if (ifu_arvalid) begin
                    saved_araddr <= ifu_araddr;
                    state <= IFU_READ_START;
                end
                // LSU写请求
                else if (lsu_awvalid && lsu_wvalid) begin
                    //saved_awaddr <= lsu_awaddr;
                    //saved_wdata <= lsu_wdata;
                    //saved_wstrb <= lsu_wstrb;
                    state <= LSU_WRITE_START;
                end
            end
            
            // IFU读操作
            IFU_READ_START: begin
                if (master_arready) begin
                    state <= IFU_READ_WAIT;
                end
            end
            
            IFU_READ_WAIT: begin
                if (master_rvalid && master_rready && master_rlast) begin
                    state <= IDLE;
                end
            end
            
            // LSU读操作
            LSU_READ_START: begin
                if (master_arready) begin
                    state <= LSU_READ_WAIT;
                end
            end
            
            LSU_READ_WAIT: begin
                if (master_rvalid && master_rready) begin
                    state <= IDLE;
                end
            end
            
            // LSU写操作
            LSU_WRITE_START: begin
                if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
                else if (master_awready && master_wready) begin
                    state <= LSU_WRITE_RESP;
                end
                else if (master_awready) begin
                    state <= LSU_WRITE_DATA;
                end
            end
            
            LSU_WRITE_DATA: begin
                
                if (master_wready) begin
                    state <= LSU_WRITE_RESP;
                end
                else if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
            end
            
            LSU_WRITE_RESP: begin
                if (master_bvalid && master_bready) begin
                    state <= IDLE;
                end
            end
            
            default: state <= IDLE;
        endcase
    end
end

// 读地址通道仲裁
assign master_araddr = saved_araddr;/*(state == IFU_READ_START || state == IFU_READ_WAIT) ? saved_araddr :
                     (state == LSU_READ_START || state == LSU_READ_WAIT) ? saved_araddr : '0;*/
assign master_arlen = (state == IFU_READ_START || state == IFU_READ_WAIT) ? ICACHE_AXI4_arlen : 8'b0;
assign master_arvalid = (state == IFU_READ_START || state == LSU_READ_START) ? 1'b1 : 1'b0;
assign master_arsize = (state == LSU_READ_START || state == LSU_READ_WAIT) ? lsu_arsize : 3'b10;

assign ifu_arready = (state == IFU_READ_START) ? master_arready : 1'b0;
assign lsu_arready = (state == LSU_READ_START) ? master_arready : 1'b0;

// 读数据通道仲裁
assign ifu_rdata = master_rdata;
assign lsu_rdata = master_rdata;

assign ifu_rvalid = (state == IFU_READ_WAIT || state == IFU_READ_WAIT) ? master_rvalid : 1'b0;
assign lsu_rvalid = (state == LSU_READ_WAIT) ? master_rvalid : 1'b0;

assign master_rready = (state == IFU_READ_WAIT) ? ifu_rready :
                     (state == LSU_READ_WAIT) ? lsu_rready : 1'b0;

// 写地址通道仲裁 (仅LSU)
assign master_awaddr = lsu_awaddr;
assign master_awvalid = lsu_awvalid;
assign lsu_awready = master_awready;

// 写数据通道仲裁 (仅LSU)
assign master_wdata = lsu_wdata;
assign master_wstrb = lsu_wstrb;
assign master_wvalid = lsu_wvalid;
assign lsu_wready =  master_wready ;

// 写响应通道仲裁 (仅LSU)
//assign lsu_bresp = sram_bresp;
assign lsu_bvalid =master_bvalid ;
assign master_bready = lsu_bready ;

endmodule
