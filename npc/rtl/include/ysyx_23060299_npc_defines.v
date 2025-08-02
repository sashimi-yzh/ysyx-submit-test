`ifndef __ICARUS__
    // `define ysyx_23060299_verilator_env

    // `define ysyx_23060299_PO // need to same as include/config/config.h

    // `define ysyx_23060299_NPC
`endif

`define ysyx_23060299_RESET_PC    32'h30000000


// `define ysyx_23060299_APB_DELAY

// `define ysyx_23060299_AXI_DELAY

// `define ysyx_23060299_M_EXTENSION

`define ysyx_23060299_E_EXTENSION

`ifdef ysyx_23060299_E_EXTENSION
    `define ysyx_23060299_REG_ADDR_WIDTH  4
`else
    `define ysyx_23060299_REG_ADDR_WIDTH  5
`endif