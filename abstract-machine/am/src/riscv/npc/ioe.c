#include <am.h>
#include <klib-macros.h>

void __am_timer_init(void);
void __am_timer_rtc(AM_TIMER_RTC_T *rtc);
void __am_timer_uptime(AM_TIMER_UPTIME_T *uptime);
void __am_input_keybrd(AM_INPUT_KEYBRD_T *keyboard);

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

static void uart_config(void *payload) {
  AM_UART_CONFIG_T *config = payload;
  config->present = false;
}

static void uart_receive(void *payload) {
  AM_UART_RX_T *receive = payload;
  receive->data = 0xff;
}

static void uart_transmit(void *payload) {
  const AM_UART_TX_T *transmit = payload;
  putch((char)transmit->data);
}

static const IOHandler read_handlers[IOE_REGISTER_COUNT] = {
  [AM_TIMER_CONFIG] = timer_config,
  [AM_TIMER_RTC] = timer_rtc,
  [AM_TIMER_UPTIME] = timer_uptime,
  [AM_INPUT_CONFIG] = input_config,
  [AM_INPUT_KEYBRD] = input_keyboard,
  [AM_UART_CONFIG] = uart_config,
  [AM_UART_RX] = uart_receive,
};

static const IOHandler write_handlers[IOE_REGISTER_COUNT] = {
  [AM_UART_TX] = uart_transmit,
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
  return true;
}

void ioe_read(int register_id, void *payload) {
  dispatch(read_handlers, register_id, payload);
}

void ioe_write(int register_id, void *payload) {
  dispatch(write_handlers, register_id, payload);
}
