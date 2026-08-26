/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <isa.h>
#include <memory/paddr.h>
#include <elf.h>
#include <ftrace.h>
void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();
void sdb_set_batch_mode();

static void welcome() {
  Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
  IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
        "to record the trace. This may lead to a large log file. "
        "If it is not necessary, you can disable it in menuconfig"));
  Log("Build time: %s, %s", __TIME__, __DATE__);
  printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
  printf("For help, type \"help\"\n");
  //Log("Exercise: Please remove me in the source code and compile NEMU again.");
  //assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;

#ifdef CONFIG_FTRACE
symtab_t *funsymtab=NULL;
ftracer_stack_t  ftracer_stack={.depth=0,.is_ftrace=false,.stack=NULL,.symtab_size=0};
#endif
static void load_elf(){
#ifdef CONFIG_FTRACE
  //
  //elf_file=malloc(256);
  //strcpy(elf_file,"/home/seaber/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-riscv32-nemu.elf");

  //
  if (elf_file == NULL) {Log("Cannot open .elf. Disabled 'ftrace'.");return;}
  int elf_size;
  FILE *fp = fopen(elf_file,"rb");
  if(fp==NULL){Log("Cannot open %s. Disabled 'ftrace'.",elf_file);return;}
  //Get ELF size
  if(fseek(fp,0,SEEK_END)!=0){fclose(fp);Log("Cannot init 'ftrace'. (fseek() ERROR) Disabled 'ftrace'.");return;}
  elf_size=ftell(fp);
  Log("Load .elf. Size = %d",elf_size);

  //Get ELF data
  char *elf_buf = malloc(elf_size);
  if(!elf_buf){fclose(fp);Log("Cannot init 'ftrace'. (malloc() elf_buf ERROR) Disabled 'ftrace'.");return;}
  fseek(fp, 0, SEEK_SET);
  if(fread(elf_buf,1,elf_size,fp)!=elf_size){free(elf_buf);fclose(fp);Log("Cannot init 'ftrace'. (read .elf ERROR) Disabled 'ftrace'.");return;}
  fclose(fp);

  //Get elf_header
  Elf32_Ehdr *elf_header = (Elf32_Ehdr *)elf_buf;
  Log("ELF HEADER MAGIC: %02x %02x %02x %02x",elf_header->e_ident[EI_MAG0],elf_header->e_ident[EI_MAG1],elf_header->e_ident[EI_MAG2],elf_header->e_ident[EI_MAG3]);

  //Get elf_section_header[]
  Elf32_Shdr *elf_section_header = (Elf32_Shdr *)(elf_buf+(uint32_t)(elf_header->e_shoff));
  Log("ELF SECTION HEADER OFFSET: %d, NUM: %d, SIZE: %d",elf_header->e_shoff,elf_header->e_shnum,elf_header->e_shentsize);

  //Get elf_section_header_symtab
  Elf32_Off elf_section_header_strtab_off=elf_section_header[elf_header->e_shstrndx].sh_offset;
  Elf32_Off elf_section_symtab_off=0;
  uint32_t elf_section_symtab_num;
  uint32_t elf_section_symtab_index;
  for(int i=0;i<elf_header->e_shnum;i++){
    if(strcmp(elf_buf+elf_section_header_strtab_off+elf_section_header[i].sh_name,".symtab")==0){
      elf_section_symtab_off=elf_section_header[i].sh_offset;
      elf_section_symtab_num = elf_section_header[i].sh_size / elf_section_header[i].sh_entsize;
      elf_section_symtab_index=i;
      funsymtab=malloc(sizeof(symtab_t)*elf_section_header[i].sh_size);
      if(!funsymtab){free(elf_buf);Log("Cannot init 'ftrace'. (malloc() symtab ERROR) Disabled 'ftrace'.");return;}
      break;
    }
  }
  if(elf_section_symtab_off==0){free(elf_buf);Log("Cannot init 'ftrace'. (find .symtab ERROR) Disabled 'ftrace'.");return;}
  Log("ELF SECTION .symtab OFFSET: 0x%x num:%d",elf_section_symtab_off,elf_section_symtab_num);
  
  //Set symtab
  Elf32_Sym *elf_section_symtab=(Elf32_Sym*)(elf_buf+elf_section_symtab_off);
  int cnt=0;
  for(int i=0;i<elf_section_symtab_num;i++){
    if(ELF32_ST_TYPE(elf_section_symtab[i].st_info)==STT_FUNC){
      strcpy(funsymtab[cnt].name,(char *)(elf_buf + elf_section_header[elf_section_header[elf_section_symtab_index].sh_link].sh_offset + elf_section_symtab[i].st_name));
      funsymtab[cnt].start_add=elf_section_symtab[i].st_value;
      funsymtab[cnt].size=elf_section_symtab[i].st_size;
      cnt++;
    }
  }
  //for(int i=0;i<cnt;i++)  Log("ELF .symtab: 0x%x + 0x%x | %s",funsymtab[i].start_add,funsymtab[i].size,funsymtab[i].name);
  free(elf_buf);
  
  //init ftracer stack
  ftracer_stack.is_ftrace=true;
  ftracer_stack.symtab_size=cnt;
  func_trace(NULL);
#endif
  return;
}

