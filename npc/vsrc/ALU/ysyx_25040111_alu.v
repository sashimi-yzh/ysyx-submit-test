`ifndef NPC_ALU
`define NPC_ALU 

module ysyx_25040111_alu (
    input  [31:0] var1,
    input  [31:0] var2,
    input  [2:0]  opt,
    input         snpc,
    input         ext,
    input         sign,
    input         negate,
    output reg [31:0] res
);

    wire [31:0] adder_b = snpc ? 32'd4 : var2;
    wire [31:0] res_add;
    wire        overflow, cout;

    ysyx_25040111_adder32 u_adder32 (
        .ina      (var1),
        .inb      (adder_b),
        .sub      (ext),
        .sout     (res_add),
        .overflow (overflow),
        .cout     (cout)
    );

    wire [31:0] res_and = var1 & var2;
    wire [31:0] res_or  = var1 | var2;
    wire [31:0] res_xor = var1 ^ var2;

    // 逻辑移位和算术移位
    wire [4:0]  shamt = var2[4:0];
    wire [31:0] res_sll = var1 << shamt;
    wire [31:0] res_srl = var1 >> shamt;
    
    // 算术右移仅在 sign=1 时生效
    wire [31:0] res_sra = $signed(var1) >>> shamt;
    wire [31:0] res_shift = sign ? res_sra : res_srl;

    wire lt = sign ? (res_add[31] ^ overflow) : (~cout);
    wire eq = (var1 == var2);

    wire [31:0] alu_pass = var1;
    wire [31:0] alu_add  = res_add;
    wire [31:0] alu_logic = ext ? res_or : res_and;
    wire [31:0] alu_xor = res_xor;
    wire [31:0] alu_sll = res_sll;
    wire [31:0] alu_srl_sra = res_shift;
    wire [31:0] alu_lt = {31'b0, lt ^ negate};
    wire [31:0] alu_eq = {31'b0, (eq ^ negate)};

    always @(*) begin
        res = (opt == 3'b000) ? alu_pass :
              (opt == 3'b001) ? alu_add :
              (opt == 3'b010) ? alu_logic :
              (opt == 3'b011) ? alu_xor :
              (opt == 3'b100) ? alu_sll :
              (opt == 3'b101) ? alu_srl_sra :
              (opt == 3'b110) ? alu_lt :
              (opt == 3'b111) ? alu_eq :
              32'b0;
    end

endmodule

`endif
