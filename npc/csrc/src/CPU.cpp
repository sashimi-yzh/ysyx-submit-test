#include "VysyxSoCFull.h"
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "config.hpp"
#include "sdb.hpp"
#include "ftrace.hpp"

#include <nvboard.h>

uint8_t mrom[0x8000000]; // 128MB mrom
uint8_t flash[0x1000000]; // 16MB flash
uint8_t psram[0x1000000]; //16MB psram
uint16_t sdram[4][8192][512]; // 4 banks, 8192 rows, 512 columns
uint8_t vbuf[640*480*4]; // 640*480 vga buffer

uint64_t cycle_cnt = 0;
uint64_t instr_cnt = 0;
uint64_t ihit_cnt = 0;
uint64_t ifetch_cnt = 0;
bool bootloader_stage = true;

bool exit_flag = false;
enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void load_bin(const char *path) {
    FILE *fp = fopen(path, "rb");
    assert(fp != NULL);
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    assert(size <= (long)sizeof(flash));
    size_t ret = fread(flash, 1, size, fp);
    assert(ret == (size_t)size);
    fclose(fp);
}

VysyxSoCFull* cpu = new VysyxSoCFull;
VerilatedVcdC* tfp = new VerilatedVcdC;
void init_disasm();
char *elf_file = NULL;

extern "C" {
void difftest_init(int port);
void difftest_memcpy(uint32_t addr, void *buf, size_t n, bool direction);
void difftest_regcpy(void *dut, bool direction);
}

void nvboard_bind_all_pins(VysyxSoCFull *top);

typedef struct {
  uint32_t gpr[16];
  uint32_t pc;
} CPU_state;

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);

    Verilated::commandArgs(argc, argv);
    if(argc > 2){
        load_bin(argv[1]);
        elf_file = argv[2];
    } else {
        printf("Usage: %s <binary> <elf_file>\n", argv[0]);
        assert(0);
    }

    nvboard_bind_all_pins(cpu);
    nvboard_init();

#ifdef WAVEON
    Verilated::traceEverOn(true);
#endif

#ifdef WAVEON
    cpu->trace(tfp, 99);
    tfp->open("cpu.vcd");
#endif

#ifdef FTRACE
    init_elf();
#endif

#ifdef ITRACE
    init_disasm();
#endif

#ifdef DIFFTEST
    difftest_init(1234);
    difftest_memcpy(0x80000000, mem, sizeof(mem), DIFFTEST_TO_REF);
#endif

    cpu->contextp()->time(0);
    cpu->eval();

    //reset assert 100 cycles
    while(cpu->contextp()->time() < 100 && !exit_flag) {
        cpu->contextp()->timeInc(1);
        cpu->clock = 0;
        cpu->reset = 1;
        cpu->eval();
    #ifdef WAVEON
        tfp->dump(cpu->contextp()->time());
    #endif

        cpu->contextp()->timeInc(1);
        cpu->clock = 1;
        cpu->reset = 1;
        cpu->eval();
    #ifdef WAVEON
        tfp->dump(cpu->contextp()->time());
    #endif
    }

    sdb_set_batch_mode();

    sdb_mainloop();

#ifdef WAVEON
    tfp->close();
    delete tfp;
#endif

#ifdef FTRACE
    extern ftrace_t ftrace_info;
    if (ftrace_info.symtab) {
        free(ftrace_info.symtab);
        ftrace_info.symtab = NULL;
    }
    if (ftrace_info.strtab) {
        free(ftrace_info.strtab);
        ftrace_info.strtab = NULL;
    }
#endif

    nvboard_quit();
    delete cpu;
    return 0;
}