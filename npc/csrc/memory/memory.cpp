#include <my_memory.h>
#include <common.h>
#include <mtrace.h>
#include <device.h>
#include <vga.h>

extern bool is_skip_diff;
extern word_t pc,dnpc;
static int count = 0;
static uint64_t timer = 0;

static const uint32_t img[] = {
	0x00000413,
    0x00009117,
    0xffc10113,
	0x00c00513,
    0x00c000ef,
    0x00000513,
    0x00008067,
    0xff410113,
    0x00000517,
    0x01c50513,
    0x00112423,
    0xfe9ff0ef,
    0x00050513,
    0x00100073,
    0x0000006f
};

// 下面两个想跑就得改GPR的0号寄存器的初值，因为不能读取地址0x0的内容，那块就没有数据
static const uint32_t img_data_hazards_1[] = {
	// 指令1: addi x1, x0, 10
	0x00a00093,  // [12:0]=10, rd=1, funct3=0, rs1=0, opcode=0010011

	// 指令2: addi x2, x1, 5  (RAW冒险)
	0x00508113,  // [12:0]=5, rd=2, funct3=0, rs1=1, opcode=0010011

	// 指令3: add x3, x1, x2  (双RAW冒险)
	0x002081b3,  // funct7=0, rs2=2, rs1=1, funct3=0, rd=3, opcode=0110011

	// 指令5: addi x1, x0, 20
	0x01400093,  // [12:0]=20, rd=1, funct3=0, rs1=0, opcode=0010011

	// 指令6: addi x4, x1, 3  (潜在WAR冒险)
	0x00308213,  // [12:0]=3, rd=4, funct3=0, rs1=1, opcode=0010011

	// 指令7: addi x2, x0, 30
	0x01e00113,  // [12:0]=30, rd=2, funct3=0, rs1=0, opcode=0010011

	// 指令8: addi x2, x2, 40 (潜在WAW冒险)
	0x02810113,  // [12:0]=40, rd=2, funct3=0, rs1=2, opcode=0010011

	// 指令9: add x5, x3, x0  (结构冒险)
	0x000182b3,  // funct7=0, rs2=0, rs1=3, funct3=0, rd=5, opcode=0110011

	// 指令10: ebreak
	0x00100073,	 // ebreak
};

static const uint32_t img_data_hazards_2[] = {
	// 示例1：lw -> addi（RAW冒险）
	0x00002083,  // lw x1, 0(x0)    [x1 = mem[0]]
	0x00508113,  // addi x2, x1, 5  [x2 = x1 + 5]  <-- RAW冒险（依赖x1）

	// 示例2：lw -> add（RAW冒险）
	0x00402183,  // lw x3, 4(x0)    [x3 = mem[4]]
	0x00018233,  // add x4, x3, x0  [x4 = x3 + 0]  <-- RAW冒险（依赖x3）

	// 示例3：lw -> sw（RAW冒险）
	0x00802283,  // lw x5, 8(x0)    [x5 = mem[8]]
	0x00502623,  // sw x5, 12(x0)   [mem[12] = x5] <-- RAW冒险（依赖x5）
	// 指令: ebreak
	0x00100073,	 // ebreak
};

