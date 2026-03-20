REPO_PATH = repo
ifeq ($(wildcard $(REPO_PATH)/Makefile),)
  $(shell git clone --depth=1 https://github.com/WangYiJie020/ysyx-workbench-nemu-inst-gen.git $(REPO_PATH))
endif

ifeq ($(NO_VENV),1)
VENV_PATH = /usr/local
else
VENV_PATH = $(abspath $(REPO_PATH)/.venv)
endif
VENV_CREATED = $(VENV_PATH)/bin/python
VENV_DONE = ./venv.done

OUT_DIR = $(abspath ./build)
$(shell mkdir -p $(OUT_DIR))

RISCV_UNIFIED_DB_GIT_DIR ?= ~/gitclones/riscv-unified-db/

default: $(VENV_DONE)
	$(MAKE) -C $(REPO_PATH) VENV=$(VENV_PATH) BUILD_DIR=$(OUT_DIR) RISCV_UNIFIED_DB_GIT_DIR=$(RISCV_UNIFIED_DB_GIT_DIR)

$(VENV_CREATED):
	$(shell python3 -m venv $(VENV_PATH))

$(VENV_DONE): $(VENV_CREATED)
	$(VENV_PATH)/bin/pip install -r $(REPO_PATH)/requirements.txt
	touch $@

clean:
	$(MAKE) -C $(REPO_PATH) clean

.PHONY: default clean
