module ysyx_24100007_MuxKey #(NR_KEY = 2, KEY_LEN = 1, DATA_LEN = 1) (
  output [DATA_LEN-1:0] out,
  input [KEY_LEN-1:0] key,
  input[NR_KEY*(KEY_LEN + DATA_LEN)-1:0] lut
);
  ysyx_24100007_MuxKeyInternal #(NR_KEY, KEY_LEN, DATA_LEN, 0)
    i0 (out, key, {DATA_LEN{1'b0}}, lut);
endmodule
