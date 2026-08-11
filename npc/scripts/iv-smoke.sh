#!/usr/bin/env bash
set -euo pipefail

die() {
  printf 'iverilog smoke: %s\n' "$*" >&2
  exit 1
}

need_file() {
  [ -f "$1" ] || die "missing $2: $1"
}

[ -n "${IV_IMAGE:-}" ] || die 'IMG=...bin is required'
need_file "$IV_IMAGE" image

work=${IV_WORK:?missing IV_WORK}
mkdir -p "$work/tmp"
image="$work/image.bin"
hex="$work/image.hex"
program="$work/simv"
log="$work/sim.log"
cp "$IV_IMAGE" "$image"

python3 - "$image" "$hex" <<'PY'
from pathlib import Path
import sys

data = Path(sys.argv[1]).read_bytes()
Path(sys.argv[2]).write_text("".join(f"{byte:02x}\n" for byte in data))
PY
bytes=$(wc -c < "$image")

read -r -a sources <<< "${IV_SOURCES:?missing IV_SOURCES}"
read -r -a options <<< "${IV_OPTIONS:-}"

case ${IV_MODE:?missing IV_MODE} in
  rtl)
    inputs=("${sources[@]}")
    ;;
  netlist)
    [ -n "${IV_NETLIST:-}" ] || die 'NETLIST=...netlist.v is required'
    [ -n "${IV_CELLS:-}" ] || die 'CELLS=...cells.v is required'
    netlist=$IV_NETLIST
    if [[ $netlist != *.sim && -f $netlist.sim ]]; then
      netlist=$netlist.sim
    fi
    need_file "$netlist" 'netlist simulation file'
    need_file "$IV_CELLS" 'cell model'
    inputs=("$netlist" "$IV_CELLS" "${sources[@]}")
    ;;
  *)
    die "unknown mode: $IV_MODE"
    ;;
esac

printf '[iverilog][prepare] mode=%s image=%s bytes=%s work=%s\n' \
  "$IV_MODE" "$IV_IMAGE" "$bytes" "$work"
printf '[iverilog][compile] compiler=%s top=%s sources=%s output=%s\n' \
  "$IV_CC" "$IV_TOP" "${#inputs[@]}" "$program"
if ((${#options[@]} > 0)); then
  printf '[iverilog][compile] options=%s\n' "${options[*]}"
fi
TMPDIR="$work/tmp" TMP="$work/tmp" TEMP="$work/tmp" \
  "$IV_CC" "${options[@]}" -I"$IV_INCLUDE" -g2012 \
  -o "$program" -s "$IV_TOP" "${inputs[@]}"
printf '[iverilog][compile] complete output=%s\n' "$program"

run_args=("$program" "+IMG=$hex" "+IMG_BYTES=$bytes")
[ -z "${IV_WAVE:-}" ] || run_args+=("$IV_WAVE")
read -r -a user_args <<< "${IV_VVP_ARGS:-}"
run_args+=("${user_args[@]}")

rm -f "$log" "$work/wave.vcd"
printf '[iverilog][run] runtime=%s log=%s args=%s\n' \
  "$IV_VM" "$log" "${run_args[*]}"
TMPDIR="$work/tmp" TMP="$work/tmp" TEMP="$work/tmp" \
  "$IV_VM" "${run_args[@]}" 2>&1 | tee "$log"
if grep -q 'HIT GOOD TRAP' "$log"; then
  printf '[iverilog][pass] good trap detected log=%s\n' "$log"
else
  die "simulation did not reach a good trap; log=$log"
fi
