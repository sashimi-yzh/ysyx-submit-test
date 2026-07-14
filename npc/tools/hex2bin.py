import sys
import struct
import os

def hex_to_bin(input_path, output_path):
    print(f"Converting '{input_path}' to '{output_path}'...")
    
    try:
        with open(input_path, 'r') as f_in, open(output_path, 'wb') as f_out:
            for line_num, line in enumerate(f_in):
                line = line.strip()
                
                # 1. 跳过空行和 Logisim 的头信息 (v3.0 hex ...)
                if not line or line.startswith('v'):
                    continue
                
                parts = line.split()
                
                # 2. 确保行内有数据
                if not parts:
                    continue

                # 3. 处理数据部分
                # Logisim 格式通常是 "地址: 数据 数据 ..."
                # 例如: "00000: 00000413 00051137"
                # 我们从索引 1 开始遍历，跳过索引 0 的地址标签 (例如 "00000:")
                
                # 检查第一项是否是地址标签（以冒号结尾）
                start_index = 0
                if parts[0].endswith(':'):
                    start_index = 1
                
                for i in range(start_index, len(parts)):
                    hex_str = parts[i]
                    try:
                        # 将十六进制字符串转换为整数
                        val = int(hex_str, 16)
                        
                        # 4. 写入二进制文件
                        # '<I' 表示: Little Endian (小端序), Unsigned Int (32位/4字节)
                        # 如果你需要大端序 (Big Endian)，请将 '<I' 改为 '>I'
                        binary_data = struct.pack('<I', val) 
                        f_out.write(binary_data)
                        
                    except ValueError:
                        print(f"Warning: Skipping invalid hex at line {line_num+1}: {hex_str}")

        print(f"Success! Output file size: {os.path.getsize(output_path)} bytes.")

    except FileNotFoundError:
        print(f"Error: File '{input_path}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python hex2bin.py <input.hex> <output.bin>")
        print("Example: python hex2bin.py rom.hex rom.bin")
    else:
        hex_to_bin(sys.argv[1], sys.argv[2])