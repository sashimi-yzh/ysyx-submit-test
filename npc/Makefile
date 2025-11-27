# Verilator 编译选项：
# -MMD: 生成 .d 依赖文件，支持增量编译
# -build: 生成可执行文件
# -cc: 生成 C++ 代码
# -O3: 最高级别优化
# --x-assign fast: 允许 X 值快速赋值，提高仿真效率
# --x-initial fast: 允许 X 初值优化
# --noassert: 关闭 Verilator 内部的 assert
VERILATOR_CFLAGS += -MMD --build -cc  --autoflush \
				-O3 --x-assign fast --x-initial fast --noassert \
				--timescale "1ns/1ns" --no-timing

CURRDIR ?= $(shell pwd)

IVERILOG_FLAG = -g2012 -I$(CURRDIR)/vsrc/ \
					-I$(CURRDIR)/vsrc/IDU \

# 顶层模块名称
TOPNAME ?= ysyx_25040111 # ysyxSoCFull

# ysyxSoC 目录
SOC_DIR = $(CURRDIR)/../ysyxSoC

ARGS ?= 

IMG ?=

# 获取所有 Verilog 源文件（`vsrc` 目录下的 `.v` 文件）
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")

NETLIST ?= # result/ysyx_25040111-500MHz/ysyx_25040111.netlist.fixed.v
CELLS ?= # /home/dallous/Documents/yosys-sta/pdk/nangate45/sim/cells.v

ifeq ($(TOPNAME), ysyxSoCFull)
VSRCS += $(shell find $(SOC_DIR)/perip -name "*.v")
VSRCS += $(SOC_DIR)/build/ysyxSoCFull.v
endif

RTL_FILE = $(VSRCS)

# 获取所有 C/C++ 源文件（`csrc` 目录下的 `.c`、`.cc`、`.cpp` 文件）
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")


# C++ 编译选项：
ifeq ($(TOPNAME), ysyxSoCFull)
INCFLAGS = $(addprefix -I, $(NVBOARD_HOME)/usr/include)
INCFLAGS += -DRUNSOC=1
endif

INCFLAGS += -I$(CURRDIR)/csrc/inc/
INCFLAGS += -I$(CURRDIR)/csrc/uinc/

CXXFLAGS += $(INCFLAGS) # -g
VERILATOR_CFLAGS +=	-Wno-UNOPTFLAT \
					-I$(CURRDIR)/vsrc/ \
					-I$(CURRDIR)/vsrc/IDU \
					-Mdir build/$(TOPNAME)

ifeq ($(TOPNAME), ysyxSoCFull)
VERILATOR_CFLAGS +=	-I$(SOC_DIR)/perip/uart16550/rtl \
					-I$(SOC_DIR)/perip/spi/rtl \
					-DRUNSOC=1
endif


# LDFLAGS 添加链接库
LDFLAGS += -L/usr/lib/x86_64-linux-gnu -lreadline -lhistory

ifeq ($(TOPNAME), ysyxSoCFull)
include $(NVBOARD_HOME)/scripts/nvboard.mk
endif

all: sim

# simple sim test
sim: $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@mkdir -p build
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator $(VERILATOR_CFLAGS) \
		--trace --top-module ${TOPNAME} $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) $(addprefix -LDFLAGS , $(LDFLAGS)) \
		--exe -o top

sta: verilog
	make -C/home/dallous/Documents/yosys-sta/ \
		RTL_FILES=$(CURRDIR)/build/ysyx_25040111.v \
		DESIGN=ysyx_25040111 \
		O=$(CURRDIR)/result \
		CLK_PORT_NAME=clock sta

# gtkwave
gtkwave:
	@if [ -f waveform/waveform.vcd ]; then \
		/mnt/d/Tools/gtkwave64/bin/gtkwave.exe waveform/waveform.vcd; \
	else \
		echo "\033[31mPlease include and use <verilated_vcd_c.h> to create waveform.vcd\033[31m"; \
	fi

# build and run
run: sim
	./build/$(TOPNAME)/top $(ARGS)

verilog:
	@mkdir -p build
	@iverilog -g2012 -E -DYOSYS_STA -I$(CURRDIR)/vsrc/ \
		-I$(CURRDIR)/vsrc/IDU -obuild/ysyx_25040111.v $(VSRCS)

sim-iverilog: verilog
	@mkdir -p build/isim
	@rm -f build/isim/sim-iverilog.hex
	@riscv64-linux-gnu-objcopy -Ibinary -O verilog $(IMG) build/isim/sim-iverilog.hex
	@iverilog $(IVERILOG_FLAG) -DHEX_PATH="\"$(CURRDIR)/build/isim/sim-iverilog.hex\""\
		-o $(CURRDIR)/build/isim/itop $(CURRDIR)/build/ysyx_25040111.v isim.v $(CURRDIR)/vsrc/ysyx_25040111_sram.v
	@vvp build/isim/itop

sim-iverilog-netlist:
	@mkdir -p build/netlist
	@rm -f build/netlist/sim-iverilog-netlist.hex
	@riscv64-linux-gnu-objcopy -Ibinary -O verilog $(IMG) build/netlist/sim-iverilog-netlist.hex
	@iverilog $(IVERILOG_FLAG) -DHEX_PATH="\"$(CURRDIR)/build/netlist/sim-iverilog-netlist.hex\""\
		-o $(CURRDIR)/build/netlist/itop $(NETLIST) $(CELLS) isim.v $(CURRDIR)/vsrc/ysyx_25040111_sram.v
	@vvp build/netlist/itop

pref:
	make -C/home/dallous/Documents/ysyx-workbench/am-kernels/benchmarks/microbench/ \
		ARCH=riscv32e-ysyxsoc run mainargs=test

clean:
	@rm -rf build
	@rm -rf waveform
	@rm -rf result

include ../Makefile
