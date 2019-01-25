#include "light_sensor.h"

void light_sensor_init(void) {

	uint8_t light_sensor_settings = 0x10;

	HAL_I2C_Master_Transmit(&hi2c1, LIGHT_SENSOR_ADDRESS,
			&light_sensor_settings, 1, 100);

}

is_Dark get_lux_value(void) {

	is_Dark condition;
	static uint16_t lux_value;

	HAL_I2C_Master_Receive(&hi2c1, LIGHT_SENSOR_ADDRESS, (uint8_t*) &lux_value,
			2, 160);

	switch (lux_value) {
	case 0 ... 1200:
		condition = NIGHT;
		break;
	default:
		condition = DAY;
	}
	return condition;
}
