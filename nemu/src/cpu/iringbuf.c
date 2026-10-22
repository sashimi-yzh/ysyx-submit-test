#include <cpu/cpu.h>
#include <isa.h>
#include <memory/vaddr.h>

#ifdef CONFIG_IRINGBUF
// 定义环形缓冲区和索引
IRingBufEntry iringbuf[IRINGBUF_SIZE];
int iringbuf_index = 0;

// 向环形缓冲区添加一条指令记录
void iringbuf_add_inst(vaddr_t pc, uint32_t inst, const char *asm_str) {
  // 保存指令信息到当前位置
  iringbuf[iringbuf_index].pc = pc;
  iringbuf[iringbuf_index].inst = inst;
  
  // 复制反汇编文本
  strncpy(iringbuf[iringbuf_index].asm_buf, asm_str, sizeof(iringbuf[iringbuf_index].asm_buf) - 1);
  iringbuf[iringbuf_index].asm_buf[sizeof(iringbuf[iringbuf_index].asm_buf) - 1] = '\0';
  
  // 更新索引，实现环形效果
  iringbuf_index = (iringbuf_index + 1) % IRINGBUF_SIZE;
}

// 打印环形缓冲区内容
void print_iringbuf(vaddr_t pc) {
  printf("Instruction Ring Buffer (most recent %d instructions):\n", IRINGBUF_SIZE);
  
  // 找到出错指令在环形缓冲区中的位置
  int error_idx = -1;
  for (int i = 0; i < IRINGBUF_SIZE; i++) {
    if (iringbuf[i].pc == pc) {
      error_idx = i;
      break;
    }
  }
  
  // 从最旧的指令开始打印
  int start = (iringbuf_index) % IRINGBUF_SIZE;
  char p_str [256];
  
  for (int i = 0; i < IRINGBUF_SIZE; i++) {
    int idx = (start + i) % IRINGBUF_SIZE;
    // int idx = i;
    
    // 跳过未初始化的条目
    if (iringbuf[idx].pc == 0) continue;
    
    // 标记出错指令
    const char *marker = (idx == error_idx) ? "-->" : "   ";
    
    // printf("%s 0x%08x: %-24s %08x\n", 
    //        marker, (uint32_t)iringbuf[idx].pc, iringbuf[idx].asm_buf, iringbuf[idx].inst);
    snprintf(p_str, sizeof(p_str) - 1, "%s 0x%08x: %-20s  \t%02x %02x %02x %02x\n", 
            marker,
            (uint32_t)iringbuf[idx].pc,
            iringbuf[idx].asm_buf,
            (iringbuf[idx].inst >> 24) & 0xFF,
            (iringbuf[idx].inst >> 16) & 0xFF,
            (iringbuf[idx].inst >> 8)  & 0xFF,
            iringbuf[idx].inst & 0xFF);
    // printf("%s 0x%08x: %-20s  \t%02x %02x %02x %02x\n", 
    //         marker,
    //         (uint32_t)iringbuf[idx].pc,
    //         iringbuf[idx].asm_buf,
    //         (iringbuf[idx].inst >> 24) & 0xFF,
    //         (iringbuf[idx].inst >> 16) & 0xFF,
    //         (iringbuf[idx].inst >> 8)  & 0xFF,
    //         iringbuf[idx].inst & 0xFF);
    printf("%s", p_str);
    log_write("%s", p_str);
  }
  printf("\n");
}
#endif
