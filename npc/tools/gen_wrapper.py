import re
import sys

def generate_netlist_wrapper(rtl_file, in_netlist_file, out_netlist_file, wrapper_file, module_name):
    # 1. 从原始 RTL 中提取正确的端口方向 (input/output)
    directions = {}
    try:
        with open(rtl_file, 'r') as f:
            for line in f:
                line = line.strip()
                m = re.search(r'(input|output|inout)\s+(?:logic\s+|reg\s+)?(?:\[.*?\]\s+)?(\w+)', line)
                if m:
                    directions[m.group(2)] = m.group(1)
    except Exception as e:
        print(f"读取原 RTL 文件失败: {e}")
        return

    # 2. 读取原始网表文件 (只读)
    try:
        with open(in_netlist_file, 'r') as f:
            netlist_content = f.read()
    except Exception as e:
        print(f"读取原始网表文件失败: {e}")
        return

    # 查找网表的端口列表
    port_match = re.search(fr'\bmodule\s+{module_name}\s*\((.*?)\);', netlist_content, re.DOTALL)
    if not port_match:
        print(f"Error: 在网表中找不到 module {module_name}")
        return
    
    netlist_ports = [p.strip() for p in port_match.group(1).split(',')]

    # 将网表里的实体 module 改名，并写入新的输出文件
    new_netlist_content = re.sub(
        fr'\bmodule\s+{module_name}\b', 
        f'module {module_name}_netlist', 
        netlist_content
    )
    with open(out_netlist_file, 'w') as f:
        f.write(new_netlist_content)
    print(f"安全拷贝并重命名网表至: {out_netlist_file}")

    # 3. 对端口进行分组，找出哪些是单比特，哪些是向量
    port_groups = {}
    for p in netlist_ports:
        m = re.match(r'^(.*)_(\d+)_$', p)
        if m:
            base = m.group(1)
            idx = int(m.group(2))
            if base not in port_groups: port_groups[base] = []
            port_groups[base].append(idx)
        else:
            if p not in port_groups: port_groups[p] = []

    # 4. 生成 Wrapper 代码
    lines = [f"// Auto-generated Wrapper for Netlist Simulation", f"module {module_name} ("]
    port_decls = []
    inst_conns = []
    
    for base, indices in port_groups.items():
        dir_str = directions.get(base, "input")
        if not indices:
            port_decls.append(f"    {dir_str} {base}")
            inst_conns.append(f"    .{base}({base})")
        else:
            max_idx = max(indices)
            port_decls.append(f"    {dir_str} [{max_idx}:0] {base}")
            for i in sorted(indices):
                inst_conns.append(f"    .{base}_{i}_({base}[{i}])")
                
    lines.append(",\n".join(port_decls))
    lines.append(");")
    
    lines.append(f"\n  // 实例化底层真实的拷贝网表")
    lines.append(f"  {module_name}_netlist core_netlist (")
    lines.append(",\n".join(inst_conns))
    lines.append("  );")
    lines.append("\nendmodule\n")
    
    with open(wrapper_file, 'w') as f:
        f.write("\n".join(lines))
    print(f"Wrapper 已成功生成至: {wrapper_file}")

if __name__ == "__main__":
    if len(sys.argv) != 6:
        print("用法: python3 gen_wrapper.py <原RTL> <输入网表> <输出网表> <生成的Wrapper> <模块名>")
    else:
        generate_netlist_wrapper(sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5])