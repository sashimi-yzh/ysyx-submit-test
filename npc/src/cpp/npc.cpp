#include <npc.hpp>

#ifdef USE_YSYXSOC
bool Npc::sdramInited() {
//   return top->rootp
//       ->ysyxSoCFull__DOT__asic__DOT__lsdram_apb__DOT__msdram__DOT__u_sdram_ctrl__DOT__state_q;
  return top->rootp
      ->ysyxSoCFull__DOT__asic__DOT__lsdram_axi__DOT__msdram__DOT__u_sdram_axi__DOT__u_core__DOT__state_q;
}
#endif