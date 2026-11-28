#!/usr/bin/env python3
# .bin -> $readmemh 格式（存储器下标 0 对应 0x80000000）
#
# 适配 AM/RT-Thread 的镜像约定：
#   * 普通镜像（最低 VMA = 0x80000000）：文件偏移 0 就是 0x80000000；
#   * 若镜像里存在 VMA=0 的段（RT-Thread 端口的 .data.extra/.bss.extra 等），
#     objcopy -O binary 会把整张地址图从 0 铺到 0x8007xxxx，文件高达 2GB，
#     这时真正属于 0x80000000 的内容在文件偏移 0x80000000 之后，前面那 2GB
#     （VMA=0 的段 + 空洞）要丢掉 —— 否则会把启动代码覆盖掉。
#   * 尾部全零（flatten 进来的 .bss）裁掉，存储器本身已清零。
import sys, struct, mmap

PMEM_START = 0x8000_0000
CHUNK      = 1 << 22      # 4MB
PER_LINE   = 8

def trimmed_end(mm, size):
    pos = size
    while pos > 0:
        start = max(0, pos - CHUNK)
        s = len(mm[start:pos].rstrip(b"\0"))
        if s:
            return start + s
        pos = start
    return 0

def main():
    if len(sys.argv) < 3:
        print("用法: bin2hex.py <in.bin> <out.hex>"); return 1
    src, dst = sys.argv[1], sys.argv[2]
    with open(src, "rb") as f:
        size = f.seek(0, 2); f.seek(0)
        mm = mmap.mmap(f.fileno(), 0, access=mmap.ACCESS_READ)
        end = trimmed_end(mm, size)
        # 有 VMA=0 的段时，镜像内容从文件偏移 PMEM_START 开始
        off0 = PMEM_START if size >= PMEM_START else 0
        if end <= off0:
            print(f"bin2hex: 警告：镜像在 {off0:#x} 之后没有有效内容", file=sys.stderr)
        body = mm[off0:end]
    dropped = off0
    if len(body) % 4:
        body += b"\0" * (4 - len(body) % 4)
    nwords = len(body) // 4
    with open(dst, "w") as fo:
        fo.write("".join(
            " ".join("%08x" % w for (w,) in struct.iter_unpack("<I", body[i:i + 4 * PER_LINE]))
            + "\n"
            for i in range(0, len(body), 4 * PER_LINE)
        ))
    print(f"bin2hex: {src} {size/1048576:.1f}MB"
          + (f" (丢弃前 {dropped/1048576:.1f}MB: VMA=0 的段/空洞)" if dropped else "")
          + f" -> {len(body)/1024:.1f}KB / {nwords} words -> {dst}")
    return 0

sys.exit(main())
