#pragma once

#include <stdint.h>
#include <functional>
#include <format>
#include <iostream>
#include <vector>
#include <memory>
#include <sstream>

#include "cmd.hpp"

namespace sdb {

	using word_t=uint32_t;
	using sword_t=int32_t;

	using paddr_t = uint32_t;

	using vlen_inst_code=std::vector<uint8_t>;
	using vlen_inst_view=std::span<const uint8_t>;

	using reg_snapshot_t=std::vector<word_t>;
	using reg_snapshot_view=std::span<const word_t>;
	
	// impl should return npc(pc after exec)
	using cpu_executor=std::function<paddr_t(size_t n)>;
	// impl should prepare n bytes continuously in mem corresponding to addr
	// and return the pointer to the first byte
	using mem_loader=std::function<uint8_t*(paddr_t addr,size_t n)>;
	// impl should fill reg_snapshot_t with current register values 
	using reg_snapshoter=std::function<void(reg_snapshot_t&)>;
	using inst_fetcher=std::function<vlen_inst_code(paddr_t pc)>;


	enum class run_state{
		running,
		stop,
		end,
		abort,
		quit
	};

	struct cpu_state{
		run_state state;
		paddr_t last_pc;
		paddr_t pc;
		uint32_t halt_ret;

		cpu_state():state(run_state::running),pc(0),halt_ret(0){}
		cpu_state(run_state s,paddr_t pc=0,uint32_t ret=0):
			state(s),pc(pc),halt_ret(ret){}

		inline bool is_badexit()const{
			bool good=
				(state==run_state::end&&halt_ret==0)
				||(state==run_state::quit);
			return !good;
		}

		void halt(uint32_t ret){
			state=run_state::end;
			halt_ret=ret;
		}
		void abort(){
			state=run_state::abort;
		}
		void stop(){
			state=run_state::stop;
		}
	};
	struct expr_t{
		using get_reg_by_name_f=std::function<std::optional<word_t>(std::string_view)>;
		std::string raw;
		expr_t(){}
		expr_t(std::string_view s):raw(s){}
		uint64_t eval(
				get_reg_by_name_f fr,
				mem_loader fm
				)const;
	};

	struct trace_context{
		paddr_t lastpc,pc;
		reg_snapshot_view regs;
		vlen_inst_view inst;
		std::span<std::string_view> reg_names;
		mem_loader loadmem;
		expr_t::get_reg_by_name_f get_reg;
		auto eval(const expr_t& e)const{
			return e.eval(get_reg, loadmem);
		}
	};

	using output_iterator=std::ostream_iterator<char>;

	namespace _impl{
		std::string_view error_head_str();
	}

	class trace_handler{
	private:
		std::ostringstream _logbuf;
		std::ostringstream _dmpbuf;

		std::string _pop_str(std::ostringstream& buf){
			auto s=buf.str();
			buf.str("");
			buf.clear();
			return s;
		}
	protected:


		bool _require_call_after_inst_exec=false;
		enum class _require_interrupt_type{
			none,
			stop,
			abort,
			halt,
		};
		_require_interrupt_type _req_int_t;
		word_t _req_halt_ret = 0;

		void _req_abort(){_req_int_t=_require_interrupt_type::abort;}
		void _req_stop(){_req_int_t=_require_interrupt_type::stop;}
		void _req_halt(word_t ret=0){_req_int_t=_require_interrupt_type::halt; _req_halt_ret=ret;}

		void _log(std::string_view fmt, auto&&... args){
			using namespace std;
			vformat_to(ostream_iterator<char>(_logbuf),
					fmt,make_format_args(args...));
		}
		void _dump(std::string_view fmt, auto&&... args){
			using namespace std;
			vformat_to(ostream_iterator<char>(_dmpbuf),
					fmt,make_format_args(args...));
		}
		void _error(std::string_view fmt, auto&&... args){
			_log(_impl::error_head_str());
			_log(fmt,std::forward<decltype(args)>(args)...);
			_log("\n");
		}
		using _ctx_ref = const trace_context&;

