#!/usr/bin/env python3

"""
Usage:
    python3 plot_mem_trace.py <trace_file> [--output-dir DIR]

Examples:
    # Basic usage
    python3 plot_mem_trace.py build/npc-log-mem.txt

    # Specify output directory
    python3 plot_mem_trace.py build/npc-log-mem.txt --output-dir build/trace-plots

    # Only count read or write accesses
    python3 plot_mem_trace.py build/npc-log-mem.txt --access read
    python3 plot_mem_trace.py build/npc-log-mem.txt --access write

    # Change bucket size and top-N hot addresses
    python3 plot_mem_trace.py build/npc-log-mem.txt --bucket-size 0x100 --top 50

Outputs:
    - top-addresses.png
    - bucket-distribution.png
    - exact-address-counts.csv
    - bucket-counts.csv
"""

import argparse
import csv
import re
import sys
from collections import Counter
from pathlib import Path

import matplotlib

matplotlib.use("Agg")

import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MaxNLocator


TRACE_RE = re.compile(r"^(read|write)\s+mem\s+(0x[0-9a-fA-F]+)\s+mask\s+(\d+)")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Parse NPC memory trace and plot address access frequency."
    )
    parser.add_argument("trace_file", type=Path, help="Path to the trace file")
    parser.add_argument(
        "--output-dir",
        type=Path,
        default=Path("trace-plots"),
        help="Directory for generated plots and CSV files",
    )
    parser.add_argument(
        "--bucket-size",
        type=lambda value: int(value, 0),
        default=0x10,
        help="Bucket size for address-range aggregation, e.g. 0x40 or 64",
    )
    parser.add_argument(
        "--top",
        type=int,
        default=30,
        help="Number of hottest exact addresses to plot",
    )
    parser.add_argument(
        "--access",
        choices=["all", "read", "write"],
        default="all",
        help="Filter access type before counting",
    )
    return parser.parse_args()


def iter_trace(trace_file: Path, access_filter: str):
    with trace_file.open("r", encoding="utf-8") as handle:
        for line_no, raw_line in enumerate(handle, start=1):
            line = raw_line.strip()
            if not line:
                continue
            match = TRACE_RE.match(line)
            if not match:
                continue

            access_type, address_hex, mask = match.groups()
            if access_filter != "all" and access_type != access_filter:
                continue

            yield {
                "line_no": line_no,
                "access_type": access_type,
                "address": int(address_hex, 16),
                "mask": int(mask),
            }


def write_exact_csv(output_path: Path, counts: Counter) -> None:
    with output_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.writer(handle)
        writer.writerow(["address_hex", "address_dec", "count"])
        for address, count in counts.most_common():
            writer.writerow([hex(address), address, count])


def write_bucket_csv(output_path: Path, counts: Counter, bucket_size: int) -> None:
    with output_path.open("w", newline="", encoding="utf-8") as handle:
        writer = csv.writer(handle)
        writer.writerow(["bucket_base_hex", "bucket_end_hex", "count"])
        for bucket_base, count in sorted(counts.items()):
            writer.writerow(
                [hex(bucket_base), hex(bucket_base + bucket_size - 1), count]
            )


def plot_top_addresses(output_path: Path, counts: Counter, top_n: int, title: str) -> None:
    top_items = counts.most_common(top_n)
    if not top_items:
        return

    items = list(reversed(top_items))
    labels = [hex(address) for address, _ in items]
    values = [count for _, count in items]

    fig_height = max(6, len(items) * 0.35)
    fig, ax = plt.subplots(figsize=(12, fig_height))
    bars = ax.barh(labels, values, color="#1f77b4", alpha=0.9)
    ax.set_title(title)
    ax.set_xlabel("Access count")
    ax.set_ylabel("Exact address")
    ax.grid(axis="x", linestyle="--", alpha=0.35)

    max_value = max(values)
    text_offset = max(1, max_value * 0.01)
    for bar, value in zip(bars, values):
        ax.text(
            bar.get_width() + text_offset,
            bar.get_y() + bar.get_height() / 2,
            str(value),
            va="center",
            fontsize=9,
        )

    fig.tight_layout()
    fig.savefig(output_path, dpi=180)
    plt.close(fig)


