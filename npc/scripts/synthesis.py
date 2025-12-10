#!/usr/bin/env python3
import sys
import re
import subprocess
import os

# 内置模块列表：(模块名, 时钟端口名)
MODULES = [
    ("ysyx_25050136", "clock"),
    # ("ysyx_25050136_NPCCORE", "clk"),
    # ("ysyx_25050136_NPC", "clk"),
    # ("ysyx_25050136_ICACHE", "clk"),
    # ("ysyx_25050136_IF", "clk"),
    # ("ysyx_25050136_ID", "clk"),
    # ("ysyx_25050136_EX", "clk"),
    # ("ysyx_25050136_MEM", "clk"),
    # ("ysyx_25050136_WB", "clk"),
    # ("ysyx_25050136_DCACHE", "clk"),
    # ("ysyx_25050136_ALU", "clk"),
    # ("ysyx_25050136_BQU", "clk"),
    # ("ysyx_25050136_CSRU", "clk"),
]

def run_sta(design, clk_freq, clk_port, rtl_files):
    """运行 STA 分析"""
    cmd = [
        'make', '-C', '/home/yunhai/ysyx-workbench/yosys-sta', 'sta',
        f'DESIGN={design}',
        f'CLK_FREQ_MHZ={clk_freq}',
        f'CLK_PORT_NAME={clk_port}',
        f'RTL_FILES={rtl_files}'
    ]
    try:
        result = subprocess.run(cmd, check=True, capture_output=True, text=True)
        return True, None
    except subprocess.CalledProcessError as e:
        return False, str(e)

def extract_area(log_file):
    """从 synth_stat_fixed.txt 提取面积信息"""
    try:
        with open(log_file, 'r') as f:
            content = f.read()
            
        # 提取总面积
        area_match = re.search(r"Chip area for module.*:\s*([\d.]+)", content)
        total_area = area_match.group(1) if area_match else "未找到"
        
        # 提取时序单元占比
        seq_match = re.search(r"of which used for sequential elements:\s*([\d.]+)\s*\(([\d.]+)%\)", content)
        if seq_match:
            seq_area = seq_match.group(1)
            seq_percent = seq_match.group(2)
        else:
            seq_area = "未找到"
            seq_percent = "未找到"
            
        return total_area, seq_area, seq_percent
    except FileNotFoundError:
        return "文件不存在", "文件不存在", "文件不存在"
    except Exception as e:
        return f"错误: {e}", "错误", "错误"

def extract_freq(rpt_file):
    """从 .rpt 提取最大频率和 Slack"""
    try:
        with open(rpt_file, 'r') as f:
            lines = f.readlines()
        
        max_freq = "未找到"
        slack = "未找到"
        
        # 查找第一个有效频率（非 NA）
        for line in lines:
            if '|' in line and 'Freq(MHz)' not in line and '---' not in line:
                parts = [p.strip() for p in line.split('|')]
                if len(parts) >= 9:
                    freq = parts[8]
                    slk = parts[7]
                    if freq and freq != 'NA' and freq != 'Freq(MHz)':
                        max_freq = freq
                        slack = slk
                        break
                    
        return max_freq, slack
    except FileNotFoundError:
        return "文件不存在", "文件不存在"
    except Exception as e:
        return f"错误: {e}", "错误"

def analyze_module(design, clk_port, clk_freq, rtl_files):
    """分析单个模块"""
    result = {
        'design': design,
        'status': 'FAIL',
        'total_area': 'N/A',
        'seq_area': 'N/A',
        'seq_percent': 'N/A',
        'max_freq': 'N/A',
        'slack': 'N/A',
        'error': None
    }
    
    # 运行 STA
    success, error = run_sta(design, clk_freq, clk_port, rtl_files)
    if not success:
        result['error'] = error
        return result
    
    # 文件路径
    result_dir = f"/home/yunhai/ysyx-workbench/yosys-sta/result/{design}-{clk_freq}MHz"
    stat_file = f"{result_dir}/synth_stat_fixed.txt"
    rpt_file = f"{result_dir}/{design}.rpt"
    
    # 提取信息
    total_area, seq_area, seq_percent = extract_area(stat_file)
    max_freq, slack = extract_freq(rpt_file)
    
    result.update({
        'status': 'OK',
        'total_area': total_area,
        'seq_area': seq_area,
        'seq_percent': seq_percent,
        'max_freq': max_freq,
        'slack': slack
    })
    
    return result

