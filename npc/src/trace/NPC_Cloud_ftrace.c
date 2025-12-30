#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


//#include <nvboard.h>   //启用nvboard
#include <elf.h>  // 主要ELF定义


#include "npc.h"
#include "trace.h"


/*实现ftrace:为NPC传入一个ELF文件，从ELF文件中读出符号表和字符串表。*/
Ftrace_Elf_Symbol_Table  *ftrace_symbol_table = NULL;
size_t ftrace_symbol_table_size = 0;
void load_elf(const char *elf_file) {
	//printf("=== parse_elf 开始执行 ===\n");
    //printf("ELF 文件路径: %s\n", elf_file ? elf_file : "NULL");

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
    char *string_table = (char*)malloc(strtab_header.sh_size);
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
    ftrace_symbol_table = (Ftrace_Elf_Symbol_Table *)malloc(num_symbols * sizeof(Ftrace_Elf_Symbol_Table));
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
    Log("Loaded %ld symbol tables from %s foe ftrace.", ftrace_symbol_table_size , elf_file);
}


/**实现ftrace的相关函数*/
TailRecNode  *tail_rec_head = NULL;
int call_depth = 0;

static int find_symbol_func(uint32_t target, bool is_call) {
	int i;
	for (i = 0; i < ftrace_symbol_table_size ; i++) {
		if (ELF32_ST_TYPE(ftrace_symbol_table[i].info) == STT_FUNC) {
			if (is_call) {
				if (ftrace_symbol_table[i].addr == target) break; // 对于函数调用：精确匹配目标地址（函数入口点）
			} else {
				if (ftrace_symbol_table[i].addr <= target && target < ftrace_symbol_table[i].addr + ftrace_symbol_table[i].size) break;
			}//对于函数返回：范围匹配（函数内的任何地址）
		}
	}
	return i < ftrace_symbol_table_size  ?i:-1;
}

void trace_func_call(uint32_t pc, uint32_t target, bool is_tail) {
	if (ftrace_symbol_table == NULL) return;
	// 初始化：第一次调用时创建链表头节点
	if (tail_rec_head == NULL) {
		tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
        tail_rec_head->pc = 0;
        tail_rec_head->depth = 0;
        tail_rec_head->next = NULL;
    }

	call_depth++;
	if (call_depth <= 2) return; // 忽略前2层调用（_trm_init和main()）

	int i = find_symbol_func(target, true);

	//输出
	printf("0x%x: ", pc);                               // 地址部分
	for(int k=0;k<(call_depth-2);k++) {printf(" ");}          // 缩进部分  
	printf("call [");                                         // call固定文本
	if (i >= 0) {printf("%s", ftrace_symbol_table[i].name);}  // 函数名
	else {printf("???"); }                                    // 未知函数
    printf("@ 0x%x ]\n", target);                      // 目标地址和换行

	// 如果是尾调用，加入链表记录信息
	if (is_tail) {
		TailRecNode *node = (TailRecNode *)malloc(sizeof(TailRecNode));
		node->pc = pc;
		node->depth = call_depth - 1;
		node->next = tail_rec_head->next;
		tail_rec_head->next = node;
	}
}

void trace_func_ret(uint32_t pc) {
	if (ftrace_symbol_table == NULL) return;
	//初始化：第一次调用时创建链表头节点
	if (tail_rec_head == NULL) {
		tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
        tail_rec_head->pc = 0;
        tail_rec_head->depth = 0;
        tail_rec_head->next = NULL;
    }
	
	if (call_depth <= 2) return; // 忽略前2层调用（_trm_init和main()）
	int i = find_symbol_func(pc, false);

	//输出
	printf("0x%x: ", pc);                                     // 地址部分
	for(int k=0;k<(call_depth-2);k++) {printf(" ");}          // 缩进部分  
	printf("ret [");                                          // ret固定文本
	if (i >= 0) {printf("%s", ftrace_symbol_table[i].name);}  // 函数名
	else {printf("???");}                                     // 未知函数   	                            
	printf("]\n");                                            // ]和换行

	call_depth--;

	// 当遇到函数返回时，检查是否有待处理的尾调用，有的话删除链表信息
	TailRecNode *node = tail_rec_head->next;
	if ( (node != NULL) && (node->depth == call_depth) ){
			uint32_t ret_target = node->pc;
			tail_rec_head->next = node->next;
			free(node);
			trace_func_ret(ret_target);
	}
}
