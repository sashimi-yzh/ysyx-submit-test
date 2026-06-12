ifeq ($(MAKECMDGOALS),run)
ifeq ($(PCTRACE),)
$(error Need PCTRACE=<pctrace.bin.xz>)
endif
ifeq ($(BTRACE),)
$(error Need BTRACE=<btrace.bin.xz>)
endif
ifeq ($(ELF),)
$(error Need ELF=<binary>)
endif
ifeq ($(OUTPUT),)
$(error Need OUTPUT=<afdo path>)
endif
endif

SRC_DIR = src
BUILD_DIR = build
$(shell mkdir -p $(BUILD_DIR))
BINARY = $(BUILD_DIR)/trace2fdo

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = gcc
CFLAGS = -O3 -flto -ggdb3 -std=gnu11 -lm

TEXT_FILE = $(basename $(OUTPUT)).txt

all: $(BINARY)

run: all
	$(BINARY) $(PCTRACE) $(BTRACE) $(TEXT_FILE)
	create_gcov --profiler text --profile $(TEXT_FILE) \
		--gcov $(OUTPUT) --binary $(ELF) --gcov_version 2

debug: CFLAGS += -O0 -ggdb3 -fsanitize=undefined -fsanitize=leak -fsanitize=address
debug: $(BINARY)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

$(BINARY): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: run all debug clean
