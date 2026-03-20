#!/bin/bash
sudo apt update
sudo apt install -y gcc-multilib g++-multilib
sudo apt install -y gcc-riscv64-linux-gnu
# force fix
# see https://ysyx.oscc.cc/docs/ics-pa/2.2.html#%E8%BF%90%E8%A1%8C%E7%AC%AC%E4%B8%80%E4%B8%AAc%E7%A8%8B%E5%BA%8F
sudo sed -i 's|# include <gnu/stubs-ilp32.h>|// # include <gnu/stubs-ilp32.h>|g' /usr/riscv64-linux-gnu/include/gnu/stubs.h

sudo apt install -y build-essential    # build-essential packages, include binary utilities, gcc, make, and so on
sudo apt install -y libreadline-dev    # a library used later
sudo apt install -y libsdl2-dev        # a library used later

# nemu KConfig
sudo apt install -y bison flex

# nvboard dependencies
sudo apt install -y libsdl2-image-dev libsdl2-ttf-dev

# for npc
sudo apt install -y verilator

sudo apt install -y ccache

# 如果你安装过 mill 可以删掉下面所有
cd ysyx-workbench/npc
curl -L https://repo1.maven.org/maven2/com/lihaoyi/mill-dist/1.1.2/mill-dist-1.1.2-mill.sh -o mill
chmod +x mill

# 在此处根据你的环境选择如何切换 Java 版本
# 总之需要切换到 Java 21（因为旧版本 mill 的签名不兼容 Java 25 及更新版本）
# Github Codespaces 中默认安装了 sdkman 和 Java 21.0.9-ms，直接使用即可

# 如果你使用 sdkman 管理 Java 且没有安装 Java 21
# 取消注释下面一行
# sdk install java 21.0.9-ms
sdk use java 21.0.9-ms

# 询问是否替换全局 mill
read -p "是否将 mill 设置为全局可用？(y/n) " -n 1 -r
echo    # (optional) move to a new line
if [[ $REPLY =~ ^[Yy]$ ]]; then
    sudo mv mill /usr/local/bin/mill
fi

./mill version