static const uint32_t img_data_hazards_3[] = {
	// ---------------------------
	// 1. ALU → ALU hazard
	// ---------------------------
	0x00500093,  // addi x1, x0, 5
	0x00a00113,  // addi x2, x0, 10
	0x002081b3,  // add  x3, x1, x2
	0x40118233,  // sub  x4, x3, x1
	0x002222b3,  // xor  x5, x4, x2

	// ---------------------------
	// 2. Load → ALU hazard
	// ---------------------------
	0x00002303,  // lw   x6, 0(x0)
	0x001302b3,  // add  x5, x6, x1

	// ---------------------------
	// 3. Load → Store hazard
	// ---------------------------
	0x00402403,  // lw   x8, 4(x0)
	0x00802423,  // sw   x8, 8(x0)

	// ---------------------------
	// 4. Store Address hazard
	// ---------------------------
	0x06400493,  // addi x9,  x0, 100
	0x0c800513,  // addi x10, x0, 200
	0x00a485b3,  // add  x11, x9, x10
	0x00b0a023,  // sw   x1, 0(x11)

	// ---------------------------
	// 5. Multi-source hazard
	// ---------------------------
	0x00700613,  // addi x12, x0, 7
	0x00900693,  // addi x13, x0, 9
	0x00d60733,  // add  x14, x12, x13
	0x40c707b3,  // sub  x15, x14, x12
	0x00f70833,  // add  x16, x14, x15

	// ---------------------------
	// 6. 自依赖 (不应stall)
	// ---------------------------
	0x00088893,  // addi x17, x17, 0
	0x00188933,  // add  x18, x17, x1
	0x00100073,	 // ebreak

};

static const uint32_t img_data_hazards_4[] = {
	0x00202023,//          	sw	s1,0(sp)
	0x00202023,//          	sw	ra,8(sp)
	0x00000497,//          	auipc	s1,0x0
	0x0bc4a483,//          	lw	s1,188(s1) # 800000f4 <a>
	0x00000013,
	0x00000013,
	0x00000013,
	0x00000013,
	0x00000013,
	// 指令: ebreak
	0x00100073,	 // ebreak
};

static const uint32_t img_control_hazard_1[] = {
	// 用例 1: BEQ 控制冒险
	0x00000513,   // addi x10, x0, 0
	0x00100593,   // addi x11, x0, 1
	0x00b50663,   // beq  x10, x11, 0x80000010   // 控制冒险
	0x00200513,   // addi x10, x0, 2             // 未跳转路径
	0x00300513,   // addi x10, x0, 3             // 分支目标 ; 控制冒险点

	// 用例 2: BEQ + 数据冒险
	0x00c00093,   // addi x1, x0, 12
	0x00108093,   // addi x1, x1, 1              // x1=13
	0x00108463,   // beq  x1, x1, 0x80000024      // 控制冒险 + 数据冒险 (x1 刚写)
	0x00200093,   // addi x1, x0, 2               // 未跳转路径 (需冲刷)
	0x00300093,   // addi x1, x0, 3               // 分支目标 ; 控制冒险点

	// 用例 3: JAL 控制冒险
	0x00000297,   // auipc x5, 0x0
	0x008000EF,   // jal   x1, 0x80000034         // 控制冒险
	0x00100313,   // addi  x6, x0, 1              // 被冲刷
	0x00200313,   // addi  x6, x0, 2              // JAL 目标 ; 控制冒险点
	0x00300313,   // addi  x6, x0, 3              

	// 用例 4: JALR 控制冒险
	0x00000413,   // addi x8, x0, 0
	0x03800493,   // addi x9, x0, 56              // x9=0x38 ; 跳转目标
	0x800004b7,   // lui  x9, 0x80000             // x9=0x80000000
	0x05048493,   // addi x9, x9, 50              // x9=0x80000050
	0x000480E7,   // jalr  x1, 0(x9)              // 控制冒险 + 数据冒险 (依赖x9)
	0x00400413,   // addi x8, x0, 4               // JALR 目标 ; 控制冒险点
	0x00500413,   // addi x8, x0, 5 

	// 用例 5: 混合控制+数据冒险
	0x00a00293,   // addi x5, x0, 10
	0x00a00313,   // addi x6, x0, 11
	0x00628463,   // beq   x5, x6, 0x80000068     // 控制冒险
	0x00a303B3,   // add   x7, x6, x10            // 数据冒险 (依赖x6) ; 未跳转路径
	0x00000393,   // addi  x7, x0, 0              // 分支目标 ; 控制冒险点

	// // 用例 6: JALR 控制冒险
	0x00000413,   // addi x8, x0, 0
	0x00000513,   // addi x10, x0, 0              // x9=0x38 ; 跳转目标
	0x80000537,   // lui  x10, 0x80000             // x9=0x80000000
	0x08050513,   // addi x10, x10, 80              // x9=0x80000050
	0x004500e7,   // jalr  x1, 4(x10)              // 控制冒险 + 数据冒险 (依赖x9)
	0x00400413,   // addi x8, x0, 4               // 被冲刷
	0x00b00293,   // addi x5, x0, 11               // JALR 目标 ; 控制冒险点
	0x00b00313,   // addi x6, x0, 11
	0x00628463,   // beq   x5, x6, 0x80000094     // 控制冒险
	0x06400293,   // addi x5, x0, 100			// 被冲刷
	0x00b30313,   // addi x6, x6, 11
	0x00100073,	 // ebreak
};

