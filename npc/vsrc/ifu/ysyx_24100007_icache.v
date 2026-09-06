module ysyx_24100007_icache (
    input clk,
    input rst,
    input [31:0] addr,
    input w_valid,
    input [127:0] w_data,
    input set_invalid,
    output hit,
    output [31:0] data_r
);
  localparam INDEX_LEN = 0;
  localparam TAG_LEN = 32 - INDEX_LEN - 4;
  localparam OFFSET_LEN = 4;

  wire [OFFSET_LEN-1:0] offset = addr[OFFSET_LEN-1:0];
  wire [TAG_LEN-1:0] tag = addr[31:OFFSET_LEN+INDEX_LEN];

  wire line_hit;
  wire [31:0] line_data_r;
  wire line_w_valid;
  wire [127:0] line_data_w;

  assign line_w_valid = w_valid;
  assign line_data_w  = w_data;

  // Manually expanded cache lines (4 instances)
  ysyx_24100007_icahce_line #(
      .TAG_LEN(TAG_LEN),
      .OFFSET_LEN(OFFSET_LEN)
  ) u_cacheline_0 (
      .clk(clk),
      .rst(rst),
      .tag(tag),
      .offset(offset),
      .set_invalid(set_invalid),
      .w_valid(line_w_valid),
      .data_w(line_data_w),
      .hit(line_hit),
      .data_r(line_data_r)
  );

  assign hit = line_hit;
  assign data_r = line_data_r;
endmodule

module ysyx_24100007_icahce_line #(
    parameter TAG_LEN = 26,
    parameter OFFSET_LEN = 4
) (
    input clk,
    input rst,
    input [TAG_LEN-1:0] tag,
    input [OFFSET_LEN-1:0] offset,
    input set_invalid,
    input w_valid,
    input [127:0] data_w,
    output hit,
    output [31:0] data_r
);
  localparam DATABLOCK_SIZE = (2 ** OFFSET_LEN) * 8;
  localparam DATABLOCK_NUMB = DATABLOCK_SIZE / 32;

  reg [DATABLOCK_NUMB-1:0][31:0] data_block;
  reg valid_r;
  reg [TAG_LEN-1:0] tag_r;

  wire [OFFSET_LEN-3:0] word_idx = offset[OFFSET_LEN-1:2];
  assign data_r = data_block[word_idx];
  assign hit = (valid_r && (tag == tag_r));

  always @(posedge clk) begin
    if (rst) begin
      valid_r <= 1'b0;
    end else begin
      if (set_invalid) begin
        valid_r <= 1'b0;
      end else if (w_valid) begin
        valid_r <= 1'b1;
        tag_r <= tag;
        data_block <= data_w;
      end
    end
  end

endmodule
