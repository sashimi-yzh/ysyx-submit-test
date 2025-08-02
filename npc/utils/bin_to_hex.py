import argparse

def bin_to_hex(input_bin_file, output_hex_file, word_size=1, little_endian=False):
    try:
        with open(input_bin_file, 'rb') as bin_file:
            with open(output_hex_file, 'w') as hex_file:
                while True:
                    word = bin_file.read(word_size)
                    if not word:
                        break
                    
                    # 处理字节序
                    if little_endian:
                        word = word[::-1]  # 小端序，反转字节顺序
                    
                    # 转换为十六进制字符串
                    hex_str = ''.join(f"{byte:02X}" for byte in word)
                    hex_file.write(hex_str + '\n')
        
        print(f"转换成功！输出文件: {output_hex_file}")
    except IOError as e:
        print(f"文件操作错误: {e}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="将二进制(.bin)文件转换为Verilog $readmemh可读取的十六进制文件(.hex)")
    parser.add_argument("input", help="输入二进制文件 (.bin)")
    parser.add_argument("output", help="输出十六进制文件 (.hex)")
    parser.add_argument("--word-size", type=int, default=1, help="每个字的字节数（默认1字节）")
    parser.add_argument("--little-endian", action="store_true", help="使用小端序（默认大端序）")
    
    args = parser.parse_args()
    
    bin_to_hex(args.input, args.output, args.word_size, args.little_endian)
