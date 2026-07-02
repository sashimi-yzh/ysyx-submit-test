#!/usr/bin/env python3

from __future__ import annotations

import argparse
import json
import os
import pathlib
import re
import shutil
import subprocess
import sys
import tempfile
from dataclasses import asdict, dataclass


@dataclass
class CiConfig:
    yosys_sta_branch: str
    revert_commit: str
    area_budget: float
    area_old_budget: float


@dataclass
class AreaResult:
    area: float
    result_dir: str
    worst_slack_ns: float
    fmax_mhz: float


@dataclass
class EvalSummary:
    workbench: str
    npc_home: str
    vfile: str
    stuid: str
    design: str
    yosys_bin: str
    cache_dir: str
    run_dir: str | None
    ci_repo: str
    ci: CiConfig
    new_flow: AreaResult
    old_flow: AreaResult
    pass_ci: bool


AREA_RE = re.compile(r"Chip area for module '.*?': ([0-9.]+)")
FLOAT_RE = r"[-+]?(?:[0-9]+(?:\.[0-9]*)?|\.[0-9]+)"
TIMING_ROW_RE = re.compile(
    rf"^\|.*?\|\s*[^|]+\s*\|\s*max\s*\|\s*[^|]+\|\s*[^|]+\|\s*[^|]+\|\s*({FLOAT_RE})\s*\|\s*({FLOAT_RE})\s*\|$",
    re.MULTILINE,
)
STUID_RE = re.compile(r"^STUID\s*=\s*ysyx_(\d{8})\s*$", re.MULTILINE)
WORKFLOW_CLONE_RE = re.compile(r"git clone -b ([^\s]+) https://github\.com/OSCPU/yosys-sta")
WORKFLOW_REVERT_RE = re.compile(r"git revert --no-edit ([0-9a-f]{40})")
WORKFLOW_BUDGET_RE = re.compile(r"AREA_BUDGET=(\d+)")
WORKFLOW_OLD_BUDGET_RE = re.compile(r"AREA_OLD_BUDGET=(\d+)")
MODULE_RE = re.compile(r"Generating RTLIL representation for module `\\([^']+)'\.")


def eprint(*args: object) -> None:
    print(*args, file=sys.stderr)


def run(
    cmd: list[str],
    *,
    cwd: pathlib.Path | None = None,
    env: dict[str, str] | None = None,
) -> None:
    eprint("+", " ".join(cmd))
    subprocess.run(cmd, cwd=str(cwd) if cwd else None, env=env, check=True)


def parse_args() -> argparse.Namespace:
    script_path = pathlib.Path(__file__).resolve()
    default_workbench = script_path.parents[1]
    default_yosys = pathlib.Path.home() / "oss-cad-suite" / "bin" / "yosys"
    default_cache = pathlib.Path.home() / ".cache" / "ysyx-ci-area" / "yosys-sta"
    parser = argparse.ArgumentParser(description="Run a CI-equivalent local area evaluation.")
    parser.add_argument("--workbench", type=pathlib.Path, default=default_workbench)
    parser.add_argument("--npc-home", type=pathlib.Path)
    parser.add_argument("--ci-repo", type=pathlib.Path, help="Repo containing .github/workflows/autotest.yml")
    parser.add_argument("--stuid", help="8-digit student id without ysyx_ prefix")
    parser.add_argument("--yosys-bin", type=pathlib.Path, default=default_yosys)
    parser.add_argument("--cache-dir", type=pathlib.Path, default=default_cache)
    parser.add_argument("--keep-run-dir", action="store_true")
    parser.add_argument("--json-out", type=pathlib.Path)
    return parser.parse_args()


def find_ci_repo(workbench: pathlib.Path, override: pathlib.Path | None) -> pathlib.Path:
    if override:
        candidates = [override.expanduser().resolve()]
    else:
        script_path = pathlib.Path(__file__).resolve()
        candidates = [
            script_path.parents[1],
            workbench.parent / "ysyx-submit-test",
            workbench.parent / "ysyx-submit-ci",
        ]

    for candidate in candidates:
        workflow = candidate / ".github" / "workflows" / "autotest.yml"
        if workflow.is_file():
            return candidate
    raise RuntimeError("can not find CI repo containing .github/workflows/autotest.yml; please pass --ci-repo")


