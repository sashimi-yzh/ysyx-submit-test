import argparse
import binascii
import os
import sys

def bin_to_hex(input_bin, output_hex, vma_start, bytes_per_line=16):
    """
    转换 .bin 文件为 .hex 文件
    :param input_bin: 输入 .bin 文件路径
    :param output_hex: 输出 .hex 文件路径
    :param vma_start: VMA 起始地址 (整数)
    :param bytes_per_line: 每行字节数 (默认 16)
    """
    # 读取二进制文件
    with open(input_bin, 'rb') as f:
        bin_data = f.read()
    
    # 计算需要填充的字节数 (使总字节数为 bytes_per_line 的倍数)
    padding = bytes_per_line - (len(bin_data) % bytes_per_line)
    if padding != bytes_per_line:
        bin_data += b'\x00' * padding
    
    # 写入 HEX 文件
    with open(output_hex, 'w') as f:
        # 写入 VMA 起始地址
        f.write(f"@%x\n" % vma_start)
        
        # 写入数据
        for i in range(0, len(bin_data), bytes_per_line):
            # 获取当前行数据
            chunk = bin_data[i:i+bytes_per_line]
            
            # 转换为十六进制字符串 (大写)
            hex_line = ' '.join(f"{b:02X}" for b in chunk)
            
            # 写入行
            f.write(f"{hex_line}\n")
    
    print(f"转换完成: {input_bin} -> {output_hex}")
    print(f"VMA 起始地址: {hex(vma_start)}")
    print(f"总字节数: {len(bin_data)}")
    print(f"每行字节数: {bytes_per_line}")

def main():
    parser = argparse.ArgumentParser(description='将 RISC-V .bin 文件转换为 Verilog HEX 格式')
    parser.add_argument('input_bin', help='输入 .bin 文件')
    parser.add_argument('output_hex', help='输出 .hex 文件')
    parser.add_argument('--vma_start', type=lambda x: int(x, 0), default=0x100000000,
                        help='VMA 起始地址 (十六进制, 默认: 0x00000000)')
    parser.add_argument('--bytes_per_line', type=int, default=16,
                        help='每行字节数 (默认: 16)')
    
    args = parser.parse_args()
    
    # 执行转换
    bin_to_hex(
        args.input_bin,
        args.output_hex,
        args.vma_start,
        args.bytes_per_line
    )

if __name__ == "__main__":
    main()