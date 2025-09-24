module ysyx_23060170_IDU (
  input                 clock ,
  input                 reset ,
  input                 ifu_valid ,
  input                 exu_ready ,
  input                 lsu_idu_flush ,
  input                 ifu_idu_excp ,
  input        [3  :0]  ifu_idu_excp_code ,
  input        [31 :0]  ifu_idu_pc ,
  input        [31 :0]  ifu_idu_tpc ,
  input        [31 :0]  ifu_idu_inst ,
  input        [31 :0]  gpr_idu_rdata1 ,
  input        [31 :0]  gpr_idu_rdata2 ,
  input        [31 :0]  csr_idu_rdata ,
  input        [3  :0]  exu_idu_gpr_waddr ,
  input        [3  :0]  lsu_idu_gpr_waddr ,
`ifdef ysyx_23060170_SIM_INFO
  output       [31 :0]  idu_exu_inst ,
  output       [31 :0]  idu_exu_tpc ,
`endif
  output                idu_valid ,
  output                idu_ready ,
  output       [4  :0]  idu_gpr_raddr1 ,
  output       [4  :0]  idu_gpr_raddr2 ,
  output       [1  :0]  idu_csr_raddr ,
  output                idu_exu_excp ,
  output       [3  :0]  idu_exu_excp_code ,
  output       [7  :0]  idu_exu_exu_sel_signal ,
  output       [31 :0]  idu_exu_out ,
  output       [31 :0]  idu_exu_gpr_rdata1 ,
  output       [31 :0]  idu_exu_gpr_rdata2 ,
  output       [31 :0]  idu_exu_pc ,
  output       [31 :0]  idu_exu_tpc_or_csr_wdata ,
  output       [2  :0]  idu_exu_branch_code ,
  output       [9  :0]  idu_exu_alu_op ,
  output                idu_exu_gpr_wen ,
  output       [4  :0]  idu_exu_gpr_waddr ,
  output                idu_exu_csr_wen ,
  output       [1  :0]  idu_exu_csr_waddr ,
  output                idu_exu_mem_ren ,
  output                idu_exu_mem_wen 
);

reg              reg_ifu_idu_excp ;
reg     [3  :0]  reg_ifu_idu_excp_code ;
reg     [31 :0]  reg_ifu_idu_pc /*verilator public*/;
reg     [31 :0]  reg_ifu_idu_tpc ;
reg     [31 :0]  reg_ifu_idu_inst /*verilator public*/;
reg              idu_pipe_valid ;
reg              idu_pipe_ready ;

// bus control
wire             ifu_idu_handshake ;
wire             idu_exu_handshake /*verilator public*/;
wire             raw_stall /*verilator public*/;
wire    [31 :0]  csr_rdata ;

// predecode
wire    [6  :0]  func7 ;
wire    [4  :0]  rs2 ;
wire    [4  :0]  rs1 ;
wire    [2  :0]  func3 ;
wire    [4  :0]  rd ;
wire    [4  :0]  opcode ;
// inst signal
wire             op_lui ;
wire             op_auipc ;
wire             op_jal ;
wire             op_jalr ;
wire             op_branch ;
wire             op_load ;
wire             op_store ;
wire             op_imm ;
wire             op_op ;
wire             op_system ;
wire             op_fencei ;

wire             inst_beq ;
wire             inst_bne ;
wire             inst_blt ;
wire             inst_bge ;
wire             inst_bltu ;
wire             inst_bgeu ;

wire             inst_lb ;
wire             inst_lh ;
wire             inst_lw ;
wire             inst_lbu ;
wire             inst_lhu ;
wire             inst_sb ;
wire             inst_sh ;
wire             inst_sw ;

wire             inst_addi ;
wire             inst_slti ;
wire             inst_sltiu ;
wire             inst_xori ;
wire             inst_ori ;
wire             inst_andi ;
wire             inst_slli ;
wire             inst_srli ;
wire             inst_srai ;

wire             inst_add ;
wire             inst_sub ;
wire             inst_sll ;
wire             inst_slt ;
wire             inst_sltu ;
wire             inst_xor ;
wire             inst_srl ;
wire             inst_sra ;
wire             inst_or ;
wire             inst_and ;

