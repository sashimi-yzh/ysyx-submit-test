#include "include/common.h"
#include <cerrno>
#include <cstring>


#define FLASH_SIZE (16 * 1024 * 1024) // 16MB flash
uint32_t flash[FLASH_SIZE/4];// 16MB flash

extern "C" void flash_read(int32_t addr, int32_t *data) { 
    if(addr >= 0 && addr < FLASH_SIZE){
        *data = flash[addr/4];
    } else {
        printf("flash_read: Address out of range: 0x%08x\n", addr);
        *data = 0; // 或者其他默认值
    }


}

void init_flash(const std::string &path)
{
    printf("init_flash: loading binary from '%s'\n", path.c_str());
    FILE *fp = fopen(path.c_str(), "rb");
    if (!fp) {
        fprintf(stderr, "init_flash: cannot open '%s': %s\n", path.c_str(), strerror(errno));
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    if (size <= 0 || size > (long)FLASH_SIZE) {
        fprintf(stderr, "init_flash: invalid file size %ld (max %d)\n", size, FLASH_SIZE);
        fclose(fp);
        exit(1);
    }

    size_t n = fread(flash, 1, size, fp);
    fclose(fp);

    if ((long)n != size) {
        fprintf(stderr, "init_flash: read %zu bytes, expected %ld\n", n, size);
        exit(1);
    }
    bin_size = size;

    printf("init_flash: loaded %ld bytes from '%s'\n", size, path.c_str());
}