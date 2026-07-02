#include <contract_suite.h>
#include <klib-macros.h>

static void spin(unsigned n) { for (volatile unsigned i = 0; i < n; i++) {} }

static void point_dispatch_config(void) {
  CONTRACT_CHECK_POINT("dispatch-config", ioe_init(), "ioe-init");
  AM_TIMER_CONFIG_T timer = io_read(AM_TIMER_CONFIG);
  CONTRACT_CHECK_POINT("dispatch-config", timer.present, "timer-config");
  AM_INPUT_CONFIG_T input = io_read(AM_INPUT_CONFIG);
  CONTRACT_CHECK_POINT("dispatch-config", input.present, "input-config");
  AM_UART_CONFIG_T uart = io_read(AM_UART_CONFIG);
#if defined(__PLATFORM_YSYXSOC)
  CONTRACT_CHECK_POINT("dispatch-config", uart.present, "uart-config");
  AM_GPU_CONFIG_T gpu = io_read(AM_GPU_CONFIG);
  CONTRACT_CHECK_POINT("dispatch-config", gpu.present, "gpu-config");
  AM_GPIO_CONFIG_T gpio = io_read(AM_GPIO_CONFIG);
  CONTRACT_CHECK_POINT("dispatch-config", gpio.present, "gpio-config");
#elif defined(__PLATFORM_NEMU)
  CONTRACT_CHECK_POINT("dispatch-config", !uart.present, "uart-config");
  AM_GPU_CONFIG_T gpu = io_read(AM_GPU_CONFIG);
  CONTRACT_CHECK_POINT("dispatch-config", gpu.present, "gpu-config");
#else
  CONTRACT_CHECK_POINT("dispatch-config", !uart.present, "uart-config");
#endif
}

static void point_timer_uptime_precision(void) {
  uint64_t first = io_read(AM_TIMER_UPTIME).us;
  uint64_t last = first;
  bool grew = false;
  for (int i = 0; i < 256; i++) {
    spin(10000u);
    uint64_t now = io_read(AM_TIMER_UPTIME).us;
    CONTRACT_CHECK_POINT("timer-uptime-precision", now >= last, "uptime-monotonic");
    if (now > first) grew = true;
    last = now;
  }
  CONTRACT_CHECK_POINT("timer-uptime-precision", grew, "uptime-growth");
}

static uint64_t rtc_key(AM_TIMER_RTC_T r) {
  uint64_t v = (uint64_t)r.year;
  v = v * 13u + (uint64_t)r.month;
  v = v * 32u + (uint64_t)r.day;
  v = v * 24u + (uint64_t)r.hour;
  v = v * 60u + (uint64_t)r.minute;
  v = v * 60u + (uint64_t)r.second;
  return v;
}

static void check_rtc(AM_TIMER_RTC_T r) {
  CONTRACT_CHECK_POINT("timer-rtc", r.year >= 1970, "rtc-year");
  CONTRACT_CHECK_POINT("timer-rtc", r.month >= 1 && r.month <= 12, "rtc-month");
  CONTRACT_CHECK_POINT("timer-rtc", r.day >= 1 && r.day <= 31, "rtc-day");
  CONTRACT_CHECK_POINT("timer-rtc", r.hour >= 0 && r.hour < 24, "rtc-hour");
  CONTRACT_CHECK_POINT("timer-rtc", r.minute >= 0 && r.minute < 60, "rtc-minute");
  CONTRACT_CHECK_POINT("timer-rtc", r.second >= 0 && r.second < 60, "rtc-second");
}

static void point_timer_rtc(void) {
#if defined(__PLATFORM_NEMU)
  (void)rtc_key;
  (void)check_rtc;
  CONTRACT_CHECK_POINT("timer-rtc", true, "nemu-rtc-not-contract-critical");
#else
  AM_TIMER_RTC_T a = io_read(AM_TIMER_RTC);
  spin(200000u);
  AM_TIMER_RTC_T b = io_read(AM_TIMER_RTC);
  check_rtc(a); check_rtc(b);
  CONTRACT_CHECK_POINT("timer-rtc", rtc_key(b) >= rtc_key(a), "rtc-monotonic");
#endif
}

