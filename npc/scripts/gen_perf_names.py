#!/usr/bin/env python3
# 从生成的 Verilog 中提取所有 PerfCounterArray 实例的层次路径，生成 C++ 头文件。
# 性能计数器的名称只在 RTL（PerfCounter("name")）指定，本脚本是 C++ 侧的自动名字来源。
import re
import sys
import os
import glob

BUILD_DIR = sys.argv[1]
OUT_PATH = sys.argv[2]

# 行首关键字（非模块实例化）
KEYWORDS = (
    'wire|reg|logic|input|output|inout|parameter|localparam|assign|always|initial|'
    'endmodule|module|import|export|task|function|genvar|generate|endgenerate|'
    'ifdef|ifndef|define|else|endif|typedef|class|struct|interface|for|case|default'
)

def parse_modules(text):
    """合并后的单文件里含多个 module，按 module ... endmodule 切块解析"""
    out = {}
    for m in re.finditer(r'^\s*module\s+(\w+)\s*\(', text, re.M):
        name = m.group(1)
        start = m.start()
        endm = re.search(r'^\s*endmodule', text[start:], re.M)
        body = text[start:start + endm.end()] if endm else text[start:]
        insts, counters = [], []
        for im in re.finditer(r'^\s*(\w+)\s+(\w+)\s*\(', body, re.M):
            typ, iname = im.group(1), im.group(2)
            if re.fullmatch(KEYWORDS, typ):
                continue
            if typ.endswith('PerfCounterArray'):
                counters.append(iname)
            else:
                insts.append((typ, iname))
        out[name] = (insts, counters)
    return out

# 第一遍：收集所有模块名（build 下所有 .v/.sv 都读，单个合并文件也能处理）
modules = {}
for f in sorted(glob.glob(os.path.join(BUILD_DIR, '*.sv')) +
                glob.glob(os.path.join(BUILD_DIR, '*.v'))):
    modules.update(parse_modules(open(f).read()))

# 第二遍：从顶层递归收集计数器路径
paths = []
def walk(mod, prefix):
    if mod not in modules:
        return
    insts, counters = modules[mod]
    for (t, n) in insts:
        walk(t, prefix + n + '.')
    for c in counters:
        paths.append(prefix + c)

if 'ysyx_26030092' not in modules:
    print(f"Error: top module 'ysyx_26030092' not found in {BUILD_DIR}", file=sys.stderr)
    sys.exit(1)
walk('ysyx_26030092', '')

if not paths:
    print(f"Error: no PerfCounterArray instances found", file=sys.stderr)
    sys.exit(1)

# 检查重名（同名实例会在 Verilog 里冲突，早发现）
seen = set()
for p in paths:
    assert p not in seen, f"duplicate perf scope: {p}"
    seen.add(p)

with open(OUT_PATH, 'w') as f:
    f.write("// 自动生成：性能计数器实例列表（RTL PerfCounter 声明是名称的唯一来源，请勿手改）\n")
    f.write(f"#define PERF_PREFIX \"TOP.ysyxSoCFull.asic.cpu.cpu.\"\n")
    f.write(f"#define PERF_COUNT {len(paths)}\n")
    f.write("static const char* perf_scope_names[] = {\n")
    for p in paths:
        f.write(f"  \"{p}\",\n")
    f.write("};\n")

print(f"generated {OUT_PATH}: {len(paths)} perf counters")
