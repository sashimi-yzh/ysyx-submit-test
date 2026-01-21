#include "../include/common.h"
//=====================================================
// 主函数
//=====================================================
int main(int argc, char **argv)
{
  init_main(argc, argv);
  if(batch_mode)
    batch_mainloop();
  else
    sdb_mainloop();
  npc_end();
  // 结束
  return 0;
}
