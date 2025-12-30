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

#include <elf.h>  // 主要ELF定义
#include <cpu/itrace.h>

void init_rand();
void init_log(const char *log_file);
void init_mem();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_device();
void init_sdb();
void init_disasm();

static void welcome() {
	Log("Trace: %s", MUXDEF(CONFIG_TRACE, ANSI_FMT("ON", ANSI_FG_GREEN), ANSI_FMT("OFF", ANSI_FG_RED)));
	IFDEF(CONFIG_TRACE, Log("If trace is enabled, a log file will be generated "
				"to record the trace. This may lead to a large log file. "
				"If it is not necessary, you can disable it in menuconfig"));
	Log("Build time: %s, %s", __TIME__, __DATE__);
	printf("Welcome to %s-NEMU!\n", ANSI_FMT(str(__GUEST_ISA__), ANSI_FG_YELLOW ANSI_BG_RED));
	printf("For help, type \"help\"\n");
	Log("Exercise: Please remove me in the source code and compile NEMU again.");
	//assert(0);
}

#ifndef CONFIG_TARGET_AM
#include <getopt.h>

void sdb_set_batch_mode();

static char *log_file = NULL;
static char *diff_so_file = NULL;
static char *img_file = NULL;
static int difftest_port = 1234;

static long load_img() {
	if (img_file == NULL) {
		Log("No image is given. Use the default build-in image.");
		return 4096; // built-in image size
	}

	FILE *fp = fopen(img_file, "rb");
	Assert(fp, "Can not open '%s'", img_file);

	fseek(fp, 0, SEEK_END);
	long size = ftell(fp); // 获取文件大小

	Log("The image is %s, size = %ld", img_file, size); // 检查不超出内存

	fseek(fp, 0, SEEK_SET);

	int ysyxsoc_difftest = 0;
	IFDEF(CONFIG_YSYXSOC_DIFFTEST, ysyxsoc_difftest = 1);
	if (ysyxsoc_difftest == 0){
		int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);   // 读取文件到内存
		assert(ret == 1);
	} else {
		//printf("start load data");
		int ret = fread(guest_to_host_flash(0x30000000), size, 1, fp);   // 读取文件到flash
		//printf("finish load data");
		assert(ret == 1);
	}
	
	
	

	fclose(fp);

	return size;
}

