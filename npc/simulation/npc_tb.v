`timescale 1ns/1ns
`define PLATFORM_NPC  // 匹配顶层模块的PLATFORM_NPC宏
// `define ITRACE  // 匹配顶层模块的PLATFORM_NPC宏

module npc_tb;

// ==============================================
// 1. 信号定义（包含所有需要驱动的端口）
// ==============================================
reg             clock;
reg             reset;
reg             io_interrupt;

// slave输入端口信号（消除悬空警告）
reg             io_slave_awvalid;
reg [31:0]      io_slave_awaddr;
reg [3:0]       io_slave_awid;
reg [7:0]       io_slave_awlen;
reg [2:0]       io_slave_awsize;
reg [1:0]       io_slave_awburst;
reg             io_slave_wvalid;
reg [31:0]      io_slave_wdata;
reg [3:0]       io_slave_wstrb;
reg             io_slave_wlast;
reg             io_slave_bready;
reg             io_slave_arvalid;
reg [31:0]      io_slave_araddr;
reg [3:0]       io_slave_arid;
reg [7:0]       io_slave_arlen;
reg [2:0]       io_slave_arsize;
reg [1:0]       io_slave_arburst;
reg             io_slave_rready;

`ifdef __ICARUS__
// master总线信号 — 连接顶层模块和外部memory
wire            io_master_awready;
wire            io_master_awvalid;
wire [31:0]     io_master_awaddr;
wire [3:0]      io_master_awid;
wire [7:0]      io_master_awlen;
wire [2:0]      io_master_awsize;
wire [1:0]      io_master_awburst;
wire            io_master_wready;
wire            io_master_wvalid;
wire [31:0]     io_master_wdata;
wire [3:0]      io_master_wstrb;
wire            io_master_wlast;
wire            io_master_bready;
wire            io_master_bvalid;
wire [1:0]      io_master_bresp;
wire [3:0]      io_master_bid;
wire            io_master_arready;
wire            io_master_arvalid;
wire [31:0]     io_master_araddr;
wire [3:0]      io_master_arid;
wire [7:0]      io_master_arlen;
wire [2:0]      io_master_arsize;
wire [1:0]      io_master_arburst;
wire            io_master_rready;
wire            io_master_rvalid;
wire [1:0]      io_master_rresp;
wire [31:0]     io_master_rdata;
wire            io_master_rlast;
wire [3:0]      io_master_rid;
`endif

// 全局定义cycle_cnt（解决绑定失败）
reg [31:0]      cycle_cnt;

// ==============================================
// 2. 信号初始化
// ==============================================
initial begin
    // 基础信号初始化
    clock = 1'b0;
    reset = 1'b1;
    io_interrupt = 1'b0;
    cycle_cnt = 32'd0;

    // slave信号初始化（全部置0）
    io_slave_awvalid = 1'b0;
    io_slave_awaddr  = 32'd0;
    io_slave_awid    = 4'd0;
    io_slave_awlen   = 8'd0;
    io_slave_awsize  = 3'd0;
    io_slave_awburst = 2'd0;
    io_slave_wvalid  = 1'b0;
    io_slave_wdata   = 32'd0;
    io_slave_wstrb   = 4'd0;
    io_slave_wlast   = 1'b0;
    io_slave_bready  = 1'b0;
    io_slave_arvalid = 1'b0;
    io_slave_araddr  = 32'd0;
    io_slave_arid    = 4'd0;
    io_slave_arlen   = 8'd0;
    io_slave_arsize  = 3'd0;
    io_slave_arburst = 2'd0;
    io_slave_rready  = 1'b0;

    // 复位50ns后释放
    #40;
    reset = 1'b0;

    // 仿真时长（1ms）
    #10000000;
    $display("Simulation finished: Timeout!");
    $finish;
end

// ==============================================
// 3. 时钟生成（500MHz）
// ==============================================
always #1 clock = ~clock;

