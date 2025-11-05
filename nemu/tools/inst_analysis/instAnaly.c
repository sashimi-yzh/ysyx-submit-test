#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include <stdint.h>
#include <string.h>


#define CHUNK (65536)

#define RV32
#ifdef RV32
#define PC_T uint32_t
#else
#define PC_T uint64_t
#endif

#ifdef RV32
#define PC_BYTE 4
#else
#define PC_BYTE 8
#endif 

#define INSTS(_) \
_(or) _(sltiu) _(sw) _(lb) _(lui) _(bltu) _(lhu) _(bge) _(mulh) _(sub) _(srli) _(auipc) \
_(jal) _(sltu) _(xori) _(srai) _(bgeu) _(and) _(add) _(remu) _(ebreak ) _(slt) _(jalr) \
_(lw) _(srl) _(andi) _(sb) _(addi) _(mulhu) _(ori) _(bne) _(sll) _(blt) _(divu) _(lbu) \
_(slli) _(sh) _(beq) _(mul) _(div) _(xor)

#define INSTS_ITEM(inst) uint64_t inst;



int read_gzip_file(const char *filename);
const char* get_instname(PC_T pc);

typedef struct{
    int pc;
    char* inst;
}InstPC;


typedef struct InstPCList{
    InstPC instpc;
    struct InstPCList *next;
}InstPCList;

typedef struct{
    uint64_t unknow;
    INSTS(INSTS_ITEM)
}InstSet;

InstSet instSet = {0};
InstPCList *instpc_head = NULL;
InstPCList *instpc_tail = NULL;


void record_data(PC_T pc){
    const char* instname = get_instname(pc);
#define RECORD_DATA(inst) \
    if(strcmp(instname, #inst) == 0 ){instSet.inst++; return;}
    INSTS(RECORD_DATA)
    instSet.unknow++;
}



InstPCList* InstPCList_add(InstPCList* l, PC_T pc, const char* instname){
    //static int inst_add_cnt = 0;
    InstPCList *list = l;
    if(list != NULL){
        while(list->next != NULL){
            list = list->next;
        }
        list->next = (InstPCList*)malloc(sizeof(InstPCList));
        list = list->next;
    }else {
        list = (InstPCList*)malloc(sizeof(InstPCList));
    }
    
    list->instpc.pc = pc;
    list->instpc.inst = (char*)malloc(strlen(instname)+1);
    strcpy(list->instpc.inst, instname);
    //printf("inst_add_cnt: %d\n", ++ inst_add_cnt);
    return list;
}
void InstPCList_print(InstPCList* l){
    InstPCList* list = l;
    while(list != NULL){
        printf("pc: %x, inst: %s\n", list->instpc.pc, list->instpc.inst);
        list = list->next;
    }
}

const char* get_instname(PC_T pc){
    InstPCList* list = instpc_head;
    while(list != NULL){
        if(list->instpc.pc == pc){
            return list->instpc.inst;
        }
        list = list->next;
    }
    return "";
}

void readDisasm(const char* filename){
    int instpc_is_head = 1;
    FILE*fp = fopen(filename,"r");
    if(fp==NULL){
        perror("readDisasm ERROR");
        return;
    }
    char line[100];
    char* l_ptr;
    PC_T pc;

    while(fgets(line,sizeof(line),fp)!=NULL){
        *(line + PC_BYTE*2) = '\0';
#ifdef RV32
        sscanf(line, "%x", &pc);
#else
        sscanf(line, "%lx", &pc);
#endif
        l_ptr = line + PC_BYTE*2+1;
        while(*(l_ptr++)){
            if(*l_ptr == ' '){
                *l_ptr = '\0';
            }
        }
        instpc_tail = InstPCList_add(instpc_tail, pc, line+PC_BYTE*2+1);
        if(instpc_is_head){instpc_head = instpc_tail; instpc_is_head = 0;}

    }
    fclose(fp);
}

void print_data(){
    uint64_t total_inst = 0;
#define CNT_INST(inst) total_inst += instSet.inst;
    INSTS( CNT_INST )
    printf("total_inst: %lu\n", total_inst);
    printf("inst, count, per/%%\n");
    
#define PRINT_DATA(inst) printf(#inst", %lu, %.3lf\n", instSet.inst, \
    (double)instSet.inst/total_inst*100);
    INSTS( PRINT_DATA )

    printf("unknow, %lu, %.3lf\n", instSet.unknow, (double)instSet.unknow/total_inst*100);
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s logfilename.gz filename.disasm \n", argv[0]);
        return EXIT_FAILURE;
    }
    readDisasm(argv[2]);
    //InstPCList_print(instpc_head);
    const char *filename = argv[1];
    if (read_gzip_file(filename) != 0) {
        return EXIT_FAILURE;
    }
    print_data();
    return EXIT_SUCCESS;
}



