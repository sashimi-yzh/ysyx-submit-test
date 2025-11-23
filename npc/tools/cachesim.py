import math
import random
import argparse

class CacheSimulator:
    def __init__(self, b, k, w, algorithm):
        """初始化缓存模拟器
        
        Args:
            b (int): 缓存块大小（字节）
            k (int): 缓存总块数
            w (int): 每组包含块数（组相连）
            algorithm (str): 替换算法（FIFO/LRU/RANDOM）
        """
        # 参数有效性检查
        if (b & (b-1)) != 0 or b <= 0:
            raise ValueError("块大小b必须是2的幂且大于0")
        if k % w != 0:
            raise ValueError("总块数k必须是每组块数w的倍数")
        self.s = s = k // w  # 总组数
        if (s & (s-1)) != 0 or s <= 0:
            raise ValueError("k/w必须是2的幂且大于0")

        # 基础参数
        self.b = b
        self.k = k
        self.w = w
        self.algorithm = algorithm
        self.offset_bits = int(math.log2(b))
        self.group_bits = int(math.log2(s))
        self.mask_group = (1 << self.group_bits) - 1

        # 初始化缓存结构
        self.cache = []
        for _ in range(self.s):
            group = {
                'blocks': [{'valid': False, 'tag': None} for _ in range(w)],
                'fifo_ptr': 0,  # 仅FIFO使用
                'lru_queue': list(range(w))  # 仅LRU使用
            }
            self.cache.append(group)

        # 统计信息
        self.hits = 0
        self.misses = 0

    def access(self, address):
        """处理一个内存访问请求"""
        addr = int(address, 16)
        # 计算地址组成部分
        group_index = (addr >> self.offset_bits) & self.mask_group
        tag = addr >> (self.offset_bits + self.group_bits)
        group = self.cache[group_index]

        # 查找是否命中
        hit = False
        for i, block in enumerate(group['blocks']):
            if block['valid'] and block['tag'] == tag:
                self.hits += 1
                hit = True
                # LRU需要更新访问顺序
                if self.algorithm == 'LRU':
                    group['lru_queue'].remove(i)
                    group['lru_queue'].append(i)
                break

        if not hit:
            self.misses += 1
            # 查找可用块
            replaced = False
            for i, block in enumerate(group['blocks']):
                if not block['valid']:
                    group['blocks'][i]['tag'] = tag
                    group['blocks'][i]['valid'] = True
                    # 更新LRU队列
                    if self.algorithm == 'LRU':
                        group['lru_queue'].remove(i)
                        group['lru_queue'].append(i)
                    replaced = True
                    break
            
            if not replaced:  # 需要替换
                if self.algorithm == 'FIFO':
                    ptr = group['fifo_ptr']
                    group['blocks'][ptr]['tag'] = tag
                    group['fifo_ptr'] = (ptr + 1) % self.w
                elif self.algorithm == 'LRU':
                    lru = group['lru_queue'].pop(0)
                    group['blocks'][lru]['tag'] = tag
                    group['lru_queue'].append(lru)
                else:  # RANDOM
                    idx = random.randint(0, self.w-1)
                    group['blocks'][idx]['tag'] = tag

    def get_hit_rate(self):
        """获取命中率"""
        total = self.hits + self.misses
        return self.hits / total if total else 0.0

def main():
    # 命令行参数解析
    parser = argparse.ArgumentParser(description='缓存模拟器')
    parser.add_argument('--b', type=int, default=8, help='缓存块大小（字节）')
    parser.add_argument('--k', type=int, default=2, help='总缓存块数')
    parser.add_argument('--w', type=int, default=1, help='每组块数')
    parser.add_argument('--algorithm', choices=['FIFO', 'LRU', 'RANDOM'], default='LRU', help='替换算法')
    parser.add_argument('--input', type=str, default='itrace.txt', help='输入文件路径')
    args = parser.parse_args()

    # 初始化模拟器
    try:
        sim = CacheSimulator(args.b, args.k, args.w, args.algorithm)
    except ValueError as e:
        print(f"参数错误: {e}")
        return

    # 处理地址访问
    with open(args.input, 'r') as f:
        for line in f:
            addr = line.strip()
            if addr:
                sim.access(addr)

    # 输出结果
    print(f"命中次数: {sim.hits}")
    print(f"未命中次数: {sim.misses}")
    print(f"命中率: {sim.get_hit_rate():.2%}")

if __name__ == "__main__":
    main()
