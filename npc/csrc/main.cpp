#include "verilated.h"
#include "verilated_vcd_c.h"
#include "VysyxSoCFull.h"
#include <cstdint>
#include <stdio.h>
#include <stdint.h>
#include <getopt.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <capstone/capstone.h>
#include <sys/time.h>
#ifdef SOC
  #include <nvboard.h>
#endif
#include <sys/stat.h>
#include <sys/types.h>

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

#define PMEM_SIZE        0x8000000
#define FLASH_SIZE       0x1000000
#define PSRAM_SIZE       0x20000000
#define SDRAM_SIZE       0x20000000
#define SRAM_SIZE        0x1000000

#define CONFIG_SRAMBASE  0x0f000000
#define CONFIG_SDRAMBASE 0xa0000000
#define PMEM_SIZE_SOC    0x1000
#define CONFIG_MBASE     0x80000000
#define CONFIG_MBASE_SOC 0x20000000
#define CONFIG_FLASHBASE 0x30000000
#define CONFIG_PSRAMBASE 0x80000000

#define LOAD_IMG_TO_FLASH    0
#define START_FROM_MROM      0
#define M_R_TRACE            0
#define M_W_TRACE            0
#define M_R_ASSERT           1
#define M_W_ASSERT           1
#define PC_ASSERT            1
#define REG_ASSERT           1
#define DIFFTESE             0
#define BMODE                1
#define WATCHPOINT           0
#define WAVE                 0
#define PC_NO_CHANGE_DECETE  1
#define ITRACE_FILE          0
#define INST_NOT_VALID_CHECK 1
#define BTRACE_FILE          0
#define PRINT_REG            0
#define PERF_FILE            0

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;
static VysyxSoCFull dut;
#ifdef SOC
  void nvboard_bind_all_pins(VysyxSoCFull* top);
#endif


int trap = 0;
static char *img_file = NULL;
csh handle;
uint32_t gpr[32];
int top_pc;
int top_dnpc;
int top_inst;
int top_inst_valid;

uint8_t pmem[PMEM_SIZE] = {
  0x13,0x04,0x00,0x00,
  0x17,0x91,0x00,0x00,
  0x13,0x01,0xc1,0xff,
  0xef,0x00,0xc0,0x00,
  0x13,0x05,0x00,0x00,
  0x67,0x80,0x00,0x00,
  0x13,0x01,0x41,0xff,
  0x17,0x05,0x00,0x00,
  0x13,0x05,0xc5,0x01,
  0x23,0x24,0x11,0x00,
  0xef,0xf0,0x9f,0xfe,
  0x13,0x05,0x05,0x00,
  0x73,0x00,0x10,0x00,
  0x6f,0x00,0x00,0x00,  
};

uint8_t flash[FLASH_SIZE] = {
  0x13,0x04,0x00,0x00,
  0x17,0x91,0x00,0x00,
  0x13,0x01,0xc1,0xff,
  0xef,0x00,0xc0,0x00,
  0x13,0x05,0x00,0x00,
  0x67,0x80,0x00,0x00,
  0x13,0x01,0x41,0xff,
  0x17,0x05,0x00,0x00,
  0x13,0x05,0xc5,0x01,
  0x23,0x24,0x11,0x00,
  0xef,0xf0,0x9f,0xfe,
  0x13,0x05,0x05,0x00,
  0x73,0x00,0x10,0x00,
  0x6f,0x00,0x00,0x00,  
};

uint8_t psram[PSRAM_SIZE] = {
  0x13,0x04,0x00,0x00,
  0x17,0x91,0x00,0x00,
  0x13,0x01,0xc1,0xff,
  0xef,0x00,0xc0,0x00,
  0x13,0x05,0x00,0x00,
  0x67,0x80,0x00,0x00,
  0x13,0x01,0x41,0xff,
  0x17,0x05,0x00,0x00,
  0x13,0x05,0xc5,0x01,
  0x23,0x24,0x11,0x00,
  0xef,0xf0,0x9f,0xfe,
  0x13,0x05,0x05,0x00,
  0x73,0x00,0x10,0x00,
  0x6f,0x00,0x00,0x00,  
};

typedef struct {
  uint32_t gpr[32];
  uint32_t pc;
} CPU_state;

const char *regs[] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6"
};
static char* rl_gets() {
  static char *line_read = NULL;

  if (line_read) {
    free(line_read);
    line_read = NULL;
  }

  line_read = readline("(npc) ");

  if (line_read && *line_read) {
    add_history(line_read);
  }

  return line_read;
}

