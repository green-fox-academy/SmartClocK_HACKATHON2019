#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "main.h"

#define TEMPSENS_ADDRESS 0x90
#define TEMPSENS_READING 0x91
#define CONTROL_REGISTER 0x01
#define TEMP_REGISTER	 0x00
#define TEMP_ID			 (0b00001111)

#define TEMPSENS_ON  	 (0b00000000)
#define TEMPSENS_OFF	 (0b00000001)

void tempsens_on(void);
void tempsens_off(void);
void get_temp(void);
uint8_t get_temp_id(void);


#endif /* TEMPERATURE_SENSOR_H */