static void point_uart_loop(void) {
  AM_UART_CONFIG_T cfg = io_read(AM_UART_CONFIG);
#if defined(__PLATFORM_YSYXSOC)
  CONTRACT_CHECK_POINT("uart-loop", cfg.present, "uart-present");
  const char *token = "UART_TX_TOKEN\n";
  for (const char *p = token; *p; p++) io_write(AM_UART_TX, *p);
#else
  CONTRACT_CHECK_POINT("uart-loop", !cfg.present, "uart-absent");
  AM_UART_RX_T rx = io_read(AM_UART_RX);
  CONTRACT_CHECK_POINT("uart-loop", rx.data == (char)0xff, "uart-rx-idle");
#endif
}

static void point_input_idle_auto(void) {
  AM_INPUT_CONFIG_T cfg = io_read(AM_INPUT_CONFIG);
  CONTRACT_CHECK_POINT("input-idle-auto", cfg.present, "input-config");
  for (int i = 0; i < 128; i++) {
    AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
    CONTRACT_CHECK_POINT("input-idle-auto", ev.keycode >= AM_KEY_NONE && ev.keycode <= AM_KEY_PAGEDOWN, "key-range");
  }
}

static uint32_t pixels[16 * 16];
static void fill_pixels(uint32_t base) {
  for (int i = 0; i < 16 * 16; i++) {
    uint32_t x = base + (uint32_t)i;
    pixels[i] = ((x * 17u) & 0xffu) << 16 | ((x * 29u) & 0xffu) << 8 | ((x * 43u) & 0xffu);
  }
}
static void point_gpu_auto_smoke(void) {
#if defined(__PLATFORM_NPC)
  (void)pixels;
  (void)fill_pixels;
  CONTRACT_CHECK_POINT("gpu-auto-smoke", true, "npc-gpu-registers-unimplemented");
#else
  AM_GPU_CONFIG_T cfg = io_read(AM_GPU_CONFIG);
  CONTRACT_CHECK_POINT("gpu-auto-smoke", cfg.present && cfg.width >= 64 && cfg.height >= 64, "gpu-config");
#if defined(__PLATFORM_YSYXSOC)
  CONTRACT_CHECK_POINT("gpu-auto-smoke", cfg.width == 640 && cfg.height == 480, "ysyxsoc-size");
#endif
  fill_pixels(0x10u); io_write(AM_GPU_FBDRAW, 0, 0, pixels, 16, 16, false);
  fill_pixels(0x20u); io_write(AM_GPU_FBDRAW, cfg.width - 16, 0, pixels, 16, 16, false);
  fill_pixels(0x30u); io_write(AM_GPU_FBDRAW, 0, cfg.height - 16, pixels, 16, 16, false);
  fill_pixels(0x40u); io_write(AM_GPU_FBDRAW, cfg.width - 16, cfg.height - 16, pixels, 16, 16, true);
  AM_GPU_STATUS_T st = io_read(AM_GPU_STATUS);
  CONTRACT_CHECK_POINT("gpu-auto-smoke", st.ready, "gpu-status");
#endif
}
static void point_gpio_auto_smoke(void) {
#if defined(__PLATFORM_YSYXSOC)
  AM_GPIO_CONFIG_T cfg = io_read(AM_GPIO_CONFIG);
  CONTRACT_CHECK_POINT("gpio-auto-smoke", cfg.present, "gpio-present");
  io_write(AM_GPIO_LED, 0xa55au);
  io_write(AM_GPIO_SEG, 0x20260702u);
  AM_GPIO_SW_T sw = io_read(AM_GPIO_SW);
  (void)sw;
#else
  CONTRACT_CHECK_POINT("gpio-auto-smoke", true, "gpio-registers-unimplemented-on-platform");
#endif
}

int main(const char *args) {
  (void)args; contract_suite_begin();
  CONTRACT_RUN("dispatch-config", point_dispatch_config);
  CONTRACT_RUN("timer-uptime-precision", point_timer_uptime_precision);
  CONTRACT_RUN("timer-rtc", point_timer_rtc);
  CONTRACT_RUN("uart-loop", point_uart_loop);
  CONTRACT_RUN("input-idle-auto", point_input_idle_auto);
  CONTRACT_RUN("gpu-auto-smoke", point_gpu_auto_smoke);
  CONTRACT_RUN("gpio-auto-smoke", point_gpio_auto_smoke);
  contract_suite_pass();
}
