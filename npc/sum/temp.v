// 自动合并生成：2026-07-30 12:46:10
// 合并源文件列表：/home/long/ysyx-workbench/npc/sum/sum_filelist.txt
// ===========================================

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042.v ----------
`timescale 1ns/1ns 
   module ysyx_25020042 (
        input             clock            ,
        input             reset            ,
        /* verilator lint_off UNUSEDSIGNAL */
        input             io_interrupt     ,
        /* verilator lint_on UNUSEDSIGNAL */
        // Master AXI ports: exposed for external memory connection
        //   1) SoC mode (!PLATFORM_NPC): connected to crossbar
        //   2) Iverilog mode (PLATFORM_NPC && __ICARUS__): connected to external mem in testbench
        //   3) Verilator mode (PLATFORM_NPC && !__ICARUS__): NOT present (memory is internal)
        `ifdef PLATFORM_NPC
            `ifdef __ICARUS__
            input             io_master_awready,
            output            io_master_awvalid,
            output  [31:0]    io_master_awaddr,
            output  [3:0]     io_master_awid   ,
            output  [7:0]     io_master_awlen  ,
            output  [2:0]     io_master_awsize ,
            output  [1:0]     io_master_awburst,
            input             io_master_wready ,
            output            io_master_wvalid ,
            output  [31:0]    io_master_wdata  ,
            output  [3:0]     io_master_wstrb  ,
            output            io_master_wlast  ,
            output            io_master_bready ,
            input             io_master_bvalid ,
            input   [1:0]     io_master_bresp  ,
            input   [3:0]     io_master_bid    ,
            input             io_master_arready,
            output            io_master_arvalid,
            output  [31:0]    io_master_araddr ,
            output  [3:0]     io_master_arid   ,
            output  [7:0]     io_master_arlen  ,
            output  [2:0]     io_master_arsize ,
            output  [1:0]     io_master_arburst,
            output            io_master_rready ,
            input             io_master_rvalid ,
            input   [1:0]     io_master_rresp  ,
            input   [31:0]    io_master_rdata  ,
            input             io_master_rlast  ,
            input   [3:0]     io_master_rid    ,
            `endif
        `else
        input             io_master_awready,
        output            io_master_awvalid,
        output  [31:0]    io_master_awaddr,
        output  [3:0]     io_master_awid   ,
        output  [7:0]     io_master_awlen  ,
        output  [2:0]     io_master_awsize ,
        output  [1:0]     io_master_awburst,
        input             io_master_wready ,
        output            io_master_wvalid ,
        output  [31:0]    io_master_wdata  ,
        output  [3:0]     io_master_wstrb  ,
        output            io_master_wlast  ,
        output            io_master_bready ,
        input             io_master_bvalid ,
        input   [1:0]     io_master_bresp  ,
        input   [3:0]     io_master_bid    ,
        input             io_master_arready,
        output            io_master_arvalid,
        output  [31:0]    io_master_araddr ,
        output  [3:0]     io_master_arid   ,
        output  [7:0]     io_master_arlen  ,
        output  [2:0]     io_master_arsize ,
        output  [1:0]     io_master_arburst,
        output            io_master_rready ,
        input             io_master_rvalid ,
        input   [1:0]     io_master_rresp  ,
        input   [31:0]    io_master_rdata  ,
        input             io_master_rlast  ,
        input   [3:0]     io_master_rid    ,
        `endif
        /* verilator lint_off UNUSEDSIGNAL */
        /* verilator lint_off UNDRIVEN */
        output            io_slave_awready ,
        input             io_slave_awvalid ,
        input   [31:0]    io_slave_awaddr  ,
        input   [3:0]     io_slave_awid    ,
        input   [7:0]     io_slave_awlen   ,
        input   [2:0]     io_slave_awsize  ,
        input   [1:0]     io_slave_awburst ,
        output            io_slave_wready  ,
        input             io_slave_wvalid  ,
        input   [31:0]    io_slave_wdata   ,
        input   [3:0]     io_slave_wstrb   ,
        input             io_slave_wlast   ,
        input             io_slave_bready  ,
        output            io_slave_bvalid  ,
        output  [1:0]     io_slave_bresp   ,
        output  [3:0]     io_slave_bid     ,
        output            io_slave_arready ,
        input             io_slave_arvalid ,
        input   [31:0]    io_slave_araddr  ,
        input   [3:0]     io_slave_arid    ,
        input   [7:0]     io_slave_arlen   ,
        input   [2:0]     io_slave_arsize  ,
        input   [1:0]     io_slave_arburst ,
        input             io_slave_rready  ,
        output            io_slave_rvalid  ,
        output  [1:0]     io_slave_rresp   ,
        output  [31:0]    io_slave_rdata   ,
        output            io_slave_rlast   ,
        output  [3:0]     io_slave_rid   
    /* verilator lint_on UNDRIVEN */
    /* verilator lint_on UNUSEDSIGNAL */
    );

assign io_slave_rvalid = 1'b0;
assign io_slave_bvalid = 1'b0;
assign io_slave_rdata = 32'h0;
assign io_slave_rresp = 2'b0;
assign io_slave_rlast = 1'b0;
assign io_slave_bid = 4'b0;
assign io_slave_bresp = 2'b0;
assign io_slave_arready = 1'b0;
assign io_slave_wready = 1'b0;
assign io_slave_awready = 1'b0;
assign io_slave_rid = 4'b0;
//------------------------------------------
// 模块间握手信号
//------------------------------------------
    wire ifu_valid;
    wire idu_valid;
    wire idu_ready;
    wire exu_valid;
    wire exu_ready;
    wire lsu_valid;
    wire lsu_ready;
    wire wbu_valid;
    wire wbu_ready;
//------------------------------------------
// 指令信号
//------------------------------------------
    wire [7:0] idu_inst;
    wire fencei_signal;
//------------------------------------------
// 数据通路信号
//------------------------------------------
    wire [4:0] branch_rs1;
    wire [4:0] branch_rs2;
    wire [4:0] branch_rd;
    wire [31:0] branch_exu_data;
    wire [31:0] branch_lsu_data;
    wire [31:0] rs1_data;
    wire [31:0] rs2_data;
    wire        rs1_data_ready;
    wire        rs2_data_ready;
    wire        load_valid;
    wire [31:0] wdata;
    wire [31:0] imm;
    wire [31:0] src1;
    wire [31:0] src2;
    wire [5:0] shamt;
    wire [31:0] jump_pc;
    wire [31:0] instruction;
    wire [31:0] exu_data;
    wire [31:0] lsu_data;
    wire [11:0] csr_addr;
    wire [31:0] csr_data;
    wire [31:0] mstatus;
    wire [31:0] mtvec;
    wire [31:0] mepc;
    wire [31:0] mcause_wdata;
    wire [31:0] mstatus_wdata = 32'h0;
    wire [31:0] mtvec_wdata = 32'h0;
    wire [31:0] mepc_wdata;
    wire [31:0] csr_wdata;
    wire [4:0]  rs1;
    wire [4:0]  rs2;
    wire        fault;
    wire        jump_valid;
    wire [31:0] ifu_to_idu_pc_data;
    wire [31:0] idu_to_exu_pc_data;
    wire [31:0] exu_to_lsu_pc_data;
    wire [31:0] lsu_to_wbu_pc_data;
    wire [4:0]  wbu_rd;
    wire [31:0] exu_to_lsu_csr_data;
    wire [31:0] lsu_to_wbu_csr_data;
    wire [7:0] exu_to_lsu_inst;
    wire [7:5] lsu_to_wbu_inst;
    wire [31:0] exu_to_lsu_src2;
    wire [11:0] exu_to_lsu_csr_addr;
    wire [11:0] lsu_to_wbu_csr_addr;
    wire [11:0] wbu_csr_addr;
    wire  [2:0] IFU_Exception_Handling0;
    wire  [2:0] IFU_Exception_Handling1;
    wire  [2:0] IFU_Exception_Handling2;
    wire  [2:0] IFU_Exception_Handling3;
    wire  [2:0] IDU_Exception_Handling0;
    wire  [2:0] IDU_Exception_Handling1;
    wire  [2:0] IDU_Exception_Handling2;
    wire  [5:0] LSU_Exception_Handling0;
    wire        Exception_valid;
    wire [31:0] fast_jump_pc;
    wire        fast_jump_valid;
     `ifdef VERILATOR
    wire [31:0] idu_to_exu_instrction_data;
    wire [31:0] exu_to_lsu_instrction_data;
    wire [31:0] lsu_to_wbu_instrction_data;
    `endif
//------------------------------------------
// AXI 总线
//------------------------------------------
    
    wire [31:0] io_ifu_araddr;
    wire        io_ifu_arvalid;
    wire        io_ifu_arready;
    wire [7:0]  io_ifu_arlen;
    wire [3:0]  io_ifu_arid;
    wire [1:0]  io_ifu_arburst;
    wire [2:0]  io_ifu_arsize;
    wire        io_ifu_rready;
    wire        io_ifu_rvalid;
    wire [31:0] io_ifu_rdata;
    wire [1:0]  io_ifu_rresp;
    wire        io_ifu_rlast;
    wire [3:0]  io_ifu_rid;

    // axi 握手信号
    wire [31:0] io_lsu_araddr;
    wire        io_lsu_arvalid;
    wire        io_lsu_arready;
    wire [7:0]  io_lsu_arlen;
    wire [3:0]  io_lsu_arid;
    wire [1:0]  io_lsu_arburst;
    wire [2:0]  io_lsu_arsize;

    wire [31:0] io_lsu_rdata;
    wire        io_lsu_rvalid;
    wire [1:0]  io_lsu_rresp;
    wire        io_lsu_rready;
    wire        io_lsu_rlast;
    wire [3:0]  io_lsu_rid;

    wire [31:0] io_lsu_awaddr;
    wire        io_lsu_awvalid;
    wire        io_lsu_awready;
    wire [3:0]  io_lsu_awid;
    wire [7:0]  io_lsu_awlen;
    wire [2:0]  io_lsu_awsize;
    wire [1:0]  io_lsu_awburst;

    wire [31:0] io_lsu_wdata;
    wire [3:0]  io_lsu_wstrb;
    wire        io_lsu_wvalid;
    wire        io_lsu_wready;
    wire        io_lsu_wlast;

    wire        io_lsu_bvalid;
    wire        io_lsu_bready;
    wire [1:0]  io_lsu_bresp;
    wire [3:0]  io_lsu_bid;

    wire            io_clint_awready;
    wire            io_clint_awvalid;
    wire  [31:0]    io_clint_awaddr ;
    wire  [3:0]     io_clint_awid   ;
    wire  [7:0]     io_clint_awlen  ;
    wire  [2:0]     io_clint_awsize ;
    wire  [1:0]     io_clint_awburst;
    wire            io_clint_wready ;
    wire            io_clint_wvalid ;
    wire  [31:0]    io_clint_wdata  ;
    wire  [3:0]     io_clint_wstrb  ;
    wire            io_clint_wlast  ;
    wire            io_clint_bready ;
    wire            io_clint_bvalid ;
    wire  [1:0]     io_clint_bresp  ;
    wire  [3:0]     io_clint_bid    ;
    wire            io_clint_arready;
    wire            io_clint_arvalid;
    wire  [31:0]    io_clint_araddr ;
    wire  [3:0]     io_clint_arid   ;
    wire  [7:0]     io_clint_arlen  ;
    wire  [2:0]     io_clint_arsize ;
    wire  [1:0]     io_clint_arburst;
    wire            io_clint_rready ;
    wire            io_clint_rvalid ;
    wire  [1:0]     io_clint_rresp  ;
    wire  [31:0]    io_clint_rdata  ;
    wire            io_clint_rlast  ;
    wire  [3:0]     io_clint_rid    ;
    `ifdef PLATFORM_NPC
    // `ifdef VERILATOR
    wire            io_master_awready;
    wire            io_master_awvalid;
    wire  [31:0]    io_master_awaddr ;
    wire  [3:0]     io_master_awid   ;
    wire  [7:0]     io_master_awlen  ;
    wire  [2:0]     io_master_awsize ;
    wire  [1:0]     io_master_awburst;
    wire            io_master_wready ;
    wire            io_master_wvalid ;
    wire  [31:0]    io_master_wdata  ;
    wire  [3:0]     io_master_wstrb  ;
    wire            io_master_wlast  ;
    wire            io_master_bready ;
    wire            io_master_bvalid ;
    wire  [1:0]     io_master_bresp  ;
    wire  [3:0]     io_master_bid    ;
    wire            io_master_arready;
    wire            io_master_arvalid;
    wire  [31:0]    io_master_araddr ;
    wire  [3:0]     io_master_arid   ;
    wire  [7:0]     io_master_arlen  ;
    wire  [2:0]     io_master_arsize ;
    wire  [1:0]     io_master_arburst;
    wire            io_master_rready ;
    wire            io_master_rvalid ;
    wire  [1:0]     io_master_rresp  ;
    wire  [31:0]    io_master_rdata  ;
    wire            io_master_rlast  ;
    wire  [3:0]     io_master_rid    ;
    // `endif
    `endif
//------------------------------------------
// 性能计数器
//------------------------------------------    
    `ifdef VERILATOR
    wire [63:0] ifu_performance_counter;
    wire [63:0] idu_performance_counter;
    wire [63:0] exu_performance_counter;
    wire [63:0] lsu_performance_counter;
    wire [63:0] wbu_performance_counter;
    wire [63:0] ifu_cycles_counter;
    wire [63:0] idu_cycles_counter;
    wire [63:0] exu_cycles_counter;
    wire [63:0] lsu_cycles_counter;
    wire [63:0] wbu_cycles_counter;
    wire [63:0] csr_hit_counter;
    wire [63:0] exu_hit_counter;
    wire [63:0] jump_hit_counter;
    wire [63:0] mem_hit_counter;
    wire [63:0] fence_hit_counter;
    wire [63:0] ifu_single_cycles_counter;
    wire [63:0] idu_single_cycles_counter;
    wire [63:0] exu_single_cycles_counter;
    wire [63:0] lsu_single_cycles_counter;
    wire [63:0] wbu_single_cycles_counter;
        `ifdef ICACHE_ON
    wire [63:0]      icache_hit_count;
    `endif
    `endif

//------------------------------------------
// 异常信号
//------------------------------------------
assign fault = (io_master_rresp == 2'b00) ? 1'b0 : 1'b1;

//------------------------------------------
// axi  仲裁器模块实例化
//------------------------------------------
ysyx_25020042_axi_arbiter axi_arbiter_u (
    .clock(clock),
    .reset(reset),

    .io_lsu_araddr(io_lsu_araddr),
    .io_lsu_arvalid(io_lsu_arvalid),
    .io_lsu_arready(io_lsu_arready),
    .io_lsu_arid(io_lsu_arid),
    .io_lsu_arlen(io_lsu_arlen),
    .io_lsu_arsize(io_lsu_arsize),
    .io_lsu_arburst(io_lsu_arburst),

    .io_lsu_rdata(io_lsu_rdata),
    .io_lsu_rvalid(io_lsu_rvalid),
    .io_lsu_rresp(io_lsu_rresp),
    .io_lsu_rready(io_lsu_rready),
    .io_lsu_rid(io_lsu_rid),
    .io_lsu_rlast(io_lsu_rlast),
    .io_lsu_awaddr(io_lsu_awaddr),
    .io_lsu_awvalid(io_lsu_awvalid),
    .io_lsu_awready(io_lsu_awready),
    .io_lsu_awid(io_lsu_awid),
    .io_lsu_awlen(io_lsu_awlen),
    .io_lsu_awsize(io_lsu_awsize),
    .io_lsu_awburst(io_lsu_awburst),   

    .io_lsu_wdata(io_lsu_wdata),
    .io_lsu_wstrb(io_lsu_wstrb),
    .io_lsu_wvalid(io_lsu_wvalid),
    .io_lsu_wready(io_lsu_wready),
    .io_lsu_wlast(io_lsu_wlast),

    .io_lsu_bvalid(io_lsu_bvalid),
    .io_lsu_bready(io_lsu_bready),
    .io_lsu_bresp(io_lsu_bresp),
    .io_lsu_bid(io_lsu_bid),

    .io_ifu_araddr(io_ifu_araddr),
    .io_ifu_arvalid(io_ifu_arvalid),
    .io_ifu_arready(io_ifu_arready),
    .io_ifu_arid(io_ifu_arid),
    .io_ifu_arlen(io_ifu_arlen),
    .io_ifu_arsize(io_ifu_arsize),
    .io_ifu_arburst(io_ifu_arburst),

    .io_ifu_rdata(io_ifu_rdata),
    .io_ifu_rvalid(io_ifu_rvalid),
    .io_ifu_rresp(io_ifu_rresp),
    .io_ifu_rready(io_ifu_rready),
    .io_ifu_rid(io_ifu_rid),
    .io_ifu_rlast(io_ifu_rlast),

    .io_araddr(io_master_araddr),
    .io_arvalid(io_master_arvalid),
    .io_arready(io_master_arready),
    .io_arid(io_master_arid),
    .io_arlen(io_master_arlen),
    .io_arsize(io_master_arsize),
    .io_arburst(io_master_arburst),
    

    .io_rdata(io_master_rdata),
    .io_rvalid(io_master_rvalid),
    .io_rresp(io_master_rresp),
    .io_rready(io_master_rready),
    .io_rid(io_master_rid),
    .io_rlast(io_master_rlast),

    .io_awaddr(io_master_awaddr),
    .io_awvalid(io_master_awvalid),
    .io_awready(io_master_awready),
    .io_awid(io_master_awid),
    .io_awlen(io_master_awlen),
    .io_awsize(io_master_awsize),
    .io_awburst(io_master_awburst), 
    

    .io_wdata(io_master_wdata),
    .io_wstrb(io_master_wstrb),
    .io_wvalid(io_master_wvalid),
    .io_wready(io_master_wready),
    .io_wlast(io_master_wlast),

    .io_bvalid(io_master_bvalid),
    .io_bready(io_master_bready),
    .io_bresp(io_master_bresp),
    .io_bid(io_master_bid),

    .io_clint_araddr(io_clint_araddr),
    .io_clint_arvalid(io_clint_arvalid),
    .io_clint_arready(io_clint_arready),
    .io_clint_arid(io_clint_arid),
    .io_clint_arlen(io_clint_arlen),
    .io_clint_arsize(io_clint_arsize),
    .io_clint_arburst(io_clint_arburst),
    

    .io_clint_rdata(io_clint_rdata),
    .io_clint_rvalid(io_clint_rvalid),
    .io_clint_rresp(io_clint_rresp),
    .io_clint_rready(io_clint_rready),
    .io_clint_rid(io_clint_rid),
    .io_clint_rlast(io_clint_rlast),

    .io_clint_awaddr(io_clint_awaddr),
    .io_clint_awvalid(io_clint_awvalid),
    .io_clint_awready(io_clint_awready),
    .io_clint_awid(io_clint_awid),
    .io_clint_awlen(io_clint_awlen),
    .io_clint_awsize(io_clint_awsize),
    .io_clint_awburst(io_clint_awburst), 


    .io_clint_wdata(io_clint_wdata),
    .io_clint_wstrb(io_clint_wstrb),
    .io_clint_wvalid(io_clint_wvalid),
    .io_clint_wready(io_clint_wready),
    .io_clint_wlast(io_clint_wlast),

    .io_clint_bvalid(io_clint_bvalid),
    .io_clint_bready(io_clint_bready),
    .io_clint_bresp(io_clint_bresp),
    .io_clint_bid(io_clint_bid)
);

//------------------------------------------
// ipc_counter实例化
//------------------------------------------
`ifdef VERILATOR
ipc_counter ipc_counter_u(
    .clk(clock),
    .rst(reset),
    .wbu_valid(wbu_valid),
    .ebreak(IDU_Exception_Handling2[1]),
    .ifu_performance_counter(ifu_performance_counter),
    .idu_performance_counter(idu_performance_counter),
    .lsu_performance_counter(lsu_performance_counter),
    .exu_performance_counter(exu_performance_counter),
    .wbu_performance_counter(wbu_performance_counter),
    .csr_hit_counter(csr_hit_counter),
    .exu_hit_counter(exu_hit_counter),
    .jump_hit_counter(jump_hit_counter),
    .mem_hit_counter(mem_hit_counter),
    .fence_hit_counter(fence_hit_counter),
    .ifu_cycles_counter(ifu_cycles_counter),
    .idu_cycles_counter(idu_cycles_counter),
    .lsu_cycles_counter(lsu_cycles_counter),
    .exu_cycles_counter(exu_cycles_counter),
    .wbu_cycles_counter(wbu_cycles_counter),
    .single_cycle_counter(wbu_single_cycles_counter),
    .inst(lsu_to_wbu_inst),
    .icache_hit_counter(icache_hit_count)
);
`endif

//------------------------------------------
// mem实例化
//------------------------------------------

`ifdef PLATFORM_NPC
    `ifndef __ICARUS__
    ysyx_25020042_mem mem_u (
        .clock(clock),
        .reset(reset),
        // axi 握手信号
        .slave_araddr(io_master_araddr),
        .slave_arvalid(io_master_arvalid),
        .slave_arready(io_master_arready),
        .slave_arid(io_master_arid),
        .slave_arlen(io_master_arlen),
        .slave_arsize(io_master_arsize),
        .slave_arburst(io_master_arburst),

        .slave_rdata(io_master_rdata),
        .slave_rvalid(io_master_rvalid),
        .slave_rresp(io_master_rresp),
        .slave_rready(io_master_rready),
        .slave_rlast(io_master_rlast),
        .slave_rid(io_master_rid),

        .slave_awaddr(io_master_awaddr),
        .slave_awvalid(io_master_awvalid),
        .slave_awready(io_master_awready),
        .slave_awid(io_master_awid),
        .slave_awlen(io_master_awlen),
        .slave_awsize(io_master_awsize),
        .slave_awburst(io_master_awburst),

        .slave_wdata(io_master_wdata),
        .slave_wstrb(io_master_wstrb),
        .slave_wvalid(io_master_wvalid),
        .slave_wready(io_master_wready),
        .slave_wlast(io_master_wlast),

        .slave_bvalid(io_master_bvalid),
        .slave_bready(io_master_bready),
        .slave_bresp(io_master_bresp),
        .slave_bid(io_master_bid)
    );
    `endif