def parse_ci_config(workflow_path: pathlib.Path) -> CiConfig:
    text = workflow_path.read_text()
    branch = require_match(WORKFLOW_CLONE_RE, text, f"clone branch in {workflow_path}")
    revert_commit = require_match(WORKFLOW_REVERT_RE, text, f"revert commit in {workflow_path}")
    area_budget = float(require_match(WORKFLOW_BUDGET_RE, text, f"AREA_BUDGET in {workflow_path}"))
    area_old_budget = float(
        require_match(WORKFLOW_OLD_BUDGET_RE, text, f"AREA_OLD_BUDGET in {workflow_path}")
    )
    return CiConfig(
        yosys_sta_branch=branch,
        revert_commit=revert_commit,
        area_budget=area_budget,
        area_old_budget=area_old_budget,
    )


def require_match(pattern: re.Pattern[str], text: str, desc: str) -> str:
    match = pattern.search(text)
    if not match:
        raise RuntimeError(f"can not find {desc}")
    return match.group(1)


def resolve_paths(args: argparse.Namespace) -> tuple[pathlib.Path, pathlib.Path]:
    workbench = args.workbench.expanduser().resolve()
    npc_home = args.npc_home.expanduser().resolve() if args.npc_home else workbench / "npc"
    return workbench, npc_home


def read_stuid(workbench: pathlib.Path, override: str | None) -> str:
    if override:
        digits = override
    else:
        text = (workbench / "Makefile").read_text()
        match = STUID_RE.search(text)
        if not match:
            raise RuntimeError(f"can not find STUID in {workbench / 'Makefile'}")
        digits = match.group(1)
    if not re.fullmatch(r"\d{8}", digits):
        raise RuntimeError(f"invalid STUID digits: {digits}")
    return digits


def choose_vfile(npc_home: pathlib.Path, design: str) -> pathlib.Path:
    file_sv = npc_home / "build" / f"{design}.sv"
    file_v = npc_home / "build" / f"{design}.v"
    if file_sv.is_file():
        vfile = file_sv
    elif file_v.is_file():
        vfile = file_v
    else:
        raise RuntimeError(f"{file_sv} or {file_v} does not exist")
    timestamp = npc_home / ".timestamp"
    if not timestamp.exists():
        raise RuntimeError(f"{timestamp} does not exist")
    if timestamp.stat().st_mtime_ns > vfile.stat().st_mtime_ns:
        raise RuntimeError(f"{vfile} is older than {timestamp}")
    return vfile.resolve()


def ensure_verilog(npc_home: pathlib.Path) -> None:
    timestamp = npc_home / ".timestamp"
    run(["make", "-C", str(npc_home), "clean"])
    timestamp.touch()
    run(["make", "-C", str(npc_home), "verilog"])


def ensure_cache(cache_dir: pathlib.Path, branch: str) -> None:
    cache_dir.parent.mkdir(parents=True, exist_ok=True)
    if not cache_dir.exists():
        run(["git", "clone", "-b", branch, "https://github.com/OSCPU/yosys-sta", str(cache_dir)])
    shallow_file = cache_dir / ".git" / "shallow"
    if shallow_file.exists():
        run(["git", "-C", str(cache_dir), "fetch", "--unshallow", "origin", branch])
    else:
        run(["git", "-C", str(cache_dir), "fetch", "origin", branch])
    run(["git", "-C", str(cache_dir), "checkout", "-B", branch, "FETCH_HEAD"])
    if not (cache_dir / "bin" / "iEDA").exists() or not (cache_dir / "pdk" / "nangate45").exists():
        run(["make", "-C", str(cache_dir), "init"])


def make_temp_clone(cache_dir: pathlib.Path, branch: str) -> pathlib.Path:
    run_dir = pathlib.Path(tempfile.mkdtemp(prefix="ysyx-ci-area-"))
    run(["git", "clone", "--shared", "--branch", branch, str(cache_dir), str(run_dir)])
    for name in ("bin", "pdk"):
        src = cache_dir / name
        dst = run_dir / name
        if src.exists() and not dst.exists():
            dst.symlink_to(src, target_is_directory=True)
    return run_dir


