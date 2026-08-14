`include "ysyx_26010007_defines.v"
module ysyx_26010007_IDU (
`ifdef ysyx_26010007_debug
  input clock,
  output [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_pc,
  output [`ysyx_26010007_WORD_WIDTH-1:0]    debug_idu_inst,
  output                      debug_idu_is_ret,
  output                      debug_idu_is_call,
`endif

  // 握手信号
  input                     idu_valid_i,
  output                    idu_ready_i,
  output                    idu_valid_o,
  input                     idu_ready_o,

  // 来自ifu的数据
  input [`ysyx_26010007_WORD_WIDTH-1:0]   idu_inst,
  input [`ysyx_26010007_PADDR_WIDTH-1:0]  idu_pc,

  // 传输到exu的数据
  output [`ysyx_26010007_WORD_WIDTH-1:0]    SrcA,
  output [`ysyx_26010007_WORD_WIDTH-1:0]    SrcB,
  output [`ysyx_26010007_ALU_OP_WIDTH-1:0]  ALU_OP,
  output [`ysyx_26010007_WORD_WIDTH-1:0]    plusImm,
  output [1:0]                jump_op,
  output                      wreg,
  output [`ysyx_26010007_REG_ADDR_WIDTH-1:0]wa,
  output [`ysyx_26010007_WORD_WIDTH-1:0]    MemWdata,
  output [`ysyx_26010007_MEMMASK_WIDTH-1:0] MemMask,
  // 与Rigister File连接的线
  input [`ysyx_26010007_WORD_WIDTH-1:0] rd1,
  input [`ysyx_26010007_WORD_WIDTH-1:0] rd2,
  output[`ysyx_26010007_REG_ADDR_WIDTH-1:0] ra1,
  output[`ysyx_26010007_REG_ADDR_WIDTH-1:0] ra2,
  // 与 CSR 连接的线
  input [`ysyx_26010007_WORD_WIDTH-1:0] csrrd,
  output[`ysyx_26010007_WORD_WIDTH-1:0] csrwd,
  output[`ysyx_26010007_CSR_ADDR_WIDTH-1:0] csra,
  output csrwen,
  // exception
  output [`ysyx_26010007_EXC_EVENT_WIDTH-1:0] exc_event,
  // fence
  output fence_flush,

  // forwarding
  input [`ysyx_26010007_WORD_WIDTH-1:0]     exu_wd,
  input [`ysyx_26010007_REG_ADDR_WIDTH-1:0] exu_wa,
  input                       exu_wen,
  input                       exu_MemWrite,
  input                       exu_Mem2reg,

  input [`ysyx_26010007_WORD_WIDTH-1:0]     lsu_wd,
  input [`ysyx_26010007_REG_ADDR_WIDTH-1:0] lsu_wa,
  input                       lsu_wen,
  input                       lsu_MemWrite,
  input                       lsu_Mem2reg,

  input [`ysyx_26010007_WORD_WIDTH-1:0]     exu_csrwd,
  input [`ysyx_26010007_CSR_ADDR_WIDTH-1:0] exu_csra,
  input                       exu_csrwen,

  input [`ysyx_26010007_WORD_WIDTH-1:0]     lsu_csrwd,
  input [`ysyx_26010007_CSR_ADDR_WIDTH-1:0] lsu_csra,
  input                       lsu_csrwen
);
  wire [`ysyx_26010007_WORD_WIDTH-1:0] inst = idu_inst;
  /*-------- decode-1 --------*/
  wire [6:0] funct7 = inst[31:25];
  wire [4:0] rs2 = inst[24:20];
  wire [4:0] rs1 = inst[19:15];
  wire [2:0] funct3 = inst[14:12];
  wire [4:0] rd = inst[11:7];
  wire [6:0] op = inst[6:0];

  wire funct3_000 = funct3 == 3'b000;
  wire funct3_101 = funct3 == 3'b101;
  wire funct3_010 = funct3 == 3'b010;
  wire funct3_011 = funct3 == 3'b011;
  
  // load & store
  wire op_load  = op == 7'b0000011;
  wire op_store = op == 7'b0100011;
  // J
  wire jal_inst  = op == 7'b1101111;
  wire jalr_inst = (op == 7'b1100111) && funct3_000;
  // U
  wire lui_inst   = op == 7'b0110111;
  wire auipc_inst = op == 7'b0010111;
  // R
  wire op_r = op == 7'b0110011;
  // I
  wire op_i = op == 7'b0010011;
  // B
  wire op_branch = op == 7'b1100011;
  
  // exc
  wire op_csr = (op == 7'b1110011) && (funct3 != 0);
  wire mret_inst = (inst == 32'b00110000001000000000000001110011);
  wire ecall_inst = (inst == 32'b00000000000000000000000001110011);
  
  // fence.i
  wire fencei_inst = (op == 7'b0001111) && funct3 == 3'b001;

  // imm
  wire [`ysyx_26010007_WORD_WIDTH-1:0] immI = {{20{inst[31]}}, inst[31:20]};
  wire [`ysyx_26010007_WORD_WIDTH-1:0] immU = {inst[31:12], 12'd0};
  wire [`ysyx_26010007_WORD_WIDTH-1:0] immS = {{20{inst[31]}}, inst[31:25], inst[11:7]};
  wire [`ysyx_26010007_WORD_WIDTH-1:0] immJ = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
  wire [`ysyx_26010007_WORD_WIDTH-1:0] immB = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};

  wire instI = jalr_inst | op_load | op_i;
  wire instU = lui_inst | auipc_inst;
  wire [`ysyx_26010007_WORD_WIDTH-1:0] imm =  {32{instI}} & immI | 
                                {32{op_store}} & immS |
                                {32{jal_inst}} & immJ |
                                {32{op_branch}} & immB |
                                {32{instU}} & immU;
  wire imm_sel = instI | instU | op_store | lui_inst | jalr_inst;
  assign plusImm = idu_pc + imm;
  assign jump_op = {jal_inst | jalr_inst, jalr_inst | op_branch};

  /*-------- decode-2 --------*/
  
  wire alu_add = (((op_r & ~funct7[5]) | op_i) & funct3_000) | // addi_inst
                  op_load | // 计算访存地址
                  op_store | // 计算访存地址
                  auipc_inst | 
                  jalr_inst; // 计算跳转地址

  wire sub_flag = op_branch | 
                  ((funct3_010 | funct3_011) & (op_i | op_r)) | 
                  ((funct3_101) & funct7[5] & (op_i | op_r)) | 
                  (op_r & funct3_000 & funct7[5]);
  assign ALU_OP[3:0] = alu_add ? 4'b0000 : (op_csr | lui_inst) ? `ysyx_26010007_ALU_LUI : {sub_flag, funct3};
  assign ALU_OP[4] = op_branch;
  assign wreg = instI | instU | op_r | jal_inst | op_csr; 
  assign wa = rd[`ysyx_26010007_REG_ADDR_WIDTH-1:0];
  assign ra1 = rs1[`ysyx_26010007_REG_ADDR_WIDTH-1:0];
  assign ra2 = rs2[`ysyx_26010007_REG_ADDR_WIDTH-1:0];

  assign csra = inst[31:20];
  assign csrwen = op_csr;

  // forwarding
  wire rd2_valid = op_branch | op_store | op_r;
  wire rd1_valid = jalr_inst | op_load | op_i | rd2_valid | op_csr;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  f_rd1;
  wire [`ysyx_26010007_WORD_WIDTH-1:0]  f_rd2;
  wire f_exu_1 = (exu_wa == ra1) && rd1_valid && (exu_wa != 0) && exu_wen;
  wire f_exu_2 = (exu_wa == ra2) && rd2_valid && (exu_wa != 0) && exu_wen;
  wire f_lsu_1 = (lsu_wa == ra1) && rd1_valid && (lsu_wa != 0) && lsu_wen;
  wire f_lsu_2 = (lsu_wa == ra2) && rd2_valid && (lsu_wa != 0) && lsu_wen;
  wire load_use_1 = f_exu_1 & exu_Mem2reg | f_lsu_1 & lsu_Mem2reg;
  wire load_use_2 = f_exu_2 & exu_Mem2reg | f_lsu_2 & lsu_Mem2reg;

  wire [`ysyx_26010007_WORD_WIDTH-1:0]  f_csr;
  wire f_csr_exu = (exu_csra == csra) && exu_csrwen;
  wire f_csr_lsu = (lsu_csra == csra) && lsu_csrwen;

  ysyx_26010007_MuxKeyWithDefault #(4, 2, `ysyx_26010007_WORD_WIDTH) f1 (f_rd1, {f_lsu_1, f_exu_1}, 0, {
    2'b00, rd1,
    2'b01, exu_wd,
    2'b10, lsu_wd,
    2'b11, exu_wd
  });

  ysyx_26010007_MuxKeyWithDefault #(4, 2, `ysyx_26010007_WORD_WIDTH) f2 (f_rd2, {f_lsu_2, f_exu_2}, 0, {
    2'b00, rd2,
    2'b01, exu_wd,
    2'b10, lsu_wd,
    2'b11, exu_wd
  });

  ysyx_26010007_MuxKeyWithDefault #(4, 2, `ysyx_26010007_WORD_WIDTH) fcsr (f_csr, {f_csr_lsu, f_csr_exu}, 0, {
    2'b00, csrrd,
    2'b01, exu_csrwd,
    2'b10, lsu_csrwd,
    2'b11, exu_csrwd
  });

  // csr可以在idu计算得出，不必推到exu
  ysyx_26010007_MuxKeyWithDefault #(6, 3, `ysyx_26010007_WORD_WIDTH) i1 (csrwd, funct3, 0, {
    3'b001, f_rd1,
    3'b010, f_csr | f_rd1,
    3'b011, f_csr & ~f_rd1,
    3'b101, {27'd0, rs1},
    3'b110, f_csr | {27'd0, rs1},
    3'b111, f_csr | ~{27'd0, rs1}
  });

  assign SrcA = auipc_inst ? idu_pc : f_rd1;
  assign SrcB = op_csr ? f_csr : imm_sel ? imm : f_rd2;
  
  assign MemWdata = f_rd2;
  assign MemMask  = {op_load, op_store, funct3};

  // 握手信号
  assign idu_ready_i = idu_ready_o & ~(load_use_1 | load_use_2) & ~(fence_flush & (exu_MemWrite | lsu_MemWrite));
  assign idu_valid_o = idu_valid_i & ~(load_use_1 | load_use_2) & ~(fence_flush & (exu_MemWrite | lsu_MemWrite));

  assign exc_event[0] = ecall_inst;
  assign exc_event[1] = mret_inst;

  assign fence_flush = fencei_inst;

