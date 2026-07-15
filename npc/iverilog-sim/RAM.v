// AXI4 Full RAM — 32 MB
// Supports INCR burst transfers, byte-enable writes, and $readmemh initialisation.
// Port naming follows the AXI4 slave convention (s_axi_*).

// `define MTRACE

module RAM #(
    parameter MEM_FILE = "microbench-riscv32e-npc.hex"
)(
    input  wire        clk,
    input  wire        reset,

    // -----------------------------------------------------------------------
    // Read address channel (AR)
    // -----------------------------------------------------------------------
    input  wire [31:0] s_axi_araddr,
    input  wire        s_axi_arvalid,
    output wire        s_axi_arready,
    input  wire [3:0]  s_axi_arid,
    input  wire [7:0]  s_axi_arlen,
    input  wire [2:0]  s_axi_arsize,
    input  wire [1:0]  s_axi_arburst,

    // -----------------------------------------------------------------------
    // Read data channel (R)
    // -----------------------------------------------------------------------
    output wire [31:0] s_axi_rdata,
    output wire [1:0]  s_axi_rresp,
    output wire        s_axi_rvalid,
    input  wire        s_axi_rready,
    output wire [3:0]  s_axi_rid,
    output wire        s_axi_rlast,

    // -----------------------------------------------------------------------
    // Write address channel (AW)
    // -----------------------------------------------------------------------
    input  wire [31:0] s_axi_awaddr,
    input  wire        s_axi_awvalid,
    output wire        s_axi_awready,
    input  wire [3:0]  s_axi_awid,
    input  wire [7:0]  s_axi_awlen,
    input  wire [2:0]  s_axi_awsize,
    input  wire [1:0]  s_axi_awburst,

    // -----------------------------------------------------------------------
    // Write data channel (W)
    // -----------------------------------------------------------------------
    input  wire [31:0] s_axi_wdata,
    input  wire [3:0]  s_axi_wstrb,
    input  wire        s_axi_wvalid,
    output wire        s_axi_wready,
    input  wire        s_axi_wlast,

    // -----------------------------------------------------------------------
    // Write response channel (B)
    // -----------------------------------------------------------------------
    output wire [1:0]  s_axi_bresp,
    output wire        s_axi_bvalid,
    input  wire        s_axi_bready,
    output wire [3:0]  s_axi_bid
);

    // -----------------------------------------------------------------------
    // Memory array — 32 MB = 32 M × 8-bit bytes
    // -----------------------------------------------------------------------
    localparam BYTE_SIZE  = 32 * 1024 * 1024;   // 32 MB
    localparam BYTE_NUM   = BYTE_SIZE;          // 32 768 000 bytes
    localparam ADDR_BITS  = 25;                 // log2(BYTE_SIZE) = 25

    reg [7:0] mem [0:BYTE_NUM-1];

    initial begin
        $readmemh(MEM_FILE, mem);
    end

    // addr[ADDR_BITS-1:0] selects the byte within the 32-MB window,
    // automatically masking away the upper address bits (e.g. 0x8000_0000 base).

    // -----------------------------------------------------------------------
    // Read channel state machine
    // -----------------------------------------------------------------------
    localparam R_IDLE  = 1'b0;
    localparam R_BURST = 1'b1;

    reg        r_state;
    reg [31:0] r_addr;
    reg [7:0]  r_len;
    reg [7:0]  r_cnt;
    reg [2:0]  r_size;
    reg [3:0]  r_id;

    assign s_axi_arready = (r_state == R_IDLE);

    always @(posedge clk) begin
        if (reset) begin
            r_state <= R_IDLE;
            r_cnt   <= 8'd0;
            r_addr  <= 32'd0;
            r_len   <= 8'd0;
            r_size  <= 3'd0;
            r_id    <= 4'd0;
        end else begin
            case (r_state)
                R_IDLE: begin
                    if (s_axi_arvalid) begin
                        r_addr  <= s_axi_araddr;
                        r_len   <= s_axi_arlen;
                        r_size  <= s_axi_arsize;
                        r_id    <= s_axi_arid;
                        r_cnt   <= 8'd0;
                        r_state <= R_BURST;
                    end
                end

                R_BURST: begin
                    if (s_axi_rvalid && s_axi_rready) begin
