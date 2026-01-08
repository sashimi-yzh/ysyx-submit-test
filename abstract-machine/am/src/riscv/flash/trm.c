#include <am.h>
#include <klib-macros.h>
#include <klib.h>
extern char _heap_start;
extern char _heap_end;
int main(const char *args);

extern char _pmem_start;
#define PMEM_SIZE (128 * 1024 * 1024)
#define NPC_MROM_MSIZE 0xfff
#define NPC_MROM_MBASE 0x20000000
#define PMEM_END  ((uintptr_t)&_pmem_start + NPC_MROM_MSIZE)

Area heap = RANGE(&_heap_start, &_heap_end);
static const char mainargs[MAINARGS_MAX_LEN] = TOSTRING(MAINARGS_PLACEHOLDER); // defined in CFLAGS

// UART寄存器地址定义
#define UART_BASE 0x10000000
#define UART_RBR  (UART_BASE + 0x0)  // 接收器缓冲区,接收器 FIFO 输出 (read)
#define UART_THR  (UART_BASE + 0x0)  // 发射机保持寄存器,传输 FIFO 输入 (write)
#define UART_IER  (UART_BASE + 0x1)  // 启用/屏蔽由 UART 产生的中断信号
#define UART_IIR  (UART_BASE + 0x2)  // Interrupt Identification Register (read)
#define UART_FCR  (UART_BASE + 0x2)  // FIFO k (write)
#define UART_LCR  (UART_BASE + 0x3)  // 线路控制寄存器。控制连接参数
#define UART_MCR  (UART_BASE + 0x4)  // Modem Control Register，控制 FIFO 选项
#define UART_LSR  (UART_BASE + 0x5)  // 状态寄存器:状态信息
#define UART_MSR  (UART_BASE + 0x6)  // Modem Status Register
#define UART_DL1  (UART_BASE + 0x0)  // 除数锁存器的最低有效位（RW）
#define UART_DL2  (UART_BASE + 0x1)  // 除数锁存器的最高有效位（RW）

void UART_init(){
	/*设置除数寄存器, 波特率 = 基准时钟频率 / (16 × 除数)*/
	//线路控制寄存器的第7位(DLAB位)设置为'1'时,才能访问除数锁存器
	*(volatile uint8_t *)UART_LCR = 0b10000000; 
	//2个时钟除数寄存器共同组成一个16位的寄存器
    *(volatile uint8_t *)UART_DL1 = 0x01;  //The LSB of the divisor latch
    *(volatile uint8_t *)UART_DL2 = 0x00;  //The MSB of the divisor latch
	
	// 线路控制寄存器。控制连接参数
	*(volatile uint8_t *)UART_LCR = 0b00000011; 
	// 7位除数锁存器访问位 6位中断控制位 3位校验位 2位停止位 1,0位：字符的位数

	*(volatile uint8_t *)UART_IER = 0x00; //禁用中断（NPC目前不支持中断, 因此可不设置）

	*(volatile uint8_t *)UART_FCR = 0b00000001; //启用FIFO(此UART仅支持FIFO模式，会被忽略。)

}

void putch(char ch) {
	//asm volatile("汇编指令" : 输出操作数 : 输入操作数 : 破坏列表);
	// asm volatile("lui	a5, 0xa0000" : : :"a5");
	// asm volatile("sb	a0, 1016(a5)" : :"r"(ch): "memory");

	/*线路状态寄存器 (LSR) 第5位是'1'：发送器FIFO为空。
	产生发送保持寄存器空中断。当数据被写入发送器FIFO时，该位被清除。
	线路状态寄存器 (LSR) 第5位是'0': 等待 */
	while ( ( *(volatile uint8_t *)UART_LSR & 0b00100000) == 0) {}

	asm volatile(
				"lui a5, 0x10000\n"      // a5 = 0x10000 << 12 = 0x10000000
				"sb %0, 0x0(a5)"       // t0的值存储到 0x1000_0000(a5 + 0x0)
				: 
				: "r"(ch)                // %0 对应 ch 参数
				: "a5", "memory"         // a5和内存会被修改
	);

		    // 处理换行符
    if (ch == '\n') {
		while ((*(volatile uint8_t *)UART_LSR & 0x20) == 0) {}		
        // 发送回车
        asm volatile(
            "lui a5, 0x10000\n"
            "li t0, 0x0d\n"      // 回车符 ASCII 13
            "sb t0, 0x0(a5)"
            : 
            : 
            : "a5", "t0", "memory"
        );    	
    }
}