static const uint32_t img_control_hazard_2[] = {
	0x00008513,   // addi x10, x1, 0
	0x00002583,   // lw x11, 0(x0)			// 0
	0x00b50663,   // beq  x10, x11, 0x80000010   // 控制冒险
	0x00200513,   // addi x10, x0, 2             // 未跳转路径
	0x00300513,   // addi x10, x0, 3             // 分支目标 ; 控制冒险点
	0x00100073,	 // ebreak
};

static const uint32_t img_control_hazard_3[] = {
	0x00002783,	// lw x15, 0(x0)	
	0x000780e7,	// jalr x1, 0(x15)		// 控制冒险 + 数据冒险 (依赖x15)
	0x00200513,   // addi x10, x0, 2             // 被冲刷
	0x00300513,   // addi x10, x0, 3             // JALR 目标 ; 控制冒险点
	0x00100073,	 // ebreak
};

// 输出ABCD两个字符
static const uint32_t img_char_test[] = {
	0x100007b7,
	0x04100713,
	0x00e78023,
	0x04200713,
	0x00e78023,
	0x04300713,
	0x00e78023,
	0x04400713,
	0x00e78023,
	0x0000006f
};

static uint8_t *pmem = NULL;
static uint8_t *mrom = NULL;
static uint8_t *flash = NULL;
static uint8_t *psram = NULL;
static uint8_t *sdramChip0 = NULL;
static uint8_t *sdramChip1 = NULL;
static uint8_t *sdramChip2 = NULL;
static uint8_t *sdramChip3 = NULL;
static int cnt = 0;
static uint8_t flash_src_data[FLASH_SIZE];  // 原始数据缓冲区

void init_mem(size_t size){ 
	pmem = (uint8_t *)malloc(size * sizeof(uint8_t));
	// memset(pmem,0,size * sizeof(uint8_t));
	memcpy(pmem , img_data_hazards_3 , sizeof(img_data_hazards_3));
	if(pmem == NULL){exit(0);}
	printf("npc physical memory area [%#x, %#lx]\n",PMEM_BASE, PMEM_BASE + size * sizeof(uint8_t));
}

void init_mrom(){
	mrom = (uint8_t *)malloc(MROM_SIZE * sizeof(uint8_t));
	memcpy(mrom, img, sizeof(img));
	if(mrom == NULL) assert(0);
	printf("mrom memory area [%#x, %#lx]\n",MROM_BASE, MROM_BASE + MROM_SIZE * sizeof(uint8_t));
}

// TAG:这里只是为了测试flash的读需要
void generate_pattern_data() {
    for (uint32_t addr = 0; addr < FLASH_SIZE; addr++) {
        // 混合特征生成策略
        flash_src_data[addr] = 
            (addr & 0xFF) |                  // 低8位直接映射
            ((addr >> 8) & 0x0F) << 4 |      // 高4位映射到bit4-7
            (addr % 3) << 2 |                // 3种循环模式
            ((addr & 0x100) ? 0x80 : 0x00);  // 地址bit8作为最高位
			// if(addr < 10){
			// 	printf("addr is %x,data is 0x%08x\n",addr,flash_src_data[addr]);
			// }
    }
}