`ifdef MTRACE
                            $display("[mtrace] rd addr=0x%08x data=0x%08x",
                                     r_addr,
                                     { mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 3],
                                       mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 2],
                                       mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 1],
                                       mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 0] });
`endif
                        if (r_cnt == r_len) begin
                            r_state <= R_IDLE;
                        end else begin
                            r_cnt  <= r_cnt + 8'd1;
                            r_addr <= r_addr + (32'd1 << r_size); // INCR
                        end
                    end
                end

                default: r_state <= R_IDLE;
            endcase
        end
    end

    assign s_axi_rvalid = (r_state == R_BURST);
    assign s_axi_rdata  = { mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 3],
                            mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 2],
                            mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 1],
                            mem[{r_addr[ADDR_BITS-1:2], 2'b00} + 0] };
    assign s_axi_rresp  = 2'b00;   // OKAY
    assign s_axi_rid    = r_id;
    assign s_axi_rlast  = (r_cnt == r_len);

    // -----------------------------------------------------------------------
    // Write channel state machine
    // -----------------------------------------------------------------------
    localparam W_IDLE  = 2'b00;
    localparam W_BURST = 2'b01;
    localparam W_RESP  = 2'b10;

    reg [1:0]  w_state;
    reg [31:0] w_addr;
    reg [7:0]  w_len;
    reg [7:0]  w_cnt;
    reg [2:0]  w_size;
    reg [3:0]  w_id;

    assign s_axi_awready = (w_state == W_IDLE);
    assign s_axi_wready  = (w_state == W_BURST);

    always @(posedge clk) begin
        if (reset) begin
            w_state <= W_IDLE;
            w_cnt   <= 8'd0;
            w_addr  <= 32'd0;
            w_len   <= 8'd0;
            w_size  <= 3'd0;
            w_id    <= 4'd0;
        end else begin
            case (w_state)
                W_IDLE: begin
                    if (s_axi_awvalid) begin
                        w_addr  <= s_axi_awaddr;
                        w_len   <= s_axi_awlen;
                        w_size  <= s_axi_awsize;
                        w_id    <= s_axi_awid;
                        w_cnt   <= 8'd0;
                        w_state <= W_BURST;
                    end
                end

                W_BURST: begin
                    if (s_axi_wvalid) begin
`ifdef MTRACE
                        $display("[mtrace] wr addr=0x%08x data=0x%08x strb=0x%x",
                                 w_addr, s_axi_wdata, s_axi_wstrb);
`endif
                        if(w_addr == 32'h1000_0000) begin
                            $write("%c", s_axi_wdata[7:0]);
                            $fflush();
                        end

                        else begin
                            // Byte-enable write
                            if (s_axi_wstrb[0]) mem[{w_addr[ADDR_BITS-1:2], 2'b00} + 0] <= s_axi_wdata[7:0];
                            if (s_axi_wstrb[1]) mem[{w_addr[ADDR_BITS-1:2], 2'b00} + 1] <= s_axi_wdata[15:8];
                            if (s_axi_wstrb[2]) mem[{w_addr[ADDR_BITS-1:2], 2'b00} + 2] <= s_axi_wdata[23:16];
                            if (s_axi_wstrb[3]) mem[{w_addr[ADDR_BITS-1:2], 2'b00} + 3] <= s_axi_wdata[31:24];
                        end

                        if (s_axi_wlast) begin
                            w_state <= W_RESP;
                        end
                        else begin
                            w_cnt  <= w_cnt + 8'd1;
                            w_addr <= w_addr + (32'd1 << w_size); // INCR
                        end
                    end
                end

                W_RESP: begin
                    if (s_axi_bready) begin
                        w_state <= W_IDLE;
                    end
                end

                default: w_state <= W_IDLE;
            endcase
        end
    end

    assign s_axi_bresp  = 2'b00;   // OKAY
    assign s_axi_bvalid = (w_state == W_RESP);
    assign s_axi_bid    = w_id;

endmodule
