`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_auipc_lui (
    input [31:7] inst,
    input chos,
    output [4:0] rd,
    output [31:0] imm,
    output [`OPT_HIGH:0] opt
);

    wire [31:12] imm_m;

    assign {imm_m, rd} = inst[31:7];

    assign imm = {imm_m, 12'b0};
    //                                          lui
    assign opt = chos ? `OPTG(`WXX, `EMP, `EMPTY, `SNPC, `EMPTY, `EMPTY) :
                        `OPTG(`WXX, `PC_IM, `ADD, `SNPC, `EMPTY, `EMPTY);
    //                                          auipc

endmodule
