def parse_line(line):
    """解析每一行，返回 pc、inst 和实际是否跳转"""
    parts = line.strip().split(',')
    pc = int(parts[0], 16)
    inst = int(parts[1], 16)
    actual = parts[2].strip().lower() == "taken"
    return pc, inst, actual

def get_branch_target(pc, inst):
    """根据 B-type 指令计算跳转目标地址"""
    # 提取立即数字段（RV32 B-type）
    imm12 = (inst >> 31) & 0x1
    imm10_5 = (inst >> 25) & 0x3F
    imm4_1 = (inst >> 8) & 0xF
    imm11 = (inst >> 7) & 0x1

    imm = (imm12 << 12) | (imm11 << 11) | (imm10_5 << 5) | (imm4_1 << 1)

    # 符号扩展
    if imm & (1 << 12):
        imm |= ~((1 << 13) - 1)

    target = pc + imm
    return target

def predict(pc, inst, strategy):
    """根据策略进行预测"""
    if strategy == "always_taken":
        return True
    elif strategy == "never_taken":
        return False
    elif strategy == "btfn":
        target = get_branch_target(pc, inst)
        return target < pc
    else:
        raise ValueError(f"Unknown strategy: {strategy}")

def evaluate(filename, strategy):
    total = 0
    correct = 0
    with open(filename, 'r') as f:
        for line in f:
            if not line.strip():
                continue
            pc, inst, actual = parse_line(line)
            prediction = predict(pc, inst, strategy)
            if prediction == actual:
                correct += 1
            total += 1
    accuracy = correct / total * 100 if total else 0
    print(f"Strategy: {strategy:<13} Accuracy: {accuracy:.2f}% ({correct}/{total})")

if __name__ == "__main__":
    filename = "btrace.txt"
    strategies = ["always_taken", "never_taken", "btfn"]
    for strategy in strategies:
        evaluate(filename, strategy)

