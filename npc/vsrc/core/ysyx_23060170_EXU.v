module ysyx_23060170_EXU (
  input                 clock ,
  input                 reset ,
  input                 idu_valid /*verilator public*/,
  input                 lsu_ready ,
  input                 lsu_exu_flush ,
  input                 idu_exu_excp ,
  input        [3  :0]  idu_exu_excp_code ,
  input        [7  :0]  idu_exu_exu_sel_signal ,
  input        [31 :0]  idu_exu_out ,
  input        [31 :0]  idu_exu_gpr_rdata1 ,
  input        [31 :0]  idu_exu_gpr_rdata2 ,
  input        [31 :0]  idu_exu_pc ,
  input        [31 :0]  idu_exu_tpc_or_csr_wdata ,
  input        [2  :0]  idu_exu_branch_code ,
  input        [9  :0]  idu_exu_alu_op ,
  input                 idu_exu_gpr_wen ,
  input        [4  :0]  idu_exu_gpr_waddr ,
  input                 idu_exu_csr_wen ,
  input        [1  :0]  idu_exu_csr_waddr ,
  input                 idu_exu_mem_ren ,
  input                 idu_exu_mem_wen ,
`ifdef ysyx_23060170_SIM_INFO
  input        [31 :0]  idu_exu_inst ,
  input        [31 :0]  idu_exu_tpc ,
  output       [31 :0]  exu_lsu_tpc ,
  output       [31 :0]  exu_lsu_inst ,
`endif
  output                exu_valid ,
  output                exu_ready ,
  output       [31 :0]  exu_lsu_out ,
  output       [2  :0]  exu_lsu_mem_func3 ,
  output       [4  :0]  exu_lsu_gpr_waddr ,
  output       [1  :0]  exu_lsu_csr_waddr ,
  output       [31 :0]  exu_lsu_csr_or_mem_wdata ,
  output                exu_lsu_mem_ren ,
  output                exu_lsu_mem_wen ,
  output                exu_lsu_gpr_wen ,
  output                exu_lsu_csr_wen ,
  output                exu_lsu_excp ,
  output       [3  :0]  exu_lsu_excp_code ,
  output                exu_lsu_is_fencei ,
  output                exu_lsu_br_mispred ,
  output       [31 :0]  exu_lsu_pc ,
  output       [31 :0]  exu_lsu_npc ,
  output       [3  :0]  exu_idu_gpr_waddr 
);

// reg
`ifdef ysyx_23060170_SIM_INFO
reg      [31 :0]  reg_idu_exu_inst ;
`endif
reg               reg_idu_exu_excp ;
reg      [3  :0]  reg_idu_exu_excp_code ;
reg      [7  :0]  reg_idu_exu_exu_sel_signal ;
reg      [31 :0]  reg_idu_exu_out ;
reg      [31 :0]  reg_idu_exu_gpr_rdata1 ;
reg      [31 :0]  reg_idu_exu_gpr_rdata2 ;
reg      [31 :0]  reg_idu_exu_pc ;
reg      [31 :0]  reg_idu_exu_tpc_or_csr_wdata ;
reg      [2  :0]  reg_idu_exu_branch_code ;
reg      [9  :0]  reg_idu_exu_alu_op ;
reg               reg_idu_exu_gpr_wen ;
reg      [4  :0]  reg_idu_exu_gpr_waddr ;
reg               reg_idu_exu_csr_wen ;
reg      [1  :0]  reg_idu_exu_csr_waddr ;
reg               reg_idu_exu_mem_ren ;
reg               reg_idu_exu_mem_wen ;
reg               exu_pipe_valid ;
reg               exu_pipe_ready ;

// wire
wire              idu_exu_handshake ;
wire              exu_lsu_handshake /*verilator public*/;
wire              exu_wen ;
wire     [31 :0]  gpr_rdata1 ;
wire     [31 :0]  gpr_rdata2 ;
wire              op_add ;
wire              op_sub ;
wire              op_sll ;
wire              op_slt ;
wire              op_sltu ;
wire              op_xor ;
wire              op_srl ;
wire              op_sra ;
wire              op_or ;
wire              op_and ;
wire              is_fencei ;
wire              is_br ;
wire              is_jal ;
wire              is_lui_system ;
wire              is_jalr ;
wire              is_mret ;
wire              is_auipc ;
wire              is_op ;
wire              is_control /*verilator public*/;
wire     [31 :0]  alu_src1 ;
wire     [31 :0]  alu_src2 ;
wire     [31 :0]  alu_res ;
wire     [31 :0]  npc_adder2_res ;
wire     [31 :0]  npc_jalr_res ;
wire     [31 :0]  dnpc ;
wire              br_taken ;
wire              npc_beq_true ;
wire              npc_bne_true ;
wire              npc_blt_true ;
wire              npc_bge_true ;
wire              npc_bltu_true ;
wire              npc_bgeu_true ;

