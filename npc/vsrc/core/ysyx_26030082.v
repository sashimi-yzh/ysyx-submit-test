module ysyx_26030082 #(
    parameter [31:0] RESET_PC = 32'h3000_0000
) (
    input         clock,
    input         reset,
    input         io_interrupt,
    // AXI4 master interface
    input         io_master_awready,
    output        io_master_awvalid,
    output [ 3:0] io_master_awid,
    output [31:0] io_master_awaddr,
    output [ 7:0] io_master_awlen,
    output [ 2:0] io_master_awsize,
    output [ 1:0] io_master_awburst,
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [ 3:0] io_master_wstrb,
    output        io_master_wlast,
    output        io_master_bready,
    input         io_master_bvalid,
    input  [ 3:0] io_master_bid,
    input  [ 1:0] io_master_bresp,
    input         io_master_arready,
    output        io_master_arvalid,
    output [ 3:0] io_master_arid,
    output [31:0] io_master_araddr,
    output [ 7:0] io_master_arlen,
    output [ 2:0] io_master_arsize,
    output [ 1:0] io_master_arburst,
    output        io_master_rready,
    input         io_master_rvalid,
    input  [ 3:0] io_master_rid,
    input  [31:0] io_master_rdata,
    input  [ 1:0] io_master_rresp,
    input         io_master_rlast,
    // AXI4 slave interface (unused)
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [ 3:0] io_slave_awid,
    input  [31:0] io_slave_awaddr,
    input  [ 7:0] io_slave_awlen,
    input  [ 2:0] io_slave_awsize,
    input  [ 1:0] io_slave_awburst,
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [ 3:0] io_slave_wstrb,
    input         io_slave_wlast,
    input         io_slave_bready,
    output        io_slave_bvalid,
    output [ 3:0] io_slave_bid,
    output [ 1:0] io_slave_bresp,
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [ 3:0] io_slave_arid,
    input  [31:0] io_slave_araddr,
    input  [ 7:0] io_slave_arlen,
    input  [ 2:0] io_slave_arsize,
    input  [ 1:0] io_slave_arburst,
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [ 3:0] io_slave_rid,
    output [31:0] io_slave_rdata,
    output [ 1:0] io_slave_rresp,
    output        io_slave_rlast
);

    assign io_slave_awready = 1'b0;
    assign io_slave_wready = 1'b0;
    assign io_slave_bvalid = 1'b0;
    assign io_slave_bid = 4'b0;
    assign io_slave_bresp = 2'b00;
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid = 1'b0;
    assign io_slave_rid = 4'b0;
    assign io_slave_rdata = 32'b0;
    assign io_slave_rresp = 2'b00;
    assign io_slave_rlast = 1'b0;

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
    always @(posedge clock) begin
        if (!reset) begin
            if (io_master_wvalid && io_master_wready && (io_master_wlast != 1'b1)) begin
                $fatal(1, "ysyx_26030082: WLAST must be 1 for single-beat write");
            end
            if (io_master_rvalid && io_master_rready && (io_master_rresp !== 2'b00)) begin
                $fatal(1,
                    "ysyx_26030082: AXI read access fault: resp=%0b rid=%0d",
                    io_master_rresp, io_master_rid);
            end
            if (io_master_bvalid && io_master_bready && (io_master_bresp !== 2'b00)) begin
                $fatal(1,
                    "ysyx_26030082: AXI write access fault: resp=%0b bid=%0d",
                    io_master_bresp, io_master_bid);
            end
        end
    end
`endif
`endif
`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    import "DPI-C" function void npc_commit(
        input int unsigned commit_pc,
        input int unsigned commit_inst,
        input int unsigned pc,
        input int unsigned mstatus,
        input int unsigned mtvec,
        input int unsigned mepc,
        input int unsigned mcause,
        input int unsigned gpr[32]
    );
    import "DPI-C" function void npc_bus_trace(
        input int is_write,
        input int addr,
        input int data,
        input int len
    );
/*
`ifdef NPC_ENABLE_PERF
    import "DPI-C" function void npc_pmu_event(input int event_mask);
`endif
*/
`endif
`endif
`endif

    // IF -> IF/EX
    wire        if_out_valid;
    wire        if_out_ready;
    wire [31:0] if_pc;
    wire [31:0] if_inst;

    // IF/EX
    reg         ex_in_valid;
    wire        ex_in_ready;
    reg  [31:0] ex_pc;
    reg  [31:0] ex_inst;

    // EX
    wire        ex_redirect;
    wire [31:0] ex_redirect_pc;
    wire        ex_fence_i;
    wire        ex_out_valid;

    // IFU AXI4 (read-only in practice)
    wire [31:0] ifu_master_araddr;
    wire [ 7:0] ifu_master_arlen;
    wire [ 1:0] ifu_master_arburst;
    wire        ifu_master_arvalid;
    wire        ifu_master_arready;
    wire [31:0] ifu_master_rdata;
    wire [ 1:0] ifu_master_rresp;
    wire        ifu_master_rlast;
    wire        ifu_master_rvalid;
    wire        ifu_master_rready;

    // EXU LSU AXI4-Lite master
    wire [31:0] lsu_master_araddr;
    wire [ 2:0] lsu_master_arsize;
    wire        lsu_master_arvalid;
    wire        lsu_master_arready;
    wire [31:0] lsu_master_rdata;
    wire [ 1:0] lsu_master_rresp;
    wire        lsu_master_rvalid;
    wire        lsu_master_rready;
    wire [31:0] lsu_master_awaddr;
    wire [ 2:0] lsu_master_awsize;
    wire        lsu_master_awvalid;
    wire        lsu_master_awready;
    wire [31:0] lsu_master_wdata;
    wire [ 3:0] lsu_master_wstrb;
    wire        lsu_master_wvalid;
    wire        lsu_master_wready;
    wire [ 1:0] lsu_master_bresp;
    wire        lsu_master_bvalid;
    wire        lsu_master_bready;
    reg  [63:0] mtime;

////////////////////////////////////////////////////////////////

    always @(posedge clock) begin
        if (reset) begin
            mtime <= 64'b0;
        end else begin
            mtime <= mtime + 64'd1;
        end
    end

    ysyx_26030082_ifu #(
        .RESET_PC           (RESET_PC),
        .LINE_WORDS         (4),
        .LINE_COUNT         (4)
    ) ifu (
        .clock              (clock),
        .reset              (reset),

        .ex_out_valid       (ex_out_valid),
        .ex_redirect        (ex_redirect),
        .ex_redirect_pc     (ex_redirect_pc),
        .ex_fence_i         (ex_fence_i),

        .if_out_valid       (if_out_valid),
        .if_out_ready       (if_out_ready),
        .if_pc              (if_pc),
        .if_inst            (if_inst),

        .ifu_master_araddr  (ifu_master_araddr),
        .ifu_master_arlen   (ifu_master_arlen),
        .ifu_master_arburst (ifu_master_arburst),
        .ifu_master_arvalid (ifu_master_arvalid),
        .ifu_master_arready (ifu_master_arready),
        .ifu_master_rdata   (ifu_master_rdata),
        .ifu_master_rresp   (ifu_master_rresp),
        .ifu_master_rlast   (ifu_master_rlast),
        .ifu_master_rvalid  (ifu_master_rvalid),
        .ifu_master_rready  (ifu_master_rready)
    );
    
    assign if_out_ready = ex_in_ready;

    // ================================================================
    // IF -> EX
    // ================================================================
    always @(posedge clock) begin
        if (reset || (ex_redirect && ex_out_valid)) begin
            ex_in_valid <= 1'b0;
        end else if (if_out_ready) begin
            ex_in_valid <= if_out_valid;
            ex_pc <= if_pc;
            ex_inst <= if_inst;
        end
    end

    ysyx_26030082_exu exu (
        .clock              (clock),
        .reset              (reset),
        .ex_in_valid        (ex_in_valid),
        .ex_in_ready        (ex_in_ready),
        .ex_pc              (ex_pc),
        .ex_inst            (ex_inst),

        .ex_out_valid       (ex_out_valid),

        .ex_mtime           (mtime),

        .ex_redirect        (ex_redirect),
        .ex_redirect_pc     (ex_redirect_pc),
        .ex_fence_i         (ex_fence_i),

        .lsu_master_araddr  (lsu_master_araddr),
        .lsu_master_arsize  (lsu_master_arsize),
        .lsu_master_arvalid (lsu_master_arvalid),
        .lsu_master_arready (lsu_master_arready),
        .lsu_master_rdata   (lsu_master_rdata),
        .lsu_master_rresp   (lsu_master_rresp),
        .lsu_master_rvalid  (lsu_master_rvalid),
        .lsu_master_rready  (lsu_master_rready),
        .lsu_master_awaddr  (lsu_master_awaddr),
        .lsu_master_awsize  (lsu_master_awsize),
        .lsu_master_awvalid (lsu_master_awvalid),
        .lsu_master_awready (lsu_master_awready),
        .lsu_master_wdata   (lsu_master_wdata),
        .lsu_master_wstrb   (lsu_master_wstrb),
        .lsu_master_wvalid  (lsu_master_wvalid),
        .lsu_master_wready  (lsu_master_wready),
        .lsu_master_bresp   (lsu_master_bresp),
        .lsu_master_bvalid  (lsu_master_bvalid),
        .lsu_master_bready  (lsu_master_bready)
    );

    ysyx_26030082_axi4lite_arbiter axi4lite_arbiter (
        .clock              (clock),
        .reset              (reset),

        .ifu_master_araddr  (ifu_master_araddr),
        .ifu_master_arlen   (ifu_master_arlen),
        .ifu_master_arburst (ifu_master_arburst),
        .ifu_master_arvalid (ifu_master_arvalid),
        .ifu_master_arready (ifu_master_arready),
        .ifu_master_rdata   (ifu_master_rdata),
        .ifu_master_rresp   (ifu_master_rresp),
        .ifu_master_rlast   (ifu_master_rlast),
        .ifu_master_rvalid  (ifu_master_rvalid),
        .ifu_master_rready  (ifu_master_rready),

        .lsu_master_araddr  (lsu_master_araddr),
        .lsu_master_arsize  (lsu_master_arsize),
        .lsu_master_arvalid (lsu_master_arvalid),
        .lsu_master_arready (lsu_master_arready),
        .lsu_master_rdata   (lsu_master_rdata),
        .lsu_master_rresp   (lsu_master_rresp),
        .lsu_master_rvalid  (lsu_master_rvalid),
        .lsu_master_rready  (lsu_master_rready),
        .lsu_master_awaddr  (lsu_master_awaddr),
        .lsu_master_awsize  (lsu_master_awsize),
        .lsu_master_awvalid (lsu_master_awvalid),
        .lsu_master_awready (lsu_master_awready),
        .lsu_master_wdata   (lsu_master_wdata),
        .lsu_master_wstrb   (lsu_master_wstrb),
        .lsu_master_wvalid  (lsu_master_wvalid),
        .lsu_master_wready  (lsu_master_wready),
        .lsu_master_bresp   (lsu_master_bresp),
        .lsu_master_bvalid  (lsu_master_bvalid),
        .lsu_master_bready  (lsu_master_bready),

        .io_master_araddr   (io_master_araddr),
        .io_master_arid     (io_master_arid),
        .io_master_arlen    (io_master_arlen),
        .io_master_arsize   (io_master_arsize),
        .io_master_arburst  (io_master_arburst),
        .io_master_arvalid  (io_master_arvalid),
        .io_master_arready  (io_master_arready),
        .io_master_rdata    (io_master_rdata),
        .io_master_rid      (io_master_rid),
        .io_master_rresp    (io_master_rresp),
        .io_master_rlast    (io_master_rlast),
        .io_master_rvalid   (io_master_rvalid),
        .io_master_rready   (io_master_rready),
        .io_master_awaddr   (io_master_awaddr),
        .io_master_awid     (io_master_awid),
        .io_master_awlen    (io_master_awlen),
        .io_master_awsize   (io_master_awsize),
        .io_master_awburst  (io_master_awburst),
        .io_master_awvalid  (io_master_awvalid),
        .io_master_awready  (io_master_awready),
        .io_master_wdata    (io_master_wdata),
        .io_master_wstrb    (io_master_wstrb),
        .io_master_wlast    (io_master_wlast),
        .io_master_wvalid   (io_master_wvalid),
        .io_master_wready   (io_master_wready),
        .io_master_bid      (io_master_bid),
        .io_master_bresp    (io_master_bresp),
        .io_master_bvalid   (io_master_bvalid),
        .io_master_bready   (io_master_bready)
    );

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
    wire lsu_r_fire = lsu_master_rvalid && lsu_master_rready;
    wire lsu_b_fire = lsu_master_bvalid && lsu_master_bready;
    reg [31:0] trace_raddr;
    reg [ 2:0] trace_rsize;
    reg [31:0] trace_waddr;
    reg [ 2:0] trace_wsize;
    reg [31:0] trace_wdata;

    always @(posedge clock) begin
        if (lsu_master_arvalid && lsu_master_arready) begin
            trace_raddr <= lsu_master_araddr;
            trace_rsize <= lsu_master_arsize;
        end
        if (lsu_master_awvalid && lsu_master_awready) begin
            trace_waddr <= lsu_master_awaddr;
            trace_wsize <= lsu_master_awsize;
        end
        if (lsu_master_wvalid && lsu_master_wready) begin
            trace_wdata <= lsu_master_wdata;
        end
        if (!reset && lsu_r_fire) begin
            npc_bus_trace(0, trace_raddr, lsu_master_rdata, 1 << trace_rsize);
        end
        if (!reset && lsu_b_fire) begin
            npc_bus_trace(1, trace_waddr, trace_wdata, 1 << trace_wsize);
        end
    end

    wire commit_is_ebreak = ex_inst == 32'h00100073;
    wire [31:0] commit_next_pc = (ex_redirect && !commit_is_ebreak) ? ex_redirect_pc : ex_pc + 32'd4;
    reg commit_valid_d;
    reg [31:0] commit_pc_d;
    reg [31:0] commit_inst_d;
    reg [31:0] commit_next_pc_d;
    int unsigned commit_gpr[32];

    always @(posedge clock) begin
        if (reset) begin
            commit_valid_d <= 1'b0;
        end else begin
            if (commit_valid_d) begin
                commit_gpr[0] = 32'b0;
                for (int i = 1; i < 16; i++) begin
                    commit_gpr[i] = exu.reg_bank[i];
                end
                for (int i = 16; i < 32; i++) begin
                    commit_gpr[i] = 32'b0;
                end
                npc_commit(
                    commit_pc_d,
                    commit_inst_d,
                    commit_next_pc_d,
                    exu.csr_mstatus,
                    exu.csr_mtvec,
                    exu.csr_mepc,
                    exu.csr_mcause,
                    commit_gpr
                );
            end

            commit_valid_d <= ex_out_valid;
            if (ex_out_valid) begin
                commit_pc_d <= ex_pc;
                commit_inst_d <= ex_inst;
                commit_next_pc_d <= commit_next_pc;
            end
        end
    end
`endif
`endif
`endif

/*
    // ================================================================
    // PMU hooks (simulation-only, kept at module tail to avoid clutter)
    // ================================================================
`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
`ifndef __ICARUS__
`ifdef NPC_ENABLE_PERF
    localparam [31:0] PMU_EVT_IFETCH_FIRE       = 32'h0000_0001;
    localparam [31:0] PMU_EVT_ICACHE_MISS       = 32'h0000_0002;
    localparam [31:0] PMU_EVT_ICACHE_MISS_CYCLE = 32'h0000_0004;
    localparam [31:0] PMU_EVT_DCACHE_ACCESS     = 32'h0000_0008;
    localparam [31:0] PMU_EVT_DCACHE_STORE      = 32'h0000_0010;
    localparam [31:0] PMU_EVT_DCACHE_MISS       = 32'h0000_0020;
    localparam [31:0] PMU_EVT_DCACHE_MISS_CYCLE = 32'h0000_0040;
    localparam [31:0] PMU_EVT_REDIRECT          = 32'h0000_0080;

    localparam [1:0] PMU_ICACHE_LOOKUP  = 2'd0;
    localparam [1:0] PMU_ICACHE_MISS_AR = 2'd1;
    localparam [1:0] PMU_ICACHE_MISS_R  = 2'd2;

    localparam PMU_LSU_R_IDLE = 1'd0;
    localparam [1:0] PMU_LSU_W_IDLE = 2'd0;

    reg  [31:0] pmu_event_mask;

    // Direct hierarchical reads: simulation-only, no extra submodule ports.
    wire pmu_ifetch_fire = if_out_valid && if_out_ready;
    wire pmu_icache_miss = (ifu.state == PMU_ICACHE_LOOKUP) && ~ifu.icache_hit;
    wire pmu_icache_miss_cycle =
        (ifu.state == PMU_ICACHE_MISS_AR) ||
        (ifu.state == PMU_ICACHE_MISS_R);
    wire pmu_dcache_access = (exu.rd_state == PMU_LSU_R_IDLE) &&
                             (exu.wr_state == PMU_LSU_W_IDLE) &&
                             (exu.ext_load_req || exu.ext_store_req);
    wire pmu_dcache_store = pmu_dcache_access && exu.mem_wen;
    wire pmu_dcache_miss_cycle = ex_in_valid && !ex_in_ready &&
                                 (exu.ext_load_req || exu.ext_store_req);
    wire pmu_redirect = ex_out_valid && ex_redirect;

    always @(*) begin
        pmu_event_mask = 32'b0;

        if (!reset) begin
            if (pmu_ifetch_fire) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_IFETCH_FIRE;
            end
            if (pmu_icache_miss) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_ICACHE_MISS;
            end
            if (pmu_icache_miss_cycle) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_ICACHE_MISS_CYCLE;
            end
            if (pmu_dcache_access) begin
                pmu_event_mask = pmu_event_mask |
                                 PMU_EVT_DCACHE_ACCESS |
                                 PMU_EVT_DCACHE_MISS;
            end
            if (pmu_dcache_store) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_DCACHE_STORE;
            end
            if (pmu_dcache_miss_cycle) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_DCACHE_MISS_CYCLE;
            end
            if (pmu_redirect) begin
                pmu_event_mask = pmu_event_mask | PMU_EVT_REDIRECT;
            end
        end
    end

    always @(posedge clock) begin
        if (!reset && (pmu_event_mask != 32'b0)) begin
            npc_pmu_event(pmu_event_mask);
        end
    end
`endif
`endif
`endif
*/


    wire _unused_ok = &{1'b0,
        io_interrupt,
        io_slave_awvalid, io_slave_awid, io_slave_awaddr, io_slave_awlen, io_slave_awsize, io_slave_awburst,
        io_slave_wvalid, io_slave_wdata, io_slave_wstrb, io_slave_wlast, io_slave_bready,
        io_slave_arvalid, io_slave_arid, io_slave_araddr, io_slave_arlen, io_slave_arsize, io_slave_arburst,
        io_slave_rready
    };

endmodule
