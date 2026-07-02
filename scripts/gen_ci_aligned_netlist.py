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
import urllib.request
from dataclasses import asdict, dataclass


REPO_ROOT = pathlib.Path(__file__).resolve().parents[1]
DEFAULT_CI_REPO = pathlib.Path("/home/ecall73/ysyx-submit-test")
DEFAULT_TOOL_HOME = pathlib.Path.home() / "ysyx-ci-tools"
WORKFLOW_REL = pathlib.Path(".github/workflows/autotest.yml")
STUID_RE = re.compile(r"^\s*STUID\s*=\s*ysyx_(\d{8})\s*$", re.MULTILINE)
RELEASE_TAG_RE = re.compile(r"OSS_CAD_SUITE_RELEASE_TAG:\s*([0-9-]+)")
YOSYS_STA_BRANCH_RE = re.compile(r"git clone -b ([^\s]+) https://github\.com/OSCPU/yosys-sta")
YOSYS_STA_REVERT_RE = re.compile(r"git revert --no-edit ([0-9a-f]{40})")
AREA_RE = re.compile(r"Chip area for module '.*?': ([0-9.]+)")
FLOAT_RE = r"[-+]?(?:[0-9]+(?:\.[0-9]*)?|\.[0-9]+)"
TIMING_ROW_RE = re.compile(
    rf"^\|.*?\|\s*[^|]+\s*\|\s*max\s*\|\s*[^|]+\|\s*[^|]+\|\s*[^|]+\|\s*({FLOAT_RE})\s*\|\s*({FLOAT_RE})\s*\|$",
    re.MULTILINE,
)
MODULE_RE = re.compile(r"Generating RTLIL representation for module `\\([^']+)'\.")


@dataclass
class CiSpec:
    oss_cad_suite_release_tag: str
    yosys_sta_branch: str
    yosys_sta_revert_commit: str


@dataclass
class FlowResult:
    area: float
    worst_slack_ns: float
    fmax_mhz: float
    result_dir: str
    netlist: str


@dataclass
class Summary:
    design: str
    vfile: str
    output_netlist: str
    area_fixed: float
    area_old: float
    new_worst_slack_ns: float
    new_fmax_mhz: float
    old_worst_slack_ns: float
    old_fmax_mhz: float
    new_flow_result_dir: str
    old_flow_result_dir: str
    run_dir: str | None
    tool_home: str
    oss_cad_suite: str
    yosys_sta_cache: str


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


def run_capture(
    cmd: list[str],
    *,
    cwd: pathlib.Path | None = None,
    env: dict[str, str] | None = None,
) -> str:
    eprint("+", " ".join(cmd))
    proc = subprocess.run(
        cmd,
        cwd=str(cwd) if cwd else None,
        env=env,
        check=True,
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
    )
    return proc.stdout


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Quickly synthesize the local build Verilog into a CI-aligned netlist.fixed.v."
    )
    parser.add_argument("--workbench", type=pathlib.Path, default=REPO_ROOT)
    parser.add_argument("--npc-home", type=pathlib.Path)
    parser.add_argument("--ci-repo", type=pathlib.Path, default=DEFAULT_CI_REPO)
    parser.add_argument("--vfile", type=pathlib.Path, help="Use an explicit local build Verilog file.")
    parser.add_argument(
        "--refresh-verilog",
        action="store_true",
        help="Regenerate npc/build/ysyx_<stuid>.v before running yosys-sta.",
    )
    parser.add_argument("--tool-home", type=pathlib.Path, default=DEFAULT_TOOL_HOME)
    parser.add_argument("--oss-cad-suite", type=pathlib.Path)
    parser.add_argument("--yosys-sta-cache", type=pathlib.Path)
    parser.add_argument("--output-netlist", type=pathlib.Path)
    parser.add_argument("--keep-run-dir", action="store_true")
    parser.add_argument("--json-out", type=pathlib.Path)
    return parser.parse_args()


