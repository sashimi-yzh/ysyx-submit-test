module ps2_keyboard (
    clk,
    clrn,
    ps2_clk,
    ps2_data,
    data,
    ascii,
    input_count,
    ready,
    overflow,
    off
);
  input clk, clrn, ps2_clk, ps2_data;
  output reg [7:0] data, ascii, input_count;
  output reg ready;
  output reg overflow;  // fifo overflow
  output reg off;  //lignt off
  // internal signal, for test
  reg [9:0] buffer;  // ps2_data bits
  reg [7:0] fifo                     [7:0];  // data fifo
  reg [2:0] w_ptr, r_ptr;  // fifo write and read pointers
  reg [3:0] count;  // count ps2_data bits
  // detect falling edge of ps2_clk
  reg [2:0] ps2_clk_sync;

  always @(posedge clk) begin
    ps2_clk_sync <= {ps2_clk_sync[1:0], ps2_clk};
  end

  wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

  always @(posedge clk) begin
    if (clrn == 0) begin  // reset
      count <= 0;
      w_ptr <= 0;
      r_ptr <= 0;
      overflow <= 0;
      ready <= 0;
    end else begin
      if (ready) begin  // read to output next data
        begin
          r_ptr <= r_ptr + 3'b1;
          if (w_ptr == (r_ptr + 1'b1))  //empty
            ready <= 1'b0;
        end

        if (fifo[r_ptr] == 8'hF0) begin
          input_count = input_count + 1;
        end

        data = fifo[r_ptr];

        if (data != 8'hF0) begin
          case (data)
            8'h1C:   ascii = 97;
            8'h32:   ascii = 98;
            8'h21:   ascii = 99;
            8'h23:   ascii = 100;
            8'h24:   ascii = 101;
            8'h2B:   ascii = 102;
            8'h34:   ascii = 103;
            8'h33:   ascii = 104;
            8'h43:   ascii = 105;
            8'h3B:   ascii = 106;
            8'h42:   ascii = 107;
            8'h4B:   ascii = 108;
            8'h3A:   ascii = 109;
            8'h31:   ascii = 110;
            8'h44:   ascii = 111;
            8'h4D:   ascii = 112;
            8'h15:   ascii = 113;
            8'h2D:   ascii = 114;
            8'h1B:   ascii = 115;
            8'h2C:   ascii = 116;
            8'h3C:   ascii = 117;
            8'h2A:   ascii = 118;
            8'h1D:   ascii = 119;
            8'h22:   ascii = 120;
            8'h35:   ascii = 121;
            8'h1A:   ascii = 122;
            default: ascii = 0;
          endcase
        end

        if (fifo[r_ptr-1] == 8'hF0) begin
          off = 1;
        end else begin
          off = 0;
        end
      end
      if (sampling) begin
        if (count == 4'd10) begin
          if ((buffer[0] == 0) &&  // start bit
              (ps2_data) &&  // stop bit
              (^buffer[9:1])) begin  // odd  parity
            fifo[w_ptr] <= buffer[8:1];  // kbd scan code
            w_ptr <= w_ptr + 3'b1;
            ready <= 1'b1;
            overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
          end
          count <= 0;  // for next
        end else begin
          buffer[count] <= ps2_data;  // store ps2_data
          count <= count + 3'b1;
        end
      end
    end
  end

endmodule

module Keyboard (
    clk,
    rst,
    hex0,
    hex1,
    hex2,
    hex3,
    hex4,
    hex5,
    ps2_clk,
    ps2_data
);
  input clk, rst, ps2_clk, ps2_data;
  output reg [7:0] hex0, hex1, hex2, hex3, hex4, hex5;

  reg [7:0] data, ascii, input_count;
  reg ready;
  reg overflow;
  reg off;
  ps2_keyboard key_board (
      clk,
      rst,
      ps2_clk,
      ps2_data,
      data,
      ascii,
      input_count,
      ready,
      overflow,
      off
  );

  bcd7seg i0 (
      data[3:0],
      off,
      hex0
  );
  bcd7seg i1 (
      data[7:4],
      off,
      hex1
  );
  bcd7seg i2 (
      ascii[3:0],
      off,
      hex2

  );
  bcd7seg i3 (
      ascii[7:4],
      off,
      hex3
  );
  bcd7seg i4 (
      input_count[3:0],
      0,
      hex4
  );
  bcd7seg i5 (
      input_count[7:4],
      0,
      hex5
  );
endmodule