	public:
		std::string name;
		trace_handler(std::string n="unnamed"):name(n){}

		std::string get_log(){return _pop_str(_logbuf);}
		std::string get_dump(){
			make_dump();
			return _pop_str(_dmpbuf);
		}
		inline void reset_int(){
			_req_int_t=_require_interrupt_type::none;
		}
		inline bool require_call_after_inst_exec()const{
			return _require_call_after_inst_exec;
		}
		inline bool is_require_abort()const{
			return _req_int_t==_require_interrupt_type::abort;
		}
		inline bool is_require_stop()const{
			return _req_int_t==_require_interrupt_type::stop;
		}
		inline bool is_require_halt()const{
			return _req_int_t==_require_interrupt_type::halt;
		}
		inline word_t required_halt_ret()const{
			return _req_halt_ret;
		}

		virtual void init(_ctx_ref,std::span<uint8_t> init_mem,paddr_t mem_base){
			(void)init_mem; (void)mem_base;
		}

		virtual bool no_call_when_batch(size_t){return false;}
		virtual void make_dump(){}
		virtual void handle(_ctx_ref)=0;
	};
	using trace_handler_ptr=std::shared_ptr<trace_handler>;


class debuger{
	public:
		bool enable_inst_trace=false;
private:

	using fmt_str=std::string_view;

	cpu_executor _exec;
	cpu_state _state;

	mem_loader _loadmem;

	reg_snapshoter _shot_reg;
	std::vector<std::string_view> _reg_names;
	reg_snapshot_t _reg_snap;

	std::optional<word_t> _get_reg_from_name(std::string_view);

	vlen_inst_code _current_inst;
	inst_fetcher _fetch_inst;

	std::vector<trace_handler_ptr> _trace_handlers;

	const paddr_t _INITIAL_PC;
	const paddr_t _MEMARY_BASE;
	const size_t _IMG_SIZE;

	clscmd::command_table _cmd_table;

	std::ostream_iterator<char> _o_iter{std::cout};

	inline void _print(fmt_str fmt, auto&&... args){
		vformat_to(_o_iter,fmt,std::make_format_args(args...));
	}
	inline void _error(fmt_str fmt, auto&&... args){
		std::cerr
			<<_impl::error_head_str()
			<<vformat(fmt,std::make_format_args(args...))
			<<std::endl;
	}

	void _init_cmd_table();

	inline void _load_inst(){
		_current_inst=_fetch_inst(_state.pc);
	}

	void _step_one();
	void _step(size_t n);

	trace_context _make_trace_ctx();

	void cmd_p(expr_t);
	void cmd_q();
	void cmd_info(std::string_view);
	void cmd_x(size_t N,expr_t addr);
	void cmd_w(expr_t);

	inline void cmd_c(){cmd_si(-1);}
	void cmd_si(size_t n=1);
	void dump_mem(paddr_t addr,paddr_t end);
	void dump_reg();


public:

	debuger(
			paddr_t init_pc,paddr_t mem_base,paddr_t img_size,
			cpu_executor e,mem_loader ml,reg_snapshoter rss,auto&& regnames,
			inst_fetcher f=inst_fetcher()
	): _exec(e),_loadmem(ml),_shot_reg(rss),_reg_names(regnames),
	_fetch_inst(f),
	_INITIAL_PC(init_pc),_MEMARY_BASE(mem_base),_IMG_SIZE(img_size){
		_state.pc=init_pc;
		_reg_snap.resize(_reg_names.size());
		_init_cmd_table();
	}

	void add_trace(trace_handler_ptr th);

	inline const cpu_state& state()const{return _state;}
	inline cpu_state& state(){return _state;}

	inline bool is_running(){
		return _state.state==run_state::running;
	}	


	void dump_all();
	void abort();
	void stop();
	void exec_command(std::string_view cmdline);
};

}