`ifdef ysyx_26010007_debug
  assign debug_idu_inst = inst;
  assign debug_idu_pc = idu_pc;

  always @(posedge clock) begin
    if(idu_valid_o && idu_ready_o) begin
      if(op_load) event_count(4);
      else if(op_store) event_count(5);
      else if(jalr_inst) event_count(6);
      else if(jal_inst) event_count(7);
      else if(op_branch) event_count(8);
      else if(op_csr) event_count(9);
      else if(mret_inst) event_count(10);
      else if(ecall_inst) event_count(11);
      else event_count(12);
    end

    if(idu_valid_i) begin
      if(load_use_1 | load_use_2) begin
        event_count(21);
        if(exu_Mem2reg | lsu_Mem2reg) begin
          event_count(22);
        end
      end
    end
  end

  export "DPI-C" function npc_jump_addr;
  function int npc_jump_addr();
    npc_jump_addr = 0;
  endfunction

  wire ebreak_inst = (inst == 32'h00100073);
  export "DPI-C" function npc_ebreak_inst;
  function int npc_ebreak_inst();
    npc_ebreak_inst = {31'd0, idu_valid_i & ebreak_inst};
  endfunction
  
  assign debug_idu_is_ret = jalr_inst && rd == 0 && imm == 0 && rs1 == 1;
  assign debug_idu_is_call = (jal_inst || jalr_inst) && rd == 1;
`endif
endmodule