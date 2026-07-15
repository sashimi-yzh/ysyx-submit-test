module tb;

    reg clk;
    reg reset;

    // 10 ns clock
    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        reset = 0;
        #100;
        reset = 1;
        repeat (5) @(posedge clk);
        reset = 0;
    end

    // initial begin
    //     $dumpfile("wave.fst");
    //     $dumpvars(0, tb);
    // end

    // -----------------------------------------------------------------------
    // AXI4 master wires between DUT and RAM
    // -----------------------------------------------------------------------
    // Write address channel
    wire        io_master_awready;
    wire        io_master_awvalid;
    wire [31:0] io_master_awaddr;
    wire [3:0]  io_master_awid;
    wire [7:0]  io_master_awlen;
    wire [2:0]  io_master_awsize;
    wire [1:0]  io_master_awburst;
    // Write data channel
    wire        io_master_wready;
    wire        io_master_wvalid;
    wire [31:0] io_master_wdata;
    wire [3:0]  io_master_wstrb;
    wire        io_master_wlast;
    // Write response channel
    wire        io_master_bready;
    wire        io_master_bvalid;
    wire [1:0]  io_master_bresp;
    wire [3:0]  io_master_bid;
    // Read address channel
    wire        io_master_arready;
    wire        io_master_arvalid;
    wire [31:0] io_master_araddr;
    wire [3:0]  io_master_arid;
    wire [7:0]  io_master_arlen;
    wire [2:0]  io_master_arsize;
    wire [1:0]  io_master_arburst;
    // Read data channel
    wire        io_master_rready;
    wire        io_master_rvalid;
    wire [1:0]  io_master_rresp;
    wire [31:0] io_master_rdata;
    wire        io_master_rlast;
    wire [3:0]  io_master_rid;

    // -----------------------------------------------------------------------
    // DUT
    // -----------------------------------------------------------------------
    ysyx_26040125 ysyx_26040125 (
        .clock              (clk),
        .reset              (reset),
        .io_interrupt       (1'b0),

        // AXI4 master → RAM
        .io_master_awready  (io_master_awready),
        .io_master_awvalid  (io_master_awvalid),
        .io_master_awaddr   (io_master_awaddr),
        .io_master_awid     (io_master_awid),
        .io_master_awlen    (io_master_awlen),
        .io_master_awsize   (io_master_awsize),
        .io_master_awburst  (io_master_awburst),
        .io_master_wready   (io_master_wready),
        .io_master_wvalid   (io_master_wvalid),
        .io_master_wdata    (io_master_wdata),
        .io_master_wstrb    (io_master_wstrb),
        .io_master_wlast    (io_master_wlast),
        .io_master_bready   (io_master_bready),
        .io_master_bvalid   (io_master_bvalid),
        .io_master_bresp    (io_master_bresp),
        .io_master_bid      (io_master_bid),
        .io_master_arready  (io_master_arready),
        .io_master_arvalid  (io_master_arvalid),
        .io_master_araddr   (io_master_araddr),
        .io_master_arid     (io_master_arid),
        .io_master_arlen    (io_master_arlen),
        .io_master_arsize   (io_master_arsize),
        .io_master_arburst  (io_master_arburst),
        .io_master_rready   (io_master_rready),
        .io_master_rvalid   (io_master_rvalid),
        .io_master_rresp    (io_master_rresp),
        .io_master_rdata    (io_master_rdata),
        .io_master_rlast    (io_master_rlast),
        .io_master_rid      (io_master_rid),

        // AXI4 slave: all inputs tied to 0 (unconnected)
        .io_slave_awvalid   (1'b0),
        .io_slave_awaddr    (32'b0),
        .io_slave_awid      (4'b0),
        .io_slave_awlen     (8'b0),
        .io_slave_awsize    (3'b0),
        .io_slave_awburst   (2'b0),
        .io_slave_wvalid    (1'b0),
        .io_slave_wdata     (32'b0),
        .io_slave_wstrb     (4'b0),
        .io_slave_wlast     (1'b0),
        .io_slave_bready    (1'b0),
        .io_slave_arvalid   (1'b0),
        .io_slave_araddr    (32'b0),
        .io_slave_arid      (4'b0),
        .io_slave_arlen     (8'b0),
        .io_slave_arsize    (3'b0),
        .io_slave_arburst   (2'b0),
        .io_slave_rready    (1'b0)
    );

    // -----------------------------------------------------------------------
    // RAM — connected to the DUT master port
    // -----------------------------------------------------------------------
    RAM #(
        .MEM_FILE(`HEX_PATH)
    ) ram (
        .clk            (clk),
        .reset          (reset),

        // AR channel
        .s_axi_araddr   (io_master_araddr),
        .s_axi_arvalid  (io_master_arvalid),
        .s_axi_arready  (io_master_arready),
        .s_axi_arid     (io_master_arid),
        .s_axi_arlen    (io_master_arlen),
        .s_axi_arsize   (io_master_arsize),
        .s_axi_arburst  (io_master_arburst),

        // R channel
        .s_axi_rdata    (io_master_rdata),
        .s_axi_rresp    (io_master_rresp),
        .s_axi_rvalid   (io_master_rvalid),
        .s_axi_rready   (io_master_rready),
        .s_axi_rid      (io_master_rid),
        .s_axi_rlast    (io_master_rlast),

        // AW channel
        .s_axi_awaddr   (io_master_awaddr),
        .s_axi_awvalid  (io_master_awvalid),
        .s_axi_awready  (io_master_awready),
        .s_axi_awid     (io_master_awid),
        .s_axi_awlen    (io_master_awlen),
        .s_axi_awsize   (io_master_awsize),
        .s_axi_awburst  (io_master_awburst),

        // W channel
        .s_axi_wdata    (io_master_wdata),
        .s_axi_wstrb    (io_master_wstrb),
        .s_axi_wvalid   (io_master_wvalid),
        .s_axi_wready   (io_master_wready),
        .s_axi_wlast    (io_master_wlast),

        // B channel
        .s_axi_bresp    (io_master_bresp),
        .s_axi_bvalid   (io_master_bvalid),
        .s_axi_bready   (io_master_bready),
        .s_axi_bid      (io_master_bid)
    );

endmodule
