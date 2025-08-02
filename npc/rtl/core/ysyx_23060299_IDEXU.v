`include "../include/ysyx_23060299_npc_defines.v"

module ysyx_23060299_IDEXU (
    input   wire            clock                       ,
    input   wire            reset                       ,

    // from IFU         
    input   wire    [31:0]  inst_idu                    ,
    input   wire    [31:0]  pc_IDEXU                    ,
    input   wire            ifu_valid                   ,

    // to IFU           
    output  wire            idexu_ready                 ,
    output  reg             need_jump_ifu               ,
    output  reg             branch_inst_ifu             ,
    output  reg     [31:0]  pc_jump                     ,
    output  reg             jump_inst                   ,

    // to regfile   
    output  wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0]     rs1_idx     ,
    output  wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0]     rs2_idx     ,
    output  wire                                rs1_ren     ,
    output  wire                                rs2_ren     ,
    input   wire    [31:0]                      rs1_IDEXU   ,
    input   wire    [31:0]                      rs2_IDEXU   ,

    // to LSU   
    output  reg                             wr_en_lsu       ,
    output  reg     [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_lsu      ,
    output  reg                             lw_lsu          ,
    output  reg                             lbu_lsu         ,
    output  reg                             lb_lsu          ,
    output  reg                             lh_lsu          ,
    output  reg                             lhu_lsu         ,
    output  reg                             sw_lsu          ,
    output  reg                             sh_lsu          ,
    output  reg                             sb_lsu          ,
    output  reg     [31:0]                  exu_result_lsu  ,
    output  reg     [31:0]                  rs2_lsu         ,
    output  reg                             idexu_valid     ,
    input   wire                            lsu_ready       ,

    // from LSU
    input   wire            lsu_rhandshake_d1   ,

    // from WBU
    input   wire                            wr_en_wbu       ,
    input   wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_wbu      ,
    input   wire    [31:0]                  wbu_result      ,
    input   wire                            load_inst_wbu   ,

`ifdef ysyx_23060299_verilator_env
    // signal to debug, can be removed
    output  reg     [31:0]  pc_LSU              ,
`endif

    // to CSR Reg
    output  wire    [31:0]  csr_wdata           ,
    output  wire    [11:0]  csr_waddr           ,
    output  wire            csr_wen             ,
    input   wire    [31:0]  csr_rdata           ,
    output  wire    [11:0]  csr_raddr           ,
    output  wire            csr_ren             ,
    output  wire    [31:0]  pc_csr              ,
    output  wire            ecall_csr           ,
    output  wire            mret_csr            
);

wire    [31:0]                      rs1         ;
wire    [31:0]                      rs2         ;
wire    [`ysyx_23060299_REG_ADDR_WIDTH - 1:0]     rd_idx      ;
wire                                wr_en       ;

wire            need_pc_U   ;
wire            dec_inst_U  ;
wire            dec_inst_I  ;
wire            dec_inst_J  ;
wire            dec_inst_S  ;
wire            dec_inst_R  ;
wire            dec_inst_B  ;
wire    [31:0]  imm         ;

wire            alu_xor     ;
wire            alu_or      ;
wire            alu_add     ;
wire            alu_comp    ;
wire            alu_sr      ;
wire            alu_sl      ;
wire            alu_slogic  ;
wire            alu_and     ;
wire            alu_signed  ;

wire            jalr        ; 
wire            beq         ; 
wire            bne         ; 
wire            bge         ; 
wire            bgeu        ; 
wire            blt         ; 
wire            bltu        ; 

wire            sw          ;
wire            sh          ;
wire            sb          ;
wire            lw          ;
wire            lbu         ;
wire            lb          ;
wire            lh          ;
wire            lhu         ;
wire            need_sub    ;

wire            ecall       ;
wire            mret        ;
wire            csrrs       ;
wire            csrrw       ;

// from IFU
wire            ifu_idexu_handshake   ;

// to LSU
wire            idexu_lsu_handshake   /* verilator public_flat_rd */;

// common
wire    [6:0]   op_code         ;
wire    [2:0]   func3           ;
wire    [6:0]   func7           ;
wire            func3_000       ;
wire            func3_001       ;
wire            func3_010       ;
wire            func3_011       ;
wire            func3_100       ;
wire            func3_101       ;
wire            func3_110       ;
wire            func3_111       ;
wire            invalid_inst    ;

// U type inst
wire    [31:0]  imm_U   ;
wire            auipc   ;
wire            lui     ;

