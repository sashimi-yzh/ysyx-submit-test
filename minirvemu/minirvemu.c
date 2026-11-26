/*
 * minirvemu - 简化的 RISC-V 32位模拟器
 * 实现 RV32E 指令集的子集
 */

#include <am.h>
#include <klib-macros.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

/* 内存配置 */
#define MEM_SIZE (16 * 1024 * 1024)  // 16MB 内存

/* VGA 配置 */
#define VGA_BASE 0x20000000           // VGA 显存基地址
#define VGA_SIZE (256 * 256 * 4)      // 256x256 像素，每像素 4 字节
#define VGA_WIDTH 256
#define VGA_HEIGHT 256 

/* 错误码 */
typedef enum {
    ERR_NONE = 0,
    ERR_ILLEGAL_INSTRUCTION,
    ERR_MEMORY_OUT_OF_BOUNDS,
    ERR_FILE_NOT_FOUND,
    ERR_EBREAK_GOOD_TRAP,      // ebreak 正常结束 (a0 = 0)
    ERR_EBREAK_BAD_TRAP        // ebreak 错误结束 (a0 != 0)
} ErrorCode;

/* CPU 状态结构 */
typedef struct {
    uint32_t pc;           // 程序计数器
    uint32_t gpr[16];      // 16个通用寄存器 (RV32E)
} CPU;

/* 指令结构体 */
typedef struct {
    uint32_t opcode;   // bits [6:0]
    uint32_t rd;       // bits [11:7]
    uint32_t funct3;   // bits [14:12]
    uint32_t rs1;      // bits [19:15]
    uint32_t rs2;      // bits [24:20]
    uint32_t funct7;   // bits [31:25] (R-type)
    int32_t imm;       // 符号扩展的立即数 (I-type, S-type)
    uint32_t uimm;     // U-type 立即数
} Instruction;

/* 全局内存 */
uint8_t memory[MEM_SIZE];

/* VGA 显存缓冲区 */
uint32_t vga_buffer[VGA_WIDTH * VGA_HEIGHT];

void cpu_init(CPU *cpu) {
    cpu->pc = 0;
    for (int i = 0; i < 16; i++) {
        cpu->gpr[i] = 0;
    }
}

/* 符号扩展 12 位立即数到 32 位 */
int32_t sign_extend_12bit(uint32_t imm) {
    /* 提取 12 位立即数 */
    uint32_t imm_12bit = imm & 0xFFF;
    
    /* 将 12 位值放到 32 位整数的高位，然后算术右移 */
    /* 这样可以自动进行符号扩展 */
    int32_t extended = (int32_t)(imm_12bit << 20) >> 20;
    
    return extended;
}

int32_t extract_s_imm(uint32_t inst_word) {
    uint32_t imm_11_5 = (inst_word >> 25) & 0x7F;  // bits [31:25]
    uint32_t imm_4_0 = (inst_word >> 7) & 0x1F;    // bits [11:7]
    uint32_t imm_12bit = (imm_11_5 << 5) | imm_4_0;
    return sign_extend_12bit(imm_12bit);
}

uint32_t extract_u_imm(uint32_t inst_word) {
    return inst_word & 0xFFFFF000;  // bits [31:12]，低12位为0
}

