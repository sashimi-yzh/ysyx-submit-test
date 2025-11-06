import re

def extract_read_addresses(input_file, output_file):
    """
    从输入文件提取read地址，写入输出文件
    """
    # 正则表达式匹配"This has read addr :"后面的十六进制地址
    pattern = re.compile(r"This has read addr : 0x([0-9a-fA-F]+),")
    
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            match = pattern.search(line)
            if match:
                # 提取地址并转换为小写（可选）
                address = match.group(1).lower()
                outfile.write(address + '\n')

if __name__ == "__main__":
    input_filename = "/home/lq/ysyx-workbench/npc/mtrace.log"    # 替换为你的输入文件名
    output_filename = "/home/lq/ysyx-workbench/cachesim/build/mtrace.log"  # 输出文件名
    
    extract_read_addresses(input_filename, output_filename)
    print(f"已提取地址数据到 {output_filename}")