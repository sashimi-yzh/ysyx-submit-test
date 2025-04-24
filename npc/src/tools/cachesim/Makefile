BIN = build/cachesim

$(BIN): cachesim.c
	mkdir -p $(@D)
	gcc -O2 -Wall -Werror -o $@ $^

run: $(BIN)
	./$^ icache $(NEMU_HOME)/inst.trace
	./$^ dcache $(NEMU_HOME)/mem.trace

.PHONY: run
