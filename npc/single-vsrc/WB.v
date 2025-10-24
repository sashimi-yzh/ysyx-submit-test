`include "/home/furina/ysyx-workbench/npc/single-vsrc/defines.v"
module WB (
    input       [31:0] pc,
    input       [31:0] imm,
    input       [31:0] rs1_val,
    input       [31:0] alu_result,
    input       [31:0] data_out,
    input       [31:0] csr_rdata,
    input       [6:0]  opcode,
    input       [2:0]  func3,
    input              alu_zero,
    input              alu_less,
    output wire [31:0] jal_target,
    output wire [31:0] jalr_target,
    output wire        is_jal,
    output wire        is_jalr,
    output wire        take_branch,
    output wire [31:0] wb_data
);

    // 跳转目标计算
    assign jal_target = pc + imm;
    assign jalr_target = (rs1_val + imm) & ~32'h1;
    assign is_jal = (opcode == `INST_JAL);
    assign is_jalr = (opcode == `INST_JALR) & (func3 == 3'b000);
    assign take_branch = (opcode == `INST_B) && (
        (func3 == `F3_BNE && !alu_zero) || // bne
        (func3 == `F3_BEQ && alu_zero) ||  // beq
        (func3 == `F3_BLT && alu_less) ||  // blt
        (func3 == `F3_BGE && !alu_less) || // bge
        (func3 == `F3_BLTU && alu_less) || // bltu
        (func3 == `F3_BGEU && !alu_less)   // bgeu
    );

    // 写回数据选择
    assign wb_data = (opcode == `INST_LUI) ? imm :                   // LUI
                     (opcode == `INST_AUIPC) ? (pc + imm) :          // AUIPC
                     (opcode == `INST_JAL || opcode == `INST_JALR) ? (pc + 4) : // JAL, JALR
                     (opcode == `INST_LW) ? data_out :              // LW
                     (opcode == `INST_CSR) ? csr_rdata :            //CSR指令返回csr_rdata
                     (opcode == `INST_R || opcode == `INST_I) ? alu_result : 32'b0; // R-type, I-type
    

endmodule