#include "sdb.h"

#define NR_WP 32

static WP wp_pool[NR_WP] = {};
static WP *head = NULL, *free_ = NULL;

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
    wp_pool[i].expr[0] = '\0';
    wp_pool[i].new_value = 0;
    wp_pool[i].old_value = 0;
    wp_pool[i].hit_count= 0;
  }

  head = NULL;
  free_ = wp_pool;
}


WP *new_wp() {
    if(free_ == NULL) {
        printf("Error: watchpoint pool full\n");
        return NULL;
    }
    WP *wp = free_;
    free_ = free_->next;
    
    wp->next = head;
    head = wp;

    return wp;
}

void free_wp(uint32_t N) {
    WP *index = head;
    WP *wp = NULL;
    WP *prev = head;
    for(; index != NULL; index = index->next) {
        if(index->NO == N) {
            wp = index;
            break;
        } 
        prev = index;
    }

    if(wp == NULL) {
        printf("Error: no this wp!\n");
        return ;
    }

    printf("Successfully del #%d watchpoint\n", N);

    if(wp == head) {
        head = wp->next;
    } else {
        prev->next = wp->next;
    }

    wp->next = free_;
    free_ = wp;
}

word_t eval_expr(char *e, bool *success);

void set_watchpoint(char *expr) {
    WP *wp = new_wp();
    if(wp == NULL) {
        printf("Error to set wp\n");
        return ;
    }

    bool success = false;

    strncpy(wp->expr, expr, sizeof(wp->expr)-1);
    wp->old_value = eval_expr(expr, &success);
    assert(success);
    wp->new_value = wp->old_value;
    wp->hit_count = 0;

    printf("Set wp: #%d: %s\n", wp->NO, expr);
    return ;
}

void check_watchpoint() {
    WP *wp = head;
    bool success = false;
    uint32_t times = 0;

    while(wp != NULL) {
        wp->new_value = eval_expr(wp->expr, &success);
        assert(success);
        if(wp->new_value != wp->old_value) {
            printf("Wp #%d ack: %s\n", wp->NO, wp->expr);
            printf("Old: 0x%08x, New: 0x%08x\n", wp->old_value, wp->new_value);
            wp->old_value = wp->new_value;
            wp->hit_count++;
            times++;
        }
        wp = wp->next;
    }
    if(times != 0) {
        if(npc_state.state == NPC_RUNNING)
            npc_state.state = NPC_STOP;
    }
}

void info_watchpoint() {
    if(head == NULL) {
        printf("No watchpoint!\n");
        return ;
    }

    WP *index = head;
    while(index != NULL) {
        printf("Num: #%-3d   Expr: %-15s   Value: 0x%08x   Hit: %d\n", index->NO, index->expr, index->new_value, index->hit_count);
        index = index->next;
    }
    return ;
}
