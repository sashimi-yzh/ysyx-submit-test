module ShiftReg (
    input [7:0] din,
    input [2:0] shamt,
    input direct,  // 0 is left, 1 is right
    input shift_type,  // 0 is arithmetic,1 is logic
    output [7:0] dout
);
  wire [7:0] tmp;

  wire [7:0] tmp1;

  wire left_bit = shift_type ? 0 : din[7];

  genvar i;
  generate
    for (i = 0; i < 8; i++) begin
      if (i == 0) begin
        MuxKey #(4, 2, 1) mux41 (
            tmp[i],
            {direct, shamt[0]},
            {2'b00, din[i], 2'b01, 1'b0, 2'b10, din[i], 2'b11, din[i+1]}
        );
      end else if (i == 7) begin
        MuxKey #(4, 2, 1) mux41 (
            tmp[i],
            {direct, shamt[0]},
            {2'b00, din[i], 2'b01, din[i-1], 2'b10, din[i], 2'b11, left_bit}
        );
      end else
        MuxKey #(4, 2, 1) mux41 (
            tmp[i],
            {direct, shamt[0]},
            {2'b00, din[i], 2'b01, din[i-1], 2'b10, din[i], 2'b11, din[i+1]}
        );
    end
  endgenerate

  generate
    for (i = 0; i < 8; i++) begin
      if (i == 0 || i == 1) begin
        MuxKey #(4, 2, 1) mux41 (
            tmp1[i],
            {direct, shamt[1]},
            {2'b00, tmp[i], 2'b01, 1'b0, 2'b10, tmp[i], 2'b11, tmp[i+2]}
        );
      end else if (i == 7 || i == 6) begin
        MuxKey #(4, 2, 1) mux41 (
            tmp1[i],
            {direct, shamt[1]},
            {2'b00, tmp[i], 2'b01, tmp[i-2], 2'b10, tmp[i], 2'b11, left_bit}
        );
      end else
        MuxKey #(4, 2, 1) mux41 (
            tmp1[i],
            {direct, shamt[1]},
            {2'b00, tmp[i], 2'b01, tmp[i-2], 2'b10, tmp[i], 2'b11, tmp[i+2]}
        );
    end
  endgenerate

  generate
    for (i = 0; i < 8; i++) begin
      if (i < 4) begin
        MuxKey #(4, 2, 1) mux41 (
            dout[i],
            {direct, shamt[2]},
            {2'b00, tmp1[i], 2'b01, 1'b0, 2'b10, tmp1[i], 2'b11, tmp1[i+4]}
        );
      end else
        MuxKey #(4, 2, 1) mux41 (
            dout[i],
            {direct, shamt[2]},
            {2'b00, tmp1[i], 2'b01, tmp1[i-4], 2'b10, tmp1[i], 2'b11, left_bit}
        );
    end
  endgenerate






endmodule
