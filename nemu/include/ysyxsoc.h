#ifndef __YSYXSOC_H__
#define __YSYXSOC_H__
#include <common.h>

extern uint8_t *mrom;
extern uint8_t *flash;
void init_soc();
bool in_socMem(paddr_t addr);       // 判断是否在SOC对应的存储中
bool in_Mrom(paddr_t addr);         // 判断是否在MROM中
bool in_Flash(paddr_t addr);        // 判断是否在FLASH
bool in_socDevW(paddr_t addr);      // 是否写设备
bool in_socDevR(paddr_t addr);      // 是否读设备

word_t soc_read(paddr_t addr, int len);
void soc_write(paddr_t addr, int len, word_t data);


word_t socDev_read(paddr_t addr,int len);
void socDev_write(paddr_t addr, int len, word_t data);
// 写icachetrace
void write_icacheitrace(paddr_t addr);

// 写branchtrace
void write_branchtrace(paddr_t pc, uint32_t inst, bool is_taken);

#endif