// I type inst
wire    [31:0]  imm_I   ;
wire            xori    ;
wire            ori     ;
wire            addi    ;
wire            ebreak  ;
wire            slti    ;
wire            sltiu   ;
wire            srai    ;
wire            andi    ;
wire            srli    ;
wire            slli    ;

// J type inst
wire    [31:0]  imm_J   ;
wire            jal     ;

// S type inst
wire    [31:0]  imm_S   ;

// R type inst
wire            add     ;
wire            sub     ;
wire            sltu    ;
wire            xorr    ;
wire            orr     ;
wire            sll     ;
wire            andr    ;
wire            slt     ;
wire            sra     ;
wire            srl     ;

// B type inst
wire    [31:0]  imm_B   ;

// CSR type inst
wire    [11:0]  csr_idx ;
wire            dec_csr ;

wire    [31:0]  exu_result      ;
wire            load_inst       ;
reg             load_inst_lsu   ;

wire            rs1_need_forward_LSU2EXU    ;
wire            rs2_need_forward_LSU2EXU    ;
wire            rs1_need_forward_WBU2EXU    ;
wire            rs2_need_forward_WBU2EXU    ;

wire            need_jump_ifu_w             ;

`ifdef ysyx_23060299_verilator_env  

// for verilator
// yosys-sta need to mask
import "DPI-C" function void trace_func_call(int pc, int target);
import "DPI-C" function void trace_func_ret(int pc);

always @(posedge clock) begin
    if(jal && (rd_idx == 1) && ifu_idexu_handshake)
        trace_func_call(pc_IDEXU, pc_IDEXU  + imm);
end

always @(posedge clock) begin
    if(jalr && ifu_idexu_handshake) begin
        if(inst_idu == 32'h00008067)
            trace_func_ret(pc_IDEXU);
        else if(rd_idx == 1)
            trace_func_call(pc_IDEXU, rs1  + imm);
        else if((rd_idx == 0) && (imm == 0))
            trace_func_call(pc_IDEXU, rs1  + imm);
  end
end

`endif

`ifdef ysyx_23060299_M_EXTENSION

wire            mul     ;
wire            mulh    ;
wire            mulhsu  ;
wire            mulhu   ;
wire            div     ;
wire            divu    ;
wire            rem     ;
wire            remu    ;

wire    [31:0]  muldiv_reg_wdata_o  ;
wire            muldiv_reg_we_o     ;
wire            muldiv_stall_o      ;
wire            alu_muldiv          ;
wire            alu_muldiv_r        ;

assign  alu_muldiv  =   mul ||  mulh    ||  mulhsu  ||  mulhu   ||  div ||  divu    ||  rem ||  remu    ;

assign  mul     =   (op_code    ==  7'b0110011) &&  func3_000   &&  (func7  ==  7'b0000001) ;
assign  mulh    =   (op_code    ==  7'b0110011) &&  func3_001   &&  (func7  ==  7'b0000001) ;
assign  mulhsu  =   (op_code    ==  7'b0110011) &&  func3_010   &&  (func7  ==  7'b0000001) ;
assign  mulhu   =   (op_code    ==  7'b0110011) &&  func3_011   &&  (func7  ==  7'b0000001) ;
assign  div     =   (op_code    ==  7'b0110011) &&  func3_100   &&  (func7  ==  7'b0000001) ;
assign  divu    =   (op_code    ==  7'b0110011) &&  func3_101   &&  (func7  ==  7'b0000001) ;
assign  rem     =   (op_code    ==  7'b0110011) &&  func3_110   &&  (func7  ==  7'b0000001) ;
assign  remu    =   (op_code    ==  7'b0110011) &&  func3_111   &&  (func7  ==  7'b0000001) ;

reg mul_r ,   mulh_r,   mulhsu_r, mulhu_r,  div_r,    divu_r,   rem_r,    remu_r;

always @(posedge clock or posedge reset) begin
    if(reset) begin
        mul_r       <=  1'b0    ;
        mulh_r      <=  1'b0    ;
        mulhsu_r    <=  1'b0    ;    
        mulhu_r     <=  1'b0    ;
        div_r       <=  1'b0    ;
        divu_r      <=  1'b0    ;
        rem_r       <=  1'b0    ;
        remu_r      <=  1'b0    ;
    end
    else if(ifu_idexu_handshake) begin
        mul_r       <=  mul     ;
        mulh_r      <=  mulh    ;
        mulhsu_r    <=  mulhsu  ;    
        mulhu_r     <=  mulhu   ;
        div_r       <=  div     ;
        divu_r      <=  divu    ;
        rem_r       <=  rem     ;
        remu_r      <=  remu    ;
    end
    else if(muldiv_reg_we_o)begin
        mul_r       <=  1'b0    ;
        mulh_r      <=  1'b0    ;
        mulhsu_r    <=  1'b0    ;    
        mulhu_r     <=  1'b0    ;
        div_r       <=  1'b0    ;
        divu_r      <=  1'b0    ;
        rem_r       <=  1'b0    ;
        remu_r      <=  1'b0    ;
    end
end

assign  alu_muldiv_r  =   mul_r ||  mulh_r    ||  mulhsu_r  ||  mulhu_r   ||  div_r ||  divu_r    ||  rem_r ||  remu_r    ;

wire    muldiv_start    =   ifu_idexu_handshake ;

exu_muldiv  exu_muldiv(
    .clock              (clock      ),
    .reset              (reset      ),

    .muldiv_op1_i       (rs1                    ),
    .muldiv_op2_i       (rs2                    ),
    .muldiv_op_mul_i    ((mul    && muldiv_start)  ||  mul_r      ),
    .muldiv_op_mulh_i   ((mulh   && muldiv_start)  ||  mulh_r     ),
    .muldiv_op_mulhsu_i ((mulhsu && muldiv_start)  ||  mulhsu_r   ),
    .muldiv_op_mulhu_i  ((mulhu  && muldiv_start)  ||  mulhu_r    ),
    .muldiv_op_div_i    ((div    && muldiv_start)  ||  div_r      ),
    .muldiv_op_divu_i   ((divu   && muldiv_start)  ||  divu_r     ),
    .muldiv_op_rem_i    ((rem    && muldiv_start)  ||  rem_r      ),
    .muldiv_op_remu_i   ((remu   && muldiv_start)  ||  remu_r     ),

    .muldiv_reg_wdata_o (muldiv_reg_wdata_o     ),
    .muldiv_reg_we_o    (muldiv_reg_we_o        ),
    .muldiv_stall_o     (muldiv_stall_o         )

);

`endif