/*实现ftrace:为NEMU传入一个ELF文件，从ELF文件中读出符号表和字符串表。*/
static char *elf_file = NULL;
Ftrace_Elf_Symbol_Table  *ftrace_symbol_table = NULL;
size_t ftrace_symbol_table_size = 0;
void parse_elf(const char *elf_file) {
	printf("=== parse_elf 开始执行 ===\n");
    printf("ELF 文件路径: %s\n", elf_file ? elf_file : "NULL");

    if (elf_file == NULL)  return;
    // 打开ELF文件
    FILE *fp = fopen(elf_file, "rb");
    Assert(fp, "Can not open '%s'", elf_file);

    // 读取ELF header
    Elf32_Ehdr elf_header;
    if (fread(&elf_header, sizeof(Elf32_Ehdr), 1, fp) <= 0) { //没有读取到数据
        fclose(fp);  //关闭文件
		assert(0 && "Failed to read ELF header\n");
    }
    // 检查文件是否为ELF文件
    if (memcmp(elf_header.e_ident, ELFMAG, SELFMAG) != 0) {
        fclose(fp);
        assert(0 && "Not an ELF file\n");
    }
	
    //寻找字符串表节
    fseek(fp, elf_header.e_shoff, SEEK_SET); //移动文件指针,从文件开头,到节头表
    Elf32_Shdr strtab_header  = {0};
    while (strtab_header.sh_type != SHT_STRTAB) {
        if (fread(&strtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            assert(0 && "Failed to read section header\n");
        }
    }

    // 读取字符串表节内容(函数名称)
    char *string_table = malloc(strtab_header.sh_size);
    fseek(fp, strtab_header.sh_offset, SEEK_SET);   //指针移动到字符串表节
    if (fread(string_table, strtab_header.sh_size, 1, fp) <= 0) {
        fclose(fp);
        assert(0 && "Failed to read string table data\n");
    }

    // 寻找符号表节（函数信息）
    Elf32_Shdr symtab_header  = {0};
    fseek(fp, elf_header.e_shoff, SEEK_SET);  //将文件指针移动到节头表
    while (symtab_header.sh_type != SHT_SYMTAB) {
        if (fread(&symtab_header, sizeof(Elf32_Shdr), 1, fp) <= 0) {
            fclose(fp);
            assert(0 && "Failed to read section header entry\n");
        }
    }

    /* 读取符号表中的每个符号项 */ 
    fseek(fp, symtab_header.sh_offset, SEEK_SET); //指针移动到字符串表节
    Elf32_Sym symbol;
    // 确定符号表的条数
    size_t num_symbols = symtab_header.sh_size / symtab_header.sh_entsize;
    // 分配内存用于存储符号表
    ftrace_symbol_table = malloc(num_symbols * sizeof(Ftrace_Elf_Symbol_Table));
	size_t function_count = 0;
    for (size_t i = 0; i < num_symbols; i++) {
        if (fread(&symbol, sizeof(Elf32_Sym), 1, fp) <= 0 ) {
            fclose(fp);
            assert(0 && "Failed to read symbol entry");
        }
        // 判断符号是否为函数，并且函数的大小不为零
        if (ELF32_ST_TYPE(symbol.st_info) == STT_FUNC && symbol.st_size != 0) {
            // 从字符串表中获取符号名称
            const char *name = string_table  + symbol.st_name;
            // 存储符号信息到 symbol_table 结构体数组
			if (name == NULL || *name == '\0') {
    			ftrace_symbol_table[i].name[0] = '\0';
    			continue;
			}
            strncpy(ftrace_symbol_table[function_count].name, name, sizeof(ftrace_symbol_table[i].name) - 1);
            ftrace_symbol_table[function_count].addr = symbol.st_value;     // 函数地址
            ftrace_symbol_table[function_count].info = symbol.st_info;      // 符号信息
            ftrace_symbol_table[function_count].size = symbol.st_size;      // 函数大小
			function_count++;   //符号表(函数)的条数
        }
    }
	ftrace_symbol_table_size = function_count;

    // for (int i = 0; i < (ftrace_symbol_table_size < 10 ? ftrace_symbol_table_size : 10); i++) {
    //     printf("符号[%d]: 地址=0x%x, 名称='%s', 大小=%u\n", 
    //            i, ftrace_symbol_table[i].addr, ftrace_symbol_table[i].name, ftrace_symbol_table[i].size);
    // }

    // 关闭文件并释放内存
    fclose(fp);
    free(string_table);
}

static int parse_args(int argc, char *argv[]) {
	const struct option table[] = {
		{"batch"    , no_argument      , NULL, 'b'},
		{"log"      , required_argument, NULL, 'l'},
		{"diff"     , required_argument, NULL, 'd'},
		{"port"     , required_argument, NULL, 'p'},
		{"help"     , no_argument      , NULL, 'h'},
		{"elf"      , required_argument, NULL, 'e'},
		{0          , 0                , NULL,  0 },
	};
	int o;
	while ( (o = getopt_long(argc, argv, "-bhl:d:p:e:", table, NULL)) != -1) {
		switch (o) {
			case 'b': sdb_set_batch_mode(); break;
			case 'p': sscanf(optarg, "%d", &difftest_port); break;
			case 'l': log_file = optarg; break;
			case 'd': diff_so_file = optarg; break;
			case 'e': elf_file = optarg; break;
			case 1: img_file = optarg; return 0;
			default:
				printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
				printf("\t-b,--batch              run with batch mode\n");
				printf("\t-l,--log=FILE           output log to FILE\n");
				printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
				printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
				printf("\t-e,--elf=FILE           elf file to be parsed\n");
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
	
	/* Initialize .elf */
	if (elf_file != NULL){parse_elf(elf_file);}

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
	init_difftest(diff_so_file, img_size, difftest_port);//differential testing的初始化

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
