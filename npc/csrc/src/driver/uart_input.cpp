#include "common.h"

#ifdef SOC_UART_INPUT
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <string>

#include "driver.h"

class ThreadSafeQueue {
private:
  std::queue<std::string> q;
  std::mutex m;

public:
  void push(const std::string& s) {
    std::lock_guard<std::mutex> lock(m);
    q.push(s);
  }

  bool try_pop(std::string& s) {
    std::lock_guard<std::mutex> lock(m);
    if (q.empty()) return false;
    s = q.front();
    q.pop();
    return true;
  }

  bool empty() {
    std::lock_guard<std::mutex> lock(m);
    return q.empty();
  }
};

static ThreadSafeQueue str_queue;

static void input_thread() {
  std::string line;
  while (std::getline(std::cin, line)) {
    str_queue.push(line);
    if (std::cin.eof() || std::cin.fail()) break;
  }
}

static const int uart_divisor = 16;
static int uart_divisor_cnt;

void soc_uart_input_init() {
  uart_divisor_cnt = uart_divisor;
  top_module->externalPins_uart_rx = 1;
  std::thread t(input_thread);
  t.detach();
  Log("SOC UART input initialized");
}

void soc_uart_input_update() {
  if (--uart_divisor_cnt) return;
  else uart_divisor_cnt = uart_divisor;

  static std::string buffer;
  static int state = 0;
  static uint8_t data;

  if (state == 0) {
    if (buffer.empty()) {
      std::string line;
      while (str_queue.try_pop(line)) {
        buffer += line + "\n";
      }
      if (buffer.empty()) return;
    }
    data = buffer[0];
    buffer.erase(0, 1);
    top_module->externalPins_uart_rx = 0; // start bit
    state = 1;
  } else if (1 <= state && state <= 8) {
    top_module->externalPins_uart_rx = data & 1;
    data >>= 1;
    state++;
  } else if (state == 9) {
    top_module->externalPins_uart_rx = 1; // stop bit
    state = 0;
  }
}

#endif