// ==============================================
// 4. 存储器模块（外部实例化，仅iverilog）
// ==============================================
`ifdef __ICARUS__
// memory初始化
initial begin
    $readmemh(`HEX_FILE, mem_u.mem);
    $display("mem[0] = 0x%08x", {mem_u.mem[3], mem_u.mem[2], mem_u.mem[1], mem_u.mem[0]});
    $display("Memory initialized from: %s", `HEX_FILE);
end

// 外部memory模块 — 通过master总线连接到顶层
ysyx_25020042_mem mem_u (
    .clock          (clock),
    .reset          (reset),

    .slave_araddr   (io_master_araddr),
    .slave_arvalid  (io_master_arvalid),
    .slave_arready  (io_master_arready),
    .slave_arid     (io_master_arid),
    .slave_arlen    (io_master_arlen),
    .slave_arsize   (io_master_arsize),
    .slave_arburst  (io_master_arburst),

    .slave_rdata    (io_master_rdata),
    .slave_rvalid   (io_master_rvalid),
    .slave_rresp    (io_master_rresp),
    .slave_rready   (io_master_rready),
    .slave_rlast    (io_master_rlast),
    .slave_rid      (io_master_rid),

    .slave_awaddr   (io_master_awaddr),
    .slave_awvalid  (io_master_awvalid),
    .slave_awready  (io_master_awready),
    .slave_awid     (io_master_awid),
    .slave_awlen    (io_master_awlen),
    .slave_awsize   (io_master_awsize),
    .slave_awburst  (io_master_awburst),

    .slave_wdata    (io_master_wdata),
    .slave_wstrb    (io_master_wstrb),
    .slave_wvalid   (io_master_wvalid),
    .slave_wready   (io_master_wready),
    .slave_wlast    (io_master_wlast),

    .slave_bvalid   (io_master_bvalid),
    .slave_bready   (io_master_bready),
    .slave_bresp    (io_master_bresp),
    .slave_bid      (io_master_bid)
);
`endif

// ==============================================
// 5. 顶层模块实例化
// ==============================================
ysyx_25020042 ysyx_25020042_inst (
    .clock(clock),
    .reset(reset),
    .io_interrupt(io_interrupt),

    
    .io_slave_awvalid(io_slave_awvalid),
    .io_slave_awaddr(io_slave_awaddr),
    .io_slave_awid(io_slave_awid),
    .io_slave_awlen(io_slave_awlen),
    .io_slave_awsize(io_slave_awsize),
    .io_slave_awburst(io_slave_awburst),
    .io_slave_wvalid(io_slave_wvalid),
    .io_slave_wdata(io_slave_wdata),
    .io_slave_wstrb(io_slave_wstrb),
    .io_slave_wlast(io_slave_wlast),
    .io_slave_bready(io_slave_bready),
    .io_slave_arvalid(io_slave_arvalid),
    .io_slave_araddr(io_slave_araddr),
    .io_slave_arid(io_slave_arid),
    .io_slave_arlen(io_slave_arlen),
    .io_slave_arsize(io_slave_arsize),
    .io_slave_arburst(io_slave_arburst),
    .io_slave_rready(io_slave_rready),

`ifdef __ICARUS__
    // master端口 — 连接到外部memory
    .io_master_awready (io_master_awready),
    .io_master_awvalid (io_master_awvalid),
    .io_master_awaddr  (io_master_awaddr),
    .io_master_awid    (io_master_awid),
    .io_master_awlen   (io_master_awlen),
    .io_master_awsize  (io_master_awsize),
    .io_master_awburst (io_master_awburst),
    .io_master_wready  (io_master_wready),
    .io_master_wvalid  (io_master_wvalid),
    .io_master_wdata   (io_master_wdata),
    .io_master_wstrb   (io_master_wstrb),
    .io_master_wlast   (io_master_wlast),
    .io_master_bready  (io_master_bready),
    .io_master_bvalid  (io_master_bvalid),
    .io_master_bresp   (io_master_bresp),
    .io_master_bid     (io_master_bid),
    .io_master_arready (io_master_arready),
    .io_master_arvalid (io_master_arvalid),
    .io_master_araddr  (io_master_araddr),
    .io_master_arid    (io_master_arid),
    .io_master_arlen   (io_master_arlen),
    .io_master_arsize  (io_master_arsize),
    .io_master_arburst (io_master_arburst),
    .io_master_rready  (io_master_rready),
    .io_master_rvalid  (io_master_rvalid),
    .io_master_rresp   (io_master_rresp),
    .io_master_rdata   (io_master_rdata),
    .io_master_rlast   (io_master_rlast),
    .io_master_rid     (io_master_rid),
`endif

    // slave输出端口悬空（无外部接收）
    .io_slave_awready(),
    .io_slave_wready(),
    .io_slave_bvalid(),
    .io_slave_bresp(),
    .io_slave_bid(),
    .io_slave_arready(),
    .io_slave_rvalid(),
    .io_slave_rresp(),
    .io_slave_rdata(),
    .io_slave_rlast(),
    .io_slave_rid()
);

// ==============================================
// 6. 波形导出
// ==============================================
initial begin
    // $dumpfile("/home/long/ysyx-workbench/npc/simulation/build/npc_wave.vcd");
    // $dumpvars(0, npc_tb);
end

// ==============================================
// 7. 仿真日志（修复cycle_cnt绑定）
// ==============================================
always @(posedge clock) begin
    if (!reset) begin
        cycle_cnt <= cycle_cnt + 1'b1;
        `ifdef ITRACE
        if (ysyx_25020042_inst.WBU_u.wbu_valid) begin
            case (ysyx_25020042_inst.WBU_u.i_inst)
            3'b001: $display("pc: %08x\tinstruction: EXU", ysyx_25020042_inst.WBU_u.i_pc_data);
            3'b010: $display("pc: %08x\tinstruction: JUMP", ysyx_25020042_inst.WBU_u.i_pc_data);
            3'b011: $display("pc: %08x\tinstruction: LSU", ysyx_25020042_inst.WBU_u.i_pc_data);
            3'b100: $display("pc: %08x\tinstruction: CSR", ysyx_25020042_inst.WBU_u.i_pc_data);
            3'b101: $display("pc: %08x\tinstruction: FENCE", ysyx_25020042_inst.WBU_u.i_pc_data);
            default: $display("pc: %08x\tinstruction: NOP", ysyx_25020042_inst.WBU_u.i_pc_data);
            endcase
        end
        `endif
        // 检测ebreak
        // if (ysyx_25020042_inst.WBU_u.i_IDU_Exception_Handling[1]) begin
        //     $display("EBREAK detected! Cycle: %0d", cycle_cnt);
        //     if(ysyx_25020042_inst.gpr_u.a0 == 0) begin
        //         $display("Good Trap!");
        //     end
        //     else begin
        //         $display("Bad Trap! pc at 0x%08x", ysyx_25020042_inst.WBU_u.i_pc_data);
        //     end
        //     $finish;
        // end
    end else begin
        cycle_cnt <= 32'd0;
    end
end

endmodule