void decode_instruction(uint32_t inst_word, Instruction *inst) {
    /* 提取通用字段 */
    /* 提取 opcode (bits [6:0]) */
    inst->opcode = inst_word & 0x7F;
    
    /* 提取 rd (bits [11:7]) */
    inst->rd = (inst_word >> 7) & 0x1F;
    
    /* 提取 funct3 (bits [14:12]) */
    inst->funct3 = (inst_word >> 12) & 0x7;
    
    /* 提取 rs1 (bits [19:15]) */
    inst->rs1 = (inst_word >> 15) & 0x1F;
    
    /* 提取 rs2 (bits [24:20]) */
    inst->rs2 = (inst_word >> 20) & 0x1F;
    
    /* 提取 funct7 (bits [31:25]) - R-type */
    inst->funct7 = (inst_word >> 25) & 0x7F;
    
    /* 根据 opcode 判断指令类型并提取相应立即数 */
    switch (inst->opcode) {
        case 0x37:  // LUI (U-type)
        case 0x17:  // AUIPC (U-type)
            inst->uimm = extract_u_imm(inst_word);
            inst->imm = 0;
            break;
            
        case 0x23:  // Store 指令 (S-type): SW, SB
            inst->imm = extract_s_imm(inst_word);
            inst->uimm = 0;
            break;
            
        case 0x33:  // R-type 算术指令: ADD, SUB, etc.
            inst->imm = 0;
            inst->uimm = 0;
            break;
            
        default:    // I-type 指令: ADDI, JALR, LW, LBU, etc.
            {
                uint32_t imm_raw = inst_word >> 20;
                inst->imm = sign_extend_12bit(imm_raw);
                inst->uimm = 0;
            }
            break;
    }
}

uint8_t mem_read_byte(uint32_t addr, ErrorCode *err) {
    if (addr >= MEM_SIZE) {
        if (err) *err = ERR_MEMORY_OUT_OF_BOUNDS;
        fprintf(stderr, "Error: Memory read out of bounds at addr=0x%08x\n", addr);
        return 0;
    }
    if (err) *err = ERR_NONE;
    return memory[addr];
}

ErrorCode mem_write_byte(uint32_t addr, uint8_t value) {
    if (addr >= MEM_SIZE) {
        fprintf(stderr, "Error: Memory write out of bounds at addr=0x%08x\n", addr);
        return ERR_MEMORY_OUT_OF_BOUNDS;
    }
    memory[addr] = value;
    return ERR_NONE;
}

uint32_t mem_read_word(uint32_t addr, ErrorCode *err) {
    /* 检查地址对齐 */
    if (addr & 0x3) {
        if (err) *err = ERR_MEMORY_OUT_OF_BOUNDS;
        fprintf(stderr, "Error: Unaligned memory read at addr=0x%08x\n", addr);
        return 0;
    }
    
    /* 检查地址边界 */
    if (addr + 3 >= MEM_SIZE) {
        if (err) *err = ERR_MEMORY_OUT_OF_BOUNDS;
        fprintf(stderr, "Error: Memory read out of bounds at addr=0x%08x\n", addr);
        return 0;
    }
    
    if (err) *err = ERR_NONE;
    
    /* 小端序读取：低字节在低地址 */
    uint32_t value = memory[addr] |
                     (memory[addr + 1] << 8) |
                     (memory[addr + 2] << 16) |
                     (memory[addr + 3] << 24);
    return value;
}

ErrorCode mem_write_word(uint32_t addr, uint32_t value) {
    /* 检查地址对齐 */
    if (addr & 0x3) {
        fprintf(stderr, "Error: Unaligned memory write at addr=0x%08x\n", addr);
        return ERR_MEMORY_OUT_OF_BOUNDS;
    }
    
    /* 检查地址边界 */
    if (addr + 3 >= MEM_SIZE) {
        fprintf(stderr, "Error: Memory write out of bounds at addr=0x%08x\n", addr);
        return ERR_MEMORY_OUT_OF_BOUNDS;
    }
    
    /* 小端序写入：低字节在低地址 */
    memory[addr] = value & 0xFF;
    memory[addr + 1] = (value >> 8) & 0xFF;
    memory[addr + 2] = (value >> 16) & 0xFF;
    memory[addr + 3] = (value >> 24) & 0xFF;
    
    return ERR_NONE;
}

void execute_addi(CPU *cpu, Instruction *inst) {
    /* 计算结果: gpr[rs1] + 立即数 */
    uint32_t result = cpu->gpr[inst->rs1] + inst->imm;
    
    /* 如果目标寄存器不是 x0,则写入结果 */
    /* x0 寄存器硬连线为 0,写入无效 */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = result;
    }
    
    /* PC 递增 4 字节（一条指令的长度） */
    cpu->pc += 4;
}

