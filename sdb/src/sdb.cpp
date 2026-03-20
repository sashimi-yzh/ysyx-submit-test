#include "sdb.hpp"
#include <assert.h>
#include <ranges>
#include <algorithm>
#include <tracers.hpp>

#include "ansi_col.h"

using namespace std;
using namespace sdb;
using namespace std::views;
using namespace clscmd;

template <typename T>
struct std::formatter<optional<T>> : formatter<T> {
    auto format(const optional<T>& opt, auto& ctx) const {
        if (opt)
            return formatter<T>::format(*opt, ctx);
        else
            return format_to(ctx.out(), "(nullopt)");
    }
};

template<>
struct std::formatter<errc> : formatter<string> {
    auto format(errc ec, auto& ctx) const {
        return formatter<string>::format(
            make_error_code(ec).message(), ctx);
    }
};

string_view sdb::_impl::error_head_str(){
	return ANSI_FG_RED "[ERROR] " ANSI_NONE;
}

trace_context debuger::_make_trace_ctx(){
	_load_inst();
	return trace_context{
		_state.last_pc,
		_state.pc,
		_reg_snap,
		_current_inst,
		_reg_names,
		_loadmem,
		bind_front(&debuger::_get_reg_from_name,this),
	};
}

void debuger::add_trace(trace_handler_ptr h){
	_trace_handlers.push_back(h);
	auto mem=_loadmem(_MEMARY_BASE,_IMG_SIZE);

	h->init(_make_trace_ctx(),
		 	std::span<uint8_t>(mem,mem+_IMG_SIZE),
		 	_MEMARY_BASE);
	_print("{}",h->get_log());
}
void debuger::_step(size_t n){
	if(!enable_inst_trace){
		_exec(n);
		return;
	}
	vector<trace_handler_ptr> before_exec,after_exec;
	ranges::partition_copy(
	_trace_handlers|filter([n](auto h){
			return !h->no_call_when_batch(n);
			}),
		back_inserter(after_exec),
		back_inserter(before_exec),
		&trace_handler::require_call_after_inst_exec
	);
	auto invoke=[this](auto h){
		h->handle(_make_trace_ctx());
		_print("{}",h->get_log());
		if(h->is_require_abort()){
			_print("{} require abort\n", h->name);
			abort();
		}
		if(h->is_require_stop()){
			_print("{} require stop\n", h->name);
			stop();
		}
		if(h->is_require_halt()){
			_print("{} require halt\n", h->name);
			_state.halt(h->required_halt_ret());
		}
	};

	for(size_t i=0;i<n&&is_running();i++){
		//_print("step {} before exec\n", i);
		ranges::for_each(before_exec,invoke);
		if(!is_running())break; // NOTICE!!!!
														// must check before inst exec
														// exec impl always try sync 
														// state to sdb, so will modify
														// sdb state !!!!
														//
														// TODO: refactor to restrict 
														// other part modify self state
														//
		_step_one();
		//_print("step {} after exec\n", i);
		ranges::for_each(after_exec,invoke);
		if(!is_running())break;
	}
}

void debuger::dump_all(){
	for(auto h:_trace_handlers){
		_print("{}",h->get_dump());
	}
	dump_reg();
}

void debuger::stop(){
	_state.stop();
	assert(!is_running());
	_print("Program stopped.\n");
	dump_all();
}

void debuger::abort(){
	_state.abort();
	_print("Program aborted.\n");
	dump_all();
}

void debuger::_step_one(){
	_state.last_pc= _state.pc;
	_state.pc = _exec(1);
	_shot_reg(_reg_snap);
}

void debuger::cmd_si(size_t n){
	if(_state.state==run_state::end||_state.state==run_state::quit){
		_error("Program has ended. Cannot execuate.");
		return;
	}
	ranges::for_each(_trace_handlers,&trace_handler::reset_int);
	_state.state=run_state::running;
	_step(n);
}


void debuger::cmd_q(){
	if(_state.is_badexit()){
		// cur pc has not executed yet
		_error("Program exited with bad state. nxt pc = 0x{:08x}", _state.pc);
	}
	_state.state=run_state::quit;
}

void debuger::dump_mem(paddr_t addr,paddr_t end){
	assert((end-addr)%4==0);
	while (addr!=end) {
		_print(ANSI_FG_GRAY"0x{:08x}: " ANSI_NONE,addr);	
		auto p=_loadmem(addr,4);
		for(int i=0;i<4;i++)_print("{:02x} ", p[i]);
		_print("\n");
		addr+=4;
	}
}
void debuger::dump_reg(){
	_print(ANSI_FG_YELLOW "==== register ====\n" ANSI_NONE);
	for(size_t i=0;i<_reg_names.size();i++){
		auto r=_reg_names[i];
		auto v=_reg_snap[i];
		_print(ANSI_FG_BLUE"{:>3}" ANSI_NONE ": 0x{:08x} ", r, v);
		if((i+1)%4==0){
			/*_print("\n" ANSI_FG_GRAY);
			for(size_t j=i-3;j<=i;j++){
				auto rv=_reg_snap[j];
				_print("{:3} {:11} ",' ',rv);
			}*/
			_print("\n");
		}
	}
}

void debuger::cmd_info(string_view s){
	if(s=="r"){
		_shot_reg(_reg_snap);
		dump_reg();
	}
	else return _error("Unknown info command {}", s);	
}

optional<word_t> debuger::_get_reg_from_name(string_view name){
	if(name=="pc"){
		return _state.pc;
	}
	auto it=ranges::find(_reg_names,name);
	if(it==_reg_names.end())return nullopt;
	auto idx=it-_reg_names.begin();
	return _reg_snap[idx];
}
void debuger::cmd_p(expr_t e){
	_print("{}\n", e.eval(
			bind_front(&debuger::_get_reg_from_name,this),
			_loadmem
			));
}
void debuger::cmd_x(size_t N,expr_t e_addr){
	paddr_t addr=e_addr.eval(
		bind_front(&debuger::_get_reg_from_name,this),
			_loadmem
			);
	dump_mem(addr, addr+N*4);
}
void debuger::cmd_w(expr_t e){
	add_trace(make_shared<watchpoint_tracer>(e));
}

void debuger::_init_cmd_table(){
#define _ITEM(name,desc,...) {name,command_t(desc,this,&debuger::__VA_ARGS__)}
	_cmd_table={
		_ITEM("c", "Continue the execution of the program", cmd_c),
		_ITEM("q", "Exit program",cmd_q),
		_ITEM("si","Step the program for N instructions",cmd_si,1),
		_ITEM("info", "Display information about registers or watchpoints",cmd_info),
		_ITEM("x", "Examine memory: x N EXPR",cmd_x),
		_ITEM("p", "print EXPR",cmd_p),
		_ITEM("w","watch point: w EXPR",cmd_w),
		};
}

void debuger::exec_command(string_view cmdline){
	auto ec=exec(_cmd_table,cmdline);
	if(ec!=invoke_success){
		_error("{}", ec);
	}
}
