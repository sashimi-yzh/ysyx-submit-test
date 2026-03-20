#pragma once
#include "vpi_user.h"
#include <algorithm>
#include <cstdint>
#include <format>
#include <iostream>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>
#include <verilated.h>
#include <verilated_vpi.h>

#define ANSIFMT_NONE "\e[0m"
#define ANSIFMT_GRAY "\e[38;2;90;90;90m"
#define ANSIFMT_SIGNAL_REPEATED_PARENT "\e[38;2;84;118;138m"
#define ANSIFMT_SIGNAL_NAME "\e[38;2;156;220;254m"
#define ANSIFMT_NUM "\e[38;2;181;206;168m"
#define ANSIFMT_NUM_PREFIX "\e[38;2;113;129;105m"
#define ANSIFMT_COMMENT "\e[38;2;106;153;85m"
#define ANSIFMT_HINT "\e[38;2;156;179;255m"
#define ANSIFMT_SIGNAL_TYPE "\e[38;2;78;201;176m"
#define ANSIFMT_BOLD "\e[1m"

#if ENABLE_VPI==0
#define vpi_get_str(...) ""
#define vpi_get(...) 0
#define vpi_release_handle(...)
#define vpi_handle_by_name(...) NULL
#define vpi_scan(...) NULL
#define vpi_iterate(...) NULL
#define vpi_get_value(...) 
#endif

class SProbe {
  static std::string_view _max_common_prefix(std::string_view a,
                                             std::string_view b) {
    auto [it1, it2] = std::ranges::mismatch(a, b);
    return std::string_view(a.begin(), it1);
  }
  std::vector<std::string> _ignored_names = {
      "clock",
      "reset",
      "_RANDOM",
  };
  bool _in_ignore_list(std::string_view name) {
    if (name.starts_with("_GEN"))
      return true;
    for (auto &ign : _ignored_names) {
      if (ign == name)
        return true;
    }
    return false;
  }

public:
  struct WatchItem {
    std::string fullname;
    std::string type;
    std::string name;
    size_t width;

    vpiHandle handle;
    uint64_t last_value;
    auto getValue() {
      s_vpi_value v;
      v.format = vpiVectorVal;
      vpi_get_value(handle, &v);
      uint64_t res = v.value.vector[1].aval;
      res <<= 32;
      res |= v.value.vector[0].aval;
      return res;
    }
    void updateLastValue() { last_value = getValue(); }
    WatchItem(vpiHandle h) {
      handle = h;
      last_value = getValue();
      fullname = vpi_get_str(vpiFullName, handle);
      name = vpi_get_str(vpiName, handle);
      type = vpi_get_str(vpiType, handle);
      width = vpi_get(vpiSize, handle);
    }
  };
  std::vector<WatchItem> _watched;

  ~SProbe() {
    for (auto &w : _watched) {
      vpi_release_handle(w.handle);
    }
  }

  void watch_inside(vpiHandle top, int max_depth = 1, int cur_depth = 0) {
    if (cur_depth >= max_depth)
      return;

    vpiHandle iter;
    vpiHandle it;
    int type_begin = 0, type_end = 136;
    for (int type = type_begin; type < type_end; type++) {
      iter = vpi_iterate(type, top);
      if (iter != NULL) {
        // printf("SProbe scanning type %d\n",type);
        while ((it = vpi_scan(iter)) != NULL) {
          // printf("SProbe found %d  %s\n", type, vpi_get_str(vpiFullName,
          // it));

          if (vpi_get(vpiType,it) == vpiModule) {
            watch_inside(it, max_depth, cur_depth + 1);
            vpi_release_handle(it);
          } else {
            if (_in_ignore_list(vpi_get_str(vpiName, it))) {
              std::cout << "ignore " << vpi_get_str(vpiType, it) << " "
                        << vpi_get_str(vpiFullName, it) << std::endl;
              vpi_release_handle(it);
              continue;
            }
            std::cout << "add watch " << vpi_get_str(vpiType, it) << " "
                      << vpi_get_str(vpiFullName, it) << std::endl;
            _watched.emplace_back(it);
          }
          // printf("SProbe back to %s\n",vpi_get_str(vpiFullName,top));
        }
      }
    }
  }
  void watch_inside(std::string_view top) {
    watch_inside(vpi_handle_by_name((PLI_BYTE8 *)top.data(), NULL));
  }

  bool add_watch(std::string_view sig_name) {
    vpiHandle vh1 = vpi_handle_by_name((PLI_BYTE8 *)(sig_name.data()), NULL);
    if (!vh1) {
      std::cout << "SProbe add_watch no handle found for " << sig_name
                << std::endl;
      return false;
    }
    auto type = vpi_get(vpiType, vh1);
    if (type == vpiModule) {
      watch_inside(vh1);
      vpi_release_handle(vh1);
      return true;
    }
    _watched.emplace_back(vh1);
    return true;
  }

  void dump_watched();
};
