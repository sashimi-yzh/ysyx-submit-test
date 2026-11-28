#!/usr/bin/env python3
# yosys-sta 的综合网表把端口 bit-blast 成了 io_master_awaddr_0_ 这种形式，
# 这里生成一个同名壳模块（端口向量与 RTL 顶层一致）把网表接回去，供 iverilog 使用。
#
# 用法: netlist_wrap.py <netlist.v> <rtl_top.v> <out_net_core.v> <out_wrap.v>
import re
import sys

PORT_RE = re.compile(r'(input|output)?\s*(\[\s*(\d+)\s*:\s*(\d+)\s*\])?\s*(\w+)\s*$')


def rtl_ports(path):
    """返回 [(方向, 位宽, 名字)]，按 RTL 顶层端口顺序。"""
    s = open(path).read()
    m = re.search(r'^module\s+ysyx_26030092\s*\(', s, re.M)
    if not m:
        raise SystemExit("找不到 RTL 顶层 module ysyx_26030092")
    body = s[m.end():s.index(");", m.end())]
    ports = []
    direction = None
    for line in body.split(","):
        line = line.split("//")[0].strip()
        if not line:
            continue
        mm = PORT_RE.match(line)
        if not mm:
            continue
        if mm.group(1):
            direction = mm.group(1)      # firtool 只在同方向端口的第一个上写 input/output
        if direction is None:
            continue
        if mm.group(2):
            hi, lo = int(mm.group(3)), int(mm.group(4))
            width = abs(hi - lo) + 1
        else:
            width = 1
        ports.append((direction, width, mm.group(5)))
    return ports


def main():
    if len(sys.argv) != 5:
        raise SystemExit("用法: netlist_wrap.py <netlist.v> <rtl_top.v> <net_core.v> <wrap.v>")
    net_path, rtl_path, core_out, wrap_out = sys.argv[1:5]
    ports = rtl_ports(rtl_path)
    if not ports:
        raise SystemExit("端口解析失败")

    # 1) 网表顶层改名，避免与壳模块重名
    text = open(net_path).read()
    renamed = re.sub(r'^module\s+ysyx_26030092\s*\(',
                     'module ysyx_26030092_netlist(', text, count=1, flags=re.M)
    if renamed == text:
        raise SystemExit("网表里找不到 module ysyx_26030092")
    open(core_out, 'w').write(renamed)

    # 2) 壳模块：向量端口 <-> 网表的逐位端口
    decl, conn = [], []
    for (d, w, name) in ports:
        decl.append("  %s %s%s" % (d, "[%d:0] " % (w - 1) if w > 1 else "", name))
        if w == 1:
            conn.append("    .%s(%s)" % (name, name))
        else:
            for b in range(w):
                conn.append("    .%s_%d_(%s[%d])" % (name, b, name, b))
    open(wrap_out, 'w').write(
        "// 自动生成：把综合网表的 bit-blast 端口接回向量端口\n"
        "module ysyx_26030092(\n" + ",\n".join(decl) + "\n);\n"
        "  ysyx_26030092_netlist u_netlist(\n" + ",\n".join(conn) + "\n  );\n"
        "endmodule\n")
    print("netlist_wrap: %d 个端口 -> %s, 网表改名 -> %s" % (len(ports), wrap_out, core_out))


main()
