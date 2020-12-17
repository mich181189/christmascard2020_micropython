// Based on NUCLEO_F401RE
// Customised for christmas card by removing a bunch of irrelevant stuff

#define MICROPY_HW_BOARD_NAME       "Christmas Card from Michael (2020)"
#define MICROPY_HW_MCU_NAME         "STM32F401RE"

#define MICROPY_HW_HAS_SWITCH       (0)
#define MICROPY_HW_HAS_FLASH        (1)
#define MICROPY_HW_ENABLE_USB 		(1)
#define MICROPY_HW_USB_FS           (1)

#define MICROPY_HW_ENABLE_ADC       (0)

// This board has no oscillator so we use HSI
#define MICROPY_HW_CLK_USE_HSI (1)

#define MICROPY_HW_CLK_PLLM (16)

#define MICROPY_HW_CLK_PLLN (336)
#define MICROPY_HW_CLK_PLLP (RCC_PLLP_DIV4)
#define MICROPY_HW_CLK_PLLQ (7)

// UART config

// I2C busses
#define MICROPY_HW_I2C1_SCL (pin_B8)        // Arduino D15, pin 3 on CN10
#define MICROPY_HW_I2C1_SDA (pin_B9)        //         D14, pin 5 on CN10

// LEDs
#define MICROPY_HW_LED1             (pin_A5) // Red LED on board
#define MICROPY_HW_LED_ON(pin)      (mp_hal_pin_high(pin))
#define MICROPY_HW_LED_OFF(pin)     (mp_hal_pin_low(pin))
