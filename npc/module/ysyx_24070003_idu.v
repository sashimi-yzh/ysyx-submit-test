// module ysyx_24070003_idu(
//     input wire [31:0] INSTR,
//     input wire [31:0] IFU_IDU_PC,
//     input [31:0]IFU_IDU_pre_dnpc,
//     input       flush,
//     //input wire EXU_IFU_flush,
//     input clock,
//     input rst_n,
//     output fence_i,
//     //input               IFU_IDU_STALL,
//     input               IFU_IDU_valid,          // 从IFU到IDU的有效信号
//     output           IDU_IFU_ready,          // IDU到IFU的就绪信号
//     input               EXU_IDU_ready,          // 从执行单元(EXU)到IDU的就绪信号
//     output reg          IDU_EXU_valid,          // IDU到EXU的有效信号
//     //output reg[6:0] IDU_EXU_opcode,
//     output reg[4:0] IDU_EXU_rd,
//     output reg[4:0] IDU_EXU_rs1,
//     output reg[4:0] IDU_EXU_rs2,
//     output reg[2:0] IDU_EXU_csr_rst,
//     output reg[31:0]IDU_EXU_imm,
//     output reg [3:0]IDU_EXU_alu_op ,       
//     output reg IDU_EXU_u_alu_type    ,
//     //output reg IDU_EXU_mul_high      ,
//     output reg [1:0] IDU_EXU_alu_src1      ,
//     output reg [1:0] IDU_EXU_alu_src2      ,
//     output reg IDU_EXU_branch        ,
//    // output reg IDU_EXU_mem_to_reg    ,
//     output reg IDU_EXU_mem_read      ,
//     //output reg IDU_EXU_mem_write     ,
//     output reg IDU_EXU_reg_write     ,
//     output reg IDU_EXU_jal           ,
//     output reg IDU_EXU_jalr          ,
//     // output reg IDU_EXU_lw            ,
//     // output reg IDU_EXU_lh            ,
//     // output reg IDU_EXU_lb            ,
//     // output reg IDU_EXU_lbu           ,
//     // output reg IDU_EXU_lhu           ,
//     // output reg IDU_EXU_sw            ,
//     // output reg IDU_EXU_sb            ,
//     // output reg IDU_EXU_sh            ,
//     output reg [8:0] IDU_EXU_RW_sign,
//     output reg [2:0]IDU_EXU_csr_op,
//     output reg IDU_EXU_ebreak        ,
//     output reg IDU_EXU_ecall         ,
//     output reg IDU_EXU_mret          ,
//     //output reg IDU_EXU_U_type_1      ,
//     //output reg IDU_EXU_J_type_1      ,
//     output reg IDU_EXU_B_type      ,
//     //output reg IDU_EXU_pcsrc         ,
//     output reg IDU_EXU_C_type        ,
//     //output reg IDU_EXU_STALL         ,
//     output reg [31:0] IDU_EXU_PC  ,
//     output reg [31:0] IDU_EXU_pre_dnpc,

//     output reg IDU_EXU_exu_raw_rs1,
//     output reg IDU_EXU_exu_raw_rs2,
//     output reg IDU_EXU_lsu_raw_rs1,
//     output reg IDU_EXU_lsu_raw_rs2,

//     // output reg [63:0] calcu_type_count,
//     // output reg [63:0] Jump_type_count,
//     // output reg [63:0] BJump_type_count,
//     // output reg [63:0] LOAD_type_count,
//     // output reg [63:0] STORE_type_count,
//     // output reg [63:0] C_type_count,

//     input         exu_reg_write_en,
//     input  [4:0]  exu_rd_addr,
//     input         exu_ren,

//     // 来自级
//     input         lsu_reg_write_en,
//     input  [4:0]  lsu_rd_addr,


//     output        stall

// );
// // reg [63:0] calcu_type_count;
// // reg [63:0] Jump_type_count;
// // reg [63:0] LOAD_type_count;
// // reg [63:0] STORE_type_count;
// // reg [63:0] C_type_count;

