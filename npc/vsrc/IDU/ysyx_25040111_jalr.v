`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_jalr(
    input [31:7] inst,
    output [4:0] rs1,
    output [31:0] imm,
    output [`OPT_HIGH:0] opt,
    output [4:0] rd
);

    wire [11:0] imm_m;
    wire [2:0] fun3;

    assign {imm_m, rs1, fun3, rd} = inst[31:7];
    
    assign imm = fun3 == 3'b0 ? {{20{imm_m[11]}}, imm_m} : 32'b0;
    assign opt = fun3 == 3'b0 ? `OPTG(`WFX, `PC_IM, `ADD, `INRF, `RDPC, `EMPTY) 
                                : `INVALID_INST;

endmodule
