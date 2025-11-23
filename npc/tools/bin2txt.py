#!/usr/bin/env python3

import sys

def bin_to_hex_txt(bin_file, txt_file, bytes_per_line=16):
    """
    Convert a binary file to a text file with hex representation
    Format: 
    @00000000
    XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX
    XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX XX
    ...
    """
    with open(bin_file, 'rb') as f_in:
        bin_data = f_in.read()
    
    with open(txt_file, 'w') as f_out:
        # Write the initial address
        f_out.write("@00000000\n")
        
        # Write hex data
        for i in range(0, len(bin_data), bytes_per_line):
            # Get bytes for this line
            line_bytes = bin_data[i:i+bytes_per_line]
            
            # Convert to hex representation
            hex_str = ' '.join(f"{b:02x}" for b in line_bytes)
            
            # Write line
            f_out.write(f"{hex_str}\n")

if __name__ == "__main__":
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} input.bin output.txt [bytes_per_line]")
        sys.exit(1)
    
    bin_file = sys.argv[1]
    txt_file = sys.argv[2]
    bytes_per_line = 16  # Default
    
    if len(sys.argv) > 3:
        bytes_per_line = int(sys.argv[3])
    
    bin_to_hex_txt(bin_file, txt_file, bytes_per_line)
    print(f"Converted {bin_file} to {txt_file}")
