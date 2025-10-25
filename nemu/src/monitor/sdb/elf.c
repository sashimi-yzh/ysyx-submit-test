#include <common.h>
#include <elf.h>
struct ELF
{
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
} typedef ELF;
static ELF *elf = NULL;
void init_elf(char *elf_file)
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
	char *buf = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (buf == MAP_FAILED)
	{
		perror("failed to mmap elf file");
		return;
	}
	elf = (ELF *)calloc(sizeof(ELF), 1);
	elf->ehdr = (Elf32_Ehdr *)buf;
	if (elf->ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
		elf->ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
		elf->ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
		elf->ehdr->e_ident[EI_MAG3] != ELFMAG3)
	{
		perror("not a valid elf file");
		return;
	}
	printf("ELF Type: %d-bit\n", elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32 ? 32 : 64);
	printf("Entry Point: 0x%lx\n", (unsigned long)elf->ehdr->e_entry);
	elf->shdr = (Elf32_Shdr *)(buf + elf->ehdr->e_shoff);
	elf->phdr = (Elf32_Phdr *)(buf + elf->ehdr->e_phoff);
	for (int i = 0; i < elf->ehdr->e_shnum; i++)
	{
		if (elf->shdr[i].sh_type == SHT_SYMTAB)
		{
			elf->symtab = &elf->shdr[i];
			elf->strtab = &elf->shdr[elf->shdr[i].sh_link];
			break;
		}
	}
	if (elf->symtab == NULL || elf->strtab == NULL)
	{
		perror("failed to find symbol table");
		return;
	}
	elf->sym = (Elf32_Sym *)(buf + elf->symtab->sh_offset);
	elf->strtab_buf = (char *)(buf + elf->strtab->sh_offset);
	for (int i = 0; i < elf->symtab->sh_size / sizeof(Elf32_Sym); i++)
	{
		if (ELF32_ST_TYPE(elf->sym[i].st_info) == STT_FUNC)
		{
			printf("Function: %s, Address: 0x%x\n", elf->strtab_buf + elf->sym[i].st_name, elf->sym[i].st_value);
		}
	}
}
void check(char *inst)
{
	if (!elf)
		return;
	uint32_t addr = 0;
	unsigned char insts[4];
	uint32_t full_inst = 0;
	// printf("Check Instruction: %s\n", inst);
	sscanf(inst, "%x: %2hhx %2hhx %2hhx %2hhx", &addr, &insts[3], &insts[2], &insts[1], &insts[0]);
	memcpy(&full_inst, insts, 4);
	// printf("Full Instruction: 0x%x\n", full_inst);
	if (elf->is_ret)
	{
		// 找出这条指令在哪个函数中调用的，打印从哪个函数返回
		for (int i = 0; i < elf->symtab->sh_size / sizeof(Elf32_Sym); i++)
		{
			if (ELF32_ST_TYPE(elf->sym[i].st_info) == STT_FUNC)
			{
				if (elf->prev_addr >= elf->sym[i].st_value && elf->prev_addr < elf->sym[i].st_value + elf->sym[i].st_size)
				{

					if (strcmp(elf->strtab_buf + elf->sym[i].st_name, "_start") == 0 || strcmp(elf->strtab_buf + elf->sym[i].st_name, "_trm_init") == 0 || strcmp(elf->strtab_buf + elf->sym[i].st_name, "putch") == 0)
						break;
					elf->depth--;
					// for (int j = 0; j < elf->depth; j++)
					// 	printf(" ");
					printf("0x%08x: returned %s\n", addr, elf->strtab_buf + elf->sym[i].st_name);
					elf->prev_addr = addr;
					elf->is_ret = (full_inst == 0x00008067);

					return;
				}
			}
		}
	}
	for (int i = 0; i < elf->symtab->sh_size / sizeof(Elf32_Sym); i++)
	{
		if (ELF32_ST_TYPE(elf->sym[i].st_info) == STT_FUNC)
		{
			if (addr == elf->sym[i].st_value)
			{
				if (strcmp(elf->strtab_buf + elf->sym[i].st_name, "_start") == 0 || strcmp(elf->strtab_buf + elf->sym[i].st_name, "_trm_init") == 0 || strcmp(elf->strtab_buf + elf->sym[i].st_name, "putch") == 0)
					break;

				// for (int j = 0; j < elf->depth; j++)
				// 	printf(" ");
				printf("0x%08x: called %s\n", elf->prev_addr, elf->strtab_buf + elf->sym[i].st_name);
				elf->depth++;
				break;
			}
		}
	}
	elf->is_ret = (full_inst == 0x00008067);
	elf->prev_addr = addr;
}
