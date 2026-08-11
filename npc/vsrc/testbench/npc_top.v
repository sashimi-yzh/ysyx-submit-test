module npc_top
(
    input             clock,
    input             reset,
    output reg        halt_seen,
    output reg [31:0] halt_status
);
    wire        retire_seen;
    wire [31:0] retire_pc;
    wire [31:0] retire_word;
`ifdef NPC_NETLIST_SIM
    assign retire_seen = 1'b0;
    assign retire_pc   = 32'b0;
    assign retire_word = 32'b0;
`endif
    // AXI4模拟外部总线
    // AXI4 AR读地址通道信号
    wire [31:0] bus_araddr;
    wire [ 3:0] bus_arid;
    wire [ 7:0] bus_arlen;
    wire [ 2:0] bus_arsize;
    wire [ 1:0] bus_arburst;
    wire        bus_arvalid;
    wire        bus_arready;
    // AXI4 R读返回通道信号
    wire [31:0] bus_rdata;
    wire [ 3:0] bus_rid;
    wire [ 1:0] bus_rresp;
    wire        bus_rlast;
    wire        bus_rvalid;
    wire        bus_rready;
    // AXI4 AW写地址通道信号
    wire [31:0] bus_awaddr;
    wire [ 3:0] bus_awid;
    wire [ 7:0] bus_awlen;
    wire [ 2:0] bus_awsize;
    wire [ 1:0] bus_awburst;
    wire        bus_awvalid;
    wire        bus_awready;
    // AXI4 W写数据通道信号
    wire [31:0] bus_wdata;
    wire [ 3:0] bus_wstrb;
    wire        bus_wlast;
    wire        bus_wvalid;
    wire        bus_wready;
    // AXI4 B写响应通道信号
    wire [ 3:0] bus_bid;
    wire [ 1:0] bus_bresp;
    wire        bus_bvalid;
    wire        bus_bready;
    // cpu实例化
