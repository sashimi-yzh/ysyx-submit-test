run:
	verilator -Wall --trace --cc --exe --build -CFLAGS "-std=c++11" --no-timing booth_wallace_multiplier.v sim_main.cpp
	./obj_dir/Vbooth_wallace_multiplier

wave:
	gtkwave waveform.vcd

clean:
	rm -rf obj_dir waveform.vcd

.PHONY: all run wave clean

