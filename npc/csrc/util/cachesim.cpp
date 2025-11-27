#include "device.h"
#include "memory.h"

#include <cstdio>
#include <string.h>
#include <math.h>

typedef uint64_t (*diff_sim)(word_t*, word_t*);
extern diff_sim ref_difftest_sim;

static const uint8_t load = 0b0000011;
static const uint8_t store = 0b0100011;
static const uint8_t branch = 0b1100011;

void nemu_init(long img_size, int port);

bool cachesim_run(int cache_ls, int block_ls)
{
#ifdef RUNSOC
    word_t pc = 0x30000000;
#else
    word_t pc = 0x80000000;
#endif
    
    int block_l = (int)pow(2, block_ls) * 8;
    int cache_l = (int)pow(2, cache_ls);

    uint32_t* tags = new uint32_t[cache_l];
    bool* valids = new bool[cache_l];
    memset(valids, 0, sizeof(bool) * cache_l);

    uint32_t* mtags = new uint32_t[cache_l];
    bool* mvalids = new bool[cache_l];
    memset(valids, 0, sizeof(bool) * cache_l);

    int tag_idx = block_ls + cache_ls;

    double inst_num = 0, hit_num = 0, mem_num = 0, mhit_num = 0;
    double branch_hit = 0., branch_num = 0.; 
    word_t paddr = 0, nxpc = 0, inst = 0;
    while (pc != 0)
    {
        uint32_t tag = BITS(pc, 31, tag_idx);
        uint32_t index = BITS(pc, tag_idx - 1, block_ls);
        
        bool hit = (tags[index] == tag) && valids[index];
        if (hit) hit_num++;
        else
        {
            tags[index] = tag;
            valids[index] = true;
        }

        uint64_t ret = ref_difftest_sim(&paddr, &nxpc);
        pc = (uint32_t)ret;
        inst = (word_t)(ret >> 32);

        uint8_t opcode = BITS(inst, 6, 0);
        if (opcode == load || opcode == store)
        {
            if (!device_visit(paddr, inst))
            {
                uint32_t mtag = BITS(paddr, 31, tag_idx);
                uint32_t mindex = BITS(paddr, tag_idx - 1, block_ls);
                mem_num++;
                
                bool mhit = (mtags[mindex] == mtag) && mvalids[mindex];
                if (mhit) mhit_num++;
                else
                {
                    mtags[mindex] = mtag;
                    mvalids[mindex] = true;
                }
            }
        }
        
        if (opcode == branch)
        {
            branch_num++;
            // 总是不跳转
            if (nxpc == pc + 4)
                branch_hit++;
        }

        inst_num++;
    }

    double p  = hit_num / inst_num;
    double mp = mhit_num / mem_num;
    printf("[cache hit] = " ANSI_FMT("%ld / %ld", ANSI_FG_GREEN) "\n", (long)hit_num, (long)inst_num);
    printf(" [hit rate] = " ANSI_FMT("%5.3lf%%", ANSI_FG_GREEN) "\n", p * 100.);
    printf("     [AMAT] = " ANSI_FMT("%5.3lf", ANSI_FG_GREEN) "\n", 3. + (1. - p) * 13);
    printf("  [mem hit] = " ANSI_FMT("%ld / %ld", ANSI_FG_GREEN) "\n", (long)mhit_num, (long)mem_num);
    printf("[mhit rete] = " ANSI_FMT("%5.3lf%%", ANSI_FG_GREEN) "\n", mp * 100.);
    printf("   [AMAT_M] = " ANSI_FMT("%5.3lf", ANSI_FG_GREEN) "\n", 3. + (1. - mp) * 13);
    printf("[branch hit] = " ANSI_FMT("%ld / %ld", ANSI_FG_GREEN) "\n", (long)branch_hit, (long)branch_num);
    printf("[b hit rate] = " ANSI_FMT("%5.3lf%%", ANSI_FG_GREEN) "\n", branch_hit / branch_num * 100.);

    nemu_init(get_img_size(), 0);
    
    return true;
}