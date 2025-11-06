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

# 参数文件
PARAM_FILE="./script/params_sets_ways.txt"

# BLOCK_SIZE 可变
BLOCK_SIZES=(4 8 16)

# POLICIES
POLICIES=("fifo" "lru")

# 输出目录
OUTPUT_DIR="$BUILD_DIR/results"
mkdir -p "$OUTPUT_DIR"

# 并发运行
while read line; do
  # 跳过空行或注释
  [[ -z "$line" || "$line" =~ ^# ]] && continue

  # 读取 set 和 way
  read set way <<< "$line"

  for block_size in "${BLOCK_SIZES[@]}"; do

    # 计算缓存大小 (set * way * block_size)
    cache_size=$((set * way * block_size))
    
    # 如果缓存大小超过阈值 (16 * 8 = 128)，则跳过
    if [ $cache_size -gt 128 ]; then
      echo "# Skipping: set=${set} way=${way} block_size=${block_size} (cache_size=${cache_size} > 128)"
      continue
    fi

    for policy in "${POLICIES[@]}"; do
      out_file="$OUTPUT_DIR/cache_sim_sets${set}_ways${way}_block${block_size}_policy_${policy}.log"
      echo "# Running: $CACHESIM $TRACE_FILE $set $way $block_size $policy"
      "$CACHESIM" "$TRACE_FILE" "$set" "$way" "$block_size" "$policy" > "$out_file" &

      # 控制最大并发数为6
      if (( $(jobs -r | wc -l) >= 6 )); then
        wait -n
      fi
    done
  done
done < "$PARAM_FILE"

# 等待所有后台进程完成
wait
echo "All combinations completed. Results saved to $OUTPUT_DIR"
