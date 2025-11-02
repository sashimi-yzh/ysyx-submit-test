#include <am.h>
#include <klib-macros.h>
#include <klib.h>

void __am_timer_init();

void __am_timer_rtc(AM_TIMER_RTC_T *);
void __am_timer_uptime(AM_TIMER_UPTIME_T *);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *);
void __am_gpu_config(AM_GPU_CONFIG_T *);
void __am_gpu_status(AM_GPU_STATUS_T *);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *);
void __am_audio_config(AM_AUDIO_CONFIG_T *);
void __am_audio_ctrl(AM_AUDIO_CTRL_T *);
void __am_audio_status(AM_AUDIO_STATUS_T *);
void __am_audio_play(AM_AUDIO_PLAY_T *);

//新增
void __am_uart_rx(AM_UART_RX_T *);
void __am_gpio_led_rd(AM_GPIO_LED_RD_T *);
void __am_gpio_led_wr(AM_GPIO_LED_WR_T *);
void __am_gpio_switch(AM_GPIO_SWITCH_T *);
void __am_gpio_seg_rd(AM_GPIO_SEG_RD_T *);
void __am_gpio_seg_wr(AM_GPIO_SEG_WR_T *);



static void __am_timer_config(AM_TIMER_CONFIG_T *cfg) { cfg->present = true; cfg->has_rtc = true; }
static void __am_input_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }
static void __am_uart_config(AM_INPUT_CONFIG_T *cfg) { cfg->present = true;  }

typedef void (*handler_t)(void *buf);
static void *lut[128] = {
  [AM_TIMER_CONFIG] = __am_timer_config,
  [AM_TIMER_RTC   ] = __am_timer_rtc,
  [AM_TIMER_UPTIME] = __am_timer_uptime,
  [AM_INPUT_CONFIG] = __am_input_config,
  [AM_INPUT_KEYBRD] = __am_input_keybrd,
  [AM_UART_CONFIG ]  = __am_uart_config,
  [AM_GPU_CONFIG  ] = __am_gpu_config,
  [AM_GPU_FBDRAW  ] = __am_gpu_fbdraw,
  [AM_GPU_STATUS  ] = __am_gpu_status,
  [AM_AUDIO_CONFIG] = __am_audio_config,
  [AM_AUDIO_CTRL  ] = __am_audio_ctrl,
  [AM_AUDIO_STATUS] = __am_audio_status,
  [AM_AUDIO_PLAY  ] = __am_audio_play,
  
  //新增
  [AM_UART_RX	  ] = __am_uart_rx,
  [AM_GPIO_LED_RD ] = __am_gpio_led_rd,
  [AM_GPIO_LED_WR ] = __am_gpio_led_wr,
  [AM_GPIO_SWITCH ] = __am_gpio_switch,
  [AM_GPIO_SEG_RD ] = __am_gpio_seg_rd,
  [AM_GPIO_SEG_WR ] = __am_gpio_seg_wr,
};

static void fail(void *buf) { panic("access nonexist register"); }

bool ioe_init() {
  for (int i = 0; i < LENGTH(lut); i++)
    if (!lut[i]) {lut[i] = fail;}
  __am_timer_init();
  return true;
}

void ioe_read (int reg, void *buf) { ((handler_t)lut[reg])(buf); }
void ioe_write(int reg, void *buf) { ((handler_t)lut[reg])(buf); }