int read_gzip_file(const char *filename) {

    uint64_t read_pc_cnt = 0;

    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Failed to open gzip file");
        return -1;
    }

    z_stream strm;
    memset(&strm, 0, sizeof(strm));

    int ret = inflateInit2(&strm, 16 + MAX_WBITS); // 16 + MAX_WBITS to enable gzip decoding
    if (ret != Z_OK) {
        fprintf(stderr, "inflateInit2 failed\n");
        fclose(fp);
        return -1;
    }

    unsigned char in[CHUNK];
    unsigned char out[CHUNK];
    int done = 0;

    // 临时缓冲区用于存储当前块和剩余字节
    unsigned char temp_buffer[CHUNK + PC_BYTE];

    // 缓冲区用于存储上一次剩余的字节
    unsigned char leftover[PC_BYTE];
    size_t leftover_count = 0;

    while (!done) {
        strm.avail_in = fread(in, 1, CHUNK, fp);
        if (ferror(fp)) {
            perror("Read error");
            inflateEnd(&strm);
            fclose(fp);
            return -1;
        }
        done = feof(fp);

        strm.next_in = in;

        do {
            strm.avail_out = CHUNK;
            strm.next_out = out;

            ret = inflate(&strm, Z_NO_FLUSH);
            if (ret == Z_STREAM_ERROR) {
                fprintf(stderr, "Decompress error: Z_STREAM_ERROR\n");
                inflateEnd(&strm);
                fclose(fp);
                return -1;
            }

            if (ret == Z_NEED_DICT || ret == Z_DATA_ERROR || ret == Z_MEM_ERROR) {
                fprintf(stderr, "Decompress error: %d\n", ret);
                inflateEnd(&strm);
                fclose(fp);
                return -1;
            }

            size_t have = CHUNK - strm.avail_out;
            if (have > 0) {
                size_t total_bytes = leftover_count + have;
                size_t full_pc = total_bytes / PC_BYTE;


                memcpy(temp_buffer, leftover, leftover_count);
                memcpy(temp_buffer + leftover_count, out, have);

                for (size_t i = 0; i < full_pc; ++i) {
                    PC_T value;
                    memcpy(&value, temp_buffer + i * PC_BYTE, sizeof(PC_T));
                    //printf("%08x\n", value);
                    record_data(value);
                    read_pc_cnt++;
                    if(read_pc_cnt % 100000 == 0){
                        fprintf(stderr,"read_pc_cnt: %lu\n", read_pc_cnt);
                    }
                }

                // 更新剩余字节的数量和内容
                leftover_count = total_bytes % PC_BYTE;
                if (leftover_count > 0) {
                    memcpy(leftover, temp_buffer + full_pc * PC_BYTE, leftover_count);
                }
            }
        } while (strm.avail_out == 0);
    }

    // 处理最后可能剩余的字节
    if (leftover_count > 0) {
        unsigned char temp[PC_BYTE] = {0};
        memcpy(temp, leftover, leftover_count);
        PC_T value;
        memcpy(&value, temp, (PC_BYTE));
        printf("%08x (partial)\n", value);
        printf("ERROR: Has Partial Binary data!\n");
    }

    inflateEnd(&strm);
    fclose(fp);
    return ret == Z_STREAM_END ? 0 : -1;
}

