CSRCS = $(wildcard $(SOC_EMU_HOME)/src/*.cpp)
INC = $(SOC_EMU_HOME)/include

OPTIMFLAGS = -Ofast   \
-march=native -mtune=native \
-funroll-loops -flto=auto -ffast-math -fno-math-errno \
-funsafe-math-optimizations

CXXSTD = -std=c++23

SPDLOG_FLAGS = -DSPDLOG_USE_STD_FORMAT

EMU_CXXFLAGS = -I$(INC) $(SPDLOG_FLAGS) $(CXXSTD) $(OPTIMFLAGS)

CXX = g++

MDIR = $(SOC_EMU_HOME)/build

$(MDIR):
	mkdir -p $@ || true

OBJDIR := $(MDIR)/obj
OBJS := $(patsubst $(SOC_EMU_HOME)/src/%.cpp,$(OBJDIR)/%.o,$(CSRCS))

DEPS := $(OBJS:.o=.d)

DEPFLAGS = -MMD -MP

build: $(MDIR)/soc_emu

$(MDIR)/soc_emu: $(OBJS)
	@echo "LINK $(notdir $@)"
	@$(CXX) $(EMU_CXXFLAGS) -o $@ $^

-include $(DEPS)

$(OBJDIR)/%.o: $(SOC_EMU_HOME)/src/%.cpp | $(OBJDIR)
	@echo "CXX $(shell basename $<)"
	@$(CXX) $(EMU_CXXFLAGS) $(DEPFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $@

TIME_STAMP := $(shell date +"%Y_%m_%d_%H_%M_%S")
BIN ?= $(SOC_EMU_HOME)/images/microbench_test.bin
LOG_DIR ?= $(SOC_EMU_HOME)/logs
LOG_FILE ?= $(LOG_DIR)/$(TIME_STAMP).log
ICACHE_N ?= 2
ICACHE_M ?= 3
DCACHE_N ?= 0
DCACHE_M ?= 0
BTB_N ?= 2


$(LOG_DIR):
	mkdir -p $@ || true

sim: build $(LOG_DIR)
	$(MDIR)/soc_emu --image $(BIN) \
	--nr_icacheline $(ICACHE_N) --nr_icachesize $(ICACHE_M) \
	--nr_dcacheline $(DCACHE_N) --nr_dcachesize $(DCACHE_M) \
	--nr_btbsize $(BTB_N) \
	--log $(LOG_FILE)

clean:
	rm -rf build

.PHONY: build clean sim
