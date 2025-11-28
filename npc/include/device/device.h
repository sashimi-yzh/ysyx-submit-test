#ifndef __DEVICE__H__
#define __DEVICE__H__
#include <common.h>

#ifdef __cplusplus
extern "C" {
#endif
void init_mrom();
uint8_t* guest_to_mrom(uint32_t paddr);
#ifdef __cplusplus
}       
#endif //__cplusplus
#endif // __DEVICE__H__ 