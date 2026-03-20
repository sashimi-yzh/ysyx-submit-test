#!/bin/bash

DONEFILE="/tmp/ysyx_dep_installed.done"

if [ -f "$DONEFILE" ]; then
	exit 0
fi

LOCKFILE="/tmp/ysxy_dep_install.lock"

DEST_CLANG_VERSION=21
DEST_CLANG=clang-$DEST_CLANG_VERSION
DEST_CLANGPP=clang++-$DEST_CLANG_VERSION

DEST_GPP_VERSION=13
DEST_GPP=g++-$DEST_GPP_VERSION

do_install_clang() {
	# 1. 获取 Clang 主版本号
	# 如果没安装 clang，这里会报错，所以加个简单的判断
	if ! command -v clang &> /dev/null; then
			CLANG_VERSION_MAJOR=0
	else
			CLANG_VERSION_MAJOR=$(clang -dumpversion | cut -f1 -d.)
	fi

	INSTALL_FLAG="./llvm21_installed.done"

	echo "Current clang version is [$CLANG_VERSION_MAJOR]"

	if [ "$CLANG_VERSION_MAJOR" -lt $DEST_CLANG_VERSION ]; then
		if [ -f /usr/bin/$DEST_CLANG ]; then
			echo "LLVM 21 is already installed."
			exit 0
		else
			echo "LLVM 21 is not installed. Proceeding with installation..."
		fi
			
		# 执行清理和安装逻辑
		# sudo apt remove -y llvm llvm-dev
		
		echo "Downloading LLVM script..."
		wget 'https://apt.llvm.org/llvm.sh' -O /tmp/llvm.sh > /dev/null
		chmod +x /tmp/llvm.sh
		
		echo "Installing LLVM $DEST_CLANG_VERSION..."
		sudo /tmp/llvm.sh $DEST_CLANG_VERSION > /dev/null
		
		# 验证安装情况
		echo "Checking installation paths:"
		ls /usr/bin | grep clang | tr '\n' ' '
		ls /usr/lib | grep llvm | tr '\n' ' '
		ls /usr/lib/clang
		sudo update-alternatives --install /usr/bin/clang clang /usr/bin/$DEST_CLANG 100
		sudo update-alternatives --install /usr/bin/clang++ clang++ /usr/bin/$DEST_CLANGPP 100
		# must set
		sudo update-alternatives --set clang /usr/bin/$DEST_CLANG
		sudo update-alternatives --set clang++ /usr/bin/$DEST_CLANGPP
		echo "clang-$DEST_CLANG_VERSION path: $(which $DEST_CLANG)"
		echo "default clang path: $(which clang)"
		echo "all clang $(which -a clang)"
		if [ "$(clang -dumpversion | cut -f1 -d.)" != "$DEST_CLANG_VERSION" ]; then
			echo "Error: clang version is not $DEST_CLANG_VERSION"
			exit 1
		fi
	fi
}

do_install_gpp() {
	GPP_VERSION=$(g++ -dumpversion)
	echo "g++ version: $GPP_VERSION"
	if [ $GPP_VERSION -lt $DEST_GPP_VERSION ]; then
			echo "g++ version is less than $DEST_GPP_VERSION"
	else
			echo "g++ version is $GPP_VERSION, no need to install."
			return
	fi
	echo "Installing g++-13 for new stdlib"
	sudo add-apt-repository ppa:ubuntu-toolchain-r/test -y > /dev/null
	sudo apt-get update > /dev/null
	sudo apt-get install g++-13 gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu -y > /dev/null
	sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/$DEST_GPP 100
	sudo update-alternatives --set g++ /usr/bin/$DEST_GPP
	echo "current g++ version: $(g++ -dumpversion)"
	if [ "$(g++ -dumpversion)" != "$DEST_GPP_VERSION" ]; then
			echo "Error: g++ version is not $DEST_GPP_VERSION"
			exit 1
	fi
}

exec 200>"$LOCKFILE"
echo "Waiting for file lock on $LOCKFILE..."
flock -x 200

# 获得锁后执行逻辑
do_install_clang
do_install_gpp
#
# echo "check ccache installation..."
# if ! command -v ccache &> /dev/null; then
# 	echo "ccache is not installed. Installing ccache..."
# 	sudo apt-get install -y ccache > /dev/null
# 	if [ $? -ne 0 ]; then
# 		echo "Error: Failed to install ccache"
# 		exit 1
# 	fi
# 	if [ ! -d "/usr/lib/ccache" ]; then
# 		echo "Error: ccache installation did not create /usr/lib/ccache"
# 		exit 1
# 	fi
# 	echo "ccache installed successfully. Adding /usr/lib/ccache to PATH."
# 	export PATH=/usr/lib/ccache:$PATH
# else
# 	echo "ccache is already installed."
# fi

touch "$DONEFILE"
