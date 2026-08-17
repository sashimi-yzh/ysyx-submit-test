#include "Device/Audio.h"
#include "Device/Device.h"
#include "Device/Keyboard.h"
#include "Device/VGA.h"
#include "Setup.h"
#include "my_utils.h"
#include "spdlog/spdlog.h"
#include <Mem.h>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <fmt/format.h>
#include <stdexcept>

extern "C" uint32_t mem_read(uint32_t raddr) {
  if (config.mtracer)
    spdlog::info("Reading from address : {:#010x}", raddr);
  if (raddr >= config.base_memory &&
      raddr < config.base_memory + config.mem_size) {
    // in memory space
    size_t index = (raddr - config.base_memory) >> 2;
    // spdlog::info("addr : {:08x}, data : {:08x}", raddr, mem[index]);
    return mem[index];
  } else if (raddr >= config.base_device &&
             raddr < config.base_device + config.device_size) {
    // in MMIO
    uint32_t offset = raddr - config.base_device;
    if (offset == SERIAL_OFFSET) {
      // in Serial
      log_and_throw<std::logic_error>("Serial cannot be read");
    } else if (offset >= RTC_OFFSET && offset < RTC_OFFSET + RTC_LEN) {
      // in RTC
      size_t index = (offset - RTC_OFFSET) / sizeof(uint32_t);
      uint64_t value = update_RTC();
      if (index == 0)
        return value & 0xFFFFFFFF;
      else
        return value >> 32;
    } else if (offset == VGA_CTL_OFFSET && config.enable_vga) {
      // in VGA info
      return Video.screen_size_info;
    } else if (offset == VGA_CTL_OFFSET + 4 && config.enable_vga) {
      // in VGA sync
      return Video.sync.load();
    } else if (offset >= VGA_BF_OFFSET && offset < VGA_BF_OFFSET + VGA_BF_LEN &&
               config.enable_vga) {
      // in VGA buffer
      size_t index = (offset - VGA_BF_OFFSET) / 4;
      return Video.back_ptr[index];
    } else if (offset >= AUDIO_CTL_OFFSET &&
               offset < AUDIO_CTL_OFFSET + AUDIO_CTL_LEN) {
      // in audio ctl
      size_t AudioReg_id = (offset - AUDIO_CTL_OFFSET) / sizeof(uint32_t);
      std::span<uint32_t, AudioBase_t::n_regs> ctlreg_arrview(
          &Audio.reg_ctl.reg_freq, AudioBase_t::n_regs);
      return ctlreg_arrview[AudioReg_id];
    } else if (offset >= AUDIO_BF_OFFSET &&
               offset < AUDIO_BF_OFFSET + AUDIO_BF_LEN) {
      // in audio buffer
      size_t SoundBufferOffset = (offset - AUDIO_BF_OFFSET) / sizeof(uint32_t);
      return reinterpret_cast<uint32_t *>(Audio.sbuf.get())[SoundBufferOffset];
    } else if (offset == KBD_OFFSET && config.enable_vga) {
      // in keyboard
      uint32_t key;
      if (Keyboard.kbd_buf->Pop(key))
        return key;
      else
        return 0;
    } else {
      log_and_throw<std::logic_error>("Reading from unknown device : {:#010x}",
                                      raddr);
    }
  } else {
    log_and_throw<std::logic_error>("Reading from illegal address : {:#010x}",
                                    raddr);
  }
}

extern "C" void mem_write(uint32_t waddr, uint32_t wmask, uint32_t wdata) {
  uint32_t mask32 = lookup_mask32[wmask];
  if (config.mtracer)
    spdlog::info(
        "Writing to address {:#010x}, mask = {:#010x}, wdata = {:#010x}", waddr,
        mask32, wdata);
  if (waddr >= config.base_memory &&
      waddr < config.base_memory + config.mem_size) {
    // in memory space
    size_t index = (waddr - config.base_memory) >> 2;
    write_mask(mem[index], mask32, wdata);
  } else if (waddr >= config.base_device &&
             waddr < config.base_device + config.device_size) {
    // in MMIO
    uint32_t offset = waddr - config.base_device;
    if (offset == SERIAL_OFFSET) {
      // in Serial
      std::cout.put(wdata);
    } else if (offset >= RTC_OFFSET && offset < RTC_OFFSET + RTC_LEN) {
      // in RTC
      size_t index = (offset - RTC_OFFSET) / sizeof(uint32_t);
      uint64_t value = update_RTC();
      uint32_t lower = value & 0xFFFFFFFF;
      uint32_t upper = value >> 32;
      if (index == 0)
        write_mask(lower, mask32, wdata);
      else
        write_mask(upper, mask32, wdata);
      uint64_t new_value = (static_cast<uint64_t>(upper) << 32) | lower;
      RTC.last_time = std::chrono::steady_clock::now();
      RTC.RTC_reg_bias = new_value;
    } else if (offset == VGA_CTL_OFFSET && config.enable_vga) {
      // in in VGA info
      log_and_throw<std::logic_error>(
          "Address {:#010x} (screen_size_info) is readonly", waddr);
    } else if (offset == VGA_CTL_OFFSET + 4 && config.enable_vga) {
      // in VGA sync
      uint32_t tmp = Video.sync.load();
      if (!tmp) {
        write_mask(tmp, mask32, wdata);
        if (tmp) {
          Video.back_ptr = Video.front_ptr.exchange(Video.back_ptr);
          uint32_t *f = Video.front_ptr.load();
          std::copy(f, f + VideoBase_t::VMemSize / sizeof(uint32_t),
                    Video.back_ptr);
        }
        Video.sync.store(tmp);
      }
    } else if (offset >= VGA_BF_OFFSET && offset < VGA_BF_OFFSET + VGA_BF_LEN &&
               config.enable_vga) {
      // in VGA buffer
      size_t index = (offset - VGA_BF_OFFSET) / 4;
      write_mask(Video.back_ptr[index], mask32, wdata);
    } else if (offset >= AUDIO_CTL_OFFSET &&
               offset < AUDIO_CTL_OFFSET + AUDIO_CTL_LEN) {
      // in audio ctl
      size_t AudioReg_id = (offset - AUDIO_CTL_OFFSET) / sizeof(uint32_t);
      std::span<uint32_t, AudioBase_t::n_regs> ctlreg_arrview(
          &Audio.reg_ctl.reg_freq, AudioBase_t::n_regs);
      write_mask(ctlreg_arrview[AudioReg_id], mask32, wdata);
      if (Audio.reg_ctl.reg_init) {
        audio_init_event();
        Audio.reg_ctl.reg_init = 0;
      }
    } else if (offset >= AUDIO_BF_OFFSET &&
               offset < AUDIO_BF_OFFSET + AUDIO_BF_LEN) {
      // in audio buffer
      size_t SoundBufferOffset = (offset - AUDIO_BF_OFFSET) / sizeof(uint32_t);
      SDL_LockAudio();
      write_mask(
          reinterpret_cast<uint32_t *>(Audio.sbuf.get())[SoundBufferOffset],
          mask32, wdata);
      SDL_UnlockAudio();
    } else if (offset == KBD_OFFSET && config.enable_vga) {
      // in keyboard
      log_and_throw<std::logic_error>("Address {:#010x} (keyboard) is readonly",
                                      waddr);
    } else {
      log_and_throw<std::logic_error>("Writing to unknown device : {:#010x}",
                                      waddr);
    }
  } else {
    log_and_throw<std::logic_error>("Writing to illegal address : : {:#010x}",
                                    waddr);
  }
}