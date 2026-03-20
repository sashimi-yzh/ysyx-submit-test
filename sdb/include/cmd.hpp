#pragma once
#include <functional>
#include <string_view>
#include <ranges>
#include <vector>
#include <charconv>
#include <tuple>
#include <concepts>
#include <system_error>

namespace clscmd {
	using std::string_view;
	using std::string;
	using std::function;

	using toks_t = std::vector<string_view>;
	using invoke_error = std::errc;

	constexpr invoke_error invoke_success=invoke_error();

	namespace _impl {
		template <typename T>
		concept CanFromChars = std::integral<T> || std::floating_point<T>;
		template <typename T>
		concept CanFromStrView = requires(std::string_view sv) {T{sv};};
	}

	auto parse(string_view s,_impl::CanFromChars auto& v,int base=10){
		return std::from_chars(s.begin(),s.end(),v,base).ec;
	}
	inline auto parse(string_view s,_impl::CanFromStrView auto& v){
		v=s;
		return std::errc();
	}

	inline auto make_toksview(string_view str){
		using namespace std::views;
		return str | split(' ')
			| transform([](auto&& rng) {
					return string_view(rng.begin(), rng.size());
			});
	}

	struct command_t{
		string_view description;
		function<invoke_error(toks_t)> invoke;

		command_t(){}
		
		template <typename Class, typename Ret, typename... Args,typename... Defaults>
		command_t(
			string_view desc,
			Class* obj, Ret(Class::*func)(Args...),
			Defaults&&... defaults
		):description(desc){
			using namespace std;
			// TODO: use C++23 bind_back
			auto def_args=make_tuple(forward<Defaults>(defaults)...);
			invoke=[obj, func, def_args](toks_t toks) {
				tuple<decay_t<Args>...> args;
				constexpr size_t N_args = sizeof...(Args);
				constexpr size_t N_def  = sizeof...(Defaults);
				constexpr size_t I_required_end = N_args - N_def;

				const size_t n_tok = toks.size();

				if(n_tok > N_args) return errc::argument_list_too_long;
				if(n_tok+N_def<N_args) return errc::invalid_argument;

				bool ok=true;
				errc ec;

				[&]<size_t... Is>(index_sequence<Is...>) { (([&]{
					if (Is < n_tok) {
						if(!ok)return;
						ec = parse(toks[Is], get<Is>(args));
						ok=(ec==errc());
						if(!ok)printf("parse failed arg#%zu(%s) as typeid`%s\n",
								Is, toks[Is].data(), typeid(decltype(get<Is>(args))).name()
								);
					}
					else{
						if constexpr (Is >= I_required_end) {
							get<Is>(args) = get<Is-I_required_end>(def_args);
						} else { // should return early when check n_tok+n_def
							throw std::logic_error("unreachable");
						}
					}
				}()),...); }(index_sequence_for<Args...>{});

				if(!ok)return invoke_error(ec);

				apply(bind_front(func, obj), args);
				return invoke_success;
			};
		}

	};

	using command_table=std::unordered_map<string_view, command_t>;

	inline invoke_error exec(const command_table& table,string_view cmdline){
		auto toks=make_toksview(cmdline);
		if(toks.empty())return invoke_success;
		auto it=table.find(toks.front());
		if(it==table.end())return std::errc::no_such_process;
		auto cmd=it->second;
		auto args=toks|std::views::drop(1);
		return cmd.invoke(toks_t(args.begin(),args.end()));
	}

}
