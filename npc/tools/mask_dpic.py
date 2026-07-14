#!/usr/bin/env python3
import sys
import os
import re

def process(action, files):
    # 正则表达式匹配：从 module 声明一直到分号 ; 为头部，中间为 body，尾部为 endmodule
    pattern = re.compile(r'(\bmodule\s+[^;]+;)(.*?)(\bendmodule\b)', re.DOTALL)

    for filepath in files:
        if not os.path.exists(filepath):
            continue
        bak_path = filepath + ".bak"

        if action == "mask":
            with open(filepath, 'r', encoding='utf-8') as f:
                content = f.read()

            def repl(match):
                header = match.group(1)
                body = match.group(2)
                footer = match.group(3)
                
                # 如果该模块内部（或头部）包含了 DPI-C
                if 'DPI-C' in body or 'DPI-C' in header:
                    # 使用 translate_off/on 隔离整个 body
                    masked_body = f"\n// synopsys translate_off\n{body}\n// synopsys translate_on\n"
                    return header + masked_body + footer
                return match.group(0)

            new_content = pattern.sub(repl, content)

            # 如果文件内容发生了变化，说明成功处理了 DPI-C
            if new_content != content:
                os.rename(filepath, bak_path) # 备份原文件
                with open(filepath, 'w', encoding='utf-8') as f:
                    f.write(new_content)
                print(f"[DPI-C Masker] Masked DPI-C in: {filepath}")

        elif action == "restore":
            if os.path.exists(bak_path):
                os.rename(bak_path, filepath) # 恢复原文件
                print(f"[DPI-C Masker] Restored: {filepath}")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print("Usage: python3 mask_dpic.py [mask|restore] <file1.v> <file2.v> ...")
        sys.exit(1)
    
    action = sys.argv[1]
    files = sys.argv[2:]
    process(action, files)