def require_file(path: pathlib.Path, desc: str) -> pathlib.Path:
    resolved = path.expanduser().resolve()
    if not resolved.is_file():
        raise RuntimeError(f"missing {desc}: {resolved}")
    return resolved


def resolve_paths(args: argparse.Namespace) -> tuple[pathlib.Path, pathlib.Path]:
    workbench = args.workbench.expanduser().resolve()
    npc_home = args.npc_home.expanduser().resolve() if args.npc_home else workbench / "npc"
    return workbench, npc_home


def read_stuid(workbench: pathlib.Path) -> str:
    text = require_file(workbench / "Makefile", "workspace Makefile").read_text(encoding="utf-8")
    match = STUID_RE.search(text)
    if not match:
        raise RuntimeError(f"can not find STUID in {workbench / 'Makefile'}")
    return match.group(1)


def load_ci_spec(ci_repo: pathlib.Path) -> CiSpec:
    workflow_text = require_file(ci_repo / WORKFLOW_REL, "CI workflow").read_text(encoding="utf-8")
    return CiSpec(
        oss_cad_suite_release_tag=require_match(RELEASE_TAG_RE, workflow_text, "OSS_CAD_SUITE_RELEASE_TAG"),
        yosys_sta_branch=require_match(YOSYS_STA_BRANCH_RE, workflow_text, "yosys-sta branch"),
        yosys_sta_revert_commit=require_match(YOSYS_STA_REVERT_RE, workflow_text, "yosys-sta revert commit"),
    )


def require_match(pattern: re.Pattern[str], text: str, desc: str) -> str:
    match = pattern.search(text)
    if not match:
        raise RuntimeError(f"can not find {desc}")
    return match.group(1)


def ensure_verilog(npc_home: pathlib.Path) -> None:
    run(["make", "-C", str(npc_home), "clean"])
    (npc_home / ".timestamp").touch()
    run(["make", "-C", str(npc_home), "verilog"])


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


def prepare_oss_cad_suite(tool_home: pathlib.Path, spec: CiSpec, override: pathlib.Path | None) -> pathlib.Path:
    if override is not None:
        root = require_file(override / "bin" / "yosys", "explicit yosys").parents[1]
        require_file(root / "bin" / "iverilog", "explicit iverilog")
        require_file(root / "bin" / "vvp", "explicit vvp")
        return root

    tag = spec.oss_cad_suite_release_tag
    compact_tag = tag.replace("-", "")
    archive_name = f"oss-cad-suite-linux-x64-{compact_tag}.tgz"
    url = f"https://github.com/YosysHQ/oss-cad-suite-build/releases/download/{tag}/{archive_name}"

    downloads_dir = tool_home / "downloads"
    extract_root = tool_home / f"oss-cad-suite-{tag}"
    oss_root = extract_root / "oss-cad-suite"
    archive_path = downloads_dir / archive_name
    downloads_dir.mkdir(parents=True, exist_ok=True)

    if not archive_path.exists():
        eprint(f"downloading {url} -> {archive_path}")
        urllib.request.urlretrieve(url, archive_path)
    if not oss_root.exists():
        extract_root.mkdir(parents=True, exist_ok=True)
        shutil.unpack_archive(str(archive_path), str(extract_root))

    require_file(oss_root / "bin" / "yosys", "downloaded yosys")
    require_file(oss_root / "bin" / "iverilog", "downloaded iverilog")
    require_file(oss_root / "bin" / "vvp", "downloaded vvp")
    return oss_root


def ensure_yosys_sta_cache(cache_dir: pathlib.Path, branch: str) -> None:
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
    run_dir = pathlib.Path(tempfile.mkdtemp(prefix="ysyx-ci-netlist-"))
    run(["git", "clone", "--shared", "--branch", branch, str(cache_dir), str(run_dir)])
    for name in ("bin", "pdk"):
        src = cache_dir / name
        dst = run_dir / name
        if src.exists() and not dst.exists():
            dst.symlink_to(src, target_is_directory=True)
    return run_dir


