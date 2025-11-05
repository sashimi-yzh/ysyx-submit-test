#include <stdio.h>
#include "../include/elfread.h"
#include <string.h>



inline const char *get_elf_type(ElfN_Half e_type)
{
	switch (e_type)
	{
		case ET_NONE: return "NONE (None)";
		case ET_REL: return "REL (Relocatable file)";
		case ET_EXEC: return "EXEC (Executable file)";
		case ET_DYN: return "DYN (Shared object file)";
		case ET_CORE: return "CORE (Core file)";
		default: return "UNKNOWN";
	}
}

inline const char* get_elf_osabi(const unsigned char* e_ident)
{
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: return "UNIX - System V";
		case ELFOSABI_HPUX: return "HP-UX ABI";
		case ELFOSABI_NETBSD: return "NetBSD ABI";
		case ELFOSABI_LINUX: return "Linux ABI";
		case ELFOSABI_SOLARIS: return "Solaris ABI";
		case ELFOSABI_IRIX: return "IRIX ABI";
		case ELFOSABI_FREEBSD: return "FreeBSD ABI";
		case ELFOSABI_TRU64: return "TRU64 UNIX ABI";
		case ELFOSABI_ARM: return "ARM architecture ABI";
		case ELFOSABI_STANDALONE: return "Stand-alone (embedded) ABI";
		default: return "UNKNOW";
	}
}

inline const char* get_elf_machine(ElfN_Half e_machine){
	switch (e_machine)
	{
		case EM_NONE: return "An unknown machine";
		case EM_M32: return "AT&T WE 32100";
		case EM_SPARC: return "Sun Microsystems SPARC";
		case EM_386: return "Intel 80386";
		case EM_68K: return "Motorola 68000";
		case EM_88K: return "Motorola 88000";
		case EM_860: return "Intel 80860";
		case EM_MIPS: return "MIPS RS3000 (big-endian only)";
		case EM_PARISC: return "HP/PA";
		case EM_SPARC32PLUS: return "SPARC with enhanced instruction set";
		case EM_PPC: return "PowerPC";
		case EM_PPC64: return "PowerPC 64-bit";
		case EM_S390: return "IBM S/390";
		case EM_ARM: return "Advanced RISC Machines";
		case EM_SH: return "Renesas SuperH";
		case EM_SPARCV9: return "SPARC v9 64-bit";
		case EM_IA_64: return "Intel Itanium";
		case EM_X86_64: return "AMD x86-64";
		case EM_VAX: return "DEC Vax";
		case EM_RISCV: return "RISC-V";
		default: return "UNKNOWN";
		}

}

void print_elf_header(Elf64_Ehdr elf_header) {
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; i++) {
		printf("%02x ", elf_header.e_ident[i]);
	}
	printf("\n");
	printf("  %-34s %s\n", "Class:", elf_header.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
					 elf_header.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "UNKNOWN");
	printf("  %-34s %s\n", "Data:", elf_header.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
					elf_header.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" : "UNKNOW");
	printf("  %-34s %s\n", "Version:",elf_header.e_ident[EI_VERSION] == EV_CURRENT ? "1 (current)" :
					    elf_header.e_ident[EI_VERSION] == EV_NONE ? "0 (invalid)" : "UNKNOWN");
	printf("  %-34s %s\n", "OS/ABI:", get_elf_osabi(elf_header.e_ident));
	printf("  %-34s %s\n", "Type:", get_elf_type(elf_header.e_type));
	printf("  %-34s %s\n", "Machine", get_elf_machine(elf_header.e_machine));
	printf("  %-34s 0x%x\n", "Version:",elf_header.e_version);

	printf("  %-34s 0x%lx\n", "Entry Point Address", elf_header.e_entry);
	printf("  %-34s %ld (bytes into file)\n", "Start of program headers:", elf_header.e_phoff);
	printf("  %-34s %ld (bytes into file)\n", "Start of section headers:", elf_header.e_shoff);
	printf("  %-34s 0x%x\n", "Flags:", elf_header.e_flags);
	printf("  %-34s %d\n","Size of this header:", elf_header.e_ehsize);
	printf("  %-34s %d\n","Size of program headers:", elf_header.e_phentsize);
	printf("  %-34s %0d\n","Numbers of program headers", elf_header.e_phnum);
	printf("  %-34s %d (bytes)\n", "Size of section headers", elf_header.e_shentsize);
	printf("  %-34s %d\n", "Number of section headers", elf_header.e_shnum);
	printf("  %-34s %d\n", "Section header string table index:", elf_header.e_shstrndx);
}

