// module ysyx_24070003_exu(
//     input clock,
//     input rstn,
//     //input IDU_EXU_STALL,
//     output      reg       EXU_IDU_ready,          // 从执行单元(EXU)到IDU的就绪信号
//     input               IDU_EXU_valid,          // IDU到EXU的有效信号
//     input       LSU_EXU_ready,
//     output      reg EXU_LSU_valid,
//     input IDU_EXU_ren,
//     //input IDU_EXU_wen,
//     input IDU_EXU_reg,
//     input IDU_EXU_ebreak,
//     input IDU_EXU_jal,
//     input IDU_EXU_jalr,
//     // input IDU_EXU_lw,
//     // input IDU_EXU_lh,
//     // input IDU_EXU_lb,
//     // input IDU_EXU_lbu,
//     // input IDU_EXU_lhu,
//     // input IDU_EXU_sw,
//     // input IDU_EXU_sb,
//     // input IDU_EXU_sh,
//     input [8:0] IDU_EXU_RW_sign,
//     input [2:0] csr_op,
//     input [31:0] csr_data,
//     input [31:0] IDU_EXU_pre_dnpc,

//     input IDU_EXU_exu_raw_rs1,
//     input IDU_EXU_exu_raw_rs2,
//     input IDU_EXU_lsu_raw_rs1,
//     input IDU_EXU_lsu_raw_rs2,
//     input [31:0] LSU_forward_data,

//     input IDU_EXU_ecall,
//     input IDU_EXU_mret,
//     input IDU_EXU_C_type,
//     input IDU_EXU_B_type,
//     input [2:0] IDU_EXU_csr_rst,
    
//     input [31:0] rs1_data,
//     input [31:0] rs2_data,
//     input [31:0] imm_data,
//     input [31:0] pc_data,
//     input [1:0] alu_src1,
//     input [1:0] alu_src2,
//     input branch,
//     input u_alu_type,
//     //input mul_high,
//     //input U_type_1,
//     //input J_type_1,
    
//     output  [31:0] EXU_LSU_alu_out,
//     //output  EXU_IFU_zero,
//     input [3:0]  alu_op,
//     input [4:0] IDU_EXU_rd,
//     output[4:0] EXU_LSU_rd,
//     output reg EXU_LSU_ren,
//     //output reg EXU_LSU_wen,
//     output reg EXU_LSU_reg,
//     output reg EXU_LSU_ebreak,
//     //output reg EXU_IFU_jal,
//     //output reg EXU_IFU_jalr,
//     // output reg EXU_LSU_lw,
//     // output reg EXU_LSU_lh,
//     // output reg EXU_LSU_lb,
//     // output reg EXU_LSU_lbu,
//     // output reg EXU_LSU_lhu,
//     // output reg EXU_LSU_sw,
//     // output reg EXU_LSU_sb,
//     // output reg EXU_LSU_sh,
//     output reg [8:0]  EXU_LSU_RW_sign,
//     output reg [31:0] EXU_LSU_csr_data,
//     output reg [31:0] EXU_LSU_csr_in,
//     output     [31:0] EXU_IFU_pc,
//     output reg EXU_LSU_ecall,
//     output reg EXU_LSU_mret,
//     output reg EXU_LSU_C_type,
//     output reg [2:0] EXU_LSU_csr_rst,
//    // output reg EXU_IFU_STALL_done,
//     output     EXU_flush,
//     output reg [31:0] EXU_LSU_RS2DATA,
//     output reg [31:0] EXU_LSU_PC,
//     output reg [31:0] EXU_LSU_dnpc,
//     //output reg [31:0] EXU_LSU_IMM,

//     output [4:0]  EXU_IDU_REG_ADDR,
//     output        EXU_IDU_REG_WEN,
//     output        EXU_IDU_REN,

//     output [31:0] EXU_BTB_PC,
//     output        EXU_BTB_updata_valid
    
