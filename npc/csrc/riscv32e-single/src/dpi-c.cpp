#include <common.h>
extern "C" int pmem_read(int raddr, int valid, int mtrace_flag) {
  if(valid == 0) return 0;
  // 总是读取地址为`raddr & ~0x3u`的4字节返回
  if (raddr == UPDATE_ADDR || raddr == UPDATE_ADDR + 4) {
    // rct
    difftest_skip_next_ref = true;
    gettimeofday(&tv, NULL);
    long int cur_time = tv.tv_sec * 1000000 + tv.tv_usec - start_time;
    return (raddr == UPDATE_ADDR) ? cur_time & 0xffffffff : (cur_time >> 32) & 0xffffffff;
  }
  raddr &= ~0x3u;
  raddr &= 0x7ffffff;
  if((uint32_t)raddr >= CONFIG_MSIZE) {
    printf(ANSI_FMT("raddr: 0x%08x out of mem\n", ANSI_FG_RED), (uint32_t)raddr);
    npc_state = NPC_ABORT;
  }
  uint32_t data = mem[raddr] | (mem[raddr+1] << 8) | (mem[raddr+2] << 16) | (mem[raddr+3] << 24);
#ifdef MTRACE_COND
  if(mtrace_flag) printf("%d read: 0x%08x: 0x%08x\n", mtrace_flag, raddr, data);
#endif
  return data;
}

extern "C" void npctrap(int a0) {
  if(a0 == 0) {
    printf(ANSI_FMT("HIT GOOD TRAP\n", ANSI_FG_GREEN));
    npc_state = NPC_GOODTRAP;
  }
  else if(a0 == 2) {
    printf("\033[1;31mIllegal Inst\033[0m\n");
    inst_display(npc_pc, npc_inst);
    npc_state = NPC_ABORT;
  }
  else {
    printf("\033[1;31mHIT BAD TRAP\033[0m\n");
    npc_state = NPC_BADTRAP;
  }
}

extern "C" void pmem_write(int waddr, int wdata, char wmask) {
  if (waddr == SERIAL_ADDR) {
    // serial
    difftest_skip_ref = true;
    putchar(wdata);
    fflush(stdout); 
    return ;
  }
  waddr &= ~0x3u;
  waddr &= 0x7ffffff;
  if((uint32_t)waddr >= CONFIG_MSIZE) {
    printf(ANSI_FMT("waddr: 0x%08x out of mem\n", ANSI_FG_RED), (uint32_t)waddr);
    npc_state = NPC_ABORT;
  }
  if(wmask & 0x1) mem[waddr] = (wdata >>  0) & 0xff;
  if(wmask & 0x2) mem[waddr + 1] = (wdata >>  8) & 0xff;
  if(wmask & 0x4) mem[waddr + 2] = (wdata >> 16) & 0xff;
  if(wmask & 0x8) mem[waddr + 3] = (wdata >> 24) & 0xff;
#ifdef MTRACE_COND
  printf("write: 0x%08x mask: %d data: 0x%08x\n", waddr, wmask, wdata);
#endif
  // 总是往地址为`waddr & ~0x3u`的4字节按写掩码`wmask`写入`wdata`
  // `wmask`中每比特表示`wdata`中1个字节的掩码,
  // 如`wmask = 0x3`代表只写入最低2个字节, 内存中的其它字节保持不变
}