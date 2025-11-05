import math
import gzip
import struct
import random

class CacheLine:
    def __init__(self):
        self.valid = False
        self.tag = None
        self.data = None  
        self.lru_counter = 0  # 用于LRU替换策略
        self.insert_time = 0  # 用于FIFO替换策略

    def __str__(self):
        return f"Valid: {self.valid}, Tag: {self.tag}, LRU: {self.lru_counter}, Insert Time: {self.insert_time}"

class CacheSet:
    def __init__(self, associativity, replacement_policy='LRU'):
        self.associativity = associativity
        self.replacement_policy = replacement_policy
        self.lines = [CacheLine() for _ in range(associativity)]
        self.current_time = 0  # 用于FIFO

    def find_line(self, tag):
        for line in self.lines:
            if line.valid and line.tag == tag:
                return line
        return None

    def get_replacement_line(self):
        if self.replacement_policy == 'LRU':
            return min(self.lines, key=lambda line: line.lru_counter)
        elif self.replacement_policy == 'RANDOM':
            return random.choice(self.lines)
        elif self.replacement_policy == 'FIFO':
            return min(self.lines, key=lambda line: line.insert_time)
        else:
            raise ValueError("Unknown replacement policy")

    def replace_line(self, tag):
        replacement_line = self.get_replacement_line()
        replacement_line.valid = True
        replacement_line.tag = tag
        replacement_line.lru_counter = 0
        self.current_time += 1
        replacement_line.insert_time = self.current_time
        return replacement_line

    def update_on_hit(self, line):
        if self.replacement_policy == 'LRU':
            for l in self.lines:
                if l != line and l.valid:
                    l.lru_counter += 1
            line.lru_counter = 0

    def access(self, tag):
        line = self.find_line(tag)
        if line:
            # Cache Hit
            self.update_on_hit(line)
            return True
        else:
            # Cache Miss
            self.replace_line(tag)
            return False

    def __str__(self):
        return '\n'.join([str(line) for line in self.lines])

class Cache:
    def __init__(self, cache_size, block_size, associativity, addressbits = 32,replacement_policy='LRU'):
        self.cache_size = cache_size  
        self.block_size = block_size 
        self.associativity = associativity
        self.replacement_policy = replacement_policy.upper()

        self.num_blocks = self.cache_size // self.block_size
        self.num_sets = self.num_blocks // self.associativity

        self.sets = [CacheSet(associativity, self.replacement_policy) for _ in range(self.num_sets)]

        self.block_offset_bits = int(math.log2(self.block_size))
        self.index_bits = int(math.log2(self.num_sets))
        self.tag_bits = addressbits - self.index_bits - self.block_offset_bits  

        # 统计数据
        self.accesses = 0
        self.hits = 0
        self.misses = 0

    def access(self, address):
        self.accesses += 1

        # 提取地址的各部分
        #block_offset = address & (self.block_size - 1)
        index = (address >> self.block_offset_bits) & (self.num_sets - 1)
        tag = address >> (self.block_offset_bits + self.index_bits)

        cache_set = self.sets[index]
        hit = cache_set.access(tag)

        if hit:
            self.hits += 1
        else:
            self.misses += 1

        return hit

    def get_stats(self):
        hit_rate = self.hits / self.accesses if self.accesses else 0
        miss_rate = self.misses / self.accesses if self.accesses else 0
        return {
            'Accesses': self.accesses,
            'Hits': self.hits,
            'Misses': self.misses,
            'Hit Rate': hit_rate,
            'Miss Rate': miss_rate
        }

    def __str__(self):
        stats = self.get_stats()
        return (f"Cache Stats:\n"
                f"Total Accesses: {stats['Accesses']}\n"
                f"Hits: {stats['Hits']}\n"
                f"Misses: {stats['Misses']}\n"
                f"Hit Rate: {stats['Hit Rate'] * 100:.2f}%\n"
                f"Miss Rate: {stats['Miss Rate'] * 100:.2f}%")