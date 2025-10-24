VERILATOR = verilator
VFLAGS = -Wall --cc --trace --exe -Wno-EOFNEWLINE --top-module fpu_tb

all: fpu_sim

fpu_sim: fpu.v fregs.v fpu_tb.v amultiplier.v divider.v sim_main.cpp
	$(VERILATOR) $(VFLAGS) $^ -o $@
	make -C obj_dir -f Vfpu_tb.mk fpu_sim
	mv obj_dir/fpu_sim .

run: fpu_sim
	./fpu_sim

clean:
	rm -rf obj_dir fpu_sim fpu_waveform.vcd fpu_test_ops.log fpu_test_vector.hex test
runc:
	gcc test.c -o test -lm
	./test

.PHONY: all run clean
