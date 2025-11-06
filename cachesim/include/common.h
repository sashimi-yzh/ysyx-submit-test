#ifndef __COMMON_H__
#define __COMMON_H__

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdint.h>
#include <fstream>
#include <vector>
extern FILE *fp;

typedef uint64_t paddr_t;

typedef struct
{
    uint64_t req_cnt;   // 请求总数
    uint64_t hit;       // 命中次数
    uint64_t miss;      // 缺失次数
}Report;

// cache块的元数据
typedef struct
{
    uint32_t tag;
    uint32_t index;
    bool     valid;
}CacheBlock;

typedef std::vector<CacheBlock> CacheSet_t; //  cache块的组合
typedef CacheSet_t *cache_t;

#endif