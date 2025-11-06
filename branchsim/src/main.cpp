#include <common.h>
#include <branch.h>
FILE *fp = NULL;

int main(int argc, char **argv) {
    fp = fopen(argv[1], "r");
    if (!fp) assert(0);
    AlwaysTakenPredictor *atbp = new AlwaysTakenPredictor("./build/alwaysTaken.log", 0);
    AlwaysNotTakenPredictor *antbp = new AlwaysNotTakenPredictor("./build/alwaysNotTaken.log", 0);
    BTFNPredictor *btfnbp = new BTFNPredictor("./build/btfn.log", 4096);
    uint32_t inst;
    uint32_t pc;
    int temp;
    bool is_taken;

    while(fscanf(fp, "%u %u %d\n", &pc, &inst, &temp) != EOF){
        if(temp == 1){is_taken = true;}
        else if(temp == 0){is_taken = false;}
        else assert(0);
        atbp->check(atbp->predict(pc, inst), is_taken);
        antbp->check(antbp->predict(pc, inst), is_taken);
        btfnbp->check(btfnbp->predict(pc, inst), is_taken);
    }
    delete atbp;
    delete antbp;
    delete btfnbp;

    return 0;
}