//-----------------------------------------------------------------
// Pipe Logic
//-----------------------------------------------------------------
assign idu_exu_handshake = idu_valid && exu_ready;
assign exu_lsu_handshake = exu_valid && lsu_ready;
assign exu_wen           = idu_exu_handshake;
assign exu_valid         = exu_pipe_valid && !lsu_exu_flush;
assign exu_ready         = exu_pipe_ready;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    exu_pipe_valid <= 1'b0;
  end else if (idu_exu_handshake) begin
    exu_pipe_valid <= 1'b1;
  end else if (exu_lsu_handshake || lsu_exu_flush) begin
    exu_pipe_valid <= 1'b0;
  end else begin
    exu_pipe_valid <= exu_pipe_valid;
  end
end

always @(posedge clock) begin
  if (reset) begin
    exu_pipe_ready <= 1'b1;
  end
  else if (exu_lsu_handshake || lsu_exu_flush) begin
    exu_pipe_ready <= 1'b1;
  end
  else if (idu_exu_handshake) begin
    exu_pipe_ready <= 1'b0;
  end
  else begin
    exu_pipe_ready <= exu_pipe_ready;
  end
end

// ----------------- data part ------------------------
always @(posedge clock) begin
  if (reset) begin
`ifdef ysyx_23060170_SIM_INFO
    reg_idu_exu_inst               <= 32'h0;
`endif
    reg_idu_exu_excp               <= 1'b0;
    reg_idu_exu_excp_code          <= 4'h0;
    reg_idu_exu_exu_sel_signal     <= 8'h0;
    reg_idu_exu_out                <= 32'h0;
    reg_idu_exu_gpr_rdata1         <= 32'h0;
    reg_idu_exu_gpr_rdata2         <= 32'h0;
    reg_idu_exu_pc                 <= 32'h0;
    reg_idu_exu_tpc_or_csr_wdata   <= 32'h0;
    reg_idu_exu_branch_code        <=  3'h0;
    reg_idu_exu_alu_op             <= 10'h0;
    reg_idu_exu_gpr_wen            <=  1'h0;
    reg_idu_exu_gpr_waddr          <=  5'h0;
    reg_idu_exu_csr_wen            <=  1'h0;
    reg_idu_exu_csr_waddr          <=  2'h0;
    reg_idu_exu_mem_ren            <=  1'h0;
    reg_idu_exu_mem_wen            <=  1'h0;
  end
  else if (exu_wen) begin
`ifdef ysyx_23060170_SIM_INFO
    reg_idu_exu_inst               <= idu_exu_inst          ;
`endif
    reg_idu_exu_excp               <= idu_exu_excp          ;
    reg_idu_exu_excp_code          <= idu_exu_excp_code     ;
    reg_idu_exu_exu_sel_signal     <= idu_exu_exu_sel_signal;
    reg_idu_exu_out                <= idu_exu_out           ;
    reg_idu_exu_gpr_rdata1         <= idu_exu_gpr_rdata1    ;
    reg_idu_exu_gpr_rdata2         <= idu_exu_gpr_rdata2    ;
    reg_idu_exu_pc                 <= idu_exu_pc            ;
    reg_idu_exu_tpc_or_csr_wdata   <= idu_exu_tpc_or_csr_wdata;
    reg_idu_exu_branch_code        <= idu_exu_branch_code   ;
    reg_idu_exu_alu_op             <= idu_exu_alu_op        ;
    reg_idu_exu_gpr_wen            <= idu_exu_gpr_wen       ;
    reg_idu_exu_gpr_waddr          <= idu_exu_gpr_waddr     ;
    reg_idu_exu_csr_wen            <= idu_exu_csr_wen       ;
    reg_idu_exu_csr_waddr          <= idu_exu_csr_waddr     ;
    reg_idu_exu_mem_ren            <= idu_exu_mem_ren       ;
    reg_idu_exu_mem_wen            <= idu_exu_mem_wen       ;
  end
  else begin
