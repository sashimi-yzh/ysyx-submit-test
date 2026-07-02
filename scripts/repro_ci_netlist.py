#!/usr/bin/env python3

from __future__ import annotations

import argparse
import dataclasses
import datetime as dt
import json
import os
import pathlib
import re
import shlex
import shutil
import subprocess
import sys
import tempfile
import urllib.request
from typing import Any


REPO_ROOT = pathlib.Path(__file__).resolve().parents[1]
DEFAULT_CI_REPO = pathlib.Path("/home/ecall73/ysyx-submit-test")
WORKFLOW_REL = pathlib.Path(".github/workflows/autotest.yml")
MONITOR_REL = pathlib.Path("monitor.py")
STUID_RE = re.compile(r"^\s*STUID\s*=\s*ysyx_(\d{8})\s*$", re.MULTILINE)
TRACER_COMPILE_RE = re.compile(r"compile NEMU - (\d+)")
TRACER_RUN_RE = re.compile(r"run NEMU - (\d+)")
TRACER_SIM_RTL_RE = re.compile(r"sim RTL - (\d+)")
TOP_AREA_RE = re.compile(r"Chip area for module '\\ysyx_(\d{8})': ([0-9.]+)")
FANOUT_NET_RE = re.compile(r"Find (\d+) Net with fanout violation")
FANOUT_BUF_RE = re.compile(r"Insert (\d+) Buffers")
AREA_ENV_RE = re.compile(r"\bAREA:\s*([0-9.]+)")
AREA_OLD_ENV_RE = re.compile(r"\bAREA_OLD:\s*([0-9.]+)")
RELEASE_TAG_RE = re.compile(r"OSS_CAD_SUITE_RELEASE_TAG:\s*([0-9-]+)")
YOSYS_STA_BRANCH_RE = re.compile(r"git clone -b ([^\s]+) https://github\.com/OSCPU/yosys-sta")
YOSYS_STA_REVERT_RE = re.compile(r"git revert --no-edit ([0-9a-f]{40})")


@dataclasses.dataclass
class CiRunConfig:
    makejobs: int
    parallel: bool


@dataclasses.dataclass
class CiSpec:
    oss_cad_suite_release_tag: str
    yosys_sta_branch: str
    yosys_sta_revert_commit: str


@dataclasses.dataclass
class TargetContext:
    stuid: str
    repo_url: str
    branch: str
    commit: str


@dataclasses.dataclass
class SetupOutputs:
    ysyx_home_suffix: str
    vfile_suffix: str
    workbench_artifact: str
    target_repo_commit: str
    tracer_compile_nemu: int
    tracer_run_nemu: int
    tracer_sim_rtl: int


@dataclasses.dataclass
class YosysMetrics:
    area_first: float
    fanout_nets: int
    inserted_buffers: int
    area_fixed: float
    area_old: float


@dataclasses.dataclass
class CommandResult:
    output: str
    returncode: int


class StageError(RuntimeError):
    pass


class StageLogger:
    def __init__(self, path: pathlib.Path, *, mirror_stream: Any | None = None) -> None:
        self.path = path
        self.path.parent.mkdir(parents=True, exist_ok=True)
        self._fp = path.open("w", encoding="utf-8")
        self._mirror_stream = mirror_stream

    def close(self) -> None:
        self._fp.close()

    def _stamp(self) -> str:
        return dt.datetime.now(dt.timezone.utc).isoformat(timespec="microseconds").replace("+00:00", "Z")

    def line(self, text: str = "") -> None:
        rendered = f"{self._stamp()} {text}"
        self._fp.write(f"{rendered}\n")
        self._fp.flush()
        if self._mirror_stream is not None:
            self._mirror_stream.write(f"{rendered}\n")
            self._mirror_stream.flush()

    def group(self, title: str) -> None:
        self.line(f"##[group]Run {title}")

    def endgroup(self) -> None:
        self.line("##[endgroup]")


def read_text(path: pathlib.Path) -> str:
    return path.read_text(encoding="utf-8")


def must_capture(pattern: re.Pattern[str], text: str, desc: str) -> str:
    match = pattern.search(text)
    if not match:
        raise StageError(f"missing {desc}")
    if match.groups():
        return match.group(1)
    return match.group(0)


def first_match(pattern: re.Pattern[str], text: str, desc: str) -> re.Match[str]:
    match = pattern.search(text)
    if not match:
        raise StageError(f"missing {desc}")
    return match


def require_path(path: pathlib.Path, desc: str) -> pathlib.Path:
    if not path.exists():
        raise StageError(f"missing {desc}: {path}")
    return path


def ensure_clean_dir(path: pathlib.Path) -> None:
    if path.exists():
        shutil.rmtree(path)
    path.mkdir(parents=True, exist_ok=True)


def copytree(src: pathlib.Path, dst: pathlib.Path) -> None:
    if dst.exists():
        shutil.rmtree(dst)
    shutil.copytree(src, dst, symlinks=True)


def shell_quote(path: pathlib.Path | str) -> str:
    return shlex.quote(str(path))


def git_https_rewrite_env() -> list[str]:
    return [
        "export GIT_CONFIG_COUNT=1",
        "export GIT_CONFIG_KEY_0=url.https://github.com/.insteadOf",
        "export GIT_CONFIG_VALUE_0=git@github.com:",
    ]


