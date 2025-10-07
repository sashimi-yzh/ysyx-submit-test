// module ysyx_24070003_exuop_ctrl(
//     input [2:0]  funct3,
//     input [5:0]  funct7,
//     input [1:0]  alu_op,
//     output reg [3:0] aluOp
// );
// `define ysyx_24070003_OP_ADD         4'b0001 // +
// `define ysyx_24070003_OP_SUB         4'b0011 // -

// `define ysyx_24070003_OP_AND         4'b0100 // &
// `define ysyx_24070003_OP_OR          4'b0101 // |
// `define ysyx_24070003_OP_XOR         4'b0110 // ^

// `define ysyx_24070003_OP_SLL         4'b1100 // <<
// `define ysyx_24070003_OP_SRL         4'b1101 // >>
// `define ysyx_24070003_OP_SRA         4'b1110 // >>>

// `define ysyx_24070003_OP_BLT         4'b1000 // <
// `define ysyx_24070003_OP_BGE         4'b1001 // >=
// `define ysyx_24070003_OP_BNE         4'b1010 // !=
// `define ysyx_24070003_OP_BEQ         4'b1011 // ==

// `define ysyx_24070003_BEQ_FUNCT3         3'b000
// `define ysyx_24070003_BNE_FUNCT3         3'b001
// `define ysyx_24070003_BLT_FUNCT3         3'b100
// `define ysyx_24070003_BGE_FUNCT3         3'b101
// `define ysyx_24070003_BLTU_FUNCT3        3'b110
// `define ysyx_24070003_BGEU_FUNCT3        3'b111

// `define ysyx_24070003_ADDI_FUNCT3         3'b000
// `define ysyx_24070003_SLLI_FUNCT3         3'b001
// `define ysyx_24070003_SLTI_FUNCT3         3'b010
// `define ysyx_24070003_SLTIU_FUNCT3        3'b011
// `define ysyx_24070003_XORI_FUNCT3         3'b100
// `define ysyx_24070003_SRLI_SRAI_FUNCT3    3'b101
// `define ysyx_24070003_ORI_FUNCT3          3'b110
// `define ysyx_24070003_ANDI_FUNCT3         3'b111

// `define ysyx_24070003_SUB_ADD_MUL_FUNCT3         3'b000
// `define ysyx_24070003_SLL_MULH_FUNCT3            3'b001
// `define ysyx_24070003_SLT_FUNCT3                 3'b010
// `define ysyx_24070003_SLTU_MULHU_FUNCT3          3'b011
// `define ysyx_24070003_XOR_DIV_FUNCT3             3'b100
// `define ysyx_24070003_SRL_SRA_DIVU_FUNCT3        3'b101
// `define ysyx_24070003_OR_REM_FUNCT3              3'b110
// `define ysyx_24070003_AND_REMU_FUNCT3            3'b111
//     always @(*) begin
//       case(alu_op)
//         2'b00:  aluOp = `ysyx_24070003_OP_ADD;       //load/store    
//         2'b10:  begin //R
//           case(funct3)                   
//             `ysyx_24070003_SUB_ADD_MUL_FUNCT3: begin
//                   if(funct7[5]) //sub
//                     aluOp = `ysyx_24070003_OP_SUB;
//                   else //add
//                     aluOp = `ysyx_24070003_OP_ADD;
//               end
//             `ysyx_24070003_SLL_MULH_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_SLL;
//               end
//             `ysyx_24070003_SLT_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_BLT;
//               end
//             `ysyx_24070003_SLTU_MULHU_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_BLT;
//               end
//             `ysyx_24070003_XOR_DIV_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_XOR;
//               end
//             `ysyx_24070003_SRL_SRA_DIVU_FUNCT3: begin
//                   if(funct7[5]) //sra
//                     aluOp = `ysyx_24070003_OP_SRA;
//                   else //srl
//                     aluOp = `ysyx_24070003_OP_SRL;
//               end
//             `ysyx_24070003_OR_REM_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_OR;
//               end
//             `ysyx_24070003_AND_REMU_FUNCT3: begin
//                   aluOp = `ysyx_24070003_OP_AND;
//               end
//             default : aluOp = `ysyx_24070003_OP_ADD;
//         endcase
//         end
//         2'b01:  begin //B
//           case(funct3)                   
//             `ysyx_24070003_BEQ_FUNCT3:  aluOp = `ysyx_24070003_OP_BEQ;
//             `ysyx_24070003_BNE_FUNCT3:  aluOp = `ysyx_24070003_OP_BNE;
//             `ysyx_24070003_BLT_FUNCT3:  aluOp = `ysyx_24070003_OP_BLT;
//             `ysyx_24070003_BGE_FUNCT3:  aluOp = `ysyx_24070003_OP_BGE;
//             `ysyx_24070003_BLTU_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
//             `ysyx_24070003_BGEU_FUNCT3: aluOp = `ysyx_24070003_OP_BGE;
//             default:      aluOp = `ysyx_24070003_OP_ADD;
//           endcase
//           end
//         2'b11:  begin //I
//         case(funct3)                   
//             `ysyx_24070003_ADDI_FUNCT3: aluOp = `ysyx_24070003_OP_ADD;
//             `ysyx_24070003_SLLI_FUNCT3: aluOp = `ysyx_24070003_OP_SLL;
//             `ysyx_24070003_SLTI_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
//             `ysyx_24070003_SLTIU_FUNCT3: aluOp = `ysyx_24070003_OP_BLT;
//             `ysyx_24070003_XORI_FUNCT3: aluOp = `ysyx_24070003_OP_XOR;
//             `ysyx_24070003_SRLI_SRAI_FUNCT3: begin if(funct7[5]) aluOp = `ysyx_24070003_OP_SRA;else aluOp = `ysyx_24070003_OP_SRL; end
//             `ysyx_24070003_ORI_FUNCT3: aluOp = `ysyx_24070003_OP_OR;
//             `ysyx_24070003_ANDI_FUNCT3: aluOp = `ysyx_24070003_OP_AND;
//             default: aluOp = funct7[4:1];
//         endcase
//         end
//         default: aluOp = `ysyx_24070003_OP_ADD;
//       endcase
//     end
//     /*
//     always @(*) begin
//     $display("Value of signal alu_op is %02b", alu_op);
//     $display("Value of signal funct3 is %03b", funct3);
//     $display("Value of signal funct7 is %07b", funct7);
//     $display("Value of signal aluOp is %07b", aluOp);
//     end
//     */
// endmodule
