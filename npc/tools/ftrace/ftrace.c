#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ftrace.h"
#include "fmt-def.h"

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


void ftrace_phase_elf(const char* _elf_file);
void ftrace_print_func_list();
void ftrace_init(const char* _img_file);

bool ftrace_enabled = false;
char* elf_file = NULL;

ElfN_Ehdr *elf_header = NULL;
ElfN_Shdr *section_headers = NULL;
ElfN_Shdr *symtab_hdr = NULL;
ElfN_Shdr *strtab_hdr = NULL;
ElfN_Sym *symtab = NULL;
Func_List *func_list = NULL;


int func_num = 0;


void ftrace_reset()
{
        if(elf_file != NULL)
                free(elf_file);
        if(elf_header != NULL)
                free(elf_header);
        if(section_headers != NULL)
                free(section_headers);
        if(symtab_hdr != NULL)
                free(symtab_hdr);
        if(strtab_hdr != NULL)
                free(strtab_hdr);
        if(symtab != NULL)
                free(symtab);
        if(func_list != NULL){
                for (int i = 0; i < func_num; i++){
                        free(func_list[i].name);
                }
                free(func_list);
        }
        func_num = 0;
}


void ftrace_init(const char* _img_file)
{
        //printf("%s",_img_file);
        if(_img_file == NULL)
                return;
        if(elf_file != NULL)
                free(elf_file);
        size_t len =  strlen(_img_file);
        elf_file = (char*)malloc(len+1);
        strncpy(elf_file,_img_file, len-3);
        strcpy(elf_file + len -3 , "elf");
        ftrace_phase_elf(elf_file);
}

void ftrace_phase_elf(const char* _elf_file)
{
        FILE* fp = fopen(_elf_file, "r");

	if (fp == NULL) {
        perror("parse_elf error");
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

        //ftrace_print_func_list();
}

void ftrace_print_func_list()
{
        if(func_list != NULL){
                for(int i = 0; i < func_num; i++){
                        printf("%-21s: 0x" FMT_WORD_HEX_WIDTH " - 0x" FMT_WORD_HEX "\n", func_list[i].name, func_list[i].value,
                                 func_list[i].value + (func_list[i].size > 0 ? func_list[i].size - 4 : 0));
                                        // _start 函数没有大小，要特殊对待
                }
        }
}


void ftrace_get_func_name(char* buf, word_t pc)
{
        for(int i=0; i<func_num; i++)
        {
                
                if(pc >= func_list[i].value && pc < func_list[i].value + func_list[i].size)
                {
                        strcpy(buf, func_list[i].name);
                        return;
                }
                else if(!strcmp(func_list[i].name,"_start")){  // _start读出的没有大小，要特殊对待
                        if(pc >= func_list[i].value && pc < func_list[i].value + 16)
                        {
                                strcpy(buf, func_list[i].name);
                                return;
                        }
                }
        }
        buf[0] = '\0';
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