def build_env(yosys_bin: pathlib.Path) -> dict[str, str]:
    if not yosys_bin.exists():
        raise RuntimeError(f"yosys not found: {yosys_bin}")
    env = os.environ.copy()
    env["PATH"] = f"{yosys_bin.parent}:{env.get('PATH', '')}"
    fallback_tmp = pathlib.Path(tempfile.gettempdir()).resolve()
    if not fallback_tmp.is_dir():
        fallback_tmp = pathlib.Path("/tmp")
    for key in ("TMPDIR", "TMP", "TEMP"):
        current = env.get(key)
        if not current or not pathlib.Path(current).expanduser().is_dir():
            env[key] = str(fallback_tmp)
    return env


def run_sta(
    run_dir: pathlib.Path,
    *,
    env: dict[str, str],
    design: str,
    vfile: pathlib.Path,
) -> AreaResult:
    run(
        [
            "make",
            "-C",
            str(run_dir),
            "clean",
            "sta",
            f"DESIGN={design}",
            "CLK_FREQ_MHZ=500",
            "CLK_PORT_NAME=clock",
            f"RTL_FILES={vfile}",
        ],
        env=env,
    )
    result_dir = run_dir / "result" / f"{design}-500MHz"
    log_path = result_dir / "yosys-fixed.log"
    rpt_path = result_dir / f"{design}.rpt"
    area = parse_area(log_path)
    worst_slack_ns, fmax_mhz = parse_timing(rpt_path)
    return AreaResult(area=area, result_dir=str(result_dir), worst_slack_ns=worst_slack_ns, fmax_mhz=fmax_mhz)


def parse_area(log_path: pathlib.Path) -> float:
    text = log_path.read_text()
    matches = AREA_RE.findall(text)
    if not matches:
        raise RuntimeError(f"can not obtain area from {log_path}")
    return float(matches[-1])


def parse_timing(rpt_path: pathlib.Path) -> tuple[float, float]:
    text = rpt_path.read_text()
    matches = TIMING_ROW_RE.findall(text)
    if not matches:
        raise RuntimeError(f"can not obtain timing summary from {rpt_path}")
    slacks = [float(slack) for slack, _ in matches]
    freqs = [float(freq) for _, freq in matches]
    return min(slacks), min(freqs)


def verify_module_name(log_path: pathlib.Path, design: str) -> None:
    text = log_path.read_text()
    frontend_done = "Successfully finished Verilog frontend."
    end_idx = text.find(frontend_done)
    if end_idx < 0:
        raise RuntimeError(f"can not find frontend marker in {log_path}")
    checked = text[:end_idx]
    bad_modules = [name for name in MODULE_RE.findall(checked) if not name.startswith(design)]
    if bad_modules:
        raise RuntimeError(f"there exist modules which do not start with {design}: {bad_modules}")


def verify_no_latch(stat_path: pathlib.Path) -> None:
    text = stat_path.read_text()
    if "DLL" in text or "DLH" in text:
        raise RuntimeError("the design contains latch, which is not allowed")


def copy_new_result(run_dir: pathlib.Path, design: str) -> pathlib.Path:
    src = run_dir / "result" / f"{design}-500MHz"
    dst = run_dir / "saved-result" / f"{design}-500MHz.new-flow"
    if dst.exists():
        shutil.rmtree(dst)
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(src, dst)
    return dst


def revert_old_flow(run_dir: pathlib.Path, commit: str) -> None:
    run(["git", "-C", str(run_dir), "config", "user.email", "ci@ysyx.org"])
    run(["git", "-C", str(run_dir), "config", "user.name", "ysyx-ci"])
    run(["git", "-C", str(run_dir), "revert", "--no-edit", commit])


