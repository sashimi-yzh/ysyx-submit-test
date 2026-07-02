module top
(
    input             clock,
    input             reset
);

    // Shared MEM AXI4
    wire [31:0] axi_araddr;
    wire [ 3:0] axi_arid;
    wire [ 7:0] axi_arlen;
    wire [ 2:0] axi_arsize;
    wire [ 1:0] axi_arburst;
    wire        axi_arvalid;
    reg         axi_arready;
    reg  [31:0] axi_rdata;
    reg  [ 3:0] axi_rid;
    reg  [ 1:0] axi_rresp;
    reg         axi_rlast;
    reg         axi_rvalid;
    wire        axi_rready;
    wire [31:0] axi_awaddr;
    wire [ 3:0] axi_awid;
    wire [ 7:0] axi_awlen;
    wire [ 2:0] axi_awsize;
    wire [ 1:0] axi_awburst;
    wire        axi_awvalid;
    reg         axi_awready;
    wire [31:0] axi_wdata;
    wire [ 3:0] axi_wstrb;
    wire        axi_wlast;
    wire        axi_wvalid;
    reg         axi_wready;
    reg  [ 3:0] axi_bid;
    reg  [ 1:0] axi_bresp;
    reg         axi_bvalid;
    wire        axi_bready;

`ifdef __ICARUS__
    ysyx_26030082 Core_cpu (
`else
    ysyx_26030082 #(
        .RESET_PC             (32'h8000_0000)
    ) Core_cpu (
`endif
        .clock                (clock),
        .reset                (reset),
        .io_interrupt         (1'b0),

        .io_master_araddr     (axi_araddr),
        .io_master_arid       (axi_arid),
        .io_master_arlen      (axi_arlen),
        .io_master_arsize     (axi_arsize),
        .io_master_arburst    (axi_arburst),
        .io_master_arvalid    (axi_arvalid),
        .io_master_arready    (axi_arready),
        .io_master_rdata      (axi_rdata),
        .io_master_rid        (axi_rid),
        .io_master_rresp      (axi_rresp),
        .io_master_rlast      (axi_rlast),
        .io_master_rvalid     (axi_rvalid),
        .io_master_rready     (axi_rready),
        .io_master_awaddr     (axi_awaddr),
        .io_master_awid       (axi_awid),
        .io_master_awlen      (axi_awlen),
        .io_master_awsize     (axi_awsize),
        .io_master_awburst    (axi_awburst),
        .io_master_awvalid    (axi_awvalid),
        .io_master_awready    (axi_awready),
        .io_master_wdata      (axi_wdata),
        .io_master_wstrb      (axi_wstrb),
        .io_master_wlast      (axi_wlast),
        .io_master_wvalid     (axi_wvalid),
        .io_master_wready     (axi_wready),
        .io_master_bid        (axi_bid),
        .io_master_bresp      (axi_bresp),
        .io_master_bvalid     (axi_bvalid),
        .io_master_bready     (axi_bready),

        .io_slave_awready     (),
        .io_slave_awvalid     (1'b0),
        .io_slave_awid        (4'b0),
        .io_slave_awaddr      (32'b0),
        .io_slave_awlen       (8'b0),
        .io_slave_awsize      (3'b0),
        .io_slave_awburst     (2'b0),
        .io_slave_wready      (),
        .io_slave_wvalid      (1'b0),
        .io_slave_wdata       (32'b0),
        .io_slave_wstrb       (4'b0),
        .io_slave_wlast       (1'b0),
        .io_slave_bready      (1'b0),
        .io_slave_bvalid      (),
        .io_slave_bid         (),
        .io_slave_bresp       (),
        .io_slave_arready     (),
        .io_slave_arvalid     (1'b0),
        .io_slave_arid        (4'b0),
        .io_slave_araddr      (32'b0),
        .io_slave_arlen       (8'b0),
        .io_slave_arsize      (3'b0),
        .io_slave_arburst     (2'b0),
        .io_slave_rready      (1'b0),
        .io_slave_rvalid      (),
        .io_slave_rid         (),
        .io_slave_rdata       (),
        .io_slave_rresp       (),
        .io_slave_rlast       ()
    );

    localparam [31:0] UART_BASE_ADDR = 32'h1000_0000;
    localparam [31:0] UART_END_ADDR  = 32'h1000_0fff;

    localparam SEL_PMEM = 1'b0;
    localparam SEL_UART = 1'b1;

    localparam [1:0] RD_IDLE = 2'd0;
    localparam [1:0] RD_PREP = 2'd1;
    localparam [1:0] RD_R    = 2'd2;

    localparam [2:0] WR_IDLE    = 3'd0;
    localparam [2:0] WR_COLLECT = 3'd1;
    localparam [2:0] WR_ISSUE   = 3'd2;
    localparam [2:0] WR_DATA    = 3'd3;
    localparam [2:0] WR_B       = 3'd4;

`ifdef __ICARUS__
    localparam [31:0] PBASE_ADDR = 32'h8000_0000;
    localparam [31:0] PBOOT_ALIAS_ADDR = 32'h3000_0000;
    localparam integer PBYTES = 32'h0800_0000;

    reg [7:0] pmem [0:PBYTES-1];
    reg [8*256-1:0] img_file;
    integer img_load_status;
    integer img_bytes;

    function [31:0] pmodel_read;
        input [31:0] raddr;
        integer byte_addr;
        begin
            byte_addr = {raddr[31:2], 2'b00} - PBASE_ADDR;
            if ((raddr >= PBOOT_ALIAS_ADDR) && (raddr < (PBOOT_ALIAS_ADDR + 32'h40))) begin
                case (raddr - PBOOT_ALIAS_ADDR)
                    32'h0000_0000: pmodel_read = 32'h8000_02b7;
                    32'h0000_0004: pmodel_read = 32'h0002_8067;
                    default:       pmodel_read = 32'h0000_0013;
                endcase
            end else if ((raddr < PBASE_ADDR) || (byte_addr < 0) || (byte_addr > (PBYTES - 4))) begin
                pmodel_read = 32'hxxxx_xxxx;
            end else begin
                pmodel_read = {
                    pmem[byte_addr + 3],
                    pmem[byte_addr + 2],
                    pmem[byte_addr + 1],
                    pmem[byte_addr + 0]
                };
            end
        end
    endfunction

    task pmodel_write;
        input [31:0] waddr;
        input [31:0] wdata;
        input [7:0]  wmask;
        integer byte_addr;
        begin
            byte_addr = {waddr[31:2], 2'b00} - PBASE_ADDR;
            if ((waddr < PBASE_ADDR) || (byte_addr < 0) || (byte_addr > (PBYTES - 4))) begin
                $display("top: write out of range addr=0x%08x", waddr);
            end else begin
                if (wmask[0]) pmem[byte_addr + 0] = wdata[7:0];
                if (wmask[1]) pmem[byte_addr + 1] = wdata[15:8];
                if (wmask[2]) pmem[byte_addr + 2] = wdata[23:16];
                if (wmask[3]) pmem[byte_addr + 3] = wdata[31:24];
            end
        end
    endtask

    initial begin
        if (!$value$plusargs("IMG=%s", img_file)) begin
            $display("top: missing +IMG=<image.hex> plusarg");
            $finish;
        end
        img_load_status = $fopen(img_file, "r");
        if (img_load_status == 0) begin
            $display("top: failed to open image %0s", img_file);
            $finish;
        end
        $fclose(img_load_status);
        if ($value$plusargs("IMG_BYTES=%d", img_bytes)) begin
            $readmemh(img_file, pmem, 0, img_bytes - 1);
        end else begin
            $readmemh(img_file, pmem);
        end
    end
`else
    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
`endif

    reg [1:0] rd_state;
    reg [2:0] wr_state;
    reg        rd_sel;
    reg [31:0] rd_addr_reg;
    reg [ 7:0] rd_len_reg;
    reg [ 1:0] rd_burst_reg;
    reg [ 7:0] rd_beats_left;
    reg        rd_buf_valid;
    reg [31:0] rd_buf_data;
    reg [ 1:0] rd_buf_resp;
    reg        rd_buf_last;
    reg        wr_sel;
    reg        wr_have_aw;
    reg        wr_have_w;
    reg        wr_buf_valid;
    reg [ 1:0] wr_buf_resp;
    reg [31:0] wr_addr_reg;
    reg [31:0] wr_data_reg;
    reg [ 3:0] wr_strb_reg;
    reg [31:0] uart_reg;
    reg [31:0] rd_next_addr;
    reg [31:0] rd_next_data;
    reg [31:0] uart_after_write;

    wire ar_sel;
    wire aw_sel;
    wire ar_fire;
    wire r_fire;
    wire aw_fire;
    wire w_fire;
    wire b_fire;
    wire rd_buf_take;

    assign ar_sel = ((axi_araddr >= UART_BASE_ADDR) && (axi_araddr <= UART_END_ADDR)) ? SEL_UART : SEL_PMEM;
    assign aw_sel = ((axi_awaddr >= UART_BASE_ADDR) && (axi_awaddr <= UART_END_ADDR)) ? SEL_UART : SEL_PMEM;
    assign ar_fire = axi_arvalid && axi_arready;
    assign r_fire  = axi_rvalid  && axi_rready;
    assign aw_fire = axi_awvalid && axi_awready;
    assign w_fire  = axi_wvalid  && axi_wready;
    assign b_fire  = axi_bvalid  && axi_bready;
    assign rd_buf_take = rd_buf_valid && axi_rready;

    always @(*) begin
        rd_next_addr = rd_addr_reg;
        case (rd_burst_reg)
            2'b00: rd_next_addr = rd_addr_reg;
            2'b01: rd_next_addr = rd_addr_reg + 32'd4;
            default: rd_next_addr = rd_addr_reg + 32'd4;
        endcase
    end

    always @(*) begin
        uart_after_write = uart_reg;
        if (wr_strb_reg[0]) uart_after_write[7:0]   = wr_data_reg[7:0];
        if (wr_strb_reg[1]) uart_after_write[15:8]  = wr_data_reg[15:8];
        if (wr_strb_reg[2]) uart_after_write[23:16] = wr_data_reg[23:16];
        if (wr_strb_reg[3]) uart_after_write[31:24] = wr_data_reg[31:24];
    end

    always @(*) begin
`ifdef __ICARUS__
        rd_next_data = pmodel_read(rd_next_addr);
`else
        rd_next_data = pmem_read(rd_next_addr);
`endif
    end

    always @(*) begin
        axi_arready = 1'b0;
        axi_rid     = 4'b0;
        axi_rdata   = 32'b0;
        axi_rresp   = 2'b00;
        axi_rlast   = 1'b0;
        axi_rvalid  = 1'b0;
        axi_awready = 1'b0;
        axi_wready  = 1'b0;
        axi_bid     = 4'b0;
        axi_bresp   = 2'b00;
        axi_bvalid  = 1'b0;

        case (rd_state)
            RD_IDLE: begin
                axi_arready = 1'b1;
            end
            RD_R: begin
                axi_rdata  = rd_buf_data;
                axi_rresp  = rd_buf_resp;
                axi_rlast  = rd_buf_last;
                axi_rvalid = rd_buf_valid;
            end
            default: begin
            end
        endcase

        case (wr_state)
            WR_IDLE: begin
                axi_awready = 1'b1;
                axi_wready  = 1'b1;
            end
            WR_COLLECT: begin
                axi_awready = !wr_have_aw;
                axi_wready  = !wr_have_w;
            end
            WR_B: begin
                axi_bresp  = wr_buf_resp;
                axi_bvalid = wr_buf_valid;
            end
            default: begin
            end
        endcase
    end

    always @(posedge clock) begin
        if (reset) begin
            rd_state      <= RD_IDLE;
            wr_state      <= WR_IDLE;
            rd_sel        <= SEL_PMEM;
            rd_addr_reg   <= 32'b0;
            rd_len_reg    <= 8'b0;
            rd_burst_reg  <= 2'b0;
            rd_beats_left <= 8'b0;
            rd_buf_valid  <= 1'b0;
            rd_buf_data   <= 32'b0;
            rd_buf_resp   <= 2'b0;
            rd_buf_last   <= 1'b0;
            wr_sel        <= SEL_PMEM;
            wr_have_aw    <= 1'b0;
            wr_have_w     <= 1'b0;
            wr_buf_valid  <= 1'b0;
            wr_buf_resp   <= 2'b0;
            wr_addr_reg   <= 32'b0;
            wr_data_reg   <= 32'b0;
            wr_strb_reg   <= 4'b0;
            uart_reg      <= 32'b0;
        end else begin
            case (rd_state)
                RD_IDLE: begin
                    rd_buf_valid <= 1'b0;

                    if (ar_fire) begin
                        rd_sel       <= ar_sel;
                        rd_addr_reg  <= axi_araddr;
                        rd_len_reg   <= axi_arlen;
                        rd_burst_reg <= axi_arburst;
                        rd_state     <= RD_PREP;
                    end
                end

                RD_PREP: begin
                    if (rd_sel == SEL_UART) begin
                        rd_beats_left <= 8'd1;
                        rd_buf_valid  <= 1'b1;
                        rd_buf_data   <= uart_reg;
                        rd_buf_resp   <= 2'b00;
                        rd_buf_last   <= 1'b1;
                    end else begin
                        rd_beats_left <= rd_len_reg + 8'd1;
                        rd_buf_valid  <= 1'b1;
`ifdef __ICARUS__
                        rd_buf_data   <= pmodel_read(rd_addr_reg);
`else
                        rd_buf_data   <= pmem_read(rd_addr_reg);
`endif
                        rd_buf_resp   <= 2'b00;
                        rd_buf_last   <= (rd_len_reg == 8'd0);
                    end
                    rd_state <= RD_R;
                end

                RD_R: begin
                    if (rd_buf_take) begin
                        if (rd_buf_last) begin
                            rd_buf_valid <= 1'b0;
                            rd_state <= RD_IDLE;
                        end else begin
                            rd_beats_left <= rd_beats_left - 8'd1;
                            rd_addr_reg   <= rd_next_addr;
                            rd_buf_valid  <= 1'b1;
                            rd_buf_data   <= rd_next_data;
                            rd_buf_resp   <= 2'b00;
                            rd_buf_last   <= (rd_beats_left == 8'd2);
                        end
                    end
                end

                default: begin
                    rd_state <= RD_IDLE;
                end
            endcase

            case (wr_state)
                WR_IDLE: begin
                    wr_have_aw   <= 1'b0;
                    wr_have_w    <= 1'b0;
                    wr_buf_valid <= 1'b0;

                    if (aw_fire || w_fire) begin
                        if (aw_fire) begin
                            wr_sel      <= aw_sel;
                            wr_addr_reg <= axi_awaddr;
                        end
                        if (w_fire) begin
                            wr_data_reg <= axi_wdata;
                            wr_strb_reg <= axi_wstrb;
                        end
                        wr_have_aw <= aw_fire;
                        wr_have_w  <= w_fire;
                        wr_state   <= (aw_fire && w_fire) ? WR_ISSUE : WR_COLLECT;
                    end
                end

                WR_COLLECT: begin
                    if (!wr_have_aw && aw_fire) begin
                        wr_sel      <= aw_sel;
                        wr_addr_reg <= axi_awaddr;
                        wr_have_aw  <= 1'b1;
                    end
                    if (!wr_have_w && w_fire) begin
                        wr_data_reg <= axi_wdata;
                        wr_strb_reg <= axi_wstrb;
                        wr_have_w   <= 1'b1;
                    end
                    if ((wr_have_aw || aw_fire) && (wr_have_w || w_fire)) begin
                        wr_state <= WR_ISSUE;
                    end
                end

                WR_ISSUE: begin
                    wr_state <= WR_DATA;
                end

                WR_DATA: begin
                    if (wr_sel == SEL_UART) begin
                        uart_reg <= uart_after_write;
                        $write("%c", wr_data_reg[7:0]);
                        $fflush();
                    end else begin
`ifdef __ICARUS__
                        pmodel_write(wr_addr_reg, wr_data_reg, {4'b0000, wr_strb_reg});
`else
                        pmem_write(wr_addr_reg, wr_data_reg, {4'b0000, wr_strb_reg});
`endif
                    end
                    wr_buf_valid <= 1'b1;
                    wr_buf_resp  <= 2'b00;
                    wr_state <= WR_B;
                end

                WR_B: begin
                    if (b_fire) begin
                        wr_buf_valid <= 1'b0;
                        wr_state <= WR_IDLE;
                    end
                end

                default: begin
                    wr_state <= WR_IDLE;
                end
            endcase
        end
    end

`ifndef SYNTHESIS
`ifndef __ICARUS__
    always @(posedge clock) begin
        if (!reset) begin
            if (axi_arvalid && axi_arready && (ar_sel != SEL_PMEM) &&
                ((axi_arlen != 8'h00) || (axi_arburst != 2'b00))) begin
                $fatal(1, "top: MMIO burst read is not supported addr=%08x", axi_araddr);
            end
            if (axi_arvalid && axi_arready && (axi_arsize > 3'd2)) begin
                $fatal(1, "top: unsupported read size addr=%08x size=%0d", axi_araddr, axi_arsize);
            end
            if (axi_awvalid && axi_awready &&
                ((axi_awlen != 8'h00) || (axi_awburst != 2'b00))) begin
                $fatal(1, "top: burst write is not supported addr=%08x", axi_awaddr);
            end
            if (axi_awvalid && axi_awready && (axi_awsize > 3'd2)) begin
                $fatal(1, "top: unsupported write size addr=%08x size=%0d", axi_awaddr, axi_awsize);
            end
            if (axi_wvalid && axi_wready && (axi_wlast != 1'b1)) begin
                $fatal(1, "top: WLAST must be 1 for single-beat write");
            end
            if (axi_wvalid && axi_wready && (axi_wstrb == 4'b0000)) begin
                $fatal(1, "top: zero write strobe data=%08x", axi_wdata);
            end
            if (axi_arvalid && axi_arready && (ar_sel == SEL_PMEM) &&
                (axi_arburst != 2'b00) && (axi_arburst != 2'b01)) begin
                $fatal(1, "top: unsupported read burst type %0b", axi_arburst);
            end
        end
    end
`endif
`endif

    wire _unused_ok;
    assign _unused_ok = &{1'b0, clock, axi_arid, axi_arsize, axi_awid, axi_awsize};

endmodule
