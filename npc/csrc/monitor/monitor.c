#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<elf.h>
#include<getopt.h>
#include "include/macro.h"
#include "memory/pmem.h"
#include "cpu/cpu.h"
#include "include/debug.h"
#include "include/autoconf.h"
void init_disasm();
void sdb_set_batch_mode();
void init_difftest(const char*ref_so_file,long img_size);
static char * img_file=NULL;
static char * elf_file=NULL;
Func_list func_list[1024]={};
int func_cnt=0;
static long load_img(){
    if(img_file==NULL){
        Log("No image is given.");
        assert(0);
    }
    FILE*fp;
    fp=fopen(img_file,"rb");
    assert(fp!=NULL);
    fseek(fp,0,SEEK_END);
    long fpsize=ftell(fp);
    fseek(fp,0,SEEK_SET);
#ifdef RISCV32E_NPC
    int ret=fread(psram,1,fpsize,fp);
#else
    int ret=fread(flash,1,fpsize,fp);
#endif
    printf("Opening image: %s, size: %ld\n", img_file, fpsize);
    assert(ret==fpsize);
    fclose(fp);
    return fpsize;
}
static void init_func(){
    if(elf_file==NULL){
        Log("No elf is given");
        return ;
    }
    FILE *fp=fopen(elf_file,"rb");
    assert(fp);
    fseek(fp,0,SEEK_END);
    long size=ftell(fp);
    fseek(fp,0,SEEK_SET);
    char *buf=(char*)malloc(size);
    int ret=fread(buf,size,1,fp);
    assert(ret==1);
    Elf32_Ehdr *ehdr=(Elf32_Ehdr*)buf;
    Elf32_Shdr *section=(Elf32_Shdr*)(ehdr->e_shoff+buf);
    char * strSection = buf+section[ehdr->e_shstrndx].sh_offset;
    Elf32_Sym *sym=NULL;
    int i;char * strtab=NULL;int n=0;
    for(i=0;i<ehdr->e_shnum;i++){
        if(strcmp(strSection+section[i].sh_name,".symtab")==0){
            sym=(Elf32_Sym*)(buf+section[i].sh_offset);
            n=section[i].sh_size/section[i].sh_entsize;
        }else if(strcmp(strSection+section[i].sh_name,".strtab")==0){
            strtab=buf+section[i].sh_offset;
        }
    }
    for(i=0;i<n;i++){
        if(ELF32_ST_TYPE(sym[i].st_info)==STT_FUNC){
            strncpy(func_list[func_cnt].name,strtab+sym[i].st_name,31);
            func_list[func_cnt].name[31]='\0';
            func_list[func_cnt].low=sym[i].st_value;
            func_list[func_cnt].high=sym[i].st_value+sym[i].st_size-4;
            func_cnt++;
            assert(func_cnt<=MAX_FUNC_CNT);
        }
    }
    free(buf);
}
static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"elf"      , required_argument, NULL, 'e'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  while ( (o = getopt_long(argc, argv, "-be:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'e': elf_file=optarg; break;
      case 1: img_file = optarg; break;
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-e,--elf=IMAGE.elf\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}
void nvboard_bind_all_pins(TOP_NAME*top);
void init_monitor(int argc,char*argv[]){
    parse_args(argc,argv);
    //read pmem of IMG file
    long img_size=load_img();
    //init ftrace 
    IFDEF(CONFIG_FTRACE,init_func();)
    //initial verilator
    contextp=new VerilatedContext;
    contextp->commandArgs(argc,argv);
    dut=new TOP_NAME(contextp);
    //open vcd trace
    IFDEF(CONFIG_VCD_TRACE,{
        contextp->traceEverOn(true);
        tfp=new VerilatedVcdC;
        dut->trace(tfp,CONFIG_VCD_TRACE_LENGTH);
        tfp->open("simx.vcd");
    })
    //nvboard
    IFDEF(USE_NVBOARD,{
        nvboard_bind_all_pins(dut);
        nvboard_init();    
    })

    //reset
    reset(30);
    //difftest
    IFDEF(CONFIG_DIFFTEST,init_difftest(str(NEMU_HOME_STR) "/build/riscv32-nemu-interpreter-so",img_size));
    IFDEF(CONFIG_ITRACE,init_disasm());
}
void free_monitor(){
    delete dut;
    delete contextp;
    IFDEF(CONFIG_VCD_TRACE,tfp->close();delete tfp;)
}
