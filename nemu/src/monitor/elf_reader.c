#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>
#include "elf_reader.h"

// Functab functab[30];
// int functab_count = 0;
Functab *functab = NULL;
int functab_count = 0;
int functab_capacity = 0;

#ifdef CONFIG_FTRACE

// 读取ELF文件并提取函数名
void extract_functions(const char* elf_path) {
  //初始化
		functab_count = 0;
    functab_capacity = 0;
if (functab) {
    free(functab);
    functab = NULL;
}

		printf("%s\n", elf_path);
    FILE* fp = fopen(elf_path, "rb");
    if (!fp) {
        perror("Failed to open file");
        return;
    }

    // 1. 读取ELF头部
    Elf32_Ehdr ehdr;
    //fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp);
		if (fread(&ehdr, sizeof(Elf32_Ehdr), 1, fp) != 1) {
    fprintf(stderr, "Failed to read ELF header\n");
    fclose(fp);
    return;
	}
  // 检查ELF魔数
    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "Not an ELF file: %s\n", elf_path);
        fclose(fp);
        return;
    }

    // 检查32/64位兼容性
    if (ehdr.e_ident[EI_CLASS] != ELFCLASS32) {
        fprintf(stderr, "Only 32-bit ELF files supported: %s\n", elf_path);
        fclose(fp);
        return;
    }

    // 2. 定位节区头部表
    fseek(fp, ehdr.e_shoff, SEEK_SET);
    Elf32_Shdr shdr[ehdr.e_shnum];
    //fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp);
		if (fread(shdr, sizeof(Elf32_Shdr), ehdr.e_shnum, fp) != ehdr.e_shnum) {
			fprintf(stderr, "Failed to read section headers\n");
			fclose(fp);
			return;
		}

    // 3. 获取.shstrtab（节区名称表）
    Elf32_Shdr shstrtab_hdr = shdr[ehdr.e_shstrndx];
    char shstrtab[shstrtab_hdr.sh_size];
    fseek(fp, shstrtab_hdr.sh_offset, SEEK_SET);
    //fread(shstrtab, shstrtab_hdr.sh_size, 1, fp);
		if (fread(shstrtab, shstrtab_hdr.sh_size, 1, fp) != 1) {
			fprintf(stderr, "Failed to read section string table\n");
			fclose(fp);
			return;
		}

    // 4. 查找.symtab和.strtab节区
    Elf32_Shdr symtab_hdr, strtab_hdr;
    int found_symtab = 0, found_strtab = 0;

    for (int i = 0; i < ehdr.e_shnum; i++) {
        char* name = shstrtab + shdr[i].sh_name;
        
        if (strcmp(name, ".symtab") == 0) {
            symtab_hdr = shdr[i];
            found_symtab = 1;
        } else if (strcmp(name, ".strtab") == 0) {
            strtab_hdr = shdr[i];
            found_strtab = 1;
        }
    }

    if (!found_symtab || !found_strtab) {
        fprintf(stderr, "Required sections not found\n");
        fclose(fp);
        return;
		}
    // 5. 读取.strtab内容
    char* strtab = malloc(strtab_hdr.sh_size);
    fseek(fp, strtab_hdr.sh_offset, SEEK_SET);
    //fread(strtab, strtab_hdr.sh_size, 1, fp);
		if (fread(strtab, strtab_hdr.sh_size, 1, fp) != 1) {
			fprintf(stderr, "Failed to read string table\n");
			free(strtab);
			fclose(fp);
			return;
		}

    // 6. 解析.symtab，提取函数名
    int sym_count = symtab_hdr.sh_size / symtab_hdr.sh_entsize;
    Elf32_Sym* symbols = malloc(symtab_hdr.sh_size);
    fseek(fp, symtab_hdr.sh_offset, SEEK_SET);
    //fread(symbols, symtab_hdr.sh_size, 1, fp);
		if (fread(symbols, symtab_hdr.sh_size, 1, fp) != 1) {
			fprintf(stderr, "Failed to read symbol table\n");
			free(strtab);
			free(symbols);
			fclose(fp);
			return;
		}

    //printf("Found functions:\n");
    for (int i = 0; i < sym_count; i++) {
        unsigned char type = ELF32_ST_TYPE(symbols[i].st_info);
        if (type == STT_FUNC) {  // 过滤函数符号
            char* func_name = strtab + symbols[i].st_name;
            
        if (functab_count >= functab_capacity) {
        // 计算新容量：首次分配32个，之后每次翻倍
        int new_capacity = (functab_capacity == 0) ? 32 : functab_capacity * 2;
        
        // 重新分配内存
        Functab *new_tab = realloc(functab, new_capacity * sizeof(Functab));
        
        if (!new_tab) {
            // 内存分配失败处理
            fprintf(stderr, "Error: Memory allocation failed for %d functions\n", new_capacity);
            fprintf(stderr, "Current function count: %d, aborting further processing\n", functab_count);
            break;  // 中断循环
        }
        functab = new_tab;
        functab_capacity = new_capacity;
        //printf("Resized function table to %d entries\n", functab_capacity);
      }

						strncpy(functab[functab_count].func_name, func_name, sizeof(functab[0].func_name) - 1);
						functab[functab_count].func_name[sizeof(functab[0].func_name) - 1] = '\0';
						functab[functab_count].value = symbols[i].st_value;
						functab_count ++;
						//printf("  [%s@%08x]\n", func_name, symbols[i].st_value);
        }
    }

		//便历程序
		// for(int i = 0; i < functab_count; i ++){
		// 	printf("  [%s@%08x]\n", functab[i].func_name, functab[i].value);
		// }

    // 7. 清理资源
    free(strtab);
    free(symbols);
    fclose(fp);
}
#else
void extract_functions(const char* elf_path) {}
#endif