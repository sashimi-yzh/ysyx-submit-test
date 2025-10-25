import sys
bin_path = sys.argv[1]
print(f"Converting binary file {bin_path} to hex format...")
hex_path = "build/program.hex"
with open(bin_path, 'rb') as bin_file:
	with open(hex_path, 'w') as hex_file:
		while True:
			byte1 = bin_file.read(1)
			byte2 = bin_file.read(1)
			byte3 = bin_file.read(1)
			byte4 = bin_file.read(1)
			if not byte4:
				break
			byte = byte4 + byte3 + byte2 + byte1
			hex_value = byte.hex()
			hex_file.write(hex_value + '\n')
