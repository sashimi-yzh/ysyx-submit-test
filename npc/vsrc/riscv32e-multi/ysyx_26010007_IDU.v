`include "ysyx_26010007_defines.v"
module ysyx_26010007_IDU (
`ifdef debug
  input clock,
`endif

  // Distributed Bus
  // 握手信号
  input                     ifu_valid,
  output                    idu_ready,
  output                    idu_valid,
  input                     exu_ready,
  // 来自ifu的数据
  input [`WORD_WIDTH-1:0]   ifu_inst,
  input [`PADDR_WIDTH-1:0]  ifu_pc,
  // 传输到ifu的数据（target addr）
  output [`PADDR_WIDTH-1:0] jump_addr,
  output jump_flag,
  // 传输到exu的数据
  output [`WORD_WIDTH-1:0] idu_src1,
  output [`WORD_WIDTH-1:0] idu_src2,
  output [`ALU_OP_WIDTH-1:0] idu_alu_op,
  output idu_wreg,
  output [`REG_ADDR_WIDTH-1:0] idu_wa,
  output [7:0] idu_ls_inst,
  output [`WORD_WIDTH-1:0] idu_store_data,
  // 与Rigister File连接的线
  input [`WORD_WIDTH-1:0] rd1,
  input [`WORD_WIDTH-1:0] rd2,
  output[`REG_ADDR_WIDTH-1:0] ra1,
  output[`REG_ADDR_WIDTH-1:0] ra2,
  // 与 CSR 连接的线
  input [`WORD_WIDTH-1:0] csrrd,
  output[`WORD_WIDTH-1:0] csrwd,
  output[`CSR_ADDR_WIDTH-1:0] csra,
  output csrwen,
  output [`EXC_EVENT_WIDTH-1:0] exc_event,
  // fence
  output flush_icache
);
  wire [`WORD_WIDTH-1:0] inst = ifu_valid ? ifu_inst : `NOP_INST;
  /*-------- decode-1 --------*/
  wire [6:0] funct7 = inst[31:25];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rs1 = inst[19:15];
  wire [2:0] funct3 = inst[14:12];
  wire [4:0] rd = inst[11:7];
  wire [6:0] op = inst[6:0];

  // S
  wire sw_inst   = ~funct3[2]& funct3[1]&~funct3[0]&~op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sb_inst   = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sh_inst   = ~funct3[2]&~funct3[1]& funct3[0]&~op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  
  // J
  wire jal_inst  =  op[6]& op[5]&~op[4]& op[3]& op[2] & op[1]& op[0];

  // R
  wire add_inst  = ~(|funct7)&~funct3[2]&~funct3[1]&~funct3[0]&~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire and_inst  = ~(|funct7)& funct3[2]& funct3[1]& funct3[0]&~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sltu_inst = ~(|funct7)&~funct3[2]& funct3[1] & funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire slt_inst  = ~(|funct7)&~funct3[2]& funct3[1] &~funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire xor_inst  = ~(|funct7)& funct3[2]&~funct3[1] &~funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire or_inst   = ~(|funct7)& funct3[2]& funct3[1] &~funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sub_inst  = funct7[5]&~(|{funct7[6], funct7[4:0]})&~funct3[2]&~funct3[1]&~funct3[0]&~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sll_inst   = ~(|funct7)&~funct3[2]&~funct3[1] & funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire sra_inst   = funct7[5]&~(|{funct7[6], funct7[4:0]})& funct3[2]&~funct3[1]& funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire srl_inst   = ~(|funct7)& funct3[2]&~funct3[1]& funct3[0] & ~op[6]& op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  
  // U
  wire lui_inst  = ~op[6]& op[5]& op[4]&~op[3]& op[2] & op[1]& op[0];
  wire auipc_inst= ~op[6]&~op[5]& op[4]&~op[3]& op[2] & op[1]& op[0];

  // I
  wire lw_inst   = ~funct3[2]& funct3[1]&~funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lbu_inst  =  funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lb_inst   = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lhu_inst  =  funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire lh_inst   = ~funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  
  wire sltiu_inst= ~funct3[2]& funct3[1]& funct3[0] & ~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire addi_inst = ~funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire jalr_inst = ~funct3[2]&~funct3[1]&~funct3[0]& op[6]& op[5]&~op[4]&~op[3]& op[2] & op[1]& op[0];
  wire srai_inst = funct7[5]&~(|{funct7[6], funct7[4:0]})& funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire slli_inst = ~(|funct7)&&~funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire srli_inst = ~(|funct7)&& funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire andi_inst =  funct3[2]& funct3[1]& funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire ori_inst  =  funct3[2]& funct3[1]&~funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire xori_inst =  funct3[2]&~funct3[1]&~funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire slti_inst = ~funct3[2]& funct3[1]&~funct3[0]&~op[6]&~op[5]& op[4]&~op[3]&~op[2] & op[1]& op[0];
  
  // B
  wire beq_inst= ~funct3[2]&~funct3[1]&~funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire bne_inst= ~funct3[2]&~funct3[1]& funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire blt_inst=  funct3[2]&~funct3[1]&~funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire bge_inst=  funct3[2]&~funct3[1]& funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire bltu_inst=  funct3[2]& funct3[1]&~funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  wire bgeu_inst=  funct3[2]& funct3[1]& funct3[0] & op[6]& op[5]&~op[4]&~op[3]&~op[2] & op[1]& op[0];
  
  // csr
  wire csrrw_inst  = ~funct3[2]&~funct3[1]& funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];
  wire csrrs_inst  = ~funct3[2]& funct3[1]&~funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];
  wire csrrc_inst  = ~funct3[2]& funct3[1]& funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];
  wire csrrwi_inst =  funct3[2]&~funct3[1]& funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];
  wire csrrsi_inst =  funct3[2]& funct3[1]&~funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];
  wire csrrci_inst =  funct3[2]& funct3[1]& funct3[0]& op[6]& op[5] & op[4]&~op[3]&~op[2]& op[1] & op[0];

  // fence
  wire fence_inst = ~funct3[2]&~funct3[1]& funct3[0]&~op[6]&~op[5]&~op[4]& op[3]& op[2]& op[1]& op[0];

  // imm
  wire [`WORD_WIDTH-1:0] immI = {{20{inst[31]}}, inst[31:20]};
  wire [`WORD_WIDTH-1:0] immU = {inst[31:12], 12'd0};
  wire [`WORD_WIDTH-1:0] immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  wire [`WORD_WIDTH-1:0] immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
  wire [`WORD_WIDTH-1:0] immB = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};


  wire instI = addi_inst | jalr_inst | lw_inst | lbu_inst | sltiu_inst | lb_inst | lh_inst | lhu_inst | srai_inst | slli_inst | srli_inst | andi_inst | ori_inst | xori_inst | slti_inst;
  wire instU = lui_inst | auipc_inst;
  wire instJ = jal_inst;
  wire instS = sw_inst | sb_inst | sh_inst;
  wire instB = beq_inst | bne_inst | bge_inst | blt_inst | bgeu_inst | bltu_inst;
  wire [`WORD_WIDTH-1:0] imm =  instI ? immI : 
                                instS ? immS :
                                instJ ? immJ :
                                instB ? immB :
                                instU ? immU : 0;
  wire imm_sel = instI | instU | instS;
  
  wire [1:0] jump_sel;
  assign jump_sel[0] = jalr_inst | (beq_inst && (rd1 == rd2)) | (bne_inst && (rd1 != rd2)) | (blt_inst && ($signed(rd1) < $signed(rd2))) | (bge_inst && ($signed(rd1) >= $signed(rd2))) | (bltu_inst && (rd1 < rd2)) | (bgeu_inst && (rd1 >= rd2));
  assign jump_sel[1] = jalr_inst | jal_inst;
  
  assign jump_flag = |jump_sel;
  ysyx_26010007_MuxKey #(4, 2, `WORD_WIDTH) i0 (jump_addr, jump_sel, {
    2'b00, ifu_pc + 32'd4,
    2'b01, ifu_pc + imm,
    2'b10, ifu_pc + imm,
    2'b11, (rd1 + imm) & 32'hfffffffe
  });

  /*-------- decode-2 --------*/
  assign idu_ls_inst = {lw_inst, lbu_inst, lb_inst, lhu_inst, lh_inst, sw_inst, sb_inst, sh_inst};
  assign idu_alu_op[3] = sltu_inst | sltiu_inst | sub_inst | srai_inst | sra_inst | slt_inst | slti_inst;
  assign idu_alu_op[2] = xor_inst | or_inst | srai_inst | srli_inst | sra_inst | srl_inst | andi_inst | and_inst | xori_inst | ori_inst;
  assign idu_alu_op[1] = csrwen | lui_inst | sltu_inst | or_inst | sltiu_inst | andi_inst | and_inst | ori_inst | slti_inst | slt_inst;
  assign idu_alu_op[0] = csrwen | lui_inst | srai_inst | sltu_inst | sltiu_inst | srli_inst | slli_inst | sra_inst | srl_inst | sll_inst | andi_inst | and_inst;
  
  assign csrwen = csrrc_inst | csrrci_inst | csrrs_inst | csrrsi_inst | csrrw_inst | csrrwi_inst;

  assign idu_wreg = addi_inst | jalr_inst | add_inst | lui_inst | lw_inst | lbu_inst | auipc_inst | jal_inst | sltu_inst | xor_inst | or_inst | sltiu_inst | sub_inst | lb_inst | lh_inst | lhu_inst | srai_inst | slli_inst | srli_inst | andi_inst | sll_inst | srl_inst | sra_inst | and_inst | ori_inst | xori_inst | slti_inst | slt_inst | csrrc_inst | csrrci_inst | csrrs_inst | csrrsi_inst | csrrw_inst | csrrwi_inst; 
  assign idu_wa = rd[`REG_ADDR_WIDTH-1:0];
  assign ra1 = rs1[`REG_ADDR_WIDTH-1:0];
  assign ra2 = rs2[`REG_ADDR_WIDTH-1:0];
  assign csra = inst[31:20];
  ysyx_26010007_MuxKeyWithDefault #(6, 3, `WORD_WIDTH) i1 (csrwd, funct3, 0, {
    3'b001, rd1,
    3'b010, csrrd | rd1,
    3'b011, csrrd & ~rd1,
    3'b101, {27'd0, rs1},
    3'b110, csrrd | {27'd0, rs1},
    3'b111, csrrd | ~{27'd0, rs1}
  });

  assign idu_src1 = (jal_inst | jalr_inst | auipc_inst) ? ifu_pc : rd1;
  assign idu_src2 = csrwen ? csrrd : (jalr_inst | jal_inst) ? 32'd4 : imm_sel ? imm : rd2;

  // exception
  wire mret_inst = (inst == 32'b00110000001000000000000001110011);
  wire ecall_inst = (inst == 32'b00000000000000000000000001110011);
  assign exc_event[0] = ecall_inst;
  assign exc_event[1] = mret_inst;
  
  assign idu_store_data = rd2;
  // 握手信号
  assign idu_ready = exu_ready;
  assign idu_valid = ifu_valid;

  assign flush_icache = fence_inst;

`ifdef debug
  always @(posedge clock) begin
    if(idu_valid && idu_ready) begin
      if(lb_inst | lbu_inst | lw_inst | lh_inst | lhu_inst) event_count(4);
      else if(sb_inst | sh_inst | sw_inst) event_count(5);
      else if(jalr_inst) event_count(6);
      else if(jal_inst) event_count(7);
      else if(instB) event_count(8);
      else if(csrwen) event_count(9);
      else if(mret_inst) event_count(10);
      else if(ecall_inst) event_count(11);
      else event_count(12);
    end
  end

  export "DPI-C" function npc_inst;
  function int npc_inst();
    npc_inst = inst;
  endfunction

  export "DPI-C" function npc_jump_addr;
  function int npc_jump_addr();
    npc_jump_addr = jump_addr;
  endfunction

  export "DPI-C" function npc_isRet;
  function int npc_isRet();
    if(jalr_inst && rd == 0 && imm == 0 && rs1 == 1) npc_isRet = 32'd1;
    else npc_isRet = 32'd0;
  endfunction

  export "DPI-C" function npc_isCall;
  function int npc_isCall();
    if((jal_inst || jalr_inst) && rd == 1) npc_isCall = 32'd1;
    else npc_isCall = 32'd0;
  endfunction
`endif
endmodule