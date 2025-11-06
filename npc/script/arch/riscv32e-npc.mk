#top name
TOPNAME = ysyx_24100006

NXDC_FILES = constr/npc.nxdc #nvboard pin file
#verilator flag
VERILATOR_CFLAGS += -MMD -cc -O3 --x-assign fast --x-initial fast --noassert -autoflush
VERILATOR_CFLAGS += --trace
VERILATOR_CFLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_CFLAGS += -DVERILATOR_SIM
# verilog使用的参数：是否使用NPC，这里是为了综合才只能使用NPC，因为在综合的时候没有这个参数，所以就不会走这个分支
VERILATOR_CFLAGS += -DNPC

#source code
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")