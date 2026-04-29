#include "sdb.hpp"
#include "sdbc.h"
#include <elf_tool.hpp>
#include <tracers.hpp>
#include <cassert>

using namespace std;

extern "C" sdb_debuger sdb_create_debuger(
		sdb_paddr_t init_pc,size_t img_size,
	 	sdb_cpu_executor exec, sdb_mem_loader loadmem, sdb_reg_snapshoter shotreg, const char **reg_names, size_t n_reg_names, sdb_inst_fetcher fetcher){
	auto dbg=new sdb::debuger(
		init_pc,init_pc,img_size,
		exec,
		loadmem,
		[shotreg](sdb::reg_snapshot_t& snap){
			shotreg(snap.data());
		},
		vector<string_view>(reg_names,reg_names+n_reg_names),
		fetcher?(sdb::inst_fetcher)[fetcher](sdb::paddr_t pc){
			auto cinst=fetcher(pc);
			assert(cinst.data != nullptr);
			return sdb::vlen_inst_code(cinst.data,cinst.data+cinst.len);
		}:(sdb::inst_fetcher)[loadmem](sdb::paddr_t pc){
			// default fetcher: fetch 4 bytes
			auto data=loadmem(pc,4);
			return sdb::vlen_inst_code(data,data+4);
		}
	);
	using namespace sdb;
	return (sdb_debuger)dbg;
}

void sdb_destroy_debuger(sdb_debuger dbg){
	delete (sdb::debuger*)dbg;
}

#define _DBG (assert(dbg!=NULL),(*((sdb::debuger*)dbg)))
using namespace sdb;

static bool enable_ftrace=false;

void sdb_enable_entrace(sdb_debuger dbg, int flags){
 	bool enable_difftest=(flags&SDB_ENTRACE_DIFFTEST);
 	_DBG.enable_inst_trace=(flags&SDB_ENTRACE_INST);
 	enable_ftrace=(flags&SDB_ENTRACE_FUNC);
 	if(enable_ftrace)assert(_DBG.enable_inst_trace);
 	if(enable_difftest)assert(_DBG.enable_inst_trace);

 	if(_DBG.enable_inst_trace)
	{
 	 	_DBG.add_trace(make_disasm_trace_handler());
		_DBG.add_trace(make_iringbuf_trace_handler());
		_DBG.add_trace(make_etrace_handler());
	}
}

bool sdb_try_findload_elf_fromimg(sdb_debuger dbg, const char* img_file){
	string imgf=try_find_elf_file_of(img_file);
	if(imgf.empty())return false;
	sdb_load_elf(dbg,imgf.c_str());
	return true;
}
void sdb_load_elf(sdb_debuger dbg, const char* filename){
	if(!enable_ftrace)return;
	_DBG.add_trace(
		sdb::make_ftrace_handler(filename)
	);
}

static sdb::difftest_trace_handler_ptr difftest_handler=nullptr;

void sdb_load_difftest_ref(sdb_debuger dbg, const char* so_file, int port){
	assert(difftest_handler==nullptr);
	difftest_handler=sdb::make_difftest_trace_handler(so_file,port);
	_DBG.add_trace(difftest_handler);
}
void sdb_exec(sdb_debuger dbg, const char* cmdline){
	_DBG.exec_command(cmdline);
}
void sdb_skip_difftest_ref(sdb_debuger){
	assert(difftest_handler!=nullptr);
	difftest_handler->skip_ref();
}

void sdb_abort(sdb_debuger dbg){
	_DBG.abort();
}

void sdb_set_state(sdb_debuger dbg, sdbc_cpu_state state){
	sdb::cpu_state s;
	s.state=(sdb::run_state)state.state;
	s.pc=state.pc;
	s.halt_ret=state.halt_ret;
	_DBG.state()=s;
}
sdbc_cpu_state sdb_get_state(sdb_debuger dbg){
	sdbc_cpu_state state;
	auto s=_DBG.state();
	state.state=(sdb_run_state)s.state;
	state.pc=s.pc;
	state.halt_ret=s.halt_ret;
	return state;
}