`endif

//------------------------------------------
// clint实例化
//------------------------------------------
ysyx_25020042_clint clint_u (
    .clock(clock),
    .reset(reset),
    // axi 握手信号
    .slave_araddr(io_clint_araddr),
    .slave_arvalid(io_clint_arvalid),
    .slave_arready(io_clint_arready),
    .slave_arid(io_clint_arid),
    .slave_arlen(io_clint_arlen),
    .slave_arsize(io_clint_arsize),
    .slave_arburst(io_clint_arburst),

    .slave_rdata(io_clint_rdata),
    .slave_rvalid(io_clint_rvalid),
    .slave_rresp(io_clint_rresp),
    .slave_rready(io_clint_rready),
    .slave_rlast(io_clint_rlast),
    .slave_rid(io_clint_rid),

    .slave_awaddr(io_clint_awaddr),
    .slave_awvalid(io_clint_awvalid),
    .slave_awready(io_clint_awready),
    .slave_awid(io_clint_awid),
    .slave_awlen(io_clint_awlen),
    .slave_awsize(io_clint_awsize),
    .slave_awburst(io_clint_awburst),

    .slave_wdata(io_clint_wdata),
    .slave_wstrb(io_clint_wstrb),
    .slave_wvalid(io_clint_wvalid),
    .slave_wready(io_clint_wready),
    .slave_wlast(io_clint_wlast),

    .slave_bvalid(io_clint_bvalid),
    .slave_bready(io_clint_bready),
    .slave_bresp(io_clint_bresp),
    .slave_bid(io_clint_bid)
);
//------------------------------------------
// IFU实例化
//------------------------------------------


ysyx_25020042_IFU IFU_u (
    .clock(clock),
    .reset(reset),
    .idu_ready(idu_ready),
    .ifu_valid(ifu_valid),

    .i_jump_valid(jump_valid),
    .i_jump_pc(jump_pc),
    .i_fast_jump_pc(fast_jump_pc),
    .i_fast_jump_valid(fast_jump_valid),

    .fencei_signal(fencei_signal),
    .fault(fault),
    .o_instruction(instruction),
    .o_pc_data(ifu_to_idu_pc_data),
    .o_IFU_Exception_Handling(IFU_Exception_Handling0),

    `ifdef VERILATOR
    .o_performance_counter(ifu_performance_counter),
    .o_cycles_counter(ifu_cycles_counter),
    .o_single_cycles_counter(ifu_single_cycles_counter),
    `ifdef ICACHE_ON
    .o_icache_hit_count(icache_hit_count),
    `endif
    `endif

    .ifu_araddr(io_ifu_araddr),
    .ifu_arvalid(io_ifu_arvalid),
    .ifu_arready(io_ifu_arready),
    .ifu_arlen(io_ifu_arlen),
    .ifu_arid(io_ifu_arid),
    .ifu_arburst(io_ifu_arburst),
    .ifu_arsize(io_ifu_arsize),
    .ifu_rdata(io_ifu_rdata),
    .ifu_rvalid(io_ifu_rvalid),
    .ifu_rready(io_ifu_rready),
    .ifu_rresp(io_ifu_rresp),
    .ifu_rlast(io_ifu_rlast),
    .ifu_rid(io_ifu_rid)

);

//------------------------------------------
// IDU实例化
//------------------------------------------
ysyx_25020042_IDU IDU_u (
    .clock(clock),
    .reset(reset),
    .ifu_valid(ifu_valid),
    .exu_ready(exu_ready),
    .idu_ready(idu_ready),
    .idu_valid(idu_valid),
    `ifdef VERILATOR
    .csr_hit_counter(csr_hit_counter),
    .exu_hit_counter(exu_hit_counter),
    .jump_hit_counter(jump_hit_counter),
    .mem_hit_counter(mem_hit_counter),
    .fence_hit_counter(fence_hit_counter),
    .performance_counter(idu_performance_counter),
    .cycles_counter(idu_cycles_counter),
    .o_instruction_data(idu_to_exu_instrction_data),
    .i_single_cycles_counter(ifu_single_cycles_counter),
    .o_single_cycles_counter(idu_single_cycles_counter),
    `endif

    .i_jump_valid(jump_valid),
    .i_inst(instruction),
    .i_pc_data(ifu_to_idu_pc_data),
    .i_IFU_Exception_Handling(IFU_Exception_Handling0),
    .o_IFU_Exception_Handling(IFU_Exception_Handling1),
    .o_IDU_Exception_Handling(IDU_Exception_Handling0),
    .o_fast_jump_pc(fast_jump_pc),
    .o_fast_jump_valid(fast_jump_valid),
    .o_instruction_out(idu_inst),
    .o_imm(imm),
    .o_pc_data(idu_to_exu_pc_data),
    .o_csr_addr(csr_addr),
    .o_shamt(shamt),
    .o_rd(branch_rd),
    .o_rs1(branch_rs1),
    .o_rs2(branch_rs2)
    );
//------------------------------------------
// data branch实例化
//------------------------------------------
ysyx_25020042_data_branch data_branch_u(
    .clock(clock),
    .reset(reset),
    .i_rs1(branch_rs1),
    .i_rs2(branch_rs2),
    .i_rd(branch_rd),
    .i_exu_to_lsu_inst(exu_to_lsu_inst[7:5]),
    .i_idu_to_exu_inst(idu_inst[7:5]),
    .idu_exu_handshake(idu_valid & exu_ready),
    .exu_lsu_handshake(exu_valid & lsu_ready),
    .lsu_wbu_handshake(lsu_valid & wbu_ready),
    .load_valid(load_valid),
    .i_exu_rd_data(exu_data),
    .i_lsu_rd_data(lsu_data),
    .i_src1(src1),
    .i_src2(src2),
    .rs1_data_ready(rs1_data_ready),
    .rs2_data_ready(rs2_data_ready),
    .rs1_data(rs1_data),
    .rs2_data(rs2_data),
    .o_rs1(rs1),
    .o_rs2(rs2),
    .o_exu_rd_data(branch_exu_data),
    .o_lsu_rd_data(branch_lsu_data),
    .o_lsu_rd(wbu_rd)
);

//------------------------------------------
// EXU实例化
//------------------------------------------
ysyx_25020042_EXU EXU_u (
    .clock(clock),
    .reset(reset),
    .idu_valid(idu_valid),
    .lsu_ready(lsu_ready),
    .exu_valid(exu_valid),
    .exu_ready(exu_ready),

    `ifdef VERILATOR
    .performance_counter(exu_performance_counter),
    .cycles_counter(exu_cycles_counter),
    .i_instruction_data(idu_to_exu_instrction_data),
    .o_instruction_data(exu_to_lsu_instrction_data),
    .i_single_cycles_counter(idu_single_cycles_counter),
    .o_single_cycles_counter(exu_single_cycles_counter),
    `endif

    .i_inst(idu_inst),
    .i_src1(rs1_data),
    .i_src2(rs2_data),
    .i_imm(imm),
    .i_pc_data(idu_to_exu_pc_data),
    .i_shamt(shamt),
    .i_csr_data(csr_data),
    .i_csr_addr(csr_addr),
    .i_mepc_rdata(mepc),
    .i_mtvec_rdata(mtvec),
    .i_src1_valid(rs1_data_ready),
    .i_src2_valid(rs2_data_ready),
    .o_fence_i_valid(fencei_signal),
    .i_IFU_Exception_Handling(IFU_Exception_Handling1),
    .o_IFU_Exception_Handling(IFU_Exception_Handling2),
    .i_IDU_Exception_Handling(IDU_Exception_Handling0),
    .o_IDU_Exception_Handling(IDU_Exception_Handling1),
    .i_LSU_Exception_Handling(LSU_Exception_Handling0),
    .o_csr_data(exu_to_lsu_csr_data),
    .o_csr_addr(exu_to_lsu_csr_addr),
    .o_idu_inst(exu_to_lsu_inst),
    .o_pc_data(exu_to_lsu_pc_data),
    .o_src2(exu_to_lsu_src2),
    .jump_pc(jump_pc),
    .jump_valid(jump_valid),
    .o_data(exu_data)
    );

//------------------------------------------
// LSU实例化
//------------------------------------------
ysyx_25020042_LSU LSU_u (
    .clock(clock),
    .reset(reset),
    .exu_valid(exu_valid),
    .wbu_ready(wbu_ready),
    .lsu_valid(lsu_valid),
    .lsu_ready(lsu_ready),

    .i_inst(exu_to_lsu_inst),
    .i_src2(exu_to_lsu_src2),
    .i_data(branch_exu_data),
    .i_pc_data(exu_to_lsu_pc_data),
    .i_csr_data(exu_to_lsu_csr_data),
    .i_csr_addr(exu_to_lsu_csr_addr),

    .o_inst(lsu_to_wbu_inst),
    .o_data(lsu_data),
    .o_pc_data(lsu_to_wbu_pc_data),
    .o_csr_data(lsu_to_wbu_csr_data),
    .o_csr_addr(lsu_to_wbu_csr_addr),
    .load_valid(load_valid),
    .i_IFU_Exception_Handling(IFU_Exception_Handling2),
    .o_IFU_Exception_Handling(IFU_Exception_Handling3),
    .i_IDU_Exception_Handling(IDU_Exception_Handling1),
    .o_IDU_Exception_Handling(IDU_Exception_Handling2),
    .o_LSU_Exception_Handling(LSU_Exception_Handling0),

    `ifdef VERILATOR
    .performance_counter(lsu_performance_counter),
    .cycles_counter(lsu_cycles_counter),
    .i_instruction_data(exu_to_lsu_instrction_data),
    .o_instruction_data(lsu_to_wbu_instrction_data),
    .i_single_cycles_counter(exu_single_cycles_counter),
    .o_single_cycles_counter(lsu_single_cycles_counter),
    `endif

    // axi 握手信号
    .lsu_araddr(io_lsu_araddr),
    .lsu_arvalid(io_lsu_arvalid),
    .lsu_arready(io_lsu_arready),
    .lsu_arlen(io_lsu_arlen),
    .lsu_arid(io_lsu_arid),
    .lsu_arburst(io_lsu_arburst),
    .lsu_arsize(io_lsu_arsize),

    .lsu_rdata(io_lsu_rdata),
    .lsu_rvalid(io_lsu_rvalid),
    .lsu_rresp(io_lsu_rresp),
    .lsu_rready(io_lsu_rready),
    .lsu_rlast(io_lsu_rlast),
    .lsu_rid(io_lsu_rid),

    .lsu_awaddr(io_lsu_awaddr),
    .lsu_awvalid(io_lsu_awvalid),
    .lsu_awready(io_lsu_awready),
    .lsu_awlen(io_lsu_awlen),
    .lsu_awid(io_lsu_awid),
    .lsu_awburst(io_lsu_awburst),
    .lsu_awsize(io_lsu_awsize),

    .lsu_wdata(io_lsu_wdata),
    .lsu_wstrb(io_lsu_wstrb),
    .lsu_wvalid(io_lsu_wvalid),
    .lsu_wready(io_lsu_wready),
    .lsu_wlast(io_lsu_wlast),

    .lsu_bvalid(io_lsu_bvalid),
    .lsu_bready(io_lsu_bready),
    .lsu_bresp(io_lsu_bresp),
    .lsu_bid(io_lsu_bid)
);

//------------------------------------------
// WBU实例化
//------------------------------------------
ysyx_25020042_WBU WBU_u (
    `ifdef VERILATOR
    .clock(clock),
    .reset(reset),
    `endif
    .lsu_valid(lsu_valid),
    .wbu_ready(wbu_ready),
    .wbu_valid(wbu_valid),

    `ifdef VERILATOR
    .i_instruction_data(lsu_to_wbu_instrction_data),
    .performance_counter(wbu_performance_counter),
    .cycles_counter(wbu_cycles_counter),
    .i_single_cycles_counter(lsu_single_cycles_counter),
    .o_single_cycles_counter(wbu_single_cycles_counter),
    `endif

    .i_data(branch_lsu_data),
    .i_pc_data(lsu_to_wbu_pc_data),
    .i_inst(lsu_to_wbu_inst),
    .i_mstatus(mstatus),
    .i_IFU_Exception_Handling(IFU_Exception_Handling3),
    .i_IDU_Exception_Handling(IDU_Exception_Handling2),
    .i_LSU_Exception_Handling(LSU_Exception_Handling0),
    .o_Exception_valid(Exception_valid),
    .i_csr_addr(lsu_to_wbu_csr_addr),
    .i_csr_rdata(lsu_to_wbu_csr_data),
    .csr_wdata(csr_wdata),
    .csr_addr(wbu_csr_addr),
    .reg_wdata(wdata),
    .o_mepc_wdata(mepc_wdata),
    .o_mcause_wdata(mcause_wdata)
    );

`ifdef VERILATOR
    reg [31:0] wbu_next_pc;
    always @(posedge clock) begin
        if (reset) begin
            wbu_next_pc <= 32'h80000000;
        end 
        else if (wbu_valid) begin
            if (lsu_to_wbu_pc_data != exu_to_lsu_pc_data) begin
                wbu_next_pc <= exu_to_lsu_pc_data;
            end
            else if (exu_to_lsu_pc_data != idu_to_exu_pc_data) begin
                wbu_next_pc <= idu_to_exu_pc_data;
            end
            else if (idu_to_exu_pc_data != ifu_to_idu_pc_data) begin
                wbu_next_pc <= ifu_to_idu_pc_data;
            end
        end
    end
    `endif


//------------------------------------------
// CSR实例化
//------------------------------------------
ysyx_25020042_csr csr_u (
    .clock(clock),
    .reset(reset),
    .i_Exception_valid(Exception_valid),
    .i_csr_wdata(csr_wdata),
    .i_csr_addr(csr_addr),
    .i_wbu_csr_addr(wbu_csr_addr),
    .i_mstatus_wdata(mstatus_wdata),
    .i_mcause_wdata(mcause_wdata),
    .i_mtvec_wdata(mtvec_wdata),
    .i_mepc_wdata(mepc_wdata),
    .wbu_valid(wbu_valid),
    .o_mtvec(mtvec),
    .o_mepc(mepc),
    .o_mstatus(mstatus),
    .o_csr_rdata(csr_data)
);
//------------------------------------------
// GPR实例化
//------------------------------------------
ysyx_25020042_gpr gpr_u(
    .clock(clock),
    .reset(reset), 
    .i_rs1(rs1),
    .i_rs2(rs2),
    .i_rd(wbu_rd),
    .i_data(wdata),
    .wbu_valid(wbu_valid),
    .o_src1(src1),
    .o_src2(src2)
);

    endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/IFU/ysyx_25020042_icache.v ----------

module ysyx_25020042_icache(
    input              clock            ,
    input              reset            ,
    input              pc_valid         ,
    input   [31:0]     pc_addr          ,
    output reg         instruction_ready,
    output reg [31:0]  instruction      ,
    output             Instruction_access_fault,
    `ifdef VERILATOR
    output reg [63:0]  icache_hit_count ,
    `endif

    input              io_icache_arready,
    input              fencei_signal    ,
    output reg         io_icache_arvalid,
    output reg [31:0]  io_icache_araddr ,
    output reg [3:0]   io_icache_arid   ,
    output reg [7:0]   io_icache_arlen  ,
    output reg [2:0]   io_icache_arsize ,
    output reg [1:0]   io_icache_arburst,
    output reg         io_icache_rready ,
    input              io_icache_rvalid ,
    input   [1:0]      io_icache_rresp  ,
    input   [31:0]     io_icache_rdata  ,
    input              io_icache_rlast  ,
    input   [3:0]      io_icache_rid    
);

`ifdef VERILATOR

