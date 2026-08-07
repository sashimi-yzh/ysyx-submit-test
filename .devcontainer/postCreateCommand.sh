export GIT_SSH_COMMAND="ssh -o StrictHostKeyChecking=accept-new"
git config --global user.email "1481542813@qq.com"
git config --global user.name "WuShFeng"
git submodule sync
git submodule update --init --force
git clone git@github.com:WuShFeng/rt-thread-am.git /workspaces/rt-thread-am --depth=1
git fetch origin tracer-ysyx --depth 1
git branch tracer-ysyx origin/tracer-ysyx
// ysyxSoC
make -C ysyxSoC dev-init
cd ysyxSoC && git checkout ysyx6 && cd -
// am-kernels
cd am-kernels && git checkout master && cd -
// yosys-sta
cd yosys-sta && git checkout master && cd -
// nvboard
cd nvboard && git checkout master && cd -
// fceux-am
cd fceux-am && git checkout master && cd -