def build_env(oss_cad_suite: pathlib.Path) -> dict[str, str]:
    env = os.environ.copy()
    env["PATH"] = f"{oss_cad_suite / 'bin'}:{env.get('PATH', '')}"
    tmp_root = pathlib.Path(tempfile.gettempdir()).resolve()
    if not tmp_root.is_dir():
        tmp_root = pathlib.Path("/tmp")
    for key in ("TMPDIR", "TMP", "TEMP"):
        current = env.get(key)
        if not current or not pathlib.Path(current).expanduser().is_dir():
            env[key] = str(tmp_root)
    return env


def run_sta(
    run_dir: pathlib.Path,
    *,
    env: dict[str, str],
    design: str,
    vfile: pathlib.Path,
) -> FlowResult:
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
    verify_module_name(result_dir / "yosys.log", design)
    verify_no_latch(result_dir / "synth_stat.txt")
    worst_slack_ns, fmax_mhz = parse_timing(rpt_path)
    return FlowResult(
        area=parse_area(log_path),
        worst_slack_ns=worst_slack_ns,
        fmax_mhz=fmax_mhz,
        result_dir=str(result_dir),
        netlist=str(result_dir / f"{design}.netlist.fixed.v"),
    )


def parse_area(log_path: pathlib.Path) -> float:
    text = require_file(log_path, "yosys-fixed log").read_text(encoding="utf-8")
    matches = AREA_RE.findall(text)
    if not matches:
        raise RuntimeError(f"can not obtain area from {log_path}")
    return float(matches[-1])


def parse_timing(rpt_path: pathlib.Path) -> tuple[float, float]:
    text = require_file(rpt_path, "STA report").read_text(encoding="utf-8")
    matches = TIMING_ROW_RE.findall(text)
    if not matches:
        raise RuntimeError(f"can not obtain timing summary from {rpt_path}")
    slacks = [float(slack) for slack, _ in matches]
    freqs = [float(freq) for _, freq in matches]
    return min(slacks), min(freqs)


def verify_module_name(log_path: pathlib.Path, design: str) -> None:
    text = require_file(log_path, "yosys log").read_text(encoding="utf-8")
    frontend_done = "Successfully finished Verilog frontend."
    end_idx = text.find(frontend_done)
    if end_idx < 0:
        raise RuntimeError(f"can not find frontend marker in {log_path}")
    checked = text[:end_idx]
    bad_modules = [name for name in MODULE_RE.findall(checked) if not name.startswith(design)]
    if bad_modules:
        raise RuntimeError(f"there exist modules which do not start with {design}: {bad_modules}")


def verify_no_latch(stat_path: pathlib.Path) -> None:
    text = require_file(stat_path, "synth_stat").read_text(encoding="utf-8")
    if "DLL" in text or "DLH" in text:
        raise RuntimeError("the design contains latch, which is not allowed")


def revert_old_flow(run_dir: pathlib.Path, commit: str) -> None:
    run(["git", "-C", str(run_dir), "config", "user.email", "ci@ysyx.org"])
    run(["git", "-C", str(run_dir), "config", "user.name", "ysyx-ci"])
    run(["git", "-C", str(run_dir), "revert", "--no-edit", commit])


def save_new_flow_result(run_dir: pathlib.Path, design: str, flow: FlowResult) -> FlowResult:
    src = pathlib.Path(flow.result_dir)
    dst = run_dir / "saved-result" / f"{design}-500MHz.new-flow"
    if dst.exists():
        shutil.rmtree(dst)
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copytree(src, dst)
    return FlowResult(
        area=flow.area,
        worst_slack_ns=flow.worst_slack_ns,
        fmax_mhz=flow.fmax_mhz,
        result_dir=str(dst),
        netlist=str(dst / pathlib.Path(flow.netlist).name),
    )


def copy_output(src: pathlib.Path, dst: pathlib.Path) -> pathlib.Path:
    dst = dst.expanduser().resolve()
    dst.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(src, dst)
    return dst