// );
// wire [31:0] RS1_data;
// wire [31:0] RS2_data;
// assign EXU_IDU_REG_ADDR = IDU_EXU_rd;
// assign EXU_IDU_REG_WEN = IDU_EXU_reg && IDU_EXU_valid && EXU_IDU_ready;
// assign EXU_IDU_REN = IDU_EXU_ren && IDU_EXU_valid && EXU_IDU_ready;
// //wire [3:0]aluop;
// wire zero;
// wire [31:0] alu_out;
// wire [31:0] csr_in;

// //assign RS1_data = (IDU_EXU_exu_raw_rs1) ? EXU_LSU_alu_out : (IDU_EXU_lsu_raw_rs1) ? LSU_forward_data : rs1_data;
// ysyx_24070003_mux4_32bit my(
//     .sel            ({IDU_EXU_exu_raw_rs1,IDU_EXU_lsu_raw_rs1}),
//     .a              (rs1_data), 
//     .b              (LSU_forward_data),
//     .c              (EXU_LSU_alu_out),
//     .d              (EXU_LSU_alu_out),
//     .out            (RS1_data)
// );
// //MuxKeyInternal #(2, 2, 32, 1) i0 (RS1_data, {IDU_EXU_exu_raw_rs1,IDU_EXU_lsu_raw_rs1}, EXU_LSU_alu_out, {2'b00,rs1_data,2'b01,LSU_forward_data});
// //assign RS2_data = (IDU_EXU_exu_raw_rs2) ? EXU_LSU_alu_out : (IDU_EXU_lsu_raw_rs2) ? LSU_forward_data : rs2_data;
// ysyx_24070003_mux4_32bit my1(
//     .sel            ({IDU_EXU_exu_raw_rs2,IDU_EXU_lsu_raw_rs2}),
//     .a              (rs2_data), 
//     .b              (LSU_forward_data),
//     .c              (EXU_LSU_alu_out),
//     .d              (EXU_LSU_alu_out),
//     .out            (RS2_data)
// );
// // assign csr_in = ( {32{IDU_EXU_csw}} & (RS1_data)) |
// //                 ( {32{IDU_EXU_csc}} & (RS1_data &csr_data)) |
// //                 ( {32{IDU_EXU_css}} & (csr_data | RS1_data)) ;

// //wire [2:0] csr_op = {IDU_EXU_csw, IDU_EXU_csc, IDU_EXU_css};

// assign  csr_in =     (csr_op == 3'b100) ? RS1_data        :
//                      (csr_op == 3'b010) ? RS1_data & csr_data :
//                      (csr_op == 3'b001) ? RS1_data | csr_data :
//                                         32'h0;   // 无效，理论上不会出现
// wire [31:0] opdata1;
// wire [31:0] opdata2;
// //assign opdata1 = (alu_src1 == 2'b10)? RS1_data : (alu_src1 == 2'b01) ? 32'h00000000 : pc_data;
// ysyx_24070003_mux4_32bit my3(
//     .sel            (alu_src1),
//     .a              (pc_data), 
//     .b              (32'h00000000),
//     .c              (RS1_data),
//     .d              (pc_data),
//     .out            (opdata1)
// );
// //assign opdata2 = (alu_src2 == 2'b10)? RS2_data : (alu_src2 == 2'b01) ? 32'h00000004 : imm_data;
// ysyx_24070003_mux4_32bit my4(
//     .sel            (alu_src2),
//     .a              (imm_data), 
//     .b              (32'h00000004),
//     .c              (RS2_data),
//     .d              (imm_data),
//     .out            (opdata2)
// );

// ysyx_24070003_alu my_alu(
//     .clock          (clock      ),
//     .opdata1        (opdata1   ),
//     .opdata2        (opdata2   ),
//     .branch         (branch     ), 
//     .u_alu_type     (u_alu_type ),
//     .alu_crtl       (alu_op      ),
//     .alu_out        (alu_out    ),
//     .zero           (zero       )
// );

