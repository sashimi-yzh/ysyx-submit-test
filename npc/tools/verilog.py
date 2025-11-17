import os
import re
import argparse

def process_files(folder_path):
    # 获取文件夹中的所有文件
    files = [f for f in os.listdir(folder_path) if os.path.isfile(os.path.join(folder_path, f))]
    
    for file_name in files:
        file_path = os.path.join(folder_path, file_name)
        
        # 尝试打开文件并进行处理
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                lines = file.readlines()
            
            # 标记是否在dpic区域内
            in_dpic_section = False
            modified = False
            
            # 处理每一行
            for i in range(len(lines)):
                # 检查是否是dpic区域的边界线
                if "//======================dpic========================//" in lines[i]:
                    in_dpic_section = not in_dpic_section
                    if in_dpic_section:  # 如果是开始边界
                        continue
                
                # 如果在dpic区域内，或者是以import "DPI-C"开头的行
                if (in_dpic_section or lines[i].strip().startswith('import "DPI-C"')) and not lines[i].strip().startswith('//'):
                    lines[i] = "//" + lines[i]
                    modified = True
            
            # 只有在文件被修改的情况下才写回
            if modified:
                with open(file_path, 'w', encoding='utf-8') as file:
                    file.writelines(lines)
                print(f"处理文件: {file_name}")
            
        except Exception as e:
            print(f"处理文件 {file_name} 时出错: {e}")

def remove_comments_and_empty_lines(content):
    # 删除单行注释
    content = re.sub(r'//.*', '', content)
    # 删除多行注释
    content = re.sub(r'/\*.*?\*/', '', content, flags=re.DOTALL)
    # 删除空行
    content = re.sub(r'\n\s*\n', '\n', content)
    return content

def process_verilog_file(file_path):
    print(f"Processing {file_path}...")
    
    # Read the file content
    with open(file_path, 'r') as f:
        content = f.read()
    
    # Find all module declarations and their positions
    module_pattern = re.compile(r'module\s+\w+\s*\([^;]*\);', re.DOTALL)
    module_matches = list(module_pattern.finditer(content))
    
    if not module_matches:
        print(f"No module declarations found in {file_path}, skipping...")
        return
    
    # Find all reg and wire declarations
    reg_wire_pattern = re.compile(r'^\s*(reg|wire|parameter)\s+[^;]*;', re.MULTILINE)
    reg_wire_matches = list(reg_wire_pattern.finditer(content))
    
    if not reg_wire_matches:
        print(f"No reg/wire declarations found in {file_path}, skipping...")
        return
    
    # Create a list of declarations to be moved
    declarations = []
    positions_to_remove = []
    
    for match in reg_wire_matches:
        declarations.append(match.group(0))
        positions_to_remove.append((match.start(), match.end()))
    
    # Sort positions in reverse order to remove from end to beginning
    positions_to_remove.sort(reverse=True)
    
    # Create a new content by removing the declarations
    new_content = content
    for start, end in positions_to_remove:
        new_content = new_content[:start] + new_content[end:]
    
    # Insert the declarations after each module declaration
    for module_match in module_matches:
        module_end = module_match.end()
        declarations_text = "\n    " + "\n    ".join(declarations) + "\n"
        new_content = new_content[:module_end] + declarations_text + new_content[module_end:]
    
    # Write the modified content back to the file
    with open(file_path, 'w') as f:
        f.write(new_content)
    
    print(f"Successfully reorganized declarations in {file_path}")

def traverse_directory(directory):
    """Traverse directory and process all Verilog files."""
    count = 0
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(('.v')):
                file_path = os.path.join(root, file)
                process_verilog_file(file_path)
                count += 1
    
    print(f"Processed {count} Verilog files in total.")

def merge_v_files(directory, output_file):
    with open(output_file, 'w') as outfile:
        for filename in os.listdir(directory):
            if filename.endswith('.v'):
                file_path = os.path.join(directory, filename)
                with open(file_path, 'r') as infile:
                    content = infile.read()
                    clean_content = remove_comments_and_empty_lines(content)
                    outfile.write(clean_content)
                    outfile.write('\n')  # Add a newline to separate files


# 使用示例
if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Verilog")
    parser.add_argument("NPC_HOME", type=str)
    args = parser.parse_args()

    vsrc_path = f"{args.NPC_HOME}/vsrc_no_dpic/"
    out_file = f"{args.NPC_HOME}/build/ysyx_24120011.v"
    process_files(vsrc_path)
    traverse_directory(vsrc_path)
    merge_v_files(vsrc_path, out_file)
    print("处理完成！")

