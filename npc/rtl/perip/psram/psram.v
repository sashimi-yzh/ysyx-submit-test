module psram(
  input sck,
  input ce_n,
  inout [3:0] dio
);

  reg   [7:0]   mem [(4 * 1024 * 1024 - 1) : 0] ;

  // initial begin
  //     $readmemh("/home/ysyx/Desktop/ysyx/ics2023/am-kernels/benchmarks/microbench/build/microbench-riscv32e-npc.hex", mem);
  // end

  reg   [4:0]   sck_cnt   ;
  reg   [7:0]   cmd       ;
  reg   [23:0]  addr      ;
  reg   [7:0]   wdata     ;
  reg   [7:0]   rdata     ;
  reg           is_read   ;
  reg           is_write  ;
  reg           qpi_mode  = 0;

  wire          wen       ;
  wire          ren       ;

  wire  [3:0]   din, dout ;
  reg   [3:0]   douten    ;

  assign  wen   = (sck_cnt >=  14) &&  sck_cnt[0]   &&  is_write ;
  assign  ren   = (sck_cnt >=  20) &&  !sck_cnt[0]  &&  is_read  ;

  assign  dout  = rdata[7:4]  ;

  always @(posedge ce_n ) begin
    if(ce_n &&  (cmd  ==  8'h35))
      qpi_mode  <=  1 ;
  end

  always @(posedge sck) begin
    if(wen)
      mem[addr[21:0]] <=  {wdata[3:0],  din} ;
  end

  always @(negedge sck ) begin
    if(ren)
      rdata <=  mem[addr[21:0]] ;
    else  if((sck_cnt >=  19) &&  is_read)
      rdata[7:4]  <=  rdata[3:0]  ;
  end

  always @(posedge sck ) begin
    if(sck_cnt  ==  6)  begin
      is_read   <=  1'b0  ;
      is_write  <=  1'b0  ;
    end
    else if(sck_cnt  ==  8) begin
      if(cmd  ==  8'hEB)
        is_read   <=  1'b1  ;
      else if(cmd  ==  8'h38)
        is_write  <=  1'b1  ;
      else begin
        $display("Assertion failed: Unsupport psram command `%xh`, only support `EBh` `38h` command\n", cmd);
        $fatal;
      end
    end
  end

  always @(posedge sck ) begin
    if(sck_cnt >=  14)
      wdata <=  {wdata[3:0],  din};
  end
  
  // always @(posedge sck or negedge ce_n) begin
  //   if(!ce_n)
  //     sck_cnt <=  'd0 ;
  //   else
  //     sck_cnt <=  sck_cnt + 1 ;
  // end

  always @(posedge sck or posedge ce_n) begin
    if(ce_n) begin
      if(qpi_mode ||  (cmd ==  'h35))
        sck_cnt <=  'd6 ;
      else
        sck_cnt <=  'd0 ;
    end
    else
      sck_cnt <=  sck_cnt + 1 ;
  end

  always @(posedge sck ) begin
    if(sck_cnt <=  7  &&  !qpi_mode)
      cmd   <=  {cmd[6:0],  din[0]};
    else  if(qpi_mode)  begin
      if(sck_cnt ==  6)
        cmd[7:4]   <=  din  ;
      else  if(sck_cnt ==  7)
        cmd[3:0]   <=  din  ;
    end
  end

  always @(posedge sck ) begin
    if(sck_cnt  >=  8 &&  sck_cnt <=  13)
      addr  <=  {addr[19:0],  din};
    else  if(wen)
      addr  <=  addr  + 1'b1  ;
    else  if(sck_cnt >=  20 &&  !sck_cnt[0]  &&  is_read)
      addr  <=  addr  + 1'b1  ;
  end

  always @(*) begin
    if(sck_cnt <=  19)
      douten  =  4'b0000 ;
    else begin
      if(is_read)
        douten  =  4'b1111 ;
      else if(is_write)
        douten  =  4'b0000 ;
      else
        douten  =  4'b0000 ;
    end
  end

  assign  dio[0] = douten[0] ? dout[0] : 1'bz;
  assign  dio[1] = douten[1] ? dout[1] : 1'bz;
  assign  dio[2] = douten[2] ? dout[2] : 1'bz;
  assign  dio[3] = douten[3] ? dout[3] : 1'bz;

  assign  din = dio ;
endmodule
