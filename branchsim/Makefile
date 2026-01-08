CC = cc
CFLAGS = -Wall -g
TARGET = branchsim
SOURCE = src/branchsim.c

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean