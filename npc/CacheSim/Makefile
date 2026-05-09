
BUILD = ./build
CSRC = $(shell find $(abspath ./csrc) -name "*.c")
INCLUDE = ./csrc/include

ARGS ?= 

run: 
	gcc -o $(BUILD)/cachesim $(CSRC) -I$(INCLUDE)
	$(BUILD)/cachesim /home/dengzibin/ysyx-workbench/npc/CacheSim/build/pctrace_train.bin $(ARGS)