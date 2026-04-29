#include <cstdint>
#include <tracers.hpp>
#include <ansi_col.h>
#include <deque>
#include <ranges>

using namespace sdb;
using namespace std;

struct _irb_inst_ctx{
	paddr_t pc;
	vlen_inst_code inst;
	reg_snapshot_t regs;
	std::span<std::string_view> reg_names;
	_irb_inst_ctx()=default;
	_irb_inst_ctx(const trace_context& ctx):pc(ctx.pc){
		inst=vector<uint8_t>(ctx.inst.begin(),ctx.inst.end());
		regs=reg_snapshot_t(ctx.regs.begin(),ctx.regs.end());
		reg_names=ctx.reg_names;
	}
	operator trace_context()const{
		return trace_context{
			.lastpc=0, // not used
			.pc=pc,
			.regs=reg_snapshot_view(regs),
			.inst=vlen_inst_view(inst),
			.reg_names=reg_names,
			.loadmem=nullptr,
			.get_reg=nullptr,
		};
	}
};

class sdb::iringbuf_trace_handler : public disasm_trace_handler {
	size_t n_records;
	deque<_irb_inst_ctx> buf;

	public:
		iringbuf_trace_handler(inst_disasmsembler d,size_t n):
			disasm_trace_handler(d),n_records(n){}

		virtual void handle(const trace_context& ctx)override{
			buf.emplace_back(ctx);
			while(buf.size()>n_records)buf.pop_front();
		}

		virtual bool no_call_when_batch(size_t)override{
			return false;
		}


		void _dump_using_reg(_irb_inst_ctx& ctx){
			auto dump_one_reg=[&](uint8_t r){
				if(r==0)return;
				_dump(ANSI_FG_BLUE " {}" ANSI_NONE ": {:08x}",ctx.reg_names[r],ctx.regs[r]);
			};
			uint32_t code=*(uint32_t*)ctx.inst.data();
			uint8_t rd=(code>>7)&0x1f;
			uint8_t rs1=(code>>15)&0x1f;
			uint8_t rs2=(code>>20)&0x1f;
			dump_one_reg(rd);
			dump_one_reg(rs1);
			dump_one_reg(rs2);
		}

		virtual void make_dump()override{
			_dump(ANSI_FG_YELLOW "==== recent instructions ====\n" ANSI_NONE);
			auto last=prev(end(buf));
			for(auto it=buf.begin();it!=buf.end();++it){
				_dump("[{}{:02}" ANSI_NONE "] ",
					it==last?ANSI_FG_RED:ANSI_FG_CYAN,
					distance(it,end(buf))-1
				);
				_dump(_dump_inst(*it,it==last));
				_dump_using_reg(*it);
				_dump("\n");
			}
		}



};

trace_handler_ptr sdb::make_iringbuf_trace_handler(
	inst_disasmsembler disasm,size_t n_records
){
	return make_shared<iringbuf_trace_handler>(disasm,n_records);
}
