/**
 * WBU AXI 配置模块。
 * 所有 WBU 访问都是单 beat INCR 传输。Memory-like devices use an
 * aligned 32-bit read; MMIO devices keep their original address and size.
 */
module ysyx_24100007_wbucfg (
    input        mem_we,
    input [31:0] mem_addr,
    input [31:0] mem_wdata,
    input [ 2:0] mem_mask,

    output [31:0] araddr,
    output [31:0] awaddr,
    output [ 2:0] arsize,
    output [ 2:0] awsize,
    output [ 7:0] arlen,
    output [ 7:0] awlen,
    output [ 1:0] arburst,
    output [ 1:0] awburst,
    output [31:0] wdata,
    output [ 3:0] wstrb,
    output        read_full_word
);

  wire in_sram  = (mem_addr >= 32'h0f000000) && (mem_addr <= 32'h0fffffff);
  wire in_flash = (mem_addr >= 32'h30000000) && (mem_addr <= 32'h3fffffff);
  wire in_psram = (mem_addr >= 32'h80000000) && (mem_addr <= 32'h9fffffff);
  wire in_sdram = (mem_addr >= 32'ha0000000) && (mem_addr <= 32'hbfffffff);
  assign read_full_word = in_sram | in_flash | in_psram | in_sdram;

  wire [2:0] access_size = (mem_mask == 3'b001) ? 3'b000 :
                           (mem_mask == 3'b010) ? 3'b001 : 3'b010;

  assign araddr  = read_full_word ? {mem_addr[31:2], 2'b00} : mem_addr;
  assign arlen   = 8'd0;
  assign arburst = 2'b01;  // INCR
  assign arsize  = read_full_word ? 3'b010 : access_size;

  assign awaddr  = mem_addr;
  assign awlen   = 8'd0;
  assign awburst = 2'b01;  // INCR

  wire [1:0] wdata_offset;

  ysyx_24100007_memwritelen strbcontrol (
      .awaddr(mem_addr),
      .wirtelen(mem_mask),
      .wstrb(wstrb),
      .awsize(awsize),
      .wdata_offset(wdata_offset)
  );

  assign wdata = mem_wdata << {wdata_offset, 3'b000};

endmodule
