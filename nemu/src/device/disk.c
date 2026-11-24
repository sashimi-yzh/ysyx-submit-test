/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
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

static uint8_t *disk_ctl_base = NULL;

static void disk_ctl_io_handler(uint32_t offset, int len, bool is_write) {}

void init_disk() {
  disk_ctl_base = new_space(64);
#ifdef CONFIG_HAS_PORT_IO
  add_pio_map("disk", CONFIG_DISK_CTL_PORT, disk_ctl_base, 64, disk_ctl_io_handler);
#else
  add_mmio_map("disk", CONFIG_DISK_CTL_MMIO, disk_ctl_base, 64, disk_ctl_io_handler);
#endif
}
