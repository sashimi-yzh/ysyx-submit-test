#!/usr/bin/env python3
"""Generate the single-file CPU RTL required by the B-stage CI flow.

The generated file is a *SoC-mode, synthesis-mode* view of the NPC:

  * PC reset value is 0x30000000;
  * DPI-C / PMEM / perf / trace / difftest code is excluded;
  * only modules instantiated by the CPU wrapper are emitted;
  * all inner module names are prefixed with the student ID;
  * the top-level module is named exactly <stuid> and starts at column 0.

The source RTL in npc/vsrc is never modified.  Verilator's preprocessor is
used to resolve the SOC_MODE / SYNTHESIS branches, then the preprocessed text
is concatenated and the inner module names are renamed.

Usage:
    python3 npc/scripts/gen_verilog.py [--out DIR]

The output file is npc/build/<stuid>.v by default.
"""

from __future__ import annotations

import argparse
import re
import subprocess
import sys
from pathlib import Path


SCRIPT_DIR = Path(__file__).resolve().parent
NPC_DIR = SCRIPT_DIR.parent
WORKBENCH_ROOT = NPC_DIR.parent
VSRC = NPC_DIR / "vsrc"
DEFAULT_OUT_DIR = NPC_DIR / "build"

# Modules that are part of the current SoC/synthesis view.  Keep this list in
# sync with the active RTL after moving experimental modules to vsrc/back/.
# PMEM.v is deliberately excluded: it is a simulation-only DPI-C memory model.
INNER_MODULES = [
    "top",
    "Core",
    "ICache",
    "LSU",
    "Arbiter",
    "CSR",
    "RegisterFile",
]

# Optional modules: included automatically when present.
OPTIONAL_MODULES = [
    "CLINT",
]

WRAPPER = "ysyx_26020070.v"


def find_stuid() -> str:
    """Read STUID from the workbench Makefile, or use the environment."""
    env_stuid = None
    # The environment variable is convenient for local experiments; the
    # Makefile is the authoritative source for CI.
    import os

    env_stuid = os.environ.get("STUID")
    if env_stuid:
        return env_stuid.strip()

    makefile = WORKBENCH_ROOT / "Makefile"
    if makefile.is_file():
        text = makefile.read_text()
        m = re.search(r"^\s*STUID\s*=\s*(\S+)", text, re.M)
        if m:
            return m.group(1).strip()
    raise SystemExit("error: cannot determine STUID from environment or ysyx-workbench/Makefile")


