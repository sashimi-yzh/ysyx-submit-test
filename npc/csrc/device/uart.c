#include <stdio.h>
#include <common.h>
#include <device/device.h>
#include <memory/memory.h>


#ifdef CONFIG_HAS_UART
    bool in_uart(uint32_t paddr) { 
        return paddr >= CONFIG_UART_BASE && 
            paddr < CONFIG_UART_BASE + CONFIG_UART_SIZE; 
    }
    
#endif


bool in_clint(paddr_t addr) {
  bool res = false;
  IFDEF(CONFIG_HAS_CLINT, res=(addr - CONFIG_CLINT_BASE) < CONFIG_CLINT_SIZE);
  return  res;  
}