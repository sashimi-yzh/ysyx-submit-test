`include "/home/furina/ysyx-workbench/npc/minirv-vsrc/defines.v"
module WB (
    input       [31:0] pc,
    input       [31:0] imm,
    input       [31:0] rs1_val,
    input       [31:0] alu_result,
    input       [31:0] data_out,
    input       [6:0]  opcode,
    input       [2:0]  func3,
    output wire [31:0] jalr_target,
    output wire        is_jalr,
    output wire [31:0] wb_data
);
    assign jalr_target = (rs1_val + imm) & ~32'h1;
    assign is_jalr = (opcode == `INST_JALR) & (func3 == 3'b000);

    // 写回数据选择
    assign wb_data = (opcode == `INST_LUI) ? imm :                   // LUI
                    //  (opcode == `INST_AUIPC) ? (pc + imm) :          // AUIPC
                     (opcode == `INST_JALR) ? (pc + 4) :
                     (opcode == `INST_LW) ? data_out :              // LW
                     (opcode == `INST_R || opcode == `INST_I) ? alu_result : 32'b0; // R-type, I-type
    

endmodule