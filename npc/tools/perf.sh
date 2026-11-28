#!/bin/bash
# npc/tools/perf.sh —— 跑一次 benchmark，把 perf 数据记到 npc/perf/
#
#   tools/perf.sh [-a mainargs] [-n bench]
#     -a  mainargs（默认 test，可选 train/ref...）
#     -n  am-kernels/benchmarks 下的目录名（默认 microbench）
#
# 产物：perf/<commit>_<mainargs>.txt —— 头部是 commit/时间，然后是 PASS、周期/IPC、
# 全部 [PERF] 计数器，末尾是 [AREA]/[TIME]（nangate45 @ 800MHz 的综合面积与时序）。
# 跑失败了就把完整输出存进去并标 FAIL，不丢信息。
#
# 环境变量：
#   PERF_STA=0  跳过综合/时序（make sta 自带增量依赖，RTL 没变时本来就是空转）
set -u
NPC=$(cd "$(dirname "$0")/.." && pwd)
YSYX=$(cd "$NPC/.." && pwd)
MAINARGS=test
BENCH=microbench
while getopts "a:n:h" o; do case $o in
  a) MAINARGS=$OPTARG;; n) BENCH=$OPTARG;;
  *) sed -n '2,12p' "$0"; exit 0;;
esac; done

BENCH_DIR=$BENCH
case $BENCH in /*) ;; *) BENCH_DIR=$YSYX/am-kernels/benchmarks/$BENCH;; esac
[ -d "$BENCH_DIR" ] || { echo "找不到 $BENCH_DIR" >&2; exit 1; }
mkdir -p "$NPC/perf"

# commit：当前分支当前的 HEAD；工作区有未提交改动就加 +dirty 后缀
C=$(git -C "$YSYX" rev-parse --short HEAD)
D=""
{ git -C "$YSYX" diff --quiet && git -C "$YSYX" diff --cached --quiet; } || D="+dirty"
REC=$NPC/perf/${C}${D}_${MAINARGS}.txt
TMP=$(mktemp)

echo "=== $(date '+%F %T')  $BENCH  mainargs=$MAINARGS ==="
( cd "$BENCH_DIR" && make ARCH=riscv32e-ysyxsoc run mainargs="$MAINARGS" ) 2>&1 | tee "$TMP"
RC=${PIPESTATUS[0]}

# 综合/时序：make sta 依赖 build/*.sv 与网表，RTL 没变时直接空转（秒级）
STA_LINES=""
if [ "${PERF_STA:-1}" != 0 ]; then
  echo "== 综合 + 时序（nangate45，增量）..."
  if ( cd "$NPC" && make sta ) > "$TMP.sta" 2>&1; then
    STA_LINES=$(python3 "$NPC/tools/sta_summary.py" "$NPC/result")
  else
    STA_LINES="[AREA] n/a（make sta 失败，见 result/*/sta.log）"
  fi
  [ -n "$STA_LINES" ] && echo "$STA_LINES"
fi

{
  echo "# $(date '+%F %T')  bench=$(basename "$BENCH_DIR")  mainargs=$MAINARGS  commit=${C}${D}  make_rc=$RC"
  echo "# $(git -C "$YSYX" log -1 --format='%s' "$C" 2>/dev/null)"
  if grep -q '^\[PERF\] ' "$TMP"; then
    grep -E 'cycle:|\[PERF\]|PASS|TRAP|Scored time|Total  time' "$TMP"
  else
    echo "!!! FAIL: 没有 [PERF] 输出（make 返回 $RC），下面是完整输出"
    cat "$TMP"
  fi
  if [ -n "$STA_LINES" ]; then
    echo "#"
    echo "# --- 综合/时序（yosys-sta: make sta，nangate45）---"
    echo "$STA_LINES"
  fi
} > "$REC"
rm -f "$TMP" "$TMP.sta"
echo "==> $REC"
