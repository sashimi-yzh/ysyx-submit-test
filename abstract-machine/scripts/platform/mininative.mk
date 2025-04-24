AM_SRCS := platform/mininative/trm.c \
           platform/mininative/ioe.c \
           platform/mininative/timer.c \
           platform/dummy/cte.c \
           platform/dummy/vme.c \
           platform/dummy/mpe.c \

CFLAGS  += -D__ISA_NATIVE__
CFLAGS  += -static

image:
	@echo + LD "->" $(IMAGE_REL)
	@$(CXX) -static -o $(IMAGE) -Wl,--whole-archive $(LINKAGE) -Wl,-no-whole-archive

run: image
	$(IMAGE)
