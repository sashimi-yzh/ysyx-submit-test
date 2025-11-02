#define 	CHECK_MROM(addr)	((addr >= 0x20000000) && (addr <= 0x20000fff))
#define 	CHECK_FLASH(addr)	((addr >= 0x30000000) && (addr <= 0x3fffffff))
#define		CHECK_SRAM(addr)	((addr >= 0x0f000000) && (addr <= 0x0f001fff))
#define 	CHECK_PSRAM(addr)	((addr >= 0x80000000) && (addr <= 0x803fffff))
#define		CHECK_SDRAM(addr)	((addr >= 0xa0000000) && (addr <= 0xa1ffffff))
//注意PSRAM和SDRAM没有被全部使用
