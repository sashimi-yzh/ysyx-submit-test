#include <replace_strategy.h>

void lru_replace(Cache *cache, CacheSet_t& set, int tag){
    cache->req_count();

    bool hit = false;
    for(auto it = set.begin(); it < set.end(); it++){
        if(it->tag == tag && it->valid == 1){
            hit = true;
            cache->hit_count();
            std::rotate(set.begin(), it, it+1);
        }
    }
    if(hit == false){
        cache->miss_count();
        std::rotate(set.begin(), set.end() - 1, set.end());
        set.front().valid = true;
        set.front().tag = tag;
    }
}