#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "main.h"



#define LIGHT_SENSOR_ADDRESS 0x46

typedef enum Darkness {
	DAY,
	NIGHT
}is_Dark;

void light_sensor_init(void);
is_Dark  get_lux_value(void);



#endif /* LIGHT_SENSOR_H */
