#include ~/ysyx-workbench/Makefile
TOPNAME = ysyxSoCFull
NXDC_FILES = ./constr/top.nxdc
INC_PATH ?=
INC_DIR := ./include
VERILATOR = verilator
VERILATOR_CFLAGS += -MMD --build -cc  \
				-O3 --x-assign fast --x-initial fast --noassert
BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir

default: $(BIN)

#$(shell mkdir -p $(BUILD_DIR))

NEMU_SO_PATH :=  $(NEMU_HOME)/build/riscv32-nemu-interpreter-so# NEMU动态库路径
NEMU_SO := $(if $(wildcard $(NEMU_SO_PATH)),$(NEMU_SO_PATH),)# 检查 NEMU SO 文件是否存在，存在则使用，不存在则为空
VERILOG_NPC_GENERATED := $(BUILD_DIR)/ysyx_25080222.v
ysyxSoC_HOME = $(AM_HOME)/../ysyxSoC
ysyxSoC_PERIP_FILES := $(shell find $(ysyxSoC_HOME)/perip -name '*.v')
ysyxSoC_TOP_FILE := $(ysyxSoC_HOME)/build/ysyxSoCFull.v
#ysyxSoC_TOP_FILE := $(ysyxSoC_HOME)/build/ysyxSoCFull_APB.v
CFLAGS := -I $(abspath $(INC_DIR)) #指定头文件目录,获取绝对路径 
#CFLAGS := -I$(INC_DIR)
LDFLAGS := -Wl,-rpath,$(dir $(NEMU_SO)) $(NEMU_SO) -ldl# 动态链接

# constraint file
SRC_AUTO_BIND = $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $^ $@

# project source
VSRCS = $(ysyxSoC_TOP_FILE) $(VERILOG_NPC_GENERATED) $(ysyxSoC_PERIP_FILES)
CSRCS = $(shell find $(abspath ./src) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
#IVSRCS = $(shell find $(abspath ./iverilog) -name "*.v")
IVSRCS = $(shell find ./iverilog -name "*.v")
NETLIST := ./netlist/ysyx_25080222.netlist.fixed.v
CELLS := ./netlist/cells.v

# rules for NVBoard
include $(NVBOARD_HOME)/scripts/nvboard.mk

# rules for verilator
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME="\"V$(TOPNAME)\""

#make ARCH=riscv32e-ysyxSoC run 在SoC环境下
verilog:
#$(call git_commit, "generate verilog")
	mkdir -p $(BUILD_DIR)
	mill -i npc_cloud.runMain npc_cloud.TopMain
#cat $(BUILD_DIR)/npc_cloud_cpu.v $(BUILD_DIR)/npc_cloud_DPI_C.v $(BUILD_DIR)/ysyx_25080222_pc.v > $(BUILD_DIR)/ysyx_25080222.v
#rm -f $(BUILD_DIR)/npc_cloud_cpu.v $(BUILD_DIR)/npc_cloud_DPI_C.v $(BUILD_DIR)/ysyx_25080222_pc.v
	@mv $(BUILD_DIR)/firrtl_black_box_resource_files.f  $(BUILD_DIR)/ysyx_25080222.anno.json  $(BUILD_DIR)/ysyx_25080222.fir ./out

sim: verilog $(VSRCS) $(CSRCS) $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
#$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@echo "sim with ysyxsoc"
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME)\
		$(VSRCS) $(CSRCS) $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)\
		--trace \
		--autoflush \
		-Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
		-I$(ysyxSoC_HOME)/perip/uart16550/rtl \
		-I$(ysyxSoC_HOME)/perip/spi/rtl \
		--timescale "1ns/1ns" \
		--no-timing \
		$(addprefix +define+, NPC_CLOUD_SIM) \
		$(addprefix -CFLAGS , $(CFLAGS) $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BUILD_DIR)/$(TOPNAME))

#IMG ?= ./rtthread.bin