`ifdef ysyx_23060170_SIM_INFO
    reg_idu_exu_inst               <= reg_idu_exu_inst          ;
`endif
    reg_idu_exu_excp               <= reg_idu_exu_excp          ;
    reg_idu_exu_excp_code          <= reg_idu_exu_excp_code     ;
    reg_idu_exu_exu_sel_signal     <= reg_idu_exu_exu_sel_signal;
    reg_idu_exu_out                <= reg_idu_exu_out           ;
    reg_idu_exu_gpr_rdata1         <= reg_idu_exu_gpr_rdata1    ;
    reg_idu_exu_gpr_rdata2         <= reg_idu_exu_gpr_rdata2    ;
    reg_idu_exu_pc                 <= reg_idu_exu_pc            ;
    reg_idu_exu_tpc_or_csr_wdata   <= reg_idu_exu_tpc_or_csr_wdata;
    reg_idu_exu_branch_code        <= reg_idu_exu_branch_code   ;
    reg_idu_exu_alu_op             <= reg_idu_exu_alu_op        ;
    reg_idu_exu_gpr_wen            <= reg_idu_exu_gpr_wen       ;
    reg_idu_exu_gpr_waddr          <= reg_idu_exu_gpr_waddr     ;
    reg_idu_exu_csr_wen            <= reg_idu_exu_csr_wen       ;
    reg_idu_exu_csr_waddr          <= reg_idu_exu_csr_waddr     ;
    reg_idu_exu_mem_ren            <= reg_idu_exu_mem_ren       ;
    reg_idu_exu_mem_wen            <= reg_idu_exu_mem_wen       ;
  end
end

//-----------------------------------------------------------------
// Signal Parse
//-----------------------------------------------------------------
assign gpr_rdata1 = reg_idu_exu_gpr_rdata1;
assign gpr_rdata2 = reg_idu_exu_gpr_rdata2;

assign op_add  = reg_idu_exu_alu_op[0];
assign op_sub  = reg_idu_exu_alu_op[1];
assign op_sll  = reg_idu_exu_alu_op[2];
assign op_slt  = reg_idu_exu_alu_op[3];
assign op_sltu = reg_idu_exu_alu_op[4];
assign op_xor  = reg_idu_exu_alu_op[5];
assign op_srl  = reg_idu_exu_alu_op[6];
assign op_sra  = reg_idu_exu_alu_op[7];
assign op_or   = reg_idu_exu_alu_op[8];
assign op_and  = reg_idu_exu_alu_op[9];

assign is_fencei     = reg_idu_exu_exu_sel_signal[7];
assign is_br         = reg_idu_exu_exu_sel_signal[6];
assign is_jal        = reg_idu_exu_exu_sel_signal[5];
assign is_lui_system = reg_idu_exu_exu_sel_signal[4];
assign is_jalr       = reg_idu_exu_exu_sel_signal[3];
assign is_mret       = reg_idu_exu_exu_sel_signal[2];
assign is_auipc      = reg_idu_exu_exu_sel_signal[1];
assign is_op         = reg_idu_exu_exu_sel_signal[0];
assign is_control    = is_mret || is_jalr || is_jal || is_br;

//-----------------------------------------------------------------
// ALU
//-----------------------------------------------------------------
assign alu_src1 = (is_auipc || is_jal || is_br) ? reg_idu_exu_pc : gpr_rdata1;
assign alu_src2 = is_op ? gpr_rdata2 : reg_idu_exu_out;

