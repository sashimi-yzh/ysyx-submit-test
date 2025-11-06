# block_size固定的版本
#!/bin/bash

# 设置构建目录和可执行文件路径
BUILD_DIR="${CACHE_SIM_HOME}/build"
CACHESIM="${BUILD_DIR}/cachesim"
TRACE_FILE="${BUILD_DIR}/itrace.bin"

# 检查 trace 文件是否存在
if [ ! -f "$TRACE_FILE" ]; then
    echo "Error: Trace file not found at $TRACE_FILE"
    exit 1
fi

BLOCK_SIZE=4

# 参数文件
PARAM_FILE="./script/params_sets_ways.txt"

# 输出目录
OUTPUT_DIR="$BUILD_DIR/results"
mkdir -p "$OUTPUT_DIR"

# 并发运行
while read line; do
  # 跳过以 # 开头的行，或空行
  [[ -z "$line" || "$line" =~ ^# ]] && continue

  # 从行里读取 set 和 way
  read set way <<< "$line"

  for policy in "fifo" "lru"; do
    out_file="$OUTPUT_DIR/cache_sim_sets${set}_ways${way}_block${BLOCK_SIZE}_policy_${policy}.log"
    echo "# Running: $CACHESIM $TRACE_FILE $set $way $BLOCK_SIZE $policy"
    "$CACHESIM" "$TRACE_FILE" "$set" "$way" "$BLOCK_SIZE" "$policy" > "$out_file" &

    # 控制最大并发数为4
    if (( $(jobs -r | wc -l) >= 4 )); then
      wait -n
    fi
  done
done < "$PARAM_FILE"

# 等待所有后台进程完成
wait
echo "All combinations completed. Results saved to $OUTPUT_DIR"
