#include <am.h>
#include <amdev.h>
#include <klib.h>
#include <klib-macros.h>
#include <stdbool.h>
#include <stdint.h>

#define DEFAULT_REPEAT 1
#define MAX_REPEAT 1000000

typedef struct {
  int w;
  int h;
  const char *name;
} DrawCase;

// Collected from current workspace VGA users.
static const DrawCase kCases[] = {
  {4, 4, "demo_tile_4x4"},      // demo TILE_W=4
  {8, 8, "snake_tile_8x8"},     // snake TILE_W=8
  {8, 16, "typing_char_8x16"},  // typing-game CHAR_W/CHAR_H
  {20, 15, "amtest_blk_20x15"}, // am-tests video on 640x480 => 20x15
  {256, 1, "fceux_row_256x1"},  // fceux-am per-line blit
  {320, 1, "demo_row_320x1"},   // demo screen_clear()
  {640, 1, "typing_row_640x1"}, // typing-game clear row on 640-wide
  {256, 240, "nes_frame_256x240"},
  {320, 200, "demo_frame_320x200"},
  {400, 300, "slider_frame_400x300"},
  {640, 480, "full_frame_640x480"},
};

static uint32_t color_buf[640 * 480];
static uint32_t line_buf[640];

static inline uint64_t read_mcycle64(void) {
  uint32_t hi1 = 0, hi2 = 0, lo = 0;
  do {
    asm volatile("csrr %0, mcycleh" : "=r"(hi1));
    asm volatile("csrr %0, mcycle" : "=r"(lo));
    asm volatile("csrr %0, mcycleh" : "=r"(hi2));
  } while (hi1 != hi2);
  return ((uint64_t)hi2 << 32) | lo;
}

static int parse_repeat(const char *args) {
  if (args == NULL || args[0] == '\0') return DEFAULT_REPEAT;
  for (const char *p = args; *p != '\0'; p++) {
    if (p[0] == 'r' && p[1] == '=') {
      int val = atoi(p + 2);
      if (val <= 0 || val > MAX_REPEAT) return DEFAULT_REPEAT;
      return val;
    }
  }
  return DEFAULT_REPEAT;
}

static bool prepare_case(const AM_GPU_CONFIG_T *cfg, const DrawCase *c, int *ow, int *oh) {
  int w = c->w;
  int h = c->h;
  if (w <= 0 || h <= 0) return false;
  if (w > cfg->width || h > cfg->height) return false;
  *ow = w;
  *oh = h;
  return true;
}

static void fill_pattern(uint32_t *buf, int w, int h, uint32_t seed) {
  int n = w * h;
  for (int i = 0; i < n; i++) {
    uint32_t x = (uint32_t)i + seed;
    uint8_t r = (uint8_t)((x * 17u) & 0xffu);
    uint8_t g = (uint8_t)((x * 29u) & 0xffu);
    uint8_t b = (uint8_t)((x * 43u) & 0xffu);
    buf[i] = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
  }
}

static uint64_t bench_rect_once(int x, int y, int w, int h, uint32_t seed) {
  fill_pattern(color_buf, w, h, seed);
  uint64_t t0 = read_mcycle64();
  io_write(AM_GPU_FBDRAW, x, y, color_buf, w, h, false);
  uint64_t t1 = read_mcycle64();
  return t1 - t0;
}

static uint64_t bench_fceux_style_once(int x, int y, int w, int h, uint32_t seed) {
  for (int i = 0; i < w; i++) {
    uint32_t v = seed + (uint32_t)i;
    uint8_t r = (uint8_t)((v * 11u) & 0xffu);
    uint8_t g = (uint8_t)((v * 23u) & 0xffu);
    uint8_t b = (uint8_t)((v * 37u) & 0xffu);
    line_buf[i] = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
  }

  uint64_t t0 = read_mcycle64();
  for (int j = 0; j < h; j++) {
    io_write(AM_GPU_FBDRAW, x, y + j, line_buf, w, 1, false);
  }
  uint64_t t1 = read_mcycle64();
  return t1 - t0;
}

static uint64_t bench_amtest_grid32_once(int x, int y, int w, int h, uint32_t seed) {
  int n = 32;
  int bw = w / n;
  int bh = h / n;
  if (bw <= 0 || bh <= 0) return 0;
  int block_pixels = bw * bh;
  assert((uint32_t)block_pixels <= LENGTH(color_buf));

  uint64_t t0 = read_mcycle64();
  for (int gy = 0; gy < n; gy++) {
    for (int gx = 0; gx < n; gx++) {
      uint32_t c = seed + (uint32_t)(gy * n + gx);
      uint8_t r = (uint8_t)((c * 7u) & 0xffu);
      uint8_t g = (uint8_t)((c * 9u) & 0xffu);
      uint8_t b = (uint8_t)((c * 5u) & 0xffu);
      uint32_t pix = ((uint32_t)r << 16) | ((uint32_t)g << 8) | b;
      for (int i = 0; i < block_pixels; i++) color_buf[i] = pix;
      io_write(AM_GPU_FBDRAW, x + gx * bw, y + gy * bh, color_buf, bw, bh, false);
    }
  }
  uint64_t t1 = read_mcycle64();
  return t1 - t0;
}

