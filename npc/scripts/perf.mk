
PERF_BENCH ?= $(CURDIR)/../am-kernels/benchmarks/microbench
PERF_ARGS ?= test
PERF_STA ?= 1

perf:
	PERF_STA=$(PERF_STA) tools/perf.sh -a $(PERF_ARGS) -n $(PERF_BENCH)
