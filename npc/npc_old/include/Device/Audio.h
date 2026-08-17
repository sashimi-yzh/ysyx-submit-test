#pragma once
#include "my_utils.h"
#include <SDL2/SDL.h>
#include <array>
#include <cstdint>
#include <memory>
#include <ostream>
struct AudioBase_t {
  struct {
    uint32_t reg_freq;
    uint32_t reg_channels;
    uint32_t reg_samples;
    uint32_t reg_sbuf_size;
    uint32_t reg_init;
    uint32_t reg_count;
  } reg_ctl;

  static constexpr int n_regs = 6;
  static constexpr size_t SoundBufferSize = 0x10000;
  using SBF = std::array<uint32_t, SoundBufferSize / sizeof(uint32_t)>;
  std::unique_ptr<SBF> sbuf;
};
inline AudioBase_t Audio;
inline void audio_init() {
  Audio.reg_ctl.reg_sbuf_size = AudioBase_t::SoundBufferSize;
  Audio.sbuf = std::make_unique<AudioBase_t::SBF>();
}

static void fill_audio_callback(void *udata, Uint8 *stream, int len) {
  SDL_memset(stream, 0, len);
  static int last_pos = 0;
  if (len == 0) {
    return;
  }
  uint32_t cnt = Audio.reg_ctl.reg_count;
  if (len > cnt)
    len = cnt;
  if (last_pos + len <= AudioBase_t::SoundBufferSize) {
    SDL_MixAudio(stream, static_cast<uint8_t *>(udata) + last_pos, len,
                 SDL_MIX_MAXVOLUME);
    last_pos += len;
  } else {
    SDL_MixAudio(stream, static_cast<uint8_t *>(udata) + last_pos,
                 AudioBase_t::SoundBufferSize - last_pos, SDL_MIX_MAXVOLUME);
    SDL_MixAudio(stream + AudioBase_t::SoundBufferSize - last_pos,
                 static_cast<uint8_t *>(udata),
                 len - AudioBase_t::SoundBufferSize + last_pos,
                 SDL_MIX_MAXVOLUME);
    last_pos = len - AudioBase_t::SoundBufferSize + last_pos;
  }

  Audio.reg_ctl.reg_count -= len;
}
inline void audio_init_event() {
  if (SDL_InitSubSystem(SDL_INIT_AUDIO)) {
    log_and_throw<std::runtime_error>("Could not initialize SDL - {}\n",
                                      SDL_GetError());
  }
  SDL_CloseAudio();
  if (Audio.reg_ctl.reg_samples >= (1 << 16)) {
    log_and_throw<std::logic_error>(
        "Audio.reg_samples = {} is bigger than 65535",
        Audio.reg_ctl.reg_samples);
  }
  if (Audio.reg_ctl.reg_channels >= (1 << 8)) {
    log_and_throw<std::logic_error>(
        "Audio.reg_channels = {} is bigger than 255",
        Audio.reg_ctl.reg_channels);
  }
  SDL_AudioSpec sdlAudioSpec = {
      .freq = static_cast<int>(Audio.reg_ctl.reg_freq),
      .format = AUDIO_S16SYS,
      .channels = static_cast<Uint8>(Audio.reg_ctl.reg_channels),
      .silence = 0,
      .samples = static_cast<Uint16>(Audio.reg_ctl.reg_samples),
      .callback = fill_audio_callback,
      .userdata = Audio.sbuf.get()};
  if (SDL_OpenAudio(&sdlAudioSpec, NULL) < 0) {
    log_and_throw<std::runtime_error>("Can't open audio - %s\n",
                                      SDL_GetError());
  }
  SDL_PauseAudio(0);
}