void halt(int code) {
	asm volatile("mv a0, %0; ebreak" : :"r"(code): "a0");
	//将函数的code(0的话表示正常退出)参数通过a0寄存器传递给ebreak异常处理器。
	while (1);
}

void CSR_init(){
	// 使用内联汇读取 CSR 寄存器
	uint32_t mvendorid, marchid;
    asm volatile("csrr %0, 0xF11" : "=r"(mvendorid));  // 读取 mvendorid 
    asm volatile("csrr %0, 0xF12" : "=r"(marchid));    // 读取 marchid 
	//数码管地址
    volatile uint32_t *gpio_seg = (volatile uint32_t *)0x10002008;	
    *gpio_seg = marchid;//数码管显示学号(16进制)

    // 输出 mvendorid:ysyx的ASCII
    putch((char)(mvendorid >> 24));
    putch((char)(mvendorid >> 16)); 
    putch((char)(mvendorid >> 8));
    putch((char)mvendorid);
    putch('_');

	char buffer[8]; // 存16进制数字
	int i = 0;
	while (marchid > 0) {
        buffer[i++] = '0' + (marchid % 16);
        marchid /= 16;
    }
    while (i > 0) {    // 反向输出
		//*(gpio_seg + i) = buffer[i];
        putch(buffer[--i]);
    }
	putch('\n');


}


// void __attribute__((section(".text.bootloader1"))) bootloader1(){
// 	extern char _bootloader2_start;  
// 	extern char _bootloader2_LMA_addr;
// 	extern char  _bootloader2_len;  //bootloader2的长度（地址）
// 	size_t len = (size_t)&_bootloader2_len; //读取_bootloader2_len地址，即为bootloader2的长度
// 	//一个指令一个指令转移
// 	if (len != 0){ //text,rodata,data一块转移
// 		//memcpy((void*)text_start, (const void*)text_LMA_addr, len); 
// 		uint32_t *out = (void*)&_bootloader2_start;  //将_text_start的地址转换为无类型指针
// 		const uint32_t *in = (const void*)&_bootloader2_LMA_addr;	
// 		size_t word_count = len / 4;
// 		for(size_t i = 0; i < word_count; i++){
// 			out[i] = in[i];
// 		}
// 		char *out_byte = (char*)(out + word_count);//非对齐的剩余字节
//     	const char *in_byte = (const char*)(in + word_count);
//     	for(size_t i = 0; i < len % 4; i++){
//         	out_byte[i] = in_byte[i];
//     	}
// 	} 
// 	return;
// }


void __attribute__((section(".text.bootloader2"))) bootloader2(){
	extern char __fsymtab_start;  // VMA中.text段的起始地址 存储在_text_start地址(0x80000000)处的一个字节的数据
	extern char _data_EXTRA_LMA_addr;// LMA中.text段的起始地址
	extern char _bss_start;  
	size_t len =  (size_t)&_bss_start - (size_t)&__fsymtab_start; //&_text_start:char*（指向char的指针）,_text_start的地址
	//4字节4字节转移
	if (len != 0){ //text,rodata,data一块转移
		//memcpy((void*)text_start, (const void*)text_LMA_addr, len); 
		uint32_t *out = (void*)&__fsymtab_start;  //将_text_start的地址转换为无类型指针
		const uint32_t *in = (const void*)&_data_EXTRA_LMA_addr;	
		size_t word_count = len / 4;
		for(size_t i = 0; i < word_count; i++){
			out[i] = in[i];
		}
		char *out_byte = (char*)(out + word_count);//非对齐的剩余字节
    	const char *in_byte = (const char*)(in + word_count);
    	for(size_t i = 0; i < len % 4; i++){
        	out_byte[i] = in_byte[i];
    	}
	} 


	return;
}

void _trm_init() {
	//bootloader();//将全局变量从LMA到VMA
	UART_init();// 初始化UART串口
	//CSR_init();// 使用内联汇读取 CSR 寄存器
	int ret = main(mainargs);
	halt(ret);
}
