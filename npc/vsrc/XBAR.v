module XBAR(
    input clk,
    input reset,

    /* slave AXI full port */
    input  [3:0] s_axi_arid,
    input  [31:0] s_axi_araddr,
    input  [7:0]  s_axi_arlen,
    input  [2:0]  s_axi_arsize,
    input  [1:0]  s_axi_arburst,
    input         s_axi_arvalid,
    output        s_axi_arready,

    output [3:0] s_axi_rid,
    output [31:0] s_axi_rdata,
    output [1:0]  s_axi_rresp,
    output        s_axi_rlast,
    output        s_axi_rvalid,
    input         s_axi_rready,

    input  [3:0] s_axi_awid,
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

    output [3:0] s_axi_bid,
    output [1:0]  s_axi_bresp,
    output        s_axi_bvalid,
    input         s_axi_bready,

    /* master AXI full port A (0x0200_0000 ~ 0x0200_ffff) */
    output [3:0] m_axi_arid_A,
    output [31:0] m_axi_araddr_A,
    output [7:0]  m_axi_arlen_A,
    output [2:0]  m_axi_arsize_A,
    output [1:0]  m_axi_arburst_A,
    output        m_axi_arvalid_A,
    input         m_axi_arready_A,

    input  [3:0] m_axi_rid_A,
    input  [31:0] m_axi_rdata_A,
    input  [1:0]  m_axi_rresp_A,
    input         m_axi_rlast_A,
    input         m_axi_rvalid_A,
    output        m_axi_rready_A,

    output [3:0] m_axi_awid_A,
    output [31:0] m_axi_awaddr_A,
    output [7:0]  m_axi_awlen_A,
    output [2:0]  m_axi_awsize_A,
    output [1:0]  m_axi_awburst_A,
    output        m_axi_awvalid_A,
    input         m_axi_awready_A,

    output [31:0] m_axi_wdata_A,
    output [3:0]  m_axi_wstrb_A,
    output        m_axi_wlast_A,
    output        m_axi_wvalid_A,
    input         m_axi_wready_A,

    input  [3:0] m_axi_bid_A,
    input  [1:0]  m_axi_bresp_A,
    input         m_axi_bvalid_A,
    output        m_axi_bready_A,

    /* master AXI full port B*/
    output [3:0] m_axi_arid_B,
    output [31:0] m_axi_araddr_B,
    output [7:0]  m_axi_arlen_B,
    output [2:0]  m_axi_arsize_B,
    output [1:0]  m_axi_arburst_B,
    output        m_axi_arvalid_B,
    input         m_axi_arready_B,

    input  [3:0] m_axi_rid_B,
    input  [31:0] m_axi_rdata_B,
    input  [1:0]  m_axi_rresp_B,
    input         m_axi_rlast_B,
    input         m_axi_rvalid_B,
    output        m_axi_rready_B,

    output [3:0] m_axi_awid_B,
    output [31:0] m_axi_awaddr_B,
    output [7:0]  m_axi_awlen_B,
    output [2:0]  m_axi_awsize_B,
    output [1:0]  m_axi_awburst_B,
    output        m_axi_awvalid_B,
    input         m_axi_awready_B,

    output [31:0] m_axi_wdata_B,
    output [3:0]  m_axi_wstrb_B,
    output        m_axi_wlast_B,
    output        m_axi_wvalid_B,
    input         m_axi_wready_B,

    input  [3:0] m_axi_bid_B,
    input  [1:0]  m_axi_bresp_B,
    input         m_axi_bvalid_B,
    output        m_axi_bready_B
);

    // 0x0200_0000 ~ 0x0200_ffff -> port A (0), else -> port B (1)
    function addr_sel;
        input [31:0] addr;
        begin
            addr_sel = (addr >= 32'h0200_0000 && addr <= 32'h0200_ffff) ? 1'b0 : 1'b1;
        end
    endfunction

    /*Read Channel*/
    localparam READ_IDLE = 2'b00, READ_REQ = 2'b01, READ_WAIT = 2'b10;
    reg [1:0] r_state, r_next_state;
    reg r_sel;

    always @(*) begin
        case (r_state)
            READ_IDLE: r_next_state = (s_axi_arvalid && s_axi_arready) ? READ_REQ  : READ_IDLE;
            READ_REQ:  r_next_state = (r_sel == 1'b0 ? m_axi_arready_A : m_axi_arready_B) ? READ_WAIT : READ_REQ;
            READ_WAIT: r_next_state = (s_axi_rvalid && s_axi_rready && s_axi_rlast) ? READ_IDLE : READ_WAIT;
            default:   r_next_state = READ_IDLE;
        endcase
    end

    always @(posedge clk) begin
        if (reset) r_state <= READ_IDLE;
        else        r_state <= r_next_state;
    end

    assign s_axi_arready = (r_state == READ_IDLE);

    reg [3:0] r_id;
    reg [31:0] raddr;
    reg [7:0]  rlen;
    reg [2:0]  rsize;
    reg [1:0]  rburst;

    always @(posedge clk) begin
        if (reset) begin
            r_id   <= 4'b0;
            raddr  <= 32'b0;
            rlen   <= 8'b0;
            rsize  <= 3'b0;
            rburst <= 2'b0;
            r_sel  <= 1'b0;
        end else if (s_axi_arvalid && s_axi_arready) begin
            r_id   <= s_axi_arid;
            raddr  <= s_axi_araddr;
            rlen   <= s_axi_arlen;
            rsize  <= s_axi_arsize;
            rburst <= s_axi_arburst;
            r_sel  <= addr_sel(s_axi_araddr);
        end
    end

    assign m_axi_arid_A    = r_id;
    assign m_axi_araddr_A  = raddr;
    assign m_axi_arlen_A   = rlen;
    assign m_axi_arsize_A  = rsize;
    assign m_axi_arburst_A = rburst;
    assign m_axi_arvalid_A = (r_state == READ_REQ) && (r_sel == 1'b0);

    assign m_axi_arid_B    = r_id;
    assign m_axi_araddr_B  = raddr;
    assign m_axi_arlen_B   = rlen;
    assign m_axi_arsize_B  = rsize;
    assign m_axi_arburst_B = rburst;
    assign m_axi_arvalid_B = (r_state == READ_REQ) && (r_sel == 1'b1);

    assign m_axi_rready_A  = (r_state == READ_WAIT) && (r_sel == 1'b0) && s_axi_rready;
    assign m_axi_rready_B  = (r_state == READ_WAIT) && (r_sel == 1'b1) && s_axi_rready;

    assign s_axi_rid    = (r_state == READ_WAIT) ? (r_sel == 1'b0 ? m_axi_rid_A    : m_axi_rid_B)    : 4'b0;
    assign s_axi_rdata  = (r_state == READ_WAIT) ? (r_sel == 1'b0 ? m_axi_rdata_A  : m_axi_rdata_B)  : 32'b0;
    assign s_axi_rresp  = (r_state == READ_WAIT) ? (r_sel == 1'b0 ? m_axi_rresp_A  : m_axi_rresp_B)  : 2'b0;
    assign s_axi_rlast  = (r_state == READ_WAIT) ? (r_sel == 1'b0 ? m_axi_rlast_A  : m_axi_rlast_B)  : 1'b0;
    assign s_axi_rvalid = (r_state == READ_WAIT) ? (r_sel == 1'b0 ? m_axi_rvalid_A : m_axi_rvalid_B) : 1'b0;

    /*Write Channel*/
    localparam WRITE_IDLE      = 3'b000,
               WRITE_WAIT_ADDR = 3'b001,
               WRITE_WAIT_DATA = 3'b010,
               WRITE_REQ       = 3'b011,
               WRITE_REQ_ADDR  = 3'b100,
               WRITE_REQ_DATA  = 3'b101,
               WRITE_RESP      = 3'b110;
    reg [2:0] w_state, w_next_state;
    reg w_sel;

    always @(*) begin
        case (w_state)
            WRITE_IDLE: begin
                if (s_axi_awvalid && s_axi_awready && s_axi_wvalid && s_axi_wready)
                    w_next_state = WRITE_REQ;
                else if (s_axi_awvalid && s_axi_awready)
                    w_next_state = WRITE_WAIT_DATA;
                else if (s_axi_wvalid && s_axi_wready)
                    w_next_state = WRITE_WAIT_ADDR;
                else
                    w_next_state = WRITE_IDLE;
            end
            WRITE_WAIT_DATA: w_next_state = (s_axi_wvalid  && s_axi_wready)  ? WRITE_REQ : WRITE_WAIT_DATA;
            WRITE_WAIT_ADDR: w_next_state = (s_axi_awvalid && s_axi_awready) ? WRITE_REQ : WRITE_WAIT_ADDR;
            WRITE_REQ      : begin
                if (w_sel == 1'b0) begin
                    if (m_axi_awready_A && m_axi_wready_A && m_axi_awvalid_A && m_axi_wvalid_A)
                        w_next_state = WRITE_RESP;
                    else if (m_axi_awready_A && m_axi_awvalid_A)
                        w_next_state = WRITE_REQ_DATA;
                    else if (m_axi_wready_A && m_axi_wvalid_A)
                        w_next_state = WRITE_REQ_ADDR;
                    else
                        w_next_state = WRITE_REQ;
                end
                else begin
                    if (m_axi_awready_B && m_axi_wready_B && m_axi_awvalid_B && m_axi_wvalid_B)
                        w_next_state = WRITE_RESP;
                    else if (m_axi_awready_B && m_axi_awvalid_B)
                        w_next_state = WRITE_REQ_DATA;
                    else if (m_axi_wready_B && m_axi_wvalid_B)
                        w_next_state = WRITE_REQ_ADDR;
                    else
                        w_next_state = WRITE_REQ;
                end
            end
            WRITE_REQ_ADDR:  w_next_state = (w_sel == 1'b0 ? m_axi_awready_A : m_axi_awready_B) ? WRITE_REQ_DATA : WRITE_REQ_ADDR;
            WRITE_REQ_DATA:  w_next_state = (w_sel == 1'b0 ? m_axi_wready_A  : m_axi_wready_B)  ? WRITE_RESP     : WRITE_REQ_DATA;
            WRITE_RESP:      w_next_state = (s_axi_bvalid  && s_axi_bready)  ? WRITE_IDLE       : WRITE_RESP;
            default:         w_next_state = WRITE_IDLE;
        endcase
    end

    always @(posedge clk) begin
        if (reset) w_state <= WRITE_IDLE;
        else        w_state <= w_next_state;
    end

    assign s_axi_awready = (w_state == WRITE_IDLE || w_state == WRITE_WAIT_ADDR);
    assign s_axi_wready  = (w_state == WRITE_IDLE || w_state == WRITE_WAIT_DATA);

    reg [3:0] w_id;
    reg [31:0] waddr;
    reg [7:0]  wlen;
    reg [2:0]  wsize;
    reg [1:0]  wburst;
    reg [31:0] wdata;
    reg [3:0]  wstrb;
    reg        wlast;

    always @(posedge clk) begin
        if (reset) begin
            w_id   <= 4'b0;
            waddr  <= 32'b0;
            wlen   <= 8'b0;
            wsize  <= 3'b0;
            wburst <= 2'b0;
            w_sel  <= 1'b0;
        end else if (s_axi_awvalid && s_axi_awready) begin
            w_id   <= s_axi_awid;
            waddr  <= s_axi_awaddr;
            wlen   <= s_axi_awlen;
            wsize  <= s_axi_awsize;
            wburst <= s_axi_awburst;
            w_sel  <= addr_sel(s_axi_awaddr);
        end
    end

    always @(posedge clk) begin
        if (reset) begin
            wdata <= 32'b0;
            wstrb <= 4'b0;
            wlast <= 1'b0;
        end else if (s_axi_wvalid && s_axi_wready) begin
            wdata <= s_axi_wdata;
            wstrb <= s_axi_wstrb;
            wlast <= s_axi_wlast;
        end
    end

    assign m_axi_awid_A    = w_id;
    assign m_axi_awaddr_A  = waddr;
    assign m_axi_awlen_A   = wlen;
    assign m_axi_awsize_A  = wsize;
    assign m_axi_awburst_A = wburst;
    assign m_axi_awvalid_A = (w_state == WRITE_REQ_ADDR || w_state == WRITE_REQ) && (w_sel == 1'b0);
    assign m_axi_wdata_A   = wdata;
    assign m_axi_wstrb_A   = wstrb;
    assign m_axi_wlast_A   = wlast;
    assign m_axi_wvalid_A  = (w_state == WRITE_REQ_DATA || w_state == WRITE_REQ) && (w_sel == 1'b0);
    assign m_axi_bready_A  = (w_state == WRITE_RESP)     && (w_sel == 1'b0) && s_axi_bready;

    assign m_axi_awid_B    = w_id;
    assign m_axi_awaddr_B  = waddr;
    assign m_axi_awlen_B   = wlen;
    assign m_axi_awsize_B  = wsize;
    assign m_axi_awburst_B = wburst;
    assign m_axi_awvalid_B = (w_state == WRITE_REQ_ADDR || w_state == WRITE_REQ) && (w_sel == 1'b1);
    assign m_axi_wdata_B   = wdata;
    assign m_axi_wstrb_B   = wstrb;
    assign m_axi_wlast_B   = wlast;
    assign m_axi_wvalid_B  = (w_state == WRITE_REQ_DATA || w_state == WRITE_REQ) && (w_sel == 1'b1);
    assign m_axi_bready_B  = (w_state == WRITE_RESP)     && (w_sel == 1'b1) && s_axi_bready;

    assign s_axi_bid    = (w_state == WRITE_RESP) ? (w_sel == 1'b0 ? m_axi_bid_A    : m_axi_bid_B)    : 4'b0;
    assign s_axi_bresp  = (w_state == WRITE_RESP) ? (w_sel == 1'b0 ? m_axi_bresp_A  : m_axi_bresp_B)  : 2'b0;
    assign s_axi_bvalid = (w_state == WRITE_RESP) ? (w_sel == 1'b0 ? m_axi_bvalid_A : m_axi_bvalid_B) : 1'b0;

endmodule
