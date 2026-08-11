#include <am.h>
#include <klib-macros.h>

#include "include/npc.h"

void __am_timer_init(void);
void __am_gpu_init(void);

void __am_timer_rtc(AM_TIMER_RTC_T *rtc);
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *keyboard);
void __am_gpu_config(AM_GPU_CONFIG_T *config);
void __am_gpu_status(AM_GPU_STATUS_T *status);
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *drawing);

typedef void (*IOHandler)(void *payload);
enum { IOE_REGISTER_COUNT = 128 };

static void timer_config(void *payload) {
  AM_TIMER_CONFIG_T *config = payload;
  config->present = true;
  config->has_rtc = true;
}

static void timer_rtc(void *payload) {
  __am_timer_rtc(payload);
}

static void timer_uptime(void *payload) {
  __am_timer_uptime(payload);
}

static void input_config(void *payload) {
  AM_INPUT_CONFIG_T *config = payload;
  config->present = true;
}

static void input_keyboard(void *payload) {
  __am_input_keybrd(payload);
}

static void gpu_config(void *payload) {
  __am_gpu_config(payload);
}

static void gpu_status(void *payload) {
  __am_gpu_status(payload);
}

static void gpu_draw(void *payload) {
  __am_gpu_fbdraw(payload);
}

static void uart_config(void *payload) {
  AM_UART_CONFIG_T *config = payload;
  config->present = true;
}

static uint8_t uart_read_register(uint32_t offset) {
  return inb(YSYXSOC_UART_BASE + offset);
}

static void uart_receive(void *payload) {
  AM_UART_RX_T *receive = payload;
  if (uart_read_register(UART_LINE_STATUS_OFFSET) & UART_STATUS_RX_READY) {
    receive->data = (char)uart_read_register(UART_RX_DATA_OFFSET);
  } else {
    receive->data = (char)0xffu;
  }
}

static void uart_transmit(void *payload) {
  const AM_UART_TX_T *transmit = payload;
  putch((char)transmit->data);
}

static void gpio_config(void *payload) {
  AM_GPIO_CONFIG_T *config = payload;
  config->present = true;
}

static void gpio_read_switches(void *payload) {
  AM_GPIO_SW_T *switches = payload;
  switches->value = (uint16_t)(inl(YSYXSOC_GPIO_SWITCH_ADDR) & 0xffffu);
}

static void gpio_write_leds(void *payload) {
  const AM_GPIO_LED_T *leds = payload;
  outl(YSYXSOC_GPIO_LED_ADDR, (uint32_t)leds->value);
}

static void gpio_write_segments(void *payload) {
  const AM_GPIO_SEG_T *segments = payload;
  outl(YSYXSOC_GPIO_SEGMENT_ADDR, segments->value);
}

static const IOHandler read_handlers[IOE_REGISTER_COUNT] = {
  [AM_TIMER_CONFIG] = timer_config,
  [AM_TIMER_RTC] = timer_rtc,
  [AM_TIMER_UPTIME] = timer_uptime,
  [AM_INPUT_CONFIG] = input_config,
  [AM_INPUT_KEYBRD] = input_keyboard,
  [AM_GPU_CONFIG] = gpu_config,
  [AM_GPU_STATUS] = gpu_status,
  [AM_UART_CONFIG] = uart_config,
  [AM_UART_RX] = uart_receive,
  [AM_GPIO_CONFIG] = gpio_config,
  [AM_GPIO_SW] = gpio_read_switches,
};

static const IOHandler write_handlers[IOE_REGISTER_COUNT] = {
  [AM_GPU_FBDRAW] = gpu_draw,
  [AM_UART_TX] = uart_transmit,
  [AM_GPIO_LED] = gpio_write_leds,
  [AM_GPIO_SEG] = gpio_write_segments,
};

static void dispatch(const IOHandler handlers[], int register_id, void *payload) {
  if ((unsigned)register_id >= IOE_REGISTER_COUNT) {
    panic("IOE register is out of range");
  }

  IOHandler handler = handlers[register_id];
  if (handler == NULL) {
    panic("unsupported IOE register");
  }
  handler(payload);
}

bool ioe_init(void) {
  __am_timer_init();
  __am_gpu_init();
  return true;
}

void ioe_read(int register_id, void *payload) {
  dispatch(read_handlers, register_id, payload);
}

void ioe_write(int register_id, void *payload) {
  dispatch(write_handlers, register_id, payload);
}