def git_ci_identity_lines() -> list[str]:
    return [
        'git config user.email "ci@ysyx.org"',
        'git config user.name "ysyx-ci"',
    ]


def run_process(
    logger: StageLogger,
    title: str,
    script: str,
    *,
    cwd: pathlib.Path,
    env: dict[str, str],
    check: bool = True,
) -> CommandResult:
    logger.group(title)
    for line in script.strip().splitlines():
        logger.line(f"\x1b[36;1m{line}\x1b[0m")
    logger.line("shell: /usr/bin/bash -e {0}")
    logger.line("env:")
    for key in (
        "OSS_CAD_SUITE_RELEASE_TAG",
        "TEST_CI",
        "STUID",
        "YSYX_HOME",
        "NEMU_HOME",
        "AM_HOME",
        "NAVY_HOME",
        "NPC_HOME",
        "NVBOARD_HOME",
        "MAKEFLAGS",
        "MONITOR_PY",
        "PATH",
    ):
        if key in env:
            logger.line(f"  {key}: {env[key]}")
    logger.endgroup()

    proc = subprocess.Popen(
        ["bash", "-lc", script],
        cwd=str(cwd),
        env=env,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        text=True,
        bufsize=1,
    )
    assert proc.stdout is not None
    out_lines: list[str] = []
    for raw_line in proc.stdout:
        line = raw_line.rstrip("\n")
        logger.line(line)
        out_lines.append(line)
    ret = proc.wait()
    output = "\n".join(out_lines)
    if out_lines:
        output += "\n"
    if check and ret != 0:
        raise StageError(f"command failed with exit code {ret}: {title}")
    return CommandResult(output=output, returncode=ret)


def run_short(args: list[str], *, cwd: pathlib.Path | None = None) -> str:
    proc = subprocess.run(
        args,
        cwd=None if cwd is None else str(cwd),
        text=True,
        stdout=subprocess.PIPE,
        stderr=subprocess.STDOUT,
        check=True,
    )
    return proc.stdout.strip()


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Reproduce the CI path parse -> setup -> yosys-sta -> iverilog-netlist-microbench under /tmp."
    )
    parser.add_argument("--ci-repo", type=pathlib.Path, default=DEFAULT_CI_REPO)
    parser.add_argument(
        "--parallel",
        action="store_true",
        help="Use nproc for MAKEFLAGS, matching the CI parallel=true path. The default mimics workflow_dispatch with MAKEJOBS=1.",
    )
    parser.add_argument(
        "--makejobs",
        type=int,
        help="Explicit MAKEJOBS override. If omitted, use 1 or nproc when --parallel is set.",
    )
    parser.add_argument(
        "--oss-cad-suite",
        type=pathlib.Path,
        help="Optional preexisting oss-cad-suite root. If omitted, download the exact CI release into /tmp.",
    )
    parser.add_argument("--run-root", type=pathlib.Path)
    parser.add_argument(
        "--cleanup",
        action="store_true",
        help="Delete the /tmp run root on success. By default the run directory is kept for inspection.",
    )
    parser.add_argument(
        "--quiet",
        action="store_true",
        help="Do not mirror stage logs to the terminal; only write them to the per-stage log files.",
    )
    return parser.parse_args()


def make_ci_config(args: argparse.Namespace) -> CiRunConfig:
    if args.makejobs is not None:
        if args.makejobs < 1:
            raise StageError("--makejobs must be >= 1")
        return CiRunConfig(makejobs=args.makejobs, parallel=args.makejobs != 1)

    if args.parallel:
        return CiRunConfig(makejobs=os.cpu_count() or 1, parallel=True)
    return CiRunConfig(makejobs=1, parallel=False)


def load_ci_spec(ci_repo: pathlib.Path) -> CiSpec:
    workflow_text = read_text(require_path(ci_repo / WORKFLOW_REL, "CI workflow"))
    return CiSpec(
        oss_cad_suite_release_tag=must_capture(RELEASE_TAG_RE, workflow_text, "OSS_CAD_SUITE_RELEASE_TAG"),
        yosys_sta_branch=must_capture(YOSYS_STA_BRANCH_RE, workflow_text, "yosys-sta branch"),
        yosys_sta_revert_commit=must_capture(YOSYS_STA_REVERT_RE, workflow_text, "yosys-sta revert commit"),
    )


def resolve_target_context(repo_root: pathlib.Path) -> TargetContext:
    makefile_text = read_text(require_path(repo_root / "Makefile", "workspace Makefile"))
    stuid = must_capture(STUID_RE, makefile_text, "workspace STUID")
    repo_url = run_short(["git", "remote", "get-url", "origin"], cwd=repo_root)
    branch = "ci"
    ls_remote = run_short(["git", "ls-remote", "--heads", repo_url, branch], cwd=repo_root)
    if not ls_remote:
        raise StageError(f"can not resolve remote branch {branch} from {repo_url}")
    commit = ls_remote.split()[0]
    return TargetContext(stuid=stuid, repo_url=repo_url, branch=branch, commit=commit)


