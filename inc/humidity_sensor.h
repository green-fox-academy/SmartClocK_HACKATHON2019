#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include "main.h"

#define HH10D_ADDRESS     0xA2

#define SENS_MSB          0x0A
#define SENS_LSB		  0x0B
#define SENS_OFFMSB	      0x0C
#define SENS_OFFLSB		  0x0D

typedef struct hh10d_data_t {

	uint8_t sensitivity_msb;
	uint8_t sensitivity_lsb;
	uint8_t offset_msb;
	uint8_t offset_lsb;
	uint16_t sensitivty;
	uint16_t offset;
	uint32_t frequency;
	uint32_t increment_freq;
	int RH;

}hh10d_data_t;



int get_humidity(hh10d_data_t *inputStructure);
void get_constant_datas(hh10d_data_t *inputStructure);
void get_freq(hh10d_data_t* inputStructure);

#endif /* HUMIDITY_SENSOR_H */