// // reg [31:0]instr;
// wire    [31:0]    immI_num ;
// wire    [31:0]    immS_num ;
// wire    [31:0]    immB_num ;
// wire    [31:0]    immU_num ;
// wire    [31:0]    immJ_num ;
// wire    [2:0]     immC_num ;
// wire    [6:0]     opcode   ;
// wire    [2:0]     funct3   ; 
// wire    [6:0]     funct7   ; 
// wire    [4:0]     rd       ;     
// wire    [4:0]     rs1      ; 
// wire    [4:0]     rs2      ; 
// wire    [2:0]     csr_rst  ; 
// wire    [31:0]    imm      ; 
// wire U_type;
// wire J_type;
// wire I_type;
// wire S_type;
// wire R_type;
// wire B_type;
// wire C_type;
// wire I_type_1 = (opcode == 7'b0010011);

// assign funct3 = (R_type || I_type || S_type || B_type|| C_type) ? INSTR[14:12] : 3'b0;
// assign funct7 = (R_type || I_type_1) ? INSTR[31:25] : 7'b0;
// assign opcode = INSTR[6:0];
// assign I_type = (opcode == 7'b0010011 || opcode == 7'b1100111 || opcode == 7'b0000011 || opcode == 7'b1010011);
// assign R_type = (opcode == 7'b0110011);
// assign S_type = (opcode == 7'b0100011);
// assign U_type = (opcode == 7'b0110111 || opcode == 7'B0010111);
// assign B_type = (opcode == 7'b1100011);
// assign J_type = (opcode == 7'b1101111 || opcode == 7'b1011111);
// assign C_type = (opcode == 7'b1110011);

// assign  immI_num = { {21{INSTR[31]}}, INSTR[30:20] };
// assign  immS_num = { {21{INSTR[31]}}, INSTR[30:25], INSTR[11:7] };
// assign  immB_num = { {20{INSTR[31]}}, INSTR[7], INSTR[30:25], INSTR[11:8], 1'b0 };
// assign  immU_num = { INSTR[31], INSTR[30:12], 12'b0 };
// assign  immJ_num = { {12{INSTR[31]}}, INSTR[19:12], INSTR[20], INSTR[30:21], 1'b0 };
// assign  immC_num =   (INSTR[31:20] == 'h341) ? 3'd0 :
//                     (INSTR[31:20] == 'h300) ? 3'd1 :
//                     (INSTR[31:20] == 'h342) ? 3'd2 :
//                     (INSTR[31:20] == 'h305) ? 3'd3 : 
//                     (INSTR[31:20] == 'hf11) ? 3'd4 :
//                     (INSTR[31:20] == 'hf12) ? 3'd5 :3'd0;
// assign rs2 = (R_type || S_type || B_type) ? INSTR[24:20] :5'b0;
// assign csr_rst = (C_type) ? immC_num : 3'd0;
// assign rs1 = (R_type || S_type || B_type || I_type || C_type) ? INSTR[19:15] : 5'b0;

// assign rd = (R_type || I_type || U_type || J_type || C_type) ? INSTR[11:7] : 5'b0;



// assign imm = ( {32{I_type}} & immI_num ) |
//                      ( {32{S_type}} & immS_num ) |
//                      ( {32{B_type}} & immB_num ) |
//                      ( {32{U_type}} & immU_num ) |
//                      ( {32{J_type}} & immJ_num ) ;

// wire J_type_1;
// wire [1:0] alu_op;
// assign J_type_1 = (opcode == 7'b1101111) || I_type_2; 
// assign C_type = (opcode == 7'b1110011);
// wire I_type_2 = (opcode == 7'b1100111);
// wire I_type_3 = (opcode == 7'b0000011);
// wire I_type_4 = (opcode == 7'b1010011);
// wire jalr = (opcode == 7'b1100111);
// wire jal  = (opcode == 7'b1101111);
// wire U_type_1 = (opcode == 7'b0110111);

// wire csw = ( C_type && funct3 == 3'b001 );
// wire csc = ( C_type && funct3 == 3'b011 );
// wire css = ( C_type && funct3 == 3'b010 );

// wire lh   = (I_type_3 && funct3 == 3'b001);
// wire lw   = (I_type_3 && funct3 == 3'b010);
// wire lb   = (I_type_3 && funct3 == 3'b000);
// wire lbu  = (I_type_3 && funct3 == 3'b100);
// wire lhu  = (I_type_3 && funct3 == 3'b101);

// wire sw   = (S_type && funct3 == 3'b010);
// wire sb   = (S_type && funct3 == 3'b000);
// wire sh   = (S_type && funct3 == 3'b001);

