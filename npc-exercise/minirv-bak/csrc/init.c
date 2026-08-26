#include "common.h"
#include "mem.h"
#include "cpu.h"
#include "devices.h"
#include "trace.h"
#include <elf.h>
#include <getopt.h>
static int parse_args(int argc, char *argv[]);
static long load_img();
static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;

char *IMAGE_NAME;
char *ELF_NAME;
VerilatedContext* contextp = NULL;
Vtop* top = NULL;

void init(int argc, char** argv){
	//init PRAISE
	parse_args(argc, argv);
    //init log
	extern void init_log(const char *log_file);
	init_log(log_file);

    //init MEMORY & elf
	long img_size = load_img();

	//init verilator
	contextp = new VerilatedContext;
	top = new Vtop{contextp};
	contextp->commandArgs(argc, argv);
	top->clk=0;top->rst=0;top->eval();contextp->timeInc(10);
	top->clk=0;top->rst=1;top->eval();contextp->timeInc(10);
	top->clk=0;top->rst=0;top->eval();contextp->timeInc(10);
	// top->clk=1;top->rst=0;top->eval();contextp->timeInc(10);
	// top->clk=0;top->rst=0;top->eval();contextp->timeInc(10);

    //init CPU
	cpu.pc = RESET_VECTOR;
	cpu.dnpc = RESET_VECTOR;
    cpu.state = NPC_STOP;
	cpu.halt_ret = 0;
	cpu.count = 0;
	cpu.inst = MEM(cpu.pc);
	//cpu.pc=
	
	//init regex
	extern void init_regex();
	init_regex();
	//init WP
	extern void init_wp_pool();
	init_wp_pool();

	//init devices
	init_rtc();
	init_serial();

	//init itrace
	#ifdef CONFIG_ITRACE_ENABLE
	init_disasm();
	#endif
	
	//init difftest
	#ifdef CONFIG_DIFFTEST_ENABLE
	extern void init_difftest(char *ref_so_file, long img_size);
	init_difftest(diff_so_file, img_size);
	#endif
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
    extern void sdb_set_batch_mode();
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

static void load_elf(){
#ifdef CONFIG_FTRACE_ENABLE
extern symtab_t *funsymtab;
extern ftracer_stack_t  ftracer_stack;
	if (elf_file == NULL) {Log("Cannot open .elf. Disabled 'ftrace'.");return;}
	int elf_size;
	FILE *fp = fopen(elf_file,"rb");
	if(fp==NULL){Log("Cannot open %s. Disabled 'ftrace'.",elf_file);return;}
	//Get ELF size
  	if(fseek(fp,0,SEEK_END)!=0){fclose(fp);Log("Cannot init 'ftrace'. (fseek() ERROR) Disabled 'ftrace'.");return;}
  	elf_size=ftell(fp);
  	Log("Load .elf. Size = %d",elf_size);

  	//Get ELF data
  	char *elf_buf = (char*)malloc(elf_size);
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
      		funsymtab=(symtab_t*)malloc(sizeof(symtab_t)*elf_section_header[i].sh_size);
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
		//MEM[0]=0b00000000100000000000000010010011;//addi r1,r0,8
		//MEM[1]=0b00000000010000001000010001100111;//jalr r8,4(r1)
		MEM[ 0]=0b00000000100000000000000010010011;//addi r1,r0,8
		MEM[ 1]=0b00000000001000001000000100010011;//addi r2,r1,2
		MEM[ 2]=0b00000000000100010000000110110011;//add  r3,r1,r2
		MEM[ 3]=0b00000000000000000111000110110111;//lui  r3,0x7000
		MEM[ 4]=0b00010001000100011000001000010011;//addi r4,r3,0x111
		MEM[ 5]=0b00000000010000000010000010000011;//lw   r1,4(r0)
		MEM[ 6]=0b00000000001000000100000100000011;//lbu  r2,+2(r0)
		MEM[ 7]=0b00000000001000000000000110000011;//lb   r3,+2(r0)
		MEM[ 8]=0b00010000001100000010000000100011;//sw   r3,0x100(r0)
		MEM[ 9]=0b00010000001100000000001100100011;//sb   r3,0x106(r0)
		MEM[10]=0b00010000000000000010001010000011;//lw   r5,0x100(r0)
		MEM[11]=0b00010000010000000010001100000011;//lw   r6,0x104(r0)
		MEM[12]=0b00000000000100000000010100010011;//addi r10,r0,1
		MEM[13]=0b00000000000100000000000001110011;//ebreak
		MEM[14]=0b00000000010000000000010001100111;//jalr r8,4(r0)
    return 4096; // built-in image size
  }

  FILE *fp = fopen(img_file, "rb");
  Assert(fp, "Can not open '%s'", img_file);

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);

  Log("The image is %s, size = %ld", img_file, size);

  fseek(fp, 0, SEEK_SET);
  int ret = fread((uint8_t*)MEM + RESET_VECTOR - CONFIG_MBASE, size, 1, fp);
  assert(ret == 1);
  fclose(fp);
  load_elf();
  return size;
}