def print_summary(summary: EvalSummary) -> None:
    new_ok = summary.new_flow.area <= summary.ci.area_budget
    old_ok = summary.old_flow.area <= summary.ci.area_old_budget
    print(f"workbench : {summary.workbench}")
    print(f"ci repo   : {summary.ci_repo}")
    print(f"vfile     : {summary.vfile}")
    print(f"yosys     : {summary.yosys_bin}")
    print(f"new area  : {summary.new_flow.area:.3f} / {summary.ci.area_budget:.0f} ({'PASS' if new_ok else 'FAIL'})")
    print(
        "new fmax  : "
        f"{summary.new_flow.fmax_mhz:.3f} MHz, slack {summary.new_flow.worst_slack_ns:.3f} ns "
        f"({'PASS' if summary.new_flow.fmax_mhz >= 600.0 else 'FAIL'} for 600 MHz)"
    )
    print(f"old area  : {summary.old_flow.area:.3f} / {summary.ci.area_old_budget:.0f} ({'PASS' if old_ok else 'FAIL'})")
    print(
        "old fmax  : "
        f"{summary.old_flow.fmax_mhz:.3f} MHz, slack {summary.old_flow.worst_slack_ns:.3f} ns "
        f"({'PASS' if summary.old_flow.fmax_mhz >= 600.0 else 'FAIL'} for 600 MHz)"
    )
    print(f"ci result : {'PASS' if summary.pass_ci else 'FAIL'}")
    if summary.run_dir:
        print(f"run dir   : {summary.run_dir}")


def maybe_write_json(summary: EvalSummary, json_out: pathlib.Path | None) -> None:
    if not json_out:
        return
    json_out.parent.mkdir(parents=True, exist_ok=True)
    json_out.write_text(json.dumps(asdict(summary), indent=2) + "\n")


def main() -> int:
    args = parse_args()
    workbench, npc_home = resolve_paths(args)
    ci_repo = find_ci_repo(workbench, args.ci_repo)
    workflow_path = ci_repo / ".github" / "workflows" / "autotest.yml"
    ci = parse_ci_config(workflow_path)
    stuid = read_stuid(workbench, args.stuid)
    design = f"ysyx_{stuid}"
    yosys_bin = args.yosys_bin.expanduser().resolve()
    cache_dir = args.cache_dir.expanduser().resolve()

    ensure_verilog(npc_home)
    vfile = choose_vfile(npc_home, design)
    ensure_cache(cache_dir, ci.yosys_sta_branch)

    env = build_env(yosys_bin)
    run_dir: pathlib.Path | None = None
    try:
        run_dir = make_temp_clone(cache_dir, ci.yosys_sta_branch)
        new_flow = run_sta(run_dir, env=env, design=design, vfile=vfile)
        verify_module_name(pathlib.Path(new_flow.result_dir) / "yosys.log", design)
        verify_no_latch(pathlib.Path(new_flow.result_dir) / "synth_stat.txt")
        new_flow = AreaResult(
            area=new_flow.area,
            result_dir=str(copy_new_result(run_dir, design)),
            worst_slack_ns=new_flow.worst_slack_ns,
            fmax_mhz=new_flow.fmax_mhz,
        )

        revert_old_flow(run_dir, ci.revert_commit)
        old_flow = run_sta(run_dir, env=env, design=design, vfile=vfile)

        summary = EvalSummary(
            workbench=str(workbench),
            npc_home=str(npc_home),
            vfile=str(vfile),
            stuid=stuid,
            design=design,
            yosys_bin=str(yosys_bin),
            cache_dir=str(cache_dir),
            run_dir=str(run_dir) if args.keep_run_dir else None,
            ci_repo=str(ci_repo),
            ci=ci,
            new_flow=new_flow,
            old_flow=old_flow,
            pass_ci=(new_flow.area <= ci.area_budget) or (old_flow.area <= ci.area_old_budget),
        )
        print_summary(summary)
        maybe_write_json(summary, args.json_out.expanduser().resolve() if args.json_out else None)
        return 0 if summary.pass_ci else 1
    finally:
        if run_dir and run_dir.exists() and not args.keep_run_dir:
            shutil.rmtree(run_dir)


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except subprocess.CalledProcessError as exc:
        eprint(f"command failed with exit code {exc.returncode}")
        raise SystemExit(exc.returncode)
    except RuntimeError as exc:
        eprint(f"error: {exc}")
        raise SystemExit(2)
