#pragma once
#include "Device/Device.h"
#include "lockfree/spsc/queue.hpp"
#include <Device/Device.h>
#include <cstdint>
#include <memory>
struct KeyboardBase_t {
  using KBD_BUF = lockfree::spsc::Queue<uint32_t, 128>;
  std::unique_ptr<KBD_BUF> kbd_buf;
};

inline KeyboardBase_t Keyboard;

inline void keyboard_init() {
  init_keymap();
  Keyboard.kbd_buf = std::make_unique<KeyboardBase_t::KBD_BUF>();
}