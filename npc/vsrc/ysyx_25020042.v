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
    wire [3:0] mcause_wdata;
    // wire [31:0] mstatus_wdata = 32'h0;
    // wire [31:0] mtvec_wdata;
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
    `ifndef  __ICARUS__
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
    `endif
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
    // .reset(reset),
    .i_Exception_valid(Exception_valid),
    .i_csr_wdata(csr_wdata),
    .i_csr_addr(csr_addr),
    .i_wbu_csr_addr(wbu_csr_addr),
    // .i_mstatus_wdata(mstatus_wdata),
    .i_mcause_wdata(mcause_wdata),
    // .i_mtvec_wdata(mtvec_wdata),
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
    // .reset(reset), 
    .i_rs1(rs1),
    .i_rs2(rs2),
    .i_rd(wbu_rd),
    .i_data(wdata),
    .wbu_valid(wbu_valid),
    .o_src1(src1),
    .o_src2(src2)
);

    endmodule