// wire btb_pre_error = (IDU_EXU_pre_dnpc != EXU_IFU_pc) && (IDU_EXU_jal || IDU_EXU_B_type);
// assign EXU_flush = (IDU_EXU_ecall || IDU_EXU_mret || IDU_EXU_jalr || btb_pre_error) && (IDU_EXU_valid && EXU_IDU_ready);

// assign EXU_IDU_ready = LSU_EXU_ready;  

// ///assign EXU_BTB_PC = (pc_sel[3]) ? next_pc_jal : next_pc_jalr;
// assign EXU_BTB_PC = next_pc;
// assign EXU_BTB_updata_valid = (IDU_EXU_jal || IDU_EXU_B_type) && (IDU_EXU_valid && EXU_IDU_ready);

// always @(posedge clock) begin 
//     if(rstn) begin
//         EXU_LSU_valid <= 1'b0;
//     end
//     else if(EXU_IDU_ready & IDU_EXU_valid) begin
//         EXU_LSU_valid <= 1'b1;
//     end
//     else if(LSU_EXU_ready && EXU_LSU_valid)begin
//         EXU_LSU_valid <= 1'b0;
//     end
// end
// wire [31:0] pc_opdata1;
// wire [31:0] pc_opdata2;

// assign pc_opdata1 = (pc_sel[1] || pc_sel[3]) ? pc_data : RS1_data;
// assign pc_opdata2 = imm_data;
// wire [31:0] next_pc = pc_opdata1 + pc_opdata2;
// // wire [31:0] next_pc_jal = pc_data + imm_data;
// // wire [31:0] next_pc_jalr = RS1_data + imm_data;

// wire [3:0] pc_sel = {IDU_EXU_jal || IDU_EXU_B_type, IDU_EXU_ecall || IDU_EXU_mret, IDU_EXU_jal || zero, IDU_EXU_jalr};
// assign EXU_IFU_pc =
//             (pc_sel[2]) ? csr_data      :
//             (pc_sel[1] || pc_sel[0]) ? next_pc   :
//                                   pc_data + 32'd4;



