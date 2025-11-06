#ifndef BRANCH_H_
#define BRANCH_H_
#include <string>
#include <iostream>
#include <cstdarg>
#include <cmath>
#include <cstring>
using std::string;

typedef struct{
    int tag;
    uint32_t target;
}BTB;

class BranchPredictor {
    private:
        FILE *logfp;
        uint64_t count = 0;
        uint64_t correctCnt = 0;
        uint64_t mispredCnt = 0;

        int set;
        int block_size = 4;         // pc多少bit对齐
        BTB* btb; //完全映射

    protected:
        bool parse_inst(uint32_t inst, uint32_t pc, string* op, uint32_t* dest);
        int M() { return log2(set);}        // set = 2^M，表示BTB有多少个entry
        int N() { return log2(block_size);} // block_size = 2^N，表示忽略 pc 低N位
        int getIndex(uint32_t pc);
        int getTag(uint32_t pc);

    public:
        BranchPredictor(const char* logFile, int set):set(set) {
            logfp = fopen(logFile, "w");
            if (!logfp) {
                std::cerr << "Error opening log file: " << logFile << std::endl;
                exit(1);
            }
            btb = new BTB[set];
        }
        virtual ~BranchPredictor() {
            if (logfp){
                fclose(logfp);
            }
            delete[] btb;
        }
        virtual bool predict(uint32_t pc, uint32_t inst) = 0;  // 纯虚函数，必须在派生类中实现
        // 检查预测结果是否正确，并更新统计信息
        inline bool check(bool predict, bool actual) {
            count++;
            if (predict == actual) {
                correctCnt++;
                return true;
            } else {
                mispredCnt++;
                return false;
            }
        }
        virtual void statistic();
        void log(const char* format, ...) {
            if (logfp) {
                va_list args;
                va_start(args, format);         // 初始化 va_list
                vfprintf(logfp, format, args);  // 使用 vfprintf 写入日志文件
                va_end(args);                   // 清理 va_list
                fflush(logfp);                  // 确保数据立即写入文件
            }
        }

        bool findBTB(uint32_t pc);
        void updateBTB(uint32_t pc, uint32_t target);
        
};

class BTFNPredictor : public BranchPredictor {
    public:
        BTFNPredictor(const char* logFile, int set) : BranchPredictor(logFile,set) {}
        
        bool predict(uint32_t pc, uint32_t inst) override;

        void statistic() override{
            log("========== BTFN Predictor Statistic ==========\n");
            printf("========== BTFN Predictor Statistic ==========\n");
            BranchPredictor::statistic();
        }

        ~BTFNPredictor(){
            statistic();   
        }
};

class AlwaysTakenPredictor : public BranchPredictor {
    public:
        AlwaysTakenPredictor(const char* logFile, int set) : BranchPredictor(logFile,set) {}
        
        bool predict(uint32_t pc, uint32_t inst) override {
            return true; // 总是预测为跳转
        }

        void statistic() override{
            log("========== Always Taken Predictor Statistic ==========\n");
            printf("========== Always Taken Predictor Statistic ==========\n");
            BranchPredictor::statistic();
        }

        ~AlwaysTakenPredictor(){
            statistic();   
        }
};

class AlwaysNotTakenPredictor : public BranchPredictor {
    public:
        AlwaysNotTakenPredictor(const char* logFile, int set) : BranchPredictor(logFile,set) {}
        
        bool predict(uint32_t pc, uint32_t inst) override {
            return false; // 总是预测为跳转
        }

        void statistic() override{
            log("========== Always Not Taken Predictor Statistic ==========\n");
            printf("========== Always Not Taken Predictor Statistic ==========\n");
            BranchPredictor::statistic();
        }

        ~AlwaysNotTakenPredictor(){
            statistic();   
        }
};

#endif // BRANCH_H_