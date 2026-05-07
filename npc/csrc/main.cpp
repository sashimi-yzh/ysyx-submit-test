
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <assert.h>
#include <regex.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#include <elf.h>
#include "VysyxSoCFull.h"

#include "common.h"
#include "debug.h"
#include "macro.h"
#include "utils.h"
#include "include.h"
#include "paddr.h"
#include <time.h>



//#define  DIFFTEST_ON
//#define  WAVE_ON
//#define  TRACE_ON
#define NVBOARD_ON


int cpu_state;
uint32_t mem[0xffffffff];
uint32_t flash[0xfffffff];
bool is_skip_ref = false;
bool difftest_check_all = false;
static uint64_t counter=0;

enum { DIFFTEST_TO_DUT, DIFFTEST_TO_REF };

void (*ref_difftest_memcpy)(paddr_t addr, void *buf, size_t n, bool direction) = NULL;
void (*ref_difftest_regcpy)(void *dut, bool direction) = NULL;
void (*ref_difftest_exec)(uint64_t n) = NULL;
void (*ref_difftest_raise_intr)(uint64_t NO) = NULL;

time_t start_time;
time_t currentTimeABS;
static int flag = 0;

uint32_t sdram[4][8192][512] = {};

uint64_t icache_get_addr_time,icache_back_self_inst_time,icache_back_mem_inst_time;
uint64_t icache_access_time=0,icache_miss_penalty=0;

extern "C" void difftest_skip() {
  is_skip_ref = true;
}

extern "C" void icache_get_addr() {
  icache_get_addr_time = counter;
}

extern "C" void icache_back_self_inst(){
  icache_back_self_inst_time = counter - icache_get_addr_time;
  icache_access_time += icache_back_self_inst_time;
}

extern "C" void icache_back_mem_inst(){
  icache_back_mem_inst_time = counter - icache_get_addr_time;
  icache_miss_penalty += icache_back_mem_inst_time;
}

uint64_t icache_hit_counter=0,icache_miss_counter=0;

extern "C" void icache_hit() {
  icache_hit_counter++;
}

extern "C" void icache_miss() {
  icache_miss_counter++;
}

uint64_t request_num=0,request_time=0,process_time=0,process_time_all=0;

extern "C" void send_data_request(){
  request_time = counter;
}

extern "C" void receive_data_back(){
  process_time = counter - request_time;
  process_time_all += process_time;
  request_num++;
}

static uint64_t inst_length;
static uint32_t last_inst,current_inst;
static uint64_t length_calculation=0, length_branch=0, length_mem=0, length_other=0, length_csr=0, length_error=0; 

extern "C" void return_inst(uint32_t inst1,char inst_opcode){
  //last_inst = current_inst;
  //current_inst = inst1;
  //if(current_inst == last_inst) { //指令没有发生变化
    switch(inst_opcode) {
      case 0x73: length_csr++; break;
      case 0x37: length_other++; break;
      case 0x17: length_other++; break;
      case 0x6f: length_branch++; break;
      case 0x67: length_branch++; break;
      case 0x63: length_branch++; break;
      case 0x03: length_mem++; break;
      case 0x23: length_mem++; break;
      case 0x13: length_calculation++; break;
      case 0x33: length_calculation++; break;
      default :length_error++; break;
  }
  //}

}

static uint64_t inst_counter = 0,data_counter = 0;
static uint64_t inst_calculation=0, inst_branch=0, inst_mem=0, inst_other=0, inst_csr=0, inst_error=0; 

extern "C" void idu_counter_return(char inst_opcode) {
  switch(inst_opcode) {
    case 0x73: inst_csr++; break;
    case 0x37: inst_other++; break;
    case 0x17: inst_other++; break;
    case 0x6f: inst_branch++; break;
    case 0x67: inst_branch++; break;
    case 0x63: inst_branch++; break;
    case 0x03: inst_mem++; break;
    case 0x23: inst_mem++; break;
    case 0x13: inst_calculation++; break;
    case 0x33: inst_calculation++; break;
    default :inst_error++; break;
  }
}

extern "C" void inst_counter_sub() {
  inst_counter--;
}

extern "C" void inst_counter_add() {
  inst_counter++;
}

extern "C" void data_counter_add() {
  data_counter++;
}

