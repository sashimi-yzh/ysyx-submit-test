.PHONY: run all clean help

ARCH ?= riscv32e-ysyxsoc
RUNNER := $(CURDIR)/tools/contract_runner.py

run all:
	@python3 $(RUNNER) --root $(CURDIR) --arch $(ARCH) --all "$(ALL)" --group "$(GROUP)"

clean:
	@rm -rf build
	@find suites -name build -type d -exec rm -rf {} +

help:
	@echo "Usage:"
	@echo "  make -C am-apps/contracts ARCH=riscv32e-ysyxsoc run"
	@echo "  make -C am-apps/contracts ARCH=riscv32e-ysyxsoc ALL='klib-suite cte-basic-suite' run"
	@echo "  make -C am-apps/contracts ARCH=riscv32e-ysyxsoc ALL=klib-suite,cte-basic-suite run"
	@echo "  make -C am-apps/contracts ARCH=riscv32e-ysyxsoc GROUP=cte run"
