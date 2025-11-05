import subprocess
import threading

def handle_process(process, nways, nsets, bs, replace, process_id):
    try:
        for line in process.stdout:
            print(f"{nways}, {nsets}, {bs}, {replace}, {line.strip()}, {nways*nsets*bs}")
        process.wait()
    except Exception as e:
        print(f"Error in process {process_id}: {e}")

def runJobs(njobs, nways, nsets, bs, replace, access_time, miss_penalty, trace_file):
    num_processes = njobs
    processes = []
    threads = []

    for i in range(num_processes):
        args = [
            "--nways", str(nways[i]),
            "--nsets", str(nsets[i]),
            "--bs", str(bs[i]),
            "--replace", replace[i],
            "-f", trace_file,
            "--access-time", str(access_time),
            "--miss-penalty", str(miss_penalty[i])
        ]

        process = subprocess.Popen(
            ['python', '-u', 'cachesim.py'] + args,  # '-u' for unbuffered
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,  # Merge stderr into stdout
            text=True
        )
        processes.append(process)

        thread = threading.Thread(target=handle_process, args=(
            process, 
            nways[i], 
            nsets[i], 
            bs[i], 
            replace[i], 
            i + 1
        ))
        thread.start()
        threads.append(thread)

        process.stdin.close()

    # Wait for all threads to complete
    for thread in threads:
        thread.join()

def main():
    pc_trace = "pc_trace.bin.gz"
    maxJobs = 8
    ways = [1, 2, 4]
    sets = [2, 4, 8, 16]
    bs = [4, 8, 12, 16, 20, 24, 28, 32]
    replaces = ["RANDOM", "LRU", "FIFO"]
    access_time = 1
    axi_hand_shake = 30
    axi_read_time = 53

    print("ways, sets, bs, replace, hit_rate, AMAT, size")
    arg_ways = []
    arg_sets = []
    arg_bs = []
    arg_replace = []
    arg_miss_penalty = []
    for nways in ways:
        for nsets in sets:
            for nbs in bs:
                if(nways*nsets*nbs > 64):
                    continue

                for replace in replaces:  # Corrected loop variable
                    arg_ways.append(nways)
                    arg_sets.append(nsets)
                    arg_bs.append(nbs)
                    arg_replace.append(replace)
                    arg_miss_penalty.append(axi_hand_shake + axi_read_time * nbs / 4)
                    if len(arg_ways) == maxJobs:
                        runJobs(maxJobs, arg_ways, arg_sets, arg_bs, arg_replace, access_time, arg_miss_penalty, pc_trace)
                        arg_ways = []
                        arg_sets = []
                        arg_bs = []
                        arg_replace = []
                        arg_miss_penalty = []
    if len(arg_ways) > 0:
        runJobs(len(arg_ways), arg_ways, arg_sets, arg_bs, arg_replace, access_time, arg_miss_penalty, pc_trace)

if __name__ == "__main__":
    main()
