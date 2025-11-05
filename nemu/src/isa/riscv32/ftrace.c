#include "./include/ftrace.h"
#include <stdio.h>
#include <string.h>
#include "./include/elfread.h"
#include <stdlib.h>
#include <common.h>
#include <fmt-def.h>

/*
enum {
        FUNC_NONE = 0,
        FUNC_CALL,
        FUNC_RET
}FUNC_TYPE;

typedef struct {
        char* name;
        word_t value;
        word_t size;
} Func_List;

typedef struct Func_Call{
        word_t addr1; //源地址
        word_t addr2; //跳转的地址
        uint32_t func_index; //function name在函数列表中。
        uint8_t type;    //call or ret
        uint32_t depth;
        struct Func_Call* prev;
        struct Func_Call* next;
} Func_Call;


bool ftrace_enabled = false;
char* elf_file = NULL;

ElfN_Ehdr *elf_header = NULL;
ElfN_Shdr *section_headers = NULL;
ElfN_Shdr *symtab_hdr = NULL;
ElfN_Shdr *strtab_hdr = NULL;
ElfN_Sym *symtab = NULL;
Func_List *func_list = NULL;
Func_Call *func_call_list = NULL;

int func_num = 0;
int stack_depth = 0;




void ftrace_phase_elf(const char* _elf_file);
void ftrace_print_func_list();
void ftrace_init(const char* _img_file);
void ftrace_func_call_list_append(const Func_Call* f);


void ftrace_init(const char* _img_file)
{
        //printf("%s: %d\n",__func__,ftrace_enabled);
        if(_img_file == NULL)
                return;

        //xxxx.bin --> xxxx.elf
        if(elf_file != NULL)
                free(elf_file);
        size_t len =  strlen(_img_file);
        elf_file = (char*)malloc(len+1);
        strncpy(elf_file,_img_file, len-3);
        strcpy(elf_file + len -3 , "elf");
        
        //printf("%s: %s\n",__func__,elf_file);
        ftrace_enabled = true;
        //printf("%s: %d\n",__func__,ftrace_enabled);
        ftrace_phase_elf(elf_file);
}

void ftrace_phase_elf(const char* _elf_file)
{
        FILE* fp = fopen(_elf_file, "r");

	if (fp == NULL) {
		printf("Can not open file! \n");
                return;
	}

        //读取ELF Header
        if(elf_header != NULL)
                free(elf_header);
	elf_header = (ElfN_Ehdr *)malloc(sizeof(ElfN_Ehdr));
	read_elf_header(fp, elf_header);
	//print_elf_header(*elf_header);

	//读取Section Header Table
	fseek(fp, elf_header->e_shoff, SEEK_SET);
        if(section_headers != NULL)
                free(section_headers);
	section_headers = (ElfN_Shdr*)malloc(elf_header->e_shnum * sizeof(ElfN_Shdr));
	for (int i = 0; i < elf_header->e_shnum; i++) {
        	read_section_header(fp, &section_headers[i], elf_header, i);
   	}
	//print_section_headers(fp, elf_header, section_headers, elf_header->e_shnum);


	//找到符号表和字符串表
	for(int i = 0; i < elf_header->e_shnum; i++){
		if(section_headers[i].sh_type == SHT_SYMTAB){
			symtab_hdr = &section_headers[i];
			strtab_hdr = &section_headers[symtab_hdr->sh_link];
			break;
		}
			
	}

	//读取Symbol Table
	int syms_num = symtab_hdr->sh_size / symtab_hdr->sh_entsize;
	 symtab = (ElfN_Sym*)malloc(syms_num * sizeof(ElfN_Sym));
	read_symtab(fp, symtab, symtab_hdr);
	//print_symtab(fp, symtab, strtab_hdr, syms_num);

        if(func_list != NULL){
                for (int i = 0; i < func_num; i++){
                        free(func_list[i].name);
                }
        }

        if(func_num != 0) 
                func_num = 0;

        for(int i = 0; i< syms_num; i++){
                if(ELFN_ST_TYPE(symtab[i].st_info) == STT_FUNC){
                        func_num++;
                }
        }
        
        func_list = (Func_List*)malloc(sizeof(Func_List)*func_num);
	
        char buf[100];
        int index = 0;
	for(int i = 0; i < syms_num; i++){
                if(ELFN_ST_TYPE(symtab[i].st_info) == STT_FUNC)
                {
                        func_list[index].value = symtab[i].st_value;
                        func_list[index].size = symtab[i].st_size;
                        get_symtab_entry_name(fp, buf, strtab_hdr, &symtab[i]);
		        func_list[index].name = (char*)malloc(strlen(buf)+1);
                        strcpy(func_list[index].name, buf);
                        index++;
                }		
	}       

        ftrace_print_func_list();
}

void ftrace_print_func_list()
{
        if(func_list != NULL){
                for(int i = 0; i < func_num; i++){
                        printf("%s: 0x" FMT_WORD_HEX_WIDTH "\n", func_list[i].name, func_list[i].value);

                }
        }
}

void _get_func_name(word_t addr, char** name, uint32_t* index){
        for(int i=0; i<func_num; i++)
        {
                if(addr >= func_list[i].value && addr < func_list[i].value + func_list[i].size)
                {
                        *name = func_list[i].name;
                        *index = i;
                        return;
                }
        }
        *name = NULL;
        *index = -1;
}

void ftrace_func_call(word_t pc, word_t dnpc,  uint32_t inst){
        if(!ftrace_enabled)
                return;
        static int32_t pre_func_index = -1;
        Func_Call f;
        f.type = FUNC_CALL;
        for(int i = 0; i < func_num; i++){
                if(dnpc == func_list[i].value){
                        if((inst & 0x7f) == 0x6f){ //jal指令

                        }
                        else if((inst & 0x7f) == 0x67) //jalr指令
                        {
                                uint32_t rd = (inst >> 7) & 0x1f;
                                //uint32_t rs1 = (inst >> 15) & 0x1f;
                              
                                if(rd ==0)
                                        f.type = FUNC_RET; // 标记为返回
                                
                        }

                        if(pre_func_index == i){
                                f.type = FUNC_RET;
                        }
                        printf("Call function: %s: " FMT_WORD_HEX " -> " FMT_WORD_HEX "\n", func_list[i].name, pc , dnpc);

                        
                        f.addr1 = pc;
                        f.addr2 = dnpc;
                        f.func_index = i;
                        f.depth = stack_depth;
                        ftrace_func_call_list_append(&f);

                        if( f.type == FUNC_CALL) stack_depth++; else stack_depth--;

                        pre_func_index = i;
                        return;
                }
        }
}

void ftrace_func_call_list_print()
{
        Func_Call* p = func_call_list;
        int depth;
        Func_Call* p_next = NULL;
        while(p != NULL){
                
                p_next = p;
                p = p->prev;
        }
        p = p_next;
        while(p != NULL){
                depth = p->depth;

                printf("0x" FMT_WORD_HEX ":  ", p->addr1);   

                while(depth-- > 0) printf("  ");
                if(p->type == FUNC_CALL){
                        printf("call ");
                } 
                else if( p-> type == FUNC_RET){
                        printf("ret  ");
                }

                printf("[%s@0x" FMT_WORD_HEX "]\n", func_list[p->func_index].name, p->addr2);

                p = p->next;
        }
}

void ftrace_func_call_list_append(const Func_Call* f)
{
        if(!ftrace_enabled)
                return;
        //printf("Push: %s: 0x" FMT_WORD_HEX_WIDTH "\n", func_list[func_index].name, pc);
        Func_Call *item = (Func_Call*)malloc(sizeof(Func_Call));
        item->addr1 = f->addr1;
        item->addr2 = f->addr2;
        item->func_index = f->func_index;
        item->type = f->type;
        item->depth = f->depth;
        if(func_call_list != NULL)
                func_call_list->next = item;
        item->prev = func_call_list;
        func_call_list = item;
        ftrace_func_call_list_print();
}

*/


void ftrace_init(const char* _img_file){};
void ftrace_func_call(word_t pc, word_t dnpc, uint32_t inst){};
void ftrace_func_ret(word_t pc, uint32_t inst){};
void ftrace_func_call_list_print(){};