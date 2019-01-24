#include "gpio.h"

void MX_GPIO_init(void) {

	__HAL_RCC_GPIOC_CLK_ENABLE()
	;
	bluetooth_config.Pin = GPIO_PIN_6 | GPIO_PIN_7;
	bluetooth_config.Mode = GPIO_MODE_AF_PP;
	bluetooth_config.Pull = GPIO_NOPULL;
	bluetooth_config.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
	bluetooth_config.Alternate = GPIO_AF8_USART6;
	HAL_GPIO_Init(GPIOC, &bluetooth_config);


}
