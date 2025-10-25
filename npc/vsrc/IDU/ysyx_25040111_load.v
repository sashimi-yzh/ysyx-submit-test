`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_load (
    input [31:7] inst,
    output [4:0] rs1,
    output [4:0] rd,
    output [31:0] imm,
    output reg [`OPT_HIGH:0] opt
);

    wire [11:0] imm_m;
    wire [2:0] fun3;

    assign {imm_m, rs1, fun3, rd} = inst[31:7];
    assign imm = {{20{imm_m[11]}}, imm_m};

    always @(*) begin
        case (fun3)
            3'b010: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `MLW, `EMPTY);  // lw
            3'b100: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `MLB, `EMPTY);  // lbu
            3'b001: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `MLH, `XSX);    // lh
            3'b101: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `MLH, `EMPTY);  // lhu
            3'b000: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `MLB, `XSX);    // lb
            default: opt = `OPT_LEN'b0;
        endcase
    end

endmodule
