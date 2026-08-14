module vga_top(
  input           clk,
  input           rst,
  output          hsync,    //行同步和列同步信号
  output          vsync,
  output          valid,    //消隐信号
  output [7:0]    vga_r,    //红绿蓝颜色信号
  output [7:0]    vga_g,
  output [7:0]    vga_b
);

wire [9:0] h_addr;
wire [9:0] v_addr;
wire [23:0] vga_data;

vga_ctrl vga_ctrl0(
  clk, rst, vga_data, h_addr, v_addr, hsync, vsync, valid, vga_r, vga_g, vga_b
);

reg [23:0] pic_data [524287:0];

initial begin
  $readmemh("resource/Ace Attorney.hex", pic_data);
end

assign vga_data = pic_data[{h_addr, v_addr[8:0]}];

endmodule