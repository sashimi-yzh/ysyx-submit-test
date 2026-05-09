import sys

def main():
    if len(sys.argv) < 3:
        print("Usage: python bin2hex_little.py <input.bin> <output.hex> [data_width_bytes]")
        return
    
    input_file = sys.argv[1]
    output_file = sys.argv[2]
    data_width_bytes = int(sys.argv[3]) if len(sys.argv) > 3 else 4  # 默认 4 字节

    with open(input_file, "rb") as fin, open(output_file, "w") as fout:
        while True:
            chunk = fin.read(data_width_bytes)
            if not chunk:
                break
            if len(chunk) < data_width_bytes:
                chunk = chunk.ljust(data_width_bytes, b'\x00')
            
            # 关键修改：按小端序解释字节流
            hex_val = int.from_bytes(chunk, byteorder='little')
            fout.write(f"{hex_val:0{data_width_bytes*2}x}\n")

    print(f"Converted {input_file} -> {output_file} (Little-Endian)")

if __name__ == "__main__":
    main()