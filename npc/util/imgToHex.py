from PIL import Image

input_path = "input.jpg"
output_path = "output.hex.txt"
size = (640, 480)

img = Image.open(input_path).convert('RGB').resize(size)
img.show()
with open(output_path, 'w') as f:
    for y in range(size[1]):
        for x in range(size[0]):
            line = ""
            r, g, b = img.getpixel((x, y))
            line += f"{r>>4:01x}{g>>4:01x}{b>>4:01x}"
            #line += f"{r:02x}{g:02x}{b:02x}"
            f.write(line + "\n")
