import threading, queue, time, subprocess
import argparse
import pty, os, sys


parser = argparse.ArgumentParser()
parser.add_argument('--timeout', type=int, default=3600)
parser.add_argument('--good', type=str, default="HIT GOOD TRAP")
parser.add_argument('--bad', type=str, default="HIT BAD TRAP")
parser.add_argument("cmd", nargs=argparse.REMAINDER)
args = parser.parse_args()

keys = {"success": args.good, "error": args.bad}
state = "empty"

buffer = bytearray()
def read_line(fd, buffer_size=1024):
    global buffer
    if not (b'\n' in buffer):
        while True:
            # 每次读取buffer_size字节
            try:
                chunk = os.read(fd, buffer_size)
            except OSError:
                break
            if not chunk:  # 文件结束
                break

            buffer.extend(chunk)
            # 检查是否包含换行符
            if b'\n' in buffer:
                break

    # 分割出第一行（含换行符）
    if b'\n' in buffer:
        line_end = buffer.index(b'\n') + 1
        line = buffer[:line_end]
        # 剩余数据保留在缓冲区
        buffer = buffer[line_end:]
    else:
        line = bytes(buffer)
        buffer.clear()
        if line == bytearray():
            return None

    return line.decode().rstrip('\r\n')

def monitor_output(proc, result_queue):
    global state
    global master
    while True:
        line = read_line(master)
        if line == None:
            break
        print(line)
        for s, k in keys.items():
            if k in line:
                state = s
                result_queue.put("match")
                proc.kill()
                return

    result_queue.put("end")

master, slave = pty.openpty()
proc = subprocess.Popen(args.cmd, stdout=slave, text=True)
os.close(slave)

result_queue = queue.Queue()
monitor_thread = threading.Thread(target=monitor_output, args=(proc, result_queue))
monitor_thread.start()

try:
    result = result_queue.get(timeout=args.timeout)
except queue.Empty:
    proc.kill()
    print("Kill the process due to timeout")

if state == "empty":
    print(sys.argv[0] + ": Keyword not detected")
    exit(1)
if state == "error":
    print("sys.argv[0]" + ": Detect bad trap")
    exit(1)