// wire [8:0] rw_sign;
// assign rw_sign = {mem_write,lh,lw,lb,lbu,lhu,sw,sb,sh};
// // wire remu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b111);
// // wire mulh = (R_type && funct7 == 7'b0000001 && funct3 == 3'b001);
// // wire mulhu= (R_type && funct7 == 7'b0000001 && funct3 == 3'b011);
// // wire divu = (R_type && funct7 == 7'b0000001 && funct3 == 3'b101);
// wire sltu = (R_type && funct7 == 7'b0000000 && funct3 == 3'b011);
// // wire mul  = (R_type && funct7 == 7'b0000001 && funct3 == 3'b000);
// wire sltiu= (I_type_1 && funct3 == 3'b011);
// wire bltu = (B_type && funct3 == 3'b110);
// wire bgeu = (B_type && funct3 == 3'b111);

// wire u_alu_type = (sltu | sltiu | bltu | bgeu | lbu | lhu );
// //wire mul_high = mulh | mulhu;
// //wire jump = J_type | I_type_2;
// wire mem_read = I_type_3;
// wire mem_write = S_type;
// wire  ebreak = ( INSTR == 32'b00000000000100000000000001110011 ) ;
// wire ecall  = ( INSTR == 32'b00000000000000000000000001110011)  ;
// wire mret   = ( INSTR == 32'b00110000001000000000000001110011 ) ;
// wire reg_write = !(B_type || S_type);
// wire alu_src1 = R_type | I_type_1 | I_type_3 | I_type_4 | S_type | B_type;
// wire alu_src2 = R_type | B_type;

// wire idu_rs1_valid = R_type | I_type | S_type | B_type | C_type;
// wire idu_rs2_valid = R_type | S_type | B_type;
// //wire mem_to_reg = (mem_read|mem_write);
// wire branch = B_type;
// assign alu_op = (R_type) ? 2'b10 :
//                 (B_type) ? 2'b01 :
//                 (S_type | U_type | I_type_3 | J_type) ? 2'b00 :
//                 2'b11;
// wire [3:0] aluop;
// ysyx_24070003_exuop_ctrl my_exuop_crtl(
//     .funct3         (funct3),
//     .funct7         (funct7[5:0]),
//     .alu_op         (alu_op),
//     .aluOp          (aluop)
// );


// ///////////////////////////

// //////////////////////////

// wire rs1_raw_exu;
// wire rs2_raw_exu;
// wire rs1_raw_lsu;
// wire rs2_raw_lsu;

// ysyx_24070003_raw raw_detect(
//     // 来自译码的源寄存器
//     .idu_rs1_addr               (rs1),
//     .idu_rs2_addr               (rs2),
//     .idu_rs1_valid              (idu_rs1_valid),   // 为 1 表示本指令真正读 rs1
//     .idu_rs2_valid              (idu_rs2_valid),   // 为 1 表示本指令真正读 rs2

//     // 来自
//     .exu_reg_write_en           (exu_reg_write_en),
//     .exu_rd_addr                (exu_rd_addr),
//     .exu_ren                    (exu_ren),

//     // 来自级
//     .lsu_reg_write_en           (lsu_reg_write_en),
//     .lsu_rd_addr                (lsu_rd_addr),

//     .rs1_raw_exu                 (rs1_raw_exu),
//     .rs2_raw_exu                 (rs2_raw_exu),
//     .rs1_raw_lsu                 (rs1_raw_lsu),
//     .rs2_raw_lsu                 (rs2_raw_lsu),

//     // 输出有一个冲突就阻塞
//     .stall                      (stall)
// );
// ////////////0x0000100F//////////////0000000 00000 00000 001 00000 0001111/////////////
// assign fence_i = (INSTR == 32'h0000100F) && IFU_IDU_valid && IDU_IFU_ready;
// //wire pcsrc = (branch /*& zero*/) | jump | ecall | mret;


// wire [2:0] csr_op = {csw, csc, css};

// assign IDU_IFU_ready = EXU_IDU_ready  && (~stall);    // 设置IDU到IFU的就绪信号

// reg idu_exu_valid;
// always @(posedge clock) begin
//     if(rst_n) begin
//         idu_exu_valid <= 1'b0;
//     end else if(stall) begin
//         idu_exu_valid <= 1'b0;
//     end else if(IFU_IDU_valid && IDU_IFU_ready ) begin
//         idu_exu_valid <= 1'b1;
//     end else if(EXU_IDU_ready && IDU_EXU_valid) begin
//         idu_exu_valid <= 1'b0;
//     end
// end

// assign IDU_EXU_valid = idu_exu_valid ;