void init_flash(){
	// TAG:下面三行是测试flash_read使用的，可以删除
	// printf("generate START\n");
	// generate_pattern_data();
	// printf("generate END\n");
	flash = (uint8_t *)malloc(FLASH_SIZE * sizeof(uint8_t));
	// memset(flash, 0, FLASH_SIZE);
	// memcpy(flash, flash_src_data, FLASH_SIZE);
	// memcpy(flash, img_char_test, sizeof(img_char_test));
	memcpy(flash, img, sizeof(img));

	if(flash == NULL) assert(0);
	printf("flash memory area [%#x, %#lx]\n",FLASH_BASE, FLASH_BASE + FLASH_SIZE * sizeof(uint8_t));
}

void init_psram(){
	psram = (uint8_t *)malloc(PSRAM_SIZE * sizeof(uint8_t));
	// memset(psram, 0, PSRAM_SIZE);
	memcpy(psram, img, sizeof(img));
	
	if(psram == NULL) assert(0);
	printf("psram memory area [%#x, %#lx]\n",PSRAM_BASE, PSRAM_BASE + PSRAM_SIZE * sizeof(uint8_t));
}

void init_sdram(){
	sdramChip0 = (uint8_t *)malloc(SDRAM_SIZE * sizeof(uint8_t));
	sdramChip1 = (uint8_t *)malloc(SDRAM_SIZE * sizeof(uint8_t));
	sdramChip2 = (uint8_t *)malloc(SDRAM_SIZE * sizeof(uint8_t));
	sdramChip3 = (uint8_t *)malloc(SDRAM_SIZE * sizeof(uint8_t));

	memset(sdramChip0, 0, SDRAM_SIZE * sizeof(uint8_t));
	memset(sdramChip1, 0, SDRAM_SIZE * sizeof(uint8_t));
	memset(sdramChip2, 0, SDRAM_SIZE * sizeof(uint8_t));
	memset(sdramChip3, 0, SDRAM_SIZE * sizeof(uint8_t));

	if(sdramChip0 == NULL) assert(0);
	if(sdramChip1 == NULL) assert(0);
	if(sdramChip2 == NULL) assert(0);
	if(sdramChip3 == NULL) assert(0);
	printf("sdram memory area [%#x, %#lx]\n",SDRAM_BASE, SDRAM_BASE + SDRAM_SIZE * sizeof(uint8_t));
}

uint8_t *guest_to_host(uint32_t paddr){
	if(in_flash(paddr)){
		return flash + (paddr - FLASH_BASE);
	}
	#ifdef CONFIG_SOC
		else if(in_psram(paddr)){
			return psram + (paddr - PSRAM_BASE);
		} 
		
	#else 
		else if(in_pmem(paddr)){
			return pmem + (paddr - PMEM_BASE);
		}
	#endif
	else{
		panic("%#x is out of bound of npc",paddr);
	}
}

// TAG:FALSH的大小端转化可能后续需要调整一下位置，现在是在flash_read将小端序转化为了大端序，然后在flash.v中转化为了小端序进行执行
// flash读取出来的数据需要转化大小端，因为使用的flash是MSB优先的
extern "C" void flash_read(int32_t addr, int32_t *data) {
	addr = addr + FLASH_BASE;
	// printf("flash addr is 0x%08x\n",addr);
	int align_addr = addr & (~3);

	// 需要转化大小端
	uint32_t read_value;
	read_value = *(uint32_t *)guest_to_host(align_addr);
	// printf("real read value is %08x\n",read_value);

	// 手动交换32位数据的字节序
    uint32_t swapped_value = 
        ((read_value & 0x000000FF) << 24) |
        ((read_value & 0x0000FF00) << 8)  |
        ((read_value & 0x00FF0000) >> 8)  |
        ((read_value & 0xFF000000) >> 24);

	// 赋值给输出参数
    *data = (int32_t)swapped_value;

	// *data = *(int32_t *)guest_to_host(align_addr);
	// printf("real read value is %08x\n",*data);
}

