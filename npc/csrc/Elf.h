#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <elf.h>
class Elf
{
public:
	Elf() : ehdr(NULL), phdr(NULL), shdr(NULL), strtab(NULL), strtab_buf(NULL), symtab(NULL), sym(NULL), prev_addr(0), is_ret(false), depth(0)
	{
	}
	void open_elf(char *elf_file)
	{
		if (!elf_file)
			return;
		int fd = open(elf_file, O_RDONLY);
		if (fd < 0)
		{
			perror("failed to open elf file");
			return;
		}
		struct stat st;
		if (fstat(fd, &st) < 0)
		{
			perror("failed to fstat elf file");
			return;
		}
		char *buf = (char *)mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
		if (buf == MAP_FAILED)
		{
			perror("failed to mmap elf file");
			return;
		}
		ehdr = (Elf32_Ehdr *)buf;
		if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
			ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
			ehdr->e_ident[EI_MAG3] != ELFMAG3)
		{
			perror("not a valid elf file");
			return;
		}
		printf("ELF Type: %d-bit\n", ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
		printf("Entry Point: 0x%lx\n", (unsigned long)ehdr->e_entry);
		shdr = (Elf32_Shdr *)(buf + ehdr->e_shoff);
		phdr = (Elf32_Phdr *)(buf + ehdr->e_phoff);
		for (int i = 0; i < ehdr->e_shnum; i++)
		{
			if (shdr[i].sh_type == SHT_SYMTAB)
			{
				symtab = &shdr[i];
				strtab = &shdr[shdr[i].sh_link];
				break;
			}
		}
		if (symtab == NULL || strtab == NULL)
		{
			perror("failed to find symbol table");
			return;
		}
		sym = (Elf32_Sym *)(buf + symtab->sh_offset);
		strtab_buf = (char *)(buf + strtab->sh_offset);
		for (int i = 0; i < symtab->sh_size / sizeof(Elf32_Sym); i++)
		{
			if (ELF32_ST_TYPE(sym[i].st_info) == STT_FUNC)
			{
				printf("Function: %s, Address: 0x%x\n", strtab_buf + sym[i].st_name, sym[i].st_value);
			}
		}
	}
	~Elf()
	{
		// if (ehdr)
		// 	free(ehdr);
		// if (phdr)
		// 	free(phdr);
		// if (shdr)
		// 	free(shdr);
		// if (strtab_buf)
		// 	free(strtab_buf);
		// if (symtab)
		// 	free(symtab);
		// if (sym)
		// 	free(sym);
	}
	void check(char *inst)
	{
		if (!ehdr)
			return;
		uint32_t addr = 0;
		uint32_t full_inst = 0;
		// printf("Check Instruction: %s\n", inst);
		sscanf(inst, "pc %x inst %x", &addr, &full_inst);
		// printf("Full Instruction: 0x%x\n", full_inst);
		if (is_ret)
		{
			// 找出这条指令在哪个函数中调用的，打印从哪个函数返回
			for (int i = 0; i < symtab->sh_size / sizeof(Elf32_Sym); i++)
			{
				if (ELF32_ST_TYPE(sym[i].st_info) == STT_FUNC)
				{
					if (prev_addr >= sym[i].st_value && prev_addr < sym[i].st_value + sym[i].st_size)
					{
						if (strcmp(strtab_buf + sym[i].st_name, "_start") == 0 || strcmp(strtab_buf + sym[i].st_name, "_trm_init") == 0 || strcmp(strtab_buf + sym[i].st_name, "putch") == 0)
							return;
						depth--;
						for (int j = 0; j < depth; j++)
							printf(" ");
						printf("0x%08x: returned %s\n", addr, strtab_buf + sym[i].st_name);
						prev_addr = addr;
						is_ret = (full_inst == 0x00008067);

						return;
					}
				}
			}
		}
		for (int i = 0; i < symtab->sh_size / sizeof(Elf32_Sym); i++)
		{
			if (ELF32_ST_TYPE(sym[i].st_info) == STT_FUNC)
			{
				if (addr == sym[i].st_value)
				{
					if (strcmp(strtab_buf + sym[i].st_name, "_start") == 0 || strcmp(strtab_buf + sym[i].st_name, "_trm_init") == 0 || strcmp(strtab_buf + sym[i].st_name, "putch") == 0)
						break;

					for (int j = 0; j < depth; j++)
						printf(" ");
					printf("0x%08x: called %s\n", prev_addr, strtab_buf + sym[i].st_name);
					depth++;
					break;
				}
			}
		}
		is_ret = (full_inst == 0x00008067);
		prev_addr = addr;
	}

private:
	Elf32_Ehdr *ehdr;
	Elf32_Phdr *phdr;
	Elf32_Shdr *shdr;
	Elf32_Shdr *strtab;
	char *strtab_buf;
	Elf32_Shdr *symtab;
	Elf32_Sym *sym;
	uint32_t prev_addr;
	bool is_ret;
	int depth;
};
