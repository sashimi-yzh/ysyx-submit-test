REPO_PATH = repo
CAPSTONE_H = $(REPO_PATH)/include/capstone/capstone.h

ifeq ($(shell uname -s),Linux)
suffix = so.5
else ifeq ($(shell uname -s),Darwin)
suffix = 5.dylib
else
  $(error Unsupported OS ($(shell uname -s)))
endif

CAPSTONE = $(REPO_PATH)/libcapstone.$(suffix)

$(CAPSTONE_H):
	git clone --depth=1 -b 5.0.6 git@github.com:capstone-engine/capstone.git $(REPO_PATH)

$(CAPSTONE): $(CAPSTONE_H)
	cd $(REPO_PATH) && CAPSTONE_ARCHS="riscv" bash make.sh

clean:
	@test ! -d $(REPO_PATH) || $(MAKE) -C $(REPO_PATH) clean

all: $(CAPSTONE)
.DEFAULT_GOAL = all

.PHONY: all clean
