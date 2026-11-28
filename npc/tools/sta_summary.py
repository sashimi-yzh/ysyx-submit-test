#!/usr/bin/env python3
"""从 yosys-sta 的结果目录里提取面积和时序，打成几行可 grep / 可 diff 的摘要。

    tools/sta_summary.py                 # 默认 result/，自动挑最新一次 sta 结果
    tools/sta_summary.py result/ysyx_26030092-800MHz

数据来源：
    synth_stat.txt          综合后的单元/面积统计（yosys）
    <DESIGN>.rpt            iEDA 的时序报告（Endpoint 汇总表 + TNS 表）
"""
import glob
import os
import re
import sys


def resolve(path):
    """path 给 result/ 就挑里面最新的一次结果，给具体目录就原样用"""
    if not os.path.isdir(path) or glob.glob(os.path.join(path, '*.rpt')):
        return path
    dirs = [d for d in glob.glob(os.path.join(path, '*')) if glob.glob(os.path.join(d, '*.rpt'))]
    if not dirs:
        return path
    return max(dirs, key=lambda d: os.path.getmtime(glob.glob(os.path.join(d, '*.rpt'))[0]))


def parse_area(path):
    txt = open(path, encoding='utf-8', errors='replace').read() if os.path.exists(path) else ''
    out = {}
    m = re.search(r"Chip area for module '[^']*':\s*([0-9.]+)", txt)
    if m:
        out['area_um2'] = m.group(1)
    m = re.search(r"of which used for sequential elements:\s*([0-9.]+)\s*\(([0-9.]+)%\)", txt)
    if m:
        out['seq_um2'], out['seq_pct'] = m.group(1), m.group(2)
    m = re.search(r"^\s*(\d+)\s+[\d.Ee+]+\s+DFF_X1\s*$", txt, re.M)
    if m:
        out['DFF_X1'] = m.group(1)
    m = re.search(r"^\s*(\d+)\s+[\d.Ee+]+\s+cells\s*$", txt, re.M)
    if m:
        out['cells'] = m.group(1)
    return out


def parse_timing(path):
    """setup/hold 的最差 slack（core_clock 一份、含时钟门控检查一份）、fmax、TNS、端点"""
    res = {'tns': {}}
    if not os.path.exists(path):
        return res
    for line in open(path, encoding='utf-8', errors='replace'):
        if not line.startswith('|'):
            continue
        col = [c.strip() for c in line.strip().strip('|').split('|')]
        # Endpoint 汇总表：Endpoint | Clock Group | Delay Type | ... | Slack | Freq(MHz)
        if len(col) == 8 and col[2] in ('max', 'min'):
            try:
                slack = float(col[6])
            except ValueError:
                continue
            keys = ['setup' if col[2] == 'max' else 'hold']
            if col[1] == 'core_clock':
                keys.append(keys[0] + '_core')
            for key in keys:
                cur = res.get(key)
                if cur is None or slack < cur[0]:
                    res[key] = (slack, col[0], col[7])
        # TNS 表：Clock | Delay Type | TNS
        elif len(col) == 3 and col[0] == 'core_clock' and col[1] in ('max', 'min'):
            res['tns']['setup' if col[1] == 'max' else 'hold'] = col[2]
    return res


def main():
    root = resolve(sys.argv[1] if len(sys.argv) > 1 else 'result')
    name = os.path.basename(os.path.normpath(root))

    area = parse_area(os.path.join(root, 'synth_stat.txt'))
    if area:
        g = lambda k: area.get(k, 'n/a')
        um2 = lambda k: f"{float(area[k]):.3f}" if k in area else 'n/a'
        print(f"[AREA] dir={name} cells={g('cells')} DFF_X1={g('DFF_X1')} area_um2={um2('area_um2')} "
              f"seq_um2={um2('seq_um2')} seq_pct={g('seq_pct')}")
    else:
        print(f"[AREA] dir={name} n/a（找不到 synth_stat.txt，先跑 make syn）")

    rpts = glob.glob(os.path.join(root, '*.rpt'))
    tim = parse_timing(max(rpts, key=os.path.getmtime) if rpts else '')
    if tim.get('setup') is None:
        print("[TIME] n/a（找不到时序报告，先跑 make sta）")
        return
    wns = lambda k: f"{tim[k][0]:.3f}" if tim.get(k) else "n/a"
    # 时钟门控检查那组没有 Freq 列，fmax 取 core_clock 的关键路径
    fmax = (tim.get('setup_core') or tim['setup'])[2]
    tns = tim['tns']
    print(f"[TIME] wns_setup_all={wns('setup')} wns_setup_core={wns('setup_core')} "
          f"wns_hold_core={wns('hold_core')} fmax_MHz={fmax} "
          f"tns_setup={tns.get('setup', 'n/a')} tns_hold={tns.get('hold', 'n/a')}")
    if tim.get('setup_core'):
        print(f"[TIME] path_setup_core={tim['setup_core'][1]}")
    print(f"[TIME] path_setup_all={tim['setup'][1]}")


if __name__ == '__main__':
    main()
