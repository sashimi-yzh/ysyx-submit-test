`timescale 1ns/1ps
module axi_uart #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter STRB_WIDTH = 4,
    parameter ID_WIDTH    = 4,
    parameter BASE_ADDR   = 32'h1000_0000,
    parameter HIGH_ADDR   = 32'h1000_0FFF
) (
    input  wire                        aclk,
    input  wire                        aresetn,

    input  wire [ID_WIDTH-1:0]         awid,
    input  wire [ADDR_WIDTH-1:0]       awaddr,
    input  wire [7:0]                  awlen,
    input  wire [2:0]                  awsize,
    input  wire [1:0]                  awburst,
    input  wire                        awvalid,
    output wire                        awready,

    input  wire [DATA_WIDTH-1:0]       wdata,
    input  wire [STRB_WIDTH-1:0]       wstrb,
    input  wire                        wlast,
    input  wire                        wvalid,
    output wire                        wready,

    output wire [ID_WIDTH-1:0]         bid,
    output wire [1:0]                  bresp,
    output wire                        bvalid,
    input  wire                        bready,

    input  wire [ID_WIDTH-1:0]         arid,
    input  wire [ADDR_WIDTH-1:0]       araddr,
    input  wire [7:0]                  arlen,
    input  wire [2:0]                  arsize,
    input  wire [1:0]                  arburst,
    input  wire                        arvalid,
    output wire                        arready,

    output wire [ID_WIDTH-1:0]         rid,
    output wire [DATA_WIDTH-1:0]       rdata,
    output wire [1:0]                  rresp,
    output wire                        rlast,
    output wire                        rvalid,
    input  wire                        rready
);

    // 写通道
    reg                awready_r, wready_r;
    reg                bvalid_r;
    reg  [1:0]         bresp_r;
    reg  [ID_WIDTH-1:0] bid_r;
    reg  [7:0]         char_to_print;

    assign awready = awready_r;
    assign wready  = wready_r;
    assign bvalid  = bvalid_r;
    assign bresp   = bresp_r;
    assign bid     = bid_r;

    always @(posedge aclk) begin
        if (!aresetn) begin
            awready_r <= 1'b1;
            wready_r  <= 1'b1;
            bvalid_r  <= 1'b0;
            bid_r     <= {ID_WIDTH{1'b0}};
            bresp_r   <= 2'b00;
        end else begin
            if (awready_r && awvalid) begin
                awready_r <= 1'b0;
                bid_r     <= awid;  // 锁存 awid
            end

            if (wready_r && wvalid && wlast) begin
                wready_r <= 1'b0;
                char_to_print <= wdata[7:0];
            end

            if (!awready_r && !wready_r && !bvalid_r) begin
                bvalid_r <= 1'b1;
                bresp_r  <= 2'b00;
                $write("%c", char_to_print);
            end

            if (bvalid_r && bready) begin
                bvalid_r  <= 1'b0;
                awready_r <= 1'b1;
                wready_r  <= 1'b1;
            end
        end
    end

    // 读通道
    reg                arready_r, rvalid_r;
    reg  [1:0]         rresp_r;
    reg  [ID_WIDTH-1:0] rid_r;

    assign arready = arready_r;
    assign rdata   = 32'h0;
    assign rresp   = rresp_r;
    assign rid     = rid_r;
    assign rlast   = 1'b1;
    assign rvalid  = rvalid_r;

    always @(posedge aclk) begin
        if (!aresetn) begin
            arready_r <= 1'b1;
            rvalid_r  <= 1'b0;
            rid_r     <= {ID_WIDTH{1'b0}};
            rresp_r   <= 2'b00;
        end else begin
            if (arready_r && arvalid) begin
                arready_r <= 1'b0;
                rid_r     <= arid;  // 锁存 arid
            end

            if (!arready_r && !rvalid_r) begin
                rvalid_r <= 1'b1;
                rresp_r  <= 2'b00;
            end

            if (rvalid_r && rready) begin
                rvalid_r  <= 1'b0;
                arready_r <= 1'b1;
            end
        end
    end

endmodule