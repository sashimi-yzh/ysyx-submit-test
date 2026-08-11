module ysyx_26010028_axilit_arbiter(
    input clk,
    input rst,
    // IFU Master接口
    // IFU AR地址通道
    input  [31:0] ifu_araddr,
    input  [ 7:0] ifu_arlen,
    input  [ 1:0] ifu_arburst, 
    input         ifu_arvalid,
    output        ifu_arready,
    // IFU R指令通道
    output [31:0] ifu_rdata,
    output [ 1:0] ifu_rresp,
    output        ifu_rlast,
    output        ifu_rvalid,
    input         ifu_rready,
    // LSU Master接口
    // LSU AR地址通道
    input  [31:0] lsu_araddr,
    input  [ 2:0] lsu_arsize,
    input         lsu_arvalid,
    output        lsu_arready,
    // LSU R读返回通道
    output [31:0] lsu_rdata,
    output [ 1:0] lsu_rresp,
    output        lsu_rvalid,
    input         lsu_rready,
    // LSU AW地址通道
    input  [31:0] lsu_awaddr,
    input  [ 2:0] lsu_awsize,
    input         lsu_awvalid,
    output        lsu_awready,
    // LSU W写数据通道
    input  [31:0] lsu_wdata,
    input  [ 3:0] lsu_wstrb,
    input         lsu_wvalid,
    output        lsu_wready,
    // LSU B返回信号通道
    output [ 1:0] lsu_bresp,
    output        lsu_bvalid,
    input         lsu_bready,
    // NPC2SoC
    // axi AR地址通道
    output [31:0] axi_araddr,
    output [ 3:0] axi_arid,
    output [ 7:0] axi_arlen,
    output [ 1:0] axi_arburst,
    output [ 2:0] axi_arsize,
    output        axi_arvalid,
    input         axi_arready,
    // axi R读返回通道
    input  [31:0] axi_rdata,
    input  [ 3:0] axi_rid,
    input  [ 1:0] axi_rresp,
    input         axi_rlast,
    input         axi_rvalid,
    output        axi_rready,
    // axi AW地址通道
    output [31:0] axi_awaddr,
    output [ 3:0] axi_awid,
    output [ 7:0] axi_awlen,
    output [ 2:0] axi_awsize,
    output [ 1:0] axi_awburst,
    output        axi_awvalid,
    input         axi_awready,
    // axi W数据通道
    output [31:0] axi_wdata,
    output [ 3:0] axi_wstrb,
    output        axi_wlast,
    output        axi_wvalid,
    input         axi_wready,
    // axi B信号通道
    input  [ 1:0] axi_bresp,
    input         axi_bvalid,
    output        axi_bready
);

    localparam S_IDLE = 2'd0;
    localparam S_AR   = 2'd1;
    localparam S_R    = 2'd2;

    reg [1:0] states;
    reg       right_ifu;

    wire ifu_sel = ((states == S_IDLE) && ifu_arvalid) || ((states == S_AR) && right_ifu);
    wire lsu_sel = ((states == S_IDLE) && !ifu_arvalid && lsu_arvalid) || ((states == S_AR) && !right_ifu);
    wire ifu_data = (states == S_R) && right_ifu;
    wire lsu_data = (states == S_R) && (!right_ifu);

    wire ifu_ar_hs = ifu_sel && ifu_arvalid && axi_arready;
    wire lsu_ar_hs = lsu_sel && lsu_arvalid && axi_arready;
    wire ifu_r_hs = ifu_data && ifu_rready && axi_rvalid;
    wire lsu_r_hs = lsu_data && lsu_rready && axi_rvalid;

    assign ifu_arready = axi_arready && ifu_sel;

    assign ifu_rdata = axi_rdata;
    assign ifu_rresp = axi_rresp;
    assign ifu_rlast = axi_rlast;
    assign ifu_rvalid = ifu_data && axi_rvalid;

    assign lsu_arready = axi_arready && lsu_sel;

    assign lsu_rdata = axi_rdata;
    assign lsu_rresp = axi_rresp;
    assign lsu_rvalid = lsu_data && axi_rvalid;

    assign lsu_awready = axi_awready;

    assign lsu_wready = axi_wready;

    assign lsu_bresp = axi_bresp;
    assign lsu_bvalid = axi_bvalid;

    assign axi_araddr = ifu_sel ? ifu_araddr : lsu_araddr;
    assign axi_arid = 4'b0;
    assign axi_arlen = ifu_sel ? ifu_arlen : 8'b0;
    assign axi_arburst = ifu_sel ? ifu_arburst : 2'b0;
    assign axi_arsize = ifu_sel ? 3'b010 : lsu_arsize;
    assign axi_arvalid = ifu_sel ? ifu_arvalid : (lsu_arvalid && lsu_sel);

    assign axi_rready = right_ifu ? (ifu_data && ifu_rready) : (lsu_data && lsu_rready);

    assign axi_awaddr = lsu_awaddr;
    assign axi_awid = 4'b0;
    assign axi_awlen = 8'b0;
    assign axi_awsize = lsu_awsize;
    assign axi_awburst = 2'b0;
    assign axi_awvalid = lsu_awvalid;

    assign axi_wdata = lsu_wdata;
    assign axi_wstrb = lsu_wstrb;
    assign axi_wlast = 1'b1;
    assign axi_wvalid = lsu_wvalid;

    assign axi_bready = lsu_bready;

    always @(posedge clk)begin
        if(rst)begin
            states <= S_IDLE;
            right_ifu <= 1'b0;
        end else begin
            case(states)
                S_IDLE: begin
                    if (ifu_arvalid) begin
                        right_ifu <= 1'b1;
                        if (ifu_ar_hs) begin
                            states <= S_R;
                        end else begin
                            states <= S_AR;
                        end
                    end else if (lsu_arvalid) begin
                        right_ifu <= 1'b0;
                        if (lsu_ar_hs) begin
                            states <= S_R;
                        end else begin
                            states <= S_AR;
                        end
                    end else begin
                        states    <= S_IDLE;
                        right_ifu <= 1'b0;
                    end
                end
                S_AR:begin
                    if(ifu_ar_hs || lsu_ar_hs)begin
                        states <= S_R;
                    end
                end
                S_R:begin
                    if((ifu_r_hs && axi_rlast) || (lsu_r_hs && axi_rlast))begin
                        states <= S_IDLE;
                        right_ifu <= 1'b0;
                    end
                end
                default:begin
                    states <= S_IDLE;
                    right_ifu <= 1'b0;                    
                end
            endcase
        end
    end


// ignore unused AXI ID signals
wire _unused_ok = &{
    1'b0,
    axi_rid
};
endmodule
