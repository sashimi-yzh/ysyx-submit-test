#ifndef __WATCHPOINT_H__
#define __WATCHPOINT_H__

#define NR_WP 5

void init_wp_pool();
void watchpoint_display();
void add_watchpoint(char *args);
void delete_watchpoint(int number);
void scan_watchpoint();

#endif