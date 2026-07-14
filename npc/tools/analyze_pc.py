import numpy as np
import matplotlib.pyplot as plt
import time

def parse_trace_file(file_path):
    print(f"Reading and parsing file: {file_path} ...")
    start_time = time.time()
    
    pcs = []
    cycles = []
    
    with open(file_path, 'r', encoding='utf-8') as f:
        for line in f:
            if line.startswith("[pc]"):
                parts = line.split()
                if len(parts) >= 4:
                    try:
                        pc_str = parts[0].replace("[pc]", "").replace(":", "")
                        pc = int(pc_str, 16)
                        cycle = int(parts[3])
                        
                        pcs.append(pc)
                        cycles.append(cycle)
                    except ValueError:
                        continue
                        
    pcs = np.array(pcs, dtype=np.uint64)
    cycles = np.array(cycles, dtype=np.uint64)
    
    print(f"Parsing finished in {time.time() - start_time:.2f}s. Valid instructions: {len(pcs)}")
    return pcs, cycles

def text_based_analysis(pcs, cycles, strides, reuse_distances):
    """
    提供图形无法呈现的纯文字、数字化深度细节分析
    """
    print("\n" + "="*20 + " TEXT-BASED QUANTITATIVE ANALYSIS " + "="*20)
    total_ins = len(pcs)
    
    # 1. 空间局部性文字细节
    seq_4 = np.sum(strides == 4)
    seq_2 = np.sum(strides == 2)
    back_jump = np.sum(strides < 0)
    fwd_jump = np.sum(strides > 4)
    
    print(f"[Spatial Locality Metrics]")
    print(f"  - Total Dynamic Instructions: {total_ins}")
    print(f"  - Sequential (+4 Bytes) Stride: {seq_4} ({seq_4/total_ins*100:.2f}%) -> Standard 32-bit sequential fetch")
    print(f"  - Compressed (+2 Bytes) Stride: {seq_2} ({seq_2/total_ins*100:.2f}%) -> 16-bit compressed instruction (if any)")
    print(f"  - Backward Branches (Looping): {back_jump} ({back_jump/total_ins*100:.2f}%) -> High percentage means dense loops")
    print(f"  - Forward Jumps (If-Else/Calls): {fwd_jump} ({fwd_jump/total_ins*100:.2f}%)")
    
    # 2. 时间局部性文字细节
    rd_arr = np.array(reuse_distances)
    if len(rd_arr) > 0:
        print(f"\n[Temporal Locality Metrics]")
        print(f"  - Instructions with Reuse: {len(rd_arr)} ({len(rd_arr)/total_ins*100:.2f}%) -> Percentage of code re-executed")
        print(f"  - Median Reuse Distance: {np.median(rd_arr):.1f} instructions")
        print(f"  - Average Reuse Distance: {np.mean(rd_arr):.1f} instructions")
        print(f"  - Short-range Reuse (<128 ins): {np.sum(rd_arr < 128)} ({np.sum(rd_arr < 128)/len(rd_arr)*100:.2f}%) -> Friendly to small L1 I-Cache")
    else:
        print(f"\n[Temporal Locality Metrics]\n  - No reused instructions detected in this trace.")

    # 3. 性能/流水线停顿文字细节
    cycle_diffs = np.diff(cycles)
    avg_cpi = (cycles[-1] - cycles[0]) / total_ins if total_ins > 1 else 0
    print(f"\n[Performance & Stall Metrics]")
    print(f"  - Total Execution Cycles: {cycles[-1] - cycles[0]}")
    print(f"  - Average CPI (Cycles Per Instruction): {avg_cpi:.2f}")
    
    # 寻找异常长的周期停顿（比如由于 Cache Miss 或 异常 导致的突变）
    heavy_stalls = np.sum(cycle_diffs > (avg_cpi * 5))
    print(f"  - Anomalous Long Cycles (>5x Avg CPI): {heavy_stalls} occurrences")
    print("=" * 74 + "\n")

def analyze_and_plot(pcs, cycles):
    print("Calculating metrics and generating plots...")
    n_instructions = len(pcs)
    
    # 计算空间和时间度量
    strides = np.diff(pcs)
    
    last_seen = {}
    reuse_distances = []
    for i, pc in enumerate(pcs):
        if pc in last_seen:
            reuse_distances.append(i - last_seen[pc])
        last_seen[pc] = i
    reuse_distances = np.array(reuse_distances)

    # 打印纯文字细节分析
    text_based_analysis(pcs, cycles, strides, reuse_distances)

    # 开始绘图 (全英文，无任何特殊字体设置)
    fig = plt.figure(figsize=(15, 10))

    # Plot 1: Address Trace (Sequence vs PC)
    ax1 = fig.add_subplot(2, 2, 1)
    ax1.scatter(range(n_instructions), pcs, s=0.05, alpha=0.2, color='blue')
    ax1.set_title("1. Instruction Fetch Trace (Sequence vs PC)")
    ax1.set_xlabel("Instruction Index")
    ax1.set_ylabel("PC Address")
    ax1.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, pos: f"0x{int(x):X}"))
    ax1.grid(True, linestyle='--', alpha=0.5)

    # Plot 2: Stride Distribution (Spatial Locality)
    ax2 = fig.add_subplot(2, 2, 2)
    mask = (strides >= -32) & (strides <= 32)
    ax2.hist(strides[mask], bins=range(-32, 36, 4), color='green', edgecolor='black', alpha=0.7, rwidth=0.8)
    ax2.set_title("2. Spatial Locality: PC Stride Distribution")
    ax2.set_xlabel("Delta PC (Bytes)")
    ax2.set_ylabel("Frequency")
    ax2.set_xticks(range(-32, 36, 8))
    ax2.grid(True, linestyle='--', alpha=0.5)

    # Plot 3: Reuse Distance (Temporal Locality)
    ax3 = fig.add_subplot(2, 2, 3)
    if len(reuse_distances) > 0:
        rd_filtered = reuse_distances[reuse_distances < 500]
        ax3.hist(rd_filtered, bins=50, color='orange', edgecolor='black', alpha=0.7)
    ax3.set_title("3. Temporal Locality: Reuse Distance (<500 ins)")
    ax3.set_xlabel("Reuse Distance (Instructions)")
    ax3.set_ylabel("Frequency")
    ax3.grid(True, linestyle='--', alpha=0.5)

    # Plot 4: Timeline Analysis (Cycle vs PC)
    ax4 = fig.add_subplot(2, 2, 4)
    ax4.scatter(cycles, pcs, s=0.05, alpha=0.2, color='purple')
    ax4.set_title("4. Timeline Analysis (Cycle vs PC)")
    ax4.set_xlabel("CPU Clock Cycle")
    ax4.set_ylabel("PC Address")
    ax4.yaxis.set_major_formatter(plt.FuncFormatter(lambda x, pos: f"0x{int(x):X}"))
    ax4.grid(True, linestyle='--', alpha=0.5)

    plt.tight_layout()
    print("Displaying plots. Close the window to exit.")
    plt.show()

if __name__ == "__main__":
    # 请确保你的txt文件名为 trace.txt，或者修改下方变量
    file_path = "./build/itrace-log.txt" 
    
    try:
        pcs, cycles = parse_trace_file(file_path)
        if len(pcs) > 0:
            analyze_and_plot(pcs, cycles)
        else:
            print("Error: No data parsed.")
    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")