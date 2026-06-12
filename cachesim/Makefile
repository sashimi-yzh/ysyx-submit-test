SRC_DIR = src
BUILD_DIR = build
$(shell mkdir -p $(BUILD_DIR))
BINARY = $(BUILD_DIR)/cachesim

SRCS = $(shell find $(SRC_DIR) -name '*.c')
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC = gcc
CFLAGS = -O3 -flto -g -std=gnu11 -lm 

all: $(BINARY)

debug: CFLAGS += -O0 -ggdb3 -fsanitize=undefined -fsanitize=leak -fsanitize=address
debug: $(BINARY)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c -o $@ $^ $(CFLAGS)

$(BINARY): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf $(BUILD_DIR)
