
module ysyx_25020042_clint(
    input clock,
    input reset,

    /* verilator lint_off UNUSEDSIGNAL */
    input  [31:0] slave_araddr,
    input         slave_arvalid,
    output        slave_arready,
    input  [3:0]  slave_arid,
    input  [7:0]  slave_arlen,
    input  [2:0]  slave_arsize,
    input  [1:0]  slave_arburst,

    output [31:0] slave_rdata,
    output        slave_rvalid,
    output [1:0]  slave_rresp,
    input         slave_rready,
    output        slave_rlast,
    output [3:0]  slave_rid,

    input  [31:0] slave_awaddr,
    input         slave_awvalid,
    output        slave_awready,
    input  [3:0]  slave_awid,
    input  [7:0]  slave_awlen,
    input  [2:0]  slave_awsize,
    input  [1:0]  slave_awburst,

    input  [31:0] slave_wdata,
    input  [3:0]  slave_wstrb,
    input         slave_wvalid,
    output        slave_wready,
    input         slave_wlast,

    output        slave_bvalid,
    input         slave_bready,
    output [1:0]  slave_bresp,
    output [3:0]  slave_bid
    /* verilator lint_on UNUSEDSIGNAL */
);

    // 33 位计数器：{mtimeh, mtime} 整体进位，省掉 32 输入 AND
    reg [63:0] mtime_cnt;

    always @(posedge clock) begin
        if (reset)
            mtime_cnt <= 64'b0;
        else
            mtime_cnt <= mtime_cnt + 1'b1;
    end

    wire [31:0] mtime  = mtime_cnt[31:0];
    wire [31:0] mtimeh = mtime_cnt[63:32];

    // 读握手
    reg rvalid;
    assign slave_arready = ~rvalid;

    always @(posedge clock) begin
        if (reset)
            rvalid <= 1'b0;
        else if (slave_arvalid && slave_arready)
            rvalid <= 1'b1;
        else if (rvalid && slave_rready)
            rvalid <= 1'b0;
    end

    assign slave_rvalid = rvalid;
    assign slave_rlast  = rvalid;
    assign slave_rresp  = 2'b00;
    assign slave_rid    = slave_arid;

    assign slave_rdata = (slave_araddr == 32'h0200_0000) ? mtime  :
                         (slave_araddr == 32'h0200_0004) ? mtimeh :
                         32'b0;

    // 写通道：不实现
    assign slave_awready = 1'b0;
    assign slave_wready  = 1'b0;
    assign slave_bvalid  = 1'b0;
    assign slave_bresp   = 2'b00;
    assign slave_bid     = 4'b00;

endmodule
