#include <common.h>
#include <cache.h>
#include <algorithm>

void fifo_replace(Cache *cache, CacheSet_t& set, int tag);
void lru_replace(Cache *cache, CacheSet_t& set, int tag);