#define UART_BASE 0x10000000
#define UART_TX 0
#define UART_RX	0
#define UART_LCR 3
//Line Control Register
#define UART_DLB1 0
#define UART_DLB2 1
//Divisor Latch Byte 1/2
//假设工作主频为2GHz左右,波特率为115200,则根据计算,Divisor Latch
//的值应该等于2G/115200/16 ~ 1024,即DL内数据应该为:
//0000_0100_0000_0000
//亦即应该向DLB1写入0000_0000,向DLB2写入0000_0100
#define UART_LSR 5
//状态寄存器


#define GPIO_BASE	0x10002000
#define GPIO_LED	GPIO_BASE + 0x0
#define GPIO_SWITCH	GPIO_BASE + 0x4
#define GPIO_SEG	GPIO_BASE + 0x8



#define CLINT_BASE 	0x02000000
#define CLINT_END	0x0200ffff


#define KBD_BASE	0x10011000
#define KBD_END		0x10011007


//暂未使用
#define VGACTL_BASE	0x00000000
#define FB_BASE		0x21000000
#define FB_END		0x211fffff


//暂未使用
#define AUDIO_BASE	0x00000000