// always@(posedge clock)
// begin 
//    if(rstn)begin
//     //EXU_IFU_zero              <=        1'b0;
//     EXU_LSU_alu_out           <=        32'b0;
//     EXU_LSU_rd                <=        5'b0;
//     EXU_LSU_ren               <=        1'b0;
//     //EXU_LSU_wen               <=        1'b0;
//     //EXU_LSU_reg               <=        1'b0;
//     EXU_LSU_ebreak               <=        1'b0;
//     //EXU_IFU_jal               <=        1'b0;
//     //EXU_IFU_jalr               <=        1'b0;
//     // EXU_LSU_lw               <=        1'b0;
//     // EXU_LSU_lh               <=        1'b0;
//     // EXU_LSU_lb               <=        1'b0;
//     // EXU_LSU_lbu               <=        1'b0;
//     // EXU_LSU_lhu               <=        1'b0;
//     // EXU_LSU_sw               <=        1'b0;
//     // EXU_LSU_sb               <=        1'b0;
//     // EXU_LSU_sh               <=        1'b0;
//     EXU_LSU_RW_sign            <=        8'b0;
//     EXU_LSU_csr_data           <=        32'b0;
//     EXU_LSU_ecall               <=        1'b0;
//     EXU_LSU_mret               <=        1'b0;
//     EXU_LSU_C_type               <=        1'b0;
//     EXU_LSU_csr_rst               <=        3'b0;
//     EXU_LSU_csr_in               <=        32'b0;
//     //EXU_IFU_pc               <=        32'b0;
//     EXU_LSU_RS2DATA           <=        32'b0;
//     EXU_LSU_PC               <=        32'b0;
//     EXU_LSU_dnpc               <=        32'b0;
//     //EXU_LSU_IMM              <=          32'b0;
//     end
//     else if(IDU_EXU_valid & EXU_IDU_ready)begin
//     EXU_LSU_alu_out           <=        alu_out;
//     //EXU_IFU_zero              <=        zero;
//     EXU_LSU_rd                <=        IDU_EXU_rd;
//     EXU_LSU_ren               <=        IDU_EXU_ren;
//     //EXU_LSU_wen               <=        IDU_EXU_wen;
//     EXU_LSU_reg               <=        IDU_EXU_reg;
//     EXU_LSU_ebreak               <=        IDU_EXU_ebreak;
//     EXU_LSU_RW_sign             <=      IDU_EXU_RW_sign;
//     //EXU_IFU_jal               <=        IDU_EXU_jal;
//     //EXU_IFU_jalr               <=        IDU_EXU_jalr;
//     // EXU_LSU_lw               <=        IDU_EXU_lw;
//     // EXU_LSU_lh               <=        IDU_EXU_lh;
//     // EXU_LSU_lb               <=        IDU_EXU_lb;
//     // EXU_LSU_lbu               <=        IDU_EXU_lbu;
//     // EXU_LSU_lhu               <=        IDU_EXU_lhu;
//     // EXU_LSU_sw               <=        IDU_EXU_sw;
//     // EXU_LSU_sb               <=        IDU_EXU_sb;
//     // EXU_LSU_sh               <=        IDU_EXU_sh;
//     EXU_LSU_csr_data           <=        csr_data;
//     EXU_LSU_ecall               <=        IDU_EXU_ecall;
//     EXU_LSU_mret               <=        IDU_EXU_mret;
//     EXU_LSU_C_type               <=        IDU_EXU_C_type;
//     EXU_LSU_csr_rst               <=        IDU_EXU_csr_rst;
//     EXU_LSU_csr_in               <=        csr_in;
//     //EXU_IFU_pc               <=        pc_jump;
//     EXU_LSU_RS2DATA           <=        RS2_data;
//     EXU_LSU_PC               <=        pc_data;
//     EXU_LSU_dnpc               <=        EXU_IFU_pc;
//     //EXU_LSU_IMM                <=      imm_data;
//     end
//     else begin
//     //EXU_IFU_zero              <=        1'b0;
//     EXU_LSU_alu_out           <=        EXU_LSU_alu_out;
//     EXU_LSU_rd                <=        EXU_LSU_rd;
//     EXU_LSU_ren               <=        EXU_LSU_ren;
//     //EXU_LSU_wen               <=        EXU_LSU_wen;
//     //EXU_LSU_reg               <=        1'b0;
//     EXU_LSU_ebreak               <=        EXU_LSU_ebreak;
//     //EXU_IFU_jal               <=        1'b0;
//     //EXU_IFU_jalr               <=        1'b0;
//     // EXU_LSU_lw               <=        EXU_LSU_lw;
//     // EXU_LSU_lh               <=        EXU_LSU_lh;
//     // EXU_LSU_lb               <=        EXU_LSU_lb;
//     // EXU_LSU_lbu               <=        EXU_LSU_lbu;
//     // EXU_LSU_lhu               <=        EXU_LSU_lhu;
//     // EXU_LSU_sw               <=        EXU_LSU_sw;
//     // EXU_LSU_sb               <=        EXU_LSU_sb;
//     // EXU_LSU_sh               <=        EXU_LSU_sh;
//     EXU_LSU_RW_sign            <=       EXU_LSU_RW_sign;
//     EXU_LSU_csr_data           <=        EXU_LSU_csr_data;
//     EXU_LSU_ecall               <=        EXU_LSU_ecall;
//     EXU_LSU_mret               <=        EXU_LSU_mret;
//     EXU_LSU_C_type               <=        EXU_LSU_C_type;
//     EXU_LSU_csr_rst               <=        EXU_LSU_csr_rst;
//     EXU_LSU_csr_in               <=        EXU_LSU_csr_in;
//     //EXU_IFU_pc               <=        32'b0;
//     EXU_LSU_RS2DATA           <=        EXU_LSU_RS2DATA;
//     EXU_LSU_PC               <=        EXU_LSU_PC;
//     EXU_LSU_dnpc               <=        EXU_LSU_dnpc;
//     //EXU_LSU_IMM              <=         EXU_LSU_IMM;
// end
// end
// endmodule

