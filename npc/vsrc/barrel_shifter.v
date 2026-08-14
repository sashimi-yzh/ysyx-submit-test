module barrel_shifter (
  input [7:0] din,
  output [7:0] dout,
  input [2:0] shamt,
  input AL,
  input LR
);
  wire arith_MSB = AL & din[7];

  // 第一层
  wire res10;
  MUX41 mux10(din[0], din[1], din[0], 1'b0, {LR, shamt[0]}, res10);
  wire res11;
  MUX41 mux11(din[1], din[2], din[1], din[0], {LR, shamt[0]}, res11);
  wire res12;
  MUX41 mux12(din[2], din[3], din[2], din[1], {LR, shamt[0]}, res12);
  wire res13;
  MUX41 mux13(din[3], din[4], din[3], din[2], {LR, shamt[0]}, res13);
  wire res14;
  MUX41 mux14(din[4], din[5], din[4], din[3], {LR, shamt[0]}, res14);
  wire res15; 
  MUX41 mux15(din[5], din[6], din[5], din[4], {LR, shamt[0]}, res15);
  wire res16;
  MUX41 mux16(din[6], din[7], din[6], din[5], {LR, shamt[0]}, res16);
  wire res17;
  MUX41 mux17(din[7], arith_MSB, din[7], din[6], {LR, shamt[0]}, res17);

  // 第二层
  wire res20;
  MUX41 mux20(res10, res12, res10, 1'b0, {LR, shamt[1]}, res20);
  wire res21;
  MUX41 mux21(res11, res13, res11, 1'b0, {LR, shamt[1]}, res21);
  wire res22;
  MUX41 mux22(res12, res14, res12, res10, {LR, shamt[1]}, res22);
  wire res23;
  MUX41 mux23(res13, res15, res13, res11, {LR, shamt[1]}, res23);
  wire res24;
  MUX41 mux24(res14, res16, res14, res12, {LR, shamt[1]}, res24);
  wire res25;
  MUX41 mux25(res15, res17, res15, res13, {LR, shamt[1]}, res25);
  wire res26;
  MUX41 mux26(res16, arith_MSB, res16, res14, {LR, shamt[1]}, res26);
  wire res27;
  MUX41 mux27(res17, arith_MSB, res17, res15, {LR, shamt[1]}, res27);

  // 第三层
  MUX41 mux30(res20, res24, res20, 1'b0, {LR, shamt[2]}, dout[0]);
  MUX41 mux31(res21, res25, res21, 1'b0, {LR, shamt[2]}, dout[1]);
  MUX41 mux32(res22, res26, res22, 1'b0, {LR, shamt[2]}, dout[2]);
  MUX41 mux33(res23, res27, res23, 1'b0, {LR, shamt[2]}, dout[3]);
  MUX41 mux34(res24, arith_MSB, res24, res20, {LR, shamt[2]}, dout[4]);
  MUX41 mux35(res25, arith_MSB, res25, res21, {LR, shamt[2]}, dout[5]);
  MUX41 mux36(res26, arith_MSB, res26, res22, {LR, shamt[2]}, dout[6]);
  MUX41 mux37(res27, arith_MSB, res27, res23, {LR, shamt[2]}, dout[7]);
endmodule

module MUX21(
  input X0,X1,s,
  output y 
);
  MuxKey #(2, 1, 1) i0 (y, s, {
    1'b0, X0,
    1'b1, X1
  });
endmodule

module MUX41(
  input X0,X1,X2,X3,
  input [1:0] s,
  output y
);
  MuxKey #(4, 2, 1) i0 (y, s, {
    2'b00, X0,
    2'b01, X1,
    2'b10, X2,
    2'b11, X3
  });
endmodule