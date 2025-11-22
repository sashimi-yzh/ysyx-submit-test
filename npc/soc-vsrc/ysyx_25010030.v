/*********************************************************************/
//                    _ooOoo_
//                   o8888888o
//                   88" . "88
//                   (| -_- |)
//                   O\  =  /O
//                ____/`---'\____
//              .'  \\|     |//  `.
//             /  \\|||  :  |||//  \
//            /  _||||| -:- |||||-  \
//            |   | \\\  -  /// |   |
//            | \_|  ''\---/''  |   |
//            \  .-\__  `-`  ___/-. /
//          ___`. .'  /--.--\  `. . __
//       ."" '<  `.___\_<|>_/___.'  >'"".
//      | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//      \  \ `-.   \_ __\ /__ _/   .-` /  /
// ======`-.____`-.___\_____/___.-`____.-'======
//                    `=---='
// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//             佛祖保佑        永无BUG
//           南无阿弥陀佛   就算报错也让我看懂
//                    佛祖保佑
/*********************************************************************/
`include "/home/furina/ysyx-workbench/npc/soc-vsrc/defines.v"
module ysyx_25010030 (
    input         clock,
    input         reset,
    input         io_interrupt,

    //====== AXI Master ======//
    input         io_master_awready,
    output        io_master_awvalid,
    output [31:0] io_master_awaddr,
    output [3:0]  io_master_awid,
    output [7:0]  io_master_awlen,
    output [2:0]  io_master_awsize,
    output [1:0]  io_master_awburst,

    input         io_master_wready,
    output        io_master_wvalid,
    output [31:0] io_master_wdata,
    output [3:0]  io_master_wstrb,
    output        io_master_wlast,

    output        io_master_bready,
    input         io_master_bvalid,
    input  [1:0]  io_master_bresp,
    input  [3:0]  io_master_bid,

    input         io_master_arready,
    output        io_master_arvalid,
    output [31:0] io_master_araddr,
    output [3:0]  io_master_arid,
    output [7:0]  io_master_arlen,
    output [2:0]  io_master_arsize,
    output [1:0]  io_master_arburst,

    output        io_master_rready,
    input         io_master_rvalid,
    input  [1:0]  io_master_rresp,
    input  [31:0] io_master_rdata,
    input         io_master_rlast,
    input  [3:0]  io_master_rid,

    //====== AXI Slave ======//
    output        io_slave_awready,
    input         io_slave_awvalid,
    input  [31:0] io_slave_awaddr,
    input  [3:0]  io_slave_awid,
    input  [7:0]  io_slave_awlen,
    input  [2:0]  io_slave_awsize,
    input  [1:0]  io_slave_awburst,

    output        io_slave_wready,
    input         io_slave_wvalid,
    input  [31:0] io_slave_wdata,
    input  [3:0]  io_slave_wstrb,
    input         io_slave_wlast,

    input         io_slave_bready,
    output        io_slave_bvalid,
    output [1:0]  io_slave_bresp,
    output [3:0]  io_slave_bid,

    output        io_slave_arready,
    input         io_slave_arvalid,
    input  [31:0] io_slave_araddr,
    input  [3:0]  io_slave_arid,
    input  [7:0]  io_slave_arlen,
    input  [2:0]  io_slave_arsize,
    input  [1:0]  io_slave_arburst,

    input         io_slave_rready,
    output        io_slave_rvalid,
    output [1:0]  io_slave_rresp,
    output [31:0] io_slave_rdata,
    output        io_slave_rlast,
    output [3:0]  io_slave_rid

);
`ifdef VERILATOR
    import "DPI-C" function void counter(input int inst_type, input int cycles, input int ifu_inc, input int lsu_inc, input int exu_inc);
