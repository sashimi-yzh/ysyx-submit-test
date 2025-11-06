#include <replace_strategy.h>

bool is_hit(CacheSet_t& set, int tag, int way){
    for(int i = 0;i < way;i++){
        if(set[i].valid == 1 && set[i].tag == tag){
            return true;
        }
    }
    return false;
}

void fifo_replace(Cache *cache, CacheSet_t& set, int tag){
    cache->req_count();

    if(is_hit(set, tag, cache->get_ways())){
        cache->hit_count();
        return;
    } else {
        cache->miss_count();
        int empty_place = cache->has_empty(set);
        // 说明缓存组还有剩余
        if(empty_place != -1){
            set[empty_place].valid  = true;
            set[empty_place].tag    = tag;
        } else {
            // 缓存组没有剩余就将最早的缓存删除，就是第0号数据，然后将最后的数据修改
            std::rotate(set.begin(), set.begin() + 1, set.end());
            set.back().valid = true;
            set.back().tag = tag;
        }
        return;
    }
}