// alu out
assign alu_res = ( {32{op_add }} & (alu_src1 + alu_src2 ))
               | ( {32{op_sub }} & (alu_src1 + ~alu_src2 + 1 ))
               | ( {32{op_sll }} & (alu_src1 << alu_src2[4:0] ))
               | ( {32{op_srl }} & (alu_src1 >> alu_src2[4:0] ))
               | ( {32{op_sra }} & ($unsigned($signed(alu_src1) >>> alu_src2[4:0]) ))
               | ( {32{op_slt }} & ({31'b0, {$signed(alu_src1) < $signed(alu_src2)}} ))
               | ( {32{op_sltu}} & ({31'b0, {$unsigned(alu_src1) < $unsigned(alu_src2)}} ))
               | ( {32{op_xor }} & (alu_src1 ^ alu_src2 ))
               | ( {32{op_or  }} & (alu_src1 | alu_src2 ))
               | ( {32{op_and }} & (alu_src1 & alu_src2  ));

//-----------------------------------------------------------------
// BRU
//-----------------------------------------------------------------
// branch taken
assign npc_beq_true  = reg_idu_exu_branch_code == 3'b000 && (gpr_rdata1 == gpr_rdata2);
assign npc_bne_true  = reg_idu_exu_branch_code == 3'b001 && (gpr_rdata1 != gpr_rdata2);
assign npc_blt_true  = reg_idu_exu_branch_code == 3'b100 && ($signed(gpr_rdata1) < $signed(gpr_rdata2));
assign npc_bge_true  = reg_idu_exu_branch_code == 3'b101 && ($signed(gpr_rdata1) >= $signed(gpr_rdata2));
assign npc_bltu_true = reg_idu_exu_branch_code == 3'b110 && ($unsigned(gpr_rdata1) < $unsigned(gpr_rdata2));
assign npc_bgeu_true = reg_idu_exu_branch_code == 3'b111 && ($unsigned(gpr_rdata1) >= $unsigned(gpr_rdata2));
assign br_taken      = npc_beq_true  | npc_bne_true  | npc_blt_true
                      | npc_bge_true | npc_bltu_true | npc_bgeu_true;

// calculate dnpc
assign npc_adder2_res   = reg_idu_exu_pc + 32'h4;
assign npc_jalr_res     = alu_res & 32'hfffffffe;

assign dnpc = {32{is_jalr}} & npc_jalr_res
            | {32{is_mret}} & reg_idu_exu_out
            | {32{is_jal || is_br && br_taken}} & alu_res
            | {32{~(is_jalr || is_mret || is_jal || is_br && br_taken)}} & npc_adder2_res;

// flush
assign exu_lsu_br_mispred = (dnpc != reg_idu_exu_tpc_or_csr_wdata) && exu_pipe_valid && is_control;

//-----------------------------------------------------------------
// Output
//-----------------------------------------------------------------
// to lsu
assign exu_lsu_out = {32{is_lui_system}} & reg_idu_exu_out
                   | {32{is_jalr || is_jal}} & npc_adder2_res
                   | {32{is_auipc}} & alu_res
                   | {32{~(is_lui_system || is_jalr || is_jal || is_auipc)}} & alu_res;

assign exu_lsu_gpr_wen            = reg_idu_exu_gpr_wen;
assign exu_lsu_gpr_waddr          = reg_idu_exu_gpr_waddr;
assign exu_lsu_csr_wen            = reg_idu_exu_csr_wen;
assign exu_lsu_csr_waddr          = reg_idu_exu_csr_waddr;
assign exu_lsu_csr_or_mem_wdata   = reg_idu_exu_csr_wen ?  reg_idu_exu_tpc_or_csr_wdata : gpr_rdata2;
assign exu_lsu_mem_ren            = reg_idu_exu_mem_ren && !exu_lsu_excp;
assign exu_lsu_mem_wen            = reg_idu_exu_mem_wen && !exu_lsu_excp;
assign exu_lsu_mem_func3          = reg_idu_exu_branch_code;

assign exu_lsu_excp               = reg_idu_exu_excp;
assign exu_lsu_excp_code          = reg_idu_exu_excp_code;
assign exu_lsu_is_fencei          = is_fencei;
assign exu_lsu_pc                 = reg_idu_exu_pc;
assign exu_lsu_npc                = dnpc;

// to idu
assign exu_idu_gpr_waddr = {4{reg_idu_exu_gpr_wen && exu_pipe_valid}} & reg_idu_exu_gpr_waddr[3:0];

//-----------------------------------------------------------------
// Monitor
//-----------------------------------------------------------------
`ifdef ysyx_23060170_SIM_INFO

assign exu_lsu_tpc         = dnpc;
assign exu_lsu_inst        = reg_idu_exu_inst;

`endif

endmodule
