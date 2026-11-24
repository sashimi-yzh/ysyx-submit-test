`include "opcode_defines.v"

module adder (
  input  wire [31:0] a,     // operator 1
  input  wire [31:0] b,     // operator 2
  input  wire        cin,
  output wire [31:0] sum,   // result
  output wire        carry  // carry out
);
    assign {carry, sum} = {1'b0, a} + {1'b0, b} + {32'b0, cin};
endmodule

module shifter (
    input [3:0] shift_type,
    input wire [31:0] shift_input,
    input wire [31:0] shift_count,
    output wire [31:0] shift_output
);
    wire sign_bit              = shift_input[31];
    wire [31:0] sign_extension = {32{sign_bit}};
    wire [31:0] right_shift    = shift_input >> (shift_count[4:0]);
    wire [31:0] sign_padded    = (sign_extension & (~(32'hffffffff >> shift_count))) | right_shift;

    assign shift_output = (shift_type == `FUNC_SH_L) ? (shift_input << (shift_count[4:0])) :
                         (shift_type == `FUNC_SH_AR ? sign_padded : right_shift);
endmodule

module logicer(
    input [3:0] logic_type,
    input [31:0] a,
    input [31:0] b,
    output reg [31:0] logic_out
);

always @(*) begin
    logic_out = 32'b0; // Default output
    if (logic_type == `FUNC_AND) begin // AND
        logic_out = a & b;
    end else if (logic_type == `FUNC_OR) begin // OR
        logic_out = a | b;
    end else if (logic_type == `FUNC_XOR) begin // XOR
        logic_out = a ^ b;
    end else if (logic_type == `FUNC_NOR) begin // NOR
        logic_out = ~(a | b);
    end
end
endmodule

// module comparator (
//     input  [3:0] cmp_type,      // compare type
//     input wire [31:0] a,        // op1
//     input wire [31:0] b,        // op2
//     output reg [31:0] cmp_out   // result of comparison
// );
//     // use extra bit [32] for overflow handling
//     // this will happen when rs1 is 0x0, and rs2 is 0x80000000
//     // in this case, the cmp_out will overflow to 0x80000000, which is negative
//     reg signed [32:0] diff;
//     reg cmp_imter;

//     always @(*) begin
//         diff = $signed(a) - $signed(b);
//         case (cmp_type)
//             `FUNC_EQ: cmp_imter = (diff == 0);      // BEQ: rs1 == rs2
//             `FUNC_NEQ: cmp_imter = (diff != 0);      // BNE: rs1 != rs2
//             `FUNC_LESS_SIGN: cmp_imter = (diff < 0);       // BLT: rs1 < rs2 (signed)
//             `FUNC_LESS: cmp_imter = (a < b);      // BLTU: rs1 < rs2 (unsigned)
//             `FUNC_BGE_SIGN: cmp_imter = (diff >= 0);       // BGE: rs1 >= rs2 (signed)
//             `FUNC_BGE: cmp_imter = (a >= b);      // BGEU: rs1 >= rs2 (unsigned)
//             default: cmp_imter = 1'b0;            // Default case
//         endcase
//         cmp_out = {31'b0, cmp_imter}; // Set the output to 32 bits
//     end
// endmodule

module comparator (
  input       [ 3:0] cmp_type,  // compare type
  input  wire [31:0] a,         // op A
  input  wire [31:0] b,         // op B
  output reg  [31:0] cmp_out    // Comparison result (1 for True, 0 for False)
);

  // 1. Subtraction control logic: A - B = A + ~B + 1
  wire [31:0] b_operand = ~b;  // Bitwise inversion of B
  wire        cin_signal = 1'b1;  // Set carry-in to 1 to complete 2's complement

  wire [31:0] sub_sum;
  wire        sub_carry;

  // Instantiate the adder with carry-in to perform subtraction
  adder sub_adder (
  .a    (a),
  .b    (b_operand),
  .cin  (cin_signal),
  .sum  (sub_sum),
  .carry(sub_carry)
  );

  // 2. Extract status flags

  // Zero Flag: High if the subtraction result is exactly zero
  wire zero = (sub_sum == 32'b0);

  // Unsigned Less Than Flag:
  // For A + ~B + 1, if A < B, no carry-out is generated (i.e., sub_carry == 0)
  wire unsigned_lt = ~sub_carry;

  // Signed Less Than Flag:
  // Requires overflow correction.
  // Overflow occurs when operands A and B have different signs,
  // and the result sign differs from operand A's sign.
  wire sign_a = a[31];
  wire sign_b = b[31];
  wire sign_res = sub_sum[31];
  wire overflow = (sign_a ^ sign_b) & (sign_res ^ sign_a);

  // Signed Less Than: Negative result without overflow, or positive result with overflow

  wire signed_lt = sign_res ^ overflow;

  // 3. Select output based on comparison type

  always @(*) begin
    case (cmp_type)
      `FUNC_EQ:        cmp_out = {31'b0, zero};  // A == B
      `FUNC_NEQ:       cmp_out = {31'b0, ~zero};  // A != B
      `FUNC_LESS:      cmp_out = {31'b0, unsigned_lt};  // A < B  (unsigned)
      `FUNC_BGE:       cmp_out = {31'b0, ~unsigned_lt};  // A >= B (unsigned)
      `FUNC_LESS_SIGN: cmp_out = {31'b0, signed_lt};  // A < B  (signed)
      `FUNC_BGE_SIGN:  cmp_out = {31'b0, ~signed_lt};  // A >= B (signed)
      default:         cmp_out = 32'b0;
    endcase
  end
endmodule

module ysyx_24110012_alu(
    input  [3:0] alu_type,
    input  [31:0] alu_p1,
    input  [31:0] alu_p2,
    output reg [31:0] alu_out
);

wire [31:0] add_out;
reg [31:0] logic_out;
reg shift_signed;
reg [31:0] shift_out;
wire [31:0] cmp_out;
wire add_carry;

adder my_adder (
    .a(alu_p1),
    .b(alu_p2),
    .cin(1'b0),
    .sum(add_out),
    .carry(add_carry)
);

comparator u_comparator (
    .cmp_type(alu_type),
    .a(alu_p1),
    .b(alu_p2),
    .cmp_out(cmp_out)
);

logicer u_logicer (
    .logic_type(alu_type),
    .a(alu_p1),
    .b(alu_p2),
    .logic_out(logic_out)
);

shifter u_shifter(
    .shift_type(alu_type),
    .shift_input(alu_p1),
    .shift_count(alu_p2),
    .shift_output(shift_out)
);

always @(*) begin
    case (alu_type)
    `FUNC_ADD:
        alu_out = add_out;
    `FUNC_SUB:
        alu_out = add_out;
    `FUNC_AND,
    `FUNC_OR,
    `FUNC_XOR,
    `FUNC_NOR:
        alu_out = logic_out;
    `FUNC_EQ,
    `FUNC_NEQ,
    `FUNC_LESS,
    `FUNC_LESS_SIGN,
    `FUNC_BGE,
    `FUNC_BGE_SIGN:
        alu_out = cmp_out;
    `FUNC_SH_L,
    `FUNC_SH_R,
    `FUNC_SH_AR:
        alu_out = shift_out;
    default: alu_out = 32'b0;
    endcase
end
endmodule
