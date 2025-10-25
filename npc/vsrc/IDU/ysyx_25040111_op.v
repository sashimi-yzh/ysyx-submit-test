`include "../HDR/ysyx_25040111_inc.vh"

`define OP_ADD  10'b0000000_000
`define OP_SUB  10'b0100000_000
`define OP_SLL  10'b0000000_001
`define OP_SLT  10'b0000000_010
`define OP_SLTU 10'b0000000_011
`define OP_XOR  10'b0000000_100
`define OP_SRL  10'b0000000_101
`define OP_SRA  10'b0100000_101
`define OP_OR   10'b0000000_110
`define OP_AND  10'b0000000_111

module ysyx_25040111_op(
    input [31:7] inst,
    output [4:0] rs1,
    output [4:0] rs2,
    output [4:0] rd,
    output reg [`OPT_HIGH:0] opt
);

    wire [6:0] fun7;
    wire [2:0] fun3;

    assign {fun7, rs2, rs1, fun3, rd} = inst;

    always @(*) begin
        case ({fun7, fun3})
            `OP_SUB:  opt = `OPTG(`WFS, `RF_RS, `ADD, `SNPC, `EMPTY, `EXX);
            `OP_ADD:  opt = `OPTG(`WFS, `RF_RS, `ADD, `SNPC, `EMPTY, `EMPTY);
            `OP_SLL:  opt = `OPTG(`WFS, `RF_RS, `LSHIFT, `SNPC, `EMPTY, `EMPTY);
            `OP_AND:  opt = `OPTG(`WFS, `RF_RS, `AND, `SNPC, `EMPTY, `EMPTY);
            `OP_SLTU: opt = `OPTG(`WFS, `RF_RS, `COMPARE, `SNPC, `EMPTY, `EXX);
            `OP_OR:   opt = `OPTG(`WFS, `RF_RS, `AND, `SNPC, `EMPTY, `EXX);
            `OP_XOR:  opt = `OPTG(`WFS, `RF_RS, `XOR, `SNPC, `EMPTY, `EMPTY);
            `OP_SLT:  opt = `OPTG(`WFS, `RF_RS, `COMPARE, `SNPC, `EMPTY, `ESX);
            `OP_SRA:  opt = `OPTG(`WFS, `RF_RS, `RSHIFT, `SNPC, `EMPTY, `XSX);
            `OP_SRL:  opt = `OPTG(`WFS, `RF_RS, `RSHIFT, `SNPC, `EMPTY, `EMPTY);
            default:  opt = `OPT_LEN'b0;
        endcase
    end

endmodule
