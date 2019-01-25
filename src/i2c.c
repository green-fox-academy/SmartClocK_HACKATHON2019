#include "i2c.h"


void MX_I2C_init(void) {

	i2c_pin_config.Pin = GPIO_PIN_9 | GPIO_PIN_8;
	i2c_pin_config.Mode = GPIO_MODE_AF_OD;
	i2c_pin_config.Alternate = GPIO_AF4_I2C1;
	i2c_pin_config.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOB, &i2c_pin_config);

	__HAL_RCC_I2C1_CLK_ENABLE()
	;
	hi2c1.Instance = I2C1;
	hi2c1.Init.Timing = 0x40912732;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	HAL_I2C_Init(&hi2c1);
}

void i2c_detect(void) {

	uint8_t devices = 0u;

	printf("Searching for I2C devices on the bus...\n");
	/* Values outside 0x03 and 0x77 are invalid. */
	for (uint8_t i = 0x03u; i < 0x78u; i++) {
		uint8_t address = i << 1u;
		/* In case there is a positive feedback, print it out. */
		if (HAL_OK == HAL_I2C_IsDeviceReady(&hi2c1, address, 3u, 10u)) {
			printf("Device found: 0x%02X\n", address);
			devices++;
		}
	}
	/* Feedback of the total number of devices. */
	if (0u == devices) {
		printf("No device found.\n");
	} else {
		printf("Total found devices: %d\n", devices);
	}
}
