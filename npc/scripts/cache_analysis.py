#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
内存访问模式分析工具

功能:
1. 分析日志文件中的内存访问模式
2. 生成空间局部性和时间局部性可视化图表

输入要求:
- 日志文件需包含内存访问记录，格式示例:
  pc: 0x80000000 memory read: addr = 0x80000000, len = 4, data = 0x00000413
  或类似格式(支持read/write操作)

使用方法:
1. 基本用法:
   python cache_analysis.py <日志文件路径>

2. 可选参数:
   --cacheline <大小>   设置缓存行大小(默认64字节)
   --window <次数>      设置时间局部性分析窗口大小(默认10次访问)
   --ticks <数量>       设置x轴刻度数量(默认10个)

3. 输出文件:
   - spatial_locality.png   空间局部性分析图
   - temporal_locality.png  时间局部性分析图

示例:
   python cache_analysis.py trace.log --cacheline 64 --window 20 --ticks 8

注意事项:
1. 日志文件需包含有效的内存地址信息
2. 地址格式应为十六进制(0x开头)
3. 建议分析至少1000次内存访问以获得有意义的结果

作者:xhf
版本:v1.2
最后更新:2025-3-31
"""
import argparse
import matplotlib.pyplot as plt
from collections import defaultdict, deque
import re
import numpy as np

def parse_log_file(log_file):
    """Parse log file and extract memory addresses"""
    addresses = []
    addr_pattern = re.compile(r'addr\s*=\s*(0x[0-9a-fA-F]+)')
    
    with open(log_file, 'r') as f:
        for line in f:
            if not line.strip():
                continue
                
            match = addr_pattern.search(line)
            if match:
                try:
                    addr = int(match.group(1), 16)
                    addresses.append(addr)
                except ValueError:
                    continue
    return addresses

def plot_spatial_locality(addresses, cacheline_size=64, num_ticks=10):
    """Plot spatial locality within cachelines"""
    if len(addresses) < 2:
        print("Error: Not enough addresses for spatial locality analysis")
        return
        
    cacheline_counts = defaultdict(int)
    prev_cacheline = None
    
    for addr in addresses:
        current_cacheline = addr // cacheline_size
        
        if prev_cacheline is not None and current_cacheline == prev_cacheline:
            cacheline_counts[current_cacheline * cacheline_size] += 1
        
        prev_cacheline = current_cacheline
    
    if not cacheline_counts:
        print("Warning: No spatial locality patterns detected")
        return
    
    cachelines = sorted(cacheline_counts.keys())
    counts = [cacheline_counts[addr] for addr in cachelines]
    
    plt.figure(figsize=(14, 6))
    bars = plt.bar(range(len(cachelines)), counts, width=1.0)
    
    # Add meaningful x-axis ticks
    if len(cachelines) > num_ticks:
        step = max(1, len(cachelines) // num_ticks)
        tick_positions = range(0, len(cachelines), step)
    else:
        tick_positions = range(len(cachelines))

    tick_labels = [f"0x{cachelines[pos]:08x}" for pos in tick_positions]
    
    plt.xticks(tick_positions, tick_labels, rotation=45, ha='right')
    plt.xlabel('Cacheline Address (64B aligned)')
    plt.ylabel('Adjacent Access Count')
    plt.title('Spatial Locality: Adjacent Accesses within Cachelines')
    plt.grid(True, axis='y')
    plt.tight_layout()
    plt.savefig('build/space_locality.png', dpi=300)
    plt.close()
    print("Spatial locality plot saved to build/space_locality.png")

def plot_temporal_locality(addresses, cacheline_size=64, window_size=10, num_ticks=10):
    """Plot temporal locality within access window"""
    if len(addresses) < window_size:
        print(f"Error: Not enough addresses (need at least {window_size})")
        return
        
    cacheline_counts = defaultdict(int)
    recent_accesses = deque(maxlen=window_size)
    
    for addr in addresses:
        cacheline_addr = addr // cacheline_size * cacheline_size
        
        if cacheline_addr in recent_accesses:
            cacheline_counts[cacheline_addr] += 1
        
        recent_accesses.append(cacheline_addr)
    
    if not cacheline_counts:
        print("Warning: No temporal locality patterns detected")
        return
    
    cachelines = sorted(cacheline_counts.keys())
    counts = [cacheline_counts[addr] for addr in cachelines]
    
    plt.figure(figsize=(14, 6))
    bars = plt.bar(range(len(cachelines)), counts, width=1.0)
    
    # Add meaningful x-axis ticks
    if len(cachelines) > num_ticks:
        step = max(1, len(cachelines) // num_ticks)
        tick_positions = range(0, len(cachelines), step)
    else:
        tick_positions = range(len(cachelines))

    tick_labels = [f"0x{cachelines[pos]:08x}" for pos in tick_positions]
    
    plt.xticks(tick_positions, tick_labels, rotation=45, ha='right')
    plt.xlabel('Cacheline Address (64B aligned)')
    plt.ylabel(f'Reuse Count (window={window_size})')
    plt.title('Temporal Locality: Cacheline Reuse Pattern')
    plt.grid(True, axis='y')
    plt.tight_layout()
    plt.savefig('build/time_locality.png', dpi=300)
    plt.close()
    print("Temporal locality plot saved to build/time_locality.png")

def main():
    parser = argparse.ArgumentParser(description='Analyze memory access patterns from log file')
    parser.add_argument('log_file', help='Path to the memory access log file')
    parser.add_argument('--cacheline', type=int, default=64,
                      help='Cacheline size in bytes (default: 64)')
    parser.add_argument('--window', type=int, default=10,
                      help='Temporal locality window size (default: 10)')
    parser.add_argument('--ticks', type=int, default=20,
                      help='Number of x-axis ticks (default: 10)')
    args = parser.parse_args()

    try:
        addresses = parse_log_file(args.log_file)
        print(f"Analyzed {len(addresses)} memory accesses from {args.log_file}")
        
        plot_spatial_locality(addresses, args.cacheline, args.ticks)
        plot_temporal_locality(addresses, args.cacheline, args.window, args.ticks)
        
    except FileNotFoundError:
        print(f"Error: File not found - {args.log_file}")
    except Exception as e:
        print(f"An error occurred: {str(e)}")

if __name__ == "__main__":
    main()