// to IFU
assign  ifu_idexu_handshake   =   ifu_valid   &&  idexu_ready   ;

// to LSU

`ifdef ysyx_23060299_M_EXTENSION
always @(posedge clock ) begin
    if(reset)
        idexu_valid   <=  1'b0    ;
    else if((ifu_idexu_handshake &&  !alu_muldiv) ||  (alu_muldiv_r  &&  muldiv_reg_we_o))
        idexu_valid   <=  1'b1    ;
    else if((idexu_lsu_handshake   &&  !ifu_idexu_handshake)  ||    (alu_muldiv &&  idexu_ready))
        idexu_valid   <=  1'b0    ;
end
`else
always @(posedge clock ) begin
    if(reset)
        idexu_valid   <=  1'b0    ;
    else if(ifu_idexu_handshake)
        idexu_valid   <=  1'b1    ;
    else if(idexu_lsu_handshake   &&  !ifu_idexu_handshake)
        idexu_valid   <=  1'b0    ;
end
`endif

assign  idexu_lsu_handshake   =   idexu_valid   &&  lsu_ready   ;

assign  pc_csr      =   pc_IDEXU   ;

//common
assign  func3       =   inst_idu[14:12];
assign  func3_000   =   (func3  ==  3'b000);
assign  func3_001   =   (func3  ==  3'b001);
assign  func3_010   =   (func3  ==  3'b010);
assign  func3_011   =   (func3  ==  3'b011);
assign  func3_100   =   (func3  ==  3'b100);
assign  func3_101   =   (func3  ==  3'b101);
assign  func3_110   =   (func3  ==  3'b110);
assign  func3_111   =   (func3  ==  3'b111);
assign  op_code     =   inst_idu[6:0];
assign  rs1_idx     =   inst_idu[15 + `ysyx_23060299_REG_ADDR_WIDTH -1 :15];
assign  rs2_idx     =   inst_idu[20 + `ysyx_23060299_REG_ADDR_WIDTH -1 :20];
assign  rd_idx      =   inst_idu[7 + `ysyx_23060299_REG_ADDR_WIDTH -1 :7];
assign  func7       =   inst_idu[31:25];