def main():
    # 如果提供了命令行参数，使用单模块模式
    if len(sys.argv) >= 5:
        design = sys.argv[1]
        clk_freq = sys.argv[2]
        clk_port = sys.argv[3]
        rtl_files = sys.argv[4]
        
        print(f"正在运行 STA 分析: {design} @ {clk_freq}MHz...")
        run_sta(design, clk_freq, clk_port, rtl_files)
        
        result_dir = f"/home/yunhai/ysyx-workbench/yosys-sta/result/{design}-{clk_freq}MHz"
        stat_file = f"{result_dir}/synth_stat_fixed.txt"
        rpt_file = f"{result_dir}/{design}.rpt"
        
        total_area, seq_area, seq_percent = extract_area(stat_file)
        max_freq, slack = extract_freq(rpt_file)
        
        print("\n" + "=" * 60)
        print("综合面积报告 (优化扇出后):")
        print(f"  总面积:        {total_area}")
        print(f"  时序单元面积:  {seq_area} ({seq_percent}%)")
        print("=" * 60)
        print("时序分析报告:")
        print(f"  最大频率:      {max_freq} MHz")
        print(f"  Slack:         {slack}")
        print("=" * 60)
        return
    
    # 批量模式
    clk_freq = "1500"
    
    # 获取 RTL_FILES（从环境变量或使用默认值）
    rtl_files = os.environ.get('NPC_VSRC', '')
    if not rtl_files:
        print("警告: 未找到 NPC_VSRC 环境变量，使用空值")
    
    print("=" * 80)
    print(f"开始批量综合分析 (目标频率: {clk_freq}MHz)")
    print(f"共 {len(MODULES)} 个模块")
    print("=" * 80)
    
    results = []
    for idx, (design, clk_port) in enumerate(MODULES, 1):
        print(f"\n[{idx}/{len(MODULES)}] 正在分析模块: {design} (时钟: {clk_port})...")
        result = analyze_module(design, clk_port, clk_freq, rtl_files)
        results.append(result)
        
        if result['status'] == 'OK':
            print(f"  ✓ 成功 - 面积: {result['total_area']}, 频率: {result['max_freq']} MHz")
        else:
            print(f"  ✗ 失败 - {result['error']}")
    
    # 汇总输出
    print("\n" + "=" * 90)
    print("综合分析汇总")
    print("=" * 90)
    # 调整列宽以适应中文字符和符号
    print(f"{'模块名':<35} {'状态':<6} {'面积':<8} {'时序(%)':<8} {'频率(MHz)':<13} {'Slack':<10}")
    print("-" * 90)
    
    for r in results:
        status_mark = "✓ OK" if r['status'] == 'OK' else "✗ FAIL"
        # 调整列宽以对齐标题
        print(f"{r['design']:<35} {status_mark:<6} {r['total_area']:<15} {r['seq_percent']:<10} {r['max_freq']:<15} {r['slack']:<10}")
    
    print("=" * 90)
        
    
    # 统计
    success_count = sum(1 for r in results if r['status'] == 'OK')
    fail_count = len(results) - success_count
    print(f"\n总计: {len(results)} 个模块, 成功: {success_count}, 失败: {fail_count}")
    
    if fail_count > 0:
        print("\n失败的模块:")
        for r in results:
            if r['status'] == 'FAIL':
                print(f"  - {r['design']}: {r['error']}")

if __name__ == '__main__':
    main()