def make_run_root(run_root: pathlib.Path | None) -> pathlib.Path:
    if run_root is not None:
        ensure_clean_dir(run_root)
        return run_root
    return pathlib.Path(tempfile.mkdtemp(prefix="ysyx-ci-repro-", dir="/tmp"))


def prepare_oss_cad_suite(
    run_root: pathlib.Path,
    spec: CiSpec,
    override: pathlib.Path | None,
) -> pathlib.Path:
    if override is not None:
        return require_path(override, "explicit oss-cad-suite")

    tag = spec.oss_cad_suite_release_tag
    compact_tag = tag.replace("-", "")
    archive_name = f"oss-cad-suite-linux-x64-{compact_tag}.tgz"
    url = f"https://github.com/YosysHQ/oss-cad-suite-build/releases/download/{tag}/{archive_name}"

    toolchain_root = run_root / "toolchain"
    extract_root = toolchain_root / f"oss-cad-suite-{tag}"
    oss_root = extract_root / "oss-cad-suite"
    archive_path = toolchain_root / archive_name
    toolchain_root.mkdir(parents=True, exist_ok=True)

    if not archive_path.exists():
        urllib.request.urlretrieve(url, archive_path)
    if not oss_root.exists():
        extract_root.mkdir(parents=True, exist_ok=True)
        shutil.unpack_archive(str(archive_path), str(extract_root))

    require_path(oss_root / "bin" / "yosys", "downloaded yosys")
    require_path(oss_root / "bin" / "iverilog", "downloaded iverilog")
    require_path(oss_root / "bin" / "vvp", "downloaded vvp")
    return oss_root


def build_job_env(job_root: pathlib.Path, spec: CiSpec, oss_cad_suite: pathlib.Path) -> dict[str, str]:
    home = job_root / "home"
    temp_dir = job_root / "tmp"
    home.mkdir(parents=True, exist_ok=True)
    temp_dir.mkdir(parents=True, exist_ok=True)

    env = os.environ.copy()
    env["HOME"] = str(home)
    env["TMPDIR"] = str(temp_dir)
    env["TMP"] = str(temp_dir)
    env["TEMP"] = str(temp_dir)
    env["TEST_CI"] = "true"
    env["TZ"] = "Asia/Shanghai"
    env["OSS_CAD_SUITE_RELEASE_TAG"] = spec.oss_cad_suite_release_tag
    env["PATH"] = f"{home / '.local' / 'bin'}:{oss_cad_suite / 'bin'}:{env.get('PATH', '')}"
    for key in (
        "STUID",
        "YSYX_HOME",
        "NEMU_HOME",
        "AM_HOME",
        "NAVY_HOME",
        "NPC_HOME",
        "NVBOARD_HOME",
        "MONITOR_PY",
        "VFILE",
    ):
        env.pop(key, None)
    return env


def install_mill(logger: StageLogger, job_repo: pathlib.Path, env: dict[str, str], ysyx_home: pathlib.Path) -> None:
    mill_version = "0.11.13"
    mill_version_file = ysyx_home / "npc" / ".mill-version"
    if mill_version_file.exists():
        mill_version = mill_version_file.read_text(encoding="utf-8").strip()
    run_process(
        logger,
        "mkdir -p ~/.local/bin",
        "\n".join(
            [
                "mkdir -p ~/.local/bin",
                f'echo "Downloading mill with version {mill_version}"',
                f'curl -L "https://github.com/com-lihaoyi/mill/releases/download/{mill_version}/{mill_version}" -o ~/.local/bin/mill',
                "chmod +x ~/.local/bin/mill",
                "~/.local/bin/mill --version",
            ]
        ),
        cwd=job_repo,
        env=env,
    )


def verify_local_toolchain(logger: StageLogger, job_repo: pathlib.Path, env: dict[str, str]) -> None:
    run_process(
        logger,
        "command -v riscv64-linux-gnu-gcc riscv64-linux-gnu-g++",
        "\n".join(
            [
                'echo "Reuse local toolchain under the /tmp-only constraint."',
                "command -v riscv64-linux-gnu-gcc",
                "command -v riscv64-linux-gnu-g++",
                "command -v iverilog",
                "command -v vvp",
            ]
        ),
        cwd=job_repo,
        env=env,
    )


def copy_ci_repo(ci_repo: pathlib.Path, stage_root: pathlib.Path) -> pathlib.Path:
    job_repo = stage_root / ci_repo.name
    copytree(ci_repo, job_repo)
    return job_repo


def run_parse_stage(
    run_root: pathlib.Path,
    target: TargetContext,
    config: CiRunConfig,
    mirror_stream: Any | None,
) -> pathlib.Path:
    stage_root = run_root / "jobs" / "parse"
    ensure_clean_dir(stage_root)
    log_path = stage_root / "parse.log"
    logger = StageLogger(log_path, mirror_stream=mirror_stream)
    try:
        logger.line(f"STUID={target.stuid}")
        logger.line(f"REPO={target.repo_url}")
        logger.line(f"BRANCH={target.branch}")
        logger.line(f"TARGET_COMMIT={target.commit}")
        logger.line(f"MAKEJOBS={config.makejobs}")
        logger.line(f"PARALLEL={str(config.parallel).lower()}")
        logger.line("COMMENT=this reproducer follows the current origin/ci only")
    finally:
        logger.close()
    return log_path


