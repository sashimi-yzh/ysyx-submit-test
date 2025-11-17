#include <cpu/top.h>

Tfp* _tfp = NULL;

Tfp* tfp() {
    if (!_tfp) {
        _tfp = new Tfp;
        Verilated::traceEverOn(true);  // 启用追踪
        top()->trace(_tfp, 99);           // 设置追踪深度（99 表示完整层级）
        _tfp->open("wave.fst");         // 指定输出文件名（FST 用 .fst）
    }
    return _tfp;
}