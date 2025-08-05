import threading, queue, time, subprocess
import argparse
import pty, os, sys


parser = argparse.ArgumentParser()
parser.add_argument('--timeout', type=int, default=3600)
parser.add_argument('--good', type=str, default="HIT GOOD TRAP")
parser.add_argument('--middle', type=str, default="MicroBench PASS")
parser.add_argument('--bad', type=str, default="HIT BAD TRAP")
parser.add_argument("cmd", nargs=argparse.REMAINDER)
args = parser.parse_args()

keys = {"good": args.good, "middle": args.middle, "bad": args.bad}
state = "empty"
state_rtt = "empty"
            # input                  string for success
rtt_input = [('help',                 'am_hello'),
             ('am_hello',             'Hello, AbstractMachine!'),
             ('am_microbench',        'MicroBench PASS'),
             (f'echo "{args.good}"',  args.good)]

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
            if b'msh />' in buffer:  # for rt-thread
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
    global state_rtt
    global master
    global rtt_input
    rtt_ans = ""
    while True:
        line = read_line(master)
        if line == None:
            break
        print(line)
        if state_rtt == "rtt-monitor":
            if rtt_ans in line:
                state_rtt = "empty"
        else:
            if line == "msh />" and rtt_input != []:
                proc.stdin.write(rtt_input[0][0] + '\n')
                proc.stdin.flush()
                rtt_ans = rtt_input[0][1]
                state_rtt = "rtt-monitor"
                rtt_input = rtt_input[1:]
        for s, k in keys.items():
            if k in line:
                if not (s == "good" and state != "middle"):
                    state = s
                if state == "good" or state == "bad":
                    result_queue.put("match")
                    proc.kill()
                    return

    result_queue.put("end")

master, slave = pty.openpty()
proc = subprocess.Popen(args.cmd, stdin=subprocess.PIPE, stdout=slave, text=True)
os.close(slave)

result_queue = queue.Queue()
monitor_thread = threading.Thread(target=monitor_output, args=(proc, result_queue))
monitor_thread.start()

try:
    result = result_queue.get(timeout=args.timeout)
except queue.Empty:
    proc.kill()
    print("Kill the process due to timeout")

if state == "good":
    print(sys.argv[0] + ": Keyword detected, OK!")

if state == "empty":
    print(sys.argv[0] + ": Keyword not detected")
    exit(1)
if state == "bad":
    print("sys.argv[0]" + ": Detect bad trap")
    exit(1)
