`ifdef NPC_DEBUG

  import "DPI-C" function void halt();
  import "DPI-C" function void inst_complete(input int pc, input int inst);

  import "DPI-C" function void event_mem_read(
    input int raddr,
    input int rsize,
    input int rdata
  );
  import "DPI-C" function void event_mem_write(
    input int waddr,
    input int wsize,
    input int wdata
  );

  import "DPI-C" function void perf_event(input int id);

  `ifdef YSYXSOC

    import "DPI-C" function void abort_err(input int err);

  `else

    import "DPI-C" function int pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(
      input int waddr,
      input int wdata,
      input byte wmask
    );
  
  `endif // YSYXSOC

`endif // NPC_DEBUG
