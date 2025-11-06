#top name
TOPNAME = ysyxSoCFull

NXDC_FILES = constr/ysyxSoC.nxdc #nvboard pin file

#ysyxSoC
YSYXSoC = ../ysyxSoC

# 这是因为绑定管脚的需要写入build文件夹
$(shell mkdir -p $(BUILD_DIR))

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

#verilator flag
# 将ysyxSoC/perip/uart16550/rtl和ysyxSoC/perip/spi/rtl两个目录加入verilator的include搜索路径中
VERILATOR_INC += -I$(YSYXSoC)/perip/uart16550/rtl -I$(YSYXSoC)/perip/spi/rtl
# 加入autoflush参数是为了 ​​禁用标准输出（stdout）的缓冲机制,使得每次调用 printf 或 cout 时立即刷新输出内容，而无需等待换行符（\n）或手动调用 fflush(stdout)。
VERILATOR_CFLAGS += -MMD -cc -O3 --x-assign fast --x-initial fast --noassert -autoflush
VERILATOR_CFLAGS += --trace
VERILATOR_CFLAGS += --timescale "1ns/1ns" --no-timing
VERILATOR_CFLAGS += $(VERILATOR_INC)
# 这是为了避免DPI-C在综合的时候被选中了
VERILATOR_CFLAGS += -DVERILATOR_SIM
# verilog使用的参数：是否使用YSYXSOC
VERILATOR_CFLAGS += -DYSYXSOC

# 多线程编译
VERILATOR_CFLAGS += -j

#source code
VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
# 将ysySoc/perip目录下面的所有的.v文件加入verilator的Verilog文件列表
VSRCS += $(shell find $(abspath $(YSYXSoC)/perip) -name "*.v")
VSRCS += $(shell find $(abspath $(YSYXSoC)/build) -name "*.v")
CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")

CSRCS += $(SRC_AUTO_BIND)
