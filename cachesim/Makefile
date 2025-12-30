CC = cc
CFLAGS = -Wall -g
TARGET = cachesim
SOURCE = src/cachesim.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean