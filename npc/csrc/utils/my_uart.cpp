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
    // new_tio.c_lflag &= ~(ICANON | ECHO); 
    new_tio.c_lflag &= ~(ICANON); 
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
}

MyUART::~MyUART() {
    // 恢复终端设置
    tcsetattr(STDIN_FILENO, TCSANOW, &original_tio);
}

void MyUART::tick(unsigned char *rx_pin) {
    // 1. 优化：大幅降低系统调用频率
    // 每 10000 个时钟周期（或更多）才尝试读一次 stdin
    static uint32_t poll_timer = 0;
    if (poll_timer-- == 0) {
        poll_timer = 20000; 
        char c;
        if (read(STDIN_FILENO, &c, 1) > 0) {
            tx_queue.push(c);
        }
    }

    // 2. 发送逻辑优化：只在 busy 时处理定时器
    if (busy) {
        // tx_line 在整个 bit 持续期间保持不变，没必要每周期都计算
        timer--;
        if (timer <= 0) {
            timer = cycles_per_bit;
            bit_idx++;
            if (bit_idx < 10) {
                tx_line = (shifter >> bit_idx) & 1;
            } else {
                busy = false;
                tx_line = 1; // 停止位结束后回到空闲
                gap_timer = 10000; 
            }
        }
    } else {
        if (!tx_queue.empty() && gap_timer == 0) {
            uint8_t data = tx_queue.front();
            tx_queue.pop();
            shifter = (1 << 9) | (data << 1) | 0; // 1 Stop + 8 Data + 1 Start
            busy = true;
            bit_idx = 0;
            timer = cycles_per_bit;
            tx_line = 0; // 起始位(0)
        } else {
            tx_line = 1;
            if (gap_timer > 0) gap_timer--;
        }
    }

    if (rx_pin) {
        *rx_pin = tx_line;
    }
}