wire             inst_ecall ;
wire             inst_ebreak ;
wire             inst_csrrw ;
wire             inst_csrrs ;
wire             inst_mret ;
// control signal
wire             sel_idu_out ;
// imm
wire    [31 :0]  imm ;
wire    [31 :0]  I_imm ;
wire    [31 :0]  S_imm ;
wire    [31 :0]  B_imm ;
wire    [31 :0]  U_imm ;
wire    [31 :0]  J_imm ;
wire             is_I ;
wire             is_S /*verilator public*/;
wire             is_B /*verilator public*/;
wire             is_U ;
wire             is_J ;
// csr
wire    [1  :0]  csrr_ws_addr ;
wire    [31 :0]  csr_wdata ;
// exception
wire             excp_ill_inst ;


parameter MSTATUS   = 32'h300;
parameter MTVEC     = 32'h305;
parameter MEPC      = 32'h341;
parameter MCAUSE    = 32'h342;
parameter MVENDORID = 32'h343;
parameter MARCHID   = 32'h344;

//-----------------------------------------------------------------
// Exception
//-----------------------------------------------------------------
assign excp_ill_inst = ~(&reg_ifu_idu_inst[1:0] && (op_lui || op_auipc || op_jal || op_jalr || op_fencei
                        || inst_beq || inst_bne || inst_blt || inst_bge || inst_bltu || inst_bgeu
                        || inst_lb  || inst_lh  || inst_lw  || inst_lbu || inst_lhu
                        || inst_sb  || inst_sh  || inst_sw
                        || inst_addi || inst_slti || inst_sltiu || inst_xori || inst_ori  || inst_andi
                        || inst_slli || inst_srli || inst_srai
                        || inst_add  || inst_sub  || inst_sll   || inst_slt  || inst_sltu || inst_xor
                        || inst_srl  || inst_sra  || inst_or    || inst_and
                        || inst_ecall || inst_ebreak || inst_csrrw || inst_csrrs || inst_mret));

assign idu_exu_excp       = excp_ill_inst || inst_ecall || inst_ebreak || reg_ifu_idu_excp;
assign idu_exu_excp_code  = {4{reg_ifu_idu_excp}} & reg_ifu_idu_excp_code
                          | {4{excp_ill_inst && !reg_ifu_idu_excp}} & 4'd2
                          | {4{inst_ecall && !reg_ifu_idu_excp}} & 4'd11
                          | {4{inst_ebreak && !reg_ifu_idu_excp}} & 4'd3;

//-----------------------------------------------------------------
// Pipe Logic
//-----------------------------------------------------------------
assign ifu_idu_handshake     = ifu_valid && idu_ready;
assign idu_exu_handshake     = idu_valid && exu_ready;
assign idu_valid             = idu_pipe_valid && !lsu_idu_flush && !raw_stall;
assign idu_ready             = idu_pipe_ready && !raw_stall;

// --------------- control part ------------------------
always @(posedge clock) begin
  if (reset) begin
    idu_pipe_valid           <= 1'b0;
  end else if (ifu_idu_handshake) begin
    idu_pipe_valid           <= 1'b1;
  end else if (idu_exu_handshake || lsu_idu_flush) begin
    idu_pipe_valid           <= 1'b0;
  end else begin
    idu_pipe_valid           <= idu_pipe_valid;
  end
end

always @(posedge clock) begin
  if (reset) begin
    idu_pipe_ready           <= 1'b1;
  end else if (idu_exu_handshake || lsu_idu_flush) begin
    idu_pipe_ready           <= 1'b1;
  end else if (ifu_idu_handshake) begin
    idu_pipe_ready           <= 1'b0;
  end else begin
    idu_pipe_ready           <= idu_pipe_ready;
  end
end