extern "C" void sdram_write(int32_t bank, int32_t row, int32_t column, int32_t data, char mask){
  switch(mask) {
    case 0: sdram[bank][row][column] = data; break;
    case 1: sdram[bank][row][column] = (sdram[bank][row][column]&0x00ff)+(data&0xff00); break;
    case 2: sdram[bank][row][column] = (sdram[bank][row][column]&0xff00)+(data&0x00ff); break;
    default: break;
  }
  
  log_write("[write] bank = %d,row = %d, column = %d, mask=%d, data= %04x, sdram= %04x\n",bank,row,column,mask,data,sdram[bank][row][column]);
}

extern "C" int sdram_read(int32_t bank, int32_t row, int32_t column, char mask){
  log_write("[read] bank = %d,row = %d, column = %d, mask=%d, data= %04x\n",bank,row,column,mask,sdram[bank][row][column]);
  switch(mask) {
    case 0: return sdram[bank][row][column]; break;
    case 1: return sdram[bank][row][column]&0xff00; break;
    case 2: return sdram[bank][row][column]&0x00ff; break;
    default: return sdram[bank][row][column]; break;
  }
  //return sdram[bank][row][column];
}


extern "C" void difftest_next_step(char difftest_check) {
  difftest_check_all = (bool)difftest_check;
}
extern "C" void flash_read(int32_t addr, int32_t *data) { 
  uint32_t tmp = (uint32_t)addr / 4;
  //printf("%x\n",tmp);
  *data = flash[tmp]; 
  //printf("%x\n",mem[tmp]);
  log_write("raddr = %08x,data= %08x\n",addr,*data);
}
extern "C" void mrom_read(int32_t addr, int32_t *data) { 
  uint32_t tmp = (uint32_t)addr / 4;
  //printf("%x\n",tmp);
  *data = mem[tmp]; 
  //printf("%x\n",mem[tmp]);
  log_write("[itrace]raddr = %08x,data= %08x\n",addr,mem[tmp]);
}


extern "C" int pmem_read(int raddr) {
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  /*
  time(&currentTimeABS);
  uint64_t time = (currentTimeABS - start_time)*1000000;
  if(raddr == RTC_ADDR){
    is_skip_ref = true;
    if(flag==0) {
      start_time = currentTimeABS;
      time = 0;
      flag=1;
    }
    
    //log_write("raddr = %08x,the time = %08x\n",raddr,(uint32_t)time);
    return time;
  }
  else{
    is_skip_ref = false;
  }
  if(raddr == RTC_ADDR + 4) {
    //log_write("raddr = %08x,the time = %08x\n",raddr,(uint32_t)(time << 32));
    is_skip_ref = true;
    if(flag==0) {
      start_time = currentTimeABS;
      time = 0;
      flag=1;
    }
    return (time << 32);
  }
  else{
    is_skip_ref = false;
  }
  */
  uint32_t return_data;
  uint32_t tmp = (uint32_t)raddr /4; //int类型是有符号的，要转成无符号的
  //uint32_t align = (uint32_t)raddr % 4;
  //if(align != 0 && rmask == 0){
  //  printf("不对齐\n");
  //  switch(align) {
  //    case 1:return_data = ((mem[tmp+1] & 0x000000ff) << 24) + ((mem[tmp] & 0xffffff00) >> 8);
  //    case 2:return_data = ((mem[tmp+1] & 0x0000ffff) << 16) + ((mem[tmp] & 0xffff0000) >> 16);
  //    case 3:return_data = ((mem[tmp+1] & 0x00ffffff) << 8 ) + ((mem[tmp] & 0xff000000) >> 24);
  //  }
  //}
  //else {
  return_data = mem[tmp];
  //}
#ifdef TRACE_ON
  if(raddr >= 0X80000000 && raddr <= 0X80000118)
  log_write("[i trace]                   raddr = %08x,data= %08x\n",raddr,return_data);
  else
  log_write("raddr = %08x,data= %08x\n",raddr,return_data);
#endif
  return return_data;
}
extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
  //log_write("                               wmask=%x,waddr = %08x,data= %08x\n",wmask,waddr,wdata);
  time(&currentTimeABS);
  //if(waddr == SERIAL_PORT) {
  //  putchar(wdata);
    //log_write("                               wmask=%x,waddr = %08x,data= %08x\n",wmask,waddr,wdata);
  //  return;
  //}
  /*if(waddr == RTC_ADDR){
    start_time = currentTimeABS + wdata;
    return;
  }
  if(waddr == RTC_ADDR + 4){
    start_time = currentTimeABS + wdata << 32;
    return;
  }*/
  uint32_t addr_tmp = (uint32_t)waddr / 4;
  switch(wmask) {
    case 0x1:  mem[addr_tmp] = (mem[addr_tmp] & 0xffffff00) + (wdata & 0x000000ff);break;
    case 0x2:  mem[addr_tmp] = (mem[addr_tmp] & 0xffff00ff) + ((wdata & 0x000000ff)<<8);break; 
    case 0x4:  mem[addr_tmp] = (mem[addr_tmp] & 0xff00ffff) + ((wdata & 0x000000ff)<<16);break;
    case 0x8:  mem[addr_tmp] = (mem[addr_tmp] & 0x00ffffff) + ((wdata & 0x000000ff)<<24);break;
    case 0x3:  mem[addr_tmp] = (mem[addr_tmp] & 0xffff0000) + (wdata & 0x0000ffff);break;
    case 0xc:  mem[addr_tmp] = (mem[addr_tmp] & 0x0000ffff) + ((wdata & 0x0000ffff)<<16);break;
    case 0xf:  mem[addr_tmp] = (mem[addr_tmp] & 0x00000000) + (wdata & 0xffffffff);;break;
    default: mem[addr_tmp] = mem[addr_tmp];
  }