extern "C" void psram_read(int32_t addr, int32_t *data){
	// printf("psram read addr is %08x\n",addr);
	addr = addr + PSRAM_BASE;	// 如果传过来的地址不只是偏移量，这个就可以直接删除
	
	int align_addr = addr & (~3);

	// 需要转化大小端
	// uint32_t read_value;
	// read_value = *(uint32_t *)guest_to_host(align_addr);
	// // printf("real read value is %08x\n",read_value);

	// // 手动交换32位数据的字节序
    // uint32_t swapped_value = 
    //     ((read_value & 0x000000FF) << 24) |
    //     ((read_value & 0x0000FF00) << 8)  |
    //     ((read_value & 0x00FF0000) >> 8)  |
    //     ((read_value & 0xFF000000) >> 24);

	// // 赋值给输出参数
    // *data = (int32_t)swapped_value;

	*data = *(int32_t *)guest_to_host(align_addr);
	// printf("READ addr = %#x , data = %#x\n",align_addr - PSRAM_BASE, *data);
}

extern "C" void psram_write(int addr, int data,int wstrb){
	// printf("psram write addr is %08x, data is %#x\n",addr,data);
	addr = addr + PSRAM_BASE;	// 如果传过来的地址不只是偏移量，这个就可以直接删除

	// int align_addr = addr & (~3);
	int align_addr = addr;		// 在这里写入不用进行对齐的操作
	switch (wstrb)
	{
		case 0b0001:
			*(uint8_t *)guest_to_host(align_addr) = (uint8_t)data;
			// printf("WRITE addr = %#x , data = %#x ,wstrb = %d\n",align_addr - PSRAM_BASE, data, wstrb);
			break;
		case 0b0011:
			*(uint16_t *)guest_to_host(align_addr) = (uint16_t)data;
			// printf("WRITE addr = %#x , data = %#x ,wstrb = %d\n",align_addr, data, wstrb);
			break;
		case 0b1111:
			*(uint32_t *)guest_to_host(align_addr) = (uint32_t)data;
			// printf("WRITE addr = %#x , data = %#x ,wstrb = %d\n",align_addr - PSRAM_BASE, data, wstrb);
			break;
		default:
			printf("wstrb is %x\n",wstrb);
			panic("DONOT SUPPORT THIS WSTRB");
			break;
	}
	return;
}


// TAG：因为加入了位扩展，所以需要判断chip_id，所以单独写了一个访问函数
uint8_t *guest_to_host_sdram(uint32_t paddr, int chip_id){
	if(chip_id == 0){
		if(in_sdram(paddr)){
			return sdramChip0 + (paddr - SDRAM_BASE);
		}
	} else if(chip_id == 1){
		if(in_sdram(paddr)){
			return sdramChip1 + (paddr - SDRAM_BASE);
		}
	} else if(chip_id == 2){
		if(in_sdram(paddr)){
			return sdramChip2 + (paddr - SDRAM_BASE);
		}
	} else if(chip_id == 3){
		if(in_sdram(paddr)){
			return sdramChip3 + (paddr - SDRAM_BASE);
		}
	}
	assert(0);
}

extern "C" void sdram_read(int chip_id, int bank_id, int row_id, int col_id, int *data){
	// 使用的sdram的颗粒是4个bank总共32MB，所以一个bank也就8MB
	int align_addr = (bank_id * 8192 * 512 * 2) + (row_id * 512 * 2) + (col_id * 2) + SDRAM_BASE;
	*data = *(uint16_t *)guest_to_host_sdram(align_addr, chip_id);
	align_addr = (chip_id == 2 || chip_id == 3)? align_addr + 0x2000000 : align_addr;
	// printf("READ  addr = %#x , data = %#x\t",align_addr, *data);
	// printf(" chip_id = %d, ba = %d, ra = %d, ca = %d\n", chip_id, bank_id, row_id, col_id);
	
	// if((bank_id == 0x2 && row_id == 0x5e && col_id == 0x16A) || (bank_id == 0x0 && row_id == 0x91 && col_id == 0x1f4) || (bank_id == 0x0 && row_id == 0x13 && col_id == 0x1f4)){
	// 	printf("chip id is %x, bank_id is %x, row_id is %x, col_id is %x\n",chip_id,bank_id,row_id,col_id);
	// 	printf("now read data:%#x , addr %x data is %x\n\n",*data,align_addr,*(uint16_t *)guest_to_host_sdram(align_addr, chip_id));
	// }
	#ifdef CONFIG_MTRACE
		mtrace_log_write(align_addr, 16, 'r', 0);
	#endif

	return;
}

