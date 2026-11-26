module EXU(
  input [31:0] rs1_data,      
  input [31:0] rs2_data,      
  input [31:0] imm_i,         
  input [31:0] imm_b,         
  input [31:0] imm_j,
  input [31:0] pc,            
  
  // R型算术/逻辑指令
  input is_add,
  input is_sub,
  input is_and,
  input is_or,
  input is_xor,
  input is_sll,
  input is_srl,
  input is_sra,
  input is_slt,
  input is_sltu,
  
  // I型算术/逻辑指令
  input is_addi,
  input is_slti,
  input is_sltiu,
  input is_xori,
  input is_ori,
  input is_andi,
  input is_slli,
  input is_srli,
  input is_srai,
  
  // B型分支指令
  input is_beq,
  input is_bne,
  input is_blt,
  input is_bge,
  input is_bltu,
  input is_bgeu,
  
  // J型指令
  input is_jal,

  input op_r_type,
  
  output reg [31:0] alu_result,
  output [31:0] jump_target,  
  output [31:0] branch_target,
  output reg branch_taken         
);

  wire [31:0] alu_src2 = op_r_type ? rs2_data : imm_i;
  wire [4:0] shamt = op_r_type ? rs2_data[4:0] : imm_i[4:0];
  
  always @(*) begin
    case (1'b1)
      is_add || is_addi : alu_result = rs1_data + alu_src2;
      is_sub: alu_result = rs1_data - alu_src2;
      is_and || is_andi: alu_result = rs1_data & alu_src2;
      is_or  || is_ori:  alu_result = rs1_data | alu_src2;
      is_xor || is_xori: alu_result = rs1_data ^ alu_src2;
      is_sll || is_slli: alu_result = rs1_data << shamt;
      is_srl || is_srli: alu_result = rs1_data >> shamt;
      is_sra || is_srai: alu_result = $signed(rs1_data) >>> shamt;
      is_slt || is_slti: alu_result = ($signed(rs1_data) < $signed(alu_src2)) ? 32'b1 : 32'b0;
      is_sltu || is_sltiu: alu_result = (rs1_data < alu_src2) ? 32'b1 : 32'b0;
      default: alu_result = 32'b0;
    endcase
  end
  
  // ========== 分支判断 ==========
  always @(*) begin
    case (1'b1)
      is_beq:  branch_taken = (rs1_data == rs2_data);
      is_bne:  branch_taken = (rs1_data != rs2_data);
      is_blt:  branch_taken = ($signed(rs1_data) < $signed(rs2_data));
      is_bge:  branch_taken = ($signed(rs1_data) >= $signed(rs2_data));
      is_bltu: branch_taken = (rs1_data < rs2_data);
      is_bgeu: branch_taken = (rs1_data >= rs2_data);
      default: branch_taken = 1'b0;
    endcase
  end

  assign jump_target = (rs1_data + imm_i) & ~32'h1;
  assign branch_target = pc + (is_jal ? imm_j : imm_b);

endmodule
