module ALU (
    input      [2:0] OP,
    input      [3:0] A,
    input      [3:0] B,
    output reg [3:0] result,
    output reg       carry,
    output reg       zero,
    output reg       overflow,
    output reg [7:0] seg0,
    output reg [7:0] seg1
);

  reg [3:0] num;

  reg [3:0] tmpResult;

  always @(OP or A or B) begin
    overflow = 0;
    carry = 0;
    tmpResult = 0;
    case (OP)
      3'b000: begin
        {carry, result} = A + B;
        overflow = (result[3] & ~A[3] & ~B[3]) | (~result[3] & A[3] & B[3]);
      end
      3'b001: begin
        {carry, result} = A - B;
        overflow = (result[3] & ~A[3] & B[3]) | (~result[3] & A[3] & ~B[3]);
      end
      3'b010:  result = ~A;
      3'b011:  result = A & B;
      3'b100:  result = A | B;
      3'b101:  result = A ^ B;
      3'b110: begin
        tmpResult = A - B;
        result = {
          3'b000,
          ((tmpResult[3] & ~A[3] & B[3]) | (~tmpResult[3] & A[3] & ~B[3])) ? A[3] : tmpResult[3]
        };
      end
      default: result = {3'b000, A == B};
    endcase
    zero = result == 0;
  end


  always @(result) begin
    if (result[3] == 0) begin
      seg1 = 8'b1111_1111;  // 正数符号为空 
      num  = result;
    end else begin
      seg1 = 8'b1111_1101;  // 负号
      num  = ~result + 1;
    end
  end

  bcd7seg b1 (
      num,
      seg0
  );

endmodule
