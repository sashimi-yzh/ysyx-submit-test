import json
import sys

def parse_config_file(config_file):
    config_dict = {}
    
    with open(config_file, 'r') as f:
        for line in f:
            # 跳过注释行
            if line.startswith('#') or not line.strip():
                continue
            # 查找等号分隔的键值对
            if '=' in line:
                key, value = line.strip().split('=', 1)
                config_dict[key.strip()] = value.strip()
    
    return config_dict

def config_to_json(config_file, output_json_file):
    config_dict = parse_config_file(config_file)
    with open(output_json_file, 'w') as json_file:
        json.dump(config_dict, json_file, indent=4)


if __name__ == "__main__":

    if(len(sys.argv)!=3):
        print("python config2json.py .config .config.json")
        sys.exit(-1)
    config_file = sys.argv[1]
    output_json_file = sys.argv[2]

    config_to_json(config_file, output_json_file)

