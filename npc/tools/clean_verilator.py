#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
清理文件中的条件编译块：
- VERILATOR块：整块删除
- PLATFORM_NPC块：视作未定义，保留else/ifndef分支，删除ifdef分支，移除包裹指令
- __ICARUS__块：视作未定义，保留else/ifndef分支，删除ifdef分支，移除包裹指令
- PLATFORM_YSYXSOC块：视作已定义，保留ifdef分支，删除else/ifndef分支，移除包裹指令

调用方式：
  python3 clean_verilator.py <源文件路径> <输出文件路径>
  输出文件路径不能与源文件相同（除非你确实想覆盖，但脚本不会自动覆盖）。
"""
import os
import sys


def clean_verilator_block(lines: list) -> list:
    """删除所有 `ifdef VERILATOR ... `endif 块（支持嵌套）"""
    cleaned = []
    in_block = False
    nest = 0

    for line in lines:
        stripped = line.strip()

        if stripped.startswith('`ifdef VERILATOR'):
            in_block = True
            nest = 1
            continue

        if in_block:
            if stripped.startswith('`ifdef') or stripped.startswith('`ifndef'):
                nest += 1
            elif stripped.startswith('`endif'):
                nest -= 1
                if nest == 0:
                    in_block = False
            continue

        cleaned.append(line)

    return cleaned


def clean_macro_block(lines: list, macro: str) -> list:
    """
    处理指定宏的条件编译，视作该宏未定义：
    - `ifdef MACRO ... `endif        → 整块删除
    - `ifdef MACRO ... `else ... `endif → 删除ifdef分支，保留else分支
    - `ifndef MACRO ... `endif       → 保留内容，删除包裹指令
    - `ifndef MACRO ... `else ... `endif → 保留ifndef分支，删除else分支
    """
    cleaned = []
    in_ifdef = False       # 在 ifdef 分支内 → 跳过（宏未定义）
    in_else = False        # 在 else 分支内 → 保留
    ifdef_nest = 0
    else_nest = 0
    in_ifndef = False      # 在 ifndef 分支内 → 保留
    ifndef_nest = 0
    in_ifndef_else = False # 在 ifndef 的 else 分支内 → 跳过
    ifndef_else_nest = 0

    def is_ifdef(s):
        return s.startswith(f'`ifdef {macro}')

    def is_ifndef(s):
        return s.startswith(f'`ifndef {macro}')

    def is_any_directive(s):
        return s.startswith('`ifdef') or s.startswith('`ifndef')

    for line in lines:
        stripped = line.strip()

        # --- ifndef MACRO：ifndef分支保留，else分支删除 ---
        if is_ifndef(stripped) and not in_ifndef_else:
            in_ifndef = True
            ifndef_nest = 1
            continue

        if in_ifndef:
            if is_any_directive(stripped):
                ifndef_nest += 1
                cleaned.append(line)
            elif stripped.startswith('`else') and ifndef_nest == 1:
                in_ifndef = False
                in_ifndef_else = True
                ifndef_else_nest = 0
                continue
            elif stripped.startswith('`endif'):
                ifndef_nest -= 1
                if ifndef_nest == 0:
                    in_ifndef = False
                    continue
                else:
                    cleaned.append(line)
            else:
                cleaned.append(line)
            continue

        if in_ifndef_else:
            if is_any_directive(stripped):
                ifndef_else_nest += 1
            elif stripped.startswith('`endif'):
                if ifndef_else_nest == 0:
                    in_ifndef_else = False
                else:
                    ifndef_else_nest -= 1
            continue

        # --- ifdef MACRO：ifdef分支删除，else分支保留 ---
        if is_ifdef(stripped):
            in_ifdef = True
            ifdef_nest = 1
            continue

        # 在 ifdef 分支内 → 跳过
        if in_ifdef:
            if is_any_directive(stripped):
                ifdef_nest += 1
            elif stripped.startswith('`else') and ifdef_nest == 1:
                in_ifdef = False
                in_else = True
                else_nest = 0
                continue
            elif stripped.startswith('`endif'):
                ifdef_nest -= 1
                if ifdef_nest == 0:
                    in_ifdef = False
            continue

        # 在 else 分支内 → 保留
        if in_else:
            if is_any_directive(stripped):
                else_nest += 1
                cleaned.append(line)
            elif stripped.startswith('`endif'):
                if else_nest == 0:
                    in_else = False
                    continue
                else:
                    else_nest -= 1
                    cleaned.append(line)
            else:
                cleaned.append(line)
            continue

        cleaned.append(line)

    return cleaned


def clean_macro_block_keep_ifdef(lines: list, macro: str) -> list:
    """
    处理指定宏的条件编译，视作该宏【已定义】：
    - `ifdef MACRO ... `endif         → 保留内容，删除包裹指令
    - `ifdef MACRO ... `else ... `endif → 保留ifdef分支，删除else分支
    - `ifndef MACRO ... `endif        → 整块删除
    - `ifndef MACRO ... `else ... `endif → 删除ifndef分支，保留else分支
    """
    cleaned = []
    in_ifdef = False       # 在 ifdef 分支内 → 保留
    in_else = False        # 在 ifdef 的 else 分支内 → 跳过
    ifdef_nest = 0
    else_nest = 0
    in_ifndef = False      # 在 ifndef 分支内 → 跳过
    ifndef_nest = 0
    in_ifndef_else = False # 在 ifndef 的 else 分支内 → 保留
    ifndef_else_nest = 0

    def is_ifdef(s):
        return s.startswith(f'`ifdef {macro}')

    def is_ifndef(s):
        return s.startswith(f'`ifndef {macro}')

    def is_any_directive(s):
        return s.startswith('`ifdef') or s.startswith('`ifndef')

    for line in lines:
        stripped = line.strip()

        # --- ifndef MACRO：ifndef分支删除，else分支保留 ---
        if is_ifndef(stripped) and not in_ifndef_else:
            in_ifndef = True
            ifndef_nest = 1
            continue

        if in_ifndef:
            if is_any_directive(stripped):
                ifndef_nest += 1
            elif stripped.startswith('`else') and ifndef_nest == 1:
                in_ifndef = False
                in_ifndef_else = True
                ifndef_else_nest = 0
                continue
            elif stripped.startswith('`endif'):
                ifndef_nest -= 1
                if ifndef_nest == 0:
                    in_ifndef = False
                    continue
            continue

        if in_ifndef_else:
            if is_any_directive(stripped):
                ifndef_else_nest += 1
                cleaned.append(line)
            elif stripped.startswith('`endif'):
                if ifndef_else_nest == 0:
                    in_ifndef_else = False
                    continue
                else:
                    ifndef_else_nest -= 1
                    cleaned.append(line)
            else:
                cleaned.append(line)
            continue

        # --- ifdef MACRO：ifdef分支保留，else分支删除 ---
        if is_ifdef(stripped):
            in_ifdef = True
            ifdef_nest = 1
            continue

        if in_ifdef:
            if is_any_directive(stripped):
                ifdef_nest += 1
                cleaned.append(line)
            elif stripped.startswith('`else') and ifdef_nest == 1:
                in_ifdef = False
                in_else = True
                else_nest = 0
                continue
            elif stripped.startswith('`endif'):
                ifdef_nest -= 1
                if ifdef_nest == 0:
                    in_ifdef = False
                    continue
                else:
                    cleaned.append(line)
            else:
                cleaned.append(line)
            continue

        if in_else:
            if is_any_directive(stripped):
                else_nest += 1
            elif stripped.startswith('`endif'):
                if else_nest == 0:
                    in_else = False
                else:
                    else_nest -= 1
            continue

        cleaned.append(line)

    return cleaned


def clean_file(input_file: str, output_file: str):
    """核心清理函数"""
    if not os.path.exists(input_file):
        print(f"❌ 错误：源文件 {input_file} 不存在！")
        sys.exit(1)

    # 安全检查：不允许输出路径与输入路径完全相同（避免意外覆盖）
    if os.path.abspath(input_file) == os.path.abspath(output_file):
        print("❌ 错误：输出文件不能与源文件相同，以免覆盖原文件！")
        print("   请指定不同的输出路径。")
        sys.exit(1)

    output_dir = os.path.dirname(output_file)
    if output_dir and not os.path.exists(output_dir):
        os.makedirs(output_dir, exist_ok=True)

    with open(input_file, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    # 四步清理
    lines = clean_verilator_block(lines)                       # 1. 删除 VERILATOR 块
    lines = clean_macro_block(lines, 'PLATFORM_NPC')           # 2. PLATFORM_NPC 视作未定义
    lines = clean_macro_block(lines, '__ICARUS__')             # 3. __ICARUS__ 视作未定义
    lines = clean_macro_block_keep_ifdef(lines, 'PLATFORM_YSYXSOC')  # 4. PLATFORM_YSYXSOC 视作已定义

    with open(output_file, 'w', encoding='utf-8') as f:
        f.writelines(lines)

    print(f"✅ 清理完成！（已处理 VERILATOR / PLATFORM_NPC / __ICARUS__ / PLATFORM_YSYXSOC）")
    print(f"  源文件：{input_file}")
    print(f"  输出文件：{output_file}")


if __name__ == '__main__':
    if len(sys.argv) != 3:
        print("用法：python3 clean_verilator.py <源文件路径> <输出文件路径>")
        print("示例：python3 clean_verilator.py sum/ysyx_25020042.v sum/ysyx_25020042_clean.v")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    clean_file(input_file, output_file)