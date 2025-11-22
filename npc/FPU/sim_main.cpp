#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include "Vfpu_tb.h"
#include "verilated.h"
#include "verilated_vcd_c.h"

// 测试向量结构
struct TestVector {
    uint8_t op_type;        // 操作码 (2 hex digits)
    uint32_t op1;           // 操作数1 (8 hex digits)
    uint32_t op2;           // 操作数2 (8 hex digits)
    uint8_t frm;            // 舍入模式 (1 hex digit)
    uint32_t expected_result; // 预期结果 (8 hex digits)
    uint8_t expected_flags; // 预期异常标志 (2 hex digits)
};

// 操作码到指令名的映射
std::string get_instruction_name(uint8_t op_type) {
    switch (op_type) {
        case 0x09: return "FADD_S";
        case 0x0A: return "FSUB_S";
        case 0x0B: return "FMUL_S";
        case 0x0C: return "FDIV_S";
        case 0x05: return "FSGNJ_S";
        case 0x06: return "FSGNJN_S";
        case 0x07: return "FSGNJX_S";
        case 0x0F: return "FEQ_S";
        case 0x11: return "FLT_S";
        case 0x10: return "FLE_S";
        case 0x0D: return "FMIN_S";
        case 0x0E: return "FMAX_S";
        default: return "UNKNOWN";
    }
}

// 舍入模式到字符串的映射
std::string get_rounding_mode(uint8_t frm) {
    switch (frm) {
        case 0: return "RNE";   // FE_TONEAREST
        case 1: return "RTZ";   // FE_TOWARDZERO
        case 2: return "RDN";   // FE_DOWNWARD
        case 3: return "RUP";   // FE_UPWARD
        default: return "UNKNOWN";
    }
}

// 加载测试向量（支持所有操作码）
bool load_test_vectors(const std::string& filename, std::vector<TestVector>& test_vectors) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "错误：无法打开测试向量文件 " << filename << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.length() < 29) continue; // 跳过无效行
        TestVector tv;
        try {
            tv.op_type = std::stoul(line.substr(0, 2), nullptr, 16);
            tv.op1 = std::stoul(line.substr(2, 8), nullptr, 16);
            tv.op2 = std::stoul(line.substr(10, 8), nullptr, 16);
            tv.frm = std::stoul(line.substr(18, 1), nullptr, 16);
            tv.expected_result = std::stoul(line.substr(19, 8), nullptr, 16);
            tv.expected_flags = std::stoul(line.substr(27, 2), nullptr, 16);
            test_vectors.push_back(tv);
        } catch (const std::exception& e) {
            std::cerr << "解析测试向量错误: " << line << std::endl;
            continue;
        }
    }
    file.close();
    std::cout << "加载了 " << test_vectors.size() << " 个测试向量" << std::endl;
    return true;
}

// 时钟tick函数
void tick(Vfpu_tb* tb, VerilatedVcdC* tfp) {
    tb->clk = 0;
    tb->eval();
    tfp->dump(Verilated::time());
    tb->clk = 1;
    tb->eval();
    tfp->dump(Verilated::time() + 1);
    Verilated::timeInc(2);
}

// 执行FPU操作
bool execute_fpu_op(Vfpu_tb* tb, VerilatedVcdC* tfp, uint8_t op_type, uint32_t op1, uint32_t op2, 
                    uint8_t frm, uint8_t freg_rd, uint32_t& result, uint32_t& int_result, 
                    uint8_t& exception_flags) {
    int timeout = 100; // 单周期操作，100周期足够

    // 设置操作数
    tb->freg_rs1 = 0; // 不使用寄存器
    tb->freg_rs2 = 0;
    tb->freg_rd = freg_rd;
    tb->fpu_op_valid = 1;
    tb->fpu_op_type = op_type;
    tb->fpu_op_round = frm;
    tb->operand1_fp = op1;
    tb->operand2_fp = op2;
    tb->operand4_int = 0; // 整数操作数未使用
    tb->downstream_valid = 1;
    tick(tb, tfp);

    tb->fpu_op_valid = 0;
    tick(tb, tfp);

    // 等待结果
    while (!tb->fpu_result_valid && timeout > 0) {
        tick(tb, tfp);
        timeout--;
    }

    if (timeout == 0) {
        std::cout << "错误：等待 fpu_result_valid 超时,op_type=0x" << std::hex << (int)op_type 
                  << ", op1=0x" << op1 << ", op2=0x" << op2 << std::dec << std::endl;
        return false;
    }

    // 捕获结果
    result = tb->fpu_result;
    int_result = tb->int_result;
    exception_flags = tb->exception_flags;

    // 写入寄存器（如果需要）
    if (freg_rd != 0) {
        tb->freg_write_data = tb->fpu_result;
        tb->freg_write_en = 1;
        tick(tb, tfp);
        tb->freg_write_en = 0;
        tick(tb, tfp);
    }

    return true;
}

