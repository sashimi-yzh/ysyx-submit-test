#!/usr/bin/env python3
import sys
import os
from pathlib import Path
import shutil
import argparse
import re

def iter_verilog_files(root: Path):
    exts = {".v", ".sv", ".vh", ".svh"}
    for path in root.rglob("*"):
        if path.is_file() and path.suffix.lower() in exts:
            yield path

def process_file(path: Path, backup: bool, dry_run: bool, pattern: re.Pattern):
    try:
        text = path.read_text(encoding="utf-8")
    except UnicodeDecodeError:
        # 尝试其他常见编码
        for enc in ("latin-1", "gb18030"):
            try:
                text = path.read_text(encoding=enc)
                break
            except Exception:
                continue
        else:
            print(f"[SKIP] Cannot decode: {path}")
            return False

    new_text, n = pattern.subn("", text)
    if n == 0:
        return False

    if dry_run:
        print(f"[DRY] {path} -> {n} replacement(s)")
        return True

    if backup:
        bak = path.with_suffix(path.suffix + ".bak")
        if not bak.exists():
            shutil.copy2(path, bak)

    path.write_text(new_text, encoding="utf-8")
    print(f"[OK] {path} -> {n} replacement(s)")
    return True

def main():
    parser = argparse.ArgumentParser(
        description="Recursively remove '/*verilator public*/' from Verilog files under vsrc."
    )
    parser.add_argument("root", nargs="?", default="vsrc", help="Root directory (default: vsrc)")
    parser.add_argument("--no-backup", action="store_true", help="Do not create .bak backups")
    parser.add_argument("--dry-run", action="store_true", help="Preview changes without writing files")
    # 如果你的代码里可能出现空格形式，如 '/* verilator public */'，可以打开宽松匹配
    parser.add_argument("--loose", action="store_true",
                        help="Looser pattern to also match spaces: '/* verilator public */'")
    args = parser.parse_args()

    root = Path(args.root)
    if not root.exists():
        print(f"Root directory not found: {root}")
        sys.exit(1)

    # 精确匹配：/*verilator public*/
    exact_pattern = re.compile(r"/\*verilator public\*/")
    # 宽松匹配：允许空白字符
    loose_pattern = re.compile(r"/\*\s*verilator\s+public\s*\*/")

    pattern = loose_pattern if args.loose else exact_pattern

    total = 0
    changed = 0
    for f in iter_verilog_files(root):
        total += 1
        if process_file(f, backup=not args.no_backup, dry_run=args.dry_run, pattern=pattern):
            changed += 1

    print(f"Done. Scanned {total} files, modified {changed} files.")

if __name__ == "__main__":
    main()
