update-buildtools:
	$(YSYX_HOME)/init-deps/check-and-install-buildtools.sh

# not install when clean anything
# ifneq ($(filter clean%,$(MAKECMDGOALS)),)
# -include always-make.mk
# endif
