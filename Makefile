STUID = ysyx_26010008
STUNAME = 严晨瑞

# DO NOT modify the following code!!!

TRACER = tracer-ysyx
GITFLAGS = -q --author="$(TRACER) <tracer@ysyx.org>" --no-verify --allow-empty

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
	trap "" INT; \
		flock $(LOCK_DIR) $(MAKE) -C $(YSYX_HOME) .git_commit MSG='$(1)'; \
		sync $(LOCK_DIR); \
	trap - INT;
endef

.git_commit:
	@bash -c ' \
		trap "" INT; \
		while (test -e .git/index.lock); do sleep 0.1; done; \
		git branch $(TRACER_BRANCH) -q 2>/dev/null || true; \
		cp -a .git/index $(WORK_INDEX); \
		$(call git_soft_checkout, $(TRACER_BRANCH)); \
		git add . -A --ignore-errors; \
		(echo "> $(MSG)" && echo "$(STUID)" "$(STUNAME)" && uname -a && uptime) | git commit -F - $(GITFLAGS); \
		$(call git_soft_checkout, $(WORK_BRANCH)); \
		mv $(WORK_INDEX) .git/index; \
	'

.clean_index:
	rm -f $(WORK_INDEX)

# count:
# 	find ./nemu -type f -name '*.c' -o -name '*.h' | xargs cat |\
# 		perl -n -e 'print if m/.+/' | wc -l

_default:
	@echo "Please run 'make' under subprojects."

.PHONY: .git_commit .clean_index _default count