`endif
    //===== IF =====//
    wire [31:0]  pc;
    wire [31:0]  instr;
    wire         if_ready;
    wire         wb_valid;
    wire         if_valid;
    wire         id_ready;
    wire         if_access_fault;
    wire [31:0]  if_fault_addr;
    wire [31:0]  trap_pc;

    wire [31:0] ifu_sram_araddr;
    wire        ifu_sram_arvalid;
    wire        ifu_sram_arready;
    wire [31:0] ifu_sram_rdata;
    wire        ifu_sram_rvalid;
    wire        ifu_sram_rready;
    wire [1:0]  ifu_sram_rresp;
    wire [31:0] ifu_sram_awaddr;
    wire        ifu_sram_awvalid;
    wire        ifu_sram_awready;
    wire [31:0] ifu_sram_wdata;
    wire [3:0]  ifu_sram_wstrb;
    wire        ifu_sram_wvalid;
    wire        ifu_sram_wready;
    wire [1:0]  ifu_sram_bresp;
    wire        ifu_sram_bvalid;
    wire        ifu_sram_bready;

    //===== ID =====//
    wire [6:0]   opcode;
    wire [4:0]   rs1, rs2, rd;
    wire [31:0]  imm;
    wire [2:0]   func3;
    wire [6:0]   func7;
    wire         RegWrite;
    wire         MemWrite;
    wire         MemRead;
    wire [3:0]   alu_op;
    wire [2:0]   MemLen;
    wire         id_valid;
    wire         ex_ready;

    //===== RegFile =====//
    wire         reg_valid;
    wire         reg_ready;

    //===== EX =====//
    wire [31:0]  rs1_val, rs2_val;
    wire [31:0]  alu_result;
    wire         alu_zero;
    wire         alu_less;
    wire         ex_valid;
    wire         mem_ready;

    //===== MEM =====//
    wire [31:0]  data_out;
    wire         mem_valid;
    wire         wb_ready;
    wire         load_access_fault;
    wire         store_access_fault;
    wire [31:0]  mem_fault_addr;

    wire [31:0] mem_sram_araddr;
    wire        mem_sram_arvalid;
    wire        mem_sram_arready;
    wire [31:0] mem_sram_rdata;
    wire        mem_sram_rvalid;
    wire        mem_sram_rready;
    wire [1:0]  mem_sram_rresp;
    wire [31:0] mem_sram_awaddr;
    wire        mem_sram_awvalid;
    wire        mem_sram_awready;
    wire [31:0] mem_sram_wdata;
    wire [3:0]  mem_sram_wstrb;
    wire        mem_sram_wvalid;
    wire        mem_sram_wready;
    wire [1:0]  mem_sram_bresp;
    wire        mem_sram_bvalid;
    wire        mem_sram_bready;

    //===== WB =====//
    wire [31:0]  wb_data;
    wire [31:0]  jal_target;
    wire [31:0]  jalr_target;
    wire         is_jal, is_jalr;
    wire         take_branch;
    wire [31:0]  branch_target;
    
    wire [4:0]   rd_wb;
    wire         RegWrite_wb;
    wire         wb_MemRead, wb_MemWrite;
    wire [2:0]   wb_MemLen;
    wire [31:0]  wb_addr, wb_data_in;

    //====SRAM读写接口====//
    //AR channel
    wire [31:0] sram_araddr;
    wire        sram_arvalid;
    wire        sram_arready;
    //R channel
    wire [1:0]  sram_rresp;
    wire [31:0] sram_rdata;
    wire        sram_rvalid;
    wire        sram_rready;
    //AW channel
    wire [31:0] sram_awaddr;
    wire        sram_awready;
    wire        sram_awvalid;
    //W channel
    wire [31:0] sram_wdata;
    wire [3:0]  sram_wstrb;
    wire        sram_wvalid;
    wire        sram_wready;
    //B channel
    wire [1:0]  sram_bresp;
    wire        sram_bvalid;
    wire        sram_bready;

    //====== UART =======//
    //AR channel
    wire [31:0] uart_araddr;
    wire        uart_arvalid;
    wire        uart_arready;
    //R channel
    wire [1:0]  uart_rresp;
    wire [31:0] uart_rdata;
    wire        uart_rvalid;
    wire        uart_rready;
    //AW channel
    wire [31:0] uart_awaddr;
    wire        uart_awready;
    wire        uart_awvalid;
    //W channel
    wire [31:0] uart_wdata;
    wire [3:0]  uart_wstrb;
    wire        uart_wvalid;
    wire        uart_wready;
    //B channel
    wire [1:0]  uart_bresp;
    wire        uart_bvalid;
    wire        uart_bready;

    //====== CLINT =======//
    //AR channel
    wire [31:0] clint_araddr;
    wire        clint_arvalid;
    wire        clint_arready;
    //R channel
    wire [1:0]  clint_rresp;
    wire [31:0] clint_rdata;
    wire        clint_rvalid;
    wire        clint_rready;
    //AW channel
    wire [31:0] clint_awaddr;
    wire        clint_awready;
    wire        clint_awvalid;
    //W channel
    wire [31:0] clint_wdata;
    wire [3:0]  clint_wstrb;
    wire        clint_wvalid;
    wire        clint_wready;
    //B channel
    wire [1:0]  clint_bresp;
    wire        clint_bvalid;
    wire        clint_bready;

    //性能计数器
    wire [31:0] id_inst_type;
    wire [31:0] id_start_cycle;
    wire [31:0] ex_inst_type;
    wire [31:0] ex_start_cycle;
    wire [31:0] mem_inst_type;
    wire [31:0] mem_start_cycle;

    AXI_ARB axi_arb (
        .clk(clock),
        .reset(reset),

        // IFU master
        .ifu_araddr(ifu_sram_araddr),
        .ifu_arvalid(ifu_sram_arvalid),
        .ifu_arready(ifu_sram_arready),
        .ifu_rdata(ifu_sram_rdata),
        .ifu_rresp(ifu_sram_rresp),
        .ifu_rvalid(ifu_sram_rvalid),
        .ifu_rready(ifu_sram_rready),

        // MEM master
        .mem_araddr(mem_sram_araddr),
        .mem_arvalid(mem_sram_arvalid),
        .mem_arready(mem_sram_arready),
        .mem_rdata(mem_sram_rdata),
        .mem_rresp(mem_sram_rresp),
        .mem_rvalid(mem_sram_rvalid),
        .mem_rready(mem_sram_rready),
        .mem_awaddr(mem_sram_awaddr),
        .mem_awvalid(mem_sram_awvalid),
        .mem_awready(mem_sram_awready),
        .mem_wdata(mem_sram_wdata),
        .mem_wstrb(mem_sram_wstrb),
        .mem_wvalid(mem_sram_wvalid),
        .mem_wready(mem_sram_wready),
        .mem_bresp(mem_sram_bresp),
        .mem_bvalid(mem_sram_bvalid),
        .mem_bready(mem_sram_bready),

        .io_master_araddr(io_master_araddr),
        .io_master_arvalid(io_master_arvalid),
        .io_master_arready(io_master_arready),
        .io_master_rdata(io_master_rdata),
        .io_master_rresp(io_master_rresp),
        .io_master_rvalid(io_master_rvalid),
        .io_master_rready(io_master_rready),
        .io_master_awaddr(io_master_awaddr),
        .io_master_awvalid(io_master_awvalid),
        .io_master_awready(io_master_awready),
        .io_master_wdata(io_master_wdata),
        .io_master_wstrb(io_master_wstrb),
        .io_master_wvalid(io_master_wvalid),
        .io_master_wready(io_master_wready),
        .io_master_bresp(io_master_bresp),
        .io_master_bvalid(io_master_bvalid),
        .io_master_bready(io_master_bready),    

        // CLINT从设备
        .clint_araddr(clint_araddr),
        .clint_arvalid(clint_arvalid),
        .clint_arready(clint_arready),
        .clint_rdata(clint_rdata),
        .clint_rresp(clint_rresp),
        .clint_rvalid(clint_rvalid),
        .clint_rready(clint_rready),
        .clint_awaddr(clint_awaddr),
        .clint_awvalid(clint_awvalid),
        .clint_awready(clint_awready),
        .clint_wdata(clint_wdata),
        .clint_wstrb(clint_wstrb),
        .clint_wvalid(clint_wvalid),
        .clint_wready(clint_wready),
        .clint_bresp(clint_bresp),
        .clint_bvalid(clint_bvalid),
        .clint_bready(clint_bready)
    );

    // CLINT模块
    CLINT clint (
        .clk(clock),
        .reset(reset),
        .awvalid(clint_awvalid),
        .awready(clint_awready),
        .awaddr(clint_awaddr),
        .wdata(clint_wdata),
        .wstrb(clint_wstrb),
        .wvalid(clint_wvalid),
        .wready(clint_wready),
        .bresp(clint_bresp),
        .bvalid(clint_bvalid),
        .bready(clint_bready),
        .arvalid(clint_arvalid),
        .araddr(clint_araddr),
        .arready(clint_arready),
        .rready(clint_rready),
        .rvalid(clint_rvalid),
        .rresp(clint_rresp),
        .rdata(clint_rdata)
    );

    // UART模块
    // UART uart (
    //     .clk(clock),
    //     .reset(reset),
    //     .awvalid(uart_awvalid),
    //     .awready(uart_awready),
    //     .awaddr(uart_awaddr),
    //     .wdata(uart_wdata),
    //     .wstrb(uart_wstrb),
    //     .wvalid(uart_wvalid),
    //     .wready(uart_wready),
    //     .bresp(uart_bresp),
    //     .bvalid(uart_bvalid),
    //     .bready(uart_bready),
    //     .arvalid(uart_arvalid),
    //     .araddr(uart_araddr),
    //     .arready(uart_arready),
    //     .rready(uart_rready),
    //     .rvalid(uart_rvalid),
    //     .rresp(uart_rresp),
    //     .rdata(uart_rdata)
    // );

    // SRAM sram(
    //         .clk(clock),
    //         .reset(reset),
    //         //AR channel
    //         .araddr(sram_araddr),
    //         .arvalid(sram_arvalid),
    //         .arready(sram_arready),
    //         //R channel
    //         .rdata(sram_rdata),
    //         .rvalid(sram_rvalid),
    //         .rready(sram_rready),
    //         .rresp(sram_rresp),
    //         //AW channel
    //         .awaddr(sram_awaddr),
    //         .awvalid(sram_awvalid),
    //         .awready(sram_awready),
    //         //W channel
    //         .wdata(sram_wdata),
    //         .wstrb(sram_wstrb),
    //         .wvalid(sram_wvalid),
    //         .wready(sram_wready),
    //         //B channel
    //         .bresp(sram_bresp),
    //         .bvalid(sram_bvalid),
    //         .bready(sram_bready)
    // );

    // SRAM isram(
    //         .clk(clock),
    //         .reset(reset),
    //         //AR channel
    //         .araddr(ifu_sram_araddr),
    //         .arvalid(ifu_sram_arvalid),
    //         .arready(ifu_sram_arready),
    //         //R channel
    //         .rdata(ifu_sram_rdata),
    //         .rvalid(ifu_sram_rvalid),
    //         .rready(ifu_sram_rready),
    //         .rresp(ifu_sram_rresp),
    //         //AW channel
    //         .awaddr(ifu_sram_awaddr),
    //         .awvalid(ifu_sram_awvalid),
    //         .awready(ifu_sram_awready),
    //         //W channel
    //         .wdata(ifu_sram_wdata),
    //         .wstrb(ifu_sram_wstrb),
    //         .wvalid(ifu_sram_wvalid),
    //         .wready(ifu_sram_wready),
    //         //B channel
    //         .bresp(ifu_sram_bresp),
    //         .bvalid(ifu_sram_bvalid),
    //         .bready(ifu_sram_bready)
    // );

    // SRAM msram(
    //         .clk(clock),
    //         .reset(reset),
    //         //AR channel
    //         .araddr(mem_sram_araddr),
    //         .arvalid(mem_sram_arvalid),
    //         .arready(mem_sram_arready),
    //         //R channel
    //         .rdata(mem_sram_rdata),
    //         .rvalid(mem_sram_rvalid),
    //         .rready(mem_sram_rready),
    //         .rresp(mem_sram_rresp),
    //         //AW channel
    //         .awaddr(mem_sram_awaddr),
    //         .awvalid(mem_sram_awvalid),
    //         .awready(mem_sram_awready),
    //         //W channel
    //         .wdata(mem_sram_wdata),
    //         .wstrb(mem_sram_wstrb),
    //         .wvalid(mem_sram_wvalid),
    //         .wready(mem_sram_wready),
    //         //B channel
    //         .bresp(mem_sram_bresp),
    //         .bvalid(mem_sram_bvalid),
    //         .bready(mem_sram_bready)
    // );

    // 取指模块
    IF if_stage (
        .clk(clock),
        .reset(reset),
        // .branch_target(is_jalr ? jalr_target : jal_target),
        .branch_target(branch_target),
        .pc_src(is_jal | is_jalr | take_branch),
        .pc(pc),
        .instr(instr),
        .if_ready(if_ready),
        .wb_valid(wb_valid),
        .if_valid(if_valid),
        .id_ready(id_ready),
        .if_access_fault(if_access_fault),
        .if_fault_addr(if_fault_addr),
        // .flush(flush),
        // .actual_target(actual_target),
        // .predict_taken(predict_taken),
        // .predict_target(predict_target),
        // .ghr(ghr),
        .sram_araddr(ifu_sram_araddr),
        .sram_arvalid(ifu_sram_arvalid),
        .sram_arready(ifu_sram_arready),
        .sram_rdata(ifu_sram_rdata),
        .sram_rvalid(ifu_sram_rvalid),
        .sram_rready(ifu_sram_rready),
        .sram_rresp(ifu_sram_rresp),
        .sram_awaddr(ifu_sram_awaddr),
        .sram_awvalid(ifu_sram_awvalid),
        .sram_awready(ifu_sram_awready),
        .sram_wdata(ifu_sram_wdata),
        .sram_wstrb(ifu_sram_wstrb),
        .sram_wvalid(ifu_sram_wvalid),
        .sram_wready(ifu_sram_wready),
        .sram_bresp(ifu_sram_bresp),
        .sram_bvalid(ifu_sram_bvalid),
        .sram_bready(ifu_sram_bready)
    );

    // 译码模块
    ID id_stage (
        .clk(clock),
        .reset(reset),
        .instr(instr),
        .if_valid(if_valid),
        .id_ready(id_ready),
        .id_valid(id_valid),
        .ex_ready(ex_ready),
        .opcode(opcode),
        .rs1(rs1),
        .rs2(rs2),
        .rd(rd),
        .imm(imm),
        .func3(func3),
        .func7(func7),
        .RegWrite(RegWrite),
        .MemWrite(MemWrite),
        .MemRead(MemRead),
        .alu_op(alu_op),
        .MemLen(MemLen),
        .id_start_cycle(id_start_cycle),
        .id_inst_type(id_inst_type)
    );
    
    EX ex_stage(
        .clk(clock), 
        .reset(reset),
        .id_valid(id_valid),
        .ex_ready(ex_ready),
        .opcode(opcode), 
        .rs1_val(rs1_val),
        .rs2_val(rs2_val),
        .imm(imm),
        .alu_op(alu_op),
        .mem_ready(mem_ready),
        .ex_valid(ex_valid),
        .alu_result(alu_result),
        .alu_zero(alu_zero),   
        .alu_less(alu_less),
        .id_start_cycle(id_start_cycle),
        .id_inst_type(id_inst_type),
        .ex_start_cycle(ex_start_cycle),
        .ex_inst_type(ex_inst_type)
    );
    // 内存模块
    MEM mem_stage(
        .clk(clock),
        .reset(reset),
        .ex_valid(ex_valid),
        .mem_ready(mem_ready),
        .wb_ready(wb_ready),
        .mem_valid(mem_valid),
        .MemRead(MemRead),
        .MemWrite(MemWrite),
        .MemLen(MemLen),
        .addr(rs1_val + imm),
        .data_in(rs2_val),
        .data_out(data_out),
        .load_access_fault(load_access_fault),
        .store_access_fault(store_access_fault),
        .mem_fault_addr(mem_fault_addr),
        .sram_araddr(mem_sram_araddr),
        .sram_arvalid(mem_sram_arvalid),
        .sram_arready(mem_sram_arready),
        .sram_rdata(mem_sram_rdata),
        .sram_rvalid(mem_sram_rvalid),
        .sram_rready(mem_sram_rready),
        .sram_rresp(mem_sram_rresp),
        .sram_awaddr(mem_sram_awaddr),
        .sram_awvalid(mem_sram_awvalid),
        .sram_awready(mem_sram_awready),
        .sram_wdata(mem_sram_wdata),
        .sram_wstrb(mem_sram_wstrb),
        .sram_wvalid(mem_sram_wvalid),
        .sram_wready(mem_sram_wready),
        .sram_bresp(mem_sram_bresp),
        .sram_bvalid(mem_sram_bvalid),
        .sram_bready(mem_sram_bready),
        .ex_start_cycle(ex_start_cycle),
        .ex_inst_type(ex_inst_type),
        .mem_start_cycle(mem_start_cycle),
        .mem_inst_type(mem_inst_type)
    );

    // 写回模块
    WB wb_stage (
        .clk(clock), 
        .reset(reset),
        .mem_valid(mem_valid),
        .wb_ready(wb_ready),
        .if_ready(if_ready),
        .wb_valid(wb_valid),
        .opcode(opcode),
        .func3(func3),

        .id_rd(rd),
        .id_RegWrite(RegWrite),

        .rs1(rs1),
        .rs2(rs2),
        .rs1_val(rs1_val),
        .rs2_val(rs2_val),

        .pc(pc),
        .imm(imm),
        // .rs1_val(rs1_val),
        .alu_less(alu_less),
        .alu_zero(alu_zero),
        .alu_result(alu_result),
        .data_out(data_out),
        .is_jal(is_jal),
        .is_jalr(is_jalr),
        .take_branch(take_branch),
        .jal_target(jal_target),
        .jalr_target(jalr_target),
        .wb_data(wb_data)

        // .predict_taken(predict_taken),
        // .flush(flush),
        // .actual_target(actual_target),
        // .branch_total(branch_total),
        // .branch_correct(branch_correct),
        // .ghr(ghr),
        // .ghr_update(ghr_update)
    );
    assign branch_target = is_jalr ? jalr_target : jal_target;

    reg [31:0] inst_cnt;
    reg [31:0] cycle_cnt;
    reg [31:0] cycles;
    always @(posedge clock) begin
        if(reset) begin
            inst_cnt <= 0;
            cycle_cnt <= 0;
        end
        else begin
            cycle_cnt <= cycle_cnt + 1;
            if(wb_valid) begin
                inst_cnt <= inst_cnt + 1;
            `ifdef VERILATOR
                counter(mem_inst_type, (cycle_cnt - mem_start_cycle + 1), 0, 0, 0);
            `endif
            end
        end
    end

    // EBREAK 处理
    // always @(posedge clock) begin
    //     if (instr == 32'h00100073) begin
    //         real IPC = (cycle_cnt == 0) ? 0.0 : real'(inst_cnt) / real'(cycle_cnt);
    //         $display("\033[33mIPC = %f\033[0m", IPC);
    //     end
    // end

    always @(*) begin
        if(if_access_fault) begin
            $display("\033[31m[IF]:IF access fault at address: %h\033[0m", if_fault_addr);
        end
        if(load_access_fault) begin
            $display("\033[31m[MEM]:Load access fault at address: %h\033[0m", mem_fault_addr);
        end
        if(store_access_fault) begin
            $display("\033[31m[MEM]:Store access fault at address: %h\033[0m", mem_fault_addr);
        end
    end 
endmodule