always @(posedge clock) begin
    if (reset) begin
        icache_hit_count <= 0;
    end
    else begin
        if (hit & pc_valid)
            icache_hit_count <= icache_hit_count + 1;
    end
end

`endif

parameter CACHE_BLOCK_SIZE  = 16;
parameter CACHE_BLOCK_BANK  = 4;
parameter CACHE_BLOCK_COUNT = CACHE_BLOCK_SIZE / 4;
// parameter m                 = $clog2(CACHE_BLOCK_SIZE);
// parameter n                 = $clog2(CACHE_BLOCK_BANK);
parameter m                 = 4;
parameter n                 = 2;
parameter SDRAM_BASE_ADDR   = 32'ha0000000;
parameter SDRAM_SIZE        = 32'h20000000;
`ifdef PLATFORM_NPC
wire                          sdram_valid = 1;
`else 
wire                          sdram_valid    = (pc_addr >= SDRAM_BASE_ADDR) && (pc_addr < SDRAM_BASE_ADDR + SDRAM_SIZE);
// wire                          sdram_valid = 1;
`endif
wire [31:m+n]                 addr_tag       = pc_addr[31:m+n];
wire [m+n-1:m]                index          = pc_addr[m+n-1:m];
wire [m-1:2]                  offset         = pc_addr[m-1:2];
wire [31:m+n]                 icache_tag     = icache_addr[index][31:m+n];
wire                          hit            = (icache_tag == addr_tag) && (icache_valid[index]);
wire [31:m]                   burst_addr     = io_icache_araddr[31:m];
wire [m+n-1:m]                burst_index    = burst_addr[m+n-1:m];
wire [m-1:2]                  burst_offset   = burst_count;

reg [32-1:0]                 icache_data[0:CACHE_BLOCK_BANK-1][0:CACHE_BLOCK_COUNT-1];
reg [32-1:0]                 icache_addr[0:CACHE_BLOCK_BANK-1];
reg                          icache_valid[0:CACHE_BLOCK_BANK-1];
reg                          state;
reg [m-1:2]                  burst_count;
reg [1:0]                    rresp;

localparam IDLE = 1'b0;
localparam READ = 1'b1;

assign Instruction_access_fault = rresp[1] | rresp[0];

always @(posedge clock) begin
    state <= state;
    if (reset) begin
        state <= IDLE;
    end
    else begin
        case(state)
            IDLE: begin
                if (pc_valid) begin
                    if(hit)
                        state <= IDLE;
                    else 
                        state <= READ;
                end
                else 
                    state <= IDLE;
            end
            READ: begin
                if (io_icache_rlast && io_icache_rvalid && io_icache_rid == io_icache_arid)
                    state <= IDLE;
                else 
                    state <= READ;
            end
            default: begin
                state <= state;
            end
        endcase
    end
end

//  31    m+n m+n-1   m m-1    0
// +---------+---------+--------+
// |   tag   |  index  | offset |
// +---------+---------+--------+

always @(posedge clock) begin
    burst_count <= burst_count;
    if (reset) begin
        burst_count <= 0;
    end
    else begin
        if (io_icache_rlast & sdram_valid)
            burst_count <= 0;
        else if (io_icache_rvalid & sdram_valid) 
            burst_count <= burst_count + 1;        
    end
end


// integer i;
// integer j;