// always@(posedge clock)
// begin 
//    if((rst_n ))begin
//    // IDU_EXU_opcode        <=        7'b0;     
//     IDU_EXU_rd            <=        5'b0;
//     IDU_EXU_rs1           <=        5'b0;  
//     IDU_EXU_rs2           <=        5'b0;
//     IDU_EXU_csr_rst       <=        3'b0;    
//     IDU_EXU_imm           <=        32'b0;

//     IDU_EXU_alu_op              <=        4'b0;     
//     IDU_EXU_u_alu_type          <=        1'b0;   
//     //IDU_EXU_mul_high            <=        1'b0;
//     IDU_EXU_alu_src1            <=        2'b0;
//     IDU_EXU_alu_src2            <=        2'b0;  
//     IDU_EXU_branch              <=        1'b0;
//  //   IDU_EXU_mem_to_reg          <=        1'b0;    
//     IDU_EXU_mem_read            <=        1'b0;
//     //IDU_EXU_mem_write           <=        1'b0;     
//     IDU_EXU_reg_write           <=        1'b0;   
//     IDU_EXU_jal                 <=        1'b0;
//     IDU_EXU_jalr                <=        1'b0;
//     IDU_EXU_RW_sign             <=        8'b0;
//     // IDU_EXU_lw                  <=        1'b0;  
//     // IDU_EXU_lh                  <=        1'b0;
//     // IDU_EXU_lb                  <=        1'b0;    
//     // IDU_EXU_lbu                 <=        1'b0;
//     // IDU_EXU_lhu                 <=        1'b0;     
//     // IDU_EXU_sw                  <=        1'b0;   
//     // IDU_EXU_sb                  <=        1'b0;
//     // IDU_EXU_sh                  <=        1'b0;
//     IDU_EXU_csr_op              <=        3'b0;  
//     IDU_EXU_ebreak              <=        1'b0;
//     IDU_EXU_ecall               <=        1'b0;     
//     IDU_EXU_mret                <=        1'b0;   
//     //IDU_EXU_U_type_1            <=        1'b0;
//     //IDU_EXU_J_type_1            <=        1'b0;
//     //IDU_EXU_pcsrc               <=        1'b0;  
//     IDU_EXU_C_type              <=        1'b0;
//     IDU_EXU_B_type              <=        1'b0;
//     IDU_EXU_exu_raw_rs1           <=        1'b0;
//     IDU_EXU_exu_raw_rs2           <=        1'b0;
//     IDU_EXU_lsu_raw_rs1           <=        1'b0;
//     IDU_EXU_lsu_raw_rs2           <=        1'b0;

//     //IDU_EXU_STALL               <=        1'b0;
//     IDU_EXU_PC                  <=        32'b0;
//     IDU_EXU_pre_dnpc                <=        32'b0;
//     // calcu_type_count               <=        64'b0;
//     // Jump_type_count               <=        64'b0;
//     // BJump_type_count               <=        64'b0;
//     // C_type_count               <=        64'b0;
//     // LOAD_type_count               <=        64'b0;
//     // STORE_type_count               <=        64'b0;
//     end
//     else if(stall || flush)begin
//    // IDU_EXU_opcode        <=        opcode   ;     
//     IDU_EXU_rd            <=        5'b0;
//     IDU_EXU_rs1           <=        5'b0;  
//     IDU_EXU_rs2           <=        5'b0;
//     IDU_EXU_csr_rst       <=        3'b0;    
//     IDU_EXU_imm           <=        32'b0;

