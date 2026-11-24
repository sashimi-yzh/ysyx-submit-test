#include <am.h>
#include <klib-macros.h>
#include <klib.h>
#include <soc.h>

// Global SPI configuration
static spi_config_t g_spi_config;
static bool         g_spi_initialized = false;

/**
 * SPI initialization function
 * @param config SPI configuration parameters, use default if NULL
 * @return 0 for success, -1 for failure
 */
static int spi_init(const spi_config_t *config) {
  // Use default configuration or user-provided configuration
  if (config == NULL) {
    // Default configuration - suitable for most SPI Flash devices
    g_spi_config.div              = DEFAULT_SPI_DIV;
    g_spi_config.rx_neg           = false; // Positive edge sampling
    g_spi_config.tx_neg           = false; // Positive edge transmission
    g_spi_config.lsb_first        = false; // MSB first
    g_spi_config.auto_ss          = false; // Manual slave select
    g_spi_config.interrupt_enable = false; // No interrupt
  } else {
    g_spi_config = *config;
  }

  // Set divider register
  REG_WRITE(SPI_DIV_REG, g_spi_config.div);

  // Initialize slave select register (deselect all slaves)
  REG_WRITE(SPI_SS_REG, 0x00);

  // Clear control register
  // REG_WRITE(SPI_CTRL_REG, 0x00);

  g_spi_initialized = true;
  return 0;
}

int __am_spi_init(void) {
  return spi_init(NULL);
}

/**
 * Build control register value
 * @param char_len Transfer length in bits
 * @param start_transfer Whether to start transfer immediately
 * @return Control register value
 */
static uint32_t build_ctrl_reg(uint32_t char_len, bool start_transfer) {
  uint32_t ctrl_val = 0;

  // Set transfer length
  ctrl_val |= (char_len & SPI_CTRL_CHAR_LEN_MASK) << SPI_CTRL_CHAR_LEN_SHIFT;

  // Set control bits according to configuration
  if (g_spi_config.rx_neg) {
    ctrl_val |= SPI_CTRL_RX_NEG;
  }

  if (g_spi_config.tx_neg) {
    ctrl_val |= SPI_CTRL_TX_NEG;
  }

  if (g_spi_config.lsb_first) {
    ctrl_val |= SPI_CTRL_LSB;
  }

  if (g_spi_config.auto_ss) {
    ctrl_val |= SPI_CTRL_ASS;
  }

  if (g_spi_config.interrupt_enable) {
    ctrl_val |= SPI_CTRL_IE;
  }

  return ctrl_val;
}

/**
 * Wait for SPI transfer completion
 * @param timeout_ms Timeout in milliseconds, 0 for infinite wait
 * @return 0 for success, -1 for timeout
 */
static int wait_spi_complete(uint32_t timeout_ms) {
  uint32_t ctrl_val;
  uint32_t count     = 0;
  uint32_t max_count = timeout_ms * 1000; // Assume 1us per loop iteration

  do {
    ctrl_val = REG_READ(SPI_CTRL_REG);
    if (timeout_ms > 0 && ++count > max_count) {
      printf("wait for spi complete timeout\n");
      return -1; // Timeout
    }
  } while (ctrl_val & SPI_CTRL_BSY);

  return 0;
}

/**
 * Select SPI slave device
 * @param slave_id Slave device ID
 */
static void spi_select_slave(uint32_t slave_id) {
  REG_WRITE(SPI_SS_REG, 1 << slave_id);
}

/**
 * Deselect SPI slave device
 */
static void spi_deselect_slave(void) { REG_WRITE(SPI_SS_REG, 0x00); }

static inline uint32_t flash_swap32(uint32_t val) {
  return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) |
         ((val & 0xFF0000) >> 8) | ((val & 0xFF000000) >> 24);
}

/**
 * Generic SPI transfer function
 * @param tx_data Data to transmit
 * @param char_len Transfer length in bits
 * @param slave_id Slave device ID
 * @return Received data, 0 on failure
 */
uint32_t spi_transfer(uint32_t tx_data, uint32_t char_len, uint32_t slave_id) {
  uint32_t ctrl_val;
  uint32_t rx_data;

  if (!g_spi_initialized) {
    return 0; // SPI not initialized
  }

  // 1. Select slave device
  spi_select_slave(slave_id);

  // 2. Build and write control register and set
  ctrl_val = build_ctrl_reg(char_len, true);
  REG_WRITE(SPI_CTRL_REG, ctrl_val);

  // 3. Set TX data and trigger go
  REG_WRITE(SPI_TX_REG, tx_data);
  ctrl_val |= SPI_CTRL_GO;
  REG_WRITE(SPI_CTRL_REG, ctrl_val);

  // 4. Wait for transfer completion
  if (wait_spi_complete(1000) != 0) { // 1 second timeout
    spi_deselect_slave();
    return 0; // Transfer timeout
  }

  // 5. Read received data
  rx_data = REG_READ(SPI_RX_REG);

  // 6. Deselect slave
  if (!g_spi_config.auto_ss) {
    spi_deselect_slave();
  }

  // 7. Swap the endian
  return flash_swap32(rx_data);
}

/**
 * Flash read function
 * @param addr Flash address
 * @return 32-bit data read from flash
 */
uint32_t flash_read(uint32_t addr) {
  uint32_t tx_data;

  // Ensure SPI is initialized
  if (!g_spi_initialized) {
    spi_init(NULL); // Initialize with default configuration
  }

  // Prepare transmit data: [8-bit command][24-bit address]
  tx_data = (FLASH_READ_CMD << 24) | (addr & 0xFFFFFF);

  // Execute SPI transfer: 64-bit transfer (32-bit command+address + 32-bit
  // data)
  return spi_transfer(tx_data, 64, FLASH_SLAVE_ID);
}

/**
 * Get current SPI configuration
 * @return Pointer to current SPI configuration
 */
const spi_config_t *spi_get_config(void) { return &g_spi_config; }

/**
 * Check if SPI is initialized
 * @return true if initialized, false if not initialized
 */
bool spi_is_initialized(void) { return g_spi_initialized; }