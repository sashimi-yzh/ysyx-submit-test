`include "MACRO.v"

module ALU(
        input signed [31:0] A, //srcR1 or PC
        input signed [31:0] B, //srcR2 or imm
        input [3:0] Opcode,
        output reg [31:0] Result
    );

    wire [31:0] add_res;
    wire [31:0] sub_res;
    wire [31:0] and_res;
    wire [31:0] or_res;
    wire [31:0] xor_res;
    wire [31:0] lt_res;
    wire [31:0] ge_res;
    wire [31:0] ltu_res;
    wire [31:0] geu_res;
    wire [31:0] eq_res;
    wire [31:0] ne_res;
    wire [31:0] sll_res;
    wire [31:0] srl_res;
    wire [31:0] sra_res;

    assign add_res = A + B;
    assign sub_res = A - B;
    assign and_res = A & B;
    assign or_res = A | B;
    assign xor_res = A ^ B;
    assign lt_res = (A < B) ? 32'h0000_0001 : 32'h0000_0000;
    assign ge_res = (A >= B) ? 32'h0000_0001 : 32'h0000_0000;
    assign eq_res = (A == B) ? 32'h0000_0001 : 32'h0000_0000;
    assign ne_res = (A != B) ? 32'h0000_0001 : 32'h0000_0000;
    assign sll_res = A << B[4:0];
    assign srl_res = A >> B[4:0];
    assign sra_res = A >>> B[4:0];
    assign ltu_res = ($unsigned(A) < $unsigned(B)) ? 32'h0000_0001 : 32'h0000_0000;
    assign geu_res = ($unsigned(A) >= $unsigned(B)) ? 32'h0000_0001 : 32'h0000_0000;

    always @(*) begin
        case (Opcode)
            `ALU_OP_ADD:
                Result = add_res;
            `ALU_OP_SUB:
                Result = sub_res;
            `ALU_OP_AND:
                Result = and_res;
            `ALU_OP_OR:
                Result = or_res;
            `ALU_OP_XOR:
                Result = xor_res;
            `ALU_OP_LT:
                Result = lt_res;
            `ALU_OP_LTU:
                Result = ltu_res;
            `ALU_OP_GE:
                Result = ge_res;
            `ALU_OP_GEU:
                Result = geu_res;
            `ALU_OP_EQ:
                Result = eq_res;
            `ALU_OP_SLL:
                Result = sll_res;
            `ALU_OP_SRL:
                Result = srl_res;
            `ALU_OP_SRA:
                Result = sra_res;
            `ALU_OP_NE:
                Result = ne_res;
            default:
                Result = 32'h0000_0000;
        endcase
    end
endmodule
