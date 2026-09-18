`ifdef NPC_SIM
import "DPI-C" function void finish_sim();
import "DPI-C" function void ftrace_print(int pc, int target, int rd, int rs1);
import "DPI-C" function void is_illegal_inst();
import "DPI-C" function void get_reg(input int waddr, input int r);
import "DPI-C" function void get_csr(input int csr, input int data);
import "DPI-C" function void get_cpu_state(input int lsu_get_data, input int lsu_w_data, input int exu_done, input int alu_we, input int csr_we, input int cpu_jump, input int cpu_branch, input int icache_hit, input int icache_miss, input int icache_miss_latency);
import "DPI-C" function void cpu_trace(input int pc, input int inst);
import "DPI-C" function void ifu_trace(input int pc, input int inst);
`endif

module ysyx_26010027 (
    // ----- MASTER -----
    // AR
    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [ 3:0] io_master_arid,
    output [ 7:0] io_master_arlen,
    output [ 2:0] io_master_arsize,
    output [ 1:0] io_master_arburst,
    // R
    output        io_master_rready,
    input         io_master_rvalid,
    input  [31:0] io_master_rdata,
    input  [ 1:0] io_master_rresp,
    input  [ 3:0] io_master_rid,
    input         io_master_rlast,
    // AW
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [ 3:0] io_master_awid,
    output [ 7:0] io_master_awlen,
    output [ 2:0] io_master_awsize,
    output [ 1:0] io_master_awburst,
    // W
    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [ 3:0] io_master_wstrb,
    output        io_master_wlast,
    // B
    input         io_master_bvalid,
    output        io_master_bready,
    input  [ 1:0] io_master_bresp,
    input  [ 3:0] io_master_bid,

    // ----- SLAVE -----
    // AR
    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [ 3:0] io_slave_arid,
    input  [ 7:0] io_slave_arlen,
    input  [ 2:0] io_slave_arsize,
    input  [ 1:0] io_slave_arburst,
    // R
    input         io_slave_rready,
    output        io_slave_rvalid,
    output [31:0] io_slave_rdata,
    output [ 1:0] io_slave_rresp,
    output [ 3:0] io_slave_rid,
    output        io_slave_rlast,
    // AW
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [ 3:0] io_slave_awid,
    input  [ 7:0] io_slave_awlen,
    input  [ 2:0] io_slave_awsize,
    input  [ 1:0] io_slave_awburst,
    // W
    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [ 3:0] io_slave_wstrb,
    input         io_slave_wlast,
    // B
    output        io_slave_bvalid,
    input         io_slave_bready,
    output [ 1:0] io_slave_bresp,
    output [ 3:0] io_slave_bid,

    input         io_interrupt,

    input         clock,
    input         reset
);

    // Arbiter 相关信号
    wire        arb_arvalid;
    wire        arb_arready;
    wire [31:0] arb_araddr;
    wire [ 3:0] arb_arid;
    wire [ 7:0] arb_arlen;
    wire [ 2:0] arb_arsize;
    wire [ 1:0] arb_arburst;
    wire        arb_rvalid;
    wire        arb_rready;
    wire [31:0] arb_rdata;
    wire [ 1:0] arb_rresp;
    wire [ 3:0] arb_rid;
    wire        arb_rlast;

    wire        arb_awvalid;
    wire        arb_awready;
    wire [31:0] arb_awaddr;
    wire [ 3:0] arb_awid;
    wire [ 7:0] arb_awlen;
    wire [ 2:0] arb_awsize;
    wire [ 1:0] arb_awburst;
    wire        arb_wvalid;
    wire        arb_wready;
    wire [31:0] arb_wdata;
    wire [ 3:0] arb_wstrb;
    wire        arb_wlast;
    wire        arb_bvalid;
    wire        arb_bready;
    wire [ 1:0] arb_bresp;
    wire [ 3:0] arb_bid;

    // ----- IFU -----
    // IFU -> IDU
    wire        ifu_idu_valid;
    wire        idu_ifu_ready;
    wire [31:0] ifu_idu_pc;
    wire [31:0] ifu_idu_inst;

    // IFU - icache
    wire        cpu_ifu_arready;
    wire [31:0] ifu_cpu_araddr;
    wire        ifu_cpu_arvalid;
    wire        cpu_ifu_rvalid;
    wire        ifu_cpu_rready;
    wire [31:0] cpu_ifu_rdata;
    wire [ 1:0] cpu_ifu_rresp;

