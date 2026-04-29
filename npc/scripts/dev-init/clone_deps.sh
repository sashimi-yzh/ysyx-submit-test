#!/bin/bash
gcld1() {
    git clone --depth=1 "$@"
}
mkdir -p $1
cd $1
gcld1 https://github.com/androidoffsec/baremetal_kasan.git
gcld1 https://github.com/riscv/riscv-unified-db.git
gcld1 https://github.com/gabime/spdlog.git
gcld1 https://github.com/RinHizakura/mini-gdbstub.git
gcld1 https://github.com/p-ranav/tabulate.git
gcld1 https://github.com/nlohmann/json.git

cd riscv-unified-db
git fetch --depth=1 origin d91b7d4ca6bfeaf1afab3af521a266dc5b92e4c7 
git checkout d91b7d4ca6bfeaf1afab3af521a266dc5b92e4c7
cd ..