extern "C" void sdram_write(int chip_id, int bank_id, int row_id, int col_id, int wstrb, int wdata) {
	int align_addr = (bank_id * 8192 * 512 * 2) + (row_id * 512 * 2) + (col_id * 2) + SDRAM_BASE;
	switch (wstrb)
	{
		case 0b0001:
			*(uint8_t *)guest_to_host_sdram(align_addr, chip_id) = wdata;
			// 一个MT48LC16M16A2颗粒的大小是32M,所以第二个chip的颗粒的地址是在第一个chip的颗粒的地址基础上加个0x2000000,
			// 当然真实访问颗粒的时候不用,加上0x2000000只是为了记录是否访问到了另外一个chip颗粒
			align_addr = (chip_id == 2 || chip_id == 3)? align_addr + 0x2000000 : align_addr;
			// printf("WRITE addr = %#x , data = %#x\t,wstrb = %d\t",align_addr, wdata, wstrb);
			// printf(" chip_id = %d, ba = %d, ra = %d, ca = %d\n", chip_id, bank_id, row_id, col_id);
			break;
		case 0b0010:
			*(uint8_t *)(guest_to_host_sdram(align_addr, chip_id) + 1) = (wdata >> 8);
			align_addr = (chip_id == 2 || chip_id == 3)? align_addr + 0x2000000 : align_addr;
			// printf("WRITE addr = %#x , data = %#x\t,wstrb = %d\t",align_addr, wdata >> 8, wstrb);
			// printf(" chip_id = %d, ba = %d, ra = %d, ca = %d\n", chip_id, bank_id, row_id, col_id);
			break;
		case 0b0011:
			*(uint16_t *)guest_to_host_sdram(align_addr, chip_id) = wdata;
			align_addr = (chip_id == 2 || chip_id == 3)? align_addr + 0x2000000 : align_addr;
			// printf("WRITE addr = %#x , data = %#x\t,wstrb = %d\t",align_addr, wdata, wstrb);
			// printf(" chip_id = %d, ba = %d, ra = %d, ca = %d\n", chip_id, bank_id, row_id, col_id);
			break;
		case 0b1111:
			assert(0);
			*(uint32_t *)guest_to_host_sdram(align_addr, chip_id) = wdata;
			align_addr = (chip_id == 2 || chip_id == 3)? align_addr + 0x2000000 : align_addr;
			// printf("WRITE addr = %#x , data = %#x\t,wstrb = %d\t",align_addr, wdata, wstrb);
			// printf(" chip_id = %d, ba = %d, ra = %d, ca = %d\n", chip_id, bank_id, row_id, col_id);
			break;
		default:
			printf("wstrb is %d\n", wstrb);
			break;
	}
	// if((bank_id == 0x2 && row_id == 0x5e && col_id == 0x16A) || (bank_id == 0x0 && row_id == 0x91 && col_id == 0x1f4) || (bank_id == 0x0 && row_id == 0x13 && col_id == 0x1f4)){
	// 	printf("chip id is %x, bank_id is %x, row_id is %x, col_id is %x\n",chip_id,bank_id,row_id,col_id);
	// 	printf("pc is %#x,chip_id is %x, wstrb is %x, now write data:%#x , addr %x data is %x\n\n",npc_w,chip_id,wstrb,wdata,align_addr,*(uint16_t *)guest_to_host_sdram(align_addr, chip_id));
	// }
	#ifdef CONFIG_MTRACE
		mtrace_log_write(align_addr, wstrb, 'w', wdata);
	#endif
	return;
}


