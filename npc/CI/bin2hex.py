#!/usr/bin/env python3
import sys

if len(sys.argv) != 3:
    print("usage: python3 bin2hex.py input.bin output.hex")
    sys.exit(1)

bin_path = sys.argv[1]
hex_path = sys.argv[2]

with open(bin_path, "rb") as f:
    data = f.read()

# 4字节对齐补0
pad = (4 - len(data) % 4) % 4
data += b"\x00" * pad

with open(hex_path, "w") as fout:
    fout.write("@00000000\n")
    for i in range(0, len(data), 4):
        word = int.from_bytes(data[i:i+4], byteorder="little")
        fout.write(f"{word:08x}\n")
