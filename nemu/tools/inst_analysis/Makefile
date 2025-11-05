TARGET=instAnaly
SRCS=instAnaly.c 
LDFLAGS= -lz
CFLAGS=-Wall -O3

$(TARGET):$(SRCS)
	gcc $(LDFLAGS) $(CFLAGS) -o $@ $<


run: $(TARGET)
	./$(TARGET) pc_trace.bin.gz microbench-riscv32-nemu.elf.disasm

tiny_run: $(TARGET)
	./$(TARGET) pc_trace.bin_sum.gz sum-riscv32-nemu.elf.disasm

train_run:$(TARGET)
	bash disasm.sh microbench-riscv32-nemu_train.elf
	./$(TARGET) pc_trace.bin_train.gz microbench-riscv32-nemu_train.elf.disasm

test_run:$(TARGET)
	bash disasm.sh microbench-riscv32-nemu_test.elf
	./$(TARGET) pc_trace.bin_test.gz microbench-riscv32-nemu_test.elf.disasm

clean:
	-rm $(TARGET)