// ----------------- data part ------------------------
always @(posedge clock) begin
  if (reset) begin
    reg_ifu_idu_excp       <= 1'b0;
    reg_ifu_idu_excp_code  <= 4'b0;
    reg_ifu_idu_pc         <= 32'h0;
    reg_ifu_idu_tpc        <= 32'h0;
    reg_ifu_idu_inst       <= 32'h0;
  end else if (ifu_idu_handshake) begin
    reg_ifu_idu_excp       <= ifu_idu_excp;
    reg_ifu_idu_excp_code  <= ifu_idu_excp_code;
    reg_ifu_idu_pc         <= ifu_idu_pc;
    reg_ifu_idu_tpc        <= ifu_idu_tpc;
    reg_ifu_idu_inst       <= ifu_idu_inst;
  end else begin
    reg_ifu_idu_excp       <= reg_ifu_idu_excp;
    reg_ifu_idu_excp_code  <= reg_ifu_idu_excp_code;
    reg_ifu_idu_pc         <= reg_ifu_idu_pc;
    reg_ifu_idu_tpc        <= reg_ifu_idu_tpc;
    reg_ifu_idu_inst       <= reg_ifu_idu_inst;
  end
end

`ifdef ysyx_23060170_SIM_INFO
assign idu_exu_inst              = reg_ifu_idu_inst;
`endif

//======================================================
//                  idu logic
//======================================================
// == inst predecode ==================
assign func7     = reg_ifu_idu_inst[31:25];
assign rs2       = reg_ifu_idu_inst[24:20];
assign rs1       = reg_ifu_idu_inst[19:15];
assign func3     = reg_ifu_idu_inst[14:12];
assign rd        = reg_ifu_idu_inst[11:7];
assign opcode    = reg_ifu_idu_inst[6:2];

