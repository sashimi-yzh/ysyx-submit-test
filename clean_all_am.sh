make clean
make -C $AM_HOME/../fceux-am clean
make -C $AM_HOME/am clean
make -C $AM_HOME/klib clean
make -C $AM_HOME/kasan clean
find $AM_HOME/../am-kernels/kernels -maxdepth 1 -type d -exec make -C {} clean \;
find $AM_HOME/../am-kernels/benchmarks -maxdepth 1 -type d -exec make -C {} clean \;
