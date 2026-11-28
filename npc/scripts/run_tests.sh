#!/usr/bin/env bash
# 批量跑 cpu-tests（RTL 或门级网表），一次编译、多次换镜像
#   ./scripts/run_tests.sh rtl                 # RTL 四值仿真
#   ./scripts/run_tests.sh netlist             # 门级网表仿真
#   TESTS=add,dummy ./scripts/run_tests.sh rtl # 只跑指定的几个
#   CYC=5000000 ./scripts/run_tests.sh rtl     # 改周期上限
set -u

MODE=${1:-rtl}
TESTS_DIR=${TESTS_DIR:-../am-kernels/tests/cpu-tests/build}
CYC=${CYC:-2000000}
PER_TEST=${PER_TEST:-900}
VVP=${VVP:-vvp}
OUT_DIR=build/sim/run_tests
LOG=$OUT_DIR/$MODE.log

case "$MODE" in
  rtl)     TB=build/sim/tb.vvp ;;
  netlist) TB=build/sim/tb_net.vvp ;;
  *) echo "用法: $0 [rtl|netlist]"; exit 1 ;;
esac

mkdir -p "$OUT_DIR"
: > "$LOG"

# ---- 编译（有缓存就直接用）----
if [ "$MODE" = rtl ]; then
  make -s "$TB" || { echo "编译失败"; exit 1; }
else
  make -s "$TB" || { echo "编译失败"; exit 1; }
fi

# ---- 选测试 ----
if [ -n "${TESTS:-}" ]; then
  IFS=',' read -ra LIST <<< "$TESTS"
else
  LIST=()
  for f in "$TESTS_DIR"/*-riscv32e-npc.bin; do
    b=$(basename "$f"); LIST+=("${b%-riscv32e-npc.bin}")
  done
fi

pass=0; fail=0; failed=()
t0=$(date +%s)

for t in "${LIST[@]}"; do
  bin="$TESTS_DIR/$t-riscv32e-npc.bin"
  hex="$OUT_DIR/$t.hex"
  if [ ! -f "$bin" ]; then echo "跳过 $t（找不到 $bin）"; continue; fi
  python3 scripts/bin2hex.py "$bin" "$hex" >/dev/null || { echo "FAIL $t (bin2hex)"; fail=$((fail+1)); failed+=("$t"); continue; }

  log="$OUT_DIR/$t.$MODE.log"
  timeout "$PER_TEST" "$VVP" "$TB" +HEX="$PWD/$hex" +CYCLES="$CYC" > "$log" 2>&1
  rc=$?

  if [ "$MODE" = rtl ]; then
    if grep -q "EBREAK" "$log" && grep -q "a0 = 0x00000000" "$log"; then ok=1; else ok=0; fi
    cycles=$(grep -oE "cycles = [0-9]+" "$log" | tail -1 | grep -oE "[0-9]+")
  else
    if grep -q "EBREAK: 程序结束" "$log"; then ok=1; else ok=0; fi
    cycles=$(grep -oE "cycles=[0-9]+" "$log" | tail -1 | grep -oE "[0-9]+")
  fi

  if [ "$ok" = 1 ]; then
    pass=$((pass+1)); printf "PASS %-16s %8s 拍\n" "$t" "${cycles:-?}"
    echo "PASS $t ${cycles:-?}" >> "$LOG"
  else
    fail=$((fail+1)); failed+=("$t")
    printf "FAIL %-16s (rc=%d, 见 %s)\n" "$t" "$rc" "$log"
    tail -3 "$log" | sed 's/^/       /'
    echo "FAIL $t" >> "$LOG"
  fi
done

t1=$(date +%s)
echo "---------------------------------------------"
printf "%-8s 通过 %d / %d，用时 %d s\n" "$MODE" "$pass" "$((pass+fail))" "$((t1-t0))"
if [ "$fail" -ne 0 ]; then
  echo "失败: ${failed[*]}"
  exit 1
fi
