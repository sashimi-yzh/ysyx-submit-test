#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
合并文件脚本：读取sum_filelist.txt中的绝对路径，合并内容到指定输出文件
"""
import os
import sys

def merge_files(filelist_path: str, output_path: str):
    """
    核心合并函数
    :param filelist_path: 存储文件路径的列表文件（sum_filelist.txt）
    :param output_path: 合并后的输出文件路径
    """
    # 1. 检查列表文件是否存在
    if not os.path.exists(filelist_path):
        print(f"❌ 错误：文件列表 {filelist_path} 不存在！")
        sys.exit(1)
    
    # 2. 清空并创建输出文件（确保目录存在）
    output_dir = os.path.dirname(output_path)
    if output_dir and not os.path.exists(output_dir):
        os.makedirs(output_dir, exist_ok=True)
    
    # 3. 打开输出文件，准备写入
    with open(output_path, 'w', encoding='utf-8') as out_f:
        # 第一行空着
        out_f.write('\n')

        # 4. 逐行读取文件列表
        with open(filelist_path, 'r', encoding='utf-8') as list_f:
            line_num = 0
            for line in list_f:
                line_num += 1
                # 去除首尾空白（换行/空格/制表符）
                abs_path = line.strip()

                # 跳过空行和注释行（以#开头）
                if not abs_path or abs_path.startswith('#'):
                    continue

                # 5. 检查文件是否存在且可读
                if not os.path.exists(abs_path):
                    print(f"⚠️  第{line_num}行：文件不存在，跳过 → {abs_path}")
                    continue
                if not os.access(abs_path, os.R_OK):
                    print(f"⚠️  第{line_num}行：文件不可读，跳过 → {abs_path}")
                    continue

                # 6. 读取并写入文件内容（无分隔注释）
                print(f"✅ 第{line_num}行：合并文件 → {abs_path}")
                with open(abs_path, 'r', encoding='utf-8') as src_f:
                    out_f.write(src_f.read())
    
    print(f"\n🎉 合并完成！输出文件：{output_path}")

if __name__ == '__main__':
    # 接收命令行参数（支持自定义列表文件和输出文件）
    if len(sys.argv) != 3:
        print("用法：python3 merge_files.py <文件列表路径> <输出文件路径>")
        print("示例：python3 merge_files.py sum_filelist.txt /home/long/ysyx-workbench/npc/sum/ysyx_25020042.v")
        sys.exit(1)
    
    filelist_path = sys.argv[1]
    output_path = sys.argv[2]
    merge_files(filelist_path, output_path)