#include<stdlib.h>
#include<assert.h>
#include "cpu/cpu.h"
#include "monitor/sdb.h"
#include "memory/pmem.h"
#define USE_NVBOARD 1

void init_monitor(int, char *[]);
void free_monitor();
int main(int argc,char**argv){
    Verilated::commandArgs(argc, argv);

    init_monitor(argc,argv);

    sdb_main_loop();

    free_monitor();


    //nvboard_update();
    return is_exit_status_bad();

}