void execute_jalr(CPU *cpu, Instruction *inst) {
    /* 计算目标地址: (gpr[rs1] + imm) & ~1 */
    /* 最低位清零确保地址对齐 */
    uint32_t target = (cpu->gpr[inst->rs1] + inst->imm) & ~1;
    
    /* 如果目标寄存器不是 x0，保存返回地址 (PC + 4) */
    /* x0 寄存器硬连线为 0，写入无效 */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = cpu->pc + 4;
    }
    
    /* 跳转到目标地址 */
    cpu->pc = target;
}

void execute_add(CPU *cpu, Instruction *inst) {
    /* 计算结果: gpr[rs1] + gpr[rs2] */
    uint32_t result = cpu->gpr[inst->rs1] + cpu->gpr[inst->rs2];
    
    /* 如果目标寄存器不是 x0，则写入结果 */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = result;
    }
    
    /* PC 递增 4 字节 */
    cpu->pc += 4;
}

void execute_lui(CPU *cpu, Instruction *inst) {
    /* 如果目标寄存器不是 x0，则写入 U-type 立即数 */
    /* uimm 已经是正确格式（高20位有值，低12位为0） */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = inst->uimm;
    }
    
    /* PC 递增 4 字节 */
    cpu->pc += 4;
}

ErrorCode execute_lw(CPU *cpu, Instruction *inst) {
    /* 计算地址 addr = gpr[rs1] + imm */
    uint32_t addr = cpu->gpr[inst->rs1] + inst->imm;
    
    /* 从内存读取字 value = mem_read_word(addr) */
    ErrorCode err = ERR_NONE;
    uint32_t value = mem_read_word(addr, &err);
    
    /* 处理内存访问错误 */
    if (err != ERR_NONE) {
        return err;
    }
    
    /* 如果 rd != 0，写入 gpr[rd] = value */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = value;
    }
    
    /* PC 递增 4 */
    cpu->pc += 4;
    
    return ERR_NONE;
}

ErrorCode execute_lbu(CPU *cpu, Instruction *inst) {
    /* 计算地址 addr = gpr[rs1] + imm */
    uint32_t addr = cpu->gpr[inst->rs1] + inst->imm;
    
    /* 从内存读取字节 byte_value = mem_read_byte(addr) */
    ErrorCode err = ERR_NONE;
    uint8_t byte_value = mem_read_byte(addr, &err);
    
    /* 处理内存访问错误 */
    if (err != ERR_NONE) {
        return err;
    }
    
    /* 零扩展到32位 value = (uint32_t)byte_value */
    uint32_t value = (uint32_t)byte_value;
    
    /* 如果 rd != 0，写入 gpr[rd] = value */
    if (inst->rd != 0) {
        cpu->gpr[inst->rd] = value;
    }
    
    /* PC 递增 4 */
    cpu->pc += 4;
    
    return ERR_NONE;
}

