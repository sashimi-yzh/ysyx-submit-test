//`include "defines.v"
module alu_ctrl(
    input [2:0]  funct3,
    input [5:0]  funct7,
    input [1:0]  alu_op,
    output reg [3:0] aluOp
);
`define OP_ADD         4'b0000 // +
`define OP_SUB         4'b0001 // -
`define OP_SLL         4'b0010 // <<
`define OP_SLT         4'b0011 // <
`define OP_XOR         4'b0100 // ^
`define OP_SRL         4'b0101 // >>
`define OP_SRA         4'b0110 // >>>
`define OP_OR          4'b0111 // |
`define OP_AND         4'b1000 // &
`define OP_MU          4'b1001 // *
`define OP_DIV         4'b1010 // /
`define OP_REM         4'b1011 // %
`define OP_BGE         4'b1100 // >=
`define OP_BNE         4'b1101 // !=
`define OP_BEQ         4'b1110 // ==
`define MUL_H          4'b1111 // *

`define BEQ_FUNCT3         3'b000
`define BNE_FUNCT3         3'b001
`define BLT_FUNCT3         3'b100
`define BGE_FUNCT3         3'b101
`define BLTU_FUNCT3        3'b110
`define BGEU_FUNCT3        3'b111

`define ADDI_FUNCT3         3'b000
`define SLLI_FUNCT3         3'b001
`define SLTI_FUNCT3         3'b010
`define SLTIU_FUNCT3        3'b011
`define XORI_FUNCT3         3'b100
`define SRLI_SRAI_FUNCT3    3'b101
`define ORI_FUNCT3          3'b110
`define ANDI_FUNCT3         3'b111

`define SUB_ADD_MUL_FUNCT3         3'b000
`define SLL_MULH_FUNCT3            3'b001
`define SLT_FUNCT3                 3'b010
`define SLTU_MULHU_FUNCT3          3'b011
`define XOR_DIV_FUNCT3             3'b100
`define SRL_SRA_DIVU_FUNCT3        3'b101
`define OR_REM_FUNCT3              3'b110
`define AND_REMU_FUNCT3            3'b111
    always @(*) begin
      case(alu_op)
        2'b00:  aluOp = `OP_ADD;       //load/store    
        2'b10:  begin //R
          case(funct3)                   
            `SUB_ADD_MUL_FUNCT3: begin
                  if(funct7[5]) //sub
                    aluOp = `OP_SUB;
                  else if(funct7[0]) //mul
                    aluOp = `OP_MU;
                  else //add
                    aluOp = `OP_ADD;
              end
            `SLL_MULH_FUNCT3: begin
                  if(funct7[0]) //mulh
                    aluOp = `OP_MU;
                  else //sll
                    aluOp = `OP_SLL;
              end
            `SLT_FUNCT3: begin
                  aluOp = `OP_SLT;
              end
            `SLTU_MULHU_FUNCT3: begin
                  if(funct7[0]) //mulhu
                    aluOp = `OP_MU;
                  else //sltu
                    aluOp = `OP_SLT;
              end
            `XOR_DIV_FUNCT3: begin
                  if(funct7[0]) //div
                    aluOp = `OP_DIV;
                  else //xor
                    aluOp = `OP_XOR;
              end
            `SRL_SRA_DIVU_FUNCT3: begin
                  if(funct7[5]) //sra
                    aluOp = `OP_SRA;
                  else if(funct7[0]) //divu
                    aluOp = `OP_DIV;
                  else //srl
                    aluOp = `OP_SRL;
              end
            `OR_REM_FUNCT3: begin
                  if(funct7[0]) //rem
                    aluOp = `OP_REM;
                  else //or
                    aluOp = `OP_OR;
              end
            `AND_REMU_FUNCT3: begin
                  if(funct7[0]) //remu
                    aluOp = `OP_REM;
                  else //and
                    aluOp = `OP_AND;
              end
            default : aluOp = `OP_ADD;
        endcase
        end
        2'b01:  begin //B
          case(funct3)                   
            `BEQ_FUNCT3:  aluOp = `OP_BEQ;
            `BNE_FUNCT3:  aluOp = `OP_BNE;
            `BLT_FUNCT3:  aluOp = `OP_SLT;
            `BGE_FUNCT3:  aluOp = `OP_BGE;
            `BLTU_FUNCT3: aluOp = `OP_SLT;
            `BGEU_FUNCT3: aluOp = `OP_BGE;
            default:      aluOp = `OP_ADD;
          endcase
          end
        2'b11:  begin //I
        case(funct3)                   
            `ADDI_FUNCT3: aluOp = `OP_ADD;
            `SLLI_FUNCT3: aluOp = `OP_SLL;
            `SLTI_FUNCT3: aluOp = `OP_SLT;
            `SLTIU_FUNCT3: aluOp = `OP_SLT;
            `XORI_FUNCT3: aluOp = `OP_XOR;
            `SRLI_SRAI_FUNCT3: begin if(funct7[5]) aluOp = `OP_SRA;else aluOp = `OP_SRL; end
            `ORI_FUNCT3: aluOp = `OP_OR;
            `ANDI_FUNCT3: aluOp = `OP_AND;
            default: aluOp = funct7[4:1];
        endcase
        end
        default: aluOp = `OP_ADD;
      endcase
    end
    /*
    always @(*) begin
    $display("Value of signal alu_op is %02b", alu_op);
    $display("Value of signal funct3 is %03b", funct3);
    $display("Value of signal funct7 is %07b", funct7);
    $display("Value of signal aluOp is %07b", aluOp);
    end
    */
endmodule
