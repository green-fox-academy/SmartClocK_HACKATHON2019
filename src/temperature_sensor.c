#include "temperature_sensor.h"


uint8_t temp = 0;

void tempsens_on(void) {

	HAL_I2C_Mem_Write(&hi2c1, TEMPSENS_ADDRESS, CONTROL_REGISTER,
			I2C_ADDRESSINGMODE_7BIT, TEMPSENS_ON, 1, 100);

}

void tempsens_off(void) {

	HAL_I2C_Mem_Write(&hi2c1, TEMPSENS_ADDRESS, CONTROL_REGISTER,
			I2C_ADDRESSINGMODE_7BIT, (uint8_t*) TEMPSENS_OFF, 1, 100);

}

void get_temp(void) {

	HAL_I2C_Mem_Read(&hi2c1, TEMPSENS_READING, TEMP_REGISTER,
			I2C_ADDRESSINGMODE_7BIT, &temp, 2, 300);

}

uint8_t get_temp_id(void) {

	uint8_t id = 0;

	HAL_I2C_Mem_Read(&hi2c1, TEMPSENS_ADDRESS, TEMP_ID, I2C_ADDRESSINGMODE_7BIT,
			&id, 1, 100);

	return id;

}
