module top(
  input clk,
  input rst,
  input btc,
  input [15:0] sw,
  input ps2_clk,
  input ps2_data,
  output [6:0] seg0,
  output [6:0] seg1,
  output [6:0] seg2,
  output [6:0] seg6,
  output [6:0] seg7,
  output VGA_CLK,
  output VGA_HSYNC,
  output VGA_VSYNC,
  output VGA_BLANK_N,
  output [7:0] VGA_R,
  output [7:0] VGA_G,
  output [7:0] VGA_B,
  output [15:0] led
);

  // prencoder83 u_prencoder83 (
  //   .x(sw[7:0]),
  //   .en(clk),
  //   .y(led[2:0]),
  //   .seg(seg0)
  // );

  // reg [3:0]out;

  // alu u_alu (
  //   .A(sw[7:4]),
  //   .B(sw[3:0]),
  //   .sel(sw[10:8]),
  //   .out(out),
  //   .Z(led[4]),
  //   .O(led[5]),
  //   .C(led[6])
  // );

  // hex u_hex0 (
  //   .hex(out),
  //   .seg(seg0)
  // );
  // hex u_hex1 (
  //   .hex(sw[3:0]),
  //   .seg(seg1)
  // );
  // hex u_hex2 (
  //   .hex(sw[7:4]),
  //   .seg(seg2)
  // );

  // assign led[10:8] = sw[10:8];
  // assign led[3:0] = out;

  // lfsr u_lfsr (
  //   .rst(rst),
  //   .step(btc),
  //   .hex0(seg0),
  //   .hex1(seg1)
  // );

  ps2_keyboard u_ps2_keyboard (
    .clk(clk),
    .resetn(rst),
    .ps2_clk(ps2_clk),
    .ps2_data(ps2_data),
    .key_pressed(led[0]),
    .key_valid(led[1]),
    .seg0(seg0),
    .seg1(seg1),
    .seg6(seg6),
    .seg7(seg7)
  );

  // scpu u_scpu (
  //   .clk(btc),
  //   .rst(rst),
  //   .seg0(seg0),
  //   .seg1(seg1),
  //   .led(led)
  // );

  // vmem my_vmem(
  //   .h_addr(h_addr),
  //   .v_addr(v_addr[8:0]),
  //   .vga_data(vga_data)
  // );
  
  // assign VGA_CLK = clk;

  // wire [9:0] h_addr;
  // wire [9:0] v_addr;
  // wire [23:0] vga_data;

  // vga_ctrl my_vga_ctrl(
  //     .pclk(clk),
  //     .reset(rst),
  //     .vga_data(vga_data),
  //     .h_addr(h_addr),
  //     .v_addr(v_addr),
  //     .hsync(VGA_HSYNC),
  //     .vsync(VGA_VSYNC),
  //     .valid(VGA_BLANK_N),
  //     .vga_r(VGA_R),
  //     .vga_g(VGA_G),
  //     .vga_b(VGA_B)
  // );

endmodule

// module vmem(
//     input [9:0] h_addr,
//     input [8:0] v_addr,
//     output [23:0] vga_data
// );

// reg [23:0] vga_mem [524287:0];

// initial begin
//     $readmemh("resource/picture.hex", vga_mem);
// end

// assign vga_data = vga_mem[{h_addr, v_addr}];

// endmodule