#!/usr/bin/bash

#反汇编ELF文件
#$1 .elf文件

#ELF="${1%.bin}.elf"
ELF=$1
FILE_NAME=$(basename "${1}")
DISASM="./${FILE_NAME}.disasm"
##echo "$ELF"
##echo "$DISASM"
##riscv64-linux-gnu-objdump -d --no-show-raw-insn -M numeric,no-aliases "${ELF}" \
#        | awk '/^[[:xdigit:]]+:/ {printf "%s\t", substr($1, 1, length($1)-1); \
#        for (i=2; i<=NF; i++) { if ($i ~ /<|#/) break; printf "%s ", $i} printf "\n";}' > "${DISASM}";

riscv64-linux-gnu-objdump -d --no-show-raw-insn -M no-aliases "${ELF}" \
        | awk '/^[[:xdigit:]]+:/ {printf "%s\t", substr($1, 1, length($1)-1); \
        for (i=2; i<=NF; i++) { if ($i ~ /<|#/) break; printf "%s ", $i} printf "\n";}' > "${DISASM}";