def plot_bucket_counts(
    output_path: Path, counts: Counter, bucket_size: int, title: str
) -> None:
    if not counts:
        return

    bucket_bases = sorted(counts)
    min_bucket = bucket_bases[0]
    max_bucket = bucket_bases[-1]
    right_edge = max_bucket + bucket_size
    values = [counts[bucket_base] for bucket_base in bucket_bases]
    fig, ax = plt.subplots(figsize=(14, 6))
    ax.bar(
        bucket_bases,
        values,
        width=max(1, bucket_size * 0.9),
        align="edge",
        color="#d62728",
        alpha=0.85,
        edgecolor="#8c1d18",
        linewidth=0.5,
    )
    ax.set_title(title)
    ax.set_xlabel(f"Address bucket base (bucket size = {hex(bucket_size)})")
    ax.set_ylabel("Access count")
    ax.grid(axis="y", linestyle="--", alpha=0.35)
    ax.set_xlim(min_bucket, right_edge)
    ax.xaxis.set_major_locator(MaxNLocator(nbins=8, integer=True))

    # Always show both endpoints to avoid missing start/end labels.
    ticks = list(ax.get_xticks())
    for endpoint in (min_bucket, right_edge):
        if all(abs(tick - endpoint) > 1e-6 for tick in ticks):
            ticks.append(endpoint)
    ax.set_xticks(sorted(ticks))

    ax.xaxis.set_major_formatter(FuncFormatter(lambda value, _: hex(int(value))))
    fig.autofmt_xdate(rotation=25)
    fig.tight_layout()
    fig.savefig(output_path, dpi=180)
    plt.close(fig)


def main() -> int:
    args = parse_args()
    if args.bucket_size <= 0:
        print("bucket size must be positive", file=sys.stderr)
        return 1

    if args.top <= 0:
        print("top must be positive", file=sys.stderr)
        return 1

    accesses = list(iter_trace(args.trace_file, args.access))
    if not accesses:
        print("no matching trace records found", file=sys.stderr)
        return 1

    exact_counts = Counter(item["address"] for item in accesses)
    bucket_counts = Counter(
        (item["address"] // args.bucket_size) * args.bucket_size for item in accesses
    )

    args.output_dir.mkdir(parents=True, exist_ok=True)

    exact_csv = args.output_dir / "exact-address-counts.csv"
    bucket_csv = args.output_dir / "bucket-counts.csv"
    top_png = args.output_dir / "top-addresses.png"
    bucket_png = args.output_dir / "bucket-distribution.png"

    write_exact_csv(exact_csv, exact_counts)
    write_bucket_csv(bucket_csv, bucket_counts, args.bucket_size)

    access_label = args.access.capitalize()
    plot_top_addresses(
        top_png,
        exact_counts,
        args.top,
        f"{access_label} hottest exact addresses",
    )
    plot_bucket_counts(
        bucket_png,
        bucket_counts,
        args.bucket_size,
        f"{access_label} access distribution by address bucket",
    )

    print(f"parsed records: {len(accesses)}")
    print(f"unique exact addresses: {len(exact_counts)}")
    print(f"non-empty buckets: {len(bucket_counts)}")
    print(f"top address plot: {top_png}")
    print(f"bucket plot: {bucket_png}")
    print(f"exact counts csv: {exact_csv}")
    print(f"bucket counts csv: {bucket_csv}")

    print("\nhottest addresses:")
    for address, count in exact_counts.most_common(min(args.top, 10)):
        print(f"  {hex(address)} -> {count}")

    return 0


if __name__ == "__main__":
    raise SystemExit(main())