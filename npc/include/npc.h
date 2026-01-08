#ifndef __NPC_H__
#define __NPC_H__

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <assert.h> 

#include "VysyxSoCFull.h"

/*开关选择*/
//#define WAVE 1  //生成波形数据写入VCD文件
#ifndef NPC_WITHOUT_SOC
	#define NVBOARD 1 //连接NVBoard
#endif

//#define NPC_WITHOUT_SOC 1 //不连接SoC  别动

#define TEST_EXPR 0
#define SCAN_WATCHPOINT 0

//#define NPC_ITRACE 1
#define NPC_RTRACE 0
#define NPC_FTRACE 0
#define NPC_MTRACE 0

#define NPC_DIFFTEST 0

#define ARRLEN(arr) (int)(sizeof(arr) / sizeof(arr[0]))

extern int npc_state;
enum { NPC_RUNNING, NPC_STOP, NPC_END, NPC_ABORT, NPC_QUIT };

extern bool  npc_without_soc;

void cpu_exec(uint64_t n);
void exec_once();

extern TOP_NAME* top; //声明全局模块实例 

typedef struct {
	uint32_t gpr[32];  // 通用寄存器
	uint32_t pc;       // 程序计数器（当前,刚刚运行完的pc）
	uint32_t dnpc;     // 动态pc，即下一步pc
	uint32_t inst;     // 当前pc对应的指令
} CPU_state;
extern CPU_state npc;


/*关于调debug的宏定义*/

#define Log(format, ...)do { \
    const char *file = __FILE__; \
    const char *project_dir = "NPC_cloud_SoC/"; \
    const char *project_pos = strstr(file, project_dir); \
    const char *display_file = (project_pos != NULL) ? project_pos : file; \
    printf("\033[1;34m[%s:%d %s] " format "\033[0m \n",\
           display_file, __LINE__, __func__, ## __VA_ARGS__); \
} while(0)

#define Assert(cond, format, ...) \
	do { \
		if (!(cond)) { \
		fprintf(stderr, "\033[1;31m[%s:%d %s] " format "\033[0m \n",\
			 __FILE__, __LINE__, __func__, ## __VA_ARGS__); \
			assert(cond); \
		} \
	} while (0)

#define panic(format, ...) Assert(0, format, ## __VA_ARGS__)

/*关于存储器的定义和函数 */
#define NPC_PMEM_MSIZE 0x8000000
#define NPC_PMEM_MBASE 0x80000000

extern uint8_t pmem[NPC_PMEM_MSIZE];
uint32_t *paddr_read(uint32_t addr);
void pmem_write(int awaddr, int wdata, char wmask);
uint32_t  pmem_read(uint32_t addr);
//static void  default_peme();
long load_img(const char* img_file);

/*ysyxSoC*/

/*易失存储器(volatile memory) */
//例如SRAM和DRAM, 它们在上电时并没有存放有效数据. 
//如果上电后CPU直接从内存中读取指令执行, 存储器读出什么数据是未定义的,

/*非易失存储器(non-volatile memory):*/
//存放最初的程序, 其内容能在断电时保持, 并在上电时能让CPU马上从中取出指令. 
//一个最简单的解决方案就是ROM(Read-Only Memory), 每次从ROM中相同位置读出的内容都是相同的. 



/*MROM(mask Read-Only Memory) 掩膜只读存储器*/
//只读，出厂时内容被固定，无法修改;非易失性，断电后数据不丢失;成本低，适合大规模生产
#define NPC_MROM_MBASE 0x20000000 
#define NPC_MROM_MSIZE 0x1000
/* SRAM (Static Random-Access Memory) - 静态随机存取存储器*/
//易失性，断电后数据丢失;速度快，比DRAM快很多;不需要刷新，只要供电就保持数据;成本高，占用芯片面积大
#define NPC_SRAM_MBASE 0x0f000000
#define NPC_SRAM_MSIZE 0x2000
/*flash存储器,闪存*/
//在某些条件下擦除flash存储器中存放的内容, 并重新进行写入.(烧录器,U盘)
//处理过程包括接收命令, 解析, 执行, 等待新命令
#define NPC_FLASH_MBASE 0x30000000
#define NPC_FLASH_MSIZE 0x10000000

/*DRAM - 动态随机存取存储器*/
//每个存储单元由1个晶体管和1个电容组成。数据以电荷的形式存储在电容中。
// 需要刷新：电容会漏电，电荷会在几毫秒内消失，
//因此必须定期（例如每秒几百次）给电容充电（刷新），否则数据会丢失。这是“动态”一词的由来。
// 密度高、成本低：结构简单，可以在同样面积的芯片上做出更大容量，因此价格便宜。
// 速度比SRAM慢：因为需要刷新和读取时的放大操作。
// 易失性：断电后数据丢失。

/*psram(Pseudo Static Random Access Memory)颗粒 伪静态随机存取存储器*/
//在内部集成了刷新的逻辑,PSRAM控制器无需实现刷新的功能, 也无需关心PSRAM颗粒的内部结构, 
//在soc里映射0x8000_0000~0xa000_0000，实际上0x8000_0000 ~ 0x8010_0000
#define NPC_PSRAM_MBASE 0x80000000
#define NPC_PSRAM_MSIZE 0x20000000
//*SDRAM(Synchronous Dynamic Random Access Memory)颗粒 同步DRAM*/
//进一步提升访问DRAM颗粒的效率, 就要考虑将控制器和颗粒之间的串行总线改成并行总线了
// 这里的时钟信号CLK通常由DRAM控制器的时钟直接驱动
//SDR SDRAM(Single Date Rate SDRAM), 表示一个时钟传输一次数据
//DDR SDRAM(Double Data Rate SDRAM), 它可以分别在时钟的上升沿和下降沿传输数据, 因此提升了数据传输带宽; 
//此后依次出现了DDR2, DDR3, DDR4, DDR5, 它们均通过不同技术进一步提升数据传输带宽. 
//与同步DRAM相对, 还有异步DRAM(Asynchronous DRAM), 它的总线信号中没有时钟. 
//目前异步DRAM基本上被SDRAM替代, 因此今天讨论DRAM时, 几乎都指代SDRAM.
//在soc里映射0xa000_0000~0xbfff_ffff，实际上0xa0000000 ~ 0xa7ffffff
//SoC 里采用的共有4(存储体) * 8192(行地址) * 512(列地址) 
//* 32(每个矩阵元素的储存大小，原16bit，后用2个SDRAM颗粒扩展到32bit)，
//后实例化总计4个SDRAM颗粒的子模块,字扩展，地址翻倍
#define NPC_SDRAM_MBASE 0xa0000000
#define NPC_SDRAM_MSIZE 0x20000000

extern uint8_t mrom[NPC_MROM_MSIZE];
extern uint8_t sram[NPC_SRAM_MSIZE];
extern uint8_t flash[NPC_FLASH_MSIZE];
extern uint8_t psram[NPC_PSRAM_MSIZE];
extern uint8_t sdram[NPC_SDRAM_MSIZE];



#endif
