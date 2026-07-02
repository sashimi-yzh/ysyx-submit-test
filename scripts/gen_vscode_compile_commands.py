#!/usr/bin/env python3

import json
import os
import re
import subprocess
from pathlib import Path


ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / ".vscode" / "compile_commands.json"


def source_files(base, suffixes):
  root = ROOT / base
  return sorted(p for p in root.rglob("*") if p.suffix in suffixes)


def verilator_include_dirs():
  roots = []
  env_root = os.environ.get("VERILATOR_ROOT")
  if env_root:
    roots.append(Path(env_root))
  try:
    output = subprocess.check_output(["verilator", "-V"], text=True, stderr=subprocess.DEVNULL)
    match = re.search(r"VERILATOR_ROOT\s*=\s*(\S+)", output)
    if match:
      roots.append(Path(match.group(1)))
  except (OSError, subprocess.CalledProcessError):
    pass

  roots += [
    Path("/usr/local/share/verilator"),
    Path("/usr/share/verilator"),
    ROOT.parent / "oss-cad-suite" / "share" / "verilator",
  ]

  dirs = []
  for root in roots:
    inc = root / "include"
    if inc.is_dir() and inc not in dirs:
      dirs.append(inc)
    vltstd = inc / "vltstd"
    if vltstd.is_dir() and vltstd not in dirs:
      dirs.append(vltstd)
  return dirs


def add_entry(entries, compiler, std, defines, includes, autoconf, source):
  rel_source = source.relative_to(ROOT)
  command = [
    compiler,
    std,
    *defines,
    *(f"-I {path}" for path in includes),
    f"-include {autoconf}",
    "-c",
    str(rel_source),
  ]
  entries.append({
    "directory": str(ROOT),
    "command": " ".join(command),
    "file": str(source),
  })


def add_nemu(entries):
  defines = [
    "-D__GUEST_ISA__=riscv32",
    "-DDEBUG",
    "-DITRACE_COND=true",
    "-DMTRACE_COND=true",
  ]
  includes = [
    "nemu/include",
    "nemu/src/isa/riscv32/include",
    "nemu/src/engine/interpreter",
    "nemu/tools/capstone/repo/include",
  ]
  dirs = [
    "nemu/src/cpu",
    "nemu/src/device",
    "nemu/src/engine/interpreter",
    "nemu/src/isa/riscv32",
    "nemu/src/memory",
    "nemu/src/monitor",
    "nemu/src/utils",
  ]
  files = []
  for directory in dirs:
    files += source_files(directory, {".c"})
  files.append(ROOT / "nemu" / "src" / "nemu-main.c")

  for source in sorted(set(files)):
    if source.exists():
      add_entry(entries, "gcc", "-std=gnu11", defines, includes,
                "nemu/include/generated/autoconf.h", source)


def add_npc(entries):
  base_defines = [
    "-D__GUEST_ISA__=riscv32",
    "-DDEBUG",
    "-DITRACE_COND=true",
    "-DMTRACE_COND=true",
  ]
  base_includes = [
    "npc/include",
    "npc/src/isa/riscv32/include",
    "npc/src/engine/interpreter",
    "npc/vsrc",
    "npc/vsrc/core",
    "npc/tools/capstone/repo/include",
    "nvboard/usr/include",
  ]
  base_includes += [str(path) for path in verilator_include_dirs()]
  verilator_dirs = sorted((ROOT / "npc" / "build").glob("*/obj-*/verilator"))
  for source in source_files("npc/src", {".c", ".cpp"}):
    is_cpp = source.suffix == ".cpp"
    rel = source.relative_to(ROOT).as_posix()
    defines = list(base_defines)
    includes = list(base_includes)
    if is_cpp:
      if "/platform/ysyxsoc/" in rel:
        defines.append("-DNPC_BUILD_PLATFORM_YSYXSOC=1")
      else:
        defines.append("-DNPC_BUILD_PLATFORM_NPC=1")
      includes += [str(path.relative_to(ROOT)) for path in verilator_dirs]
    add_entry(entries, "g++" if is_cpp else "gcc",
              "-std=c++17" if is_cpp else "-std=gnu11",
              defines, includes, "npc/include/generated/autoconf.h", source)


def main():
  entries = []
  add_nemu(entries)
  add_npc(entries)
  OUT.parent.mkdir(parents=True, exist_ok=True)
  OUT.write_text(json.dumps(entries, indent=2) + "\n")
  print(f"wrote {OUT.relative_to(ROOT)} with {len(entries)} entries")


if __name__ == "__main__":
  main()
