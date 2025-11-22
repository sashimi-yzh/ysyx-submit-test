VERILATOR = verilator
VERILATOR_FLAGS = -cc --exe --build -j 4 -Wall

all: sim

sim: divider.v divider_main.cpp
	$(VERILATOR) $(VERILATOR_FLAGS) -o divider_sim divider.v divider_main.cpp

run: sim
	./obj_dir/divider_sim

clean:
	rm -rf obj_dir *.vcd

.PHONY: all sim run clean