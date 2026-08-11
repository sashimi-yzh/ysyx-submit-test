#include "sdb.h"
#include <npc/diagnostics.h>
#include <string.h>

#define NR_WP 32
#define WP_EXPR_SIZE 128

typedef struct watchpoint {
  int number;
  struct watchpoint *next;
  char expression[WP_EXPR_SIZE];
  word_t previous_value;
} WP;

static WP watchpoint_pool[NR_WP] = {};
static WP *active_list = NULL;
static WP *free_list = NULL;

void init_wp_pool() {
  for (int index = 0; index < NR_WP; index ++) {
    watchpoint_pool[index].number = index;
    watchpoint_pool[index].next =
      (index == NR_WP - 1 ? NULL : &watchpoint_pool[index + 1]);
  }
  active_list = NULL;
  free_list = watchpoint_pool;
}

int new_wp(char *expression) {
  bool success;
  word_t initial_value = expr(expression, &success);
  if (!success) return -1;

  if (free_list == NULL) return -1;

  size_t expression_length = strlen(expression);
  if (expression_length >= WP_EXPR_SIZE) return -1;

  WP *watchpoint = free_list;
  free_list = free_list->next;
  watchpoint->next = active_list;
  active_list = watchpoint;

  memcpy(watchpoint->expression, expression, expression_length + 1);
  watchpoint->previous_value = initial_value;
  return watchpoint->number;
}

bool free_wp(int number) {
  WP *previous = NULL;
  WP *current = active_list;

  while (current != NULL) {
    if (current->number == number) {
      if (previous == NULL) active_list = current->next;
      else previous->next = current->next;

      current->next = free_list;
      free_list = current;
      return true;
    }
    previous = current;
    current = current->next;
  }
  return false;
}

void display_watchpoints(void) {
  if (active_list == NULL) {
    puts("[watch] none");
    return;
  }

  printf("%-5s %-12s %s\n", "ID", "VALUE", "EXPRESSION");
  for (WP *current = active_list; current != NULL; current = current->next) {
    printf("#%-4d " FMT_WORD "   %s\n",
        current->number, current->previous_value, current->expression);
  }
}

bool check_watchpoints(void) {
  bool triggered = false;

  for (WP *current = active_list; current != NULL; current = current->next) {
    bool success;
    word_t current_value = expr(current->expression, &success);
    if (!success) {
      printf("[watch:%d] evaluation failed: %s\n",
          current->number, current->expression);
      continue;
    }

    if (current_value != current->previous_value) {
      printf("[watch:%d] %s\n", current->number, current->expression);
      printf("  value: " FMT_WORD " (%u) -> " FMT_WORD " (%u)\n",
          current->previous_value, current->previous_value,
          current_value, current_value);
      current->previous_value = current_value;
      triggered = true;
    }
  }
  return triggered;
}
