/* ****************************************
    * 顺序双发射ID译码模块（草稿）
    *
    * 该模块实现了指令译码功能，并将译码结果打包发送，减少臃肿的数据传递
***************************************** */
`include "defines.vh"
module ID(#
    parameter DECODE_WIDTH = 64
)(
    input             clk,
    input             rst,
    input      [31:0] inst,
    output reg [DECODE_WIDTH-1:0] decode
    //[31:0] imm, [36:32] rd, [41:37] rs1, [46:42] rs2, [49:47] func3, [50] RegWrite
    //[51] MemRead, [52] MemWrite, [56:53] mask, [59:57] alu_op, [60] is_Branch, [61] is_Jal, [62] is_Jalr, [63] decode_valid 
); 
    wire [6:0] opcode     = inst[6:0];
    wire [6:0] func7      = inst[31:25];
    wire [2:0] func3      = inst[14:12];
    wire [4:0] rd         = inst[11:7];
    wire [4:0] rs1        = inst[19:15];
    wire [4:0] rs2        = inst[24:20];
    wire [4:0] get_opcode = inst[6:2];
    wire [31:0] imm;
    wire [2:0] alu_op;

    wire [31:0] immI   = {{20{inst[31]}}, inst[31:20]};
    wire [31:0] immU   = {inst[31:12], 12'b0};
    wire [31:0] immS   = {{20{inst[31]}}, inst[31:25], inst[11:7]};
    wire [31:0] immB   = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8], 1'b0};
    wire [31:0] immJ   = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
    wire [31:0] immR   = 32'b0;
    wire [31:0] immCSR = {27'b0, inst[19:15]};

    assign imm = (get_opcode == `INST_TYPE_AUIPC || get_opcode == `INST_TYPE_LUI                            ) ? immU :
                 (get_opcode == `INST_TYPE_JAL                                                              ) ? immJ :
                 (get_opcode == `INST_TYPE_JALR || get_opcode == `INST_TYPE_L || get_opcode == `INST_TYPE_I ) ? immI :
                 (get_opcode == `INST_TYPE_R                                                                ) ? immR :
                 (get_opcode == `INST_TYPE_S                                                                ) ? immS :
                 (get_opcode == `INST_TYPE_B                                                                ) ? immB :
                 (opcode == `INST_CSR && (func3 == `F3_CSRRCI || func3 == `F3_CSRRSI || func3 == `F3_CSRRWI)) ? immCSR : 32'h0;
     
    assign alu_op = (get_opcode  == `INST_TYPE_R && func3 == 3'b000 && func7[5]) ? `ALU_SUB :
                    (get_opcode  == `INST_TYPE_R && func3 == 3'b000 && !func7[5]) ? `ALU_ADD :
                    (get_opcode  == `INST_TYPE_I && func3 == `F3_ADDI) ? `ALU_ADD :
                    (get_opcode  == `INST_TYPE_I && func3 == `F3_SLTI) ? `ALU_SLT :
                    (get_opcode  == `INST_TYPE_B && (func3 == `F3_BEQ || func3 == `F3_BNE)) ? `ALU_SUB :
                    (get_opcode  == `INST_TYPE_B && (func3 == `F3_BLT || func3 == `F3_BGE)) ? `ALU_SLT :
                    (get_opcode  == `INST_TYPE_B && (func3 == `F3_BLTU || func3 == `F3_BGEU)) ? `ALU_SLTU :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_ORI) ? `ALU_OR :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_XORI) ? `ALU_XOR :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_ANDI) ? `ALU_AND :
                    (get_opcode  == `INST_TYPE_R && func3 == `F3_SLTU && func7 == 7'b0000000) ? `ALU_SLTU :
                    (get_opcode  == `INST_TYPE_I && func3 == `F3_SLTU) ? `ALU_SLTU :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_RSH && func7 == 7'b0000000) ? `ALU_SRL :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_RSH && func7 == 7'b0100000) ? `ALU_SRA :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_LSH && func7 == 7'b0000000) ? `ALU_SLL :
                    ((get_opcode == `INST_TYPE_R || get_opcode == `INST_TYPE_I) && func3 == `F3_SLT && func7 == 7'b0000000) ? `ALU_SLT :
                    (get_opcode  == `INST_TYPE_L || get_opcode == `INST_TYPE_AUIPC) ? `ALU_ADD : `ALU_ADD;

    wire MemRead  = (get_opcode == `INST_TYPE_L) &&
                    ((func3 == `F3_LW) || (func3 == `F3_LH) || (func3 == `F3_LB) || (func3 == `F3_LHU) || (func3 == `F3_LBU));
    wire MemWrite = (get_opcode == `INST_TYPE_S);

    wire [3:0] mask;
    assign mask =  ((get_opcode == `INST_TYPE_S || get_opcode == `INST_TYPE_L) && (func3 == `F3_SW || func3 == `F3_LW)) ? `Mem_Word :
                   ((get_opcode == `INST_TYPE_S || get_opcode == `INST_TYPE_L) && (func3 == `F3_SH || func3 == `F3_LH)) ? `Mem_Half :
                   ((get_opcode == `INST_TYPE_S || get_opcode == `INST_TYPE_L) && (func3 == `F3_SB || (func3 == `F3_LB && opcode == 7'b00000_11))) ? `Mem_Bit :
                   (get_opcode == `INST_TYPE_L && func3 == `F3_LHU) ? `Mem_UHalf : 
                   (get_opcode == `INST_TYPE_L && func3 == `F3_LBU) ? `Mem_UBit : `Mem_Word; 
    
    wire is_jal    = (opcode == `INST_JAL);
    wire is_jalr   = (opcode == `INST_JALR) & (func3 == 3'b000);
    wire is_branch = (get_opcode == `INST_TYPE_B);

    wire csr_rd_en = csr && !csr_ecall && !csr_mret;
    wire rd_en     = (get_opcode == `INST_TYPE_LUI || get_opcode == `INST_TYPE_AUIPC || get_opcode == `INST_TYPE_L ||
                      get_opcode == `INST_TYPE_JAL || get_opcode == `INST_TYPE_JALR || get_opcode == `INST_TYPE_R ||
                      get_opcode == `INST_TYPE_I || csr_rd_en);

    //decode打包发送
    always @(posedge clk) begin
        if (rst) begin
            decode <= 64'b0;
        end
        else begin
            decode <= {inst, imm, rd, rs1, rs2, func3,
                       rd_en, MemRead, MemWrite, mask, alu_op, is_branch, is_jal, is_jalr,
                       1'b1 // decode_valid
                       };
        end
    end
endmodule