// ----- 内存路由 -----
    assign io_master_arvalid = arb_arvalid;
    assign io_master_araddr  = arb_araddr;
    assign io_master_arid    = arb_arid;
    assign io_master_arlen   = arb_arlen;
    assign io_master_arsize  = arb_arsize;
    assign io_master_arburst = arb_arburst;
    assign io_master_rready  = arb_rready;
    assign arb_arready = io_master_arready;
    assign arb_rvalid  = io_master_rvalid;
    assign arb_rdata   = io_master_rdata;
    assign arb_rresp   = io_master_rresp;
    assign arb_rid     = io_master_rid;
    assign arb_rlast   = io_master_rlast;

    assign io_master_awvalid = arb_awvalid;
    assign io_master_awaddr  = arb_awaddr;
    assign io_master_awid    = arb_awid;
    assign io_master_awlen   = arb_awlen;
    assign io_master_awsize  = arb_awsize;
    assign io_master_awburst = arb_awburst;
    assign arb_awready = io_master_awready;

    assign io_master_wvalid = arb_wvalid;
    assign io_master_wdata  = arb_wdata;
    assign io_master_wstrb  = arb_wstrb;
    assign io_master_wlast  = arb_wlast;
    assign arb_wready = io_master_wready;

    assign arb_bvalid = io_master_bvalid;
    assign arb_bresp  = io_master_bresp;
    assign arb_bid    = io_master_bid;
    assign io_master_bready = arb_bready;

    // io_slave
    assign io_slave_arready = 1'b0;
    assign io_slave_rvalid  = 1'b0;
    assign io_slave_rdata   = 32'b0;
    assign io_slave_rresp   = 2'b0;
    assign io_slave_rid     = 4'b0;
    assign io_slave_rlast   = 1'b0;
    assign io_slave_awready = 1'b0;
    assign io_slave_wready  = 1'b0;
    assign io_slave_bvalid  = 1'b0;
    assign io_slave_bresp   = 2'b0;
    assign io_slave_bid     = 4'b0;

    // ----- unused -----
    wire unused_ok = &{io_slave_arvalid, io_slave_araddr, io_slave_arid, io_slave_arlen,
                       io_slave_arsize, io_slave_arburst, io_slave_rready,
                       io_slave_awvalid, io_slave_awaddr, io_slave_awid, io_slave_awlen,
                       io_slave_awsize, io_slave_awburst, io_slave_wvalid, io_slave_wdata,
                       io_slave_wstrb, io_slave_wlast, io_slave_bready, io_interrupt,
                       arb_rid, arb_rlast, arb_bid, 1'b1};
    // ------------------

    // --- icache -> arbiter ---
    wire        icache_arvalid;
    wire        icache_arready;
    wire [31:0] icache_araddr;
    wire [ 7:0] icache_arlen;
    wire [ 3:0] icache_arid;
    wire [ 2:0] icache_arsize;
    wire [ 1:0] icache_arburst;
    wire        icache_rvalid;
    wire        icache_rready;
    wire [31:0] icache_rdata;
    wire [ 1:0] icache_rresp;

    // --- IDU -> EXU ---
    wire        exu_idu_ready;
    wire        idu_exu_valid;
    wire [31:0] idu_exu_pc;
    wire [31:0] idu_exu_inst;
    wire [31:0] idu_exu_imm;
    wire [31:0] idu_exu_target;
    wire [ 3:0] idu_exu_alu_op;
    wire [ 1:0] idu_exu_mem_w;
    wire [ 2:0] idu_exu_mem_r;
    wire        idu_exu_alu_arc1;
    wire        idu_exu_alu_arc2;
    wire        idu_exu_reg_w;
    wire [ 1:0] idu_exu_rf_res;
    wire [ 3:0] idu_exu_waddr;
    wire [ 1:0] idu_exu_jump;
    wire [ 2:0] idu_exu_branch;
    wire        idu_exu_fencei;

    wire [ 3:0] idu_exu_raddr1;
    wire [ 3:0] idu_exu_raddr2;

    wire [11:0] idu_exu_csr_addr;
    wire        idu_exu_csr_we;
    wire        idu_exu_csr_ecall;
    wire        idu_exu_csr_mret;

    // ----- EXU -> LSU -----
    wire        lsu_exu_ready;
    wire        exu_lsu_valid;
    wire [31:0] exu_lsu_pc;
    wire [31:0] exu_lsu_snpc;
    wire [31:0] exu_lsu_inst;
    wire [ 1:0] exu_lsu_mem_w;
    wire [ 2:0] exu_lsu_mem_r;
    wire [31:0] exu_lsu_mem_addr;
    wire [31:0] exu_lsu_wdata;
    wire        exu_lsu_reg_w;
    wire [ 1:0] exu_lsu_rf_res;
    wire [ 3:0] exu_lsu_waddr;
    wire [31:0] exu_lsu_alu_result;

    wire [11:0] exu_lsu_csr_waddr;
    wire        exu_lsu_csr_we;
    wire        exu_lsu_csr_ecall;
    wire        exu_lsu_csr_mret;
    wire [31:0] exu_lsu_csr_wdata;

    // flush
    wire        exu_flush;
    wire [31:0] exu_flush_pc;

    // --- LSU -> WBU ---
    wire        wbu_lsu_ready;
    wire        lsu_wbu_valid;
    wire [31:0] lsu_wbu_pc;
    wire [31:0] lsu_wbu_snpc;
    wire [31:0] lsu_wbu_inst;
    wire        lsu_wbu_reg_w;
    wire [ 1:0] lsu_wbu_rf_res;
    wire [ 3:0] lsu_wbu_waddr;
    wire [31:0] lsu_wbu_alu_result;
    wire [31:0] lsu_wbu_mem_result;

    wire        lsu_exu_inflight;
    wire [11:0] lsu_wbu_csr_waddr;
    wire        lsu_wbu_csr_we;
    wire        lsu_wbu_csr_ecall;
    wire        lsu_wbu_csr_mret;
    wire [31:0] lsu_wbu_csr_wdata;

`ifdef NPC_SIM
    wire [31:0] exu_lsu_dnpc;
    wire [31:0] lsu_wbu_dnpc;
    wire        lsu_wbu_mem_en;
    wire [31:0] lsu_wbu_mem_addr;
    // ----- unused -----
    wire unused = &{lsu_wbu_dnpc, lsu_wbu_mem_en, lsu_wbu_mem_addr, 1'b1};
    // ------------------
`endif

    // LSU 侧 AXI（连接 arbiter）
    wire        cpu_lsu_arready;
    wire [31:0] lsu_cpu_araddr;
    wire        lsu_cpu_arvalid;
    wire [ 3:0] lsu_cpu_arid;
    wire [ 7:0] lsu_cpu_arlen;
    wire [ 2:0] lsu_cpu_arsize;
    wire [ 1:0] lsu_cpu_arburst;

    wire        cpu_lsu_rvalid;
    wire        lsu_cpu_rready;
    wire [31:0] cpu_lsu_rdata;
    wire [ 1:0] cpu_lsu_rresp;

    wire        cpu_lsu_awready;
    wire [31:0] lsu_cpu_awaddr;
    wire        lsu_cpu_awvalid;
    wire [ 3:0] lsu_cpu_awid;
    wire [ 7:0] lsu_cpu_awlen;
    wire [ 2:0] lsu_cpu_awsize;
    wire [ 1:0] lsu_cpu_awburst;

    wire        cpu_lsu_wready;
    wire [31:0] lsu_cpu_wdata;
    wire [ 3:0] lsu_cpu_wstrb;
    wire        lsu_cpu_wvalid;
    wire        lsu_cpu_wlast;

    wire        cpu_lsu_bvalid;
    wire        lsu_cpu_bready;
    wire [ 1:0] cpu_lsu_bresp;

    // --- WBU ---
    wire [31:0] wbu_exu_rdata1;
    wire [31:0] wbu_exu_rdata2;
    wire [31:0] wbu_exu_csr_rdata;
    wire [31:0] wbu_exu_mtvec;
    wire [31:0] wbu_exu_mepc;

    ysyx_26010027_icache my_icache (
        .clock       (clock),
        .reset       (reset),
        .flush_i     (idu_exu_valid && idu_exu_fencei),

        .ifu_araddr  (ifu_cpu_araddr),
        .ifu_arvalid (ifu_cpu_arvalid),
        .ifu_arready (cpu_ifu_arready),
        .ifu_rdata   (cpu_ifu_rdata),
        .ifu_rvalid  (cpu_ifu_rvalid),
        .ifu_rready  (ifu_cpu_rready),
        .ifu_rresp   (cpu_ifu_rresp),

        .arb_araddr  (icache_araddr),
        .arb_arvalid (icache_arvalid),
        .arb_arready (icache_arready),
        .arb_arid    (icache_arid),
        .arb_rdata   (icache_rdata),
        .arb_rvalid  (icache_rvalid),
        .arb_rready  (icache_rready),
        .arb_rresp   (icache_rresp),
        .arb_arlen   (icache_arlen),
        .arb_arsize  (icache_arsize),
        .arb_arburst (icache_arburst)

    );

    ysyx_26010027_IFU my_IFU (
        .clock          (clock),
        .reset          (reset),

        .ifu_idu_valid  (ifu_idu_valid),
        .idu_ifu_ready  (idu_ifu_ready),
        .ifu_idu_pc     (ifu_idu_pc),
        .ifu_idu_inst   (ifu_idu_inst),

        .exu_flush      (exu_flush),
        .exu_flush_pc   (exu_flush_pc),

        .cpu_ifu_arready(cpu_ifu_arready),
        .ifu_cpu_araddr (ifu_cpu_araddr),
        .ifu_cpu_arvalid(ifu_cpu_arvalid),

        .cpu_ifu_rvalid (cpu_ifu_rvalid),
        .ifu_cpu_rready (ifu_cpu_rready),
        .cpu_ifu_rdata  (cpu_ifu_rdata),
        .cpu_ifu_rresp  (cpu_ifu_rresp)
    );


    // ----- IDU -----
    ysyx_26010027_IDU my_IDU (
        .clock            (clock),
        .reset            (reset),

        .ifu_idu_valid    (ifu_idu_valid),
        .idu_ifu_ready    (idu_ifu_ready),
        .ifu_idu_pc       (ifu_idu_pc),
        .ifu_idu_inst     (ifu_idu_inst),

        .exu_idu_ready    (exu_idu_ready),
        .idu_exu_valid    (idu_exu_valid),
        .idu_exu_pc       (idu_exu_pc),
        .idu_exu_inst     (idu_exu_inst),
        .idu_exu_target   (idu_exu_target),
        .idu_exu_imm      (idu_exu_imm),
        .idu_exu_alu_op   (idu_exu_alu_op),
        .idu_exu_mem_w    (idu_exu_mem_w),
        .idu_exu_mem_r    (idu_exu_mem_r),
        .idu_exu_alu_arc1 (idu_exu_alu_arc1),
        .idu_exu_alu_arc2 (idu_exu_alu_arc2),
        .idu_exu_reg_w    (idu_exu_reg_w),
        .idu_exu_rf_res   (idu_exu_rf_res),
        .idu_exu_waddr    (idu_exu_waddr),
        .idu_exu_jump     (idu_exu_jump),
        .idu_exu_branch   (idu_exu_branch),
        .idu_exu_fencei   (idu_exu_fencei),

        .exu_flush        (exu_flush),

        .idu_exu_raddr1   (idu_exu_raddr1),
        .idu_exu_raddr2   (idu_exu_raddr2),

        .idu_exu_csr_addr (idu_exu_csr_addr),
        .idu_exu_csr_we   (idu_exu_csr_we),
        .idu_exu_csr_ecall(idu_exu_csr_ecall),
        .idu_exu_csr_mret (idu_exu_csr_mret)

    );


    // ----- EXU -----
    ysyx_26010027_EXU my_EXU (
        .clock  (clock),
        .reset  (reset),

        .idu_exu_valid    (idu_exu_valid),
        .exu_idu_ready    (exu_idu_ready),
        .idu_exu_pc       (idu_exu_pc),
        .idu_exu_inst     (idu_exu_inst),
        .idu_exu_imm      (idu_exu_imm),
        .idu_exu_target   (idu_exu_target),
        .idu_exu_alu_op   (idu_exu_alu_op),
        .idu_exu_mem_w    (idu_exu_mem_w),
        .idu_exu_mem_r    (idu_exu_mem_r),
        .idu_exu_alu_arc1 (idu_exu_alu_arc1),
        .idu_exu_alu_arc2 (idu_exu_alu_arc2),
        .idu_exu_reg_w    (idu_exu_reg_w),
        .idu_exu_rf_res   (idu_exu_rf_res),
        .idu_exu_waddr    (idu_exu_waddr),
        .idu_exu_jump     (idu_exu_jump),
        .idu_exu_branch   (idu_exu_branch),
        .idu_exu_fencei   (idu_exu_fencei),
        .idu_exu_csr_we   (idu_exu_csr_we),
        .idu_exu_csr_ecall(idu_exu_csr_ecall),
        .idu_exu_csr_mret (idu_exu_csr_mret),

        .lsu_exu_ready     (lsu_exu_ready),
        .exu_lsu_valid     (exu_lsu_valid),
        .exu_lsu_pc        (exu_lsu_pc),
        .exu_lsu_snpc      (exu_lsu_snpc),
        .exu_lsu_inst      (exu_lsu_inst),
        .exu_lsu_mem_w     (exu_lsu_mem_w),
        .exu_lsu_mem_r     (exu_lsu_mem_r),
        .exu_lsu_mem_addr  (exu_lsu_mem_addr),
        .exu_lsu_wdata     (exu_lsu_wdata),
        .exu_lsu_reg_w     (exu_lsu_reg_w),
        .exu_lsu_rf_res    (exu_lsu_rf_res),
        .exu_lsu_waddr     (exu_lsu_waddr),
        .exu_lsu_alu_result(exu_lsu_alu_result),
        .exu_lsu_csr_waddr (exu_lsu_csr_waddr),
        .exu_lsu_csr_we    (exu_lsu_csr_we),
        .exu_lsu_csr_ecall (exu_lsu_csr_ecall),
        .exu_lsu_csr_mret  (exu_lsu_csr_mret),
        .exu_lsu_csr_wdata (exu_lsu_csr_wdata),

        .exu_flush         (exu_flush),
        .exu_flush_pc      (exu_flush_pc),

`ifdef NPC_SIM
        .exu_lsu_dnpc      (exu_lsu_dnpc),
`endif

        .lsu_wbu_valid     (lsu_wbu_valid),
        .lsu_wbu_reg_w     (lsu_wbu_reg_w),
        .lsu_wbu_rf_res    (lsu_wbu_rf_res),
        .idu_exu_raddr1    (idu_exu_raddr1),
        .idu_exu_raddr2    (idu_exu_raddr2),
        .idu_exu_csr_addr  (idu_exu_csr_addr),
        .lsu_wbu_waddr     (lsu_wbu_waddr),
        .lsu_wbu_alu_result(lsu_wbu_alu_result),
        .lsu_wbu_mem_result(lsu_wbu_mem_result),
        .lsu_wbu_snpc      (lsu_wbu_snpc),
        .lsu_exu_inflight  (lsu_exu_inflight),
        .wbu_exu_rdata1    (wbu_exu_rdata1),
        .wbu_exu_rdata2    (wbu_exu_rdata2),
        .wbu_exu_csr_rdata (wbu_exu_csr_rdata),
        .exu_mtvec         (wbu_exu_mtvec),
        .exu_mepc          (wbu_exu_mepc)
    );


    // ----- LSU -----
    ysyx_26010027_LSU my_LSU (
        .clock           (clock),
        .reset           (reset),

        .exu_lsu_mem_w   (exu_lsu_mem_w),
        .exu_lsu_mem_r   (exu_lsu_mem_r),
        .exu_lsu_mem_addr(exu_lsu_mem_addr),
        .exu_lsu_wdata   (exu_lsu_wdata),

        .exu_lsu_valid     (exu_lsu_valid),
        .lsu_exu_ready     (lsu_exu_ready),
        .exu_lsu_pc        (exu_lsu_pc),
        .exu_lsu_snpc      (exu_lsu_snpc),
        .exu_lsu_inst      (exu_lsu_inst),
        .exu_lsu_reg_w     (exu_lsu_reg_w),
        .exu_lsu_rf_res    (exu_lsu_rf_res),
        .exu_lsu_waddr     (exu_lsu_waddr),
        .exu_lsu_alu_result(exu_lsu_alu_result),
        .exu_lsu_csr_waddr (exu_lsu_csr_waddr),
        .exu_lsu_csr_we    (exu_lsu_csr_we),
        .exu_lsu_csr_ecall (exu_lsu_csr_ecall),
        .exu_lsu_csr_mret  (exu_lsu_csr_mret),
        .exu_lsu_csr_wdata (exu_lsu_csr_wdata),

        .wbu_lsu_ready     (wbu_lsu_ready),
        .lsu_wbu_valid     (lsu_wbu_valid),
        .lsu_wbu_pc        (lsu_wbu_pc),
        .lsu_wbu_snpc      (lsu_wbu_snpc),
        .lsu_wbu_inst      (lsu_wbu_inst),
        .lsu_wbu_reg_w     (lsu_wbu_reg_w),
        .lsu_wbu_rf_res    (lsu_wbu_rf_res),
        .lsu_wbu_waddr     (lsu_wbu_waddr),
        .lsu_wbu_alu_result(lsu_wbu_alu_result),
        .lsu_wbu_mem_result(lsu_wbu_mem_result),
        .lsu_wbu_csr_waddr (lsu_wbu_csr_waddr),
        .lsu_wbu_csr_we    (lsu_wbu_csr_we),
        .lsu_wbu_csr_ecall (lsu_wbu_csr_ecall),
        .lsu_wbu_csr_mret  (lsu_wbu_csr_mret),
        .lsu_wbu_csr_wdata (lsu_wbu_csr_wdata),
        .lsu_exu_inflight  (lsu_exu_inflight),

`ifdef NPC_SIM
        .exu_lsu_dnpc      (exu_lsu_dnpc),
        .lsu_wbu_dnpc      (lsu_wbu_dnpc),
        .lsu_wbu_mem_en    (lsu_wbu_mem_en),
        .lsu_wbu_mem_addr  (lsu_wbu_mem_addr),
`endif

        // AXI
        .cpu_lsu_arready (cpu_lsu_arready),
        .lsu_cpu_araddr  (lsu_cpu_araddr),
        .lsu_cpu_arvalid (lsu_cpu_arvalid),
        .lsu_cpu_arid    (lsu_cpu_arid),
        .lsu_cpu_arlen   (lsu_cpu_arlen),
        .lsu_cpu_arsize  (lsu_cpu_arsize),
        .lsu_cpu_arburst (lsu_cpu_arburst),

        .lsu_cpu_rready  (lsu_cpu_rready),
        .cpu_lsu_rvalid  (cpu_lsu_rvalid),
        .cpu_lsu_rdata   (cpu_lsu_rdata),
        .cpu_lsu_rresp   (cpu_lsu_rresp),

        .cpu_lsu_awready (cpu_lsu_awready),
        .lsu_cpu_awaddr  (lsu_cpu_awaddr),
        .lsu_cpu_awvalid (lsu_cpu_awvalid),
        .lsu_cpu_awid    (lsu_cpu_awid),
        .lsu_cpu_awlen   (lsu_cpu_awlen),
        .lsu_cpu_awsize  (lsu_cpu_awsize),
        .lsu_cpu_awburst (lsu_cpu_awburst),

        .cpu_lsu_wready  (cpu_lsu_wready),
        .lsu_cpu_wdata   (lsu_cpu_wdata),
        .lsu_cpu_wstrb   (lsu_cpu_wstrb),
        .lsu_cpu_wvalid  (lsu_cpu_wvalid),
        .lsu_cpu_wlast   (lsu_cpu_wlast),

        .cpu_lsu_bresp   (cpu_lsu_bresp),
        .cpu_lsu_bvalid  (cpu_lsu_bvalid),
        .lsu_cpu_bready  (lsu_cpu_bready)
    );


    // ----- WBU -----
    ysyx_26010027_WBU my_WBU (
        .clock  (clock),
        .reset  (reset),

        .exu_wbu_raddr1 (idu_exu_raddr1),
        .exu_wbu_raddr2 (idu_exu_raddr2),
        .lsu_wbu_rf_res (lsu_wbu_rf_res),

        .wbu_exu_rdata1   (wbu_exu_rdata1),
        .wbu_exu_rdata2   (wbu_exu_rdata2),
        .wbu_exu_csr_rdata(wbu_exu_csr_rdata),
        .csr_mtvec        (wbu_exu_mtvec),
        .csr_mepc         (wbu_exu_mepc),

        .lsu_wbu_valid  (lsu_wbu_valid),
        .wbu_lsu_ready  (wbu_lsu_ready),
        .lsu_wbu_pc     (lsu_wbu_pc),
        .lsu_wbu_snpc   (lsu_wbu_snpc),
        .lsu_wbu_reg_w     (lsu_wbu_reg_w),
        .lsu_wbu_waddr     (lsu_wbu_waddr),
        .lsu_wbu_alu_result(lsu_wbu_alu_result),
        .lsu_wbu_mem_result(lsu_wbu_mem_result),

        .csr_raddr (idu_exu_csr_addr),
        .csr_waddr (lsu_wbu_csr_waddr),
        .csr_wdata (lsu_wbu_csr_wdata),
        .csr_we    (lsu_wbu_csr_we),
        .csr_ecall (lsu_wbu_csr_ecall),
        .csr_mret  (lsu_wbu_csr_mret)
    );


    // ----- Arbiter -----

    reg [1:0] grant;

    localparam IFU_GRANT = 2'b01;
    localparam LSU_GRANT = 2'b10;

    // icache 与 LSU 共享总线访问权
    assign icache_arready = (grant == IFU_GRANT) ? arb_arready : 1'b0;
    assign icache_rvalid  = (grant == IFU_GRANT) ? arb_rvalid  : 1'b0;
    assign icache_rdata   = (grant == IFU_GRANT) ? arb_rdata   : 32'b0;
    assign icache_rresp   = (grant == IFU_GRANT) ? arb_rresp   : 2'b0;

    assign cpu_lsu_arready = (grant == LSU_GRANT) ? arb_arready : 1'b0;
    assign cpu_lsu_rvalid  = (grant == LSU_GRANT) ? arb_rvalid  : 1'b0;
    assign cpu_lsu_rdata   = (grant == LSU_GRANT) ? arb_rdata   : 32'b0;
    assign cpu_lsu_rresp   = (grant == LSU_GRANT) ? arb_rresp   : 2'b0;
    assign cpu_lsu_awready = (grant == LSU_GRANT) ? arb_awready : 1'b0;
    assign cpu_lsu_wready  = (grant == LSU_GRANT) ? arb_wready  : 1'b0;
    assign cpu_lsu_bvalid  = (grant == LSU_GRANT) ? arb_bvalid  : 1'b0;
    assign cpu_lsu_bresp   = (grant == LSU_GRANT) ? arb_bresp   : 2'b0;

    // lsu事务完成时握手信号
    wire handshake_lsu_r = cpu_lsu_rvalid && lsu_cpu_rready;
    wire handshake_lsu_b = cpu_lsu_bvalid && lsu_cpu_bready;

    // arbiter -> 下游总线
    assign arb_arvalid  = (grant == IFU_GRANT) ? icache_arvalid : lsu_cpu_arvalid;
    assign arb_araddr   = (grant == IFU_GRANT) ? icache_araddr  : lsu_cpu_araddr;
    assign arb_arid     = (grant == IFU_GRANT) ? icache_arid    : lsu_cpu_arid;
    assign arb_arlen    = (grant == IFU_GRANT) ? icache_arlen   : lsu_cpu_arlen;
    assign arb_arsize   = (grant == IFU_GRANT) ? icache_arsize  : lsu_cpu_arsize;
    assign arb_arburst  = (grant == IFU_GRANT) ? icache_arburst : lsu_cpu_arburst;
    assign arb_rready   = (grant == IFU_GRANT) ? icache_rready  : lsu_cpu_rready;

    assign arb_awvalid  = (grant == LSU_GRANT) ? lsu_cpu_awvalid : 1'b0;
    assign arb_awaddr   = lsu_cpu_awaddr;
    assign arb_awid     = lsu_cpu_awid;
    assign arb_awlen    = lsu_cpu_awlen;
    assign arb_awsize   = lsu_cpu_awsize;
    assign arb_awburst  = lsu_cpu_awburst;
    assign arb_wvalid   = (grant == LSU_GRANT) ? lsu_cpu_wvalid : 1'b0;
    assign arb_wdata    = lsu_cpu_wdata;
    assign arb_wstrb    = lsu_cpu_wstrb;
    assign arb_wlast    = lsu_cpu_wlast;
    assign arb_bready   = lsu_cpu_bready;

    always @(posedge clock, posedge reset) begin
        if (reset) begin
            grant <= IFU_GRANT;
        end else begin
            case (grant)
                IFU_GRANT:
                    // IFU 空闲(未发请求且未等响应)且有 LSU 请求时让出总线, 否则 IFU 优先
                    if ((lsu_cpu_arvalid || lsu_cpu_awvalid) && !ifu_cpu_arvalid && !ifu_cpu_rready)
                        grant <= LSU_GRANT;
                    else grant <= IFU_GRANT;

                LSU_GRANT:
                    if (handshake_lsu_r || handshake_lsu_b)
                        grant <= IFU_GRANT;
                    else grant <= LSU_GRANT;
                default: grant <= IFU_GRANT;
            endcase
        end
    end

`ifdef NPC_SIM
    wire access_fault = (cpu_ifu_rvalid && ifu_cpu_rready && cpu_ifu_rresp != 2'b00)
                     || (cpu_lsu_rvalid && lsu_cpu_rready && cpu_lsu_rresp != 2'b00)
                     || (cpu_lsu_bvalid && lsu_cpu_bready && cpu_lsu_bresp != 2'b00);

    // 提交指令类型（统计用）
    wire [6:0] wbu_opcode = lsu_wbu_inst[6:0];
    wire wbu_load   = (wbu_opcode == 7'b0000011);
    wire wbu_store  = (wbu_opcode == 7'b0100011);
    wire wbu_csr    = (wbu_opcode == 7'b1110011);
    wire wbu_jump   = (wbu_opcode == 7'b1101111) || (wbu_opcode == 7'b1100111);
    wire wbu_branch = (wbu_opcode == 7'b1100011);
    wire wbu_alu    = (wbu_opcode == 7'b0110011) || (wbu_opcode == 7'b0010011) ||
                      (wbu_opcode == 7'b0010111) || (wbu_opcode == 7'b0110111);
    wire [31:0] hit_count    = 32'b0;
    wire [31:0] miss_count   = 32'b0;
    wire [31:0] miss_latency = 32'b0;

    wire ebreak = (lsu_wbu_inst == 32'h00100073);

    always @(posedge clock, posedge reset) begin
        if (!reset) begin
            get_cpu_state({{31{1'b0}}, lsu_wbu_valid && wbu_load},
                          {{31{1'b0}}, lsu_wbu_valid && wbu_store},
                          {{31{1'b0}}, lsu_wbu_valid},
                          {{31{1'b0}}, lsu_wbu_valid && wbu_alu},
                          {{31{1'b0}}, lsu_wbu_valid && wbu_csr},
                          {{31{1'b0}}, lsu_wbu_valid && wbu_jump},
                          {{31{1'b0}}, lsu_wbu_valid && wbu_branch},
                          hit_count, miss_count, miss_latency);

            // 提交追踪
            // if (lsu_wbu_valid) cpu_trace(lsu_wbu_pc, lsu_wbu_inst);
            // // IFU->IDU 交付追踪
            // if (ifu_idu_valid && idu_ifu_ready) ifu_trace(ifu_idu_pc, ifu_idu_inst);

            // ftrace
            if (idu_exu_valid && exu_idu_ready && idu_exu_jump == 2'b01) begin
                ftrace_print(idu_exu_pc, exu_flush_pc, {28'b0, idu_exu_waddr}, {27'b0, idu_exu_inst[19:15]});
            end

            // ebreak
            if (ebreak || access_fault) begin
                finish_sim();
                if (ebreak) $display("ebreak at PC = 0x%h Inst = 0x%h", lsu_wbu_pc, lsu_wbu_inst);
                if (access_fault) $fatal(1, "![Access-FAULT]");
            end
        end
    end
`endif

endmodule