ErrorCode execute_sw(CPU *cpu, Instruction *inst) {
    /* 计算地址 addr = gpr[rs1] + imm */
    uint32_t addr = cpu->gpr[inst->rs1] + inst->imm;
    
    /* 获取要写入的值 value = gpr[rs2] */
    uint32_t value = cpu->gpr[inst->rs2];
    
    /* 检查是否写入 VGA 显存区域 (内存映射 I/O) */
    if (addr >= VGA_BASE && addr < VGA_BASE + VGA_SIZE) {
        /* 检查地址是否 4 字节对齐 */
        if (addr & 0x3) {
            fprintf(stderr, "Warning: Unaligned VGA write at addr=0x%08x\n", addr);
            cpu->pc += 4;
            return ERR_NONE;
        }
        
        /* 计算在 VGA 缓冲区中的偏移 */
        uint32_t offset = (addr - VGA_BASE) / 4;  // 字节偏移转换为字偏移
        
        /* 从地址计算 X、Y 坐标 */
        /* 地址 0x20000000 对应 (0, 0) */
        /* 地址 0x20000004 对应 (1, 0) */
        /* 地址 0x20000400 对应 (0, 1) */
        uint32_t pixel_index = offset;
        uint32_t x = pixel_index % VGA_WIDTH;
        uint32_t y = pixel_index / VGA_WIDTH;
        
        if (y < VGA_HEIGHT) {
            /* 写入 VGA 缓冲区 */
            vga_buffer[y * VGA_WIDTH + x] = value;
        }
        
        /* PC 递增 4 */
        cpu->pc += 4;
        return ERR_NONE;
    }
    
    /* 写入普通内存 mem_write_word(addr, value) */
    ErrorCode err = mem_write_word(addr, value);
    
    /* 处理内存访问错误 */
    if (err != ERR_NONE) {
        return err;
    }
    
    /* PC 递增 4 */
    cpu->pc += 4;
    
    return ERR_NONE;
}

ErrorCode execute_sb(CPU *cpu, Instruction *inst) {
    /* 计算地址 addr = gpr[rs1] + imm */
    uint32_t addr = cpu->gpr[inst->rs1] + inst->imm;
    
    /* 获取要写入的字节 byte_value = gpr[rs2] & 0xFF */
    uint8_t byte_value = cpu->gpr[inst->rs2] & 0xFF;
    
    /* 检查是否写入 VGA 显存区域 (内存映射 I/O) */
    if (addr >= VGA_BASE && addr < VGA_BASE + VGA_SIZE) {
        /* VGA 区域的字节写入 */
        /* 计算像素索引和字节偏移 */
        uint32_t offset = addr - VGA_BASE;
        uint32_t pixel_index = offset / 4;
        uint32_t byte_offset = offset % 4;
        
        uint32_t x = pixel_index % VGA_WIDTH;
        uint32_t y = pixel_index / VGA_WIDTH;
        
        if (y < VGA_HEIGHT) {
            /* 读取当前像素值，修改对应字节，然后写回 */
            uint32_t pixel = vga_buffer[y * VGA_WIDTH + x];
            uint32_t shift = byte_offset * 8;
            uint32_t mask = ~(0xFF << shift);
            pixel = (pixel & mask) | (byte_value << shift);
            vga_buffer[y * VGA_WIDTH + x] = pixel;
        }
        
        /* PC 递增 4 */
        cpu->pc += 4;
        return ERR_NONE;
    }
    
    /* 写入普通内存 mem_write_byte(addr, byte_value) */
    ErrorCode err = mem_write_byte(addr, byte_value);
    
    /* 处理内存访问错误 */
    if (err != ERR_NONE) {
        return err;
    }
    
    /* PC 递增 4 */
    cpu->pc += 4;
    
    return ERR_NONE;
}

ErrorCode execute_ebreak(CPU *cpu) {
    /* 检查 a0 寄存器 (x10) 的值 */
    uint32_t a0 = cpu->gpr[10];
    
    if (a0 == 0) {
        /* 程序正常结束 */
        printf("\n*** HIT GOOD TRAP ***\n");
        return ERR_EBREAK_GOOD_TRAP;
    } else {
        /* 程序错误结束 */
        printf("\n*** HIT BAD TRAP (a0 = %u) ***\n", a0);
        return ERR_EBREAK_BAD_TRAP;
    }
}

uint32_t fetch_instruction(CPU *cpu, ErrorCode *err) {
    /* 使用 mem_read_word 从 PC 指向的地址读取指令 */
    return mem_read_word(cpu->pc, err);
}

