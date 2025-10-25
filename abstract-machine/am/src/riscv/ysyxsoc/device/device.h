#ifndef YSYX_SOC_DEVICE
#define YSYX_SOC_DEVICE

#define DEV_KEYBOARD    (0x10011000)
#define DEV_SERIAL      (0x10000000)
#define DEV_SRAM        (0x0f000000)
#define DEV_SPI         (0x10001000)
#define DEV_FLASH       (0x30000000)
#define DEV_PSRAM       (0x80000000)
#define DEV_VGA         (0x21000000)

typedef volatile unsigned char* device_ctrl;

#endif // YSYX_SOC_DEVICE