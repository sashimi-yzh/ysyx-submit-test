#ifndef __NPC_MEMORY_H__
#define __NPC_MEMORY_H__
#include<stdint.h>
typedef struct MemAccessInfo_{
    int      type;       
    uint32_t addr;      
    uint8_t  size;      
    int      sign_ext;  
    uint32_t data;      
                        
    uint8_t  reg;      
    uint8_t  funct3;   
    uint8_t  opcode;    
} MemAccessInfo;

MemAccessInfo get_mem_access_info(uint32_t instr);
#endif