static long load_img() {
  if (img_file == NULL) {
    Log("No image is given. Use the default build-in image.");
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
  assert(ret == 1);

  fclose(fp);

  load_elf();

  return size;
}

static int parse_args(int argc, char *argv[]) {
  const struct option table[] = {
    {"batch"    , no_argument      , NULL, 'b'},
    {"log"      , required_argument, NULL, 'l'},
    {"diff"     , required_argument, NULL, 'd'},
    {"port"     , required_argument, NULL, 'p'},
    {"help"     , no_argument      , NULL, 'h'},
    {0          , 0                , NULL,  0 },
  };
  int o;
  int filecount=0;
  while ( (o = getopt_long(argc, argv, "-bhl:d:p:", table, NULL)) != -1) {
    switch (o) {
      case 'b': sdb_set_batch_mode(); break;
      case 'p': sscanf(optarg, "%d", &difftest_port); break;
      case 'l': log_file = optarg; break;
      case 'd': diff_so_file = optarg; break;
      case 1:
        filecount++;
        if(filecount==1){img_file = optarg;break;}
        else if(filecount==2){elf_file = optarg;return 0;}
      default:
        printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
        printf("\t-b,--batch              run with batch mode\n");
        printf("\t-l,--log=FILE           output log to FILE\n");
        printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
        printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
        printf("\n");
        exit(0);
    }
  }
  return 0;
}

void init_monitor(int argc, char *argv[]) {
  /* Perform some global initialization. */

  /* Parse arguments. */
  parse_args(argc, argv);

  /* Set random seed. */
  init_rand();

  /* Open the log file. */
  init_log(log_file);

  /* Initialize memory. */
  init_mem();

  /* Initialize devices. */
  IFDEF(CONFIG_DEVICE, init_device());

  /* Perform ISA dependent initialization. */
  init_isa();

  /* Load the image to memory. This will overwrite the built-in image. */
  long img_size = load_img();

  /* Initialize differential testing. */
  init_difftest(diff_so_file, img_size, difftest_port);

  /* Initialize the simple debugger. */
  init_sdb();

  IFDEF(CONFIG_ITRACE, init_disasm());

  /* Display welcome message. */
  welcome();
}
#else // CONFIG_TARGET_AM
static long load_img() {
  extern char bin_start, bin_end;
  size_t size = &bin_end - &bin_start;
  Log("img size = %ld", size);
  memcpy(guest_to_host(RESET_VECTOR), &bin_start, size);
  return size;
}

void am_init_monitor() {
  init_rand();
  init_mem();
  init_isa();
  load_img();
  IFDEF(CONFIG_DEVICE, init_device());
  welcome();
}
#endif