// U type inst
assign  auipc       =   (op_code    ==  7'b0010111)    ;
assign  lui         =   (op_code    ==  7'b0110111)    ;
assign  imm_U       =   ({{12{inst_idu[31]}}, inst_idu[31:12]} << 12);
assign  dec_inst_U  =   auipc   |   lui;
assign  need_pc_U   =   auipc   ;

// I type inst
assign  addi        =   (op_code    ==  7'b0010011) &&  func3_000   ;
assign  slli        =   (op_code    ==  7'b0010011) &&  func3_001   &&  (func7  ==  7'b0000000);
assign  slti        =   (op_code    ==  7'b0010011) &&  func3_010   ; 
assign  sltiu       =   (op_code    ==  7'b0010011) &&  func3_011   ;
assign  xori        =   (op_code    ==  7'b0010011) &&  func3_100   ;
assign  srai        =   (op_code    ==  7'b0010011) &&  func3_101   &&  (func7  ==  7'b0100000);
assign  srli        =   (op_code    ==  7'b0010011) &&  func3_101   &&  (func7  ==  7'b0000000);
assign  ori         =   (op_code    ==  7'b0010011) &&  func3_110   ;
assign  andi        =   (op_code    ==  7'b0010011) &&  func3_111   ;
assign  jalr        =   (op_code    ==  7'b1100111) &&  func3_000   ;
assign  ebreak      =   (op_code    ==  7'b1110011) &&  func3_000   &&  (inst_idu[31:20] == 12'b1);
assign  lw          =   (op_code    ==  7'b0000011) &&  func3_010   ;
assign  lbu         =   (op_code    ==  7'b0000011) &&  func3_100   ;
assign  lb          =   (op_code    ==  7'b0000011) &&  func3_000   ;
assign  lh          =   (op_code    ==  7'b0000011) &&  func3_001   ;
assign  lhu         =   (op_code    ==  7'b0000011) &&  func3_101   ;
assign  imm_I       =   {{20{inst_idu[31]}}, inst_idu[31:20]};
assign  dec_inst_I  =   xori    |   ori    |    addi    |   jalr    |
                        ebreak  |   lw     |    sltiu   |   srai    |
                        lbu     |   andi   |    srli    |   slli    |
                        lh      |   lhu    |    lb      |   slti    ;

// J type inst
assign  jal         =   (op_code    ==  7'b1101111)    ;
assign  imm_J       =   {{12{inst_idu[31]}}, inst_idu[19:12], inst_idu[20], inst_idu[30:21], 1'b0};
assign  dec_inst_J  =   jal ;

// S type inst
assign  sw          =   (op_code    ==  7'b0100011) &&  func3_010;
assign  sh          =   (op_code    ==  7'b0100011) &&  func3_001;
assign  sb          =   (op_code    ==  7'b0100011) &&  func3_000;
assign  imm_S       =   {{20{inst_idu[31]}}, inst_idu[31:25], inst_idu[11:7]};
assign  dec_inst_S  =   sw     |    sh     |    sb      ;

// R type inst
assign  add         =   (op_code    ==  7'b0110011) &&  func3_000   &&  (func7  ==  7'b0000000);
assign  sub         =   (op_code    ==  7'b0110011) &&  func3_000   &&  (func7  ==  7'b0100000);
assign  sltu        =   (op_code    ==  7'b0110011) &&  func3_011   &&  (func7  ==  7'b0000000);
assign  xorr        =   (op_code    ==  7'b0110011) &&  func3_100   ;
assign  orr         =   (op_code    ==  7'b0110011) &&  func3_110   ;
assign  sll         =   (op_code    ==  7'b0110011) &&  func3_001   &&  (func7  ==  7'b0000000);
assign  andr        =   (op_code    ==  7'b0110011) &&  func3_111   &&  (func7  ==  7'b0000000);
assign  slt         =   (op_code    ==  7'b0110011) &&  func3_010   &&  (func7  ==  7'b0000000);
assign  sra         =   (op_code    ==  7'b0110011) &&  func3_101   &&  (func7  ==  7'b0100000);
assign  srl         =   (op_code    ==  7'b0110011) &&  func3_101   &&  (func7  ==  7'b0000000);
assign  dec_inst_R  =   add    |    sub     |   sltu    |   xorr    |
                        orr    |    sll     |   andr    |   slt     |
                        sra    |    srl     
                        `ifdef ysyx_23060299_M_EXTENSION
                        |   alu_muldiv
                        `endif
                        ;

// B type inst
assign  beq         =   (op_code    ==  7'b1100011) &&  func3_000;
assign  bne         =   (op_code    ==  7'b1100011) &&  func3_001;
assign  bge         =   (op_code    ==  7'b1100011) &&  func3_101;
assign  bgeu        =   (op_code    ==  7'b1100011) &&  func3_111;
assign  blt         =   (op_code    ==  7'b1100011) &&  func3_100;
assign  bltu        =   (op_code    ==  7'b1100011) &&  func3_110;
assign  imm_B       =   {{20{inst_idu[31]}}, inst_idu[7], inst_idu[30:25], inst_idu[11:8], 1'b0};
assign  dec_inst_B  =   beq    |    bne     |    bge    |   bgeu    |   blt    |    bltu    ;

// common
assign  rs1_ren     =   dec_inst_I  |   dec_inst_S  |   dec_inst_R  |   dec_inst_B  |   csrrw   |   csrrs   ;
assign  rs2_ren     =   dec_inst_S  |   dec_inst_R  |   dec_inst_B  ;
assign  wr_en       =   dec_inst_I  |   dec_inst_U  |   dec_inst_J  |   dec_inst_R  |   jalr    |   csrrw   |   csrrs   ;

assign  alu_xor     =   xori    |   xorr    ;
assign  alu_or      =   ori     |   orr     ;
assign  alu_add     =   addi    |   auipc   |   add   |   sub   |   lui     ;
assign  need_sub    =   sltiu   |   sub     |   beq   |   bne   |   sltu    |   bge    
                    |   bgeu    |   blt     |   bltu  |   slt   |   slti    ;
assign  alu_comp    =   sltiu   |   sltu    |   slt   |   slti  ;
assign  alu_sr      =   srai    |   srli    |   sra   |   srl   ;
assign  alu_sl      =   sll     |   slli    ;
assign  alu_and     =   andi    |   andr    ;
assign  alu_slogic  =   srli    |   sll     |   slli  |   srl   ;
assign  alu_signed  =   slt     |   slti    ;

assign  imm =       ({32{dec_inst_U}} & imm_U)
                |   ({32{dec_inst_I}} & imm_I)
                |   ({32{dec_inst_J}} & imm_J)
                |   ({32{dec_inst_S}} & imm_S)
                |   ({32{dec_inst_B}} & imm_B)
                |   32'd0   ;
            
assign  invalid_inst    =   !(  dec_inst_U  ||  dec_inst_I  ||  dec_inst_J
                            ||  dec_inst_S  ||  dec_inst_R  ||  dec_inst_B  
                            ||  dec_csr     )   ;

assign  rs1_need_forward_LSU2EXU    =   (rs1_idx    ==  rd_idx_lsu) &&  wr_en_lsu   &&  rs1_ren    &&  (rd_idx_lsu    !=  0)  &&  idexu_valid;
assign  rs2_need_forward_LSU2EXU    =   (rs2_idx    ==  rd_idx_lsu) &&  wr_en_lsu   &&  rs2_ren    &&  (rd_idx_lsu    !=  0)  &&  idexu_valid;
assign  rs1_need_forward_WBU2EXU    =   (rs1_idx    ==  rd_idx_wbu) &&  wr_en_wbu   &&  rs1_ren    &&  (rd_idx_wbu    !=  0);
assign  rs2_need_forward_WBU2EXU    =   (rs2_idx    ==  rd_idx_wbu) &&  wr_en_wbu   &&  rs2_ren    &&  (rd_idx_wbu    !=  0);


assign  rs1 =   ({32{rs1_need_forward_LSU2EXU                                   }} &   exu_result_lsu               ) |
                ({32{rs1_need_forward_WBU2EXU   &&  !rs1_need_forward_LSU2EXU   }} &   wbu_result                   ) |
                ({32{!rs1_need_forward_LSU2EXU  &&  !rs1_need_forward_WBU2EXU   }} &   rs1_IDEXU                    ) |
                32'd0   ;

assign  rs2 =   ({32{rs2_need_forward_LSU2EXU                                   }} &   exu_result_lsu               ) |
                ({32{rs2_need_forward_WBU2EXU   &&  !rs2_need_forward_LSU2EXU   }} &   wbu_result                   ) |
                ({32{!rs2_need_forward_LSU2EXU  &&  !rs2_need_forward_WBU2EXU   }} &   rs2_IDEXU                    ) |
                32'd0   ;

assign  load_inst   =   lw  ||  lbu ||  lb  ||  lh  ||  lhu ;

assign  idexu_ready =   (lsu_ready                   // lsu_ready 条件
                        ||  (lsu_rhandshake_d1       // load 提前一个周期拉高
                        ))
                        &&  !( (rs2_need_forward_LSU2EXU ||  rs1_need_forward_LSU2EXU) &&   load_inst_lsu)  // 不存在load指令的数据相关性
                        `ifdef ysyx_23060299_M_EXTENSION
                        &&  !alu_muldiv_r
                        `endif
                        ;

// xor operation
wire    [31:0]      xor_op1     ;
wire    [31:0]      xor_op2     ;
wire    [31:0]      xor_result  ;

assign  xor_op1     =   ({32{1'b1 }}    &   rs1 )
                    |   32'd0   ;

assign  xor_op2     =   ({32{dec_inst_I  }}  &   imm     )
                    |   ({32{dec_inst_R  }}  &   rs2     )
                    |   32'd0   ;

assign  xor_result  =   xor_op1    ^   xor_op2 ;

// or operation
wire    [31:0]      or_op1     ;
wire    [31:0]      or_op2     ;
wire    [31:0]      or_result  ;

assign  or_op1  =   ({32{1'b1 }}    &   rs1 )
                |   32'd0   ;

assign  or_op2  =   ({32{dec_inst_I }}  &   imm         )
                |   ({32{dec_inst_R }}  &   rs2         )
                |   ({32{csrrs      }}  &   csr_rdata   )   
                |   32'd0   ;

assign  or_result  =    or_op1  |   or_op2 ;

wire    [31:0]      add_op1         ;
wire    [31:0]      add_op2         ;
wire    [31:0]      add_result      ;
wire                is_min_signed   ;
wire    [32:0]      add_op2_tmp     ;
wire                add_overflow    ;
wire                add_result_sign ;
wire                add_less        ;
wire                add_carry       ;
wire                add_zero        ;

// add operation
assign  add_op1     =   ({32{need_pc_U                  }}  &   pc_IDEXU  )   // auipc
                    |   ({32{dec_inst_J                 }}  &   pc_IDEXU  )   // jal
                    |   ({32{jalr                       }}  &   rs1 )
                    |   ({32{dec_inst_I &&  !jalr       }}  &   rs1 )
                    |   ({32{dec_inst_S                 }}  &   rs1 )
                    |   ({32{dec_inst_R                 }}  &   rs1 )
                    |   ({32{dec_inst_B                 }}  &   rs1 )
                    |   32'd0   ;

assign  add_op2     =   ({32{dec_inst_U             }}  &   imm     )
                    |   ({32{dec_inst_J             }}  &   imm     )
                    |   ({32{jalr                   }}  &   imm     )
                    |   ({32{dec_inst_I &&  !jalr   }}  &   imm     )
                    |   ({32{dec_inst_S             }}  &   imm     )
                    |   ({32{dec_inst_R             }}  &   rs2     )
                    |   ({32{dec_inst_B             }}  &   rs2     )
                    |   32'd0   ;

assign  add_op2_tmp =   need_sub ? ~{1'b1, add_op2} + 32'b1 :   {1'b0, add_op2};
assign  {add_carry, add_result}  =   add_op1    +   add_op2_tmp ;   
assign  is_min_signed   =   add_op2_tmp[31] &&  add_op2[31] ;
assign  add_overflow    =   is_min_signed   ?   (add_op1[31] != add_op2_tmp[31] && add_result[31] != add_op1[31])
                                            :   (add_op1[31] == add_op2_tmp[31] && add_result[31] != add_op1[31]);
assign  add_result_sign =   add_result[31];
assign  add_less        =   add_overflow  ^ add_result_sign;
assign  add_zero        =   ~(|add_result);

// shift right operation
wire    signed  [31:0]      sr_op1      ;
wire            [4:0]       sr_op2      ;
wire            [31:0]      sr_result   ;

assign  sr_op1      =   rs1         ;
assign  sr_op2      =   ({5{dec_inst_R }}  &   rs2[4:0] )
                    |   ({5{dec_inst_I }}  &   imm[4:0] )
                    |   5'd0;
assign  sr_result   =   alu_slogic  ?   {sr_op1 >>  sr_op2} :   {sr_op1 >>>  sr_op2} ;

// shift left operation
wire    signed  [31:0]  sl_op1      ;
wire            [4:0]   sl_op2      ;
wire            [31:0]  sl_result   ;

assign  sl_op1      =   rs1 ;
assign  sl_op2      =   ({5{dec_inst_R }}  &   rs2[4:0] )
                    |   ({5{dec_inst_I }}  &   imm[4:0] )
                    |   5'd0;
assign  sl_result   =   sl_op1  <<  sl_op2 ;

// compare operation
wire    [31:0]      comp_result  ;
assign  comp_result =   ({32{alu_signed     }}  &   {31'd0, add_less}   )
                    |   ({32{!alu_signed    }}  &   {31'd0, !add_carry} );

// and operation
wire    [31:0]      and_result      ;
wire    [31:0]      and_op1         ;
wire    [31:0]      and_op2         ;

assign  and_op1     =   rs1         ;
assign  and_op2     =   ({32{dec_inst_I             }}  &   imm     )
                    |   ({32{dec_inst_R             }}  &   rs2     )
                    |   32'd0   ;
assign  and_result  =   and_op1 &   and_op2 ;

// mux
assign  exu_result  =   ({32{alu_xor                }}  &   xor_result          )
                    |   ({32{alu_or                 }}  &   or_result           )
                    |   ({32{alu_add                }}  &   add_result          )
                    |   ({32{alu_comp               }}  &   comp_result         )
                    |   ({32{alu_sr                 }}  &   sr_result           )
                    |   ({32{alu_sl                 }}  &   sl_result           )
                    |   ({32{alu_and                }}  &   and_result          )
                    |   ({32{csrrs  |  csrrw        }}  &   csr_rdata           )
                    |   ({32{dec_inst_S             }}  &   add_result          )
                    |   ({32{load_inst              }}  &   add_result          )
                    |   ({32{jalr   ||  dec_inst_J  }}  &   (pc_IDEXU  +   4)   )
                    |   32'd0   ;

always @(posedge clock ) begin
    if(reset) begin
        lw_lsu          <=  'd0 ; 
        lbu_lsu         <=  'd0 ; 
        lb_lsu          <=  'd0 ; 
        lh_lsu          <=  'd0 ; 
        lhu_lsu         <=  'd0 ; 
        sw_lsu          <=  'd0 ; 
        sh_lsu          <=  'd0 ; 
        sb_lsu          <=  'd0 ;
        load_inst_lsu   <=  'd0 ;
    end
    else if(ifu_idexu_handshake) begin
        lw_lsu          <=  lw          ;
        lbu_lsu         <=  lbu         ;
        lb_lsu          <=  lb          ;
        lh_lsu          <=  lh          ;
        lhu_lsu         <=  lhu         ;
        sw_lsu          <=  sw          ;
        sh_lsu          <=  sh          ;
        sb_lsu          <=  sb          ;
        load_inst_lsu   <=  load_inst   ;
    end
end

`ifdef ysyx_23060299_verilator_env
`ifdef ysyx_23060299_M_EXTENSION
    always @(posedge clock ) begin
        if(ifu_idexu_handshake && !alu_muldiv) begin
            pc_LSU          <=  pc_IDEXU    ;
        end
        else if(alu_muldiv_r  &&  muldiv_reg_we_o) begin
            pc_LSU          <=  pc_IDEXU_muldiv     ;
        end
    end
`else
    always @(posedge clock ) begin
        if(ifu_idexu_handshake) begin
            pc_LSU          <=  pc_IDEXU    ;
        end
    end
`endif
`endif


`ifdef ysyx_23060299_M_EXTENSION
reg [31:0]                  pc_IDEXU_muldiv ;
reg [`ysyx_23060299_REG_ADDR_WIDTH - 1:0] rd_idx_muldiv   ;
reg                         wr_en_muldiv    ;

always @(posedge clock ) begin
    if(ifu_idexu_handshake  &&  alu_muldiv) begin
        rd_idx_muldiv   <=  rd_idx      ;
        pc_IDEXU_muldiv <=  pc_IDEXU    ;
        wr_en_muldiv    <=  wr_en       ;
    end
end

always @(posedge clock ) begin
    if(ifu_idexu_handshake)
        rs2_lsu         <=  rs2         ;
end

always @(posedge clock ) begin
    if(ifu_idexu_handshake && !alu_muldiv) begin
        exu_result_lsu  <=  exu_result  ;
        rd_idx_lsu      <=  rd_idx      ;
        wr_en_lsu       <=  wr_en       ;
    end
    else if(alu_muldiv_r  &&  muldiv_reg_we_o) begin
        exu_result_lsu  <=  muldiv_reg_wdata_o  ;
        rd_idx_lsu      <=  rd_idx_muldiv       ;
        wr_en_lsu       <=  wr_en_muldiv        ;
    end
end

`else
always @(posedge clock ) begin
    if(ifu_idexu_handshake) begin
        exu_result_lsu  <=  exu_result  ;
        rd_idx_lsu      <=  rd_idx      ;
        rs2_lsu         <=  rs2         ;
    end
end

always @(posedge clock ) begin
    if(reset) begin
        wr_en_lsu       <=  'd0 ;
    end
    else if(ifu_idexu_handshake) begin
        wr_en_lsu       <=  wr_en       ;
    end
end

`endif

//  branch logic
assign  need_jump_ifu_w =   ifu_idexu_handshake   &&  (
                            jalr    
                        ||  dec_inst_J
                        ||  (beq    &&  add_zero    )
                        ||  (bne    &&  !add_zero   )
                        ||  (bge    &&  !add_less   )
                        ||  (bgeu   &&  add_carry   )
                        ||  (blt    &&  add_less    )
                        ||  (bltu   &&  !add_carry  )
                        ||  ecall
                        ||  mret
                        );

always @(posedge clock ) begin
    if(jalr || jal)
        pc_jump <=  add_result  ;
    else if(dec_inst_B)
        pc_jump <=  pc_IDEXU  +   imm_B   ;
    else if(ecall  ||  mret)
        pc_jump <=  csr_rdata   ;
end

always @(posedge clock ) begin
    if(reset)
        need_jump_ifu   <=  1'b0    ;
    else if(need_jump_ifu_w)
        need_jump_ifu   <=  1'b1    ;
    else
        need_jump_ifu   <=  1'b0    ;
end

always @(posedge clock ) begin
    if(reset)
        branch_inst_ifu <=  1'b0    ;
    else if(dec_inst_B  &&  ifu_idexu_handshake)
        branch_inst_ifu <=  1'b1    ;
    else
        branch_inst_ifu <=  1'b0    ;
end

always @(posedge clock ) begin
    if(reset)
        jump_inst   <=  1'b0    ;
    else if(ifu_idexu_handshake &&  (jal || jalr || beq || bne || bge || bgeu || blt || bltu || ecall || mret))
        jump_inst   <=  1'b1    ;
    else
        jump_inst   <=  1'b0    ;
end

// CSR logic
assign  csrrw       =   (op_code    ==  7'b1110011) &&  func3_001;
assign  csrrs       =   (op_code    ==  7'b1110011) &&  func3_010;
assign  ecall       =   (op_code    ==  7'b1110011) &&  (inst_idu[31:7] == 25'd0);
assign  mret        =   (op_code    ==  7'b1110011) &&  (inst_idu[31:7] == 25'b0011000_00010_00000_000_00000);
assign  csr_idx     =   inst_idu[31:20] ;
assign  csr_waddr   =   csr_idx     ;
assign  csr_raddr   =   csr_idx     ;
assign  csr_wen     =   ifu_idexu_handshake   ?   (csrrw   |   csrrs) :   'd0 ;
assign  csr_ren     =   ifu_idexu_handshake   ?   (csrrw   |   csrrs) :   'd0 ;
assign  dec_csr     =   csrrw   |   csrrs   |   ecall   |   mret    ;

assign  csr_wdata   =   ({32{csrrs}}    &   or_result   )
                    |   ({32{csrrw}}    &   rs1         )
                    |   32'd0   ;

assign  ecall_csr   =   ifu_idexu_handshake   ?   ecall   :   'd0 ;
assign  mret_csr    =   ifu_idexu_handshake   ?   mret    :   'd0 ;

`ifdef ysyx_23060299_verilator_env  

// for verilator 
// yosys-sta need to mask
import "DPI-C" function void npc_trap(int code);
import "DPI-C" function void npc_itrace(int pc, int inst_idu);

always @(posedge clock) begin
    if(ifu_idexu_handshake) begin
        if(ebreak)
            npc_trap(32'd1);
        else if(invalid_inst && reset)
            npc_trap(pc_IDEXU);
    end
end

`endif

`ifdef ysyx_23060299_PO

import "DPI-C" function void idu_cal();
import "DPI-C" function void idu_sw();
import "DPI-C" function void idu_csr();
import "DPI-C" function void idu_jump();
import "DPI-C" function void trace_pc();

always @(posedge clock) begin
    if(ifu_idexu_handshake) begin
        npc_itrace(pc_IDEXU, inst_idu);
        trace_pc();
    end
end

always @(posedge clock) begin
    if(ifu_idexu_handshake && (sw || sh || sb))
        idu_sw();
end

always @(posedge clock) begin
    if(ifu_idexu_handshake && (csrrs || csrrw || ecall  ||  mret))
        idu_csr();
end

always @(posedge clock) begin
    if(ifu_idexu_handshake && (jalr || dec_inst_J || beq || bne || bge || bgeu || blt || bltu))
        idu_jump();
end

always @(posedge clock) begin
    if(ifu_idexu_handshake && (alu_xor || alu_or || alu_add || alu_comp || alu_sr || alu_sl || alu_and ))
        idu_cal();
end

`endif

endmodule

