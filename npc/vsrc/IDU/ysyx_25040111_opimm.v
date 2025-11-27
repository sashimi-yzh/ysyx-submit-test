`include "../HDR/ysyx_25040111_inc.vh"

module ysyx_25040111_opimm (
    input [31:7] inst,
    output [4:0] rs1,
    output [4:0] rd,
    output reg [31:0] imm,
    output reg [`OPT_HIGH:0] opt
);

    wire [11:0] imm_m;
    wire [2:0] fun3;

    assign {imm_m, rs1, fun3, rd} = inst[31:7];

    always @(*) begin
        imm = {{20{imm_m[11]}}, imm_m};

        case (fun3)
            3'b000: opt = `OPTG(`WFX, `RF_IM, `ADD, `SNPC, `EMPTY, `EMPTY);     // addi
            3'b011: opt = `OPTG(`WFX, `RF_IM, `COMPARE, `SNPC, `EMPTY, `EXX);   // sltiu
            3'b010: opt = `OPTG(`WFX, `RF_IM, `COMPARE, `SNPC, `EMPTY, `ESX);   // slti
            3'b111: opt = `OPTG(`WFX, `RF_IM, `AND, `SNPC, `EMPTY, `EMPTY);     // andi
            3'b100: opt = `OPTG(`WFX, `RF_IM, `XOR, `SNPC, `EMPTY, `EMPTY);     // xori
            3'b110: opt = `OPTG(`WFX, `RF_IM, `AND, `SNPC, `EMPTY, `EXX);       // ori
            3'b001: begin
                opt = `OPTG(`WFX, `RF_IM, `LSHIFT, `SNPC, `EMPTY, `EMPTY);      // slli
                imm = {27'b0, imm_m[4:0]};
            end
            3'b101: begin
                opt = `OPTG(`WFX, `RF_IM, `RSHIFT, `SNPC, `EMPTY, {1'b0, inst[30], 1'b0}); // srai srli
                imm = {27'b0, imm_m[4:0]};
            end
        endcase
    end

endmodule
