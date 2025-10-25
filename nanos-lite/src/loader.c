#include <proc.h>
#include <elf.h>

#ifdef __LP64__
#define Elf_Ehdr Elf64_Ehdr
#define Elf_Phdr Elf64_Phdr
#else
#define Elf_Ehdr Elf32_Ehdr
#define Elf_Phdr Elf32_Phdr
#endif
#define EXPECTED_TYPE EM_RISCV
enum
{
	SEEK_SET = 0,
	SEEK_CUR = 1,
	SEEK_END = 2
};
static char program_buf[0x80000];
extern int fs_open(const char *pathname, int flags, int mode);
extern void *new_page(size_t nr_page);
extern size_t fs_read(int fd, void *buf, size_t len);
extern int fs_close(int fd);
extern size_t fs_lseek(int fd, size_t offset, int whence);
static uintptr_t loader(PCB *pcb, const char *filename)
{
	Log("Loading program '%s'...", filename);
	int fd = fs_open(filename, 0, 0);
	size_t file_size = fs_lseek(fd, 0, SEEK_END);			  // Get file size
	assert(file_size > 0 && file_size < sizeof(program_buf)); // Ensure file size is valid
	fs_lseek(fd, 0, SEEK_SET);								  // Reset file cursor to the beginning
	fs_read(fd, program_buf, file_size);					  // Read the program into buffer
	fs_close(fd);
	Elf_Ehdr *ehdr = (Elf_Ehdr *)program_buf;
	assert(ehdr->e_ident[0] == ELFMAG0 &&
		   ehdr->e_ident[1] == ELFMAG1 &&
		   ehdr->e_ident[2] == ELFMAG2 &&
		   ehdr->e_ident[3] == ELFMAG3);		// Check ELF magic number
	assert(ehdr->e_machine == EXPECTED_TYPE);	// Check machine type
	uint32_t program_off = ehdr->e_phoff;		// Program header offset
	uint32_t program_num = ehdr->e_phnum;		// Number of program headers
	assert(program_off > 0 && program_num > 0); // Ensure valid program header
	uint32_t max_brk = 0;
	for (uint32_t i = 0; i < program_num; i++)
	{
		Elf_Phdr *phdr = (Elf_Phdr *)(program_buf + program_off + i * sizeof(Elf_Phdr));
		if (phdr->p_type == PT_LOAD) // Loadable segment
		{
			uintptr_t vaddr = phdr->p_vaddr;
			uintptr_t paddr = vaddr;
			uint32_t memsz = phdr->p_memsz;
			uint32_t filesz = phdr->p_filesz; // File size
			assert(memsz >= filesz);		  // Ensure memory size is at least file size
			// memcpy((void *)paddr, program_buf + phdr->p_offset, filesz); // Load segment into memory
			// memset((void *)(paddr + filesz), 0, memsz - filesz);		 // Zero out the rest of the segment
			uint32_t offset = phdr->p_offset; // Offset in the file

			if (max_brk < vaddr + memsz)
				max_brk = vaddr + memsz; // Update max_brk if this segment extends beyond current max_br

			size_t aligned_addr = paddr & ~(PGSIZE - 1);
			size_t zero_bytes = paddr - aligned_addr;
			size_t avail_bytes = PGSIZE - zero_bytes;
			// printf("aligned_addr = %p, avail_bytes = %u\n", (void *)aligned_addr, avail_bytes);
			// printf("seg %d start to load, paddr = %p, vaddr = %p, memsz = %x, filesz = %x, offset = %u\n",
			// 	   i, (void *)paddr, (void *)vaddr, memsz, filesz, offset);
			for (uintptr_t addr = aligned_addr; addr < paddr + memsz; addr += PGSIZE)
			{
				void *page = new_page(1);
				map(&pcb->as, (void *)(addr), page, 0); // Map the page into the address space

				if (zero_bytes)
				{
					if (filesz < avail_bytes)
						avail_bytes = filesz;
					// printf("memcpy 0 from %p to %p, size = %u\n", page + zero_bytes, page + zero_bytes + avail_bytes, avail_bytes);
					memcpy(page + zero_bytes, program_buf + offset, avail_bytes); // Copy data from the file to the page
					offset += avail_bytes;										  // Update offset
					filesz -= avail_bytes;										  // Decrease file size by the number of bytes
					zero_bytes = 0;												  // Reset zero_bytes after the first page
					continue;
				}

				if (filesz >= PGSIZE)
				{
					// printf("memcpy from 1 %p to %p, size = %u\n", page, page + PGSIZE, PGSIZE);
					memcpy(page, program_buf + offset, PGSIZE); // Load page into memory
					filesz -= PGSIZE;
					offset += PGSIZE;
				}
				else if (filesz > 0)
				{
					// printf("memcpy from 2 %p to %p, size = %u\n", page, page + filesz, filesz);
					memcpy(page, program_buf + offset, filesz); // Load remaining data into the page
					offset += filesz;							// Update offse
					filesz = 0;
				}
			}
		}
	}
	pcb->max_brk = ROUNDUP(max_brk, PGSIZE); // Set the maximum break value for the address space
	return ehdr->e_entry;					 // Return the entry point address
}
void hello_only()
{
	printf("Hello, world!\n");
}
void naive_uload(PCB *pcb, const char *filename)
{
	uintptr_t entry = loader(pcb, filename);
	Log("Jump to entry = %p", entry);
	((void (*)())entry)();
}
void context_uload(PCB *pcb, char *filename, const char *argv[], const char *envp[])
{
	protect(&pcb->as); // Protect the address space before loading
	int argc = 0;
	while (argv[argc] != NULL)
		argc++;
	int envc = 0;
	while (envp[envc] != NULL)
		envc++;
	int str_size = 0;
	for (int i = 0; i < argc; i++)
	{
		str_size += strlen(argv[i]) + 1; // +1 for null terminator
	}

	for (int i = 0; i < envc; i++)
	{
		str_size += strlen(envp[i]) + 1; // +1 for null termin
	}

	char *argc_pos = (char *)(new_page(8));				   // Allocate a new page for arguments
	uint32_t v_stack_bottom = (uintptr_t)pcb->as.area.end; // Get the end of the user stack area
	uint32_t v_stack_top = v_stack_bottom - 8 * PGSIZE;	   // Set the stack top to 8 pages below the end
	uint32_t p_stack_top = (uint32_t)argc_pos;
	uint32_t p_stack_bottom = p_stack_top + 8 * PGSIZE;			   // Set the stack bottom to 8 pages below the top
	uint32_t offset_from_v_to_p = p_stack_bottom - v_stack_bottom; // Calculate the offset from virtual to physical address

	// build mapping relationship
	assert(v_stack_bottom % PGSIZE == 0); // Ensure the stack end is page-aligned

	for (int i = 0; i < 8; i++)
	{
		map(&pcb->as, (void *)(v_stack_top + i * PGSIZE), (void *)(p_stack_top + i * PGSIZE), 0);
	}
	argc_pos += 8 * PGSIZE;
	argc_pos -= (sizeof(int) + (argc + 2 + envc) * sizeof(char *));
	argc_pos -= str_size;				  // Adjust for the size of strings
	uintptr_t gprx = (uintptr_t)argc_pos; // Set the stack pointer to the start of the arguments
	*(int *)argc_pos = argc;			  // Store argc at the start of the arguments area
	char *strpos = argc_pos + sizeof(int) + (argc + 2 + envc) * sizeof(char *);
	argc_pos += sizeof(int);
	for (int i = 0; i < argc; i++)
	{
		*(char **)(argc_pos + i * sizeof(char *)) = strpos; // Store argument pointers
		strcpy(strpos, argv[i]);							// Copy argument strings
		strpos += strlen(argv[i]) + 1;						// Move to the next string position
	}
	*(char **)(argc_pos + argc * sizeof(char *)) = NULL; // Null-terminate the argument list
	for (int i = 0; i < envc; i++)
	{
		*(char **)(argc_pos + (argc + 1 + i) * sizeof(char *)) = strpos; // Store environment pointers
		strcpy(strpos, envp[i]);										 // Copy environment strings
		strpos += strlen(envp[i]) + 1;									 // Move to the next string position
	}
	*(char **)(argc_pos + (argc + 1 + envc) * sizeof(char *)) = NULL; // Null-terminate the environment list

	uintptr_t entry = loader(pcb, filename);
	printf("Loading program '%s' with entry point %p\n", filename, (void *)entry);
	Context *ctx = ucontext(&pcb->as, (Area){pcb->stack, pcb->stack + sizeof(pcb->stack)}, ((void (*)())entry));
	ctx->GPRx = gprx - offset_from_v_to_p; // Set the stack pointer in the context
	printf("User sp is set to %p (physical), %p (virtual)\n",
		   (void *)gprx, (void *)(gprx - offset_from_v_to_p));
	pcb->cp = ctx;
	printf("User context created at position %p with entry point %p\n", ctx, (void *)entry);
}
void context_kload(PCB *pcb, void *entry_func, void *arg)
{
	Context *ctx = kcontext((Area){pcb->stack, pcb->stack + sizeof(pcb->stack)}, entry_func, arg);
	printf("Kernel context created at position %p with entry point %p\n", ctx, entry_func);
	pcb->cp = ctx;
}