static void report(const char *name, int w, int h,
                   uint64_t avg_cycles, uint64_t min_cycles, uint64_t max_cycles) {
  uint64_t pixels = (uint64_t)w * (uint64_t)h;
  uint64_t cpp_milli = (pixels == 0) ? 0 : (avg_cycles * 1000ull) / pixels;
  printf("[vga-bench] %-18s %3dx%-3d %10llu %10llu %10llu %6llu.%03llu\n",
         name, w, h,
         (unsigned long long)avg_cycles,
         (unsigned long long)min_cycles,
         (unsigned long long)max_cycles,
         (unsigned long long)(cpp_milli / 1000ull),
         (unsigned long long)(cpp_milli % 1000ull));
}

static void run_case_rect(const char *name, int w, int h, int repeat, uint32_t seed,
                          uint64_t *tot_cycles, uint64_t *tot_pixels) {
  uint64_t min_cycles = (uint64_t)-1, max_cycles = 0, sum_cycles = 0;
  for (int r = 0; r < repeat; r++) {
    uint64_t d = bench_rect_once(0, 0, w, h, seed + (uint32_t)r);
    if (d < min_cycles) min_cycles = d;
    if (d > max_cycles) max_cycles = d;
    sum_cycles += d;
  }
  uint64_t avg = sum_cycles / (uint64_t)repeat;
  report(name, w, h, avg, min_cycles, max_cycles);
  *tot_cycles += avg;
  *tot_pixels += (uint64_t)w * (uint64_t)h;
}

int main(const char *args) {
  ioe_init();

  AM_GPU_CONFIG_T cfg = io_read(AM_GPU_CONFIG);
  if (!cfg.present || cfg.width <= 0 || cfg.height <= 0) {
    printf("[vga-bench] GPU unavailable or invalid cfg: present=%d w=%d h=%d\n",
           cfg.present, cfg.width, cfg.height);
    return 1;
  }

  int repeat = parse_repeat(args);
  printf("[vga-bench] GPU %dx%d repeat=%d\n", cfg.width, cfg.height, repeat);
  printf("[vga-bench] format: scenario size avg_cycles min_cycles max_cycles cycles_per_pixel\n");

  uint64_t total_avg_cycles = 0;
  uint64_t total_pixels = 0;

  for (int i = 0; i < (int)LENGTH(kCases); i++) {
    int w = 0, h = 0;
    if (!prepare_case(&cfg, &kCases[i], &w, &h)) {
      printf("[vga-bench] skip %-18s (case too large for cfg)\n", kCases[i].name);
      continue;
    }
    run_case_rect(kCases[i].name, w, h, repeat, (uint32_t)(i * 0x1000u),
                  &total_avg_cycles, &total_pixels);
  }

  // Workload-style composite scenarios.
  if (cfg.width >= 256 && cfg.height >= 240) {
    uint64_t min_cycles = (uint64_t)-1, max_cycles = 0, sum_cycles = 0;
    for (int r = 0; r < repeat; r++) {
      uint64_t d = bench_fceux_style_once(0, 0, 256, 240, (uint32_t)(0x700000u + r));
      if (d < min_cycles) min_cycles = d;
      if (d > max_cycles) max_cycles = d;
      sum_cycles += d;
    }
    uint64_t avg = sum_cycles / (uint64_t)repeat;
    report("fceux_rows", 256, 240, avg, min_cycles, max_cycles);
    total_avg_cycles += avg;
    total_pixels += (uint64_t)256 * 240;
  }

  if (cfg.width >= 640 && cfg.height >= 480) {
    uint64_t min_cycles = (uint64_t)-1, max_cycles = 0, sum_cycles = 0;
    for (int r = 0; r < repeat; r++) {
      uint64_t d = bench_amtest_grid32_once(0, 0, 640, 480, (uint32_t)(0x800000u + r));
      if (d < min_cycles) min_cycles = d;
      if (d > max_cycles) max_cycles = d;
      sum_cycles += d;
    }
    uint64_t avg = sum_cycles / (uint64_t)repeat;
    report("amtest_grid32", 640, 480, avg, min_cycles, max_cycles);
    total_avg_cycles += avg;
    total_pixels += (uint64_t)640 * 480;
  }

  io_write(AM_GPU_FBDRAW, 0, 0, NULL, 0, 0, true);

  if (total_pixels != 0) {
    uint64_t overall_cpp_milli = (total_avg_cycles * 1000ull) / total_pixels;
    printf("[vga-bench] overall avg_cpp=%llu.%03llu (weighted by pixels)\n",
           (unsigned long long)(overall_cpp_milli / 1000ull),
           (unsigned long long)(overall_cpp_milli % 1000ull));
  }

  return 0;
}
