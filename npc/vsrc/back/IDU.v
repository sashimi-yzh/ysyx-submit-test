module IDU(
  input [31:0] inst, input ifu_valid,
  output [4:0] rd, output [4:0] rs1, output [4:0] rs2,
  output [31:0] imm_i, output [31:0] imm_s, output [31:0] imm_b,
  output [31:0] imm_u, output [31:0] imm_j,
  output is_add, output is_sub, output is_and, output is_or, output is_xor,
  output is_sll, output is_srl, output is_sra, output is_slt, output is_sltu,
  output is_addi, output is_slti, output is_sltiu, output is_xori, output is_ori,
  output is_andi, output is_slli, output is_srli, output is_srai,
  output is_lb, output is_lh, output is_lw, output is_lbu, output is_lhu,
  output is_sb, output is_sh, output is_sw,
  output is_beq, output is_bne, output is_blt, output is_bge, output is_bltu, output is_bgeu,
  output is_lui, output is_auipc, output is_jal, output is_jalr,
  output is_ebreak, output is_ecall, output is_mret,
  output is_csrrw, output is_csrrs,
  output is_fence_i,
  output reg_wen, output mem_valid, output mem_wen, output csr_wen,

  output op_r_type,
  output op_load,
  output op_store,
  output is_jump
);

  wire [6:0] opcode;
  wire [2:0] funct3;
  wire [6:0] funct7;
  wire op_branch;
  assign opcode = inst[6:0];
  assign rd = inst[11:7];
  assign rs1 = inst[19:15];
  assign rs2 = inst[24:20];
  assign funct3 = inst[14:12];
  assign funct7 = inst[31:25];
  assign imm_i = {{20{inst[31]}}, inst[31:20]};
  assign imm_s = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  assign imm_b = {{19{inst[31]}}, inst[31], inst[7], inst[30:25], inst[11:8], 1'b0};
  assign imm_u = {inst[31:12], 12'b0};
  assign imm_j = {{11{inst[31]}}, inst[31], inst[19:12], inst[20], inst[30:21], 1'b0};
  
  assign op_r_type = (opcode == 7'b0110011);
  wire op_i_arith = (opcode == 7'b0010011);
  assign op_load = (opcode == 7'b0000011);
  assign op_store = (opcode == 7'b0100011);
  assign op_branch = (opcode == 7'b1100011);
  wire op_lui = (opcode == 7'b0110111);
  wire op_auipc = (opcode == 7'b0010111);
  wire op_jal = (opcode == 7'b1101111);
  wire op_jalr = (opcode == 7'b1100111);
  wire op_system = (opcode == 7'b1110011);

  assign is_add = op_r_type && (funct3 == 3'b000) && (funct7 == 7'b0000000);
  assign is_sub = op_r_type && (funct3 == 3'b000) && (funct7 == 7'b0100000);
  assign is_and = op_r_type && (funct3 == 3'b111);
  assign is_or = op_r_type && (funct3 == 3'b110);
  assign is_xor = op_r_type && (funct3 == 3'b100);
  assign is_sll = op_r_type && (funct3 == 3'b001);
  assign is_srl = op_r_type && (funct3 == 3'b101) && (funct7 == 7'b0000000);
  assign is_sra = op_r_type && (funct3 == 3'b101) && (funct7 == 7'b0100000);
  assign is_slt = op_r_type && (funct3 == 3'b010);
  assign is_sltu = op_r_type && (funct3 == 3'b011);

  assign is_addi = op_i_arith && (funct3 == 3'b000);
  assign is_slti = op_i_arith && (funct3 == 3'b010);
  assign is_sltiu = op_i_arith && (funct3 == 3'b011);
  assign is_xori = op_i_arith && (funct3 == 3'b100);
  assign is_ori = op_i_arith && (funct3 == 3'b110);
  assign is_andi = op_i_arith && (funct3 == 3'b111);
  assign is_slli = op_i_arith && (funct3 == 3'b001);
  assign is_srli = op_i_arith && (funct3 == 3'b101) && (funct7 == 7'b0000000);
  assign is_srai = op_i_arith && (funct3 == 3'b101) && (funct7 == 7'b0100000);

  assign is_lb = op_load && (funct3 == 3'b000);
  assign is_lh = op_load && (funct3 == 3'b001);
  assign is_lw = op_load && (funct3 == 3'b010);
  assign is_lbu = op_load && (funct3 == 3'b100);
  assign is_lhu = op_load && (funct3 == 3'b101);

  assign is_sb = op_store && (funct3 == 3'b000);
  assign is_sh = op_store && (funct3 == 3'b001);
  assign is_sw = op_store && (funct3 == 3'b010);
  
  assign is_beq = op_branch && (funct3 == 3'b000);
  assign is_bne = op_branch && (funct3 == 3'b001);
  assign is_blt = op_branch && (funct3 == 3'b100);
  assign is_bge = op_branch && (funct3 == 3'b101);
  assign is_bltu = op_branch && (funct3 == 3'b110);
  assign is_bgeu = op_branch && (funct3 == 3'b111);
  assign is_lui = op_lui;
  assign is_auipc = op_auipc;
  assign is_jal = op_jal;
  assign is_jalr = op_jalr && (funct3 == 3'b000);
  assign is_jump = is_jal || is_jalr;

  assign is_ebreak = (inst == 32'h00100073);
  assign is_ecall = ifu_valid && inst == 32'h00000073;
  assign is_mret = (inst == 32'h30200073);
  assign is_csrrw = op_system && (funct3 == 3'b001);
  assign is_csrrs = op_system && (funct3 == 3'b010);
  assign is_fence_i = (inst == 32'h0000100F);

  assign reg_wen = ifu_valid && (op_r_type || op_i_arith || op_load ||
                                 is_jump || is_lui || is_auipc || op_system);
  assign mem_valid = ifu_valid && (op_load || op_store);
  assign mem_wen = ifu_valid && op_store;
  assign csr_wen = ifu_valid && (is_csrrw || is_csrrs);


endmodule
