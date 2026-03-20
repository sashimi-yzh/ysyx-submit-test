#include "elf_tool.hpp"

#include <cstring>
#include <format>
#include <stdexcept>
#include <ranges>
#include <functional>
#include <source_location>

using namespace std;
using namespace std::views;

string try_find_elf_file_of(string img_file){
	size_t pos=img_file.rfind('.');
	if(pos==string::npos)return "";
	string base=img_file.substr(0,pos);
	string elf_file=base+".elf";
	FILE* fp=fopen(elf_file.c_str(),"rb");
	if(fp){
		fclose(fp);
		return elf_file;
	}
	return "";
}

void _check(bool cond, const string& msg,
		const source_location& loc = source_location::current()) {
	if (!cond) {
		throw runtime_error(format("{}:{}: ElfHandler: {}", loc.file_name(), loc.line(), msg));
	}
}
static void _ensure_fread(fstream& _fs,void* ptr, size_t siz) {
	_check((size_t)_fs.read((char*)ptr, siz).gcount() == siz,
			format("read failed, expected {} bytes", siz));
}

static string _load_strbuf(fstream& _fs,const Elf32_Shdr& shdr) {
	_check(shdr.sh_type == SHT_STRTAB, "try read strtable on wrong header type");
	_fs.seekg(shdr.sh_offset, ios::beg);
	string buf(shdr.sh_size, '\0');
	_ensure_fread(_fs,buf.data(), shdr.sh_size);
	return buf;
}

void elf_handler::load(fstream& fs) {
	auto _frd = bind_front(_ensure_fread, ref(fs));

	// Read ELF header
	char e_ident[EI_NIDENT];
	_frd(e_ident, EI_NIDENT);

	_check(e_ident[EI_CLASS] == ELFCLASS32,"only support 32-bit ELF files"); 
	_check(memcmp(e_ident, ELFMAG, SELFMAG) == 0,"not a valid ELF file");

	Elf32_Ehdr hdr;
	fs.seekg(0, ios::beg);
	_frd(&hdr, sizeof(hdr));

	// Read section headers
	_check(hdr.e_shstrndx < hdr.e_shnum,"invalid section header string table index");

	vector<Elf32_Shdr> shdrs(hdr.e_shnum);
	fs.seekg(hdr.e_shoff, ios::beg);
	_frd(shdrs.data(), hdr.e_shnum * sizeof(Elf32_Shdr));

	// Find symbol table section
	auto it = ranges::find(shdrs, SHT_SYMTAB, &Elf32_Shdr::sh_type);
	_check(it != shdrs.end(),"symbol table section not found");
	const auto& sh_symtab = *it;

	// Read symbol table entries
	_check(sh_symtab.sh_entsize == sizeof(Elf32_Sym),
			"symbol table entry size mismatch");
	_check(sh_symtab.sh_size%sh_symtab.sh_entsize==0, 
			"symbol table size not multiple of entry size");

	size_t n_symbols = sh_symtab.sh_size / sh_symtab.sh_entsize;
	vector<Elf32_Sym> syms(n_symbols);

	fs.seekg(sh_symtab.sh_offset, ios::beg);
	_frd(syms.data(), sh_symtab.sh_size);

	// Read symbol string table
	_check(sh_symtab.sh_link<hdr.e_shnum, "invalid symbol string table index");
	const auto& sh_symstrtab = shdrs[sh_symtab.sh_link];
	_symstr_buf = _load_strbuf(fs,sh_symstrtab);

	// Extract function symbols
	for(auto& s: syms) {
		if(ELF32_ST_TYPE(s.st_info) != STT_FUNC) continue;
		_funcs.emplace_back(s.st_value, s.st_size,&_symstr_buf[s.st_name]);
	}

}

optional<elf_handler::func> elf_handler::get_fun_at(uint32_t addr) const {
	for (auto& f : _funcs) {
		if (addr >= f.addr && addr < f.addr + f.size)return f;
	}
	return nullopt;
}

void elf_handler::dump_func_syms() const {
	for (auto& f : _funcs) {
		printf("FUNC: %08X %5d %s\n", f.addr, f.size, f.name.data());
	}
}