#ifdef TRACE_ON
  log_write("                               wmask=%x,waddr = %08x,data= %08x\n",wmask,waddr,mem[addr_tmp]);
#endif
}

FILE *log_fp = NULL;
uint64_t g_nr_guest_inst = 0;
extern uint64_t g_nr_guest_inst;

void init_log(const char *log_file) {
  //log_fp = stdout;
  if (log_file != NULL) {
    log_fp = fopen(log_file, "w");
    if(log_fp == NULL)
      printf("Can not open '%s'", log_file);
    //log_fp = fp;
  }
  Log("Log is written to %s", log_file ? log_file : "stdout");
  //printf("Log is written to %s\n", log_file ? log_file : "stdout");
}
extern "C" void reg_return_value(uint32_t gpr_0,uint32_t gpr_1,uint32_t gpr_2,uint32_t gpr_3,uint32_t gpr_4,\
uint32_t gpr_5,uint32_t gpr_6,uint32_t gpr_7,uint32_t gpr_8,uint32_t gpr_9,uint32_t gpr_10,uint32_t gpr_11,uint32_t gpr_12,\
uint32_t gpr_13,uint32_t gpr_14,uint32_t gpr_15,uint32_t pc,uint32_t csr_reg_0,uint32_t csr_reg_1,uint32_t csr_reg_2,uint32_t csr_reg_3){
  cpu.gpr[0] = gpr_0;
  cpu.gpr[1] = gpr_1;
  cpu.gpr[2] = gpr_2;
  cpu.gpr[3] = gpr_3;
  cpu.gpr[4] = gpr_4;
  cpu.gpr[5] = gpr_5;
  cpu.gpr[6] = gpr_6;
  cpu.gpr[7] = gpr_7;
  cpu.gpr[8] = gpr_8;
  cpu.gpr[9] = gpr_9;
  cpu.gpr[10] = gpr_10;
  cpu.gpr[11] = gpr_11;
  cpu.gpr[12] = gpr_12;
  cpu.gpr[13] = gpr_13;
  cpu.gpr[14] = gpr_14;
  cpu.gpr[15] = gpr_15;
  cpu.pc = pc;
  cpu.csr_mepc = csr_reg_0;
  cpu.csr_mstatus = csr_reg_1;
  cpu.csr_mcause = csr_reg_2;
  cpu.csr_mtvec = csr_reg_3;

  //printf("gpr0 = %x",gpr_0);

}

extern "C" void ebreak() {
  if(cpu.gpr[10]==0) {
    printf("HIT GOOD TRAP\n");
    cpu_state = NPC_END;
  }
  else {
    printf("HIT BAD TRAP\n");
    cpu_state = NPC_ABORT;
  }
  
  
}

