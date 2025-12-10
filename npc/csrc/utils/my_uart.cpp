#include "../../include/common.h"
#include <unistd.h>
#include <fcntl.h>

MyUART::MyUART(int cycles_per_bit) 
    : cycles_per_bit(cycles_per_bit), busy(false), 
      timer(0), bit_idx(0), shifter(0), tx_line(1), gap_timer(0)
{
    // 配置 stdin 为非阻塞
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

    // 配置终端为 Raw 模式 (禁用行缓冲和回显)
    // 回显在不需要串口输入的情况下可以打开
    tcgetattr(STDIN_FILENO, &original_tio);
    struct termios new_tio = original_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO); 
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

MyUART::~MyUART() {
    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
}

void MyUART::tick(unsigned char *rx_pin) {
    char c;
    // 从 stdin 读取一个字节
    if (read(STDIN_FILENO, &c, 1) > 0) {
        tx_queue.push(c);
    }
    // 只有当不忙、有数据、且冷却时间已结束时，才开始发送下一个字节
    if (!busy && !tx_queue.empty() && gap_timer == 0) {
        uint8_t data = tx_queue.front();
        tx_queue.pop();
        //1 Start(0) + 8 Data + 1 Stop(1)
        shifter = (1 << 9) | (data << 1) | 0; 
        busy = true;
        bit_idx = 0;
        timer = cycles_per_bit;
    }
    if (busy) {
        tx_line = (shifter >> bit_idx) & 1;
        timer--;
        if (timer <= 0) {
            timer = cycles_per_bit;
            bit_idx++;
            if (bit_idx >= 10) { 
                busy = false;
                gap_timer = 5000; // 发送完一个字节后设置冷却时间 
            }
        }
    } else {
        tx_line = 1;        
        if (gap_timer > 0) {
            gap_timer--;
        }
    }
    if (rx_pin) {
        *rx_pin = tx_line;
    }
}