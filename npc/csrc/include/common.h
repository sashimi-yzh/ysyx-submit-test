#pragma once
#include <stdint.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <VysyxSoCFull__Dpi.h>
#include "VysyxSoCFull.h"
#include "verilated.h"

// difftest
#define REG_NUM 16
extern long long bin_size;
extern uint32_t rom[];
extern uint8_t memory[];
extern uint32_t flash[];
extern uint8_t psram[];

extern std::string build_dir;

typedef uint32_t word_t;
typedef uint32_t vaddr_t;

void sdb_mainloop(int argc, char **argv);

// memory

int mem_read(int addr);
void mem_write(int addr, int data, char wmask);
int mem_print(uint32_t addr, int len);

void init_mem(const std::string &filename);

void init_rom(const std::string &path);
void init_flash(const std::string &path);

// device io
#define SERIAL_PORT 0x10000000
#define RTC 0x10000004
#define RTC_UPTIME 0x10000028

void add_device(uint32_t begin_addr, int len, uint32_t (*read)(int addr), void (*write)(int addr, int data, char wmask));
bool handle_mmio_write(int addr, int data, char wmask);
bool handle_mmio_read(int addr, int &data);

void init_devices();

void init_serial();
void init_timer();

// performance event
void print_performance_counters();

void run_cache_dse();
void run_cache_single();

void run_btb_dse();
