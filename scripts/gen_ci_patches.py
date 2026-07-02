#!/usr/bin/env python3

from __future__ import annotations

import argparse
import fnmatch
import os
import pathlib
import shutil
import subprocess
import sys
import tempfile
from dataclasses import dataclass


@dataclass(frozen=True)
class ProjectConfig:
    name: str
    upstream: str
    branch: str
    local_dir: str
    output_dir: str
    exclude_patterns: tuple[str, ...]


PROJECTS = {
    "rt-thread-am": ProjectConfig(
        name="rt-thread-am",
        upstream="https://github.com/NJU-ProjectN/rt-thread-am",
        branch="master",
        local_dir="rt-thread-am",
        output_dir="patch/rt-thread-am",
        exclude_patterns=(
            ".git",
            "build",
            "out",
            "__pycache__",
            ".sconsign.dblite",
            "*.o",
            "*.a",
            "*.d",
            "*.elf",
            "*.bin",
            "*.log",
            "*.tmp",
            "*.swp",
            "*.pyc",
        ),
    ),
    "ysyxSoC": ProjectConfig(
        name="ysyxSoC",
        upstream="https://github.com/OSCPU/ysyxSoC",
        branch="ysyx6",
        local_dir="ysyxSoC",
        output_dir="patch/ysyxSoC",
        exclude_patterns=(
            ".git",
            "rocket-chip",
            "build",
            "out",
            "__pycache__",
            "*.o",
            "*.a",
            "*.d",
            "*.elf",
            "*.bin",
            "*.log",
            "*.tmp",
            "*.swp",
            "*.pyc",
        ),
    ),
}

ROCKET_CHIP_EXCLUDES = (
    ".git",
    "build",
    "out",
    "__pycache__",
    "*.o",
    "*.a",
    "*.d",
    "*.elf",
    "*.bin",
    "*.log",
    "*.tmp",
    "*.swp",
    "*.pyc",
)


def eprint(*args: object) -> None:
    print(*args, file=sys.stderr)


def run(cmd: list[str], *, cwd: pathlib.Path | None = None) -> None:
    eprint("+", " ".join(cmd))
    subprocess.run(cmd, cwd=str(cwd) if cwd else None, check=True)


def run_capture_bytes(cmd: list[str], *, cwd: pathlib.Path | None = None) -> bytes:
    eprint("+", " ".join(cmd))
    proc = subprocess.run(
        cmd,
        cwd=str(cwd) if cwd else None,
        check=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )
    return proc.stdout


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Generate CI-compatible patch series for vendored repos.")
    parser.add_argument(
        "--workbench",
        type=pathlib.Path,
        default=pathlib.Path(__file__).resolve().parents[1],
        help="ysyx-workbench root directory",
    )
    parser.add_argument(
        "--project",
        choices=tuple(PROJECTS.keys()) + ("all",),
        default="all",
        help="project to export",
    )
    return parser.parse_args()


def should_exclude(rel_path: pathlib.Path, patterns: tuple[str, ...]) -> bool:
    parts = rel_path.parts
    for pattern in patterns:
        if any(fnmatch.fnmatch(part, pattern) for part in parts):
            return True
    return False


def remove_path(path: pathlib.Path) -> None:
    if path.is_dir() and not path.is_symlink():
        shutil.rmtree(path)
    else:
        path.unlink()


def sync_tree(src_root: pathlib.Path, dst_root: pathlib.Path, patterns: tuple[str, ...], rel: pathlib.Path = pathlib.Path()) -> None:
    src_dir = src_root / rel
    dst_dir = dst_root / rel

    src_entries = {entry.name: entry for entry in src_dir.iterdir()}
    dst_entries = {entry.name: entry for entry in dst_dir.iterdir()}

    for name, dst_entry in dst_entries.items():
        child_rel = rel / name
        if should_exclude(child_rel, patterns):
            continue
        if name not in src_entries:
            remove_path(dst_entry)

    for name, src_entry in src_entries.items():
        child_rel = rel / name
        if should_exclude(child_rel, patterns):
            continue

        dst_entry = dst_dir / name
        if src_entry.is_dir() and not src_entry.is_symlink():
            if dst_entry.exists() and not dst_entry.is_dir():
                remove_path(dst_entry)
            dst_entry.mkdir(exist_ok=True)
            sync_tree(src_root, dst_root, patterns, child_rel)
        else:
            if dst_entry.exists():
                if dst_entry.is_dir() and not dst_entry.is_symlink():
                    shutil.rmtree(dst_entry)
                else:
                    dst_entry.unlink()
            if src_entry.is_symlink():
                os.symlink(os.readlink(src_entry), dst_entry)
            else:
                shutil.copy2(src_entry, dst_entry)


