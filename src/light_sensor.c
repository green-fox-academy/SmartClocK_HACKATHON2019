#include "light_sensor.h"

void light_sensor_init(void) {

	uint8_t settings = 0x10;

	HAL_I2C_Master_Transmit(&hi2c1, LIGHT_SENSOR_ADDRESS, &settings, 1, 100);

	HAL_Delay(30);
}

is_Dark get_lux_value(void) {

	is_Dark condition;

	static uint16_t value;

	HAL_I2C_Master_Receive(&hi2c1, LIGHT_SENSOR_ADDRESS, (uint8_t*) &value, 2,
			160);



	switch (value) {
	case 0 ... 500:
		condition = NIGHT;
		break;
	default:
		condition = DAY;
	}

	return condition;
}
