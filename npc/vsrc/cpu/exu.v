module ysyx_26010028_exu (
    input             clock,
    input             reset,

    input             pipe_valid,
    output            pipe_ready,
    input      [31:0] pipe_pc,
    input      [31:0] pipe_inst,
    input      [ 6:0] pipe_opcode,
    input      [ 2:0] pipe_funct3,
    input      [ 6:0] pipe_funct7,
    input      [ 4:0] pipe_rd,
    input      [11:0] pipe_csr_addr,
    input      [31:0] pipe_rs1_value,
    input      [31:0] pipe_rs2_value,
    input      [31:0] pipe_imm,
    input             pipe_rf_wen,
    input             pipe_load,
    input             pipe_store,
    input             pipe_fence_i,

    output            retire_valid,
    output     [31:0] retire_pc,
    output     [31:0] retire_inst,
    output     [31:0] retire_next_pc,
    input      [63:0] mtime_value,

    output            redirect_valid,
    output     [31:0] redirect_pc,
    output            fence_done,

    output            wb_rf_wen,
    output     [ 4:0] wb_rf_waddr,
    output     [31:0] wb_rf_wdata,

    output     [31:0] csr_probe_status,
    output     [31:0] csr_probe_vector,
    output     [31:0] csr_probe_epc,
    output     [31:0] csr_probe_cause,

    output     [31:0] lsu_master_araddr,
    output     [ 2:0] lsu_master_arsize,
    output            lsu_master_arvalid,
    input             lsu_master_arready,
    input      [31:0] lsu_master_rdata,
    input      [ 1:0] lsu_master_rresp,
    input             lsu_master_rvalid,
    output            lsu_master_rready,

    output     [31:0] lsu_master_awaddr,
    output     [ 2:0] lsu_master_awsize,
    output            lsu_master_awvalid,
    input             lsu_master_awready,
    output     [31:0] lsu_master_wdata,
    output     [ 3:0] lsu_master_wstrb,
    output            lsu_master_wvalid,
    input             lsu_master_wready,
    input      [ 1:0] lsu_master_bresp,
    input             lsu_master_bvalid,
    output            lsu_master_bready
);
    localparam [6:0] OP_ALU_REG   = 7'b011_0011;
    localparam [6:0] OP_ALU_IMM   = 7'b001_0011;
    localparam [6:0] OP_MEM_RD  = 7'b000_0011;
    localparam [6:0] OP_JUMP_REG  = 7'b110_0111;
    localparam [6:0] OP_MEM_WR = 7'b010_0011;
    localparam [6:0] OP_BRANCH    = 7'b110_0011;
    localparam [6:0] OP_UPPER   = 7'b011_0111;
    localparam [6:0] OP_PC_REL = 7'b001_0111;
    localparam [6:0] OP_JUMP   = 7'b110_1111;
    localparam [6:0] OP_CSR   = 7'b111_0011;
    localparam [6:0] OP_FENCEI = 7'b000_1111;

    localparam [11:0] CSR_STAT   = 12'h300;
    localparam [11:0] CSR_VECTOR     = 12'h305;
    localparam [11:0] CSR_EXC_PC      = 12'h341;
    localparam [11:0] CSR_CAUSE    = 12'h342;
    localparam [11:0] CSR_VENDOR = 12'hF11;
    localparam [11:0] CSR_ARCH   = 12'hF12;

    localparam [11:0] SYS_ECALL  = 12'h000;
    localparam [11:0] SYS_EBREAK = 12'h001;
    localparam [11:0] SYS_MRET   = 12'h302;

    localparam [2:0] FN_ADD = 3'b000;
    localparam [2:0] FN_SLL     = 3'b001;
    localparam [2:0] FN_SLT     = 3'b010;
    localparam [2:0] FN_SLTU    = 3'b011;
    localparam [2:0] FN_XOR     = 3'b100;
    localparam [2:0] FN_SR = 3'b101;
    localparam [2:0] FN_OR      = 3'b110;
    localparam [2:0] FN_AND     = 3'b111;

    localparam [15:0] TMR_BASE_HI = 16'h0200;
    localparam [15:0] TMR_LO  = 16'hbff8;
    localparam [15:0] TMR_HI = 16'hbffc;

    wire system_inst = (pipe_opcode == OP_CSR);
    wire privileged_inst = system_inst && (pipe_funct3 == 3'b000);
    wire take_ecall  = privileged_inst && (pipe_csr_addr == SYS_ECALL);
    wire take_ebreak = privileged_inst && (pipe_csr_addr == SYS_EBREAK);
    wire take_mret   = privileged_inst && (pipe_csr_addr == SYS_MRET);
    wire [31:0] csr_operand = pipe_funct3[2] ? pipe_imm : pipe_rs1_value;
    wire [31:0] csr_read_data;

    wire [31:0] snpc = pipe_pc + 32'd4;
    wire       branch_taken;
    wire [31:0] sub_src = (pipe_opcode == OP_ALU_IMM) ? pipe_imm : pipe_rs2_value;
    wire [31:0] sub_diff = pipe_rs1_value - sub_src;
    wire        eq = (pipe_rs1_value == sub_src);
    wire        slt = ($signed(pipe_rs1_value) < $signed(sub_src));
    wire        sltu = (pipe_rs1_value < sub_src);
    reg         branch_taken_value;
    reg [31:0] add_src1;
    reg [31:0] add_src2;
    always @(*) begin
        add_src1 = pipe_rs1_value;
        add_src2 = pipe_imm;
        case (pipe_opcode)
            OP_ALU_REG: begin
                add_src1 = pipe_rs1_value;
                add_src2 = pipe_rs2_value;
            end
            OP_PC_REL,
            OP_JUMP,
            OP_BRANCH: begin
                add_src1 = pipe_pc;
                add_src2 = pipe_imm;
            end
            default: begin end
        endcase
    end

    wire [31:0] add_sum = add_src1 + add_src2;

    always @(*) begin
        case (pipe_funct3)
            3'b000: branch_taken_value = eq;
            3'b001: branch_taken_value = !eq;
            3'b100: branch_taken_value = slt;
            3'b101: branch_taken_value = !slt;
            3'b110: branch_taken_value = sltu;
            3'b111: branch_taken_value = !sltu;
            default: branch_taken_value = 1'b0;
        endcase
    end
    assign branch_taken = branch_taken_value;
    wire [31:0] arith_result = (pipe_opcode == OP_ALU_REG && pipe_funct3 == FN_ADD && pipe_funct7[5]) ? sub_diff : add_sum;
    wire [31:0] alu_result = select_alu(pipe_funct3, pipe_funct7, arith_result, pipe_rs1_value, add_src2, slt, sltu);

    wire branch_redirect = (pipe_opcode == OP_BRANCH) && branch_taken;
    wire jump_redirect = (pipe_opcode == OP_JUMP) || (pipe_opcode == OP_JUMP_REG);
    wire redirect_request = branch_redirect || jump_redirect || take_ecall || take_mret || pipe_fence_i;
    wire [31:0] dnpc =
        ((pipe_opcode == OP_BRANCH) ||
         (pipe_opcode == OP_JUMP) ||
         (pipe_opcode == OP_JUMP_REG)) ? {add_sum[31:1], 1'b0} :
        take_ecall ? {csr_probe_vector[31:2], 2'b00} :
        take_mret  ? csr_probe_epc :
                     snpc;

    wire lsu_ready;
    wire lsu_complete;
    wire [31:0] load_result;

    ysyx_26010028_lsu #(
        .TIMER_BASE_HI (TMR_BASE_HI),
        .TIMER_LOW_OFF (TMR_LO),
        .TIMER_HIGH_OFF (TMR_HI)
    ) lsu (
        .clock         (clock),
        .reset         (reset),

        .pipe_valid   (pipe_valid),
        .pipe_ready   (lsu_ready),
        .pipe_load    (pipe_load),
        .pipe_store    (pipe_store),
        .pipe_funct3     (pipe_funct3),
        .exu_data      (pipe_rs2_value),
        .exu_addr      (add_sum),

        .mtime_value  (mtime_value),

        .retire_valid  (lsu_complete),
        .load_data     (load_result),

        .lsu_araddr    (lsu_master_araddr),
        .lsu_arsize    (lsu_master_arsize),
        .lsu_arvalid   (lsu_master_arvalid),
        .lsu_arready   (lsu_master_arready),

        .lsu_rdata     (lsu_master_rdata),
        .lsu_rresp     (lsu_master_rresp),
        .lsu_rvalid    (lsu_master_rvalid),
        .lsu_rready    (lsu_master_rready),

        .lsu_awaddr    (lsu_master_awaddr),
        .lsu_awsize    (lsu_master_awsize),
        .lsu_awvalid   (lsu_master_awvalid),
        .lsu_awready   (lsu_master_awready),

        .lsu_wdata     (lsu_master_wdata),
        .lsu_wstrb     (lsu_master_wstrb),
        .lsu_wvalid    (lsu_master_wvalid),
        .lsu_wready    (lsu_master_wready),
        
        .lsu_bresp     (lsu_master_bresp),
        .lsu_bvalid    (lsu_master_bvalid),
        .lsu_bready    (lsu_master_bready)
    );

    ysyx_26010028_csr_file csr_file (
        .clock        (clock),
        .reset        (reset),
        .address      (pipe_csr_addr),
        .read_data    (csr_read_data),

        .retire_valid (lsu_complete),
        .system_inst  (system_inst),
        .funct3       (pipe_funct3),
        .operand      (csr_operand),
        .retire_pc    (pipe_pc),
        .take_ecall   (take_ecall),
        .take_mret    (take_mret),
        
        .mstatus      (csr_probe_status),
        .mtvec        (csr_probe_vector),
        .mepc         (csr_probe_epc),
        .mcause       (csr_probe_cause)
    );

    reg [31:0] writeback_data;
    always @(*) begin
        case (pipe_opcode)
            OP_ALU_REG,
            OP_ALU_IMM:   writeback_data = alu_result;
            OP_UPPER:   writeback_data = pipe_imm;
            OP_PC_REL: writeback_data = add_sum;
            OP_MEM_RD:  writeback_data = load_result;
            OP_JUMP,
            OP_JUMP_REG:  writeback_data = snpc;
            OP_CSR:   writeback_data = csr_read_data;
            default:  writeback_data = 32'b0;
        endcase
    end

    assign pipe_ready   = lsu_ready;
    assign retire_valid  = lsu_complete;
    assign retire_pc     = pipe_pc;
    assign retire_inst   = pipe_inst;
    assign retire_next_pc = redirect_request ? dnpc : snpc;

    assign redirect_valid    = lsu_complete && redirect_request;
    assign redirect_pc = dnpc;
    assign fence_done     = lsu_complete && pipe_fence_i;

    assign wb_rf_wen   = lsu_complete && pipe_rf_wen && (pipe_rd != 5'd0) && !pipe_rd[4];
    assign wb_rf_waddr = pipe_rd;
    assign wb_rf_wdata = writeback_data;

`ifdef NPC_SIMULATION
`ifndef SYNTHESIS
    wire csr_known = (pipe_csr_addr == CSR_STAT) ||
                     (pipe_csr_addr == CSR_VECTOR) ||
                     (pipe_csr_addr == CSR_EXC_PC) ||
                     (pipe_csr_addr == CSR_CAUSE) ||
                     (pipe_csr_addr == CSR_VENDOR) ||
                     (pipe_csr_addr == CSR_ARCH);
    wire csr_read_only = (pipe_csr_addr == CSR_VENDOR) ||
                         (pipe_csr_addr == CSR_ARCH);
    wire csr_may_write = (pipe_funct3[1:0] == 2'b01) ||
                         (((pipe_funct3[1:0] == 2'b10) ||
                           (pipe_funct3[1:0] == 2'b11)) && (csr_operand != 32'b0));

    always @(posedge clock) begin
        if (!reset && pipe_valid) begin
            if (pipe_pc[1:0] != 2'b00) begin
                $fatal(1, "exu: instruction address is not aligned: %08x", pipe_pc);
            end
            if (lsu_complete && redirect_request && !take_ebreak &&
                (dnpc[1:0] != 2'b00)) begin
                $fatal(1, "exu: redirect target is not aligned: %08x", dnpc);
            end
            if (privileged_inst && !take_ecall && !take_ebreak && !take_mret) begin
                $fatal(1, "exu: unsupported privileged instruction %08x", pipe_inst);
            end
            if (system_inst && !privileged_inst && !csr_known) begin
                $fatal(1, "exu: unsupported CSR %03x", pipe_csr_addr);
            end
            if (system_inst && csr_may_write && csr_read_only) begin
                $fatal(1, "exu: write to read-only CSR %03x", pipe_csr_addr);
            end
        end
    end
`endif
`endif

    wire _unused_ok = &{1'b0, OP_MEM_WR, OP_FENCEI,
        lsu_master_rresp, lsu_master_bresp};
function [31:0] select_alu;
    input [2:0]  funct3;
    input [6:0]  funct7;
    input [31:0] arithmetic;
    input [31:0] rs1;
    input [31:0] right;
    input        slt_result;
    input        sltu_result;

    begin
        case (funct3)
            FN_ADD: select_alu = arithmetic;
            FN_SLL: select_alu = rs1 << right[4:0];
            FN_SLT: select_alu = {31'b0, slt_result};
            FN_SLTU: select_alu = {31'b0, sltu_result};
            FN_XOR: select_alu = rs1 ^ right;
            FN_SR: begin
                if (funct7[5]) begin
                    select_alu = $signed(rs1) >>> right[4:0];
                end else begin
                    select_alu = rs1 >> right[4:0];
                end
            end
            FN_OR: select_alu = rs1 | right;
            FN_AND: select_alu = rs1 & right;
            default: select_alu = 32'b0;
        endcase
    end
endfunction

endmodule
