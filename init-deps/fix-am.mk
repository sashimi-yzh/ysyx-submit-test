AM_FIX_DONE = $(YSYX_HOME)/.am_fix_done
AM_KERNELS_HOME = $(YSYX_HOME)/am-kernels

$(AM_FIX_DONE):
	@if [ -d $(AM_KERNELS_HOME) ]; then \
		echo "Fixing am-kernels cpu patch..."; \
		cd $(AM_KERNELS_HOME) && git am $(YSYX_HOME)/patch/am-kernels/tests/cpu-tests/*.patch; \
		touch $@; \
	else \
		echo "am-kernels directory not found."; \
		exit 1; \
	fi

always-make-patch-am.mk: $(AM_FIX_DONE)

-include always-make-patch-am.mk