run: sim
#$(call git_commit, "run cpu") # DO NOT REMOVE THIS LINE!!!
	@echo "Loading image: $(IMG)"
	@echo "Loading others: $(ARGS) "
	@echo "Loading NEMU SO: $(NEMU_SO)"
	$(BUILD_DIR)/$(TOPNAME) $(IMG)  -b -e $(ARGS) -d $(NEMU_SO) 

#make ARCH=riscv32e-npc run 没有SoC的环境
sim-npc: verilog $(VERILOG_NPC_GENERATED) $(CSRCS)
	@echo "sim without ysyxsoc"
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--prefix VysyxSoCFull \
		--top-module ysyx_25080222\
		$(VERILOG_NPC_GENERATED) $(CSRCS) \
		--trace \
		--autoflush \
		-Wall -Wno-DECLFILENAME -Wno-UNUSEDSIGNAL \
		--timescale "1ns/1ns" \
		--no-timing \
		+define+PC_INIT="32'h80000000" \
		$(addprefix +define+, NPC_CLOUD_SIM) \
		$(addprefix -CFLAGS , $(CFLAGS) $(CXXFLAGS) -DNPC_WITHOUT_SOC=1) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BUILD_DIR)/$(TOPNAME))


run-npc: sim-npc
#$(call git_commit, "run cpu") # DO NOT REMOVE THIS LINE!!!
	@echo "Loading image: $(IMG)"
	@echo "Loading ELF: $(ARGS) "
	@echo "Loading NEMU SO: $(NEMU_SO)"
	$(BUILD_DIR)/$(TOPNAME) $(IMG) -b -e $(ARGS) npc -d $(NEMU_SO) 

#用iverilog进行四值仿真
sim-iverilog: verilog $(VERILOG_NPC_GENERATED) $(IVSRCS)
	@echo "Icarus Verilog simulation."
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo "Loading image: $(IMG)"
	objcopy -I binary -O verilog --verilog-data-width=4 $(IMG) $(OBJ_DIR)/program.hex
	iverilog \
		-s sim_top \
		$(VERILOG_NPC_GENERATED) $(IVSRCS) \
		-g2012 \
		-D__ICARUS__ \
		-o $(OBJ_DIR)/sim.vvp
	vvp -n $(OBJ_DIR)/sim.vvp

#用iverilog进行四值仿真
sim-iverilog-netlist: $(NETLIST) $(CELLS) $(IVSRCS)
	@echo "Icarus Verilog netlist simulation"
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo "Loading image: $(IMG)"
	objcopy -I binary -O verilog --verilog-data-width=4 $(IMG) $(OBJ_DIR)/program.hex
	iverilog \
		-s sim_top \
		$(NETLIST) $(CELLS) $(IVSRCS) \
		-g2012 \
		-D__ICARUS__ \
		-o $(OBJ_DIR)/sim.vvp
	vvp -n $(OBJ_DIR)/sim.vvp

clean:
	rm -rf out $(BUILD_DIR)
	rm -f wave.vcd


perf: $(BIN)
	@echo "复现历史版本性能测试..."
	@# 从当前提交信息中提取IMG路径
	$(eval HISTORY_IMG := $(shell git log -1 --pretty=format:%B | grep "^IMG=" | cut -d= -f2))
	@if [ -z "$(HISTORY_IMG)" ]; then \
		echo "错误: 该提交没有记录测试程序信息"; \
		exit 1; \
	fi
	@echo "使用历史测试程序: $(HISTORY_IMG)"
	$(BIN) $(HISTORY_IMG) -b -d $(NEMU_SO)


.PHONY: default all clean run perf verilog sim