// == inst signal =====================
assign op_lui    = (opcode == 5'b01101);
assign op_auipc  = (opcode == 5'b00101);
assign op_jal    = (opcode == 5'b11011);
assign op_jalr   = (opcode == 5'b11001);
assign op_branch = (opcode == 5'b11000);
assign op_load   = (opcode == 5'b00000);
assign op_store  = (opcode == 5'b01000);
assign op_imm    = (opcode == 5'b00100);
assign op_op     = (opcode == 5'b01100);
assign op_system = (opcode == 5'b11100);
assign op_fencei = (opcode == 5'b00011);

assign inst_beq      = op_branch && func3 == 3'b000;
assign inst_bne      = op_branch && func3 == 3'b001;
assign inst_blt      = op_branch && func3 == 3'b100;
assign inst_bge      = op_branch && func3 == 3'b101;
assign inst_bltu     = op_branch && func3 == 3'b110;
assign inst_bgeu     = op_branch && func3 == 3'b111;

assign inst_lb       = op_load && func3 == 3'b000;
assign inst_lh       = op_load && func3 == 3'b001;
assign inst_lw       = op_load && func3 == 3'b010;
assign inst_lbu      = op_load && func3 == 3'b100;
assign inst_lhu      = op_load && func3 == 3'b101;

assign inst_sb       = op_store && func3 == 3'b000;
assign inst_sh       = op_store && func3 == 3'b001;
assign inst_sw       = op_store && func3 == 3'b010;

assign inst_addi     = op_imm && func3 == 3'b000;
assign inst_slti     = op_imm && func3 == 3'b010;
assign inst_sltiu    = op_imm && func3 == 3'b011;
assign inst_xori     = op_imm && func3 == 3'b100;
assign inst_ori      = op_imm && func3 == 3'b110;
assign inst_andi     = op_imm && func3 == 3'b111;
assign inst_slli     = op_imm & (func3 == 3'b001) & (func7 == 7'h0);
assign inst_srli     = op_imm & (func3 == 3'b101) & (func7 == 7'h0);
assign inst_srai     = op_imm & (func3 == 3'b101) & (func7 == 7'b0100000);

assign inst_add      = op_op & (func3 == 3'b000) & (func7 == 7'h0);
assign inst_sub      = op_op & (func3 == 3'b000) & (func7 == 7'b0100000);
assign inst_sll      = op_op & (func3 == 3'b001) & (func7 == 7'h0);
assign inst_slt      = op_op & (func3 == 3'b010) & (func7 == 7'h0);
assign inst_sltu     = op_op & (func3 == 3'b011) & (func7 == 7'h0);
assign inst_xor      = op_op & (func3 == 3'b100) & (func7 == 7'h0);
assign inst_srl      = op_op & (func3 == 3'b101) & (func7 == 7'h0);
assign inst_sra      = op_op & (func3 == 3'b101) & (func7 == 7'b0100000);
assign inst_or       = op_op & (func3 == 3'b110) & (func7 == 7'h0);
assign inst_and      = op_op & (func3 == 3'b111) & (func7 == 7'h0);

assign inst_ecall    = op_system & (func3 == 3'b000) & (func7 == 7'h0) & (rs2 == 5'h0);
assign inst_ebreak   = op_system & (func3 == 3'b000) & (func7 == 7'h0) & (rs2 == 5'h1);
assign inst_csrrw    = op_system & (func3 == 3'b001);
assign inst_csrrs    = op_system & (func3 == 3'b010);
assign inst_mret     = op_system & (func3 == 3'b000) & (func7 == 7'b0011000) & (rs2 == 5'b00010);

// == control signal ==================
// alu
assign idu_exu_alu_op[0]    = op_auipc | op_jal | op_jalr | op_load  | op_store | inst_addi | inst_add | is_B;
assign idu_exu_alu_op[1]    = inst_sub;
assign idu_exu_alu_op[2]    = inst_slli  | inst_sll;
assign idu_exu_alu_op[3]    = inst_slti  | inst_slt;
assign idu_exu_alu_op[4]    = inst_sltiu | inst_sltu;
assign idu_exu_alu_op[5]    = inst_xori  | inst_xor;
assign idu_exu_alu_op[6]    = inst_srli  | inst_srl;
assign idu_exu_alu_op[7]    = inst_srai  | inst_sra;
assign idu_exu_alu_op[8]    = inst_ori   | inst_or;
assign idu_exu_alu_op[9]    = inst_andi  | inst_and;

// mem
assign idu_exu_mem_ren        = op_load;
assign idu_exu_mem_wen        = op_store;
// assign idu_exu_mem_func3[2:0] = func3; // mem func3 code

// regfile
assign idu_exu_gpr_wen      = ~(op_branch | op_store | op_system & (func3 == 3'b000)) && |rd[3:0];

// csr
assign idu_exu_csr_wen      = |rs1 & (inst_csrrw | inst_csrrs);

// == imm =============================
assign I_imm   = {{20{reg_ifu_idu_inst[31]}}, reg_ifu_idu_inst[31:20]};
assign S_imm   = {{20{reg_ifu_idu_inst[31]}}, reg_ifu_idu_inst[31:25], reg_ifu_idu_inst[11:7]};
assign B_imm   = {{20{reg_ifu_idu_inst[31]}}, reg_ifu_idu_inst[7], reg_ifu_idu_inst[30:25], reg_ifu_idu_inst[11:8], 1'b0};
assign U_imm   = {reg_ifu_idu_inst[31:12], 12'b0};
assign J_imm   = {{12{reg_ifu_idu_inst[31]}}, reg_ifu_idu_inst[19:12], reg_ifu_idu_inst[20], reg_ifu_idu_inst[30:21], 1'b0};

assign is_I    = op_jalr | op_load | op_imm | inst_csrrw | inst_csrrs;
assign is_S    = op_store;
assign is_B    = op_branch;
assign is_U    = op_lui | op_auipc;
assign is_J    = op_jal;

assign imm     = ( {32{is_I}} & I_imm )
               | ( {32{is_S}} & S_imm )
               | ( {32{is_B}} & B_imm )
               | ( {32{is_U}} & U_imm )
               | ( {32{is_J}} & J_imm );

// == exu use signal =========================
assign sel_idu_out        = op_system;
assign idu_exu_out        = sel_idu_out ? csr_rdata : imm;
assign idu_exu_pc         = reg_ifu_idu_pc;
assign idu_exu_gpr_rdata1 = gpr_idu_rdata1 & {32{|rs1[3:0]}};
assign idu_exu_gpr_rdata2 = gpr_idu_rdata2 & {32{|rs2[3:0]}};

assign idu_exu_branch_code[2:0] = func3; // branch func3 code

assign idu_exu_exu_sel_signal[7] = op_fencei;
assign idu_exu_exu_sel_signal[6] = is_B;
assign idu_exu_exu_sel_signal[5] = op_jal;
assign idu_exu_exu_sel_signal[4] = op_lui | sel_idu_out; //idu_exu_sel_exu_out
assign idu_exu_exu_sel_signal[3] = op_jalr;
assign idu_exu_exu_sel_signal[2] = inst_mret;
assign idu_exu_exu_sel_signal[1] = op_auipc;
assign idu_exu_exu_sel_signal[0] = op_op;
assign idu_exu_tpc_or_csr_wdata = (inst_csrrs | inst_csrrw) ? csr_wdata : reg_ifu_idu_tpc;

// == regfile addr ====================
assign idu_exu_gpr_waddr   = rd;
assign idu_gpr_raddr1      = rs1;
assign idu_gpr_raddr2      = rs2;

// == csr =============================
assign csrr_ws_addr      = {2{((I_imm == MTVEC    ))}} & 2'd0
                         | {2{((I_imm == MEPC     ))}} & 2'd1
                         | {2{((I_imm == MCAUSE   ))}} & 2'd2
                         | {2{((I_imm == MSTATUS  ))}} & 2'd3;
assign idu_csr_raddr     = {2{(inst_csrrw | inst_csrrs)}} & csrr_ws_addr
                         | {2{inst_mret}}  & 2'd1;

assign idu_exu_csr_waddr = csrr_ws_addr;

assign csr_rdata = I_imm == MVENDORID
                      ? 32'h79737978
                      : I_imm == MARCHID
                          ? 32'd23060170
                          : csr_idu_rdata;

assign csr_wdata = {32{inst_csrrs}} & (gpr_idu_rdata1 | csr_rdata)
                 | {32{inst_csrrw}} & gpr_idu_rdata1;

// == raw check =======================
wire             inst_read_rs1 ;
wire             inst_read_rs2 ;
wire             raw_rs1_stall ;
wire             raw_rs2_stall ;
assign inst_read_rs1 = ~(op_lui | op_auipc | op_jal);
assign inst_read_rs2 = op_branch | op_store | op_op;
assign raw_rs1_stall = inst_read_rs1 && idu_pipe_valid && |rs1[3:0]
                        && (exu_idu_gpr_waddr == rs1[3:0] ||
                            lsu_idu_gpr_waddr == rs1[3:0]);
assign raw_rs2_stall = inst_read_rs2 && idu_pipe_valid && |rs2[3:0]
                        && (exu_idu_gpr_waddr == rs2[3:0] ||
                            lsu_idu_gpr_waddr == rs2[3:0]);
assign raw_stall = (raw_rs1_stall | raw_rs2_stall) && !lsu_idu_flush;

// == perf counter ====================
`ifdef ysyx_23060170_SIM_INFO

wire is_jump /*verilator public*/;
wire is_load /*verilator public*/;
wire is_alu /*verilator public*/;
wire is_csr /*verilator public*/;
wire is_trap /*verilator public*/;
assign is_jump = op_jal | op_jalr;
assign is_load = inst_lb | inst_lh | inst_lw | inst_lbu | inst_lhu;
assign is_alu  = is_U | (is_I && ~is_load && ~is_csr && ~op_jalr) | op_op;
assign is_csr  = inst_csrrw | inst_csrrs;
assign is_trap = inst_ecall | inst_mret | inst_ebreak;

wire             inst_lui ;
wire             inst_auipc ;
wire             inst_jal ;
wire             inst_jalr ;
assign inst_lui      = op_lui;
assign inst_auipc    = op_auipc;
assign inst_jal      = op_jal;
assign inst_jalr     = op_jalr && (func3 == 3'b000);

assign idu_exu_tpc               = reg_ifu_idu_tpc;
`endif
endmodule
