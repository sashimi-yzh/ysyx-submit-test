#include <common.h>
#include <device/map.h>
#include <SDL2/SDL.h>

#define MIN(a,b) (((a)<(b))?(a):(b))

enum
{
  reg_freq,
  reg_channels,
  reg_samples,
  reg_sbuf_size,
  reg_init,
  reg_count,
  nr_reg
};

#define OFFSET(name) (4 * (name))

static uint8_t *sbuf = NULL;
static uint32_t *audio_base = NULL;

static int r_idx = 0;

static void audio_play(void *userdata, uint8_t *stream, int len)
{
  int nread = MIN(audio_base[reg_count], len);
  int sbuf_size = audio_base[reg_sbuf_size];
  assert(sbuf_size > 0);

  int b = 0;
  int count = audio_base[reg_count];
  while (b < nread) {
    if (count != 0)
    {
      *stream = sbuf[r_idx % sbuf_size];    
      r_idx++;
      b++;
      stream++;
      count--;
    }
  }  
  audio_base[reg_count] -= nread;
  if (len > nread) {
    memset(stream, 0, len - nread);
  }
}

static void audio_io_handler(uint32_t offset, int len, bool is_write)
{
  assert(offset >= 0 && offset <= 20 && offset % 4 == 0);
  switch (offset)
  {
  // case OFFSET(reg_freq):
  //   break;
  // case OFFSET(reg_channels):
  //   break;
  // case OFFSET(reg_samples):
  //   break;
  // case OFFSET(reg_sbuf_size):
  //   break;
  case OFFSET(reg_init):
    if (is_write)
    {
      SDL_AudioSpec s = {};
      s.freq = audio_base[reg_freq];
      s.format = AUDIO_S16SYS;
      s.channels = audio_base[reg_channels];
      s.samples = audio_base[reg_samples];
      s.callback = audio_play;
      s.userdata = NULL;
      if (SDL_InitSubSystem(SDL_INIT_AUDIO) == 0)
      {
        SDL_OpenAudio(&s, NULL);
        SDL_PauseAudio(0);
      }
    }
    break;
    // case OFFSET(reg_count):
    //   break;
  }
}

void init_audio()
{
  uint32_t space_size = sizeof(uint32_t) * nr_reg;
  audio_base = (uint32_t *)new_space(space_size);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("audio", CONFIG_AUDIO_CTL_PORT, audio_base, space_size, audio_io_handler);
#else
  add_mmio_map("audio", CONFIG_AUDIO_CTL_MMIO, audio_base, space_size, audio_io_handler);
#endif

  sbuf = (uint8_t *)new_space(CONFIG_SB_SIZE);
  add_mmio_map("audio-sbuf", CONFIG_SB_ADDR, sbuf, CONFIG_SB_SIZE, NULL);
}