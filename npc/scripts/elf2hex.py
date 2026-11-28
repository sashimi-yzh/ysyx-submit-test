#!/usr/bin/env python3
# 从 ELF 直接生成 $readmemh 格式（带 @地址 指令），只取 SHF_ALLOC 且非 NOBITS 的段。
# 相比 objcopy -O binary：不怕段之间巨大的空洞（RT-Thread 镜像就是被 VMA=0 的段
# 和一个 2GB 的文件偏移撑到 2GB 的，实际内容只有几百 KB）。
import sys, struct

def main():
    if len(sys.argv) < 3:
        print("用法: elf2hex.py <in.elf> <out.hex> [base_override]\n"
              "  base_override: 把 VMA 为 0 的段映射到的地址（默认 0x80000000）")
        return 1
    src, dst = sys.argv[1], sys.argv[2]
    base0 = int(sys.argv[3], 0) if len(sys.argv) > 3 else 0x80000000

    d = open(src, "rb").read()
    assert d[:4] == b"\x7fELF", "不是 ELF"
    is64 = d[4] == 2
    assert not is64, "目前只支持 ELF32"
    e_shoff, = struct.unpack_from("<I", d, 0x20)
    e_shentsize, e_shnum, e_shstrndx = struct.unpack_from("<HHH", d, 0x2E)
    secs = []
    for i in range(e_shnum):
        o = e_shoff + i * e_shentsize
        name, typ, flags, addr, off, size = struct.unpack_from("<IIIIII", d, o)
        secs.append((name, typ, flags, addr, off, size))

    out = []
    total = 0
    skipped = []
    for (name, typ, flags, addr, off, size) in secs:
        if typ == 8:            # SHT_NOBITS (.bss/.bss.extra)：不占文件，跳过（存储器已清零）
            continue
        if not (flags & 0x2):   # 只要 SHF_ALLOC
            continue
        if size == 0:
            continue
        if addr == 0:
            # VMA=0 的段（RT-Thread 端口的 .data.extra/.bss.extra 之类）不属于
            # 0x80000000 起的镜像，直接跳过，否则会把启动代码覆盖掉
            skipped.append((name, size))
            continue
        a = addr
        body = d[off:off + size]
        body += b"\0" * ((4 - len(body) % 4) % 4)
        # $readmemh 的 @ 是"数组下标"，不是字节地址：按 32 位字折算
        out.append("@%x\n" % ((a - base0) >> 2))
        for i in range(0, len(body), 4):
            out.append("%08x\n" % struct.unpack_from("<I", body, i)[0])
        total += size
    open(dst, "w").write("".join(out))
    for (name, size) in skipped:
        print(f"  [跳过] 段 {name} (VMA=0, {size} B)")
    print(f"elf2hex: {src} -> {dst}: {len(out)//4} 处段内容, 共 {total/1024:.1f} KB")
    return 0

sys.exit(main())
