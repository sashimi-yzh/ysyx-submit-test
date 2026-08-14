`include "defines.v"
module IDU (
  input [`INST_ADDR_WIDTH-1:0] pc,
  input [`INST_DATA_WIDTH-1:0] inst,
  input [`REG_DATA_WIDTH-1:0] a0,

  input [`WORD_WIDTH-1:0] rd1,
  input [`WORD_WIDTH-1:0] rd2,
  output[`REG_ADDR_WIDTH-1:0] ra1,
  output[`REG_ADDR_WIDTH-1:0] ra2, 
  output [`WORD_WIDTH-1:0] src1,
  output [`WORD_WIDTH-1:0] src2,
  output [`ALU_OP_WIDTH-1:0] alu_op,
  output wreg,
  output [`REG_ADDR_WIDTH-1:0] wa,
  output [3:0] ls_inst,
  output [`INST_ADDR_WIDTH-1:0] jump_addr,
  output jump_flag
);
  /*-------- decode-1 --------*/
  wire [6:0] funct7 = inst[31:25];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rs1 = inst[19:15];
  wire [2:0] funct3 = inst[14:12];
  wire [4:0] rd = inst[11:7];
  wire [6:0] op = inst[6:0];
  
  wire addi_inst = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire jalr_inst = ~funct3[2]&~funct3[1]&~funct3[0]& op[6]& op[5]&~op[4]&~op[3]& op[2] & op[1]& op[0];
  wire add_inst  = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lui_inst  = ~op[6]& op[5]& op[4]&~op[3]& op[2] & op[1]& op[0];
  wire lw_inst   = ~funct3[2]& funct3[1]&~funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lbu_inst  =  funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sw_inst   = ~funct3[2]& funct3[1]&~funct3[0]&~op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sb_inst   = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];

  // imm
  wire [`WORD_WIDTH-1:0] immI = {{20{inst[31]}}, inst[31:20]};
  wire [`WORD_WIDTH-1:0] immU = {inst[31:12], 12'd0};
  wire [`WORD_WIDTH-1:0] immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};

  wire instI = addi_inst | jalr_inst | lw_inst | lbu_inst;
  wire instU = lui_inst;
  wire instS = sw_inst | sb_inst;
  wire [`WORD_WIDTH-1:0] imm =  instI ? immI : 
                                instS ? immS :
                                instU ? immU : 0;
  wire imm_sel = instI | instU | instS;
  
  wire [1:0] jump_sel;
  assign jump_flag = jalr_inst;
  assign jump_addr = (jalr_inst) ? ((rd1 + imm) & 32'hfffffffe) : (pc + 32'd4);

  /*-------- decode-2 --------*/
  assign ls_inst = {lw_inst, lbu_inst, sb_inst, sw_inst};
  assign alu_op[3] = 0;
  assign alu_op[2] = 0;
  assign alu_op[1] = lui_inst;
  assign alu_op[0] = lui_inst;
  
  assign wreg = addi_inst | jalr_inst | add_inst | lui_inst | lw_inst | lbu_inst;
  assign wa = rd[`REG_ADDR_WIDTH-1:0];
  assign ra1 = rs1[`REG_ADDR_WIDTH-1:0];
  assign ra2 = rs2[`REG_ADDR_WIDTH-1:0];
  
  assign src1 = jalr_inst ? pc : rd1;
  assign src2 = jalr_inst ? 32'd4 : imm_sel ? imm : rd2;

  wire ebreak_inst = (inst == 32'b00000000000100000000000001110011);
  wire illegal_inst = ~(addi_inst | jalr_inst | add_inst | lui_inst | 
                      lw_inst | lbu_inst | sw_inst | sb_inst | ebreak_inst);
  always @(*) begin
    if(ebreak_inst) npctrap(a0);
    if(illegal_inst) npctrap(32'd2);
    if(rd == 0 && imm == 0 && rs1 == 1) ftrace_ret(pc);
    if(rd == 1) ftrace_call(pc, jump_addr);
  end



endmodule