inline const char* get_section_type_name(ElfN_Word sh_type) {
	switch (sh_type) {
		case SHT_NULL: return "NULL";
		case SHT_PROGBITS: return "PROGBITS";
		case SHT_SYMTAB: return "SYMTAB";
		case SHT_STRTAB: return "STRTAB";
		case SHT_RELA: return "RELA";
		case SHT_HASH: return "HASH";
		case SHT_DYNAMIC: return "DYNAMIC";
		case SHT_NOTE: return "NOTE";
		case SHT_NOBITS: return "NOBITS";
		case SHT_REL: return "REL";
		case SHT_SHLIB: return "SHLIB";
		case SHT_DYNSYM: return "DYNSYM";
		case SHT_INIT_ARRAY: return "INIT_ARRAY";
		case SHT_FINI_ARRAY: return "FINI_ARRAY";
		case SHT_PREINIT_ARRAY: return "PREINIT_ARRAY";
		case SHT_GROUP: return "GROUP";
		case SHT_SYMTAB_SHNDX: return "SYMTAB_SHNDX";
		case SHT_NUM: return "NUM";
		case SHT_LOOS: return "LOOS";
		case SHT_LOPROC: return "LOPROC";
		case SHT_HIPROC: return "HIPROC";
		case SHT_LOUSER: return "LOUSER";
		case SHT_HIUSER: return "HIUSER";
		//case PT_RISCV_ATTRIBUTES: return "RISCV_ATTRIBUTE";
		default: return "UNKNOWN";
	}
}


char* get_section_header_name(FILE *fp, char *dest, const ElfN_Ehdr* elf_header, const ElfN_Shdr *section_headers, int index){
	int idx = 0;
	char ch;
	const ElfN_Shdr *strtab_hdr = &section_headers[elf_header->e_shstrndx];
	fseek(fp, strtab_hdr->sh_offset + section_headers[index].sh_name, SEEK_SET);
	do
	{
		size_t _nread = fread(&ch, sizeof(char), 1, fp);
		(void)_nread;
		dest[idx++] = ch;
	} while (ch);
	dest[idx] = '\0';
	return dest;
}

char* get_section_flag_name(char *dest, uintN_t sh_flags) {
	int index = 0;
	if(sh_flags & SHF_WRITE) dest[index++] = 'W';
	if(sh_flags & SHF_ALLOC) dest[index++] = 'A';
	if(sh_flags & SHF_EXECINSTR) dest[index++] = 'X';
	if(sh_flags & SHF_MERGE) dest[index++] = 'M';
	dest[index++] = '\0';
	return dest;
}

void print_section_headers(FILE* fp, const ElfN_Ehdr* elf_header, const ElfN_Shdr* section_headers, int sh_num) {
	char buf[100];
	printf("Section Headers:\n");

#if(NBIT == 32)
#error "32位的还未实现好, 和gcc的readelf还有不同"
#endif
	if(NBIT == 32){
		printf("  [Nr]  Name              Type                Addr   Off    Size   ES Flg Lk Inf Al\n");
		for (int i = 0; i < sh_num; i++) {
			get_section_header_name(fp, buf, elf_header, &section_headers[i], i);
			printf("  [%2d] ", i);
			printf("%-18s ", buf);
			printf("%-17s ", get_section_type_name(section_headers[i].sh_type));
			printf("%08lx ", section_headers[i].sh_addr);
			printf("%06lx ", section_headers[i].sh_offset);
			printf("%06lx ", section_headers[i].sh_size);
			printf("%02lx ", section_headers[i].sh_entsize);
			printf("%03lx ", section_headers[i].sh_flags);
			printf("%02x ", section_headers[i].sh_link);
			printf("%02x ", section_headers[i].sh_info);
			printf("%02lx\n", section_headers[i].sh_addralign);
		}
	}
	else{
		printf("  [Nr]  Name             Type               Address         Offset\n"
		       "        Size             EntSize            Flags Link  Info  Align \n");
		for (int i = 0; i < sh_num; i++) {

			printf("  [%2d] ", i);
			printf("%-17s ", get_section_header_name(fp, buf, elf_header, &section_headers[i], i));
			printf("%-17s ", get_section_type_name(section_headers[i].sh_type));
			printf("%016lx ", section_headers[i].sh_addr);
			printf("%08lx\n ", section_headers[i].sh_offset);
			printf("       %016lx ", section_headers[i].sh_size);
			printf("%016lx ", section_headers[i].sh_entsize);
			printf("%5s", get_section_flag_name(buf,section_headers[i].sh_flags));
			printf("%6d", section_headers[i].sh_link);
			printf("%5d", section_headers[i].sh_info);
			printf("%5ld\n", section_headers[i].sh_addralign);
		}
	}

}