def run_verilator_preprocess(src: Path) -> str:
    """Return source text with SOC_MODE + SYNTHESIS branches resolved."""
    cmd = [
        "verilator",
        "-E",
        "-DSOC_MODE",
        "-DSYNTHESIS",
        str(src),
    ]
    proc = subprocess.run(cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    if proc.returncode != 0:
        sys.stderr.write(proc.stderr)
        raise SystemExit(f"error: Verilator preprocessing failed for {src}")
    lines = []
    for line in proc.stdout.splitlines():
        # Verilator emits `line directives; they are harmless for simulation
        # but make the generated file noisy and can confuse simple parsers.
        if re.match(r"^\s*`line\b", line):
            continue
        lines.append(line)
    return "\n".join(lines) + "\n"


def rename_modules(text: str, prefix: str, names: list[str]) -> str:
    """Prefix module declarations and instantiations.

    Declarations are renamed first, so the instantiation regex cannot match a
    declaration again.  The regexes are deliberately conservative: the active
    RTL is small and uses simple ``Module instance (`` instantiation syntax.
    """
    # 1. module declarations.
    for name in names:
        text = re.sub(
            rf"(?m)^(\s*)module\s+{re.escape(name)}\b",
            rf"\1module {prefix}{name}",
            text,
        )

    # 2. instantiations: "Module u_instance (" (possibly on one line).
    for name in names:
        text = re.sub(
            rf"\b{re.escape(name)}\s+([A-Za-z_]\w*)\s*\(",
            rf"{prefix}{name} \1(",
            text,
        )

    return text


def validate(text: str, stuid: str, inner_names: list[str]) -> None:
    if "import \"DPI-C\"" in text:
        raise SystemExit("error: generated RTL still contains DPI-C imports")
    if re.search(r"(?m)^\s*module\s+PMEM\b", text):
        raise SystemExit("error: generated RTL contains the PMEM simulation model")
    if not re.search(rf"(?m)^module\s+{re.escape(stuid)}\b", text):
        raise SystemExit(f"error: generated RTL is missing top-level module {stuid}")
    if not re.search(r"32'h3000_?0000", text):
        raise SystemExit("error: generated RTL does not contain the 0x30000000 reset PC")

    # Core.v intentionally keeps the SIM_IVERILOG reset switch.  Other
    # modules are preprocessed, so only the known configuration macros may
    # remain as directives in the delivered file.
    allowed_macros = {"SOC_MODE", "SYNTHESIS", "SIM_IVERILOG"}
    for m in re.finditer(r"(?m)^\s*`(?:ifdef|ifndef|elsif)\s+([A-Za-z_]\w*)", text):
        if m.group(1) not in allowed_macros:
            raise SystemExit(f"error: unresolved preprocessor condition: {m.group(1)}")
    for m in re.finditer(r"(?m)^\s*`define\s+([A-Za-z_]\w*)", text):
        if m.group(1) not in allowed_macros:
            raise SystemExit(f"error: unexpected preprocessor define: {m.group(1)}")
    if re.search(r"(?m)^\s*`(?:include|undef)\b", text):
        raise SystemExit("error: unexpected preprocessor directive in generated RTL")

    modules = re.findall(r"(?m)^\s*module\s+([A-Za-z_]\w*)\b", text)
    if len(modules) != len(set(modules)):
        raise SystemExit("error: duplicate module declarations in generated RTL")

    for name in inner_names:
        if name in modules:
            raise SystemExit(f"error: inner module '{name}' was not prefixed")
        if f"{stuid}_{name}" not in modules:
            raise SystemExit(f"error: generated RTL is missing module {stuid}_{name}")

    for name in modules:
        if name != stuid and not name.startswith(stuid + "_"):
            raise SystemExit(f"error: module '{name}' is not prefixed with {stuid}_")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--out", type=Path, default=None, help="output directory (default: npc/build)")
    args = parser.parse_args()

    stuid = find_stuid()
    if not re.fullmatch(r"ysyx_\d{8}", stuid):
        raise SystemExit(f"error: invalid STUID '{stuid}' (expected ysyx_XXXXXXXX)")
    prefix = stuid + "_"

    out_dir = args.out if args.out is not None else DEFAULT_OUT_DIR
    out_dir.mkdir(parents=True, exist_ok=True)
    out_file = out_dir / f"{stuid}.v"

    active = list(INNER_MODULES)
    for name in OPTIONAL_MODULES:
        if (VSRC / f"{name}.v").is_file():
            active.append(name)

    missing = [name for name in active if not (VSRC / f"{name}.v").is_file()]
    missing += [WRAPPER] if not (VSRC / WRAPPER).is_file() else []
    if missing:
        raise SystemExit("error: missing source file(s): " + ", ".join(missing))

    chunks = [
        "// Generated by npc/scripts/gen_verilog.py. Do not edit by hand.\n"
        f"// Student ID: {stuid}\n"
        "// Default view: SOC_MODE + SYNTHESIS (no DPI-C, no simulation-only memory).\n"
        "// SIM_IVERILOG is used by the 4-state testbench to start at 0x8000_0000.\n"
        "// Lint waivers: unused wrapper/debug ports are expected.\n"
        "/* verilator lint_off UNUSEDSIGNAL */\n"
        "/* verilator lint_off DECLFILENAME */\n"
        "`ifndef SOC_MODE\n"
        "`define SOC_MODE\n"
        "`endif\n"
        "`ifndef SYNTHESIS\n"
        "`define SYNTHESIS\n"
        "`endif\n"
    ]

    for name in active:
        src = VSRC / f"{name}.v"
        chunks.append(f"\n// ===== {src.name} =====\n")
        if name == "Core":
            # Keep the SIM_IVERILOG reset conditional in the delivered file.
            # The other modules are resolved for the SOC_MODE + SYNTHESIS view.
            chunks.append(src.read_text())
        else:
            chunks.append(run_verilator_preprocess(src))

    wrapper = VSRC / WRAPPER
    chunks.append(f"\n// ===== {wrapper.name} =====\n")
    chunks.append(run_verilator_preprocess(wrapper))

    text = "\n".join(chunks)
    text = rename_modules(text, prefix, active)
    text += "\n/* verilator lint_on DECLFILENAME */\n/* verilator lint_on UNUSEDSIGNAL */\n"

    validate(text, stuid, active)
    out_file.write_text(text)
    print(f"[gen_verilog] wrote {out_file} ({len(text)} bytes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