# Verilator的手册中Argument Summary：
# 文件相关：
# <file.v> Verilog包、模块和顶层模块文件名
# <file.c/cc/cpp> 可选的C++文件进行编译
# <file.a/o/so> 可选的C++文件进行链接
# 语言版本：
# +1364-1995ext+<ext> 使用Verilog 1995，文件扩展名为<ext>
# +1364-2001ext+<ext> 使用Verilog 2001，文件扩展名为<ext>
# +1364-2005ext+<ext> 使用Verilog 2005，文件扩展名为<ext>
# +1800-2005ext+<ext> 使用SystemVerilog 2005，文件扩展名为<ext>
# +1800-2009ext+<ext> 使用SystemVerilog 2009，文件扩展名为<ext>
# +1800-2012ext+<ext> 使用SystemVerilog 2012，文件扩展名为<ext>
# +1800-2017ext+<ext> 使用SystemVerilog 2017，文件扩展名为<ext>
# +1800-2023ext+<ext> 使用SystemVerilog 2023，文件扩展名为<ext>
# 断言和调试：
# --no-assert 禁用所有断言
# --no-assert-case 禁用unique/unique0/priority-case断言
# --autoflush 在所有$display后刷新流
# 行缓冲是C标准库中I/O流的一种缓冲策略。
# 当程序使用标准输出函数（如printf）时，数据并不会立即被发送到目的地（如屏幕），
# 而是先被存放在一个内存缓冲区中，等到特定条件满足时(缓冲区满了、遇见换行符 \n、手动调用 fflush（刷新）)，
# 缓冲区的内容才会被"刷新"（即真正输出）。
# --bbox-sys 黑盒化未知的$system调用
# --bbox-unsup 黑盒化不支持的语言特性
# 构建选项：
# --binary 构建模型二进制文件
# --build Verilation后构建可执行文件/库
# --build-dep-bin <filename> 覆盖构建依赖的Verilator二进制文件
# --build-jobs <jobs> --build的并行度
# --cc 创建C++输出
# -CFLAGS <flags> makefile的C++编译器参数
# --compiler <compiler-name> 为指定的C++编译器调优
# --compiler-include 在预编译头中包含额外头文件
# 覆盖率和收敛：
# --coverage 启用所有覆盖率
# --coverage-expr 启用表达式覆盖率
# --coverage-expr-max <value> 表达式允许的最大排列数
# --coverage-line 启用行覆盖率
# --coverage-max-width <width> 覆盖率的最大数组深度
# --coverage-toggle 启用翻转覆盖率
# --coverage-underscore 启用_信号的覆盖率
# --coverage-user 启用SVL用户覆盖率
# 预处理和调试：
# -D<var>[=<value>] 设置预处理器定义
# --debug 启用调试
# --debug-check 启用调试断言
# --no-debug-leak 在--debug模式下禁用内存泄漏
# --debugi <level> 在指定级别启用调试
# 输出控制：
# --no-decoration 禁用注释和降低间距级别
# --decorations <level> 设置输出注释和间距级别
# --default-language <lang> 默认解析语言
# DPI和转储：
# --dpi-hdr-only 仅生成DPI头文件
# --dump-<srcfile> 启用源文件中所有内容的转储
# --dump-defines 显示-E的预处理器定义
# 构建系统：
# --exe 链接创建可执行文件
# --expand-limit <value> 设置展开优化限制
# -F <file> 从文件解析参数（相对路径）
# -f <file> 从文件解析参数
# 优化和性能：
# --flatten 强制内联所有模块、任务和函数
# -fno-<optimization> 禁用内部优化阶段
# -G<name>=<value> 覆盖顶层参数
# 帮助和版本：
# --gdb 在GDB交互模式下运行Verilator
# --gdbbt 在GDB下运行Verilator进行回溯
# --generate-key 为--protect-key创建随机密钥
# --get-supported <feature> 获取是否支持某个功能
# --help 显示此帮助
# 层次化设计：
# --hierarchical 启用层次化Verilation
# --hierarchical-params-file <name> 内部选项，指定层次块的参数文件
# 包含目录：
# -I<dir> 搜索include文件的目录
# +incdir+<dir> 搜索include文件的目录
# JSON和链接：
# --no-json-edit-nums 不在.tree.json文件中转储editNum
# --json-only 创建JSON解析器输出
# -LDFLAGS <flags> makefile的链接器预对象参数
# 本地化和主函数：
# --lib-create <name> 创建DPI库
# +libext+<ext>+[ext]... 查找模块的扩展名
# --lint-only 仅进行lint检查，不生成输出
# --main 生成C++ main()文件
# Make和目录：
# --make <build-tool> 为指定的构建工具生成脚本
# -MAKEFLAGS <flags> 在--build期间传递给make的参数
# --max-num-width <value> 最大数字宽度（默认：64K）
# --Mdir <directory> 输出对象目录的名称
# 模块和输出：
# --MMD 创建.d依赖文件
# --mod-prefix <topname> 预置到较低类别的名称
# --MP 创建伪依赖目标
# 优化级别：
# -o <executable> 最终可执行文件的名称
# -O0 禁用优化
# -O3 高性能优化
# -O<optimization-letter> 可选择的优化
# 引脚和端口：
# --pins-bv <bits> 为顶层端口指定类型
# --pins-inout-enables 为inout创建__en和__out信号
# --no-pins64 不对33-64位信号使用uint64_t
# 预处理和分析：
# --pipe-filter <command> 将所有输入通过脚本过滤
# --pp-comments 显示-E的预处理器注释
# --prefix <topname> 顶层类的名称
# 分析和保护：
# --prof-c 使用性能分析编译C++代码
# --prof-cfuncs 为性能分析命名函数
# --protect-ids 哈希标识符名称以进行混淆
# 公共和参数：
# --public 将信号标记为public
# --public-depth <level> 标记public到指定的模块深度
# -pvalue+<name>=<value> 覆盖顶层参数
# 安静模式：
# --quiet 最小化额外打印
# --quiet-exit 失败时不打印命令
# 重循环和报告：
# --reloop-limit <value> 形成循环的最小迭代次数
# --report-unoptflat 为UNOPTFLAT提供额外诊断
# 运行时和SystemC：
# --runtime-debug 启用模型运行时调试
# --savable 启用模型保存恢复
# --sc 创建SystemC输出
# 统计和标准：
# --stats 创建统计文件
# --stats-vars 提供变量统计信息
# --no-std 阻止加载标准文件
# 结构和线程：
# --structs-packed 将所有未打包结构转换为打包结构
# -sv 启用SystemVerilog解析
# 时序和跟踪：
# --threads <threads> 启用多线程
# --timescale <timescale> 设置默认时间尺度
# --timing 启用时序支持
# --no-timing 禁用时序支持
# 追踪和波形：
# --top-module <topname> 顶层输入模块的名称
# --trace 启用VCD波形创建
# --trace-depth <levels> 追踪深度
# 未使用和版本：
# --unused-regexp <regexp> 调整UNUSED lint信号
# -V 详细版本和配置
# -v <filename> Verilog库
# 验证和警告：
# --version 显示程序版本并退出
# --vpi 启用VPI编译
# -Wall 启用所有样式警告
# -Werror-<message> 将警告转换为错误
# 工作目录和其他：
# -Wno-<message> 禁用警告
# -work <libname> 为后续文件设置配置库
# -Wpedantic 在合规性测试问题上警告
# X值处理：
# --x-assign <mode> 将非初始X分配为此值
# --x-initial <mode> 将初始X分配为此值
# --x-initial-edge 启用初始X->0和X->1边沿触发
# XML输出：
# --xml-only 创建XML解析器输出
# --xml-output XML输出文件名
# -y <dir> 搜索模块的目录



#1: 一般性错误。通常表示构建过程中发生了未指定的错误。
#2: 语法错误。Makefile文件中存在语法错误。
# 127: 找不到要执行的命令。这通常是由于系统无法找到指定的命令或脚本。
# 126: 执行的命令无法执行。通常是由于权限问题或者脚本没有执行权限。
# 139：与段错误有关的错误。这可能是由于程序在执行期间引起了段错误，可能是由于访问无效的内存地址等原因。


