`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_miscmem(
    input  [2:0] func3,
    output [4:0] rd,
    output [`OPT_HIGH:0] opt
);

    assign rd = {2'b0, func3};

    assign opt = func3 == 3'b001 ? `OPTG(`EMPTY, `EMP, `EMPTY, `SNPC, `RDPC, `EMPTY) :
        `EBREAK_INST;

endmodule
