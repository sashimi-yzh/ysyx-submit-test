SRCS = $(shell find . -name '*.cpp' -or -name '*.cc' -or -name '*.c')
INCS = -I./public

CXX = clang++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror -O2 $(INCS)
LDFLAGS = -lpthread

BUILD_DIR = build

$(shell mkdir -p $(BUILD_DIR))

TARGET = $(BUILD_DIR)/branchsim

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(BUILD_DIR)

run: $(TARGET)
	@$(TARGET)
