#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vorbis.h>
#include <SDL.h>

#define MUSIC_PATH "/share/music/startup.ogg"
#define SAMPLES 4096

static void *file_buf;
static stb_vorbis *v = NULL;
static stb_vorbis_info info = {};
static int16_t *stream_save = NULL;
static bool is_end = false;

static void FillAudio(void *userdata, uint8_t *stream, int len) {
  int nbyte = 0;
  int samples_per_channel = stb_vorbis_get_samples_short_interleaved(v,
      info.channels, (int16_t *)stream, len / sizeof(int16_t));
  if (samples_per_channel != 0 || len < sizeof(int16_t)) {
    int samples = samples_per_channel * info.channels;
    nbyte = samples * sizeof(int16_t);
  } else {
    is_end = true;
  }
  if (nbyte < len) memset(stream + nbyte, 0, len - nbyte);
  memcpy(stream_save, stream, len);
}

void play_audio() {
  FILE *fp = fopen(MUSIC_PATH, "rb");
  assert(fp);
  fseek(fp, 0, SEEK_END);
  size_t size = ftell(fp);
  assert(size);
  void *file_buf = malloc(size);
  fseek(fp, 0, SEEK_SET);
  assert(fread(file_buf, size, 1, fp) == 1);
  fclose(fp);

  int error;
  v = stb_vorbis_open_memory((const unsigned char *)file_buf, size, &error, NULL);
  assert(v);
  info = stb_vorbis_get_info(v);

  SDL_AudioSpec spec;
  spec.freq = info.sample_rate;
  spec.channels = info.channels;
  spec.samples = SAMPLES;
  spec.format = AUDIO_S16SYS;
  spec.userdata = NULL;
  spec.callback = FillAudio;
  SDL_OpenAudio(&spec, NULL);

  stream_save = (int16_t *)malloc(SAMPLES * info.channels * sizeof(*stream_save));
  assert(stream_save);
  SDL_PauseAudio(0);
}

void close_audio() {
  if (is_end) {
    SDL_CloseAudio();
    stb_vorbis_close(v);
    free(stream_save);
    free(file_buf);
    is_end = false;
  }
}