def refresh_rocket_chip_patch(workbench: pathlib.Path) -> None:
    local_rocket_chip = workbench / "ysyxSoC" / "rocket-chip"
    if not local_rocket_chip.exists():
        return

    patch_path = workbench / "ysyxSoC" / "patch" / "rocket-chip.patch"
    cfg = PROJECTS["ysyxSoC"]

    with tempfile.TemporaryDirectory(prefix="gen-ci-patch-rocket-chip-") as tmp:
        clone_dir = pathlib.Path(tmp) / "ysyxSoC"
        run(["git", "clone", "--depth", "1", "-b", cfg.branch, cfg.upstream, str(clone_dir)])
        run(["git", "submodule", "update", "--init", "--depth", "1", "rocket-chip"], cwd=clone_dir)

        temp_rocket_chip = clone_dir / "rocket-chip"
        sync_tree(local_rocket_chip, temp_rocket_chip, ROCKET_CHIP_EXCLUDES)
        run(["git", "add", "-A"], cwd=temp_rocket_chip)
        diff = run_capture_bytes(["git", "diff", "--binary", "--cached", "HEAD"], cwd=temp_rocket_chip)

    if diff:
        patch_path.parent.mkdir(parents=True, exist_ok=True)
        patch_path.write_bytes(diff)
        eprint(f"updated {patch_path}")
    elif not patch_path.exists():
        eprint(f"warning: {local_rocket_chip} has no diff and {patch_path} does not exist")


def clear_patch_dir(path: pathlib.Path) -> None:
    path.mkdir(parents=True, exist_ok=True)
    for patch in path.glob("*.patch"):
        patch.unlink()


def generate_patch_series(workbench: pathlib.Path, cfg: ProjectConfig) -> pathlib.Path:
    local_dir = (workbench / cfg.local_dir).resolve()
    output_dir = (workbench / cfg.output_dir).resolve()
    if not local_dir.is_dir():
        raise RuntimeError(f"missing local directory: {local_dir}")

    with tempfile.TemporaryDirectory(prefix=f"gen-ci-patch-{cfg.name}-") as tmp:
        clone_dir = pathlib.Path(tmp) / cfg.name
        run(["git", "clone", "--depth", "1", "-b", cfg.branch, cfg.upstream, str(clone_dir)])
        sync_tree(local_dir, clone_dir, cfg.exclude_patterns)

        run(["git", "config", "user.name", "ysyx-ci-local"], cwd=clone_dir)
        run(["git", "config", "user.email", "ci-local@ysyx.org"], cwd=clone_dir)
        run(["git", "add", "-A"], cwd=clone_dir)
        run(["git", "commit", "--allow-empty", "-m", f"ci: sync vendored {cfg.name}"], cwd=clone_dir)

        clear_patch_dir(output_dir)
        run(["git", "format-patch", "-1", "HEAD", "-o", str(output_dir)], cwd=clone_dir)
        return output_dir


def main() -> int:
    args = parse_args()
    workbench = args.workbench.expanduser().resolve()

    if args.project in ("all", "ysyxSoC"):
        refresh_rocket_chip_patch(workbench)

    selected = PROJECTS.values() if args.project == "all" else (PROJECTS[args.project],)
    for cfg in selected:
        output_dir = generate_patch_series(workbench, cfg)
        print(f"{cfg.name}: generated patches in {output_dir}")
    return 0


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except subprocess.CalledProcessError as exc:
        eprint(f"command failed with exit code {exc.returncode}")
        raise SystemExit(exc.returncode)
    except RuntimeError as exc:
        eprint(f"error: {exc}")
        raise SystemExit(2)
