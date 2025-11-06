import os
import re
import csv

log_dir = "./build/results"
output_file = "summary.csv"

table = []

filename_pattern = re.compile(
    r'cache_sim_sets(\d+)_ways(\d+)_block(\d+)_policy_(\w+)\.log'
)

for filename in os.listdir(log_dir):
    filepath = os.path.join(log_dir, filename)
    if not os.path.isfile(filepath):
        continue

    match = filename_pattern.match(filename)
    if not match:
        continue

    sets = int(match.group(1))
    ways = int(match.group(2))
    block_size = int(match.group(3))
    policy = match.group(4)

    hit_rate = None
    with open(filepath, 'r') as f:
        for line in f:
            line = line.strip()
            if line.startswith("Hit rate"):
                parts = line.split(":")
                if len(parts) == 2:
                    hit_rate = float(parts[1].strip())
                break

    if hit_rate is None:
        print(f"Warning: No hit rate found in {filename}")
        continue

    sets_times_ways = sets * ways
    capacity = sets_times_ways * block_size  # 新增容量列
    hit_rate_percent = hit_rate * 100

    # 添加新列capacity
    table.append([policy, sets, ways, sets_times_ways, block_size, capacity, hit_rate_percent])

# 调整排序键：索引位置变了
table.sort(key=lambda x: (x[0], x[3], x[5], x[6]))  # 第5列现在是capacity，第6列是hit_rate

with open(output_file, 'w', newline='') as csvfile:
    writer = csv.writer(csvfile)
    # 更新表头，添加新列
    writer.writerow(["Policy", "Sets", "Ways", "Sets*Ways", "Block Size", "Capacity(Sets*Ways*Block Size)", "Hit rate*100%"])

    last_policy = None
    last_sets_times_ways = None
    last_capacity = None

    for row in table:
        current_policy = row[0]
        current_sets_times_ways = row[3]
        current_capacity = row[5]

        # 格式化命中率
        row[6] = f"{row[6]:.2f}"

        # 如果切换到新的 policy 或新的 sets*ways，插空行
        if ((last_policy is not None and last_policy != current_policy) or
            (last_sets_times_ways is not None and last_sets_times_ways != current_sets_times_ways)):
            writer.writerow([])

        # 或在同组里 capacity 发生变化
        elif (last_capacity is not None and last_capacity != current_capacity and
              last_policy == current_policy and last_sets_times_ways == current_sets_times_ways):
            writer.writerow([])

        writer.writerow(row)

        last_policy = current_policy
        last_sets_times_ways = current_sets_times_ways
        last_capacity = current_capacity

print(f"Improved summary with full spacing and capacity column written to {output_file}")