#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_audio.h>

enum {
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  reg_wp,       // 应用程序可设置的写指针
  reg_rp,       // 只读的读指针
  nr_reg
};

static SDL_AudioDeviceID dev = 0;
static uint32_t rp = 0;  // 环形缓冲区读取位置
static uint32_t wp = 0;  // 环形缓冲区写入位置

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static void audio_io_handler(uint32_t offset, int len, bool is_write) {
  if (offset % 4 != 0 || len != 4) return;
  int index = offset / 4;

   if (is_write) {
    if (index == reg_init) {
      // 关闭旧设备（如果存在）
      if (dev) {
        SDL_PauseAudioDevice(dev, 1);
        SDL_CloseAudioDevice(dev);
        dev = 0;
      }
      
      // 初始化新设备
      if (audio_base[reg_init]) {
        SDL_AudioSpec want, have;
        want.freq = audio_base[reg_freq];
        want.format = AUDIO_S16SYS;
        want.channels = audio_base[reg_channels];
        want.samples = audio_base[reg_samples];
        want.callback = NULL;

        dev = SDL_OpenAudioDevice(NULL, 0, &want, &have, 0);
        if (dev) {
          SDL_PauseAudioDevice(dev, 0);
          // 重置指针
          rp = 0;
          wp = 0;
          audio_base[reg_wp] = 0;
          audio_base[reg_rp] = 0;
        // printf("SDL audio initialized: freq=%d, channels=%d, samples=%d\n",
        //      have.freq, have.channels, have.samples);
        } else {
          Log("Audio init failed: %s", SDL_GetError());
        }
      }
    } 
    else if (index == reg_wp) {
      // 更新写指针（由应用程序设置）
      uint32_t new_wp = audio_base[reg_wp];
      
      // 保护边界
      if (new_wp < CONFIG_SB_SIZE) {
        wp = new_wp;
      }
    }
    else if (index == reg_count && dev) {
      // 手动提交数据（可选）
      uint32_t len_val = audio_base[reg_count];
      uint32_t remain = (wp >= rp) ? (wp - rp) : (CONFIG_SB_SIZE - rp + wp);
      len_val = (len_val > remain) ? remain : len_val;
      
      if (len_val > 0) {
        if (rp + len_val <= CONFIG_SB_SIZE) {
          SDL_QueueAudio(dev, &sbuf[rp], len_val);
          rp = (rp + len_val) % CONFIG_SB_SIZE;
        } else {
          uint32_t part1 = CONFIG_SB_SIZE - rp;
          SDL_QueueAudio(dev, &sbuf[rp], part1);
          SDL_QueueAudio(dev, &sbuf[0], len_val - part1);
          rp = len_val - part1;
        }
      }
    }
  } else {
    // 读操作
    if (index == reg_count) {
      // 更新待播放数据量
      if (dev) {
        uint32_t data_remain = (wp >= rp) ? (wp - rp) : (CONFIG_SB_SIZE - rp + wp);
        audio_base[reg_count] = data_remain + SDL_GetQueuedAudioSize(dev);
      } else {
        audio_base[reg_count] = 0;
      }
    }
    else if (index == reg_rp) {
      // 确保读指针是最新的
      audio_base[reg_rp] = rp;
    }
  }
}

void audio_update() {
  if (dev == 0 || sbuf == NULL) return;
  
  // 检查环形缓冲区中的待播放数据量
  uint32_t remain = (wp >= rp) ? (wp - rp) : (CONFIG_SB_SIZE - rp + wp);
  
  if (remain == 0) return;
  
  // 获取SDL内部已排队但未播放的数据量
  uint32_t sdl_queued = SDL_GetQueuedAudioSize(dev);
  
  // 如果SDL内部缓冲空间不足一半容量，提交一批数据
  if (sdl_queued < (CONFIG_SB_SIZE / 2)) {
    // 确定提交长度（最大4096字节）
    uint32_t submit_len = remain > 4096 ? 4096 : remain;
    
    if (rp + submit_len <= CONFIG_SB_SIZE) {
      SDL_QueueAudio(dev, &sbuf[rp], submit_len);
      rp += submit_len;
    } else {
      uint32_t part1 = CONFIG_SB_SIZE - rp;
      SDL_QueueAudio(dev, &sbuf[rp], part1);
      
      uint32_t part2 = submit_len - part1;
      if (part2 > 0) {
        SDL_QueueAudio(dev, &sbuf[0], part2);
        rp = part2;
      } else {
        rp = 0;
      }
    }
  }
}

void init_audio() {
  if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
    Log("SDL audio init failed: %s", SDL_GetError());
    return;
  }

  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);

  audio_base[reg_sbuf_size] = CONFIG_SB_SIZE;
  audio_base[reg_wp] = 0;     // 写指针初始值
  audio_base[reg_rp] = 0;
}