// 主函数
int main(int argc, char **argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // 初始化测试平台
    Vfpu_tb* tb = new Vfpu_tb;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    tb->trace(tfp, 99);
    tfp->open("fpu_waveform.vcd");

    // 打开日志文件
    std::ofstream log_file("fpu_test_ops.log");

    // 复位
    tb->reset = 1;
    tick(tb, tfp);
    tb->reset = 0;
    tick(tb, tfp);

    // 加载测试向量
    std::vector<TestVector> test_vectors;
    if (!load_test_vectors("./fpu_test_vector.hex", test_vectors)) {
        tfp->close();
        delete tfp;
        delete tb;
        log_file.close();
        return 1;
    }

    // 执行测试
    int pass_count = 0, fail_count = 0;
    for (size_t i = 0; i < test_vectors.size(); i++) {
        const auto& tv = test_vectors[i];
        uint32_t result, int_result;
        uint8_t exception_flags;
	
        bool success = execute_fpu_op(tb, tfp, tv.op_type, tv.op1, tv.op2, tv.frm, 1, result, int_result, exception_flags);
        bool pass;
        if (tv.op_type == 0x0F || tv.op_type == 0x11 || tv.op_type == 0x10) {
    	 pass = success && (int_result == tv.expected_result && exception_flags == tv.expected_flags);
	} else {
    	 pass = success && (result == tv.expected_result && exception_flags == tv.expected_flags);
	}

        //bool pass = success && (result == tv.expected_result && exception_flags ==tv.expected_flags );
        //bool pass = success && (result == tv.expected_result );

        // 获取指令名称和舍入模式
        std::string instr_name = get_instruction_name(tv.op_type);
        std::string round_str = get_rounding_mode(tv.frm);

        // 输出结果
        std::cout << "测试 " << i << ": " << instr_name 
                  << (pass ? "\033[32m 通过\033[0m" : "\033[31m 失败\033[0m") 
                  << " (Op1: 0x" << std::hex << std::setw(8) << std::setfill('0') << tv.op1
                  << ", Op2: 0x" << std::setw(8) << std::setfill('0') << tv.op2
                  << ", 舍入: " << round_str 
                  << ", 结果: 0x" << std::setw(8) << std::setfill('0') << result
                  << ", 预期: 0x" << std::setw(8) << std::setfill('0') << tv.expected_result
                  << ", 异常: 0x" << std::setw(2) << std::setfill('0') << (int)exception_flags
                  << ", 预期异常: 0x" << std::setw(2) << std::setfill('0') << (int)tv.expected_flags 
                  << std::dec << ")" << std::endl;

        log_file << "测试 " << i << ": " << instr_name 
                 << (pass ? " 通过" : " 失败")
                 << " (Op1: 0x" << std::hex << std::setw(8) << std::setfill('0') << tv.op1
                 << ", Op2: 0x" << std::setw(8) << std::setfill('0') << tv.op2
                 << ", 舍入: " << round_str 
                 << ", 结果: 0x" << std::setw(8) << std::setfill('0') << result
                 << ", 预期: 0x" << std::setw(8) << std::setfill('0') << tv.expected_result
                 << ", 异常: 0x" << std::setw(2) << std::setfill('0') << (int)exception_flags
                 << ", 预期异常: 0x" << std::setw(2) << std::setfill('0') << (int)tv.expected_flags 
                 << std::dec << ")\n";

        if (pass) pass_count++;
        else fail_count++;
    }

    // 输出总结
    std::cout << "测试总结: " << pass_count << " 通过, " << fail_count << " 失败" << std::endl;
    log_file << "测试总结: " << pass_count << " 通过, " << fail_count << " 失败\n";

    // 清理
    tfp->close();
    delete tfp;
    delete tb;
    log_file.close();

    return fail_count > 0 ? 1 : 0;
}