extern "C" void mrom_read(int32_t addr, int32_t *data) {
    // MROM 地址范围为 0x20000000 ~ 0x20000FFF（4KB）
    // constexpr int32_t MROM_BASE = 0x20000000;
    // constexpr int32_t MROM_SIZE = 0x1000;
	int align_addr = addr & (~3);
	*data = *(int32_t *)guest_to_host(align_addr);

    // if (addr >= MROM_BASE && addr < MROM_BASE + MROM_SIZE) {
    //     *data = 0x00100073; // ebreak 指令
    // } else {
    //     *data = 0; // 非法地址返回 0 或触发错误
    //     // assert(0 && "Invalid MROM address");
    // }
}


extern "C" int pmem_read(int paddr){
	if(!((paddr >= 0x80000000 && paddr <= 0x87ffffff) || (paddr == RTC_ADDR) || (paddr == RTC_ADDR + 4) || (paddr == KBD_ADDR))) 
		return 0;
	paddr = paddr & (~3);	// 对齐地址
	/**
	 * 如果是设备访问内存，直接不用进行difftest
	 */
	if(paddr == RTC_ADDR || paddr == RTC_ADDR + 4 || paddr == KBD_ADDR){
		// printf("KBD_ADDR:%d\n",paddr==KBD_ADDR);
		is_skip_diff = true;
	}

	if(paddr == RTC_ADDR+4) {
		return (uint32_t)(timer >> 32);
	}
	else if(paddr == RTC_ADDR) {
		timer = get_time(); 
		return (uint32_t)timer;
	}
	else if(paddr == KBD_ADDR){
		return (uint32_t)key_dequeue();
	}
	else if(paddr == VGACTL_ADDR + 4){
		update_vga();
	}
	uint32_t *inst_paddr = (uint32_t *)guest_to_host(paddr);

	#ifdef CONFIG_MTRACE
		mtrace_log_write(paddr, 32, 'r', *inst_paddr);
	#endif

	return *inst_paddr;
}

extern "C" void pmem_write(int waddr, int wdata,char wmask){
	// printf("addr is %x,wmask is %x,write data is %x\n",waddr,wmask,wdata);
	if(!((waddr >= 0x80000000 && waddr <= 0x87ffffff) || (waddr == SERIAL_PORT))){
		return ;
	}
	
	if(waddr == SERIAL_PORT){
		// printf("now_pc:%#x\n",now_pc);
		is_skip_diff = true;
	}
	
	#ifdef CONFIG_MTRACE
		mtrace_log_write(waddr, wmask, 'w', wdata);
	#endif

	// device_write == 0 表示当前没有设备写入串口
	if(waddr == SERIAL_PORT) {
		putc((char)wdata,stderr);
		return;
	}
    // printf("data is %x\n",wdata);
	int align_addr = waddr & (~3);
	uint8_t *vaddr = guest_to_host(align_addr);
	uint8_t *iaddr;
	// 根据 wmask 写入对应的字节
    for (int i = 0; i < 4; ++i) {
        if(wmask & (1 << i)){
			// printf("vaddr is %x,iaddr is %x,realaddr is %x, realaddr_i is %x,wdata is %x,wdata_i is %x\n",waddr,waddr + i,vaddr, vaddr+i, wdata, (wdata >> (j * 8)) & 0xFF);
			iaddr = vaddr + i;
			*iaddr = (wdata >> (i * 8)) & 0xFF;
			// printf("align_addr is %x,write data is %x,data is %x\n",align_addr,(wdata >> (j * 8)) & 0xFF,*(uint32_t *)vaddr);
		}
    }
}

// 用于跳过访问UART、RTC等外设的指令
// TAG:这个函数的作用是没有在NEMU中跳过外设的时候有用，如果用于diff test的模块有了跳过外设的功能，就不需要了
extern "C" void skip(){
	is_skip_diff = true;
	return;
}