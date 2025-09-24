import re
import os
import sys
import tempfile
from pathlib import Path

def process_file(file_path):
    pattern = re.compile(
        r'^(\s*)(wire|reg)\b'
        r'(\s+(?:\[.*?\])?\s*\S+)'
        r'(\s*);'
        r'(.*)$', 
        flags=re.IGNORECASE
    )

    temp_fd, temp_path = tempfile.mkstemp()
    modified = False

    try:
        with open(file_path, 'r') as src, os.fdopen(temp_fd, 'w') as dst:
            for line in src:
                if re.match(r'\s*\/\/', line) or '/*' in line:
                    dst.write(line)
                    continue

                if '/*verilator public*/' not in line:
                    match = pattern.match(line)
                    if match:
                        indent = match.group(1)
                        type_decl = match.group(2)
                        signal = match.group(3).rstrip()
                        semicolon = match.group(4)
                        tail = match.group(5)
                        
                        new_line = (
                            f"{indent}{type_decl}{signal} "
                            f"/*verilator public*/{semicolon}{tail};\n"
                        )
                        dst.write(new_line)
                        modified = True
                        continue
                
                dst.write(line)

        if modified:
            os.replace(temp_path, file_path)
            print(f"Updated: {file_path}")
        else:
            os.remove(temp_path)
            print(f"No changes: {file_path}")

    except Exception as e:
        os.remove(temp_path)
        print(f"Error processing {file_path}: {e}")

def process_paths(paths):
    for path in paths:
        path = Path(path)
        if path.is_file() and path.suffix.lower() in ('.v', '.sv'):
            process_file(str(path))
        elif path.is_dir():
            for root, _, files in os.walk(str(path)):
                for file in files:
                    if file.lower().endswith(('.v', '.sv')):
                        process_file(os.path.join(root, file))
        else:
            print(f"Skipped (not Verilog file/dir): {path}")

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python add_verilator_public.py [file1.v] [dir1/] [*.v] ...")
        sys.exit(1)

    process_paths(sys.argv[1:])