`include "opcode_defines.v"
module ysyx_24110012_idu #(
  ADDR_WIDTH = 4
) (
    input [31:0] ifu_idu_inst,
    input [31:0] ifu_idu_pc,
    input ifu_idu_cycle_done,

    input wire ifu_idu_valid,
    output wire idu_ifu_ready,

    output reg [ADDR_WIDTH-1:0] idu_rf_rs1_idx,
    output reg [ADDR_WIDTH-1:0] idu_rf_rs2_idx,
    output reg [11:0] idu_rf_csr_idx,
    input wire [31:0] rf_idu_rs1,
    input wire [31:0] rf_idu_rs2,
    input [31:0] rf_idu_csr_rdata,

    output reg [31:0] idu_exu_pc,
    output reg [6:0] idu_exu_opcode,
    output reg [2:0] idu_exu_func3,
    output reg [6:0] idu_exu_func7,
    output wire [31:0] idu_exu_imm,
    output wire [31:0] idu_exu_rs1,
    output wire [31:0] idu_exu_rs2,
    output wire [3:0] idu_exu_rd_idx,
    output wire [11:0] idu_exu_csr_idx,
    output reg [31:0] idu_exu_csr_rdata,
    output reg idu_exu_ecall,
    output reg idu_exu_mret,
    output reg idu_exu_fencei,
    output reg idu_exu_cycle_done,

    output wire idu_exu_valid,
    input wire exu_idu_ready
);

parameter MRET   = 32'h30200073;
parameter EBREAK = 32'h00100073;
parameter ECALL  = 32'h00000073;
parameter FENCEI = 32'h0000100f;

parameter CSR_MEPC   = 12'h341;
parameter CSR_MTVEC   = 12'h305;

assign idu_exu_pc = ifu_idu_pc;
assign idu_exu_rs1 = rf_idu_rs1;
assign idu_exu_rs2 = rf_idu_rs2;
assign idu_exu_csr_rdata = rf_idu_csr_rdata;

// valid/ready
assign idu_exu_valid = ifu_idu_valid;
assign idu_ifu_ready = exu_idu_ready;  // only combinational logic here

reg [2:0] imm_type;

  always @(*) begin
    idu_exu_opcode = ifu_idu_inst[6:0];
    idu_rf_rs1_idx = ifu_idu_inst[18:15];  // rs1 index where only support 16 regs
    idu_rf_rs2_idx = ifu_idu_inst[23:20];  // rs2 index（only R/S/B type）where only support 16 regs
    idu_exu_rd_idx = ifu_idu_inst[10:7];  // rd index（R/I/U/J type）
    idu_exu_func3 = ifu_idu_inst[14:12];  // func3 for R/I/S/B
    idu_exu_func7 = ifu_idu_inst[31:25];  // func7 for I type
    idu_rf_csr_idx = (ifu_idu_inst == MRET) ? CSR_MEPC :
                      (ifu_idu_inst == ECALL) ? CSR_MTVEC :
                      ifu_idu_inst[31:20];  // CSR address for CSR instructions
    idu_exu_csr_idx = ifu_idu_inst[31:20];  // pass CSR address to EXU
  end

always @(*) begin
    imm_type  = 3'b000;
    case (idu_exu_opcode)
        `OPT_R_LOGIC: imm_type = 3'b000; // R-Type
        `OPT_I_LOGIC: imm_type = 3'b000; // I-Type
        `OPT_S_STORE: imm_type = 3'b001; // S-Type
        `OPT_B:       imm_type = 3'b010; // B-Type
        `OPT_U_LUI,
        `OPT_U_AUIPC:   imm_type = 3'b011; // U-Type
        `OPT_J_JAL:   imm_type = 3'b100; // J-Type
        default:      imm_type = 3'b000; // Default value
    endcase
end

// imm generation
always @(*) begin
    case (imm_type)
        3'b000: begin  // I-Type
            if (idu_exu_opcode == `OPT_I_LOGIC && (idu_exu_func3 == 3'b001 || idu_exu_func3 == 3'b101)) begin
                // For shift instructions (slli, srli, srai)
                idu_exu_imm = {27'b0, ifu_idu_inst[24:20]};  // only use shamt field
            end else begin
                // For other I-Type instructions
                idu_exu_imm = {{20{ifu_idu_inst[31]}}, ifu_idu_inst[31:20]};
            end
        end
        3'b001: idu_exu_imm = {{20{ifu_idu_inst[31]}}, ifu_idu_inst[31:25], ifu_idu_inst[11:7]};  // S-Type（sw, sb, sh）
        3'b010: idu_exu_imm = {{19{ifu_idu_inst[31]}}, ifu_idu_inst[31], ifu_idu_inst[7], ifu_idu_inst[30:25], ifu_idu_inst[11:8], 1'b0};  // B-Type（beq, bne, blt, bge）
        3'b011: idu_exu_imm = {ifu_idu_inst[31:12], 12'b0};  // U-Type（lui, auipc）
        3'b100: idu_exu_imm = {{12{ifu_idu_inst[31]}}, ifu_idu_inst[19:12], ifu_idu_inst[20], ifu_idu_inst[30:21], 1'b0};  // J-Type（jal）
        default: idu_exu_imm = 32'b0;
    endcase
end

// handle ebreak
always @(*) begin
    idu_exu_ecall = 1'b0; // default no ecall
    idu_exu_mret  = 1'b0;
    idu_exu_fencei = 1'b0;
    idu_exu_cycle_done = ifu_idu_cycle_done;
    if (ifu_idu_inst == EBREAK) begin
        // mark cycle done for ebreak; trap handling is retired in WBU
        idu_exu_cycle_done = 1'b1;
    end else if (ifu_idu_inst == ECALL) begin
        idu_exu_ecall = 1'b1; // ecall instruction flag
    end else if (ifu_idu_inst == MRET) begin
        idu_exu_mret = 1'b1; // mret instruction flag
    end else if (ifu_idu_inst == FENCEI) begin
        idu_exu_fencei = 1'b1; // fence.i instruction flag
    end
    // others handled by 1st always block
end

endmodule
