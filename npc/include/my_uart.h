#ifndef MY_UART_H
#define MY_UART_H

#include <queue>
#include <cstdint>
#include <termios.h>

class MyUART {
public:
    // cycles_per_bit: 波特率对应的仿真周期数
    MyUART(int cycles_per_bit);
    ~MyUART();

    void tick(unsigned char *rx_pin);

private:
    int cycles_per_bit;
    std::queue<uint8_t> tx_queue;
    struct termios original_tio;

    bool busy;
    int timer;
    int bit_idx;
    uint16_t shifter;
    int tx_line;
    int gap_timer;
};

#endif