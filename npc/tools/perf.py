import os
import csv
import subprocess
from datetime import datetime

def extract_hz(file_path):
    with open(file_path, 'r') as file:
        # Skip the first few lines to reach the table
        for _ in range(4):  # Skip header and separator lines
            file.readline()
        
        # Read the first data row
        first_data_row = file.readline().strip()
        
        # Split the row by '|' and remove empty entries
        cells = [cell.strip() for cell in first_data_row.split('|') if cell.strip()]
        
        # Get the last cell value
        last_number = cells[-1]
        
        return float(last_number)
        
def extract_chip_area(file_path):
    # 打开文件并逐行读取
    with open(file_path, 'r') as file:
        for line in file:
            # 查找包含"Chip area for top module '\ysyx_24120011':"的行
            if "Chip area for module '\\ysyx_24120011':" in line:
                # 分割行并提取最后一个部分作为数字
                parts = line.strip().split(':')
                if len(parts) >= 2:
                    number_str = parts[-1].strip()
                    # 转换为浮点数并返回
                    return float(number_str)
    
    # 如果没找到匹配的行，返回None
    return None
file_path = "/home/plutoisy/yosys-sta/result/ysyx_24120011-100MHz/ysyx_24120011.rpt"
hz = extract_hz(file_path)
file_path = "/home/plutoisy/yosys-sta/result/ysyx_24120011-100MHz/synth_stat.txt"
area = extract_chip_area(file_path)

# Read data from perf.txt
perf_data = {}
try:
    with open('/home/plutoisy/ysyx-workbench/npc/log/perf.txt', 'r') as file:
        for line in file:
            if ':' in line:
                key, value = line.strip().split(':', 1)
                perf_data[key.strip()] = value.strip()
except FileNotFoundError:
    print("perf.txt file not found!")
    exit(1)

# Get Git commit information
try:
    git_commit = subprocess.check_output(['git', 'log', '-1']).decode('utf-8').strip()
    git_hash = git_commit.split()[1]
    git_message = git_commit.split()[-1]
except Exception as e:
    print(f"Error getting Git commit info: {e}")
    git_hash = "unknown"
    git_message = "unknown"

# Print all the variables
print("\n===== Performance Data =====")
print(f"Area: {area}")
print(f"Frequency: {hz} MHz")
for key, value in perf_data.items():
    print(f"{key}: {value}")

print("\n===== Git Information =====")
print(f"Commit Hash: {git_hash}")
print(f"Commit Message: {git_message}")
print("===========================\n")

# Ask user if they want to save to CSV
user_choice = input("Do you want to record this data in perf.csv? (y/n): ").lower()

if user_choice == 'y' or user_choice == 'yes':
    # Check if perf.csv exists and create with headers if not
    file_exists = os.path.isfile('/home/plutoisy/ysyx-workbench/npc/perf.csv')
    
    with open('/home/plutoisy/ysyx-workbench/npc/perf.csv', 'a', newline='') as csvfile:
        fieldnames = ['timestamp', 'area', 'frequency', 'git_hash', 'git_message'] + list(perf_data.keys())
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        
        if not file_exists:
            writer.writeheader()
        
        # Prepare row data
        row_data = {
            'timestamp': datetime.now().strftime('%Y-%m-%d %H:%M:%S'),
            'area': area,
            'frequency': hz,
            'git_hash': git_hash,
            'git_message': git_message
        }
        # Add perf data to row
        row_data.update(perf_data)
        
        # Write to CSV
        writer.writerow(row_data)
        print("Data successfully recorded in perf.csv")
else:
    print("Data not recorded")

