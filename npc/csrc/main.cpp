#include <circuit.h>
#include <my_memory.h>
#include <utils.h>

void reset_cpu(int n);
void single_cycle();
void init_wave();
void close_wave();
void init_monitor(int , char **);
void sdb_mainloop();

int main(int args,char *argv[]) {
    get_time();
    init_wave();
    init_monitor(args, argv);
    Verilated::commandArgs(args, argv);
    reset_cpu(10);
    
    sdb_mainloop();

    close_wave();
    return 0;
}