//     IDU_EXU_alu_op              <=        4'b0;     
//     IDU_EXU_u_alu_type          <=        1'b0;   
//     //IDU_EXU_mul_high            <=        1'b0;
//     IDU_EXU_alu_src1            <=       2'b0;
//     IDU_EXU_alu_src2            <=        2'b0;  
//     IDU_EXU_branch              <=        1'b0;
//  //   IDU_EXU_mem_to_reg          <=        1'b0;    
//     IDU_EXU_mem_read            <=        1'b0;
//     //IDU_EXU_mem_write           <=        1'b0;     
//     IDU_EXU_reg_write           <=        1'b0;   
//     IDU_EXU_jal                 <=        1'b0;
//     IDU_EXU_jalr                <=        1'b0;
//     // IDU_EXU_lw                  <=        1'b0;  
//     // IDU_EXU_lh                  <=        1'b0;
//     // IDU_EXU_lb                  <=        1'b0;    
//     // IDU_EXU_lbu                 <=        1'b0;
//     // IDU_EXU_lhu                 <=        1'b0;     
//     // IDU_EXU_sw                  <=        1'b0;   
//     // IDU_EXU_sb                  <=        1'b0;
//     // IDU_EXU_sh                  <=        1'b0;
//     IDU_EXU_RW_sign             <=        8'b0;
//     IDU_EXU_csr_op              <=        3'b0;     
//     IDU_EXU_ebreak              <=        1'b0;
//     IDU_EXU_ecall               <=        1'b0;     
//     IDU_EXU_mret                <=        1'b0;   
//     //IDU_EXU_U_type_1            <=        1'b0;
//     //IDU_EXU_J_type_1            <=        1'b0;
//     //IDU_EXU_pcsrc               <=        1'b0;  
//     IDU_EXU_C_type              <=        1'b0;
//     IDU_EXU_B_type              <=        1'b0;
//     //IDU_EXU_STALL               <=        1'b0;
//     IDU_EXU_PC                  <=        32'b0;
//     IDU_EXU_pre_dnpc                <=        32'b0;

//     IDU_EXU_exu_raw_rs1           <=        1'b0;
//     IDU_EXU_exu_raw_rs2           <=        1'b0;
//     IDU_EXU_lsu_raw_rs1           <=        1'b0;
//     IDU_EXU_lsu_raw_rs2           <=        1'b0;
//     end
//     else if(IFU_IDU_valid && IDU_IFU_ready)begin
//         // if(U_type|R_type|I_type_1|I_type_4) begin calcu_type_count <= calcu_type_count + 1'b1; end
//         // else if(J_type) begin Jump_type_count <= Jump_type_count + 1'b1; end
//         // else if(B_type) begin BJump_type_count <= BJump_type_count + 1'b1; end
//         // else if(C_type) begin C_type_count <= C_type_count + 1'b1; end
//         // else if(I_type_3) begin LOAD_type_count <= LOAD_type_count + 1'b1; end
//         // else if(S_type) begin STORE_type_count <= STORE_type_count + 1'b1; end
//    // IDU_EXU_opcode        <=        opcode   ;     
//     IDU_EXU_rd            <=        rd       ;
//     IDU_EXU_rs1           <=        rs1      ;  
//     IDU_EXU_rs2           <=        rs2      ;
//     IDU_EXU_csr_rst       <=        csr_rst  ;    
//     IDU_EXU_imm           <=        imm      ;
//     IDU_EXU_alu_op              <=        aluop;     
//     IDU_EXU_u_alu_type          <=        u_alu_type;   
//     //IDU_EXU_mul_high            <=        mul_high     ;
//     IDU_EXU_alu_src1            <=        {alu_src1, U_type_1}    ;
//     IDU_EXU_alu_src2            <=        {alu_src2, J_type_1}    ;  
//     IDU_EXU_branch              <=        branch       ;
//    // IDU_EXU_mem_to_reg          <=        mem_to_reg   ;    
//     IDU_EXU_mem_read            <=        mem_read     ;
//     //IDU_EXU_mem_write           <=        mem_write    ;     
//     IDU_EXU_reg_write           <=        reg_write    ;   
//     IDU_EXU_jal                 <=        jal          ;
//     IDU_EXU_jalr                <=        jalr   ;
//     IDU_EXU_RW_sign             <=        rw_sign;
//     // IDU_EXU_lw                  <=        lw     ;  
//     // IDU_EXU_lh                  <=        lh     ;
//     // IDU_EXU_lb                  <=        lb     ;    
//     // IDU_EXU_lbu                 <=        lbu    ;
//     // IDU_EXU_lhu                 <=        lhu    ;     
//     // IDU_EXU_sw                  <=        sw     ;   
//     // IDU_EXU_sb                  <=        sb     ;
//     // IDU_EXU_sh                  <=        sh     ;
//     IDU_EXU_csr_op              <=        csr_op;     
//     IDU_EXU_ebreak              <=        ebreak    ;
//     IDU_EXU_ecall               <=        ecall     ;     
//     IDU_EXU_mret                <=        mret      ;   
//     // IDU_EXU_U_type_1            <=        U_type_1  ;
//     // IDU_EXU_J_type_1            <=        J_type_1  ;
//     //IDU_EXU_pcsrc               <=        pcsrc     ;  
//     IDU_EXU_C_type              <=        C_type    ;
//     IDU_EXU_B_type              <=        B_type    ;
//     //IDU_EXU_STALL               <=        IFU_IDU_STALL;
//     IDU_EXU_PC                  <=        IFU_IDU_PC;
//     IDU_EXU_pre_dnpc                <=        IFU_IDU_pre_dnpc;

