#!/bin/bash

# 检查输入参数
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <input_bin_file> <output_coe_file>"
    exit 1
fi

INPUT_BIN=$1
OUTPUT_COE=$2

# 检查输入文件是否存在
if [ ! -f "$INPUT_BIN" ]; then
    echo "Error: Input file '$INPUT_BIN' does not exist."
    exit 1
fi

# 数据宽度（字节数），默认为32位 = 4字节
WORD_SIZE=4

# 输出 COE 文件头部
echo "; Vivado COE file" > "$OUTPUT_COE"
echo "; Generated from $(basename "$INPUT_BIN")" >> "$OUTPUT_COE"
echo "memory_initialization_radix=16;" >> "$OUTPUT_COE"
echo "memory_initialization_vector=" >> "$OUTPUT_COE"

# 转换二进制文件为16进制，并按照数据宽度分组
xxd -p -c $WORD_SIZE "$INPUT_BIN" | sed 's/\(..\)\(..\)\(..\)\(..\)/\4\3\2\1/' | awk '{printf "%s,\n", $0}' >> "$OUTPUT_COE"

# 替换最后一个逗号为分号，完成文件格式
sed -i '$s/,$/;/' "$OUTPUT_COE"

echo "Successfully converted '$INPUT_BIN' to '$OUTPUT_COE'."

cp $OUTPUT_COE /mnt/hgfs/share

echo "Already copy into share folder. Thanks to Ocean"

