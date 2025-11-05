BIN=ftrace

CFLAGS = -Wall -O0 -g 
CSRCS = ftrace.c main.c elfread.c


$(BIN): $(CSRCS)
	gcc $(CFLAGS) $(CSRCS) -o $(BIN)

run: $(BIN)
	./$(BIN)

clean:
	rm $(BIN)



