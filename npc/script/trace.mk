# 这个运行在npc目录下运行
PF_TRACE_NUM = $(NPC_HOME)/tools/performance-trace/perf_trace_num.py
PF_TRACE_TIME = $(NPC_HOME)/tools/performance-trace/perf_trace_time.py
PF_TRACE1 = $(NPC_HOME)/tools/performance-trace/trace.csv
PF_TRACE2 = $(NPC_HOME)/tools/performance-trace/trace2.csv
#pf_trace
pft_num:
	python $(PF_TRACE_NUM)
pft_time:
	python $(PF_TRACE_TIME)
#perf
MICROBENCH_DIR = $(AM_KERNEL_HOME)/benchmarks/microbench
perf:
	make -C $(MICROBENCH_DIR) ARCH=riscv32e-ysyxsoc run mainargs=train

#rtt
RTT_DIR = /home/lq/rtt/rt-thread-am/bsp/abstract-machine
rtt:
	make -C $(RTT_DIR) ARCH=riscv32e-ysyxsoc run

# 下面为面积可视化的配置
# 配置参数
SCRIPT = $(NPC_HOME)/tools/area-count/plot_module_areas.py
INPUT_FILE = $(NPC_HOME)/result/ysyx_24100006-430MHz/synth_stat.txt
OUTPUT_DIR = $(NPC_HOME)/build

# 默认目标
all: analyze plot

# 分析并生成结果
analyze:
	@echo "Analyzing module areas from $(INPUT_FILE)"
	python $(SCRIPT) $(INPUT_FILE) $(OUTPUT_DIR)
