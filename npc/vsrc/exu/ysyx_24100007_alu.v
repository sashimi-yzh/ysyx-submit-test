module ysyx_24100007_alu (
    input [31:0] A,
    input [31:0] B,
    input [4:0] op,
    output reg [31:0] res,
    output zero,
    output signal,
    output carry
);
  wire addsig, logsig, shfsig, sltsig;
  reg carry_tmp;

  assign addsig = !(op[3] | op[2]);
  assign logsig = (op[3] == 0) & (op[2] == 1);
  assign shfsig = (op[3] & op[2]);
  assign sltsig = (op[3] == 1) & (op[2] == 0);

  wire type_I = op[4];
  // logic part
  reg [31:0] logres;
  always @(*) begin
    case (op[1:0])
      2'b00: logres = (type_I) ? A & $signed(B) : A & B;
      2'b01: logres = A | B;
      2'b10: logres = A ^ B;
      2'b11: logres = ~(A | B);
    endcase
  end

  // add part
  reg [31:0] addres;
  always @(*) begin
    case (op[0] ^ op[1])
      1'b1: {carry_tmp, addres} = {1'b0, A} + {1'b0, B};
      1'b0: {carry_tmp, addres} = {1'b0, A} + {1'b0, (~B)} + 1;
    endcase
    // $display("%x + %x = %x", A, B, addres);
  end

  // shift part
  reg [31:0] shfres;
  always @(*) begin
    case (op[1:0])
      2'b00:   shfres = (type_I) ? A << B[4:0] : A << B[4:0];
      2'b01:   shfres = (type_I) ? A >> B[4:0] : A >> B[4:0];
      2'b10:   shfres = (type_I) ? ($signed(A)) >>> B[4:0] : ($signed(A)) >>> B[4:0];
      default: shfres = 32'b0;
    endcase
  end

  // stl part
  reg [31:0] sltres;
  wire signed [31:0] A_s = A;
  wire signed [31:0] B_s = B;
  always @(*) begin
    case (op[0])
      1'b0: sltres = (A < B) ? 32'd1 : 32'b0;
      1'b1: sltres = (A_s < B_s) ? 32'd1 : 32'b0;
    endcase
  end

  assign res = addsig ? addres : logsig ? logres : shfsig ? shfres : sltsig ? sltres : 32'b0;
  assign zero = (res == 0);
  assign signal = res[31];
  assign carry = carry_tmp;

endmodule