always @(posedge clock) begin
    instruction <= instruction;
    instruction_ready <= instruction_ready;

    icache_valid[0] <= icache_valid[0];
    icache_valid[1] <= icache_valid[1];
    icache_valid[2] <= icache_valid[2];
    icache_valid[3] <= icache_valid[3];
    icache_addr[0]  <= icache_addr[0];
    icache_addr[1]  <= icache_addr[1];
    icache_addr[2]  <= icache_addr[2];
    icache_addr[3]  <= icache_addr[3];
    icache_data[0][0]  <= icache_data[0][0];
    icache_data[0][1]  <= icache_data[0][1];
    icache_data[0][2]  <= icache_data[0][2];
    icache_data[0][3]  <= icache_data[0][3];
    icache_data[1][0]  <= icache_data[1][0];
    icache_data[1][1]  <= icache_data[1][1];
    icache_data[1][2]  <= icache_data[1][2];
    icache_data[1][3]  <= icache_data[1][3];
    icache_data[2][0]  <= icache_data[2][0];
    icache_data[2][1]  <= icache_data[2][1];
    icache_data[2][2]  <= icache_data[2][2];
    icache_data[2][3]  <= icache_data[2][3];
    icache_data[3][0]  <= icache_data[3][0];
    icache_data[3][1]  <= icache_data[3][1];
    icache_data[3][2]  <= icache_data[3][2];
    icache_data[3][3]  <= icache_data[3][3];

    if (reset) begin
        // for (i = 0; i < CACHE_BLOCK_BANK; i = i + 1) begin
        //     icache_valid[i] <= 1'b0;
        //     icache_addr[i]  <= 0;
        //     for (j = 0; j < CACHE_BLOCK_COUNT; j = j + 1) begin
        //         icache_data[i][j]  <= 0;
        //     end
        // end
        icache_valid[0] <= 1'b0;
        icache_valid[1] <= 1'b0;
        icache_valid[2] <= 1'b0;
        icache_valid[3] <= 1'b0;
        icache_addr[0]  <= 32'b0;
        icache_addr[1]  <= 32'b0;
        icache_addr[2]  <= 32'b0;
        icache_addr[3]  <= 32'b0;

        icache_data[0][0]  <= 32'b0;
        icache_data[0][1]  <= 32'b0;
        icache_data[0][2]  <= 32'b0;
        icache_data[0][3]  <= 32'b0;
        icache_data[1][0]  <= 32'b0;
        icache_data[1][1]  <= 32'b0;
        icache_data[1][2]  <= 32'b0;
        icache_data[1][3]  <= 32'b0;
        icache_data[2][0]  <= 32'b0;
        icache_data[2][1]  <= 32'b0;
        icache_data[2][2]  <= 32'b0;
        icache_data[2][3]  <= 32'b0;
        icache_data[3][0]  <= 32'b0;
        icache_data[3][1]  <= 32'b0;
        icache_data[3][2]  <= 32'b0;
        icache_data[3][3]  <= 32'b0;

        instruction <= 0;
        instruction_ready <= 1'b0;
    end
    else begin
        if (state == READ) begin
            if (io_icache_rvalid && io_icache_rid == io_icache_arid) begin
                if (sdram_valid) begin
                    icache_valid[burst_index]                               <= 1'b1;
                    icache_addr[burst_index][31:m+n]                        <= burst_addr[31:m+n];
                    icache_addr[burst_index][m+n-1:m]                       <= burst_addr[m+n-1:m];
                    icache_addr[burst_index][m-1:0]                         <= {m{1'b0}};
                    icache_data[burst_index][burst_offset]           <= io_icache_rdata;
                end
                if (io_icache_rlast) begin
                    instruction_ready            <= 1'b1;
                    if (sdram_valid) begin
                        instruction <= (offset == {(m-2){1'b1}})? io_icache_rdata : icache_data[index][offset];
                    end
                    else begin
                        instruction <= io_icache_rdata;
                    end
                end
            end
        end
        else if (fencei_signal) begin
            icache_valid[0] <= 1'b0;
            icache_valid[1] <= 1'b0;
            icache_valid[2] <= 1'b0;
            icache_valid[3] <= 1'b0;
        end
        if (state == IDLE) begin
            if (hit & pc_valid) begin
                instruction_ready <= 1'b1;
                instruction       <= icache_data[index][offset];
            end
            if (instruction_ready)
                instruction_ready <= 1'b0;
        end
    end
end

always @(posedge clock) begin
    io_icache_arvalid <= io_icache_arvalid;
    io_icache_araddr <= io_icache_araddr;
    io_icache_arid <= io_icache_arid;
    io_icache_arlen <= io_icache_arlen;
    io_icache_arsize <= io_icache_arsize;
    io_icache_arburst <= io_icache_arburst;
    io_icache_rready <= io_icache_rready;
    rresp <= rresp;
    if (reset) begin
        io_icache_araddr <= 32'h0;
        io_icache_arvalid <= 1'b0;
        io_icache_rready <= 1'b0;
        io_icache_arid <= 4'h0;
        io_icache_arsize <= 3'b010;
        io_icache_arburst <= 2'b00; 
        io_icache_arlen <= 8'h0;
        rresp <= 2'b0;
    end
    else begin
        if (state == IDLE && !hit && pc_valid) begin
            if (sdram_valid) begin
                io_icache_araddr  <= {pc_addr[31:m], {m{1'b0}}};
                io_icache_arvalid <= 1'b1;
                io_icache_arburst <= 2'b01; // INCR 01
                io_icache_arlen   <= 8'h3; // 4beat  3
            end
            else begin
                io_icache_arburst <= 2'b00;
                io_icache_arlen   <= 8'h0;
                io_icache_araddr  <= pc_addr;
                io_icache_arvalid <= 1'b1;
            end
        end

        if (io_icache_arvalid & io_icache_arready) begin
            io_icache_arvalid <= 1'b0;
            io_icache_rready <= 1'b1;
        end
            
        if (io_icache_rlast && io_icache_rvalid && io_icache_rid == io_icache_arid) begin
            io_icache_rready <= 1'b0;
            rresp <= io_icache_rresp;
        end
    end
end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/IFU/ysyx_25020042_icache.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/IFU/ysyx_25020042_IFU.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_IFU(
    input                  clock,
    input                  reset,
    input                  idu_ready,
    output reg             ifu_valid,

    input                  i_jump_valid,
    input      [31:0]      i_jump_pc,
    input                  i_fast_jump_valid,
    input      [31:0]      i_fast_jump_pc,

    input                  fencei_signal,
    input                  fault,
    output reg [31:0]      o_instruction,
    output wire [31:0]     o_pc_data    ,
    output [2:0]           o_IFU_Exception_Handling,

    `ifdef VERILATOR
    output     [63:0]      o_performance_counter,
    output reg [63:0]      o_cycles_counter,
    output reg [63:0]      o_single_cycles_counter,
    `ifdef ICACHE_ON
    output     [63:0]      o_icache_hit_count,
    `endif
    `endif

    output wire [31:0]     ifu_araddr,
    output wire            ifu_arvalid,
    input                  ifu_arready,
    output wire [7:0]      ifu_arlen,
    output wire [3:0]      ifu_arid,
    output wire [1:0]      ifu_arburst,
    output wire [2:0]      ifu_arsize,
    input      [31:0]      ifu_rdata,
    input                  ifu_rvalid,
    output wire            ifu_rready,
    input      [1:0]       ifu_rresp,
    input                  ifu_rlast,
    input      [3:0]       ifu_rid
);
`ifdef VERILATOR

    reg [63:0] performance_counter;
    reg        ifu_busy_signal;
    assign o_performance_counter = performance_counter;
    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if (pc_valid & ifu_ready)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            ifu_busy_signal <= 0;
        else if(i_jump_valid) begin
            if (state == IDLE && !(pc_valid && ifu_ready)) begin
                ifu_busy_signal <= 1'b0;
            end
            else if (state == READY && instruction_ready) begin
                ifu_busy_signal <= 1'b0;
            end
            else begin
                ifu_busy_signal <= 1'b1;
            end
        end
        else if(state == READY && instruction_ready && Control_Hazard) begin
                ifu_busy_signal <= 1'b0;
        end
        else if (pc_valid & ifu_ready)
            ifu_busy_signal <= 1;
        else if (idu_ready & ifu_valid)
            ifu_busy_signal <= 0;
    end

    always @(posedge clock) begin
        if(reset) begin
            o_cycles_counter <= 0;
        end
        else if (ifu_busy_signal) begin
            o_cycles_counter <= o_cycles_counter + 1;
        end
    end

    always @(posedge clock) begin
        if(reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (pc_valid && ifu_ready) begin
            o_single_cycles_counter <= 0;
        end
        else 
            o_single_cycles_counter <= o_single_cycles_counter + 1;
    end

`endif

wire Instruction_address_misaligned;
wire Instruction_access_fault;
wire Instruction_page_fault;
wire instruction_ready;
wire [31:0] instruction;
reg ifu_ready;
reg state ;
reg Control_Hazard;
localparam IDLE  = 1'b0;
localparam READY = 1'b1;

//-----------------pc------------------
reg [31:0] pc;
// reg [31:0] next_pc;
reg pc_valid;
always @(posedge clock) begin
        if (reset)begin
            `ifdef PLATFORM_NPC
            pc <= 32'h8000_0000;
            `else
            pc <= 32'h3000_0000;
            // pc <= 32'h8000_0000;
            `endif
        end 
        else if (fault)begin
            pc <= 0;
        end
        else if (i_jump_valid) begin
            pc <= i_jump_pc;
        end
        else if (i_fast_jump_valid) begin
            pc <= i_fast_jump_pc;
        end
        else if (ifu_valid & idu_ready)begin
            pc <= pc + 4;
        end
    end

// always @(posedge clock) begin
//         if (reset) begin
//             `ifdef PLATFORM_NPC
//             next_pc <= 32'h8000_0004;
//             `else
//             // next_pc <= 32'h3000_0004;
//             next_pc <= 32'h8000_0004;

//             `endif
//         end
//         else if (i_jump_valid) begin
//             next_pc <= i_jump_pc + 4;
//         end
//         else if (i_fast_jump_valid) begin
//             next_pc <= i_fast_jump_pc + 4;
//         end
//         else if (ifu_ready & pc_valid) begin
//             next_pc <= pc + 4;
//         end
//         else begin
//             next_pc <= next_pc;
//         end
//     end

always @(posedge clock) begin
        if (reset)begin
            pc_valid <= 1'b1;
        end 
        else if (ifu_valid & idu_ready) 
            pc_valid <= 1'b1;
        else if (i_jump_valid)
            pc_valid <= 1'b1;
        else 
            pc_valid <= ifu_ready ? 1'b0 :pc_valid;
            
    end

//-----------------ifu-------------------
assign o_pc_data = pc;
assign o_IFU_Exception_Handling = {Instruction_page_fault, Instruction_access_fault, Instruction_address_misaligned};
assign Instruction_page_fault = 1'b0;
assign Instruction_address_misaligned = |pc[1:0];

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
    end
    else begin
        case(state)
            IDLE: begin
                if(pc_valid & ifu_ready) begin
                    state <= READY;
                end
                else begin
                    state <= IDLE;
                end
            end
            READY: begin
                if(instruction_ready) begin
                    state <= IDLE;
                end
                else begin
                    state <= READY;
                end
            end
            default: begin
                state <= state;
                end
        endcase
    end
end

always @(posedge clock) begin
    if(reset) begin
        Control_Hazard <= 1'b0;
    end
    else begin
        if (Control_Hazard & instruction_ready) begin
            Control_Hazard <= 1'b0;
        end
        else if(i_jump_valid && ((state == READY) || (pc_valid & ifu_ready))) begin
            Control_Hazard <= 1'b1;
            if (instruction_ready) begin
                Control_Hazard <= 1'b0;
            end
        end
        else begin
            Control_Hazard <= Control_Hazard;
        end
    end
end

always @(posedge clock) begin
    if(reset) begin
        ifu_ready <= 1'b1;
        ifu_valid <= 1'b0;
    end
    else begin
        if(i_jump_valid) begin
            if (state == IDLE && !(pc_valid && ifu_ready)) begin
                ifu_ready <= 1'b1;
            end
            else if (state == READY && instruction_ready) begin
                ifu_ready <= 1'b1;
            end
            else begin
                ifu_ready <= 1'b0;
            end
            ifu_valid <= 1'b0;
        end
        else if(ifu_ready & pc_valid) begin
            ifu_ready <= 1'b0;
            ifu_valid <= 1'b0;
        end
        else if(state == READY && instruction_ready) begin
            if(Control_Hazard) begin
                ifu_valid <= 1'b0;
                ifu_ready <= 1'b1;
            end
            else begin
                ifu_valid <= 1'b1;
                ifu_ready <= 1'b0;
            end
        end
        else if (idu_ready & ifu_valid) begin
            ifu_valid <= 1'b0;
            ifu_ready <= 1'b1;
        end
    end
end

always @(posedge clock) begin
    if(reset) begin
        o_instruction <= 32'h0;
    end
    else if (i_jump_valid)
        o_instruction <= 32'h0;
    else begin
        if(state == READY && instruction_ready) begin
            o_instruction <= instruction;
        end
    end
end

ysyx_25020042_icache #(
    .CACHE_BLOCK_SIZE(16), //4 * 8
    .CACHE_BLOCK_BANK(4) //2 ^ n
) u_icache(
    .clock            (clock),
    .reset            (reset),
    .pc_valid         (pc_valid & ifu_ready),
    .pc_addr          (pc),
    .fencei_signal    (fencei_signal),
    `ifdef VERILATOR
    .icache_hit_count (o_icache_hit_count),
    `endif
    .instruction_ready(instruction_ready),
    .instruction      (instruction),
    .Instruction_access_fault(Instruction_access_fault),
    .io_icache_arready(ifu_arready),
    .io_icache_arvalid(ifu_arvalid),
    .io_icache_araddr (ifu_araddr),
    .io_icache_arid   (ifu_arid),
    .io_icache_arlen  (ifu_arlen),
    .io_icache_arsize (ifu_arsize),
    .io_icache_arburst(ifu_arburst),
    .io_icache_rready (ifu_rready),
    .io_icache_rvalid (ifu_rvalid),
    .io_icache_rresp  (ifu_rresp),
    .io_icache_rdata  (ifu_rdata),
    .io_icache_rlast  (ifu_rlast),
    .io_icache_rid    (ifu_rid)
);

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/IFU/ysyx_25020042_IFU.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/IDU/ysyx_25020042_IDU.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_IDU (
    input   wire         clock                  ,  
    input   wire         reset                  ,
    input   wire         ifu_valid              ,
    input   wire         exu_ready              ,
    output  reg          idu_ready              ,
    output  reg          idu_valid              ,
    `ifdef VERILATOR 
    output reg  [63:0]   csr_hit_counter        ,
    output reg  [63:0]   exu_hit_counter        ,
    output reg  [63:0]   jump_hit_counter       ,
    output reg  [63:0]   mem_hit_counter        ,
    output reg  [63:0]   fence_hit_counter      ,
    output reg  [63:0]   performance_counter    ,
    output reg  [63:0]   cycles_counter         ,
    input  wire [63:0]   i_single_cycles_counter,
    output reg  [63:0]   o_single_cycles_counter,
    `endif
 
    input  wire          i_jump_valid           ,
    input  wire [31:0]   i_inst                 ,
    input  wire [31:0]   i_pc_data              ,
    output reg  [7:0]    o_instruction_out      ,
    input  wire [2:0]    i_IFU_Exception_Handling,
    output reg [2:0]     o_IFU_Exception_Handling,
    output wire [2:0]    o_IDU_Exception_Handling,
    `ifdef VERILATOR 
    output reg [31:0]    o_instruction_data     ,
    `endif 
    output wire          o_fast_jump_valid      ,
    output wire [31:0]   o_fast_jump_pc         ,
    output reg  [31:0]   o_imm                  ,
    output reg  [31:0]   o_pc_data              ,
    output reg  [11:0]   o_csr_addr             ,
    output reg  [5:0]    o_shamt                ,
    output reg  [4:0]    o_rd                   ,
    output reg  [4:0]    o_rs1                  ,
    output reg  [4:0]    o_rs2
);

    localparam  NOP_INST     = 3'b000;
    localparam  EXU_INST     = 3'b001;
    localparam  JUMP_INST    = 3'b010;
    localparam  MEM_INST     = 3'b011;
    localparam  CSR_INST     = 3'b100;
    localparam  SPECIAL_INST = 3'b101;

    wire csr_valid = (opcode == 7'b1110011);
    wire [6:0] opcode = i_inst[6:0];
    wire [11:7] rd = i_inst[11:7];
    wire [19:15] rs1 = i_inst[19:15];
    wire [24:20] rs2 = i_inst[24:20];
    wire [14:12] funct3 = i_inst[14:12];
    wire [31:25] funct7 = i_inst[31:25];
    wire [31:0]  u_imm = {i_inst[31:12], 12'b0};
    wire [31:0]  i_imm = {{20{i_inst[31]}}, i_inst[31:20]};
    wire [31:0]  s_imm = {{20{i_inst[31]}}, i_inst[31:25], i_inst[11:7]};
    wire [31:0]  b_imm = {{19{i_inst[31]}}, i_inst[31], i_inst[7], i_inst[30:25], i_inst[11:8], 1'b0};
    wire [31:0]  j_imm = {{11{i_inst[31]}}, i_inst[31], i_inst[19:12], i_inst[20], i_inst[30:21], 1'b0};
    wire [24:20] shamt = i_inst[24:20];
    wire [11:0] csr_addr = i_inst[31:20];
    wire ebreak_signal  = (o_instruction_out == 8'b10000101);
    wire ecall_signal   = (o_instruction_out  == 8'b10000011);
    wire illegal_signal = (o_instruction_out[4:0]  == 5'b0);

    wire u_type_signal = (opcode == 7'b0110111 | opcode == 7'b0010111);
    wire i_type_signal = (opcode == 7'b1100111 | opcode == 7'b0000011 | opcode == 7'b0010011 | opcode == 7'b0001111 | opcode == 7'b1110011);
    wire s_type_signal = (opcode == 7'b0100011);
    wire b_type_signal = (opcode == 7'b1100011);
    wire j_type_signal = (opcode == 7'b1101111);
    wire r_type_signal = (opcode == 7'b0110011);

    assign o_IDU_Exception_Handling = {ecall_signal, ebreak_signal, illegal_signal};
    assign o_fast_jump_valid = j_type_signal & ifu_valid & idu_ready;
    assign o_fast_jump_pc    = i_pc_data + j_imm;

`ifdef VERILATOR
    reg idu_busy_signal;
    always @(posedge clock) begin
        if (reset) begin
            csr_hit_counter <= 0;
            exu_hit_counter <= 0;
            jump_hit_counter <= 0;
            mem_hit_counter <= 0;
            fence_hit_counter <= 0;
        end
        else if (exu_ready & idu_valid) begin
            case (o_instruction_out[7:5])
            CSR_INST:  csr_hit_counter <= csr_hit_counter + 1;
            MEM_INST:  mem_hit_counter <= mem_hit_counter + 1;
            SPECIAL_INST:fence_hit_counter <= fence_hit_counter + 1;
            JUMP_INST: jump_hit_counter <= jump_hit_counter + 1;
            default:    exu_hit_counter <= exu_hit_counter + 1;
            endcase
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (ifu_valid & idu_ready) begin
            o_single_cycles_counter <= i_single_cycles_counter;
        end
        else begin
            o_single_cycles_counter <= o_single_cycles_counter + 1;
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            performance_counter <= 0;
        end
        else if (exu_ready & idu_valid) begin
            performance_counter <= performance_counter + 1;
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            idu_busy_signal <= 0;
        end 
        else if (i_jump_valid) begin
            idu_busy_signal <= 0;
        end
        else if (ifu_valid & idu_ready) begin
            idu_busy_signal <= 1;
        end
        else if (idu_valid & exu_ready) begin
            idu_busy_signal <= 0;
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            cycles_counter <= 0;
        end
        else if (idu_busy_signal) begin
            cycles_counter <= cycles_counter + 1;
        end
    end

`endif

    always @ (posedge clock) begin
        if (reset) begin
            idu_ready <= 1'b1;
            idu_valid <= 1'b0;
        end
        else if (i_jump_valid) begin
            idu_ready <= 1'b1;
            idu_valid <= 1'b0;
        end
        else if (ifu_valid & idu_ready) begin
                idu_ready <= 1'b0;
                idu_valid <= 1'b1;
        end
        else if (exu_ready & idu_valid) begin
            idu_ready <= 1'b1;
            idu_valid <= 1'b0;
            // $display("exu_ready = %b idu_valid = %b idu inst: %08b", exu_ready, idu_valid, o_instruction_out);
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_imm <= 32'b0;
        end
            // o_imm <= 32'b0;
        else if (i_jump_valid) begin
            o_imm <= 32'b0;
        end

        else if (ifu_valid & idu_ready) begin
            case (1'b1)
                u_type_signal: o_imm <= u_imm;
                i_type_signal: o_imm <= i_imm;
                s_type_signal: o_imm <= s_imm;
                j_type_signal: o_imm <= j_imm;
                b_type_signal: o_imm <= b_imm;
                default: o_imm <= 32'b0;
            endcase
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_rs1 <= 5'b0;
        end
        else if (i_jump_valid)
            o_rs1 <= 5'b0;
        else if (ifu_valid & idu_ready) begin
            if (r_type_signal | i_type_signal | j_type_signal | b_type_signal | s_type_signal)
                o_rs1 <= rs1;
            else 
                o_rs1 <= 5'b0;
        end
    end

    always @ (posedge clock) begin
        if (reset)
            o_IFU_Exception_Handling <= 3'b0;
        else if (i_jump_valid)
            o_IFU_Exception_Handling <= 3'b0;
        else if (ifu_valid & idu_ready) begin
                o_IFU_Exception_Handling <= i_IFU_Exception_Handling;
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_rs2 <= 5'b0;
        end
        else if (i_jump_valid)
            o_rs2 <= 5'b0;
        else if (ifu_valid & idu_ready) begin
            if (b_type_signal | s_type_signal | r_type_signal)
                o_rs2 <= rs2;
            else
                o_rs2 <= 5'b0;
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_pc_data <= 32'b0;
            `ifdef VERILATOR
                o_instruction_data <= 32'b0;
            `endif
        end
        else if (i_jump_valid) begin
            o_pc_data <= 32'b0;
                `ifdef VERILATOR
                    o_instruction_data <= 32'b0;
                `endif
        end
        else if (ifu_valid & idu_ready) begin
            o_pc_data <= i_pc_data;
                `ifdef VERILATOR
                    o_instruction_data <= i_inst;
                `endif
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_rd <= 5'b0;
        end
        else if (i_jump_valid)
            o_rd <= 5'b0;
        else if (ifu_valid & idu_ready) begin
            if (r_type_signal | i_type_signal | u_type_signal | j_type_signal) 
                o_rd <= rd;
            else
                o_rd <= 5'b0;
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_csr_addr <= 12'b0;
        end
            
        else if (i_jump_valid)
            o_csr_addr <= 12'b0;
        else if (ifu_valid & idu_ready) begin
            if (csr_valid)
                o_csr_addr <= csr_addr;
            else 
                o_csr_addr <= 12'b0;
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_shamt <= 6'b0;
        end
            
        else if (i_jump_valid)
            o_shamt <= 6'b0;
        else if (ifu_valid & idu_ready) begin
            o_shamt <= {1'b0, shamt};
        end
    end

    always @ (posedge clock) begin
        if (reset) begin
            o_instruction_out     <= 8'b0;
        end
        else if (i_jump_valid)
            o_instruction_out     <= 8'b0;
        else begin
            if (ifu_valid & idu_ready) begin
                case (1'b1)
                    u_type_signal: begin
                            o_instruction_out[7:5] <= EXU_INST;
                        case (opcode) 
                        7'b0110111:
                            o_instruction_out[4:0] <= 5'b00110;//lui                        
                        7'b0010111:
                            o_instruction_out[4:0] <= 5'b00101;//auipc
                        default:
                            o_instruction_out[4:0] <= 5'b00000; // nop
                        endcase
                    end

                    s_type_signal: begin
                        if (opcode == 7'b0100011) begin
                            o_instruction_out[7:5] <= MEM_INST;
                            case (funct3) 
                            3'b000:
                                o_instruction_out[4:0] <= 5'b01000;//sb
                            3'b001:
                                o_instruction_out[4:0] <= 5'b00111;//sh
                            3'b010:
                                o_instruction_out[4:0] <= 5'b00110;//sw
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end
                        else begin
                            o_instruction_out[7:5] <= NOP_INST;
                            o_instruction_out[4:0] <= 5'b00000;
                        end
                    end

                    i_type_signal: begin
                        case (opcode) 
                        7'b1100111:begin
                            o_instruction_out[7:5] <= JUMP_INST;
                            case (funct3) 
                            3'b000:
                                o_instruction_out[4:0] <= 5'b00001;//jalr
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end
                        7'b0010011: begin
                            o_instruction_out[7:5] <= EXU_INST;
                            case (funct3) 
                            3'b000:
                                o_instruction_out[4:0] <= 5'b00001;//addi
                            3'b001:
                                o_instruction_out[4:0] <= (funct7 == 7'b0000000) ? 5'b01000 : 5'b00000;//slli
                            3'b010:
                                o_instruction_out[4:0] <= 5'b01001;//slti
                            3'b011:
                                o_instruction_out[4:0] <= 5'b01010;//sltiu
                            3'b100:
                                o_instruction_out[4:0] <= 5'b00011;//xori
                            3'b101:begin
                                if (funct7 == 7'b0000000) 
                                    o_instruction_out[4:0] <= 5'b01011;//srli
                                else if (funct7 == 7'b0100000) 
                                    o_instruction_out[4:0] <= 5'b00111;//srai
                                else
                                    o_instruction_out[4:0] <= 5'b00000;//nop
                                end
                            3'b110:
                                o_instruction_out[4:0] <= 5'b00100;//ori
                            3'b111:
                                o_instruction_out[4:0] <= 5'b00010;//andi
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end

                        7'b1110011: begin
                            o_instruction_out[7:5] <= CSR_INST;
                            case (funct3) 
                            3'b000: begin
                                if ({funct7, rs2} == 12'b000000000001) 
                                    o_instruction_out[4:0] <= 5'b00101;//ebreak                              
                                else if ({funct7, rs2} == 12'b000000000000) 
                                    o_instruction_out[4:0] <= 5'b00011;//ecall  
                                else if ({funct7, rs2} == 12'b001100000010) 
                                    o_instruction_out[4:0] <= 5'b00100;//mret                              
                                else
                                     o_instruction_out[4:0] <= 5'b00000;//nop
                            end
                            3'b001:
                                o_instruction_out[4:0] <= 5'b00010;//csrrw
                            3'b010:
                                o_instruction_out[4:0] <= 5'b00001;//csrrs
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end

                        7'b0000011: begin
                            o_instruction_out[7:5] <= MEM_INST;
                            case (funct3) 
                            3'b000:
                                o_instruction_out[4:0] <= 5'b00100;//lb
                            3'b001:
                                o_instruction_out[4:0] <= 5'b00010;//lh
                            3'b010:
                                o_instruction_out[4:0] <= 5'b00001;//lw
                            3'b100:
                                o_instruction_out[4:0] <= 5'b00101;//lbu
                            3'b101:
                                o_instruction_out[4:0] <= 5'b00011;//lhu
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end
                        7'b0001111: begin
                            o_instruction_out[7:5] <= SPECIAL_INST;
                            case (funct3) 
                            3'b001:
                                o_instruction_out[4:0] <= 5'b00001;//fencei
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end
                        default:
                            o_instruction_out[4:0] <= 5'b00000; // nop
                        endcase
                    end

                    r_type_signal: begin
                        o_instruction_out[7:5] <= EXU_INST;
                        if (funct7 == 7'b0000000) begin
                            case (funct3)
                            3'b000:
                                o_instruction_out[4:0] <= 5'b01101;//add
                            3'b001:
                                o_instruction_out[4:0] <= 5'b01100;//sll
                            3'b010:
                                o_instruction_out[4:0] <= 5'b10010;//slt
                            3'b011:
                                o_instruction_out[4:0] <= 5'b10011;//sltu
                            3'b100:
                                o_instruction_out[4:0] <= 5'b10000;//xor
                            3'b101:
                                o_instruction_out[4:0] <= 5'b10101;//srl
                            3'b110:
                                o_instruction_out[4:0] <= 5'b01111;//or
                            3'b111:
                                o_instruction_out[4:0] <= 5'b01110;//and
                            endcase
                        end
                        else if (funct7 == 7'b0100000) begin
                            case (funct3)
                            3'b000:
                                o_instruction_out[4:0] <= 5'b10001;//sub
                            3'b101:
                                o_instruction_out[4:0] <= 5'b10100;//sra
                            default:
                                o_instruction_out[4:0] <= 5'b00000; // nop
                            endcase
                        end
                        else 
                            o_instruction_out[4:0] <= 5'b00000; // nop
                    end

                    b_type_signal: begin
                        o_instruction_out[7:5] <= JUMP_INST;
                        case (funct3) 
                        3'b000:
                            o_instruction_out[4:0] <= 5'b00011;//beq
                        3'b001:
                            o_instruction_out[4:0] <= 5'b00100;//bne
                        3'b100:
                            o_instruction_out[4:0] <= 5'b00111;//blt
                        3'b101:
                            o_instruction_out[4:0] <= 5'b00101;//bge
                        3'b110:
                            o_instruction_out[4:0] <= 5'b01000;//bltu
                        3'b111:
                            o_instruction_out[4:0] <= 5'b00110;//bgeu
                        default:
                            o_instruction_out[4:0] <= 5'b00000; // nop
                        endcase
                    end

                    j_type_signal: begin
                        o_instruction_out[7:5] <= JUMP_INST;
                        o_instruction_out[4:0] <= 5'b00010;//jal
                    end
                endcase
            end
        end
    end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/IDU/ysyx_25020042_IDU.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/IDU/ysyx_25020042_gpr.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_gpr  (
    input clock,
    input reset,   
    /* verilator lint_off UNUSEDSIGNAL */
    input  [4:0] i_rs1,
    input  [4:0] i_rs2,
    /* verilator lint_on UNUSEDSIGNAL */
    input  [4:0] i_rd,
    input  [31:0] i_data,
    input  wbu_valid,
    output [31:0] o_src1,
    output [31:0] o_src2
    );
    
    wire [15:0] wen;
    wire [31:0] reg_file [0:15];
    assign wen = wbu_valid? (16'b1 << i_rd) : 16'b0; // 写使能信号

    reg [31:0] zero;
    reg [31:0] ra;  
    reg [31:0] sp; 
    reg [31:0] gp;  
    reg [31:0] tp;  
    reg [31:0] t0;  
    reg [31:0] t1;  
    reg [31:0] t2;  
    reg [31:0] s0;  
    reg [31:0] s1;  
    reg [31:0] a0;  
    reg [31:0] a1;  
    reg [31:0] a2;  
    reg [31:0] a3;  
    reg [31:0] a4;  
    reg [31:0] a5; 
    always @(posedge clock) begin
        if (reset) begin
            zero <= 32'b0;
            ra   <= 32'b0;
            sp   <= 32'b0;
            gp   <= 32'b0;
            tp   <= 32'b0;
            t0   <= 32'b0;
            t1   <= 32'b0;
            t2   <= 32'b0;
            s0   <= 32'b0;
            s1   <= 32'b0;
            a0   <= 32'b0;
            a1   <= 32'b0;
            a2   <= 32'b0;
            a3   <= 32'b0;
            a4   <= 32'b0;
            a5   <= 32'b0;
        end else begin
            if (wen[0]) zero   <= 0;
            if (wen[1]) ra   <= i_data;
            if (wen[2]) sp   <= i_data;
            if (wen[3]) gp   <= i_data;
            if (wen[4]) tp   <= i_data;
            if (wen[5]) t0   <= i_data;
            if (wen[6]) t1   <= i_data;
            if (wen[7]) t2   <= i_data;
            if (wen[8]) s0   <= i_data;
            if (wen[9]) s1   <= i_data;
            if (wen[10]) a0  <= i_data;
            if (wen[11]) a1  <= i_data;
            if (wen[12]) a2  <= i_data;
            if (wen[13]) a3  <= i_data;
            if (wen[14]) a4  <= i_data;
            if (wen[15]) a5  <= i_data;
        end
    end
    assign reg_file [0] = zero;
    assign reg_file [1] = ra;
    assign reg_file [2] = sp;
    assign reg_file [3] = gp;
    assign reg_file [4] = tp;
    assign reg_file [5] = t0;
    assign reg_file [6] = t1;
    assign reg_file [7] = t2;
    assign reg_file [8] = s0;
    assign reg_file [9] = s1;
    assign reg_file [10] = a0;
    assign reg_file [11] = a1;
    assign reg_file [12] = a2;
    assign reg_file [13] = a3;
    assign reg_file [14] = a4;
    assign reg_file [15] = a5;


// 读取寄存器
    assign o_src1 = reg_file[i_rs1[3:0]];
    assign o_src2 = reg_file[i_rs2[3:0]];

endmodule






// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/IDU/ysyx_25020042_gpr.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/EXU/ysyx_25020042_EXU.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_EXU(
    input wire clock,
    input wire reset,
    input wire idu_valid,
    input wire lsu_ready,
    output wire exu_ready,
    // output reg exu_ready,
    output reg exu_valid,

    `ifdef VERILATOR
    output reg [63:0] performance_counter,
    output reg [63:0] cycles_counter,
    input  wire [63:0]   i_single_cycles_counter,
    output reg  [63:0]   o_single_cycles_counter,
    `endif

    input wire [7:0] i_inst,
    input wire [31:0] i_src1,
    input wire [31:0] i_src2,
    input wire [31:0] i_imm,
    input wire [31:0] i_pc_data,
    input wire [5:0]  i_shamt,
    input wire [31:0] i_csr_data,
    input wire [11:0] i_csr_addr,
    input wire [31:0] i_mepc_rdata,
    input wire [31:0] i_mtvec_rdata,
    input wire        i_src1_valid,
    input wire        i_src2_valid,
    input  wire [2:0]    i_IFU_Exception_Handling,
    output reg [2:0]     o_IFU_Exception_Handling,
    input  wire [2:0]    i_IDU_Exception_Handling,
    output reg [2:0]     o_IDU_Exception_Handling,
    input  wire [5:0]    i_LSU_Exception_Handling,
    `ifdef VERILATOR
    input  [31:0]     i_instruction_data,
    `endif
    // input wire [4:0]  i_rd,
    output reg [31:0]  o_csr_data,
    output reg [11:0]  o_csr_addr,
    output reg  [7:0]  o_idu_inst,
    output reg  [31:0] o_pc_data,
    output wire        o_fence_i_valid,
    `ifdef VERILATOR
    output reg [31:0] o_instruction_data,
    `endif
    output reg  [31:0] o_src2,
    // output reg  [4:0] o_rd,
    output reg [31:0] jump_pc,
    output wire        jump_valid,
    // output reg [31:0] o_data
    output wire  [31:0]  o_data
);

    localparam  EXU_INST     = 3'b001;
    localparam  JUMP_INST    = 3'b010;
    localparam  MEM_INST     = 3'b011;
    localparam  CSR_INST     = 3'b100;
    localparam  SPECIAL_INST = 3'b101;

    reg [31:0] alu_data1;
    reg [31:0] alu_data2;
    reg [3:0]  alu_ctrl;
    reg        B_jump_signal;
    reg        jump_valid_signal;
    reg        Exception_hit_reg;
    wire Exception_valid0 = |{i_IFU_Exception_Handling, i_IDU_Exception_Handling};
    wire Exception_valid1 = |i_LSU_Exception_Handling;
    wire [31:0] alu_out;
    wire equal       = (i_src1 == i_src2);
    wire sign_less   = $signed(i_src1) < $signed(i_src2) ? 1'b1 : 1'b0;
    wire unsign_less = (i_src1 < i_src2);

    always @(posedge clock) begin
        if (reset)
            Exception_hit_reg <= 1'b0;
        else if (Exception_valid1) 
            Exception_hit_reg <= 1'b1;
        else 
            Exception_hit_reg <= 1'b0;
    end

    assign exu_ready = idu_valid & !exu_valid & i_src1_valid & i_src2_valid;
    always @(posedge clock) begin
        if (reset) begin
            exu_valid <= 0;
        end
        else if (idu_valid & exu_ready) begin
            exu_valid <= 1;
        end
        else if ((lsu_ready | (Exception_valid1 & !Exception_hit_reg)) & exu_valid) begin
            exu_valid <= 0;
        end
    end

    // always @(posedge clock) begin
    //     if (reset) begin
    //         exu_ready <= 0;
    //         exu_valid <= 0;
    //     end
    //     else if (!exu_valid & !exu_ready & idu_valid & i_src1_valid & i_src2_valid) begin
    //         exu_ready <= 1;
    //     end
    //     else if (idu_valid & exu_ready) begin
    //         exu_ready <= 0;
    //         exu_valid <= 1;
    //     end
    //     else if ((lsu_ready | (Exception_valid1 & !Exception_hit_reg)) & exu_valid) begin
    //         exu_valid <= 0;
    //         if (idu_valid & i_src1_valid & i_src2_valid)
    //             exu_ready <= 1;
    //         else 
    //             exu_ready <= 0;
    //     end
    // end

    `ifdef VERILATOR
    // reg [63:0] performance_counter;
    always @(posedge clock) begin
        if (reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (idu_valid & exu_ready) begin
            o_single_cycles_counter <= i_single_cycles_counter;
        end
        else begin
            o_single_cycles_counter <= o_single_cycles_counter + 1;
        end
    end

    reg exu_busy_signal;

    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if (idu_valid & exu_ready)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            exu_busy_signal <= 0;
        else if (idu_valid & exu_ready)
            exu_busy_signal <= 1;
        else if (lsu_ready & exu_valid)
            exu_busy_signal <= 0;
    end

    always @(posedge clock) begin
        if(reset) 
            cycles_counter <= 0;
        else if (exu_busy_signal)
            cycles_counter <= cycles_counter + 1;
    end


    `endif

assign jump_valid = jump_valid_signal & (exu_valid | (Exception_valid1 & !Exception_hit_reg));
assign o_fence_i_valid = i_inst == 8'b10100001;

always @(posedge clock) begin
    if(reset) begin
        jump_pc <= 32'h0;
        jump_valid_signal <= 1'b0;
    end
    else if (idu_valid & exu_ready) begin
        case(i_inst[7:5])
            JUMP_INST: begin
                if (B_jump_signal == 1'b1) begin
                    jump_pc <= alu_out;
                    jump_valid_signal <= 1'b1;
                end
                else if (i_inst[4:0] == 5'b00001) begin
                    jump_pc <= alu_out;
                    jump_valid_signal <= 1'b1;
                end
            end
        
            CSR_INST: begin
                case (i_inst[4:0])
                    5'b00100: begin // mret
                        jump_pc <= i_mepc_rdata;
                        jump_valid_signal <= 1'b1;
                    end
                    5'b00011: begin // ecall
                        jump_pc <= i_mtvec_rdata;
                        jump_valid_signal <= 1'b1;
                    end
                    default: begin
                        jump_valid_signal <= 1'b0;
                    end
                endcase
            end
            SPECIAL_INST: begin
                jump_pc <= i_pc_data + 4;
                jump_valid_signal <= 1'b1;
            end 
            default: begin
                if (Exception_valid0 | Exception_valid1) begin
                    jump_valid_signal <= 1'b1;
                    jump_pc <= i_mtvec_rdata;
                end
                else
                jump_valid_signal <= 1'b0;
            end
        endcase
    end
    else if (exu_valid)begin
        jump_valid_signal <= 1'b0;
    end
end

    assign o_data = alu_out;

    always @(posedge clock) begin
        if (reset) begin
            o_pc_data <= 0;
            o_idu_inst <= 0;
            o_csr_data <= 0;
            o_src2     <= 0;
            o_csr_addr <= 0;
            o_IFU_Exception_Handling <= 0;
            o_IDU_Exception_Handling <= 0;
            `ifdef VERILATOR
                o_instruction_data <= 32'b0;
            `endif
        end
        else if (idu_valid & exu_ready) begin
            o_pc_data <= i_pc_data;
            o_idu_inst <= i_inst;
            o_csr_data <= i_csr_data;
            o_src2     <= i_src2;
            o_csr_addr <= i_csr_addr;
            o_IFU_Exception_Handling <= i_IFU_Exception_Handling;
            o_IDU_Exception_Handling <= i_IDU_Exception_Handling;
            `ifdef VERILATOR
                o_instruction_data <= i_instruction_data;
            `endif
        end
    end

    always @(*) begin
        B_jump_signal = 1'b0;
        if(i_inst[7:5] == JUMP_INST) begin
            case(i_inst[4:0])
            5'b00001:  // jalr
                B_jump_signal = 1'b0;
            5'b00010:  // jal
                B_jump_signal = 1'b0;
            5'b00011:  // beq
                B_jump_signal = equal ? 1'b1 : 1'b0;
            5'b00100:  // bne
                B_jump_signal = equal ? 1'b0 : 1'b1;
            5'b00101:  // bge
                B_jump_signal = sign_less ? 1'b0 : 1'b1;
            5'b00110:  // bgeu
                B_jump_signal = unsign_less ? 1'b0 : 1'b1;   
            5'b00111:  // blt
                B_jump_signal = sign_less ? 1'b1 : 1'b0;          
            5'b01000:  // bltu
                B_jump_signal = unsign_less ? 1'b1 : 1'b0;           
            default: 
                B_jump_signal = 1'b0;
            endcase
        end
    end

// ALUctr[3] | ALUctr[2:0] | ALU操作
// ---------|------------|--------------------------------
// 0        | 000        | 选择加法器输出，做加法
// 1        | 000        | 选择加法器输出，做减法
// ×        | 001        | 选择移位器输出，左移
// 0        | 010        | 做减法，选择带符号小于置位结果输出, Less按带符号结果设置
// 1        | 010        | 做减法，选择无符号小于置位结果输出, Less按无符号结果设置
// ×        | 011        | 选择ALU输入B的结果直接输出
// ×        | 100        | 选择异或输出
// 0        | 101        | 选择移位器输出，逻辑右移
// 1        | 101        | 选择移位器输出，算术右移
// ×        | 110        | 选择逻辑或输出
// ×        | 111        | 选择逻辑与输出
    always @(*) begin
        case(i_inst[7:5])
            EXU_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin//addi 
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    5'b00010: begin // andi
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0111;
                    end
                    5'b00011: begin // xori
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0100;
                    end
                    5'b00100: begin // ori
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0110;
                    end
                    5'b00101: begin//auipc
                        alu_data1 = i_pc_data;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    5'b00110: begin // lui
                        alu_data1 = 0;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00111: begin // srai
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b1101;
                    end
                    5'b01000: begin // slli
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b0001;
                    end
                    5'b01001: begin // slti
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0010;
                    end
                    5'b01010: begin // sltiu
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b1010;
                    end
                    5'b01011: begin // srli
                        alu_data1 = i_src1;
                        alu_data2 = {26'b0 ,i_shamt};
                        alu_ctrl = 4'b0101;
                    end
                    5'b01100: begin // sll
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0001;
                    end
                    5'b01101: begin // add
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0000;
                    end
                    5'b01110: begin //and
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0111;
                    end
                    5'b01111: begin //or
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0110;
                    end
                    5'b10000: begin // xor
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0100;
                    end
                    5'b10001: begin // sub
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1000;
                    end
                    5'b10010: begin // slt
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0010;
                    end
                    5'b10011: begin // sltu
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1010;
                    end
                    5'b10100: begin // sra
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b1101;
                    end
                    5'b10101: begin // srl
                        alu_data1 = i_src1;
                        alu_data2 = i_src2;
                        alu_ctrl = 4'b0101;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end
            JUMP_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // jalr
                        alu_data1 = i_src1;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                    default: begin
                        alu_data1 = i_pc_data;
                        alu_data2 = i_imm;
                        alu_ctrl = 4'b0000;
                    end
                endcase
            end

            MEM_INST: begin
                alu_data1 = i_src1;
                alu_data2 = i_imm;
                alu_ctrl = 4'b0000;
            end

            CSR_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // csrrs
                        alu_data1 = i_src1;
                        alu_data2 = i_csr_data;
                        alu_ctrl = 4'b0110;
                    end
                    5'b00010: begin // csrrw
                        alu_data1 = 0;
                        alu_data2 = i_src1;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00011: begin // ecall
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00100: begin // mret
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    5'b00101: begin // ebreak
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end

            SPECIAL_INST: begin
                case(i_inst[4:0])
                    5'b00001: begin // fencei
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                    default: begin
                        alu_data1 = 0;
                        alu_data2 = 0;
                        alu_ctrl = 4'b0011;
                    end
                endcase
            end

            default: begin
                alu_data1 = 0;
                alu_data2 = 0;
                alu_ctrl = 4'b0011;
            end

        endcase
    end

ysyx_25020042_alu u_alu(
    .data1(alu_data1),
    .data2(alu_data2),
    .ALUctrl(alu_ctrl),
    .o_data(alu_out)
);

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/EXU/ysyx_25020042_EXU.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/EXU/ysyx_25020042_alu.v ----------
`timescale 1ns/1ns 

module ysyx_25020042_alu (
    input [31:0] data1,
    input [31:0] data2,
    input [3:0] ALUctrl,
    output reg [31:0] o_data
);

wire [31:0] adder_out;
wire [31:0] shift_out;
wire [31:0] less_out;

always @(*) begin
    o_data = 32'h00000000;
    case (ALUctrl[2:0])
        3'b000: o_data = adder_out;
        3'b001: o_data = shift_out;
        3'b010: o_data = less_out;
        3'b011: o_data = data2;
        3'b100: o_data = data1 ^ data2;
        3'b101: o_data = shift_out;
        3'b110: o_data = data1 | data2;
        3'b111: o_data = data1 & data2;
    endcase
end

adder u_adder (
    .Add(~ALUctrl[3]),
    .x(data1),
    .y(data2),
    .sum(adder_out)
);

barrel_shifter_param u_shift (
    .Logic(~ALUctrl[3]),
    .Right(ALUctrl[2:0] == 3'b101),
    .data_i(data1),   
    .shift_amt(data2[4:0]), 
    .data_o(shift_out)  
);

comparer u_comparer (
    .sign(~ALUctrl[3]),
    .x(data1),
    .y(data2),
    .less_out(less_out)
);

endmodule

module comparer (
    input sign,
    input [31:0] x,
    input [31:0] y,
    output reg [31:0]less_out
);
always @(*) begin
    if (sign) begin
        less_out = $signed(x) < $signed(y) ? 32'h00000001 : 32'h00000000;
    end else begin
        less_out = x < y ? 32'h00000001 : 32'h00000000;
    end
end

endmodule

module adder (
    input Add,
    input [31:0] x,
    input [31:0] y,
    output reg [31:0] sum
);

always @(*) begin
    if (Add)
        sum = x + y;
    else
        sum = x + ~y + 1;
end

endmodule

module barrel_shifter_param (
    input  Logic,
    input  Right,
    input  [31:0] data_i,   
    input  [4:0]  shift_amt, 
    output [31:0] data_o     
);

wire sign = Logic ? 1'b0 : data_i[31];

wire [31:0] stage0, stage1, stage2, stage3, stage4;
wire [31:0] Lstage0, Lstage1, Lstage2, Lstage3, Lstage4;
// 右
assign stage0 = shift_amt[0] ? {sign, data_i[31:1]} : data_i;

assign stage1 = shift_amt[1] ? {{2{sign}}, stage0[31:2]} : stage0;

assign stage2 = shift_amt[2] ? {{4{sign}}, stage1[31:4]} : stage1;

assign stage3 = shift_amt[3] ? {{8{sign}}, stage2[31:8]} : stage2;

assign stage4 = shift_amt[4] ? {{16{sign}}, stage3[31:16]} : stage3;
// 左
assign Lstage0 = shift_amt[0] ? {data_i[30:0], 1'b0} : data_i;

assign Lstage1 = shift_amt[1] ? {Lstage0[29:0], 2'b0} : Lstage0;

assign Lstage2 = shift_amt[2] ? {Lstage1[27:0], 4'b0}: Lstage1;

assign Lstage3 = shift_amt[3] ? {Lstage2[23:0], 8'b0}: Lstage2;

assign Lstage4 = shift_amt[4] ? {Lstage3[15:0], 16'b0} : Lstage3;

assign data_o = Right ? stage4 : Lstage4; 
endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/EXU/ysyx_25020042_alu.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/LSU/ysyx_25020042_LSU.v ----------
`timescale 1ns/1ns 
// `define LSU_MTRACE
module ysyx_25020042_LSU(
    input                           clock,
    input                           reset,
    input                           exu_valid,
    input                           wbu_ready,
    output reg                      lsu_valid,
    output reg                      lsu_ready,

    input [7:0]                     i_inst,
    input [31:0]                    i_src2,
    input [31:0]                    i_data, // exu data
    input [31:0]                    i_pc_data,
    input [31:0]                    i_csr_data,
    input [11:0]                    i_csr_addr,
    `ifdef VERILATOR
    input  [31:0]                   i_instruction_data,
    `endif

    output wire [7:5]                o_inst,
    output reg [31:0]               o_data,
    output reg [31:0]               o_pc_data,
    `ifdef VERILATOR
    output reg [31:0]               o_instruction_data,
    `endif
    output reg [31:0]               o_csr_data,
    output reg [11:0]               o_csr_addr,
    output                          load_valid,
    input  wire [2:0]    i_IFU_Exception_Handling,
    output reg [2:0]     o_IFU_Exception_Handling,
    input  wire [2:0]    i_IDU_Exception_Handling,
    output reg [2:0]     o_IDU_Exception_Handling,
    output wire [5:0]    o_LSU_Exception_Handling,

    `ifdef VERILATOR
    /* verilator lint_off UNUSEDSIGNAL */
    output reg [63:0]               performance_counter,
    output reg [63:0]               cycles_counter,
    input  wire [63:0]              i_single_cycles_counter,
    output reg [63:0]               o_single_cycles_counter,
    /* verilator lint_on UNUSEDSIGNAL */
    `endif

    // axi 握手信号
    output reg [31:0]               lsu_araddr,
    output reg                      lsu_arvalid,
    output reg [3:0]                lsu_arid,
    output reg [7:0]                lsu_arlen,
    output reg [2:0]                lsu_arsize,
    output reg [1:0]                lsu_arburst,
    input                           lsu_arready,

    input [31:0]                    lsu_rdata,
    input                           lsu_rvalid,
    input [1:0]                     lsu_rresp,
    input [3:0]                     lsu_rid,
    input                           lsu_rlast,
    output reg                      lsu_rready,

    output reg [31:0]               lsu_awaddr,
    output reg                      lsu_awvalid,
    output reg [3:0]                lsu_awid,
    output reg [7:0]                lsu_awlen,
    output reg [2:0]                lsu_awsize,
    output reg [1:0]                lsu_awburst,
    input                           lsu_awready,

    output reg [31:0]               lsu_wdata,
    output reg [3:0]                lsu_wstrb,
    output reg                      lsu_wvalid,
    output reg                      lsu_wlast,
    input                           lsu_wready,

    input                           lsu_bvalid,
    output reg                      lsu_bready,
    input [1:0]                     lsu_bresp,
    input [3:0]                     lsu_bid
);

`ifdef PLATFORM_NPC
`else
`ifdef VERILATOR
import "DPI-C" function void difftest_device_skip();
`endif
`endif

`ifdef VERILATOR

    // reg [63:0] performance_counter;
    reg lsu_mem_hit_signal;
    reg lsu_busy_signal;
    always @(posedge clock) begin
        if(reset) begin
            lsu_busy_signal <= 1'b0;
        end
        else if (exu_valid & lsu_ready) begin
            lsu_busy_signal <= 1;
        end
        else if (lsu_valid & wbu_ready) begin
            lsu_busy_signal <= 0;
        end
    end

    always @(posedge clock) begin
        if(reset) begin
            lsu_mem_hit_signal <= 1'b0;
        end
        else if (lsu_arvalid | lsu_awvalid) begin
            lsu_mem_hit_signal <= 1;
        end
        else if (lsu_rvalid | lsu_bvalid) begin
            lsu_mem_hit_signal <= 0;
        end
    end

    always @(posedge clock) begin
        if(reset) 
            performance_counter <= 0;
        else if ((lsu_bvalid | lsu_rvalid) & lsu_mem_hit_signal)
            performance_counter <= performance_counter + 1;
    end

    always @(posedge clock) begin
        if(reset) 
            cycles_counter <= 0;
        else if (lsu_busy_signal)
            cycles_counter <= cycles_counter + 1;
    end

        always @(posedge clock) begin
        if (reset) begin
            o_single_cycles_counter <= 0;
        end
        else if (exu_valid & lsu_ready) begin
            o_single_cycles_counter <= i_single_cycles_counter;
        end
        else begin
            o_single_cycles_counter <= o_single_cycles_counter + 1;
        end
    end
`endif

localparam  MEM_INST     = 3'b011;
// 状态定义
localparam IDLE = 1'b0;
localparam WAIT = 1'b1;

reg [7:0]                inst_reg;
reg       state;
reg [1:0] rresp;
reg [1:0] bresp;
wire [3:0] wstrb;
wire [31:0] wdata;
reg Load_address_misaligned;
reg Store_address_misaligned;
wire Load_access_fault;
wire Store_access_fault;
wire Load_page_fault;
wire Store_page_fault;

// 记得修改回来

wire [31:0] shifted_rdata = lsu_rdata >> (lsu_araddr[1:0] * 8);
reg wen;
reg ren;
reg [3:0] wmask;

assign o_LSU_Exception_Handling = {Store_page_fault, Load_page_fault, Store_access_fault, Store_address_misaligned, Load_access_fault, Load_address_misaligned};
assign Store_page_fault = 1'b0;
assign Load_page_fault = 1'b0;
assign Store_access_fault = bresp == 2'b10 | bresp == 2'b11;
assign Load_access_fault = |rresp;
assign o_inst = inst_reg[7:5];

always @(*) begin
    case (lsu_arsize)
        3'b010: Load_address_misaligned = |lsu_araddr[1:0];
        3'b001: Load_address_misaligned = lsu_araddr[0];
        3'b000: Load_address_misaligned = 1'b0;
        default: Load_address_misaligned = 1'b0;
    endcase

    case (lsu_awsize)
        3'b010: Store_address_misaligned = |lsu_awaddr[1:0];
        3'b001: Store_address_misaligned = lsu_awaddr[0];
        3'b000: Store_address_misaligned = 1'b0;
        default: Store_address_misaligned = 1'b0;
    endcase
end

always @(posedge clock) begin
    if(reset) begin
        inst_reg <= 8'b0;
        o_pc_data <= 32'b0;
        o_csr_data <= 32'b0;
        o_csr_addr <= 12'b0;
        o_IFU_Exception_Handling <= 3'b0;
        o_IDU_Exception_Handling <= 3'b0;
        `ifdef VERILATOR
            o_instruction_data <= 32'b0;
        `endif
    end
    else if(exu_valid & lsu_ready) begin
        inst_reg <= i_inst;
        o_pc_data <= i_pc_data;
        o_csr_data <= i_csr_data;
        o_csr_addr <= i_csr_addr;
        o_IFU_Exception_Handling <= i_IFU_Exception_Handling;
        o_IDU_Exception_Handling <= i_IDU_Exception_Handling;
        `ifdef VERILATOR
            o_instruction_data <= i_instruction_data;
        `endif
    end
end

assign wdata = i_src2 << (i_data[1:0] * 8);
assign wstrb = wmask << i_data[1:0];

always @(*) begin
    wen = 1'b0;
    ren = 1'b0;
    wmask = 4'b0000;
    if(i_inst[7:5] == MEM_INST) begin
        case (i_inst[4:0])
            5'b00110: begin // sw
                wen = 1'b1;
                wmask = 4'b1111;
            end
            5'b00111: begin // sh
                wen = 1'b1;
                wmask = 4'b0011;
            end
            5'b01000: begin // sb
                wen = 1'b1;
                wmask = 4'b0001;
            end
            default: begin
                ren = 1'b1;
            end
    endcase
    end
end

assign load_valid = lsu_rvalid & lsu_rlast & lsu_rid == lsu_arid & state == WAIT;

always @(*) begin
    case (inst_reg[4:0])
        5'b00001: o_data = shifted_rdata[31:0];
        5'b00011: o_data = {16'b0, shifted_rdata[15:0]};
        5'b00010: o_data = {{16{shifted_rdata[15]}}, shifted_rdata[15:0]};
        5'b00101: o_data = {24'b0, shifted_rdata[7:0]};
        5'b00100: o_data = {{24{shifted_rdata[7]}}, shifted_rdata[7:0]};
        default:  o_data = 0;
    endcase
end

always @(posedge clock) begin
    if(reset) begin
        state <= IDLE;
        lsu_ready <= 1'b1;
        lsu_valid <= 1'b0;
        lsu_arvalid <= 1'b0;
        lsu_awvalid <= 1'b0;
        lsu_araddr <= 32'b0;
        lsu_awaddr <= 32'b0;
        lsu_rready <= 1'b0;
        lsu_wdata <= 32'b0;
        lsu_wstrb <= 4'b0;
        lsu_wvalid <= 1'b0;
        lsu_bready <= 1'b0;
        lsu_arid <= 4'b0;
        lsu_awid <= 4'b0;
        lsu_arlen <= 8'b0;
        lsu_awlen <= 8'b0;
        lsu_arsize <= 3'b0;
        lsu_awsize <= 3'b0;
        lsu_arburst <= 2'b00;
        lsu_awburst <= 2'b00;
        lsu_wlast <= 1'b0;
        rresp <= 2'b0;
        bresp <= 2'b0;
    end
    else begin
        case (state)
            IDLE: begin
                if(exu_valid & lsu_ready) begin
                    if (wen || ren) begin
                        state <= WAIT;
                        lsu_ready <= 1'b0;
                        lsu_wdata <= wdata;
                        lsu_wstrb <= wstrb;
                        lsu_araddr <= i_data;
                        lsu_awaddr <= i_data;  

                        case (i_inst[4:0])
                            5'b00110: begin // sw
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b010;
                            end
                            5'b00111: begin // sh
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b001;
                            end
                            5'b00001: begin // lw
                                lsu_arsize <= 3'b010;
                                lsu_awsize <= 3'b000;
                            end
                            5'b00010: begin // lh
                                lsu_arsize <= 3'b001;
                                lsu_awsize <= 3'b000;
                            end
                            5'b00011: begin // lhu
                                lsu_arsize <= 3'b001;
                                lsu_awsize <= 3'b000;
                            end
                            default: begin
                                lsu_arsize <= 3'b000;
                                lsu_awsize <= 3'b000;
                            end
                        endcase
                        if (wen) begin
                            lsu_awvalid <= 1'b1;
                            lsu_wvalid <= 1'b1;
                            lsu_wlast <= 1'b1; 
                            `ifdef LSU_MTRACE
                                $display("LSU: write addr: %x data: %x", i_data, wdata);
                            `endif
                        end
                        else begin
                            lsu_rready <= 1'b1;
                            lsu_arvalid <= 1'b1;
                        end
                    end
                    else begin
                        // o_data <= i_data;
                        lsu_ready <= 1'b0;
                        lsu_valid <= 1'b1;
                    end
                end
                else begin
                    state <= IDLE;

                    // if (lsu_rready) begin
                        lsu_rready <= 1'b0;
                    // end

                    // if (lsu_bready) begin
                        lsu_bready <= 1'b0;
                    // end

                    if(lsu_valid & wbu_ready ) begin
                        lsu_ready <= 1'b1;
                        lsu_valid <= 1'b0;
                        rresp <= 2'b00;
                        bresp <= 2'b00;
                        lsu_araddr <= 32'b0;
                        lsu_awaddr <= 32'b0;
                    end
                end
            end
            WAIT: begin
                `ifdef VERILATOR 
                `ifdef PLATFORM_NPC
                `else
                    if (lsu_araddr >= 32'h1000_0000 && lsu_araddr < 32'h1000_1000 && lsu_arvalid && lsu_arready || 
                        lsu_araddr >= 32'h1000_1000 && lsu_araddr < 32'h1000_2000 && lsu_arvalid && lsu_arready) begin
                        difftest_device_skip();
                    end
                    if (lsu_araddr >= 32'h0200_0000 && lsu_araddr < 32'h0201_0000 && lsu_arvalid && lsu_arready) begin
                        difftest_device_skip();
                    end
                `endif
                `endif
                // if(lsu_arready) begin
                    lsu_arvalid <= lsu_arready ? 1'b0 : lsu_arvalid;
                // end
                
                if(lsu_awready & lsu_wready) begin
                    lsu_awvalid <= 1'b0;
                    lsu_wvalid <= 1'b0;
                    lsu_wlast <= 1'b0;
                end

                else if (lsu_rvalid & lsu_rlast & lsu_rid == lsu_arid) begin
                    lsu_rready <= 1'b0;
                    lsu_valid <= 1'b1;
                    rresp <= lsu_rresp;
                    state <= IDLE;
                    `ifdef LSU_MTRACE
                        $display("LSU: read addr: %x data: %x", lsu_araddr, shifted_rdata);
                    `endif
                end
                else if (lsu_bvalid & lsu_bid == lsu_awid) begin
                    lsu_bready <= 1'b1;
                    lsu_valid <= 1'b1;
                    bresp <= lsu_bresp;
                    state <= IDLE;
                end
                else begin 
                    state <= WAIT;
                end
            end
            default: begin
                state <= IDLE;
            end
        endcase

    end
    
end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/LSU/ysyx_25020042_LSU.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/WBU/ysyx_25020042_WBU.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_WBU(
    `ifdef VERILATOR
    input             clock,
    input             reset,
    `endif
    input             lsu_valid,
    output wire       wbu_ready,
    output wire       wbu_valid,
    
    input [31:0]      i_data,
    input [31:0]      i_pc_data,
    input  [7:5]      i_inst,
    /* verilator lint_off UNUSEDSIGNAL */
    input [31:0]      i_mstatus,
    /* verilator lint_on UNUSEDSIGNAL */
    input  [2:0]      i_IFU_Exception_Handling,
    input  [2:0]      i_IDU_Exception_Handling,
    input  [5:0]      i_LSU_Exception_Handling,
    output            o_Exception_valid,
    `ifdef VERILATOR
    input  [31:0]     i_instruction_data,
    output reg [63:0] performance_counter,
    output reg [63:0] cycles_counter,
    input  [63:0]     i_single_cycles_counter,
    output wire [63:0] o_single_cycles_counter,
    `endif
    input  [11:0]     i_csr_addr,
    input  [31:0]     i_csr_rdata,
    output wire [31:0] csr_wdata,
    output wire [11:0] csr_addr,
    output reg [31:0] reg_wdata,
    output wire [31:0] o_mepc_wdata,
    output reg [31:0] o_mcause_wdata
);


    // localparam IDLE = 1'b0;
    // localparam WAIT = 1'b1;
    // reg  state;
    wire [11:0] Exception_Handling = {i_LSU_Exception_Handling, i_IDU_Exception_Handling, i_IFU_Exception_Handling};
    wire [1:0] MPP = i_mstatus[13:12];
    assign o_Exception_valid = |Exception_Handling;

    localparam Instruction_address_misaligned = 32'd0;
    localparam Instruction_access_fault       = 32'd1;
    localparam Illegal_instruction            = 32'd2;
    localparam Breakpoint                     = 32'd3;
    localparam Load_address_misaligned        = 32'd4;
    localparam Load_access_fault              = 32'd5;
    localparam Store_address_misaligned       = 32'd6;
    localparam Store_access_fault             = 32'd7;
    localparam Environment_call_from_U_mode   = 32'd8;
    localparam Environment_call_from_S_mode   = 32'd9;
    localparam Environment_call_from_M_mode   = 32'd11;
    localparam Instruction_page_fault         = 32'd12;
    localparam Load_page_fault                = 32'd13;
    localparam Store_page_fault               = 32'd15;

`ifdef VERILATOR

    import "DPI-C" function void dpi_ebreak();

    always @(posedge clock) begin
            if (Exception_Handling[4] & wbu_valid) begin
                dpi_ebreak();
            end
    end

    // always @(posedge clock) begin
    //     if (o_Exception_valid) begin
    //     case (1'b1)
    //         Exception_Handling[0]: $display("Instruction_address_misaligned");
    //         Exception_Handling[1]: $display("Instruction_access_fault");
    //         Exception_Handling[2]: $display("Instruction_page_fault");

    //         Exception_Handling[3]: $display("Illegal_instruction");
    //         Exception_Handling[4]: $display("Breakpoint");
    //         Exception_Handling[5]: begin 
    //             case (MPP)
    //                 2'b00: $display("Environment_call_from_U_mode");
    //                 2'b01: $display("Environment_call_from_S_mode");
    //                 2'b11: $display("Environment_call_from_M_mode");
    //                 default: $display("Environment_call_from_M_mode");
    //             endcase
    //         end

    //         Exception_Handling[6]: $display("Load_address_misaligned");
    //         Exception_Handling[7]: $display("Load_access_fault");
    //         Exception_Handling[8]: $display("Store_address_misaligned");
    //         Exception_Handling[9]: $display("Store_access_fault");
    //         Exception_Handling[10]: $display("Load_page_fault");
    //         Exception_Handling[11]: $display("Store_page_fault");
    //     endcase
    //     end
    // end

    reg [31:0] pc;
    reg [31:0] instruction_data;
    reg        instruction_done;
    always @(posedge clock) begin
        if (reset) begin
            pc <= 0;
            instruction_data <= 0;
            instruction_done <= 0;
        end
        else begin
            instruction_done <= wbu_valid;
            if (lsu_valid & wbu_ready) begin
                instruction_data <= i_instruction_data;
                pc <= i_pc_data;
            end
        end
    end

    always @(posedge clock) begin
        if (reset) begin
            performance_counter <= 0;
            cycles_counter <= 0;
        end
        else if (lsu_valid & wbu_ready) begin
            performance_counter <= performance_counter + 1;
            cycles_counter <= cycles_counter + 1;
        end
    end

    assign o_single_cycles_counter = i_single_cycles_counter;
`endif

assign o_mepc_wdata = i_pc_data;
always @(*) begin
    o_mcause_wdata = 32'b0;
    case (1'b1)
        Exception_Handling[0]: o_mcause_wdata = Instruction_address_misaligned;
        Exception_Handling[1]: o_mcause_wdata = Instruction_access_fault;
        Exception_Handling[2]: o_mcause_wdata = Instruction_page_fault;

        Exception_Handling[3]: o_mcause_wdata = Illegal_instruction;
        Exception_Handling[4]: o_mcause_wdata = Breakpoint;
        Exception_Handling[5]: begin 
            case (MPP)
                2'b00: o_mcause_wdata = Environment_call_from_U_mode;
                2'b01: o_mcause_wdata = Environment_call_from_S_mode;
                2'b11: o_mcause_wdata = Environment_call_from_M_mode;
                default: o_mcause_wdata = Environment_call_from_M_mode;
            endcase
        end

        Exception_Handling[6]: o_mcause_wdata = Load_address_misaligned;
        Exception_Handling[7]: o_mcause_wdata = Load_access_fault;
        Exception_Handling[8]: o_mcause_wdata = Store_address_misaligned;
        Exception_Handling[9]: o_mcause_wdata = Store_access_fault;
        Exception_Handling[10]: o_mcause_wdata = Load_page_fault;
        Exception_Handling[11]: o_mcause_wdata = Store_page_fault;
    endcase
end

assign wbu_ready = 1'b1;
assign wbu_valid = wbu_ready & lsu_valid;
assign csr_wdata = i_data;
assign csr_addr = i_csr_addr;

always @(*) begin
    case (i_inst[7:5])
        3'b010: begin
            reg_wdata = i_pc_data + 4;
        end
        3'b100: begin
            reg_wdata = i_csr_rdata;
        end
        default: begin
            reg_wdata = i_data;
        end
    endcase
end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/WBU/ysyx_25020042_WBU.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_axi_arbiter.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_axi_arbiter (
    input              clock,
    input              reset,
    // lsu
    input [31:0]       io_lsu_araddr,
    input              io_lsu_arvalid,
    input      [3:0]   io_lsu_arid,
    input      [7:0]   io_lsu_arlen,
    input      [2:0]   io_lsu_arsize,
    input      [1:0]   io_lsu_arburst,    
    output reg         io_lsu_arready ,

    output reg [31:0]  io_lsu_rdata ,
    output reg         io_lsu_rvalid ,
    output reg [1:0]   io_lsu_rresp ,
    output reg [3:0]   io_lsu_rid,
    output reg         io_lsu_rlast,
    input              io_lsu_rready ,

    input [31:0]       io_lsu_awaddr ,
    input              io_lsu_awvalid ,
    input      [3:0]   io_lsu_awid,
    input      [7:0]   io_lsu_awlen,
    input      [2:0]   io_lsu_awsize,
    input      [1:0]   io_lsu_awburst,    
    output reg         io_lsu_awready ,

    input [31:0]       io_lsu_wdata ,
    input [3:0]        io_lsu_wstrb ,
    input              io_lsu_wvalid ,
    input              io_lsu_wlast,
    output reg         io_lsu_wready ,

    output reg         io_lsu_bvalid ,
    input              io_lsu_bready ,
    output reg [1:0]   io_lsu_bresp ,
    output reg [3:0]   io_lsu_bid,

    //IFU
    input [31:0]       io_ifu_araddr,
    input              io_ifu_arvalid,
    output reg         io_ifu_arready,
    input [7:0]        io_ifu_arlen,
    input [3:0]        io_ifu_arid,
    input [1:0]        io_ifu_arburst,
    input [2:0]        io_ifu_arsize,

    output reg [31:0]  io_ifu_rdata,
    output reg         io_ifu_rvalid,
    output reg [1:0]   io_ifu_rresp,
    input              io_ifu_rready,
    output reg         io_ifu_rlast,
    output reg [3:0]   io_ifu_rid,

    // out
    input              io_awready,
    output reg         io_awvalid,
    output reg [31:0]  io_awaddr ,
    output reg [3:0]   io_awid   ,
    output reg [7:0]   io_awlen  ,
    output reg [2:0]   io_awsize ,
    output reg [1:0]   io_awburst,
    input              io_wready ,
    output reg         io_wvalid ,
    output reg [31:0]  io_wdata  ,
    output reg [3:0]   io_wstrb  ,
    output reg         io_wlast  ,
    output reg         io_bready ,
    input              io_bvalid ,
    input   [1:0]      io_bresp  ,
    input   [3:0]      io_bid    ,
    input              io_arready,
    output reg         io_arvalid,
    output reg [31:0]  io_araddr ,
    output reg [3:0]   io_arid   ,
    output reg [7:0]   io_arlen  ,
    output reg [2:0]   io_arsize ,
    output reg [1:0]   io_arburst,
    output reg         io_rready ,
    input              io_rvalid ,
    input   [1:0]      io_rresp  ,
    input   [31:0]     io_rdata  ,
    input              io_rlast  ,
    input   [3:0]      io_rid    ,
    // clint
    input              io_clint_awready,
    output reg         io_clint_awvalid,
    output reg [31:0]  io_clint_awaddr ,
    output reg [3:0]   io_clint_awid   ,
    output reg [7:0]   io_clint_awlen  ,
    output reg [2:0]   io_clint_awsize ,
    output reg [1:0]   io_clint_awburst,
    input              io_clint_wready ,
    output reg         io_clint_wvalid ,
    output reg [31:0]  io_clint_wdata  ,
    output reg [3:0]   io_clint_wstrb  ,
    output reg         io_clint_wlast  ,
    output reg         io_clint_bready ,
    input              io_clint_bvalid ,
    input   [1:0]      io_clint_bresp  ,
    input   [3:0]      io_clint_bid    ,
    input              io_clint_arready,
    output reg         io_clint_arvalid,
    output reg [31:0]  io_clint_araddr ,
    output reg [3:0]   io_clint_arid   ,
    output reg [7:0]   io_clint_arlen  ,
    output reg [2:0]   io_clint_arsize ,
    output reg [1:0]   io_clint_arburst,
    output reg         io_clint_rready ,
    input              io_clint_rvalid ,
    input   [1:0]      io_clint_rresp  ,
    input   [31:0]     io_clint_rdata  ,
    input              io_clint_rlast  ,
    input   [3:0]      io_clint_rid   
);

    // arbiter
    reg [1:0] state;
    wire clint_active = (io_lsu_araddr >= 32'h0200_0000 && io_lsu_araddr < 32'h0201_0000);

    parameter ARB_IDLE = 2'd0, ARB_LSU = 2'd1, ARB_IFU = 2'd2;

    // reg io_lsu_arvalid_reg;

    // always @(posedge clock) begin
    //     io_lsu_arvalid_reg <= io_lsu_arvalid;
    // end

    always @ (posedge clock) begin
        if (reset) begin
            state <= ARB_IDLE;
        end
        else begin
            case (state)
                ARB_IDLE: begin
                    if (io_lsu_arvalid | io_lsu_awvalid) begin
                        state <= ARB_LSU;
                    end
                    else if (io_ifu_arvalid) begin
                        state <= ARB_IFU;
                    end
                    else begin
                        state <= ARB_IDLE;
                    end
                end
                ARB_LSU: begin
                    if (io_lsu_rready & io_lsu_rvalid & (io_rlast | io_clint_rlast)) begin
                        state <= ARB_IDLE;
                    end
                    else if (io_lsu_bvalid & io_lsu_bready) begin
                        state <= ARB_IDLE;
                    end
                    else begin
                        state <= ARB_LSU;
                    end
                end
                ARB_IFU: begin
                    if (io_ifu_rready & io_ifu_rvalid & io_rlast) begin
                        state <= ARB_IDLE;
                    end
                    else begin
                        state <= ARB_IFU;
                    end
                end
                default: begin
                    state <= ARB_IDLE;
                end
            endcase      
        end
    end

    always @(*) begin
        io_araddr = 0;
        io_arvalid = 0;
        io_arid = 0;
        io_arlen = 0;
        io_arsize = 0;
        io_arburst = 0;
        io_rready = 0;
        io_awaddr = 0;
        io_awvalid = 0;
        io_awid = 0;
        io_awlen = 0;
        io_awsize = 0;
        io_awburst = 0;
        io_wdata = 0;
        io_wstrb = 0;
        io_wvalid = 0;
        io_wlast = 0;
        io_bready = 0;

        io_clint_araddr = 0;
        io_clint_arvalid = 0;
        io_clint_arid = 0;
        io_clint_arlen = 0;
        io_clint_arsize = 0;
        io_clint_arburst = 0;
        io_clint_rready = 0;
        io_clint_awaddr = 0;
        io_clint_awvalid = 0;
        io_clint_awid = 0;
        io_clint_awlen = 0;
        io_clint_awsize = 0;
        io_clint_awburst = 0;
        io_clint_wdata = 0;
        io_clint_wstrb = 0;
        io_clint_wvalid = 0;
        io_clint_wlast = 0;
        io_clint_bready = 0;

        io_lsu_arready = 0;
        io_lsu_rdata = 0;
        io_lsu_rvalid = 0;
        io_lsu_rresp = 0;
        io_lsu_awready = 0;
        io_lsu_wready = 0;
        io_lsu_bvalid = 0;
        io_lsu_bresp = 0;
        io_lsu_rid = 0;
        io_lsu_rlast = 0;
        io_lsu_bid = 0;

        io_ifu_arready = 0;
        io_ifu_rdata = 0;
        io_ifu_rvalid = 0;
        io_ifu_rresp = 0;
        io_ifu_rlast = 0;
        io_ifu_rid = 0;
        
        if (state == ARB_IFU) begin
            io_araddr = io_ifu_araddr;
            io_arvalid = io_ifu_arvalid;
            io_rready = io_ifu_rready;
            io_arid = io_ifu_arid;
            io_arlen = io_ifu_arlen;
            io_arsize = io_ifu_arsize;
            io_arburst = io_ifu_arburst;

            io_ifu_arready = io_arready;
            io_ifu_rdata = io_rdata;
            io_ifu_rvalid = io_rvalid;
            io_ifu_rresp = io_rresp;
            io_ifu_rlast = io_rlast;
            io_ifu_rid = io_rid;
            
        end
        else if (state == ARB_LSU) begin
            if (clint_active) begin
                io_clint_araddr =  io_lsu_araddr;
                io_clint_arvalid = io_lsu_arvalid;
                io_clint_arid =    io_lsu_arid;
                io_clint_arlen =   io_lsu_arlen;
                io_clint_arsize =  io_lsu_arsize;
                io_clint_arburst = io_lsu_arburst;
                io_clint_rready =  io_lsu_rready;
                io_clint_awaddr =  io_lsu_awaddr;
                io_clint_awvalid = io_lsu_awvalid;
                io_clint_awlen =   io_lsu_awlen;
                io_clint_awsize =  io_lsu_awsize;
                io_clint_awburst = io_lsu_awburst;
                io_clint_awid =    io_lsu_awid;
                io_clint_wdata =   io_lsu_wdata;
                io_clint_wstrb =   io_lsu_wstrb;
                io_clint_wvalid =  io_lsu_wvalid;
                io_clint_wlast =   io_lsu_wlast;
                io_clint_bready =  io_lsu_bready;

                io_lsu_arready =io_clint_arready ;
                io_lsu_rdata   =io_clint_rdata   ;
                io_lsu_rvalid  =io_clint_rvalid  ;
                io_lsu_rresp   =io_clint_rresp   ;
                io_lsu_awready =io_clint_awready ;
                io_lsu_wready  =io_clint_wready  ;
                io_lsu_bvalid  =io_clint_bvalid  ;
                io_lsu_bresp   =io_clint_bresp   ;
                io_lsu_rid     =io_clint_rid     ;
                io_lsu_rlast   =io_clint_rlast   ;
                io_lsu_bid     =io_clint_bid     ;
            end
            else begin
                io_araddr =  io_lsu_araddr;
                io_arvalid = io_lsu_arvalid;
                io_arid =    io_lsu_arid;
                io_arlen =   io_lsu_arlen;
                io_arsize =  io_lsu_arsize;
                io_arburst = io_lsu_arburst;
                io_rready =  io_lsu_rready;
                io_awaddr =  io_lsu_awaddr;
                io_awvalid = io_lsu_awvalid;
                io_awlen =   io_lsu_awlen;
                io_awsize =  io_lsu_awsize;
                io_awburst = io_lsu_awburst;
                io_awid =    io_lsu_awid;
                io_wdata =   io_lsu_wdata;
                io_wstrb =   io_lsu_wstrb;
                io_wvalid =  io_lsu_wvalid;
                io_wlast =   io_lsu_wlast;
                io_bready =  io_lsu_bready;

                io_lsu_arready = io_arready;
                io_lsu_rdata   = io_rdata;
                io_lsu_rvalid  = io_rvalid;
                io_lsu_rresp   = io_rresp;
                io_lsu_awready = io_awready;
                io_lsu_wready  = io_wready;
                io_lsu_bvalid  = io_bvalid;
                io_lsu_bresp   = io_bresp;
                io_lsu_rid     = io_rid;
                io_lsu_rlast   = io_rlast;
                io_lsu_bid     = io_bid;
            end
            
        end
    end
endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_axi_arbiter.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_csr.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_csr (
    input clock,
    input reset,
    input i_Exception_valid,
    input [31:0] i_csr_wdata,
    input [11:0] i_csr_addr,
    input [11:0] i_wbu_csr_addr,
    input [31:0] i_mstatus_wdata,
    input [31:0] i_mtvec_wdata,
    input [31:0] i_mepc_wdata,
    input [31:0] i_mcause_wdata,
    input wbu_valid,
    output [31:0] o_mstatus,
    output [31:0] o_mtvec,
    output [31:0] o_mepc,
    output reg [31:0] o_csr_rdata
);

reg [5:0] wen;
wire [31:0] mstatus_wdata;
wire [31:0] mtvec_wdata;
wire [31:0] mepc_wdata;
wire [31:0] mcause_wdata;
wire [31:0] mcycle_val;
wire [31:0] mcycleh_val;
wire [31:0] mvendorid_val;
wire [31:0] marchid_val;
wire [31:0] mcycle_wdata;
wire [31:0] mcycleh_wdata;

assign mstatus_wdata = (i_Exception_valid == 1'b1) ? i_mstatus_wdata : i_csr_wdata;
assign mtvec_wdata   = (i_Exception_valid == 1'b1) ? i_mtvec_wdata   : i_csr_wdata;
assign mepc_wdata    = (i_Exception_valid == 1'b1) ? i_mepc_wdata    : i_csr_wdata;
assign mcause_wdata  = (i_Exception_valid == 1'b1) ? i_mcause_wdata  : i_csr_wdata;
assign mcycle_wdata  = (wen[4] == 1'b1) ? i_csr_wdata    : mcycle_val + 1;
assign mcycleh_wdata = (wen[5] == 1'b1) ? i_csr_wdata    : mcycle_val == 32'hffffffff ? mcycleh_val + 1 : mcycleh_val;


always @(*) begin
    wen = 6'b0;
    o_csr_rdata = 32'b0;
    if (wbu_valid) begin
        if(i_Exception_valid == 1'b1 ) begin
            wen = 6'b001100;
        end else if(i_wbu_csr_addr == 12'h300) begin
            wen[0] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h305) begin
            wen[1] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h341) begin
            wen[2] = 1'b1;
        end else if(i_wbu_csr_addr == 12'h342) begin
            wen[3] = 1'b1;
        end else if(i_wbu_csr_addr == 12'hB00) begin
            wen[4] = 1'b1;
        end else if(i_wbu_csr_addr == 12'hB80) begin
            wen[5] = 1'b1;
        end else begin
            wen = 6'b0;
        end
    end else begin  wen = 6'b0; end

    if(i_csr_addr == 12'h300) begin
        o_csr_rdata = o_mstatus;
    end else if(i_csr_addr == 12'h305) begin
        o_csr_rdata = o_mtvec;
    end else if(i_csr_addr == 12'h341) begin
        o_csr_rdata = o_mepc;
    end else if(i_csr_addr == 12'h342) begin
        o_csr_rdata = mcause;
    end else if(i_csr_addr == 12'hB00) begin
        o_csr_rdata = mcycle_val;
    end else if(i_csr_addr == 12'hB80) begin
        o_csr_rdata = mcycleh_val;
    end else if(i_csr_addr == 12'hF11) begin
        o_csr_rdata = mvendorid_val;
    end else if(i_csr_addr == 12'hF12) begin
        o_csr_rdata = marchid_val;
    end else begin
        o_csr_rdata = 32'b0;
    end
    
end

reg [31:0] mstatus;  
reg [31:0] mtvec;    
reg [31:0] mepc;     
reg [31:0] mcause;   
reg [31:0] mcycle;   
reg [31:0] mcycleh;  
reg [31:0] mvendorid;
reg [31:0] marchid;  
assign o_mstatus = mstatus;
assign o_mtvec   = mtvec;
assign o_mepc    = mepc;
assign mcycle_val = mcycle;
assign mcycleh_val = mcycleh;
assign mvendorid_val = mvendorid;
assign marchid_val = marchid;
always @(posedge clock) begin
    if(reset) begin
        mstatus   <= 32'h1800;
        mtvec     <= 32'h0;
        // mepc      <= 32'h0;
        mcause    <= 32'h0;
        mcycle    <= 32'h0;
        mcycleh   <= 32'h0;
        mvendorid <= 32'h79737978;
        marchid   <= 32'h017DC68A;
    end
    else begin
        if(wen[0]) begin
            mstatus   <= mstatus_wdata;
        end
        if(wen[1]) begin
            mtvec     <= mtvec_wdata;
        end
        if(wen[2]) begin
            mepc      <= mepc_wdata;
        end
        if(wen[3]) begin
            mcause    <= mcause_wdata;
        end
        mcycle    <= mcycle_wdata;
        mcycleh   <= mcycleh_wdata;
    end
end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_csr.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_data_branch.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_data_branch(
    input                clock,
    input                reset,
    input [4:0]          i_rs1,
    input [4:0]          i_rs2,
    input [4:0]          i_rd,
    input [2:0]          i_exu_to_lsu_inst,
    input [2:0]          i_idu_to_exu_inst,
    input                idu_exu_handshake,
    input                exu_lsu_handshake,
    input                lsu_wbu_handshake,
    input                load_valid,
    input  [31:0]        i_exu_rd_data,
    input  [31:0]        i_lsu_rd_data,
    input  [31:0]        i_src1,
    input  [31:0]        i_src2,
    output reg           rs1_data_ready,
    output reg           rs2_data_ready,
    output reg [31:0]    rs1_data,
    output reg [31:0]    rs2_data,
    output  [4:0]        o_rs1,
    output  [4:0]        o_rs2,
    output  [31:0]       o_exu_rd_data,
    output  [31:0]       o_lsu_rd_data,
    output  [4:0]        o_lsu_rd
);


wire rs1_hit = i_rs1 != 0 && (i_rs1 == exu_rd_buffer || i_rs1 == lsu_rd_buffer);
wire rs2_hit = i_rs2 != 0 && (i_rs2 == exu_rd_buffer || i_rs2 == lsu_rd_buffer);
reg [31:0] exu_rd_data_buffer;
reg [31:0] lsu_rd_data_buffer;
reg [4:0]  exu_rd_buffer;
reg [4:0]  lsu_rd_buffer;
reg        exu_rd_valid;
reg        lsu_rd_valid;

assign o_exu_rd_data = exu_rd_data_buffer;
assign o_lsu_rd_data = lsu_rd_data_buffer;
assign o_lsu_rd = lsu_rd_buffer;

assign o_rs1 = i_rs1;
assign o_rs2 = i_rs2;

always @(*) begin
    rs1_data_ready = 1;
    rs1_data = i_src1;
    if (rs1_hit) begin
        if (i_rs1 == exu_rd_buffer && exu_rd_valid) begin
            rs1_data = exu_rd_data_buffer;
        end
        else if (i_rs1 == lsu_rd_buffer && lsu_rd_valid) begin
            rs1_data = lsu_rd_data_buffer;
        end
        else begin
            rs1_data = 0;
            rs1_data_ready = 0;
        end
    end
end

always @(*) begin
    rs2_data_ready = 1;
    rs2_data = i_src2;
    if (rs2_hit) begin
        if (i_rs2 == exu_rd_buffer && exu_rd_valid) begin
            rs2_data = exu_rd_data_buffer;
        end
        else if (i_rs2 == lsu_rd_buffer && lsu_rd_valid) begin
            rs2_data = lsu_rd_data_buffer;
        end
        else begin
            rs2_data = 0;
            rs2_data_ready = 0;
        end
    end
end

always @(posedge clock) begin
    if (reset) begin
        exu_rd_data_buffer <= 0;
        exu_rd_buffer <= 0;
        exu_rd_valid <= 0;
    end
    else begin

        if (idu_exu_handshake) begin
            exu_rd_buffer <= i_rd;
            exu_rd_data_buffer <= i_exu_rd_data;
            if (i_idu_to_exu_inst == 3'b011 || i_idu_to_exu_inst == 3'b010)
                exu_rd_valid <= 0;
            else 
                exu_rd_valid <= 1;
        end
        else if (exu_lsu_handshake) begin
            exu_rd_buffer <= 0;
        end
    end
end

always @(posedge clock) begin
    if (reset) begin
        lsu_rd_data_buffer <= 0;
        lsu_rd_buffer <= 0;
        lsu_rd_valid <= 0;
    end
    else begin
        case (1'b1)
            exu_lsu_handshake: begin
                lsu_rd_buffer <= exu_rd_buffer;
                lsu_rd_data_buffer <= exu_rd_data_buffer;
            if (i_exu_to_lsu_inst != 3'b011 && i_exu_to_lsu_inst != 3'b010) begin
                lsu_rd_valid <= 1;
            end
            else 
                lsu_rd_valid <= 0;
            end
            load_valid: begin
                lsu_rd_data_buffer <= i_lsu_rd_data;
                lsu_rd_valid <= 1;

            end
            lsu_wbu_handshake: begin
                lsu_rd_buffer <= 0;
            end
        endcase
    
    //     if (exu_lsu_handshake) begin
    //         lsu_rd_buffer <= exu_rd_buffer;
    //             lsu_rd_data_buffer <= exu_rd_data_buffer;
    //         if (i_exu_to_lsu_inst != 3'b011 && i_exu_to_lsu_inst != 3'b010) begin
    //             lsu_rd_valid <= 1;
    //         end
    //         else 
    //             lsu_rd_valid <= 0;
    //     end

    //     if (load_valid) begin
    //         lsu_rd_data_buffer <= i_lsu_rd_data;
    //         lsu_rd_valid <= 1;
    //     end

    //     if (lsu_wbu_handshake) begin
    //         lsu_rd_buffer <= 0;
    //     end
    end
end

endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/ysyx_25020042_data_branch.v ----------

// ---------- 开始：/home/long/ysyx-workbench/npc/vsrc/device/ysyx_25020042_clint.v ----------
`timescale 1ns/1ns 
module ysyx_25020042_clint(
    input clock,
    input reset,
    // axi 握手信号
    input [31:0]      slave_araddr    ,
    input             slave_arvalid   ,
    output reg        slave_arready   ,
    input [3:0]       slave_arid      ,
    input [7:0]       slave_arlen     ,
    input [2:0]       slave_arsize    ,
    input [1:0]       slave_arburst   ,

    output reg [31:0] slave_rdata     ,
    output reg        slave_rvalid    ,
    output reg [1:0]  slave_rresp     ,
    input             slave_rready    ,
    output reg        slave_rlast     ,
    output reg  [3:0] slave_rid       ,

    input [31:0]      slave_awaddr    ,
    input             slave_awvalid   ,
    output reg        slave_awready   ,
    input  [3:0]      slave_awid      ,
    input  [7:0]      slave_awlen     ,
    input  [2:0]      slave_awsize    ,
    input  [1:0]      slave_awburst   ,

    input [31:0]      slave_wdata     ,
    input [3:0]       slave_wstrb     ,
    input             slave_wvalid    ,
    output reg        slave_wready    ,
    input             slave_wlast     ,

    output reg        slave_bvalid    ,
    input             slave_bready    ,
    output reg [1:0]  slave_bresp     ,
    output reg [3:0]  slave_bid    
);


reg [2:0] state;
localparam IDLE = 3'd0;
localparam READ = 3'd1;
localparam READ_WAIT = 3'd2;
localparam WRITE = 3'd3;
localparam WRITE_WAIT = 3'd4;
reg [31:0] mtime;
reg [31:0] mtimeh;
wire read_valid = ~|slave_arlen && slave_arsize == 3'b010 && ~|slave_arburst;
wire write_valid =  ~|slave_awlen && slave_awsize == 3'b010 && ~|slave_awburst && slave_wlast == 1'b1 && slave_wstrb == 4'hf;

always @(posedge clock) begin
    if (reset) begin
        mtime <= 32'b0;
        mtimeh <= 32'b0;
    end
    else begin
        if (state == WRITE && write_valid) begin
            if (slave_awaddr == 32'h0200_0000) 
                mtime <= slave_wdata;
            else if (slave_awaddr == 32'h0200_0004) 
                mtimeh <= slave_wdata;
        end
        mtime <= mtime + 1;
        mtimeh <= mtime == 32'hffffffff ? mtimeh + 1 : mtimeh;
    end
end

always @(posedge clock) begin
    if (reset) begin
        state <= IDLE;
        slave_arready <= 1'b0;
        slave_awready <= 1'b0;
        slave_rid <= 0;
        slave_bid <= 0;
        slave_wready <= 1'b0;
        slave_bvalid <= 1'b0;
        slave_bresp <= 2'b0;
        slave_rdata <= 32'b0;
        slave_rvalid <= 0;
        slave_rlast <= 0;
        slave_rresp <= 2'b00;
    end
    case (state)
        IDLE: begin
            if (slave_arvalid) begin
                slave_arready <= 1'b1;
                state <= READ;
                slave_rid <= slave_arid;
            end
            else if (slave_awvalid && slave_wvalid) begin
                slave_awready <= 1'b1;
                slave_wready <= 1'b1;
                slave_bid <= slave_awid;
                state <= WRITE;
            end
        end
        READ: begin
            if (slave_arready) begin
                slave_arready <= 1'b0;
            end
            if (slave_araddr == 32'h0200_0000 && read_valid) begin
                slave_rdata <= mtime;
            end
            else if (slave_araddr == 32'h0200_0004 && read_valid) begin
                slave_rdata <= mtimeh;
            end
            else begin
                slave_rdata <= 32'b0;
            end
            slave_rvalid <= 1'b1;
            slave_rlast <= 1'b1;
            slave_rresp <= 2'b00;
            state <= READ_WAIT;
        end
        READ_WAIT: begin
            if (slave_rready) begin
                slave_rvalid <= 1'b0;
                slave_rresp <= 2'b00;
                slave_rdata <= 32'b0;
                slave_rlast <= 0;
                state <= IDLE;
            end
        end
        WRITE: begin
            if (slave_awready || slave_wready) begin
                slave_awready <= 1'b0;
                slave_wready <= 1'b0;
            end
            state <= WRITE_WAIT;
            slave_bresp <= 2'b00;
            slave_bvalid <= 1'b1;
        end
        WRITE_WAIT: begin
            if (slave_bready) begin
                slave_bvalid <= 1'b0;
                slave_bresp <= 2'b00;
                state <= IDLE;
            end
        end
        default: begin
            state <= IDLE;
        end
    endcase 
end


endmodule

// ---------- 结束：/home/long/ysyx-workbench/npc/vsrc/device/ysyx_25020042_clint.v ----------

