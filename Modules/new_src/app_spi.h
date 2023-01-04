SPI2 define 
//SPI2
#define MASTER_BOARD
#define SPI2_CLK_ENABLE()                __HAL_RCC_SPI2_CLK_ENABLE()
#define SPI2_SCK_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOB_CLK_ENABLE()
#define SPI2_MISO_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()
#define SPI2_MOSI_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOB_CLK_ENABLE()

/* Definition for SPIx Pins */
#define SPI2_NSS_PIN                     GPIO_PIN_12
#define SPI2_NSS_GPIO_PORT               GPIOB

#define SPI2_SCK_PIN                     GPIO_PIN_13
#define SPI2_SCK_GPIO_PORT               GPIOB
#define SPI2_MISO_PIN                    GPIO_PIN_14
#define SPI2_MISO_GPIO_PORT              GPIOB
#define SPI2_MOSI_PIN                    GPIO_PIN_15
#define SPI2_MOSI_GPIO_PORT              GPIOB