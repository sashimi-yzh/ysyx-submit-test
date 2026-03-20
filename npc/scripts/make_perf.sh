#!/bin/bash
export ARCH=riscv32e-ysyxsoc
export MAKE_PERF=1
rm ./build/bin/*
make -C ../am-kernels/benchmarks/microbench run VSIM_difftest=0 mainargs=train SAN_FLAGS=
