# 脚本说明

这个目录放的是一些本地辅助脚本，主要用于准备 CI 所需文件，以及在本机快速做 CI 等效检查。

## `gen_ci_patches.py`

功能：
- 生成 CI 所需的 `patch/rt-thread-am/` 和 `patch/ysyxSoC/` 补丁
- 在导出 `ysyxSoC` 补丁前，先刷新 `ysyxSoC/patch/rocket-chip.patch`

用法：

```bash
cd ~/ysyx-workbench
python3 scripts/gen_ci_patches.py
```

如果只想生成其中一个项目的补丁：

```bash
python3 scripts/gen_ci_patches.py --project rt-thread-am
python3 scripts/gen_ci_patches.py --project ysyxSoC
```

输出位置：
- `patch/rt-thread-am/0001-*.patch`
- `patch/ysyxSoC/0001-*.patch`

## `eval_ci_area.py`

功能：
- 在本机执行一套与当前 CI `yosys-sta` 流程等效的面积评估
- 自动从 CI workflow 中读取 `yosys-sta` 分支、`revert` 提交和面积门限
- 同时跑新 flow 和旧 flow，并给出最终的 CI 通过/失败结论

默认假设：
- `ysyx-workbench` 就是当前 `scripts/` 所在仓库根目录
- CI 仓库默认在同级目录 `~/ysyx-submit-test`
- Yosys 默认使用 `~/oss-cad-suite/bin/yosys`

用法：

```bash
cd ~/ysyx-workbench
python3 scripts/eval_ci_area.py
```

如果 CI 仓库不在默认位置，可以手动指定：

```bash
python3 scripts/eval_ci_area.py --ci-repo ~/ysyx-submit-test
```

如果希望保留运行目录并导出 JSON 摘要：

```bash
python3 scripts/eval_ci_area.py \
  --keep-run-dir \
  --json-out /tmp/ysyx-ci-area.json
```

常用参数：
- `--workbench`：指定 workbench 根目录
- `--npc-home`：指定 NPC 目录
- `--stuid`：手动指定学号，覆盖从 `Makefile` 自动解析的结果
- `--yosys-bin`：指定使用的 Yosys 可执行文件
- `--cache-dir`：指定 `yosys-sta` 本地缓存目录

## `repro_ci_netlist.py`

功能：
- 严格按 `parse -> setup -> yosys-sta -> iverilog-netlist-microbench` 复刻当前 `origin/ci`
- 输出 `yosys-sta` 指标和 netlist 仿真指纹，便于和历史结果人工对照
- 默认实时把每阶段 log 输出到命令行，同时仍然落盘到 `/tmp/.../*.log`

用法：

```bash
cd ~/ysyx-workbench
python3 scripts/repro_ci_netlist.py --run-root /tmp/ysyx-ci-repro-cli
```

如果只想写日志文件、不在终端实时打印：

```bash
python3 scripts/repro_ci_netlist.py --run-root /tmp/ysyx-ci-repro-cli --quiet
```

## `gen_ci_aligned_netlist.py`

功能：
- 直接使用本地 `npc/build/ysyx_<stuid>.v` 或 `.sv` 做 `yosys-sta`
- 自动准备 `~/ysyx-ci-tools/` 下的 CI 指定 `oss-cad-suite` 和 `yosys-sta` 缓存
- 同时跑新 flow 和 `revert` 后的旧 flow
- 导出最终 `ysyx_<stuid>.netlist.fixed.v`
- 输出两轮面积结果以及对应结果目录，便于后续实时评估和人工对照

用法：

```bash
cd ~/ysyx-workbench
python3 scripts/gen_ci_aligned_netlist.py
```

默认输出：
- 网表：`~/ysyx-workbench/.tmp/ysyx_<stuid>.netlist.fixed.v`
- 工具缓存：`~/ysyx-ci-tools/`

常用参数：
- `--refresh-verilog`：先重新执行 `make -C npc verilog`
- `--vfile <path>`：显式指定本地 build Verilog
- `--keep-run-dir`：保留临时 `yosys-sta` 运行目录
