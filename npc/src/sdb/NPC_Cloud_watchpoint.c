#include "npc.h"
#include "sdb.h"

#define NR_WP 32

typedef struct watchpoint {
	int NO;
	struct watchpoint *next;
	struct watchpoint *prev;

	/* TODO: Add more members if necessary */
	uint32_t result;
	char expr[65536];

} WP;

static WP wp_pool[NR_WP] = {};//监视点结构的池
static WP *head = NULL, *final = NULL, *free_ = NULL;
//head用于组织使用中的监视点结构, free_用于组织空闲的监视点结构, 


void init_wp_pool() {
	int i;
	for (i = 0; i < NR_WP; i ++) {
		wp_pool[i].NO = i;
		wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
		wp_pool[i].prev = (i == 0 ? NULL : &wp_pool[i - 1]);
	}
	head = NULL;
	free_ = wp_pool;
	static WP fin;
	final = &fin;
	final->prev = NULL;
	final->next = NULL;

}//链表初始化

/* TODO: Implement the functionality of watchpoint */


WP* new_wp(){
	assert(free_);
	WP *wp = free_;
	free_ = free_->next;
	if (free_ != NULL) { free_->prev = NULL; }//检查free_是否还有剩余
	wp->next = final;
	wp->prev = final->prev;
	if(head == NULL){ head = wp; } //head为空的情况
	else{ final->prev->next = wp; }
	final->prev = wp;
	return wp;
};


void free_wp(WP *wp){
	WP *current = wp;
	while(current != final){
		current->NO--; 
		current = current->next;
	}
	if(wp == head){//取消的监视点是第一个(NO.0)
		if(head->next == final){  //仅剩下这一个监视点
			init_wp_pool();
			return;  
		}
		head = wp->next; 
	}else{
		wp->prev->next = wp->next;
	}
	wp->next->prev = wp->prev;
	//释放的监视点转移到free_
	wp->prev = NULL;
	wp->next = free_;
	if(free_ == NULL){//如果free_为空
		wp->NO = 31;
	}
	else{
		wp->NO = free_->NO - 1;
		free_->prev = wp;
	}
	free_ = wp;
	wp->result = 0;
	memset(wp->expr, 0, sizeof(wp->expr)); 
	return;
};


void isa_watchpoint_display(){
	WP *current = head;
	if( (head == NULL) ){
		printf("No wattchpoints\n");
		return;
	}
	printf("监视点信息:\n");
	while (current != final){
		int success;
		expr(current->expr, &success);
		if(success == 16)
			printf("NO.%d: expr=%s result=0x%-8x\n", current->NO, current->expr, current->result);
		else
			printf("NO.%d: expr=%s result=%u\n", current->NO, current->expr, current->result);
		current = current->next;
	}
	// printf("空余监视点信息:\n");
	// current = free_;
	// 	while (current != NULL){
	// 	printf("NO.%d: expr=%s result=%u\n", current->NO, current->expr, current->result);
	// 	current = current->next;
	// }
	return;
}


void set_watchpoint(char *args, uint32_t result, int *success){
	WP *wp = new_wp();
	strcpy(wp->expr,args);
	wp->result = result;
	if(*success == 16)
		printf("Set watchpoint NO.%d: expr=%s result=0x%-8x\n", wp->NO, wp->expr, wp->result);
	else
		printf("Set watchpoint NO.%d: expr=%s result=%u\n", wp->NO, wp->expr, wp->result);
	return;
}


void remove_watchpoint(int NO_watchpoint){
	if(NO_watchpoint <= final->prev->NO){
		WP *current = head;	
		while (current->NO != NO_watchpoint){
		current = current->next;
		}
		int success;
		expr(current->expr, &success);
		if(success == 16)
		printf("Delete watchpoint NO.%d: expr=%s result=0x%-8x\n", current->NO, current->expr, current->result);
		else
		printf("Delete watchpoint NO.%d: expr=%s result=%u\n", current->NO, current->expr, current->result);
		free_wp(current);
	}
	else 
		printf("Not this watchpoints\n");
	return;
}


bool scan_watchpoint(){
	WP *current = head;
	int change = 0;
	if( (head == NULL) ){ return false; }
	while (current != final){
		int success;
		uint32_t new_result = expr(current->expr, &success);
		if(new_result != current->result){
			change = 1;
			if(success == 16)
			printf("\nWatchpoint NO.%d: expr=%s\nold_result=0x%-8x\nnew_result=0x%-8x\n", current->NO, current->expr, current->result, new_result);
			else
			printf("\nWatchpoint NO.%d: expr=%s\nold_result=%u\nnew_result=%u\n", current->NO, current->expr, current->result, new_result);
			current->result = new_result;
		}
		current = current->next;
	}
	if (change){ 
		printf("\nWatchpoinst has changed!\n"); 
		return true; 
	}
	else return false;
}