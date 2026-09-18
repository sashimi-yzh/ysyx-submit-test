module ysyx_26010027_LSU (
    input             clock,
    input             reset,

    input      [ 1:0] exu_lsu_mem_w,
    input      [ 2:0] exu_lsu_mem_r,
    input      [31:0] exu_lsu_mem_addr,
    input      [31:0] exu_lsu_wdata,

    // EXU - LSU
    input             exu_lsu_valid,
    output wire       lsu_exu_ready,
    input      [31:0] exu_lsu_pc,
    input      [31:0] exu_lsu_snpc,
    input      [31:0] exu_lsu_inst,
    input             exu_lsu_reg_w,
    input      [ 1:0] exu_lsu_rf_res,
    input      [ 3:0] exu_lsu_waddr,
    input      [31:0] exu_lsu_alu_result,

    input      [11:0] exu_lsu_csr_waddr,
    input             exu_lsu_csr_we,
    input             exu_lsu_csr_ecall,
    input             exu_lsu_csr_mret,
    input      [31:0] exu_lsu_csr_wdata,
    output wire       lsu_exu_inflight, // 前递/停顿: LSU 中还在飞的 load

    // LSU - WBU
    input             wbu_lsu_ready,
    output wire       lsu_wbu_valid,
    output reg [31:0] lsu_wbu_pc,
    output reg [31:0] lsu_wbu_snpc,
    output reg [31:0] lsu_wbu_inst,
    output reg        lsu_wbu_reg_w,
    output reg [ 1:0] lsu_wbu_rf_res,
    output reg [ 3:0] lsu_wbu_waddr,
    output reg [31:0] lsu_wbu_alu_result,
    output reg [31:0] lsu_wbu_mem_result,

    output reg [11:0] lsu_wbu_csr_waddr,
    output reg        lsu_wbu_csr_we,
    output reg        lsu_wbu_csr_ecall,
    output reg        lsu_wbu_csr_mret,
    output reg [31:0] lsu_wbu_csr_wdata,

`ifdef NPC_SIM
    input      [31:0] exu_lsu_dnpc,
    output reg [31:0] lsu_wbu_dnpc,
    output reg        lsu_wbu_mem_en,
    output reg [31:0] lsu_wbu_mem_addr,
`endif

    // ----------- AXI4 -----------
    input             cpu_lsu_arready,
    output     [31:0] lsu_cpu_araddr,
    output            lsu_cpu_arvalid,
    output     [ 3:0] lsu_cpu_arid,
    output     [ 7:0] lsu_cpu_arlen,
    output     [ 2:0] lsu_cpu_arsize,
    output     [ 1:0] lsu_cpu_arburst,

    output            lsu_cpu_rready,
    input             cpu_lsu_rvalid,
    input      [31:0] cpu_lsu_rdata,
    input      [ 1:0] cpu_lsu_rresp,

    output     [31:0] lsu_cpu_awaddr,
    output            lsu_cpu_awvalid,
    output     [ 3:0] lsu_cpu_awid,
    output     [ 7:0] lsu_cpu_awlen,
    output     [ 2:0] lsu_cpu_awsize,
    output     [ 1:0] lsu_cpu_awburst,
    input             cpu_lsu_awready,

    output     [31:0] lsu_cpu_wdata,
    output     [ 3:0] lsu_cpu_wstrb,
    output            lsu_cpu_wvalid,
    output            lsu_cpu_wlast,
    input             cpu_lsu_wready,

    input      [ 1:0] cpu_lsu_bresp,
    input             cpu_lsu_bvalid,
    output            lsu_cpu_bready
);

    // ----- 锁存 -----
    reg        l_busy;     // 被占用且可能未完成的访存事务
    reg [ 1:0] l_mem_w;
    reg [ 2:0] l_mem_r;
    reg [31:0] l_mem_addr;
    reg [31:0] l_wdata;
    reg        mem_done;    // 访存事务完成

    wire is_load  = (l_mem_r != 3'd5);
    wire is_store = (l_mem_w != 2'b11);
    wire mem_op   = is_load || is_store;

    // ----- CLINT -----
    localparam [15:0] CLINT_BASE_HI = 16'h0200;
    localparam [13:0] MTIME_OFF     = 14'h0000; // 0x0200_0000 >> 2
    localparam [13:0] MTIMEH_OFF    = 14'h0001; // 0x0200_0004 >> 2

    wire addr_is_clint = (l_mem_addr[31:16] == CLINT_BASE_HI);
    wire clint_access  = l_busy && mem_op && addr_is_clint && !mem_done;

    reg [31:0] mtime_l;
    reg [31:0] mtime_h;
    always @(posedge clock, posedge reset) begin
        if (reset) begin 
            mtime_l <= 32'b0;
            mtime_h <= 32'b0;
        end 
        else begin
            mtime_l <= mtime_l + 32'd1;
            mtime_h <= mtime_l == 32'hFFFF_FFFF ? mtime_h + 32'd1 : mtime_h;
        end
    end

    wire mtime_l_sel = (l_mem_addr[15:2] == MTIME_OFF);
    wire mtime_h_sel = (l_mem_addr[15:2] == MTIMEH_OFF);

    wire [31:0] clint_rdata = mtime_l_sel ? mtime_l :
                              mtime_h_sel ? mtime_h : 32'b0;

    // ----- state -----
    reg [2:0] state_w;
    reg [1:0] state_r;
    localparam W_IDLE    = 3'b000;
    localparam W_WAIT_W  = 3'b001;
    localparam W_WAIT_AW = 3'b010;
    localparam W_RESP    = 3'b011;
    localparam R_IDLE = 2'b00;
    localparam R_WAIT = 2'b01;

    wire load_q  = l_busy && is_load  && !mem_done; // 寄存访存信号 避免重复达成请求条件
    wire store_q = l_busy && is_store && !mem_done;

    // ----- 访存相关数据 -----
    // 数据移位信号 w/r
    wire [31:0] wdata_shifted = (l_mem_w == 2'b00) ? l_wdata : (l_wdata << (l_mem_addr[1:0] * 8)); // 桶形移位
    wire [31:0] rdata_shifted = cpu_lsu_rdata >> (l_mem_addr[1:0] * 8);

    assign lsu_cpu_awaddr  = l_mem_addr;
    assign lsu_cpu_araddr  = l_mem_addr;
    assign lsu_cpu_wdata   = wdata_shifted;
    assign lsu_cpu_wstrb   = (l_mem_w == 2'b00) ? 4'hF :
                             (l_mem_w == 2'b01) ? (4'h1 << l_mem_addr[1:0]) :
                             (l_mem_w == 2'b10) ? (4'h3 << l_mem_addr[1:0]) : 4'h0;
    assign lsu_cpu_awsize  = (l_mem_w == 2'b00) ? 3'b010 : // sw
                             (l_mem_w == 2'b10) ? 3'b001 : 3'b000; // sb/sh
    assign lsu_cpu_arsize  = (l_mem_r == 3'd0) ? 3'b010 : // lw
                             (l_mem_r == 3'd2 || l_mem_r == 3'd4) ? 3'b001 : 3'b000; // lb/lbu lh/lhu

    assign lsu_cpu_awid    = 4'h0;
    assign lsu_cpu_awlen   = 8'h0;
    assign lsu_cpu_awburst = 2'b01;
    assign lsu_cpu_wlast   = 1'b1;
    assign lsu_cpu_arid    = 4'h0;
    assign lsu_cpu_arlen   = 8'h0;
    assign lsu_cpu_arburst = 2'b01;

    assign lsu_cpu_awvalid = (state_w == W_IDLE || state_w == W_WAIT_AW) && store_q && !addr_is_clint;
    assign lsu_cpu_wvalid  = (state_w == W_IDLE || state_w == W_WAIT_W)  && store_q && !addr_is_clint;
    assign lsu_cpu_arvalid = (state_r == R_IDLE) && load_q && !addr_is_clint;
    assign lsu_cpu_rready  = (state_r == R_WAIT);
    assign lsu_cpu_bready  = (state_w == W_RESP);

    // 握手请求与响应信号
    wire handshake_aw = cpu_lsu_awready && lsu_cpu_awvalid;
    wire handshake_w  = cpu_lsu_wready  && lsu_cpu_wvalid;
    wire handshake_ar = cpu_lsu_arready && lsu_cpu_arvalid;
    wire handshake_r  = lsu_cpu_rready  && cpu_lsu_rvalid;
    wire handshake_b  = cpu_lsu_bvalid  && lsu_cpu_bready;

    // ----- W 状态机 -----
    always @(posedge clock, posedge reset) begin
        if (reset) state_w <= W_IDLE;
        else case (state_w)
            W_IDLE: if (handshake_aw && handshake_w) state_w <= W_RESP;
                    else if (handshake_aw) state_w <= W_WAIT_W;
                    else if (handshake_w)  state_w <= W_WAIT_AW;
            W_WAIT_W:  if (handshake_w)  state_w <= W_RESP;
            W_WAIT_AW: if (handshake_aw) state_w <= W_RESP;
            W_RESP:    if (handshake_b)  state_w <= W_IDLE;
            default: state_w <= W_IDLE;
        endcase
    end

    // ----- R 状态机 -----
    always @(posedge clock, posedge reset) begin
        if (reset) state_r <= R_IDLE;
        else case (state_r)
            R_IDLE: if (handshake_ar) state_r <= R_WAIT;
            R_WAIT: if (handshake_r)  state_r <= R_IDLE;
            default: state_r <= R_IDLE;
        endcase
    end

    // ----- Load 数据处理 -----
    wire [31:0] mem_rdata = (l_mem_r == 3'd0) ? rdata_shifted :
                            (l_mem_r == 3'd1) ? {{24{rdata_shifted[7]}}, rdata_shifted[7:0]} :
                            (l_mem_r == 3'd2) ? {{16{rdata_shifted[15]}}, rdata_shifted[15:0]} :
                            (l_mem_r == 3'd3) ? {24'b0, rdata_shifted[7:0]} :
                            (l_mem_r == 3'd4) ? {16'b0, rdata_shifted[15:0]} : 32'b0;

    // ----- 访存占用 -----
    always @(posedge clock, posedge reset) begin
        if (reset)
            l_busy <= 1'b0;
        else if (exu_lsu_valid && lsu_exu_ready)
            l_busy <= 1'b1; // 访存事务 忙
        else if (lsu_wbu_valid && wbu_lsu_ready)
            l_busy <= 1'b0;
    end

    // ----- 访存完成标志 -----
    always @(posedge clock, posedge reset) begin
        if (reset)
            mem_done <= 1'b0;
        else if (exu_lsu_valid && lsu_exu_ready)
            mem_done <= 1'b0; // 数据交接 标记进行中
        else if (handshake_r || handshake_b || clint_access)
            mem_done <= 1'b1; // 捕捉返回标志 标记完成
    end
    
    assign lsu_exu_ready     = !l_busy; // 不忙 向上游要数据
    assign lsu_wbu_valid     = l_busy && (!mem_op || mem_done); // 忙 & (非访存或访存完成)
    assign lsu_exu_inflight  = l_busy && (is_load | is_store) && !mem_done; // 忙 & 未完成 load|store线还在飞

    // ----- 网表锁存 -----
    always @(posedge clock, posedge reset) begin
        if (reset) begin
            lsu_wbu_reg_w     <= 1'b0;
            lsu_wbu_csr_we    <= 1'b0;
            lsu_wbu_csr_ecall <= 1'b0;
            lsu_wbu_csr_mret  <= 1'b0;
        end else if (exu_lsu_valid && lsu_exu_ready) begin
            lsu_wbu_reg_w     <= exu_lsu_reg_w;
            lsu_wbu_csr_we    <= exu_lsu_csr_we;
            lsu_wbu_csr_ecall <= exu_lsu_csr_ecall;
            lsu_wbu_csr_mret  <= exu_lsu_csr_mret;
        end
    end

    always @(posedge clock) begin
        if (exu_lsu_valid && lsu_exu_ready) begin
            // 非访存相关数据透传
            lsu_wbu_pc         <= exu_lsu_pc;
            lsu_wbu_snpc       <= exu_lsu_snpc;
            lsu_wbu_inst       <= exu_lsu_inst;
            lsu_wbu_rf_res     <= exu_lsu_rf_res;
            lsu_wbu_waddr      <= exu_lsu_waddr;
            lsu_wbu_alu_result <= exu_lsu_alu_result;

            lsu_wbu_csr_waddr  <= exu_lsu_csr_waddr;
            lsu_wbu_csr_wdata  <= exu_lsu_csr_wdata;

            // 访存相关锁存
            l_mem_w            <= exu_lsu_mem_w;
            l_mem_r            <= exu_lsu_mem_r;
            l_mem_addr         <= exu_lsu_mem_addr;
            l_wdata            <= exu_lsu_wdata;
        end
        // 单独写回load值 缩短访存时间 
        if (handshake_r || clint_access)
            lsu_wbu_mem_result <= addr_is_clint ? clint_rdata : mem_rdata;
    end


    wire unused_ok = &{cpu_lsu_rresp, cpu_lsu_bresp};
//  DIFFTEST
`ifdef NPC_SIM
    always @(posedge clock, posedge reset) begin
        if (reset) begin
            lsu_wbu_dnpc     <= 32'b0;
            lsu_wbu_mem_en   <= 1'b0;
            lsu_wbu_mem_addr <= 32'b0;
        end else if (exu_lsu_valid && lsu_exu_ready) begin
            lsu_wbu_dnpc     <= exu_lsu_dnpc;
            lsu_wbu_mem_en   <= (exu_lsu_mem_r != 3'd5) | (exu_lsu_mem_w != 2'b11); // 访存相关标志
            lsu_wbu_mem_addr <= exu_lsu_mem_addr; // 访存地址
        end
    end

`endif

endmodule
