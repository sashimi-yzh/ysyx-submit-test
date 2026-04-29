#include "sprobe.hpp"

#define _STR2(x) #x
#define _STR(x) _STR2(x)

void SProbe::dump_watched() {
	static const std::string TOP_DOT = std::string(_STR(TOP_NAME)).substr(1) + ".";

    if (_watched.empty())
      return;

    bool is_first = true;

    std::cout << ANSIFMT_COMMENT << "-- poke beg\n" << ANSIFMT_NONE;

    std::string last_name = "";
    std::string showed_type;

    auto val_upd_hint = ANSIFMT_HINT "*" ANSIFMT_NONE;

    for (auto &h : _watched) {
      const auto &fullname = h.fullname;
      const auto &selfname = h.name;
      const auto &type = h.type;
      const auto &sig_width = h.width;

      if (type.starts_with("vpi")) {
        showed_type = type[3];
      } else {
        showed_type = type;
      }

      // Remove the "TOP."
      auto cur_name = fullname.substr(4);
      if (cur_name.starts_with(TOP_DOT)) {
        cur_name = cur_name.substr(TOP_DOT.size());
      }

      auto sig_value = h.getValue();
      bool value_changed = (sig_value != h.last_value);

      auto common_prefix = _max_common_prefix(last_name, cur_name);

			// prefix should end with '.' or '_' (module/level separator)
			while(common_prefix.size()>0&&
				(common_prefix.back()!='.'&&common_prefix.back()!='_')){
				common_prefix=common_prefix.substr(0,common_prefix.size()-1);
			}
			// remove last '.' or '_', which should show in the unique part
      if (!common_prefix.empty()){
        common_prefix = common_prefix.substr(0, common_prefix.size() - 1);
      }

      auto unique_part = cur_name.substr(common_prefix.size());

      std::string showed_name = std::format(
          ANSIFMT_SIGNAL_REPEATED_PARENT "{}{}{}" ANSIFMT_NONE, common_prefix,
          value_changed ? ANSIFMT_HINT ANSIFMT_BOLD : ANSIFMT_SIGNAL_NAME,
          unique_part);

      auto val_out_width = (sig_width + 3) / 4; // (8bits per 2hex) upceil

      if (!is_first) {
        std::cout << std::endl;
      } else {
        is_first = false;
      }

      std::cout << std::format(
          ANSIFMT_GRAY "si{} " ANSIFMT_SIGNAL_TYPE "{} " ANSIFMT_NUM "{:2} "
                       "{}" ANSIFMT_NONE " = " ANSIFMT_NUM_PREFIX
                       "h'{}" ANSIFMT_NUM "{:0{}x}" ANSIFMT_NONE,
          value_changed ? val_upd_hint : "g", showed_type, sig_width,
          showed_name, value_changed ? ANSIFMT_BOLD : ANSIFMT_NONE,
          (uint32_t)sig_value, val_out_width);

      h.updateLastValue();
      last_name = cur_name;
    }
    std::cout << ANSIFMT_COMMENT " -- end" ANSIFMT_NONE << std::endl;
  }

