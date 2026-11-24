STUID = ysyx_24110012
STUNAME = 王源

# DO NOT modify the following code!!!

TRACER = tracer-ysyx
GITFLAGS = -q --author='$(TRACER) <tracer@ysyx.org>' --no-verify --allow-empty

YSYX_HOME = $(NEMU_HOME)/..
WORK_BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
WORK_INDEX = $(YSYX_HOME)/.git/index.$(WORK_BRANCH)
TRACER_BRANCH = $(TRACER)

LOCK_DIR = $(YSYX_HOME)/.git/

# prototype: git_soft_checkout(branch)
define git_soft_checkout
	git checkout --detach -q && git reset --soft $(1) -q -- && git checkout $(1) -q --
endef

# prototype: git_commit(msg)
define git_commit
	-@flock $(LOCK_DIR) $(MAKE) -C $(YSYX_HOME) .git_commit MSG='$(1)'
	-@sync $(LOCK_DIR)
endef

.git_commit:
	-@while (test -e .git/index.lock); do sleep 0.1; done;               `# wait for other git instances`
	-@git branch $(TRACER_BRANCH) -q 2>/dev/null || true                 `# create tracer branch if not existent`
	-@cp -a .git/index $(WORK_INDEX)                                     `# backup git index`
	-@$(call git_soft_checkout, $(TRACER_BRANCH))                        `# switch to tracer branch`
	-@git add . -A --ignore-errors                                       `# add files to commit`
	-@(echo "> $(MSG)" && echo $(STUID) $(STUNAME) && uname -a && uptime `# generate commit msg`) \
	                | git commit -F - $(GITFLAGS)                        `# commit changes in tracer branch`
	-@$(call git_soft_checkout, $(WORK_BRANCH))                          `# switch to work branch`
	-@mv $(WORK_INDEX) .git/index                                        `# restore git index`

.clean_index:
	rm -f $(WORK_INDEX)

_default:
	@echo "Please run 'make' under subprojects."

verify: verify_nemu verify_npc

verify_nemu:
	$(MAKE) -C nemu clean
	$(MAKE) -C nemu
	$(MAKE) -C am-kernels/tests/cpu-tests ARCH=riscv32-nemu ALL=fib run
	$(MAKE) -C am-kernels/tests/klib-tests ARCH=riscv32-nemu run

verify_nemu_dev:
	$(MAKE) -C am-kernels/kernels/typing-game ARCH=riscv32e-nemu run

verify_npc:
	$(MAKE) -C npc clean
	$(MAKE) -C npc
	$(MAKE) -C am-kernels/tests/cpu-tests ARCH=riscv32e-npc ALL=dummy run

verify_npc_h:
	$(MAKE) -C am-kernels/benchmarks/dhrystone ARCH=riscv32e-npc run
	#$(MAKE) -C am-kernels/benchmarks/coremark ARCH=riscv32e-npc run
	#$(MAKE) -C am-kernels/benchmarks/microbench ARCH=riscv32e-npc run

verify_npc_dev:
	$(MAKE) -C am-kernels/kernels/typing-game ARCH=riscv32e-npc run

.PHONY: .git_commit .clean_index _default verify
