#include "flash.h"

uint8_t flash[FLASH_SIZE] = { 0x93,0x80,0x10,0x00,//addi,R(1) += 1, R(1) = 1
                            0x93,0x83,0x20,0x00,//addi,R(7) = R(1) + 2 = 3
                            0x93,0x83,0xf3,0xff,//addi,R(7) = R(7) - 1 = 2
                            0x03,0xaf,0x8f,0x01,//lw, R(30) = Mem(R(31) + 0x18) = Mem(0x80000018) = 0x55667788
                            0x73,0x00,0x10,0x00,//ebreak
                            0x12,0x13,0x14,0x15,
                            0x88,0x77,0x66,0x55 //data for reading
                            };



long init_flash(const char* file){
    printf("---------------------------------init_flash----------------------------------\n");
    FILE *fp = fopen(file, "rb");
    if(fp == NULL){
        printf("\033[31mFailed to locate file:\n%s\n",file);
        printf("Reading image file failure. Using built-in memory ...\033[0m\n");
        printf("\033[32mSize of image file = 32\n\033[0m");
        printf("--------------------------------init_flash done------------------------------\n");
        return 36;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("\033[32mImage file found in:\n%s\nSize of image file = %ld\033[0m\n",file, size);
	
	fseek(fp, 0, SEEK_SET);
    int ret = fread(flash, size, 1, fp);
	
	if(!ret)
        printf("Fread error. Using built-in memory ...\n");
    else
        ;
        //printf("Image file successfully loaded!\n");

    fclose(fp);

    printf("--------------------------------init_flash done------------------------------\n");
    return size;
}



extern "C" void flash_read(int32_t addr, int32_t *data){
    //注意入口参数addr已经减去了偏移量
	//printf("in flash_read, the addr is %x\n", addr);
	//addr = addr - FLASH_BASE;
    addr = addr & 0xfffffffc;//4字节对齐(可加可不加,默认已经四字节对齐了)
	//*data = (flash[addr] | (int32_t)flash[addr+1] << 8
    //        | (int32_t)flash[addr+2] << 16
    //        | (int32_t)flash[addr+3] << 24);
	/**data = (flash[addr+3] | (int32_t)flash[addr+2] << 8
            | (int32_t)flash[addr+1] << 16
            | (int32_t)flash[addr] << 24);*/
	*data = (flash[addr] | (int32_t)flash[addr+1] << 8
            | (int32_t)flash[addr+2] << 16
            | (int32_t)flash[addr+3] << 24);
}



void flash_read_sdb(int32_t addr, int32_t *data){
	addr = addr & 0xfffffffc;
	*data = (flash[addr] | (int32_t)flash[addr+1] << 8
            | (int32_t)flash[addr+2] << 16
            | (int32_t)flash[addr+3] << 24);
}