def run_setup_stage(
    run_root: pathlib.Path,
    ci_repo: pathlib.Path,
    spec: CiSpec,
    config: CiRunConfig,
    target: TargetContext,
    oss_cad_suite: pathlib.Path,
    mirror_stream: Any | None,
) -> tuple[pathlib.Path, SetupOutputs]:
    stage_root = run_root / "jobs" / "setup"
    ensure_clean_dir(stage_root)
    job_repo = copy_ci_repo(ci_repo, stage_root)
    log_path = stage_root / "setup.log"
    logger = StageLogger(log_path, mirror_stream=mirror_stream)
    env = build_job_env(stage_root, spec, oss_cad_suite)
    try:
        temp_dir = pathlib.Path(tempfile.mkdtemp(prefix="tmp.", dir=job_repo))
        ysyx_home = temp_dir / "ysyx-workbench"
        ysyx_home_suffix = ysyx_home.relative_to(job_repo)

        run_process(
            logger,
            f"git clone --depth 1 -b {target.branch} {target.repo_url} ysyx-workbench",
            "\n".join(
                [
                    *git_https_rewrite_env(),
                    f"mkdir -p {shell_quote(ysyx_home)}",
                    f"cd {shell_quote(ysyx_home.parent)}",
                    f"git clone --depth 1 -b {shlex.quote(target.branch)} {shlex.quote(target.repo_url)} ysyx-workbench",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        cloned_commit = run_short(["git", "rev-parse", "HEAD"], cwd=ysyx_home)

        run_process(
            logger,
            "git checkout --orphan tmp-ci",
            "\n".join(
                [
                    f"cd {shell_quote(ysyx_home)}",
                    *git_ci_identity_lines(),
                    "git checkout --orphan tmp-ci",
                    'git commit -m "orphan branch created by CI"',
                    f"cd {shell_quote(ysyx_home.parent)}",
                    f"git clone -b tmp-ci file://{ysyx_home} ysyx-workbench-ci",
                    "rm -rf ysyx-workbench",
                    "mv ysyx-workbench-ci ysyx-workbench",
                    f"cd {shell_quote(ysyx_home)}",
                    f"git remote set-url origin {shlex.quote(target.repo_url)}",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        cloned_makefile = read_text(ysyx_home / "Makefile")
        cloned_stuid = must_capture(STUID_RE, cloned_makefile, "cloned workbench STUID")
        if cloned_stuid != target.stuid:
            raise StageError(f"STUID mismatch in cloned workbench: {cloned_stuid} != {target.stuid}")

        tracer_result = run_process(
            logger,
            "parse tracer-ysyx",
            "\n".join(
                [
                    f"cd {shell_quote(ysyx_home)}",
                    "git fetch origin tracer-ysyx:tracer-ysyx",
                    f"git log tracer-ysyx --author='tracer-ysyx <tracer@ysyx.org>' --grep='{target.stuid}' --oneline > log.txt",
                    "NR_COMPILE_NEMU=$(grep 'compile NEMU' log.txt | wc -l)",
                    "NR_RUN_NEMU=$(grep 'run NEMU' log.txt | wc -l)",
                    "NR_GDB_NEMU=$(grep 'gdb NEMU' log.txt | wc -l)",
                    "NR_SIM_RTL=$(grep 'sim RTL' log.txt | wc -l)",
                    'echo "compile NEMU - $NR_COMPILE_NEMU"',
                    'echo "run NEMU - $NR_RUN_NEMU"',
                    'echo "gdb NEMU - $NR_GDB_NEMU"',
                    'echo "sim RTL - $NR_SIM_RTL"',
                    'test "$NR_COMPILE_NEMU" -gt 0',
                    'test "$NR_RUN_NEMU" -gt 0',
                    'test "$NR_SIM_RTL" -gt 0',
                ]
            ),
            cwd=job_repo,
            env=env,
        )
        tracer_compile_nemu = int(must_capture(TRACER_COMPILE_RE, tracer_result.output, "current tracer compile count"))
        tracer_run_nemu = int(must_capture(TRACER_RUN_RE, tracer_result.output, "current tracer run count"))
        tracer_sim_rtl = int(must_capture(TRACER_SIM_RTL_RE, tracer_result.output, "current tracer sim RTL count"))

        env["STUID"] = target.stuid
        env["YSYX_HOME"] = str(ysyx_home)
        env["NEMU_HOME"] = str(ysyx_home / "nemu")
        env["AM_HOME"] = str(ysyx_home / "abstract-machine")
        env["NAVY_HOME"] = str(ysyx_home / "navy-apps")
        env["NPC_HOME"] = str(ysyx_home / "npc")
        env["NVBOARD_HOME"] = str(ysyx_home / "nvboard")
        env["MAKEFLAGS"] = f"-j{config.makejobs}"

        run_process(
            logger,
            'test -e "$AM_HOME/tools/insert-arg.py"',
            "\n".join(
                [
                    'test -e "$AM_HOME/tools/insert-arg.py"',
                    "sed -i -e 's/MAINARGS_PLACEHOLDER = .*/MAINARGS_PLACEHOLDER = the_insert-arg_rule_in_Makefile_will_insert_mainargs_here/' $AM_HOME/scripts/platform/npc.mk",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "disable git tracer",
            "\n".join(
                [
                    "cd $YSYX_HOME",
                    "echo '.git_commit:' >> Makefile",
                    "printf '\\t@echo git tracer is disabled\\n' >> Makefile",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "check patch size",
            "\n".join(
                [
                    "SIZE=$(du -sb $YSYX_HOME/patch | grep -o '^[0-9]*')",
                    'test "$SIZE" -le 1048576',
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        install_mill(logger, job_repo, env, ysyx_home)
        verify_local_toolchain(logger, job_repo, env)

        run_process(
            logger,
            "git ls-remote https://github.com/OSCPU/ysyxSoC.git ysyx6",
            "git ls-remote https://github.com/OSCPU/ysyxSoC.git ysyx6",
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "git clone --depth 1 -b ysyx6 https://github.com/OSCPU/ysyxSoC ysyxSoC-inited",
            "\n".join(
                [
                    *git_https_rewrite_env(),
                    "git clone --depth 1 -b ysyx6 https://github.com/OSCPU/ysyxSoC ysyxSoC-inited",
                    "cd ysyxSoC-inited",
                    *git_ci_identity_lines(),
                    "make dev-init",
                    "mill __.compile",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "patch ysyxSoC",
            "\n".join(
                [
                    "mkdir -p $YSYX_HOME/ysyxSoC",
                    "cp -a ysyxSoC-inited/. $YSYX_HOME/ysyxSoC/",
                    "cd $YSYX_HOME/ysyxSoC",
                    "git am $YSYX_HOME/patch/ysyxSoC/*",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "git clone --depth 1 -b no-gui https://github.com/NJU-ProjectN/nvboard",
            "\n".join(
                [
                    "cd $YSYX_HOME",
                    "git clone --depth 1 -b no-gui https://github.com/NJU-ProjectN/nvboard",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "make clean",
            "make -C $NEMU_HOME clean\nmake -C $AM_HOME clean-all\nmake -C $NPC_HOME clean",
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "make -C $NPC_HOME verilog",
            "touch $NPC_HOME/.timestamp\nmake -C $NPC_HOME verilog",
            cwd=job_repo,
            env=env,
        )

        vfile_sv = ysyx_home / "npc" / "build" / f"ysyx_{target.stuid}.sv"
        vfile_v = ysyx_home / "npc" / "build" / f"ysyx_{target.stuid}.v"
        vfile = vfile_sv if vfile_sv.exists() else vfile_v
        if not vfile.exists():
            raise StageError("setup did not produce the expected NPC verilog file")
        if (ysyx_home / "npc" / ".timestamp").stat().st_mtime > vfile.stat().st_mtime:
            raise StageError(f"{vfile} is older than .timestamp")
        logger.line(f"Find {vfile}")

        vfile_text = read_text(vfile)
        if f"module ysyx_{target.stuid}" not in vfile_text.replace("\n", " "):
            raise StageError(f"can not find module ysyx_{target.stuid} in {vfile}")
        if re.search(r"\bnegedge\b", vfile_text):
            raise StageError(f"{vfile} contains negedge")

        run_process(
            logger,
            "make -C $YSYX_HOME/ysyxSoC verilog",
            "make -C $YSYX_HOME/ysyxSoC verilog",
            cwd=job_repo,
            env=env,
        )

        artifacts_dir = run_root / "artifacts"
        artifacts_dir.mkdir(parents=True, exist_ok=True)
        workbench_artifact = artifacts_dir / "ysyx-workbench.tar.gz"
        run_process(
            logger,
            "pack workbench",
            "\n".join(
                [
                    f"cd {shell_quote(ysyx_home.parent)}",
                    f"tar -czf {shell_quote(workbench_artifact)} ysyx-workbench",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        setup_outputs = SetupOutputs(
            ysyx_home_suffix=str(ysyx_home_suffix),
            vfile_suffix=str(vfile.relative_to(ysyx_home)),
            workbench_artifact=str(workbench_artifact),
            target_repo_commit=cloned_commit,
            tracer_compile_nemu=tracer_compile_nemu,
            tracer_run_nemu=tracer_run_nemu,
            tracer_sim_rtl=tracer_sim_rtl,
        )
        return log_path, setup_outputs
    finally:
        logger.close()


def restore_workbench(
    logger: StageLogger,
    job_repo: pathlib.Path,
    env: dict[str, str],
    setup_outputs: SetupOutputs,
) -> pathlib.Path:
    ysyx_home = job_repo / setup_outputs.ysyx_home_suffix
    artifact = pathlib.Path(setup_outputs.workbench_artifact)
    require_path(artifact, "packed workbench artifact")
    ysyx_home.parent.mkdir(parents=True, exist_ok=True)
    run_process(
        logger,
        f"tar -xzf {artifact.name}",
        "\n".join(
            [
                f"cd {shell_quote(ysyx_home.parent)}",
                f"tar -xzf {shell_quote(artifact)}",
            ]
        ),
        cwd=job_repo,
        env=env,
    )
    return ysyx_home


def populate_common_env(env: dict[str, str], job_repo: pathlib.Path, ysyx_home: pathlib.Path, makejobs: int, stuid: str) -> None:
    env["STUID"] = stuid
    env["MONITOR_PY"] = str(job_repo / MONITOR_REL)
    env["YSYX_HOME"] = str(ysyx_home)
    env["NEMU_HOME"] = str(ysyx_home / "nemu")
    env["AM_HOME"] = str(ysyx_home / "abstract-machine")
    env["NAVY_HOME"] = str(ysyx_home / "navy-apps")
    env["NPC_HOME"] = str(ysyx_home / "npc")
    env["NVBOARD_HOME"] = str(ysyx_home / "nvboard")
    env["MAKEFLAGS"] = f"-j{makejobs}"


def run_common_stage(
    logger: StageLogger,
    job_repo: pathlib.Path,
    env: dict[str, str],
    ysyx_home: pathlib.Path,
    install_toolchain: bool,
) -> None:
    install_mill(logger, job_repo, env, ysyx_home)
    if install_toolchain:
        verify_local_toolchain(logger, job_repo, env)

    run_process(
        logger,
        "clone other repos",
        "\n".join(
            [
                "cd $YSYX_HOME",
                "git clone --depth 1 -b ci https://github.com/NJU-ProjectN/am-kernels",
                "git clone --depth 1 https://github.com/NJU-ProjectN/rt-thread-am",
                "cd rt-thread-am",
                *git_ci_identity_lines(),
                "git am $YSYX_HOME/patch/rt-thread-am/*",
                "cd $YSYX_HOME",
            ]
        ),
        cwd=job_repo,
        env=env,
    )


def collect_yosys_metrics(log_text: str, stuid: str) -> YosysMetrics:
    top_areas = list(TOP_AREA_RE.finditer(log_text))
    if not top_areas:
        raise StageError("yosys stage log does not contain any top-level area")

    current_area_match = first_match(AREA_ENV_RE, log_text, "current AREA")
    old_area_match = first_match(AREA_OLD_ENV_RE, log_text, "current AREA_OLD")
    fanout_match = first_match(FANOUT_NET_RE, log_text, "current fanout net count")
    buffer_match = first_match(FANOUT_BUF_RE, log_text, "current inserted buffer count")
    first_top_area = None
    for match in top_areas:
        if match.group(1) == stuid:
            first_top_area = float(match.group(2))
            break
    if first_top_area is None:
        raise StageError("yosys stage log does not contain the expected STUID top-level area")

    return YosysMetrics(
        area_first=first_top_area,
        fanout_nets=int(fanout_match.group(1)),
        inserted_buffers=int(buffer_match.group(1)),
        area_fixed=float(current_area_match.group(1)),
        area_old=float(old_area_match.group(1)),
    )


def run_yosys_stage(
    run_root: pathlib.Path,
    ci_repo: pathlib.Path,
    spec: CiSpec,
    config: CiRunConfig,
    target: TargetContext,
    setup_outputs: SetupOutputs,
    oss_cad_suite: pathlib.Path,
    mirror_stream: Any | None,
) -> tuple[pathlib.Path, YosysMetrics, pathlib.Path]:
    stage_root = run_root / "jobs" / "yosys-sta"
    ensure_clean_dir(stage_root)
    job_repo = copy_ci_repo(ci_repo, stage_root)
    log_path = stage_root / "yosys-sta.log"
    logger = StageLogger(log_path, mirror_stream=mirror_stream)
    env = build_job_env(stage_root, spec, oss_cad_suite)
    try:
        ysyx_home = restore_workbench(logger, job_repo, env, setup_outputs)
        populate_common_env(env, job_repo, ysyx_home, config.makejobs, target.stuid)
        run_common_stage(logger, job_repo, env, ysyx_home, install_toolchain=False)

        run_process(
            logger,
            f"git clone -b {spec.yosys_sta_branch} https://github.com/OSCPU/yosys-sta",
            "\n".join(
                [
                    f"git clone -b {shlex.quote(spec.yosys_sta_branch)} https://github.com/OSCPU/yosys-sta",
                    "cd yosys-sta",
                    "make init",
                    "echo exit | ./bin/iEDA -v",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "make -C $NPC_HOME verilog",
            "make -C $NPC_HOME verilog",
            cwd=job_repo,
            env=env,
        )

        vfile = ysyx_home / setup_outputs.vfile_suffix
        require_path(vfile, "setup VFILE")
        env["VFILE"] = str(vfile)

        run_process(
            logger,
            "make -C yosys-sta sta DESIGN=ysyx_$STUID CLK_FREQ_MHZ=500 CLK_PORT_NAME=clock RTL_FILES=$VFILE",
            "make -C yosys-sta sta DESIGN=ysyx_$STUID CLK_FREQ_MHZ=500 CLK_PORT_NAME=clock RTL_FILES=$VFILE",
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "check yosys verilog module names",
            "\n".join(
                [
                    "YOSYS_LOG=yosys-sta/result/ysyx_$STUID-500MHz/yosys.log",
                    "LINE=$(grep -n 'Successfully finished Verilog frontend' $YOSYS_LOG | head -n 1 | grep -o '^[0-9]*')",
                    'if head -n $LINE $YOSYS_LOG | grep "Generating RTLIL representation for module" | grep -v "ysyx_$STUID"; then',
                    '  echo "There exist modules which do not start with ysyx_$STUID"',
                    "  false",
                    "fi",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "check latch",
            "\n".join(
                [
                    "YOSYS_LOG=yosys-sta/result/ysyx_$STUID-500MHz/synth_stat.txt",
                    "if grep 'DLL\\|DLH' $YOSYS_LOG; then",
                    "  echo 'The design contains latch, which is not allowed.'",
                    "  false",
                    "fi",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "parse area",
            "\n".join(
                [
                    "YOSYS_LOG=yosys-sta/result/ysyx_$STUID-500MHz/yosys-fixed.log",
                    "AREA=$(grep -o 'Chip area for module .*: .*' $YOSYS_LOG | sed -e 's/.*: \\([0-9]*\\.[0-9]*\\)$/\\1/')",
                    'test "$AREA" != ""',
                    'printf "%s\\n" "$AREA" > .ci-area-current.txt',
                    'echo "AREA: $AREA"',
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            f"git revert --no-edit {spec.yosys_sta_revert_commit}",
            "\n".join(
                [
                    "cd yosys-sta",
                    *git_ci_identity_lines(),
                    f"git revert --no-edit {spec.yosys_sta_revert_commit}",
                    "make clean",
                    "make sta DESIGN=ysyx_$STUID CLK_FREQ_MHZ=500 CLK_PORT_NAME=clock RTL_FILES=$VFILE",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "parse area with older version",
            "\n".join(
                [
                    "YOSYS_LOG=yosys-sta/result/ysyx_$STUID-500MHz/yosys-fixed.log",
                    "AREA_OLD=$(grep -o 'Chip area for module .*: .*' $YOSYS_LOG | sed -e 's/.*: \\([0-9]*\\.[0-9]*\\)$/\\1/')",
                    'test "$AREA_OLD" != ""',
                    'printf "%s\\n" "$AREA_OLD" > .ci-area-old.txt',
                    'echo "AREA_OLD: $AREA_OLD"',
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "check area",
            "\n".join(
                [
                    "AREA_BUDGET=16500",
                    "AREA_OLD_BUDGET=25000",
                    "AREA=$(cat .ci-area-current.txt)",
                    "AREA_OLD=$(cat .ci-area-old.txt)",
                    "if [ $(awk \"BEGIN {print ($AREA > $AREA_BUDGET)}\") -eq 1 ]; then",
                    "  if [ $(awk \"BEGIN {print ($AREA_OLD > $AREA_OLD_BUDGET)}\") -eq 1 ]; then",
                    '    echo "Area($AREA) is larger than the budget($AREA_BUDGET)."',
                    '    echo "Area for old version of yosys-sta($AREA_OLD) is larger than the budget($AREA_OLD_BUDGET)."',
                    "    false",
                    "  fi",
                    "fi",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        log_text = read_text(log_path)
        metrics = collect_yosys_metrics(log_text, target.stuid)

        netlist_path = job_repo / "yosys-sta" / "result" / f"ysyx_{target.stuid}-500MHz" / f"ysyx_{target.stuid}.netlist.fixed.v"
        require_path(netlist_path, "uploaded netlist artifact from reverted yosys-sta")
        artifact_path = run_root / "artifacts" / netlist_path.name
        shutil.copy2(netlist_path, artifact_path)
        return log_path, metrics, artifact_path
    finally:
        logger.close()


def run_netlist_stage(
    run_root: pathlib.Path,
    ci_repo: pathlib.Path,
    spec: CiSpec,
    config: CiRunConfig,
    target: TargetContext,
    setup_outputs: SetupOutputs,
    netlist_artifact: pathlib.Path,
    oss_cad_suite: pathlib.Path,
    mirror_stream: Any | None,
) -> tuple[pathlib.Path, int]:
    stage_root = run_root / "jobs" / "iverilog-netlist-microbench"
    ensure_clean_dir(stage_root)
    job_repo = copy_ci_repo(ci_repo, stage_root)
    log_path = stage_root / "iverilog-netlist-microbench.log"
    logger = StageLogger(log_path, mirror_stream=mirror_stream)
    env = build_job_env(stage_root, spec, oss_cad_suite)
    try:
        ysyx_home = restore_workbench(logger, job_repo, env, setup_outputs)
        populate_common_env(env, job_repo, ysyx_home, config.makejobs, target.stuid)
        run_common_stage(logger, job_repo, env, ysyx_home, install_toolchain=True)

        downloaded_netlist = job_repo / netlist_artifact.name
        shutil.copy2(netlist_artifact, downloaded_netlist)
        logger.line(f"Downloaded netlist artifact to {downloaded_netlist}")

        run_process(
            logger,
            f"git clone -b {spec.yosys_sta_branch} https://github.com/OSCPU/yosys-sta",
            "\n".join(
                [
                    f"git clone -b {shlex.quote(spec.yosys_sta_branch)} https://github.com/OSCPU/yosys-sta",
                    "cd yosys-sta",
                    "make init",
                    "echo exit | ./bin/iEDA -v",
                ]
            ),
            cwd=job_repo,
            env=env,
        )

        run_process(
            logger,
            "make ARCH=riscv32e-npc -C $YSYX_HOME/am-kernels/benchmarks/microbench mainargs=the_insert-arg_rule_in_Makefile_will_insert_mainargs_here",
            "make ARCH=riscv32e-npc -C $YSYX_HOME/am-kernels/benchmarks/microbench mainargs=the_insert-arg_rule_in_Makefile_will_insert_mainargs_here",
            cwd=job_repo,
            env=env,
        )

        sim_result = run_process(
            logger,
            "python $MONITOR_PY --good=$KEY make -C $NPC_HOME sim-iverilog-netlist IMG=$IMG NETLIST=$NETLIST CELLS=$CELLS",
            "\n".join(
                [
                    "make -C $NPC_HOME clean",
                    "NETLIST=$(pwd)/" + netlist_artifact.name,
                    "CELLS=$(pwd)/yosys-sta/pdk/nangate45/sim/cells.v",
                    "KEY=$(head -c 5 /dev/urandom | base32)",
                    "IMG=$YSYX_HOME/am-kernels/benchmarks/microbench/build/microbench-riscv32e-npc.bin",
                    "python $AM_HOME/tools/insert-arg.py $IMG 64 the_insert-arg_rule_in_Makefile_will_insert_mainargs_here $KEY",
                    "python $MONITOR_PY --good=$KEY make -C $NPC_HOME sim-iverilog-netlist IMG=$IMG NETLIST=$NETLIST CELLS=$CELLS",
                ]
            ),
            cwd=job_repo,
            env=env,
            check=False,
        )

        return log_path, sim_result.returncode
    finally:
        logger.close()


def write_summary(
    run_root: pathlib.Path,
    target: TargetContext,
    spec: CiSpec,
    config: CiRunConfig,
    setup_outputs: SetupOutputs,
    yosys_metrics: YosysMetrics,
    netlist_stage_exit: int,
    logs: dict[str, str],
    netlist_artifact: pathlib.Path,
) -> pathlib.Path:
    summary_path = run_root / "summary.json"
    data = {
        "run_root": str(run_root),
        "target": dataclasses.asdict(target),
        "ci_spec": dataclasses.asdict(spec),
        "config": dataclasses.asdict(config),
        "setup_outputs": dataclasses.asdict(setup_outputs),
        "yosys_metrics": dataclasses.asdict(yosys_metrics),
        "netlist_stage_exit": netlist_stage_exit,
        "netlist_artifact": str(netlist_artifact),
        "logs": logs,
    }
    summary_path.write_text(json.dumps(data, indent=2, sort_keys=True), encoding="utf-8")
    return summary_path


def main() -> int:
    args = parse_args()
    ci_repo = require_path(args.ci_repo, "CI repo")
    require_path(ci_repo / MONITOR_REL, "CI monitor.py")

    spec = load_ci_spec(ci_repo)
    config = make_ci_config(args)
    target = resolve_target_context(REPO_ROOT)

    run_root = make_run_root(args.run_root)
    oss_cad_suite = prepare_oss_cad_suite(run_root, spec, args.oss_cad_suite)
    mirror_stream = None if args.quiet else sys.stdout
    parse_log = run_parse_stage(run_root, target, config, mirror_stream)

    setup_log, setup_outputs = run_setup_stage(
        run_root=run_root,
        ci_repo=ci_repo,
        spec=spec,
        config=config,
        target=target,
        oss_cad_suite=oss_cad_suite,
        mirror_stream=mirror_stream,
    )

    yosys_log, yosys_metrics, netlist_artifact = run_yosys_stage(
        run_root=run_root,
        ci_repo=ci_repo,
        spec=spec,
        config=config,
        target=target,
        setup_outputs=setup_outputs,
        oss_cad_suite=oss_cad_suite,
        mirror_stream=mirror_stream,
    )

    netlist_log, netlist_stage_exit = run_netlist_stage(
        run_root=run_root,
        ci_repo=ci_repo,
        spec=spec,
        config=config,
        target=target,
        setup_outputs=setup_outputs,
        netlist_artifact=netlist_artifact,
        oss_cad_suite=oss_cad_suite,
        mirror_stream=mirror_stream,
    )

    summary_path = write_summary(
        run_root=run_root,
        target=target,
        spec=spec,
        config=config,
        setup_outputs=setup_outputs,
        yosys_metrics=yosys_metrics,
        netlist_stage_exit=netlist_stage_exit,
        logs={
            "parse": str(parse_log),
            "setup": str(setup_log),
            "yosys-sta": str(yosys_log),
            "iverilog-netlist-microbench": str(netlist_log),
        },
        netlist_artifact=netlist_artifact,
    )

    print(f"run_root={run_root}")
    print(f"target_repo={target.repo_url}")
    print(f"target_branch={target.branch}")
    print(f"target_commit={target.commit}")
    print(f"summary={summary_path}")
    print(f"netlist_stage_exit={netlist_stage_exit}")
    print(f"completed={1 if netlist_stage_exit == 0 else 0}")

    if args.cleanup and netlist_stage_exit == 0:
        shutil.rmtree(run_root)
    return netlist_stage_exit


if __name__ == "__main__":
    try:
        raise SystemExit(main())
    except StageError as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        raise SystemExit(1)
