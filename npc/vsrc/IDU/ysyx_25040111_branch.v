`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_branch(
    input [31:7] inst,
    output [4:0] rs1,
    output [4:0] rs2,
    output [31:0] imm,
    output reg [`OPT_HIGH:0] opt
);

    wire [12:0] imm_m;
    wire [2:0] fun3;

    assign imm_m[12] = inst[31];
    assign imm_m[10:5] = inst[30:25];
    assign imm_m[4:1] = inst[11:8];
    assign imm_m[11] = inst[7];
    assign imm_m[0] = 1'b0;

    assign {rs2, rs1, fun3} = inst[24:12];
    assign imm = {{19{imm_m[12]}}, imm_m};

    always @(*) begin
        case (fun3)
            3'b000: opt = `OPTG(`XFS, `RF_RS, `EQUAL,   `BRANCH, `EMPTY, `EXX); // beq
            3'b001: opt = `OPTG(`XFS, `RF_RS, `EQUAL,   `BRANCH, `EMPTY, `EXN); // bne
            3'b111: opt = `OPTG(`XFS, `RF_RS, `COMPARE, `BRANCH, `EMPTY, `EXN); // bgeu
            3'b100: opt = `OPTG(`XFS, `RF_RS, `COMPARE, `BRANCH, `EMPTY, `ESX); // blt
            3'b101: opt = `OPTG(`XFS, `RF_RS, `COMPARE, `BRANCH, `EMPTY, `ESN); // bge
            3'b110: opt = `OPTG(`XFS, `RF_RS, `COMPARE, `BRANCH, `EMPTY, `EXX); // bltu
            default: opt = `OPT_LEN'b0;
        endcase
    end

endmodule
