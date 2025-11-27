`include "../HDR/ysyx_25040111_inc.vh"

`define SYS_EBREAK 12'h001
`define SYS_ECALL  12'h000
`define SYS_MRET   12'h302
// mcause process
module ysyx_25040111_system(
    input       [31:7]          inst,
    output      [4:0]           rs1,
    output      [4:0]           rd,
    output reg  [11:0]          csrw,
    output reg  [11:0]          csrr,
    output      [31:0]          imm,
    output reg  [`OPT_HIGH:0]   opt,
    output reg  [3:0]           err_type,
    output reg                  err
);
    wire [2:0] fun3;
    wire fix;
    reg [`OPT_HIGH:0] opt_t;

    assign fun3 = inst[14:12];
    assign rd = inst[11:7];
    assign fix = ~(|fun3);
    assign rs1 = fix ?  5'd10 : inst[19:15];
    assign imm = 32'b0;

    always @(*) begin
        csrw = inst[31:20];
        csrr = inst[31:20];
        err_type = 4'b0;
        err      = 0;

        case ({inst[31:20], fix})
            {`SYS_EBREAK, 1'b1}: begin
                csrw = 12'b0;
                csrr = 12'b0;
            end
            {`SYS_ECALL,  1'b1}: begin
                err_type = 4'd11;
                err      = 1;
            end
            {`SYS_MRET,   1'b1}: begin
                csrw = 12'b0;
                csrr = `MEPC;
            end
            default: begin
            end
        endcase

        case (inst[31:20])
            `SYS_EBREAK: opt_t = `EBREAK_INST;
            `SYS_ECALL:  opt_t = `OPT_LEN'h8000;
            `SYS_MRET:   opt_t = `OPTG(`EMPTY, `EMP, `EMPTY, `EMP, `XFS, `XXN);
            default:     opt_t = `OPT_LEN'b0;
        endcase

        case (fun3)
            3'b000:  opt = opt_t;
            3'b001:  opt = `OPTG(`WFX, `RF_IM, `ADD,   `SNPC, `WFX, `XXN);
            3'b010:  opt = `OPTG(`WFX, `RF_RS, `AND,   `SNPC, `WFX, `EXN);
            default: opt = `OPT_LEN'b0;
        endcase
    end

endmodule
