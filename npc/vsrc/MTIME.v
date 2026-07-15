`ifndef SYNTHESIS
    import PKG::mtime_read;
`endif

module MTIME(
    input clk,
    input reset,

    input  [3:0]  s_axi_arid,
    input  [31:0] s_axi_araddr,
    input  [7:0]  s_axi_arlen,
    input  [2:0]  s_axi_arsize,
    input  [1:0]  s_axi_arburst,
    input         s_axi_arvalid,
    output        s_axi_arready,

    output [3:0] s_axi_rid,
    output reg [31:0] s_axi_rdata,
    output [1:0]  s_axi_rresp,
    output        s_axi_rlast,
    output        s_axi_rvalid,
    input         s_axi_rready,

    input  [3:0]  s_axi_awid,
    input  [31:0] s_axi_awaddr,
    input  [7:0]  s_axi_awlen,
    input  [2:0]  s_axi_awsize,
    input  [1:0]  s_axi_awburst,
    input         s_axi_awvalid,
    output        s_axi_awready,

    input  [31:0] s_axi_wdata,
    input  [3:0]  s_axi_wstrb,
    input         s_axi_wlast,
    input         s_axi_wvalid,
    output        s_axi_wready,

    output [3:0]  s_axi_bid,
    output [1:0]  s_axi_bresp,
    output        s_axi_bvalid,
    input         s_axi_bready
);

    /*write port unused*/
    assign s_axi_awready = 1'b0;
    assign s_axi_wready  = 1'b0;
    assign s_axi_bresp   = 2'b00;
    assign s_axi_bvalid  = 1'b0;

    localparam IDLE = 2'd0, RESP = 2'd1;
    reg [1:0] state, next_state;

    always @(*) begin
        case(state)
            IDLE: begin
                if (s_axi_arvalid && s_axi_arready) begin
                    next_state = RESP;
                end else begin
                    next_state = IDLE;
                end
            end
            RESP: begin
                if (s_axi_rready && s_axi_rvalid) begin
                    next_state = IDLE;
                end else begin
                    next_state = RESP;
                end
            end
            default: begin
                next_state = IDLE;
            end
        endcase
    end

    always @(posedge clk) begin
        if (reset) begin
            state <= IDLE;
        end else begin
            state <= next_state;
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            s_axi_rdata <= 32'b0;
        end
        else if (s_axi_arready && s_axi_arvalid) begin
            `ifndef SYNTHESIS
                s_axi_rdata <= mtime_read(s_axi_araddr);
            `else
                s_axi_rdata <= 32'b0; // During synthesis, we cannot call DPI function, so we return 0
            `endif
        end
    end

    assign s_axi_arready = (state == IDLE);
    assign s_axi_rvalid  = (state == RESP);
    assign s_axi_rresp   = 2'b00;
    assign s_axi_rlast   = 1'b1;
    assign s_axi_rid     = 4'b0;
    assign s_axi_bid     = 4'b0;

endmodule
