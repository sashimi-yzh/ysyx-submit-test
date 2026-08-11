# NPC host software

The host simulator is split by responsibility:

- `main.c`: process entry point and argument handoff.
- `cpu/`: execution control, DPI commit handling, and differential testing.
- `engine/`: simulator-engine initialization.
- `isa/`: RISC-V architectural state and ISA-specific difftest glue.
- `memory/`: guest physical and virtual memory access.
- `monitor/`: interactive debugger, expressions, and watchpoints.
- `platform/`: Verilator clocking plus NPC/ysyxSoC device adapters.
- `runtime/`: small process-wide services such as state and timing.
- `trace/`: instruction disassembly, logs, and function tracing.

Public cross-module interfaces stay in `../include`. Private helpers should
remain inside their owning source file unless another module truly needs them.

`sources.mk` is the only source manifest. Add new host-side modules there (or
under one of its listed directories) instead of creating nested file lists.