ErrorCode dispatch_instruction(CPU *cpu, Instruction *inst) {
    /* 根据 opcode 和 funct3 识别指令 */
    switch (inst->opcode) {
        case 0x13:  /* I-type 算术指令 */
            if (inst->funct3 == 0x0) {
                /* ADDI 指令 */
                execute_addi(cpu, inst);
                return ERR_NONE;
            }
            break;
            
        case 0x67:  /* JALR 指令 */
            if (inst->funct3 == 0x0) {
                /* JALR 指令 */
                execute_jalr(cpu, inst);
                return ERR_NONE;
            }
            break;
            
        case 0x33:  /* R-type 算术指令 */
            if (inst->funct3 == 0x0 && inst->funct7 == 0x00) {
                /* ADD 指令 */
                execute_add(cpu, inst);
                return ERR_NONE;
            }
            break;
            
        case 0x37:  /* LUI 指令 */
            execute_lui(cpu, inst);
            return ERR_NONE;
            
        case 0x03:  /* Load 指令 */
            if (inst->funct3 == 0x2) {  /* LW */
                return execute_lw(cpu, inst);
            }
            if (inst->funct3 == 0x4) {  /* LBU */
                return execute_lbu(cpu, inst);
            }
            break;
            
        case 0x23:  /* Store 指令 */
            if (inst->funct3 == 0x2) {  /* SW */
                return execute_sw(cpu, inst);
            }
            if (inst->funct3 == 0x0) {  /* SB */
                return execute_sb(cpu, inst);
            }
            break;
            
        case 0x73:  /* 系统指令 */
            if (inst->funct3 == 0x0 && inst->imm == 1) {  /* EBREAK */
                return execute_ebreak(cpu);
            }
            break;
    }
    
    /* 不支持的指令 */
    fprintf(stderr, "Error: Illegal instruction at PC=0x%08x, opcode=0x%02x, funct3=0x%x\n",
            cpu->pc, inst->opcode, inst->funct3);
    return ERR_ILLEGAL_INSTRUCTION;
}

ErrorCode run_simulator(CPU *cpu, int max_cycles) {
    ErrorCode err = ERR_NONE;
    
    /* 取指-译码-执行循环 */
    for (int cycle = 0; cycle < max_cycles; cycle++) {
        /* 1. 取指：从 memory[PC] 读取指令 */
        uint32_t inst_word = fetch_instruction(cpu, &err);
        if (err != ERR_NONE) {
            /* 取指失败（如内存越界） */
            return err;
        }
        
        /* 2. 译码：解析指令格式 */
        Instruction inst;
        decode_instruction(inst_word, &inst);
        
        /* 3. 执行：分发并执行指令 */
        err = dispatch_instruction(cpu, &inst);
        if (err != ERR_NONE) {
            /* 执行失败（如非法指令） */
            return err;
        }
        
        /* 检查是否需要停止（可以通过特殊指令或条件） */
        /* 目前简单地执行到 max_cycles */
    }
    
    return ERR_NONE;
}

ErrorCode load_program(const char *filename) {
    /* 打开二进制文件 */
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file '%s'\n", filename);
        return ERR_FILE_NOT_FOUND;
    }
    
    /* 读取文件内容到内存，从地址 0 开始 */
    size_t bytes_read = fread(memory, 1, MEM_SIZE, file);
    
    /* 关闭文件 */
    fclose(file);
    
    /* 打印加载信息 */
    printf("Loaded %lu bytes from '%s' into memory\n", (unsigned long)bytes_read, filename);
    
    return ERR_NONE;
}

