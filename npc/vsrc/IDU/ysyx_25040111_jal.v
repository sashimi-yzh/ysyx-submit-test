`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_jal(
    input [31:7] inst,
    output [31:0] imm,
    output [`OPT_HIGH:0] opt,
    output [4:0] rd
);

    wire [20:0] imm_m;
    
    assign imm_m[20]   = inst[31];
    assign imm_m[10:1] = inst[30:21];
    assign imm_m[11]   = inst[20];
    assign imm_m[19:12]= inst[19:12];
    assign imm_m[0] = 1'b0;
    
    assign rd  = inst[11:7];

    assign imm = {{11{imm_m[20]}}, imm_m};
    assign opt = `OPTG(`WXX, `PC_IM, `ADD, `INPC, `RDPC, `EMPTY);

endmodule
