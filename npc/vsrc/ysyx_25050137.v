`define ysyx_25050137_CPU_WIDTH 32
`define ysyx_25050137_PC_WIDTH 32
`define ysyx_25050137_INST_WIDTH 32
`define ysyx_25050137_REG_ADDR 5

`ifdef __ICARUS__
    `define ysyx_25050137_PC_INIT 32'h80000000
`else
    `define ysyx_25050137_PC_INIT 32'h30000000
`endif 

`ifdef VERILATOR_SIM
    import "DPI-C" function void ebreak();
    import "DPI-C" function void difftest_next_step(input byte difftest_check);
    import "DPI-C" function void difftest_skip();
    import "DPI-C" function void reg_return_value(input int gpr_0,input int gpr_1,
    input int gpr_2,input int gpr_3,input int gpr_4,input int gpr_5,
    input int gpr_6,input int gpr_7,input int gpr_8,input int gpr_9,
    input int gpr_10,input int gpr_11,input int gpr_12,input int gpr_13,
    input int gpr_14,input int gpr_15,input int pc,input int csr_reg_0,
    input int csr_reg_1,input int csr_reg_2,input int csr_reg_3);
`endif 


module ysyx_25050137_adder(
    input [31:0]a,
    input [31:0]b,
    output [31:0]out
);

assign out = a + b;

endmodule

module ysyx_25050137_alu_control(
    input [31:0] inst,
    output reg [3:0] alu_op
);
    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;
    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];

    always@(*)begin
        case(opcode)          
            7'b0110111: begin //lui
                alu_op = 4'b0000; //pass b
            end
            7'b0010111: begin //auipc
                alu_op = 4'b0100; //+
            end
            7'b1101111: begin //jal
                alu_op = 4'b0100; //+
            end
            7'b1100111: begin
                case(funct3)
                    3'b000: alu_op = 4'b0100; //+ //jalr
                    default: alu_op = 0;
                endcase
            end
            7'b1100011: begin
                case(funct3)
                    3'b000: alu_op = 4'b0101;//- //beq
                    3'b001: alu_op = 4'b0101;//- //bne
                    3'b100: alu_op = 4'b1010;//s<s //blt
                    3'b101: alu_op = 4'b1010;//s<s //bge
                    3'b110: alu_op = 4'b1001;//u<u //bltu
                    3'b111: alu_op = 4'b1001;//u<u //bgeu
                    default: alu_op = 4'b0101;//- 
                endcase
            end
            7'b0000011: begin //+ //lb lh lw lbu lhu
                case(funct3)
                    3'b000: alu_op = 4'b0100; //+ //lb
                    3'b001: alu_op = 4'b0100; //+ //lh
                    3'b010: alu_op = 4'b0100; //+ //lw
                    3'b100: alu_op = 4'b0100; //+ //lbu
                    3'b101: alu_op = 4'b0100; //+ //lhu
                    default: alu_op = 4'b0100;
                endcase
            end
            7'b0100011: begin
                case(funct3)
                    3'b000: alu_op = 4'b0100; //+ //sb
                    3'b001: alu_op = 4'b0100; //+ //sh
                    3'b010: alu_op = 4'b0100; //+ //sw
                    default: alu_op = 4'b0100;
                endcase
            end
            
            7'b0010011: begin
                case(funct3)
                    3'b000: alu_op = 4'b0100; //+ //addi
                    3'b010: alu_op = 4'b1010; //s<s //slti
                    3'b011: alu_op = 4'b1001; //u<u //sltiu
                    3'b100: alu_op = 4'b0011; //^ //xori
                    3'b110: alu_op = 4'b0010; //| //ori
                    3'b111: alu_op = 4'b0001; //& //andi
                    3'b001: alu_op = 4'b0110; //<< //slli
                    3'b101: begin
                        case(funct7)
                            7'b0000000: alu_op = 4'b0111; //>> //srli
                            7'b0100000: alu_op = 4'b1000; //>> //srai
                            default: alu_op = 4'b0111; //>> //srli
                        endcase
                    end
                    default: alu_op = 0;
                endcase
            end
            7'b0110011: begin
                case(funct3)
                    3'b000: begin
                        case(funct7)
                            7'b0000000: alu_op = 4'b0100;//+ //add
                            7'b0100000: alu_op = 4'b0101;//- //sub
                            default: alu_op = 0;
                        endcase
                    end
                    3'b001: alu_op = 4'b0110; //<< //sll
                    3'b010: alu_op = 4'b1010; //s<s //slt
                    3'b011: alu_op = 4'b1001; //u<u //sltu
                    3'b100: alu_op = 4'b0011; //^ //xor
                    3'b101: begin
                        case(funct7)
                            7'b0000000: alu_op = 4'b0111; //>> //srl
                            7'b0100000: alu_op = 4'b1000; //>> //sra
                            default: alu_op = 0;
                        endcase
                    end
                    3'b110: alu_op = 4'b0010; //| //or
                    3'b111: alu_op = 4'b0001; //& //and
                    default:alu_op = 0;
                endcase
            end
            7'b1110011: begin
                alu_op = 4'b0000;//pass b
            end
            default: alu_op = 0;
        endcase
    end

endmodule

module ysyx_25050137_alu(
    input [31:0]a,
    input [31:0]b,
    input [3:0]op,
    output reg [31:0]alu_result,
    output zero
);

assign zero = ~(| alu_result);

always@(*) begin
    case(op)
        4'b0000: alu_result = b; 
        4'b0001: alu_result = a & b;
        4'b0010: alu_result = a | b;
        4'b0011: alu_result = a ^ b;
        4'b0100: alu_result = a + b;
        4'b0101: alu_result = a - b;
        4'b0110: alu_result = a << b[4:0];
        4'b0111: alu_result = a >> b[4:0];
        4'b1000: alu_result = ($signed(a)) >>> ($signed(b[4:0]));
        4'b1001: alu_result = (a < b) ? 32'd1 : 32'd0;
        4'b1010: alu_result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
        //4'b1011: alu_result = mux_tmp[31:0];
        //4'b1100: alu_result = mux_tmp[63:32];
        
        default: alu_result = b; 
    endcase

end

endmodule

module ysyx_25050137_axi_arbiter (
    input clk,
    input reset,

    // ========== Master A (e.g. IFU) ==========
    // AR
    input  [`ysyx_25050137_CPU_WIDTH-1:0] araddr_i_a,
    input  [3:0]            arid_i_a,
    input  [7:0]            arlen_i_a,
    input  [2:0]            arsize_i_a,
    input  [1:0]            arburst_i_a,
    input                   arvalid_i_a,
    output reg              arready_o_a,
    // R
    output reg [`ysyx_25050137_CPU_WIDTH-1:0] rdata_o_a,
    output reg [1:0]            rresp_o_a,
    output reg                  rlast_o_a,
    output reg [3:0]            rid_o_a,
    output reg                  rvalid_o_a,
    input                       rready_i_a,
    // AW
    input  [`ysyx_25050137_CPU_WIDTH-1:0] awaddr_i_a,
    input  [3:0]            awid_i_a,
    input  [7:0]            awlen_i_a,
    input  [2:0]            awsize_i_a,
    input  [1:0]            awburst_i_a,
    input                   awvalid_i_a,
    output               awready_o_a,
    // W
    input  [`ysyx_25050137_CPU_WIDTH-1:0] wdata_i_a,
    input  [3:0]            wstrb_i_a,
    input                   wlast_i_a,
    input                   wvalid_i_a,
    output               wready_o_a,
    // B
    output  [1:0]        bresp_o_a,
    output  [3:0]        bid_o_a,
    output               bvalid_o_a,
    input                   bready_i_a,

    // ========== Master B (e.g. LSU) ==========
    // AR
    input  [`ysyx_25050137_CPU_WIDTH-1:0] araddr_i_b,
    input  [3:0]            arid_i_b,
    input  [7:0]            arlen_i_b,
    input  [2:0]            arsize_i_b,
    input  [1:0]            arburst_i_b,
    input                   arvalid_i_b,
    output reg              arready_o_b,
    // R
    output reg [`ysyx_25050137_CPU_WIDTH-1:0] rdata_o_b,
    output reg [1:0]            rresp_o_b,
    output reg                  rlast_o_b,
    output reg [3:0]            rid_o_b,
    output reg                  rvalid_o_b,
    input                       rready_i_b,
    // AW
    input  [`ysyx_25050137_CPU_WIDTH-1:0] awaddr_i_b,
    input  [3:0]            awid_i_b,
    input  [7:0]            awlen_i_b,
    input  [2:0]            awsize_i_b,
    input  [1:0]            awburst_i_b,
    input                   awvalid_i_b,
    output               awready_o_b,
    // W
    input  [`ysyx_25050137_CPU_WIDTH-1:0] wdata_i_b,
    input  [3:0]            wstrb_i_b,
    input                   wlast_i_b,
    input                   wvalid_i_b,
    output               wready_o_b,
    // B
    output  [1:0]        bresp_o_b,
    output  [3:0]        bid_o_b,
    output               bvalid_o_b,
    input                   bready_i_b,

    // ========== Slave (Memory) ==========
    // AR
    output [`ysyx_25050137_CPU_WIDTH-1:0] araddr_o,
    output [3:0]            arid_o,
    output [7:0]            arlen_o,
    output [2:0]            arsize_o,
    output [1:0]            arburst_o,
    output                  arvalid_o,
    input                   arready_i,
    // R
    input  [`ysyx_25050137_CPU_WIDTH-1:0] rdata_i,
    input  [1:0]            rresp_i,
    input                   rlast_i,
    input  [3:0]            rid_i,
    input                   rvalid_i,
    output                  rready_o,
    // AW
    output [`ysyx_25050137_CPU_WIDTH-1:0] awaddr_o,
    output [3:0]            awid_o,
    output [7:0]            awlen_o,
    output [2:0]            awsize_o,
    output [1:0]            awburst_o,
    output                  awvalid_o,
    input                   awready_i,
    // W
    output [`ysyx_25050137_CPU_WIDTH-1:0] wdata_o,
    output [3:0]            wstrb_o,
    output                  wlast_o,
    output                  wvalid_o,
    input                   wready_i,
    // B
    input  [1:0]            bresp_i,
    input  [3:0]            bid_i,
    input                   bvalid_i,
    output                  bready_o

);

// ============================================================
// 参数
// ============================================================
localparam MASTER_A = 1'b0;
localparam MASTER_B = 1'b1;

// ============================================================
// AR/R 仲裁内部寄存器
// ============================================================
reg  arb_grant;       // 上一次仲裁结果（用于同时到达时的轮询参考）
reg  arb_locked;      // 仲裁锁：arvalid出现即置1，rlast握手后清0
reg  current_master;  // 本次事务R通道路由目标

// ============================================================
// 关键握手信号
// ============================================================
wire r_last_handshake = rvalid_i & rready_o & rlast_i;  // R通道最后一拍完成

// 任意一方出现arvalid，视为有新请求到来
wire ar_req_appear = arvalid_i_a | arvalid_i_b;

// ============================================================
// 仲裁决策（组合逻辑）
// ============================================================
// 策略：先到先得；同时到达则切换（基于上次 arb_grant 轮转）
// 锁定期间输出维持 arb_grant 不变，由 current_master 接管路由
wire arb_grant_next;
assign arb_grant_next = arb_locked                        ? arb_grant   : // 锁定中，不重新仲裁
                        ( arvalid_i_a & ~arvalid_i_b)     ? MASTER_A    : // 只有A：A先到
                        (~arvalid_i_a &  arvalid_i_b)     ? MASTER_B    : // 只有B：B先到
                        ( arvalid_i_a &  arvalid_i_b)     ? ~arb_grant  : // 同时到达：轮转
                                                             arb_grant;    // 都无请求：保持

// ============================================================
// 仲裁寄存器时序逻辑
// ============================================================
always @(posedge clk or posedge reset) begin
    if (reset) begin
        arb_grant      <= MASTER_A;
        arb_locked     <= 1'b0;
        current_master <= MASTER_A;
    end else begin
        // rlast握手：解锁，下一拍可重新仲裁
        // arvalid出现且当前未锁定：立即锁定并记录仲裁结果
        // 同一拍 rlast 握手 + 新 arvalid：优先解锁，新请求下一拍再仲裁
        if (r_last_handshake) begin
            arb_locked <= 1'b0;
        end else if (!arb_locked & ar_req_appear) begin
            arb_locked     <= 1'b1;
            arb_grant      <= arb_grant_next;   // 更新轮询指针
            current_master <= arb_grant_next;   // 锁定本次事务的路由目标
        end
    end
end

// ============================================================
// AR 通道 MUX → Memory
// 使用 current_master（寄存器）保证锁定后地址信号稳定
// ============================================================
assign araddr_o  = (current_master == MASTER_A) ? araddr_i_a  : araddr_i_b;
assign arid_o    = (current_master == MASTER_A) ? arid_i_a    : arid_i_b;
assign arlen_o   = (current_master == MASTER_A) ? arlen_i_a   : arlen_i_b;
assign arsize_o  = (current_master == MASTER_A) ? arsize_i_a  : arsize_i_b;
assign arburst_o = (current_master == MASTER_A) ? arburst_i_a : arburst_i_b;

// arvalid：只透传被授权 master 的请求
assign arvalid_o = (current_master == MASTER_A) ? arvalid_i_a : arvalid_i_b;

// arready：只反馈给被授权的 master，另一方阻塞等待
always @(*) begin
    arready_o_a = 1'b0;
    arready_o_b = 1'b0;
    if (current_master == MASTER_A)
        arready_o_a = arready_i;
    else
        arready_o_b = arready_i;
end

// ============================================================
// R 通道路由 Memory → 正确的 Master
// ============================================================
assign rready_o = (current_master == MASTER_A) ? rready_i_a : rready_i_b;

always @(*) begin
    // 默认清零，防止 latch
    rdata_o_a  = {`ysyx_25050137_CPU_WIDTH{1'b0}};
    rresp_o_a  = 2'b0;
    rlast_o_a  = 1'b0;
    rid_o_a    = 4'b0;
    rvalid_o_a = 1'b0;
    rdata_o_b  = {`ysyx_25050137_CPU_WIDTH{1'b0}};
    rresp_o_b  = 2'b0;
    rlast_o_b  = 1'b0;
    rid_o_b    = 4'b0;
    rvalid_o_b = 1'b0;

    if (current_master == MASTER_A) begin
        rdata_o_a  = rdata_i;
        rresp_o_a  = rresp_i;
        rlast_o_a  = rlast_i;
        rid_o_a    = rid_i;
        rvalid_o_a = rvalid_i;
    end else begin
        rdata_o_b  = rdata_i;
        rresp_o_b  = rresp_i;
        rlast_o_b  = rlast_i;
        rid_o_b    = rid_i;
        rvalid_o_b = rvalid_i;
    end
end

    assign awaddr_o = awaddr_i_b;
    assign awid_o = awid_i_b;
    assign awlen_o = awlen_i_b;
    assign awsize_o = awsize_i_b;
    assign awburst_o = awburst_i_b;
    assign awvalid_o = awvalid_i_b;
    assign awready_o_b = awready_i;

    assign wdata_o = wdata_i_b;
    assign wstrb_o = wstrb_i_b;
    assign wlast_o = wlast_i_b;
    assign wvalid_o = wvalid_i_b;
    assign wready_o_b = wready_i;

    assign bresp_o_b = bresp_i;
    assign bid_o_b = bid_i;
    assign bvalid_o_b = bvalid_i;
    assign bready_o = bready_i_b;

endmodule

module ysyx_25050137_branch_control(
    input [31:0] pc4,
    input [31:0] pc_new,
    input [2:0] pc_srcs,
    input zero,
    input [31:0] alu_result,
    output reg [31:0] npc
);
    always@(*) begin
        case(pc_srcs)
            3'b000: npc = pc4; //pc=pc+4
            3'b001: npc = pc_new; //pc=pc+imm or pc=rs1+imm
            3'b010: begin //beq
                if(zero==1'b1) npc = pc_new; //sub is zero,equal,jump
                else npc = pc4;
            end
            3'b011: begin //bne
                if(zero==1'b0) npc = pc_new; //sub is not zero,unequal,jump
                else npc = pc4;
            end
            3'b100: begin //blt
                if(alu_result==32'd1) npc = pc_new;
                else npc = pc4;
            end
            3'b101: begin //bge
                if(alu_result==32'd0) npc = pc_new;
                else npc = pc4;
            end
            3'b110: begin //bltu
                if(alu_result==32'd1) npc = pc_new;
                else npc = pc4;
            end
            3'b111: begin //bgeu
                if(alu_result==32'd0) npc = pc_new;
                else npc = pc4;
            end
            default: npc = pc4; //pc=pc+4
        endcase

    end

endmodule



// =============================================================================
// CLINT — area-optimized
//
// Function: 64-bit mtime counter, AXI4 slave interface
//   Read  0x0200_0048 → mtime[31:0]
//   Read  0x0200_004c → mtime[63:32]
//   Write support for mtimecmp if needed (currently no mtimecmp)
//
// Removed: LFSR delay simulator, 5 separate FSMs, all output registers,
//          wdata/wstrb/awaddr buffers
// Registers: time_counter(64) + araddr_lat(32) + state(3) + aw_done/w_done(2) = 101 bits
// Original: ~171 DFF + DFFR → estimated 1,897 area → ~700
// =============================================================================

module ysyx_25050137_clint (
    input clk,
    input reset,

    // AXI AR
    input  [`ysyx_25050137_CPU_WIDTH-1:0] araddr_i,
    input  [3:0]            arid_i,
    input  [7:0]            arlen_i,
    input  [2:0]            arsize_i,
    input  [1:0]            arburst_i,
    input                   arvalid_i,
    output                  arready_o,

    // AXI R
    output [`ysyx_25050137_CPU_WIDTH-1:0] rdata_o,
    output [1:0]            rresp_o,
    output                  rlast_o,
    output [3:0]            rid_o,
    output                  rvalid_o,
    input                   rready_i,

    // AXI AW
    input  [`ysyx_25050137_CPU_WIDTH-1:0] awaddr_i,
    input  [3:0]            awid_i,
    input  [7:0]            awlen_i,
    input  [2:0]            awsize_i,
    input  [1:0]            awburst_i,
    input                   awvalid_i,
    output                  awready_o,

    // AXI W
    input  [`ysyx_25050137_CPU_WIDTH-1:0] wdata_i,
    input  [3:0]            wstrb_i,
    input                   wlast_i,
    input                   wvalid_i,
    output                  wready_o,

    // AXI B
    output [1:0]            bresp_o,
    output [3:0]            bid_o,
    output                  bvalid_o,
    input                   bready_i
);

// =============================================================================
// mtime counter — the only real function of CLINT
// =============================================================================
reg [63:0] time_counter;

always @(posedge clk or posedge reset) begin
    if (reset)
        time_counter <= 64'd0;
    else
        time_counter <= time_counter + 1;
end

// =============================================================================
// State machine
// =============================================================================
localparam [2:0]
    S_IDLE  = 3'd0,
    S_RRESP = 3'd1,   // Read: present R data, wait rready
    S_AW    = 3'd2,   // Write: collect AW+W
    S_BRESP = 3'd3;   // Write: present B response, wait bready

reg [2:0] state;

// Latched read address (only need bit 2 to distinguish hi/lo word)
reg [`ysyx_25050137_CPU_WIDTH-1:0] araddr_lat;

// Track AW/W handshakes (can arrive in any order)
reg aw_done, w_done;

// =============================================================================
// AXI outputs — ALL combinational
// =============================================================================

// AR: accept in IDLE
assign arready_o = (state == S_IDLE) && !awvalid_i;  // read lower priority if simultaneous

// R: respond with time_counter
assign rdata_o  = araddr_lat[2] ? time_counter[63:32] : time_counter[31:0];
assign rvalid_o = (state == S_RRESP);
assign rlast_o  = rvalid_o;
assign rresp_o  = 2'b00;
assign rid_o    = 4'd0;

// AW: accept in IDLE or S_AW when not yet done
assign awready_o = (state == S_IDLE && awvalid_i) ||
                   (state == S_AW && !aw_done);

// W: accept in IDLE or S_AW when not yet done
assign wready_o  = (state == S_IDLE && awvalid_i) ||
                   (state == S_AW && !w_done);

// B: respond after write complete
assign bvalid_o = (state == S_BRESP);
assign bresp_o  = 2'b00;
assign bid_o    = 4'd0;

// =============================================================================
// State transitions
// =============================================================================
always @(posedge clk or posedge reset) begin
    if (reset) begin
        state      <= S_IDLE;
        araddr_lat <= 0;
        aw_done    <= 1'b0;
        w_done     <= 1'b0;
    end else begin
        case (state)

            S_IDLE: begin
                if (awvalid_i) begin
                    // Write request — prioritize over read
                    aw_done <= awready_o && awvalid_i;
                    w_done  <= wready_o  && wvalid_i;
                    if ((awready_o && awvalid_i) && (wready_o && wvalid_i)) begin
                        // Both handshake in same cycle
                        state <= S_BRESP;
                    end else begin
                        state <= S_AW;
                    end
                end else if (arvalid_i) begin
                    // Read request
                    araddr_lat <= araddr_i;
                    state      <= S_RRESP;
                end
            end

            S_RRESP: begin
                if (rvalid_o && rready_i)
                    state <= S_IDLE;
            end

            S_AW: begin
                if (awready_o && awvalid_i)
                    aw_done <= 1'b1;
                if (wready_o && wvalid_i)
                    w_done <= 1'b1;

                // Both channels done
                if ((aw_done || (awready_o && awvalid_i)) &&
                    (w_done  || (wready_o  && wvalid_i)))
                    state <= S_BRESP;
            end

            S_BRESP: begin
                if (bvalid_o && bready_i) begin
                    aw_done <= 1'b0;
                    w_done  <= 1'b0;
                    state   <= S_IDLE;
                end
            end

            default: state <= S_IDLE;

        endcase
    end
end

endmodule

module ysyx_25050137_controler(
    input [31:0] inst,
    output reg a_in_src,
    output reg [1:0] b_in_src,
    output reg reg_write,
    output reg [2:0] pc_srcs,
    output reg adder_a_src,
    output reg MemRead,
    output reg MemWrite,
    output reg [7:0] wmask,
    output reg wb_src,
    output reg [2:0] rmask,
    output reg csr_write,
    output reg adder_out_src,
    output reg csr_wdata_src
);

    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;
    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];

    always@(*)begin
        case(opcode)           
            7'b0110111: begin //lui
                a_in_src = 1'b0; b_in_src = 2'b01; reg_write = 1; pc_srcs = 3'b000;adder_a_src = 1'b0;
                MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                adder_out_src = 1'b0; csr_wdata_src = 1'b0;
            end 
            7'b0010111: begin //auipc
                a_in_src = 1'b1; b_in_src = 2'b01; reg_write = 1; pc_srcs = 3'b000;adder_a_src = 1'b0;
                MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                adder_out_src = 1'b0; csr_wdata_src = 1'b0;
            end
            7'b1101111: begin //jal
                a_in_src = 1'b1; b_in_src = 2'b10; reg_write = 1; pc_srcs = 3'b001;adder_a_src = 1'b0;
                MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                adder_out_src = 1'b0; csr_wdata_src = 1'b0;
            end
            7'b1100111: begin
                case(funct3)
                    3'b000: begin //jalr
                        a_in_src = 1'b1; b_in_src = 2'b10; reg_write = 1; pc_srcs = 3'b001; 
                        adder_a_src = 1'b1; MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0;
                        rmask = 0; csr_write = 1'b0; adder_out_src = 1'b0; csr_wdata_src = 1'b0;
                    end //jalr
                    default: begin 
                        a_in_src = 1'b0; b_in_src = 2'b00; reg_write = 0; pc_srcs = 3'b000; adder_a_src = 1'b0;
                        MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                        adder_out_src = 1'b0; csr_wdata_src = 1'b0;
                    end
                endcase
            end
            7'b1100011: begin
                a_in_src = 1'b0; //choose rs1
                b_in_src = 2'b00; //choose rs2
                reg_write = 1'b0; //not write regfiles 
                adder_a_src = 1'b0;//choose pc
                MemRead = 1'b0; //not read mem
                MemWrite = 1'b0; //not write mem
                wmask = 0; //do not care 
                wb_src=1'b0; //do not care 
                rmask = 3'b000; //do not care 
                csr_write = 1'b0;
                adder_out_src = 1'b0; 
                csr_wdata_src = 1'b0;
                case(funct3)
                    3'b000: pc_srcs = 3'b010; //beq
                    3'b001: pc_srcs = 3'b011; //bne 
                    3'b100: pc_srcs = 3'b100; //blt 
                    3'b101: pc_srcs = 3'b101; //bge
                    3'b110: pc_srcs = 3'b110; //bltu
                    3'b111: pc_srcs = 3'b111; //bgeu
                    default: pc_srcs = 3'b000;
                endcase
            end
            7'b0000011:begin //lb lh lw lbu lhu
                a_in_src = 1'b0; //choose rs1
                b_in_src = 2'b01; //choose imm
                reg_write = 1'b1; //write regfiles 
                pc_srcs = 3'b000; //pc=pc+4
                adder_a_src = 1'b0;//do not care 
                MemRead = 1'b1; //read mem
                MemWrite = 1'b0; //not write mem
                wmask = 8'h0f; //do not care 
                wb_src=1'b1; //wb data is mem_data
                csr_write = 1'b0;
                adder_out_src = 1'b0; 
                csr_wdata_src = 1'b0;
                case(funct3)
                    3'b000: rmask = 3'b011; //lb
                    3'b001: rmask = 3'b001; //lh
                    3'b010: rmask = 3'b000; //lw 32 pass //lw
                    3'b100: rmask = 3'b100; //lbu
                    3'b101: rmask = 3'b010; //lhu
                    default: rmask = 0;
                endcase
            end
            7'b0100011:begin //sb sh sw
                a_in_src = 1'b0; //choose rs1
                b_in_src = 2'b01; //choose imm
                reg_write = 1'b0; //no need to write regfiles 
                pc_srcs = 3'b000; //pc=pc+4
                adder_a_src = 1'b0;//do not care 
                MemRead = 1'b0; //not read mem
                MemWrite = 1'b1; //write mem
                wb_src=1'b0; //wb data is default
                rmask = 0; //do not care 
                csr_write = 1'b0;
                adder_out_src = 1'b0; 
                csr_wdata_src = 1'b0;
                case(funct3)
                    3'b000: wmask = 8'h01; //sb //1 byte can write
                    3'b001: wmask = 8'h03; //sh //2 byte can write
                    3'b010: wmask = 8'h0f; //sw //4 byte can write
                    default: wmask = 0;
                endcase
            end
            
            7'b0010011: begin  //addi slti sltiu xori ori andi slli srli srai                   
                a_in_src = 1'b0; //choose rs1
                b_in_src = 2'b01; //choose imm
                reg_write = 1; //write regfiles 
                pc_srcs = 3'b000; //pc=pc+4
                adder_a_src = 1'b0; //do not care 
                MemRead = 1'b0; MemWrite = 1'b0; //not read mem //not write mem
                wmask = 0; rmask = 0; //do not care 
                wb_src=1'b0; //wb data is alu_result
                csr_write = 1'b0;
                adder_out_src = 1'b0; 
                csr_wdata_src = 1'b0;
            end
            7'b0110011:begin //add sub sll slt sltu xor srl sra or and
                a_in_src = 1'b0; //choose rs1
                b_in_src = 2'b00; //choose rs2
                reg_write = 1'b1; //write regfiles 
                pc_srcs = 3'b000; //pc=pc+4
                adder_a_src = 1'b0;//do not care 
                MemRead = 1'b0; //not read mem
                MemWrite = 1'b0; //not write mem
                wmask = 8'h0f; //do not care 
                wb_src=1'b0; //wb data is alu_result
                rmask = 3'b000; //do not care 
                csr_write = 1'b0;
                adder_out_src = 1'b0; 
                csr_wdata_src = 1'b0;
            end
            7'b1110011:begin
                case(funct3)
                    3'b000: begin //ecall mret
                        a_in_src = 1'b0; //do not care 
                        b_in_src = 2'b11; //do not care 
                        reg_write = 1'b0; //no need to write regfiles 
                        pc_srcs = 3'b001; //pc=pc_new
                        adder_a_src = 1'b0;//do not care 
                        MemRead = 1'b0; //not read mem
                        MemWrite = 1'b0; //not write mem
                        wmask = 8'h0f; //do not care 
                        wb_src=1'b0; //do not care 
                        rmask = 3'b000; //do not care 
                        csr_write = 1'b0; //do not care 
                        adder_out_src = 1'b1; //choose csr_rdata
                        csr_wdata_src = 1'b0; //do not care 
                    end
                    3'b001: begin //csrrw
                        a_in_src = 1'b0; //choose rs1
                        b_in_src = 2'b11; //choose csr_rdata
                        reg_write = 1'b1; //write regfiles 
                        pc_srcs = 3'b000; //pc=pc+4
                        adder_a_src = 1'b0;//do not care 
                        MemRead = 1'b0; //not read mem
                        MemWrite = 1'b0; //not write mem
                        wmask = 8'h0f; //do not care 
                        wb_src=1'b0; //wb data is alu_result
                        rmask = 3'b000; //do not care 
                        csr_write = 1'b1; //write csr
                        adder_out_src = 1'b0; //do not care
                        csr_wdata_src = 1'b0; //choose rs1
                    end
                    3'b010: begin //csrrs
                        a_in_src = 1'b0; //choose rs1
                        b_in_src = 2'b11; //choose csr_rdata
                        reg_write = 1'b1; //write regfiles 
                        pc_srcs = 3'b000; //pc=pc+4
                        adder_a_src = 1'b0;//do not care 
                        MemRead = 1'b0; //not read mem
                        MemWrite = 1'b0; //not write mem
                        wmask = 8'h0f; //do not care 
                        wb_src=1'b0; //wb data is alu_result
                        rmask = 3'b000; //do not care 
                        csr_write = 1'b1; //write csr
                        adder_out_src = 1'b0; //do not care
                        csr_wdata_src = 1'b1; //choose csr_wdata | rs1
                    end
                    default: begin 
                        a_in_src = 1'b0; b_in_src = 2'b00; reg_write = 0; pc_srcs = 3'b000; adder_a_src = 1'b0;
                        MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                        adder_out_src = 1'b0; csr_wdata_src = 1'b0;
                    end
                endcase
            end
            default: begin 
                a_in_src = 1'b0; b_in_src = 2'b00; reg_write = 0; pc_srcs = 3'b000; adder_a_src = 1'b0;
                MemRead = 1'b0; MemWrite = 1'b0; wmask = 0; wb_src=1'b0; rmask = 0; csr_write = 1'b0;
                adder_out_src = 1'b0; csr_wdata_src = 1'b0;
            end
        endcase
    end


endmodule

module ysyx_25050137_csr(
    input clk,
    input [31:0] inst,
    output reg [2:0] raddr_csr,
    output reg [1:0] waddr_csr,
    output reg ecall    
    
);
    wire [6:0] opcode;
    wire [2:0] funct3;

    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];

    always@(*) begin
        waddr_csr = 2'b00;
        case (opcode)
            7'b1110011:begin
                case (funct3)
                    3'b000:begin 
                        if(inst==32'h00000073) begin //ecall
                            ecall = 1'b1;
                            //csr_mstatus[7] <= csr_mstatus[3];//MPIE = MIE
                            //csr_mstatus[3] <= 1'b0;//MIE set 0
                            //csr_mstatus[12:11] <= 2'b11;//MPP=11
                        end
                        else begin 
                            ecall = 1'b0;
                            //csr_mstatus[3] <= csr_mstatus[7]; //MIE = MPIE
                            //csr_mstatus[7] <= 1'b0;//MPIE set 0
                        end
                    end
                    3'b001, 3'b010: begin //csrrw, csrrs
                        ecall = 1'b0;
                        case (inst[31:20])
                            12'h300:waddr_csr = 2'b00;
                            12'h305:waddr_csr = 2'b01;
                            12'h341:waddr_csr = 2'b10;
                            12'h342:waddr_csr = 2'b11;
                            default:waddr_csr = 2'b00;
                        endcase
                    end
                    default:ecall = 1'b0;
                endcase
            end
            default:ecall = 1'b0;
        endcase
    end

    always@(*) begin
        case (opcode)
            7'b1110011:begin
                case (funct3)
                    3'b000:begin 
                        if(inst==32'h00000073) raddr_csr = 3'b001; //ecall csr_mtvec
                        else if(inst==32'h30200073) raddr_csr = 3'b010; //mret csr_mepc
                        else raddr_csr = 0;
                    end
                    3'b001,3'b010: begin //csrrw, csrrs
                        case (inst[31:20])
                            12'hf11:raddr_csr = 3'b100; //csr_mvendorid
                            12'hf12:raddr_csr = 3'b101; //csr_marchid
                            12'h300:raddr_csr = 3'b000; //csr_mstatus
                            12'h305:raddr_csr = 3'b001; //csr_mtvec
                            12'h341:raddr_csr = 3'b010; //csr_mepc
                            12'h342:raddr_csr = 3'b011; //csr_mcause
                            default:raddr_csr = 0;
                        endcase
                    end
                    default:raddr_csr = 0;
                endcase
            end
            default:raddr_csr = 0;
        endcase
    end

endmodule



// =============================================================================
// EXU — area-optimized
//
// Removed:
//   - a_in_src, b_in_src, pc_srcs, adder_a_src, adder_out_src, alu_op (13 bits)
//     → These are EXU-internal control signals consumed in the same cycle.
//       Feed _i inputs directly to submodules.
//   - pc_o duplicate (32 bits) → assign pc_o = pc
//   - npc_flag, exu_valid_o, exu_ready_o, npc_valid, rd_exu_valid (5 bits)
//     → derive from state
//   - S_RECEIVE state eliminated — computation is single-cycle, results
//     available on the cycle after latch, output immediately in S_OUT.
//
// Estimated: 227 DFF → ~175 DFF, plus significant MUX/BUF reduction
// =============================================================================

module ysyx_25050137_exu (
    input clk,
    input reset,
    input reset_ifu,

    // IDU → EXU
    input [`ysyx_25050137_PC_WIDTH-1:0]   pc_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  rs1_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  rs2_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  imm_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  csr_rdata_i,
    input                   a_in_src_i,
    input [1:0]             b_in_src_i,
    input [2:0]             pc_srcs_i,
    input                   adder_a_src_i,
    input                   adder_out_src_i,
    input [3:0]             alu_op_i,

    // IDU → EXU → LSU/WBU pass-through
    input                   MemRead_i,
    input                   MemWrite_i,
    input [3:0]             wmask_i,
    input [2:0]             rmask_i,
    input                   wb_src_i,
    input                   csr_write_i,
    input                   csr_wdata_src_i,
    input                   reg_write_i,
    input [`ysyx_25050137_REG_ADDR-1:0]   waddr_i,
    input                   ecall_i,
    input [1:0]             waddr_csr_i,

    input                   exu_valid_i,
    output                  exu_ready_o,

    // EXU → LSU
    output [`ysyx_25050137_CPU_WIDTH-1:0] alu_result_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] rs1_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] rs2_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_l_rs1_o,
    output [`ysyx_25050137_PC_WIDTH-1:0]  npc_o,
    output reg              MemRead_o,
    output reg              MemWrite_o,
    output reg [3:0]        wmask_o,
    output reg [2:0]        rmask_o,
    output reg              wb_src_o,
    output reg              csr_write_o,
    output reg              csr_wdata_src_o,
    output reg              reg_write_o,
    output reg [`ysyx_25050137_REG_ADDR-1:0] waddr_o,
    output                  ecall_o,
    output [1:0]            waddr_csr_o,

    output                  exu_valid_o,
    input                   exu_ready_i,

    output                  npc_valid,
    output                  rd_exu_valid,

    output [`ysyx_25050137_CPU_WIDTH-1:0] pc_o
);

// =============================================================================
// State: only IDLE and OUT
// =============================================================================
localparam S_IDLE = 1'b0,
           S_OUT  = 1'b1;

reg state;

// =============================================================================
// Pipeline registers — only data that must survive across cycles
// =============================================================================
reg [`ysyx_25050137_PC_WIDTH-1:0]   pc;
reg [`ysyx_25050137_CPU_WIDTH-1:0]  rs1, rs2, imm, csr_rdata;

// Pass-through pipeline control (latched at handshake, held until LSU accepts)
reg                   ecall_lat;
reg [1:0]             waddr_csr_lat;

// =============================================================================
// EXU-internal control: NOT registered — use _i inputs directly
// The key insight: these signals are only consumed by the combinational
// submodules (mux/alu/adder/branch) within EXU. Since the data operands
// (pc, rs1, rs2, imm, csr_rdata) are latched and stable during S_OUT,
// we need the control signals to also be stable. So we latch them too,
// but as a MINIMAL set.
// =============================================================================
reg                   a_in_src_lat;
reg [1:0]             b_in_src_lat;
reg [2:0]             pc_srcs_lat;
reg                   adder_a_src_lat;
reg                   adder_out_src_lat;
reg [3:0]             alu_op_lat;

wire [`ysyx_25050137_CPU_WIDTH-1:0] a_in, b_in, a_out, add_out, pc_new, alu_result;
wire [`ysyx_25050137_PC_WIDTH-1:0]  npc;
wire                  zero;

// =============================================================================
// Combinational outputs from state
// =============================================================================
assign exu_ready_o  = (state == S_IDLE);
assign exu_valid_o  = (state == S_OUT);
assign npc_valid    = (state == S_OUT);
assign rd_exu_valid = (state == S_OUT);

// Data outputs
assign alu_result_o       = alu_result;
assign rs1_o              = rs1;
assign rs2_o              = rs2;
assign csr_rdata_l_rs1_o  = csr_rdata | rs1;
assign npc_o              = npc;
assign pc_o               = pc;   // No duplicate register!
assign ecall_o            = ecall_lat;
assign waddr_csr_o        = waddr_csr_lat;

// =============================================================================
// Submodule interconnect (all combinational)
// =============================================================================


ysyx_25050137_mux21 Adder_A_Src (
    .d0  (pc),
    .d1  (rs1),
    .sel (adder_a_src_lat),
    .out (a_out)
);

ysyx_25050137_adder Adder (
    .a   (a_out),
    .b   (imm),
    .out (add_out)
);

ysyx_25050137_mux21 Adder_Out (
    .d0  (add_out),
    .d1  (csr_rdata),
    .sel (adder_out_src_lat),
    .out (pc_new)
);

ysyx_25050137_branch_control Branch_Control (
    .pc4        (pc + 4),
    .pc_new     (pc_new),
    .pc_srcs    (pc_srcs_lat),
    .zero       (zero),
    .alu_result (alu_result),
    .npc        (npc)
);

ysyx_25050137_mux21 ALU_A_Src (
    .d0  (rs1),
    .d1  (pc),
    .sel (a_in_src_lat),
    .out (a_in)
);

ysyx_25050137_mux41 ALU_B_Src (
    .d0  (rs2),
    .d1  (imm),
    .d2  (32'd4),
    .d3  (csr_rdata),
    .sel (b_in_src_lat),
    .out (b_in)
);

ysyx_25050137_alu ALU (
    .a          (a_in),
    .b          (b_in),
    .op         (alu_op_lat),
    .alu_result (alu_result),
    .zero       (zero)
);

// =============================================================================
// State machine
// =============================================================================
always @(posedge clk or posedge reset) begin
    if (reset) begin
        state <= S_IDLE;
        //pc <= `ysyx_25050137_PC_INIT;
    end else begin
        case (state)

            S_IDLE: begin
                if (exu_valid_i && exu_ready_o) begin
                    // Latch data operands
                    pc        <= pc_i;
                    rs1       <= rs1_i;
                    rs2       <= rs2_i;
                    imm       <= imm_i;
                    csr_rdata <= csr_rdata_i;

                    // Latch control (minimal — for submodule muxes)
                    a_in_src_lat     <= a_in_src_i;
                    b_in_src_lat     <= b_in_src_i;
                    pc_srcs_lat      <= pc_srcs_i;
                    adder_a_src_lat  <= adder_a_src_i;
                    adder_out_src_lat <= adder_out_src_i;
                    alu_op_lat       <= alu_op_i;

                    // Latch pass-through to LSU
                    MemRead_o       <= MemRead_i;
                    MemWrite_o      <= MemWrite_i;
                    wmask_o         <= wmask_i;
                    rmask_o         <= rmask_i;
                    wb_src_o        <= wb_src_i;
                    csr_write_o     <= csr_write_i;
                    csr_wdata_src_o <= csr_wdata_src_i;
                    reg_write_o     <= reg_write_i;
                    waddr_o         <= waddr_i;
                    ecall_lat       <= ecall_i;
                    waddr_csr_lat   <= waddr_csr_i;

                    state <= S_OUT;
                end
            end

            S_OUT: begin
                if (exu_valid_o && exu_ready_i)
                    state <= S_IDLE;
            end

            default: state <= S_IDLE;

        endcase
    end
end

endmodule

module ysyx_25050137_icache #(
    parameter DATA_WIDTH  = 32,
    parameter BLOCK_SIZE  = 4,
    parameter NUM_BLOCKS  = 2,
    parameter ADDR_WIDTH  = 32
) (
    input clk,
    input reset,

    // CPU side (AR)
    input  [DATA_WIDTH-1:0] cpu_araddr_i,
    input  [3:0]            cpu_arid_i,
    input  [7:0]            cpu_arlen_i,
    input  [2:0]            cpu_arsize_i,
    input  [1:0]            cpu_arburst_i,
    input                   cpu_arvalid_i,
    output                  cpu_arready_o,

    // CPU side (R)
    output [DATA_WIDTH-1:0] cpu_rdata_o,
    output [1:0]            cpu_rresp_o,
    output                  cpu_rlast_o,
    output [3:0]            cpu_rid_o,
    output                  cpu_rvalid_o,
    input                   cpu_rready_i,

    // Memory side (AR)
    output [DATA_WIDTH-1:0] mem_araddr_o,
    output [3:0]            mem_arid_o,
    output [7:0]            mem_arlen_o,
    output [2:0]            mem_arsize_o,
    output [1:0]            mem_arburst_o,
    output                  mem_arvalid_o,
    input                   mem_arready_i,

    // Memory side (R)
    input  [DATA_WIDTH-1:0] mem_rdata_i,
    input  [1:0]            mem_rresp_i,
    input                   mem_rlast_i,
    input  [3:0]            mem_rid_i,
    input                   mem_rvalid_i,
    output                  mem_rready_o,

    input                   fencei
);

// =============================================================================
// Parameters
// =============================================================================
localparam BLOCK_WORDS  = BLOCK_SIZE / (DATA_WIDTH / 8);
localparam OFFSET_BITS  = $clog2(BLOCK_SIZE);
localparam INDEX_BITS   = $clog2(NUM_BLOCKS);
localparam TAG_BITS     = ADDR_WIDTH - OFFSET_BITS - INDEX_BITS;
localparam COUNTER_SIZE = BLOCK_SIZE / 4;
localparam CNT_BITS     = (COUNTER_SIZE <= 1) ? 1 : $clog2(COUNTER_SIZE);

// =============================================================================
// Cache storage
//   - data_array & tag_array: NO RESET (use plain DFF, not DFFR)
//     Only valid_array needs reset — valid=0 means the line is invalid,
//     so garbage in tag/data doesn't matter.
//   - fencei: only clear valid bits, not tag/data
// =============================================================================
reg [DATA_WIDTH*COUNTER_SIZE-1:0] data_array [0:NUM_BLOCKS-1];  // NO reset
reg [TAG_BITS-1:0]                tag_array  [0:NUM_BLOCKS-1];  // NO reset
reg                               valid_array[0:NUM_BLOCKS-1];  // NEEDS reset

// =============================================================================
// State encoding
// =============================================================================
localparam [2:0]
    S_IDLE  = 3'd0,  // Accept CPU AR request
    S_CHECK = 3'd1,  // Compare tag, hit or miss?
    S_AR    = 3'd2,  // Send memory AR, wait arready
    S_MEM   = 3'd3,  // Receive memory R data (burst fill)
    S_RESP  = 3'd4;  // Return data to CPU

reg [2:0] state;

// =============================================================================
// Internal registers — minimal set
// =============================================================================
reg [ADDR_WIDTH-1:0]  cpu_addr;                 // Latched request address
reg [CNT_BITS-1:0]    burst_cnt;                // Burst word counter (tiny!)

// =============================================================================
// Address decomposition (combinational from latched cpu_addr)
// =============================================================================
wire [TAG_BITS-1:0]    req_tag    = cpu_addr[ADDR_WIDTH-1 : ADDR_WIDTH-TAG_BITS];
wire [INDEX_BITS-1:0]  req_index  = cpu_addr[OFFSET_BITS+INDEX_BITS-1 : OFFSET_BITS];
wire [OFFSET_BITS-1:0] req_offset = cpu_addr[OFFSET_BITS-1 : 0];

// Hit detection
wire cache_hit = valid_array[req_index] && (tag_array[req_index] === req_tag);

// =============================================================================
// ALL outputs are combinational — no output registers!
// =============================================================================

// CPU AR channel
assign cpu_arready_o = (state == S_IDLE);

// CPU R channel — read directly from data_array
assign cpu_rdata_o  = data_array[req_index][req_offset*8 +: DATA_WIDTH];
assign cpu_rvalid_o = (state == S_CHECK && cache_hit) ||
                      (state == S_RESP);
assign cpu_rlast_o  = cpu_rvalid_o;
assign cpu_rresp_o  = 2'b00;
assign cpu_rid_o    = 4'd0;

// Memory AR channel — address aligned to block boundary
assign mem_araddr_o  = {cpu_addr[ADDR_WIDTH-1:OFFSET_BITS], {OFFSET_BITS{1'b0}}};
assign mem_arvalid_o = (state == S_AR);
assign mem_rready_o  = (state == S_MEM);

// Memory AR fixed parameters
assign mem_arid_o    = 4'd0;
assign mem_arsize_o  = 3'b010;
generate
    if (COUNTER_SIZE > 1) begin : g_burst
        assign mem_arlen_o   = COUNTER_SIZE - 1;
        assign mem_arburst_o = 2'b01;  // INCR
    end else begin : g_single
        assign mem_arlen_o   = 8'd0;
        assign mem_arburst_o = 2'b00;  // FIXED
    end
endgenerate

// =============================================================================
// State machine + cache update
// =============================================================================
integer i;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        state     <= S_IDLE;
        burst_cnt <= 0;
        cpu_addr <= 0;
        for (i = 0; i < NUM_BLOCKS; i = i + 1) begin
            valid_array[i] <= 1'b0;
        end
        // NOTE: tag_array and data_array are NOT reset — saves DFFR → DFF
    end else begin

        // fencei: invalidate all lines (only valid bits, not tag/data)
        if (fencei) begin
            state <= S_IDLE;
            for (i = 0; i < NUM_BLOCKS; i = i + 1)
                valid_array[i] <= 1'b0;
        end

        case (state)

            S_IDLE: begin
                if (cpu_arvalid_i && cpu_arready_o) begin
                    cpu_addr  <= cpu_araddr_i;
                    state     <= S_CHECK;
                end
            end

            S_CHECK: begin
                if (cache_hit) begin
                    // Hit — data is already on cpu_rdata_o combinationally
                    if (cpu_rready_i)
                        state <= S_IDLE;
                    // else stay in S_CHECK until cpu_rready_i
                end else begin
                    // Miss — go fetch from memory
                    burst_cnt <= 0;
                    state     <= S_AR;
                end
            end

            S_AR: begin
                if (mem_arvalid_o && mem_arready_i)
                    state <= S_MEM;
            end

            S_MEM: begin
                if (mem_rvalid_i && mem_rready_o) begin
                    // Write incoming word into data array
                    data_array[req_index][burst_cnt * DATA_WIDTH +: DATA_WIDTH] <= mem_rdata_i;
                    tag_array[req_index]  <= req_tag;
                    valid_array[req_index] <= 1'b1;

                    if (mem_rlast_i) begin
                        state <= S_RESP;
                    end else begin
                        burst_cnt <= burst_cnt + 1;
                    end
                end
            end

            S_RESP: begin
                // Return filled data to CPU
                if (cpu_rready_i)
                    state <= S_IDLE;
            end

            default: state <= S_IDLE;

        endcase
    end
end

endmodule



module ysyx_25050137_idu(
    input clk,
    input reset,
    input reset_ifu,
    //regfiles
    output [`ysyx_25050137_REG_ADDR-1:0] raddr1,
    output [`ysyx_25050137_REG_ADDR-1:0] raddr2,
    input [`ysyx_25050137_CPU_WIDTH-1:0] rdata1,
    input [`ysyx_25050137_CPU_WIDTH-1:0] rdata2,

    output [2:0] raddr_csr,
    input [`ysyx_25050137_CPU_WIDTH-1:0] rdata_csr,

    //ifu to idu
    input [`ysyx_25050137_PC_WIDTH-1:0] pc_i,
    input [`ysyx_25050137_INST_WIDTH-1:0] inst_i,
    input idu_valid_i,
    output reg idu_ready_o,
    //idu to exu
    output [`ysyx_25050137_PC_WIDTH-1:0] pc_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] rs1_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] rs2_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] imm_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_o,
    output a_in_src_o,
    output [1:0] b_in_src_o,
    output [2:0] pc_srcs_o,
    output adder_a_src_o,
    output adder_out_src_o,
    output [3:0] alu_op,
    //idu to exu to lsu or wbu
    output MemRead_o,
    output MemWrite_o,
    output [3:0] wmask_o,
    output [2:0] rmask_o,
    output wb_src_o,
    output csr_write_o,
    output csr_wdata_src_o,
    output reg_write_o,
    output [`ysyx_25050137_REG_ADDR-1:0] waddr_o,
    output ecall_o,
    output [1:0] waddr_csr_o,

    output reg idu_valid_o,
    input idu_ready_i,

    output reg fencei,

    // ======== Forwarding接口 (新增/修改) ========
    // EXU级前递
    input [4:0]             exu_rd,
    input                   exu_rd_valid,
    input                   exu_reg_write,    // 新增: EXU级是否写寄存器
    input                   exu_MemRead,      // 新增: EXU级是否为Load指令 (load-use需要stall)
    input [`ysyx_25050137_CPU_WIDTH-1:0]  exu_fwd_data,     // 新增: EXU级前递数据 (ALU结果)

    // LSU级前递
    input [4:0]             lsu_rd,
    input                   lsu_rd_valid,
    input                   lsu_reg_write,    // 新增: LSU级是否写寄存器
    input [`ysyx_25050137_CPU_WIDTH-1:0]  lsu_fwd_data,     // 新增: LSU级前递数据 (ALU结果或Mem读取结果)

    // WBU级前递
    input [4:0]             wbu_rd,
    input                   wbu_rd_valid,
    input                   wbu_reg_write,    // 新增: WBU级是否写寄存器
    input [`ysyx_25050137_CPU_WIDTH-1:0]  wbu_fwd_data      // 新增: WBU级前递数据 (最终写回数据)
);

    reg [`ysyx_25050137_PC_WIDTH-1:0] pc;
    reg [`ysyx_25050137_INST_WIDTH-1:0] inst;

    wire [6:0] opcode;
    wire ecall;
    wire [1:0] waddr_csr;

    assign pc_o = pc;
    assign waddr_o = inst[11:7];
    assign raddr1 = inst[19:15];
    assign raddr2 = inst[24:20];
    assign opcode = inst[6:0];
    
    assign csr_rdata_o = rdata_csr;
    assign ecall_o = ecall;
    assign waddr_csr_o = waddr_csr;

    wire [7:0] wmask_tmp;
    assign wmask_o = wmask_tmp[3:0];

    // ======== 指令类型解码 ========
    wire opcode_r, opcode_i, opcode_s, opcode_sb, opcode_u, opcode_uj;

    assign opcode_r  = (opcode == 7'b0110011);
    assign opcode_i  = (opcode == 7'b0010011 || opcode == 7'b0000011 || opcode == 7'b1100111);
    assign opcode_s  = (opcode == 7'b0100011);
    assign opcode_sb = (opcode == 7'b1100011);
    assign opcode_u  = (opcode == 7'b0110111 || opcode == 7'b0010111);
    assign opcode_uj = (opcode == 7'b1101111);

    // ======== 判断当前指令是否使用rs1/rs2 ========
    wire use_rs1, use_rs2;
    // R/I/S/SB/JALR 使用 rs1;  U/UJ 不使用 rs1
    assign use_rs1 = opcode_r | opcode_i | opcode_s | opcode_sb;
    // R/S/SB 使用 rs2;  I/U/UJ 不使用 rs2
    assign use_rs2 = opcode_r | opcode_s | opcode_sb;

    // ======== Forwarding MUX for rs1 ========
    // 优先级: EXU > LSU > WBU > regfile
    // 如果EXU级是load指令且有rs1依赖, 必须stall, 不能前递
    reg [`ysyx_25050137_CPU_WIDTH-1:0] rs1_forwarded;
    reg rs1_fwd_from_exu, rs1_fwd_from_lsu, rs1_fwd_from_wbu;

    always @(*) begin
        rs1_fwd_from_exu = use_rs1 && (raddr1 != 5'd0) && (raddr1 == exu_rd) && exu_reg_write && exu_rd_valid;
        rs1_fwd_from_lsu = use_rs1 && (raddr1 != 5'd0) && (raddr1 == lsu_rd) && lsu_reg_write && lsu_rd_valid;
        rs1_fwd_from_wbu = use_rs1 && (raddr1 != 5'd0) && (raddr1 == wbu_rd) && wbu_reg_write && wbu_rd_valid;
    end

    always @(*) begin
        if (rs1_fwd_from_exu && !exu_MemRead)
            rs1_forwarded = exu_fwd_data;      // EXU级ALU结果前递
        else if (rs1_fwd_from_lsu)
            rs1_forwarded = lsu_fwd_data;       // LSU级结果前递 (含memory读取)
        else if (rs1_fwd_from_wbu)
            rs1_forwarded = wbu_fwd_data;       // WBU级结果前递
        else
            rs1_forwarded = rdata1;             // 无冒险, 直接读寄存器堆
    end

    // ======== Forwarding MUX for rs2 ========
    reg [`ysyx_25050137_CPU_WIDTH-1:0] rs2_forwarded;
    reg rs2_fwd_from_exu, rs2_fwd_from_lsu, rs2_fwd_from_wbu;

    always @(*) begin
        rs2_fwd_from_exu = use_rs2 && (raddr2 != 5'd0) && (raddr2 == exu_rd) && exu_reg_write && exu_rd_valid;
        rs2_fwd_from_lsu = use_rs2 && (raddr2 != 5'd0) && (raddr2 == lsu_rd) && lsu_reg_write && lsu_rd_valid;
        rs2_fwd_from_wbu = use_rs2 && (raddr2 != 5'd0) && (raddr2 == wbu_rd) && wbu_reg_write && wbu_rd_valid;
    end

    always @(*) begin
        if (rs2_fwd_from_exu && !exu_MemRead)
            rs2_forwarded = exu_fwd_data;
        else if (rs2_fwd_from_lsu)
            rs2_forwarded = lsu_fwd_data;
        else if (rs2_fwd_from_wbu)
            rs2_forwarded = wbu_fwd_data;
        else
            rs2_forwarded = rdata2;
    end

    // ======== 输出前递后的rs1/rs2 ========
    assign rs1_o = rs1_forwarded;
    assign rs2_o = rs2_forwarded;

    // ======== Load-Use Hazard 检测 ========
    // 只有EXU级是Load指令且有数据依赖时才需要stall (1个周期)
    // LSU/WBU级的load结果已经可用, 不需要stall
    wire load_use_hazard;
    assign load_use_hazard = exu_MemRead && exu_reg_write && (
        (use_rs1 && (raddr1 != 5'd0) && (raddr1 == exu_rd)) ||
        (use_rs2 && (raddr2 != 5'd0) && (raddr2 == exu_rd))
    ) &&(exu_rd_valid || lsu_rd_valid || wbu_rd_valid);

    // ======== 状态机 ========
    localparam S_IDLE = 2'b00, S_RECEIVE = 2'b01, S_SEND = 2'b10;

    reg [1:0] current_state, next_state;
    reg flag;

    // ======== RAW冒险 (仅load-use需要stall, 其余通过forwarding解决) ========
    wire isRAW;
    assign isRAW = load_use_hazard && (current_state == S_RECEIVE);

    // ======== 子模块实例化 ========
    ysyx_25050137_controler Controler(
        .inst(inst),
        .a_in_src(a_in_src_o),
        .b_in_src(b_in_src_o),
        .reg_write(reg_write_o),
        .adder_a_src(adder_a_src_o),
        .pc_srcs(pc_srcs_o),
        .MemRead(MemRead_o),
        .MemWrite(MemWrite_o),
        .wmask(wmask_tmp),
        .wb_src(wb_src_o),
        .rmask(rmask_o),
        .csr_write(csr_write_o),
        .adder_out_src(adder_out_src_o),
        .csr_wdata_src(csr_wdata_src_o)
    );

    ysyx_25050137_sext SEXT (
        .inst(inst),
        .data(imm_o)
    );

    ysyx_25050137_csr CSR(
        .clk(clk),
        .inst(inst),
        .raddr_csr(raddr_csr),
        .waddr_csr(waddr_csr),
        .ecall(ecall)
    );
    
    ysyx_25050137_alu_control ALU_Control(
        .inst(inst),
        .alu_op(alu_op)
    );

    
    reg flag_fencei;
    always @(*) begin
        case(current_state)
            S_IDLE: begin
                if (idu_valid_i == 1 && idu_ready_o == 1)
                    next_state = S_RECEIVE;
                else
                    next_state = current_state;
            end
            
            S_RECEIVE: begin
                if (idu_valid_o == 1 && idu_ready_i == 1)
                    next_state = S_SEND;
                else
                    next_state = current_state;
            end
            
            S_SEND: begin
                next_state = S_IDLE;
            end
            
            default: next_state = current_state;
        endcase
    end

    always @(posedge clk or posedge reset) begin        
        if (reset) begin
            current_state <= S_IDLE;
            idu_valid_o <= 0;
            idu_ready_o <= 0;
            fencei <= 0;
            inst <= 32'h00000013;  // NOP (addi x0, x0, 0)
        end else begin
            if(reset_ifu == 1'b1) begin
                current_state <= S_IDLE;
                idu_valid_o <= 0;
                idu_ready_o <= 0;
                fencei <= 0;
            end
            else begin
                current_state <= next_state;

                if (inst == 32'h0000100f && flag_fencei==0) begin
                    fencei <= 1;
                    flag_fencei <= 1;
                end
                else
                    fencei <= 0;

                if (current_state == S_IDLE)
                    idu_ready_o <= 1;
                else
                    idu_ready_o <= 0;

                if (current_state == S_IDLE) begin
                    idu_valid_o <= 0;
                    
                    if (idu_valid_i == 1 && idu_ready_o == 1) begin
                        pc <= pc_i;
                        inst <= inst_i;
                    end
                end
                else if (current_state == S_RECEIVE) begin
                    // 只有load-use冒险才stall, 其它RAW通过forwarding解决
                    if (isRAW) begin
                        idu_valid_o <= 0;   // stall: 等待load数据从memory返回
                    end
                    else begin 
                        idu_valid_o <= 1;   // 无冒险或可forwarding, 正常发射
                    end
                end
                else if (current_state == S_SEND) begin
                    idu_valid_o <= 0;
                end
                else begin
                    idu_valid_o <= 0;
                end
            end
        end
    end

endmodule



// =============================================================================
// IFU (Instruction Fetch Unit) — area-optimized
//
// Registers: pc_fetch(32) + pc_o(32) + inst_o(32) + state(2) + flush(1) = 99 DFFs
// Original:  233 DFFs → saved 134 DFFs + associated MUX/BUF
//
// Key changes:
//   - Removed pc_latch (redundant, pc_fetch is stable during S_OUT)
//   - Removed inst_buf (write rdata_i directly to inst_o)
//   - Removed npc_buf (write npc_i directly to pc_fetch)
//   - araddr_o is combinational (= pc_fetch)
//   - arvalid_o, rready_o, ifu_valid_o, reset_o derived from state
//   - ar_inflight removed (encoded in state)
//   - flush_pending kept as 1-bit flag (simplest approach)
// =============================================================================

module ysyx_25050137_ifu (
    input  wire                    clk,
    input  wire                    reset,
    input  wire                    fencei,

    // AXI AR channel
    output wire [`ysyx_25050137_CPU_WIDTH-1:0]   araddr_o,
    output wire [3:0]              arid_o,
    output wire [7:0]              arlen_o,
    output wire [2:0]              arsize_o,
    output wire [1:0]              arburst_o,
    output wire                    arvalid_o,
    input  wire                    arready_i,

    // AXI R channel
    input  wire [`ysyx_25050137_CPU_WIDTH-1:0]   rdata_i,
    input  wire [1:0]              rresp_i,
    input  wire                    rlast_i,
    input  wire [3:0]              rid_i,
    input  wire                    rvalid_i,
    output wire                    rready_o,

    // Branch from EXU
    input  wire [`ysyx_25050137_PC_WIDTH-1:0]    npc_i,
    input  wire                    npc_valid,

    // Flush downstream
    output wire                    reset_o,

    // IFU → IDU handshake
    output reg  [`ysyx_25050137_PC_WIDTH-1:0]    pc_o,
    output reg  [`ysyx_25050137_INST_WIDTH-1:0]  inst_o,
    output wire                    ifu_valid_o,
    input  wire                    ifu_ready_i

);

// =============================================================================
// AXI fixed params
// =============================================================================
assign arid_o    = 4'd0;
assign arlen_o   = 8'd0;
assign arsize_o  = 3'b010;
assign arburst_o = 2'd0;

// =============================================================================
// State encoding — 4 states, 2-bit
// =============================================================================
localparam [1:0]
    S_ADDR  = 2'd0,   // Send AR request
    S_DATA  = 2'd1,   // Wait for R data
    S_OUT   = 2'd2,   // Output to IDU, wait handshake
    S_FLUSH = 2'd3;   // Wait for R data and discard

// =============================================================================
// Registers — only what's truly needed
// =============================================================================
reg [1:0]            state;
reg [`ysyx_25050137_PC_WIDTH-1:0]  pc_fetch;     // The one true PC register
reg                  flush_pend;   // Jump request waiting to be served

reg init;

// =============================================================================
// Combinational outputs derived from state (no output registers!)
// =============================================================================
assign araddr_o   = pc_fetch;
//assign arvalid_o  = (state == S_ADDR);
assign arvalid_o = (state === S_ADDR);
assign rready_o   = (state === S_ADDR) || (state === S_DATA) || (state === S_FLUSH);
assign ifu_valid_o = (state === S_OUT);

// reset_o: pulse high for one cycle when ctrl_hazard detected
// Drives downstream flush — combinational from npc_valid
wire ctrl_hazard = npc_valid && (npc_i !== pc_fetch);
assign reset_o = ctrl_hazard;

// =============================================================================
// State machine
// =============================================================================
always @(posedge clk or posedge reset) begin
    if (reset) begin
        state      <= S_ADDR;
        pc_fetch   <= `ysyx_25050137_PC_INIT;
        pc_o       <= `ysyx_25050137_PC_INIT;
        inst_o     <= {`ysyx_25050137_INST_WIDTH{1'b0}};
        flush_pend <= 1'b0;
        init <= 1'b1;
    end else begin
        if(fencei==1) begin
            state      <= S_ADDR;
            pc_fetch <= pc_fetch + 4;
            flush_pend <= 1'b0;
        end
        else begin

            // ---- Latch jump request at any time ----
            if (ctrl_hazard) begin
                pc_fetch   <= npc_i;     // Immediately update PC (no npc_buf!)
                flush_pend <= 1'b1;
            end

            // ---- State transitions ----
            case (state)

                // ----------------------------------------------------------
                // S_ADDR: AR request on the bus, wait for arready
                // ----------------------------------------------------------
                S_ADDR: begin
                    if (arvalid_o && arready_i) begin
                        // AR handshake done
                        if (ctrl_hazard || flush_pend) begin
                            // This address is stale, go flush and discard R data
                            state <= S_FLUSH;
                        end else begin
                            state <= S_DATA;
                        end
                    end
                    // else: keep arvalid high, wait for arready
                end

                // ----------------------------------------------------------
                // S_DATA: Wait for R channel data
                // ----------------------------------------------------------
                S_DATA: begin
                    if (rvalid_i===1'b1) begin
                        if(init == 1'b1) begin
                            inst_o <= rdata_i;
                            pc_o   <= pc_fetch;
                            state  <= S_OUT;
                            init <= 1'b0;
                        end
                        else if (ctrl_hazard===1'b1 || flush_pend===1'b1) begin
                            // Data arrived but stale, discard
                            flush_pend <= 1'b0;
                            state      <= S_ADDR;
                        end else begin
                            // Good data! Latch instruction and PC, go to output
                            inst_o <= rdata_i;
                            pc_o   <= pc_fetch;
                            state  <= S_OUT;
                        end
                    end
                    else state <= S_DATA;
                end

                // ----------------------------------------------------------
                // S_OUT: Present instruction to IDU
                // ----------------------------------------------------------
                S_OUT: begin
                    if (ctrl_hazard) begin
                        // Jump! Discard current output, refetch
                        state <= S_ADDR;
                    end else if (ifu_valid_o && ifu_ready_i) begin
                        // IDU accepted, advance to next instruction
                        pc_fetch <= pc_fetch + 4;
                        state    <= S_ADDR;
                    end
                end

                // ----------------------------------------------------------
                // S_FLUSH: Drain in-flight R data and discard
                // ----------------------------------------------------------
                S_FLUSH: begin
                    if (rvalid_i) begin
                        // Data arrived, discard it, restart fetch
                        flush_pend <= 1'b0;
                        state      <= S_ADDR;
                    end
                end

            endcase
        end
    end
end

endmodule

// =============================================================================
// LSU — area-optimized
//
// Removed registers:
//   - araddr (32) → combo from alu_result
//   - awaddr (32) → combo from alu_result
//   - wdata  (32) → combo from rs2 + shift
//   - rs2    (32) → was declared but never assigned in always block
//   - csr_rdata_l_rs1 (32) → was declared but never read
//   - rs1    (32) → latch at S_IDLE with others, not S_OUT
//   - arvalid/awvalid/wvalid/rready/bready (5) → from state
//   - read_mem/write_mem/flag/wvalid_tmp (4) → encoded in state
//   - lsu_valid_o/lsu_ready_o/rd_lsu_valid (3) → from state
//   - wlast_o (1) → combo
//
// Estimated: 285 DFF → ~120 DFF
// =============================================================================

module ysyx_25050137_lsu(
    input clk,
    input reset,

    // EXU → LSU
    input [`ysyx_25050137_CPU_WIDTH-1:0] alu_result_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0] rs1_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0] rs2_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_l_rs1_i,
    input MemRead_i,
    input MemWrite_i,
    input [3:0] wmask_i,
    input [2:0] rmask_i,
    input wb_src_i,
    input csr_write_i,
    input csr_wdata_src_i,
    input reg_write_i,
    input [`ysyx_25050137_REG_ADDR-1:0] waddr_i,
    input ecall_i,
    input [1:0] waddr_csr_i,

    input lsu_valid_i,
    output wire lsu_ready_o,

    // LSU → WBU
    output [`ysyx_25050137_CPU_WIDTH-1:0] alu_result_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] rs1_o,
    output reg [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_l_rs1_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] datamem_readdata_o,
    output [2:0] rmask_o,
    output reg wb_src_o,
    output reg csr_write_o,
    output reg csr_wdata_src_o,
    output reg reg_write_o,
    output reg [`ysyx_25050137_REG_ADDR-1:0] waddr_o,
    output ecall_o,
    output [1:0] waddr_csr_o,

    output wire lsu_valid_o,
    input lsu_ready_i,

    // AXI AR
    output [`ysyx_25050137_CPU_WIDTH-1:0] araddr_o,
    output [3:0] arid_o,
    output [7:0] arlen_o,
    output [2:0] arsize_o,
    output [1:0] arburst_o,
    output arvalid_o,
    input arready_i,

    // AXI R
    input [`ysyx_25050137_CPU_WIDTH-1:0] rdata_i,
    input [1:0] rresp_i,
    input rlast_i,
    input [3:0] rid_i,
    input rvalid_i,
    output rready_o,

    // AXI AW
    output [`ysyx_25050137_CPU_WIDTH-1:0] awaddr_o,
    output [3:0] awid_o,
    output [7:0] awlen_o,
    output [2:0] awsize_o,
    output [1:0] awburst_o,
    output awvalid_o,
    input awready_i,

    // AXI W
    output [`ysyx_25050137_CPU_WIDTH-1:0] wdata_o,
    output [3:0] wstrb_o,
    output wlast_o,
    output wvalid_o,
    input wready_i,

    // AXI B
    input [1:0] bresp_i,
    input [3:0] bid_i,
    input bvalid_i,
    output bready_o,

    output rd_lsu_valid,

    input [`ysyx_25050137_CPU_WIDTH-1:0] pc_i,
    output [`ysyx_25050137_CPU_WIDTH-1:0] pc_o
);

// =============================================================================
// State encoding
// =============================================================================
localparam [2:0]
    S_IDLE   = 3'd0,   // Wait for EXU handshake
    S_AR     = 3'd1,   // Read: send AR, wait arready
    S_R      = 3'd2,   // Read: wait R data
    S_AW     = 3'd3,   // Write: send AW+W, wait handshakes
    S_B      = 3'd4,   // Write: wait B response
    S_OUT    = 3'd5;   // Output to WBU

reg [2:0] state;

// =============================================================================
// Pipeline registers — only what we truly need
// =============================================================================
reg [`ysyx_25050137_CPU_WIDTH-1:0]  alu_result;    // Latched address / ALU result
reg [`ysyx_25050137_CPU_WIDTH-1:0]  rs1_lat;       // Latched rs1 (for CSR writeback)
reg [`ysyx_25050137_CPU_WIDTH-1:0]  rs2_lat;       // Latched rs2 (store data)
reg [3:0]             wmask;         // Write byte mask
reg [2:0]             rmask;         // Read type encoding
reg                   aw_done;       // AW channel handshake completed
reg                   w_done;        // W channel handshake completed

// Read data output — needs to hold until WBU consumes
reg [`ysyx_25050137_CPU_WIDTH-1:0]  rdata_buf;

// Pass-through pipeline registers (latched at S_IDLE handshake)
reg [`ysyx_25050137_CPU_WIDTH-1:0]  pc_lat;
reg                   ecall_lat;
reg [1:0]             waddr_csr_lat;

// =============================================================================
// AXI fixed parameters
// =============================================================================
assign arid_o    = 4'd0;
assign arlen_o   = 8'd0;
assign arburst_o = 2'd0;
assign awid_o    = 4'd0;
assign awlen_o   = 8'd0;
assign awburst_o = 2'd0;

// =============================================================================
// AXI outputs — ALL combinational, derived from state + latched data
// =============================================================================

// AR channel
assign araddr_o  = alu_result;
assign arvalid_o = (state == S_AR);
assign rready_o  = (state == S_R);

// AW channel
assign awaddr_o  = alu_result;
assign awvalid_o = (state == S_AW) && !aw_done;

// W channel — shift store data by byte offset
assign wdata_o   = (wmask == 4'hf) ? rs2_lat : (rs2_lat << (8 * alu_result[1:0]));
assign wstrb_o   = (wmask == 4'hf || wmask == 4'h0) ? wmask : (wmask << alu_result[1:0]);
assign wvalid_o  = (state == S_AW) && !w_done;
assign wlast_o   = wvalid_o;

// B channel
assign bready_o  = (state == S_B);

// AXI size encoding
reg [2:0] arsize_r, awsize_r;
always @(*) begin
    case (rmask)
        3'b100, 3'b011: arsize_r = 3'b000;  // lb, lbu
        3'b010, 3'b001: arsize_r = 3'b001;  // lh, lhu
        default:        arsize_r = 3'b010;   // lw
    endcase
end
always @(*) begin
    case (wmask)
        4'h1:    awsize_r = 3'b000;
        4'h3:    awsize_r = 3'b001;
        default: awsize_r = 3'b010;
    endcase
end
assign arsize_o = arsize_r;
assign awsize_o = awsize_r;

// =============================================================================
// Handshake outputs — combinational from state
// =============================================================================
assign lsu_ready_o  = (state == S_IDLE);
assign lsu_valid_o  = (state == S_OUT);
assign rd_lsu_valid = (state != S_IDLE);

// Pipeline outputs
assign alu_result_o        = alu_result;
assign rs1_o               = rs1_lat;
assign rmask_o             = rmask;
assign datamem_readdata_o  = rdata_buf;
assign pc_o                = pc_lat;
assign ecall_o             = ecall_lat;
assign waddr_csr_o         = waddr_csr_lat;

// =============================================================================
// State machine
// =============================================================================
wire idle_handshake = (state == S_IDLE) && lsu_valid_i;

always @(posedge clk or posedge reset) begin
    if (reset) begin
        state    <= S_IDLE;
        aw_done  <= 1'b0;
        w_done   <= 1'b0;
    end else begin
        case (state)

            S_IDLE: begin
                if (lsu_valid_i) begin
                    // Latch all pipeline signals at handshake
                    alu_result        <= alu_result_i;
                    rs1_lat           <= rs1_i;
                    rs2_lat           <= rs2_i;
                    wmask             <= wmask_i;
                    rmask             <= rmask_i;
                    wb_src_o          <= wb_src_i;
                    csr_write_o       <= csr_write_i;
                    csr_wdata_src_o   <= csr_wdata_src_i;
                    reg_write_o       <= reg_write_i;
                    csr_rdata_l_rs1_o <= csr_rdata_l_rs1_i;
                    waddr_o           <= waddr_i;
                    pc_lat            <= pc_i;
                    ecall_lat         <= ecall_i;
                    waddr_csr_lat     <= waddr_csr_i;

`ifdef VERILATOR_SIM
                    // DPI-C: difftest skip for MMIO
                    if (MemRead_i) begin
                        if ((alu_result_i >= 32'h10000000 && alu_result_i <= 32'h10000fff) ||
                            (alu_result_i >= 32'h02000000 && alu_result_i <= 32'h0200ffff)) begin
                            difftest_skip();
                            //$display("difftest_skip\n");
                        end
                    end
`endif 
                    // Decide next state
                    if (MemRead_i)
                        state <= S_AR;
                    else if (MemWrite_i) begin
                        state   <= S_AW;
                        aw_done <= 1'b0;
                        w_done  <= 1'b0;
                    end else
                        state <= S_OUT;
                end
            end

            S_AR: begin
                // Wait for AR handshake
                if (arvalid_o && arready_i) begin
                    state <= S_R;
                end
            end

            S_R: begin
                // Wait for R data
                if (rvalid_i && rlast_i) begin
                    rdata_buf <= rdata_i;
                    state     <= S_OUT;
                end
            end

            S_AW: begin
                // AW and W can handshake independently
                if (awvalid_o && awready_i) begin
                    aw_done <= 1'b1;
                end
                if (wvalid_o && wready_i)
                    w_done <= 1'b1;

                // Both done → wait for B
                if ((aw_done || (awvalid_o && awready_i)) &&
                    (w_done  || (wvalid_o  && wready_i)))
                    state <= S_B;
            end

            S_B: begin
                if (bvalid_i) begin
                    state <= S_OUT;
                end
            end

            S_OUT: begin
                if (lsu_valid_o && lsu_ready_i)
                    state <= S_IDLE;
            end

            default: state <= S_IDLE;

        endcase
    end
end

endmodule

module ysyx_25050137_mux21 # (parameter WIDTH = 32)(
    input [WIDTH-1:0] d0,
    input [WIDTH-1:0] d1,
    input sel,
    output [WIDTH-1:0] out
);
    assign out = sel ? d1 : d0;


endmodule

module ysyx_25050137_mux41#(parameter WIDTH = 32)(
    input [WIDTH-1:0] d0,
    input [WIDTH-1:0] d1,
    input [WIDTH-1:0] d2,
    input [WIDTH-1:0] d3,
    input [1:0]sel,
    output [WIDTH-1:0] out
);

    assign out = sel[1] ? (sel[0] ? d3 : d2) : (sel[0] ? d1 : d0);
endmodule

module ysyx_25050137_regfile #(parameter ADDR_WIDTH = 5, parameter DATA_WIDTH = 32) (
  input clk,
  input reset,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  input wen,
  input [ADDR_WIDTH-1:0] raddr1,
  output [DATA_WIDTH-1:0] rdata1,
  input [ADDR_WIDTH-1:0] raddr2,
  output [DATA_WIDTH-1:0] rdata2,

`ifdef VERILATOR_SIM
  output [31:0] reg_file [0:15],
  output [31:0] csr_reg [0:3],
`endif 

  input [2:0] raddr_csr,
  output [DATA_WIDTH-1:0] rdata_csr,
  input [1:0] waddr_csr,
  input [DATA_WIDTH-1:0] wdata_csr,
  input wen_csr,
  input ecall,
  input [DATA_WIDTH-1:0] pc

);

  reg [DATA_WIDTH-1:0] regs [1:15];
  //reg [DATA_WIDTH-1:0] csr [0:3];

  reg [DATA_WIDTH-1:0] csr_mstatus;
  reg [DATA_WIDTH-1:0] csr_mtvec;
  reg [DATA_WIDTH-1:0] csr_mepc;
  reg [DATA_WIDTH-1:0] csr_mcause;

`ifdef VERILATOR_SIM
  genvar gv_i;
  generate
    for(gv_i=1;gv_i<16;gv_i++) begin
        assign reg_file[gv_i] = regs[gv_i];
    end
  endgenerate

  assign reg_file[0] = 0;
  assign csr_reg[0] = csr_mstatus;
  assign csr_reg[1] = csr_mtvec;
  assign csr_reg[2] = csr_mepc;
  assign csr_reg[3] = csr_mcause;
  
`endif 

  always @(posedge clk) begin
    if (wen && waddr != 0) regs[waddr] <= wdata;
  end

    integer i;

    // ============================================================
    // 读端口 1：decode-and-OR
    // ============================================================
    wire [15:0] rsel1 = (16'b1 << raddr1);
 
    wire [31:0] m1_0  = 32'b0;                        // x0 = 0
    wire [31:0] m1_1  = {32{rsel1[ 1]}} & regs[ 1];
    wire [31:0] m1_2  = {32{rsel1[ 2]}} & regs[ 2];
    wire [31:0] m1_3  = {32{rsel1[ 3]}} & regs[ 3];
    wire [31:0] m1_4  = {32{rsel1[ 4]}} & regs[ 4];
    wire [31:0] m1_5  = {32{rsel1[ 5]}} & regs[ 5];
    wire [31:0] m1_6  = {32{rsel1[ 6]}} & regs[ 6];
    wire [31:0] m1_7  = {32{rsel1[ 7]}} & regs[ 7];
    wire [31:0] m1_8  = {32{rsel1[ 8]}} & regs[ 8];
    wire [31:0] m1_9  = {32{rsel1[ 9]}} & regs[ 9];
    wire [31:0] m1_10 = {32{rsel1[10]}} & regs[10];
    wire [31:0] m1_11 = {32{rsel1[11]}} & regs[11];
    wire [31:0] m1_12 = {32{rsel1[12]}} & regs[12];
    wire [31:0] m1_13 = {32{rsel1[13]}} & regs[13];
    wire [31:0] m1_14 = {32{rsel1[14]}} & regs[14];
    wire [31:0] m1_15 = {32{rsel1[15]}} & regs[15];
 
    assign rdata1 = m1_0  | m1_1  | m1_2  | m1_3  |
                    m1_4  | m1_5  | m1_6  | m1_7  |
                    m1_8  | m1_9  | m1_10 | m1_11 |
                    m1_12 | m1_13 | m1_14 | m1_15;


    // ============================================================
    // 读端口 2：decode-and-OR
    // ============================================================
    wire [15:0] rsel2 = (16'b1 << raddr2);
 
    wire [31:0] m2_0  = 32'b0;
    wire [31:0] m2_1  = {32{rsel2[ 1]}} & regs[ 1];
    wire [31:0] m2_2  = {32{rsel2[ 2]}} & regs[ 2];
    wire [31:0] m2_3  = {32{rsel2[ 3]}} & regs[ 3];
    wire [31:0] m2_4  = {32{rsel2[ 4]}} & regs[ 4];
    wire [31:0] m2_5  = {32{rsel2[ 5]}} & regs[ 5];
    wire [31:0] m2_6  = {32{rsel2[ 6]}} & regs[ 6];
    wire [31:0] m2_7  = {32{rsel2[ 7]}} & regs[ 7];
    wire [31:0] m2_8  = {32{rsel2[ 8]}} & regs[ 8];
    wire [31:0] m2_9  = {32{rsel2[ 9]}} & regs[ 9];
    wire [31:0] m2_10 = {32{rsel2[10]}} & regs[10];
    wire [31:0] m2_11 = {32{rsel2[11]}} & regs[11];
    wire [31:0] m2_12 = {32{rsel2[12]}} & regs[12];
    wire [31:0] m2_13 = {32{rsel2[13]}} & regs[13];
    wire [31:0] m2_14 = {32{rsel2[14]}} & regs[14];
    wire [31:0] m2_15 = {32{rsel2[15]}} & regs[15];
 
    assign rdata2 = m2_0  | m2_1  | m2_2  | m2_3  |
                    m2_4  | m2_5  | m2_6  | m2_7  |
                    m2_8  | m2_9  | m2_10 | m2_11 |
                    m2_12 | m2_13 | m2_14 | m2_15;

    // mstatus — only CSR with reset value
  always @(posedge clk or posedge reset) begin
    if (reset)
      csr_mstatus <= 32'h1800;
    else if (wen_csr && waddr_csr == 2'd0)
      csr_mstatus <= wdata_csr;
  end
 
  // mtvec — no reset needed
  always @(posedge clk) begin
    if (wen_csr && waddr_csr == 2'd1)
      csr_mtvec <= wdata_csr;
  end
 
  // mepc — ecall or CSR write
  always @(posedge clk) begin
    if (ecall)
      csr_mepc <= pc;
    else if (wen_csr && waddr_csr == 2'd2)
      csr_mepc <= wdata_csr;
  end
 
  // mcause — ecall or CSR write
  always @(posedge clk) begin
    if (ecall)
      csr_mcause <= 11;
    else if (wen_csr && waddr_csr == 2'd3)
      csr_mcause <= wdata_csr;
  end

  // 替换掉 AND-OR 读端口，用简单的 case MUX
  reg [31:0] csr_reg_data;
  always @(*) begin
    case (raddr_csr[1:0])
      2'd0: csr_reg_data = csr_mstatus;
      2'd1: csr_reg_data = csr_mtvec;
      2'd2: csr_reg_data = csr_mepc;
      2'd3: csr_reg_data = csr_mcause;
    endcase
  end

  assign rdata_csr = raddr_csr[2] ? (raddr_csr[0] ? 32'h017E3C19 : 32'h79737978)
                                  : csr_reg_data;

endmodule

module ysyx_25050137_sext_mem(
    input [31:0] read_data,
    input [1:0] addr_low2,
    input [2:0] rmask,
    output reg [31:0] mem_data
);
    
    wire [31:0] sbyte3,sbyte2,sbyte1,sbyte0;
    wire [31:0] byte3,byte2,byte1,byte0;

    assign sbyte3 = {{24{read_data[31]}},read_data[31:24]};
    assign sbyte2 = {{24{read_data[23]}},read_data[23:16]};
    assign sbyte1 = {{24{read_data[15]}},read_data[15:8]};
    assign sbyte0 = {{24{read_data[7]}},read_data[7:0]};

    assign byte3 = {24'd0,read_data[31:24]};
    assign byte2 = {24'd0,read_data[23:16]};
    assign byte1 = {24'd0,read_data[15:8]};
    assign byte0 = {24'd0,read_data[7:0]};
    always@(*) begin
        case(rmask)
            3'b000:mem_data = read_data; //lw
            3'b001:begin //lh
                mem_data = addr_low2[1] ? ({{16{read_data[31]}},read_data[31:16]}) : ({{16{read_data[15]}},read_data[15:0]}) ;//lh
            end
            3'b010:begin //lhu
                mem_data = addr_low2[1] ? ({16'd0,read_data[31:16]}) : ({16'd0,read_data[15:0]}) ;//lhu
            end
            3'b011:mem_data = addr_low2[1] ? (addr_low2[0] ? sbyte3 : sbyte2) : (addr_low2[0] ? sbyte1 : sbyte0);//lb
            3'b100:mem_data = addr_low2[1] ? (addr_low2[0] ? byte3 : byte2) : (addr_low2[0] ? byte1 : byte0);//lbu
            default:mem_data = read_data;

        endcase
    end


endmodule

module ysyx_25050137_sext #(parameter DATA_WIDTH = 32)(
    input [31:0] inst,
    output reg [DATA_WIDTH-1:0]data
);
    wire [6:0] opcode;
    wire [2:0] funct3;
    wire [6:0] funct7;
    assign opcode = inst[6:0];
    assign funct3 = inst[14:12];
    assign funct7 = inst[31:25];

    always@(*) begin
        case (opcode)            
            7'b0110111: begin //U //lui
                data = {inst[31:12],12'd0};
            end
            7'b0010111: begin //U //auipc
                data = {inst[31:12],12'd0};
            end
            7'b1101111: begin //UJ //jal
                data = {{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0};
            end
            7'b1100111: begin
                case(funct3)
                    3'b000: data = {{20{inst[31]}},inst[31:20]}; //I //jalr
                    default: data = 0;
                endcase
            end
            7'b1100011: begin //SB
                case(funct3)
                    3'b000: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //beq
                    3'b001: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //bne
                    3'b100: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //blt
                    3'b101: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //bge
                    3'b110: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //bltu
                    3'b111: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0}; //SB //bgeu
                    default: data = {{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};
                endcase
            end
            7'b0000011: begin //I
                case(funct3)
                    3'b000: data = {{20{inst[31]}},inst[31:20]}; //I //lb
                    3'b001: data = {{20{inst[31]}},inst[31:20]}; //I //lh
                    3'b010: data = {{20{inst[31]}},inst[31:20]}; //I //lw
                    3'b100: data = {{20{inst[31]}},inst[31:20]}; //I //lbu
                    3'b101: data = {{20{inst[31]}},inst[31:20]}; //I //lhu
                    default: data = {{20{inst[31]}},inst[31:20]};
                endcase
            end
            7'b0100011: begin //S 
                case(funct3)
                    3'b000: data = {{20{inst[31]}},inst[31:25],inst[11:7]}; //S //sb
                    3'b001: data = {{20{inst[31]}},inst[31:25],inst[11:7]}; //S //sh
                    3'b010: data = {{20{inst[31]}},inst[31:25],inst[11:7]}; //S //sw
                    default: data = {{20{inst[31]}},inst[31:25],inst[11:7]};
                endcase
            end            
            7'b0010011: begin
                case(funct3)
                    3'b000: data = {{20{inst[31]}},inst[31:20]}; //I //addi
                    3'b010: data = {{20{inst[31]}},inst[31:20]}; //I //slti
                    3'b011: data = {{20{inst[31]}},inst[31:20]}; //I //sltiu
                    3'b100: data = {{20{inst[31]}},inst[31:20]}; //I //xori
                    3'b110: data = {{20{inst[31]}},inst[31:20]}; //I //ori
                    3'b111: data = {{20{inst[31]}},inst[31:20]}; //I //andi
                    3'b001: data = {27'd0,inst[24:20]}; //I //slli
                    3'b101: begin
                        case(funct7)
                            7'b0000000: data = {27'd0,inst[24:20]}; //I //srli
                            7'b0100000: data = {27'd0,inst[24:20]}; //I //srai
                            default: data = {27'd0,inst[24:20]};
                        endcase
                    end
                    default: data = {{20{inst[31]}},inst[31:20]};
                endcase
            end
            default: data = 0;
        endcase
    end

endmodule



// =============================================================================
// WBU — area-optimized
//
// Key insight: WBU is single-cycle. S_RECEIVE immediately goes back to S_IDLE.
// So we can latch at handshake (S_IDLE && valid && ready) and output in the
// same "next cycle" which is already S_IDLE again.
//
// Actually, since regfile write is consumed in one cycle and WBU doesn't
// need to hold data across multiple cycles, many signals can be passed
// through combinationally when we're in the "active" beat.
//
// Removed:
//   - rs1 (32 DFF) → pass through combinationally
//   - csr_rdata_l_rs1 (32 DFF) → pass through combinationally  
//   - S_RECEIVE state → merge into single-cycle operation
//   - wbu_ready_o, rd_wbu_valid → derive from state
//
// Kept (must hold stable for sext_mem/mux submodules):
//   - alu_result, datamem_readdata, rmask, wb_src, csr_wdata_src
//   - csr_write_o, reg_write_o, waddr_o, ecall_o, waddr_csr_o, pc_o
// =============================================================================

module ysyx_25050137_wbu (
    input clk,
    input reset,

    // LSU → WBU
    input [`ysyx_25050137_CPU_WIDTH-1:0]  alu_result_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  rs1_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  csr_rdata_l_rs1_i,
    input [`ysyx_25050137_CPU_WIDTH-1:0]  datamem_readdata_i,
    input [2:0]             rmask_i,
    input                   wb_src_i,
    input                   csr_write_i,
    input                   csr_wdata_src_i,
    input                   reg_write_i,
    input [`ysyx_25050137_REG_ADDR-1:0]   waddr_i,
    input                   ecall_i,
    input [1:0]             waddr_csr_i,

    input                   wbu_valid_i,
    output                  wbu_ready_o,

    // Write-back outputs
    output [`ysyx_25050137_CPU_WIDTH-1:0] csr_wdata_o,
    output [`ysyx_25050137_CPU_WIDTH-1:0] wdata_o,
    output reg              csr_write_o,
    output reg              reg_write_o,
    output reg [`ysyx_25050137_REG_ADDR-1:0] waddr_o,
    output reg              ecall_o,
    output reg [1:0]        waddr_csr_o,

    output                  rd_wbu_valid,

    input [`ysyx_25050137_CPU_WIDTH-1:0]  pc_i,
    output reg [`ysyx_25050137_CPU_WIDTH-1:0] pc_o
);

// =============================================================================
// State: just a toggle — IDLE (accept) or WRITEBACK (output results)
// =============================================================================
reg active;  // 0 = idle/ready, 1 = writeback active

assign wbu_ready_o  = !active;
assign rd_wbu_valid = active;

// =============================================================================
// Latched data — only what submodules need in the writeback cycle
// =============================================================================
reg [`ysyx_25050137_CPU_WIDTH-1:0]  alu_result;
reg [`ysyx_25050137_CPU_WIDTH-1:0]  datamem_readdata;
reg [`ysyx_25050137_CPU_WIDTH-1:0]  rs1_lat;
reg [`ysyx_25050137_CPU_WIDTH-1:0]  csr_rdata_l_rs1_lat;
reg [2:0]             rmask;
reg                   wb_src;
reg                   csr_wdata_src;

// =============================================================================
// Submodules (combinational)
// =============================================================================
wire [`ysyx_25050137_CPU_WIDTH-1:0] mem_data;

ysyx_25050137_sext_mem SEXT_Mem (
    .read_data (datamem_readdata),
    .addr_low2 (alu_result[1:0]),
    .rmask     (rmask),
    .mem_data  (mem_data)
);

ysyx_25050137_mux21 WB (
    .d0  (alu_result),
    .d1  (mem_data),
    .sel (wb_src),
    .out (wdata_o)
);

ysyx_25050137_mux21 Csr_Wdata (
    .d0  (rs1_lat),
    .d1  (csr_rdata_l_rs1_lat),
    .sel (csr_wdata_src),
    .out (csr_wdata_o)
);

// =============================================================================
// State machine
// =============================================================================
always @(posedge clk or posedge reset) begin
    if (reset) begin
        active <= 1'b0;
    end else begin
        if (!active) begin
            // S_IDLE: accept handshake
            if (wbu_valid_i) begin
                alu_result          <= alu_result_i;
                datamem_readdata    <= datamem_readdata_i;
                rs1_lat             <= rs1_i;
                csr_rdata_l_rs1_lat <= csr_rdata_l_rs1_i;
                rmask               <= rmask_i;
                wb_src              <= wb_src_i;
                csr_wdata_src       <= csr_wdata_src_i;
                csr_write_o         <= csr_write_i;
                reg_write_o         <= reg_write_i;
                waddr_o             <= waddr_i;
                ecall_o             <= ecall_i;
                waddr_csr_o         <= waddr_csr_i;
                pc_o                <= pc_i;
                active              <= 1'b1;
            end
        end else begin
            // Writeback cycle — submodules output results combinationally
            // Single cycle, go back to idle           
            active <= 1'b0;
        end
`ifdef VERILATOR_SIM
        difftest_next_step({7'd0,active});
`endif 
    end
end

endmodule



// =============================================================================
// XBAR — latch-free, pure combinational crossbar
//
// Original: 102 DLH (latches) due to incomplete assignments in always @(*)
// Fix: all outputs are wire + assign, every path has a defined value.
//
// Routing: address in CLINT range (0x0200_0000 ~ 0x0200_ffff) → clint
//          everything else → sram
//          Write channel always goes to sram (no CLINT write needed)
// =============================================================================

module ysyx_25050137_xbar (
    input clk,
    input reset,

    // Upstream (from arbiter)
    input  [`ysyx_25050137_CPU_WIDTH-1:0] axi_araddr_i,
    input  [3:0]            axi_arid_i,
    input  [7:0]            axi_arlen_i,
    input  [2:0]            axi_arsize_i,
    input  [1:0]            axi_arburst_i,
    input                   axi_arvalid_i,
    output                  axi_arready_o,

    output [`ysyx_25050137_CPU_WIDTH-1:0] axi_rdata_o,
    output [1:0]            axi_rresp_o,
    output                  axi_rlast_o,
    output [3:0]            axi_rid_o,
    output                  axi_rvalid_o,
    input                   axi_rready_i,

    input  [`ysyx_25050137_CPU_WIDTH-1:0] axi_awaddr_i,
    input  [3:0]            axi_awid_i,
    input  [7:0]            axi_awlen_i,
    input  [2:0]            axi_awsize_i,
    input  [1:0]            axi_awburst_i,
    input                   axi_awvalid_i,
    output                  axi_awready_o,

    input  [`ysyx_25050137_CPU_WIDTH-1:0] axi_wdata_i,
    input  [3:0]            axi_wstrb_i,
    input                   axi_wlast_i,
    input                   axi_wvalid_i,
    output                  axi_wready_o,

    output [1:0]            axi_bresp_o,
    output [3:0]            axi_bid_o,
    output                  axi_bvalid_o,
    input                   axi_bready_i,

    // Downstream: SRAM
    output [`ysyx_25050137_CPU_WIDTH-1:0] sram_araddr_o,
    output [3:0]            sram_arid_o,
    output [7:0]            sram_arlen_o,
    output [2:0]            sram_arsize_o,
    output [1:0]            sram_arburst_o,
    output                  sram_arvalid_o,
    input                   sram_arready_i,

    input  [`ysyx_25050137_CPU_WIDTH-1:0] sram_rdata_i,
    input  [1:0]            sram_rresp_i,
    input                   sram_rlast_i,
    input  [3:0]            sram_rid_i,
    input                   sram_rvalid_i,
    output                  sram_rready_o,

    output [`ysyx_25050137_CPU_WIDTH-1:0] sram_awaddr_o,
    output [3:0]            sram_awid_o,
    output [7:0]            sram_awlen_o,
    output [2:0]            sram_awsize_o,
    output [1:0]            sram_awburst_o,
    output                  sram_awvalid_o,
    input                   sram_awready_i,

    output [`ysyx_25050137_CPU_WIDTH-1:0] sram_wdata_o,
    output [3:0]            sram_wstrb_o,
    output                  sram_wlast_o,
    output                  sram_wvalid_o,
    input                   sram_wready_i,

    input  [1:0]            sram_bresp_i,
    input  [3:0]            sram_bid_i,
    input                   sram_bvalid_i,
    output                  sram_bready_o,

    // Downstream: CLINT
    output [`ysyx_25050137_CPU_WIDTH-1:0] clint_araddr_o,
    output [3:0]            clint_arid_o,
    output [7:0]            clint_arlen_o,
    output [2:0]            clint_arsize_o,
    output [1:0]            clint_arburst_o,
    output                  clint_arvalid_o,
    input                   clint_arready_i,

    input  [`ysyx_25050137_CPU_WIDTH-1:0] clint_rdata_i,
    input  [1:0]            clint_rresp_i,
    input                   clint_rlast_i,
    input  [3:0]            clint_rid_i,
    input                   clint_rvalid_i,
    output                  clint_rready_o,

    output [`ysyx_25050137_CPU_WIDTH-1:0] clint_awaddr_o,
    output [3:0]            clint_awid_o,
    output [7:0]            clint_awlen_o,
    output [2:0]            clint_awsize_o,
    output [1:0]            clint_awburst_o,
    output                  clint_awvalid_o,
    input                   clint_awready_i,

    output [`ysyx_25050137_CPU_WIDTH-1:0] clint_wdata_o,
    output [3:0]            clint_wstrb_o,
    output                  clint_wlast_o,
    output                  clint_wvalid_o,
    input                   clint_wready_i,

    input  [1:0]            clint_bresp_i,
    input  [3:0]            clint_bid_i,
    input                   clint_bvalid_i,
    output                  clint_bready_o
);

// =============================================================================
// Address decode — pure combinational
// =============================================================================
wire sel_clint = (axi_araddr_i >= 32'h0200_0000) && (axi_araddr_i <= 32'h0200_ffff);

// =============================================================================
// AR channel: route to clint or sram based on address
// Both downstream ports get the address/control, but only the selected
// one gets arvalid. The unselected one sees arvalid=0.
// =============================================================================
assign sram_araddr_o  = axi_araddr_i;
assign sram_arid_o    = axi_arid_i;
assign sram_arlen_o   = axi_arlen_i;
assign sram_arsize_o  = axi_arsize_i;
assign sram_arburst_o = axi_arburst_i;
assign sram_arvalid_o = axi_arvalid_i && !sel_clint;

assign clint_araddr_o  = axi_araddr_i;
assign clint_arid_o    = axi_arid_i;
assign clint_arlen_o   = axi_arlen_i;
assign clint_arsize_o  = axi_arsize_i;
assign clint_arburst_o = axi_arburst_i;
assign clint_arvalid_o = axi_arvalid_i && sel_clint;

assign axi_arready_o = sel_clint ? clint_arready_i : sram_arready_i;

// =============================================================================
// R channel: mux response back from selected slave
// =============================================================================
assign axi_rdata_o  = sel_clint ? clint_rdata_i  : sram_rdata_i;
assign axi_rresp_o  = sel_clint ? clint_rresp_i  : sram_rresp_i;
assign axi_rlast_o  = sel_clint ? clint_rlast_i  : sram_rlast_i;
assign axi_rid_o    = sel_clint ? clint_rid_i     : sram_rid_i;
assign axi_rvalid_o = sel_clint ? clint_rvalid_i  : sram_rvalid_i;

assign sram_rready_o  = axi_rready_i && !sel_clint;
assign clint_rready_o = axi_rready_i && sel_clint;

// =============================================================================
// AW/W/B channels: always route to sram (CLINT has no writes in this design)
// CLINT write ports tied to inactive defaults.
// =============================================================================
assign sram_awaddr_o  = axi_awaddr_i;
assign sram_awid_o    = axi_awid_i;
assign sram_awlen_o   = axi_awlen_i;
assign sram_awsize_o  = axi_awsize_i;
assign sram_awburst_o = axi_awburst_i;
assign sram_awvalid_o = axi_awvalid_i;
assign axi_awready_o  = sram_awready_i;

assign sram_wdata_o   = axi_wdata_i;
assign sram_wstrb_o   = axi_wstrb_i;
assign sram_wlast_o   = axi_wlast_i;
assign sram_wvalid_o  = axi_wvalid_i;
assign axi_wready_o   = sram_wready_i;

assign axi_bresp_o    = sram_bresp_i;
assign axi_bid_o      = sram_bid_i;
assign axi_bvalid_o   = sram_bvalid_i;
assign sram_bready_o  = axi_bready_i;

// CLINT write ports — inactive
assign clint_awaddr_o  = 0;
assign clint_awid_o    = 0;
assign clint_awlen_o   = 0;
assign clint_awsize_o  = 0;
assign clint_awburst_o = 0;
assign clint_awvalid_o = 1'b0;
assign clint_wdata_o   = 0;
assign clint_wstrb_o   = 0;
assign clint_wlast_o   = 1'b0;
assign clint_wvalid_o  = 1'b0;
assign clint_bready_o  = 1'b0;

endmodule

module ysyx_25050137
(
    input           clock,
    input           reset,
    input           io_interrupt,
    input           io_master_awready,
    output          io_master_awvalid,  
    output  [31:0]  io_master_awaddr,     
    output  [3:0]   io_master_awid,         
    output  [7:0]   io_master_awlen,       
    output  [2:0]   io_master_awsize,     
    output  [1:0]   io_master_awburst,   
    input           io_master_wready,     
    output          io_master_wvalid,     
    output  [31:0]  io_master_wdata,       
    output  [3:0]   io_master_wstrb,       
    output          io_master_wlast,       
    output          io_master_bready,   
    input           io_master_bvalid,    
    input   [1:0]   io_master_bresp,      
    input   [3:0]   io_master_bid,           
    input           io_master_arready,  
    output          io_master_arvalid,  
    output  [31:0]  io_master_araddr,   
    output  [3:0]   io_master_arid,         
    output  [7:0]   io_master_arlen,       
    output  [2:0]   io_master_arsize,   
    output  [1:0]   io_master_arburst,  
    output          io_master_rready,   
    input           io_master_rvalid,     
    input   [1:0]   io_master_rresp,    
    input   [31:0]  io_master_rdata,       
    input           io_master_rlast,       
    input   [3:0]   io_master_rid,      
    
    output          io_slave_awready, 
    input           io_slave_awvalid,  
    input   [31:0]  io_slave_awaddr,    
    input   [3:0]   io_slave_awid,
    input   [7:0]   io_slave_awlen,
    input   [2:0]   io_slave_awsize,
    input   [1:0]   io_slave_awburst,
    output          io_slave_wready,
    input           io_slave_wvalid,
    input   [31:0]  io_slave_wdata,
    input   [3:0]   io_slave_wstrb,
    input           io_slave_wlast,
    input           io_slave_bready,
    output          io_slave_bvalid,  
    output  [1:0]   io_slave_bresp,  
    output  [3:0]   io_slave_bid,
    output          io_slave_arready, 
    input           io_slave_arvalid, 
    input   [31:0]  io_slave_araddr, 
    input   [3:0]   io_slave_arid,
    input   [7:0]   io_slave_arlen,
    input   [2:0]   io_slave_arsize,  
    input   [1:0]   io_slave_arburst, 
    input           io_slave_rready,  
    output          io_slave_rvalid,
    output  [1:0]   io_slave_rresp,   
    output  [31:0]  io_slave_rdata,
    output          io_slave_rlast,
    output  [3:0]   io_slave_rid

);

    wire clk,reset_ifu;
    assign clk = clock;

    //wire [`ysyx_25050137_PC_WIDTH-1:0] pc_to_mem;
    //wire [`ysyx_25050137_INST_WIDTH-1:0] inst_from_mem;
    //wbu to ifu
    wire [`ysyx_25050137_PC_WIDTH-1:0] npc;
    wire valid_wbu_to_ifu;
    wire ready_wbu_to_ifu;
    //ifu to idu
    wire [`ysyx_25050137_PC_WIDTH-1:0] pc_ifu_to_idu;
    wire [`ysyx_25050137_INST_WIDTH-1:0] inst_ifu_to_idu;
    wire valid_ifu_to_idu;
    wire ready_ifu_to_idu;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] ifu_araddr;
    wire [3:0] ifu_arid;
    wire [7:0] ifu_arlen;
    wire [2:0] ifu_arsize;
    wire [1:0] ifu_arburst;
    wire ifu_arvalid;
    wire ifu_arready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] ifu_rdata;
    wire [1:0] ifu_rresp;
    wire ifu_rlast;
    wire [3:0] ifu_rid;
    wire ifu_rvalid;
    wire ifu_rready;

    wire fencei;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] cache_araddr;
    wire [3:0] cache_arid;
    wire [7:0] cache_arlen;
    wire [2:0] cache_arsize;
    wire [1:0] cache_arburst;
    wire cache_arvalid;
    wire cache_arready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] cache_rdata;
    wire [1:0] cache_rresp;
    wire cache_rlast;
    wire [3:0] cache_rid;
    wire cache_rvalid;
    wire cache_rready;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] lsu_araddr;
    wire [3:0] lsu_arid;
    wire [7:0] lsu_arlen;
    wire [2:0] lsu_arsize;
    wire [1:0] lsu_arburst;
    wire lsu_arvalid;
    wire lsu_arready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] lsu_rdata;
    wire [1:0] lsu_rresp;
    wire lsu_rlast;
    wire [3:0] lsu_rid;
    wire lsu_rvalid;
    wire lsu_rready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] lsu_awaddr;
    wire [3:0] lsu_awid;
    wire [7:0] lsu_awlen;
    wire [2:0] lsu_awsize;
    wire [1:0] lsu_awburst;
    wire lsu_awvalid;
    wire lsu_awready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] lsu_wdata;
    wire [3:0] lsu_wstrb;
    wire lsu_wlast;
    wire lsu_wvalid;
    wire lsu_wready;
    wire [1:0] lsu_bresp;
    wire [3:0] lsu_bid;
    wire lsu_bvalid;
    wire lsu_bready;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] axi_araddr;
    wire [3:0] axi_arid;
    wire [7:0] axi_arlen;
    wire [2:0] axi_arsize;
    wire [1:0] axi_arburst;
    wire axi_arvalid;
    wire axi_arready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] axi_rdata;
    wire [1:0] axi_rresp;
    wire axi_rlast;
    wire [3:0] axi_rid;
    wire axi_rvalid;
    wire axi_rready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] axi_awaddr;
    wire [3:0] axi_awid;
    wire [7:0] axi_awlen;
    wire [2:0] axi_awsize;
    wire [1:0] axi_awburst;
    wire axi_awvalid;
    wire axi_awready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] axi_wdata;
    wire [3:0] axi_wstrb;
    wire axi_wlast;
    wire axi_wvalid;
    wire axi_wready;
    wire [1:0] axi_bresp;
    wire [3:0] axi_bid;
    wire axi_bvalid;
    wire axi_bready;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] clint_araddr;
    wire [3:0] clint_arid;
    wire [7:0] clint_arlen;
    wire [2:0] clint_arsize;
    wire [1:0] clint_arburst;
    wire clint_arvalid;
    wire clint_arready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] clint_rdata;
    wire [1:0] clint_rresp;
    wire clint_rlast;
    wire [3:0] clint_rid;
    wire clint_rvalid;
    wire clint_rready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] clint_awaddr;
    wire [3:0] clint_awid;
    wire [7:0] clint_awlen;
    wire [2:0] clint_awsize;
    wire [1:0] clint_awburst;
    wire clint_awvalid;
    wire clint_awready;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] clint_wdata;
    wire [3:0] clint_wstrb;
    wire clint_wlast;
    wire clint_wvalid;
    wire clint_wready;
    wire [1:0] clint_bresp;
    wire [3:0] clint_bid;
    wire clint_bvalid;
    wire clint_bready;

    wire [`ysyx_25050137_REG_ADDR-1:0] raddr1;
    wire [`ysyx_25050137_REG_ADDR-1:0] raddr2;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rdata1;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rdata2;
    wire [`ysyx_25050137_PC_WIDTH-1:0] pc_idu_to_exu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rs1_idu_to_exu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rs2_idu_to_exu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] imm_idu_to_exu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_idu_to_exu;
    wire a_in_src_idu_to_exu;
    wire [1:0] b_in_src_idu_to_exu;
    wire [2:0] pc_srcs_idu_to_exu;
    wire adder_a_src_idu_to_exu;
    wire adder_out_src_idu_to_exu;
    wire [3:0] alu_op_idu_to_exu;
    //idu to exu to lsu or wbu
    wire MemRead_idu_to_exu;
    wire MemWrite_idu_to_exu;
    wire [3:0] wmask_idu_to_exu;
    wire [2:0] rmask_idu_to_exu;
    wire wb_src_idu_to_exu;
    wire csr_write_idu_to_exu;
    wire csr_wdata_src_idu_to_exu;
    wire reg_write_idu_to_exu;
    wire [`ysyx_25050137_REG_ADDR-1:0] waddr_idu_to_exu;
    wire ecall_idu_to_exu;
    wire [1:0] waddr_csr_idu_to_exu;

    wire valid_idu_to_exu;
    wire ready_idu_to_exu;

    wire [2:0] raddr_csr;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rdata_csr;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] wdata;
    wire [`ysyx_25050137_REG_ADDR-1:0] waddr;
    wire reg_write;

    //write csr
    wire csr_write;
    wire [1:0] waddr_csr;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] csr_wdata;
    wire ecall;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] alu_result_exu_to_lsu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rs1_exu_to_lsu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rs2_exu_to_lsu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_l_rs1_exu_to_lsu;
    wire MemRead_exu_to_lsu;
    wire MemWrite_exu_to_lsu;
    wire [3:0] wmask_exu_to_lsu;
    wire [2:0] rmask_exu_to_lsu;
    wire wb_src_exu_to_lsu;
    wire csr_write_exu_to_lsu;
    wire csr_wdta_src_exu_to_lsu;
    wire reg_write_exu_to_lsu;
    wire [`ysyx_25050137_REG_ADDR-1:0] waddr_exu_to_lsu;
    wire ecall_exu_to_lsu;
    wire [1:0] waddr_csr_exu_to_lsu;

    wire valid_exu_to_lsu;
    wire ready_exu_to_lsu;

    wire npc_valid;
    wire rd_exu_valid;

    wire [`ysyx_25050137_PC_WIDTH-1:0] pc_exu_to_lsu;

    wire [`ysyx_25050137_CPU_WIDTH-1:0] alu_result_lsu_to_wbu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] rs1_lsu_to_wbu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] csr_rdata_l_rs1_lsu_to_wbu;
    wire [`ysyx_25050137_CPU_WIDTH-1:0] datamem_readdata_lsu_to_wbu;
    wire [2:0] rmask_lsu_to_wbu;
    wire wb_src_lsu_to_wbu;
    wire csr_write_lsu_to_wbu;
    wire csr_wdata_src_lsu_to_wbu;
    wire reg_write_lsu_to_wbu;
    wire [`ysyx_25050137_REG_ADDR-1:0] waddr_lsu_to_wbu;
    wire ecall_lsu_to_wbu;
    wire [1:0] waddr_csr_lsu_to_wbu;

    wire valid_lsu_to_wbu;
    wire ready_lsu_to_wbu;

    wire rd_lsu_valid;

    wire [`ysyx_25050137_PC_WIDTH-1:0] pc_lsu_to_wbu;

    wire rd_wbu_valid;

    wire [`ysyx_25050137_PC_WIDTH-1:0] pc_wbu_out;

    ysyx_25050137_ifu IFU(
        .clk(clk),
        .reset(reset),
        .fencei(fencei),

        .araddr_o(ifu_araddr),
        .arid_o(ifu_arid),
        .arlen_o(ifu_arlen),
        .arsize_o(ifu_arsize),
        .arburst_o(ifu_arburst),
        .arvalid_o(ifu_arvalid),
        .arready_i(ifu_arready),
        .rdata_i(ifu_rdata),
        .rresp_i(ifu_rresp),
        .rlast_i(ifu_rlast),
        .rid_i(ifu_rid),
        .rvalid_i(ifu_rvalid),
        .rready_o(ifu_rready),

        .npc_i(npc),
        .npc_valid(npc_valid),
        .reset_o(reset_ifu),

        .pc_o(pc_ifu_to_idu),
        .inst_o(inst_ifu_to_idu),

        .ifu_valid_o(valid_ifu_to_idu),
        .ifu_ready_i(ready_ifu_to_idu)

    );
    //assign pc_to_mem = pc_ifu_to_idu;
    //assign inst_from_mem = inst_ifu_to_idu;

`ifdef VERILATOR_SIM
    

    ysyx_25050137_icache #(.NUM_BLOCKS(32)) ICACHE (
        .clk(clk),
        .reset(reset),

        //CPU
        .cpu_araddr_i(ifu_araddr),
        .cpu_arid_i(ifu_arid),
        .cpu_arlen_i(ifu_arlen),
        .cpu_arsize_i(ifu_arsize),
        .cpu_arburst_i(ifu_arburst),
        .cpu_arvalid_i(ifu_arvalid),
        .cpu_arready_o(ifu_arready),

        .cpu_rdata_o(ifu_rdata),
        .cpu_rresp_o(ifu_rresp),
        .cpu_rlast_o(ifu_rlast),
        .cpu_rid_o(ifu_rid),
        .cpu_rvalid_o(ifu_rvalid),
        .cpu_rready_i(ifu_rready),
        //mem
        .mem_araddr_o(cache_araddr),
        .mem_arid_o(cache_arid),
        .mem_arlen_o(cache_arlen),
        .mem_arsize_o(cache_arsize),
        .mem_arburst_o(cache_arburst),
        .mem_arvalid_o(cache_arvalid),
        .mem_arready_i(cache_arready),
        .mem_rdata_i(cache_rdata),
        .mem_rresp_i(cache_rresp),
        .mem_rlast_i(cache_rlast),
        .mem_rid_i(cache_rid),
        .mem_rvalid_i(cache_rvalid),
        .mem_rready_o(cache_rready),

        .fencei(fencei)
    );

`else
    ysyx_25050137_icache ICACHE(
        .clk(clk),
        .reset(reset),

        //CPU
        .cpu_araddr_i(ifu_araddr),
        .cpu_arid_i(ifu_arid),
        .cpu_arlen_i(ifu_arlen),
        .cpu_arsize_i(ifu_arsize),
        .cpu_arburst_i(ifu_arburst),
        .cpu_arvalid_i(ifu_arvalid),
        .cpu_arready_o(ifu_arready),

        .cpu_rdata_o(ifu_rdata),
        .cpu_rresp_o(ifu_rresp),
        .cpu_rlast_o(ifu_rlast),
        .cpu_rid_o(ifu_rid),
        .cpu_rvalid_o(ifu_rvalid),
        .cpu_rready_i(ifu_rready),
        //mem
        .mem_araddr_o(cache_araddr),
        .mem_arid_o(cache_arid),
        .mem_arlen_o(cache_arlen),
        .mem_arsize_o(cache_arsize),
        .mem_arburst_o(cache_arburst),
        .mem_arvalid_o(cache_arvalid),
        .mem_arready_i(cache_arready),
        .mem_rdata_i(cache_rdata),
        .mem_rresp_i(cache_rresp),
        .mem_rlast_i(cache_rlast),
        .mem_rid_i(cache_rid),
        .mem_rvalid_i(cache_rvalid),
        .mem_rready_o(cache_rready),

        .fencei(fencei)
    );
`endif 

    ysyx_25050137_axi_arbiter AXI_Arbiter(
        .clk(clk),
        .reset(reset),

 //a
        .araddr_i_a(cache_araddr),
        .arid_i_a(cache_arid),
        .arlen_i_a(cache_arlen),
        .arsize_i_a(cache_arsize),
        .arburst_i_a(cache_arburst),
        .arvalid_i_a(cache_arvalid),
        .arready_o_a(cache_arready),

        .rdata_o_a(cache_rdata),
        .rresp_o_a(cache_rresp),
        .rlast_o_a(cache_rlast),
        .rid_o_a(cache_rid),
        .rvalid_o_a(cache_rvalid),
        .rready_i_a(cache_rready),

        .awaddr_i_a(0),
        .awid_i_a(4'b0),
        .awlen_i_a(8'b0),
        .awsize_i_a(3'b0),
        .awburst_i_a(2'b0),
        .awvalid_i_a(1'b0),
        .awready_o_a(),

        .wdata_i_a(0),
        .wstrb_i_a(4'b0),
        .wlast_i_a(1'b0),
        .wvalid_i_a(1'b0),
        .wready_o_a(),

        .bresp_o_a(),
        .bid_o_a(),
        .bvalid_o_a(),
        .bready_i_a(1'b0),

        //b
        .araddr_i_b(lsu_araddr),
        .arid_i_b(lsu_arid),
        .arlen_i_b(lsu_arlen),
        .arsize_i_b(lsu_arsize),
        .arburst_i_b(lsu_arburst),
        .arvalid_i_b(lsu_arvalid),
        .arready_o_b(lsu_arready),

        .rdata_o_b(lsu_rdata),
        .rresp_o_b(lsu_rresp),
        .rlast_o_b(lsu_rlast),
        .rid_o_b(lsu_rid),
        .rvalid_o_b(lsu_rvalid),
        .rready_i_b(lsu_rready),

        .awaddr_i_b(lsu_awaddr),
        .awid_i_b(lsu_awid),
        .awlen_i_b(lsu_awlen),
        .awsize_i_b(lsu_awsize),
        .awburst_i_b(lsu_awburst),
        .awvalid_i_b(lsu_awvalid),
        .awready_o_b(lsu_awready),

        .wdata_i_b(lsu_wdata),
        .wstrb_i_b(lsu_wstrb),
        .wlast_i_b(lsu_wlast),
        .wvalid_i_b(lsu_wvalid),
        .wready_o_b(lsu_wready),

        .bresp_o_b(lsu_bresp),
        .bid_o_b(lsu_bid),
        .bvalid_o_b(lsu_bvalid),
        .bready_i_b(lsu_bready),

        //to xbar
        .araddr_o(axi_araddr),
        .arid_o(axi_arid),
        .arlen_o(axi_arlen),
        .arsize_o(axi_arsize),
        .arburst_o(axi_arburst),
        .arvalid_o(axi_arvalid),
        .arready_i(axi_arready),

        .rdata_i(axi_rdata),
        .rresp_i(axi_rresp),
        .rlast_i(axi_rlast),
        .rid_i(axi_rid),
        .rvalid_i(axi_rvalid),
        .rready_o(axi_rready),

        .awaddr_o(axi_awaddr),
        .awid_o(axi_awid),
        .awlen_o(axi_awlen),
        .awsize_o(axi_awsize),
        .awburst_o(axi_awburst),
        .awvalid_o(axi_awvalid),
        .awready_i(axi_awready),

        .wdata_o(axi_wdata),
        .wstrb_o(axi_wstrb),
        .wlast_o(axi_wlast),
        .wvalid_o(axi_wvalid),
        .wready_i(axi_wready),

        .bresp_i(axi_bresp),
        .bid_i(axi_bid),
        .bvalid_i(axi_bvalid),
        .bready_o(axi_bready)

    );

    ysyx_25050137_xbar Xbar(
        .clk(clk),
        .reset(reset),

        //in
        .axi_araddr_i(axi_araddr),
        .axi_arid_i(axi_arid),
        .axi_arlen_i(axi_arlen),
        .axi_arsize_i(axi_arsize),
        .axi_arburst_i(axi_arburst),
        .axi_arvalid_i(axi_arvalid),
        .axi_arready_o(axi_arready),

        .axi_rdata_o(axi_rdata),
        .axi_rresp_o(axi_rresp),
        .axi_rlast_o(axi_rlast),
        .axi_rid_o(axi_rid),
        .axi_rvalid_o(axi_rvalid),
        .axi_rready_i(axi_rready),

        .axi_awaddr_i(axi_awaddr),
        .axi_awid_i(axi_awid),
        .axi_awlen_i(axi_awlen),
        .axi_awsize_i(axi_awsize),
        .axi_awburst_i(axi_awburst),
        .axi_awvalid_i(axi_awvalid),
        .axi_awready_o(axi_awready),
        
        .axi_wdata_i(axi_wdata),
        .axi_wstrb_i(axi_wstrb),
        .axi_wlast_i(axi_wlast),
        .axi_wvalid_i(axi_wvalid),
        .axi_wready_o(axi_wready),

        .axi_bresp_o(axi_bresp),
        .axi_bid_o(axi_bid),
        .axi_bvalid_o(axi_bvalid),
        .axi_bready_i(axi_bready),

        //to mem
        .sram_araddr_o(io_master_araddr),
        .sram_arid_o(io_master_arid),
        .sram_arlen_o(io_master_arlen),
        .sram_arsize_o(io_master_arsize),
        .sram_arburst_o(io_master_arburst),
        .sram_arvalid_o(io_master_arvalid),
        .sram_arready_i(io_master_arready),

        .sram_rdata_i(io_master_rdata),
        .sram_rresp_i(io_master_rresp),
        .sram_rlast_i(io_master_rlast),
        .sram_rid_i(io_master_rid),
        .sram_rvalid_i(io_master_rvalid),
        .sram_rready_o(io_master_rready),

        .sram_awaddr_o(io_master_awaddr),
        .sram_awid_o(io_master_awid),
        .sram_awlen_o(io_master_awlen),
        .sram_awsize_o(io_master_awsize),
        .sram_awburst_o(io_master_awburst),
        .sram_awvalid_o(io_master_awvalid),
        .sram_awready_i(io_master_awready),

        .sram_wdata_o(io_master_wdata),
        .sram_wstrb_o(io_master_wstrb),
        .sram_wlast_o(io_master_wlast),
        .sram_wvalid_o(io_master_wvalid),
        .sram_wready_i(io_master_wready),

        .sram_bresp_i(io_master_bresp),
        .sram_bid_i(io_master_bid),
        .sram_bvalid_i(io_master_bvalid),
        .sram_bready_o(io_master_bready),

        //to clint
        .clint_araddr_o(clint_araddr),
        .clint_arid_o(clint_arid),
        .clint_arlen_o(clint_arlen),
        .clint_arsize_o(clint_arsize),
        .clint_arburst_o(clint_arburst),
        .clint_arvalid_o(clint_arvalid),
        .clint_arready_i(clint_arready),

        .clint_rdata_i(clint_rdata),
        .clint_rresp_i(clint_rresp),
        .clint_rlast_i(clint_rlast),
        .clint_rid_i(clint_rid),
        .clint_rvalid_i(clint_rvalid),
        .clint_rready_o(clint_rready),

        .clint_awaddr_o(clint_awaddr),
        .clint_awid_o(clint_awid),
        .clint_awlen_o(clint_awlen),
        .clint_awsize_o(clint_awsize),
        .clint_awburst_o(clint_awburst),
        .clint_awvalid_o(clint_awvalid),
        .clint_awready_i(clint_awready),

        .clint_wdata_o(clint_wdata),
        .clint_wstrb_o(clint_wstrb),
        .clint_wlast_o(clint_wlast),
        .clint_wvalid_o(clint_wvalid),
        .clint_wready_i(clint_wready),

        .clint_bresp_i(clint_bresp),
        .clint_bid_i(clint_bid),
        .clint_bvalid_i(clint_bvalid),
        .clint_bready_o(clint_bready)
    );


    ysyx_25050137_clint CLINT(
        .clk(clk),
        .reset(reset),

        .araddr_i(clint_araddr),
        .arid_i(clint_arid),
        .arlen_i(clint_arlen),
        .arsize_i(clint_arsize),
        .arburst_i(clint_arburst),
        .arvalid_i(clint_arvalid),
        .arready_o(clint_arready),

        .rdata_o(clint_rdata),
        .rresp_o(clint_rresp),
        .rlast_o(clint_rlast),
        .rid_o(clint_rid),
        .rvalid_o(clint_rvalid),
        .rready_i(clint_rready),

        .awaddr_i(clint_awaddr),
        .awid_i(clint_awid),
        .awlen_i(clint_awlen),
        .awsize_i(clint_awsize),
        .awburst_i(clint_awburst),
        .awvalid_i(clint_awvalid),
        .awready_o(clint_awready),

        .wdata_i(clint_wdata),
        .wstrb_i(clint_wstrb),
        .wlast_i(clint_wlast),
        .wvalid_i(clint_wvalid),
        .wready_o(clint_wready),

        .bresp_o(clint_bresp),
        .bid_o(clint_bid),
        .bvalid_o(clint_bvalid),
        .bready_i(clint_bready)
    );

    

    ysyx_25050137_idu IDU(
        .clk(clk),
        .reset(reset),
        .reset_ifu(reset_ifu),
        //regfiles
        .raddr1(raddr1),
        .raddr2(raddr2),
        .rdata1(rdata1),
        .rdata2(rdata2),
        .raddr_csr(raddr_csr),
        .rdata_csr(rdata_csr),

        //ifu to idu
        .pc_i(pc_ifu_to_idu),
        .inst_i(inst_ifu_to_idu),

        .idu_valid_i(valid_ifu_to_idu),
        .idu_ready_o(ready_ifu_to_idu),

        //idu to exu
        .pc_o(pc_idu_to_exu),
        .rs1_o(rs1_idu_to_exu),
        .rs2_o(rs2_idu_to_exu),
        .imm_o(imm_idu_to_exu),
        .csr_rdata_o(csr_rdata_idu_to_exu),
        .a_in_src_o(a_in_src_idu_to_exu),
        .b_in_src_o(b_in_src_idu_to_exu),
        .pc_srcs_o(pc_srcs_idu_to_exu),
        .adder_a_src_o(adder_a_src_idu_to_exu),
        .adder_out_src_o(adder_out_src_idu_to_exu),
        .alu_op(alu_op_idu_to_exu),
        //idu to exu to lsu or wbu
        .MemRead_o(MemRead_idu_to_exu),
        .MemWrite_o(MemWrite_idu_to_exu),
        .wmask_o(wmask_idu_to_exu),
        .rmask_o(rmask_idu_to_exu),
        .wb_src_o(wb_src_idu_to_exu),
        .csr_write_o(csr_write_idu_to_exu),
        .csr_wdata_src_o(csr_wdata_src_idu_to_exu),
        .reg_write_o(reg_write_idu_to_exu),
        .waddr_o(waddr_idu_to_exu),
        .ecall_o(ecall_idu_to_exu),
        .waddr_csr_o(waddr_csr_idu_to_exu),

        .idu_valid_o(valid_idu_to_exu),
        .idu_ready_i(ready_idu_to_exu),

        

        .fencei(fencei),
        //.exu_rd(reg_write_exu_to_lsu && rd_exu_valid ? waddr_exu_to_lsu : 0),
        //.lsu_rd(reg_write_lsu_to_wbu && rd_lsu_valid ? waddr_lsu_to_wbu : 0),
        //.wbu_rd(reg_write && rd_wbu_valid ? waddr : 0)

        // ======== Forwarding接口 (新增/修改) ========
        // EXU级前递
        .exu_rd(waddr_exu_to_lsu),
        .exu_rd_valid(rd_exu_valid),
        .exu_reg_write(reg_write_exu_to_lsu),    // 新增: EXU级是否写寄存器
        .exu_MemRead(MemRead_exu_to_lsu),      // 新增: EXU级是否为Load指令 (load-use需要stall)
        .exu_fwd_data(alu_result_exu_to_lsu),     // 新增: EXU级前递数据 (ALU结果)

        // LSU级前递
        .lsu_rd(waddr_lsu_to_wbu),
        .lsu_rd_valid(rd_lsu_valid),
        .lsu_reg_write(reg_write_lsu_to_wbu),    // 新增: LSU级是否写寄存器
        .lsu_fwd_data(alu_result_lsu_to_wbu),     // 新增: LSU级前递数据 (ALU结果或Mem读取结果)

        // WBU级前递
        .wbu_rd(waddr),
        .wbu_rd_valid(rd_wbu_valid),
        .wbu_reg_write(reg_write),    // 新增: WBU级是否写寄存器
        .wbu_fwd_data(wdata)      // 新增: WBU级前递数据 (最终写回数据)
    );

    

`ifdef VERILATOR_SIM
    wire [31:0] reg_file [0:15];
    wire [31:0] csr_reg [0:3];
    ysyx_25050137_regfile Rgefile (
        .clk(clk),
        .reset(reset),
        .wdata(wdata),
        .waddr(waddr), //rd
        .wen(reg_write),
        .raddr1(raddr1), //rs1
        .rdata1(rdata1),
        .raddr2(raddr2), //rs2
        .rdata2(rdata2),
        .raddr_csr(raddr_csr),
        .rdata_csr(rdata_csr),
        .waddr_csr(waddr_csr),
        .wdata_csr(csr_wdata),
        .wen_csr(csr_write),
        .ecall(ecall),
        .pc(pc_wbu_out),
        .reg_file(reg_file),//difftest
        .csr_reg(csr_reg)//difftest
    );
`else 
    ysyx_25050137_regfile Rgefile (
        .clk(clk),
        .reset(reset),
        .wdata(wdata),
        .waddr(waddr), //rd
        .wen(reg_write),
        .raddr1(raddr1), //rs1
        .rdata1(rdata1),
        .raddr2(raddr2), //rs2
        .rdata2(rdata2),
        .raddr_csr(raddr_csr),
        .rdata_csr(rdata_csr),
        .waddr_csr(waddr_csr),
        .wdata_csr(csr_wdata),
        .wen_csr(csr_write),
        .ecall(ecall),
        .pc(pc_wbu_out)
        
    );
`endif    
    

    ysyx_25050137_exu EXU(
        .clk(clk),
        .reset(reset),
        .reset_ifu(reset_ifu),
        //idu to exu
        .pc_i(pc_idu_to_exu),
        .rs1_i(rs1_idu_to_exu),
        .rs2_i(rs2_idu_to_exu),
        .imm_i(imm_idu_to_exu),
        .csr_rdata_i(csr_rdata_idu_to_exu),
        .a_in_src_i(a_in_src_idu_to_exu),
        .b_in_src_i(b_in_src_idu_to_exu),
        .pc_srcs_i(pc_srcs_idu_to_exu),
        .adder_a_src_i(adder_a_src_idu_to_exu),
        .adder_out_src_i(adder_out_src_idu_to_exu),
        .alu_op_i(alu_op_idu_to_exu),
        //idu to exu to lsu or wbu
        .MemRead_i(MemRead_idu_to_exu),
        .MemWrite_i(MemWrite_idu_to_exu),
        .wmask_i(wmask_idu_to_exu),
        .rmask_i(rmask_idu_to_exu),
        .wb_src_i(wb_src_idu_to_exu),
        .csr_write_i(csr_write_idu_to_exu),
        .csr_wdata_src_i(csr_wdata_src_idu_to_exu),
        .reg_write_i(reg_write_idu_to_exu),
        .waddr_i(waddr_idu_to_exu),
        .ecall_i(ecall_idu_to_exu),
        .waddr_csr_i(waddr_csr_idu_to_exu),

        .exu_valid_i(valid_idu_to_exu),
        .exu_ready_o(ready_idu_to_exu),

        //exu to lsu
        .alu_result_o(alu_result_exu_to_lsu),
        .rs1_o(rs1_exu_to_lsu),
        .rs2_o(rs2_exu_to_lsu),
        .csr_rdata_l_rs1_o(csr_rdata_l_rs1_exu_to_lsu),
        .npc_o(npc),
        .MemRead_o(MemRead_exu_to_lsu),
        .MemWrite_o(MemWrite_exu_to_lsu),
        .wmask_o(wmask_exu_to_lsu),
        .rmask_o(rmask_exu_to_lsu),
        .wb_src_o(wb_src_exu_to_lsu),
        .csr_write_o(csr_write_exu_to_lsu),
        .csr_wdata_src_o(csr_wdta_src_exu_to_lsu),
        .reg_write_o(reg_write_exu_to_lsu),
        .waddr_o(waddr_exu_to_lsu),
        .ecall_o(ecall_exu_to_lsu),
        .waddr_csr_o(waddr_csr_exu_to_lsu),

        .exu_valid_o(valid_exu_to_lsu),
        .exu_ready_i(ready_exu_to_lsu),
        .npc_valid(npc_valid),
        .rd_exu_valid(rd_exu_valid),
        
        .pc_o(pc_exu_to_lsu)
    );

    

    ysyx_25050137_lsu LSU(
        .clk(clk),
        .reset(reset),

        //exu to lsu
        .alu_result_i(alu_result_exu_to_lsu),
        .rs1_i(rs1_exu_to_lsu),
        .rs2_i(rs2_exu_to_lsu),
        .csr_rdata_l_rs1_i(csr_rdata_l_rs1_exu_to_lsu),
        .MemRead_i(MemRead_exu_to_lsu),
        .MemWrite_i(MemWrite_exu_to_lsu),
        .wmask_i(wmask_exu_to_lsu),
        .rmask_i(rmask_exu_to_lsu),
        .wb_src_i(wb_src_exu_to_lsu),
        .csr_write_i(csr_write_exu_to_lsu),
        .csr_wdata_src_i(csr_wdta_src_exu_to_lsu),
        .reg_write_i(reg_write_exu_to_lsu),
        .waddr_i(waddr_exu_to_lsu),
        .ecall_i(ecall_exu_to_lsu),
        .waddr_csr_i(waddr_csr_exu_to_lsu),

        .lsu_valid_i(valid_exu_to_lsu),
        .lsu_ready_o(ready_exu_to_lsu),
        
        //lsu to wbu
        .alu_result_o(alu_result_lsu_to_wbu),
        .rs1_o(rs1_lsu_to_wbu),
        .csr_rdata_l_rs1_o(csr_rdata_l_rs1_lsu_to_wbu),
        .datamem_readdata_o(datamem_readdata_lsu_to_wbu),
        .rmask_o(rmask_lsu_to_wbu),
        .wb_src_o(wb_src_lsu_to_wbu),
        .csr_write_o(csr_write_lsu_to_wbu),
        .csr_wdata_src_o(csr_wdata_src_lsu_to_wbu),
        .reg_write_o(reg_write_lsu_to_wbu),
        .waddr_o(waddr_lsu_to_wbu),
        .ecall_o(ecall_lsu_to_wbu),
        .waddr_csr_o(waddr_csr_lsu_to_wbu),

        .lsu_valid_o(valid_lsu_to_wbu),
        .lsu_ready_i(ready_lsu_to_wbu),

        //to mem
        .araddr_o(lsu_araddr),
        .arid_o(lsu_arid),
        .arlen_o(lsu_arlen),
        .arsize_o(lsu_arsize),
        .arburst_o(lsu_arburst),
        .arvalid_o(lsu_arvalid),
        .arready_i(lsu_arready),

        .rdata_i(lsu_rdata),
        .rresp_i(lsu_rresp),
        .rlast_i(lsu_rlast),
        .rid_i(lsu_rid),
        .rvalid_i(lsu_rvalid),
        .rready_o(lsu_rready),

        .awaddr_o(lsu_awaddr),
        .awid_o(lsu_awid),
        .awlen_o(lsu_awlen),
        .awsize_o(lsu_awsize),
        .awburst_o(lsu_awburst),
        .awvalid_o(lsu_awvalid),
        .awready_i(lsu_awready),

        .wdata_o(lsu_wdata),
        .wstrb_o(lsu_wstrb),
        .wlast_o(lsu_wlast),
        .wvalid_o(lsu_wvalid),
        .wready_i(lsu_wready),
        
        .bresp_i(lsu_bresp),
        .bid_i(lsu_bid),
        .bvalid_i(lsu_bvalid),
        .bready_o(lsu_bready),

        .rd_lsu_valid(rd_lsu_valid),

        .pc_i(pc_exu_to_lsu),
        .pc_o(pc_lsu_to_wbu)
    );

    
    
    ysyx_25050137_wbu WBU(
        .clk(clk),
        .reset(reset),
        //lsu to wbu
        .alu_result_i(alu_result_lsu_to_wbu),
        .rs1_i(rs1_lsu_to_wbu),
        .csr_rdata_l_rs1_i(csr_rdata_l_rs1_lsu_to_wbu),
        .datamem_readdata_i(datamem_readdata_lsu_to_wbu),
        .rmask_i(rmask_lsu_to_wbu),
        .wb_src_i(wb_src_lsu_to_wbu),
        .csr_write_i(csr_write_lsu_to_wbu),
        .csr_wdata_src_i(csr_wdata_src_lsu_to_wbu),
        .reg_write_i(reg_write_lsu_to_wbu),
        .waddr_i(waddr_lsu_to_wbu),
        .ecall_i(ecall_lsu_to_wbu),
        .waddr_csr_i(waddr_csr_lsu_to_wbu),

        .wbu_valid_i(valid_lsu_to_wbu),
        .wbu_ready_o(ready_lsu_to_wbu),

        //wbu to ifu


        //write back
        .csr_wdata_o(csr_wdata),
        .csr_write_o(csr_write),
        .wdata_o(wdata),
        .reg_write_o(reg_write),
        .waddr_o(waddr),
        .ecall_o(ecall),
        .waddr_csr_o(waddr_csr),

        .rd_wbu_valid(rd_wbu_valid),
        .pc_i(pc_lsu_to_wbu),
        .pc_o(pc_wbu_out)
    );

`ifdef VERILATOR_SIM

    always@(*) begin       
        if(inst_ifu_to_idu == 32'h00100073) begin
            ebreak();
            //$finish;
        end
    end

    always@(*) begin
        reg_return_value(reg_file[0],reg_file[1],reg_file[2],reg_file[3],reg_file[4],reg_file[5],reg_file[6],
        reg_file[7],reg_file[8],reg_file[9],reg_file[10],reg_file[11],reg_file[12],reg_file[13],reg_file[14],
        reg_file[15],pc_lsu_to_wbu,csr_reg[2],csr_reg[0],csr_reg[3],csr_reg[1]);
    end
`endif 

`ifdef __ICARUS__
    always@(*) begin       
        if(inst_ifu_to_idu == 32'h00100073) begin
           //ebreak();

           $finish;
      end
    end
`endif 
    
endmodule
