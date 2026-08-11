`ifdef NPC_SIMULATION
`define YSYX_26010028_LOCAL_COMMIT_PORTS
`elsif __ICARUS__
`define YSYX_26010028_LOCAL_COMMIT_PORTS
`endif

module ysyx_26010028 #(
    parameter [31:0] RESET_PC = 32'h3000_0000
) (
    input         clock,
    input         reset,
    input         io_interrupt,

`ifdef YSYX_26010028_LOCAL_COMMIT_PORTS
    output        commit_valid_out,
    output [31:0] commit_pc_out,
    output [31:0] commit_inst_out,
`endif

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

    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [ 3:0] io_slave_awid,
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
    output [ 1:0] io_slave_bresp,
    output [ 3:0] io_slave_bid,
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [ 3:0] io_slave_arid,
    input  [ 7:0] io_slave_arlen,
    input  [ 2:0] io_slave_arsize,
    input  [ 1:0] io_slave_arburst,
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [ 1:0] io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [ 3:0] io_slave_rid
);

    wire        fetch_valid;
    wire        fetch_ready;
    wire [31:0] fetch_pc;
    wire [31:0] fetch_inst;

    wire        decode_valid;
    wire        decode_ready;
    wire [31:0] decode_pc;
    wire [31:0] decode_inst;
    wire [ 6:0] decode_opcode;
    wire [ 2:0] decode_funct3;
    wire [ 6:0] decode_funct7;
    wire [ 4:0] decode_rd;
    wire [11:0] decode_csr_addr;
    wire [31:0] decode_rs1;
    wire [31:0] decode_rs2;
    wire [31:0] decode_imm;
    wire        decode_writes_rd;
    wire        decode_load;
    wire        decode_store;
    wire        decode_fence_i;

    wire        retire_valid;
    wire [31:0] retire_pc;
    wire [31:0] retire_inst;
    wire [31:0] retire_next_pc;
    wire        redirect_valid;
    wire [31:0] redirect_pc;
    wire        fence_i_done;

    wire        writeback_valid;
    wire [ 4:0] writeback_rd;
    wire [31:0] writeback_data;

    wire [31:0] if_araddr;
    wire [ 7:0] if_arlen;
    wire [ 1:0] if_arburst;
    wire        if_arvalid;
    wire        if_arready;
    wire [31:0] if_rdata;
    wire [ 1:0] if_rresp;
    wire        if_rlast;
    wire        if_rvalid;
    wire        if_rready;

    wire [31:0] data_araddr;
    wire [ 2:0] data_arsize;
    wire        data_arvalid;
    wire        data_arready;
    wire [31:0] data_rdata;
    wire [ 1:0] data_rresp;
    wire        data_rvalid;
    wire        data_rready;
    wire [31:0] data_awaddr;
    wire [ 2:0] data_awsize;
    wire        data_awvalid;
    wire        data_awready;
    wire [31:0] data_wdata;
    wire [ 3:0] data_wstrb;
    wire        data_wvalid;
    wire        data_wready;
    wire [ 1:0] data_bresp;
    wire        data_bvalid;
    wire        data_bready;

    wire [1023:0] gpr_probe_bus;
    wire [31:0] csr_probe_status;
    wire [31:0] csr_probe_vector;
    wire [31:0] csr_probe_epc;
    wire [31:0] csr_probe_cause;

    reg [63:0] cycle_counter;
    always @(posedge clock) begin
        if (reset) begin
            cycle_counter <= 64'b0;
        end else begin
            cycle_counter <= cycle_counter + 64'd1;
        end
    end

    ysyx_26010028_ifu #(
        .RESET_PC (RESET_PC)
    ) ifu (
        .clock           (clock),
        .reset           (reset),
        .exu_allow_in    (retire_valid),
        .exu_redirect    (redirect_valid),
        .exu_redirect_pc (redirect_pc),
        .exu_fence       (fence_i_done),
        .if_valid        (fetch_valid),
        .if_ready        (fetch_ready),
        .inst_pc         (fetch_pc),
        .inst            (fetch_inst),
        .ifu_araddr      (if_araddr),
        .ifu_arlen       (if_arlen),
        .ifu_arburst     (if_arburst),
        .ifu_arvalid     (if_arvalid),
        .ifu_arready     (if_arready),
        .ifu_rdata       (if_rdata),
        .ifu_rresp       (if_rresp),
        .ifu_rlast       (if_rlast),
        .ifu_rvalid      (if_rvalid),
        .ifu_rready      (if_rready)
    );

    ysyx_26010028_idu #(
        .RESET_PC (RESET_PC)
    ) idu (
        .clock              (clock),
        .reset              (reset),

        .id_in_valid        (fetch_valid),
        .id_in_ready        (fetch_ready),
        .id_in_pc           (fetch_pc),
        .id_in_inst         (fetch_inst),

        .id_flush           (retire_valid && redirect_valid),

        .id_out_valid       (decode_valid),
        .id_out_ready       (decode_ready),
        .id_out_pc          (decode_pc),
        .id_out_inst        (decode_inst),
        .id_out_opcode      (decode_opcode),
        .id_out_funct3      (decode_funct3),
        .id_out_funct7      (decode_funct7),
        .id_out_rd          (decode_rd),
        .id_out_csr_addr    (decode_csr_addr),
        .id_out_rs1_val     (decode_rs1),
        .id_out_rs2_val     (decode_rs2),
        .id_out_imm         (decode_imm),
        .id_out_rf_wen      (decode_writes_rd),
        .id_out_mem_ren     (decode_load),
        .id_out_mem_wen     (decode_store),
        .id_out_fence_i     (decode_fence_i),

        .wb_rf_wen          (writeback_valid),
        .wb_rf_waddr        (writeback_rd),
        .wb_rf_wdata        (writeback_data),
        .gpr_probe_bus (gpr_probe_bus)
    );

    ysyx_26010028_exu exu (
        .clock               (clock),
        .reset               (reset),
        // IDU input signals
        .pipe_valid         (decode_valid),
        .pipe_ready         (decode_ready),
        .pipe_pc               (decode_pc),
        .pipe_inst             (decode_inst),
        .pipe_opcode           (decode_opcode),
        .pipe_funct3           (decode_funct3),
        .pipe_funct7           (decode_funct7),
        .pipe_rd               (decode_rd),
        .pipe_csr_addr         (decode_csr_addr),
        .pipe_rs1_value          (decode_rs1),
        .pipe_rs2_value          (decode_rs2),
        .pipe_imm              (decode_imm),
        .pipe_rf_wen           (decode_writes_rd),
        .pipe_load          (decode_load),
        .pipe_store          (decode_store),
        .pipe_fence_i       (decode_fence_i),
        // the ports for commit units
        .retire_valid        (retire_valid),
        .retire_pc           (retire_pc),
        .retire_inst         (retire_inst),
        .retire_next_pc      (retire_next_pc),
        .mtime_value            (cycle_counter),
        // redirect for frontend
        .redirect_valid         (redirect_valid),
        .redirect_pc      (redirect_pc),
        .fence_done          (fence_i_done),
        // write back for IDU (RegisterFiles)
        .wb_rf_wen           (writeback_valid),
        .wb_rf_waddr         (writeback_rd),
        .wb_rf_wdata         (writeback_data),
        // the ports for commit units (csr)
        .csr_probe_status   (csr_probe_status),
        .csr_probe_vector     (csr_probe_vector),
        .csr_probe_epc      (csr_probe_epc),
        .csr_probe_cause    (csr_probe_cause),
        // LSU read tunnel
        .lsu_master_araddr   (data_araddr),
        .lsu_master_arsize   (data_arsize),
        .lsu_master_arvalid  (data_arvalid),
        .lsu_master_arready  (data_arready),
        .lsu_master_rdata    (data_rdata),
        .lsu_master_rresp    (data_rresp),
        .lsu_master_rvalid   (data_rvalid),
        .lsu_master_rready   (data_rready),
        // LSU write tunnel
        .lsu_master_awaddr   (data_awaddr),
        .lsu_master_awsize   (data_awsize),
        .lsu_master_awvalid  (data_awvalid),
        .lsu_master_awready  (data_awready),
        .lsu_master_wdata    (data_wdata),
        .lsu_master_wstrb    (data_wstrb),
        .lsu_master_wvalid   (data_wvalid),
        .lsu_master_wready   (data_wready),
        .lsu_master_bresp    (data_bresp),
        .lsu_master_bvalid   (data_bvalid),
        .lsu_master_bready   (data_bready)
    );

    ysyx_26010028_axilit_arbiter bus_arbiter (
        .clk          (clock),
        .rst          (reset),
        .ifu_araddr   (if_araddr),
        .ifu_arlen    (if_arlen),
        .ifu_arburst  (if_arburst),
        .ifu_arvalid  (if_arvalid),
        .ifu_arready  (if_arready),
        .ifu_rdata    (if_rdata),
        .ifu_rresp    (if_rresp),
        .ifu_rlast    (if_rlast),
        .ifu_rvalid   (if_rvalid),
        .ifu_rready   (if_rready),
        .lsu_araddr   (data_araddr),
        .lsu_arsize   (data_arsize),
        .lsu_arvalid  (data_arvalid),
        .lsu_arready  (data_arready),
        .lsu_rdata    (data_rdata),
        .lsu_rresp    (data_rresp),
        .lsu_rvalid   (data_rvalid),
        .lsu_rready   (data_rready),
        .lsu_awaddr   (data_awaddr),
        .lsu_awsize   (data_awsize),
        .lsu_awvalid  (data_awvalid),
        .lsu_awready  (data_awready),
        .lsu_wdata    (data_wdata),
        .lsu_wstrb    (data_wstrb),
        .lsu_wvalid   (data_wvalid),
        .lsu_wready   (data_wready),
        .lsu_bresp    (data_bresp),
        .lsu_bvalid   (data_bvalid),
        .lsu_bready   (data_bready),
        .axi_araddr   (io_master_araddr),
        .axi_arid     (io_master_arid),
        .axi_arlen    (io_master_arlen),
        .axi_arsize   (io_master_arsize),
        .axi_arburst  (io_master_arburst),
        .axi_arvalid  (io_master_arvalid),
        .axi_arready  (io_master_arready),
        .axi_rdata    (io_master_rdata),
        .axi_rid      (io_master_rid),
        .axi_rresp    (io_master_rresp),
        .axi_rlast    (io_master_rlast),
        .axi_rvalid   (io_master_rvalid),
        .axi_rready   (io_master_rready),
        .axi_awaddr   (io_master_awaddr),
        .axi_awid     (io_master_awid),
        .axi_awlen    (io_master_awlen),
        .axi_awsize   (io_master_awsize),
        .axi_awburst  (io_master_awburst),
        .axi_awvalid  (io_master_awvalid),
        .axi_awready  (io_master_awready),
        .axi_wdata    (io_master_wdata),
        .axi_wstrb    (io_master_wstrb),
        .axi_wlast    (io_master_wlast),
        .axi_wvalid   (io_master_wvalid),
        .axi_wready   (io_master_wready),
        .axi_bresp    (io_master_bresp),
        .axi_bvalid   (io_master_bvalid),
        .axi_bready   (io_master_bready)
    );

    ysyx_26010028_commit_monitor monitor (
        .clock          (clock),
        .reset          (reset),

        .retire_valid   (retire_valid),
        .retire_pc      (retire_pc),
        .retire_inst    (retire_inst),
        .retire_next_pc (retire_next_pc),
        .gpr_snapshot   (gpr_probe_bus),
        .csr_mstatus    (csr_probe_status),
        .csr_mtvec      (csr_probe_vector),
        .csr_mepc       (csr_probe_epc),
        .csr_mcause     (csr_probe_cause),

        .axi_w_fire     (io_master_wvalid && io_master_wready),
        .axi_wlast      (io_master_wlast),

        .axi_ar_fire    (io_master_arvalid && io_master_arready),
        .axi_araddr     (io_master_araddr),
        .axi_arlen      (io_master_arlen),
        .axi_arsize     (io_master_arsize),

        .axi_r_fire     (io_master_rvalid && io_master_rready),
        .axi_rresp      (io_master_rresp),
        .axi_rlast      (io_master_rlast),

        .axi_b_fire     (io_master_bvalid && io_master_bready),
        .axi_bresp      (io_master_bresp),

        .axi_aw_fire    (io_master_awvalid && io_master_awready),
        .axi_awaddr     (io_master_awaddr),
        .axi_awlen      (io_master_awlen),
        .axi_awsize     (io_master_awsize),

        .trace_ar_fire  (data_arvalid && data_arready),
        .trace_araddr   (data_araddr),
        .trace_arsize   (data_arsize),
        .trace_r_fire   (data_rvalid && data_rready),
        .trace_rdata    (data_rdata),
        .trace_aw_fire  (data_awvalid && data_awready),
        .trace_awaddr   (data_awaddr),
        .trace_awsize   (data_awsize),
        .trace_w_fire   (data_wvalid && data_wready),
        .trace_store_data    (data_wdata),
        .trace_b_fire   (data_bvalid && data_bready)
    );

`ifdef YSYX_26010028_LOCAL_COMMIT_PORTS
    assign commit_valid_out = retire_valid;
    assign commit_pc_out    = retire_pc;
    assign commit_inst_out  = retire_inst;
`endif

    // The CPU does not currently implement a DMA-facing AXI slave.
    assign io_slave_awready = 1'b0;
    assign io_slave_wready  = 1'b0;
    assign io_slave_bvalid  = 1'b0;
    assign io_slave_bresp   = 2'b0;
    assign io_slave_bid     = 4'b0;
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid  = 1'b0;
    assign io_slave_rresp   = 2'b0;
    assign io_slave_rdata   = 32'b0;
    assign io_slave_rlast   = 1'b0;
    assign io_slave_rid     = 4'b0;

    wire _unused_ok = &{
        1'b0, io_interrupt, io_master_bid,
        io_slave_awvalid, io_slave_awaddr, io_slave_awid,
        io_slave_awlen, io_slave_awsize, io_slave_awburst,
        io_slave_wvalid, io_slave_wdata, io_slave_wstrb, io_slave_wlast,
        io_slave_bready, io_slave_arvalid, io_slave_araddr, io_slave_arid,
        io_slave_arlen, io_slave_arsize, io_slave_arburst, io_slave_rready
    };

endmodule

`ifdef YSYX_26010028_LOCAL_COMMIT_PORTS
`undef YSYX_26010028_LOCAL_COMMIT_PORTS
`endif