char* get_symtab_entry_name(FILE *fp, char *dest, const ElfN_Shdr *strtab_hdr, const ElfN_Sym *symtab){
	int idx = 0;
	char ch;
	fseek(fp, strtab_hdr->sh_offset + symtab->st_name, SEEK_SET);
	do
	{
		size_t _nread = fread(&ch, sizeof(char), 1, fp);
		(void)_nread;
		dest[idx++] = ch;
		if(idx >= 16){
			strcpy(dest+idx, "[...]");
			return dest;
		}
	} while (ch);
	dest[idx] = '\0';
	return dest;
}

inline const char* get_symtab_entry_type_name(unsigned char st_info){
	switch (ELFN_ST_TYPE(st_info)){
		case STT_NOTYPE: return "NOTYPE";
		case STT_OBJECT: return "OBJECT";
		case STT_FUNC: return "FUNC";
		case STT_SECTION: return "SECTION";
		case STT_FILE: return "FILE";
		case STT_LOPROC: return "LOPROC";
		case STT_HIPROC: return "HIPROC";
		default: return "";
	}
}

inline const char* get_symtab_entry_bind_name(unsigned char st_info){
	switch (ELFN_ST_BIND(st_info)){
		case STB_LOCAL: return "LOCAL";
		case STB_GLOBAL: return "GLOBAL";
		case STB_WEAK: return "WEAK";
		case STB_LOPROC: return "LOPROC";
		case STB_HIPROC: return "HIPROC";
		default: return "";
	}
}

inline const char* get_symtab_entry_vis_name(unsigned char st_other)
{
	switch (ELFN_ST_VISIBILITY(st_other))
	{
		case STV_DEFAULT: return "DEFAULT";
		case STV_INTERNAL: return "INTERNAL";
		case STV_HIDDEN: return "HIDDEN";
		case STV_PROTECTED: return "PROTECTED";
		default: return "";
	}
}

char * get_symtab_entry_ndx_name(char* buf, uint16_t st_shndx){
	switch (st_shndx)
	{
		case SHN_ABS: strcpy(buf, "ABS"); break;
		case SHN_UNDEF: strcpy(buf, "UND"); break;
		case SHN_COMMON: strcpy(buf, "COM"); break;
		default: sprintf(buf, "%d", st_shndx);
	}
	return buf;
}

void print_symtab(FILE* fp, const ElfN_Sym* symtab, const ElfN_Shdr* strtab_hdr, int symtab_size){
	char buf[100];
	printf("Symbol table \'.symtab\' contains %d entries:\n", symtab_size);
	printf("  Num:    Value          Size Type    Bind   Vis       Ndx    Name\n");
	for(int i = 0; i < symtab_size; i++){
		printf("%5d: ", i);  //num
		printf("%016lx ", symtab[i].st_value); //value

		printf("%5ld ", symtab[i].st_size);//size
		printf("%-7s ", get_symtab_entry_type_name(symtab[i].st_info));//type
		printf("%-6s ", get_symtab_entry_bind_name(symtab[i].st_info));
		printf("%-9s ", get_symtab_entry_vis_name(symtab[i].st_other));
		printf("%3s ", get_symtab_entry_ndx_name(buf,symtab[i].st_shndx));
		printf("%s\n", get_symtab_entry_name(fp, buf, strtab_hdr, &symtab[i]));//get_symtab_entry_name(fp, buf, strtab_hdr, &symtab[i]));
	}
}


ElfN_Ehdr* read_elf_header(FILE* fp, ElfN_Ehdr* dest) {
	fseek(fp, 0, SEEK_SET);
	size_t _nread = fread(dest, sizeof(ElfN_Ehdr), 1, fp);
	(void)_nread;
	return dest;
}

ElfN_Shdr* read_section_header(FILE* fp,  ElfN_Shdr* dest, const ElfN_Ehdr* elf_header, int index) {
	fseek(fp, elf_header->e_shoff + index * sizeof(ElfN_Shdr), SEEK_SET);
	size_t _nread = fread(dest, sizeof(ElfN_Shdr), 1, fp);
	(void)_nread;
	return dest;
}

ElfN_Sym* read_symtab(FILE* fp, ElfN_Sym* dest, const ElfN_Shdr* symtab_hdr) {
	fseek(fp, symtab_hdr->sh_offset ,SEEK_SET);
	size_t _nread = fread(dest, sizeof(ElfN_Sym), symtab_hdr->sh_size / symtab_hdr->sh_entsize, fp);
	(void)_nread;
	return dest;
}

