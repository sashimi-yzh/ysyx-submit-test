#include <ftrace/ftrace.h>
#include <ftrace/analysis_elf.h>

Func_Name_Collation func_name[MAX_FUNC];
// 用于恢复被尾调用删除的ret语句
TailRecNode *tail_rec_head = NULL; // linklist with head, dynamic allocated
// count_inv 表示调用的深度
int count_inv;

void init_tail_rec_list() {
	tail_rec_head = (TailRecNode *)malloc(sizeof(TailRecNode));
	tail_rec_head->pc = 0;
	tail_rec_head->next = NULL;
}

void init_ftrace(char* elf_file){
    init_tail_rec_list();
    analysis_elf(func_name,elf_file);
    count_inv = 0;
}

// void free_func_name(){
//     for(size_t i = 0;i < symbol_table_entry_count;i++){
//         free(func_name[i].name);
//     }
//     free(tail_rec_head);
// }

void insert_tail_rec(vaddr_t pc, int depth) {
	TailRecNode *node = (TailRecNode *)malloc(sizeof(TailRecNode));
	node->pc = pc;
	node->depth = depth;
	node->next = tail_rec_head->next;
	tail_rec_head->next = node;
}

void remove_tail_rec() {
	TailRecNode *node = tail_rec_head->next;
	tail_rec_head->next = node->next;
	free(node);
}


/**
 * 在ELF文件解析之后的函数的结构体中，根据每个函数的大小来判断对应的pc是否落入到当前的函数的区域内
 * is_call:
 *      是调用还是返回
 */
int find_symbol_func(vaddr_t target, bool is_call) {
	size_t i;
	for (i = 0; i < symbol_table_entry_count; i++) {
        // 判断是否为FUNC
        if(ELF32_ST_TYPE(func_name[i].info) == STT_FUNC){
            if (is_call) {
                if (func_name[i].addr == target) break;
            } else {
                if (func_name[i].addr <= target && target < func_name[i].addr + func_name[i].size) break;
            }
        }
	}
	return i < symbol_table_entry_count? i : -1;
}


/**
 * addr_inv:
 *      调用函数的地址
 * addr_func:
 *      函数的地址
 * is_tail:
 *      是否是尾调用
 */
void ftrace_function_call(vaddr_t addr_inv,vaddr_t addr_func,bool is_tail){
    if(symbol_table_entry_count == 0){
        return;
    }

    // 找到调用的函数在func_name中的位置
    int i = find_symbol_func(addr_func, true);
    printf("0x%x:",addr_inv);
    for(int j = 0;j < count_inv;j++){
        printf("  ");
    }
    printf("call [");
    char* name = (i>=0)? func_name[i].name : "???";
    printf("%s@0x%x]\n",name,addr_func);

    count_inv++;

    if(is_tail){
        insert_tail_rec(addr_inv,count_inv - 1);
    }
    
}

void ftrace_function_ret(vaddr_t pc){
    if(symbol_table_entry_count == 0){
        return;
    }

    printf("0x%x:",pc);
    // 找到调用的函数在func_name中的位置
    int i = find_symbol_func(pc, false);

    for(int j = 0;j < count_inv-1;j++){
        printf("  ");
    }

    printf("ret [");

    char* name = (i>=0)? func_name[i].name : "???";
    printf("%s]\n",name);

    count_inv--;

    TailRecNode *node = tail_rec_head->next;
	
    /**
     * 对齐ret和call语句
     */
    // while(node!=NULL){
    //     count_inv--;
    //     remove_tail_rec();
    //     node = tail_rec_head->next;
    // }
    /**
     * 用于恢复被尾调用优化删除的ret语句
     */
    if (node != NULL) {
		if (node->depth == count_inv) {
			paddr_t ret_target = node->pc;
			remove_tail_rec();
			ftrace_function_ret(ret_target);
		}
	}
}