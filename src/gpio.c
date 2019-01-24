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

	__HAL_RCC_GPIOF_CLK_ENABLE()
	;
	lcd_strip.Pin = GPIO_PIN_6;
	lcd_strip.Mode = GPIO_MODE_OUTPUT_PP;
	lcd_strip.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOF, &lcd_strip);

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;
	INPUT_FREQ.Pin = GPIO_PIN_15;
	INPUT_FREQ.Mode = GPIO_MODE_INPUT;
	INPUT_FREQ.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOA, &INPUT_FREQ);

}
