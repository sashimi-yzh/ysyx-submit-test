#!/bin/sh

if [ $# -ne 2 ]; then
		echo "Usage : $0 <dir> <CPU_DESIGN_NAME>"
		exit 1
fi

SEARCH_DIR=$1

VSRCS=$(find $SEARCH_DIR -name "*.sv")

echo "# Inserting verilator public_on/off in $SEARCH_DIR"

for src in $VSRCS; do
	sed -i '1i /*verilator public_on*/' $src
	sed -i -e '$a /*verilator public_off*/' $src
done

echo "# Renaming layer$ to $2_ in $SEARCH_DIR"

for src in $VSRCS; do
	sed -i "s/layer\$\(\w\+\)/$2_\1/g" $src
done
