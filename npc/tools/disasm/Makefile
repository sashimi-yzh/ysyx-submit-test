TARGET= disasm
CXX = g++
CXXFLAGS = -O2 -Wall
CXXFLAGS += $(shell llvm-config --cxxflags) -fexceptions
LDFLAGS = $(shell llvm-config --ldflags --libs --system-libs)
CSRCS = $(shell find . -name "*.cc" -or -name "*.cpp")


$(TARGET):$(CSRCS)
	$(CXX) $(CXXFLAGS) $(CSRCS) $(LDFLAGS) -o $(TARGET)

run:$(TARGET)
	./$(TARGET)
clean:
	rm $(TARGET)
