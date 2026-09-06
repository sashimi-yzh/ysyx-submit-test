#!/usr/bin/env python3

import argparse
import sys
from pathlib import Path


OLD_MODULE_NAME = "ysyx_00000000"
NEW_MODULE_NAME = "ysyx_24100007"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Replace the placeholder CPU module name in ysyxSoCFull.v."
    )
    parser.add_argument("soc_verilog", type=Path, help="path to ysyxSoCFull.v")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    soc_verilog = args.soc_verilog

    if not soc_verilog.is_file():
        print(f"mk_soc: file not found: {soc_verilog}", file=sys.stderr)
        return 1

    try:
        source = soc_verilog.read_text(encoding="utf-8")
    except OSError as error:
        print(f"mk_soc: failed to read {soc_verilog}: {error}", file=sys.stderr)
        return 1

    replacement_count = source.count(OLD_MODULE_NAME)
    if replacement_count == 0:
        if NEW_MODULE_NAME not in source:
            print(
                f"mk_soc: neither {OLD_MODULE_NAME} nor {NEW_MODULE_NAME} "
                f"was found in {soc_verilog}",
                file=sys.stderr,
            )
            return 1

        print(f"mk_soc: {soc_verilog} already uses {NEW_MODULE_NAME}")
        return 0

    try:
        soc_verilog.write_text(
            source.replace(OLD_MODULE_NAME, NEW_MODULE_NAME), encoding="utf-8"
        )
    except OSError as error:
        print(f"mk_soc: failed to update {soc_verilog}: {error}", file=sys.stderr)
        return 1

    print(
        f"mk_soc: replaced {replacement_count} occurrence(s) of "
        f"{OLD_MODULE_NAME} with {NEW_MODULE_NAME} in {soc_verilog}"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