static long load_img_mrom() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if(!fp){
    assert(0);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("Start from mrom The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(pmem, size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

long load_img_txt_flash() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *file = fopen(img_file, "r");
  if (!file) {
      printf("无法打开文件: %s\n", img_file);
      return -1;
  }

  char line[256];
  long data_count = 0;
  
  while (fgets(line, sizeof(line), file)) {
      if (strlen(line) <= 1) continue;
      if (line[0] == '@') {
          printf("发现地址: %s", line);
          continue;
      }
      
      char* token = strtok(line, " \t\n");
      while (token != NULL) {
          int valid = 1;
          for (int i = 0; token[i] != '\0'; i++) {
              if (!isxdigit(token[i])) {
                  valid = 0;
                  break;
              }
          }
          
          if (valid && strlen(token) <= 2) {
              unsigned int value;
              sscanf(token, "%x", &value);
              flash[data_count++] = (unsigned char)value;
          }
          
          token = strtok(NULL, " \t\n");
      }
  }
  
  fclose(file);
  return data_count;
}

static long load_img_flash() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if(!fp){
    assert(0);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("Start from flash The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(flash, size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

static long load_img_to_flash(char *img) {
  if (img == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img, "rb");
  if(!fp){
    assert(0);
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  printf("The image is %s, size = %ld\n", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(flash, size, 1, fp);
  assert(ret == 1);

  fclose(fp);
  return size;
}

bool capstone_init(csh *handle) {
    if (cs_open(CS_ARCH_RISCV, CS_MODE_RISCV32, handle) != CS_ERR_OK) {
        printf("Failed to initialize Capstone\n");
        return false;
    }
    return true;
}

void AssembleDecoder(csh handle, uint32_t instruction, uint32_t pc) {
    cs_insn *insn;
    size_t count;

    count = cs_disasm(handle, reinterpret_cast<uint8_t*>(&instruction), sizeof(instruction), 0x1000, 1, &insn);
    if (count > 0) {
        for (size_t i = 0; i < count; i++) {
            printf("\33[1;34mnpc execute pc = 0x%08x, inst = 0x%08x,\t%s\t%s\033[0m\n",top_pc, top_inst, insn[i].mnemonic, insn[i].op_str);
            // printf("0x%lx:\t%s\t%s\n", insn[i].address, insn[i].mnemonic, insn[i].op_str);
        }
        cs_free(insn, count);
    } else {
        printf("Failed to disassemble given code!\n");
        printf("\33[1;34mnpc execute pc = 0x%08x, inst = 0x%08x\033[0m\n",top_pc, top_inst);

    }
}


void step_and_dump_wave(){
  dut.eval();
  if(WAVE){
    if(((top_pc & 0xF0000000) >> 28) == 0xA || ((top_pc & 0xF0000000) >> 28) == 0xB){
      contextp->timeInc(1);
      tfp->dump(contextp->time());
    } 
  }
}

FILE *itracefile;
FILE *btracefile;
FILE *perffile;
char wavePath[512];
void open_log_file(){
  const char *NPC_HOME = getenv("NPC_HOME");
  const char *itrace = "/log/itrace.txt";
  const char *btrace = "/log/btrace.txt";
  const char *perf =   "/log/perf.txt";
  const char *wave =   "/log/dump.vcd";
  char itracePath[512];
  char btracePath[512];
  char perfPath[512];
  
  if (NPC_HOME != NULL) {
      snprintf(itracePath, sizeof(itracePath), "%s%s", NPC_HOME, itrace);
      snprintf(btracePath, sizeof(btracePath), "%s%s", NPC_HOME, btrace);
      snprintf(perfPath,   sizeof(perfPath),   "%s%s", NPC_HOME, perf);
      snprintf(wavePath,   sizeof(wavePath),   "%s%s", NPC_HOME, wave);
      if(ITRACE_FILE){
        itracefile = fopen(itracePath, "w");
        if (itracefile == NULL) {
          printf("Failed to open itrace file\n");
          return;
        } 
      }
      if(BTRACE_FILE){
        btracefile = fopen(btracePath, "w");
        if (btracefile == NULL) {
          printf("Failed to open btrace file\n");
          return;
        } 
      }
      if(PERF_FILE){
        perffile = fopen(perfPath, "w");
        if (perffile == NULL) {
          printf("Failed to open perf file\n");
          return;
        } 
      }
  } else {
    printf("NPC_HOME is NULL\n");
    return;
  }
}

void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedVcdC;
  contextp->traceEverOn(true);
  dut.trace(tfp, 99);
  if(WAVE){
    tfp->open(wavePath);
  }
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

void system_rst(){
  dut.clock = 0;
  dut.reset = 0;
  step_and_dump_wave();
  dut.clock = 1;
  dut.reset = 1;
  step_and_dump_wave();
  dut.clock = 0;
  step_and_dump_wave();
  for(int i = 0; i < 20; i++){
    dut.clock = 1;
    step_and_dump_wave();
    dut.clock = 0;
    step_and_dump_wave();
  }
  dut.reset = 0;
  step_and_dump_wave();
}

uint8_t* guest_to_host(uint32_t paddr) { return pmem + paddr - CONFIG_MBASE; }
uint8_t* guest_to_host_soc(uint32_t paddr) { return pmem + paddr - CONFIG_MBASE_SOC; }
uint8_t* guest_to_host_flash(uint32_t paddr) { return flash + paddr - CONFIG_FLASHBASE; }
uint8_t* guest_to_host_psram(uint32_t paddr) { return psram + paddr - CONFIG_PSRAMBASE; }

static inline uint32_t host_read(void *addr, int len) {
  switch (len) {
    case 1: return *(uint8_t  *)addr;
    case 2: return *(uint16_t *)addr;
    case 4: return *(uint32_t *)addr;
    default: assert(0); return 0;
  }
}

static inline void host_write(void *addr, int len, uint32_t data) {
  switch (len) {
    case 1: *(uint8_t  *)addr = data; return;
    case 2: *(uint16_t *)addr = data; return;
    case 4: *(uint32_t *)addr = data; return;
    default: assert(0); return;
  }
}

static uint32_t pmem_read(uint32_t addr, int len) {
  uint32_t ret = host_read(guest_to_host(addr), len);
  return ret;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-h", table, NULL)) != -1) {
    switch (o) {
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void isa_reg_display() {
  printf("Name    DEC         HEX\n");
  for (int i = 0; i < 32; i++){
    printf("%-3s     %-10u  0x%08x\n", regs[i], gpr[i], gpr[i]);
  }
}

uint64_t sum_ifu_clock_time = 0;
uint64_t ifu_clock_time_num = 0;
uint64_t icache_hit_count = 0;
uint64_t icache_miss_count = 0;
uint64_t icache_miss_count_branch = 0;
uint64_t miss_counter_branch_c = 0;
uint64_t all_counter_branch_c = 0;
extern "C" void IFU_clktime_count(int ifu_clk_count,int hit){
  //printf("%d\n",ifu_clk_count);
  sum_ifu_clock_time = sum_ifu_clock_time + ifu_clk_count;
  ifu_clock_time_num++;
  if(hit){
    icache_hit_count++;
  }
}
extern "C" void icahce_miss_count(int miss_count){
  icache_miss_count = miss_count;
}
extern "C" void icahce_miss_count_branch(int miss_count_branch){
  icache_miss_count_branch = miss_count_branch;
}
uint64_t sum_lsu_clock_time = 0;
uint64_t lsu_clock_time_num = 0;
extern "C" void LSU_clktime_count(int lsu_clk_count){
  //printf("%d\n",lsu_clk_count);
  sum_lsu_clock_time = sum_lsu_clock_time + lsu_clk_count;
  lsu_clock_time_num++;
}
extern "C" void branch_count(int all_counter_branch,int miss_counter_branch){
  //printf("%d\n",ifu_clk_count);
  all_counter_branch_c = all_counter_branch;
  miss_counter_branch_c = miss_counter_branch;
}

uint64_t IFU_getinst = 0;
uint64_t LSU_getdata = 0;
uint64_t EXU_fincal = 0;
extern "C" void Performance_Counters(int Performancetype){
  if(Performancetype == 1){
    IFU_getinst++;
  }
  if(Performancetype == 2){
    LSU_getdata++;
  }
  if(Performancetype == 3){
    EXU_fincal++;
  }
}

extern "C" void psram_read(uint32_t addr, uint32_t *data) {
	if(addr >= 0 && addr <= PSRAM_SIZE){
		*data = host_read(psram+addr,4);
    if(M_R_TRACE){
      printf("psramR->addr: 0x%08x, len: %d, mem: 0x%08x\n", addr, 4, *data);
    }
	}else{
    if(M_R_ASSERT){
      assert(0);
    }
	}
}
extern "C" void psram_write(uint32_t addr, uint32_t data,uint32_t mask) {
	if(addr >= 0 && addr <= PSRAM_SIZE){
		uint32_t wdata = data >> ((8-mask)*4);
		host_write(psram+addr,mask/2,wdata);
    if(M_R_TRACE){
      printf("psramW->addr: 0x%08x, len: %d, mem: 0x%08x\n", addr, 4, data);
    }
	}else{
		if(M_W_ASSERT){
      assert(0);
    }
	}
}

extern "C" void flash_read(int32_t addr, int32_t *data) { 
  addr += CONFIG_FLASHBASE;
  if(addr - CONFIG_FLASHBASE > FLASH_SIZE){
    if(M_R_ASSERT){
      assert(0);
    }
    return;
  }
  else{
    *data = host_read(guest_to_host_flash(addr & ~0x3), 4);
    if(M_R_TRACE){
      printf("flashR->addr: 0x%08x, len: %d, mem: 0x%08x\n", addr & ~0x3, 4, *data);
    }
    return;
  }
}

extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  if(addr - CONFIG_MBASE_SOC > 0xfff){
    if(M_R_ASSERT){
      assert(0);
    }
    return;
  }
  else{
    *data = host_read(guest_to_host_soc(addr & ~0x3), 4);
    if(M_R_TRACE){
      printf("mromR->addr: 0x%08x, len: %d, mem: 0x%08x\n", addr & ~0x3, 4, *data);
    }
    return;
  }
}

extern "C" void ebreak(){
  trap = 1;
  // printf("excute the ebreak inst!!!\n");
}

extern "C" void npc_trap(int pc, int ret){
  printf("npc execute ebreak at pc = 0x%08x\n",pc);
  if(ret == 0){
    printf("\33[1;32mHIT GOOD TRAP!\033[0m\n");
  }
  else{
    printf("\33[1;31mHIT BAD TRAP!\033[0m\n");
  }
}

extern "C" void get_pc_inst(int pc, int dnpc, int inst, int EXU_valid_int){
  top_pc = pc;
  top_dnpc = dnpc;
  top_inst = inst;
  top_inst_valid = EXU_valid_int;
}

extern "C" void reg_out(const int array[32]) {
  for (int i = 0; i < 16; ++i) {
    gpr[i] = array[i];
  }
  for (int i = 16; i < 31; ++i) {
    gpr[i] = 0;
  }
}

extern "C" void rtl_pmem_write (int w_mem_addr, int w_mem_data, char w_mem_len){
  if(M_W_TRACE){
    printf("npcW->addr: 0x%x, len: %d, mem: 0x%08x\n", w_mem_addr, w_mem_len, w_mem_data);
  }
  if(w_mem_addr - CONFIG_MBASE > PMEM_SIZE){
    if (w_mem_addr == 0x000003f8) { 
      //putchar((char)(w_mem_data & 0xFF)); 
      if(M_W_ASSERT){
        assert(0);
      }
    }
    else{
      if(M_W_ASSERT){
        assert(0);
      }
    }
  }
  else{
    //printf("npcW->addr: 0x%x, len: %d, mem: 0x%08x\n", w_mem_addr, w_mem_len, w_mem_data);
    host_write(guest_to_host(w_mem_addr), w_mem_len, w_mem_data);
  }
}
extern "C" void sram_write_print (int w_mem_addr, int w_mem_data, char w_mem_len){
  if(M_W_TRACE){
    printf("sramW->addr: 0x%x, len: %d, mem: 0x%08x\n", w_mem_addr, w_mem_len, w_mem_data);
  }
}
static uint64_t boot_time = 0;

static uint64_t get_time_internal() {
  struct timeval now;
  gettimeofday(&now, NULL);
  uint64_t us = now.tv_sec * 1000000 + now.tv_usec;
  return us;
}

uint64_t get_time() {
  if (boot_time == 0) boot_time = get_time_internal();
  uint64_t now = get_time_internal();
  return now - boot_time;
}

static uint32_t rtc_port_base[2];

extern "C" int rtl_pmem_read(int r_mem_addr){
  if(r_mem_addr - CONFIG_MBASE > PMEM_SIZE){
    if(M_R_TRACE){
      printf("npcR->addr: 0x%x, len: %d\n", r_mem_addr, 4);
    }
    // if (r_mem_addr == 0xa0000048 + 4) { 
    //   uint64_t us = get_time();
    //   rtc_port_base[0] = (uint32_t)us;
    //   rtc_port_base[1] = us >> 32;
    //   return rtc_port_base[1];
    // }
    // else if (r_mem_addr == 0xa0000048) {
    //   return rtc_port_base[0];
    // }
    // else{
    //   if(M_R_ASSERT){
    //     assert(0);
    //   }
    //   return 0;
    // }
    if(M_R_ASSERT){
      assert(0);
    }
    return 0;
  }
  else{
    
    uint32_t ret = host_read(guest_to_host(r_mem_addr), 4);
    //printf("npcR->addr: 0x%x, len: %d, mem: 0x%08x\n", r_mem_addr, 4, ret);
    return ret;
  }
  
}

int parse_instruction_type(uint32_t top_inst) {
  uint32_t opcode = top_inst & 0x7F;
  switch (opcode) {
      case 0x33:  // R型：add, sub, sll, slt, sltu, xor, srl, sra, or, and
      case 0x13:  // I型：addi, slti, sltiu, xori, ori, andi, slli, srli, srai
      case 0x17:  // U型：auipc
      case 0x37:  // U型：lui
          return 4;
      case 0x03:  // I型：lb, lh, lw, lbu, lhu
      case 0x23:  // S型：sb, sh, sw
      case 0x0F:  // fence指令
          return 3;
      case 0x73: {
          uint32_t funct3 = (top_inst >> 12) & 0x7;
          if (funct3 != 0) {
              return 2;  // CSR指令 (csrrw, csrrs, csrrc等)
          } else {
              return 99;
          }
      }
      case 0x6F:  // J型：jal
      case 0x67:  // I型：jalr
      case 0x63:  // B型：beq, bne, blt, bge, bltu, bgeu
          return 1;
          
      default:
          return 99;
  }
}

extern "C" void difftest_exec(uint64_t n);
extern "C" void difftest_memcpy(uint32_t addr, void *buf, size_t n, bool direction);
extern "C" void difftest_regcpy(void *dut, bool direction, uint32_t pc); 

CPU_state refstate;
CPU_state dutstate;
int old_pc = 0;
int pc_count = 0;
uint64_t inst_count = 0;
int inst_type;
uint64_t jump_type_s = 0;
uint64_t csr_type_s = 0;
uint64_t read_and_store_type_s = 0;
uint64_t cal_type_s = 0;
uint64_t unk_s = 0;
uint64_t last_clock = 0;
uint64_t inst_clock_time = 0;
uint64_t clk_jump_type_s = 0;
uint64_t clk_csr_type_s = 0;
uint64_t clk_read_and_store_type_s = 0;
uint64_t clk_cal_type_s = 0;
uint64_t clk_unk_s = 0;
uint64_t func_time = 0;
uint64_t detect_btype = 0;
int      btype_pc = 0;
uint32_t access_addr = 0;
int detect_read_device = 0;
int gpr_diff_test_failed = 0;

uint32_t decode_load_instruction(uint32_t instruction) {
  // 检查是否为load指令
  uint8_t opcode = instruction & 0x7F;
  if (opcode == 0x03) {
      uint8_t rs1 = (instruction >> 15) & 0x1F;  
      uint8_t rd  = (instruction >> 7)  & 0x1F;  
      int32_t imm = (int32_t)(instruction & 0xFFF00000) >> 20;
      if (imm & 0x800) {
          imm |= 0xFFFFF000;
      }
      uint32_t addr = gpr[rs1] + (uint32_t)imm;
      return addr;
  }
  else{
    return 0;
  }
}



void cpu_exec(uint64_t n){
  
  
  for(uint64_t i = 0; i < n; i++){
    if(trap != 1){
      dut.clock ^= 1;
      step_and_dump_wave();
      #ifdef  SOC
        if(dut.clock == 1){
          nvboard_update();
        }
      #endif

      if(top_inst_valid && dut.clock == 1){
        inst_clock_time = i - last_clock;
        last_clock = i;
        inst_count++;
        if(ITRACE_FILE){
          fprintf(itracefile, "%08x\n",top_pc);
        }
        if(BTRACE_FILE){
          //printf("%08x,%08x\n",top_pc, top_inst);
          if(detect_btype == 1){
            detect_btype = 0;
            if(btype_pc + 4 == top_pc){
              fprintf(btracefile, "nottaken\n");
            }
            else{
              fprintf(btracefile, "taken\n");
            }
          }
          if((top_inst & 0x7F) == 0x63){//B-Type
            fprintf(btracefile, "%08x,%08x,",top_pc, top_inst);
            detect_btype = 1;
            btype_pc = top_pc;
          }
        }
        if(parse_instruction_type(top_inst) == 1){
          jump_type_s++;
          clk_jump_type_s += inst_clock_time;
        }
        if(parse_instruction_type(top_inst) == 2){
          csr_type_s++;
          clk_csr_type_s += inst_clock_time;
        }
        if(parse_instruction_type(top_inst) == 3){
          read_and_store_type_s++;
          clk_read_and_store_type_s += inst_clock_time;
        }
        if(parse_instruction_type(top_inst) == 4){
          cal_type_s++;
          clk_cal_type_s += inst_clock_time;
        }
        if(parse_instruction_type(top_inst) == 5){
          unk_s++;
          clk_unk_s += inst_clock_time;
        }

        if(WATCHPOINT){
          if(top_pc == 0xa00214ac){
            return;
          }
        }


        #ifdef SOC
          if(DIFFTESE){
        #else
          if(DIFFTESE && (top_pc & 0xF0000000) >> 28 == 0x8){
            if(top_pc == 0x80000000){
              dutstate.pc = top_pc;
              memcpy(dutstate.gpr, gpr, sizeof(gpr));
              difftest_regcpy(&dutstate, 1, top_pc);
            }
        #endif
          if(detect_read_device){
            dutstate.pc = top_pc;
            memcpy(dutstate.gpr, gpr, sizeof(gpr));
            difftest_regcpy(&dutstate, 1, top_pc);
            difftest_regcpy(&refstate, 0, 0x30000000);
            difftest_exec(1);
            detect_read_device = 0;
          }
          else{
            difftest_regcpy(&refstate, 0, 0x30000000);
            difftest_exec(1);
          }
          

          access_addr = decode_load_instruction(top_inst);
          if((access_addr != 0) && 
              !(access_addr - CONFIG_FLASHBASE < FLASH_SIZE ||
                access_addr - CONFIG_SRAMBASE  < SRAM_SIZE  ||
                access_addr - CONFIG_SDRAMBASE < SDRAM_SIZE)){
                //printf("Read address: 0x%08x\n", access_addr);
                detect_read_device = 1;
          }
          
          if(refstate.pc != top_pc){
           if(PC_ASSERT){
            AssembleDecoder(handle, top_inst, top_pc);
            printf("        dut                    | ref                   \n");
            printf("pc      0x%08x             | 0x%08x\n", top_pc, refstate.pc);
            for(int j = 0; j < 16; j++){
              printf("%-3s     %-10u  0x%08x | %-10u  0x%08x\n", regs[j], gpr[j], gpr[j], refstate.gpr[j], refstate.gpr[j]);
            }
            assert(0);
           }
          }

          if(REG_ASSERT){
            gpr_diff_test_failed = 0;
            for(int j = 0; j < 16; j++){
              if(refstate.gpr[j] != gpr[j]){
                gpr_diff_test_failed = 1;
              }
            }
            if(gpr_diff_test_failed){
              AssembleDecoder(handle, top_inst, top_pc);
              printf("        dut                    | ref                   \n");
              printf("pc      0x%08x             | 0x%08x\n", top_pc, refstate.pc);
              for(int j = 0; j < 16; j++){
                printf("%-3s     %-10u  0x%08x | %-10u  0x%08x\n", regs[j], gpr[j], gpr[j], refstate.gpr[j], refstate.gpr[j]);
              }
              assert(0);
            }
          }

          if(PRINT_REG){
            #ifdef SOC
              if(((top_pc & 0xF0000000) >> 28) == 0xA || ((top_pc & 0xF0000000) >> 28) == 0xB){
            #else
              if(((top_pc & 0xF0000000) >> 28) == 0x8){
            #endif
              AssembleDecoder(handle, top_inst, top_pc);
              printf("        dut                    | ref                   \n");
              printf("pc      0x%08x             | 0x%08x\n", top_pc, refstate.pc);
              for(int j = 0; j < 16; j++){
                printf("%-3s     %-10u  0x%08x | %-10u  0x%08x\n", regs[j], gpr[j], gpr[j], refstate.gpr[j], refstate.gpr[j]);
              }
            } 
          }
        }

        if(INST_NOT_VALID_CHECK){
          if(top_inst==0x00000000 && top_inst_valid){
            printf("\33[1;31mProgram inst is 0x00000000. Stuck at 0x%08x\033[0m\n",top_pc);
            return;
          }
        }
      }

      

      if(PC_NO_CHANGE_DECETE){
        if(top_pc == old_pc){
          pc_count++;
          if(pc_count > 15000){
            printf("\33[1;31mProgram pc has not change for 1.5w clk. Stuck at 0x%08x\033[0m\n",top_pc);
            // AssembleDecoder(handle, top_inst, top_pc);
            isa_reg_display();
            printf("exec times: %ld\n",i+1);
            return;
          }
        }
        else{
          pc_count = 0;
        }
        old_pc = top_pc;  
      }
      
      
    }
    else{
      float ipc = (float)inst_count/(float)(i+1);
      float cpi = 1.0/ipc;
      double avg_jump = (double)clk_jump_type_s/(double)jump_type_s;
      double avg_csr = (double)clk_csr_type_s/(double)csr_type_s;
      double avg_read_and_store = (double)clk_read_and_store_type_s/(double)read_and_store_type_s;
      double avg_cal = (double)clk_cal_type_s/(double)cal_type_s;
      double avg_unk;
      if(unk_s == 0){
        avg_unk = 0;
      }
      else{
        avg_unk = (double)clk_jump_type_s/(double)jump_type_s;
      }
      printf("\33[1;34mProgram execution has ended. To restart the program, exit npc and run again.\033[0m\n");
      printf("\33[1;34mClock Cycle: %ld\033[0m\n",i+1);
      printf("\33[1;34mInstruction Count: %ld\033[0m\n",inst_count);
      printf("\33[1;34mIPC: %f\033[0m\n",ipc);
      printf("\33[1;34mCPI: %f\033[0m\n",cpi);
      printf("\33[1;34mIFU get inst: %ld\033[0m\n",IFU_getinst);
      printf("\33[1;34mLSU get data: %ld\033[0m\n",LSU_getdata);
      printf("\33[1;34mEXU finish calculate: %ld\033[0m\n",EXU_fincal);
      printf("\33[1;34mIFU clock time: %f\033[0m\n",(double)sum_ifu_clock_time/(double)ifu_clock_time_num);
      printf("\33[1;34micache hit rate: %f\033[0m\n",1-((double)icache_miss_count/(double)ifu_clock_time_num));
      printf("\33[1;34micache miss count: %ld\033[0m\n",icache_miss_count);
      printf("\33[1;34mLSU clock time: %f\033[0m\n",(double)sum_lsu_clock_time/(double)lsu_clock_time_num);
      printf("\33[1;34msum_lsu_clock_time: %ld\033[0m\n",sum_lsu_clock_time);
      printf("\33[1;34mlsu_clock_time_num: %ld\033[0m\n",lsu_clock_time_num);
      printf("\33[1;34mifu_clock_time_num: %ld\033[0m\n",ifu_clock_time_num);
      printf("\33[1;34mmiss_counter_branch_c: %ld\033[0m\n",miss_counter_branch_c);
      printf("\33[1;34mall_counter_branch_c: %ld\033[0m\n",all_counter_branch_c);
      printf("\33[1;34mbranch hit rate: %f\033[0m\n",1-((double)miss_counter_branch_c/(double)all_counter_branch_c));
      printf("\33[1;34mTYPE COUNT SOFTWARE:\033[0m\n");
      printf("\33[1;34mjump: %ld\033[0m\n",jump_type_s);
      printf("\33[1;34mcsr: %ld\033[0m\n",csr_type_s);
      printf("\33[1;34mread_and_store: %ld\033[0m\n",read_and_store_type_s);
      printf("\33[1;34mcalculate: %ld\033[0m\n",cal_type_s);
      printf("\33[1;34munk: %ld\033[0m\n",unk_s);
      printf("\33[1;34mAVG TYPE CLOCK TIME:\033[0m\n");
      printf("\33[1;34mjump: %lf\033[0m\n",avg_jump);
      printf("\33[1;34mcsr: %lf\033[0m\n",avg_csr);
      printf("\33[1;34mread_and_store: %lf\033[0m\n",avg_read_and_store);
      printf("\33[1;34mcalculate: %lf\033[0m\n",avg_cal);
      printf("\33[1;34munk: %lf\033[0m\n",avg_unk);

      if(PERF_FILE){
        fprintf(perffile, "clk: %ld\n",i+1);
        fprintf(perffile, "inst: %ld\n",inst_count);
        fprintf(perffile, "IPC: %f\n",ipc);
        fprintf(perffile, "IFU_get_inst: %ld\n",IFU_getinst);
        fprintf(perffile, "LSU_get_data: %ld\n",LSU_getdata);
        fprintf(perffile, "EXU_finish_calculate: %ld\n",EXU_fincal);
        fprintf(perffile, "IFU_clock_time: %f\n",(double)sum_ifu_clock_time/(double)ifu_clock_time_num);
        fprintf(perffile, "icache hit rate: %f\n",1-((double)icache_miss_count/(double)ifu_clock_time_num));
        fprintf(perffile, "LSU_clock_time: %f\n",(double)sum_lsu_clock_time/(double)lsu_clock_time_num);
        fprintf(perffile, "jump: %ld\n",jump_type_s);
        fprintf(perffile, "csr: %ld\n",csr_type_s);
        fprintf(perffile, "read_and_store: %ld\n",read_and_store_type_s);
        fprintf(perffile, "calculate: %ld\n",cal_type_s);
        fprintf(perffile, "unk: %ld\n",unk_s);
        fprintf(perffile, "jump time: %lf\n",avg_jump);
        fprintf(perffile, "csr time: %lf\n",avg_csr);
        fprintf(perffile, "read_and_store time: %lf\n",avg_read_and_store);
        fprintf(perffile, "calculate time: %lf\n",avg_cal);
        fprintf(perffile, "unk time: %lf\n",avg_unk);
        fclose(perffile);
      }
      if(BTRACE_FILE){
        fclose(btracefile);
      }
      if(ITRACE_FILE){
        fclose(itracefile);
      }
      return;
    }
  }
  
}


static int cmd_si(char *args);
static int cmd_c(char *args);
static int cmd_help(char *args);
static int cmd_q(char *args);
static int cmd_info(char *args);

static struct {
  const char *name;
  const char *description;
  int (*handler) (char *);
} cmd_table [] = {
  { "help", "Display information about all supported commands", cmd_help },
  { "c", "Continue the execution of the program", cmd_c },
  { "si","Execute one time", cmd_si},
  { "q", "Exit NEMU", cmd_q },
  { "info", "Show some info", cmd_info},
};

#define NR_CMD ARRLEN(cmd_table)

static int cmd_info(char *args) {
  char ARG;
  if (args == NULL){
    printf("args needed\n");
  }
  else{
    sscanf(args,"%c",&ARG);
    if (ARG == 'r'){
      isa_reg_display();
    }
    else{
      printf("not support yet\n");
    }
  }
  return 0;
}

static int cmd_q(char *args) {
  return -1;
}

static int cmd_si(char *args) {
  int N;
  if (args == NULL){
    N = 1;
  }
  else{
    sscanf(args,"%d",&N);
    //printf("%d\n",N);
  }
  cpu_exec(N);
  return 0;
}

static int cmd_c(char *args) {
  cpu_exec(-1);
  return 0;
}

static int cmd_help(char *args) {
  /* extract the first argument */
  char *arg = strtok(NULL, " ");
  int i;

  if (arg == NULL) {
    /* no argument given */
    for (i = 0; i < NR_CMD; i ++) {
      printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
    }
  }
  else {
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(arg, cmd_table[i].name) == 0) {
        printf("%s - %s\n", cmd_table[i].name, cmd_table[i].description);
        return 0;
      }
    }
    printf("Unknown command '%s'\n", arg);
  }
  return 0;
}



void sdb_mainloop() {
  for (char *str; (str = rl_gets()) != NULL; ) {
    char *str_end = str + strlen(str);

    /* extract the first token as the command */
    char *cmd = strtok(str, " ");
    if (cmd == NULL) { continue; }

    /* treat the remaining string as the arguments,
     * which may need further parsing
     */
    char *args = cmd + strlen(cmd) + 1;
    if (args >= str_end) {
      args = NULL;
    }

    int i;
    for (i = 0; i < NR_CMD; i ++) {
      if (strcmp(cmd, cmd_table[i].name) == 0) {
        if (cmd_table[i].handler(args) < 0) { return; }
        break;
      }
    }

    if (i == NR_CMD) { printf("Unknown command '%s'\n", cmd); }
  }
}



int main(int argc, char *argv[]) {
  Verilated::traceEverOn(true);
  open_log_file();
  sim_init();
  #ifdef SOC
    nvboard_bind_all_pins(&dut);
    nvboard_init();
  #endif
  Verilated::commandArgs(argc, argv);

  parse_args(argc, argv);
  
  if (!capstone_init(&handle)) {
      return -1;
  }

  #ifdef SOC
    if(START_FROM_MROM){
      load_img_mrom();
    }
    else{
      load_img_flash();
    }
  #else
    load_img_txt_flash();
  #endif
  
  if(LOAD_IMG_TO_FLASH){
    //load_img_to_flash("/home/plutoisy/ysyx-workbench/npc/npc_test/build/char_test.bin");
  }

  if(DIFFTESE){
    void* dut = NULL;
    #ifdef SOC
      difftest_memcpy(CONFIG_FLASHBASE, flash, FLASH_SIZE, 1);
      difftest_regcpy(dut, 1, 0x30000000);
    #else
      difftest_memcpy(CONFIG_MBASE, flash, PMEM_SIZE, 1);
      difftest_regcpy(dut, 1, 0x80000000);
    #endif
  }
  
  system_rst();

  if(BMODE){
    cmd_si("-1");
    if(WATCHPOINT){
      sdb_mainloop();
    }
    else{
      cmd_q(NULL);
    }
  }
  else{
    sdb_mainloop();
  }

  cs_close(&handle);
  sim_exit();
  return 0;
}