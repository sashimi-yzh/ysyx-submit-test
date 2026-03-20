#pragma once
#include <fstream>
#include <elf.h>
#include <vector>
#include <string>
#include <optional>

class elf_handler {
public:
	struct func {
		uint32_t addr;
		uint32_t size;
		std::string_view name;
	};
private:
	std::vector<func> _funcs;
	std::string _symstr_buf;

public:

	void load(std::fstream& fs);
	void dump_func_syms()const;
	
	std::optional<func> get_fun_at(uint32_t inst_addr)const;
};
std::string try_find_elf_file_of(std::string img_file);
