import gzip
import argparse
from cache import *
import struct

class CacheSimulator:
    def __init__(self, cache, address_size=4):
        self.cache = cache
        self.address_size = address_size  # 每个地址的字节数，4或8

    def run(self, trace_file):
        with gzip.open(trace_file, 'rb') as f:
            while True:
                address_bytes = f.read(self.address_size)
                if not address_bytes or len(address_bytes) < self.address_size:
                    break
                # 根据地址大小解码
                if self.address_size == 4:
                    address = struct.unpack('<I', address_bytes)[0] 
                elif self.address_size == 8:
                    address = struct.unpack('<Q', address_bytes)[0] 
                else:
                    raise ValueError("Unsupported address size. Use 4 or 8 bytes.")
                self.cache.access(address)
    def get_stats(self):
        return {
            'hits': self.cache.hits,
            'misses': self.cache.misses,
            'accesses': self.cache.hits + self.cache.misses,
            'hit_rate': self.cache.hits / (self.cache.hits + self.cache.misses),
            'miss_rate': self.cache.misses / (self.cache.hits + self.cache.misses)
        }
    def report(self):
        print(self.cache)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        prog='cachesim',
        description='cachesim',
        epilog='By EPTansuo (Bingjin Han)'
    )
    parser.add_argument('-f','--file', help="PC Trace file(.bin.gz)")

    #parser.add_argument('-o','--out',default='out.txt', help="Output results to file")
    parser.add_argument('-w','--nways', type=int, help="Number of ways")
    parser.add_argument('-s','--nsets', type=int, help="Number of sets")
    parser.add_argument('-b','--bs', type=int, help="Size of Cache Block (Unit: Byte)")
    parser.add_argument('-r','--replace', default="FIFO", help="Repalce Methology: FIFO, RANDOM, LRU(Only Support FIFO Now)")
    parser.add_argument('-a','--access-time',type=float, help="Access time(cycle)")
    parser.add_argument('-m','--miss-penalty',type=float, help="Miss Penalty time(cycle)")

    args = parser.parse_args()

    if(args.file == None or args.nways==None or args.nsets==None or args.bs==None or
        args.access_time == None or args.miss_penalty ==None ):
        # print help 
        print("Error Usage!")
        parser.print_help()
        exit()

    cacheSize = args.nways * args.nsets * args.bs

    cache = Cache(cacheSize, args.bs, args.nways, replacement_policy=args.replace)
    simulator = CacheSimulator(cache, address_size=4)
    simulator.run(args.file)
    hit_rate = simulator.get_stats()["hit_rate"]
    print(f"{hit_rate}, {args.access_time + (1-hit_rate)*args.miss_penalty}")



