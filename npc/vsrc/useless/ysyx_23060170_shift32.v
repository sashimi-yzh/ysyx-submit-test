module ysyx_23060170_shift32 (
    input  [31:0] src ,
    input  [ 4:0] amt ,
    input  [ 2:0] op ,
    output [31:0] out 
);

  wire op_sll ;
  wire op_srl ;
  wire op_sra ;

  wire [31:0] shift_src ;
  wire [31:0] shift_res ;
  wire [31:0] sll_res ;
  wire [31:0] srl_res ;
  wire [31:0] sra_res ;
  wire [31:0] shift_mask ;

  assign op_sll = op[2];
  assign op_srl = op[1];
  assign op_sra = op[0];

  assign shift_src = op_sll ? {
                              src[ 0], src[ 1], src[ 2], src[ 3],
                              src[ 4], src[ 5], src[ 6], src[ 7],
                              src[ 8], src[ 9], src[10], src[11],
                              src[12], src[13], src[14], src[15],
                              src[16], src[17], src[18], src[19],
                              src[20], src[21], src[22], src[23],
                              src[24], src[25], src[26], src[27],
                              src[28], src[29], src[30], src[31]
                              }
                            : src;
  assign shift_res = shift_src >> amt;
  assign shift_mask = ~(32'hffffffff >> amt);
  assign srl_res = shift_res;
  assign sra_res = ({32{src[31]}} & shift_mask) | shift_res;
  assign sll_res = {
                   shift_res[ 0], shift_res[ 1], shift_res[ 2], shift_res[ 3],
                   shift_res[ 4], shift_res[ 5], shift_res[ 6], shift_res[ 7],
                   shift_res[ 8], shift_res[ 9], shift_res[10], shift_res[11],
                   shift_res[12], shift_res[13], shift_res[14], shift_res[15],
                   shift_res[16], shift_res[17], shift_res[18], shift_res[19],
                   shift_res[20], shift_res[21], shift_res[22], shift_res[23],
                   shift_res[24], shift_res[25], shift_res[26], shift_res[27],
                   shift_res[28], shift_res[29], shift_res[30], shift_res[31]
                  };

  assign out = {32{op_sll}} & sll_res |
               {32{op_srl}} & srl_res |
               {32{op_sra}} & sra_res;

endmodule