def maybe_write_json(summary: Summary, json_out: pathlib.Path | None) -> None:
    if json_out is None:
        return
    json_out.parent.mkdir(parents=True, exist_ok=True)
    json_out.write_text(json.dumps(asdict(summary), indent=2) + "\n", encoding="utf-8")


def print_summary(summary: Summary) -> None:
    print(f"design         : {summary.design}")
    print(f"vfile          : {summary.vfile}")
    print(f"output netlist : {summary.output_netlist}")
    print(f"new area       : {summary.area_fixed:.6f}")
    print(f"new slack      : {summary.new_worst_slack_ns:.3f} ns")
    print(f"new fmax       : {summary.new_fmax_mhz:.3f} MHz")
    print(f"old area       : {summary.area_old:.6f}")
    print(f"old slack      : {summary.old_worst_slack_ns:.3f} ns")
    print(f"old fmax       : {summary.old_fmax_mhz:.3f} MHz")
    print(f"new flow dir   : {summary.new_flow_result_dir}")
    print(f"old flow dir   : {summary.old_flow_result_dir}")
    print(f"oss-cad-suite  : {summary.oss_cad_suite}")
    print(f"yosys-sta cache: {summary.yosys_sta_cache}")
    if summary.run_dir:
        print(f"run dir        : {summary.run_dir}")


def main() -> int:
    args = parse_args()
    workbench, npc_home = resolve_paths(args)
    ci_repo = args.ci_repo.expanduser().resolve()
    spec = load_ci_spec(ci_repo)
    tool_home = args.tool_home.expanduser().resolve()
    stuid = read_stuid(workbench)
    design = f"ysyx_{stuid}"

    if args.refresh_verilog:
        ensure_verilog(npc_home)

    if args.vfile is not None:
        vfile = require_file(args.vfile, "explicit build Verilog")
    else:
        vfile = choose_vfile(npc_home, design)

    oss_cad_suite = prepare_oss_cad_suite(tool_home, spec, args.oss_cad_suite)
    cache_dir = (
        args.yosys_sta_cache.expanduser().resolve()
        if args.yosys_sta_cache is not None
        else tool_home / f"yosys-sta-{spec.yosys_sta_branch}"
    )
    ensure_yosys_sta_cache(cache_dir, spec.yosys_sta_branch)
    env = build_env(oss_cad_suite)

    run_dir: pathlib.Path | None = None
    try:
        run_dir = make_temp_clone(cache_dir, spec.yosys_sta_branch)
        new_flow = run_sta(run_dir, env=env, design=design, vfile=vfile)
        new_flow = save_new_flow_result(run_dir, design, new_flow)

        revert_old_flow(run_dir, spec.yosys_sta_revert_commit)
        old_flow = run_sta(run_dir, env=env, design=design, vfile=vfile)

        generated_netlist = require_file(pathlib.Path(old_flow.netlist), "generated netlist")
        output_netlist = copy_output(
            generated_netlist,
            args.output_netlist if args.output_netlist is not None else workbench / ".tmp" / generated_netlist.name,
        )
        summary = Summary(
            design=design,
            vfile=str(vfile),
            output_netlist=str(output_netlist),
            area_fixed=new_flow.area,
            area_old=old_flow.area,
            new_worst_slack_ns=new_flow.worst_slack_ns,
            new_fmax_mhz=new_flow.fmax_mhz,
            old_worst_slack_ns=old_flow.worst_slack_ns,
            old_fmax_mhz=old_flow.fmax_mhz,
            new_flow_result_dir=new_flow.result_dir,
            old_flow_result_dir=old_flow.result_dir,
            run_dir=str(run_dir) if args.keep_run_dir else None,
            tool_home=str(tool_home),
            oss_cad_suite=str(oss_cad_suite),
            yosys_sta_cache=str(cache_dir),
        )
        print_summary(summary)
        maybe_write_json(summary, args.json_out.expanduser().resolve() if args.json_out else None)
        return 0
    finally:
        if run_dir is not None and run_dir.exists() and not args.keep_run_dir:
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