void init_difftest(char *ref_so_file, long img_size, int port) {
  assert(ref_so_file != NULL);

  void *handle;
  handle = dlopen(ref_so_file, RTLD_LAZY);
  assert(handle);

  ref_difftest_memcpy = (void (*)(unsigned int, void*, long unsigned int, bool))dlsym(handle , "difftest_memcpy");
  assert(ref_difftest_memcpy);

  ref_difftest_regcpy = (void (*)(void *dut, bool direction))dlsym(handle, "difftest_regcpy");
  assert(ref_difftest_regcpy);

  ref_difftest_exec = (void (*)(uint64_t n))dlsym(handle, "difftest_exec");
  assert(ref_difftest_exec);

  ref_difftest_raise_intr = (void (*)(uint64_t NO))dlsym(handle, "difftest_raise_intr");
  assert(ref_difftest_raise_intr);

  void (*ref_difftest_init)() = (void (*)())dlsym(handle, "difftest_init");
  assert(ref_difftest_init);

  Log("Differential testing: %s", ANSI_FMT("ON", ANSI_FG_GREEN));
  Log("The result of every instruction will be compared with %s. "
      "This will help you a lot for debugging, but also significantly reduce the performance. "
      "If it is not necessary, you can turn it off in menuconfig.", ref_so_file);

  ref_difftest_init();
  ref_difftest_memcpy(PMEM_LEFT, flash, img_size, DIFFTEST_TO_REF);
  cpu.pc = 0x30000000;
  cpu.csr_mstatus = 0x1800;
  cpu.csr_mcause = 0;
  cpu.csr_mepc = 0;
  cpu.csr_mtvec = 0;
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  
}

bool difftest_check() {
  regfile ref;
  ref_difftest_regcpy(&ref, DIFFTEST_TO_DUT);
  //printf("%x,%x,%x\n",ref.pc,ref.csr_mcause,ref.csr_mepc);
  return checkregs(&ref, &cpu);
}
void diff_cpdutreg2ref() {
  ref_difftest_regcpy(&cpu, DIFFTEST_TO_REF);
  //printf("%x\n",cpu.pc);
}
void difftest_step() { 
  ref_difftest_exec(1);
}



static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
  if (img_file == NULL) {
    printf("No image is given. Use the default build-in image.\n");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  if(fp == NULL) assert("Can not open imgfile");

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(flash, size, 1, fp);
  //int ret = fread(&(mem[0x8000000]), size, 1, fp);
  assert(ret == 1);

  //printf("%x\n",mem[0x8000000]);
  //int i;
  //for (i=0;i<10;i++) {
  //  flash[i] = i;
  //}
  //printf("%c\n",mem[0x18000003]);
/*
  flash[0] = 0x00410413;
  flash[1] = 0x100007b7;
  flash[2] = 0x04100713;
  flash[3] = 0x00e78023;
  flash[4] = 0x100007b7;
  flash[5] = 0x00a00713;
  flash[6] = 0x00e78023;
  flash[7] = 0x0000006f;*/

  fclose(fp);
  return size;
}

