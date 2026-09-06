module ysyx_24100007_memreadlen(
  input  [31:0] data,       // 从内存中读取的完整32位数据
  input  [ 2:0] memmask,    // 内存掩码，用于确定读取的长度（byte, halfword, word）
  input         memsextsig, // 符号扩展信号，1表示有符号扩展，0表示无符号扩展
  input         read_full_word,
  input  [ 1:0] addr_offset,// 地址的最低两位，用于确定偏移量
  output [31:0] read        // 读取并扩展后的数据
);

  // Memory-like devices return an aligned word. MMIO devices return the
  // requested narrow value in the low bits.
  wire [31:0] shifted_data = read_full_word
                           ? data >> {addr_offset, 3'b000}
                           : data;
  wire [ 7:0] byte_data = shifted_data[7:0];
  wire [15:0] halfword_data = shifted_data[15:0];

  wire [31:0] byte_read = memsextsig
                        ? {{24{byte_data[7]}}, byte_data}
                        : {{24{1'b0}}, byte_data};
  wire [31:0] halfword_read = memsextsig
                            ? {{16{halfword_data[15]}}, halfword_data}
                            : {{16{1'b0}}, halfword_data};

  assign read = (memmask == 3'b001) ? byte_read :
                (memmask == 3'b010) ? halfword_read :
                shifted_data;
endmodule
