# -*- coding: utf-8 -*-
"""
Read one image, scale to cover 640x480, center-crop,
then generate picture.hex (RGB888, $readmemh style).

Address mapping:
addr = h * 512 + v
File order: for x=0..639, y=0..511

Visible area:
x = 0..639
y = 0..479

Padding area:
y = 480..511 (filled with FILL_COLOR)
"""

from PIL import Image

# -------------------- paths --------------------
INPUT_IMAGE = r"./resource/2.png"
OUTPUT_HEX  = r"./resource/2.hex"
# ------------------------------------------------

# Visible resolution
W, H = 640, 480

# Actual generated memory size
VRAM_W = 640
VRAM_H = 512

# Fill color for unused rows
FILL_COLOR = (255, 255, 255)  # white

def scale_cover_and_center_crop(img: Image.Image, tw: int, th: int) -> Image.Image:
    img = img.convert("RGB")
    iw, ih = img.size

    scale = max(tw / iw, th / ih)
    nw = int(round(iw * scale))
    nh = int(round(ih * scale))
    img = img.resize((nw, nh), Image.LANCZOS)

    left = (nw - tw) // 2
    top  = (nh - th) // 2
    return img.crop((left, top, left + tw, top + th))

def rgb_to_hex24(r: int, g: int, b: int) -> str:
    return f"{r:02X}{g:02X}{b:02X}"

def main():
    src = Image.open(INPUT_IMAGE)
    cropped = scale_cover_and_center_crop(src, W, H)
    pix = cropped.load()

    with open(OUTPUT_HEX, "w", encoding="ascii", newline="\n") as f:
        # column-major: x first, then y
        for x in range(VRAM_W):
            for y in range(VRAM_H):
                if y < H:
                    r, g, b = pix[x, y]
                else:
                    r, g, b = FILL_COLOR
                f.write(rgb_to_hex24(r, g, b) + "\n")

    print(f"Done. Wrote {VRAM_W * VRAM_H} words ({VRAM_W}x{VRAM_H})")

if __name__ == "__main__":
    main()
