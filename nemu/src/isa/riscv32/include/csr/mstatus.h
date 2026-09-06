// mstats 寄存器位定义 (RV32)
#define MSTATUS_UIE (1 << 0)         // User Interrupt Enable
#define MSTATUS_SIE (1 << 1)         // Supervisor Interrupt Enable
#define MSTATUS_MIE (1 << 3)         // Machine Interrupt Enable
#define MSTATUS_UPIE (1 << 4)        // User Previous Interrupt Enable
#define MSTATUS_SPIE (1 << 5)        // Supervisor Previous Interrupt Enable
#define MSTATUS_MPIE (1 << 7)        // Machine Previous Interrupt Enable
#define MSTATUS_SPP (1 << 8)         // Supervisor Previous Privilege
#define MSTATUS_MPP_HIGH (1 << 11)   // Machine Previous Privilege high bit
#define MSTATUS_MPP_LOW (1 << 12)    // Machine Previous Privilege low bit
#define MSTATUS_MPP_MASK (3 << 11)   // MPP field mask
#define MSTATUS_MPP_U (0 << 11)      // MPP = User mode
#define MSTATUS_MPP_S (1 << 11)      // MPP = Supervisor mode
#define MSTATUS_MPP_M (3 << 11)      // MPP = Machine mode
#define MSTATUS_FS (3 << 13)         // Floating-point Status
#define MSTATUS_FS_OFF (0 << 13)     // FPU off
#define MSTATUS_FS_INITIAL (1 << 13) // FPU initial
#define MSTATUS_FS_CLEAN (2 << 13)   // FPU clean
#define MSTATUS_FS_DIRTY (3 << 13)   // FPU dirty
#define MSTATUS_XS (3 << 15)         // User Extension Status
#define MSTATUS_MPRV (1 << 17)       // Modify Privilege
#define MSTATUS_SUM (1 << 18)        // Supervisor User Memory Access
#define MSTATUS_MXR (1 << 19)        // Make eXecutable Readable
#define MSTATUS_TVM (1 << 20)        // Trap Virtual Memory
#define MSTATUS_TW (1 << 21)         // Timeout Wait
#define MSTATUS_TSR (1 << 22)        // Trap SRET

// mstatush 仅包含 mstatus 的 bits 32-63 的高位字段
#define MSTATUSH_SBE                                                           \
  (1 << 4) // Supervisor Big-Endian (bits 36:35 in full mstatus)
#define MSTATUSH_MBE (1 << 5) // Machine Big-Endian (bits 37:36 in full mstatus)
#define MSTATUSH_MPV (1 << 7) // Machine Previous Virtualization mode (bit 39)
#define MSTATUSH_GVA (1 << 8) // Guest Virtual Address (bit 40)
#define MSTATUSH_MPELP (1 << 9) // Machine Previous Endianness and Label Pointer
