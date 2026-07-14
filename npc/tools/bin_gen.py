import struct

# 你的机器码列表 (从 _start 到 fun)
instructions = [
    0x00100013,
    0x000000b3,
    0x80000137,
    0xfff10113,
    0x00202023,
    0x00100223,
    0x00002183,
    0x00304203,
    0x004182b3,
    0x02400313,
    0x00030067
]

# 打开文件准备写入二进制 ('wb')
with open('program.bin', 'wb') as f:
    for inst in instructions:
        # '<I' 表示: 小端序 (Little-endian), 无符号整型 (Unsigned Int, 4 bytes)
        f.write(struct.pack('<I', inst))

print("program.bin 生成成功！")