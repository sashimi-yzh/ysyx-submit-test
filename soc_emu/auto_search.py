import re, os

match_cache = re.compile(r"Cache hit rate : (\d\.\d+)")

log_path = "/tmp/soc_emu.log"
os.system("make build")
for m in range(6):
    for n in range(6):
        cmd = f"""make sim LOG_FILE={log_path} CACHE_N={n} CACHE_M={m}"""
        os.system(cmd + " > /dev/null")
        with open(log_path, "r") as log_file:
            lines = log_file.readlines()
            for line in lines:
                group = re.search(match_cache, line)
                if group is not None:
                    print(f"{group.group(1)}", end="\t")
    print()
