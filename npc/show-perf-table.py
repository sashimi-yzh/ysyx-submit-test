#!/usr/bin/env python3
import sys
from pathlib import Path


def load_kv(path):
    """读取 key=value 形式的性能文件，返回一个 dict。"""
    text = Path(path).read_text(encoding="utf-8").strip()
    if not text:
        return {}
    kv = {}
    for line in text.splitlines():
        line = line.strip()
        if not line or "=" not in line:
            continue
        k, v = line.split("=", 1)
        kv[k.strip()] = v.strip()
    return kv


def print_table(kv):
    if not kv:
        print("no data")
        return

    # 只挑几项核心字段按固定顺序展示，避免顺序混乱
    keys = [
        "date",
        "time",
        "end_pc",
        "total_cycle",
        "total_inst",
        "ipc",
        "ifu_count",
        "ifu_time",
        "ifu_occupied",
        "lsu_count",
        "lsu_time",
        "lsu_occupied",
        "exu_count",
    ]

    header = []
    row = []
    for k in keys:
        if k in kv:
            header.append(k)
            row.append(kv[k])

    if not header:
        print("no recognized fields")
        return

    widths = [max(len(h), len(v)) for h, v in zip(header, row)]

    def sep(char_mid="-", char_cross="+"):
        parts = [char_mid * (w + 2) for w in widths]
        print(char_cross + char_cross.join(parts) + char_cross)

    # header
    sep()
    print("| " + " | ".join(col.ljust(widths[i]) for i, col in enumerate(header)) + " |")
    sep("=","+")
    print("| " + " | ".join(col.ljust(widths[i]) for i, col in enumerate(row)) + " |")
    sep()


if __name__ == "__main__":
    path = sys.argv[1] if len(sys.argv) > 1 else "/home/ysyx/project/ysyx-workbench/npc/performance.txt"
    kv = load_kv(path)
    print_table(kv)