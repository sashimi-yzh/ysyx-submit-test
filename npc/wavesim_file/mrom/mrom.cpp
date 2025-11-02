#include "mrom.h"


uint8_t mrom[MROM_SIZE] = { 0x93,0x80,0x10,0x00,//addi,R(1) += 1, R(1) = 1
                           	0x93,0x83,0x20,0x00,//addi,R(7) = R(1) + 2 = 3
                            0x93,0x83,0xf3,0xff,//addi,R(7) = R(7) - 1 = 2
                            0x03,0xaf,0x8f,0x01,//lw, R(30) = Mem(R(31) + 0x18) = Mem(0x80000018) = 0x55667788
                            0x73,0x00,0x10,0x00,//ebreak
                            0x12,0x13,0x14,0x15,
                            0x88,0x77,0x66,0x55 //data for reading
                            };


long init_mrom(const char* file){
    printf("---------------------------------init_mrom----------------------------------\n");
    FILE *fp = fopen(file, "rb");
    if(fp == NULL){
        printf("\033[31mFailed to locate file:\n%s\n",file);
        printf("Reading image file failure. Using built-in memory ...\033[0m\n");
        printf("\033[32mSize of image file = 32\n\033[0m");
        printf("--------------------------------init_mrom done------------------------------\n");
        return 36;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("\033[32mImage file found in:\n%s\nSize of image file = %ld\033[0m\n",file, size);

    fseek(fp, 0, SEEK_SET);
    int ret = fread(mrom, size, 1, fp);
	
	if(!ret)
        printf("Fread error. Using built-in memory ...\n");
    else
        ;
        //printf("Image file successfully loaded!\n");

    fclose(fp);

    printf("--------------------------------init_mrom done------------------------------\n");
    return size;

}


extern "C" void mrom_read(int32_t addr, int32_t *data){
    //assert(0);
	addr = addr - MROM_BASE;
	addr = addr & 0xfffffffc;//4字节对齐
	*data = (mrom[addr] | (int32_t)mrom[addr+1] << 8
            | (int32_t)mrom[addr+2] << 16
            | (int32_t)mrom[addr+3] << 24);
}


