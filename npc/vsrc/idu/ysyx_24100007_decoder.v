
module ysyx_24100007_decoder(
  input [31:0] inst,
  
  output ebreaksig,
  output ecallsig,
  output mretsig,
  output fenceisig,
  output [31:0] imm,
  output [6:0] opcode,
  output [2:0] func3,
  output func7,
  output [4:0] src1,
  output [4:0] src2,
  output [4:0] rd,
  output [5:0] inst_type
);
  
  wire type_I, type_R, type_U, type_S, type_J, type_B;
  wire [31:0] I_imm, U_imm, S_imm, J_imm, B_imm;
  
  assign opcode = inst[6:0];
  assign func3 = inst[14:12];
  assign func7 = inst[30];
  assign src1 = inst[19:15];
  assign src2 = inst[24:20];
  assign rd = inst[11:7];

  // Instruction type classification:
  // type_I: I-type instructions - immediate arithmetic/logic operations, load instructions,
  //         jump and link register (JALR), and system instructions (CSR, ECALL, EBREAK)
  //         Examples: ADDI, ANDI, LW, LB, JALR, CSRRW, CSRRW, ECALL, EBREAK
  assign type_I = (opcode == 7'b0000011) | (opcode == 7'b1100111) |
                  (opcode == 7'b0010011) | (opcode == 7'b0000111) |
                  (opcode == 7'b1110011);
  // type_B: B-type instructions - conditional branch instructions
  //         Examples: BEQ, BNE, BLT, BGE, BLTU, BGEU
  assign type_B = (opcode == 7'b1100011);
  // type_S: S-type instructions - store instructions to memory
  //         Examples: SW, SH, SB
  assign type_S = (opcode == 7'b0100011);
  // type_R: R-type instructions - register-to-register arithmetic and logic operations
  //         Examples: ADD, SUB, AND, OR, XOR, SLL, SRL, SRA, SLT, SLTU
  assign type_R = (opcode == 7'b0110011);
  // type_U: U-type instructions - upper immediate instructions for loading constants
  //         Examples: LUI (load upper immediate), AUIPC (add upper immediate to PC)
  assign type_U = (opcode == 7'b0110111) | (opcode == 7'b0010111);
  // type_J: J-type instructions - unconditional jump instructions
  //         Examples: JAL (jump and link)
  assign type_J = (opcode == 7'b1101111);
  assign inst_type = {type_I, type_B, type_J, type_S, type_R, type_U};

  assign I_imm={{20{inst[31]}},inst[31:20]}; 
	assign U_imm={inst[31:12],{12{1'b0}}};
	assign S_imm={{20{inst[31]}},inst[31:25],inst[11:7]};
  assign J_imm={{12{inst[31]}},inst[19:12],inst[20],inst[30:21],1'b0};
	assign B_imm={{20{inst[31]}},inst[7],inst[30:25],inst[11:8],1'b0};
  
  assign imm = type_I ? I_imm :
               type_J ? J_imm :
               type_S ? S_imm :
               type_B ? B_imm :
               type_U ? U_imm :
               32'b0;

  assign ebreaksig = (inst == 32'b00000000000100000000000001110011);
  assign ecallsig = (inst == 32'b00000000000000000000000001110011);
  assign mretsig = (inst == 32'b00110000001000000000000001110011);
  // FENCE.I is a serializing instruction.  Keep it out of the generic
  // arithmetic classes so it cannot acquire a register or memory side effect.
  assign fenceisig = (opcode == 7'b0001111) && (func3 == 3'b001);

endmodule

