/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include <device/map.h>
#include <device/alarm.h>
#include <utils.h>
#include <time.h>

static uint32_t *rtc_port_base = NULL;
#ifndef CONFIG_SIM_SOC
static int32_t *date_port_base = NULL;
#endif

static void rtc_io_handler(uint32_t offset, int len, bool is_write) {
  assert(offset == 0 || offset == 4);
  Assert(!is_write, "RTC io is read only");
  if (offset == 0) {
    uint64_t us = get_time();
    rtc_port_base[0] = (uint32_t)us;
  } else {
    uint64_t us = get_time();
    rtc_port_base[1] = us >> 32;
  }
}

#ifndef CONFIG_SIM_SOC
static void date_io_handler(uint32_t offset, int len, bool is_write) {
  Assert(!is_write, "Date io is read only");

  time_t t = time(NULL);
  struct tm *lt = localtime(&t);
  
  switch (offset) {
    case 0u:
      date_port_base[0] = lt->tm_sec;
      break;
    case 4u:
      date_port_base[1] = lt->tm_min;
      break;
    case 8u:
      date_port_base[2] = lt->tm_hour;
      break;
    case 12u:
      date_port_base[3] = lt->tm_mday;
      break;
    case 16u:
      date_port_base[4] = lt->tm_mon + 1;
      break;
    case 20u:
      date_port_base[5] = lt->tm_year + 1900;
      break;
    default:
      panic("Invalid date io offset: %u", offset);
      break;
  }
}
#endif

#ifndef CONFIG_TARGET_AM
static void timer_intr() {
  if (nemu_state.state == NEMU_RUNNING) {
    extern void dev_raise_intr();
    dev_raise_intr();
  }
}
#endif

void init_timer() {
  rtc_port_base = (uint32_t *)new_space(8);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map ("rtc", CONFIG_RTC_PORT, rtc_port_base, 8, rtc_io_handler);
#else
  add_mmio_map("rtc", CONFIG_RTC_MMIO, rtc_port_base, 8, rtc_io_handler, true);

#ifndef CONFIG_SIM_SOC
  date_port_base = (int32_t *)new_space(24);
  add_mmio_map("date", CONFIG_DATE_MMIO, date_port_base, 24, date_io_handler, true);
#endif
#endif
  IFNDEF(CONFIG_TARGET_AM, add_alarm_handle(timer_intr));
  get_time();
}
