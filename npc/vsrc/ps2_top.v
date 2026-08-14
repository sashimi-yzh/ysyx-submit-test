module ps2_top (
  input clk, rstn,
  input ps2_clk, ps2_data,

  output [6:0] seg0,
  output [6:0] seg1,
  output [6:0] seg2,
  output [6:0] seg3,
  output [6:0] seg4,
  output [6:0] seg5,

  output overflow, // 连接到 led 灯，检测溢出状态
  output ready,
  output reg [1:0] state // 连接到 led 灯
);

reg [7:0] total_count = 0;
wire [7:0] scan_data;
wire [7:0] ascii_data;

wire [6:0] seg0_dis;
wire [6:0] seg1_dis;
wire [6:0] seg2_dis;
wire [6:0] seg3_dis;

assign seg0 = (state == 2'b11) ? seg0_dis : 7'h7f;
assign seg1 = (state == 2'b11) ? seg1_dis : 7'h7f;
assign seg2 = (state == 2'b11) ? seg2_dis : 7'h7f;
assign seg3 = (state == 2'b11) ? seg3_dis : 7'h7f;

reg [7:0] scan_data_buf = 0;
wire nextdata_n;

code2ascii code2ascii0(scan_data_buf, ascii_data);

x7seg x7seg0(ascii_data[3:0], seg0_dis);
x7seg x7seg1(ascii_data[7:4], seg1_dis);
x7seg x7seg2(scan_data_buf[3:0], seg2_dis);
x7seg x7seg3(scan_data_buf[7:4], seg3_dis);
x7seg x7seg4(total_count[3:0], seg4);
x7seg x7seg5(total_count[7:4], seg5);

ps2_keyboard ps2_keyboard0(
  clk,rstn,ps2_clk,ps2_data,scan_data,ready,nextdata_n,overflow
);

// 缓存 data 数据
always @(posedge clk) begin
  if(ready) begin
    scan_data_buf <= scan_data;
  end
end

assign nextdata_n = ~ready;

// fsm
// 状态1 - 按下: 编码为2'b11
// 状态2 - 松开: 编码为2'b00
// 状态3 - 断码1：编码为2'b10

always @(posedge clk) begin
  if(~rstn) state <= 2'b00; // 初始状态为松开
  else begin
    case(state)
      2'b00: state <= (ready == 1'b1) ? 2'b11 : 2'b00;
      2'b11: state <= ((ready == 1'b1) && (scan_data == 8'hF0)) ? 2'b10 : 2'b11;
      2'b10: state <= (ready == 1'b1) ? 2'b00 : 2'b10;
      default: state <= 2'b00;
    endcase
  end
end

always @(posedge clk) begin
  if(state == 2'b10 && (ready == 1'b1)) total_count <= total_count + 1;
end

endmodule

module code2ascii (
  input [7:0] code,
  output reg [7:0] ascii
);
  always @(*) begin
    case(code)
      // 字母键 (小写)
      8'h1c : ascii = 8'h61; // a
      8'h32 : ascii = 8'h62; // b
      8'h21 : ascii = 8'h63; // c
      8'h23 : ascii = 8'h64; // d
      8'h24 : ascii = 8'h65; // e
      8'h2b : ascii = 8'h66; // f
      8'h34 : ascii = 8'h67; // g
      8'h33 : ascii = 8'h68; // h
      8'h43 : ascii = 8'h69; // i
      8'h3b : ascii = 8'h6a; // j
      8'h42 : ascii = 8'h6b; // k
      8'h4b : ascii = 8'h6c; // l
      8'h3a : ascii = 8'h6d; // m
      8'h31 : ascii = 8'h6e; // n
      8'h44 : ascii = 8'h6f; // o
      8'h4d : ascii = 8'h70; // p
      8'h15 : ascii = 8'h71; // q
      8'h2d : ascii = 8'h72; // r
      8'h1b : ascii = 8'h73; // s
      8'h2c : ascii = 8'h74; // t
      8'h3c : ascii = 8'h75; // u
      8'h2a : ascii = 8'h76; // v
      8'h1d : ascii = 8'h77; // w
      8'h22 : ascii = 8'h78; // x
      8'h35 : ascii = 8'h79; // y
      8'h1a : ascii = 8'h7a; // z
      
      // 数字键 (主键盘区)
      8'h45 : ascii = 8'h30; // 0
      8'h16 : ascii = 8'h31; // 1
      8'h1e : ascii = 8'h32; // 2
      8'h26 : ascii = 8'h33; // 3
      8'h25 : ascii = 8'h34; // 4
      8'h2e : ascii = 8'h35; // 5
      8'h36 : ascii = 8'h36; // 6
      8'h3d : ascii = 8'h37; // 7
      8'h3e : ascii = 8'h38; // 8
      8'h46 : ascii = 8'h39; // 9
      
      // 默认值：无效字符
      default: ascii = 8'hff;
    endcase
  end
endmodule

module ps2_keyboard(clk,clrn,ps2_clk,ps2_data,data,
                    ready,nextdata_n,overflow);
    input clk,clrn,ps2_clk,ps2_data;
    input nextdata_n;
    output [7:0] data;
    output reg ready;
    output reg overflow;     // fifo overflow
    // internal signal, for test
    reg [9:0] buffer;        // ps2_data bits
    reg [7:0] fifo[7:0];     // data fifo
    reg [2:0] w_ptr,r_ptr;   // fifo write and read pointers
    reg [3:0] count;  // count ps2_data bits
    // detect falling edge of ps2_clk
    reg [2:0] ps2_clk_sync;

    always @(posedge clk) begin
        ps2_clk_sync <=  {ps2_clk_sync[1:0],ps2_clk};
    end

    wire sampling = ps2_clk_sync[2] & ~ps2_clk_sync[1];

    always @(posedge clk) begin
        if (clrn == 0) begin // reset
            count <= 0; w_ptr <= 0; r_ptr <= 0; overflow <= 0; ready<= 0;
        end
        else begin
            if ( ready ) begin // read to output next data
                if(nextdata_n == 1'b0) //read next data
                begin
                    r_ptr <= r_ptr + 3'b1;
                    if(w_ptr==(r_ptr+1'b1)) //empty
                        ready <= 1'b0;
                end
            end
            if (sampling) begin
              if (count == 4'd10) begin
                if ((buffer[0] == 0) &&  // start bit
                    (ps2_data)       &&  // stop bit
                    (^buffer[9:1])) begin      // odd  parity
                    fifo[w_ptr] <= buffer[8:1];  // kbd scan code
                    w_ptr <= w_ptr+3'b1;
                    ready <= 1'b1;
                    overflow <= overflow | (r_ptr == (w_ptr + 3'b1));
                end
                count <= 0;     // for next
              end else begin
                buffer[count] <= ps2_data;  // store ps2_data
                count <= count + 3'b1;
              end
            end
        end
    end
    assign data = fifo[r_ptr]; //always set output data

endmodule