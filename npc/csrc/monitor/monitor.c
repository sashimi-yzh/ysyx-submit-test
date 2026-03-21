#include "common.h"
#include <getopt.h>
#include "utils.h"

static char *diff_so_file = NULL;
static char *log_file = NULL;
static char *img_file = NULL;
static char *elf_file = NULL;
static int difftest_port = 1234;

void sdb_set_batch_mode();
paddr_t *guest_to_host(paddr_t paddr);
void init_isa();
void init_log(const char *log_file);
// void init_device();
void init_difftest(char *ref_so_file, long img_size, int port);
void init_sdb();
void init_disasm();
void init_ftrace(char *elf_file);
void init_mem();
void init_rand();

static int parse_args(int argc, char *argv[]) {
    const struct option table[] = {
        {"batch"        , no_argument       , NULL, 'b'},
        {"log"          , required_argument , NULL, 'l'},
        {"elf"          , required_argument , NULL, 'e'},
        {"diff"         , required_argument , NULL, 'd'},
        {"port"         , required_argument , NULL, 'p'},
        {"help"         , no_argument       , NULL, 'h'},
        {0              , 0                 , NULL,  0 },
    };

    int o;
    
    while( (o = getopt_long(argc, argv, "-bhl:e:d:p:", table, NULL)) != -1) {
        switch(o) {
            case 'b': sdb_set_batch_mode(); break;
            case 'p': scanf(optarg, "%d", &difftest_port); break;
            case 'l': log_file = optarg; break;
            case 'e': elf_file = optarg; break;
            case 'd': diff_so_file = optarg; break;
            case  1 : img_file = optarg; return 0;
            default :
                printf("Usage: %s [OPTION...] IMAGE [args]\n\n", argv[0]);
                printf("\t-b,--batch              run with batch mode\n");
                printf("\t-l,--log=FILE           output log to FILE\n");
                printf("\t-l,--elf=FILE           get the elf FILE for ftrace\n");
                printf("\t-d,--diff=REF_SO        run DiffTest with reference REF_SO\n");
                printf("\t-p,--port=PORT          run DiffTest with port PORT\n");
                printf("\n");
                exit(0);
        }
    }

    return 0;
}

static long load_img()
{
    if (img_file == NULL) {
        PRINTF_BLUE("No image is given. Use the default build-in image.\n");
        return 4096;
    }

    FILE *fp = fopen(img_file, "rb");
    assert(fp);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    PRINTF_BLUE("The image is %s, size = 0x%08lx\n", img_file, size);

    fseek(fp, 0, SEEK_SET);
    int ret = fread(guest_to_host(RESET_VECTOR), size, 1, fp);
    assert(ret == 1);

    fclose(fp);
    return size;
}

static void welcome()
{
    // PRINTF_BLUE("Welcome to NPC!\n");
}

void init_monitor(int argc, char *argv[]) {

    // for (int i=0; i<argc; i++) {
    //     printf("argv[%d] = %s\n", i, argv[i]);
    // }

    parse_args(argc, argv);

    init_rand();

    init_log(log_file);

    IFDEF(CONFIG_FTRACE, init_ftrace(elf_file));

    init_mem();

    // IFDEF(CONFIG_DEVICE, init_device());
    
    init_isa();

    long img_size = load_img();

    init_difftest(diff_so_file, img_size, difftest_port);

    init_sdb();

    IFDEF(CONFIG_ITRACE, init_disasm());

    welcome();
}