`ifdef __VERILATOR__
import "DPI-C" function void idu_record0(
  input calc,
  input ls,
  input csr
);

import "DPI-C" function void idu_record1(int inst);
`endif

module ysyx_25010008_IDU (
    input clock,
    input reset,

    input [31:0] ifu_pc,
    input [31:0] inst,
    input inst_valid,
    input block,

    output idu_ready,
    output reg decode_valid,
    output reg [31:0] idu_pc,
    output [1:0] npc_sel,

    output [31:0] imm,
    output [7:0] alu_opcode,
    output [1:0] alu_operand1_sel,
    output [3:0] alu_operand2_sel,

    output reg suffix_b,
    output reg suffix_h,
    output reg sext,  
    output reg mem_ren,
    output reg mem_wen,

    output [4:0] rs1,
    output [4:0] rs2,
    output reg [4:0] rd,
    output reg r_wen,
    output [1:0] exu_r_wdata_sel,

    output [11:0] csr_s,
    output [1:0] csr_src_sel,
    output reg [11:0] csr_d,
    output reg csr_wen,

    output ecall,
    output ebreak,
    output mret,
    output fence_i,
    input clear_pipeline
);

  reg [31:0] inst_q;

  reg [4:0] rd_buffer;
  reg [11:0] csr_d_buffer;
  reg r_wen_buffer,csr_wen_buffer;
  reg [1:0] ecall_buffer;
  reg [1:0] ebreak_buffer;
  reg [1:0] mret_buffer;
  reg [1:0] fence_i_buffer;

  wire [6:0] opcode = inst_q[6:0];
  wire [2:0] funct3 = inst_q[14:12];
  wire [6:0] funct7 = inst_q[31:25];

  wire funct3_000 = funct3 == 3'b000;
  wire funct3_001 = funct3 == 3'b001;
  wire funct3_010 = funct3 == 3'b010;
  wire funct3_011 = funct3 == 3'b011;
  wire funct3_100 = funct3 == 3'b100;
  wire funct3_101 = funct3 == 3'b101;
  wire funct3_110 = funct3 == 3'b110;
  wire funct3_111 = funct3 == 3'b111;

  wire funct7_00000_00 = funct7 == 7'b00000_00;
  wire funct7_00000_01 = funct7 == 7'b00000_01;
  wire funct7_01000_00 = funct7 == 7'b01000_00;

  wire LUI   = opcode == 7'b01_101_11;

  wire AUIPC = opcode == 7'b00_101_11;

  wire JAL   = opcode == 7'b11_011_11;

  wire JALR  = opcode == 7'b11_001_11 & funct3_000;

  wire branch = opcode == 7'b11_000_11;
  wire BEQ    = branch & funct3_000;
  wire BNE    = branch & funct3_001;
  wire BLT    = branch & funct3_100;
  wire BGE    = branch & funct3_101;
  wire BLTU   = branch & funct3_110;
  wire BGEU   = branch & funct3_111;

  wire load = opcode == 7'b00_000_11;
  wire LB   = load & funct3_000;
  wire LH   = load & funct3_001;
  wire LW   = load & funct3_010;
  wire LBU  = load & funct3_100;
  wire LHU  = load & funct3_101;

  wire store = opcode == 7'b01_000_11;
  wire SB    = store & funct3_000;
  wire SH    = store & funct3_001;
  wire SW    = store & funct3_010;

  wire op_imm = opcode == 7'b00_100_11;
  wire ADDI   = op_imm & funct3_000;
  wire SLTI   = op_imm & funct3_010;
  wire SLTIU  = op_imm & funct3_011;
  wire XORI   = op_imm & funct3_100;
  wire ORI    = op_imm & funct3_110;
  wire ANDI   = op_imm & funct3_111;
  wire SLLI   = op_imm & funct3_001 & funct7_00000_00;
  wire SRLI   = op_imm & funct3_101 & funct7_00000_00;
  wire SRAI   = op_imm & funct3_101 & funct7_01000_00;

  wire op     = opcode == 7'b01_100_11;
  wire ADD    = op & funct3_000 & funct7_00000_00;
  wire SUB    = op & funct3_000 & funct7_01000_00;
  wire SLL    = op & funct3_001 & funct7_00000_00;
  wire SLT    = op & funct3_010 & funct7_00000_00;
  wire SLTU   = op & funct3_011 & funct7_00000_00;
  wire XOR    = op & funct3_100 & funct7_00000_00;
  wire SRL    = op & funct3_101 & funct7_00000_00;
  wire SRA    = op & funct3_101 & funct7_01000_00;
  wire OR     = op & funct3_110 & funct7_00000_00;
  wire AND    = op & funct3_111 & funct7_00000_00;
  // disable the RV32M temporarily
  // wire MUL    = op & funct3_000 & funct7_00000_01;
  // wire MULH   = op & funct3_001 & funct7_00000_01;
  // wire MULHSU = op & funct3_010 & funct7_00000_01;
  // wire MULHU  = op & funct3_011 & funct7_00000_01;
  // wire DIV    = op & funct3_100 & funct7_00000_01;
  // wire DIVU   = op & funct3_101 & funct7_00000_01;
  // wire REM    = op & funct3_110 & funct7_00000_01;
  // wire REMU   = op & funct3_111 & funct7_00000_01;

  wire system = opcode == 7'b11_100_11;
  wire CSRRW  = system & funct3_001;
  wire CSRRS  = system & funct3_010;
  wire CSRRC  = system & funct3_011;

  wire ECALL  = inst_q[31:0] == 32'b0000000_00000_00000_000_00000_11100_11;
  wire EBREAK = inst_q[31:0] == 32'b0000000_00001_00000_000_00000_11100_11;
  wire MRET   = inst_q[31:0] == 32'b0011000_00010_00000_000_00000_11100_11;

  wire FENCE_I = funct3_001 & opcode == 7'b00_011_11;

  wire csr_inst = CSRRW | CSRRS | CSRRC;

  assign npc_sel[0] = JAL | branch;
  assign npc_sel[1] = JALR | branch;

  wire U_type = LUI | AUIPC;
  wire J_type = JAL;
  wire B_type = branch;
  wire I_type = JALR | load | op_imm | csr_inst;
  wire S_type = store;
  wire R_type = op;

  wire [31:0] U_imm = U_type ? {inst_q[31:12], {12{1'b0}}} : 0;
  wire [31:0] J_imm = J_type ? {{12{inst_q[31]}}, inst_q[19:12], inst_q[20], inst_q[30:25], inst_q[24:21], 1'b0} : 0;
  wire [31:0] B_imm = B_type ? {{20{inst_q[31]}}, inst_q[7], inst_q[30:25], inst_q[11:8], 1'b0} : 0;
  wire [31:0] I_imm = I_type ? {{20{inst_q[31]}}, inst_q[31:20]} : 0;
  wire [31:0] S_imm = S_type ? {{20{inst_q[31]}}, inst_q[31:25], inst_q[11:7]} : 0;

  assign imm         = U_imm | J_imm | B_imm | I_imm | S_imm;

  assign rs1 = LUI ? 0 : inst_q[19:15]; // LUI always use x0 means 0 + imm
  assign rs2 = CSRRW ? 0 : inst_q[24:20]; // CSRRW always use x0 means imm + 0

  assign alu_operand1_sel[0] = rs1 != 0 && rs1 == rd_buffer;
  assign alu_operand1_sel[1] = rs1 != 0 && rs1 == rd;

  assign alu_operand2_sel[0] = LUI | JALR | load | op_imm | S_type;
  assign alu_operand2_sel[1] = CSRRS | CSRRC;
  assign alu_operand2_sel[2] = rs2 != 0 && rs2 == rd_buffer ;
  assign alu_operand2_sel[3] = rs2 != 0 && rs2 == rd; 

  assign exu_r_wdata_sel[0] = JAL | JALR | csr_inst;
  assign exu_r_wdata_sel[1] = AUIPC | csr_inst;

  assign csr_s = inst_q[31:20];
  assign csr_src_sel[0] = csr_s == csr_d_buffer;
  assign csr_src_sel[1] = csr_s == csr_d;

  assign alu_opcode[0] = SUB | branch | SLTI | SLTIU | SLT | SLTU;
  assign alu_opcode[1] = XORI | XOR | BEQ;
  assign alu_opcode[2] = ORI | OR | BNE | CSRRS;
  assign alu_opcode[3] = ANDI | AND | BLTU | SLTIU | SLTU;
  assign alu_opcode[4] = SLLI | SLL | BGEU;
  assign alu_opcode[5] = SRLI | SRL | BLT | SLTI | SLT;
  assign alu_opcode[6] = SRAI | SRA | BGE;
  assign alu_opcode[7] = CSRRC;

  assign ecall = ecall_buffer[1];
  assign ebreak = ebreak_buffer[1];
  assign mret = mret_buffer[1];
  assign fence_i = fence_i_buffer[1];

  assign idu_ready = !load ;

  //                     T1   T2   T3   T4   T5   T6   T7   T8   T9
  //                   +----+----+----+----+----+
  // I1: add a0,t0,s0  | IF | ID | EX | LS | WB |
  //                   +----+----+----+----+----+
  //                       +----+----+----+----+----+
  // I2: sub a1,a0,t0       | IF | ID | EX | LS | WB |
  //                       +----+----+----+----+----+
  //                             +----+----+----+----+----+
  // I3: and a2,a0,s0            | IF | ID | EX | LS | WB |
  //                             +----+----+----+----+----+
  //                                 +----+----+----+----+----+
  // I4: xor a3,a0,t1                 | IF | ID | EX | LS | WB |
  //                                 +----+----+----+----+----+
  //                                       +----+----+----+----+----+
  // I5: sll a4,a0,1                       | IF | ID | EX | LS | WB |
  //                                       +----+----+----+----+----+
  always @(posedge clock) begin
    if (reset | clear_pipeline) begin
      inst_q          <= 0;
      decode_valid    <= 0;

      mem_ren         <= 0;
      mem_wen         <= 0;

      r_wen_buffer    <= 0;
      csr_wen_buffer  <= 0;
      
      r_wen           <= 0;
      csr_wen         <= 0;

      ecall_buffer    <= 0;
      ebreak_buffer   <= 0;
      mret_buffer <= 0;
      fence_i_buffer <= 0;
    end else begin
      if (!block) begin
        if (inst_valid & idu_ready) begin
          inst_q <= inst;
          decode_valid <= 1;
        end else begin
          inst_q <= 0;
          decode_valid <= 0;
        end

        r_wen <= r_wen_buffer;
        csr_wen <= csr_wen_buffer;

        mem_ren <= load;
        mem_wen <= store;

        r_wen_buffer <= U_type | J_type | I_type | R_type;
        csr_wen_buffer <= csr_inst;

        ecall_buffer <= {ecall_buffer[0], ECALL};
        ebreak_buffer <= {ebreak_buffer[0], EBREAK};
        mret_buffer <= {mret_buffer[0], MRET};
        fence_i_buffer <= {fence_i_buffer[0], FENCE_I};

        idu_pc <= ifu_pc;

        suffix_b <= LB | LBU | SB;
        suffix_h <= LH | LHU | SH;
        sext <= LB | LH;

        rd_buffer <= (U_type | J_type | I_type | R_type) ? inst_q[11:7] : 0;
        csr_d_buffer <= csr_inst ? inst_q[31:20] : 0;

        rd <= rd_buffer;
        csr_d <= csr_d_buffer;

`ifdef __VERILATOR__
        idu_record0(LUI | AUIPC | JAL | JALR | branch | op_imm | op, load | store, csr_inst);
        idu_record1(inst);
`endif
      end
    end
  end

endmodule

