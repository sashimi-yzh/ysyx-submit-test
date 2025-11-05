#include "ftrace.h"
#include <stdio.h>


int main(int argc, char**argv){
    char filename_default[] = {"/home/han/Disk/Document/PROJECT/ysyx/ysyx-workbench/am-kernels/kernels/psram-test/build/psram-test-riscv32e-ysyxsoc.elf"};

    if(argc == 2)
        ftrace_init(argv[1]);
    else
        ftrace_init(filename_default);
    uint32_t pc;
    char buf[100];
    while(1){
        scanf("%x", &pc);
        ftrace_get_func_name(buf, pc);
        if(buf[0] == '\0'){
            printf("%08x\n", pc);
        }
        else{ 
            printf("%s\n", buf);
        }
        fflush(stdout);
    }
    return 0;

}   
