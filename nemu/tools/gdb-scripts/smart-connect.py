import gdb
import time
import os

def force_to_str(obj):
    if isinstance(obj, (list, tuple)):
        return "".join([force_to_str(x) for x in obj])
    
    s = str(obj)
    for char in ['[', ']', "'", '"']:
        s = s.replace(char, "")
    return s.strip()

class SmartConnect(gdb.Command):
    def __init__(self):
        super(SmartConnect, self).__init__("smart-connect", gdb.COMMAND_RUNNING)

    def invoke(self, arg, from_tty):
        raw_input = force_to_str(arg)
        parts = raw_input.split()
        
        if not parts:
            print("Error: Please provide a socket path.")
            return
            
        target_path = force_to_str(parts)
        timeout_val = 15
        if len(parts) > 1:
            try:
                timeout_val = int(force_to_str(parts))
            except ValueError:
                print(f"[*] Warning: Could not parse timeout '{parts}', using 15s default.")

        socket_path = os.path.abspath(os.path.expanduser(target_path))

        print(f"[*] Target Socket: {socket_path}")
        print(f"[*] Polling (Timeout: {timeout_val}s) ", end="", flush=True)

        start_time = time.time()
        last_error = "Socket file not found in filesystem."

        while (time.time() - start_time) < timeout_val:
            if not os.path.exists(socket_path):
                print(".", end="", flush=True)
                time.sleep(0.5)
                continue

            try:
                try: 
                    gdb.execute("disconnect", to_string=True)
                except: 
                    pass
                
                gdb.execute("target remote " + socket_path)
                print("\n[OK] Connected successfully!")
                return 
            except gdb.error as e:
                last_error = str(e)
                print("x", end="", flush=True)
                time.sleep(0.5)

        print(f"\n[Error] Connection timed out.")
        print(f"[*] Attempted Path: {socket_path}")
        print(f"[*] Last Error: {last_error}")

SmartConnect()
