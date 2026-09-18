/* verilator lint_off PINCONNECTEMPTY */
module top (
    input clock,
    input reset
);

    // ----- CPU AXI master -----
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

    ysyx_26010027 my_cpu (
        // master
        .io_master_araddr (axi_araddr),
        .io_master_arid   (axi_arid),
        .io_master_arlen  (axi_arlen),
        .io_master_arsize (axi_arsize),
        .io_master_arburst(axi_arburst),
        .io_master_arvalid(axi_arvalid),
        .io_master_arready(axi_arready),
        .io_master_rdata  (axi_rdata),
        .io_master_rid    (axi_rid),
        .io_master_rresp  (axi_rresp),
        .io_master_rlast  (axi_rlast),
        .io_master_rvalid (axi_rvalid),
        .io_master_rready (axi_rready),

        .io_master_awaddr (axi_awaddr),
        .io_master_awid   (axi_awid),
        .io_master_awlen  (axi_awlen),
        .io_master_awsize (axi_awsize),
        .io_master_awburst(axi_awburst),
        .io_master_awvalid(axi_awvalid),
        .io_master_awready(axi_awready),
        .io_master_wdata  (axi_wdata),
        .io_master_wstrb  (axi_wstrb),
        .io_master_wlast  (axi_wlast),
        .io_master_wvalid (axi_wvalid),
        .io_master_wready (axi_wready),
        .io_master_bid    (axi_bid),
        .io_master_bresp  (axi_bresp),
        .io_master_bvalid (axi_bvalid),
        .io_master_bready (axi_bready),

        // slave
        .io_slave_awready (),
        .io_slave_awvalid (1'b0),
        .io_slave_awid    (4'b0),
        .io_slave_awaddr  (32'b0),
        .io_slave_awlen   (8'b0),
        .io_slave_awsize  (3'b0),
        .io_slave_awburst (2'b0),
        .io_slave_wready  (),
        .io_slave_wvalid  (1'b0),
        .io_slave_wdata   (32'b0),
        .io_slave_wstrb   (4'b0),
        .io_slave_wlast   (1'b0),
        .io_slave_bready  (1'b0),
        .io_slave_bvalid  (),
        .io_slave_bid     (),
        .io_slave_bresp   (),
        .io_slave_arready (),
        .io_slave_arvalid (1'b0),
        .io_slave_arid    (4'b0),
        .io_slave_araddr  (32'b0),
        .io_slave_arlen   (8'b0),
        .io_slave_arsize  (3'b0),
        .io_slave_arburst (2'b0),
        .io_slave_rready  (1'b0),
        .io_slave_rvalid  (),
        .io_slave_rid     (),
        .io_slave_rdata   (),
        .io_slave_rresp   (),
        .io_slave_rlast   (),

        .clock            (clock),
        .reset            (reset),
        .io_interrupt     (1'b0)
    );

    // ----- 存储器 -----
    localparam [31:0] UART_BASE = 32'h1000_0000;
    localparam [31:0] UART_END  = 32'h1000_0fff;

`ifdef __ICARUS__
    // 行为级内存（iverilog / 网表仿真）
    localparam [31:0] MEM_BASE  = 32'h8000_0000;
    localparam integer MEM_WORDS = 16*1024*1024; // 64MB
    reg [31:0] pmem [0:MEM_WORDS-1];
    reg [8*256-1:0] img_file;
    initial begin
        if (!$value$plusargs("IMG=%s", img_file)) begin
            $display("[TOP] Missing +IMG=<image.hex> plusarg");
            $finish;
        end
        $readmemh(img_file, pmem);
    end
`else
    import "DPI-C" function int  pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input int wmask);
`endif

    wire ar_is_uart = (axi_araddr >= UART_BASE) && (axi_araddr <= UART_END);
    wire aw_is_uart = (axi_awaddr >= UART_BASE) && (axi_awaddr <= UART_END);


    // BOOT start
    localparam [31:0] BOOT_BASE = 32'h3000_0000;
    localparam [31:0] BOOT_END  = 32'h3000_003f;

    function [31:0] boot_read(input [31:0] a);
        begin
            case (a - BOOT_BASE)
                32'h00:  boot_read = 32'h8000_02b7; // lui  t0, 0x80000
                32'h04:  boot_read = 32'h0002_8067; // jalr x0, t0, 0
                default: boot_read = 32'h0000_0013; // nop
            endcase
        end
    endfunction

    wire ar_is_boot = (axi_araddr >= BOOT_BASE) && (axi_araddr <= BOOT_END);

    // ----- 读状态机 -----
    reg [1:0] rd_state;
    localparam RD_IDLE  = 2'd0;
    localparam RD_BURST = 2'd1;

    reg [31:0] rd_addr;        // 当前拍地址
    reg [ 7:0] rd_beats_left;  // 剩余拍数（含当前拍）
    reg        rd_uart;        // 当前突发是否命中 UART
    reg        rd_boot;        // 当前突发是否命中启动别名
    reg [31:0] rd_data;        // 当前拍数据

    assign axi_rdata = rd_data;
    assign axi_rid   = 4'b0;
    assign axi_rresp = 2'b0;

    always @(*) begin
        axi_arready = (rd_state == RD_IDLE);
    end

    always @(posedge clock, posedge reset) begin
        if (reset) begin
            rd_state      <= RD_IDLE;
            rd_addr       <= 32'b0;
            rd_beats_left <= 8'd0;
            rd_uart       <= 1'b0;
            rd_boot       <= 1'b0;
            rd_data       <= 32'b0;
            axi_rvalid    <= 1'b0;
            axi_rlast     <= 1'b0;
        end else begin
            case (rd_state)
                RD_IDLE: begin
                    axi_rvalid <= 1'b0;
                    if (axi_arvalid && axi_arready) begin
                        rd_addr       <= axi_araddr;
                        rd_beats_left <= axi_arlen + 8'd1;
                        rd_uart       <= ar_is_uart;
                        rd_boot       <= ar_is_boot;
`ifdef __ICARUS__
                        rd_data       <= ar_is_uart ? 32'b0 :
                                         ar_is_boot ? boot_read(axi_araddr) :
                                                      pmem[(axi_araddr - MEM_BASE) >> 2];
`else
                        rd_data       <= ar_is_boot ? boot_read(axi_araddr) : pmem_read(axi_araddr);
`endif
                        axi_rvalid    <= 1'b1;
                        axi_rlast     <= (axi_arlen == 8'd0);
                        rd_state      <= RD_BURST;
                    end
                end
                RD_BURST: begin
                    if (axi_rvalid && axi_rready) begin
                        if (axi_rlast) begin
                            axi_rvalid <= 1'b0;
                            rd_state   <= RD_IDLE;
                        end else begin
                            rd_addr       <= rd_addr + 32'd4;
                            rd_beats_left <= rd_beats_left - 8'd1;
`ifdef __ICARUS__
                            rd_data       <= rd_uart ? 32'b0 :
                                             rd_boot ? boot_read(rd_addr + 32'd4) :
                                                       pmem[(rd_addr + 32'd4 - MEM_BASE) >> 2];
`else
                            rd_data       <= rd_boot ? boot_read(rd_addr + 32'd4) : pmem_read(rd_addr + 32'd4);
`endif
                            axi_rlast     <= (rd_beats_left == 8'd2);
                        end
                    end
                end
                default: rd_state <= RD_IDLE;
            endcase
        end
    end

    // ----- 写状态机-----
    reg [1:0] wr_state;
    localparam WR_IDLE = 2'd0;
    localparam WR_RESP = 2'd1;

    assign axi_bid   = 4'b0;
    assign axi_bresp = 2'b0;

    always @(*) begin
        axi_awready = (wr_state == WR_IDLE);
        axi_wready  = (wr_state == WR_IDLE);
    end

    always @(posedge clock, posedge reset) begin
        if (reset) begin
            wr_state  <= WR_IDLE;
            axi_bvalid <= 1'b0;
        end else begin
            case (wr_state)
                WR_IDLE: begin
                    if (axi_awvalid && axi_awready && axi_wvalid && axi_wready) begin
`ifdef __ICARUS__
                        if (aw_is_uart) begin
                            $write("%c", axi_wdata[7:0]);
                            $fflush();
                        end else begin
                            if (axi_wstrb[0]) pmem[(axi_awaddr - MEM_BASE) >> 2][ 7: 0] <= axi_wdata[ 7: 0];
                            if (axi_wstrb[1]) pmem[(axi_awaddr - MEM_BASE) >> 2][15: 8] <= axi_wdata[15: 8];
                            if (axi_wstrb[2]) pmem[(axi_awaddr - MEM_BASE) >> 2][23:16] <= axi_wdata[23:16];
                            if (axi_wstrb[3]) pmem[(axi_awaddr - MEM_BASE) >> 2][31:24] <= axi_wdata[31:24];
                        end
`else
                        pmem_write(axi_awaddr, axi_wdata, {{28{1'b0}}, axi_wstrb});
`endif
                        axi_bvalid <= 1'b1;
                        wr_state   <= WR_RESP;
                    end
                end
                WR_RESP: begin
                    if (axi_bvalid && axi_bready) begin
                        axi_bvalid <= 1'b0;
                        wr_state   <= WR_IDLE;
                    end
                end
                default: wr_state <= WR_IDLE;
            endcase
        end
    end

    wire _unused_ok = &{1'b0, axi_arid, axi_arsize, axi_arburst, axi_awid, axi_awlen, axi_awsize, axi_awburst, axi_wlast, aw_is_uart, rd_uart};

endmodule
