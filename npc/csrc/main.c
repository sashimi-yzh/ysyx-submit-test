// no rst/clk for top module, so
// remove rst and clk update here

// use x0 to test as it is always 0 which make it
// easy for testing
void init_monitor(int, char *[]);

void engine_start();
int is_exit_status_bad();

int main(int argc, char** argv) {

    init_monitor(argc, argv);

    engine_start();

    return is_exit_status_bad();
}
