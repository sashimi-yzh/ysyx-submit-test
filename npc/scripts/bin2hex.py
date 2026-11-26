#!/usr/bin/env python3
"""Convert a little-endian binary image to $readmemh words.

Usage:
    python3 npc/scripts/bin2hex.py IMG.bin OUT.hex
"""

from __future__ import annotations

import sys
from pathlib import Path


def main() -> int:
    if len(sys.argv) != 3:
        print(f"usage: {sys.argv[0]} IMG.bin OUT.hex", file=sys.stderr)
        return 2
    src = Path(sys.argv[1])
    dst = Path(sys.argv[2])
    data = src.read_bytes()
    if len(data) % 4:
        data += b"\x00" * (4 - len(data) % 4)
    dst.parent.mkdir(parents=True, exist_ok=True)
    with dst.open("w", encoding="ascii") as fp:
        for off in range(0, len(data), 4):
            word = int.from_bytes(data[off : off + 4], byteorder="little")
            fp.write(f"{word:08x}\n")
    print(f"[bin2hex] {src} -> {dst} ({len(data)} bytes)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