ErrorCode write_ebreak_at(uint32_t addr) {
    /* EBREAK 指令编码 */
    uint32_t ebreak_inst = 0x00100073;
    
    /* 检查地址对齐 */
    if (addr & 0x3) {
        fprintf(stderr, "Error: EBREAK address not aligned: 0x%08x\n", addr);
        return ERR_MEMORY_OUT_OF_BOUNDS;
    }
    
    /* 检查地址边界 */
    if (addr + 3 >= MEM_SIZE) {
        fprintf(stderr, "Error: EBREAK address out of bounds: 0x%08x\n", addr);
        return ERR_MEMORY_OUT_OF_BOUNDS;
    }
    
    /* 以小端序写入 EBREAK 指令 */
    memory[addr] = ebreak_inst & 0xFF;
    memory[addr + 1] = (ebreak_inst >> 8) & 0xFF;
    memory[addr + 2] = (ebreak_inst >> 16) & 0xFF;
    memory[addr + 3] = (ebreak_inst >> 24) & 0xFF;
    
    printf("Wrote EBREAK instruction at address 0x%08x\n", addr);
    
    return ERR_NONE;
}

void print_registers(CPU *cpu) {
    printf("\n=== Register State ===\n");
    printf("PC:  0x%08x\n", cpu->pc);
    printf("\nGeneral Purpose Registers:\n");
    
    /* 打印所有 16 个通用寄存器 */
    for (int i = 0; i < 16; i++) {
        /* 每行打印 4 个寄存器 */
        printf("x%-2d: 0x%08x", i, cpu->gpr[i]);
        
        /* 每 4 个寄存器换行 */
        if ((i + 1) % 4 == 0) {
            printf("\n");
        } else {
            printf("  ");
        }
    }
    printf("======================\n");
}

void display_vga() {
    printf("\nDisplaying VGA buffer to screen (256x256)...\n");
    
    /* 使用 AM 的 GPU API 绘制整个屏幕 */
    io_write(AM_GPU_FBDRAW, 0, 0, vga_buffer, VGA_WIDTH, VGA_HEIGHT, true);
    
    printf("VGA display complete. Press ESC to exit.\n");
    
    /* 进入死循环，防止程序马上退出 */
    while (1) {
        /* 检查是否有 ESC 键按下 */
        AM_INPUT_KEYBRD_T ev = io_read(AM_INPUT_KEYBRD);
        if (ev.keycode == AM_KEY_ESCAPE && ev.keydown) {
            printf("\nESC key pressed, exiting...\n");
            break;
        }
    }
}

int main() {
    /* 初始化 CPU */
    CPU cpu;
    cpu_init(&cpu);
    
    /* 初始化 VGA 缓冲区为黑色 */
    memset(vga_buffer, 0, sizeof(vga_buffer));
    
    printf("minirvemu - RISC-V 32-bit Emulator with VGA Support\n");
    printf("====================================================\n\n");
    
    /* 加载 vga.bin 程序 */
    const char *program_file = "/home/zhangshenlu/ysyx/am-kernels/tests/am-tests/src/tests/vga.bin";
    
    printf("Loading program from '%s'...\n", program_file);
    ErrorCode err = load_program(program_file);
    if (err != ERR_NONE) {
        fprintf(stderr, "Failed to load program from '%s'\n", program_file);
        fprintf(stderr, "Falling back to simple test program...\n\n");
    }
    
    /* 运行模拟器 */
    printf("\nRunning simulator...\n");
    printf("This may take a while (vga.bin needs ~628000 cycles)...\n");
    const int MAX_CYCLES = 100000000;  /* 增加到 1 亿周期以支持 VGA 程序 */
    err = run_simulator(&cpu, MAX_CYCLES);
    
    /* 检查执行结果 */
    if (err == ERR_EBREAK_GOOD_TRAP) {
        printf("\nSimulator stopped: Program completed successfully\n");
    } else if (err == ERR_EBREAK_BAD_TRAP) {
        printf("\nSimulator stopped: Program completed with errors\n");
    } else if (err != ERR_NONE) {
        fprintf(stderr, "\nSimulator stopped with error code: %d\n", err);
    } else {
        printf("\nSimulator completed successfully\n");
    }
    
    /* 显示最终寄存器状态 */
    print_registers(&cpu);
    
    /* 显示 VGA 缓冲区内容 */
    display_vga();
}