static int parse_args(int argc, char *argv[]) {
  
  const struct option table[] = {
    {"help"     , no_argument      , NULL, 'h'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {0          , 0, NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-hd:p:", table, NULL)) != -1) {
    //printf("%c,%d\n",o,o);
    switch (o) {
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'd': diff_so_file = optarg; break;
      case 1: img_file = optarg; return 0;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}
bool skip_r=false;
static void trace_and_difftest() {
  
  //log_write("%08x,%08x\n", top->pc,top->inst); 
#ifdef DIFFTEST_ON
  if(difftest_check_all == true) {

    if(is_skip_ref) {
      //printf("skip\n");
      //skip_r = is_skip_ref;
      //diff_cpdutreg2ref();
    }
    else {
      //bool check = difftest_check();
      if(skip_r) {
        diff_cpdutreg2ref();
        is_skip_ref = false;
        //printf("aa\n");
        //difftest_step();
      }
      else{
        //printf("a\n");
        difftest_step();
      }
      bool check = difftest_check();
      
      if(check==false) {
        cpu_state = NPC_ABORT;
        return;
      }
    }
    skip_r = is_skip_ref;

/*
      if(skip_r==true) {
        diff_cpdutreg2ref();

      }
      
      bool check = difftest_check();
      if(is_skip_ref==false) {
        difftest_step();
      }
      

      if(check==false) {
        cpu_state = NPC_ABORT;
        return;
      }
      skip_r = is_skip_ref;
     */  
  

  /*
      difftest_step();//ref exc once
      bool check = difftest_check(); 

      if(check==false) {
        cpu_state = NPC_ABORT;
        return;
      }
      */
  }
#endif
  WP * p = head;
  word_t expr(char *e, bool *success);
  while(p!=NULL) {
    
    bool success;
    bool *ptr_success = &success;
    char str[100]={'\0'};
    word_t value_new;
    
    //printf("name:%s\n",p->tokens);
    strcpy(str,p->tokens);
    //printf("name2:%s\n",str);
    value_new=expr(str,ptr_success);


    if(value_new != p->value) {
      p->value = value_new;
      cpu_state = NPC_STOP;
      printf("触发监视点\n");
      
    }
    p=p->next;
  }
  return ;

}
#ifdef NVBOARD_ON
  #include "nvboard.h"
  static TOP_NAME dut;
  //void nvboard_bind_all_pins(TOP_NAME* top);
  #ifdef WAVE_ON
    #include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
    VerilatedContext* contextp = new VerilatedContext;
    //VysyxSoCFull* top = new VysyxSoCFull{contextp};
    //VerilatedFstC *tfp = new VerilatedFstC; // 创建一个波形文件指针
    VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针
  #endif

#else
  #include "verilated.h"
  //#include "verilated_vcd_c.h" //可选，如果要导出vcd则需要加上
  #include "verilated_fst_c.h"            //波形文件所需的头文件
  VerilatedContext* contextp = new VerilatedContext;
  VysyxSoCFull* top = new VysyxSoCFull{contextp};
  //VerilatedVcdC* tfp = new VerilatedVcdC; //初始化VCD对象指针

  VerilatedFstC *tfp = new VerilatedFstC; // 创建一个波形文件指针
#endif

void cpu_exec(uint64_t num) {
  uint64_t i;
  for(i = 0; i < num; i++) {
    if(cpu_state == NPC_END){ //finish
      //printf("finish,time_counter=%ld,inst_counter=%ld,data_counter=%ld\n",counter,inst_counter,data_counter);
      //printf("inst type count:\ncalculation:%ld\nbranch:%ld\nmem:%ld\nother:%ld\ncsr:%ld\nerror:%ld\n\n",inst_calculation,inst_branch,inst_mem,inst_other,inst_csr,inst_error);
      //printf("avg exec time:\ncalculation:%f\nbranch:%f\nmem:%f\nother:%f\ncsr:%f\n\n",length_calculation/(float)inst_calculation,length_branch/(float)inst_branch,length_mem/(float)inst_mem,length_other/(float)inst_other,length_csr/(float)inst_csr);
      //printf("avg access mem time:%f\n",process_time_all/(float)request_num);
      //printf("icache hit:%ld,miss:%ld,p=%f\n",icache_hit_counter,icache_miss_counter,icache_hit_counter/(float)(icache_hit_counter+icache_miss_counter));
      //printf("access_time=%f,miss_penalty=%f\n",icache_access_time/(float)icache_hit_counter,icache_miss_penalty/(float)icache_miss_counter);
      break;
    }
    if(cpu_state == NPC_STOP) { //stop
      cpu_state = NPC_RUNNING;
      break;
    }
    if(cpu_state == NPC_ABORT) {
      printf("abort! at pc=%x\n",cpu.pc);
      break;
    }
#ifdef NVBOARD_ON
    nvboard_update();
    dut.clock = 0; dut.eval();
    dut.clock = 1; dut.eval();
    counter++;
    //trace_and_difftest();
    
#else
    top->clock = 0; top->eval();
    top->clock = 1; top->eval();
    counter++;
    trace_and_difftest();

    tfp->dump(contextp->time()); //dump wave
    contextp->timeInc(1); //推动仿真时间
#endif
    
  }
}




int main(int argc, char** argv) {
  
  //Verilated::traceEverOn(true);
#ifdef NVBOARD_ON
  
  //nvboard_bind_all_pins(&dut);
  nvboard_bind_pin(&dut.externalPins_gpio_out,16,LD15, LD14, LD13, LD12, LD11, LD10, LD9, LD8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
  nvboard_bind_pin(&dut.externalPins_gpio_in,16,SW15, SW14, SW13, SW12, SW11, SW10, SW9, SW8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_0,8,SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_1,8,SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_2,8,SEG2A, SEG2B, SEG2C, SEG2D, SEG2E, SEG2F, SEG2G, DEC2P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_3,8,SEG3A, SEG3B, SEG3C, SEG3D, SEG3E, SEG3F, SEG3G, DEC3P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_4,8,SEG4A, SEG4B, SEG4C, SEG4D, SEG4E, SEG4F, SEG4G, DEC4P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_5,8,SEG5A, SEG5B, SEG5C, SEG5D, SEG5E, SEG5F, SEG5G, DEC5P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_6,8,SEG6A, SEG6B, SEG6C, SEG6D, SEG6E, SEG6F, SEG6G, DEC6P);
  nvboard_bind_pin(&dut.externalPins_gpio_seg_7,8,SEG7A, SEG7B, SEG7C, SEG7D, SEG7E, SEG7F, SEG7G, DEC7P);
  nvboard_bind_pin(&dut.externalPins_uart_tx,1,UART_TX);
  nvboard_bind_pin(&dut.externalPins_uart_rx,1,UART_RX);
  nvboard_bind_pin(&dut.externalPins_ps2_clk,1,PS2_CLK);
  nvboard_bind_pin(&dut.externalPins_ps2_data,1,PS2_DAT);
  nvboard_bind_pin(&dut.externalPins_vga_r,8,VGA_R7, VGA_R6, VGA_R5, VGA_R4, VGA_R3, VGA_R2, VGA_R1, VGA_R0);
  nvboard_bind_pin(&dut.externalPins_vga_g,8,VGA_G7, VGA_G6, VGA_G5, VGA_G4, VGA_G3, VGA_G2, VGA_G1, VGA_G0);
  nvboard_bind_pin(&dut.externalPins_vga_b,8,VGA_B7, VGA_B6, VGA_B5, VGA_B4, VGA_B3, VGA_B2, VGA_B1, VGA_B0);
  nvboard_bind_pin(&dut.externalPins_vga_hsync,1,VGA_HSYNC);
  nvboard_bind_pin(&dut.externalPins_vga_vsync,1,VGA_VSYNC);
  nvboard_bind_pin(&dut.externalPins_vga_valid,1,VGA_BLANK_N);
  nvboard_init();
  
  
#endif
  Verilated::commandArgs(argc, argv);
  
  init_log("npc-log.txt");
  parse_args(argc, argv);
  long img_size = load_img();


#ifdef DIFFTEST_ON
  init_difftest(diff_so_file, img_size, difftest_port);
#endif
  init_sdb();
  cpu_state = NPC_RUNNING;



#ifdef NVBOARD_ON
  
  
  int n = 10;
  dut.reset = 1;
  while (n > 0) {
    nvboard_update();
    dut.clock = 0; dut.eval();
    dut.clock = 1; dut.eval();
    #ifdef WAVE_ON
    tfp->dump(contextp->time()); //dump wave
    contextp->timeInc(1); //推动仿真时间
    #endif
    n--;
  }
  dut.reset = 0;

  sdb_set_batch_mode();//批处理模式
  
  sdb_mainloop();

  
  
#else 
  contextp->commandArgs(argc, argv);
  #ifdef WAVE_ON
  contextp->traceEverOn(true); //打开追踪功能
  top->trace(tfp, 99); //
  //tfp->open("wave.vcd"); //设置输出的文件wave.vcd
  tfp->open("wave.fst"); //设置输出的文件wave.vcd
  #endif
  int n = 10;
  top->reset = 1;
  while (n > 0) { 
    top->clock = 0; top->eval();
    top->clock = 1; top->eval();
    tfp->dump(contextp->time()); //dump wave
    contextp->timeInc(1); //推动仿真时间
    n--;
  }
  top->reset = 0;

  sdb_set_batch_mode();//批处理模式
  
  sdb_mainloop();


  delete top;
  #ifdef WAVE_ON
  tfp->close();
  #endif
  delete contextp;
#endif

  if(cpu_state == NPC_END || cpu_state == NPC_QUIT) {
    return 0;
  }
  else {
    return 1;
  }
}
