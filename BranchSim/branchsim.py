import gzip
import argparse
import struct
from bpu import *

class BranchSimulator:
    def __init__(self, bpu, address_size=4):
        self.address_size = address_size  # 每个地址的字节数，4或8
        self.bpu = bpu
        self.hit = 0
        self.miss = 0   

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

                inst_bytes = f.read(4)  # 4 bytes
                if not inst_bytes or len(inst_bytes) < 4:
                    break
                inst = struct.unpack('<I', inst_bytes)[0]

                taken_bytes = f.read(1)  # 1 Byte
                if not taken_bytes or len(taken_bytes) < 1:
                    break
                taken = struct.unpack('B', taken_bytes)[0]

                # 预测分支
                prediction = self.bpu.predict(address, inst)
                correct = prediction == taken
                self.bpu.update(address, taken, correct)
                if(correct):
                    self.hit += 1
                else:
                    self.miss += 1
                # 输出预测结果
                # print(f"Address: {address}, Instruction: {inst}, Predicted: {prediction}, Actual: {taken}, Correct: {correct}")
            return {"hit": self.hit, "miss": self.miss, "accuracy": self.hit / (self.hit + self.miss)}

# bpu = BPU(address_size=4, prediction_method='saturating')
# simulator = BranchSimulator(bpu=bpu, address_size=4)
# result = simulator.run("btrace_test.bin.gz")

# acc = result["accuracy"]
# print(f"{acc}")


def main():
    parser = argparse.ArgumentParser(description="Branch Prediction Simulator")
    parser.add_argument('-f','--file', required=True, help="Branch Trace file(.bin.gz)")
    parser.add_argument("--address-size", type=int, default=4, help="Size of the address in bytes (4 or 8)")
    parser.add_argument("--bits", type=int, required=True, help="Bit-width of the prediction counter")
    parser.add_argument("--table-size", type=int, required=True, help="Size of the branch prediction table")
    parser.add_argument("--prediction-method", type=str, default='saturating', help="Prediction method (static, always_taken, saturating)")
    args = parser.parse_args()

    bpu = BPU(address_size=args.address_size, prediction_method=args.prediction_method, bits = args.bits, table_size= args.table_size)
    simulator = BranchSimulator(bpu=bpu, address_size=args.address_size)
    result = simulator.run(args.file)
    acc = result["accuracy"]
    print(f"accuracy: {acc}")
    # print(result)

if __name__ == "__main__":
    main()