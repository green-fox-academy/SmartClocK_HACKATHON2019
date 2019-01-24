#include "humidity_sensor.h"

int get_humidity(hh10d_data_t *inputStructure) {

	inputStructure->RH = (((inputStructure->offset - inputStructure->frequency)
			* inputStructure->sensitivty) / 4096) / 10;

	return inputStructure->RH;

}

void get_constant_datas(hh10d_data_t *inputStructure) {

	HAL_I2C_Mem_Read(&hi2c1, HH10D_ADDRESS, SENS_MSB, I2C_MEMADD_SIZE_8BIT,
			&inputStructure->sensitivity_msb, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, HH10D_ADDRESS, SENS_LSB, I2C_MEMADD_SIZE_8BIT,
			&inputStructure->sensitivity_lsb, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, HH10D_ADDRESS, SENS_OFFMSB, I2C_MEMADD_SIZE_8BIT,
			&inputStructure->offset_msb, 1, 100);
	HAL_I2C_Mem_Read(&hi2c1, HH10D_ADDRESS, SENS_OFFLSB, I2C_MEMADD_SIZE_8BIT,
			&inputStructure->offset_lsb, 1, 100);

	inputStructure->sensitivty = ((uint16_t) inputStructure->sensitivity_lsb
			| (uint16_t) inputStructure->sensitivity_msb << 8);
	inputStructure->offset = ((uint16_t) inputStructure->offset_lsb
			| (uint16_t) inputStructure->offset_msb << 8);

}

void get_freq(hh10d_data_t* inputStructure) {

	HH10D_PWM.Instance->CNT = 0;
	while ((HH10D_PWM.Instance->CNT) < 1000) {
		if (!(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))) {

			inputStructure->increment_freq++;
		}
		else if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15)) {


		}


	}
	inputStructure->frequency = inputStructure->increment_freq;
	inputStructure->increment_freq = 0;



}
