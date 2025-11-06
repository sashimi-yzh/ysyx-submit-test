#include <branch.h>
#include <assert.h>

bool BTFNPredictor::predict(uint32_t pc, uint32_t inst)
{
    if(findBTB(pc)){
        string op;
        uint32_t dest;
        bool legal = parse_inst(pc, inst, &op, &dest);
        // std::cout<<inst<<"\t"<<op<<std::endl;
        if(!legal) assert(0);
        if(dest <= pc){
            return true;
        }else{
            return false;
        }
    }else{
        updateBTB(pc, 0); // 模拟的时候不关系目的地址
        return false;
    }
}