#!/usr/bin/python

import os
import sys
import subprocess
#
# while True:
#     line = sys.stdin.readline()
#     sys.stderr.write(line)
#
def waveRead():
    times = []
    vars_  = []
    args = []
    name = ""
    while True:
        sys.stderr.write("Waiting for read...\n")
        line = sys.stdin.readline()
        sys.stderr.write(line)
        if(line.startswith("#")):
            times.append(line[1:-1])
        elif(line.startswith("b")):
            vars_.append(line[1:].split(" ")[0])
        elif(line.startswith("$comment")):
            comment = line.split(" ")
            if(comment[1] == "args"):
                arg_str = line.split("\"")[1]
                args = arg_str.split(" ")
            elif(comment[1] == "data_end"):
                break;
            elif(comment[1] == "name"):
                name = comment[2]

    # times列表长度会比vals列表大一
    if(len(times) != len(vars_) + 1):
        sys.stderr.write("Error: len(times) != len(vars)+1\n")
    return times,vars_,args,name

def get_out(args,vals_):
    process = subprocess.Popen(args,
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True,
                bufsize=1,
                universal_newlines=True
    )
    vals_out = []
    for val in vals_:
        val_num = int(val,2)
        process.stdin.write(f"{hex(val_num)[2:]}\n")
        process.stdin.flush()
        val_out = process.stdout.readline()
        vals_out.append(val_out)
    process.terminate()

    return vals_out


def waveParse(times, vals_, args):
    times_out = []
    vals_out = []
    lastVal_out = ""
    sys.stderr.write("start Parsing....\n")
    vals_out_tmp = get_out(args,vals_)
    for time,var_out_tmp in zip(times[0:len(times)-1], vals_out_tmp):

        if(var_out_tmp != lastVal_out):
            lastVal_out = var_out_tmp
            times_out.append(time)
            vals_out.append(var_out_tmp)
    times_out.append(times[-1])
    return times_out, vals_out

def waveOut(times, vals_, name):
    sys.stderr.write("start output...\n");
    sys.stdout.write(f"$name {name}\n")
    sys.stdout.flush()
    for time,var in zip(times[0:len(times)-1], vals_):
        sys.stdout.write(f"#{time} ")
        sys.stdout.flush()
        sys.stdout.write(f"{var}\n")
        sys.stdout.flush()
    sys.stdout.write(f"{time}\n")
    sys.stdout.flush()
    sys.stdout.write("$finish\n")
    sys.stdout.flush()
    sys.stderr.write("end output\n")
def main():
    sys.stderr.write("starting program...\n")
    times, vars_, args, name = waveRead()
    times_out, vars_out = waveParse(times, vars_, args)
    waveOut(times_out, vars_out, name)




if __name__ == "__main__":
    main()
