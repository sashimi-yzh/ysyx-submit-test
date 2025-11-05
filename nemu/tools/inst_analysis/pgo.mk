# 定义变量
TARGET=instAnaly
SRCS=instAnaly.c 
LDFLAGS= -lz
CFLAGS=-Wall -O3

# 默认目标，执行完整的 PGO 流程
all: pgo

# 第一步：编译带有性能分析支持的程序
$(TARGET)_gen: $(SRCS)
	gcc $(CFLAGS) -fprofile-generate -o $@ $< $(LDFLAGS)

# 第二步：运行程序以收集性能数据
run: $(TARGET)_gen
	./$(TARGET)_gen pc_trace.bin.gz microbench-riscv32-nemu.elf.disasm

tiny_run: $(TARGET)_gen
	./$(TARGET)_gen pc_trace.bin_sum.gz sum-riscv32-nemu.elf.disasm

train_run:$(TARGET)_gen
	./$(TARGET)_gen pc_trace.bin_train.gz microbench-riscv32-nemu_train.elf
# 第三步：使用性能数据重新编译程序
$(TARGET)_pgo: $(SRCS)
	gcc $(CFLAGS) -fprofile-use -o $@ $< $(LDFLAGS)

# 完整的 PGO 流程
pgo: $(TARGET)_gen train_run $(TARGET)_pgo

# 清理生成的文件
clean:
	-rm -f $(TARGET)_gen $(TARGET)_pgo *.gcda *.gcno