//     IDU_EXU_exu_raw_rs1           <=        rs1_raw_exu;
//     IDU_EXU_exu_raw_rs2           <=        rs2_raw_exu;
//     IDU_EXU_lsu_raw_rs1           <=        rs1_raw_lsu;
//     IDU_EXU_lsu_raw_rs2           <=        rs2_raw_lsu;
//     end
//     else begin
    
//    // IDU_EXU_opcode        <=        opcode   ;     
//     IDU_EXU_rd            <=        IDU_EXU_rd           ;
//     IDU_EXU_rs1           <=        IDU_EXU_rs1         ;
//     IDU_EXU_rs2           <=        IDU_EXU_rs2         ;
//     IDU_EXU_csr_rst       <=        IDU_EXU_csr_rst     ;
//     IDU_EXU_imm           <=        IDU_EXU_imm         ;
//     IDU_EXU_alu_op              <=  IDU_EXU_alu_op      ;
//     IDU_EXU_u_alu_type          <=  IDU_EXU_u_alu_type  ;
//     //IDU_EXU_mul_high            <=  IDU_EXU_mul_high    ;
//     IDU_EXU_alu_src1            <=  IDU_EXU_alu_src1    ;
//     IDU_EXU_alu_src2            <=  IDU_EXU_alu_src2    ;
//     IDU_EXU_branch              <=  IDU_EXU_branch      ;
//    // IDU_EXU_mem_to_reg          <=/ IDU_EXU_mem_to_reg    
//     IDU_EXU_mem_read            <=  IDU_EXU_mem_read    ;
//     //IDU_EXU_mem_write           <=  IDU_EXU_mem_write      ;
//     IDU_EXU_reg_write           <=  IDU_EXU_reg_write    ;
//     IDU_EXU_jal                 <=  IDU_EXU_jal         ;
//     IDU_EXU_jalr                <=  IDU_EXU_jalr        ;
//     IDU_EXU_RW_sign             <=  IDU_EXU_RW_sign;
//     // IDU_EXU_lw                  <=  IDU_EXU_lw          ;
//     // IDU_EXU_lh                  <=  IDU_EXU_lh          ;
//     // IDU_EXU_lb                  <=  IDU_EXU_lb          ;
//     // IDU_EXU_lbu                 <=  IDU_EXU_lbu         ;
//     // IDU_EXU_lhu                 <=  IDU_EXU_lhu         ;
//     // IDU_EXU_sw                  <=  IDU_EXU_sw          ;
//     // IDU_EXU_sb                  <=  IDU_EXU_sb          ;
//     // IDU_EXU_sh                  <=  IDU_EXU_sh        ;  
//     IDU_EXU_csr_op              <=        IDU_EXU_csr_op;  
//     IDU_EXU_ebreak              <=  IDU_EXU_ebreak    ;  
//     IDU_EXU_ecall               <=  IDU_EXU_ecall     ;  
//     IDU_EXU_mret                <=  IDU_EXU_mret      ;  
//     //IDU_EXU_U_type_1            <=  IDU_EXU_U_type_1  ;  
//     //IDU_EXU_J_type_1            <=  IDU_EXU_J_type_1  ;  
//     //IDU_EXU_pcsrc               <=//IDU_EXU_pcsrc   ;  
//     IDU_EXU_C_type              <=  IDU_EXU_C_type    ;  
//     IDU_EXU_B_type              <=  IDU_EXU_B_type    ;
//     //IDU_EXU_STALL               <=//IDU_EXU_STALL   ;  
//     IDU_EXU_PC                  <=  IDU_EXU_PC        ;  
//     IDU_EXU_pre_dnpc                <=  IDU_EXU_pre_dnpc      ;  

//     IDU_EXU_exu_raw_rs1           <=        IDU_EXU_exu_raw_rs1;
//     IDU_EXU_exu_raw_rs2           <=        IDU_EXU_exu_raw_rs2;
//     IDU_EXU_lsu_raw_rs1           <=        IDU_EXU_lsu_raw_rs1;
//     IDU_EXU_lsu_raw_rs2           <=        IDU_EXU_lsu_raw_rs2;
//     end
// end


// endmodule
