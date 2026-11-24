#include <klib-macros.h>

#include ISA_H

// SPI Flash related
/*****************************************************************/
// SPI register address definitions (adjust according to actual hardware)
#define SPI_BASE     0x10001000        // SPI controller base address
#define SPI_RX_REG   (SPI_BASE + 0x00) // RX data register
#define SPI_TX_REG   (SPI_BASE + 0x04) // TX data register
#define SPI_CTRL_REG (SPI_BASE + 0x10) // Control register
#define SPI_DIV_REG  (SPI_BASE + 0x14) // Divider register
#define SPI_SS_REG   (SPI_BASE + 0x18) // Slave select register

// Control register bit definitions
#define SPI_CTRL_CHAR_LEN_SHIFT 0         // Transfer length bit shift
#define SPI_CTRL_CHAR_LEN_MASK  0x7F      // Transfer length mask
#define SPI_CTRL_RX_NEG         (1 << 9)  // RX negative edge sampling
#define SPI_CTRL_TX_NEG         (1 << 10) // TX negative edge transmission
#define SPI_CTRL_LSB            (1 << 11) // LSB first
#define SPI_CTRL_IE             (1 << 12) // Interrupt enable
#define SPI_CTRL_ASS            (1 << 13) // Automatic slave select
#define SPI_CTRL_GO             (1 << 8)  // Start transfer
#define SPI_CTRL_BSY            (1 << 8)  // Busy flag (when reading)

// Flash related definitions
#define FLASH_READ_CMD  0x03 // Standard read command
#define FLASH_SLAVE_ID  0    // Flash slave ID
#define DEFAULT_SPI_DIV 1    // Default divider value

// Register read/write macros
#define REG_READ(addr)       (*(volatile uint32_t *)(addr))
#define REG_WRITE(addr, val) (*(volatile uint32_t *)(addr) = (val))

// SPI configuration structure
typedef struct {
  uint32_t div;              // Divider value
  bool     rx_neg;           // RX negative edge sampling
  bool     tx_neg;           // TX negative edge transmission
  bool     lsb_first;        // LSB first
  bool     auto_ss;          // Automatic slave select
  bool     interrupt_enable; // Interrupt enable
} spi_config_t;

int __am_spi_init(void);

// UART related
/*****************************************************************/
#define SERIAL_PORT (0x10000000)
#define RBR_REG     (SERIAL_PORT + 0)
#define THR_REG     (SERIAL_PORT + 0)
#define DLL_REG     (SERIAL_PORT + 0)
#define DLM_REG     (SERIAL_PORT + 1)
#define IER_REG     (SERIAL_PORT + 1)
#define IIR_REG     (SERIAL_PORT + 2)
#define FCR_REG     (SERIAL_PORT + 2)
#define LCR_REG     (SERIAL_PORT + 3)
#define MCR_REG     (SERIAL_PORT + 4)
#define LSR_REG     (SERIAL_PORT + 5)
#define MSR_REG     (SERIAL_PORT + 6)

// LCR reg bit
#define LCR_DLAB         0x80
#define LCR_BREAK        0x40
#define LCR_PARITY_MASK  0x38
#define LCR_PARITY_NONE  0x00
#define LCR_PARITY_ODD   0x08
#define LCR_PARITY_EVEN  0x18
#define LCR_PARITY_MARK  0x28
#define LCR_PARITY_SPACE 0x38
#define LCR_STOP_1       0x00
#define LCR_STOP_2       0x04
#define LCR_BITS_5       0x00
#define LCR_BITS_6       0x01
#define LCR_BITS_7       0x02
#define LCR_BITS_8       0x03

// LSR reg bit
#define LSR_DR         0x01
#define LSR_THRE       0x20
#define LSR_TEMT       0x40
#define LSR_ERROR_MASK 0x80

// 标准时钟频率
#define UART_CLOCK 1843200 // 1.8432MHz

typedef enum {
  UART_BITS_5 = 5,
  UART_BITS_6 = 6,
  UART_BITS_7 = 7,
  UART_BITS_8 = 8
} uart_data_bits_t;

typedef enum { UART_STOP_1 = 1, UART_STOP_2 = 2 } uart_stop_bits_t;

typedef enum {
  UART_PARITY_NONE,
  UART_PARITY_ODD,
  UART_PARITY_EVEN,
  UART_PARITY_MARK,
  UART_PARITY_SPACE
} uart_parity_t;

typedef struct {
  uint32_t         baud_rate;
  uart_data_bits_t data_bits;
  uart_stop_bits_t stop_bits;
  uart_parity_t    parity;
} uart_config_t;

typedef enum { UART_OK = 0, UART_TT = -1, UART_ERROR = -2 } uart_status_t;

int __am_uart_init(void);

// PS2 related
/*****************************************************************/

#define KBD_BASE 0x10011000
#define KBD_ADDR KBD_BASE

// VGA related
/*****************************************************************/
// 0x0 height, 0x2 width, 0x4 sync
#define VGACTL_ADDR 0x21000000
#define SYNC_ADDR   (VGACTL_ADDR + 0x8)
#define FB_ADDR     (VGACTL_ADDR + 0x10)


// RTC related (Clint)
#define RTC_ADDR 0x02000000