`ifdef __ICARUS__
    ysyx_26010028 Core_cpu (
`else
    ysyx_26010028 #(
        .RESET_PC             (32'h8000_0000)
    ) Core_cpu (
`endif
        .clock                (clock),
        .reset                (reset),
        .io_interrupt         (1'b0),

`ifndef NPC_NETLIST_SIM
        .commit_valid_out    (retire_seen),
        .commit_pc_out       (retire_pc),
        .commit_inst_out     (retire_word),
`endif

        .io_master_araddr     (bus_araddr),
        .io_master_arid       (bus_arid),
        .io_master_arlen      (bus_arlen),
        .io_master_arsize     (bus_arsize),
        .io_master_arburst    (bus_arburst),
        .io_master_arvalid    (bus_arvalid),
        .io_master_arready    (bus_arready),
        .io_master_rdata      (bus_rdata),
        .io_master_rid        (bus_rid),
        .io_master_rresp      (bus_rresp),
        .io_master_rlast      (bus_rlast),
        .io_master_rvalid     (bus_rvalid),
        .io_master_rready     (bus_rready),

        .io_master_awaddr     (bus_awaddr),
        .io_master_awid       (bus_awid),
        .io_master_awlen      (bus_awlen),
        .io_master_awsize     (bus_awsize),
        .io_master_awburst    (bus_awburst),
        .io_master_awvalid    (bus_awvalid),
        .io_master_awready    (bus_awready),
        .io_master_wdata      (bus_wdata),
        .io_master_wstrb      (bus_wstrb),
        .io_master_wlast      (bus_wlast),
        .io_master_wvalid     (bus_wvalid),
        .io_master_wready     (bus_wready),
        .io_master_bid        (bus_bid),
        .io_master_bresp      (bus_bresp),
        .io_master_bvalid     (bus_bvalid),
        .io_master_bready     (bus_bready),

        .io_slave_awready     (),
        .io_slave_awvalid     (1'b0),
        .io_slave_awaddr      (32'b0),
        .io_slave_awid        (4'b0),
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
        .io_slave_bresp       (),
        .io_slave_bid         (),

        .io_slave_arready     (),
        .io_slave_arvalid     (1'b0),
        .io_slave_araddr      (32'b0),
        .io_slave_arid        (4'b0),
        .io_slave_arlen       (8'b0),
        .io_slave_arsize      (3'b0),
        .io_slave_arburst     (2'b0),

        .io_slave_rready      (1'b0),
        .io_slave_rvalid      (),
        .io_slave_rresp       (),
        .io_slave_rdata       (),
        .io_slave_rlast       (),
        .io_slave_rid         ()
    );
    // UART和模拟器退出寄存器地址
    localparam [31:0] UART_LO_ADDR = 32'h1000_0000;
    localparam [31:0] UART_HI_ADDR  = 32'h1000_0fff;
    localparam [31:0] HALT_REG_ADDR  = 32'h1000_0004;
    wire rd_mmio = (bus_araddr >= UART_LO_ADDR)
                    && (bus_araddr <= UART_HI_ADDR);
    // 内存访问接口icarus模型和verilator模型
`ifdef __ICARUS__
    localparam [31:0] RAM_BASE_ADDR       = 32'h8000_0000;
    localparam [31:0] BOOT_ALIAS_ADDR = 32'h3000_0000;
    localparam integer RAM_CAPACITY          = 32'h0800_0000;

    reg [7:0] pmem [0:RAM_CAPACITY-1];
    reg [8*256-1:0] image_path;
    integer image_fd;
    integer image_size;
    // icarus模型内存读函数
    function [31:0] load_word;
        input [31:0] paddr;
        integer offset;
        begin
            offset = {paddr[31:2], 2'b00} - RAM_BASE_ADDR;
            if ((paddr >= BOOT_ALIAS_ADDR) && (paddr < BOOT_ALIAS_ADDR + 32'h40)) begin
                case (paddr - BOOT_ALIAS_ADDR)
                    32'h0000_0000: load_word = 32'h8000_02b7;
                    32'h0000_0004: load_word = 32'h0002_8067;
                    default: load_word = 32'h0000_0013;
                endcase
            end else if ((paddr < RAM_BASE_ADDR) || (offset < 0) || (offset > RAM_CAPACITY - 4)) begin
                load_word = 32'hxxxx_xxxx;
            end else begin
                load_word = {pmem[offset + 3], pmem[offset + 2],
                    pmem[offset + 1], pmem[offset]};
            end
        end
    endfunction
    // icarus模型内存写函数
    task store_word;
        input [31:0] paddr;
        input [31:0] value;
        input [7:0] mask;
        integer offset;
        begin
            offset = {paddr[31:2], 2'b00} - RAM_BASE_ADDR;
            if ((paddr < RAM_BASE_ADDR) || (offset < 0) || (offset > RAM_CAPACITY - 4)) begin
                $display("sim bus: store address outside RAM addr=0x%08x", paddr);
            end else begin
                if (mask[0]) pmem[offset] = value[7:0];
                if (mask[1]) pmem[offset + 1] = value[15:8];
                if (mask[2]) pmem[offset + 2] = value[23:16];
                if (mask[3]) pmem[offset + 3] = value[31:24];
            end
        end
    endtask
    // icarus模型内存初始化函数
    initial begin
        if (!$value$plusargs("IMG=%s", image_path)) begin
            $display("sim bus: image argument +IMG=<image.hex> is required");
            $finish;
        end
        image_fd = $fopen(image_path, "r");
        if (image_fd == 0) begin
            $display("sim bus: cannot open image %0s", image_path);
            $finish;
        end
        $fclose(image_fd);
        if ($value$plusargs("IMG_BYTES=%d", image_size))
            $readmemh(image_path, pmem, 0, image_size - 1);
        else $readmemh(image_path, pmem);
    end
`else
    import "DPI-C" function int pmem_read(input int address);
    import "DPI-C" function void pmem_write(input int address, input int data, input byte byte_enable);
`endif

    reg        rd_valid;
    reg        rd_last;
    reg [31:0] rd_data;
    reg [31:0] rd_addr;
    reg [ 7:0] rd_left;
    reg [ 1:0] rd_burst;

    reg        wr_addr_hold;
    reg [31:0] wr_addr_hold_value;
    reg        wr_data_hold;
    reg [31:0] wr_data_hold_value;
    reg [ 3:0] wr_mask_hold;
    reg        wr_resp_valid;
    reg [31:0] uart_value;

    wire rd_hs = bus_arvalid && bus_arready;
    wire rd_rsp_hs  = bus_rvalid && bus_rready;
    wire wr_addr_hs = bus_awvalid && bus_awready;
    wire wr_data_hs  = bus_wvalid && bus_wready;
    wire wr_rsp_hs  = bus_bvalid && bus_bready;

    wire [31:0] next_read_addr = (rd_burst == 2'b00) ? rd_addr : rd_addr + 32'd4;
`ifdef __ICARUS__
    wire [31:0] next_read_data = load_word(next_read_addr);
`else
    wire [31:0] next_read_data = pmem_read(next_read_addr);
`endif

    wire [31:0] wr_addr_mux = wr_addr_hold ? wr_addr_hold_value : bus_awaddr;
    wire [31:0] wr_data_mux = wr_data_hold ? wr_data_hold_value : bus_wdata;
    wire [ 3:0] wr_mask_mux = wr_data_hold ? wr_mask_hold : bus_wstrb;
    wire wr_complete = (wr_addr_hold || wr_addr_hs) && (wr_data_hold || wr_data_hs);
    wire wr_mmio = (wr_addr_mux >= UART_LO_ADDR)
                       && (wr_addr_mux <= UART_HI_ADDR);

    assign bus_arready = !rd_valid;
    assign bus_rid = 4'b0;
    assign bus_rdata = rd_data;
    assign bus_rresp = 2'b00;
    assign bus_rlast = rd_last;
    assign bus_rvalid = rd_valid;

    assign bus_awready = !wr_addr_hold && !wr_resp_valid;
    assign bus_wready = !wr_data_hold && !wr_resp_valid;
    assign bus_bid = 4'b0;
    assign bus_bresp = 2'b00;
    assign bus_bvalid = wr_resp_valid;

    always @(posedge clock) begin
        if (reset) begin
            rd_valid <= 1'b0;
            rd_last <= 1'b0;
            rd_data <= 32'b0;
            rd_addr <= 32'b0;
            rd_left <= 8'b0;
            rd_burst <= 2'b0;
        end else if (rd_hs) begin
            rd_valid <= 1'b1;
            rd_addr <= bus_araddr;
            rd_left <= bus_arlen;
            rd_burst <= bus_arburst;
            rd_last <= rd_mmio || (bus_arlen == 8'b0);
        `ifdef __ICARUS__
            rd_data <= rd_mmio ? uart_value : load_word(bus_araddr);
        `else
            rd_data <= rd_mmio ? uart_value : pmem_read(bus_araddr);
        `endif
        end else if (rd_rsp_hs) begin
            if (rd_last) begin
                rd_valid <= 1'b0;
            end else begin
                rd_addr <= next_read_addr;
                rd_data <= next_read_data;
                rd_left <= rd_left - 8'd1;
                rd_last <= (rd_left == 8'd1);
            end
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            wr_addr_hold <= 1'b0;
            wr_addr_hold_value <= 32'b0;
            wr_data_hold <= 1'b0;
            wr_data_hold_value <= 32'b0;
            wr_mask_hold <= 4'b0;
            wr_resp_valid <= 1'b0;
            uart_value <= 32'b0;
            halt_seen <= 1'b0;
            halt_status <= 32'b0;
        end else begin
            if (wr_addr_hs) begin
                wr_addr_hold <= 1'b1;
                wr_addr_hold_value <= bus_awaddr;
            end
            if (wr_data_hs) begin
                wr_data_hold <= 1'b1;
                wr_data_hold_value <= bus_wdata;
                wr_mask_hold <= bus_wstrb;
            end
            if (wr_rsp_hs) wr_resp_valid <= 1'b0;

            if (wr_complete) begin
                wr_addr_hold <= 1'b0;
                wr_data_hold <= 1'b0;
                wr_resp_valid <= 1'b1;
                if (wr_mmio) begin
                    if (wr_mask_mux[0]) uart_value[7:0] <= wr_data_mux[7:0];
                    if (wr_mask_mux[1]) uart_value[15:8] <= wr_data_mux[15:8];
                    if (wr_mask_mux[2]) uart_value[23:16] <= wr_data_mux[23:16];
                    if (wr_mask_mux[3]) uart_value[31:24] <= wr_data_mux[31:24];
                    if (wr_addr_mux == UART_LO_ADDR) begin
                        $write("%c", wr_data_mux[7:0]);
                        $fflush();
                    end
                    if (wr_addr_mux == HALT_REG_ADDR) begin
                        halt_seen <= 1'b1;
                        halt_status <= wr_data_mux;
                    end
                end else begin
                `ifdef __ICARUS__
                    store_word(wr_addr_mux, wr_data_mux, {4'b0, wr_mask_mux});
                `else
                    pmem_write(wr_addr_mux, wr_data_mux, {4'b0, wr_mask_mux});
                `endif
                end
            end
        end
    end

`ifndef SYNTHESIS
`ifndef __ICARUS__
    always @(posedge clock) begin
        if (!reset) begin
            if (rd_hs && rd_mmio && ((bus_arlen != 8'b0) || (bus_arburst != 2'b0))) $fatal(1, "sim bus: UART reads cannot burst addr=%08x", bus_araddr);
            if (rd_hs && (bus_arsize > 3'd2)) $fatal(1, "sim bus: read width rejected addr=%08x size=%0d", bus_araddr, bus_arsize);
            if (wr_addr_hs && ((bus_awlen != 8'b0) || (bus_awburst != 2'b0))) $fatal(1, "sim bus: write burst rejected addr=%08x", bus_awaddr);
            if (wr_addr_hs && (bus_awsize > 3'd2)) $fatal(1, "sim bus: write width rejected addr=%08x size=%0d", bus_awaddr, bus_awsize);
            if (wr_data_hs && !bus_wlast) $fatal(1, "sim bus: write beat is missing its last marker");
            if (wr_data_hs && (bus_wstrb == 4'b0)) $fatal(1, "sim bus: write has an empty byte mask data=%08x", bus_wdata);
            if (rd_hs && !rd_mmio && (bus_arburst != 2'b00) && (bus_arburst != 2'b01)) $fatal(1, "sim bus: read burst mode %0b is invalid", bus_arburst);
        end
    end
`endif
`endif

    wire _unused_ok = &{1'b0, clock, bus_arid, bus_awid};

endmodule
